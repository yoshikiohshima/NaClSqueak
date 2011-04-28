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
#include <ppapi/c/ppb_var.h>
/*
#include <ppapi/c/ppb_url_loader.h>
#include <ppapi/c/ppb_url_request_info.h>
#include <ppapi/c/ppb_url_response_info.h>

#include <ppapi/c/pp_completion_callback.h>
*/
#include "sqNaClWindow.h"

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

void* runInterpret(void *arg);

static struct PPB_Var_Deprecated* var_interface = NULL;
static struct PPP_Class_Deprecated ppp_class;
static PP_Module module_id = 0;
const struct PPB_Instance* instance_;
/*
const struct PPB_URLLoader* loader_;
const struct PPB_URLRequestInfo* requestInfo_;
const struct PPB_URLResponseInfo* responseInfo_;
*/

/*
static PP_Resource loader = 0;
static PP_Resource requestInfo = 0;
static PP_Resource responseInfo = 0;
*/
static const char* const kPaintMethodId = "paint";
static const char* const kGetStatusMethodId = "getStatus";
/* static const char* const kGetLoaderStatusMethodId = "getLoaderStatus"; */
static const char* const kLoadImageMethodId = "loadImage";
static const char* const kSetImageSizeMethodId = "setImageSize";

/* struct PP_Var loader_status; */

static struct PPP_Instance instance_interface = {
  &Instance_DidCreate,
  &Instance_DidDestroy,
  &Instance_DidChangeView,
  &Instance_DidChangeFocus,
  &Instance_HandleInputEvent,
  NULL,  /* HandleDocumentLoad is not supported by NaCl modules. */
  &Instance_GetInstanceObject,
};

static int32_t
GetInteger(struct PP_Var var)
{
  uint32_t headerLen;
  int32_t len;
  char c;
  const char *cStr = var_interface->VarToUtf8(var, &headerLen);
  len = 0;
  c = *cStr++;
  while ('0' <= c && c <= '9') {
    len *= 10;
    len += (c - '0');
    c = *cStr++;
  }
  return len;
}

static const char cd64[]="|$$$}rstuvwxyz{$$$$$$$>?@ABCDEFGHIJKLMNOPQRSTUVW$$$$$$XYZ[\\]^_`abcdefghijklmnopq";

void
decodeblock(unsigned char in[4], unsigned char out[3])
{   
  out[ 0 ] = (unsigned char) (in[0] << 2 | in[1] >> 4);
  out[ 1 ] = (unsigned char) (in[1] << 4 | in[2] >> 2);
  out[ 2 ] = (unsigned char) (((in[2] << 6) & 0xc0) | in[3]);
}

int
decode(char *input, int input_size, char *output, int output_index)
{
  unsigned char in[4], out[3], v;
  int i, len;
  int s = 0;

  while (s < input_size) {
    for (len = 0, i = 0; i < 4 && s < input_size; i++) {
      v = 0;
      while (v == 0) {
	v = (unsigned char)input[s++];
	v = (unsigned char)((v < 43 || v > 122) ? 0 : cd64[v - 43]);
	if(v) {
	  v = (unsigned char)((v == '$') ? 0 : v - 61);
	}
      }
      if (s < input_size) {
	len++;
	if (v) {
	  in[i] = (unsigned char)(v - 1);
	}
      } else {
	in[i] = 0;
      }
    }
    if (len) {
      decodeblock(in, out);
      for (i = 0; i < len - 1; i++) {
	output[output_index++] = out[i];
      }
    }
  }
  return output_index;
}

#if 0
static int32_t
GetContentLength(struct PP_Var var)
{
  uint32_t headerLen;
  int32_t len;
  char c;
  const char *cStr = var_interface->VarToUtf8(var, &headerLen);
  char *occurence;
  occurence = strstr(cStr, "Content-Length: ");
  if (!occurence) {
    return -1;
  }
  occurence += strlen("Content-Length: ");
  len = 0;
  c = *occurence++;
  while ('0' <= c && c <= '9') {
    len *= 10;
    len += (c - '0');
    c = *occurence++;
  }
  return len;
}
#endif

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

void
Paint()
{
  if (flush_display_requested) {
    FlushPixelBuffer();
    flush_display_requested = 0;
  }
}

char *image_file_buffer = NULL;
static int32_t image_file_size = 0;
static int32_t image_file_index = 0;

#if 0
static void
ReadCallback(void *user_data, int32_t result)
{
  sprintf(LogBuffer, "read result: %d\n", (int)result);
  Log(LogBuffer);
  loader = 0;
  /*pthread_create(&interpret_thread, NULL, runInterpret, NULL);*/
}

static struct PP_CompletionCallback ReadCompletionCallback = {ReadCallback, 0};

static void
LoadCallback(void *user_data, int32_t result)
{
  int32_t len;
  responseInfo = loader_->GetResponseInfo(loader);
  loader_status = responseInfo_->GetProperty(responseInfo, PP_URLRESPONSEPROPERTY_HEADERS);
  len = GetContentLength(loader_status);
  sprintf(LogBuffer, "len: %d\n", (int)len);
  Log(LogBuffer);
  if (len > 0) {
    image_file_buffer = malloc(len+10);
    Log (image_file_buffer ? "file buffer allocated\n" : "allocation failed\n");
    if (1) {
      loader_->ReadResponseBody(loader, image_file_buffer, len+10, ReadCompletionCallback);
      sprintf(LogBuffer, "read result: %d\n", (int)image_file_buffer[100000]);
    }else 
      loader = 0;
  }
}

static struct PP_CompletionCallback LoadCompletionCallback = {LoadCallback, 0};

#endif

struct PP_Var
SetImageSize(struct PP_Var data)
{
  image_file_size = GetInteger(data);
  sprintf(LogBuffer, "set size %d\n", (int)image_file_size);
  Log(LogBuffer);
  image_file_buffer = malloc(image_file_size);
  image_file_index = 0;
  return PP_MakeInt32(image_file_size);
}

struct PP_Var
LoadImage(struct PP_Var data)
{
  const char *buf = VarToCStr(data);
  sprintf(LogBuffer, "buf size %d\n", (int)strlen(buf));
  Log(LogBuffer);
  decode((char*)buf, strlen(buf), image_file_buffer, image_file_index);
  sprintf(LogBuffer, "buf pointer %d\n", (int)image_file_index);
  Log(LogBuffer);
  return PP_MakeInt32(image_file_index);
}

static PP_Bool
Instance_DidCreate(PP_Instance instance,
                                  uint32_t argc,
                                  const char* argn[],
                                  const char* argv[])
{

#if 0
    loader = loader_->Create(instance);
    requestInfo = requestInfo_->Create(instance);
    requestInfo_->SetProperty(requestInfo, PP_URLREQUESTPROPERTY_URL, StrToVar("http://localhost:5103/squeak/Etoys.image"));
    requestInfo_->SetProperty(requestInfo, PP_URLREQUESTPROPERTY_METHOD, StrToVar("GET"));
    loader_->Open(loader, requestInfo, LoadCompletionCallback);
    Log("loader open\n");
    return loader ? PP_TRUE : PP_FALSE;
#endif
  return PP_TRUE;
}

static void Instance_DidDestroy(PP_Instance instance) {
}

static void
Instance_DidChangeView(PP_Instance instance,
		       const struct PP_Rect* position,
		       const struct PP_Rect* clip)
{
  NaCl_DidChangeView(instance, position, clip);
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
  return NaCl_HandleInputEvent(instance, event);
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
    /*    if (strcmp(method_name, kGetLoaderStatusMethodId) == 0)
	  return true; */
    if (strcmp(method_name, kLoadImageMethodId) == 0)
      return true;
    if (strcmp(method_name, kSetImageSizeMethodId) == 0)
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
      return StrToVar(NaClStatus());
    /*if (strcmp(method_name, kGetLoaderStatusMethodId) == 0)
      return loader_status; */
    if (strcmp(method_name, kLoadImageMethodId) == 0) {
      return LoadImage(argv[0]);
    }
    if (strcmp(method_name, kSetImageSizeMethodId) == 0) {
      return SetImageSize(argv[0]);
    }
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
  /*  loader_ = (const struct PPB_URLLoader*)
    get_browser_interface(PPB_URLLOADER_INTERFACE);
  requestInfo_ = (const struct PPB_URLRequestInfo*)
    get_browser_interface(PPB_URLREQUESTINFO_INTERFACE);
  responseInfo_ = (const struct PPB_URLResponseInfo*)
    get_browser_interface(PPB_URLRESPONSEINFO_INTERFACE);
  */
  NaCl_InitializeModule(get_browser_interface);
  memset(&ppp_class, 0, sizeof(ppp_class));
  ppp_class.Call = Squeak_Call;
  ppp_class.HasMethod = Squeak_HasMethod;
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

void*
runInterpret(void *arg)
{
  Log("run interpret\n");
  char *argv[] = {"squeak", NULL};
    sqMain(1, argv, NULL);
  return NULL;
}
