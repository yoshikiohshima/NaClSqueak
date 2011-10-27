/* Automatically generated from Squeak on 26 October 2011 4:09:32 pm 
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
#include "SoundCodecPrims.h"

#include "sqMemoryAccess.h"


/*** Constants ***/

/*** Function Prototypes ***/
static VirtualMachine * getInterpreter(void);
#pragma export on
EXPORT(const char*) getModuleName(void);
#pragma export off
static sqInt halt(void);
static sqInt msg(char *s);
#pragma export on
EXPORT(sqInt) primitiveGSMDecode(void);
EXPORT(sqInt) primitiveGSMEncode(void);
EXPORT(sqInt) primitiveGSMNewState(void);
EXPORT(sqInt) setInterpreter(struct VirtualMachine*anInterpreter);
#pragma export off
/*** Variables ***/

#ifdef SQUEAK_BUILTIN_PLUGIN
extern
#endif
struct VirtualMachine* interpreterProxy;
static const char *moduleName =
#ifdef SQUEAK_BUILTIN_PLUGIN
	"SoundCodecPrims 26 October 2011 (i)"
#else
	"SoundCodecPrims 26 October 2011 (e)"
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

static sqInt msg(char *s) {
	fprintf(stderr, "\n%s: %s", moduleName, s);
}

EXPORT(sqInt) primitiveGSMDecode(void) {
    sqInt dst;
    sqInt dstDelta;
    sqInt dstIndex;
    sqInt dstSize;
    sqInt frameCount;
    sqInt result;
    sqInt src;
    sqInt srcDelta;
    sqInt srcIndex;
    sqInt srcSize;
    sqInt state;

	dstIndex = interpreterProxy->stackIntegerValue(0);
	dst = interpreterProxy->stackObjectValue(1);
	srcIndex = interpreterProxy->stackIntegerValue(2);
	src = interpreterProxy->stackObjectValue(3);
	frameCount = interpreterProxy->stackIntegerValue(4);
	state = interpreterProxy->stackObjectValue(5);
	interpreterProxy->success(interpreterProxy->isWords(dst));
	interpreterProxy->success(interpreterProxy->isBytes(src));
	interpreterProxy->success(interpreterProxy->isBytes(state));
	if (interpreterProxy->failed()) {
		return null;
	}
	srcSize = interpreterProxy->slotSizeOf(src);
	dstSize = (interpreterProxy->slotSizeOf(dst)) * 2;
	gsmDecode(state + 4, frameCount, src, srcIndex, srcSize, dst, dstIndex, dstSize, &srcDelta, &dstDelta);
	if (interpreterProxy->failed()) {
		return null;
	}
	result = interpreterProxy->makePointwithxValueyValue(srcDelta, dstDelta);
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->pop(6);
	interpreterProxy->push(result);
}

EXPORT(sqInt) primitiveGSMEncode(void) {
    sqInt dst;
    sqInt dstDelta;
    sqInt dstIndex;
    sqInt dstSize;
    sqInt frameCount;
    sqInt result;
    sqInt src;
    sqInt srcDelta;
    sqInt srcIndex;
    sqInt srcSize;
    sqInt state;

	dstIndex = interpreterProxy->stackIntegerValue(0);
	dst = interpreterProxy->stackObjectValue(1);
	srcIndex = interpreterProxy->stackIntegerValue(2);
	src = interpreterProxy->stackObjectValue(3);
	frameCount = interpreterProxy->stackIntegerValue(4);
	state = interpreterProxy->stackObjectValue(5);
	interpreterProxy->success(interpreterProxy->isBytes(dst));
	interpreterProxy->success(interpreterProxy->isWords(src));
	interpreterProxy->success(interpreterProxy->isBytes(state));
	if (interpreterProxy->failed()) {
		return null;
	}
	srcSize = (interpreterProxy->slotSizeOf(src)) * 2;
	dstSize = interpreterProxy->slotSizeOf(dst);
	gsmEncode(state + 4, frameCount, src, srcIndex, srcSize, dst, dstIndex, dstSize, &srcDelta, &dstDelta);
	if (interpreterProxy->failed()) {
		return null;
	}
	result = interpreterProxy->makePointwithxValueyValue(srcDelta, dstDelta);
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->pop(6);
	interpreterProxy->push(result);
}

EXPORT(sqInt) primitiveGSMNewState(void) {
    sqInt state;
    sqInt stateBytes;

	stateBytes = gsmStateBytes();
	state = interpreterProxy->instantiateClassindexableSize(interpreterProxy->classByteArray(), stateBytes);
	gsmInitState(state + 4);
	interpreterProxy->pop(1);
	interpreterProxy->push(state);
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


#ifdef SQUEAK_BUILTIN_PLUGIN


void* SoundCodecPrims_exports[][3] = {
	{"SoundCodecPrims", "setInterpreter", (void*)setInterpreter},
	{"SoundCodecPrims", "primitiveGSMEncode", (void*)primitiveGSMEncode},
	{"SoundCodecPrims", "primitiveGSMNewState", (void*)primitiveGSMNewState},
	{"SoundCodecPrims", "primitiveGSMDecode", (void*)primitiveGSMDecode},
	{"SoundCodecPrims", "getModuleName", (void*)getModuleName},
	{NULL, NULL, NULL}
};


#endif /* ifdef SQ_BUILTIN_PLUGIN */

