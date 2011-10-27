/* Automatically generated from Squeak on 26 April 2011 1:22:08 pm 
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
static float * checkedFloatPtrOf(sqInt oop);
static unsigned int * checkedWordPtrOf(sqInt oop);
static VirtualMachine * getInterpreter(void);
#pragma export on
EXPORT(const char*) getModuleName(void);
#pragma export off
static sqInt halt(void);
static sqInt loadFFTFrom(sqInt fftOop);
static sqInt msg(char *s);
static sqInt permuteData(void);
#pragma export on
EXPORT(sqInt) primitiveFFTPermuteData(void);
EXPORT(sqInt) primitiveFFTScaleData(void);
EXPORT(sqInt) primitiveFFTTransformData(void);
#pragma export off
static sqInt scaleData(void);
#pragma export on
EXPORT(sqInt) setInterpreter(struct VirtualMachine*anInterpreter);
#pragma export off
static sqInt transformData(sqInt forward);
static sqInt transformForward(sqInt forward);
/*** Variables ***/
static sqInt fftSize;
static float * imagData;
static sqInt imagDataSize;

#ifdef SQUEAK_BUILTIN_PLUGIN
extern
#endif
struct VirtualMachine* interpreterProxy;
static const char *moduleName =
#ifdef SQUEAK_BUILTIN_PLUGIN
	"FFTPlugin 26 April 2011 (i)"
#else
	"FFTPlugin 26 April 2011 (e)"
#endif
;
static sqInt nu;
static unsigned int * permTable;
static sqInt permTableSize;
static float * realData;
static sqInt realDataSize;
static float * sinTable;
static sqInt sinTableSize;



/*	Return the first indexable word of oop which is assumed to be variableWordSubclass */

static float * checkedFloatPtrOf(sqInt oop) {
	interpreterProxy->success(interpreterProxy->isWords(oop));
	if (interpreterProxy->failed()) {
		return 0;
	}
	return ((float *) (interpreterProxy->firstIndexableField(oop)));
}


/*	Return the first indexable word of oop which is assumed to be variableWordSubclass */

static unsigned int * checkedWordPtrOf(sqInt oop) {
	interpreterProxy->success(interpreterProxy->isWords(oop));
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

static sqInt loadFFTFrom(sqInt fftOop) {
    sqInt oop;

	interpreterProxy->success((interpreterProxy->slotSizeOf(fftOop)) >= 6);
	if (interpreterProxy->failed()) {
		return 0;
	}
	nu = interpreterProxy->fetchIntegerofObject(0, fftOop);
	fftSize = interpreterProxy->fetchIntegerofObject(1, fftOop);
	oop = interpreterProxy->fetchPointerofObject(2, fftOop);
	sinTableSize = interpreterProxy->stSizeOf(oop);
	/* begin checkedFloatPtrOf: */
	interpreterProxy->success(interpreterProxy->isWords(oop));
	if (interpreterProxy->failed()) {
		sinTable = 0;
		goto l1;
	}
	sinTable = ((float *) (interpreterProxy->firstIndexableField(oop)));
l1:	/* end checkedFloatPtrOf: */;
	oop = interpreterProxy->fetchPointerofObject(3, fftOop);
	permTableSize = interpreterProxy->stSizeOf(oop);
	/* begin checkedWordPtrOf: */
	interpreterProxy->success(interpreterProxy->isWords(oop));
	permTable = ((unsigned int *) (interpreterProxy->firstIndexableField(oop)));
	oop = interpreterProxy->fetchPointerofObject(4, fftOop);
	realDataSize = interpreterProxy->stSizeOf(oop);
	/* begin checkedFloatPtrOf: */
	interpreterProxy->success(interpreterProxy->isWords(oop));
	if (interpreterProxy->failed()) {
		realData = 0;
		goto l2;
	}
	realData = ((float *) (interpreterProxy->firstIndexableField(oop)));
l2:	/* end checkedFloatPtrOf: */;
	oop = interpreterProxy->fetchPointerofObject(5, fftOop);
	imagDataSize = interpreterProxy->stSizeOf(oop);
	/* begin checkedFloatPtrOf: */
	interpreterProxy->success(interpreterProxy->isWords(oop));
	if (interpreterProxy->failed()) {
		imagData = 0;
		goto l3;
	}
	imagData = ((float *) (interpreterProxy->firstIndexableField(oop)));
l3:	/* end checkedFloatPtrOf: */;
	interpreterProxy->success((((((1 << nu) == fftSize) && (((((sqInt) fftSize >> 2)) + 1) == sinTableSize)) && (fftSize == realDataSize)) && (fftSize == imagDataSize)) && (realDataSize == imagDataSize));
	return (interpreterProxy->failed()) == 0;
}

static sqInt msg(char *s) {
	fprintf(stderr, "\n%s: %s", moduleName, s);
}

static sqInt permuteData(void) {
    sqInt a;
    sqInt b;
    sqInt end;
    sqInt i;
    float  tmp;

	i = 0;
	end = permTableSize;
	while (i < end) {
		a = (permTable[i]) - 1;
		b = (permTable[i + 1]) - 1;
		if (!((a < realDataSize) && (b < realDataSize))) {
			return interpreterProxy->success(0);
		}
		tmp = realData[a];
		realData[a] = (realData[b]);
		realData[b] = tmp;
		tmp = imagData[a];
		imagData[a] = (imagData[b]);
		imagData[b] = tmp;
		i += 2;
	}
}

EXPORT(sqInt) primitiveFFTPermuteData(void) {
    sqInt rcvr;

	rcvr = interpreterProxy->stackObjectValue(0);
	if (!(loadFFTFrom(rcvr))) {
		return null;
	}
	permuteData();
	if (interpreterProxy->failed()) {
		permuteData();
	}
}

EXPORT(sqInt) primitiveFFTScaleData(void) {
    sqInt rcvr;

	rcvr = interpreterProxy->stackObjectValue(0);
	if (!(loadFFTFrom(rcvr))) {
		return null;
	}
	scaleData();
}

EXPORT(sqInt) primitiveFFTTransformData(void) {
    sqInt forward;
    sqInt rcvr;

	forward = interpreterProxy->booleanValueOf(interpreterProxy->stackValue(0));
	rcvr = interpreterProxy->stackObjectValue(1);
	if (!(loadFFTFrom(rcvr))) {
		return null;
	}
	/* begin transformData: */
	permuteData();
	if (interpreterProxy->failed()) {
		permuteData();
		goto l1;
	}
	transformForward(forward);
	if (!(forward)) {
		scaleData();
	}
l1:	/* end transformData: */;
	if (!(interpreterProxy->failed())) {
		interpreterProxy->pop(1);
	}
}


/*	Scale all elements by 1/n when doing inverse */

static sqInt scaleData(void) {
    sqInt i;
    float  realN;

	if (fftSize <= 1) {
		return null;
	}
	realN = ((float) (1.0 / (((double) fftSize))));
	for (i = 0; i <= (fftSize - 1); i += 1) {
		realData[i] = ((realData[i]) * realN);
		imagData[i] = ((imagData[i]) * realN);
	}
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

static sqInt transformData(sqInt forward) {
	permuteData();
	if (interpreterProxy->failed()) {
		permuteData();
		return null;
	}
	transformForward(forward);
	if (!(forward)) {
		scaleData();
	}
}

static sqInt transformForward(sqInt forward) {
    sqInt fftScale;
    sqInt fftSize2;
    sqInt fftSize4;
    sqInt i;
    sqInt ii;
    float  imagT;
    float  imagU;
    sqInt ip;
    sqInt j;
    sqInt lev;
    sqInt lev1;
    sqInt level;
    float  realT;
    float  realU;
    sqInt theta;

	fftSize2 = ((sqInt) fftSize >> 1);
	fftSize4 = ((sqInt) fftSize >> 2);
	for (level = 1; level <= nu; level += 1) {
		lev = ((level < 0) ? ((usqInt) 1 >> -level) : ((usqInt) 1 << level));
		lev1 = ((sqInt) lev >> 1);
		fftScale = fftSize / lev;
		for (j = 1; j <= lev1; j += 1) {

			/* pi * (j-1) / lev1 mapped onto 0..n/2 */

			theta = (j - 1) * fftScale;
			if (theta < fftSize4) {

				/* Compute U, the complex multiplier for each level */

				realU = sinTable[(sinTableSize - theta) - 1];
				imagU = sinTable[theta];
			} else {
				realU = 0.0 - (sinTable[theta - fftSize4]);
				imagU = sinTable[fftSize2 - theta];
			}
			if (!(forward)) {
				imagU = 0.0 - imagU;
			}
			i = j;
			while (i <= fftSize) {
				ip = (i + lev1) - 1;
				ii = i - 1;
				realT = ((realData[ip]) * realU) - ((imagData[ip]) * imagU);
				imagT = ((realData[ip]) * imagU) + ((imagData[ip]) * realU);
				realData[ip] = ((realData[ii]) - realT);
				imagData[ip] = ((imagData[ii]) - imagT);
				realData[ii] = ((realData[ii]) + realT);
				imagData[ii] = ((imagData[ii]) + imagT);
				i += lev;
			}
		}
	}
}


#ifdef SQUEAK_BUILTIN_PLUGIN


void* FFTPlugin_exports[][3] = {
	{"FFTPlugin", "primitiveFFTTransformData", (void*)primitiveFFTTransformData},
	{"FFTPlugin", "setInterpreter", (void*)setInterpreter},
	{"FFTPlugin", "primitiveFFTPermuteData", (void*)primitiveFFTPermuteData},
	{"FFTPlugin", "primitiveFFTScaleData", (void*)primitiveFFTScaleData},
	{"FFTPlugin", "getModuleName", (void*)getModuleName},
	{NULL, NULL, NULL}
};


#endif /* ifdef SQ_BUILTIN_PLUGIN */

