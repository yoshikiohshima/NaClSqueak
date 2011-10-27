/* Automatically generated from Squeak on 26 April 2011 1:22:10 pm 
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
static double degreesFromXy(double x, double y);
static double degreesToRadians(double degrees);
#pragma export on
EXPORT(sqInt) drawTurtlesInArray(void);
EXPORT(sqInt) getHeadingArrayInto(void);
#pragma export off
static VirtualMachine * getInterpreter(void);
#pragma export on
EXPORT(const char*) getModuleName(void);
EXPORT(sqInt) getScalarHeading(void);
#pragma export off
static sqInt halt(void);
#pragma export on
EXPORT(sqInt) initialiseModule(void);
#pragma export off
static sqInt kedamaRandom2(sqInt range);
static sqInt kedamaRandom(sqInt range);
#pragma export on
EXPORT(sqInt) kedamaSetRandomSeed(void);
EXPORT(sqInt) makeMask(void);
EXPORT(sqInt) makeMaskLog(void);
EXPORT(sqInt) makeTurtlesMap(void);
#pragma export off
static sqInt msg(char *s);
#pragma export on
EXPORT(sqInt) primPixelAtXY(void);
EXPORT(sqInt) primPixelAtXYPut(void);
EXPORT(sqInt) primPixelsAtXY(void);
EXPORT(sqInt) primScalarForward(void);
EXPORT(sqInt) primSetPixelsAtXY(void);
EXPORT(sqInt) primTurtlesForward(void);
EXPORT(sqInt) primUpHill(void);
EXPORT(sqInt) primitiveAddArrays(void);
EXPORT(sqInt) primitiveAddScalar(void);
EXPORT(sqInt) primitiveDivArrays(void);
EXPORT(sqInt) primitiveDivScalar(void);
EXPORT(sqInt) primitiveMulArrays(void);
EXPORT(sqInt) primitiveMulScalar(void);
EXPORT(sqInt) primitiveSubArrays(void);
EXPORT(sqInt) primitiveSubScalar(void);
#pragma export off
static double radiansToDegrees(double radians);
#pragma export on
EXPORT(sqInt) randomIntoFloatArray(void);
EXPORT(sqInt) randomIntoIntegerArray(void);
EXPORT(sqInt) randomRange(void);
EXPORT(sqInt) scalarGetAngleTo(void);
EXPORT(sqInt) scalarGetDistanceTo(void);
#pragma export off
static sqInt scalarXAtxArrayheadingArrayvaluedestWidthleftEdgeModerightEdgeMode(sqInt index, float* xArray, float* headingArray, double val, double destWidth, sqInt leftEdgeMode, sqInt rightEdgeMode);
static sqInt scalarYAtyArrayheadingArrayvaluedestHeighttopEdgeModebottomEdgeMode(sqInt index, float* yArray, float* headingArray, double val, double destHeight, sqInt topEdgeMode, sqInt bottomEdgeMode);
#pragma export on
EXPORT(sqInt) setHeadingArrayFrom(void);
EXPORT(sqInt) setInterpreter(struct VirtualMachine*anInterpreter);
EXPORT(sqInt) setScalarHeading(void);
EXPORT(sqInt) shutdownModule(void);
EXPORT(sqInt) turtleScalarSetX(void);
EXPORT(sqInt) turtleScalarSetY(void);
EXPORT(sqInt) turtlesSetX(void);
EXPORT(sqInt) turtlesSetY(void);
EXPORT(sqInt) vectorGetAngleTo(void);
EXPORT(sqInt) vectorGetDistanceTo(void);
EXPORT(sqInt) zoomBitmap(void);
#pragma export off
/*** Variables ***/

#ifdef SQUEAK_BUILTIN_PLUGIN
extern
#endif
struct VirtualMachine* interpreterProxy;
static unsigned int kedamaRandomSeed;
static const char *moduleName =
#ifdef SQUEAK_BUILTIN_PLUGIN
	"KedamaPlugin 26 April 2011 (i)"
#else
	"KedamaPlugin 26 April 2011 (e)"
#endif
;
static unsigned int randA;
static unsigned int randM;
static unsigned int randQ;
static unsigned int randR;


static double degreesFromXy(double x, double y) {
    double tanVal;
    double theta;

	if (x == 0.0) {
		if (y >= 0.0) {
			return 90.0;
		} else {
			return 270.0;
		}
	} else {
		tanVal = y / x;
		theta = atan(tanVal);
		if (x >= 0.0) {
			if (y >= 0.0) {
				return theta / 0.0174532925199433;
			} else {
				return 360.0 + (theta / 0.0174532925199433);
			}
		} else {
			return 180.0 + (theta / 0.0174532925199433);
		}
	}
	return 0.0;
}

static double degreesToRadians(double degrees) {
    double deg;
    double headingRadians;
    int q;

	deg = 90.0 - degrees;
	q = deg / 360.0;
	if (deg < 0.0) {
		q -= 1;
	}
	headingRadians = (deg - (q * 360.0)) * 0.0174532925199433;
	return headingRadians;
}

EXPORT(sqInt) drawTurtlesInArray(void) {
    sqInt bitsIndex;
    unsigned int *colorArray;
    sqInt colorOop;
    unsigned int *destBits;
    sqInt destHeight;
    sqInt destOop;
    sqInt destWidth;
    sqInt i;
    sqInt size;
    sqInt visible;
    unsigned char *visibleArray;
    sqInt visibleOop;
    sqInt x;
    float *xArray;
    sqInt xOop;
    sqInt y;
    float *yArray;
    sqInt yOop;

	visibleOop = interpreterProxy->stackValue(0);
	colorOop = interpreterProxy->stackValue(1);
	yOop = interpreterProxy->stackValue(2);
	xOop = interpreterProxy->stackValue(3);
	destHeight = interpreterProxy->stackIntegerValue(4);
	destWidth = interpreterProxy->stackIntegerValue(5);
	destOop = interpreterProxy->stackValue(6);
	if (interpreterProxy->failed()) {
		return null;
	}
	if (!(interpreterProxy->isWords(destOop))) {
		interpreterProxy->primitiveFail();
		return null;
	}
	if (!(interpreterProxy->isWords(xOop))) {
		interpreterProxy->primitiveFail();
		return null;
	}
	if (!(interpreterProxy->isWords(yOop))) {
		interpreterProxy->primitiveFail();
		return null;
	}
	if (!(interpreterProxy->isWords(colorOop))) {
		interpreterProxy->primitiveFail();
		return null;
	}
	if (!(interpreterProxy->isBytes(visibleOop))) {
		interpreterProxy->primitiveFail();
		return null;
	}
	if ((destHeight * destWidth) != (interpreterProxy->slotSizeOf(destOop))) {
		interpreterProxy->primitiveFail();
		return null;
	}
	size = interpreterProxy->slotSizeOf(xOop);
	if ((interpreterProxy->slotSizeOf(yOop)) != size) {
		interpreterProxy->primitiveFail();
		return null;
	}
	if ((interpreterProxy->slotSizeOf(colorOop)) != size) {
		interpreterProxy->primitiveFail();
		return null;
	}
	if ((interpreterProxy->slotSizeOf(visibleOop)) != size) {
		interpreterProxy->primitiveFail();
		return null;
	}
	xArray = interpreterProxy->firstIndexableField(xOop);
	yArray = interpreterProxy->firstIndexableField(yOop);
	colorArray = interpreterProxy->firstIndexableField(colorOop);
	visibleArray = interpreterProxy->firstIndexableField(visibleOop);
	destBits = interpreterProxy->firstIndexableField(destOop);
	for (i = 0; i <= (size - 1); i += 1) {
		x = ((int) (xArray[i]));
		;
		y = ((int) (yArray[i]));
		;
		visible = visibleArray[i];
		if ((visible != 0) && (((x >= 0) && (y >= 0)) && ((x < destWidth) && (y < destHeight)))) {
			bitsIndex = (y * destWidth) + x;
			destBits[bitsIndex] = (colorArray[i]);
		}
	}
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->pop(7);
}

EXPORT(sqInt) getHeadingArrayInto(void) {
    double heading;
    float *headingArray;
    sqInt headingOop;
    sqInt i;
    float *resultArray;
    sqInt resultOop;
    sqInt size;

	resultOop = interpreterProxy->stackValue(0);
	headingOop = interpreterProxy->stackValue(1);
	if (interpreterProxy->failed()) {
		return null;
	}
	if (!(interpreterProxy->isWords(headingOop))) {
		interpreterProxy->primitiveFail();
		return null;
	}
	if (!(interpreterProxy->isWords(resultOop))) {
		interpreterProxy->primitiveFail();
		return null;
	}
	size = interpreterProxy->slotSizeOf(headingOop);
	if ((interpreterProxy->slotSizeOf(resultOop)) != size) {
		interpreterProxy->primitiveFail();
		return null;
	}
	headingArray = interpreterProxy->firstIndexableField(headingOop);
	resultArray = interpreterProxy->firstIndexableField(resultOop);
	for (i = 0; i <= (size - 1); i += 1) {
		heading = headingArray[i];
		heading = heading / 0.0174532925199433;
		heading = 90.0 - heading;
		if (!(heading > 0.0)) {
			heading += 360.0;
		}
		resultArray[i] = heading;
	}
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->pop(2);
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

EXPORT(sqInt) getScalarHeading(void) {
    double heading;
    float *headingArray;
    sqInt headingOop;
    sqInt index;
    double deg;
    double degrees;

	headingOop = interpreterProxy->stackValue(0);
	index = interpreterProxy->stackIntegerValue(1);
	if (interpreterProxy->failed()) {
		return null;
	}
	if (!(interpreterProxy->isWords(headingOop))) {
		interpreterProxy->primitiveFail();
		return null;
	}
	if ((interpreterProxy->slotSizeOf(headingOop)) < index) {
		interpreterProxy->primitiveFail();
		return null;
	}
	headingArray = interpreterProxy->firstIndexableField(headingOop);
	heading = headingArray[index - 1];
	/* begin radiansToDegrees: */
	degrees = heading / 0.0174532925199433;
	deg = 90.0 - degrees;
	if (!(deg > 0.0)) {
		deg += 360.0;
	}
	heading = deg;
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->pop(3);
	interpreterProxy->pushFloat(heading);
}

static sqInt halt(void) {
	;
}

EXPORT(sqInt) initialiseModule(void) {
	kedamaRandomSeed = 17;

	/*  magic constant =      16807  */

	randA = 16807;

	/*  magic constant = 2147483647  */

	randM = 2147483647U;
	randQ = randM / randA;
	randR = randM % randA;
}

static sqInt kedamaRandom2(sqInt range) {
    sqInt hi;
    sqInt lo;
    sqInt r;
    sqInt v;
    sqInt val;

	if (range < 0) {
		r = 0 - range;
	} else {
		r = range;
	}
	hi = kedamaRandomSeed / randQ;
	lo = kedamaRandomSeed % randQ;
	kedamaRandomSeed = (randA * lo) - (randR * hi);
	v = kedamaRandomSeed & 65535;
	val = ((usqInt) (v * (r + 1))) >> 16;
	if (range < 0) {
		return 0 - val;
	} else {
		return val;
	}
}

static sqInt kedamaRandom(sqInt range) {
    sqInt r;
    sqInt val;

	if (range < 0) {
		r = 0 - range;
	} else {
		r = range;
	}
	kedamaRandomSeed = ((kedamaRandomSeed * 1309) + 13849) & 65535;
	val = ((usqInt) (kedamaRandomSeed * (r + 1))) >> 16;
	if (range < 0) {
		return 0 - val;
	} else {
		return val;
	}
}

EXPORT(sqInt) kedamaSetRandomSeed(void) {
    sqInt seed;

	seed = interpreterProxy->stackIntegerValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	kedamaRandomSeed = seed & 65536;
	interpreterProxy->pop(1);
}

EXPORT(sqInt) makeMask(void) {
    unsigned int alpha;
    unsigned int* dOrigin;
    sqInt data;
    sqInt dataBits;
    sqInt dataSize;
    unsigned int highMask;
    sqInt i;
    unsigned int* mOrigin;
    sqInt maskBits;
    sqInt maskSize;
    unsigned int pixel;
    sqInt shiftAmount;

	shiftAmount = interpreterProxy->stackIntegerValue(0);
	pixel = interpreterProxy->stackIntegerValue(1);
	maskBits = interpreterProxy->stackValue(2);
	dataBits = interpreterProxy->stackValue(3);
	if (interpreterProxy->failed()) {
		return null;
	}
	dataSize = interpreterProxy->slotSizeOf(dataBits);
	maskSize = interpreterProxy->slotSizeOf(maskBits);
	if (!(dataSize == maskSize)) {
		interpreterProxy->primitiveFail();
		return null;
	}
	if (shiftAmount < -32) {
		interpreterProxy->primitiveFail();
		return null;
	}
	if (shiftAmount > 8) {
		interpreterProxy->primitiveFail();
		return null;
	}
	dOrigin = interpreterProxy->firstIndexableField(dataBits);
	mOrigin = interpreterProxy->firstIndexableField(maskBits);
	highMask = 4278190080U;
	for (i = 0; i <= (dataSize - 1); i += 1) {
		data = dOrigin[i];
		alpha = ((shiftAmount < 0) ? ((usqInt) data >> -shiftAmount) : ((usqInt) data << shiftAmount));
		if (alpha > 255) {
			alpha = 255;
		}
		if (alpha < 0) {
			alpha = 0;
		}
		mOrigin[i] = (((alpha << 24) & highMask) | pixel);
	}
	interpreterProxy->pop(4);
}

EXPORT(sqInt) makeMaskLog(void) {
    unsigned int alpha;
    unsigned int* dOrigin;
    sqInt data;
    sqInt dataBits;
    sqInt dataSize;
    unsigned int highMask;
    sqInt i;
    unsigned int* mOrigin;
    sqInt maskBits;
    sqInt maskSize;
    unsigned int max;
    unsigned int* maxFirst;
    double maxLog;
    sqInt maxOop;
    unsigned int pixel;

	maxOop = interpreterProxy->stackValue(0);
	pixel = interpreterProxy->stackIntegerValue(1);
	maskBits = interpreterProxy->stackValue(2);
	dataBits = interpreterProxy->stackValue(3);
	if (interpreterProxy->failed()) {
		return null;
	}
	maxFirst = interpreterProxy->firstIndexableField(maxOop);
	max = maxFirst[0];
	if (interpreterProxy->failed()) {
		return null;
	}
	maxLog = log(max);
	dataSize = interpreterProxy->slotSizeOf(dataBits);
	maskSize = interpreterProxy->slotSizeOf(maskBits);
	if (!(dataSize == maskSize)) {
		interpreterProxy->primitiveFail();
		return null;
	}
	dOrigin = interpreterProxy->firstIndexableField(dataBits);
	mOrigin = interpreterProxy->firstIndexableField(maskBits);
	highMask = 4278190080U;
	for (i = 0; i <= (dataSize - 1); i += 1) {
		data = dOrigin[i];
		if (data == 0) {
			alpha = 0;
		} else {
			alpha = ((sqInt)((255.0 / maxLog) * (log(data))));
		}
		if (alpha > 255) {
			alpha = 255;
		}
		mOrigin[i] = (((alpha << 24) & highMask) | pixel);
	}
	interpreterProxy->pop(4);
}

EXPORT(sqInt) makeTurtlesMap(void) {
    sqInt height;
    sqInt index;
    unsigned int *map;
    sqInt mapIndex;
    sqInt mapOop;
    sqInt size;
    unsigned int *whoArray;
    sqInt whoOop;
    sqInt width;
    sqInt x;
    float *xArray;
    sqInt xOop;
    sqInt y;
    float *yArray;
    sqInt yOop;

	height = interpreterProxy->stackIntegerValue(0);
	width = interpreterProxy->stackIntegerValue(1);
	yOop = interpreterProxy->stackValue(2);
	xOop = interpreterProxy->stackValue(3);
	whoOop = interpreterProxy->stackValue(4);
	mapOop = interpreterProxy->stackValue(5);
	if (!(interpreterProxy->isWords(yOop))) {
		interpreterProxy->primitiveFail();
		return null;
	}
	if (!(interpreterProxy->isWords(xOop))) {
		interpreterProxy->primitiveFail();
		return null;
	}
	if (!(interpreterProxy->isWords(whoOop))) {
		interpreterProxy->primitiveFail();
		return null;
	}
	if (!(interpreterProxy->isWords(mapOop))) {
		interpreterProxy->primitiveFail();
		return null;
	}
	size = interpreterProxy->slotSizeOf(whoOop);
	if ((interpreterProxy->slotSizeOf(xOop)) != size) {
		interpreterProxy->primitiveFail();
		return null;
	}
	if ((interpreterProxy->slotSizeOf(yOop)) != size) {
		interpreterProxy->primitiveFail();
		return null;
	}
	if ((interpreterProxy->slotSizeOf(mapOop)) != (height * width)) {
		interpreterProxy->primitiveFail();
		return null;
	}
	xArray = interpreterProxy->firstIndexableField(xOop);
	yArray = interpreterProxy->firstIndexableField(yOop);
	whoArray = interpreterProxy->firstIndexableField(whoOop);
	map = interpreterProxy->firstIndexableField(mapOop);
	for (index = 0; index <= ((height * width) - 1); index += 1) {
		map[index] = 0;
	}
	for (index = 0; index <= (size - 1); index += 1) {
		x = xArray[index];
		y = yArray[index];
		mapIndex = (width * y) + x;
		if ((mapIndex >= 0) && (mapIndex < (height * width))) {
			map[mapIndex] = (whoArray[index]);
		}
	}
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->pop(6);
}

static sqInt msg(char *s) {
	fprintf(stderr, "\n%s: %s", moduleName, s);
}

EXPORT(sqInt) primPixelAtXY(void) {
    unsigned int *bits;
    sqInt bitsOop;
    sqInt height;
    sqInt index;
    sqInt ret;
    sqInt width;
    sqInt x;
    double xPos;
    sqInt y;
    double yPos;

	height = interpreterProxy->stackIntegerValue(0);
	width = interpreterProxy->stackIntegerValue(1);
	yPos = interpreterProxy->stackFloatValue(2);
	xPos = interpreterProxy->stackFloatValue(3);
	bitsOop = interpreterProxy->stackValue(4);
	if (interpreterProxy->failed()) {
		return null;
	}
	if (!(interpreterProxy->isWords(bitsOop))) {
		interpreterProxy->primitiveFail();
		return null;
	}
	if ((interpreterProxy->slotSizeOf(bitsOop)) != (height * width)) {
		interpreterProxy->primitiveFail();
		return null;
	}
	x = xPos;
	y = yPos;
	bits = interpreterProxy->firstIndexableField(bitsOop);
	if ((((x >= 0) && (x < width)) && (y >= 0)) && (y < height)) {
		index = (y * width) + x;
		ret = bits[index];
	} else {
		ret = 0;
	}
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->pop(6);
	interpreterProxy->pushInteger(ret);
}

EXPORT(sqInt) primPixelAtXYPut(void) {
    unsigned int *bits;
    sqInt bitsOop;
    sqInt height;
    sqInt index;
    sqInt v;
    sqInt value;
    sqInt width;
    sqInt x;
    double xPos;
    sqInt y;
    double yPos;

	height = interpreterProxy->stackIntegerValue(0);
	width = interpreterProxy->stackIntegerValue(1);
	value = interpreterProxy->stackIntegerValue(2);
	yPos = interpreterProxy->stackFloatValue(3);
	xPos = interpreterProxy->stackFloatValue(4);
	bitsOop = interpreterProxy->stackValue(5);
	if (interpreterProxy->failed()) {
		return null;
	}
	if (!(interpreterProxy->isWords(bitsOop))) {
		interpreterProxy->primitiveFail();
		return null;
	}
	if ((interpreterProxy->slotSizeOf(bitsOop)) != (height * width)) {
		interpreterProxy->primitiveFail();
		return null;
	}
	x = xPos;
	y = yPos;
	v = value;
	if (v > 1073741823) {
		v = 1073741823;
	}
	if (v < 0) {
		v = 0;
	}
	bits = interpreterProxy->firstIndexableField(bitsOop);
	if ((((x >= 0) && (x < width)) && (y >= 0)) && (y < height)) {
		index = (y * width) + x;
		bits[index] = v;
	}
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->pop(6);
}

EXPORT(sqInt) primPixelsAtXY(void) {
    unsigned int *bits;
    sqInt bitsHeight;
    sqInt bitsIndex;
    sqInt bitsOop;
    sqInt bitsWidth;
    unsigned int *destWords;
    sqInt destWordsOop;
    sqInt i;
    sqInt size;
    sqInt x;
    float *xArray;
    sqInt xArrayOop;
    sqInt y;
    float *yArray;
    sqInt yArrayOop;

	destWordsOop = interpreterProxy->stackValue(0);
	bitsHeight = interpreterProxy->stackIntegerValue(1);
	bitsWidth = interpreterProxy->stackIntegerValue(2);
	bitsOop = interpreterProxy->stackValue(3);
	yArrayOop = interpreterProxy->stackValue(4);
	xArrayOop = interpreterProxy->stackValue(5);
	if (interpreterProxy->failed()) {
		return null;
	}
	if (!(interpreterProxy->isWords(destWordsOop))) {
		interpreterProxy->primitiveFail();
		return null;
	}
	if (!(interpreterProxy->isWords(xArrayOop))) {
		interpreterProxy->primitiveFail();
		return null;
	}
	if (!(interpreterProxy->isWords(yArrayOop))) {
		interpreterProxy->primitiveFail();
		return null;
	}
	if (!(interpreterProxy->isWords(bitsOop))) {
		interpreterProxy->primitiveFail();
		return null;
	}
	if ((bitsHeight * bitsWidth) != (interpreterProxy->slotSizeOf(bitsOop))) {
		interpreterProxy->primitiveFail();
		return null;
	}
	size = interpreterProxy->slotSizeOf(xArrayOop);
	if ((interpreterProxy->slotSizeOf(yArrayOop)) != size) {
		interpreterProxy->primitiveFail();
		return null;
	}
	if ((interpreterProxy->slotSizeOf(destWordsOop)) != size) {
		interpreterProxy->primitiveFail();
		return null;
	}
	xArray = interpreterProxy->firstIndexableField(xArrayOop);
	yArray = interpreterProxy->firstIndexableField(yArrayOop);
	destWords = interpreterProxy->firstIndexableField(destWordsOop);
	bits = interpreterProxy->firstIndexableField(bitsOop);
	for (i = 0; i <= (size - 1); i += 1) {
		x = ((int) (xArray[i]));
		;
		y = ((int) (yArray[i]));
		;
		if (((x >= 0) && (y >= 0)) && ((x < bitsWidth) && (y < bitsHeight))) {
			bitsIndex = (y * bitsWidth) + x;
			destWords[i] = (bits[bitsIndex]);
		}
	}
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->pop(6);
}

EXPORT(sqInt) primScalarForward(void) {
    sqInt bottomEdgeMode;
    double destHeight;
    double destWidth;
    double dist;
    float *headingArray;
    sqInt headingOop;
    sqInt i;
    sqInt index;
    sqInt leftEdgeMode;
    double newX;
    double newY;
    sqInt rightEdgeMode;
    sqInt size;
    sqInt topEdgeMode;
    double val;
    float *xArray;
    sqInt xOop;
    float *yArray;
    sqInt yOop;
    double headingRadians;
    double newX1;
    double newY1;

	bottomEdgeMode = interpreterProxy->stackIntegerValue(0);
	topEdgeMode = interpreterProxy->stackIntegerValue(1);
	rightEdgeMode = interpreterProxy->stackIntegerValue(2);
	leftEdgeMode = interpreterProxy->stackIntegerValue(3);
	destHeight = interpreterProxy->stackFloatValue(4);
	destWidth = interpreterProxy->stackFloatValue(5);
	val = interpreterProxy->stackFloatValue(6);
	headingOop = interpreterProxy->stackValue(7);
	yOop = interpreterProxy->stackValue(8);
	xOop = interpreterProxy->stackValue(9);
	index = interpreterProxy->stackIntegerValue(10);
	if (interpreterProxy->failed()) {
		return null;
	}
	if (!(interpreterProxy->isWords(xOop))) {
		interpreterProxy->primitiveFail();
		return null;
	}
	if (!(interpreterProxy->isWords(yOop))) {
		interpreterProxy->primitiveFail();
		return null;
	}
	if (!(interpreterProxy->isWords(headingOop))) {
		interpreterProxy->primitiveFail();
		return null;
	}
	size = interpreterProxy->slotSizeOf(xOop);
	if ((interpreterProxy->slotSizeOf(yOop)) != size) {
		interpreterProxy->primitiveFail();
		return null;
	}
	if ((interpreterProxy->slotSizeOf(headingOop)) != size) {
		interpreterProxy->primitiveFail();
		return null;
	}
	xArray = interpreterProxy->firstIndexableField(xOop);
	yArray = interpreterProxy->firstIndexableField(yOop);
	headingArray = interpreterProxy->firstIndexableField(headingOop);
	dist = val;
	i = index - 1;
	newX = (xArray[i]) + (dist * (cos(headingArray[i])));
	newY = (yArray[i]) - (dist * (sin(headingArray[i])));
	/* begin scalarXAt:xArray:headingArray:value:destWidth:leftEdgeMode:rightEdgeMode: */
	newX1 = newX;
	if (newX1 < 0.0) {
		if (leftEdgeMode == 1) {
			newX1 += destWidth;
		}
		if (leftEdgeMode == 2) {
			newX1 = 0.0;
		}
		if (leftEdgeMode == 3) {
			newX1 = 0.0 - newX1;
			headingRadians = headingArray[i];
			if (headingRadians < 3.141592653589793) {
				headingArray[i] = (3.141592653589793 - headingRadians);
			} else {
				headingArray[i] = (9.42477796076938 - headingRadians);
			}
		}
	}
	if (newX1 >= destWidth) {
		if (rightEdgeMode == 1) {
			newX1 -= destWidth;
		}
		if (rightEdgeMode == 2) {
			newX1 = destWidth - 1.0e-6;
		}
		if (rightEdgeMode == 3) {
			newX1 = (destWidth - 1.0e-6) - (newX1 - destWidth);
			headingRadians = headingArray[i];
			if (headingRadians < 3.141592653589793) {
				headingArray[i] = (3.141592653589793 - headingRadians);
			} else {
				headingArray[i] = (9.42477796076938 - headingRadians);
			}
		}
	}
	xArray[i] = newX1;
	/* begin scalarYAt:yArray:headingArray:value:destHeight:topEdgeMode:bottomEdgeMode: */
	newY1 = newY;
	if (newY1 < 0.0) {
		if (topEdgeMode == 1) {
			newY1 += destHeight;
		}
		if (topEdgeMode == 2) {
			newY1 = 0.0;
		}
		if (topEdgeMode == 3) {
			newY1 = 0.0 - newY1;
			headingArray[i] = (6.283185307179586 - (headingArray[i]));
		}
	}
	if (newY1 >= destHeight) {
		if (bottomEdgeMode == 1) {
			newY1 -= destHeight;
		}
		if (bottomEdgeMode == 2) {
			newY1 = destHeight - 1.0e-6;
		}
		if (bottomEdgeMode == 3) {
			newY1 = (destHeight - 1.0e-6) - (newY1 - destHeight);
			headingArray[i] = (6.283185307179586 - (headingArray[i]));
		}
	}
	yArray[i] = newY1;
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->pop(11);
}

EXPORT(sqInt) primSetPixelsAtXY(void) {
    unsigned int *bits;
    sqInt bitsHeight;
    sqInt bitsIndex;
    sqInt bitsOop;
    sqInt bitsWidth;
    sqInt i;
    unsigned int intValue;
    sqInt isValueInt;
    sqInt size;
    unsigned int value;
    sqInt valueOop;
    unsigned int *wordsValue;
    sqInt x;
    float *xArray;
    sqInt xArrayOop;
    sqInt y;
    float *yArray;
    sqInt yArrayOop;

	valueOop = interpreterProxy->stackValue(0);
	bitsHeight = interpreterProxy->stackIntegerValue(1);
	bitsWidth = interpreterProxy->stackIntegerValue(2);
	bitsOop = interpreterProxy->stackValue(3);
	yArrayOop = interpreterProxy->stackValue(4);
	xArrayOop = interpreterProxy->stackValue(5);
	if (interpreterProxy->failed()) {
		return null;
	}
	if (!(interpreterProxy->isWords(xArrayOop))) {
		interpreterProxy->primitiveFail();
		return null;
	}
	if (!(interpreterProxy->isWords(yArrayOop))) {
		interpreterProxy->primitiveFail();
		return null;
	}
	if (!(interpreterProxy->isWords(bitsOop))) {
		interpreterProxy->primitiveFail();
		return null;
	}
	if ((bitsHeight * bitsWidth) != (interpreterProxy->slotSizeOf(bitsOop))) {
		interpreterProxy->primitiveFail();
		return null;
	}
	size = interpreterProxy->slotSizeOf(xArrayOop);
	if ((interpreterProxy->slotSizeOf(yArrayOop)) != size) {
		interpreterProxy->primitiveFail();
		return null;
	}
	isValueInt = (valueOop & 1);
	if (isValueInt) {
		intValue = (valueOop >> 1);
	}
	if (!(isValueInt)) {
		if (!(interpreterProxy->isMemberOf(valueOop, "WordArray"))) {
			interpreterProxy->primitiveFail();
			return null;
		}
		if ((interpreterProxy->slotSizeOf(valueOop)) != size) {
			interpreterProxy->primitiveFail();
			return null;
		}
	}
	xArray = interpreterProxy->firstIndexableField(xArrayOop);
	yArray = interpreterProxy->firstIndexableField(yArrayOop);
	if (!(isValueInt)) {
		wordsValue = interpreterProxy->firstIndexableField(valueOop);
	}
	bits = interpreterProxy->firstIndexableField(bitsOop);
	if (isValueInt) {
		value = intValue;
	}
	for (i = 0; i <= (size - 1); i += 1) {
		x = ((int) (xArray[i]));
		;
		y = ((int) (yArray[i]));
		;
		if (((x >= 0) && (y >= 0)) && ((x < bitsWidth) && (y < bitsHeight))) {
			bitsIndex = (y * bitsWidth) + x;
			if (!(isValueInt)) {
				value = wordsValue[i];
			}
			bits[bitsIndex] = value;
		}
	}
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->pop(6);
}

EXPORT(sqInt) primTurtlesForward(void) {
    sqInt bottomEdgeMode;
    double destHeight;
    double destWidth;
    double dist;
    float *headingArray;
    sqInt headingOop;
    sqInt i;
    sqInt isValVector;
    sqInt leftEdgeMode;
    double newX;
    double newY;
    sqInt rightEdgeMode;
    sqInt size;
    sqInt topEdgeMode;
    double val;
    float *valArray;
    sqInt valOop;
    float *xArray;
    sqInt xOop;
    float *yArray;
    sqInt yOop;
    double headingRadians;
    double newX1;
    double newY1;

	bottomEdgeMode = interpreterProxy->stackIntegerValue(0);
	topEdgeMode = interpreterProxy->stackIntegerValue(1);
	rightEdgeMode = interpreterProxy->stackIntegerValue(2);
	leftEdgeMode = interpreterProxy->stackIntegerValue(3);
	destHeight = interpreterProxy->stackFloatValue(4);
	destWidth = interpreterProxy->stackFloatValue(5);
	valOop = interpreterProxy->stackValue(6);
	headingOop = interpreterProxy->stackValue(7);
	yOop = interpreterProxy->stackValue(8);
	xOop = interpreterProxy->stackValue(9);
	if (interpreterProxy->failed()) {
		return null;
	}
	if (!(interpreterProxy->isWords(xOop))) {
		interpreterProxy->primitiveFail();
		return null;
	}
	if (!(interpreterProxy->isWords(yOop))) {
		interpreterProxy->primitiveFail();
		return null;
	}
	if (!(interpreterProxy->isWords(headingOop))) {
		interpreterProxy->primitiveFail();
		return null;
	}
	if (interpreterProxy->isFloatObject(valOop)) {
		isValVector = 0;
	} else {
		if (interpreterProxy->isWords(valOop)) {
			isValVector = 1;
		} else {
			interpreterProxy->primitiveFail();
			return null;
		}
	}
	size = interpreterProxy->slotSizeOf(xOop);
	if ((interpreterProxy->slotSizeOf(yOop)) != size) {
		interpreterProxy->primitiveFail();
		return null;
	}
	if ((interpreterProxy->slotSizeOf(headingOop)) != size) {
		interpreterProxy->primitiveFail();
		return null;
	}
	if (isValVector) {
		if ((interpreterProxy->slotSizeOf(valOop)) != size) {
			interpreterProxy->primitiveFail();
			return null;
		}
	}
	xArray = interpreterProxy->firstIndexableField(xOop);
	yArray = interpreterProxy->firstIndexableField(yOop);
	headingArray = interpreterProxy->firstIndexableField(headingOop);
	if (isValVector) {
		valArray = interpreterProxy->firstIndexableField(valOop);
	} else {
		val = interpreterProxy->floatValueOf(valOop);
	}
	for (i = 0; i <= (size - 1); i += 1) {
		if (isValVector) {
			dist = valArray[i];
		} else {
			dist = val;
		}
		newX = (xArray[i]) + (dist * (cos(headingArray[i])));
		newY = (yArray[i]) - (dist * (sin(headingArray[i])));
		/* begin scalarXAt:xArray:headingArray:value:destWidth:leftEdgeMode:rightEdgeMode: */
		newX1 = newX;
		if (newX1 < 0.0) {
			if (leftEdgeMode == 1) {
				newX1 += destWidth;
			}
			if (leftEdgeMode == 2) {
				newX1 = 0.0;
			}
			if (leftEdgeMode == 3) {
				newX1 = 0.0 - newX1;
				headingRadians = headingArray[i];
				if (headingRadians < 3.141592653589793) {
					headingArray[i] = (3.141592653589793 - headingRadians);
				} else {
					headingArray[i] = (9.42477796076938 - headingRadians);
				}
			}
		}
		if (newX1 >= destWidth) {
			if (rightEdgeMode == 1) {
				newX1 -= destWidth;
			}
			if (rightEdgeMode == 2) {
				newX1 = destWidth - 1.0e-6;
			}
			if (rightEdgeMode == 3) {
				newX1 = (destWidth - 1.0e-6) - (newX1 - destWidth);
				headingRadians = headingArray[i];
				if (headingRadians < 3.141592653589793) {
					headingArray[i] = (3.141592653589793 - headingRadians);
				} else {
					headingArray[i] = (9.42477796076938 - headingRadians);
				}
			}
		}
		xArray[i] = newX1;
		/* begin scalarYAt:yArray:headingArray:value:destHeight:topEdgeMode:bottomEdgeMode: */
		newY1 = newY;
		if (newY1 < 0.0) {
			if (topEdgeMode == 1) {
				newY1 += destHeight;
			}
			if (topEdgeMode == 2) {
				newY1 = 0.0;
			}
			if (topEdgeMode == 3) {
				newY1 = 0.0 - newY1;
				headingArray[i] = (6.283185307179586 - (headingArray[i]));
			}
		}
		if (newY1 >= destHeight) {
			if (bottomEdgeMode == 1) {
				newY1 -= destHeight;
			}
			if (bottomEdgeMode == 2) {
				newY1 = destHeight - 1.0e-6;
			}
			if (bottomEdgeMode == 3) {
				newY1 = (destHeight - 1.0e-6) - (newY1 - destHeight);
				headingArray[i] = (6.283185307179586 - (headingArray[i]));
			}
		}
		yArray[i] = newY1;
	}
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->pop(10);
}

EXPORT(sqInt) primUpHill(void) {
    unsigned int *bits;
    sqInt bitsOop;
    sqInt endX;
    sqInt endY;
    sqInt height;
    sqInt maxVal;
    sqInt maxValX;
    sqInt maxValY;
    double ret;
    sqInt rowOffset;
    sqInt sniffRange;
    sqInt startX;
    sqInt startY;
    double tH;
    double tX;
    double tY;
    sqInt thisVal;
    sqInt turtleX;
    sqInt turtleY;
    sqInt width;
    sqInt x;
    sqInt y;
    double deg;
    double degrees;

	sniffRange = interpreterProxy->stackIntegerValue(0);
	height = interpreterProxy->stackIntegerValue(1);
	width = interpreterProxy->stackIntegerValue(2);
	bitsOop = interpreterProxy->stackValue(3);
	tH = interpreterProxy->stackFloatValue(4);
	tY = interpreterProxy->stackFloatValue(5);
	tX = interpreterProxy->stackFloatValue(6);
	if (interpreterProxy->failed()) {
		return null;
	}
	if (!(interpreterProxy->isWords(bitsOop))) {
		interpreterProxy->primitiveFail();
		return null;
	}
	if ((interpreterProxy->slotSizeOf(bitsOop)) != (height * width)) {
		interpreterProxy->primitiveFail();
		return null;
	}
	bits = interpreterProxy->firstIndexableField(bitsOop);
	turtleX = tX;
	turtleY = tY;
	turtleX = ((turtleX < 0) ? 0 : turtleX);
	turtleY = ((turtleY < 0) ? 0 : turtleY);
	turtleX = ((turtleX < (width - 1)) ? turtleX : (width - 1));
	turtleY = ((turtleY < (height - 1)) ? turtleY : (height - 1));
	startX = (((turtleX - sniffRange) < 0) ? 0 : (turtleX - sniffRange));
	endX = (((turtleX + sniffRange) < (width - 1)) ? (turtleX + sniffRange) : (width - 1));
	startY = (((turtleY - sniffRange) < 0) ? 0 : (turtleY - sniffRange));
	endY = (((turtleY + sniffRange) < (height - 1)) ? (turtleY + sniffRange) : (height - 1));
	maxVal = bits[(turtleY * width) + turtleX];
	maxValX = -1;
	for (y = startY; y <= endY; y += 1) {
		rowOffset = y * width;
		for (x = startX; x <= endX; x += 1) {
			thisVal = bits[rowOffset + x];
			if (thisVal > maxVal) {
				maxValX = x;
				maxValY = y;
				maxVal = thisVal;
			}
		}
	}
	if (-1 == maxValX) {
		/* begin radiansToDegrees: */
		degrees = tH / 0.0174532925199433;
		deg = 90.0 - degrees;
		if (!(deg > 0.0)) {
			deg += 360.0;
		}
		ret = deg;
	} else {
		ret = (degreesFromXy(((double) (maxValX - turtleX)), ((double) (maxValY - turtleY)))) + 90.0;
	}
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->pop(8);
	interpreterProxy->pushFloat(ret);
}

EXPORT(sqInt) primitiveAddArrays(void) {
    sqInt argOop;
    float *floatsArg;
    float *floatsRcvr;
    float *floatsResult;
    sqInt i;
    sqInt isArgWords;
    sqInt isRcvrWords;
    sqInt length;
    sqInt rcvrOop;
    sqInt resultOop;
    unsigned int *wordsArg;
    unsigned int *wordsRcvr;
    unsigned int *wordsResult;

	resultOop = interpreterProxy->stackObjectValue(0);
	argOop = interpreterProxy->stackObjectValue(1);
	rcvrOop = interpreterProxy->stackObjectValue(2);
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->success(interpreterProxy->isWords(argOop));
	interpreterProxy->success(interpreterProxy->isWords(rcvrOop));
	interpreterProxy->success(interpreterProxy->isWords(resultOop));
	if (interpreterProxy->failed()) {
		return null;
	}
	length = interpreterProxy->stSizeOf(argOop);
	interpreterProxy->success(length == (interpreterProxy->stSizeOf(rcvrOop)));
	interpreterProxy->success(length == (interpreterProxy->stSizeOf(resultOop)));
	if (interpreterProxy->failed()) {
		return null;
	}
	isArgWords = interpreterProxy->isMemberOf(argOop, "WordArray");
	isRcvrWords = interpreterProxy->isMemberOf(rcvrOop, "WordArray");
	if (isArgWords && isRcvrWords) {
		if (!(interpreterProxy->isMemberOf(resultOop, "WordArray"))) {
			interpreterProxy->primitiveFail();
			return null;
		}
	} else {
		if (!(interpreterProxy->isMemberOf(resultOop, "KedamaFloatArray"))) {
			interpreterProxy->primitiveFail();
			return null;
		}
	}
	if (isRcvrWords) {
		if (isArgWords) {
			wordsRcvr = interpreterProxy->firstIndexableField(rcvrOop);
			wordsArg = interpreterProxy->firstIndexableField(argOop);
			wordsResult = interpreterProxy->firstIndexableField(resultOop);
			for (i = 0; i <= (length - 1); i += 1) {
				wordsResult[i] = ((wordsRcvr[i]) + (wordsArg[i]));
			}
		} else {
			wordsRcvr = interpreterProxy->firstIndexableField(rcvrOop);
			floatsArg = interpreterProxy->firstIndexableField(argOop);
			floatsResult = interpreterProxy->firstIndexableField(resultOop);
			for (i = 0; i <= (length - 1); i += 1) {
				floatsResult[i] = ((wordsRcvr[i]) + (floatsArg[i]));
			}
		}
	} else {
		if (isArgWords) {
			floatsRcvr = interpreterProxy->firstIndexableField(rcvrOop);
			wordsArg = interpreterProxy->firstIndexableField(argOop);
			floatsResult = interpreterProxy->firstIndexableField(resultOop);
			for (i = 0; i <= (length - 1); i += 1) {
				floatsResult[i] = ((floatsRcvr[i]) + (wordsArg[i]));
			}
		} else {
			floatsRcvr = interpreterProxy->firstIndexableField(rcvrOop);
			floatsArg = interpreterProxy->firstIndexableField(argOop);
			floatsResult = interpreterProxy->firstIndexableField(resultOop);
			for (i = 0; i <= (length - 1); i += 1) {
				floatsResult[i] = ((floatsRcvr[i]) + (floatsArg[i]));
			}
		}
	}
	interpreterProxy->pop(4);
	interpreterProxy->push(resultOop);
}

EXPORT(sqInt) primitiveAddScalar(void) {
    sqInt argOop;
    double floatArg;
    float *floatsRcvr;
    float *floatsResult;
    sqInt i;
    int intArg;
    sqInt isArgInt;
    sqInt isRcvrWords;
    sqInt length;
    sqInt rcvrOop;
    sqInt resultOop;
    unsigned int *wordsRcvr;
    unsigned int *wordsResult;

	resultOop = interpreterProxy->stackObjectValue(0);
	argOop = interpreterProxy->stackValue(1);
	rcvrOop = interpreterProxy->stackObjectValue(2);
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->success(interpreterProxy->isWords(rcvrOop));
	interpreterProxy->success(interpreterProxy->isWords(resultOop));
	if (interpreterProxy->failed()) {
		return null;
	}
	length = interpreterProxy->stSizeOf(rcvrOop);
	interpreterProxy->success(length == (interpreterProxy->stSizeOf(resultOop)));
	if (interpreterProxy->failed()) {
		return null;
	}
	isArgInt = (argOop & 1);
	isRcvrWords = interpreterProxy->isMemberOf(rcvrOop, "WordArray");
	if (isArgInt && isRcvrWords) {
		if (!(interpreterProxy->isMemberOf(resultOop, "WordArray"))) {
			interpreterProxy->primitiveFail();
			return null;
		}
	} else {
		if (!(interpreterProxy->isMemberOf(resultOop, "KedamaFloatArray"))) {
			interpreterProxy->primitiveFail();
			return null;
		}
	}
	if (isRcvrWords) {
		if (isArgInt) {
			wordsRcvr = interpreterProxy->firstIndexableField(rcvrOop);
			intArg = (argOop >> 1);
			wordsResult = interpreterProxy->firstIndexableField(resultOop);
			for (i = 0; i <= (length - 1); i += 1) {
				wordsResult[i] = ((wordsRcvr[i]) + intArg);
			}
		} else {
			wordsRcvr = interpreterProxy->firstIndexableField(rcvrOop);
			floatArg = interpreterProxy->floatValueOf(argOop);
			floatsResult = interpreterProxy->firstIndexableField(resultOop);
			for (i = 0; i <= (length - 1); i += 1) {
				floatsResult[i] = ((wordsRcvr[i]) + floatArg);
			}
		}
	} else {
		if (isArgInt) {
			floatsRcvr = interpreterProxy->firstIndexableField(rcvrOop);
			intArg = (argOop >> 1);
			floatsResult = interpreterProxy->firstIndexableField(resultOop);
			for (i = 0; i <= (length - 1); i += 1) {
				floatsResult[i] = ((floatsRcvr[i]) + intArg);
			}
		} else {
			floatsRcvr = interpreterProxy->firstIndexableField(rcvrOop);
			floatArg = interpreterProxy->floatValueOf(argOop);
			floatsResult = interpreterProxy->firstIndexableField(resultOop);
			for (i = 0; i <= (length - 1); i += 1) {
				floatsResult[i] = ((floatsRcvr[i]) + floatArg);
			}
		}
	}
	interpreterProxy->pop(4);
	interpreterProxy->push(resultOop);
}

EXPORT(sqInt) primitiveDivArrays(void) {
    sqInt argOop;
    float *floatsArg;
    float *floatsRcvr;
    float *floatsResult;
    sqInt i;
    sqInt isArgWords;
    sqInt isRcvrWords;
    sqInt length;
    sqInt rcvrOop;
    sqInt resultOop;
    unsigned int *wordsArg;
    unsigned int *wordsRcvr;
    unsigned int *wordsResult;

	resultOop = interpreterProxy->stackObjectValue(0);
	argOop = interpreterProxy->stackObjectValue(1);
	rcvrOop = interpreterProxy->stackObjectValue(2);
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->success(interpreterProxy->isWords(argOop));
	interpreterProxy->success(interpreterProxy->isWords(rcvrOop));
	interpreterProxy->success(interpreterProxy->isWords(resultOop));
	if (interpreterProxy->failed()) {
		return null;
	}
	length = interpreterProxy->stSizeOf(argOop);
	interpreterProxy->success(length == (interpreterProxy->stSizeOf(rcvrOop)));
	interpreterProxy->success(length == (interpreterProxy->stSizeOf(resultOop)));
	if (interpreterProxy->failed()) {
		return null;
	}
	isArgWords = interpreterProxy->isMemberOf(argOop, "WordArray");
	isRcvrWords = interpreterProxy->isMemberOf(rcvrOop, "WordArray");
	if (isArgWords && isRcvrWords) {
		if (!(interpreterProxy->isMemberOf(resultOop, "WordArray"))) {
			interpreterProxy->primitiveFail();
			return null;
		}
	} else {
		if (!(interpreterProxy->isMemberOf(resultOop, "KedamaFloatArray"))) {
			interpreterProxy->primitiveFail();
			return null;
		}
	}
	if (isRcvrWords) {
		if (isArgWords) {
			wordsRcvr = interpreterProxy->firstIndexableField(rcvrOop);
			wordsArg = interpreterProxy->firstIndexableField(argOop);
			wordsResult = interpreterProxy->firstIndexableField(resultOop);
			for (i = 0; i <= (length - 1); i += 1) {
				wordsResult[i] = ((wordsRcvr[i]) / (wordsArg[i]));
			}
		} else {
			wordsRcvr = interpreterProxy->firstIndexableField(rcvrOop);
			floatsArg = interpreterProxy->firstIndexableField(argOop);
			floatsResult = interpreterProxy->firstIndexableField(resultOop);
			for (i = 0; i <= (length - 1); i += 1) {
				floatsResult[i] = ((wordsRcvr[i]) / (floatsArg[i]));
			}
		}
	} else {
		if (isArgWords) {
			floatsRcvr = interpreterProxy->firstIndexableField(rcvrOop);
			wordsArg = interpreterProxy->firstIndexableField(argOop);
			floatsResult = interpreterProxy->firstIndexableField(resultOop);
			for (i = 0; i <= (length - 1); i += 1) {
				floatsResult[i] = ((floatsRcvr[i]) / (wordsArg[i]));
			}
		} else {
			floatsRcvr = interpreterProxy->firstIndexableField(rcvrOop);
			floatsArg = interpreterProxy->firstIndexableField(argOop);
			floatsResult = interpreterProxy->firstIndexableField(resultOop);
			for (i = 0; i <= (length - 1); i += 1) {
				floatsResult[i] = ((floatsRcvr[i]) / (floatsArg[i]));
			}
		}
	}
	interpreterProxy->pop(4);
	interpreterProxy->push(resultOop);
}

EXPORT(sqInt) primitiveDivScalar(void) {
    sqInt argOop;
    double floatArg;
    float *floatsRcvr;
    float *floatsResult;
    sqInt i;
    int intArg;
    sqInt isArgInt;
    sqInt isRcvrWords;
    sqInt length;
    sqInt rcvrOop;
    sqInt resultOop;
    unsigned int *wordsRcvr;
    unsigned int *wordsResult;

	resultOop = interpreterProxy->stackObjectValue(0);
	argOop = interpreterProxy->stackValue(1);
	rcvrOop = interpreterProxy->stackObjectValue(2);
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->success(interpreterProxy->isWords(rcvrOop));
	interpreterProxy->success(interpreterProxy->isWords(resultOop));
	if (interpreterProxy->failed()) {
		return null;
	}
	length = interpreterProxy->stSizeOf(rcvrOop);
	interpreterProxy->success(length == (interpreterProxy->stSizeOf(resultOop)));
	if (interpreterProxy->failed()) {
		return null;
	}
	isArgInt = (argOop & 1);
	isRcvrWords = interpreterProxy->isMemberOf(rcvrOop, "WordArray");
	if (isArgInt && isRcvrWords) {
		if (!(interpreterProxy->isMemberOf(resultOop, "WordArray"))) {
			interpreterProxy->primitiveFail();
			return null;
		}
	} else {
		if (!(interpreterProxy->isMemberOf(resultOop, "KedamaFloatArray"))) {
			interpreterProxy->primitiveFail();
			return null;
		}
	}
	if (isRcvrWords) {
		if (isArgInt) {
			wordsRcvr = interpreterProxy->firstIndexableField(rcvrOop);
			intArg = (argOop >> 1);
			wordsResult = interpreterProxy->firstIndexableField(resultOop);
			for (i = 0; i <= (length - 1); i += 1) {
				wordsResult[i] = ((wordsRcvr[i]) / intArg);
			}
		} else {
			wordsRcvr = interpreterProxy->firstIndexableField(rcvrOop);
			floatArg = interpreterProxy->floatValueOf(argOop);
			floatsResult = interpreterProxy->firstIndexableField(resultOop);
			for (i = 0; i <= (length - 1); i += 1) {
				floatsResult[i] = ((wordsRcvr[i]) / floatArg);
			}
		}
	} else {
		if (isArgInt) {
			floatsRcvr = interpreterProxy->firstIndexableField(rcvrOop);
			intArg = (argOop >> 1);
			floatsResult = interpreterProxy->firstIndexableField(resultOop);
			for (i = 0; i <= (length - 1); i += 1) {
				floatsResult[i] = ((floatsRcvr[i]) / intArg);
			}
		} else {
			floatsRcvr = interpreterProxy->firstIndexableField(rcvrOop);
			floatArg = interpreterProxy->floatValueOf(argOop);
			floatsResult = interpreterProxy->firstIndexableField(resultOop);
			for (i = 0; i <= (length - 1); i += 1) {
				floatsResult[i] = ((floatsRcvr[i]) / floatArg);
			}
		}
	}
	interpreterProxy->pop(4);
	interpreterProxy->push(resultOop);
}

EXPORT(sqInt) primitiveMulArrays(void) {
    sqInt argOop;
    float *floatsArg;
    float *floatsRcvr;
    float *floatsResult;
    sqInt i;
    sqInt isArgWords;
    sqInt isRcvrWords;
    sqInt length;
    sqInt rcvrOop;
    sqInt resultOop;
    unsigned int *wordsArg;
    unsigned int *wordsRcvr;
    unsigned int *wordsResult;

	resultOop = interpreterProxy->stackObjectValue(0);
	argOop = interpreterProxy->stackObjectValue(1);
	rcvrOop = interpreterProxy->stackObjectValue(2);
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->success(interpreterProxy->isWords(argOop));
	interpreterProxy->success(interpreterProxy->isWords(rcvrOop));
	interpreterProxy->success(interpreterProxy->isWords(resultOop));
	if (interpreterProxy->failed()) {
		return null;
	}
	length = interpreterProxy->stSizeOf(argOop);
	interpreterProxy->success(length == (interpreterProxy->stSizeOf(rcvrOop)));
	interpreterProxy->success(length == (interpreterProxy->stSizeOf(resultOop)));
	if (interpreterProxy->failed()) {
		return null;
	}
	isArgWords = interpreterProxy->isMemberOf(argOop, "WordArray");
	isRcvrWords = interpreterProxy->isMemberOf(rcvrOop, "WordArray");
	if (isArgWords && isRcvrWords) {
		if (!(interpreterProxy->isMemberOf(resultOop, "WordArray"))) {
			interpreterProxy->primitiveFail();
			return null;
		}
	} else {
		if (!(interpreterProxy->isMemberOf(resultOop, "KedamaFloatArray"))) {
			interpreterProxy->primitiveFail();
			return null;
		}
	}
	if (isRcvrWords) {
		if (isArgWords) {
			wordsRcvr = interpreterProxy->firstIndexableField(rcvrOop);
			wordsArg = interpreterProxy->firstIndexableField(argOop);
			wordsResult = interpreterProxy->firstIndexableField(resultOop);
			for (i = 0; i <= (length - 1); i += 1) {
				wordsResult[i] = ((wordsRcvr[i]) * (wordsArg[i]));
			}
		} else {
			wordsRcvr = interpreterProxy->firstIndexableField(rcvrOop);
			floatsArg = interpreterProxy->firstIndexableField(argOop);
			floatsResult = interpreterProxy->firstIndexableField(resultOop);
			for (i = 0; i <= (length - 1); i += 1) {
				floatsResult[i] = ((wordsRcvr[i]) * (floatsArg[i]));
			}
		}
	} else {
		if (isArgWords) {
			floatsRcvr = interpreterProxy->firstIndexableField(rcvrOop);
			wordsArg = interpreterProxy->firstIndexableField(argOop);
			floatsResult = interpreterProxy->firstIndexableField(resultOop);
			for (i = 0; i <= (length - 1); i += 1) {
				floatsResult[i] = ((floatsRcvr[i]) * (wordsArg[i]));
			}
		} else {
			floatsRcvr = interpreterProxy->firstIndexableField(rcvrOop);
			floatsArg = interpreterProxy->firstIndexableField(argOop);
			floatsResult = interpreterProxy->firstIndexableField(resultOop);
			for (i = 0; i <= (length - 1); i += 1) {
				floatsResult[i] = ((floatsRcvr[i]) * (floatsArg[i]));
			}
		}
	}
	interpreterProxy->pop(4);
	interpreterProxy->push(resultOop);
}

EXPORT(sqInt) primitiveMulScalar(void) {
    sqInt argOop;
    double floatArg;
    float *floatsRcvr;
    float *floatsResult;
    sqInt i;
    int intArg;
    sqInt isArgInt;
    sqInt isRcvrWords;
    sqInt length;
    sqInt rcvrOop;
    sqInt resultOop;
    unsigned int *wordsRcvr;
    unsigned int *wordsResult;

	resultOop = interpreterProxy->stackObjectValue(0);
	argOop = interpreterProxy->stackValue(1);
	rcvrOop = interpreterProxy->stackObjectValue(2);
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->success(interpreterProxy->isWords(rcvrOop));
	interpreterProxy->success(interpreterProxy->isWords(resultOop));
	if (interpreterProxy->failed()) {
		return null;
	}
	length = interpreterProxy->stSizeOf(rcvrOop);
	interpreterProxy->success(length == (interpreterProxy->stSizeOf(resultOop)));
	if (interpreterProxy->failed()) {
		return null;
	}
	isArgInt = (argOop & 1);
	isRcvrWords = interpreterProxy->isMemberOf(rcvrOop, "WordArray");
	if (isArgInt && isRcvrWords) {
		if (!(interpreterProxy->isMemberOf(resultOop, "WordArray"))) {
			interpreterProxy->primitiveFail();
			return null;
		}
	} else {
		if (!(interpreterProxy->isMemberOf(resultOop, "KedamaFloatArray"))) {
			interpreterProxy->primitiveFail();
			return null;
		}
	}
	if (isRcvrWords) {
		if (isArgInt) {
			wordsRcvr = interpreterProxy->firstIndexableField(rcvrOop);
			intArg = (argOop >> 1);
			wordsResult = interpreterProxy->firstIndexableField(resultOop);
			for (i = 0; i <= (length - 1); i += 1) {
				wordsResult[i] = ((wordsRcvr[i]) * intArg);
			}
		} else {
			wordsRcvr = interpreterProxy->firstIndexableField(rcvrOop);
			floatArg = interpreterProxy->floatValueOf(argOop);
			floatsResult = interpreterProxy->firstIndexableField(resultOop);
			for (i = 0; i <= (length - 1); i += 1) {
				floatsResult[i] = ((wordsRcvr[i]) * floatArg);
			}
		}
	} else {
		if (isArgInt) {
			floatsRcvr = interpreterProxy->firstIndexableField(rcvrOop);
			intArg = (argOop >> 1);
			floatsResult = interpreterProxy->firstIndexableField(resultOop);
			for (i = 0; i <= (length - 1); i += 1) {
				floatsResult[i] = ((floatsRcvr[i]) * intArg);
			}
		} else {
			floatsRcvr = interpreterProxy->firstIndexableField(rcvrOop);
			floatArg = interpreterProxy->floatValueOf(argOop);
			floatsResult = interpreterProxy->firstIndexableField(resultOop);
			for (i = 0; i <= (length - 1); i += 1) {
				floatsResult[i] = ((floatsRcvr[i]) * floatArg);
			}
		}
	}
	interpreterProxy->pop(4);
	interpreterProxy->push(resultOop);
}

EXPORT(sqInt) primitiveSubArrays(void) {
    sqInt argOop;
    float *floatsArg;
    float *floatsRcvr;
    float *floatsResult;
    sqInt i;
    sqInt isArgWords;
    sqInt isRcvrWords;
    sqInt length;
    sqInt rcvrOop;
    sqInt resultOop;
    unsigned int *wordsArg;
    unsigned int *wordsRcvr;
    unsigned int *wordsResult;

	resultOop = interpreterProxy->stackObjectValue(0);
	argOop = interpreterProxy->stackObjectValue(1);
	rcvrOop = interpreterProxy->stackObjectValue(2);
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->success(interpreterProxy->isWords(argOop));
	interpreterProxy->success(interpreterProxy->isWords(rcvrOop));
	interpreterProxy->success(interpreterProxy->isWords(resultOop));
	if (interpreterProxy->failed()) {
		return null;
	}
	length = interpreterProxy->stSizeOf(argOop);
	interpreterProxy->success(length == (interpreterProxy->stSizeOf(rcvrOop)));
	interpreterProxy->success(length == (interpreterProxy->stSizeOf(resultOop)));
	if (interpreterProxy->failed()) {
		return null;
	}
	isArgWords = interpreterProxy->isMemberOf(argOop, "WordArray");
	isRcvrWords = interpreterProxy->isMemberOf(rcvrOop, "WordArray");
	if (isArgWords && isRcvrWords) {
		if (!(interpreterProxy->isMemberOf(resultOop, "WordArray"))) {
			interpreterProxy->primitiveFail();
			return null;
		}
	} else {
		if (!(interpreterProxy->isMemberOf(resultOop, "KedamaFloatArray"))) {
			interpreterProxy->primitiveFail();
			return null;
		}
	}
	if (isRcvrWords) {
		if (isArgWords) {
			wordsRcvr = interpreterProxy->firstIndexableField(rcvrOop);
			wordsArg = interpreterProxy->firstIndexableField(argOop);
			wordsResult = interpreterProxy->firstIndexableField(resultOop);
			for (i = 0; i <= (length - 1); i += 1) {
				wordsResult[i] = ((wordsRcvr[i]) - (wordsArg[i]));
			}
		} else {
			wordsRcvr = interpreterProxy->firstIndexableField(rcvrOop);
			floatsArg = interpreterProxy->firstIndexableField(argOop);
			floatsResult = interpreterProxy->firstIndexableField(resultOop);
			for (i = 0; i <= (length - 1); i += 1) {
				floatsResult[i] = ((wordsRcvr[i]) - (floatsArg[i]));
			}
		}
	} else {
		if (isArgWords) {
			floatsRcvr = interpreterProxy->firstIndexableField(rcvrOop);
			wordsArg = interpreterProxy->firstIndexableField(argOop);
			floatsResult = interpreterProxy->firstIndexableField(resultOop);
			for (i = 0; i <= (length - 1); i += 1) {
				floatsResult[i] = ((floatsRcvr[i]) - (wordsArg[i]));
			}
		} else {
			floatsRcvr = interpreterProxy->firstIndexableField(rcvrOop);
			floatsArg = interpreterProxy->firstIndexableField(argOop);
			floatsResult = interpreterProxy->firstIndexableField(resultOop);
			for (i = 0; i <= (length - 1); i += 1) {
				floatsResult[i] = ((floatsRcvr[i]) - (floatsArg[i]));
			}
		}
	}
	interpreterProxy->pop(4);
	interpreterProxy->push(resultOop);
}

EXPORT(sqInt) primitiveSubScalar(void) {
    sqInt argOop;
    double floatArg;
    float *floatsRcvr;
    float *floatsResult;
    sqInt i;
    int intArg;
    sqInt isArgInt;
    sqInt isRcvrWords;
    sqInt length;
    sqInt rcvrOop;
    sqInt resultOop;
    unsigned int *wordsRcvr;
    unsigned int *wordsResult;

	resultOop = interpreterProxy->stackObjectValue(0);
	argOop = interpreterProxy->stackValue(1);
	rcvrOop = interpreterProxy->stackObjectValue(2);
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->success(interpreterProxy->isWords(rcvrOop));
	interpreterProxy->success(interpreterProxy->isWords(resultOop));
	if (interpreterProxy->failed()) {
		return null;
	}
	length = interpreterProxy->stSizeOf(rcvrOop);
	interpreterProxy->success(length == (interpreterProxy->stSizeOf(resultOop)));
	if (interpreterProxy->failed()) {
		return null;
	}
	isArgInt = (argOop & 1);
	isRcvrWords = interpreterProxy->isMemberOf(rcvrOop, "WordArray");
	if (isArgInt && isRcvrWords) {
		if (!(interpreterProxy->isMemberOf(resultOop, "WordArray"))) {
			interpreterProxy->primitiveFail();
			return null;
		}
	} else {
		if (!(interpreterProxy->isMemberOf(resultOop, "KedamaFloatArray"))) {
			interpreterProxy->primitiveFail();
			return null;
		}
	}
	if (isRcvrWords) {
		if (isArgInt) {
			wordsRcvr = interpreterProxy->firstIndexableField(rcvrOop);
			intArg = (argOop >> 1);
			wordsResult = interpreterProxy->firstIndexableField(resultOop);
			for (i = 0; i <= (length - 1); i += 1) {
				wordsResult[i] = ((wordsRcvr[i]) - intArg);
			}
		} else {
			wordsRcvr = interpreterProxy->firstIndexableField(rcvrOop);
			floatArg = interpreterProxy->floatValueOf(argOop);
			floatsResult = interpreterProxy->firstIndexableField(resultOop);
			for (i = 0; i <= (length - 1); i += 1) {
				floatsResult[i] = ((wordsRcvr[i]) - floatArg);
			}
		}
	} else {
		if (isArgInt) {
			floatsRcvr = interpreterProxy->firstIndexableField(rcvrOop);
			intArg = (argOop >> 1);
			floatsResult = interpreterProxy->firstIndexableField(resultOop);
			for (i = 0; i <= (length - 1); i += 1) {
				floatsResult[i] = ((floatsRcvr[i]) - intArg);
			}
		} else {
			floatsRcvr = interpreterProxy->firstIndexableField(rcvrOop);
			floatArg = interpreterProxy->floatValueOf(argOop);
			floatsResult = interpreterProxy->firstIndexableField(resultOop);
			for (i = 0; i <= (length - 1); i += 1) {
				floatsResult[i] = ((floatsRcvr[i]) - floatArg);
			}
		}
	}
	interpreterProxy->pop(4);
	interpreterProxy->push(resultOop);
}

static double radiansToDegrees(double radians) {
    double deg;
    double degrees;

	degrees = radians / 0.0174532925199433;
	deg = 90.0 - degrees;
	if (!(deg > 0.0)) {
		deg += 360.0;
	}
	return deg;
}

EXPORT(sqInt) randomIntoFloatArray(void) {
    double factor;
    float *floatArray;
    sqInt floatArrayOop;
    sqInt from;
    sqInt index;
    sqInt range;
    sqInt size;
    sqInt to;

	factor = interpreterProxy->stackFloatValue(0);
	floatArrayOop = interpreterProxy->stackValue(1);
	to = interpreterProxy->stackIntegerValue(2);
	from = interpreterProxy->stackIntegerValue(3);
	range = interpreterProxy->stackIntegerValue(4);
	if (interpreterProxy->failed()) {
		return null;
	}
	if (!(interpreterProxy->isWords(floatArrayOop))) {
		interpreterProxy->primitiveFail();
		return null;
	}
	size = interpreterProxy->stSizeOf(floatArrayOop);
	if (!((size >= to) && ((from >= 1) && (to >= from)))) {
		interpreterProxy->primitiveFail();
		return null;
	}
	floatArray = interpreterProxy->firstIndexableField(floatArrayOop);
	if (interpreterProxy->failed()) {
		return null;
	}
	for (index = from; index <= to; index += 1) {
		floatArray[index - 1] = ((((double) (kedamaRandom2(range)))) * factor);
	}
	interpreterProxy->pop(5);
}

EXPORT(sqInt) randomIntoIntegerArray(void) {
    double factor;
    sqInt from;
    sqInt index;
    unsigned int *integerArray;
    sqInt integerArrayOop;
    sqInt range;
    sqInt size;
    sqInt to;

	factor = interpreterProxy->stackFloatValue(0);
	integerArrayOop = interpreterProxy->stackValue(1);
	to = interpreterProxy->stackIntegerValue(2);
	from = interpreterProxy->stackIntegerValue(3);
	range = interpreterProxy->stackIntegerValue(4);
	if (interpreterProxy->failed()) {
		return null;
	}
	if (!(interpreterProxy->isWords(integerArrayOop))) {
		interpreterProxy->primitiveFail();
		return null;
	}
	size = interpreterProxy->stSizeOf(integerArrayOop);
	if (!((size >= to) && ((from >= 1) && (to >= from)))) {
		interpreterProxy->primitiveFail();
		return null;
	}
	integerArray = interpreterProxy->firstIndexableField(integerArrayOop);
	if (interpreterProxy->failed()) {
		return null;
	}
	for (index = from; index <= to; index += 1) {
		integerArray[index - 1] = (((int) ((((double) (kedamaRandom2(range)))) * factor)));
	}
	interpreterProxy->pop(5);
}

EXPORT(sqInt) randomRange(void) {
    sqInt range;
    sqInt ret;
    sqInt hi;
    sqInt lo;
    sqInt r;
    sqInt v;
    sqInt val;

	range = interpreterProxy->stackIntegerValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	/* begin kedamaRandom2: */
	if (range < 0) {
		r = 0 - range;
	} else {
		r = range;
	}
	hi = kedamaRandomSeed / randQ;
	lo = kedamaRandomSeed % randQ;
	kedamaRandomSeed = (randA * lo) - (randR * hi);
	v = kedamaRandomSeed & 65535;
	val = ((usqInt) (v * (r + 1))) >> 16;
	if (range < 0) {
		ret = 0 - val;
		goto l1;
	} else {
		ret = val;
		goto l1;
	}
l1:	/* end kedamaRandom2: */;
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->pop(2);
	interpreterProxy->pushInteger(ret);
}

EXPORT(sqInt) scalarGetAngleTo(void) {
    double fromX;
    double fromY;
    double r;
    double toX;
    double toY;
    double x;
    double y;
    double tanVal;
    double theta;

	fromY = interpreterProxy->stackFloatValue(0);
	fromX = interpreterProxy->stackFloatValue(1);
	toY = interpreterProxy->stackFloatValue(2);
	toX = interpreterProxy->stackFloatValue(3);
	if (interpreterProxy->failed()) {
		return null;
	}
	x = toX - fromX;
	y = toY - fromY;
	/* begin degreesFromX:y: */
	if (x == 0.0) {
		if (y >= 0.0) {
			r = 90.0;
			goto l1;
		} else {
			r = 270.0;
			goto l1;
		}
	} else {
		tanVal = y / x;
		theta = atan(tanVal);
		if (x >= 0.0) {
			if (y >= 0.0) {
				r = theta / 0.0174532925199433;
				goto l1;
			} else {
				r = 360.0 + (theta / 0.0174532925199433);
				goto l1;
			}
		} else {
			r = 180.0 + (theta / 0.0174532925199433);
			goto l1;
		}
	}
	r = 0.0;
l1:	/* end degreesFromX:y: */;
	r += 90.0;
	if (r > 360.0) {
		r -= 360.0;
	}
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->pop(5);
	interpreterProxy->pushFloat(r);
}

EXPORT(sqInt) scalarGetDistanceTo(void) {
    double fromX;
    double fromY;
    double r;
    double toX;
    double toY;
    double x;
    double y;

	fromY = interpreterProxy->stackFloatValue(0);
	fromX = interpreterProxy->stackFloatValue(1);
	toY = interpreterProxy->stackFloatValue(2);
	toX = interpreterProxy->stackFloatValue(3);
	if (interpreterProxy->failed()) {
		return null;
	}
	x = fromX - toX;
	y = fromY - toY;
	r = sqrt((x * x) + (y * y));
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->pop(5);
	interpreterProxy->pushFloat(r);
}

static sqInt scalarXAtxArrayheadingArrayvaluedestWidthleftEdgeModerightEdgeMode(sqInt index, float* xArray, float* headingArray, double val, double destWidth, sqInt leftEdgeMode, sqInt rightEdgeMode) {
    double headingRadians;
    double newX;

	newX = val;
	if (newX < 0.0) {
		if (leftEdgeMode == 1) {
			newX += destWidth;
		}
		if (leftEdgeMode == 2) {
			newX = 0.0;
		}
		if (leftEdgeMode == 3) {

			/* bounce */

			newX = 0.0 - newX;
			headingRadians = headingArray[index];
			if (headingRadians < 3.141592653589793) {
				headingArray[index] = (3.141592653589793 - headingRadians);
			} else {
				headingArray[index] = (9.42477796076938 - headingRadians);
			}
		}
	}
	if (newX >= destWidth) {
		if (rightEdgeMode == 1) {
			newX -= destWidth;
		}
		if (rightEdgeMode == 2) {
			newX = destWidth - 1.0e-6;
		}
		if (rightEdgeMode == 3) {
			newX = (destWidth - 1.0e-6) - (newX - destWidth);
			headingRadians = headingArray[index];
			if (headingRadians < 3.141592653589793) {
				headingArray[index] = (3.141592653589793 - headingRadians);
			} else {
				headingArray[index] = (9.42477796076938 - headingRadians);
			}
		}
	}
	xArray[index] = newX;
}

static sqInt scalarYAtyArrayheadingArrayvaluedestHeighttopEdgeModebottomEdgeMode(sqInt index, float* yArray, float* headingArray, double val, double destHeight, sqInt topEdgeMode, sqInt bottomEdgeMode) {
    double newY;

	newY = val;
	if (newY < 0.0) {
		if (topEdgeMode == 1) {
			newY += destHeight;
		}
		if (topEdgeMode == 2) {
			newY = 0.0;
		}
		if (topEdgeMode == 3) {

			/* bounce */

			newY = 0.0 - newY;
			headingArray[index] = (6.283185307179586 - (headingArray[index]));
		}
	}
	if (newY >= destHeight) {
		if (bottomEdgeMode == 1) {
			newY -= destHeight;
		}
		if (bottomEdgeMode == 2) {
			newY = destHeight - 1.0e-6;
		}
		if (bottomEdgeMode == 3) {
			newY = (destHeight - 1.0e-6) - (newY - destHeight);
			headingArray[index] = (6.283185307179586 - (headingArray[index]));
		}
	}
	yArray[index] = newY;
}

EXPORT(sqInt) setHeadingArrayFrom(void) {
    double heading;
    float *headingArray;
    sqInt headingOop;
    sqInt i;
    sqInt isValVector;
    float *resultArray;
    sqInt resultOop;
    sqInt size;
    double deg;
    double headingRadians;
    int q;
    double deg1;
    double headingRadians1;
    int q1;

	resultOop = interpreterProxy->stackValue(0);
	headingOop = interpreterProxy->stackValue(1);
	if (interpreterProxy->failed()) {
		return null;
	}
	if (!(interpreterProxy->isWords(headingOop))) {
		interpreterProxy->primitiveFail();
		return null;
	}
	size = interpreterProxy->slotSizeOf(headingOop);
	if (interpreterProxy->isFloatObject(resultOop)) {
		isValVector = 0;
	} else {
		if (interpreterProxy->isWords(resultOop)) {
			if ((interpreterProxy->slotSizeOf(resultOop)) != size) {
				interpreterProxy->primitiveFail();
				return null;
			}
			isValVector = 1;
		} else {
			interpreterProxy->primitiveFail();
			return null;
		}
	}
	headingArray = interpreterProxy->firstIndexableField(headingOop);
	if (isValVector) {
		resultArray = interpreterProxy->firstIndexableField(resultOop);
	} else {
		heading = interpreterProxy->floatValueOf(resultOop);
		/* begin degreesToRadians: */
		deg = 90.0 - heading;
		q = deg / 360.0;
		if (deg < 0.0) {
			q -= 1;
		}
		headingRadians = (deg - (q * 360.0)) * 0.0174532925199433;
		heading = headingRadians;
	}
	for (i = 0; i <= (size - 1); i += 1) {
		if (isValVector) {
			heading = resultArray[i];
			/* begin degreesToRadians: */
			deg1 = 90.0 - heading;
			q1 = deg1 / 360.0;
			if (deg1 < 0.0) {
				q1 -= 1;
			}
			headingRadians1 = (deg1 - (q1 * 360.0)) * 0.0174532925199433;
			heading = headingRadians1;
		}
		headingArray[i] = heading;
	}
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->pop(2);
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

EXPORT(sqInt) setScalarHeading(void) {
    double heading;
    float *headingArray;
    sqInt headingOop;
    sqInt index;

	heading = interpreterProxy->stackFloatValue(0);
	headingOop = interpreterProxy->stackValue(1);
	index = interpreterProxy->stackIntegerValue(2);
	if (interpreterProxy->failed()) {
		return null;
	}
	if (!(interpreterProxy->isWords(headingOop))) {
		interpreterProxy->primitiveFail();
		return null;
	}
	if ((interpreterProxy->slotSizeOf(headingOop)) < index) {
		interpreterProxy->primitiveFail();
		return null;
	}
	headingArray = interpreterProxy->firstIndexableField(headingOop);
	headingArray[index - 1] = (degreesToRadians(heading));
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->pop(3);
}

EXPORT(sqInt) shutdownModule(void) {
	return 1;
}

EXPORT(sqInt) turtleScalarSetX(void) {
    double destWidth;
    float *headingArray;
    sqInt headingOop;
    sqInt leftEdgeMode;
    sqInt rightEdgeMode;
    sqInt size;
    double val;
    float *xArray;
    sqInt xIndex;
    sqInt xOop;
    double headingRadians;
    double newX;

	rightEdgeMode = interpreterProxy->stackIntegerValue(0);
	leftEdgeMode = interpreterProxy->stackIntegerValue(1);
	destWidth = interpreterProxy->stackFloatValue(2);
	val = interpreterProxy->stackFloatValue(3);
	headingOop = interpreterProxy->stackValue(4);
	xIndex = interpreterProxy->stackIntegerValue(5);
	xOop = interpreterProxy->stackValue(6);
	if (interpreterProxy->failed()) {
		return null;
	}
	if (!(interpreterProxy->isWords(xOop))) {
		interpreterProxy->primitiveFail();
		return null;
	}
	if (!(interpreterProxy->isWords(headingOop))) {
		interpreterProxy->primitiveFail();
		return null;
	}
	size = interpreterProxy->slotSizeOf(xOop);
	if ((interpreterProxy->slotSizeOf(headingOop)) != size) {
		interpreterProxy->primitiveFail();
		return null;
	}
	xArray = interpreterProxy->firstIndexableField(xOop);
	headingArray = interpreterProxy->firstIndexableField(headingOop);
	/* begin scalarXAt:xArray:headingArray:value:destWidth:leftEdgeMode:rightEdgeMode: */
	newX = val;
	if (newX < 0.0) {
		if (leftEdgeMode == 1) {
			newX += destWidth;
		}
		if (leftEdgeMode == 2) {
			newX = 0.0;
		}
		if (leftEdgeMode == 3) {
			newX = 0.0 - newX;
			headingRadians = headingArray[xIndex - 1];
			if (headingRadians < 3.141592653589793) {
				headingArray[xIndex - 1] = (3.141592653589793 - headingRadians);
			} else {
				headingArray[xIndex - 1] = (9.42477796076938 - headingRadians);
			}
		}
	}
	if (newX >= destWidth) {
		if (rightEdgeMode == 1) {
			newX -= destWidth;
		}
		if (rightEdgeMode == 2) {
			newX = destWidth - 1.0e-6;
		}
		if (rightEdgeMode == 3) {
			newX = (destWidth - 1.0e-6) - (newX - destWidth);
			headingRadians = headingArray[xIndex - 1];
			if (headingRadians < 3.141592653589793) {
				headingArray[xIndex - 1] = (3.141592653589793 - headingRadians);
			} else {
				headingArray[xIndex - 1] = (9.42477796076938 - headingRadians);
			}
		}
	}
	xArray[xIndex - 1] = newX;
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->pop(7);
}

EXPORT(sqInt) turtleScalarSetY(void) {
    sqInt bottomEdgeMode;
    double destHeight;
    float *headingArray;
    sqInt headingOop;
    sqInt size;
    sqInt topEdgeMode;
    double val;
    float *yArray;
    sqInt yIndex;
    sqInt yOop;
    double newY;

	bottomEdgeMode = interpreterProxy->stackIntegerValue(0);
	topEdgeMode = interpreterProxy->stackIntegerValue(1);
	destHeight = interpreterProxy->stackFloatValue(2);
	val = interpreterProxy->stackFloatValue(3);
	headingOop = interpreterProxy->stackValue(4);
	yIndex = interpreterProxy->stackIntegerValue(5);
	yOop = interpreterProxy->stackValue(6);
	if (interpreterProxy->failed()) {
		return null;
	}
	if (!(interpreterProxy->isWords(yOop))) {
		interpreterProxy->primitiveFail();
		return null;
	}
	if (!(interpreterProxy->isWords(headingOop))) {
		interpreterProxy->primitiveFail();
		return null;
	}
	size = interpreterProxy->slotSizeOf(yOop);
	if ((interpreterProxy->slotSizeOf(headingOop)) != size) {
		interpreterProxy->primitiveFail();
		return null;
	}
	yArray = interpreterProxy->firstIndexableField(yOop);
	headingArray = interpreterProxy->firstIndexableField(headingOop);
	/* begin scalarYAt:yArray:headingArray:value:destHeight:topEdgeMode:bottomEdgeMode: */
	newY = val;
	if (newY < 0.0) {
		if (topEdgeMode == 1) {
			newY += destHeight;
		}
		if (topEdgeMode == 2) {
			newY = 0.0;
		}
		if (topEdgeMode == 3) {
			newY = 0.0 - newY;
			headingArray[yIndex - 1] = (6.283185307179586 - (headingArray[yIndex - 1]));
		}
	}
	if (newY >= destHeight) {
		if (bottomEdgeMode == 1) {
			newY -= destHeight;
		}
		if (bottomEdgeMode == 2) {
			newY = destHeight - 1.0e-6;
		}
		if (bottomEdgeMode == 3) {
			newY = (destHeight - 1.0e-6) - (newY - destHeight);
			headingArray[yIndex - 1] = (6.283185307179586 - (headingArray[yIndex - 1]));
		}
	}
	yArray[yIndex - 1] = newY;
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->pop(7);
}

EXPORT(sqInt) turtlesSetX(void) {
    double destWidth;
    float *headingArray;
    sqInt headingOop;
    sqInt i;
    sqInt isValVector;
    sqInt leftEdgeMode;
    double newX;
    sqInt rightEdgeMode;
    sqInt size;
    double val;
    float *valArray;
    sqInt valOop;
    float *xArray;
    sqInt xOop;
    double headingRadians;
    double newX1;

	rightEdgeMode = interpreterProxy->stackIntegerValue(0);
	leftEdgeMode = interpreterProxy->stackIntegerValue(1);
	destWidth = interpreterProxy->stackFloatValue(2);
	valOop = interpreterProxy->stackValue(3);
	headingOop = interpreterProxy->stackValue(4);
	xOop = interpreterProxy->stackValue(5);
	if (interpreterProxy->failed()) {
		return null;
	}
	if (!(interpreterProxy->isWords(xOop))) {
		interpreterProxy->primitiveFail();
		return null;
	}
	if (!(interpreterProxy->isWords(headingOop))) {
		interpreterProxy->primitiveFail();
		return null;
	}
	if (interpreterProxy->isFloatObject(valOop)) {
		isValVector = 0;
	} else {
		if (interpreterProxy->isWords(valOop)) {
			isValVector = 1;
		} else {
			interpreterProxy->primitiveFail();
			return null;
		}
	}
	size = interpreterProxy->slotSizeOf(xOop);
	if ((interpreterProxy->slotSizeOf(headingOop)) != size) {
		interpreterProxy->primitiveFail();
		return null;
	}
	if (isValVector) {
		if ((interpreterProxy->slotSizeOf(valOop)) != size) {
			interpreterProxy->primitiveFail();
			return null;
		}
	}
	xArray = interpreterProxy->firstIndexableField(xOop);
	headingArray = interpreterProxy->firstIndexableField(headingOop);
	if (isValVector) {
		valArray = interpreterProxy->firstIndexableField(valOop);
	} else {
		val = interpreterProxy->floatValueOf(valOop);
	}
	for (i = 0; i <= (size - 1); i += 1) {
		if (isValVector) {
			newX = valArray[i];
		} else {
			newX = val;
		}
		/* begin scalarXAt:xArray:headingArray:value:destWidth:leftEdgeMode:rightEdgeMode: */
		newX1 = newX;
		if (newX1 < 0.0) {
			if (leftEdgeMode == 1) {
				newX1 += destWidth;
			}
			if (leftEdgeMode == 2) {
				newX1 = 0.0;
			}
			if (leftEdgeMode == 3) {
				newX1 = 0.0 - newX1;
				headingRadians = headingArray[i];
				if (headingRadians < 3.141592653589793) {
					headingArray[i] = (3.141592653589793 - headingRadians);
				} else {
					headingArray[i] = (9.42477796076938 - headingRadians);
				}
			}
		}
		if (newX1 >= destWidth) {
			if (rightEdgeMode == 1) {
				newX1 -= destWidth;
			}
			if (rightEdgeMode == 2) {
				newX1 = destWidth - 1.0e-6;
			}
			if (rightEdgeMode == 3) {
				newX1 = (destWidth - 1.0e-6) - (newX1 - destWidth);
				headingRadians = headingArray[i];
				if (headingRadians < 3.141592653589793) {
					headingArray[i] = (3.141592653589793 - headingRadians);
				} else {
					headingArray[i] = (9.42477796076938 - headingRadians);
				}
			}
		}
		xArray[i] = newX1;
	}
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->pop(6);
}

EXPORT(sqInt) turtlesSetY(void) {
    sqInt bottomEdgeMode;
    double destHeight;
    float *headingArray;
    sqInt headingOop;
    sqInt i;
    sqInt isValVector;
    double newY;
    sqInt size;
    sqInt topEdgeMode;
    double val;
    float *valArray;
    sqInt valOop;
    float *yArray;
    sqInt yOop;
    double newY1;

	bottomEdgeMode = interpreterProxy->stackIntegerValue(0);
	topEdgeMode = interpreterProxy->stackIntegerValue(1);
	destHeight = interpreterProxy->stackFloatValue(2);
	valOop = interpreterProxy->stackValue(3);
	headingOop = interpreterProxy->stackValue(4);
	yOop = interpreterProxy->stackValue(5);
	if (interpreterProxy->failed()) {
		return null;
	}
	if (!(interpreterProxy->isWords(yOop))) {
		interpreterProxy->primitiveFail();
		return null;
	}
	if (!(interpreterProxy->isWords(headingOop))) {
		interpreterProxy->primitiveFail();
		return null;
	}
	if (interpreterProxy->isFloatObject(valOop)) {
		isValVector = 0;
	} else {
		if (interpreterProxy->isWords(valOop)) {
			isValVector = 1;
		} else {
			interpreterProxy->primitiveFail();
			return null;
		}
	}
	size = interpreterProxy->slotSizeOf(yOop);
	if ((interpreterProxy->slotSizeOf(headingOop)) != size) {
		interpreterProxy->primitiveFail();
		return null;
	}
	if (isValVector) {
		if ((interpreterProxy->slotSizeOf(valOop)) != size) {
			interpreterProxy->primitiveFail();
			return null;
		}
	}
	yArray = interpreterProxy->firstIndexableField(yOop);
	headingArray = interpreterProxy->firstIndexableField(headingOop);
	if (isValVector) {
		valArray = interpreterProxy->firstIndexableField(valOop);
	} else {
		val = interpreterProxy->floatValueOf(valOop);
	}
	for (i = 0; i <= (size - 1); i += 1) {
		if (isValVector) {
			newY = valArray[i];
		} else {
			newY = val;
		}
		/* begin scalarYAt:yArray:headingArray:value:destHeight:topEdgeMode:bottomEdgeMode: */
		newY1 = newY;
		if (newY1 < 0.0) {
			if (topEdgeMode == 1) {
				newY1 += destHeight;
			}
			if (topEdgeMode == 2) {
				newY1 = 0.0;
			}
			if (topEdgeMode == 3) {
				newY1 = 0.0 - newY1;
				headingArray[i] = (6.283185307179586 - (headingArray[i]));
			}
		}
		if (newY1 >= destHeight) {
			if (bottomEdgeMode == 1) {
				newY1 -= destHeight;
			}
			if (bottomEdgeMode == 2) {
				newY1 = destHeight - 1.0e-6;
			}
			if (bottomEdgeMode == 3) {
				newY1 = (destHeight - 1.0e-6) - (newY1 - destHeight);
				headingArray[i] = (6.283185307179586 - (headingArray[i]));
			}
		}
		yArray[i] = newY1;
	}
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->pop(6);
}

EXPORT(sqInt) vectorGetAngleTo(void) {
    sqInt index;
    sqInt isVector;
    float *pX;
    sqInt pXOop;
    float *pY;
    sqInt pYOop;
    double ppx;
    double ppy;
    double r;
    float *result;
    sqInt resultOop;
    sqInt size;
    double x;
    float *xArray;
    sqInt xArrayOop;
    double y;
    float *yArray;
    sqInt yArrayOop;
    double tanVal;
    double theta;

	resultOop = interpreterProxy->stackValue(0);
	yArrayOop = interpreterProxy->stackValue(1);
	xArrayOop = interpreterProxy->stackValue(2);
	pYOop = interpreterProxy->stackValue(3);
	pXOop = interpreterProxy->stackValue(4);
	if (interpreterProxy->failed()) {
		return null;
	}
	if (!(interpreterProxy->isWords(resultOop))) {
		interpreterProxy->primitiveFail();
		return null;
	}
	if (!(interpreterProxy->isWords(xArrayOop))) {
		interpreterProxy->primitiveFail();
		return null;
	}
	if (!(interpreterProxy->isWords(yArrayOop))) {
		interpreterProxy->primitiveFail();
		return null;
	}
	size = interpreterProxy->stSizeOf(resultOop);
	if (size < 0) {
		interpreterProxy->primitiveFail();
		return null;
	}
	if ((interpreterProxy->stSizeOf(xArrayOop)) != size) {
		interpreterProxy->primitiveFail();
		return null;
	}
	if ((interpreterProxy->stSizeOf(yArrayOop)) != size) {
		interpreterProxy->primitiveFail();
		return null;
	}
	if (interpreterProxy->isFloatObject(pXOop)) {
		if (interpreterProxy->isFloatObject(pYOop)) {
			isVector = 0;
		} else {
			interpreterProxy->primitiveFail();
			return null;
		}
	} else {
		if (interpreterProxy->isFloatObject(pYOop)) {
			interpreterProxy->primitiveFail();
			return null;
		} else {
			isVector = 1;
		}
	}
	if (isVector) {
		if ((interpreterProxy->stSizeOf(pXOop)) != size) {
			interpreterProxy->primitiveFail();
			return null;
		}
		if ((interpreterProxy->stSizeOf(pYOop)) != size) {
			interpreterProxy->primitiveFail();
			return null;
		}
	}
	result = interpreterProxy->firstIndexableField(resultOop);
	xArray = interpreterProxy->firstIndexableField(xArrayOop);
	yArray = interpreterProxy->firstIndexableField(yArrayOop);
	if (isVector) {
		pX = interpreterProxy->firstIndexableField(pXOop);
		pY = interpreterProxy->firstIndexableField(pYOop);
	}
	if (!(isVector)) {
		ppx = interpreterProxy->floatValueOf(pXOop);
		ppy = interpreterProxy->floatValueOf(pYOop);
	}
	for (index = 0; index <= (size - 1); index += 1) {
		if (isVector) {
			ppx = pX[index];
			ppy = pY[index];
		}
		x = ppx - (xArray[index]);
		y = ppy - (yArray[index]);
		/* begin degreesFromX:y: */
		if (x == 0.0) {
			if (y >= 0.0) {
				r = 90.0;
				goto l1;
			} else {
				r = 270.0;
				goto l1;
			}
		} else {
			tanVal = y / x;
			theta = atan(tanVal);
			if (x >= 0.0) {
				if (y >= 0.0) {
					r = theta / 0.0174532925199433;
					goto l1;
				} else {
					r = 360.0 + (theta / 0.0174532925199433);
					goto l1;
				}
			} else {
				r = 180.0 + (theta / 0.0174532925199433);
				goto l1;
			}
		}
		r = 0.0;
	l1:	/* end degreesFromX:y: */;
		r += 90.0;
		if (r > 360.0) {
			r -= 360.0;
		}
		result[index] = r;
	}
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->pop(6);
	interpreterProxy->push(resultOop);
}

EXPORT(sqInt) vectorGetDistanceTo(void) {
    sqInt index;
    sqInt isVector;
    float *pX;
    sqInt pXOop;
    float *pY;
    sqInt pYOop;
    double ppx;
    double ppy;
    float *result;
    sqInt resultOop;
    sqInt size;
    double x;
    float *xArray;
    sqInt xArrayOop;
    double y;
    float *yArray;
    sqInt yArrayOop;

	resultOop = interpreterProxy->stackValue(0);
	yArrayOop = interpreterProxy->stackValue(1);
	xArrayOop = interpreterProxy->stackValue(2);
	pYOop = interpreterProxy->stackValue(3);
	pXOop = interpreterProxy->stackValue(4);
	if (interpreterProxy->failed()) {
		return null;
	}
	if (!(interpreterProxy->isWords(resultOop))) {
		interpreterProxy->primitiveFail();
		return null;
	}
	if (!(interpreterProxy->isWords(xArrayOop))) {
		interpreterProxy->primitiveFail();
		return null;
	}
	if (!(interpreterProxy->isWords(yArrayOop))) {
		interpreterProxy->primitiveFail();
		return null;
	}
	size = interpreterProxy->stSizeOf(resultOop);
	if (size < 0) {
		interpreterProxy->primitiveFail();
		return null;
	}
	if ((interpreterProxy->stSizeOf(xArrayOop)) != size) {
		interpreterProxy->primitiveFail();
		return null;
	}
	if ((interpreterProxy->stSizeOf(yArrayOop)) != size) {
		interpreterProxy->primitiveFail();
		return null;
	}
	if (interpreterProxy->isFloatObject(pXOop)) {
		if (interpreterProxy->isFloatObject(pYOop)) {
			isVector = 0;
		} else {
			interpreterProxy->primitiveFail();
			return null;
		}
	} else {
		if (interpreterProxy->isFloatObject(pYOop)) {
			interpreterProxy->primitiveFail();
			return null;
		} else {
			isVector = 1;
		}
	}
	if (isVector) {
		if ((interpreterProxy->stSizeOf(pXOop)) != size) {
			interpreterProxy->primitiveFail();
			return null;
		}
		if ((interpreterProxy->stSizeOf(pYOop)) != size) {
			interpreterProxy->primitiveFail();
			return null;
		}
	}
	result = interpreterProxy->firstIndexableField(resultOop);
	xArray = interpreterProxy->firstIndexableField(xArrayOop);
	yArray = interpreterProxy->firstIndexableField(yArrayOop);
	if (isVector) {
		pX = interpreterProxy->firstIndexableField(pXOop);
		pY = interpreterProxy->firstIndexableField(pYOop);
	}
	if (!(isVector)) {
		ppx = interpreterProxy->floatValueOf(pXOop);
		ppy = interpreterProxy->floatValueOf(pYOop);
	}
	for (index = 0; index <= (size - 1); index += 1) {
		if (isVector) {
			ppx = pX[index];
			ppy = pY[index];
		}
		x = ppx - (xArray[index]);
		y = ppy - (yArray[index]);
		result[index] = (sqrt((x * x) + (y * y)));
	}
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->pop(6);
	interpreterProxy->push(resultOop);
}

EXPORT(sqInt) zoomBitmap(void) {
    sqInt bit;
    unsigned int* dOrigin;
    sqInt dst;
    sqInt dstIndex;
    sqInt dstSize;
    sqInt dummy;
    sqInt sHeight;
    unsigned int* sOrigin;
    sqInt sWidth;
    sqInt src;
    sqInt srcIndex;
    sqInt srcOrigin;
    sqInt srcSize;
    sqInt sx;
    sqInt sy;
    sqInt xFactor;
    sqInt y;
    sqInt yFactor;

	yFactor = interpreterProxy->stackIntegerValue(0);
	xFactor = interpreterProxy->stackIntegerValue(1);
	sHeight = interpreterProxy->stackIntegerValue(2);
	sWidth = interpreterProxy->stackIntegerValue(3);
	dst = interpreterProxy->stackValue(4);
	src = interpreterProxy->stackValue(5);
	if (interpreterProxy->failed()) {
		return null;
	}
	srcSize = interpreterProxy->slotSizeOf(src);
	dstSize = interpreterProxy->slotSizeOf(dst);
	if (!((sWidth * sHeight) == srcSize)) {
		interpreterProxy->primitiveFail();
		return null;
	}
	if (!(((srcSize * xFactor) * yFactor) == dstSize)) {
		interpreterProxy->primitiveFail();
		return null;
	}
	sOrigin = interpreterProxy->firstIndexableField(src);
	dOrigin = interpreterProxy->firstIndexableField(dst);
	srcIndex = 0;
	srcOrigin = 0;
	dstIndex = 0;
	for (sy = 0; sy <= (sHeight - 1); sy += 1) {
		for (y = 0; y <= (yFactor - 1); y += 1) {
			for (sx = 0; sx <= (sWidth - 1); sx += 1) {
				bit = sOrigin[srcIndex];
				srcIndex += 1;
				for (dummy = 0; dummy <= (xFactor - 1); dummy += 1) {
					dOrigin[dstIndex] = bit;
					dstIndex += 1;
				}
			}
			srcIndex = srcOrigin;
		}
		srcOrigin += sWidth;
		srcIndex = srcOrigin;
	}
	interpreterProxy->pop(6);
}


#ifdef SQUEAK_BUILTIN_PLUGIN


void* KedamaPlugin_exports[][3] = {
	{"KedamaPlugin", "makeMaskLog", (void*)makeMaskLog},
	{"KedamaPlugin", "vectorGetDistanceTo", (void*)vectorGetDistanceTo},
	{"KedamaPlugin", "getScalarHeading", (void*)getScalarHeading},
	{"KedamaPlugin", "shutdownModule", (void*)shutdownModule},
	{"KedamaPlugin", "primitiveAddScalar", (void*)primitiveAddScalar},
	{"KedamaPlugin", "primSetPixelsAtXY", (void*)primSetPixelsAtXY},
	{"KedamaPlugin", "turtleScalarSetX", (void*)turtleScalarSetX},
	{"KedamaPlugin", "primPixelAtXY", (void*)primPixelAtXY},
	{"KedamaPlugin", "primUpHill", (void*)primUpHill},
	{"KedamaPlugin", "primScalarForward", (void*)primScalarForward},
	{"KedamaPlugin", "primitiveDivArrays", (void*)primitiveDivArrays},
	{"KedamaPlugin", "getModuleName", (void*)getModuleName},
	{"KedamaPlugin", "primitiveSubArrays", (void*)primitiveSubArrays},
	{"KedamaPlugin", "scalarGetAngleTo", (void*)scalarGetAngleTo},
	{"KedamaPlugin", "randomRange", (void*)randomRange},
	{"KedamaPlugin", "setInterpreter", (void*)setInterpreter},
	{"KedamaPlugin", "kedamaSetRandomSeed", (void*)kedamaSetRandomSeed},
	{"KedamaPlugin", "drawTurtlesInArray", (void*)drawTurtlesInArray},
	{"KedamaPlugin", "turtleScalarSetY", (void*)turtleScalarSetY},
	{"KedamaPlugin", "randomIntoIntegerArray", (void*)randomIntoIntegerArray},
	{"KedamaPlugin", "getHeadingArrayInto", (void*)getHeadingArrayInto},
	{"KedamaPlugin", "makeTurtlesMap", (void*)makeTurtlesMap},
	{"KedamaPlugin", "setHeadingArrayFrom", (void*)setHeadingArrayFrom},
	{"KedamaPlugin", "turtlesSetX", (void*)turtlesSetX},
	{"KedamaPlugin", "setScalarHeading", (void*)setScalarHeading},
	{"KedamaPlugin", "makeMask", (void*)makeMask},
	{"KedamaPlugin", "primitiveDivScalar", (void*)primitiveDivScalar},
	{"KedamaPlugin", "primitiveSubScalar", (void*)primitiveSubScalar},
	{"KedamaPlugin", "primPixelsAtXY", (void*)primPixelsAtXY},
	{"KedamaPlugin", "vectorGetAngleTo", (void*)vectorGetAngleTo},
	{"KedamaPlugin", "primitiveMulArrays", (void*)primitiveMulArrays},
	{"KedamaPlugin", "primPixelAtXYPut", (void*)primPixelAtXYPut},
	{"KedamaPlugin", "zoomBitmap", (void*)zoomBitmap},
	{"KedamaPlugin", "initialiseModule", (void*)initialiseModule},
	{"KedamaPlugin", "primitiveAddArrays", (void*)primitiveAddArrays},
	{"KedamaPlugin", "scalarGetDistanceTo", (void*)scalarGetDistanceTo},
	{"KedamaPlugin", "turtlesSetY", (void*)turtlesSetY},
	{"KedamaPlugin", "randomIntoFloatArray", (void*)randomIntoFloatArray},
	{"KedamaPlugin", "primTurtlesForward", (void*)primTurtlesForward},
	{"KedamaPlugin", "primitiveMulScalar", (void*)primitiveMulScalar},
	{NULL, NULL, NULL}
};


#endif /* ifdef SQ_BUILTIN_PLUGIN */

