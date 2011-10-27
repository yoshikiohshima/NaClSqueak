/* Automatically generated from Squeak on 26 April 2011 1:22:14 pm 
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

#include "sqMemoryAccess.h"


/*** Constants ***/

/*** Function Prototypes ***/
static unsigned int * checkedUnsignedIntPtrOf(sqInt oop);
static VirtualMachine * getInterpreter(void);
#pragma export on
EXPORT(const char*) getModuleName(void);
#pragma export off
static sqInt halt(void);
static sqInt msg(char *s);
#pragma export on
EXPORT(sqInt) primitiveDiffuseFromToWidthHeightDelta(void);
EXPORT(sqInt) primitiveEvaporateRate(void);
EXPORT(sqInt) primitiveMapFromToWidthHeightPatchSizeRgbFlagsShift(void);
EXPORT(sqInt) setInterpreter(struct VirtualMachine*anInterpreter);
#pragma export off
/*** Variables ***/

#ifdef SQUEAK_BUILTIN_PLUGIN
extern
#endif
struct VirtualMachine* interpreterProxy;
static const char *moduleName =
#ifdef SQUEAK_BUILTIN_PLUGIN
	"StarSqueakPlugin 26 April 2011 (i)"
#else
	"StarSqueakPlugin 26 April 2011 (e)"
#endif
;



/*	Return an unsigned int pointer to the first indexable word of oop, which must be a words object. */

static unsigned int * checkedUnsignedIntPtrOf(sqInt oop) {
	interpreterProxy->success(interpreterProxy->isWords(oop));
	if (interpreterProxy->failed()) {
		return 0;
	}
	return ((unsigned int *) (interpreterProxy->firstIndexableField(oop)));
}


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


/*	Diffuse the integer values of the source patch variable Bitmap into the output Bitmap. Each cell of the output is the average of the NxN area around it in the source, where N = (2 * delta) + 1. */

EXPORT(sqInt) primitiveDiffuseFromToWidthHeightDelta(void) {
    sqInt area;
    sqInt delta;
    unsigned int * dst;
    sqInt dstOop;
    sqInt endX;
    sqInt endY;
    sqInt height;
    sqInt rowStart;
    unsigned int * src;
    sqInt srcOop;
    sqInt startX;
    sqInt startY;
    sqInt sum;
    sqInt width;
    sqInt x;
    sqInt x2;
    sqInt y;
    sqInt y2;

	srcOop = interpreterProxy->stackValue(4);
	dstOop = interpreterProxy->stackValue(3);
	width = interpreterProxy->stackIntegerValue(2);
	height = interpreterProxy->stackIntegerValue(1);
	delta = interpreterProxy->stackIntegerValue(0);
	/* begin checkedUnsignedIntPtrOf: */
	interpreterProxy->success(interpreterProxy->isWords(srcOop));
	if (interpreterProxy->failed()) {
		src = 0;
		goto l1;
	}
	src = ((unsigned int *) (interpreterProxy->firstIndexableField(srcOop)));
l1:	/* end checkedUnsignedIntPtrOf: */;
	/* begin checkedUnsignedIntPtrOf: */
	interpreterProxy->success(interpreterProxy->isWords(dstOop));
	if (interpreterProxy->failed()) {
		dst = 0;
		goto l2;
	}
	dst = ((unsigned int *) (interpreterProxy->firstIndexableField(dstOop)));
l2:	/* end checkedUnsignedIntPtrOf: */;
	interpreterProxy->success((interpreterProxy->stSizeOf(srcOop)) == (interpreterProxy->stSizeOf(dstOop)));
	interpreterProxy->success((interpreterProxy->stSizeOf(srcOop)) == (width * height));
	if (interpreterProxy->failed()) {
		return null;
	}
	area = ((2 * delta) + 1) * ((2 * delta) + 1);
	for (y = 0; y <= (height - 1); y += 1) {
		startY = y - delta;
		if (startY < 0) {
			startY = 0;
		}
		endY = y + delta;
		if (endY >= height) {
			endY = height - 1;
		}
		for (x = 0; x <= (width - 1); x += 1) {
			startX = x - delta;
			if (startX < 0) {
				startX = 0;
			}
			endX = x + delta;
			if (endX >= width) {
				endX = width - 1;
			}
			sum = 0;
			for (y2 = startY; y2 <= endY; y2 += 1) {
				rowStart = y2 * width;
				for (x2 = startX; x2 <= endX; x2 += 1) {
					sum += src[rowStart + x2];
				}
			}
			dst[(y * width) + x] = (sum / area);
		}
	}
	interpreterProxy->pop(5);
}


/*	Evaporate the integer values of the source Bitmap at the given rate. The rate is an integer between 0 and 1024, where 1024 is a scale factor of 1.0 (i.e., no evaporation). */

EXPORT(sqInt) primitiveEvaporateRate(void) {
    sqInt i;
    unsigned int * patchVar;
    sqInt patchVarOop;
    sqInt rate;
    sqInt sz;

	patchVarOop = interpreterProxy->stackValue(1);
	rate = interpreterProxy->stackIntegerValue(0);
	/* begin checkedUnsignedIntPtrOf: */
	interpreterProxy->success(interpreterProxy->isWords(patchVarOop));
	if (interpreterProxy->failed()) {
		patchVar = 0;
		goto l1;
	}
	patchVar = ((unsigned int *) (interpreterProxy->firstIndexableField(patchVarOop)));
l1:	/* end checkedUnsignedIntPtrOf: */;
	sz = interpreterProxy->stSizeOf(patchVarOop);
	if (interpreterProxy->failed()) {
		return null;
	}
	for (i = 0; i <= (sz - 1); i += 1) {
		patchVar[i] = (((usqInt) ((patchVar[i]) * rate)) >> 10);
	}
	interpreterProxy->pop(2);
}

EXPORT(sqInt) primitiveMapFromToWidthHeightPatchSizeRgbFlagsShift(void) {
    unsigned int * dst;
    sqInt dstIndex;
    sqInt dstOop;
    sqInt h;
    sqInt level;
    sqInt offset;
    sqInt patchSize;
    sqInt pixel;
    sqInt rgbFlags;
    sqInt rgbMult;
    sqInt rowStart;
    sqInt shiftAmount;
    unsigned int * src;
    sqInt srcIndex;
    sqInt srcOop;
    sqInt w;
    sqInt x;
    sqInt y;

	srcOop = interpreterProxy->stackValue(6);
	dstOop = interpreterProxy->stackValue(5);
	w = interpreterProxy->stackIntegerValue(4);
	h = interpreterProxy->stackIntegerValue(3);
	patchSize = interpreterProxy->stackIntegerValue(2);
	rgbFlags = interpreterProxy->stackIntegerValue(1);
	shiftAmount = interpreterProxy->stackIntegerValue(0);
	/* begin checkedUnsignedIntPtrOf: */
	interpreterProxy->success(interpreterProxy->isWords(srcOop));
	if (interpreterProxy->failed()) {
		src = 0;
		goto l1;
	}
	src = ((unsigned int *) (interpreterProxy->firstIndexableField(srcOop)));
l1:	/* end checkedUnsignedIntPtrOf: */;
	/* begin checkedUnsignedIntPtrOf: */
	interpreterProxy->success(interpreterProxy->isWords(dstOop));
	if (interpreterProxy->failed()) {
		dst = 0;
		goto l2;
	}
	dst = ((unsigned int *) (interpreterProxy->firstIndexableField(dstOop)));
l2:	/* end checkedUnsignedIntPtrOf: */;
	interpreterProxy->success((interpreterProxy->stSizeOf(dstOop)) == (w * h));
	interpreterProxy->success((interpreterProxy->stSizeOf(dstOop)) == (((interpreterProxy->stSizeOf(srcOop)) * patchSize) * patchSize));
	if (interpreterProxy->failed()) {
		return null;
	}
	rgbMult = 0;
	if ((rgbFlags & 4) > 0) {
		rgbMult += 65536;
	}
	if ((rgbFlags & 2) > 0) {
		rgbMult += 256;
	}
	if ((rgbFlags & 1) > 0) {
		rgbMult += 1;
	}
	srcIndex = -1;
	for (y = 0; y <= ((h / patchSize) - 1); y += 1) {
		for (x = 0; x <= ((w / patchSize) - 1); x += 1) {
			level = ((shiftAmount < 0) ? ((usqInt) (src[(srcIndex += 1)]) >> -shiftAmount) : ((usqInt) (src[(srcIndex += 1)]) << shiftAmount));
			if (level > 255) {
				level = 255;
			}
			if (level <= 0) {

				/* non-transparent black */

				pixel = 1;
			} else {
				pixel = level * rgbMult;
			}
			offset = ((y * w) + x) * patchSize;
			for (rowStart = offset; rowStart <= (offset + ((patchSize - 1) * w)); rowStart += w) {
				for (dstIndex = rowStart; dstIndex <= ((rowStart + patchSize) - 1); dstIndex += 1) {
					dst[dstIndex] = pixel;
				}
			}
		}
	}
	interpreterProxy->pop(7);
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


void* StarSqueakPlugin_exports[][3] = {
	{"StarSqueakPlugin", "primitiveDiffuseFromToWidthHeightDelta", (void*)primitiveDiffuseFromToWidthHeightDelta},
	{"StarSqueakPlugin", "primitiveEvaporateRate", (void*)primitiveEvaporateRate},
	{"StarSqueakPlugin", "setInterpreter", (void*)setInterpreter},
	{"StarSqueakPlugin", "primitiveMapFromToWidthHeightPatchSizeRgbFlagsShift", (void*)primitiveMapFromToWidthHeightPatchSizeRgbFlagsShift},
	{"StarSqueakPlugin", "getModuleName", (void*)getModuleName},
	{NULL, NULL, NULL}
};


#endif /* ifdef SQ_BUILTIN_PLUGIN */

