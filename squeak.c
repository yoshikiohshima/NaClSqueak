/** @file squeak.c
 * This example demonstrates loading, running and scripting a very simple
 * NaCl module.
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <sys/time.h>

#include <ppapi/c/dev/ppb_var_deprecated.h>
#include <ppapi/c/dev/ppp_class_deprecated.h>
#include <ppapi/c/pp_errors.h>
#include <ppapi/c/pp_var.h>
#include <ppapi/c/pp_module.h>
#include <ppapi/c/ppb.h>
#include <ppapi/c/ppb_instance.h>
#include <ppapi/c/ppp.h>
#include <ppapi/c/ppp_instance.h>
#include <ppapi/c/pp_size.h>
#include <ppapi/c/pp_rect.h>
#include <ppapi/c/pp_point.h>
#include <ppapi/c/ppb_image_data.h>
#include <ppapi/c/ppb_graphics_2d.h>
#include <ppapi/c/ppb_core.h>
#include <ppapi/c/pp_input_event.h>
#include <ppapi/c/pp_completion_callback.h>

static PP_Bool Instance_DidCreate(PP_Instance instance,
                                  uint32_t argc,
                                  const char* argn[],
                                  const char* argv[]);
static void Instance_DidDestroy(PP_Instance instance);
static void Instance_DidChangeView(PP_Instance instance,
                                   const struct PP_Rect* position,
                                   const struct PP_Rect* clip);
static void Instance_DidChangeFocus(PP_Instance instance,
                                    PP_Bool has_focus);
static PP_Bool Instance_HandleInputEvent(PP_Instance instance,
                                         const struct PP_InputEvent* event);
static struct PP_Var Instance_GetInstanceObject(PP_Instance instance);

static void DestroyContext(PP_Instance instance);
static void CreateContext(PP_Instance instance, const struct PP_Size* size);
static void FlushPixelBuffer();
static void Paint();
static PP_Bool isContextValid();

void* runInterpret(void *arg);
int32_t interpret();

int32_t toQuit = 0;
volatile int32_t count = 0;


static struct PPB_Var_Deprecated* var_interface = NULL;
static struct PPP_Class_Deprecated ppp_class;
static PP_Module module_id = 0;
const struct PPB_Graphics2D* graphics_2d_;
const struct PPB_ImageData* image_data_;
const struct PPB_Core* core_;
const struct PPB_Instance* instance_;

static PP_Resource gc = 0;
static PP_Resource image = 0;
static pthread_mutex_t image_mutex;
static pthread_mutex_t interpret_mutex;
static pthread_t interpret_thread;
static pthread_cond_t interpret_cond = PTHREAD_COND_INITIALIZER;

static const char* const kPaintMethodId = "paint";
static const char* const kGetStatusMethodId = "getStatus";

static int32_t flush_pending;

static char status[10000];
static char buffer[1024];

static struct PPP_Instance instance_interface = {
  &Instance_DidCreate,
  &Instance_DidDestroy,
  &Instance_DidChangeView,
  &Instance_DidChangeFocus,
  &Instance_HandleInputEvent,
  NULL,  /* HandleDocumentLoad is not supported by NaCl modules. */
  &Instance_GetInstanceObject,
};

static struct PP_ImageDataDesc desc;

static int32_t screenWidth;
static int32_t screenHeight;
static int32_t screenStride;

static int32_t mouseX;
static int32_t mouseY;

static PP_Bool
getDesc()
{
  if (!image) {
    return PP_FALSE;
  }

  if (image_data_->Describe(image, &desc)) {
    screenWidth = desc.size.width;
    screenHeight = desc.size.height;
    screenStride = desc.stride;
    return PP_TRUE;
  }
  screenWidth = 0;
  screenHeight = 0;
  screenStride = 0;
  return PP_FALSE;
}

/**
 * Returns C string contained in the @a var or NULL if @a var is not string.
 * @param[in] var PP_Var containing string.
 * @return a C string representation of @a var.
 * @note Returned pointer will be invalid after destruction of @a var.
 */
static const char*
VarToCStr(struct PP_Var var)
{
  uint32_t len = 0;
  if (NULL != var_interface)
    return var_interface->VarToUtf8(var, &len);
  return NULL;
}

/**
 * Creates new string PP_Var from C string. The resulting object will be a
 * refcounted string object. It will be AddRef()ed for the caller. When the
 * caller is done with it, it should be Release()d.
 * @param[in] str C string to be converted to PP_Var
 * @return PP_Var containing string.
 */
static struct
PP_Var StrToVar(const char* str)
{
  if (NULL != var_interface)
    return var_interface->VarFromUtf8(module_id, str, strlen(str));
  return PP_MakeUndefined();
}

static PP_Bool
Instance_DidCreate(PP_Instance instance,
                                  uint32_t argc,
                                  const char* argn[],
                                  const char* argv[])
{
  return PP_TRUE;
}

static void Instance_DidDestroy(PP_Instance instance) {
}

static void
Instance_DidChangeView(PP_Instance instance,
		       const struct PP_Rect* position,
		       const struct PP_Rect* clip)
{
  if (position->size.width == screenWidth &&
      position->size.height == screenHeight)
    return;  // Size didn't change, no need to update anything.
  strcat(status, "change view\n");
  DestroyContext(instance);
  CreateContext(instance, &position->size);
}

static void
Instance_DidChangeFocus(PP_Instance instance,
                                    PP_Bool has_focus)
{
}

static PP_Bool
Instance_HandleInputEvent(PP_Instance instance,
                                         const struct PP_InputEvent* event)
{
  if (event->type == PP_INPUTEVENT_TYPE_MOUSEDOWN) {
    mouseX = event->u.mouse.x;
    mouseY = event->u.mouse.y;
    sprintf(buffer, "mouse: %d, %d\n", (int)mouseX, (int)mouseY);
    strcat(status, buffer);
  }
  if (event->type == PP_INPUTEVENT_TYPE_MOUSEMOVE) {
    mouseX = event->u.mouse.x;
    mouseY = event->u.mouse.y;
  }
  return PP_TRUE;
}

/**
 * Create scriptable object for the given instance.
 * @param[in] instance The instance ID.
 * @return A scriptable object.
 */
static struct
PP_Var Instance_GetInstanceObject(PP_Instance instance)
{
  if (var_interface)
    return var_interface->CreateObject(instance, &ppp_class, NULL);
  return PP_MakeUndefined();
}

/**
 * Check existence of the function associated with @a name.
 * @param[in] object unused
 * @param[in] name method name
 * @param[out] exception pointer to the exception object, unused
 * @return If the method does exist, return true.
 * If the method does not exist, return false and don't set the exception.
 */
static bool
Squeak_HasMethod(void* object,
		 struct PP_Var name,
		 struct PP_Var* exception)
{
  const char* method_name = VarToCStr(name);
  if (NULL != method_name) {
    if (strcmp(method_name, kPaintMethodId) == 0)
      return true;
    if (strcmp(method_name, kGetStatusMethodId) == 0)
      return true;
  }
  return false;
}

/**
 * Invoke the function associated with @a name.
 * @param[in] object unused
 * @param[in] name method name
 * @param[in] argc number of arguments
 * @param[in] argv array of arguments
 * @param[out] exception pointer to the exception object, unused
 * @return If the method does exist, return true.
 */
static struct PP_Var
Squeak_Call(void* object,
	    struct PP_Var name,
	    uint32_t argc,
	    struct PP_Var* argv,
	    struct PP_Var* exception)
{
  struct PP_Var v = PP_MakeInt32(0);
  const char* method_name = VarToCStr(name);
  if (NULL != method_name) {
    if (strcmp(method_name, kPaintMethodId) == 0) {
      Paint();
      return v;
    }
    if (strcmp(method_name, kGetStatusMethodId) == 0)
      return StrToVar(status);
  }
  return v;
}

/**
 * Entrypoints for the module.
 * Initialize instance interface and scriptable object class.
 * @param[in] a_module_id module ID
 * @param[in] get_browser pointer to PPB_GetInterface
 * @return PP_OK on success, any other value on failure.
 */

PP_EXPORT int32_t
PPP_InitializeModule(PP_Module a_module_id, PPB_GetInterface get_browser_interface)
{
  module_id = a_module_id;
  var_interface = 
      (struct PPB_Var_Deprecated*)(get_browser_interface(PPB_VAR_DEPRECATED_INTERFACE));
  core_ = (const struct PPB_Core*)
    get_browser_interface(PPB_CORE_INTERFACE);
  instance_ = (const struct PPB_Instance*)
    get_browser_interface(PPB_INSTANCE_INTERFACE);
  graphics_2d_ = (const struct PPB_Graphics2D*)
    get_browser_interface(PPB_GRAPHICS_2D_INTERFACE);
  image_data_ = (const struct PPB_ImageData*)
    get_browser_interface(PPB_IMAGEDATA_INTERFACE);
  memset(&ppp_class, 0, sizeof(ppp_class));
  ppp_class.Call = Squeak_Call;
  ppp_class.HasMethod = Squeak_HasMethod;
  strcat(status, "initialize module");
  {
    pthread_mutex_init(&image_mutex, NULL);
    pthread_mutex_init(&interpret_mutex, NULL);
    pthread_cond_init (&interpret_cond, NULL);
  }

  return PP_OK;
}

/**
 * Returns an interface pointer for the interface of the given name, or NULL
 * if the interface is not supported.
 * @param[in] interface_name name of the interface
 * @return pointer to the interface
 */
PP_EXPORT const void*
PPP_GetInterface(const char* interface_name)
{
  if (strcmp(interface_name, PPP_INSTANCE_INTERFACE) == 0)
    return &instance_interface;
  return NULL;
}

/**
 * Called before the plugin module is unloaded.
 */
PP_EXPORT void
PPP_ShutdownModule()
{
  toQuit = true;
  void *null;
  pthread_join(interpret_thread, &null);
  pthread_mutex_destroy(&image_mutex);
}

static void 
DestroyContext(PP_Instance instance)
{
  strcat(status, isContextValid() ? "destroy good\n" : "destroy bad\n");
  if (isContextValid()) {
    pthread_mutex_lock(&image_mutex);
    core_->ReleaseResource(gc);
    gc = 0;
    core_->ReleaseResource(image);
    image = 0;
    pthread_mutex_unlock(&image_mutex);
  }
}

static void
CreateContext(PP_Instance instance, const struct PP_Size* size)
{
  if (isContextValid())
    return;

  strcat(status, "making gc\n");
  sprintf(buffer, "size: %d, %d\n", (int)size->width, (int)size->height);
  strcat(status, buffer);
  pthread_mutex_lock(&image_mutex);
  gc = graphics_2d_->Create(instance, size, false);
  if (!isContextValid() /*graphics_2d_->IsGraphics2D(gc)*/)
    strcat(status, "failed to create gc\n");
  if (!instance_->BindGraphics(instance, gc)) {
    strcat(status, "couldn't bind gc\n");
  }

  strcat(status, "make image\n");
  image = image_data_->Create(instance, PP_IMAGEDATAFORMAT_BGRA_PREMUL,
				size,
				PP_FALSE);
  getDesc();
  sprintf(buffer, "desc %d, %d, %d, %d\n", (int)desc.format, (int)desc.size.width, (int)desc.size.height, (int)desc.stride);
  {
    uint32_t *pixels = image_data_->Map(image);
    int i, j;
    for (j = 0; j < screenHeight; j++) {
      for (i = 0; i < screenWidth; i++) {
	pixels[j*(screenStride/4)+i] = (j<<24)+ (i<<8) + 0xFF;
      }
    }
    image_data_->Unmap(image);
  }
  pthread_mutex_unlock(&image_mutex);
  {
    int ret = pthread_create(&interpret_thread, NULL, runInterpret, NULL);
    sprintf(buffer, "thread create %d\n", ret);
    strcat(status, buffer);
  }
}

static void
FlushCallback(void *user_data, int32_t result)
{
  flush_pending = 0;
}

static struct PP_CompletionCallback CompletionCallback = {FlushCallback, 0};

static void
FlushPixelBuffer()
{
  struct PP_Point top_left;
  /*  struct PP_Rect src_left = NULL;*/
  top_left.x = 0;
  top_left.y = 0;
  if (!isContextValid() /*!(graphics_2d_->IsGraphics2D(gc))*/) {
    flush_pending = 0;
    return;
  }
  graphics_2d_->PaintImageData(gc, image, &top_left, NULL);
  flush_pending = 1;
  graphics_2d_->Flush(gc, CompletionCallback);
}

static void
Paint()
{
  if (!flush_pending) {
    FlushPixelBuffer();
  }
}

static PP_Bool
isContextValid()
{
  return gc != 0;
}

int32_t
ioShowDisplay(uint32_t *dispBits, int32_t width, int32_t height, int32_t depth, int32_t aL, int32_t aR, int32_t aT, int32_t aB)
{
  uint32_t *pixels;
  int i, j;
  if (toQuit) {
    pthread_exit(NULL);
  }
  pthread_mutex_lock(&image_mutex);
  if (isContextValid()) {
    pixels = image_data_->Map(image);
    for (j = 0; j < screenHeight; j++) {
      for (i = 0; i < screenWidth; i++) {
	pixels[j*(screenStride/4)+i] = dispBits[j*width+i];
      }
    }
    image_data_->Unmap(image);
    /*FlushPixelBuffer();*/
  }
  pthread_mutex_unlock(&image_mutex);
  return 0;
}

void*
runInterpret(void *arg)
{
  strcat(status, "run interpret\n");
  interpret();
  return NULL;
}

int32_t
interpret()
{
  struct timeval tv;
  uint32_t *display = core_->MemAlloc(200*200*4);
  gettimeofday(&tv, NULL);
  time_t start = (tv.tv_sec * 1000 * 1000) + tv.tv_usec;
  sprintf(buffer, "start: %ld\n", (long int)start);
  strcat(status, buffer);
  while(1) {
    struct timeval tv2;
    gettimeofday(&tv2, NULL);
    time_t now = (tv.tv_sec * 1000 * 1000) + tv.tv_usec;
    count += now;
    if (1/*(count%0x100) == 0*/) {
      unsigned char r, g = 0, b;
      uint32_t i, j;
      r = (unsigned char)(mouseX);
      b = (unsigned char)(mouseY);
      for (j = 0; j < 200; j++) {
	g = j;
	for (i = 0; i < 200; i++) {
	  uint32_t c = (((r+i)&0xFF) << 24) + ((g&0xFF) << 16) + (((b+j)&0xFF) << 8) + 0xFF;
	  display[j*200+i] = c;
	}
      }
      ioShowDisplay(display, 200, 200, 32, 0, 200, 0, 200);
    }
  }
  return 0;
}
