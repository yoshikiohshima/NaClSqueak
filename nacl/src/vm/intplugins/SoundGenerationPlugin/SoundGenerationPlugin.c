/* Automatically generated from Squeak on 28 October 2011 12:11:06 am 
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



/*** Proxy Functions ***/
#define stackValue(i) (interpreterProxy->stackValue(i))
#define stackIntegerValue(i) (interpreterProxy->stackIntegerValue(i))
#define successFlag (!interpreterProxy->failed())
#define success(bool) (interpreterProxy->success(bool))
#define arrayValueOf(oop) (interpreterProxy->arrayValueOf(oop))
#define checkedIntegerValueOf(oop) (interpreterProxy->checkedIntegerValueOf(oop))
#define fetchArrayofObject(idx,oop) (interpreterProxy->fetchArrayofObject(idx,oop))
#define fetchFloatofObject(idx,oop) (interpreterProxy->fetchFloatofObject(idx,oop))
#define fetchIntegerofObject(idx,oop) (interpreterProxy->fetchIntegerofObject(idx,oop))
#define floatValueOf(oop) (interpreterProxy->floatValueOf(oop))
#define pop(n) (interpreterProxy->pop(n))
#define pushInteger(n) (interpreterProxy->pushInteger(n))
#define sizeOfSTArrayFromCPrimitive(cPtr) (interpreterProxy->sizeOfSTArrayFromCPrimitive(cPtr))
#define storeIntegerofObjectwithValue(idx,oop,value) (interpreterProxy->storeIntegerofObjectwithValue(idx,oop,value))
#define primitiveFail() interpreterProxy->primitiveFail()
/* allows accessing Strings in both C and Smalltalk */
#define asciiValue(c) c


/*** Constants ***/
#define IncrementFractionBits 16
#define LoopIndexFractionMask 511
#define LoopIndexScaleFactor 512
#define ScaleFactor 32768
#define ScaledIndexOverflow 536870912

/*** Variables ***/

#ifdef SQUEAK_BUILTIN_PLUGIN
extern
#endif
struct VirtualMachine* interpreterProxy;
static const char *moduleName =
#ifdef SQUEAK_BUILTIN_PLUGIN
	"SoundGenerationPlugin 28 October 2011 (i)"
#else
	"SoundGenerationPlugin 28 October 2011 (e)"
#endif
;

/*** Function Prototypes ***/
static VirtualMachine * getInterpreter(void);
#pragma export on
EXPORT(const char*) getModuleName(void);
#pragma export off
static sqInt halt(void);
static sqInt msg(char *s);
#pragma export on
EXPORT(sqInt) primitiveApplyReverb(void);
EXPORT(sqInt) primitiveMixFMSound(void);
EXPORT(sqInt) primitiveMixLoopedSampledSound(void);
EXPORT(sqInt) primitiveMixPluckedSound(void);
EXPORT(sqInt) primitiveMixSampledSound(void);
EXPORT(sqInt) setInterpreter(struct VirtualMachine*anInterpreter);
#pragma export off


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

EXPORT(sqInt) primitiveApplyReverb(void) {
    sqInt rcvr;
    short int *aSoundBuffer;
    sqInt startIndex;
    sqInt n;
    sqInt delayedLeft;
    sqInt delayedRight;
    sqInt i;
    sqInt j;
    sqInt out;
    sqInt sliceIndex;
    sqInt tapGain;
    sqInt tapIndex;
    int *tapDelays;
    int *tapGains;
    sqInt tapCount;
    sqInt bufferSize;
    sqInt bufferIndex;
    short int *leftBuffer;
    short int *rightBuffer;

	rcvr = stackValue(3);
	aSoundBuffer = arrayValueOf(stackValue(2));
	aSoundBuffer -= 1;
	startIndex = stackIntegerValue(1);
	n = stackIntegerValue(0);
	tapDelays = fetchArrayofObject(7, rcvr);
	tapDelays -= 1;
	tapGains = fetchArrayofObject(8, rcvr);
	tapGains -= 1;
	tapCount = fetchIntegerofObject(9, rcvr);
	bufferSize = fetchIntegerofObject(10, rcvr);
	bufferIndex = fetchIntegerofObject(11, rcvr);
	leftBuffer = fetchArrayofObject(12, rcvr);
	leftBuffer -= 1;
	rightBuffer = fetchArrayofObject(13, rcvr);
	rightBuffer -= 1;
	if (!(successFlag)) {
		return null;
	}
	for (sliceIndex = startIndex; sliceIndex <= ((startIndex + n) - 1); sliceIndex += 1) {
		delayedLeft = delayedRight = 0;
		for (tapIndex = 1; tapIndex <= tapCount; tapIndex += 1) {
			i = bufferIndex - (tapDelays[tapIndex]);
			if (i < 1) {
				i += bufferSize;
			}
			tapGain = tapGains[tapIndex];
			delayedLeft += tapGain * (leftBuffer[i]);
			delayedRight += tapGain * (rightBuffer[i]);
		}
		j = (2 * sliceIndex) - 1;
		out = (aSoundBuffer[j]) + (((sqInt) delayedLeft >> 15));
		if (out > 32767) {
			out = 32767;
		}
		if (out < -32767) {
			out = -32767;
		}
		aSoundBuffer[j] = out;
		leftBuffer[bufferIndex] = out;
		j += 1;
		out = (aSoundBuffer[j]) + (((sqInt) delayedRight >> 15));
		if (out > 32767) {
			out = 32767;
		}
		if (out < -32767) {
			out = -32767;
		}
		aSoundBuffer[j] = out;
		rightBuffer[bufferIndex] = out;
		bufferIndex = (bufferIndex % bufferSize) + 1;
	}
	if (!(successFlag)) {
		return null;
	}
	storeIntegerofObjectwithValue(11, rcvr, bufferIndex);
	pop(3);
}


/*	Play samples from a wave table by stepping a fixed amount through the table on every sample. The table index and increment are scaled to allow fractional increments for greater pitch accuracy. */
/*	(FMSound pitch: 440.0 dur: 1.0 loudness: 0.5) play */

EXPORT(sqInt) primitiveMixFMSound(void) {
    sqInt rcvr;
    sqInt n;
    short int *aSoundBuffer;
    sqInt startIndex;
    sqInt leftVol;
    sqInt rightVol;
    sqInt doingFM;
    sqInt i;
    sqInt lastIndex;
    sqInt offset;
    sqInt s;
    sqInt sample;
    sqInt sliceIndex;
    sqInt scaledVol;
    sqInt scaledVolIncr;
    sqInt scaledVolLimit;
    sqInt count;
    short int *waveTable;
    sqInt scaledWaveTableSize;
    sqInt scaledIndex;
    sqInt scaledIndexIncr;
    sqInt normalizedModulation;
    sqInt scaledOffsetIndex;
    sqInt scaledOffsetIndexIncr;

	rcvr = stackValue(5);
	n = stackIntegerValue(4);
	aSoundBuffer = arrayValueOf(stackValue(3));
	aSoundBuffer -= 1;
	startIndex = stackIntegerValue(2);
	leftVol = stackIntegerValue(1);
	rightVol = stackIntegerValue(0);
	scaledVol = fetchIntegerofObject(3, rcvr);
	scaledVolIncr = fetchIntegerofObject(4, rcvr);
	scaledVolLimit = fetchIntegerofObject(5, rcvr);
	count = fetchIntegerofObject(7, rcvr);
	waveTable = fetchArrayofObject(8, rcvr);
	waveTable -= 1;
	scaledWaveTableSize = fetchIntegerofObject(9, rcvr);
	scaledIndex = fetchIntegerofObject(10, rcvr);
	scaledIndexIncr = fetchIntegerofObject(11, rcvr);
	normalizedModulation = fetchIntegerofObject(14, rcvr);
	scaledOffsetIndex = fetchIntegerofObject(15, rcvr);
	scaledOffsetIndexIncr = fetchIntegerofObject(16, rcvr);
	if (!(successFlag)) {
		return null;
	}
	doingFM = (normalizedModulation != 0) && (scaledOffsetIndexIncr != 0);
	lastIndex = (startIndex + n) - 1;
	for (sliceIndex = startIndex; sliceIndex <= lastIndex; sliceIndex += 1) {
		sample = ((sqInt) (scaledVol * (waveTable[(((sqInt) scaledIndex >> 15)) + 1])) >> 15);
		if (doingFM) {
			offset = normalizedModulation * (waveTable[(((sqInt) scaledOffsetIndex >> 15)) + 1]);
			scaledOffsetIndex = (scaledOffsetIndex + scaledOffsetIndexIncr) % scaledWaveTableSize;
			if (scaledOffsetIndex < 0) {
				scaledOffsetIndex += scaledWaveTableSize;
			}
			scaledIndex = ((scaledIndex + scaledIndexIncr) + offset) % scaledWaveTableSize;
			if (scaledIndex < 0) {
				scaledIndex += scaledWaveTableSize;
			}
		} else {
			scaledIndex = (scaledIndex + scaledIndexIncr) % scaledWaveTableSize;
		}
		if (leftVol > 0) {
			i = (2 * sliceIndex) - 1;
			s = (aSoundBuffer[i]) + (((sqInt) (sample * leftVol) >> 15));
			if (s > 32767) {
				s = 32767;
			}
			if (s < -32767) {
				s = -32767;
			}
			aSoundBuffer[i] = s;
		}
		if (rightVol > 0) {
			i = 2 * sliceIndex;
			s = (aSoundBuffer[i]) + (((sqInt) (sample * rightVol) >> 15));
			if (s > 32767) {
				s = 32767;
			}
			if (s < -32767) {
				s = -32767;
			}
			aSoundBuffer[i] = s;
		}
		if (scaledVolIncr != 0) {
			scaledVol += scaledVolIncr;
			if (((scaledVolIncr > 0) && (scaledVol >= scaledVolLimit)) || ((scaledVolIncr < 0) && (scaledVol <= scaledVolLimit))) {

				/* reached the limit; stop incrementing */

				scaledVol = scaledVolLimit;
				scaledVolIncr = 0;
			}
		}
	}
	count -= n;
	if (!(successFlag)) {
		return null;
	}
	storeIntegerofObjectwithValue(3, rcvr, scaledVol);
	storeIntegerofObjectwithValue(4, rcvr, scaledVolIncr);
	storeIntegerofObjectwithValue(7, rcvr, count);
	storeIntegerofObjectwithValue(10, rcvr, scaledIndex);
	storeIntegerofObjectwithValue(15, rcvr, scaledOffsetIndex);
	pop(5);
}


/*	Play samples from a wave table by stepping a fixed amount through the table on every sample. The table index and increment are scaled to allow fractional increments for greater pitch accuracy.  If a loop length is specified, then the index is looped back when the loopEnd index is reached until count drops below releaseCount. This allows a short sampled sound to be sustained indefinitely. */
/*	(LoopedSampledSound pitch: 440.0 dur: 5.0 loudness: 0.5) play */

EXPORT(sqInt) primitiveMixLoopedSampledSound(void) {
    sqInt rcvr;
    sqInt n;
    short int *aSoundBuffer;
    sqInt startIndex;
    sqInt leftVol;
    sqInt rightVol;
    sqInt compositeLeftVol;
    sqInt compositeRightVol;
    sqInt i;
    sqInt isInStereo;
    sqInt lastIndex;
    sqInt leftVal;
    sqInt m;
    sqInt nextSampleIndex;
    sqInt rightVal;
    sqInt s;
    sqInt sampleIndex;
    sqInt sliceIndex;
    sqInt scaledVol;
    sqInt scaledVolIncr;
    sqInt scaledVolLimit;
    sqInt count;
    sqInt releaseCount;
    short int *leftSamples;
    short int *rightSamples;
    sqInt lastSample;
    sqInt loopEnd;
    sqInt scaledLoopLength;
    sqInt scaledIndex;
    sqInt scaledIndexIncr;

	rcvr = stackValue(5);
	n = stackIntegerValue(4);
	aSoundBuffer = arrayValueOf(stackValue(3));
	aSoundBuffer -= 1;
	startIndex = stackIntegerValue(2);
	leftVol = stackIntegerValue(1);
	rightVol = stackIntegerValue(0);
	scaledVol = fetchIntegerofObject(3, rcvr);
	scaledVolIncr = fetchIntegerofObject(4, rcvr);
	scaledVolLimit = fetchIntegerofObject(5, rcvr);
	count = fetchIntegerofObject(7, rcvr);
	releaseCount = fetchIntegerofObject(8, rcvr);
	leftSamples = fetchArrayofObject(10, rcvr);
	leftSamples -= 1;
	rightSamples = fetchArrayofObject(11, rcvr);
	rightSamples -= 1;
	lastSample = fetchIntegerofObject(16, rcvr);
	loopEnd = fetchIntegerofObject(17, rcvr);
	scaledLoopLength = fetchIntegerofObject(18, rcvr);
	scaledIndex = fetchIntegerofObject(19, rcvr);
	scaledIndexIncr = fetchIntegerofObject(20, rcvr);
	if (!(successFlag)) {
		return null;
	}
	isInStereo = leftSamples != rightSamples;
	compositeLeftVol = ((sqInt) (leftVol * scaledVol) >> 15);
	compositeRightVol = ((sqInt) (rightVol * scaledVol) >> 15);
	i = (2 * startIndex) - 1;
	lastIndex = (startIndex + n) - 1;
	for (sliceIndex = startIndex; sliceIndex <= lastIndex; sliceIndex += 1) {
		sampleIndex = ((sqInt) (scaledIndex += scaledIndexIncr) >> 9);
		if ((sampleIndex > loopEnd) && (count > releaseCount)) {

			/* loop back if not within releaseCount of the note end */
			/* note: unlooped sounds will have loopEnd = lastSample */

			sampleIndex = ((sqInt) (scaledIndex -= scaledLoopLength) >> 9);
		}
		if ((nextSampleIndex = sampleIndex + 1) > lastSample) {
			if (sampleIndex > lastSample) {
				count = 0;
				if (!(successFlag)) {
					return null;
				}
				storeIntegerofObjectwithValue(3, rcvr, scaledVol);
				storeIntegerofObjectwithValue(4, rcvr, scaledVolIncr);
				storeIntegerofObjectwithValue(7, rcvr, count);
				storeIntegerofObjectwithValue(19, rcvr, scaledIndex);
				pop(6);
				pushInteger(null);
				return null;
			}
			if (scaledLoopLength == 0) {
				nextSampleIndex = sampleIndex;
			} else {
				nextSampleIndex = (((sqInt) (scaledIndex - scaledLoopLength) >> 9)) + 1;
			}
		}
		m = scaledIndex & LoopIndexFractionMask;
		rightVal = leftVal = ((sqInt) (((leftSamples[sampleIndex]) * (LoopIndexScaleFactor - m)) + ((leftSamples[nextSampleIndex]) * m)) >> 9);
		if (isInStereo) {
			rightVal = ((sqInt) (((rightSamples[sampleIndex]) * (LoopIndexScaleFactor - m)) + ((rightSamples[nextSampleIndex]) * m)) >> 9);
		}
		if (leftVol > 0) {
			s = (aSoundBuffer[i]) + (((sqInt) (compositeLeftVol * leftVal) >> 15));
			if (s > 32767) {
				s = 32767;
			}
			if (s < -32767) {
				s = -32767;
			}
			aSoundBuffer[i] = s;
		}
		i += 1;
		if (rightVol > 0) {
			s = (aSoundBuffer[i]) + (((sqInt) (compositeRightVol * rightVal) >> 15));
			if (s > 32767) {
				s = 32767;
			}
			if (s < -32767) {
				s = -32767;
			}
			aSoundBuffer[i] = s;
		}
		i += 1;
		if (scaledVolIncr != 0) {

			/* update volume envelope if it is changing */

			scaledVol += scaledVolIncr;
			if (((scaledVolIncr > 0) && (scaledVol >= scaledVolLimit)) || ((scaledVolIncr < 0) && (scaledVol <= scaledVolLimit))) {

				/* reached the limit; stop incrementing */

				scaledVol = scaledVolLimit;
				scaledVolIncr = 0;
			}
			compositeLeftVol = ((sqInt) (leftVol * scaledVol) >> 15);
			compositeRightVol = ((sqInt) (rightVol * scaledVol) >> 15);
		}
	}
	count -= n;
	if (!(successFlag)) {
		return null;
	}
	storeIntegerofObjectwithValue(3, rcvr, scaledVol);
	storeIntegerofObjectwithValue(4, rcvr, scaledVolIncr);
	storeIntegerofObjectwithValue(7, rcvr, count);
	storeIntegerofObjectwithValue(19, rcvr, scaledIndex);
	pop(5);
}


/*	The Karplus-Strong plucked string algorithm: start with a buffer full of random noise and repeatedly play the contents of that buffer while averaging adjacent samples. High harmonics damp out more quickly, transfering their energy to lower ones. The length of the buffer corresponds to the length of the string. */
/*	(PluckedSound pitch: 220.0 dur: 6.0 loudness: 0.8) play */

EXPORT(sqInt) primitiveMixPluckedSound(void) {
    sqInt rcvr;
    sqInt n;
    short int *aSoundBuffer;
    sqInt startIndex;
    sqInt leftVol;
    sqInt rightVol;
    sqInt average;
    sqInt i;
    sqInt lastIndex;
    sqInt s;
    sqInt sample;
    sqInt scaledNextIndex;
    sqInt scaledThisIndex;
    sqInt sliceIndex;
    sqInt scaledVol;
    sqInt scaledVolIncr;
    sqInt scaledVolLimit;
    sqInt count;
    short int *ring;
    sqInt scaledIndex;
    sqInt scaledIndexIncr;
    sqInt scaledIndexLimit;

	rcvr = stackValue(5);
	n = stackIntegerValue(4);
	aSoundBuffer = arrayValueOf(stackValue(3));
	aSoundBuffer -= 1;
	startIndex = stackIntegerValue(2);
	leftVol = stackIntegerValue(1);
	rightVol = stackIntegerValue(0);
	scaledVol = fetchIntegerofObject(3, rcvr);
	scaledVolIncr = fetchIntegerofObject(4, rcvr);
	scaledVolLimit = fetchIntegerofObject(5, rcvr);
	count = fetchIntegerofObject(7, rcvr);
	ring = fetchArrayofObject(8, rcvr);
	ring -= 1;
	scaledIndex = fetchIntegerofObject(9, rcvr);
	scaledIndexIncr = fetchIntegerofObject(10, rcvr);
	scaledIndexLimit = fetchIntegerofObject(11, rcvr);
	if (!(successFlag)) {
		return null;
	}
	lastIndex = (startIndex + n) - 1;
	scaledThisIndex = scaledNextIndex = scaledIndex;
	for (sliceIndex = startIndex; sliceIndex <= lastIndex; sliceIndex += 1) {
		scaledNextIndex = scaledThisIndex + scaledIndexIncr;
		if (scaledNextIndex >= scaledIndexLimit) {
			scaledNextIndex = ScaleFactor + (scaledNextIndex - scaledIndexLimit);
		}
		average = ((sqInt) ((ring[((sqInt) scaledThisIndex >> 15)]) + (ring[((sqInt) scaledNextIndex >> 15)])) >> 1);
		ring[((sqInt) scaledThisIndex >> 15)] = average;

		/* scale by volume */

		sample = ((sqInt) (average * scaledVol) >> 15);
		scaledThisIndex = scaledNextIndex;
		if (leftVol > 0) {
			i = (2 * sliceIndex) - 1;
			s = (aSoundBuffer[i]) + (((sqInt) (sample * leftVol) >> 15));
			if (s > 32767) {
				s = 32767;
			}
			if (s < -32767) {
				s = -32767;
			}
			aSoundBuffer[i] = s;
		}
		if (rightVol > 0) {
			i = 2 * sliceIndex;
			s = (aSoundBuffer[i]) + (((sqInt) (sample * rightVol) >> 15));
			if (s > 32767) {
				s = 32767;
			}
			if (s < -32767) {
				s = -32767;
			}
			aSoundBuffer[i] = s;
		}
		if (scaledVolIncr != 0) {
			scaledVol += scaledVolIncr;
			if (((scaledVolIncr > 0) && (scaledVol >= scaledVolLimit)) || ((scaledVolIncr < 0) && (scaledVol <= scaledVolLimit))) {

				/* reached the limit; stop incrementing */

				scaledVol = scaledVolLimit;
				scaledVolIncr = 0;
			}
		}
	}
	scaledIndex = scaledNextIndex;
	count -= n;
	if (!(successFlag)) {
		return null;
	}
	storeIntegerofObjectwithValue(3, rcvr, scaledVol);
	storeIntegerofObjectwithValue(4, rcvr, scaledVolIncr);
	storeIntegerofObjectwithValue(7, rcvr, count);
	storeIntegerofObjectwithValue(9, rcvr, scaledIndex);
	pop(5);
}


/*	Mix the given number of samples with the samples already in the given buffer starting at the given index. Assume that the buffer size is at least (index + count) - 1. */

EXPORT(sqInt) primitiveMixSampledSound(void) {
    sqInt rcvr;
    sqInt n;
    short int *aSoundBuffer;
    sqInt startIndex;
    sqInt leftVol;
    sqInt rightVol;
    sqInt i;
    sqInt lastIndex;
    sqInt outIndex;
    sqInt overflow;
    sqInt s;
    sqInt sample;
    sqInt sampleIndex;
    sqInt scaledVol;
    sqInt scaledVolIncr;
    sqInt scaledVolLimit;
    sqInt count;
    short int *samples;
    sqInt samplesSize;
    sqInt scaledIndex;
    sqInt indexHighBits;
    sqInt scaledIncrement;

	rcvr = stackValue(5);
	n = stackIntegerValue(4);
	aSoundBuffer = arrayValueOf(stackValue(3));
	aSoundBuffer -= 1;
	startIndex = stackIntegerValue(2);
	leftVol = stackIntegerValue(1);
	rightVol = stackIntegerValue(0);
	scaledVol = fetchIntegerofObject(3, rcvr);
	scaledVolIncr = fetchIntegerofObject(4, rcvr);
	scaledVolLimit = fetchIntegerofObject(5, rcvr);
	count = fetchIntegerofObject(7, rcvr);
	samples = fetchArrayofObject(8, rcvr);
	samples -= 1;
	samplesSize = fetchIntegerofObject(10, rcvr);
	scaledIndex = fetchIntegerofObject(11, rcvr);
	indexHighBits = fetchIntegerofObject(12, rcvr);
	scaledIncrement = fetchIntegerofObject(13, rcvr);
	if (!(successFlag)) {
		return null;
	}
	lastIndex = (startIndex + n) - 1;

	/* index of next stereo output sample pair */

	outIndex = startIndex;
	sampleIndex = indexHighBits + (((usqInt) scaledIndex) >> IncrementFractionBits);
	while ((sampleIndex <= samplesSize) && (outIndex <= lastIndex)) {
		sample = ((sqInt) ((samples[sampleIndex]) * scaledVol) >> 15);
		if (leftVol > 0) {
			i = (2 * outIndex) - 1;
			s = (aSoundBuffer[i]) + (((sqInt) (sample * leftVol) >> 15));
			if (s > 32767) {
				s = 32767;
			}
			if (s < -32767) {
				s = -32767;
			}
			aSoundBuffer[i] = s;
		}
		if (rightVol > 0) {
			i = 2 * outIndex;
			s = (aSoundBuffer[i]) + (((sqInt) (sample * rightVol) >> 15));
			if (s > 32767) {
				s = 32767;
			}
			if (s < -32767) {
				s = -32767;
			}
			aSoundBuffer[i] = s;
		}
		if (scaledVolIncr != 0) {
			scaledVol += scaledVolIncr;
			if (((scaledVolIncr > 0) && (scaledVol >= scaledVolLimit)) || ((scaledVolIncr < 0) && (scaledVol <= scaledVolLimit))) {

				/* reached the limit; stop incrementing */

				scaledVol = scaledVolLimit;
				scaledVolIncr = 0;
			}
		}
		scaledIndex += scaledIncrement;
		if (scaledIndex >= ScaledIndexOverflow) {
			overflow = ((usqInt) scaledIndex) >> IncrementFractionBits;
			indexHighBits += overflow;
			scaledIndex -= overflow << IncrementFractionBits;
		}
		sampleIndex = indexHighBits + (((usqInt) scaledIndex) >> IncrementFractionBits);
		outIndex += 1;
	}
	count -= n;
	if (!(successFlag)) {
		return null;
	}
	storeIntegerofObjectwithValue(3, rcvr, scaledVol);
	storeIntegerofObjectwithValue(4, rcvr, scaledVolIncr);
	storeIntegerofObjectwithValue(7, rcvr, count);
	storeIntegerofObjectwithValue(11, rcvr, scaledIndex);
	storeIntegerofObjectwithValue(12, rcvr, indexHighBits);
	pop(5);
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


void* SoundGenerationPlugin_exports[][3] = {
	{"SoundGenerationPlugin", "primitiveMixFMSound", (void*)primitiveMixFMSound},
	{"SoundGenerationPlugin", "primitiveMixSampledSound", (void*)primitiveMixSampledSound},
	{"SoundGenerationPlugin", "setInterpreter", (void*)setInterpreter},
	{"SoundGenerationPlugin", "getModuleName", (void*)getModuleName},
	{"SoundGenerationPlugin", "primitiveApplyReverb", (void*)primitiveApplyReverb},
	{"SoundGenerationPlugin", "primitiveMixPluckedSound", (void*)primitiveMixPluckedSound},
	{"SoundGenerationPlugin", "primitiveMixLoopedSampledSound", (void*)primitiveMixLoopedSampledSound},
	{NULL, NULL, NULL}
};


#endif /* ifdef SQ_BUILTIN_PLUGIN */

