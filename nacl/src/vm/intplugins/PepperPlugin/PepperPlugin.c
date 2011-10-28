/* Automatically generated from Squeak on 28 October 2011 10:09:02 am 
   by VMMaker 4.4.7
 */

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/* Default EXPORT macro that does nothing (see comment in sq.h): */
#define EXPORT(returnType) returnType

/* Do not include the entire sq.h file but just those parts needed. */
/*  The virtual machine proxy definition */
#include "sqVirtualMachine.h"
/* Configuration options */
#include "sqConfig.h"
/* Platform specific definitions */
#include "sqPlatformSpecific.h"

#define true 1
#define false 0
#define null 0  /* using 'null' because nil is predefined in Think C */
#ifdef SQUEAK_BUILTIN_PLUGIN
#undef EXPORT
// was #undef EXPORT(returnType) but screws NorCroft cc
#define EXPORT(returnType) static returnType
#endif
#include "PepperPlugin.h"

#include "sqMemoryAccess.h"


/*** Constants ***/

/*** Function Prototypes ***/
static VirtualMachine * getInterpreter(void);
#pragma export on
EXPORT(const char*) getModuleName(void);
#pragma export off
static sqInt halt(void);
#pragma export on
EXPORT(sqInt) handleMessage(void);
#pragma export off
static sqInt msg(char *s);
static sqInt newString(sqInt size);
#pragma export on
EXPORT(sqInt) postMessage(void);
EXPORT(sqInt) setInterpreter(struct VirtualMachine*anInterpreter);
EXPORT(sqInt) setMessagingSemaphoreIndex(void);
#pragma export off
static void sqSignalMessagingSemaphore(void);
/*** Variables ***/

#ifdef SQUEAK_BUILTIN_PLUGIN
extern
#endif
struct VirtualMachine* interpreterProxy;
static sqInt messagingSema;
static const char *moduleName =
#ifdef SQUEAK_BUILTIN_PLUGIN
	"PepperPlugin 28 October 2011 (i)"
#else
	"PepperPlugin 28 October 2011 (e)"
#endif
;



/*	Note: This is coded so that plugins can be run from Squeak. */

static VirtualMachine * getInterpreter(void) {
	return interpreterProxy;
}


/*	Note: This is hardcoded so it can be run from Squeak.
	The module name is used for validating a module *after*
	it is loaded to check if it does really contain the module
	we're thinking it contains. This is important! */

EXPORT(const char*) getModuleName(void) {
	return moduleName;
}

static sqInt halt(void) {
	;
}

EXPORT(sqInt) handleMessage(void) {
    sqInt val;

	val = read_from_browser_to_sq(newString);
	interpreterProxy->pop((interpreterProxy->methodArgumentCount()) + 1);
	interpreterProxy->push(val);
	return 1;
}

static sqInt msg(char *s) {
	fprintf(stderr, "\n%s: %s", moduleName, s);
}

static sqInt newString(sqInt size) {
	return interpreterProxy->instantiateClassindexableSize(interpreterProxy->classByteArray(), size);
}

EXPORT(sqInt) postMessage(void) {
    sqInt sqOop;
    char *sqStr;
    sqInt stSize;

	sqOop = interpreterProxy->stackObjectValue(0);
	if (!(interpreterProxy->isBytes(sqOop))) {
		interpreterProxy->primitiveFail();
		return null;
	}
	sqStr = interpreterProxy->firstIndexableField(sqOop);
	stSize = interpreterProxy->stSizeOf(sqOop);
	send_from_sq_to_browser(sqStr, stSize);
	if ((interpreterProxy->methodArgumentCount()) == 1) {
		interpreterProxy->pop(1);
	}
	return 1;
}


/*	Note: This is coded so that is can be run from Squeak. */

EXPORT(sqInt) setInterpreter(struct VirtualMachine*anInterpreter) {
    sqInt ok;

	interpreterProxy = anInterpreter;
	ok = interpreterProxy->majorVersion() == VM_PROXY_MAJOR;
	if (ok == 0) {
		return 0;
	}
	ok = interpreterProxy->minorVersion() >= VM_PROXY_MINOR;
	return ok;
}

EXPORT(sqInt) setMessagingSemaphoreIndex(void) {
    sqInt semaIndex;

	semaIndex = interpreterProxy->stackIntegerValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	messagingSema = semaIndex;
	set_signaler(sqSignalMessagingSemaphore);
	if ((interpreterProxy->methodArgumentCount()) == 1) {
		interpreterProxy->pop(1);
	}
	return 1;
}

static void sqSignalMessagingSemaphore(void) {
	if (messagingSema > 0) {
		interpreterProxy->signalSemaphoreWithIndex(messagingSema);
	}
}


#ifdef SQUEAK_BUILTIN_PLUGIN


void* PepperPlugin_exports[][3] = {
	{"PepperPlugin", "setMessagingSemaphoreIndex", (void*)setMessagingSemaphoreIndex},
	{"PepperPlugin", "getModuleName", (void*)getModuleName},
	{"PepperPlugin", "setInterpreter", (void*)setInterpreter},
	{"PepperPlugin", "postMessage", (void*)postMessage},
	{"PepperPlugin", "handleMessage", (void*)handleMessage},
	{NULL, NULL, NULL}
};


#endif /* ifdef SQ_BUILTIN_PLUGIN */

