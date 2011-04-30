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

#include "sqUnixEvent.c"		/* see X11 and/or Quartz drivers for examples */
#include "sqNaClWindow.h"

char LogStatus[100000];
char LogBuffer[10240];

int flush_display_requested;

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
  int mods= 0;
  if (0)
    {
    }
  else
    {
      enum { _= 0, S= ShiftKeyBit, C= CtrlKeyBit, O= OptionKeyBit, M= CommandKeyBit };
      static char midofiers[32]= {	/* ALT=Cmd, META=ignored, C-ALT=Opt, META=ignored */
       	/*                - -       - S       L -       L S */
       	/* - - - - */ _|_|_|_,  _|_|_|S,  _|_|_|_,  _|_|_|S,
       	/* - - - C */ _|_|C|_,  _|_|C|S,  _|_|C|_,  _|_|C|S,
       	/* - - A - */ _|M|_|_,  _|M|_|S,  _|M|_|_,  _|M|_|S,
       	/* - - A C */ O|_|_|_,  O|_|_|S,  O|_|_|_,  O|_|_|S,
       	/*                - -       - S       L -       L S */
       	/* M - - - */ _|M|_|_,  _|M|_|S,  _|M|_|_,  _|M|_|S,
       	/* M - - C */ _|M|C|_,  _|M|C|S,  _|M|C|_,  _|M|C|S,
       	/* M - A - */ _|M|_|_,  _|M|_|S,  _|M|_|_,  _|M|_|S,
       	/* M - A C */ O|_|_|_,  O|M|_|S,  O|M|_|_,  O|M|_|S,
      };
#    if defined(__POWERPC__) || defined(__ppc__)
      mods= midofiers[state & 0x1f];
#    else
      mods= midofiers[state & 0x0f];
#    endif
#    if defined(DEBUG_EVENTS)
      fprintf(stderr, "X mod %x -> Sq mod %x (default)\n", state & 0xf, mods);
#    endif
    }
  return mods;
}

#define trace() fprintf(stderr, "%s:%d %s\n", __FILE__, __LINE__, __FUNCTION__)
/*#define trace() do {sprintf(LogBuffer, "%s:%d %s\n", __FILE__, __LINE__, __FUNCTION__); Log(LogBuffer);} while(0) */

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
  Log(isContextValid() ? "destroy good\n" : "destroy bad\n");
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

  Log("make image\n");
  image = image_data_->Create(instance, PP_IMAGEDATAFORMAT_BGRA_PREMUL,
				size,
				PP_FALSE);
  getDesc();
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
    case 1: case 2: case 3:
      buttonState &= ~nacl2sqButton(evt->u.mouse.button);
      recordMouseEvent();
      break;
    }
    return PP_TRUE;
  case PP_INPUTEVENT_TYPE_MOUSEMOVE:
    noteMouseEventState(&evt->u.mouse);
    recordMouseEvent();
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
  trace();
  return 32;
}

static sqInt display_ioScreenSize(void)
{
  trace();
  return (600 << 16) | 400;
}

static sqInt display_ioSetCursorWithMask(sqInt cursorBitsIndex, sqInt cursorMaskIndex, sqInt offsetX, sqInt offsetY)
{
  trace();
  return 0;
}

static sqInt display_ioSetCursorARGB(sqInt cursorBitsIndex, sqInt extentX, sqInt extentY, sqInt offsetX, sqInt offsetY)
{
  trace();
  return 0;
}

static sqInt display_ioSetFullScreen(sqInt fullScreen)
{
  trace();
  return 0;
}

static sqInt display_ioForceDisplayUpdate(void)
{
  trace();
  return 0;
}

static sqInt display_ioShowDisplay(sqInt dispBitsIndex, sqInt width, sqInt height, sqInt depth,
				   sqInt affectedL, sqInt affectedR, sqInt affectedT, sqInt affectedB)
{
  trace();
  if (toQuit) {
    pthread_exit(NULL);
  }
  uint32_t *dispBits= pointerForOop(dispBitsIndex);
  uint32_t *pixels;
  int i, j;
  pthread_mutex_lock(&image_mutex);
  if (isContextValid()) {
    pixels = image_data_->Map(image);
    for (j = 0; j < screenHeight; j++) {
      for (i = 0; i < screenWidth; i++) {
	pixels[j*(screenStride/4)+i] = dispBits[j*width+i];
      }
    }
    image_data_->Unmap(image);
  }
  pthread_mutex_unlock(&image_mutex);
  flush_display_requested = 1;
  return 0;
}

static sqInt display_ioHasDisplayDepth(sqInt i)
{
  trace();
  return 32 == i || 16 == i;
}

static sqInt display_ioSetDisplayMode(sqInt width, sqInt height, sqInt depth, sqInt fullscreenFlag)
{
  trace();
  return 0;
}

static void display_winSetName(char *imageName)
{
  trace();
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
  trace();
  return "NaCl";
}

static void display_winInit(void)
{
  trace();
  printf("Initialise your Custom Window system here\n");
}

static void display_winOpen(void)
{
  trace();
  printf("map your Custom Window here\n");
}


static void display_winExit(void)
{
  trace();
  printf("shut down your Custom Window system here\n");
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
  trace();
}

static void display_parseEnvironment(void)
{
  trace();
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

