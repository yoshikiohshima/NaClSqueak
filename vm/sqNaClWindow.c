/* sqUnixCustomWindow.c -- support for display via your custom window system.
 * 
 * Last edited: 2008-04-21 14:06:20 by piumarta on emilia
 * 
 * This is a template for creating your own window drivers for Squeak:
 * 
 *   - copy the entire contents of this directory to some other name
 *   - rename this file to be something more appropriate
 *   - modify acinclude.m4, Makefile.in, and ../vm/sqUnixMain accordingly
 *   - implement all the stubs in this file that currently do nothing
 * 
 */

#include "sq.h"
#include "sqMemoryAccess.h"

#include "sqUnixMain.h"
#include "sqUnixGlobals.h"
/*#include "sqUnixCharConv.h"*/		/* not required, but probably useful */
/*#include "aio.h"*/			/* ditto */

#include "SqDisplay.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <pthread.h>
/* #include <sys/time.h> */

#include "sqNaClWindow.h"
#include "sqUnixEvent.c"		/* see X11 and/or Quartz drivers for examples */

char LogStatus[10000];
char LogBuffer[1024];

static int flush_display_requested;
static uint32_t *double_buffer;
static uint32_t *pixels;

static PP_Bool isContextValid();

void
Log(char* message)
{
  int slen = strlen(LogStatus);
  int mlen = strlen(message);
  if (slen <= mlen)
    LogStatus[0] = '\0';
  else if (slen + mlen >= sizeof(LogStatus))
    memmove(LogStatus, LogStatus + mlen, slen - mlen + 1);
  strcat(LogStatus, message);
}

char*
NaClStatus()
{
  return LogStatus;
}

static const struct PPB_Graphics2D* graphics_2d_;
static const struct PPB_ImageData* image_data_;
static const struct PPB_Instance* instance_;
const struct PPB_Core* core_;

static PP_Resource gc = 0;
static PP_Resource image = 0;
pthread_mutex_t image_mutex;
pthread_t interpret_thread;
int32_t flush_pending;
int32_t toQuit = 0;

static struct PP_ImageDataDesc desc;

static int32_t screenWidth;
static int32_t screenHeight;
static int32_t screenStride;

static int translateCode(int code)
{
  switch (code)
    {
#if 0
    case XK_Left:	return 28;
    case XK_Up:		return 30;
    case XK_Right:	return 29;
    case XK_Down:	return 31;
    case XK_Insert:	return  5;
    case XK_Prior:	return 11;	/* page up */
    case XK_Next:	return 12;	/* page down */
    case XK_Home:	return  1;
    case XK_End:	return  4;

    case XK_KP_Left:	return 28;
    case XK_KP_Up:	return 30;
    case XK_KP_Right:	return 29;
    case XK_KP_Down:	return 31;
    case XK_KP_Insert:	return  5;
    case XK_KP_Prior:	return 11;	/* page up */
    case XK_KP_Next:	return 12;	/* page down */
    case XK_KP_Home:	return  1;
    case XK_KP_End:	return  4;
#endif
    default:		return -1;
    }
  /*NOTREACHED*/
}


static int nacl2sqButton(int button)
{
  if (button == PP_INPUTEVENT_MOUSEBUTTON_LEFT) {
    return RedButtonBit;
  } else if (button == PP_INPUTEVENT_MOUSEBUTTON_MIDDLE) {
    return YellowButtonBit;
  } else if (button == PP_INPUTEVENT_MOUSEBUTTON_RIGHT) {
    return BlueButtonBit;
  }
  return 0;
}

static int nacl2sqModifier(uint32_t state)
{
  int mods = 0;

  if (state & PP_INPUTEVENT_MODIFIER_SHIFTKEY) {
    mods |= ShiftKeyBit;
  }
  if (state & PP_INPUTEVENT_MODIFIER_CONTROLKEY) {
    mods |= CtrlKeyBit;
  }
  if (state & PP_INPUTEVENT_MODIFIER_ALTKEY) {
    mods |= CommandKeyBit;
  }
  if (state & PP_INPUTEVENT_MODIFIER_METAKEY) {
    mods |= OptionKeyBit;
  }
  //  fprintf(stderr, "mods = %d\n", (int)mods);
  return mods;
}

#define trace() fprintf(stderr, "%s:%d %s\n", __FILE__, __LINE__, __FUNCTION__)

static void
noteMouseEventPosition(const struct PP_InputEvent_Mouse *evt)
{
  mousePosition.x = evt->x;
  mousePosition.y = evt->y;
}
  
static void
noteMouseEventState(const struct PP_InputEvent_Mouse* evt)
{
  noteMouseEventPosition(evt);
  modifierState = nacl2sqModifier(evt->modifier);
}

static void
noteKeyEventState(const struct PP_InputEvent_Key* evt)
{
  modifierState = nacl2sqModifier(evt->modifier);
}

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

static void 
DestroyContext(PP_Instance instance)
{
  Log(isContextValid() ? "destroy good\n" : "destroy empty\n");
  if (isContextValid()) {
    core_->ReleaseResource(gc);
    gc = 0;
    core_->ReleaseResource(image);
    image = 0;
    if (double_buffer) {
      free(double_buffer);
      double_buffer = 0;
    }
  }
}

static void
CreateContext(PP_Instance instance, const struct PP_Size* size)
{
  if (isContextValid())
    return;

  Log("making gc\n");
  sprintf(LogBuffer, "size: %d, %d\n", (int)size->width, (int)size->height);
  Log(LogBuffer);
  pthread_mutex_lock(&image_mutex);
  gc = graphics_2d_->Create(instance, size, false);
  if (!isContextValid() /*graphics_2d_->IsGraphics2D(gc)*/) {
    Log("failed to create gc\n");
  }
  if (!instance_->BindGraphics(instance, gc)) {
    Log("couldn't bind gc\n");
  }
  image = image_data_->Create(instance, PP_IMAGEDATAFORMAT_BGRA_PREMUL,
				size,
				PP_FALSE);
  getDesc();
  double_buffer = malloc(size->width * size->height * sizeof(uint32_t));
  pthread_mutex_unlock(&image_mutex);
}

static void
FlushCallback(void *user_data, int32_t result)
{
  flush_pending = 0;
}

static struct PP_CompletionCallback CompletionCallback = {FlushCallback, 0};

void
FlushPixelBuffer()
{
  struct PP_Point top_left;
  int i, j;
  top_left.x = 0;
  top_left.y = 0;
  if (!isContextValid()) {
    flush_pending = 0;
    return;
  }
  pthread_mutex_lock(&image_mutex);
  pixels = image_data_->Map(image);
  for (j = 0; j < screenHeight; j++) {
    for (i = 0; i < screenWidth; i++) {
      pixels[j*(screenStride/4)+i] = double_buffer[j*screenWidth+i];
    }
  }
  image_data_->Unmap(image);
  graphics_2d_->PaintImageData(gc, image, &top_left, NULL);
  pthread_mutex_unlock(&image_mutex);
  flush_pending = 1;
  graphics_2d_->Flush(gc, CompletionCallback);
}

void
Paint()
{
  if (flush_display_requested) {
    FlushPixelBuffer();
    flush_display_requested = 0;
  }
}

static PP_Bool
isContextValid()
{
  return gc != 0;
}

void
NaCl_DidChangeView(PP_Instance instance,
		       const struct PP_Rect* position,
		       const struct PP_Rect* clip)
{
  if (position->size.width == screenWidth &&
      position->size.height == screenHeight)
    return;  // Size didn't change, no need to update anything.
  Log("change view\n");
  DestroyContext(instance);
  CreateContext(instance, &position->size);
}

PP_Bool
NaCl_HandleInputEvent(PP_Instance instance,
		      const struct PP_InputEvent* evt)
{
  switch (evt->type) {
  case PP_INPUTEVENT_TYPE_MOUSEDOWN:
    noteMouseEventState(&evt->u.mouse);
    switch (evt->u.mouse.button) {
    case PP_INPUTEVENT_MOUSEBUTTON_NONE: case PP_INPUTEVENT_MOUSEBUTTON_LEFT: case PP_INPUTEVENT_MOUSEBUTTON_MIDDLE: case PP_INPUTEVENT_MOUSEBUTTON_RIGHT:
      buttonState |= nacl2sqButton(evt->u.mouse.button);
      recordMouseEvent();
      Log("mouse down\n");
      break;
    }
    return PP_TRUE;
  case PP_INPUTEVENT_TYPE_MOUSEUP:
    noteMouseEventState(&evt->u.mouse);
    switch (evt->u.mouse.button) {
    case PP_INPUTEVENT_MOUSEBUTTON_NONE: case PP_INPUTEVENT_MOUSEBUTTON_LEFT: case PP_INPUTEVENT_MOUSEBUTTON_MIDDLE: case PP_INPUTEVENT_MOUSEBUTTON_RIGHT:
      buttonState &= ~nacl2sqButton(evt->u.mouse.button);
      recordMouseEvent();
      Log("mouse up\n");
      break;
    }
    return PP_TRUE;
  case PP_INPUTEVENT_TYPE_MOUSEMOVE:
    noteMouseEventState(&evt->u.mouse);
    recordMouseEvent();
    return PP_TRUE;
  case PP_INPUTEVENT_TYPE_KEYDOWN:
    noteKeyEventState(&evt->u.key);
    fprintf(stderr, "down: %d, %d\n", evt->u.key.key_code, evt->u.key.modifier);
    recordKeyboardEvent(evt->u.key.key_code, EventKeyDown, modifierState, evt->u.key.key_code);
    return PP_TRUE;
  case PP_INPUTEVENT_TYPE_CHAR:
    noteKeyEventState(&evt->u.key);
    fprintf(stderr, "char: %d, %d\n", evt->u.key.key_code, evt->u.key.modifier);
    recordKeyboardEvent(evt->u.key.key_code, EventKeyChar, modifierState, evt->u.key.key_code);
    return PP_TRUE;
  case PP_INPUTEVENT_TYPE_KEYUP:
    noteKeyEventState(&evt->u.key);
    fprintf(stderr, "up: %d, %d\n", evt->u.key.key_code, evt->u.key.modifier);
    recordKeyboardEvent(evt->u.key.key_code, EventKeyUp, modifierState, evt->u.key.key_code);
    return PP_TRUE;
  }
  return PP_FALSE;
}

void
NaCl_InitializeModule(PPB_GetInterface get_browser_interface)
{
  core_ = (const struct PPB_Core*)
    get_browser_interface(PPB_CORE_INTERFACE);
  instance_ = (const struct PPB_Instance*)
    get_browser_interface(PPB_INSTANCE_INTERFACE);
  graphics_2d_ = (const struct PPB_Graphics2D*)
   get_browser_interface(PPB_GRAPHICS_2D_INTERFACE);
  image_data_ = (const struct PPB_ImageData*)
   get_browser_interface(PPB_IMAGEDATA_INTERFACE);
  pthread_mutex_init(&image_mutex, NULL);
}

static int handleEvents(void)
{
  return !iebEmptyP(); /* 1 if events processed */
}

static sqInt display_clipboardSize(void)
{
  trace();
  return 0;
}

static sqInt display_clipboardWriteFromAt(sqInt count, sqInt byteArrayIndex, sqInt startIndex)
{
  trace();
  return 0;
}

static sqInt display_clipboardReadIntoAt(sqInt count, sqInt byteArrayIndex, sqInt startIndex)
{
  trace();
  return 0;
}


static char ** display_clipboardGetTypeNames(void)
{
  trace();
  return 0;
}

static sqInt display_clipboardSizeWithType(char *typeName, int ntypeName)
{
  trace();
  return 0;
}

static void display_clipboardWriteWithType(char *data, size_t ndata, char *typeName, size_t ntypeName, int isDnd, int isClaiming)
{
  trace();
}

static sqInt display_dndOutStart(char *types, int ntypes)
{
  trace();
  return 0;
}

static void display_dndOutSend (char *bytes, int nbytes)
{
  trace();
}

static sqInt display_dndOutAcceptedType(char * buf, int nbuf)
{
  trace();
  return 0;
}

static sqInt display_ioFormPrint(sqInt bitsIndex, sqInt width, sqInt height, sqInt depth, double hScale, double vScale, sqInt landscapeFlag)
{
  trace();
  return false;
}

static sqInt display_ioBeep(void)
{
  trace();
  return 0;
}

static sqInt display_ioRelinquishProcessorForMicroseconds(sqInt microSeconds)
{
  /* aioSleep(handleEvents() ? 0 : microSeconds); */
  return 0;
}

static sqInt display_ioProcessEvents(void)
{
  handleEvents();
  /* aioPoll(0); */
  return 0;
}

static sqInt display_ioScreenDepth(void)
{
  return 32;
}

static sqInt display_ioScreenSize(void)
{
  return (screenWidth << 16) | screenHeight;
}

static sqInt display_ioSetCursorWithMask(sqInt cursorBitsIndex, sqInt cursorMaskIndex, sqInt offsetX, sqInt offsetY)
{
  return 0;
}

static sqInt display_ioSetCursorARGB(sqInt cursorBitsIndex, sqInt extentX, sqInt extentY, sqInt offsetX, sqInt offsetY)
{
  return 0;
}

static sqInt display_ioSetFullScreen(sqInt fullScreen)
{
  return 0;
}

static sqInt display_ioForceDisplayUpdate(void)
{
  return 0;
}

static sqInt display_ioShowDisplay(sqInt dispBitsIndex, sqInt width, sqInt height, sqInt depth,
				   sqInt affectedL, sqInt affectedR, sqInt affectedT, sqInt affectedB)
{
#define max(x, y) ((x) > (y) ? (x) : (y))
#define min(x, y) ((x) < (y) ? (x) : (y))
  if (toQuit) {
    pthread_exit(NULL);
  }
  if (!isContextValid()) {
    return 0;
  }
  if (depth == 32) {
    uint32_t *dispBits= (uint32_t*)pointerForOop(dispBitsIndex);
    int i, j;
    for (j = max(affectedT, 0); j < min(affectedB, screenHeight); j++) {
      for (i = max(affectedL, 0); i < min(affectedR, screenWidth); i++) {
	double_buffer[j*(screenStride/4)+i] = dispBits[j*width+i];
      }
    }
  }
  if (depth == 16) {
    uint32_t col;
    uint32_t *dispBits= (uint32_t*)pointerForOop(dispBitsIndex);
    uint32_t word;
    int i, j;
#define hiword(x) (x>>16)
#define loword(x) (x&0xFFFF)
#define map16To32(w) (col= (w), \
		      ((((col >> 10) & 0x1f) * 255 / 31) << 16) | \
		      ((((col >> 5) & 0x1f) * 255 / 31) << 8)   | \
		      ((((col >> 0) & 0x1f) * 255 / 31) << 0)   | \
		      0xFF000000)

    for (j = max(affectedT, 0); j < min(affectedB, screenHeight); j++) {
      i = max(affectedL, 0);
      while (i < min(affectedR, screenWidth)) {
	if (i % 2) {
	  double_buffer[j*(screenStride/4)+i] = map16To32(loword(dispBits[(j*width+i)/2]));
	  i++;
	}
	word = dispBits[(j*width+i)/2];
	double_buffer[j*(screenStride/4)+i] = map16To32(hiword(word));
	i++;
	double_buffer[j*(screenStride/4)+i] = map16To32(loword(word));
	i++;
	if (min(affectedR, screenWidth) - i == 1) {
	  double_buffer[j*(screenStride/4)+i] = map16To32(hiword(dispBits[(j*width+i)/2]));
	  i++;
	}
      }
    }
  }
#undef hiword
#undef loword
#undef map16To32
#undef max
#undef min

  flush_display_requested = 1;
  return 0;
}

static sqInt display_ioHasDisplayDepth(sqInt i)
{
  return 32 == i || 16 == i;
}

static sqInt display_ioSetDisplayMode(sqInt width, sqInt height, sqInt depth, sqInt fullscreenFlag)
{
  return 0;
}

static void display_winSetName(char *imageName)
{
}

static void *display_ioGetDisplay(void)	{ return 0; }
static void *display_ioGetWindow(void)	{ return 0; }

static sqInt display_ioGLinitialise(void) { trace();  return 0; }
static sqInt display_ioGLcreateRenderer(glRenderer *r, sqInt x, sqInt y, sqInt w, sqInt h, sqInt flags) { trace();  return 0; }
static void  display_ioGLdestroyRenderer(glRenderer *r) { trace(); }
static void  display_ioGLswapBuffers(glRenderer *r) { trace(); }
static sqInt display_ioGLmakeCurrentRenderer(glRenderer *r) { trace();  return 0; }
static void  display_ioGLsetBufferRect(glRenderer *r, sqInt x, sqInt y, sqInt w, sqInt h) { trace(); }

static char *display_winSystemName(void)
{
  return "NaCl";
}

static void display_winInit(void)
{
}

static void display_winOpen(void)
{
}


static void display_winExit(void)
{
}

static int  display_winImageFind(char *buf, int len)		{ trace();  return 0; }
static void display_winImageNotFound(void)			{ trace(); }

static sqInt display_primitivePluginBrowserReady(void)		{ return primitiveFail(); }
static sqInt display_primitivePluginRequestURLStream(void)	{ return primitiveFail(); }
static sqInt display_primitivePluginRequestURL(void)		{ return primitiveFail(); }
static sqInt display_primitivePluginPostURL(void)		{ return primitiveFail(); }
static sqInt display_primitivePluginRequestFileHandle(void)	{ return primitiveFail(); }
static sqInt display_primitivePluginDestroyRequest(void)	{ return primitiveFail(); }
static sqInt display_primitivePluginRequestState(void)		{ return primitiveFail(); }

#if (SqDisplayVersionMajor >= 1 && SqDisplayVersionMinor >= 2)
static int display_hostWindowClose(int index)                                               { return 0; }
static int display_hostWindowCreate(int w, int h, int x, int y,
  char *list, int attributeListLength)                                                      { return 0; }
static int display_hostWindowShowDisplay(unsigned *dispBitsIndex, int width, int height, int depth,
  int affectedL, int affectedR, int affectedT, int affectedB, int windowIndex)              { return 0; }
static int display_hostWindowGetSize(int windowIndex)                                       { return -1; }
static int display_hostWindowSetSize(int windowIndex, int w, int h)                         { return -1; }
static int display_hostWindowGetPosition(int windowIndex)                                   { return -1; }
static int display_hostWindowSetPosition(int windowIndex, int x, int y)                     { return -1; }
static int display_hostWindowSetTitle(int windowIndex, char *newTitle, int sizeOfTitle)     { return -1; }
static int display_hostWindowCloseAll(void)                                                 { return 0; }
#endif

SqDisplayDefine(nacl);	/* name must match that in makeInterface() below */


/*** module ***/


static void display_printUsage(void)
{
}

static void display_printUsageNotes(void)
{
}

static void display_parseEnvironment(void)
{
}

static int display_parseArgument(int argc, char **argv)
{
  return 0;	/* arg not recognised */
}

static void *display_makeInterface(void)
{
  return &display_nacl_itf;		/* name must match that in SqDisplayDefine() above */
}

#include "SqModule.h"

SqModuleDefine(display, nacl);		/* name must match that in sqUnixMain.c's moduleDescriptions */

struct SqModule *
nacl_display_module()
{
  return &display_nacl;
}

int vm_serial = 0;
char vm_date[] = "1234";
char cc_version[] = "nacl";
char ux_version[] = "nacl";

