/* Automatically generated from Squeak on 26 April 2011 1:22:13 pm 
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

/*** Variables ***/

#ifdef SQUEAK_BUILTIN_PLUGIN
extern
#endif
struct VirtualMachine* interpreterProxy;
static const char *moduleName =
#ifdef SQUEAK_BUILTIN_PLUGIN
	"MiscPrimitivePlugin 26 April 2011 (i)"
#else
	"MiscPrimitivePlugin 26 April 2011 (e)"
#endif
;

/*** Function Prototypes ***/
static sqInt encodeBytesOfinat(sqInt anInt, unsigned char *ba, sqInt i);
static sqInt encodeIntinat(sqInt anInt, unsigned char *ba, sqInt i);
static VirtualMachine * getInterpreter(void);
#pragma export on
EXPORT(const char*) getModuleName(void);
#pragma export off
static sqInt halt(void);
static sqInt msg(char *s);
#pragma export on
EXPORT(sqInt) primitiveCompareString(void);
EXPORT(sqInt) primitiveCompressToByteArray(void);
EXPORT(sqInt) primitiveConvert8BitSigned(void);
EXPORT(sqInt) primitiveDecompressFromByteArray(void);
EXPORT(sqInt) primitiveFindFirstInString(void);
EXPORT(sqInt) primitiveFindSubstring(void);
EXPORT(sqInt) primitiveIndexOfAsciiInString(void);
EXPORT(sqInt) primitiveStringHash(void);
EXPORT(sqInt) primitiveTranslateStringWithTable(void);
EXPORT(sqInt) setInterpreter(struct VirtualMachine*anInterpreter);
#pragma export off


/*	Copy the integer anInt into byteArray ba at index i, and return the next index */

static sqInt encodeBytesOfinat(sqInt anInt, unsigned char *ba, sqInt i) {
    sqInt j;

	for (j = 0; j <= 3; j += 1) {
		ba[i + j] = ((((usqInt) anInt) >> ((3 - j) * 8)) & 255);
	}
	return i + 4;
}


/*	Encode the integer anInt in byteArray ba at index i, and return the next index.
	The encoding is as follows...
		0-223	0-223
		224-254	(0-30)*256 + next byte (0-7935)
		255		next 4 bytes */

static sqInt encodeIntinat(sqInt anInt, unsigned char *ba, sqInt i) {
    sqInt j;

	if (anInt <= 223) {
		ba[i] = anInt;
		return i + 1;
	}
	if (anInt <= 7935) {
		ba[i] = ((((sqInt) anInt >> 8)) + 224);
		ba[i + 1] = (anInt % 256);
		return i + 2;
	}
	ba[i] = 255;
	/* begin encodeBytesOf:in:at: */
	for (j = 0; j <= 3; j += 1) {
		ba[(i + 1) + j] = ((((usqInt) anInt) >> ((3 - j) * 8)) & 255);
	}
	return (i + 1) + 4;
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


/*	Return 1, 2 or 3, if string1 is <, =, or > string2, with the collating order of characters given by the order array. */

EXPORT(sqInt) primitiveCompareString(void) {
    sqInt rcvr;
    unsigned char *string1;
    unsigned char *string2;
    unsigned char *order;
    sqInt c1;
    sqInt c2;
    sqInt i;
    sqInt len1;
    sqInt len2;

	rcvr = stackValue(3);
	if (!(isBytes(stackValue(2)))) {
		return primitiveFail();
	}
	string1 = arrayValueOf(stackValue(2));
	string1 -= 1;
	if (!(isBytes(stackValue(1)))) {
		return primitiveFail();
	}
	string2 = arrayValueOf(stackValue(1));
	string2 -= 1;
	if (!(isBytes(stackValue(0)))) {
		return primitiveFail();
	}
	order = arrayValueOf(stackValue(0));
	order -= 1;
	if (!(successFlag)) {
		return null;
	}
	len1 = sizeOfSTArrayFromCPrimitive(string1 + 1);
	len2 = sizeOfSTArrayFromCPrimitive(string2 + 1);
	for (i = 1; i <= (((len1 < len2) ? len1 : len2)); i += 1) {
		c1 = order[(string1[i]) + 1];
		c2 = order[(string2[i]) + 1];
		if (!(c1 == c2)) {
			if (c1 < c2) {
				if (!(successFlag)) {
					return null;
				}
				pop(4);
				pushInteger(1);
				return null;
			} else {
				if (!(successFlag)) {
					return null;
				}
				pop(4);
				pushInteger(3);
				return null;
			}
		}
	}
	if (len1 == len2) {
		if (!(successFlag)) {
			return null;
		}
		pop(4);
		pushInteger(2);
		return null;
	}
	if (len1 < len2) {
		if (!(successFlag)) {
			return null;
		}
		pop(4);
		pushInteger(1);
		return null;
	} else {
		if (!(successFlag)) {
			return null;
		}
		pop(4);
		pushInteger(3);
		return null;
	}
	if (!(successFlag)) {
		return null;
	}
	pop(3);
}


/*	Store a run-coded compression of the receiver into the byteArray ba,
	and return the last index stored into. ba is assumed to be large enough.
	The encoding is as follows...
		S {N D}*.
		S is the size of the original bitmap, followed by run-coded pairs.
		N is a run-length * 4 + data code.
		D, the data, depends on the data code...
			0	skip N words, D is absent
			1	N words with all 4 bytes = D (1 byte)
			2	N words all = D (4 bytes)
			3	N words follow in D (4N bytes)
		S and N are encoded as follows...
			0-223	0-223
			224-254	(0-30)*256 + next byte (0-7935)
			255		next 4 bytes */

EXPORT(sqInt) primitiveCompressToByteArray(void) {
    sqInt rcvr;
    int *bm;
    unsigned char *ba;
    sqInt eqBytes;
    sqInt i;
    sqInt j;
    sqInt k;
    sqInt lowByte;
    sqInt m;
    sqInt size;
    sqInt word;
    sqInt j1;
    sqInt j2;
    sqInt j3;
    sqInt j4;
    sqInt j5;
    sqInt j6;
    sqInt j7;

	rcvr = stackValue(2);
	bm = arrayValueOf(stackValue(1));
	bm -= 1;
	if (!(isBytes(stackValue(0)))) {
		return primitiveFail();
	}
	ba = arrayValueOf(stackValue(0));
	ba -= 1;
	if (!(successFlag)) {
		return null;
	}
	size = sizeOfSTArrayFromCPrimitive(bm + 1);
	/* begin encodeInt:in:at: */
	if (size <= 223) {
		ba[1] = size;
		i = 1 + 1;
		goto l5;
	}
	if (size <= 7935) {
		ba[1] = ((((sqInt) size >> 8)) + 224);
		ba[1 + 1] = (size % 256);
		i = 1 + 2;
		goto l5;
	}
	ba[1] = 255;
	/* begin encodeBytesOf:in:at: */
	for (j7 = 0; j7 <= 3; j7 += 1) {
		ba[(1 + 1) + j7] = ((((usqInt) size) >> ((3 - j7) * 8)) & 255);
	}
	i = (1 + 1) + 4;
l5:	/* end encodeInt:in:at: */;
	k = 1;
	while (k <= size) {
		word = bm[k];
		lowByte = word & 255;
		eqBytes = (((((usqInt) word) >> 8) & 255) == lowByte) && ((((((usqInt) word) >> 16) & 255) == lowByte) && (((((usqInt) word) >> 24) & 255) == lowByte));
		j = k;
		while ((j < size) && (word == (bm[j + 1]))) {
			j += 1;
		}
		if (j > k) {
			if (eqBytes) {
				/* begin encodeInt:in:at: */
				if (((((j - k) + 1) * 4) + 1) <= 223) {
					ba[i] = ((((j - k) + 1) * 4) + 1);
					i += 1;
					goto l1;
				}
				if (((((j - k) + 1) * 4) + 1) <= 7935) {
					ba[i] = ((((sqInt) ((((j - k) + 1) * 4) + 1) >> 8)) + 224);
					ba[i + 1] = (((((j - k) + 1) * 4) + 1) % 256);
					i += 2;
					goto l1;
				}
				ba[i] = 255;
				/* begin encodeBytesOf:in:at: */
				for (j3 = 0; j3 <= 3; j3 += 1) {
					ba[(i + 1) + j3] = ((((usqInt) ((((j - k) + 1) * 4) + 1)) >> ((3 - j3) * 8)) & 255);
				}
				i = (i + 1) + 4;
			l1:	/* end encodeInt:in:at: */;
				ba[i] = lowByte;
				i += 1;
			} else {
				/* begin encodeInt:in:at: */
				if (((((j - k) + 1) * 4) + 2) <= 223) {
					ba[i] = ((((j - k) + 1) * 4) + 2);
					i += 1;
					goto l2;
				}
				if (((((j - k) + 1) * 4) + 2) <= 7935) {
					ba[i] = ((((sqInt) ((((j - k) + 1) * 4) + 2) >> 8)) + 224);
					ba[i + 1] = (((((j - k) + 1) * 4) + 2) % 256);
					i += 2;
					goto l2;
				}
				ba[i] = 255;
				/* begin encodeBytesOf:in:at: */
				for (j4 = 0; j4 <= 3; j4 += 1) {
					ba[(i + 1) + j4] = ((((usqInt) ((((j - k) + 1) * 4) + 2)) >> ((3 - j4) * 8)) & 255);
				}
				i = (i + 1) + 4;
			l2:	/* end encodeInt:in:at: */;
				/* begin encodeBytesOf:in:at: */
				for (j1 = 0; j1 <= 3; j1 += 1) {
					ba[i + j1] = ((((usqInt) word) >> ((3 - j1) * 8)) & 255);
				}
				i += 4;
			}
			k = j + 1;
		} else {
			if (eqBytes) {
				/* begin encodeInt:in:at: */
				if (((1 * 4) + 1) <= 223) {
					ba[i] = ((1 * 4) + 1);
					i += 1;
					goto l3;
				}
				if (((1 * 4) + 1) <= 7935) {
					ba[i] = ((((sqInt) ((1 * 4) + 1) >> 8)) + 224);
					ba[i + 1] = (((1 * 4) + 1) % 256);
					i += 2;
					goto l3;
				}
				ba[i] = 255;
				/* begin encodeBytesOf:in:at: */
				for (j5 = 0; j5 <= 3; j5 += 1) {
					ba[(i + 1) + j5] = ((((usqInt) ((1 * 4) + 1)) >> ((3 - j5) * 8)) & 255);
				}
				i = (i + 1) + 4;
			l3:	/* end encodeInt:in:at: */;
				ba[i] = lowByte;
				i += 1;
				k += 1;
			} else {
				while ((j < size) && ((bm[j]) != (bm[j + 1]))) {
					j += 1;
				}
				if (j == size) {
					j += 1;
				}
				/* begin encodeInt:in:at: */
				if ((((j - k) * 4) + 3) <= 223) {
					ba[i] = (((j - k) * 4) + 3);
					i += 1;
					goto l4;
				}
				if ((((j - k) * 4) + 3) <= 7935) {
					ba[i] = ((((sqInt) (((j - k) * 4) + 3) >> 8)) + 224);
					ba[i + 1] = ((((j - k) * 4) + 3) % 256);
					i += 2;
					goto l4;
				}
				ba[i] = 255;
				/* begin encodeBytesOf:in:at: */
				for (j6 = 0; j6 <= 3; j6 += 1) {
					ba[(i + 1) + j6] = ((((usqInt) (((j - k) * 4) + 3)) >> ((3 - j6) * 8)) & 255);
				}
				i = (i + 1) + 4;
			l4:	/* end encodeInt:in:at: */;
				for (m = k; m <= (j - 1); m += 1) {
					/* begin encodeBytesOf:in:at: */
					for (j2 = 0; j2 <= 3; j2 += 1) {
						ba[i + j2] = ((((usqInt) (bm[m])) >> ((3 - j2) * 8)) & 255);
					}
					i += 4;
				}
				k = j;
			}
		}
	}
	if (!(successFlag)) {
		return null;
	}
	pop(3);
	pushInteger(i - 1);
	return null;
}


/*	Copy the contents of the given array of signed 8-bit samples into the given array of 16-bit signed samples. */

EXPORT(sqInt) primitiveConvert8BitSigned(void) {
    sqInt rcvr;
    unsigned char *aByteArray;
    unsigned short *aSoundBuffer;
    sqInt i;
    sqInt n;
    sqInt s;

	rcvr = stackValue(2);
	if (!(isBytes(stackValue(1)))) {
		return primitiveFail();
	}
	aByteArray = arrayValueOf(stackValue(1));
	aByteArray -= 1;
	aSoundBuffer = arrayValueOf(stackValue(0));
	aSoundBuffer -= 1;
	if (!(successFlag)) {
		return null;
	}
	n = sizeOfSTArrayFromCPrimitive(aByteArray + 1);
	for (i = 1; i <= n; i += 1) {
		s = aByteArray[i];
		if (s > 127) {
			aSoundBuffer[i] = (((usqInt) (s - 256) << 8));
		} else {
			aSoundBuffer[i] = (((usqInt) s << 8));
		}
	}
	if (!(successFlag)) {
		return null;
	}
	pop(2);
}


/*	Decompress the body of a byteArray encoded by compressToByteArray (qv)...
	The format is simply a sequence of run-coded pairs, {N D}*.
		N is a run-length * 4 + data code.
		D, the data, depends on the data code...
			0	skip N words, D is absent
				(could be used to skip from one raster line to the next)
			1	N words with all 4 bytes = D (1 byte)
			2	N words all = D (4 bytes)
			3	N words follow in D (4N bytes)
		S and N are encoded as follows (see decodeIntFrom:)...
			0-223	0-223
			224-254	(0-30)*256 + next byte (0-7935)
			255		next 4 bytes */
/*	NOTE:  If fed with garbage, this routine could read past the end of ba, but it should fail before writing past the ned of bm. */

EXPORT(sqInt) primitiveDecompressFromByteArray(void) {
    sqInt rcvr;
    int *bm;
    unsigned char *ba;
    sqInt index;
    sqInt anInt;
    sqInt code;
    sqInt data;
    sqInt end;
    sqInt i;
    sqInt j;
    sqInt k;
    sqInt m;
    sqInt n;
    sqInt pastEnd;

	rcvr = stackValue(3);
	bm = arrayValueOf(stackValue(2));
	bm -= 1;
	if (!(isBytes(stackValue(1)))) {
		return primitiveFail();
	}
	ba = arrayValueOf(stackValue(1));
	ba -= 1;
	index = stackIntegerValue(0);
	if (!(successFlag)) {
		return null;
	}

	/* byteArray read index */

	i = index;
	end = sizeOfSTArrayFromCPrimitive(ba + 1);

	/* bitmap write index */

	k = 1;
	pastEnd = (sizeOfSTArrayFromCPrimitive(bm + 1)) + 1;
	while (i <= end) {

		/* Decode next run start N */

		anInt = ba[i];
		i += 1;
		if (!(anInt <= 223)) {
			if (anInt <= 254) {
				anInt = ((anInt - 224) * 256) + (ba[i]);
				i += 1;
			} else {
				anInt = 0;
				for (j = 1; j <= 4; j += 1) {
					anInt = (((usqInt) anInt << 8)) + (ba[i]);
					i += 1;
				}
			}
		}
		n = ((usqInt) anInt) >> 2;
		if ((k + n) > pastEnd) {
			primitiveFail();
			return null;
		}
		code = anInt & 3;
		if (code == 0) {
			null;
		}
		if (code == 1) {

			/* n consecutive words of 4 bytes = the following byte */

			data = ba[i];
			i += 1;
			data = data | (((usqInt) data << 8));
			data = data | (((usqInt) data << 16));
			for (j = 1; j <= n; j += 1) {
				bm[k] = data;
				k += 1;
			}
		}
		if (code == 2) {

			/* n consecutive words = 4 following bytes */

			data = 0;
			for (j = 1; j <= 4; j += 1) {
				data = (((usqInt) data << 8)) | (ba[i]);
				i += 1;
			}
			for (j = 1; j <= n; j += 1) {
				bm[k] = data;
				k += 1;
			}
		}
		if (code == 3) {
			for (m = 1; m <= n; m += 1) {

				/* n consecutive words from the data... */

				data = 0;
				for (j = 1; j <= 4; j += 1) {
					data = (((usqInt) data << 8)) | (ba[i]);
					i += 1;
				}
				bm[k] = data;
				k += 1;
			}
		}
	}
	if (!(successFlag)) {
		return null;
	}
	pop(3);
}

EXPORT(sqInt) primitiveFindFirstInString(void) {
    sqInt rcvr;
    unsigned char *aString;
    char *inclusionMap;
    sqInt start;
    sqInt i;
    sqInt stringSize;

	rcvr = stackValue(3);
	if (!(isBytes(stackValue(2)))) {
		return primitiveFail();
	}
	aString = arrayValueOf(stackValue(2));
	aString -= 1;
	if (!(isBytes(stackValue(1)))) {
		return primitiveFail();
	}
	inclusionMap = arrayValueOf(stackValue(1));
	inclusionMap -= 1;
	start = stackIntegerValue(0);
	if (!(successFlag)) {
		return null;
	}
	if ((sizeOfSTArrayFromCPrimitive(inclusionMap + 1)) != 256) {
		if (!(successFlag)) {
			return null;
		}
		pop(4);
		pushInteger(0);
		return null;
	}
	i = start;
	stringSize = sizeOfSTArrayFromCPrimitive(aString + 1);
	while ((i <= stringSize) && ((inclusionMap[(asciiValue(aString[i])) + 1]) == 0)) {
		i += 1;
	}
	if (i > stringSize) {
		if (!(successFlag)) {
			return null;
		}
		pop(4);
		pushInteger(0);
		return null;
	}
	if (!(successFlag)) {
		return null;
	}
	pop(4);
	pushInteger(i);
	return null;
}


/*	Answer the index in the string body at which the substring key first occurs, at or beyond start.  The match is determined using matchTable, which can be used to effect, eg, case-insensitive matches.  If no match is found, zero will be returned.

	The algorithm below is not optimum -- it is intended to be translated to C which will go so fast that it wont matter. */

EXPORT(sqInt) primitiveFindSubstring(void) {
    sqInt rcvr;
    unsigned char *key;
    unsigned char *body;
    sqInt start;
    unsigned char *matchTable;
    sqInt index;
    sqInt startIndex;

	rcvr = stackValue(4);
	if (!(isBytes(stackValue(3)))) {
		return primitiveFail();
	}
	key = arrayValueOf(stackValue(3));
	key -= 1;
	if (!(isBytes(stackValue(2)))) {
		return primitiveFail();
	}
	body = arrayValueOf(stackValue(2));
	body -= 1;
	start = stackIntegerValue(1);
	if (!(isBytes(stackValue(0)))) {
		return primitiveFail();
	}
	matchTable = arrayValueOf(stackValue(0));
	matchTable -= 1;
	if (!(successFlag)) {
		return null;
	}
	if ((sizeOfSTArrayFromCPrimitive(key + 1)) == 0) {
		if (!(successFlag)) {
			return null;
		}
		pop(5);
		pushInteger(0);
		return null;
	}
	for (startIndex = start; startIndex <= (((sizeOfSTArrayFromCPrimitive(body + 1)) - (sizeOfSTArrayFromCPrimitive(key + 1))) + 1); startIndex += 1) {
		index = 1;
		while ((matchTable[(asciiValue(body[(startIndex + index) - 1])) + 1]) == (matchTable[(asciiValue(key[index])) + 1])) {
			if (index == (sizeOfSTArrayFromCPrimitive(key + 1))) {
				if (!(successFlag)) {
					return null;
				}
				pop(5);
				pushInteger(startIndex);
				return null;
			}
			index += 1;
		}
	}
	if (!(successFlag)) {
		return null;
	}
	pop(5);
	pushInteger(0);
	return null;
}

EXPORT(sqInt) primitiveIndexOfAsciiInString(void) {
    sqInt rcvr;
    sqInt anInteger;
    unsigned char *aString;
    sqInt start;
    sqInt pos;
    sqInt stringSize;

	rcvr = stackValue(3);
	anInteger = stackIntegerValue(2);
	if (!(isBytes(stackValue(1)))) {
		return primitiveFail();
	}
	aString = arrayValueOf(stackValue(1));
	aString -= 1;
	start = stackIntegerValue(0);
	if (!(successFlag)) {
		return null;
	}
	stringSize = sizeOfSTArrayFromCPrimitive(aString + 1);
	for (pos = start; pos <= stringSize; pos += 1) {
		if ((asciiValue(aString[pos])) == anInteger) {
			if (!(successFlag)) {
				return null;
			}
			pop(4);
			pushInteger(pos);
			return null;
		}
	}
	if (!(successFlag)) {
		return null;
	}
	pop(4);
	pushInteger(0);
	return null;
}


/*	Answer the hash of a byte-indexed collection,
	using speciesHash as the initial value.
	See SmallInteger>>hashMultiply.

	The primitive should be renamed at a
	suitable point in the future */

EXPORT(sqInt) primitiveStringHash(void) {
    sqInt rcvr;
    unsigned char *aByteArray;
    sqInt speciesHash;
    sqInt byteArraySize;
    sqInt hash;
    sqInt low;
    sqInt pos;

	rcvr = stackValue(2);
	if (!(isBytes(stackValue(1)))) {
		return primitiveFail();
	}
	aByteArray = arrayValueOf(stackValue(1));
	aByteArray -= 1;
	speciesHash = stackIntegerValue(0);
	if (!(successFlag)) {
		return null;
	}
	byteArraySize = sizeOfSTArrayFromCPrimitive(aByteArray + 1);
	hash = speciesHash & 268435455;
	for (pos = 1; pos <= byteArraySize; pos += 1) {

		/* Begin hashMultiply */

		hash += aByteArray[pos];
		low = hash & 16383;
		hash = ((9741 * low) + ((((9741 * (((usqInt) hash >> 14))) + (101 * low)) & 16383) * 16384)) & 268435455;
	}
	if (!(successFlag)) {
		return null;
	}
	pop(3);
	pushInteger(hash);
	return null;
}


/*	translate the characters in the string by the given table, in place */

EXPORT(sqInt) primitiveTranslateStringWithTable(void) {
    sqInt rcvr;
    unsigned char *aString;
    sqInt start;
    sqInt stop;
    unsigned char *table;
    sqInt i;

	rcvr = stackValue(4);
	if (!(isBytes(stackValue(3)))) {
		return primitiveFail();
	}
	aString = arrayValueOf(stackValue(3));
	aString -= 1;
	start = stackIntegerValue(2);
	stop = stackIntegerValue(1);
	if (!(isBytes(stackValue(0)))) {
		return primitiveFail();
	}
	table = arrayValueOf(stackValue(0));
	table -= 1;
	if (!(successFlag)) {
		return null;
	}
	for (i = start; i <= stop; i += 1) {
		aString[i] = (table[(asciiValue(aString[i])) + 1]);
	}
	if (!(successFlag)) {
		return null;
	}
	pop(4);
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


void* MiscPrimitivePlugin_exports[][3] = {
	{"MiscPrimitivePlugin", "primitiveConvert8BitSigned", (void*)primitiveConvert8BitSigned},
	{"MiscPrimitivePlugin", "primitiveCompareString", (void*)primitiveCompareString},
	{"MiscPrimitivePlugin", "primitiveTranslateStringWithTable", (void*)primitiveTranslateStringWithTable},
	{"MiscPrimitivePlugin", "primitiveStringHash", (void*)primitiveStringHash},
	{"MiscPrimitivePlugin", "primitiveCompressToByteArray", (void*)primitiveCompressToByteArray},
	{"MiscPrimitivePlugin", "primitiveFindSubstring", (void*)primitiveFindSubstring},
	{"MiscPrimitivePlugin", "primitiveIndexOfAsciiInString", (void*)primitiveIndexOfAsciiInString},
	{"MiscPrimitivePlugin", "setInterpreter", (void*)setInterpreter},
	{"MiscPrimitivePlugin", "primitiveDecompressFromByteArray", (void*)primitiveDecompressFromByteArray},
	{"MiscPrimitivePlugin", "getModuleName", (void*)getModuleName},
	{"MiscPrimitivePlugin", "primitiveFindFirstInString", (void*)primitiveFindFirstInString},
	{NULL, NULL, NULL}
};


#endif /* ifdef SQ_BUILTIN_PLUGIN */

