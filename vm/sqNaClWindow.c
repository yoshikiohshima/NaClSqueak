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
#include "sqUnixCharConv.h"		/* not required, but probably useful */
#include "aio.h"			/* ditto */

#include "SqDisplay.h"

#include <stdio.h>

#include "sqUnixEvent.c"		/* see X11 and/or Quartz drivers for examples */


#define trace() fprintf(stderr, "%s:%d %s\n", __FILE__, __LINE__, __FUNCTION__)

static int handleEvents(void)
{
  printf("handle custom events here...\n");
  return 0;	/* 1 if events processed */
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
  aioSleep(handleEvents() ? 0 : microSeconds);
  return 0;
}

static sqInt display_ioProcessEvents(void)
{
  handleEvents();
  aioPoll(0);
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
  return 0;
}

static sqInt display_ioHasDisplayDepth(sqInt i)
{
  trace();
  return 32 == i;
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
  return "Custom";
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
  printf("\nCustom Window <option>s: (none)\n");
  /* otherwise... */
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