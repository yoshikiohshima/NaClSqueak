/* Automatically generated from Squeak on 30 April 2011 12:37:17 am 
   by VMMaker 4.4.7
 */
#define SQ_USE_GLOBAL_STRUCT 1

#include "sq.h"
#include <setjmp.h>

#ifndef allocateMemoryMinimumImageFileHeaderSize
 /* Called by Interpreter>>allocateMemory:minimum:imageFile:headerSize: */
 /* Default definition if not previously defined in config.h */
 #define allocateMemoryMinimumImageFileHeaderSize(heapSize, minimumMemory, fileStream, headerSize) \
    sqAllocateMemory(minimumMemory, heapSize)
#endif

#ifndef sqImageFileReadEntireImage
 /* Called by Interpreter>>sqImage:read:size:length: */
 /* Default definition if not previously defined in config.h */
 #define sqImageFileReadEntireImage(memoryAddress, elementSize,  length, fileStream) \
    sqImageFileRead(memoryAddress, elementSize,  length, fileStream)
#endif

#ifndef error
 /* error() function called from Interpreter */
 /* Default definition if not previously defined in config.h */
 #define error(str) defaultErrorProc(str)
#endif

#ifndef ioMicroSecondClock
 /* Called by Interpreter>>primitiveMicrosecondClock and GC methods */
 /* Default definition if not previously defined in config.h */
 #define ioMicroSecondClock ioMSecs
#endif

#ifndef ioUtcWithOffset
 /* Called by Interpreter>>primitiveUtcWithOffset */
 /* Default definition if not previously defined in config.h */
 #define ioUtcWithOffset(clock, offset) setMicroSecondsandOffset(clock, offset)
#endif

#include "sqMemoryAccess.h"

sqInt printCallStack(void);
void defaultErrorProc(char *s) {
	/* Print an error message and exit. */
	static sqInt printingStack = false;

	printf("\n%s\n\n", s);
	if (!printingStack) {
		/* flag prevents recursive error when trying to print a broken stack */
		printingStack = true;
		printCallStack();
	}
	exit(-1);
}

/*** Constants ***/
#define ActiveProcessIndex 1
#define AtCacheFixedFields 4
#define AtCacheFmt 3
#define AtCacheMask 28
#define AtCacheOop 1
#define AtCacheSize 2
#define AtCacheTotalSize 64
#define AtPutBase 32
#define BlockArgumentCountIndex 3
#define Byte0Mask 255
#define Byte1Mask 65280
#define Byte1Shift 8
#define Byte1ShiftNegated -8
#define Byte2Mask 16711680
#define Byte3Mask 4278190080U
#define Byte3Shift 24
#define Byte3ShiftNegated -24
#define Byte4Mask 1095216660480U
#define Byte4Shift 32
#define Byte4ShiftNegated -32
#define Byte5Mask 280375465082880U
#define Byte5Shift 40
#define Byte5ShiftNegated -40
#define Byte6Mask 71776119061217280U
#define Byte7Mask 18374686479671623680U
#define Byte7Shift 56
#define Byte7ShiftNegated -56
#define Bytes3to0Mask 4294967295U
#define Bytes7to4Mask 18446744069414584320U
#define CacheProbeMax 3
#define CallerIndex 0
#define CharacterTable 24
#define CharacterValueIndex 0
#define ClassAlien 52
#define ClassArray 7
#define ClassBitmap 4
#define ClassBlockClosure 36
#define ClassBlockContext 11
#define ClassByteArray 26
#define ClassCharacter 19
#define ClassExternalAddress 43
#define ClassExternalData 45
#define ClassExternalFunction 46
#define ClassExternalLibrary 47
#define ClassExternalStructure 44
#define ClassFloat 9
#define ClassInteger 5
#define ClassLargeNegativeInteger 42
#define ClassLargePositiveInteger 13
#define ClassMessage 15
#define ClassMethodContext 10
#define ClassPoint 12
#define ClassSemaphore 18
#define ClassString 6
#define ClassUnsafeAlien 54
#define ClassWeakFinalizer 55
#define ClosureFirstCopiedValueIndex 3
#define ClosureIndex 4
#define ClosureNumArgsIndex 2
#define ClosureOuterContextIndex 0
#define ClosureStartPCIndex 1
#define CompactClassMask 126976
#define CompactClasses 28
#define ConstMinusOne -1
#define ConstOne 3
#define ConstTwo 5
#define ConstZero 1
#define ContextFixedSizePlusHeader 7
#define CrossedX 258
#define CtxtTempFrameStart 6
#define DoAssertionChecks 0
#define DoBalanceChecks 0
#define Done 4
#define EndOfRun 257
#define ExcessSignalsIndex 2
#define ExternalObjectsArray 38
#define ExtraRootSize 2048
#define FalseObject 1
#define FirstLinkIndex 0
#define GCTopMarker 3
#define HashBits 536739840
#define HashBitsOffset 17
#define HeaderIndex 0
#define HeaderTypeClass 1
#define HeaderTypeFree 2
#define HeaderTypeGC 2
#define HeaderTypeShort 3
#define HeaderTypeSizeAndClass 0
#define HomeIndex 5
#define InitialIPIndex 4
#define InstanceSpecificationIndex 2
#define InstructionPointerIndex 1
#define InterpreterSourceVersion "4.4.7"
#define InvokeCallbackSelector 53
#define LargeContextBit 262144
#define LastLinkIndex 1
#define LiteralStart 1
#define MaxExternalPrimitiveTableSize 4096
#define MaxJumpBuf 32
#define MaxPrimitiveIndex 575
#define MessageArgumentsIndex 1
#define MessageDictionaryIndex 1
#define MessageLookupClassIndex 2
#define MessageSelectorIndex 0
#define MethodArrayIndex 1
#define MethodCacheClass 2
#define MethodCacheEntries 512
#define MethodCacheEntrySize 8
#define MethodCacheMask 4088
#define MethodCacheMethod 3
#define MethodCacheNative 5
#define MethodCachePrim 4
#define MethodCachePrimFunction 6
#define MethodCacheSelector 1
#define MethodCacheSize 4096
#define MethodIndex 3
#define MillisecondClockMask 536870911
#define MyListIndex 3
#define NextLinkIndex 0
#define NilContext 1
#define NilObject 0
#define PrimitiveExternalCallIndex 117
#define PriorityIndex 2
#define ProcessListsIndex 0
#define ProcessSignalingLowSpace 22
#define ReceiverIndex 5
#define RootTableRedZone 2400
#define RootTableSize 2500
#define SchedulerAssociation 3
#define SelectorAboutToReturn 48
#define SelectorCannotInterpret 34
#define SelectorCannotReturn 21
#define SelectorDoesNotUnderstand 20
#define SelectorMustBeBoolean 25
#define SelectorRunWithIn 49
#define SelectorStart 2
#define SemaphoresToSignalSize 500
#define SenderIndex 0
#define SpecialSelectors 23
#define StackPointerIndex 2
#define StartField 1
#define StartObj 2
#define SuperclassIndex 0
#define SuspendedContextIndex 1
#define TempFrameStart 6
#define TheDisplay 14
#define TheFinalizationSemaphore 41
#define TheInterruptSemaphore 30
#define TheLowSpaceSemaphore 17
#define TheTimerSemaphore 29
#define TrueObject 2
#define TypeMask 3
#define Upward 3
#define ValueIndex 1
#define XIndex 0
#define YIndex 1

/*** Function Prototypes ***/
sqInt accessibleObjectAfter(sqInt oop);
sqInt activateNewClosureMethod(sqInt blockClosure);
sqInt activateNewMethod(void);
#pragma export on
EXPORT(sqInt) addGCRoot(sqInt *varLoc);
#pragma export off
sqInt addNewMethodToCache(void);
sqInt addToExternalPrimitiveTable(void *functionAddress);
sqInt adjustAllOopsBy(sqInt bytesToShift);
sqInt allYoungand(sqInt array1, sqInt array2);
sqInt allocateChunk(sqInt byteSize);
sqInt allocateOrRecycleContext(sqInt needsLarge);
sqInt argumentCountOf(sqInt methodPointer);
void * arrayValueOf(sqInt arrayOop);
sqInt asciiOfCharacter(sqInt characterObj);
sqInt balancedStackafterPrimitivewithArgs(sqInt delta, sqInt primIdx, sqInt nArgs);
sqInt baseHeaderSize(void);
sqInt beRootIfOld(sqInt oop);
sqInt beRootWhileForwarding(sqInt oop);
sqInt becomewith(sqInt array1, sqInt array2);
sqInt becomewithtwoWaycopyHash(sqInt array1, sqInt array2, sqInt twoWayFlag, sqInt copyHashFlag);
sqInt biasToGrow(void);
sqInt booleanValueOf(sqInt obj);
sqInt byteSizeOf(sqInt oop);
sqInt byteSwapByteObjectsFromto(sqInt startOop, sqInt stopAddr);
sqInt byteSwapped(sqInt w);
sqInt bytesPerWord(void);
sqInt callExternalPrimitive(void *functionID);
#pragma export on
EXPORT(sqInt) callInterpreter(void);
EXPORT(sqInt) callbackEnter(sqInt *callbackID);
EXPORT(sqInt) callbackLeave(sqInt cbID);
#pragma export off
sqInt changeClassOfto(sqInt rcvr, sqInt argClass);
sqInt characterForAscii(sqInt ascii);
sqInt characterTable(void);
sqInt checkForInterrupts(void);
sqInt checkImageVersionFromstartingAt(sqImageFile  f, squeakFileOffsetType  imageOffset);
sqInt checkedIntegerValueOf(sqInt intOop);
sqInt checkedLongAt(sqInt byteAddress);
sqInt classAlien(void);
sqInt classArray(void);
sqInt classBitmap(void);
sqInt classByteArray(void);
sqInt classCharacter(void);
sqInt classExternalAddress(void);
sqInt classExternalData(void);
sqInt classExternalFunction(void);
sqInt classExternalLibrary(void);
sqInt classExternalStructure(void);
sqInt classFloat(void);
sqInt classLargeNegativeInteger(void);
sqInt classLargePositiveInteger(void);
sqInt classNameOfIs(sqInt aClass, char *className);
sqInt classPoint(void);
sqInt classSemaphore(void);
sqInt classSmallInteger(void);
sqInt classString(void);
sqInt classUnsafeAlien(void);
sqInt clone(sqInt oop);
sqInt commonAt(sqInt stringy);
sqInt commonAtPut(sqInt stringy);
sqInt commonVariableatcacheIndex(sqInt rcvr, sqInt index, sqInt atIx);
sqInt compare31or32Bitsequal(sqInt obj1, sqInt obj2);
sqInt compilerCreateActualMessagestoringArgs(sqInt aMessage, sqInt argArray);
sqInt compilerFlushCache(sqInt aCompiledMethod);
sqInt compilerMapFromto(sqInt memStart, sqInt memEnd);
sqInt compilerMark(void);
sqInt compilerPostGC(void);
sqInt compilerPostSnapshot(void);
sqInt compilerPreGC(sqInt fullGCFlag);
sqInt compilerPreSnapshot(void);
sqInt compilerProcessChange(void);
sqInt compilerProcessChangeto(sqInt oldProc, sqInt newProc);
sqInt compilerTranslateMethod(void);
sqInt containOnlyOopsand(sqInt array1, sqInt array2);
sqInt contexthasSender(sqInt thisCntx, sqInt aContext);
sqInt copyBits(void);
sqInt copyBitsFromtoat(sqInt x0, sqInt x1, sqInt y);
sqInt copyObjtoSegmentaddrstopAtsaveOopAtheaderAt(sqInt oop, sqInt segmentWordArray, sqInt lastSeg, sqInt stopAddr, sqInt oopPtr, sqInt hdrPtr);
sqInt createActualMessageTo(sqInt aClass);
sqInt dispatchFunctionPointer(void *aFunctionPointer);
sqInt dispatchFunctionPointerOnin(sqInt primIdx, void *primTable[]);
sqInt displayBitsOfLeftTopRightBottom(sqInt aForm, sqInt l, sqInt t, sqInt r, sqInt b);
sqInt displayObject(void);
sqInt doPrimitiveDivby(sqInt rcvr, sqInt arg);
sqInt doPrimitiveModby(sqInt rcvr, sqInt arg);
sqInt dummyReferToProxy(void);
#pragma export on
EXPORT(sqInt) dumpImage(char *fileName);
#pragma export off
sqInt executeNewMethodFromCache(void);
#pragma export on
EXPORT(sqInt) extraHeaderBytes(sqInt oopOrChunk);
#pragma export off
sqInt failed(void);
sqInt falseObject(void);
void * fetchArrayofObject(sqInt fieldIndex, sqInt objectPointer);
sqInt fetchClassOf(sqInt oop);
sqInt fetchClassOfNonInt(sqInt oop);
double fetchFloatofObject(sqInt fieldIndex, sqInt objectPointer);
sqInt fetchIntegerofObject(sqInt fieldIndex, sqInt objectPointer);
sqInt fetchLong32ofObject(sqInt fieldIndex, sqInt oop);
sqInt fetchPointerofObject(sqInt fieldIndex, sqInt oop);
sqInt fetchStackPointerOf(sqInt aContext);
sqInt fetchWordLengthOf(sqInt objectPointer);
sqInt finalizeReference(usqInt oop);
sqInt findClassOfMethodforReceiver(sqInt meth, sqInt rcvr);
sqInt findNewMethodInClass(sqInt class);
sqInt findSelectorOfMethodforReceiver(sqInt meth, sqInt rcvr);
sqInt firstAccessibleObject(void);
char * firstFixedField(sqInt oop);
char * firstIndexableField(sqInt oop);
sqInt floatObjectOf(double  aFloat);
double floatValueOf(sqInt oop);
sqInt flushExternalPrimitiveOf(sqInt methodPtr);
sqInt flushExternalPrimitives(void);
sqInt forceInterruptCheck(void);
sqInt fullDisplayUpdate(void);
sqInt fullGC(void);
sqInt fwdTableInit(sqInt blkSize);
sqInt fwdTableSize(sqInt blkSize);
sqInt getCurrentBytecode(void);
sqInt getFullScreenFlag(void);
sqInt getInterruptCheckCounter(void);
sqInt getInterruptKeycode(void);
sqInt getInterruptPending(void);
sqInt getLongFromFileswap(sqImageFile  aFile, sqInt swapFlag);
sqInt getNextWakeupTick(void);
sqInt getSavedWindowSize(void);
#pragma export on
EXPORT(sqInt) getStackPointer(void);
#pragma export off
sqInt getThisSessionID(void);
sqInt growObjectMemory(usqInt delta);
sqInt headerOf(sqInt methodPointer);
sqInt imageSegmentVersion(void);
sqInt incCompBody(void);
sqInt incCompMakeFwd(void);
sqInt incCompMove(sqInt bytesFreed);
sqInt includesBehaviorThatOf(sqInt aClass, sqInt aSuperclass);
sqInt incrementalGC(void);
sqInt initCompilerHooks(void);
sqInt initializeImageFormatVersionIfNeeded(void);
sqInt initializeInterpreter(sqInt bytesToShift);
sqInt initializeMemoryFirstFree(usqInt firstFree);
sqInt initializeObjectMemory(sqInt bytesToShift);
sqInt installinAtCacheatstring(sqInt rcvr, sqInt *cache, sqInt atIx, sqInt stringy);
sqInt instantiateClassindexableSize(sqInt classPointer, sqInt size);
sqInt instantiateContextsizeInBytes(sqInt classPointer, sqInt sizeInBytes);
sqInt instantiateSmallClasssizeInBytes(sqInt classPointer, sqInt sizeInBytes);
sqInt integerObjectOf(sqInt value);
sqInt integerValueOf(sqInt objectPointer);
#pragma export on
EXPORT(sqInt) internalIsImmutable(sqInt oop);
EXPORT(sqInt) internalIsMutable(sqInt oop);
#pragma export off
sqInt interpret(void);
sqInt ioFilenamefromStringofLengthresolveAliases(char *aCharBuffer, char *aFilenameString, sqInt filenameLength, sqInt aBoolean);
sqInt isKindOf(sqInt oop, char *className);
sqInt isMemberOf(sqInt oop, char *className);
sqInt isArray(sqInt oop);
sqInt isBigEnder(void);
sqInt isBytes(sqInt oop);
sqInt isExcessiveAllocationRequestshift(sqInt size, sqInt bits);
sqInt isFloatObject(sqInt oop);
sqInt isHandlerMarked(sqInt aContext);
sqInt isInMemory(sqInt address);
sqInt isIndexable(sqInt oop);
sqInt isIntegerObject(sqInt objectPointer);
sqInt isIntegerValue(sqInt intValue);
sqInt isPointers(sqInt oop);
sqInt isWeak(sqInt oop);
sqInt isWords(sqInt oop);
sqInt isWordsOrBytes(sqInt oop);
sqInt isWordsOrBytesNonInt(sqInt oop);
sqInt lastPointerOf(sqInt oop);
sqInt lengthOf(sqInt oop);
sqInt literalofMethod(sqInt offset, sqInt methodPointer);
sqInt literalCountOf(sqInt methodPointer);
sqInt literalCountOfHeader(sqInt headerPointer);
sqInt loadBitBltFrom(sqInt bb);
sqInt loadInitialContext(void);
sqInt lookupInMethodCacheSelclass(sqInt selector, sqInt class);
sqInt lookupMethodInClass(sqInt class);
sqInt lookupMethodInDictionary(sqInt dictionary);
sqInt lookupMethodNoMNUEtcInClass(sqInt class);
sqInt lowestFreeAfter(sqInt chunk);
sqInt makePointwithxValueyValue(sqInt xValue, sqInt yValue);
sqInt mapPointersInObjectsFromto(sqInt memStart, sqInt memEnd);
sqInt markAndTrace(sqInt oop);
sqInt markAndTraceInterpreterOops(void);
sqInt markPhase(void);
sqInt methodArgumentCount(void);
sqInt methodPrimitiveIndex(void);
#pragma export on
EXPORT(sqInt) moduleUnloaded(char *aModuleName);
#pragma export off
sqInt nilObject(void);
sqInt nonWeakFieldsOf(sqInt oop);
sqInt normalizeFloatOrderingInImage(void);
sqInt noteAsRootheaderLoc(sqInt oop, sqInt headerLoc);
sqInt nullCompilerHook(void);
sqInt objectAfter(sqInt oop);
sqInt obsoleteDontUseThisFetchWordofObject(sqInt fieldIndex, sqInt oop);
sqInt okayFields(sqInt oop);
sqInt okayOop(sqInt signedOop);
sqInt oopisGreaterThan(sqInt anOop, sqInt otherOop);
sqInt oopisGreaterThanOrEqualTo(sqInt anOop, sqInt otherOop);
sqInt oopisLessThan(sqInt anOop, sqInt otherOop);
sqInt oopHasAcceptableClass(sqInt signedOop);
sqInt oopHasOkayClass(sqInt signedOop);
sqInt pop(sqInt nItems);
sqInt popthenPush(sqInt nItems, sqInt oop);
double popFloat(void);
sqInt popRemappableOop(void);
sqInt popStack(void);
sqInt positive32BitIntegerFor(sqInt integerValue);
sqInt positive32BitValueOf(sqInt oop);
sqInt positive64BitIntegerFor(sqLong integerValue);
sqLong positive64BitValueOf(sqInt oop);
sqInt possibleRootStoreIntovalue(sqInt oop, sqInt valueObj);
sqInt postGCAction(void);
sqInt prepareForwardingTableForBecomingwithtwoWay(sqInt array1, sqInt array2, sqInt twoWayFlag);
sqInt primitiveAdd(void);
#pragma export on
EXPORT(sqInt) primitiveAddLargeIntegers(void);
#pragma export off
sqInt primitiveAdoptInstance(void);
sqInt primitiveArctan(void);
sqInt primitiveArrayBecome(void);
sqInt primitiveArrayBecomeOneWay(void);
sqInt primitiveArrayBecomeOneWayCopyHash(void);
sqInt primitiveAsFloat(void);
sqInt primitiveAsOop(void);
sqInt primitiveAt(void);
sqInt primitiveAtPut(void);
sqInt primitiveBeCursor(void);
sqInt primitiveBeDisplay(void);
sqInt primitiveBeep(void);
sqInt primitiveBitAnd(void);
#pragma export on
EXPORT(sqInt) primitiveBitAndLargeIntegers(void);
#pragma export off
sqInt primitiveBitOr(void);
#pragma export on
EXPORT(sqInt) primitiveBitOrLargeIntegers(void);
#pragma export off
sqInt primitiveBitShift(void);
#pragma export on
EXPORT(sqInt) primitiveBitShiftLargeIntegers(void);
#pragma export off
sqInt primitiveBitXor(void);
#pragma export on
EXPORT(sqInt) primitiveBitXorLargeIntegers(void);
#pragma export off
sqInt primitiveBlockCopy(void);
sqInt primitiveBytesLeft(void);
sqInt primitiveCalloutToFFI(void);
sqInt primitiveChangeClass(void);
#pragma export on
EXPORT(sqInt) primitiveChangeClassWithClass(void);
#pragma export off
sqInt primitiveClass(void);
sqInt primitiveClipboardText(void);
sqInt primitiveClone(void);
sqInt primitiveClosureCopyWithCopiedValues(void);
sqInt primitiveClosureValue(void);
sqInt primitiveClosureValueNoContextSwitch(void);
sqInt primitiveClosureValueWithArgs(void);
sqInt primitiveConstantFill(void);
sqInt primitiveCopyObject(void);
sqInt primitiveDeferDisplayUpdates(void);
#pragma export on
EXPORT(sqInt) primitiveDisablePowerManager(void);
#pragma export off
sqInt primitiveDiv(void);
#pragma export on
EXPORT(sqInt) primitiveDivLargeIntegers(void);
#pragma export off
sqInt primitiveDivide(void);
#pragma export on
EXPORT(sqInt) primitiveDivideLargeIntegers(void);
#pragma export off
sqInt primitiveDoPrimitiveWithArgs(void);
sqInt primitiveEqual(void);
#pragma export on
EXPORT(sqInt) primitiveEqualLargeIntegers(void);
#pragma export off
sqInt primitiveEquivalent(void);
sqInt primitiveExecuteMethod(void);
sqInt primitiveExecuteMethodArgsArray(void);
sqInt primitiveExitToDebugger(void);
sqInt primitiveExp(void);
sqInt primitiveExponent(void);
sqInt primitiveExternalCall(void);
sqInt primitiveFail(void);
sqInt primitiveFailFor(sqInt reasonCode);
sqInt primitiveFindHandlerContext(void);
sqInt primitiveFindNextUnwindContext(void);
sqInt primitiveFloatAdd(void);
sqInt primitiveFloatAddtoArg(sqInt rcvrOop, sqInt argOop);
sqInt primitiveFloatDivide(void);
sqInt primitiveFloatDividebyArg(sqInt rcvrOop, sqInt argOop);
sqInt primitiveFloatEqual(void);
sqInt primitiveFloatEqualtoArg(sqInt rcvrOop, sqInt argOop);
sqInt primitiveFloatGreaterthanArg(sqInt rcvrOop, sqInt argOop);
sqInt primitiveFloatGreaterOrEqual(void);
sqInt primitiveFloatGreaterOrEqualtoArg(sqInt rcvrOop, sqInt argOop);
sqInt primitiveFloatGreaterThan(void);
sqInt primitiveFloatLessthanArg(sqInt rcvrOop, sqInt argOop);
sqInt primitiveFloatLessOrEqual(void);
sqInt primitiveFloatLessOrEqualtoArg(sqInt rcvrOop, sqInt argOop);
sqInt primitiveFloatLessThan(void);
sqInt primitiveFloatMultiply(void);
sqInt primitiveFloatMultiplybyArg(sqInt rcvrOop, sqInt argOop);
sqInt primitiveFloatNotEqual(void);
sqInt primitiveFloatSubtract(void);
sqInt primitiveFloatSubtractfromArg(sqInt rcvrOop, sqInt argOop);
sqInt primitiveFlushCache(void);
sqInt primitiveFlushCacheByMethod(void);
sqInt primitiveFlushCacheSelective(void);
sqInt primitiveFlushExternalPrimitives(void);
sqInt primitiveForceDisplayUpdate(void);
#pragma export on
EXPORT(sqInt) primitiveForceTenure(void);
#pragma export off
sqInt primitiveFormPrint(void);
sqInt primitiveFractionalPart(void);
sqInt primitiveFullGC(void);
sqInt primitiveGetAttribute(void);
sqInt primitiveGetNextEvent(void);
sqInt primitiveGreaterOrEqual(void);
#pragma export on
EXPORT(sqInt) primitiveGreaterOrEqualLargeIntegers(void);
#pragma export off
sqInt primitiveGreaterThan(void);
#pragma export on
EXPORT(sqInt) primitiveGreaterThanLargeIntegers(void);
EXPORT(sqInt) primitiveImageFormatVersion(void);
#pragma export off
sqInt primitiveImageName(void);
sqInt primitiveIncrementalGC(void);
sqInt primitiveIndexOf(sqInt methodPointer);
sqInt primitiveInputSemaphore(void);
sqInt primitiveInputWord(void);
sqInt primitiveInstVarAt(void);
sqInt primitiveInstVarAtPut(void);
sqInt primitiveInstVarsPutFromStack(void);
sqInt primitiveIntegerAt(void);
sqInt primitiveIntegerAtPut(void);
#pragma export on
EXPORT(sqInt) primitiveInterpreterSourceVersion(void);
#pragma export off
sqInt primitiveInterruptSemaphore(void);
sqInt primitiveInvokeObjectAsMethod(void);
#pragma export on
EXPORT(sqInt) primitiveIsRoot(void);
EXPORT(sqInt) primitiveIsYoung(void);
#pragma export off
sqInt primitiveKbdNext(void);
sqInt primitiveKbdPeek(void);
sqInt primitiveLessOrEqual(void);
#pragma export on
EXPORT(sqInt) primitiveLessOrEqualLargeIntegers(void);
#pragma export off
sqInt primitiveLessThan(void);
#pragma export on
EXPORT(sqInt) primitiveLessThanLargeIntegers(void);
#pragma export off
sqInt primitiveListBuiltinModule(void);
sqInt primitiveListExternalModule(void);
sqInt primitiveLoadImageSegment(void);
sqInt primitiveLoadInstVar(void);
sqInt primitiveLogN(void);
sqInt primitiveLowSpaceSemaphore(void);
sqInt primitiveMakePoint(void);
sqInt primitiveMarkHandlerMethod(void);
sqInt primitiveMarkUnwindMethod(void);
sqInt primitiveMethod(void);
#pragma export on
EXPORT(sqInt) primitiveMicrosecondClock(void);
#pragma export off
sqInt primitiveMillisecondClock(void);
sqInt primitiveMod(void);
#pragma export on
EXPORT(sqInt) primitiveModLargeIntegers(void);
#pragma export off
sqInt primitiveMouseButtons(void);
sqInt primitiveMousePoint(void);
sqInt primitiveMultiply(void);
#pragma export on
EXPORT(sqInt) primitiveMultiplyLargeIntegers(void);
#pragma export off
sqInt primitiveNew(void);
sqInt primitiveNewMethod(void);
sqInt primitiveNewWithArg(void);
sqInt primitiveNextInstance(void);
sqInt primitiveNextObject(void);
sqInt primitiveNoop(void);
sqInt primitiveNotEqual(void);
#pragma export on
EXPORT(sqInt) primitiveNotEqualLargeIntegers(void);
#pragma export off
sqInt primitiveObjectAt(void);
sqInt primitiveObjectAtPut(void);
sqInt primitiveObjectPointsTo(void);
sqInt primitivePerform(void);
sqInt primitivePerformAt(sqInt lookupClass);
sqInt primitivePerformInSuperclass(void);
sqInt primitivePerformWithArgs(void);
#pragma export on
EXPORT(sqInt) primitivePlatformSourceVersion(void);
#pragma export off
sqInt primitivePushFalse(void);
sqInt primitivePushMinusOne(void);
sqInt primitivePushNil(void);
sqInt primitivePushOne(void);
sqInt primitivePushSelf(void);
sqInt primitivePushTrue(void);
sqInt primitivePushTwo(void);
sqInt primitivePushZero(void);
sqInt primitiveQuit(void);
sqInt primitiveQuo(void);
#pragma export on
EXPORT(sqInt) primitiveQuoLargeIntegers(void);
#pragma export off
sqInt primitiveRelinquishProcessor(void);
sqInt primitiveResponse(void);
sqInt primitiveResume(void);
#pragma export on
EXPORT(sqInt) primitiveRootTable(void);
EXPORT(sqInt) primitiveRootTableAt(void);
#pragma export off
sqInt primitiveScanCharacters(void);
#pragma export on
EXPORT(sqInt) primitiveScreenDepth(void);
#pragma export off
sqInt primitiveScreenSize(void);
sqInt primitiveSecondsClock(void);
sqInt primitiveSetDisplayMode(void);
sqInt primitiveSetFullScreen(void);
#pragma export on
EXPORT(sqInt) primitiveSetGCBiasToGrow(void);
EXPORT(sqInt) primitiveSetGCBiasToGrowGCLimit(void);
EXPORT(sqInt) primitiveSetGCSemaphore(void);
#pragma export off
sqInt primitiveSetInterruptKey(void);
sqInt primitiveShortAt(void);
sqInt primitiveShortAtPut(void);
sqInt primitiveShowDisplayRect(void);
sqInt primitiveSignal(void);
sqInt primitiveSignalAtBytesLeft(void);
sqInt primitiveSignalAtMilliseconds(void);
sqInt primitiveSine(void);
sqInt primitiveSize(void);
sqInt primitiveSnapshot(void);
sqInt primitiveSnapshotEmbedded(void);
sqInt primitiveSomeInstance(void);
sqInt primitiveSomeObject(void);
sqInt primitiveSpecialObjectsOop(void);
sqInt primitiveSquareRoot(void);
sqInt primitiveStoreImageSegment(void);
sqInt primitiveStoreStackp(void);
sqInt primitiveStringAt(void);
sqInt primitiveStringAtPut(void);
sqInt primitiveStringReplace(void);
sqInt primitiveSubtract(void);
#pragma export on
EXPORT(sqInt) primitiveSubtractLargeIntegers(void);
#pragma export off
sqInt primitiveSuspend(void);
sqInt primitiveTerminateTo(void);
sqInt primitiveTestDisplayDepth(void);
sqInt primitiveTimesTwoPower(void);
sqInt primitiveTruncated(void);
sqInt primitiveUnloadModule(void);
#pragma export on
EXPORT(sqInt) primitiveUtcWithOffset(void);
#pragma export off
sqInt primitiveVMParameter(void);
sqInt primitiveVMPath(void);
#pragma export on
EXPORT(sqInt) primitiveVMVersion(void);
#pragma export off
sqInt primitiveValue(void);
sqInt primitiveValueUninterruptably(void);
sqInt primitiveValueWithArgs(void);
sqInt primitiveWait(void);
sqInt primitiveYield(void);
sqInt print(char *s);
#pragma export on
EXPORT(sqInt) printAllStacks(void);
#pragma export off
sqInt printCallStack(void);
sqInt printCallStackOf(sqInt aContext);
sqInt printNameOfClasscount(sqInt classOop, sqInt cnt);
sqInt printNum(sqInt n);
sqInt printStringOf(sqInt oop);
sqInt printUnbalancedStack(sqInt primIdx);
sqInt push(sqInt object);
sqInt pushBool(sqInt trueOrFalse);
sqInt pushFloat(double  f);
sqInt pushInteger(sqInt integerValue);
sqInt pushRemappableOop(sqInt oop);
sqInt putLongtoFile(sqInt aWord, sqImageFile  aFile);
#pragma export on
EXPORT(sqInt) readImageFormatFromFileStartingAt(sqImageFile  f, squeakFileOffsetType  imageOffset);
#pragma export off
sqInt readImageFromFileHeapSizeStartingAt(sqImageFile  f, usqInt desiredHeapSize, squeakFileOffsetType  imageOffset);
sqInt readableFormat(sqInt imageVersion);
#pragma export on
EXPORT(sqInt) reestablishContextPriorToCallback(sqInt callbackContext);
#pragma export off
sqInt remap(sqInt oop);
sqInt removeFirstLinkOfList(sqInt aList);
#pragma export on
EXPORT(sqInt) removeGCRoot(sqInt *varLoc);
#pragma export off
sqInt restoreHeaderOf(sqInt oop);
sqInt restoreHeadersFromtofromandtofrom(sqInt firstIn, sqInt lastIn, sqInt hdrBaseIn, sqInt firstOut, sqInt lastOut, sqInt hdrBaseOut);
sqInt resume(sqInt aProcess);
sqInt reverseDisplayFromto(sqInt startIndex, sqInt endIndex);
sqInt rewriteMethodCacheSelclassprimIndex(sqInt selector, sqInt class, sqInt localPrimIndex);
sqInt rewriteMethodCacheSelclassprimIndexprimFunction(sqInt selector, sqInt class, sqInt localPrimIndex, void *localPrimAddress);
#pragma export on
EXPORT(sqInt) sendInvokeCallbackStackRegistersJmpbuf(sqInt thunkPtr, sqInt stackPtr, sqInt regsPtr, sqInt jmpBufPtr);
#pragma export off
sqInt setCompilerInitialized(sqInt newFlag);
sqInt setFullScreenFlag(sqInt value);
sqInt setInterruptCheckCounter(sqInt value);
sqInt setInterruptKeycode(sqInt value);
sqInt setInterruptPending(sqInt value);
sqInt setMicroSecondsandOffset(sqLong *microSeconds, int *utcOffset);
sqInt setNextWakeupTick(sqInt value);
sqInt setSavedWindowSize(sqInt value);
sqInt showDisplayBitsLeftTopRightBottom(sqInt aForm, sqInt l, sqInt t, sqInt r, sqInt b);
sqInt signalSemaphoreWithIndex(sqInt index);
sqInt signed32BitIntegerFor(int integerValue);
int signed32BitValueOf(sqInt oop);
sqInt signed64BitIntegerFor(sqLong integerValue);
sqLong signed64BitValueOf(sqInt oop);
sqInt sizeBitsOf(sqInt oop);
sqInt sizeOfSTArrayFromCPrimitive(void *cPtr);
sqInt slotSizeOf(sqInt oop);
sqInt snapshot(sqInt embedded);
sqInt splObj(sqInt index);
sqInt stObjectat(sqInt array, sqInt index);
sqInt stObjectatput(sqInt array, sqInt index, sqInt value);
sqInt stSizeOf(sqInt oop);
double stackFloatValue(sqInt offset);
sqInt stackIntegerValue(sqInt offset);
sqInt stackObjectValue(sqInt offset);
sqInt stackValue(sqInt offset);
sqInt storeIntegerofObjectwithValue(sqInt fieldIndex, sqInt objectPointer, sqInt integerValue);
sqInt storePointerofObjectwithValue(sqInt fieldIndex, sqInt oop, sqInt valuePointer);
sqInt success(sqInt successValue);
sqInt sufficientSpaceAfterGC(usqInt minFree);
sqInt sufficientSpaceToAllocate(usqInt bytes);
sqInt superclassOf(sqInt classPointer);
sqInt sweepPhase(void);
sqInt synchronousSignal(sqInt aSemaphore);
sqInt transferTo(sqInt aProc);
sqInt trueObject(void);
sqInt updatePointersInRangeFromto(sqInt memStart, sqInt memEnd);
sqInt updatePointersInRootObjectsFromto(sqInt memStart, sqInt memEnd);
sqInt validateRoots(void);
sqInt verifyCleanHeaders(void);
sqInt vmEndianness(void);
sqInt wakeHighestPriority(void);
sqInt wordSwapped(sqInt w);
sqInt writeImageFile(sqInt imageBytes);
sqInt writeImageFileIO(sqInt imageBytes);
/*** Variables ***/
static struct foo {
sqInt successFlag;
sqInt specialObjectsOop;
sqInt nilObj;
sqInt argumentCount;
sqInt falseObj;
sqInt trueObj;
sqInt interruptCheckCounter;
sqInt remapBufferCount;
sqInt nextPollTick;
sqInt primitiveIndex;
sqInt messageSelector;
sqInt rootTableCount;
sqInt compilerInitialized;
sqInt allocationCount;
sqInt receiver;
sqInt lkupClass;
sqInt allocationsBetweenGCs;
sqInt lowSpaceThreshold;
sqInt signalLowSpace;
sqInt lastHash;
sqInt reclaimableContextCount;
sqInt freeContexts;
sqInt pendingFinalizationSignals;
sqInt freeLargeContexts;
sqInt newNativeMethod;
sqInt methodClass;
sqInt jmpDepth;
sqInt statMarkCount;
sqInt extraRootCount;
sqInt nextWakeupTick;
sqInt interruptKeycode;
sqInt semaphoresToSignalCountA;
sqInt receiverClass;
sqInt interruptPending;
sqInt semaphoresToSignalCountB;
sqInt fullScreenFlag;
sqInt statCompMoveCount;
sqInt statSweepCount;
sqInt statMkFwdCount;
sqInt semaphoresUseBufferA;
sqInt tenuringThreshold;
sqInt gcBiasToGrow;
sqInt statRootTableOverflows;
sqInt statFullGCs;
sqInt gcBiasToGrowGCLimit;
sqInt statTenures;
sqInt statIncrGCs;
sqInt statGrowMemory;
sqInt savedWindowSize;
sqInt deferDisplayUpdates;
sqInt statShrinkMemory;
sqInt statpendingFinalizationSignals;
sqInt forceTenureFlag;
sqInt totalObjectCount;
sqInt interruptChecksEveryNms;
sqInt gcSemaphoreIndex;
sqInt statAllocationCount;
sqInt lastTick;
sqInt weakRootCount;
sqInt jmpMax;
sqInt interruptCheckCounterFeedBackReset;
sqInt statSpecialMarkCount;
sqInt globalSessionID;
sqInt statSurvivorCount;
sqInt statRootTableCount;
sqLong statGCTime;
sqLong statIGCDeltaTime;
sqLong statIncrGCMSecs;
usqInt shrinkThreshold;
sqLong statFullGCMSecs;
usqInt gcBiasToGrowThreshold;
sqInt headerTypeBytes[4];
sqInt remapBuffer[26];
usqInt growHeadroom;
sqInt processSignalingLowSpace;
sqInt semaphoresToSignalB[501];
sqInt semaphoresToSignalA[501];
sqInt atCache[65];
usqInt method;
usqInt theHomeContext;
usqInt stackPointer;
usqInt instructionPointer;
void *primitiveFunctionPointer;
usqInt newMethod;
void *externalPrimitiveTable[4097];
long methodCache[4097];
usqInt endOfMemory;
sqInt weakRoots[2625];
sqInt* extraRoots[2049];
usqInt compStart;
usqInt freeBlock;
usqInt fwdTableNext;
usqInt compEnd;
sqInt rootTable[2501];
usqInt memoryLimit;
usqInt fwdTableLast;
sqInt suspendedCallbacks[33];
jmp_buf jmpBuf[33];
sqInt suspendedMethods[33];
usqInt youngStart;
usqInt activeContext;
 } fum;
struct foo * foo = &fum;

sqInt extraVMMemory;
const char *interpreterVersion = "Squeak4.1 of 17 April 2010 [latest update: #9957]";
sqInt (*compilerHooks[16])();
struct VirtualMachine* interpreterProxy;
sqInt imageFormatVersionNumber = 0;
void* showSurfaceFn;
sqInt imageFormatInitialVersion = 0;
usqInt memory;
void *primitiveTable[577] = {
	/* 0*/ (void *)primitiveFail,
	/* 1*/ (void *)primitiveAdd,
	/* 2*/ (void *)primitiveSubtract,
	/* 3*/ (void *)primitiveLessThan,
	/* 4*/ (void *)primitiveGreaterThan,
	/* 5*/ (void *)primitiveLessOrEqual,
	/* 6*/ (void *)primitiveGreaterOrEqual,
	/* 7*/ (void *)primitiveEqual,
	/* 8*/ (void *)primitiveNotEqual,
	/* 9*/ (void *)primitiveMultiply,
	/* 10*/ (void *)primitiveDivide,
	/* 11*/ (void *)primitiveMod,
	/* 12*/ (void *)primitiveDiv,
	/* 13*/ (void *)primitiveQuo,
	/* 14*/ (void *)primitiveBitAnd,
	/* 15*/ (void *)primitiveBitOr,
	/* 16*/ (void *)primitiveBitXor,
	/* 17*/ (void *)primitiveBitShift,
	/* 18*/ (void *)primitiveMakePoint,
	/* 19*/ (void *)primitiveFail,
	/* 20*/ (void *)primitiveFail,
	/* 21*/ (void *)primitiveAddLargeIntegers,
	/* 22*/ (void *)primitiveSubtractLargeIntegers,
	/* 23*/ (void *)primitiveLessThanLargeIntegers,
	/* 24*/ (void *)primitiveGreaterThanLargeIntegers,
	/* 25*/ (void *)primitiveLessOrEqualLargeIntegers,
	/* 26*/ (void *)primitiveGreaterOrEqualLargeIntegers,
	/* 27*/ (void *)primitiveEqualLargeIntegers,
	/* 28*/ (void *)primitiveNotEqualLargeIntegers,
	/* 29*/ (void *)primitiveMultiplyLargeIntegers,
	/* 30*/ (void *)primitiveDivideLargeIntegers,
	/* 31*/ (void *)primitiveModLargeIntegers,
	/* 32*/ (void *)primitiveDivLargeIntegers,
	/* 33*/ (void *)primitiveQuoLargeIntegers,
	/* 34*/ (void *)primitiveBitAndLargeIntegers,
	/* 35*/ (void *)primitiveBitOrLargeIntegers,
	/* 36*/ (void *)primitiveBitXorLargeIntegers,
	/* 37*/ (void *)primitiveBitShiftLargeIntegers,
	/* 38*/ (void *)primitiveFail,
	/* 39*/ (void *)primitiveFail,
	/* 40*/ (void *)primitiveAsFloat,
	/* 41*/ (void *)primitiveFloatAdd,
	/* 42*/ (void *)primitiveFloatSubtract,
	/* 43*/ (void *)primitiveFloatLessThan,
	/* 44*/ (void *)primitiveFloatGreaterThan,
	/* 45*/ (void *)primitiveFloatLessOrEqual,
	/* 46*/ (void *)primitiveFloatGreaterOrEqual,
	/* 47*/ (void *)primitiveFloatEqual,
	/* 48*/ (void *)primitiveFloatNotEqual,
	/* 49*/ (void *)primitiveFloatMultiply,
	/* 50*/ (void *)primitiveFloatDivide,
	/* 51*/ (void *)primitiveTruncated,
	/* 52*/ (void *)primitiveFractionalPart,
	/* 53*/ (void *)primitiveExponent,
	/* 54*/ (void *)primitiveTimesTwoPower,
	/* 55*/ (void *)primitiveSquareRoot,
	/* 56*/ (void *)primitiveSine,
	/* 57*/ (void *)primitiveArctan,
	/* 58*/ (void *)primitiveLogN,
	/* 59*/ (void *)primitiveExp,
	/* 60*/ (void *)primitiveAt,
	/* 61*/ (void *)primitiveAtPut,
	/* 62*/ (void *)primitiveSize,
	/* 63*/ (void *)primitiveStringAt,
	/* 64*/ (void *)primitiveStringAtPut,
	/* 65*/ (void *)primitiveFail,
	/* 66*/ (void *)primitiveFail,
	/* 67*/ (void *)primitiveFail,
	/* 68*/ (void *)primitiveObjectAt,
	/* 69*/ (void *)primitiveObjectAtPut,
	/* 70*/ (void *)primitiveNew,
	/* 71*/ (void *)primitiveNewWithArg,
	/* 72*/ (void *)primitiveArrayBecomeOneWay,
	/* 73*/ (void *)primitiveInstVarAt,
	/* 74*/ (void *)primitiveInstVarAtPut,
	/* 75*/ (void *)primitiveAsOop,
	/* 76*/ (void *)primitiveStoreStackp,
	/* 77*/ (void *)primitiveSomeInstance,
	/* 78*/ (void *)primitiveNextInstance,
	/* 79*/ (void *)primitiveNewMethod,
	/* 80*/ (void *)primitiveBlockCopy,
	/* 81*/ (void *)primitiveValue,
	/* 82*/ (void *)primitiveValueWithArgs,
	/* 83*/ (void *)primitivePerform,
	/* 84*/ (void *)primitivePerformWithArgs,
	/* 85*/ (void *)primitiveSignal,
	/* 86*/ (void *)primitiveWait,
	/* 87*/ (void *)primitiveResume,
	/* 88*/ (void *)primitiveSuspend,
	/* 89*/ (void *)primitiveFlushCache,
	/* 90*/ (void *)primitiveMousePoint,
	/* 91*/ (void *)primitiveTestDisplayDepth,
	/* 92*/ (void *)primitiveSetDisplayMode,
	/* 93*/ (void *)primitiveInputSemaphore,
	/* 94*/ (void *)primitiveGetNextEvent,
	/* 95*/ (void *)primitiveInputWord,
	/* 96*/ (void *)primitiveFail,
	/* 97*/ (void *)primitiveSnapshot,
	/* 98*/ (void *)primitiveStoreImageSegment,
	/* 99*/ (void *)primitiveLoadImageSegment,
	/* 100*/ (void *)primitivePerformInSuperclass,
	/* 101*/ (void *)primitiveBeCursor,
	/* 102*/ (void *)primitiveBeDisplay,
	/* 103*/ (void *)primitiveScanCharacters,
	/* 104*/ (void *)primitiveFail,
	/* 105*/ (void *)primitiveStringReplace,
	/* 106*/ (void *)primitiveScreenSize,
	/* 107*/ (void *)primitiveMouseButtons,
	/* 108*/ (void *)primitiveKbdNext,
	/* 109*/ (void *)primitiveKbdPeek,
	/* 110*/ (void *)primitiveEquivalent,
	/* 111*/ (void *)primitiveClass,
	/* 112*/ (void *)primitiveBytesLeft,
	/* 113*/ (void *)primitiveQuit,
	/* 114*/ (void *)primitiveExitToDebugger,
	/* 115*/ (void *)primitiveChangeClass,
	/* 116*/ (void *)primitiveFlushCacheByMethod,
	/* 117*/ (void *)primitiveExternalCall,
	/* 118*/ (void *)primitiveDoPrimitiveWithArgs,
	/* 119*/ (void *)primitiveFlushCacheSelective,
	/* 120*/ (void *)primitiveCalloutToFFI,
	/* 121*/ (void *)primitiveImageName,
	/* 122*/ (void *)primitiveNoop,
	/* 123*/ (void *)primitiveValueUninterruptably,
	/* 124*/ (void *)primitiveLowSpaceSemaphore,
	/* 125*/ (void *)primitiveSignalAtBytesLeft,
	/* 126*/ (void *)primitiveDeferDisplayUpdates,
	/* 127*/ (void *)primitiveShowDisplayRect,
	/* 128*/ (void *)primitiveArrayBecome,
	/* 129*/ (void *)primitiveSpecialObjectsOop,
	/* 130*/ (void *)primitiveFullGC,
	/* 131*/ (void *)primitiveIncrementalGC,
	/* 132*/ (void *)primitiveObjectPointsTo,
	/* 133*/ (void *)primitiveSetInterruptKey,
	/* 134*/ (void *)primitiveInterruptSemaphore,
	/* 135*/ (void *)primitiveMillisecondClock,
	/* 136*/ (void *)primitiveSignalAtMilliseconds,
	/* 137*/ (void *)primitiveSecondsClock,
	/* 138*/ (void *)primitiveSomeObject,
	/* 139*/ (void *)primitiveNextObject,
	/* 140*/ (void *)primitiveBeep,
	/* 141*/ (void *)primitiveClipboardText,
	/* 142*/ (void *)primitiveVMPath,
	/* 143*/ (void *)primitiveShortAt,
	/* 144*/ (void *)primitiveShortAtPut,
	/* 145*/ (void *)primitiveConstantFill,
	/* 146*/ (void *)primitiveFail,
	/* 147*/ (void *)primitiveFail,
	/* 148*/ (void *)primitiveClone,
	/* 149*/ (void *)primitiveGetAttribute,
	/* 150*/ (void *)primitiveFail,
	/* 151*/ (void *)primitiveFail,
	/* 152*/ (void *)primitiveFail,
	/* 153*/ (void *)primitiveFail,
	/* 154*/ (void *)primitiveFail,
	/* 155*/ (void *)primitiveFail,
	/* 156*/ (void *)primitiveFail,
	/* 157*/ (void *)primitiveFail,
	/* 158*/ (void *)primitiveFail,
	/* 159*/ (void *)primitiveFail,
	/* 160*/ (void *)primitiveAdoptInstance,
	/* 161*/ (void *)primitiveFail,
	/* 162*/ (void *)primitiveFail,
	/* 163*/ (void *)primitiveFail,
	/* 164*/ (void *)primitiveFail,
	/* 165*/ (void *)primitiveIntegerAt,
	/* 166*/ (void *)primitiveIntegerAtPut,
	/* 167*/ (void *)primitiveYield,
	/* 168*/ (void *)primitiveCopyObject,
	/* 169*/ (void *)primitiveFail,
	/* 170*/ (void *)primitiveFail,
	/* 171*/ (void *)primitiveFail,
	/* 172*/ (void *)primitiveFail,
	/* 173*/ (void *)primitiveFail,
	/* 174*/ (void *)primitiveFail,
	/* 175*/ (void *)primitiveFail,
	/* 176*/ (void *)primitiveFail,
	/* 177*/ (void *)primitiveFail,
	/* 178*/ (void *)primitiveFail,
	/* 179*/ (void *)primitiveFail,
	/* 180*/ (void *)primitiveFail,
	/* 181*/ (void *)primitiveFail,
	/* 182*/ (void *)primitiveFail,
	/* 183*/ (void *)primitiveFail,
	/* 184*/ (void *)primitiveFail,
	/* 185*/ (void *)primitiveFail,
	/* 186*/ (void *)primitiveFail,
	/* 187*/ (void *)primitiveFail,
	/* 188*/ (void *)primitiveExecuteMethodArgsArray,
	/* 189*/ (void *)primitiveExecuteMethod,
	/* 190*/ (void *)primitiveFail,
	/* 191*/ (void *)primitiveFail,
	/* 192*/ (void *)primitiveFail,
	/* 193*/ (void *)primitiveFail,
	/* 194*/ (void *)primitiveFail,
	/* 195*/ (void *)primitiveFindNextUnwindContext,
	/* 196*/ (void *)primitiveTerminateTo,
	/* 197*/ (void *)primitiveFindHandlerContext,
	/* 198*/ (void *)primitiveMarkUnwindMethod,
	/* 199*/ (void *)primitiveMarkHandlerMethod,
	/* 200*/ (void *)primitiveClosureCopyWithCopiedValues,
	/* 201*/ (void *)primitiveClosureValue,
	/* 202*/ (void *)primitiveClosureValue,
	/* 203*/ (void *)primitiveClosureValue,
	/* 204*/ (void *)primitiveClosureValue,
	/* 205*/ (void *)primitiveClosureValue,
	/* 206*/ (void *)primitiveClosureValueWithArgs,
	/* 207*/ (void *)primitiveFail,
	/* 208*/ (void *)primitiveFail,
	/* 209*/ (void *)primitiveFail,
	/* 210*/ (void *)primitiveAt,
	/* 211*/ (void *)primitiveAtPut,
	/* 212*/ (void *)primitiveSize,
	/* 213*/ (void *)primitiveFail,
	/* 214*/ (void *)primitiveFail,
	/* 215*/ (void *)primitiveFail,
	/* 216*/ (void *)primitiveFail,
	/* 217*/ (void *)primitiveFail,
	/* 218*/ (void *)primitiveFail,
	/* 219*/ (void *)primitiveFail,
	/* 220*/ (void *)primitiveFail,
	/* 221*/ (void *)primitiveClosureValueNoContextSwitch,
	/* 222*/ (void *)primitiveClosureValueNoContextSwitch,
	/* 223*/ (void *)primitiveFail,
	/* 224*/ (void *)primitiveFail,
	/* 225*/ (void *)primitiveFail,
	/* 226*/ (void *)primitiveFail,
	/* 227*/ (void *)primitiveFail,
	/* 228*/ (void *)primitiveFail,
	/* 229*/ (void *)primitiveFail,
	/* 230*/ (void *)primitiveRelinquishProcessor,
	/* 231*/ (void *)primitiveForceDisplayUpdate,
	/* 232*/ (void *)primitiveFormPrint,
	/* 233*/ (void *)primitiveSetFullScreen,
	/* 234*/ (void *)primitiveFail,
	/* 235*/ (void *)primitiveFail,
	/* 236*/ (void *)primitiveFail,
	/* 237*/ (void *)primitiveFail,
	/* 238*/ (void *)primitiveFail,
	/* 239*/ (void *)primitiveFail,
	/* 240*/ (void *)primitiveFail,
	/* 241*/ (void *)primitiveFail,
	/* 242*/ (void *)primitiveFail,
	/* 243*/ (void *)primitiveFail,
	/* 244*/ (void *)primitiveFail,
	/* 245*/ (void *)primitiveFail,
	/* 246*/ (void *)primitiveFail,
	/* 247*/ (void *)primitiveSnapshotEmbedded,
	/* 248*/ (void *)primitiveInvokeObjectAsMethod,
	/* 249*/ (void *)primitiveArrayBecomeOneWayCopyHash,
	/* 250*/ (void *)clearProfile,
	/* 251*/ (void *)dumpProfile,
	/* 252*/ (void *)startProfiling,
	/* 253*/ (void *)stopProfiling,
	/* 254*/ (void *)primitiveVMParameter,
	/* 255*/ (void *)primitiveInstVarsPutFromStack,
	/* 256*/ (void *)primitivePushSelf,
	/* 257*/ (void *)primitivePushTrue,
	/* 258*/ (void *)primitivePushFalse,
	/* 259*/ (void *)primitivePushNil,
	/* 260*/ (void *)primitivePushMinusOne,
	/* 261*/ (void *)primitivePushZero,
	/* 262*/ (void *)primitivePushOne,
	/* 263*/ (void *)primitivePushTwo,
	/* 264*/ (void *)primitiveLoadInstVar,
	/* 265*/ (void *)primitiveLoadInstVar,
	/* 266*/ (void *)primitiveLoadInstVar,
	/* 267*/ (void *)primitiveLoadInstVar,
	/* 268*/ (void *)primitiveLoadInstVar,
	/* 269*/ (void *)primitiveLoadInstVar,
	/* 270*/ (void *)primitiveLoadInstVar,
	/* 271*/ (void *)primitiveLoadInstVar,
	/* 272*/ (void *)primitiveLoadInstVar,
	/* 273*/ (void *)primitiveLoadInstVar,
	/* 274*/ (void *)primitiveLoadInstVar,
	/* 275*/ (void *)primitiveLoadInstVar,
	/* 276*/ (void *)primitiveLoadInstVar,
	/* 277*/ (void *)primitiveLoadInstVar,
	/* 278*/ (void *)primitiveLoadInstVar,
	/* 279*/ (void *)primitiveLoadInstVar,
	/* 280*/ (void *)primitiveLoadInstVar,
	/* 281*/ (void *)primitiveLoadInstVar,
	/* 282*/ (void *)primitiveLoadInstVar,
	/* 283*/ (void *)primitiveLoadInstVar,
	/* 284*/ (void *)primitiveLoadInstVar,
	/* 285*/ (void *)primitiveLoadInstVar,
	/* 286*/ (void *)primitiveLoadInstVar,
	/* 287*/ (void *)primitiveLoadInstVar,
	/* 288*/ (void *)primitiveLoadInstVar,
	/* 289*/ (void *)primitiveLoadInstVar,
	/* 290*/ (void *)primitiveLoadInstVar,
	/* 291*/ (void *)primitiveLoadInstVar,
	/* 292*/ (void *)primitiveLoadInstVar,
	/* 293*/ (void *)primitiveLoadInstVar,
	/* 294*/ (void *)primitiveLoadInstVar,
	/* 295*/ (void *)primitiveLoadInstVar,
	/* 296*/ (void *)primitiveLoadInstVar,
	/* 297*/ (void *)primitiveLoadInstVar,
	/* 298*/ (void *)primitiveLoadInstVar,
	/* 299*/ (void *)primitiveLoadInstVar,
	/* 300*/ (void *)primitiveLoadInstVar,
	/* 301*/ (void *)primitiveLoadInstVar,
	/* 302*/ (void *)primitiveLoadInstVar,
	/* 303*/ (void *)primitiveLoadInstVar,
	/* 304*/ (void *)primitiveLoadInstVar,
	/* 305*/ (void *)primitiveLoadInstVar,
	/* 306*/ (void *)primitiveLoadInstVar,
	/* 307*/ (void *)primitiveLoadInstVar,
	/* 308*/ (void *)primitiveLoadInstVar,
	/* 309*/ (void *)primitiveLoadInstVar,
	/* 310*/ (void *)primitiveLoadInstVar,
	/* 311*/ (void *)primitiveLoadInstVar,
	/* 312*/ (void *)primitiveLoadInstVar,
	/* 313*/ (void *)primitiveLoadInstVar,
	/* 314*/ (void *)primitiveLoadInstVar,
	/* 315*/ (void *)primitiveLoadInstVar,
	/* 316*/ (void *)primitiveLoadInstVar,
	/* 317*/ (void *)primitiveLoadInstVar,
	/* 318*/ (void *)primitiveLoadInstVar,
	/* 319*/ (void *)primitiveLoadInstVar,
	/* 320*/ (void *)primitiveLoadInstVar,
	/* 321*/ (void *)primitiveLoadInstVar,
	/* 322*/ (void *)primitiveLoadInstVar,
	/* 323*/ (void *)primitiveLoadInstVar,
	/* 324*/ (void *)primitiveLoadInstVar,
	/* 325*/ (void *)primitiveLoadInstVar,
	/* 326*/ (void *)primitiveLoadInstVar,
	/* 327*/ (void *)primitiveLoadInstVar,
	/* 328*/ (void *)primitiveLoadInstVar,
	/* 329*/ (void *)primitiveLoadInstVar,
	/* 330*/ (void *)primitiveLoadInstVar,
	/* 331*/ (void *)primitiveLoadInstVar,
	/* 332*/ (void *)primitiveLoadInstVar,
	/* 333*/ (void *)primitiveLoadInstVar,
	/* 334*/ (void *)primitiveLoadInstVar,
	/* 335*/ (void *)primitiveLoadInstVar,
	/* 336*/ (void *)primitiveLoadInstVar,
	/* 337*/ (void *)primitiveLoadInstVar,
	/* 338*/ (void *)primitiveLoadInstVar,
	/* 339*/ (void *)primitiveLoadInstVar,
	/* 340*/ (void *)primitiveLoadInstVar,
	/* 341*/ (void *)primitiveLoadInstVar,
	/* 342*/ (void *)primitiveLoadInstVar,
	/* 343*/ (void *)primitiveLoadInstVar,
	/* 344*/ (void *)primitiveLoadInstVar,
	/* 345*/ (void *)primitiveLoadInstVar,
	/* 346*/ (void *)primitiveLoadInstVar,
	/* 347*/ (void *)primitiveLoadInstVar,
	/* 348*/ (void *)primitiveLoadInstVar,
	/* 349*/ (void *)primitiveLoadInstVar,
	/* 350*/ (void *)primitiveLoadInstVar,
	/* 351*/ (void *)primitiveLoadInstVar,
	/* 352*/ (void *)primitiveLoadInstVar,
	/* 353*/ (void *)primitiveLoadInstVar,
	/* 354*/ (void *)primitiveLoadInstVar,
	/* 355*/ (void *)primitiveLoadInstVar,
	/* 356*/ (void *)primitiveLoadInstVar,
	/* 357*/ (void *)primitiveLoadInstVar,
	/* 358*/ (void *)primitiveLoadInstVar,
	/* 359*/ (void *)primitiveLoadInstVar,
	/* 360*/ (void *)primitiveLoadInstVar,
	/* 361*/ (void *)primitiveLoadInstVar,
	/* 362*/ (void *)primitiveLoadInstVar,
	/* 363*/ (void *)primitiveLoadInstVar,
	/* 364*/ (void *)primitiveLoadInstVar,
	/* 365*/ (void *)primitiveLoadInstVar,
	/* 366*/ (void *)primitiveLoadInstVar,
	/* 367*/ (void *)primitiveLoadInstVar,
	/* 368*/ (void *)primitiveLoadInstVar,
	/* 369*/ (void *)primitiveLoadInstVar,
	/* 370*/ (void *)primitiveLoadInstVar,
	/* 371*/ (void *)primitiveLoadInstVar,
	/* 372*/ (void *)primitiveLoadInstVar,
	/* 373*/ (void *)primitiveLoadInstVar,
	/* 374*/ (void *)primitiveLoadInstVar,
	/* 375*/ (void *)primitiveLoadInstVar,
	/* 376*/ (void *)primitiveLoadInstVar,
	/* 377*/ (void *)primitiveLoadInstVar,
	/* 378*/ (void *)primitiveLoadInstVar,
	/* 379*/ (void *)primitiveLoadInstVar,
	/* 380*/ (void *)primitiveLoadInstVar,
	/* 381*/ (void *)primitiveLoadInstVar,
	/* 382*/ (void *)primitiveLoadInstVar,
	/* 383*/ (void *)primitiveLoadInstVar,
	/* 384*/ (void *)primitiveLoadInstVar,
	/* 385*/ (void *)primitiveLoadInstVar,
	/* 386*/ (void *)primitiveLoadInstVar,
	/* 387*/ (void *)primitiveLoadInstVar,
	/* 388*/ (void *)primitiveLoadInstVar,
	/* 389*/ (void *)primitiveLoadInstVar,
	/* 390*/ (void *)primitiveLoadInstVar,
	/* 391*/ (void *)primitiveLoadInstVar,
	/* 392*/ (void *)primitiveLoadInstVar,
	/* 393*/ (void *)primitiveLoadInstVar,
	/* 394*/ (void *)primitiveLoadInstVar,
	/* 395*/ (void *)primitiveLoadInstVar,
	/* 396*/ (void *)primitiveLoadInstVar,
	/* 397*/ (void *)primitiveLoadInstVar,
	/* 398*/ (void *)primitiveLoadInstVar,
	/* 399*/ (void *)primitiveLoadInstVar,
	/* 400*/ (void *)primitiveLoadInstVar,
	/* 401*/ (void *)primitiveLoadInstVar,
	/* 402*/ (void *)primitiveLoadInstVar,
	/* 403*/ (void *)primitiveLoadInstVar,
	/* 404*/ (void *)primitiveLoadInstVar,
	/* 405*/ (void *)primitiveLoadInstVar,
	/* 406*/ (void *)primitiveLoadInstVar,
	/* 407*/ (void *)primitiveLoadInstVar,
	/* 408*/ (void *)primitiveLoadInstVar,
	/* 409*/ (void *)primitiveLoadInstVar,
	/* 410*/ (void *)primitiveLoadInstVar,
	/* 411*/ (void *)primitiveLoadInstVar,
	/* 412*/ (void *)primitiveLoadInstVar,
	/* 413*/ (void *)primitiveLoadInstVar,
	/* 414*/ (void *)primitiveLoadInstVar,
	/* 415*/ (void *)primitiveLoadInstVar,
	/* 416*/ (void *)primitiveLoadInstVar,
	/* 417*/ (void *)primitiveLoadInstVar,
	/* 418*/ (void *)primitiveLoadInstVar,
	/* 419*/ (void *)primitiveLoadInstVar,
	/* 420*/ (void *)primitiveLoadInstVar,
	/* 421*/ (void *)primitiveLoadInstVar,
	/* 422*/ (void *)primitiveLoadInstVar,
	/* 423*/ (void *)primitiveLoadInstVar,
	/* 424*/ (void *)primitiveLoadInstVar,
	/* 425*/ (void *)primitiveLoadInstVar,
	/* 426*/ (void *)primitiveLoadInstVar,
	/* 427*/ (void *)primitiveLoadInstVar,
	/* 428*/ (void *)primitiveLoadInstVar,
	/* 429*/ (void *)primitiveLoadInstVar,
	/* 430*/ (void *)primitiveLoadInstVar,
	/* 431*/ (void *)primitiveLoadInstVar,
	/* 432*/ (void *)primitiveLoadInstVar,
	/* 433*/ (void *)primitiveLoadInstVar,
	/* 434*/ (void *)primitiveLoadInstVar,
	/* 435*/ (void *)primitiveLoadInstVar,
	/* 436*/ (void *)primitiveLoadInstVar,
	/* 437*/ (void *)primitiveLoadInstVar,
	/* 438*/ (void *)primitiveLoadInstVar,
	/* 439*/ (void *)primitiveLoadInstVar,
	/* 440*/ (void *)primitiveLoadInstVar,
	/* 441*/ (void *)primitiveLoadInstVar,
	/* 442*/ (void *)primitiveLoadInstVar,
	/* 443*/ (void *)primitiveLoadInstVar,
	/* 444*/ (void *)primitiveLoadInstVar,
	/* 445*/ (void *)primitiveLoadInstVar,
	/* 446*/ (void *)primitiveLoadInstVar,
	/* 447*/ (void *)primitiveLoadInstVar,
	/* 448*/ (void *)primitiveLoadInstVar,
	/* 449*/ (void *)primitiveLoadInstVar,
	/* 450*/ (void *)primitiveLoadInstVar,
	/* 451*/ (void *)primitiveLoadInstVar,
	/* 452*/ (void *)primitiveLoadInstVar,
	/* 453*/ (void *)primitiveLoadInstVar,
	/* 454*/ (void *)primitiveLoadInstVar,
	/* 455*/ (void *)primitiveLoadInstVar,
	/* 456*/ (void *)primitiveLoadInstVar,
	/* 457*/ (void *)primitiveLoadInstVar,
	/* 458*/ (void *)primitiveLoadInstVar,
	/* 459*/ (void *)primitiveLoadInstVar,
	/* 460*/ (void *)primitiveLoadInstVar,
	/* 461*/ (void *)primitiveLoadInstVar,
	/* 462*/ (void *)primitiveLoadInstVar,
	/* 463*/ (void *)primitiveLoadInstVar,
	/* 464*/ (void *)primitiveLoadInstVar,
	/* 465*/ (void *)primitiveLoadInstVar,
	/* 466*/ (void *)primitiveLoadInstVar,
	/* 467*/ (void *)primitiveLoadInstVar,
	/* 468*/ (void *)primitiveLoadInstVar,
	/* 469*/ (void *)primitiveLoadInstVar,
	/* 470*/ (void *)primitiveLoadInstVar,
	/* 471*/ (void *)primitiveLoadInstVar,
	/* 472*/ (void *)primitiveLoadInstVar,
	/* 473*/ (void *)primitiveLoadInstVar,
	/* 474*/ (void *)primitiveLoadInstVar,
	/* 475*/ (void *)primitiveLoadInstVar,
	/* 476*/ (void *)primitiveLoadInstVar,
	/* 477*/ (void *)primitiveLoadInstVar,
	/* 478*/ (void *)primitiveLoadInstVar,
	/* 479*/ (void *)primitiveLoadInstVar,
	/* 480*/ (void *)primitiveLoadInstVar,
	/* 481*/ (void *)primitiveLoadInstVar,
	/* 482*/ (void *)primitiveLoadInstVar,
	/* 483*/ (void *)primitiveLoadInstVar,
	/* 484*/ (void *)primitiveLoadInstVar,
	/* 485*/ (void *)primitiveLoadInstVar,
	/* 486*/ (void *)primitiveLoadInstVar,
	/* 487*/ (void *)primitiveLoadInstVar,
	/* 488*/ (void *)primitiveLoadInstVar,
	/* 489*/ (void *)primitiveLoadInstVar,
	/* 490*/ (void *)primitiveLoadInstVar,
	/* 491*/ (void *)primitiveLoadInstVar,
	/* 492*/ (void *)primitiveLoadInstVar,
	/* 493*/ (void *)primitiveLoadInstVar,
	/* 494*/ (void *)primitiveLoadInstVar,
	/* 495*/ (void *)primitiveLoadInstVar,
	/* 496*/ (void *)primitiveLoadInstVar,
	/* 497*/ (void *)primitiveLoadInstVar,
	/* 498*/ (void *)primitiveLoadInstVar,
	/* 499*/ (void *)primitiveLoadInstVar,
	/* 500*/ (void *)primitiveLoadInstVar,
	/* 501*/ (void *)primitiveLoadInstVar,
	/* 502*/ (void *)primitiveLoadInstVar,
	/* 503*/ (void *)primitiveLoadInstVar,
	/* 504*/ (void *)primitiveLoadInstVar,
	/* 505*/ (void *)primitiveLoadInstVar,
	/* 506*/ (void *)primitiveLoadInstVar,
	/* 507*/ (void *)primitiveLoadInstVar,
	/* 508*/ (void *)primitiveLoadInstVar,
	/* 509*/ (void *)primitiveLoadInstVar,
	/* 510*/ (void *)primitiveLoadInstVar,
	/* 511*/ (void *)primitiveLoadInstVar,
	/* 512*/ (void *)primitiveLoadInstVar,
	/* 513*/ (void *)primitiveLoadInstVar,
	/* 514*/ (void *)primitiveLoadInstVar,
	/* 515*/ (void *)primitiveLoadInstVar,
	/* 516*/ (void *)primitiveLoadInstVar,
	/* 517*/ (void *)primitiveLoadInstVar,
	/* 518*/ (void *)primitiveLoadInstVar,
	/* 519*/ (void *)primitiveLoadInstVar,
	/* 520*/ (void *)primitiveFail,
	/* 521*/ (void *)primitiveFail,
	/* 522*/ (void *)primitiveFail,
	/* 523*/ (void *)primitiveFail,
	/* 524*/ (void *)primitiveFail,
	/* 525*/ (void *)primitiveFail,
	/* 526*/ (void *)primitiveFail,
	/* 527*/ (void *)primitiveFail,
	/* 528*/ (void *)primitiveFail,
	/* 529*/ (void *)primitiveFail,
	/* 530*/ (void *)primitiveFail,
	/* 531*/ (void *)primitiveFail,
	/* 532*/ (void *)primitiveFail,
	/* 533*/ (void *)primitiveFail,
	/* 534*/ (void *)primitiveFail,
	/* 535*/ (void *)primitiveFail,
	/* 536*/ (void *)primitiveFail,
	/* 537*/ (void *)primitiveFail,
	/* 538*/ (void *)primitiveFail,
	/* 539*/ (void *)primitiveFail,
	/* 540*/ (void *)primitiveFail,
	/* 541*/ (void *)primitiveFail,
	/* 542*/ (void *)primitiveFail,
	/* 543*/ (void *)primitiveFail,
	/* 544*/ (void *)primitiveFail,
	/* 545*/ (void *)primitiveFail,
	/* 546*/ (void *)primitiveFail,
	/* 547*/ (void *)primitiveFail,
	/* 548*/ (void *)primitiveFail,
	/* 549*/ (void *)primitiveFail,
	/* 550*/ (void *)primitiveFail,
	/* 551*/ (void *)primitiveFail,
	/* 552*/ (void *)primitiveFail,
	/* 553*/ (void *)primitiveFail,
	/* 554*/ (void *)primitiveFail,
	/* 555*/ (void *)primitiveFail,
	/* 556*/ (void *)primitiveFail,
	/* 557*/ (void *)primitiveFail,
	/* 558*/ (void *)primitiveFail,
	/* 559*/ (void *)primitiveFail,
	/* 560*/ (void *)primitiveFail,
	/* 561*/ (void *)primitiveFail,
	/* 562*/ (void *)primitiveFail,
	/* 563*/ (void *)primitiveFail,
	/* 564*/ (void *)primitiveFail,
	/* 565*/ (void *)primitiveFail,
	/* 566*/ (void *)primitiveFail,
	/* 567*/ (void *)primitiveFail,
	/* 568*/ (void *)primitiveFail,
	/* 569*/ (void *)primitiveFail,
	/* 570*/ (void *)primitiveFlushExternalPrimitives,
	/* 571*/ (void *)primitiveUnloadModule,
	/* 572*/ (void *)primitiveListBuiltinModule,
	/* 573*/ (void *)primitiveListExternalModule,
	/* 574*/ (void *)primitiveFail,
	/* 575*/ (void *)primitiveFail,
 0 };



/*	Return the accessible object following the given object or 
	free chunk in the heap. Return nil when heap is exhausted. */

sqInt accessibleObjectAfter(sqInt oop) {
register struct foo * foo = &fum;
    sqInt obj;
    sqInt sz;
    sqInt header;
    sqInt sz1;
    sqInt header1;

	/* begin objectAfter: */
	if (DoAssertionChecks) {
		if ((((usqInt) oop)) >= (((usqInt) foo->endOfMemory))) {
			error("no objects after the end of memory");
		}
	}
	if (((longAt(oop)) & TypeMask) == HeaderTypeFree) {
		sz1 = (longAt(oop)) & (ALL_BUT_TYPE_MASK);
	} else {
		/* begin sizeBitsOf: */
		header1 = longAt(oop);
		if ((header1 & TypeMask) == HeaderTypeSizeAndClass) {
			sz1 = (longAt(oop - ((BYTES_PER_WORD) * 2))) & (LONG_SIZE_MASK);
			goto l2;
		} else {
			sz1 = header1 & (SIZE_MASK);
			goto l2;
		}
	l2:	/* end sizeBitsOf: */;
	}
	obj = (oop + sz1) + (foo->headerTypeBytes[(longAt(oop + sz1)) & TypeMask]);
	while ((((usqInt) obj)) < (((usqInt) foo->endOfMemory))) {
		if (!(((longAt(obj)) & TypeMask) == HeaderTypeFree)) {
			return obj;
		}
		/* begin objectAfter: */
		if (DoAssertionChecks) {
			if ((((usqInt) obj)) >= (((usqInt) foo->endOfMemory))) {
				error("no objects after the end of memory");
			}
		}
		if (((longAt(obj)) & TypeMask) == HeaderTypeFree) {
			sz = (longAt(obj)) & (ALL_BUT_TYPE_MASK);
		} else {
			/* begin sizeBitsOf: */
			header = longAt(obj);
			if ((header & TypeMask) == HeaderTypeSizeAndClass) {
				sz = (longAt(obj - ((BYTES_PER_WORD) * 2))) & (LONG_SIZE_MASK);
				goto l1;
			} else {
				sz = header & (SIZE_MASK);
				goto l1;
			}
		l1:	/* end sizeBitsOf: */;
		}
		obj = (obj + sz) + (foo->headerTypeBytes[(longAt(obj + sz)) & TypeMask]);
	}
	return null;
}


/*	Similar to activateNewMethod but for Closure and newMethod. */

sqInt activateNewClosureMethod(sqInt blockClosure) {
register struct foo * foo = &fum;
    sqInt closureMethod;
    sqInt i;
    sqInt methodHeader;
    sqInt newContext;
    sqInt numCopied;
    sqInt outerContext;
    sqInt theBlockClosure;
    sqInt where;
    sqInt oop;
    sqInt activeCntx;
    sqInt valuePointer;
    sqInt valuePointer1;
    sqInt tmp;

	if (DoAssertionChecks) {
		okayOop(blockClosure);
	}
	outerContext = longAt((blockClosure + (BASE_HEADER_SIZE)) + (ClosureOuterContextIndex << (SHIFT_FOR_WORD)));
	if (DoAssertionChecks) {
		okayOop(outerContext);
	}
	closureMethod = longAt((outerContext + (BASE_HEADER_SIZE)) + (MethodIndex << (SHIFT_FOR_WORD)));
	methodHeader = longAt((closureMethod + (BASE_HEADER_SIZE)) + (HeaderIndex << (SHIFT_FOR_WORD)));
	/* begin pushRemappableOop: */
	foo->remapBuffer[(foo->remapBufferCount += 1)] = blockClosure;

	/* All for one, and one for all! */
	/* allocateOrRecycleContext: may cause a GC; restore blockClosure and refetch outerContext et al */

	newContext = allocateOrRecycleContext(methodHeader & LargeContextBit);
	/* begin popRemappableOop */
	oop = foo->remapBuffer[foo->remapBufferCount];
	foo->remapBufferCount -= 1;
	theBlockClosure = oop;
	outerContext = longAt((theBlockClosure + (BASE_HEADER_SIZE)) + (ClosureOuterContextIndex << (SHIFT_FOR_WORD)));

	/* Assume: newContext will be recorded as a root if necessary by the
	 call to newActiveContext: below, so we can use unchecked stores. */

	numCopied = (fetchWordLengthOf(theBlockClosure)) - ClosureFirstCopiedValueIndex;
	where = newContext + (BASE_HEADER_SIZE);
	longAtput(where + (SenderIndex << (SHIFT_FOR_WORD)), foo->activeContext);
	longAtput(where + (InstructionPointerIndex << (SHIFT_FOR_WORD)), longAt((theBlockClosure + (BASE_HEADER_SIZE)) + (ClosureStartPCIndex << (SHIFT_FOR_WORD))));
	longAtput(where + (StackPointerIndex << (SHIFT_FOR_WORD)), (((foo->argumentCount + numCopied) << 1) | 1));
	longAtput(where + (MethodIndex << (SHIFT_FOR_WORD)), longAt((outerContext + (BASE_HEADER_SIZE)) + (MethodIndex << (SHIFT_FOR_WORD))));
	longAtput(where + (ClosureIndex << (SHIFT_FOR_WORD)), theBlockClosure);
	longAtput(where + (ReceiverIndex << (SHIFT_FOR_WORD)), longAt((outerContext + (BASE_HEADER_SIZE)) + (ReceiverIndex << (SHIFT_FOR_WORD))));
	for (i = 1; i <= foo->argumentCount; i += 1) {
		longAtput(where + ((ReceiverIndex + i) << (SHIFT_FOR_WORD)), longAt(foo->stackPointer - ((foo->argumentCount - i) * (BYTES_PER_WORD))));
	}
	where = (newContext + (BASE_HEADER_SIZE)) + (((ReceiverIndex + 1) + foo->argumentCount) << (SHIFT_FOR_WORD));
	for (i = 0; i <= (numCopied - 1); i += 1) {
		longAtput(where + (i << (SHIFT_FOR_WORD)), longAt((theBlockClosure + (BASE_HEADER_SIZE)) + ((i + ClosureFirstCopiedValueIndex) << (SHIFT_FOR_WORD))));
	}
	/* begin pop: */
	foo->stackPointer -= (foo->argumentCount + 1) * (BYTES_PER_WORD);
	/* begin newActiveContext: */
	/* begin storeContextRegisters: */
	activeCntx = foo->activeContext;
	/* begin storePointerUnchecked:ofObject:withValue: */
	valuePointer = ((((foo->instructionPointer - foo->method) - ((BASE_HEADER_SIZE) - 2)) << 1) | 1);
	longAtput((activeCntx + (BASE_HEADER_SIZE)) + (InstructionPointerIndex << (SHIFT_FOR_WORD)), valuePointer);
	/* begin storePointerUnchecked:ofObject:withValue: */
	valuePointer1 = (((((((usqInt) ((foo->stackPointer - foo->activeContext) - (BASE_HEADER_SIZE))) >> (SHIFT_FOR_WORD)) - TempFrameStart) + 1) << 1) | 1);
	longAtput((activeCntx + (BASE_HEADER_SIZE)) + (StackPointerIndex << (SHIFT_FOR_WORD)), valuePointer1);
	if ((((usqInt) newContext)) < (((usqInt) foo->youngStart))) {
		beRootIfOld(newContext);
	}
	foo->activeContext = newContext;
	/* begin fetchContextRegisters: */
	tmp = longAt((newContext + (BASE_HEADER_SIZE)) + (MethodIndex << (SHIFT_FOR_WORD)));
	if ((tmp & 1)) {
		tmp = longAt((newContext + (BASE_HEADER_SIZE)) + (HomeIndex << (SHIFT_FOR_WORD)));
		if ((((usqInt) tmp)) < (((usqInt) foo->youngStart))) {
			beRootIfOld(tmp);
		}
	} else {
		tmp = newContext;
	}
	foo->theHomeContext = tmp;
	foo->receiver = longAt((tmp + (BASE_HEADER_SIZE)) + (ReceiverIndex << (SHIFT_FOR_WORD)));
	foo->method = longAt((tmp + (BASE_HEADER_SIZE)) + (MethodIndex << (SHIFT_FOR_WORD)));
	tmp = ((longAt((newContext + (BASE_HEADER_SIZE)) + (InstructionPointerIndex << (SHIFT_FOR_WORD)))) >> 1);
	foo->instructionPointer = ((foo->method + tmp) + (BASE_HEADER_SIZE)) - 2;
	tmp = ((longAt((newContext + (BASE_HEADER_SIZE)) + (StackPointerIndex << (SHIFT_FOR_WORD)))) >> 1);
	foo->stackPointer = (newContext + (BASE_HEADER_SIZE)) + (((TempFrameStart + tmp) - 1) * (BYTES_PER_WORD));
}

sqInt activateNewMethod(void) {
register struct foo * foo = &fum;
    sqInt i;
    sqInt initialIP;
    sqInt methodHeader;
    sqInt newContext;
    sqInt nilOop;
    sqInt tempCount;
    sqInt where;
    sqInt methodPointer;
    sqInt activeCntx;
    sqInt valuePointer;
    sqInt valuePointer1;
    sqInt tmp;

	/* begin headerOf: */
	methodPointer = foo->newMethod;
	methodHeader = longAt((methodPointer + (BASE_HEADER_SIZE)) + (HeaderIndex << (SHIFT_FOR_WORD)));
	newContext = allocateOrRecycleContext(methodHeader & LargeContextBit);
	initialIP = ((LiteralStart + ((((usqInt) methodHeader) >> 10) & 255)) * (BYTES_PER_WORD)) + 1;

	/* Assume: newContext will be recorded as a root if necessary by the
	 call to newActiveContext: below, so we can use unchecked stores. */

	tempCount = (((usqInt) methodHeader) >> 19) & 63;
	where = newContext + (BASE_HEADER_SIZE);
	longAtput(where + (SenderIndex << (SHIFT_FOR_WORD)), foo->activeContext);
	longAtput(where + (InstructionPointerIndex << (SHIFT_FOR_WORD)), ((initialIP << 1) | 1));
	longAtput(where + (StackPointerIndex << (SHIFT_FOR_WORD)), ((tempCount << 1) | 1));
	longAtput(where + (MethodIndex << (SHIFT_FOR_WORD)), foo->newMethod);
	longAtput(where + (ClosureIndex << (SHIFT_FOR_WORD)), foo->nilObj);
	for (i = 0; i <= foo->argumentCount; i += 1) {
		longAtput(where + ((ReceiverIndex + i) << (SHIFT_FOR_WORD)), longAt(foo->stackPointer - ((foo->argumentCount - i) * (BYTES_PER_WORD))));
	}
	nilOop = foo->nilObj;
	for (i = ((foo->argumentCount + 1) + ReceiverIndex); i <= (tempCount + ReceiverIndex); i += 1) {
		longAtput(where + (i << (SHIFT_FOR_WORD)), nilOop);
	}
	/* begin pop: */
	foo->stackPointer -= (foo->argumentCount + 1) * (BYTES_PER_WORD);
	foo->reclaimableContextCount += 1;
	/* begin newActiveContext: */
	/* begin storeContextRegisters: */
	activeCntx = foo->activeContext;
	/* begin storePointerUnchecked:ofObject:withValue: */
	valuePointer = ((((foo->instructionPointer - foo->method) - ((BASE_HEADER_SIZE) - 2)) << 1) | 1);
	longAtput((activeCntx + (BASE_HEADER_SIZE)) + (InstructionPointerIndex << (SHIFT_FOR_WORD)), valuePointer);
	/* begin storePointerUnchecked:ofObject:withValue: */
	valuePointer1 = (((((((usqInt) ((foo->stackPointer - foo->activeContext) - (BASE_HEADER_SIZE))) >> (SHIFT_FOR_WORD)) - TempFrameStart) + 1) << 1) | 1);
	longAtput((activeCntx + (BASE_HEADER_SIZE)) + (StackPointerIndex << (SHIFT_FOR_WORD)), valuePointer1);
	if ((((usqInt) newContext)) < (((usqInt) foo->youngStart))) {
		beRootIfOld(newContext);
	}
	foo->activeContext = newContext;
	/* begin fetchContextRegisters: */
	tmp = longAt((newContext + (BASE_HEADER_SIZE)) + (MethodIndex << (SHIFT_FOR_WORD)));
	if ((tmp & 1)) {
		tmp = longAt((newContext + (BASE_HEADER_SIZE)) + (HomeIndex << (SHIFT_FOR_WORD)));
		if ((((usqInt) tmp)) < (((usqInt) foo->youngStart))) {
			beRootIfOld(tmp);
		}
	} else {
		tmp = newContext;
	}
	foo->theHomeContext = tmp;
	foo->receiver = longAt((tmp + (BASE_HEADER_SIZE)) + (ReceiverIndex << (SHIFT_FOR_WORD)));
	foo->method = longAt((tmp + (BASE_HEADER_SIZE)) + (MethodIndex << (SHIFT_FOR_WORD)));
	tmp = ((longAt((newContext + (BASE_HEADER_SIZE)) + (InstructionPointerIndex << (SHIFT_FOR_WORD)))) >> 1);
	foo->instructionPointer = ((foo->method + tmp) + (BASE_HEADER_SIZE)) - 2;
	tmp = ((longAt((newContext + (BASE_HEADER_SIZE)) + (StackPointerIndex << (SHIFT_FOR_WORD)))) >> 1);
	foo->stackPointer = (newContext + (BASE_HEADER_SIZE)) + (((TempFrameStart + tmp) - 1) * (BYTES_PER_WORD));
}


/*	Add the given variable location to the extra roots table */

EXPORT(sqInt) addGCRoot(sqInt *varLoc) {
register struct foo * foo = &fum;
	if (foo->extraRootCount >= ExtraRootSize) {
		return 0;
	}
	foo->extraRoots[(foo->extraRootCount += 1)] = varLoc;
	return 1;
}


/*	Add the given entry to the method cache.
	The policy is as follows:
		Look for an empty entry anywhere in the reprobe chain.
		If found, install the new entry there.
		If not found, then install the new entry at the first probe position
			and delete the entries in the rest of the reprobe chain.
		This has two useful purposes:
			If there is active contention over the first slot, the second
				or third will likely be free for reentry after ejection.
			Also, flushing is good when reprobe chains are getting full. */

sqInt addNewMethodToCache(void) {
register struct foo * foo = &fum;
    sqInt hash;
    sqInt p;
    sqInt probe;

	foo->compilerInitialized && (compilerTranslateMethod());

	/* drop low-order zeros from addresses */

	hash = foo->messageSelector ^ foo->lkupClass;
	foo->primitiveFunctionPointer = primitiveTable[foo->primitiveIndex];
	for (p = 0; p <= (CacheProbeMax - 1); p += 1) {
		probe = (((usqInt) hash) >> p) & MethodCacheMask;
		if ((foo->methodCache[probe + MethodCacheSelector]) == 0) {
			foo->methodCache[probe + MethodCacheSelector] = foo->messageSelector;
			foo->methodCache[probe + MethodCacheClass] = foo->lkupClass;
			foo->methodCache[probe + MethodCacheMethod] = foo->newMethod;
			foo->methodCache[probe + MethodCachePrim] = foo->primitiveIndex;
			foo->methodCache[probe + MethodCacheNative] = foo->newNativeMethod;
			foo->methodCache[probe + MethodCachePrimFunction] = (((long) foo->primitiveFunctionPointer));
			return null;
		}
	}

	/* first probe */

	probe = hash & MethodCacheMask;
	foo->methodCache[probe + MethodCacheSelector] = foo->messageSelector;
	foo->methodCache[probe + MethodCacheClass] = foo->lkupClass;
	foo->methodCache[probe + MethodCacheMethod] = foo->newMethod;
	foo->methodCache[probe + MethodCachePrim] = foo->primitiveIndex;
	foo->methodCache[probe + MethodCacheNative] = foo->newNativeMethod;
	foo->methodCache[probe + MethodCachePrimFunction] = (((long) foo->primitiveFunctionPointer));
	for (p = 1; p <= (CacheProbeMax - 1); p += 1) {
		probe = (((usqInt) hash) >> p) & MethodCacheMask;
		foo->methodCache[probe + MethodCacheSelector] = 0;
	}
}


/*	Add the given function address to the external primitive table and return the index where it's stored. This function doesn't need to be fast since it is only called when an external primitive has been looked up (which takes quite a bit of time itself). So there's nothing specifically complicated here.
	Note: Return index will be one-based (ST convention) */

sqInt addToExternalPrimitiveTable(void *functionAddress) {
register struct foo * foo = &fum;
    sqInt i;

	for (i = 0; i <= (MaxExternalPrimitiveTableSize - 1); i += 1) {
		if ((foo->externalPrimitiveTable[i]) == 0) {
			foo->externalPrimitiveTable[i] = functionAddress;
			return i + 1;
		}
	}
	return 0;
}


/*	Adjust all oop references by the given number of bytes. This 
	is done just after reading in an image when the new base 
	address of the object heap is different from the base address 
	in the image. */
/*	di 11/18/2000 - return number of objects found */

sqInt adjustAllOopsBy(sqInt bytesToShift) {
register struct foo * foo = &fum;
    sqInt oop;
    sqInt totalObjects;
    sqInt classHeader;
    sqInt fieldAddr;
    sqInt fieldOop;
    sqInt newClassOop;
    sqInt sz;
    sqInt header;

	if (bytesToShift == 0) {
		return 300000;
	}
	totalObjects = 0;
	oop = memory + (foo->headerTypeBytes[(longAt(memory)) & TypeMask]);
	while ((((usqInt) oop)) < (((usqInt) foo->endOfMemory))) {
		if (!(((longAt(oop)) & TypeMask) == HeaderTypeFree)) {
			totalObjects += 1;
			/* begin adjustFieldsAndClassOf:by: */
			if (bytesToShift == 0) {
				goto l1;
			}
			fieldAddr = oop + (lastPointerOf(oop));
			while ((((usqInt) fieldAddr)) > (((usqInt) oop))) {
				fieldOop = longAt(fieldAddr);
				if (!((fieldOop & 1))) {
					longAtput(fieldAddr, fieldOop + bytesToShift);
				}
				fieldAddr -= BYTES_PER_WORD;
			}
			if (((longAt(oop)) & TypeMask) != HeaderTypeShort) {
				classHeader = longAt(oop - (BYTES_PER_WORD));
				newClassOop = (classHeader & (ALL_BUT_TYPE_MASK)) + bytesToShift;
				longAtput(oop - (BYTES_PER_WORD), newClassOop | (classHeader & TypeMask));
			}
		l1:	/* end adjustFieldsAndClassOf:by: */;
		}
		/* begin objectAfter: */
		if (DoAssertionChecks) {
			if ((((usqInt) oop)) >= (((usqInt) foo->endOfMemory))) {
				error("no objects after the end of memory");
			}
		}
		if (((longAt(oop)) & TypeMask) == HeaderTypeFree) {
			sz = (longAt(oop)) & (ALL_BUT_TYPE_MASK);
		} else {
			/* begin sizeBitsOf: */
			header = longAt(oop);
			if ((header & TypeMask) == HeaderTypeSizeAndClass) {
				sz = (longAt(oop - ((BYTES_PER_WORD) * 2))) & (LONG_SIZE_MASK);
				goto l2;
			} else {
				sz = header & (SIZE_MASK);
				goto l2;
			}
		l2:	/* end sizeBitsOf: */;
		}
		oop = (oop + sz) + (foo->headerTypeBytes[(longAt(oop + sz)) & TypeMask]);
	}
	return totalObjects;
}


/*	Return true if all the oops in both arrays, and the arrays 
	themselves, are in the young object space. */

sqInt allYoungand(sqInt array1, sqInt array2) {
register struct foo * foo = &fum;
    sqInt fieldOffset;
    sqInt contextSize;
    sqInt fmt;
    sqInt header;
    sqInt methodHeader;
    sqInt sz;
    sqInt sp;
    sqInt header1;
    sqInt type;

	if ((((usqInt) array1)) < (((usqInt) foo->youngStart))) {
		return 0;
	}
	if ((((usqInt) array2)) < (((usqInt) foo->youngStart))) {
		return 0;
	}
	/* begin lastPointerOf: */
	header = longAt(array1);
	fmt = (((usqInt) header) >> 8) & 15;
	if (fmt <= 4) {
		if ((fmt == 3) && ((((((usqInt) header) >> 12) & 31) == 13) || ((((((usqInt) header) >> 12) & 31) == 14) || (((((usqInt) header) >> 12) & 31) == 4)))) {
			/* begin fetchStackPointerOf: */
			sp = longAt((array1 + (BASE_HEADER_SIZE)) + (StackPointerIndex << (SHIFT_FOR_WORD)));
			if (!((sp & 1))) {
				contextSize = 0;
				goto l1;
			}
			contextSize = (sp >> 1);
		l1:	/* end fetchStackPointerOf: */;
			fieldOffset = (CtxtTempFrameStart + contextSize) * (BYTES_PER_WORD);
			goto l2;
		}
		/* begin sizeBitsOfSafe: */
		header1 = longAt(array1);
		/* begin rightType: */
		if ((header1 & (SIZE_MASK)) == 0) {
			type = HeaderTypeSizeAndClass;
			goto l3;
		} else {
			if ((header1 & CompactClassMask) == 0) {
				type = HeaderTypeClass;
				goto l3;
			} else {
				type = HeaderTypeShort;
				goto l3;
			}
		}
	l3:	/* end rightType: */;
		if (type == HeaderTypeSizeAndClass) {
			sz = (longAt(array1 - ((BYTES_PER_WORD) * 2))) & (ALL_BUT_TYPE_MASK);
			goto l4;
		} else {
			sz = header1 & (SIZE_MASK);
			goto l4;
		}
	l4:	/* end sizeBitsOfSafe: */;
		fieldOffset = sz - (BASE_HEADER_SIZE);
		goto l2;
	}
	if (fmt < 12) {
		fieldOffset = 0;
		goto l2;
	}
	methodHeader = longAt(array1 + (BASE_HEADER_SIZE));
	fieldOffset = (((((usqInt) methodHeader) >> 10) & 255) * (BYTES_PER_WORD)) + (BASE_HEADER_SIZE);
l2:	/* end lastPointerOf: */;
	while (fieldOffset >= (BASE_HEADER_SIZE)) {
		if ((((usqInt) (longAt(array1 + fieldOffset)))) < (((usqInt) foo->youngStart))) {
			return 0;
		}
		if ((((usqInt) (longAt(array2 + fieldOffset)))) < (((usqInt) foo->youngStart))) {
			return 0;
		}
		fieldOffset -= BYTES_PER_WORD;
	}
	return 1;
}


/*	Allocate a chunk of the given size. Sender must be sure that  the requested size includes enough space for the header  word(s).  */
/*	Details: To limit the time per incremental GC, do one every so many allocations. The number is settable via primitiveVMParameter to tune your memory system */

sqInt allocateChunk(sqInt byteSize) {
register struct foo * foo = &fum;
    sqInt enoughSpace;
    sqInt newChunk;
    sqInt newFreeSize;
    usqInt minFree;
    sqInt currentProc;
    sqInt lastSavedProcess;
    sqInt sched;
    sqInt oop;
    sqInt oop1;
    sqInt oop2;
    sqInt oop3;

	if (foo->allocationCount >= foo->allocationsBetweenGCs) {
		incrementalGC();
	}
	/* begin sufficientSpaceToAllocate: */
	minFree = (foo->lowSpaceThreshold + byteSize) + (BASE_HEADER_SIZE);
	if (oopisGreaterThanOrEqualTo((longAt(foo->freeBlock)) & (ALL_BUT_TYPE_MASK), minFree)) {
		enoughSpace = 1;
		goto l1;
	} else {
		enoughSpace = sufficientSpaceAfterGC(minFree);
		goto l1;
	}
l1:	/* end sufficientSpaceToAllocate: */;
	if (!(enoughSpace)) {

		/* signal that space is running low, but proceed with allocation if possible */

		foo->signalLowSpace = 1;

		/* disable additional interrupts until lowSpaceThreshold is reset by image */

		foo->lowSpaceThreshold = 0;
		/* begin saveProcessSignalingLowSpace */
		/* begin fetchPointer:ofObject: */
		oop2 = foo->specialObjectsOop;
		lastSavedProcess = longAt((oop2 + (BASE_HEADER_SIZE)) + (ProcessSignalingLowSpace << (SHIFT_FOR_WORD)));
		if (lastSavedProcess == foo->nilObj) {
			/* begin fetchPointer:ofObject: */
			/* begin fetchPointer:ofObject: */
			oop3 = foo->specialObjectsOop;
			oop = longAt((oop3 + (BASE_HEADER_SIZE)) + (SchedulerAssociation << (SHIFT_FOR_WORD)));
			sched = longAt((oop + (BASE_HEADER_SIZE)) + (ValueIndex << (SHIFT_FOR_WORD)));
			currentProc = longAt((sched + (BASE_HEADER_SIZE)) + (ActiveProcessIndex << (SHIFT_FOR_WORD)));
			/* begin storePointer:ofObject:withValue: */
			oop1 = foo->specialObjectsOop;
			if ((((usqInt) oop1)) < (((usqInt) foo->youngStart))) {
				possibleRootStoreIntovalue(oop1, currentProc);
			}
			longAtput((oop1 + (BASE_HEADER_SIZE)) + (ProcessSignalingLowSpace << (SHIFT_FOR_WORD)), currentProc);
		}
		/* begin forceInterruptCheck */
		foo->interruptCheckCounter = -1000;
		foo->nextPollTick = 0;
	}
	if (oopisLessThan((longAt(foo->freeBlock)) & (ALL_BUT_TYPE_MASK), byteSize + (BASE_HEADER_SIZE))) {
		error("out of memory");
	}
	newFreeSize = ((longAt(foo->freeBlock)) & (ALL_BUT_TYPE_MASK)) - byteSize;
	newChunk = foo->freeBlock;

	/* Assume: client will initialize object header of free chunk, so following is not needed: */
	/* self setSizeOfFree: newChunk to: byteSize. */

	foo->freeBlock += byteSize;
	/* begin setSizeOfFree:to: */
	longAtput(foo->freeBlock, (newFreeSize & (ALL_BUT_TYPE_MASK)) | HeaderTypeFree);
	foo->allocationCount += 1;
	return newChunk;
}


/*	Return a recycled context or a newly allocated one if none is available for recycling. */

sqInt allocateOrRecycleContext(sqInt needsLarge) {
register struct foo * foo = &fum;
    sqInt cntxt;
    sqInt valuePointer;

	if (needsLarge == 0) {
		if (foo->freeContexts != NilContext) {
			cntxt = foo->freeContexts;
			foo->freeContexts = longAt((cntxt + (BASE_HEADER_SIZE)) + (0 << (SHIFT_FOR_WORD)));
			return cntxt;
		}
	} else {
		if (foo->freeLargeContexts != NilContext) {
			cntxt = foo->freeLargeContexts;
			foo->freeLargeContexts = longAt((cntxt + (BASE_HEADER_SIZE)) + (0 << (SHIFT_FOR_WORD)));
			return cntxt;
		}
	}
	if (needsLarge == 0) {
		cntxt = instantiateContextsizeInBytes(fetchPointerofObject(ClassMethodContext, foo->specialObjectsOop), SMALL_CONTEXT_SIZE);
	} else {
		cntxt = instantiateContextsizeInBytes(fetchPointerofObject(ClassMethodContext, foo->specialObjectsOop), LARGE_CONTEXT_SIZE);
	}
	/* begin storePointerUnchecked:ofObject:withValue: */
	valuePointer = foo->nilObj;
	longAtput((cntxt + (BASE_HEADER_SIZE)) + (4 << (SHIFT_FOR_WORD)), valuePointer);
	return cntxt;
}

sqInt argumentCountOf(sqInt methodPointer) {
	return (((usqInt) (longAt((methodPointer + (BASE_HEADER_SIZE)) + (HeaderIndex << (SHIFT_FOR_WORD))))) >> 25) & 15;
}


/*	Return the address of first indexable field of resulting array object, or fail if the instance variable does not contain an indexable bytes or words object. */
/*	Note: May be called by translated primitive code. */

void * arrayValueOf(sqInt arrayOop) {
	if ((!((arrayOop & 1))) && (((arrayOop & 1) == 0) && (isWordsOrBytesNonInt(arrayOop)))) {
		return pointerForOop(arrayOop + (BASE_HEADER_SIZE));
	}
	/* begin primitiveFail */
	foo->successFlag = 0;
}


/*	Returns an integer object */

sqInt asciiOfCharacter(sqInt characterObj) {
register struct foo * foo = &fum;
    sqInt classOop;
    sqInt ccIndex;
    sqInt cl;
    sqInt oop1;
    sqInt oop2;
    sqInt oop;

	/* begin assertClassOf:is: */
	/* begin fetchPointer:ofObject: */
	oop = foo->specialObjectsOop;
	classOop = longAt((oop + (BASE_HEADER_SIZE)) + (ClassCharacter << (SHIFT_FOR_WORD)));
	if ((characterObj & 1)) {
		foo->successFlag = 0;
		goto l1;
	}
	ccIndex = (((usqInt) (longAt(characterObj))) >> 12) & 31;
	if (ccIndex == 0) {
		cl = (longAt(characterObj - (BASE_HEADER_SIZE))) & (ALL_BUT_TYPE_MASK);
	} else {
		/* begin fetchPointer:ofObject: */
		/* begin fetchPointer:ofObject: */
		oop2 = foo->specialObjectsOop;
		oop1 = longAt((oop2 + (BASE_HEADER_SIZE)) + (CompactClasses << (SHIFT_FOR_WORD)));
		cl = longAt((oop1 + (BASE_HEADER_SIZE)) + ((ccIndex - 1) << (SHIFT_FOR_WORD)));
	}
	/* begin success: */
	foo->successFlag = (cl == classOop) && foo->successFlag;
l1:	/* end assertClassOf:is: */;
	if (foo->successFlag) {
		return longAt((characterObj + (BASE_HEADER_SIZE)) + (CharacterValueIndex << (SHIFT_FOR_WORD)));
	} else {
		return ConstZero;
	}
}


/*	Return true if the stack is still balanced after executing primitive primIndex with nArgs args. Delta is 'stackPointer - activeContext' which is a relative measure for the stack pointer (so we don't have to relocate it during the primitive) */

sqInt balancedStackafterPrimitivewithArgs(sqInt delta, sqInt primIdx, sqInt nArgs) {
register struct foo * foo = &fum;
	if ((primIdx >= 81) && (primIdx <= 88)) {
		return 1;
	}
	if (foo->successFlag) {
		return ((foo->stackPointer - foo->activeContext) + (nArgs * (BYTES_PER_WORD))) == delta;
	}
	return (foo->stackPointer - foo->activeContext) == delta;
}


/*	Answer the size of an object memory header word in bytes. */

sqInt baseHeaderSize(void) {
	return BASE_HEADER_SIZE;
}


/*	If this object is old, mark it as a root (because a new object 
	may be stored into it) */

sqInt beRootIfOld(sqInt oop) {
register struct foo * foo = &fum;
    sqInt header;

	if (((((usqInt) oop)) < (((usqInt) foo->youngStart))) && (!((oop & 1)))) {
		/* begin noteAsRoot:headerLoc: */
		header = longAt(oop);
		if ((header & (ROOT_BIT)) == 0) {
			if (foo->rootTableCount < RootTableRedZone) {
				foo->rootTableCount += 1;
				foo->rootTable[foo->rootTableCount] = oop;
				longAtput(oop, header | (ROOT_BIT));
			} else {
				if (foo->rootTableCount < RootTableSize) {
					foo->rootTableCount += 1;
					foo->rootTable[foo->rootTableCount] = oop;
					longAtput(oop, header | (ROOT_BIT));
					foo->allocationCount = foo->allocationsBetweenGCs + 1;
				}
			}
		}
	}
}


/*	Record that the given oop in the old object area points to an object in the young area when oop may be forwarded. */
/*	Warning: No young objects should be recorded as roots. Callers are responsible for ensuring this constraint is not violated. */

sqInt beRootWhileForwarding(sqInt oop) {
register struct foo * foo = &fum;
    sqInt fwdBlock;
    sqInt header;
    sqInt header1;
    sqInt header2;

	header = longAt(oop);
	if ((header & (MARK_BIT)) != 0) {

		/* This oop is forwarded */

		fwdBlock = (header & (ALL_BUT_MARK_BIT_AND_TYPE_MASK)) << 1;
		if (DoAssertionChecks) {
			/* begin fwdBlockValidate: */
			if (!(((((usqInt) fwdBlock)) > (((usqInt) foo->endOfMemory))) && (((((usqInt) fwdBlock)) <= (((usqInt) foo->fwdTableNext))) && ((fwdBlock & 3) == 0)))) {
				error("invalid fwd table entry");
			}
		}
		/* begin noteAsRoot:headerLoc: */
		header1 = longAt(fwdBlock + (BYTES_PER_WORD));
		if ((header1 & (ROOT_BIT)) == 0) {
			if (foo->rootTableCount < RootTableRedZone) {
				foo->rootTableCount += 1;
				foo->rootTable[foo->rootTableCount] = oop;
				longAtput(fwdBlock + (BYTES_PER_WORD), header1 | (ROOT_BIT));
			} else {
				if (foo->rootTableCount < RootTableSize) {
					foo->rootTableCount += 1;
					foo->rootTable[foo->rootTableCount] = oop;
					longAtput(fwdBlock + (BYTES_PER_WORD), header1 | (ROOT_BIT));
					foo->allocationCount = foo->allocationsBetweenGCs + 1;
				}
			}
		}
	} else {
		/* begin noteAsRoot:headerLoc: */
		header2 = longAt(oop);
		if ((header2 & (ROOT_BIT)) == 0) {
			if (foo->rootTableCount < RootTableRedZone) {
				foo->rootTableCount += 1;
				foo->rootTable[foo->rootTableCount] = oop;
				longAtput(oop, header2 | (ROOT_BIT));
			} else {
				if (foo->rootTableCount < RootTableSize) {
					foo->rootTableCount += 1;
					foo->rootTable[foo->rootTableCount] = oop;
					longAtput(oop, header2 | (ROOT_BIT));
					foo->allocationCount = foo->allocationsBetweenGCs + 1;
				}
			}
		}
	}
}

sqInt becomewith(sqInt array1, sqInt array2) {
	return becomewithtwoWaycopyHash(array1, array2, 1, 1);
}


/*	All references to each object in array1 are swapped with all references to the corresponding object in array2. That is, all pointers to one object are replaced with with pointers to the other. The arguments must be arrays of the same length. 
	Returns true if the primitive succeeds. */
/*	Implementation: Uses forwarding blocks to update references as done in compaction. */

sqInt becomewithtwoWaycopyHash(sqInt array1, sqInt array2, sqInt twoWayFlag, sqInt copyHashFlag) {
register struct foo * foo = &fum;
    sqInt fieldOffset;
    sqInt hdr1;
    sqInt hdr2;
    sqInt oop1;
    sqInt oop2;
    sqInt fwdBlock;
    sqInt hdr11;
    sqInt hdr21;
    sqInt oop11;
    sqInt oop21;
    sqInt contextSize;
    sqInt fmt;
    sqInt header;
    sqInt methodHeader;
    sqInt sz;
    sqInt sp;
    sqInt header1;
    sqInt type;

	if (!(((array1 & 1) == 0) && (((((usqInt) (longAt(array1))) >> 8) & 15) == 2))) {
		return 0;
	}
	if (!(((array2 & 1) == 0) && (((((usqInt) (longAt(array2))) >> 8) & 15) == 2))) {
		return 0;
	}
	if (!((lastPointerOf(array1)) == (lastPointerOf(array2)))) {
		return 0;
	}
	if (!(containOnlyOopsand(array1, array2))) {
		return 0;
	}
	if (!(prepareForwardingTableForBecomingwithtwoWay(array1, array2, twoWayFlag))) {
		return 0;
	}
	if (allYoungand(array1, array2)) {
		mapPointersInObjectsFromto(foo->youngStart, foo->endOfMemory);
	} else {
		mapPointersInObjectsFromto(memory, foo->endOfMemory);
	}
	if (twoWayFlag) {
		/* begin restoreHeadersAfterBecoming:with: */
		/* begin lastPointerOf: */
		header = longAt(array1);
		fmt = (((usqInt) header) >> 8) & 15;
		if (fmt <= 4) {
			if ((fmt == 3) && ((((((usqInt) header) >> 12) & 31) == 13) || ((((((usqInt) header) >> 12) & 31) == 14) || (((((usqInt) header) >> 12) & 31) == 4)))) {
				/* begin fetchStackPointerOf: */
				sp = longAt((array1 + (BASE_HEADER_SIZE)) + (StackPointerIndex << (SHIFT_FOR_WORD)));
				if (!((sp & 1))) {
					contextSize = 0;
					goto l1;
				}
				contextSize = (sp >> 1);
			l1:	/* end fetchStackPointerOf: */;
				fieldOffset = (CtxtTempFrameStart + contextSize) * (BYTES_PER_WORD);
				goto l2;
			}
			/* begin sizeBitsOfSafe: */
			header1 = longAt(array1);
			/* begin rightType: */
			if ((header1 & (SIZE_MASK)) == 0) {
				type = HeaderTypeSizeAndClass;
				goto l3;
			} else {
				if ((header1 & CompactClassMask) == 0) {
					type = HeaderTypeClass;
					goto l3;
				} else {
					type = HeaderTypeShort;
					goto l3;
				}
			}
		l3:	/* end rightType: */;
			if (type == HeaderTypeSizeAndClass) {
				sz = (longAt(array1 - ((BYTES_PER_WORD) * 2))) & (ALL_BUT_TYPE_MASK);
				goto l4;
			} else {
				sz = header1 & (SIZE_MASK);
				goto l4;
			}
		l4:	/* end sizeBitsOfSafe: */;
			fieldOffset = sz - (BASE_HEADER_SIZE);
			goto l2;
		}
		if (fmt < 12) {
			fieldOffset = 0;
			goto l2;
		}
		methodHeader = longAt(array1 + (BASE_HEADER_SIZE));
		fieldOffset = (((((usqInt) methodHeader) >> 10) & 255) * (BYTES_PER_WORD)) + (BASE_HEADER_SIZE);
	l2:	/* end lastPointerOf: */;
		while (fieldOffset >= (BASE_HEADER_SIZE)) {
			oop1 = longAt(array1 + fieldOffset);
			oop2 = longAt(array2 + fieldOffset);
			if (!(oop1 == oop2)) {
				restoreHeaderOf(oop1);
				restoreHeaderOf(oop2);
				hdr1 = longAt(oop1);
				hdr2 = longAt(oop2);
				longAtput(oop1, (hdr1 & (ALL_BUT_HASH_BITS)) | (hdr2 & HashBits));
				longAtput(oop2, (hdr2 & (ALL_BUT_HASH_BITS)) | (hdr1 & HashBits));
			}
			fieldOffset -= BYTES_PER_WORD;
		}
	} else {
		/* begin restoreHeadersAfterForwardBecome: */
		fwdBlock = ((foo->endOfMemory + (BASE_HEADER_SIZE)) + 7) & ((WORD_MASK) - 7);
		flag("Dan");
		fwdBlock += (BYTES_PER_WORD) * 4;
		while ((((usqInt) fwdBlock)) <= (((usqInt) foo->fwdTableNext))) {
			oop11 = longAt(fwdBlock + ((BYTES_PER_WORD) * 2));
			oop21 = longAt(fwdBlock);
			restoreHeaderOf(oop11);
			if (copyHashFlag) {
				hdr11 = longAt(oop11);
				hdr21 = longAt(oop21);
				longAtput(oop21, (hdr21 & (ALL_BUT_HASH_BITS)) | (hdr11 & HashBits));
			}
			fwdBlock += (BYTES_PER_WORD) * 4;
		}
	}
	initializeMemoryFirstFree(foo->freeBlock);
	/* begin forceInterruptCheck */
	foo->interruptCheckCounter = -1000;
	foo->nextPollTick = 0;
	return 1;
}

sqInt biasToGrow(void) {
register struct foo * foo = &fum;
    usqInt growSize;

	growSize = (((sqInt) (foo->growHeadroom * 3) >> 1)) - ((longAt(foo->freeBlock)) & (ALL_BUT_TYPE_MASK));
	if (growSize > 0) {
		growObjectMemory(growSize);
	}
}


/*	convert true and false (Smalltalk) to true or false(C) */

sqInt booleanValueOf(sqInt obj) {
register struct foo * foo = &fum;
	if (obj == foo->trueObj) {
		return 1;
	}
	if (obj == foo->falseObj) {
		return 0;
	}
	foo->successFlag = 0;
	return null;
}

sqInt byteSizeOf(sqInt oop) {
    sqInt slots;
    sqInt header;
    sqInt sz;

	flag("Dan");
	if ((oop & 1)) {
		return 0;
	}
	/* begin slotSizeOf: */
	if ((oop & 1)) {
		slots = 0;
		goto l1;
	}
	/* begin lengthOf: */
	header = longAt(oop);
	/* begin lengthOf:baseHeader:format: */
	if ((header & TypeMask) == HeaderTypeSizeAndClass) {
		sz = (longAt(oop - ((BYTES_PER_WORD) * 2))) & (LONG_SIZE_MASK);
	} else {
		sz = header & (SIZE_MASK);
	}
	sz -= header & (SIZE_4_BIT);
	if (((((usqInt) header) >> 8) & 15) <= 4) {
		slots = ((usqInt) (sz - (BASE_HEADER_SIZE))) >> (SHIFT_FOR_WORD);
		goto l2;
	}
	if (((((usqInt) header) >> 8) & 15) < 8) {
		slots = ((usqInt) (sz - (BASE_HEADER_SIZE))) >> 2;
		goto l2;
	} else {
		slots = (sz - (BASE_HEADER_SIZE)) - (((((usqInt) header) >> 8) & 15) & 3);
		goto l2;
	}
l2:	/* end lengthOf:baseHeader:format: */;
l1:	/* end slotSizeOf: */;
	if (((((usqInt) (longAt(oop))) >> 8) & 15) >= 8) {
		return slots;
	} else {
		return slots * 4;
	}
}


/*	Byte-swap the words of all bytes objects in a range of the 
	image, including Strings, ByteArrays, and CompiledMethods. 
	This returns these objects to their original byte ordering 
	after blindly byte-swapping the entire image. For compiled 
	methods, byte-swap only their bytecodes part. */

sqInt byteSwapByteObjectsFromto(sqInt startOop, sqInt stopAddr) {
register struct foo * foo = &fum;
    sqInt fmt;
    sqInt methodHeader;
    sqInt oop;
    sqInt wordAddr;
    sqInt stopAddr1;
    sqInt addr;
    sqInt stopAddr2;
    sqInt addr1;
    sqInt sz;
    sqInt header;

	oop = startOop;
	while ((((usqInt) oop)) < (((usqInt) stopAddr))) {
		if (!(((longAt(oop)) & TypeMask) == HeaderTypeFree)) {
			fmt = (((usqInt) (longAt(oop))) >> 8) & 15;
			if (fmt >= 8) {

				/* oop contains bytes */

				wordAddr = oop + (BASE_HEADER_SIZE);
				if (fmt >= 12) {

					/* compiled method; start after methodHeader and literals */

					methodHeader = longAt(oop + (BASE_HEADER_SIZE));
					wordAddr = (wordAddr + (BYTES_PER_WORD)) + (((((usqInt) methodHeader) >> 10) & 255) * (BYTES_PER_WORD));
				}
				/* begin reverseBytesFrom:to: */
				stopAddr1 = oop + (sizeBitsOf(oop));
				flag("Dan");
				addr = wordAddr;
				while ((((usqInt) addr)) < (((usqInt) stopAddr1))) {
					longAtput(addr, byteSwapped(longAt(addr)));
					addr += BYTES_PER_WORD;
				}
			}
			if ((fmt == 6) && ((BYTES_PER_WORD) == 8)) {

				/* Object contains 32-bit half-words packed into 64-bit machine words. */

				wordAddr = oop + (BASE_HEADER_SIZE);
				/* begin reverseWordsFrom:to: */
				stopAddr2 = oop + (sizeBitsOf(oop));
				addr1 = wordAddr;
				while ((((usqInt) addr1)) < (((usqInt) stopAddr2))) {
					longAtput(addr1, wordSwapped(longAt(addr1)));
					addr1 += BYTES_PER_WORD;
				}
			}
		}
		/* begin objectAfter: */
		if (DoAssertionChecks) {
			if ((((usqInt) oop)) >= (((usqInt) foo->endOfMemory))) {
				error("no objects after the end of memory");
			}
		}
		if (((longAt(oop)) & TypeMask) == HeaderTypeFree) {
			sz = (longAt(oop)) & (ALL_BUT_TYPE_MASK);
		} else {
			/* begin sizeBitsOf: */
			header = longAt(oop);
			if ((header & TypeMask) == HeaderTypeSizeAndClass) {
				sz = (longAt(oop - ((BYTES_PER_WORD) * 2))) & (LONG_SIZE_MASK);
				goto l1;
			} else {
				sz = header & (SIZE_MASK);
				goto l1;
			}
		l1:	/* end sizeBitsOf: */;
		}
		oop = (oop + sz) + (foo->headerTypeBytes[(longAt(oop + sz)) & TypeMask]);
	}
}


/*	Answer the given integer with its bytes in the reverse order. */

sqInt byteSwapped(sqInt w) {
	
# if (BYTES_PER_WORD == 4)  // swap bytes in an object word
	return ((((((usqInt) w >> 24)) & Byte0Mask) + ((((usqInt) w >> 8)) & Byte1Mask)) + ((((usqInt) w << 8)) & Byte2Mask)) + ((((usqInt) w << 24)) & Byte3Mask);
# else
	return ((((((((((usqInt) w >> 56)) & Byte0Mask) + ((((usqInt) w >> 40)) & Byte1Mask)) + ((((usqInt) w >> 24)) & Byte2Mask)) + ((((usqInt) w >> 8)) & Byte3Mask)) + ((((usqInt) w << 8)) & Byte4Mask)) + ((((usqInt) w << 24)) & Byte5Mask)) + ((((usqInt) w << 40)) & Byte6Mask)) + ((((usqInt) w << 56)) & Byte7Mask);
# endif  // BYTES_PER_WORD == 4
	
}


/*	Answer the size of an object memory word in bytes. */

sqInt bytesPerWord(void) {
	return BYTES_PER_WORD;
}


/*	Call the external plugin function identified. In the VM this is an address, see 	InterpreterSimulator for it's version.  */

sqInt callExternalPrimitive(void *functionID) {
	dispatchFunctionPointer(functionID);
}


/*	External call into the interpreter */

EXPORT(sqInt) callInterpreter(void) {
	interpret();
}


/*	Re-enter the interpreter for executing a callback */

EXPORT(sqInt) callbackEnter(sqInt *callbackID) {
register struct foo * foo = &fum;
    sqInt activeProc;
    sqInt result;
    sqInt oop;
    sqInt oop1;
    sqInt oop2;
    sqInt oop3;
    sqInt oop4;
    sqInt oop5;
    sqInt priority;
    sqInt processList;
    sqInt processLists;
    sqInt oop6;
    sqInt oop11;
    sqInt lastLink;
    sqInt oop21;

	if (foo->primitiveIndex == 0) {
		return 0;
	}
	if (foo->jmpDepth >= foo->jmpMax) {
		return 0;
	}

	/* Suspend the currently active process */

	foo->jmpDepth += 1;
	/* begin fetchPointer:ofObject: */
	/* begin fetchPointer:ofObject: */
	/* begin fetchPointer:ofObject: */
	oop4 = foo->specialObjectsOop;
	oop2 = longAt((oop4 + (BASE_HEADER_SIZE)) + (SchedulerAssociation << (SHIFT_FOR_WORD)));
	oop = longAt((oop2 + (BASE_HEADER_SIZE)) + (ValueIndex << (SHIFT_FOR_WORD)));
	activeProc = longAt((oop + (BASE_HEADER_SIZE)) + (ActiveProcessIndex << (SHIFT_FOR_WORD)));
	foo->suspendedCallbacks[foo->jmpDepth] = activeProc;
	foo->suspendedMethods[foo->jmpDepth] = foo->newMethod;
	transferTo(wakeHighestPriority());
	/* begin forceInterruptCheck */
	foo->interruptCheckCounter = -1000;
	foo->nextPollTick = 0;
	result = setjmp(foo->jmpBuf[foo->jmpDepth]);
	if (result == 0) {
		callbackID[0] = foo->jmpDepth;
		interpret();
	}
	/* begin fetchPointer:ofObject: */
	/* begin fetchPointer:ofObject: */
	/* begin fetchPointer:ofObject: */
	oop5 = foo->specialObjectsOop;
	oop3 = longAt((oop5 + (BASE_HEADER_SIZE)) + (SchedulerAssociation << (SHIFT_FOR_WORD)));
	oop1 = longAt((oop3 + (BASE_HEADER_SIZE)) + (ValueIndex << (SHIFT_FOR_WORD)));
	activeProc = longAt((oop1 + (BASE_HEADER_SIZE)) + (ActiveProcessIndex << (SHIFT_FOR_WORD)));
	/* begin putToSleep: */
	priority = ((longAt((activeProc + (BASE_HEADER_SIZE)) + (PriorityIndex << (SHIFT_FOR_WORD)))) >> 1);
	/* begin fetchPointer:ofObject: */
	/* begin fetchPointer:ofObject: */
	/* begin fetchPointer:ofObject: */
	oop21 = foo->specialObjectsOop;
	oop11 = longAt((oop21 + (BASE_HEADER_SIZE)) + (SchedulerAssociation << (SHIFT_FOR_WORD)));
	oop6 = longAt((oop11 + (BASE_HEADER_SIZE)) + (ValueIndex << (SHIFT_FOR_WORD)));
	processLists = longAt((oop6 + (BASE_HEADER_SIZE)) + (ProcessListsIndex << (SHIFT_FOR_WORD)));
	processList = longAt((processLists + (BASE_HEADER_SIZE)) + ((priority - 1) << (SHIFT_FOR_WORD)));
	/* begin addLastLink:toList: */
	if ((longAt((processList + (BASE_HEADER_SIZE)) + (FirstLinkIndex << (SHIFT_FOR_WORD)))) == foo->nilObj) {
		/* begin storePointer:ofObject:withValue: */
		if ((((usqInt) processList)) < (((usqInt) foo->youngStart))) {
			possibleRootStoreIntovalue(processList, activeProc);
		}
		longAtput((processList + (BASE_HEADER_SIZE)) + (FirstLinkIndex << (SHIFT_FOR_WORD)), activeProc);
	} else {
		lastLink = longAt((processList + (BASE_HEADER_SIZE)) + (LastLinkIndex << (SHIFT_FOR_WORD)));
		/* begin storePointer:ofObject:withValue: */
		if ((((usqInt) lastLink)) < (((usqInt) foo->youngStart))) {
			possibleRootStoreIntovalue(lastLink, activeProc);
		}
		longAtput((lastLink + (BASE_HEADER_SIZE)) + (NextLinkIndex << (SHIFT_FOR_WORD)), activeProc);
	}
	/* begin storePointer:ofObject:withValue: */
	if ((((usqInt) processList)) < (((usqInt) foo->youngStart))) {
		possibleRootStoreIntovalue(processList, activeProc);
	}
	longAtput((processList + (BASE_HEADER_SIZE)) + (LastLinkIndex << (SHIFT_FOR_WORD)), activeProc);
	/* begin storePointer:ofObject:withValue: */
	if ((((usqInt) activeProc)) < (((usqInt) foo->youngStart))) {
		possibleRootStoreIntovalue(activeProc, processList);
	}
	longAtput((activeProc + (BASE_HEADER_SIZE)) + (MyListIndex << (SHIFT_FOR_WORD)), processList);
	activeProc = foo->suspendedCallbacks[foo->jmpDepth];

	/* see comment above */

	foo->newMethod = foo->suspendedMethods[foo->jmpDepth];
	transferTo(activeProc);
	foo->jmpDepth -= 1;
	return 1;
}


/*	Leave from a previous callback */
/*	For now, do not allow a callback unless we're in a primitiveResponse */

EXPORT(sqInt) callbackLeave(sqInt cbID) {
register struct foo * foo = &fum;
	if (foo->primitiveIndex == 0) {
		return 0;
	}
	if (!(cbID == foo->jmpDepth)) {
		return 0;
	}
	if (cbID < 1) {
		return 0;
	}
	longjmp(foo->jmpBuf[foo->jmpDepth], 1);
}


/*	Change the class of the receiver into the class specified by the argument given that the format of the receiver matches the format of the argument. Fail if receiver or argument are SmallIntegers, or the receiver is an instance of a compact class and the argument isn't, or when the argument's class is compact and the receiver isn't, or when the format of the receiver is different from the format of the argument's class, or when the arguments class is fixed and the receiver's size differs from the size that an instance of the argument's class should have. */
/*	Check what the format of the class says */

sqInt changeClassOfto(sqInt rcvr, sqInt argClass) {
register struct foo * foo = &fum;
    sqInt argFormat;
    sqInt byteSize;
    sqInt ccIndex;
    sqInt classHdr;
    sqInt rcvrFormat;
    sqInt sizeHiBits;
    sqInt i;
    sqInt i1;


	/* Low 2 bits are 0 */
	/* Compute the size of instances of the class (used for fixed field classes only) */

	classHdr = (longAt((argClass + (BASE_HEADER_SIZE)) + (InstanceSpecificationIndex << (SHIFT_FOR_WORD)))) - 1;
	sizeHiBits = ((usqInt) (classHdr & 393216)) >> 9;
	classHdr = classHdr & 131071;

	/* size in bytes -- low 2 bits are 0 */
	/* Check the receiver's format against that of the class */

	byteSize = (classHdr & (SIZE_MASK)) + sizeHiBits;
	argFormat = (((usqInt) classHdr) >> 8) & 15;
	rcvrFormat = (((usqInt) (longAt(rcvr))) >> 8) & 15;
	if (!(argFormat == rcvrFormat)) {
		/* begin primitiveFail */
		foo->successFlag = 0;
		return null;
	}
	if (argFormat < 2) {
		if (!((byteSize - (BASE_HEADER_SIZE)) == (byteSizeOf(rcvr)))) {
			/* begin primitiveFail */
			foo->successFlag = 0;
			return null;
		}
	}
	if (((longAt(rcvr)) & TypeMask) == HeaderTypeShort) {

		/* Compact classes. Check if the arg's class is compact and exchange ccIndex */

		ccIndex = classHdr & CompactClassMask;
		if (ccIndex == 0) {
			/* begin primitiveFail */
			foo->successFlag = 0;
			return null;
		}
		longAtput(rcvr, ((longAt(rcvr)) & (~CompactClassMask)) | ccIndex);
	} else {
		longAtput(rcvr - (BASE_HEADER_SIZE), argClass | ((longAt(rcvr)) & TypeMask));
		if ((((usqInt) rcvr)) < (((usqInt) foo->youngStart))) {
			possibleRootStoreIntovalue(rcvr, argClass);
		}
	}
	/* begin flushMethodCache */
	for (i = 1; i <= MethodCacheSize; i += 1) {
		foo->methodCache[i] = 0;
	}
	/* begin flushAtCache */
	for (i1 = 1; i1 <= AtCacheTotalSize; i1 += 1) {
		foo->atCache[i1] = 0;
	}
}


/*	Arg must lie in range 0-255! */

sqInt characterForAscii(sqInt ascii) {
    sqInt oop;
    sqInt oop1;

	/* begin fetchPointer:ofObject: */
	/* begin fetchPointer:ofObject: */
	oop1 = foo->specialObjectsOop;
	oop = longAt((oop1 + (BASE_HEADER_SIZE)) + (CharacterTable << (SHIFT_FOR_WORD)));
	return longAt((oop + (BASE_HEADER_SIZE)) + (ascii << (SHIFT_FOR_WORD)));
}

sqInt characterTable(void) {
    sqInt oop;

	/* begin fetchPointer:ofObject: */
	oop = foo->specialObjectsOop;
	return longAt((oop + (BASE_HEADER_SIZE)) + (CharacterTable << (SHIFT_FOR_WORD)));
}


/*	Check for possible interrupts and handle one if necessary. */

sqInt checkForInterrupts(void) {
register struct foo * foo = &fum;
    sqInt now;
    sqInt sema;
    sqInt oop;
    sqInt oop1;
    sqInt oop2;
    sqInt oop3;
    sqInt i;
    sqInt index;
    sqInt sema1;
    sqInt xArray;
    sqInt xSize;
    sqInt oop4;


	/* Mask so same wrapping as primitiveMillisecondClock */

	now = (ioMSecs()) & MillisecondClockMask;
	if (!(foo->interruptCheckCounter < -100)) {
		if ((now - foo->lastTick) < foo->interruptChecksEveryNms) {

			/* don't play with the feedback if we forced a check. It only makes life difficult */
			/* wrapping is not a concern, it'll get caught quickly  
				enough. This clause is trying to keep a reasonable  
				guess of how many times per 	interruptChecksEveryNms we are calling  
				quickCheckForInterrupts. Not sure how effective it really is. */

			foo->interruptCheckCounterFeedBackReset += 10;
		} else {
			if (foo->interruptCheckCounterFeedBackReset <= 1000) {
				foo->interruptCheckCounterFeedBackReset = 1000;
			} else {
				foo->interruptCheckCounterFeedBackReset -= 12;
			}
		}
	}
	foo->interruptCheckCounter = foo->interruptCheckCounterFeedBackReset;
	if (foo->signalLowSpace) {

		/* reset flag */

		foo->signalLowSpace = 0;
		/* begin fetchPointer:ofObject: */
		oop = foo->specialObjectsOop;
		sema = longAt((oop + (BASE_HEADER_SIZE)) + (TheLowSpaceSemaphore << (SHIFT_FOR_WORD)));
		if (!(sema == foo->nilObj)) {
			synchronousSignal(sema);
		}
	}
	if (now < foo->lastTick) {

		/* millisecond clock wrapped so correct the nextPollTick */

		foo->nextPollTick = (foo->nextPollTick - MillisecondClockMask) - 1;
	}
	if (now >= foo->nextPollTick) {
		ioProcessEvents();

		/* msecs to wait before next call to ioProcessEvents.  
			Note that strictly speaking we might need to update  
			'now' at this point since ioProcessEvents could take a  
			very long time on some platforms */

		foo->nextPollTick = now + 200;
	}
	if (foo->interruptPending) {

		/* reset interrupt flag */

		foo->interruptPending = 0;
		/* begin fetchPointer:ofObject: */
		oop1 = foo->specialObjectsOop;
		sema = longAt((oop1 + (BASE_HEADER_SIZE)) + (TheInterruptSemaphore << (SHIFT_FOR_WORD)));
		if (!(sema == foo->nilObj)) {
			synchronousSignal(sema);
		}
	}
	if (foo->nextWakeupTick != 0) {
		if (now < foo->lastTick) {

			/* the clock has wrapped. Subtract the wrap  
					interval from nextWakeupTick - this might just  
					possibly result in 0. Since this is used as a flag  
					value for 'no timer' we do the 0 check above */

			foo->nextWakeupTick = (foo->nextWakeupTick - MillisecondClockMask) - 1;
		}
		if (now >= foo->nextWakeupTick) {

			/* set timer interrupt to 0 for 'no timer' */

			foo->nextWakeupTick = 0;
			/* begin fetchPointer:ofObject: */
			oop2 = foo->specialObjectsOop;
			sema = longAt((oop2 + (BASE_HEADER_SIZE)) + (TheTimerSemaphore << (SHIFT_FOR_WORD)));
			if (!(sema == foo->nilObj)) {
				synchronousSignal(sema);
			}
		}
	}
	if (foo->pendingFinalizationSignals > 0) {
		/* begin fetchPointer:ofObject: */
		oop3 = foo->specialObjectsOop;
		sema = longAt((oop3 + (BASE_HEADER_SIZE)) + (TheFinalizationSemaphore << (SHIFT_FOR_WORD)));
		if ((fetchClassOf(sema)) == (fetchPointerofObject(ClassSemaphore, foo->specialObjectsOop))) {
			synchronousSignal(sema);
		}
		foo->pendingFinalizationSignals = 0;
	}
	if ((foo->semaphoresToSignalCountA > 0) || (foo->semaphoresToSignalCountB > 0)) {
		/* begin signalExternalSemaphores */
		foo->semaphoresUseBufferA = !foo->semaphoresUseBufferA;
		/* begin fetchPointer:ofObject: */
		oop4 = foo->specialObjectsOop;
		xArray = longAt((oop4 + (BASE_HEADER_SIZE)) + (ExternalObjectsArray << (SHIFT_FOR_WORD)));
		xSize = stSizeOf(xArray);
		if (foo->semaphoresUseBufferA) {
			for (i = 1; i <= foo->semaphoresToSignalCountB; i += 1) {
				index = foo->semaphoresToSignalB[i];
				if (index <= xSize) {
					sema1 = longAt((xArray + (BASE_HEADER_SIZE)) + ((index - 1) << (SHIFT_FOR_WORD)));
					if ((fetchClassOf(sema1)) == (fetchPointerofObject(ClassSemaphore, foo->specialObjectsOop))) {
						synchronousSignal(sema1);
					}
				}
			}
			foo->semaphoresToSignalCountB = 0;
		} else {
			for (i = 1; i <= foo->semaphoresToSignalCountA; i += 1) {
				index = foo->semaphoresToSignalA[i];
				if (index <= xSize) {
					sema1 = longAt((xArray + (BASE_HEADER_SIZE)) + ((index - 1) << (SHIFT_FOR_WORD)));
					if ((fetchClassOf(sema1)) == (fetchPointerofObject(ClassSemaphore, foo->specialObjectsOop))) {
						synchronousSignal(sema1);
					}
				}
			}
			foo->semaphoresToSignalCountA = 0;
		}
	}
	foo->lastTick = now;
}


/*	Read and verify the image file version number and return true if the the given image file needs to be byte-swapped. As a side effect, position the file stream just after the version number of the image header. This code prints a warning and does a hard-exit if it cannot find a valid version number. */
/*	This code is based on C code by Ian Piumarta. */

sqInt checkImageVersionFromstartingAt(sqImageFile  f, squeakFileOffsetType  imageOffset) {
    sqInt firstVersion;

	sqImageFileSeek(f, imageOffset);
	imageFormatInitialVersion = firstVersion = getLongFromFileswap(f, 0);
	if (readableFormat(imageFormatInitialVersion)) {
		return 0;
	}
	sqImageFileSeek(f, imageOffset);
	imageFormatInitialVersion = getLongFromFileswap(f, 1);
	if (readableFormat(imageFormatInitialVersion)) {
		return 1;
	}
	if (imageOffset == 0) {
		sqImageFileSeek(f, 512);
		imageFormatInitialVersion = getLongFromFileswap(f, 0);
		if (readableFormat(imageFormatInitialVersion)) {
			return 0;
		}
		sqImageFileSeek(f, 512);
		imageFormatInitialVersion = getLongFromFileswap(f, 1);
		if (readableFormat(imageFormatInitialVersion)) {
			return 1;
		}
	}
	print("This interpreter (vers. ");
	printNum(imageFormatVersionNumber);
	print(") cannot read image file (vers. ");
	printNum(firstVersion);
	print(").");
	/* begin cr */
	printf("\n");
	print("Press CR to quit...");
	getchar();
	ioExit();
}


/*	Note: May be called by translated primitive code. */

sqInt checkedIntegerValueOf(sqInt intOop) {
	if ((intOop & 1)) {
		return (intOop >> 1);
	} else {
		/* begin primitiveFail */
		foo->successFlag = 0;
		return 0;
	}
}


/*	Assumes zero-based array indexing. For testing in Smalltalk, this method should be overridden in a subclass. */

sqInt checkedLongAt(sqInt byteAddress) {
register struct foo * foo = &fum;
	/* begin checkAddress: */
	if ((((usqInt) byteAddress)) < (((usqInt) memory))) {
		error("bad address: negative");
	}
	if ((((usqInt) byteAddress)) >= (((usqInt) foo->memoryLimit))) {
		error("bad address: past end of heap");
	}
	/* begin checkAddress: */
	if ((((usqInt) (byteAddress + 3))) < (((usqInt) memory))) {
		error("bad address: negative");
	}
	if ((((usqInt) (byteAddress + 3))) >= (((usqInt) foo->memoryLimit))) {
		error("bad address: past end of heap");
	}
	return longAt(byteAddress);
}

sqInt classAlien(void) {
    sqInt oop;

	/* begin fetchPointer:ofObject: */
	oop = foo->specialObjectsOop;
	return longAt((oop + (BASE_HEADER_SIZE)) + (ClassAlien << (SHIFT_FOR_WORD)));
}

sqInt classArray(void) {
    sqInt oop;

	/* begin fetchPointer:ofObject: */
	oop = foo->specialObjectsOop;
	return longAt((oop + (BASE_HEADER_SIZE)) + (ClassArray << (SHIFT_FOR_WORD)));
}

sqInt classBitmap(void) {
    sqInt oop;

	/* begin fetchPointer:ofObject: */
	oop = foo->specialObjectsOop;
	return longAt((oop + (BASE_HEADER_SIZE)) + (ClassBitmap << (SHIFT_FOR_WORD)));
}

sqInt classByteArray(void) {
    sqInt oop;

	/* begin fetchPointer:ofObject: */
	oop = foo->specialObjectsOop;
	return longAt((oop + (BASE_HEADER_SIZE)) + (ClassByteArray << (SHIFT_FOR_WORD)));
}

sqInt classCharacter(void) {
    sqInt oop;

	/* begin fetchPointer:ofObject: */
	oop = foo->specialObjectsOop;
	return longAt((oop + (BASE_HEADER_SIZE)) + (ClassCharacter << (SHIFT_FOR_WORD)));
}

sqInt classExternalAddress(void) {
    sqInt oop;

	/* begin fetchPointer:ofObject: */
	oop = foo->specialObjectsOop;
	return longAt((oop + (BASE_HEADER_SIZE)) + (ClassExternalAddress << (SHIFT_FOR_WORD)));
}

sqInt classExternalData(void) {
    sqInt oop;

	/* begin fetchPointer:ofObject: */
	oop = foo->specialObjectsOop;
	return longAt((oop + (BASE_HEADER_SIZE)) + (ClassExternalData << (SHIFT_FOR_WORD)));
}

sqInt classExternalFunction(void) {
    sqInt oop;

	/* begin fetchPointer:ofObject: */
	oop = foo->specialObjectsOop;
	return longAt((oop + (BASE_HEADER_SIZE)) + (ClassExternalFunction << (SHIFT_FOR_WORD)));
}

sqInt classExternalLibrary(void) {
    sqInt oop;

	/* begin fetchPointer:ofObject: */
	oop = foo->specialObjectsOop;
	return longAt((oop + (BASE_HEADER_SIZE)) + (ClassExternalLibrary << (SHIFT_FOR_WORD)));
}

sqInt classExternalStructure(void) {
    sqInt oop;

	/* begin fetchPointer:ofObject: */
	oop = foo->specialObjectsOop;
	return longAt((oop + (BASE_HEADER_SIZE)) + (ClassExternalStructure << (SHIFT_FOR_WORD)));
}

sqInt classFloat(void) {
    sqInt oop;

	/* begin fetchPointer:ofObject: */
	oop = foo->specialObjectsOop;
	return longAt((oop + (BASE_HEADER_SIZE)) + (ClassFloat << (SHIFT_FOR_WORD)));
}

sqInt classLargeNegativeInteger(void) {
    sqInt oop;

	/* begin fetchPointer:ofObject: */
	oop = foo->specialObjectsOop;
	return longAt((oop + (BASE_HEADER_SIZE)) + (ClassLargeNegativeInteger << (SHIFT_FOR_WORD)));
}

sqInt classLargePositiveInteger(void) {
    sqInt oop;

	/* begin fetchPointer:ofObject: */
	oop = foo->specialObjectsOop;
	return longAt((oop + (BASE_HEADER_SIZE)) + (ClassLargePositiveInteger << (SHIFT_FOR_WORD)));
}


/*	Check if aClass's name is className */

sqInt classNameOfIs(sqInt aClass, char *className) {
    sqInt i;
    sqInt length;
    sqInt name;
    char *srcName;

	if ((lengthOf(aClass)) <= 6) {
		return 0;
	}
	name = longAt((aClass + (BASE_HEADER_SIZE)) + (6 << (SHIFT_FOR_WORD)));
	if (!(((name & 1) == 0) && (((((usqInt) (longAt(name))) >> 8) & 15) >= 8))) {
		return 0;
	}
	length = stSizeOf(name);
	srcName = ((char *) (arrayValueOf(name)));
	for (i = 0; i <= (length - 1); i += 1) {
		if (!((srcName[i]) == (className[i]))) {
			return 0;
		}
	}
	return (className[length]) == 0;
}

sqInt classPoint(void) {
    sqInt oop;

	/* begin fetchPointer:ofObject: */
	oop = foo->specialObjectsOop;
	return longAt((oop + (BASE_HEADER_SIZE)) + (ClassPoint << (SHIFT_FOR_WORD)));
}

sqInt classSemaphore(void) {
    sqInt oop;

	/* begin fetchPointer:ofObject: */
	oop = foo->specialObjectsOop;
	return longAt((oop + (BASE_HEADER_SIZE)) + (ClassSemaphore << (SHIFT_FOR_WORD)));
}

sqInt classSmallInteger(void) {
    sqInt oop;

	/* begin fetchPointer:ofObject: */
	oop = foo->specialObjectsOop;
	return longAt((oop + (BASE_HEADER_SIZE)) + (ClassInteger << (SHIFT_FOR_WORD)));
}

sqInt classString(void) {
    sqInt oop;

	/* begin fetchPointer:ofObject: */
	oop = foo->specialObjectsOop;
	return longAt((oop + (BASE_HEADER_SIZE)) + (ClassString << (SHIFT_FOR_WORD)));
}

sqInt classUnsafeAlien(void) {
    sqInt oop;

	/* begin fetchPointer:ofObject: */
	oop = foo->specialObjectsOop;
	return longAt((oop + (BASE_HEADER_SIZE)) + (ClassUnsafeAlien << (SHIFT_FOR_WORD)));
}


/*	Return a shallow copy of the given object. May cause GC */
/*	Assume: Oop is a real object, not a small integer. */

sqInt clone(sqInt oop) {
register struct foo * foo = &fum;
    usqInt bytes;
    sqInt extraHdrBytes;
    usqInt fromIndex;
    sqInt hash;
    sqInt header;
    usqInt lastFrom;
    sqInt newChunk;
    sqInt newOop;
    sqInt remappedOop;
    sqInt toIndex;
    sqInt header1;
    sqInt enoughSpace;
    sqInt newChunk1;
    sqInt newFreeSize;
    usqInt minFree;
    sqInt oop1;
    sqInt currentProc;
    sqInt lastSavedProcess;
    sqInt sched;
    sqInt oop4;
    sqInt oop11;
    sqInt oop2;
    sqInt oop3;

	extraHdrBytes = foo->headerTypeBytes[(longAt(oop)) & TypeMask];
	/* begin sizeBitsOf: */
	header1 = longAt(oop);
	if ((header1 & TypeMask) == HeaderTypeSizeAndClass) {
		bytes = (longAt(oop - ((BYTES_PER_WORD) * 2))) & (LONG_SIZE_MASK);
		goto l1;
	} else {
		bytes = header1 & (SIZE_MASK);
		goto l1;
	}
l1:	/* end sizeBitsOf: */;

	/* allocate space for the copy, remapping oop in case of a GC */

	bytes += extraHdrBytes;
	/* begin pushRemappableOop: */
	foo->remapBuffer[(foo->remapBufferCount += 1)] = oop;
	if (!(sufficientSpaceToAllocate(2500 + bytes))) {
		return 0;
	}
	/* begin allocateChunk: */
	if (foo->allocationCount >= foo->allocationsBetweenGCs) {
		incrementalGC();
	}
	/* begin sufficientSpaceToAllocate: */
	minFree = (foo->lowSpaceThreshold + bytes) + (BASE_HEADER_SIZE);
	if (oopisGreaterThanOrEqualTo((longAt(foo->freeBlock)) & (ALL_BUT_TYPE_MASK), minFree)) {
		enoughSpace = 1;
		goto l2;
	} else {
		enoughSpace = sufficientSpaceAfterGC(minFree);
		goto l2;
	}
l2:	/* end sufficientSpaceToAllocate: */;
	if (!(enoughSpace)) {
		foo->signalLowSpace = 1;
		foo->lowSpaceThreshold = 0;
		/* begin saveProcessSignalingLowSpace */
		/* begin fetchPointer:ofObject: */
		oop2 = foo->specialObjectsOop;
		lastSavedProcess = longAt((oop2 + (BASE_HEADER_SIZE)) + (ProcessSignalingLowSpace << (SHIFT_FOR_WORD)));
		if (lastSavedProcess == foo->nilObj) {
			/* begin fetchPointer:ofObject: */
			/* begin fetchPointer:ofObject: */
			oop3 = foo->specialObjectsOop;
			oop4 = longAt((oop3 + (BASE_HEADER_SIZE)) + (SchedulerAssociation << (SHIFT_FOR_WORD)));
			sched = longAt((oop4 + (BASE_HEADER_SIZE)) + (ValueIndex << (SHIFT_FOR_WORD)));
			currentProc = longAt((sched + (BASE_HEADER_SIZE)) + (ActiveProcessIndex << (SHIFT_FOR_WORD)));
			/* begin storePointer:ofObject:withValue: */
			oop11 = foo->specialObjectsOop;
			if ((((usqInt) oop11)) < (((usqInt) foo->youngStart))) {
				possibleRootStoreIntovalue(oop11, currentProc);
			}
			longAtput((oop11 + (BASE_HEADER_SIZE)) + (ProcessSignalingLowSpace << (SHIFT_FOR_WORD)), currentProc);
		}
		/* begin forceInterruptCheck */
		foo->interruptCheckCounter = -1000;
		foo->nextPollTick = 0;
	}
	if (oopisLessThan((longAt(foo->freeBlock)) & (ALL_BUT_TYPE_MASK), bytes + (BASE_HEADER_SIZE))) {
		error("out of memory");
	}
	newFreeSize = ((longAt(foo->freeBlock)) & (ALL_BUT_TYPE_MASK)) - bytes;
	newChunk1 = foo->freeBlock;
	foo->freeBlock += bytes;
	/* begin setSizeOfFree:to: */
	longAtput(foo->freeBlock, (newFreeSize & (ALL_BUT_TYPE_MASK)) | HeaderTypeFree);
	foo->allocationCount += 1;
	newChunk = newChunk1;
	/* begin popRemappableOop */
	oop1 = foo->remapBuffer[foo->remapBufferCount];
	foo->remapBufferCount -= 1;
	remappedOop = oop1;

	/* loop below uses pre-increment */

	toIndex = newChunk - (BYTES_PER_WORD);
	fromIndex = (remappedOop - extraHdrBytes) - (BYTES_PER_WORD);
	lastFrom = fromIndex + bytes;
	while (fromIndex < lastFrom) {
		longAtput(toIndex += BYTES_PER_WORD, longAt(fromIndex += BYTES_PER_WORD));
	}

	/* convert from chunk to oop */
	/* fix base header: compute new hash and clear Mark and Root bits */

	newOop = newChunk + extraHdrBytes;
	/* begin newObjectHash */
	foo->lastHash = (13849 + (27181 * foo->lastHash)) & 65535;
	hash = foo->lastHash;

	/* use old ccIndex, format, size, and header-type fields */

	header = (longAt(newOop)) & 131071;
	header = header | ((hash << 17) & 536739840);
	longAtput(newOop, header);
	return newOop;
}


/*	This code is called if the receiver responds primitively to at:.
	If this is so, it will be installed in the atCache so that subsequent calls of at:
	or next may be handled immediately in bytecode primitive routines. */

sqInt commonAt(sqInt stringy) {
register struct foo * foo = &fum;
    sqInt atIx;
    sqInt index;
    sqInt rcvr;
    sqInt result;
    sqInt sp;
    sqInt oop;
    sqInt sp1;
    sqInt oop1;


	/* Sets successFlag */

	index = positive32BitValueOf(longAt(foo->stackPointer));
	rcvr = longAt(foo->stackPointer - (1 * (BYTES_PER_WORD)));
	if (!(foo->successFlag && (!((rcvr & 1))))) {
		/* begin primitiveFail */
		foo->successFlag = 0;
		return null;
	}
	if ((foo->messageSelector == (fetchPointerofObject(16 * 2, fetchPointerofObject(SpecialSelectors, foo->specialObjectsOop)))) && (foo->lkupClass == (fetchClassOfNonInt(rcvr)))) {

		/* OK -- look in the at-cache */
		/* Index into atCache = 4N, for N = 0 ... 7 */

		atIx = rcvr & AtCacheMask;
		if (!((foo->atCache[atIx + AtCacheOop]) == rcvr)) {
			installinAtCacheatstring(rcvr, foo->atCache, atIx, stringy);
		}
		if (foo->successFlag) {
			result = commonVariableatcacheIndex(rcvr, index, atIx);
		}
		if (foo->successFlag) {
			/* begin pop:thenPush: */
			longAtput(sp = foo->stackPointer - (((foo->argumentCount + 1) - 1) * (BYTES_PER_WORD)), result);
			foo->stackPointer = sp;
			return null;
		}
	}
	foo->successFlag = 1;
	result = stObjectat(rcvr, index);
	if (foo->successFlag) {
		if (stringy) {
			/* begin fetchPointer:ofObject: */
			/* begin fetchPointer:ofObject: */
			oop1 = foo->specialObjectsOop;
			oop = longAt((oop1 + (BASE_HEADER_SIZE)) + (CharacterTable << (SHIFT_FOR_WORD)));
			result = longAt((oop + (BASE_HEADER_SIZE)) + (((result >> 1)) << (SHIFT_FOR_WORD)));
		}
		/* begin pop:thenPush: */
		longAtput(sp1 = foo->stackPointer - (((foo->argumentCount + 1) - 1) * (BYTES_PER_WORD)), result);
		foo->stackPointer = sp1;
		return null;
	}
}


/*	This code is called if the receiver responds primitively to at:Put:.
	If this is so, it will be installed in the atPutCache so that subsequent calls of at:
	or  next may be handled immediately in bytecode primitive routines. */

sqInt commonAtPut(sqInt stringy) {
register struct foo * foo = &fum;
    sqInt atIx;
    sqInt index;
    sqInt rcvr;
    sqInt value;
    sqInt sp;
    sqInt sp1;
    sqInt fixedFields;
    sqInt fmt;
    sqInt stSize;
    sqInt valToPut;

	value = longAt(foo->stackPointer);

	/* Sets successFlag */

	index = positive32BitValueOf(longAt(foo->stackPointer - (1 * (BYTES_PER_WORD))));
	rcvr = longAt(foo->stackPointer - (2 * (BYTES_PER_WORD)));
	if (!(foo->successFlag && (!((rcvr & 1))))) {
		/* begin primitiveFail */
		foo->successFlag = 0;
		return null;
	}
	if ((foo->messageSelector == (fetchPointerofObject(17 * 2, fetchPointerofObject(SpecialSelectors, foo->specialObjectsOop)))) && (foo->lkupClass == (fetchClassOfNonInt(rcvr)))) {

		/* OK -- look in the at-cache */
		/* Index into atPutCache */

		atIx = (rcvr & AtCacheMask) + AtPutBase;
		if (!((foo->atCache[atIx + AtCacheOop]) == rcvr)) {
			installinAtCacheatstring(rcvr, foo->atCache, atIx, stringy);
		}
		if (foo->successFlag) {
			/* begin commonVariable:at:put:cacheIndex: */
			stSize = foo->atCache[atIx + AtCacheSize];
			if (((((usqInt) index)) >= (((usqInt) 1))) && ((((usqInt) index)) <= (((usqInt) stSize)))) {
				fmt = foo->atCache[atIx + AtCacheFmt];
				if (fmt <= 4) {
					fixedFields = foo->atCache[atIx + AtCacheFixedFields];
					/* begin storePointer:ofObject:withValue: */
					if ((((usqInt) rcvr)) < (((usqInt) foo->youngStart))) {
						possibleRootStoreIntovalue(rcvr, value);
					}
					longAtput((rcvr + (BASE_HEADER_SIZE)) + (((index + fixedFields) - 1) << (SHIFT_FOR_WORD)), value);
					goto l1;
				}
				if (fmt < 8) {
					valToPut = positive32BitValueOf(value);
					if (foo->successFlag) {
						long32Atput((rcvr + (BASE_HEADER_SIZE)) + ((index - 1) << 2), valToPut);
					}
					goto l1;
				}
				if (fmt >= 16) {
					valToPut = asciiOfCharacter(value);
					if (!(foo->successFlag)) {
						goto l1;
					}
				} else {
					valToPut = value;
				}
				if ((valToPut & 1)) {
					valToPut = (valToPut >> 1);
					if (!((valToPut >= 0) && (valToPut <= 255))) {
						/* begin primitiveFail */
						foo->successFlag = 0;
						goto l1;
					}
					byteAtput((rcvr + (BASE_HEADER_SIZE)) + (index - 1), valToPut);
					goto l1;
				}
			}
			/* begin primitiveFail */
			foo->successFlag = 0;
		l1:	/* end commonVariable:at:put:cacheIndex: */;
		}
		if (foo->successFlag) {
			/* begin pop:thenPush: */
			longAtput(sp = foo->stackPointer - (((foo->argumentCount + 1) - 1) * (BYTES_PER_WORD)), value);
			foo->stackPointer = sp;
			return null;
		}
	}
	foo->successFlag = 1;
	if (stringy) {
		stObjectatput(rcvr, index, asciiOfCharacter(value));
	} else {
		stObjectatput(rcvr, index, value);
	}
	if (foo->successFlag) {
		/* begin pop:thenPush: */
		longAtput(sp1 = foo->stackPointer - (((foo->argumentCount + 1) - 1) * (BYTES_PER_WORD)), value);
		foo->stackPointer = sp1;
		return null;
	}
}


/*	This code assumes the receiver has been identified at location atIx in the atCache. */

sqInt commonVariableatcacheIndex(sqInt rcvr, sqInt index, sqInt atIx) {
register struct foo * foo = &fum;
    sqInt fixedFields;
    sqInt fmt;
    sqInt result;
    sqInt stSize;
    sqInt oop;
    sqInt oop1;

	stSize = foo->atCache[atIx + AtCacheSize];
	if (((((usqInt) index)) >= (((usqInt) 1))) && ((((usqInt) index)) <= (((usqInt) stSize)))) {
		fmt = foo->atCache[atIx + AtCacheFmt];
		if (fmt <= 4) {
			fixedFields = foo->atCache[atIx + AtCacheFixedFields];
			return longAt((rcvr + (BASE_HEADER_SIZE)) + (((index + fixedFields) - 1) << (SHIFT_FOR_WORD)));
		}
		if (fmt < 8) {

			/* Bitmap */

			result = long32At((rcvr + (BASE_HEADER_SIZE)) + ((index - 1) << 2));
			result = positive32BitIntegerFor(result);
			return result;
		}
		if (fmt >= 16) {
			/* begin fetchPointer:ofObject: */
			/* begin fetchPointer:ofObject: */
			oop1 = foo->specialObjectsOop;
			oop = longAt((oop1 + (BASE_HEADER_SIZE)) + (CharacterTable << (SHIFT_FOR_WORD)));
			return longAt((oop + (BASE_HEADER_SIZE)) + ((byteAt((rcvr + (BASE_HEADER_SIZE)) + (index - 1))) << (SHIFT_FOR_WORD)));
		} else {
			return (((byteAt((rcvr + (BASE_HEADER_SIZE)) + (index - 1))) << 1) | 1);
		}
	}
	/* begin primitiveFail */
	foo->successFlag = 0;
}


/*	May set success to false */
/*	First compare two ST integers... */

sqInt compare31or32Bitsequal(sqInt obj1, sqInt obj2) {
	if (((obj1 & 1)) && ((obj2 & 1))) {
		return obj1 == obj2;
	}
	return (positive32BitValueOf(obj1)) == (positive32BitValueOf(obj2));
}

sqInt compilerCreateActualMessagestoringArgs(sqInt aMessage, sqInt argArray) {
	return compilerHooks[14](aMessage, argArray);
}

sqInt compilerFlushCache(sqInt aCompiledMethod) {
	return compilerHooks[2](aCompiledMethod);
}

sqInt compilerMapFromto(sqInt memStart, sqInt memEnd) {
	return compilerHooks[4](memStart, memEnd);
}

sqInt compilerMark(void) {
	return compilerHooks[9]();
}

sqInt compilerPostGC(void) {
	return compilerHooks[5]();
}

sqInt compilerPostSnapshot(void) {
	return compilerHooks[8]();
}

sqInt compilerPreGC(sqInt fullGCFlag) {
	return compilerHooks[3](fullGCFlag);
}

sqInt compilerPreSnapshot(void) {
	return compilerHooks[7]();
}

sqInt compilerProcessChange(void) {
	return compilerHooks[6]();
}

sqInt compilerProcessChangeto(sqInt oldProc, sqInt newProc) {
	return compilerHooks[6](oldProc, newProc);
}

sqInt compilerTranslateMethod(void) {
	return compilerHooks[1]();
}


/*	Return true if neither array contains a small integer. You 
	can't become: integers! */

sqInt containOnlyOopsand(sqInt array1, sqInt array2) {
    sqInt fieldOffset;
    sqInt contextSize;
    sqInt fmt;
    sqInt header;
    sqInt methodHeader;
    sqInt sz;
    sqInt sp;
    sqInt header1;
    sqInt type;

	/* begin lastPointerOf: */
	header = longAt(array1);
	fmt = (((usqInt) header) >> 8) & 15;
	if (fmt <= 4) {
		if ((fmt == 3) && ((((((usqInt) header) >> 12) & 31) == 13) || ((((((usqInt) header) >> 12) & 31) == 14) || (((((usqInt) header) >> 12) & 31) == 4)))) {
			/* begin fetchStackPointerOf: */
			sp = longAt((array1 + (BASE_HEADER_SIZE)) + (StackPointerIndex << (SHIFT_FOR_WORD)));
			if (!((sp & 1))) {
				contextSize = 0;
				goto l1;
			}
			contextSize = (sp >> 1);
		l1:	/* end fetchStackPointerOf: */;
			fieldOffset = (CtxtTempFrameStart + contextSize) * (BYTES_PER_WORD);
			goto l2;
		}
		/* begin sizeBitsOfSafe: */
		header1 = longAt(array1);
		/* begin rightType: */
		if ((header1 & (SIZE_MASK)) == 0) {
			type = HeaderTypeSizeAndClass;
			goto l3;
		} else {
			if ((header1 & CompactClassMask) == 0) {
				type = HeaderTypeClass;
				goto l3;
			} else {
				type = HeaderTypeShort;
				goto l3;
			}
		}
	l3:	/* end rightType: */;
		if (type == HeaderTypeSizeAndClass) {
			sz = (longAt(array1 - ((BYTES_PER_WORD) * 2))) & (ALL_BUT_TYPE_MASK);
			goto l4;
		} else {
			sz = header1 & (SIZE_MASK);
			goto l4;
		}
	l4:	/* end sizeBitsOfSafe: */;
		fieldOffset = sz - (BASE_HEADER_SIZE);
		goto l2;
	}
	if (fmt < 12) {
		fieldOffset = 0;
		goto l2;
	}
	methodHeader = longAt(array1 + (BASE_HEADER_SIZE));
	fieldOffset = (((((usqInt) methodHeader) >> 10) & 255) * (BYTES_PER_WORD)) + (BASE_HEADER_SIZE);
l2:	/* end lastPointerOf: */;
	while (fieldOffset >= (BASE_HEADER_SIZE)) {
		if (((longAt(array1 + fieldOffset)) & 1)) {
			return 0;
		}
		if (((longAt(array2 + fieldOffset)) & 1)) {
			return 0;
		}
		fieldOffset -= BYTES_PER_WORD;
	}
	return 1;
}


/*	Does thisCntx have aContext in its sender chain? */

sqInt contexthasSender(sqInt thisCntx, sqInt aContext) {
    sqInt nilOop;
    sqInt s;

	if (thisCntx == aContext) {
		return 0;
	}
	nilOop = foo->nilObj;
	s = longAt((thisCntx + (BASE_HEADER_SIZE)) + (SenderIndex << (SHIFT_FOR_WORD)));
	while (!(s == nilOop)) {
		if (s == aContext) {
			return 1;
		}
		s = longAt((s + (BASE_HEADER_SIZE)) + (SenderIndex << (SHIFT_FOR_WORD)));
	}
	return 0;
}


/*	This entry point needs to be implemented for the interpreter proxy.
	Since BitBlt is now a plugin we need to look up BitBltPlugin:=copyBits
	and call it. This entire mechanism should eventually go away and be
	replaced with a dynamic lookup from BitBltPlugin itself but for backward
	compatibility this stub is provided */

sqInt copyBits(void) {
    void *fn;

	fn = ioLoadFunctionFrom("copyBits", "BitBltPlugin");
	if (fn == 0) {
		/* begin primitiveFail */
		foo->successFlag = 0;
		return null;
	}
	return ((sqInt (*)(void))fn)();
}


/*	This entry point needs to be implemented for the interpreter proxy.
	Since BitBlt is now a plugin we need to look up BitBltPlugin:=copyBitsFrom:to:at:
	and call it. This entire mechanism should eventually go away and be
	replaced with a dynamic lookup from BitBltPlugin itself but for backward
	compatibility this stub is provided */

sqInt copyBitsFromtoat(sqInt x0, sqInt x1, sqInt y) {
    void *fn;

	fn = ioLoadFunctionFrom("copyBitsFromtoat", "BitBltPlugin");
	if (fn == 0) {
		/* begin primitiveFail */
		foo->successFlag = 0;
		return null;
	}
	return ((sqInt (*)(sqInt, sqInt, sqInt))fn)(x0, x1, y);
}


/*	Copy this object into the segment beginning at lastSeg.
	Install a forwarding pointer, and save oop and header.
	Fail if out of space.  Return the next segmentAddr if successful. */
/*	Copy the object... */

sqInt copyObjtoSegmentaddrstopAtsaveOopAtheaderAt(sqInt oop, sqInt segmentWordArray, sqInt lastSeg, sqInt stopAddr, sqInt oopPtr, sqInt hdrPtr) {
register struct foo * foo = &fum;
    sqInt bodySize;
    sqInt extraSize;
    sqInt hdrAddr;
    sqInt header;
    sqInt in;
    sqInt lastIn;
    sqInt out;

	flag("Dan");
	if (!(foo->successFlag)) {
		return lastSeg;
	}
	extraSize = foo->headerTypeBytes[(longAt(oop)) & TypeMask];
	/* begin sizeBitsOf: */
	header = longAt(oop);
	if ((header & TypeMask) == HeaderTypeSizeAndClass) {
		bodySize = (longAt(oop - ((BYTES_PER_WORD) * 2))) & (LONG_SIZE_MASK);
		goto l1;
	} else {
		bodySize = header & (SIZE_MASK);
		goto l1;
	}
l1:	/* end sizeBitsOf: */;
	if ((((usqInt) ((lastSeg + extraSize) + bodySize))) >= (((usqInt) stopAddr))) {
		/* begin primitiveFail */
		foo->successFlag = 0;
		return null;
	}
	/* begin transfer:from:to: */
	flag("Dan");
	in = (oop - extraSize) - (BYTES_PER_WORD);
	lastIn = in + (((extraSize + bodySize) / (BYTES_PER_WORD)) * (BYTES_PER_WORD));
	out = (lastSeg + (BYTES_PER_WORD)) - (BYTES_PER_WORD);
	while ((((usqInt) in)) < (((usqInt) lastIn))) {
		longAtput(out += BYTES_PER_WORD, longAt(in += BYTES_PER_WORD));
	}
	hdrAddr = (lastSeg + (BYTES_PER_WORD)) + extraSize;
	longAtput(hdrAddr, (longAt(hdrAddr)) & ((ALL_BUT_ROOT_BIT) - (MARK_BIT)));
	/* begin forward:to:savingOopAt:andHeaderAt: */
	longAtput(oopPtr, oop);
	longAtput(hdrPtr, longAt(oop));
	longAtput(oop, (((lastSeg + (BYTES_PER_WORD)) + extraSize) - segmentWordArray) + HeaderTypeFree);
	return (lastSeg + extraSize) + bodySize;
}


/*	Bundle up the selector, arguments and lookupClass into a Message object. 
	In the process it pops the arguments off the stack, and pushes the message object. 
	This can then be presented as the argument of e.g. #doesNotUnderstand:. 
	ikp 11/20/1999 03:59 -- added hook for external runtime compilers. */
/*	remap lookupClass in case GC happens during allocation */

sqInt createActualMessageTo(sqInt aClass) {
register struct foo * foo = &fum;
    sqInt argumentArray;
    sqInt lookupClass;
    sqInt message;
    sqInt sp;
    sqInt oop;
    sqInt oop1;
    sqInt count;
    sqInt src;
    sqInt in;
    sqInt lastIn;
    sqInt out;
    sqInt valuePointer;

	/* begin pushRemappableOop: */
	foo->remapBuffer[(foo->remapBufferCount += 1)] = aClass;

	/* remap argumentArray in case GC happens during allocation */

	argumentArray = instantiateClassindexableSize(fetchPointerofObject(ClassArray, foo->specialObjectsOop), foo->argumentCount);
	/* begin pushRemappableOop: */
	foo->remapBuffer[(foo->remapBufferCount += 1)] = argumentArray;
	message = instantiateClassindexableSize(fetchPointerofObject(ClassMessage, foo->specialObjectsOop), 0);
	/* begin popRemappableOop */
	oop = foo->remapBuffer[foo->remapBufferCount];
	foo->remapBufferCount -= 1;
	argumentArray = oop;
	/* begin popRemappableOop */
	oop1 = foo->remapBuffer[foo->remapBufferCount];
	foo->remapBufferCount -= 1;
	lookupClass = oop1;
	beRootIfOld(argumentArray);
	if (foo->compilerInitialized) {
		compilerCreateActualMessagestoringArgs(message, argumentArray);
	} else {
		/* begin transfer:from:to: */
		count = foo->argumentCount;
		src = foo->stackPointer - ((foo->argumentCount - 1) * (BYTES_PER_WORD));
		flag("Dan");
		in = src - (BYTES_PER_WORD);
		lastIn = in + (count * (BYTES_PER_WORD));
		out = (argumentArray + (BASE_HEADER_SIZE)) - (BYTES_PER_WORD);
		while ((((usqInt) in)) < (((usqInt) lastIn))) {
			longAtput(out += BYTES_PER_WORD, longAt(in += BYTES_PER_WORD));
		}
		/* begin pop:thenPush: */
		longAtput(sp = foo->stackPointer - ((foo->argumentCount - 1) * (BYTES_PER_WORD)), message);
		foo->stackPointer = sp;
	}
	foo->argumentCount = 1;
	/* begin storePointer:ofObject:withValue: */
	valuePointer = foo->messageSelector;
	if ((((usqInt) message)) < (((usqInt) foo->youngStart))) {
		possibleRootStoreIntovalue(message, valuePointer);
	}
	longAtput((message + (BASE_HEADER_SIZE)) + (MessageSelectorIndex << (SHIFT_FOR_WORD)), valuePointer);
	/* begin storePointer:ofObject:withValue: */
	if ((((usqInt) message)) < (((usqInt) foo->youngStart))) {
		possibleRootStoreIntovalue(message, argumentArray);
	}
	longAtput((message + (BASE_HEADER_SIZE)) + (MessageArgumentsIndex << (SHIFT_FOR_WORD)), argumentArray);
	if ((lastPointerOf(message)) >= ((MessageLookupClassIndex * (BYTES_PER_WORD)) + (BASE_HEADER_SIZE))) {
		/* begin storePointer:ofObject:withValue: */
		if ((((usqInt) message)) < (((usqInt) foo->youngStart))) {
			possibleRootStoreIntovalue(message, lookupClass);
		}
		longAtput((message + (BASE_HEADER_SIZE)) + (MessageLookupClassIndex << (SHIFT_FOR_WORD)), lookupClass);
	}
}

sqInt dispatchFunctionPointer(void *aFunctionPointer) {
	((void (*)(void))aFunctionPointer)();
}


/*	Call the primitive at index primIdx in the primitiveTable. */

sqInt dispatchFunctionPointerOnin(sqInt primIdx, void *primTable[]) {
	return dispatchFunctionPointer(primTable[primIdx]);
}


/*	Repaint the portion of the Smalltalk screen bounded by the affected rectangle. Used to synchronize the screen after a Bitblt to the Smalltalk Display object. */

sqInt displayBitsOfLeftTopRightBottom(sqInt aForm, sqInt l, sqInt t, sqInt r, sqInt b) {
register struct foo * foo = &fum;
    sqInt bottom;
    sqInt d;
    sqInt dispBits;
    sqInt dispBitsIndex;
    sqInt displayObj;
    sqInt h;
    sqInt left;
    sqInt right;
    sqInt surfaceHandle;
    sqInt top;
    sqInt w;
    sqInt oop;
    sqInt successValue;

	/* begin fetchPointer:ofObject: */
	oop = foo->specialObjectsOop;
	displayObj = longAt((oop + (BASE_HEADER_SIZE)) + (TheDisplay << (SHIFT_FOR_WORD)));
	if (!(aForm == displayObj)) {
		return null;
	}
	/* begin success: */
	successValue = (((displayObj & 1) == 0) && (((((usqInt) (longAt(displayObj))) >> 8) & 15) <= 4)) && ((lengthOf(displayObj)) >= 4);
	foo->successFlag = successValue && foo->successFlag;
	if (foo->successFlag) {
		dispBits = longAt((displayObj + (BASE_HEADER_SIZE)) + (0 << (SHIFT_FOR_WORD)));
		w = fetchIntegerofObject(1, displayObj);
		h = fetchIntegerofObject(2, displayObj);
		d = fetchIntegerofObject(3, displayObj);
	}
	if (l < 0) {
		left = 0;
	} else {
		left = l;
	}
	if (r > w) {
		right = w;
	} else {
		right = r;
	}
	if (t < 0) {
		top = 0;
	} else {
		top = t;
	}
	if (b > h) {
		bottom = h;
	} else {
		bottom = b;
	}
	if (!((left <= right) && (top <= bottom))) {
		return null;
	}
	if (foo->successFlag) {
		if ((dispBits & 1)) {
			surfaceHandle = (dispBits >> 1);
			if (showSurfaceFn == 0) {
				showSurfaceFn = ioLoadFunctionFrom("ioShowSurface", "SurfacePlugin");
				if (showSurfaceFn == 0) {
					/* begin success: */
					foo->successFlag = 0 && foo->successFlag;
					return null;
				}
			}
			((sqInt (*)(sqInt, sqInt, sqInt, sqInt, sqInt))showSurfaceFn)(surfaceHandle, left, top, right-left, bottom-top);
		} else {

			/* index in memory byte array */

			dispBitsIndex = dispBits + (BASE_HEADER_SIZE);
			ioShowDisplay(dispBitsIndex, w, h, d, left, right, top, bottom);
		}
	}
}

sqInt displayObject(void) {
    sqInt oop;

	/* begin fetchPointer:ofObject: */
	oop = foo->specialObjectsOop;
	return longAt((oop + (BASE_HEADER_SIZE)) + (TheDisplay << (SHIFT_FOR_WORD)));
}


/*	Rounds negative results towards negative infinity, rather than zero. */

sqInt doPrimitiveDivby(sqInt rcvr, sqInt arg) {
register struct foo * foo = &fum;
    sqInt integerArg;
    sqInt integerRcvr;
    sqInt posArg;
    sqInt posRcvr;
    sqInt result;
    sqInt successValue;

	if (((rcvr & arg) & 1) != 0) {
		integerRcvr = (rcvr >> 1);
		integerArg = (arg >> 1);
		/* begin success: */
		foo->successFlag = (integerArg != 0) && foo->successFlag;
	} else {
		/* begin primitiveFail */
		foo->successFlag = 0;
	}
	if (!(foo->successFlag)) {
		return 1;
	}
	if (integerRcvr > 0) {
		if (integerArg > 0) {
			result = integerRcvr / integerArg;
		} else {

			/* round negative result toward negative infinity */

			posArg = 0 - integerArg;
			result = 0 - ((integerRcvr + (posArg - 1)) / posArg);
		}
	} else {
		posRcvr = 0 - integerRcvr;
		if (integerArg > 0) {

			/* round negative result toward negative infinity */

			result = 0 - ((posRcvr + (integerArg - 1)) / integerArg);
		} else {
			posArg = 0 - integerArg;
			result = posRcvr / posArg;
		}
	}
	/* begin success: */
	successValue = 
# ifdef SQ_HOST32  // cast to int for 64 bit image on 32 bit host
		(((((int) result)) ^ ((((int) result)) << 1)) >= 0)
# else
		((result >= -1073741824) && (result <= 1073741823))
# endif  // SQ_HOST32
	;
	foo->successFlag = successValue && foo->successFlag;
	return result;
}

sqInt doPrimitiveModby(sqInt rcvr, sqInt arg) {
register struct foo * foo = &fum;
    sqInt integerArg;
    sqInt integerRcvr;
    sqInt integerResult;
    sqInt successValue;

	if (((rcvr & arg) & 1) != 0) {
		integerRcvr = (rcvr >> 1);
		integerArg = (arg >> 1);
		/* begin success: */
		foo->successFlag = (integerArg != 0) && foo->successFlag;
	} else {
		/* begin primitiveFail */
		foo->successFlag = 0;
	}
	if (!(foo->successFlag)) {
		return 1;
	}

	/* ensure that the result has the same sign as the integerArg */

	integerResult = integerRcvr % integerArg;
	if (integerArg < 0) {
		if (integerResult > 0) {
			integerResult += integerArg;
		}
	} else {
		if (integerResult < 0) {
			integerResult += integerArg;
		}
	}
	/* begin success: */
	successValue = 
# ifdef SQ_HOST32  // cast to int for 64 bit image on 32 bit host
		(((((int) integerResult)) ^ ((((int) integerResult)) << 1)) >= 0)
# else
		((integerResult >= -1073741824) && (integerResult <= 1073741823))
# endif  // SQ_HOST32
	;
	foo->successFlag = successValue && foo->successFlag;
	return integerResult;
}

sqInt dummyReferToProxy(void) {
	interpreterProxy = interpreterProxy;
}


/*	Dump the entire image out to the given file. Intended for debugging only. */

EXPORT(sqInt) dumpImage(char *fileName) {
    sqInt dataSize;
    sqImageFile f;
    sqInt result;

	f = sqImageFileOpen(fileName, "wb");
	if (f == null) {
		return -1;
	}
	dataSize = foo->endOfMemory - memory;
	result = sqImageFileWrite(pointerForOop(memory), sizeof(unsigned char), dataSize, f);
	sqImageFileClose(f);
	return result;
}


/*	execute a method found in the mCache - which means that 
	primitiveIndex & primitiveFunctionPointer are already set. Any sender 
	needs to have previously sent findMethodInClass: or equivalent */

sqInt executeNewMethodFromCache(void) {
register struct foo * foo = &fum;
    sqInt delta;
    sqInt nArgs;

	if (foo->primitiveIndex > 0) {
		if (DoBalanceChecks) {

			/* check stack balance */

			nArgs = foo->argumentCount;
			delta = foo->stackPointer - foo->activeContext;
		}
		foo->successFlag = 1;
		dispatchFunctionPointer(foo->primitiveFunctionPointer);
		if (DoBalanceChecks) {
			if (!(balancedStackafterPrimitivewithArgs(delta, foo->primitiveIndex, nArgs))) {
				printUnbalancedStack(foo->primitiveIndex);
			}
		}
		if (foo->successFlag) {
			return null;
		}
	}
	activateNewMethod();
	/* begin quickCheckForInterrupts */
	if ((foo->interruptCheckCounter -= 1) <= 0) {
		checkForInterrupts();
	}
}


/*	Return the number of extra bytes used by the given object's header. */
/*	Warning: This method should not be used during marking, when the header type bits of an object may be incorrect. */
/*	JMM should be an array lookup! */

EXPORT(sqInt) extraHeaderBytes(sqInt oopOrChunk) {
	return foo->headerTypeBytes[(longAt(oopOrChunk)) & TypeMask];
}

sqInt failed(void) {
	return !foo->successFlag;
}

sqInt falseObject(void) {
	return foo->falseObj;
}


/*	Fetch the instance variable at the given index of the given object. Return the address of first indexable field of resulting array object, or fail if the instance variable does not contain an indexable bytes or words object. */
/*	Note: May be called by translated primitive code. */

void * fetchArrayofObject(sqInt fieldIndex, sqInt objectPointer) {
    sqInt arrayOop;

	arrayOop = longAt((objectPointer + (BASE_HEADER_SIZE)) + (fieldIndex << (SHIFT_FOR_WORD)));
	/* begin arrayValueOf: */
	if ((!((arrayOop & 1))) && (((arrayOop & 1) == 0) && (isWordsOrBytesNonInt(arrayOop)))) {
		return pointerForOop(arrayOop + (BASE_HEADER_SIZE));
	}
	/* begin primitiveFail */
	foo->successFlag = 0;
	return null;
}

sqInt fetchClassOf(sqInt oop) {
register struct foo * foo = &fum;
    sqInt ccIndex;
    sqInt oop1;
    sqInt oop2;
    sqInt oop3;

	if ((oop & 1)) {
		/* begin fetchPointer:ofObject: */
		oop1 = foo->specialObjectsOop;
		return longAt((oop1 + (BASE_HEADER_SIZE)) + (ClassInteger << (SHIFT_FOR_WORD)));
	}
	ccIndex = (((usqInt) (longAt(oop))) >> 12) & 31;
	if (ccIndex == 0) {
		return (longAt(oop - (BASE_HEADER_SIZE))) & (ALL_BUT_TYPE_MASK);
	} else {
		/* begin fetchPointer:ofObject: */
		/* begin fetchPointer:ofObject: */
		oop3 = foo->specialObjectsOop;
		oop2 = longAt((oop3 + (BASE_HEADER_SIZE)) + (CompactClasses << (SHIFT_FOR_WORD)));
		return longAt((oop2 + (BASE_HEADER_SIZE)) + ((ccIndex - 1) << (SHIFT_FOR_WORD)));
	}
}

sqInt fetchClassOfNonInt(sqInt oop) {
    sqInt ccIndex;
    sqInt oop1;
    sqInt oop2;

	ccIndex = (((usqInt) (longAt(oop))) >> 12) & 31;
	if (ccIndex == 0) {
		return (longAt(oop - (BASE_HEADER_SIZE))) & (ALL_BUT_TYPE_MASK);
	} else {
		/* begin fetchPointer:ofObject: */
		/* begin fetchPointer:ofObject: */
		oop2 = foo->specialObjectsOop;
		oop1 = longAt((oop2 + (BASE_HEADER_SIZE)) + (CompactClasses << (SHIFT_FOR_WORD)));
		return longAt((oop1 + (BASE_HEADER_SIZE)) + ((ccIndex - 1) << (SHIFT_FOR_WORD)));
	}
}


/*	Fetch the instance variable at the given index of the given object. Return the C double precision floating point value of that instance variable, or fail if it is not a Float. */
/*	Note: May be called by translated primitive code. */

double fetchFloatofObject(sqInt fieldIndex, sqInt objectPointer) {
    sqInt floatOop;

	floatOop = longAt((objectPointer + (BASE_HEADER_SIZE)) + (fieldIndex << (SHIFT_FOR_WORD)));
	return floatValueOf(floatOop);
}


/*	Note: May be called by translated primitive code. */

sqInt fetchIntegerofObject(sqInt fieldIndex, sqInt objectPointer) {
    sqInt intOop;

	intOop = longAt((objectPointer + (BASE_HEADER_SIZE)) + (fieldIndex << (SHIFT_FOR_WORD)));
	/* begin checkedIntegerValueOf: */
	if ((intOop & 1)) {
		return (intOop >> 1);
	} else {
		/* begin primitiveFail */
		foo->successFlag = 0;
		return 0;
	}
	return null;
}


/*	 index by 32-bit units, and return a 32-bit value. Intended to replace fetchWord:ofObject: */

sqInt fetchLong32ofObject(sqInt fieldIndex, sqInt oop) {
	return long32At((oop + (BASE_HEADER_SIZE)) + (fieldIndex << 2));
}


/*	index by word size, and return a pointer as long as the word size */

sqInt fetchPointerofObject(sqInt fieldIndex, sqInt oop) {
	return longAt((oop + (BASE_HEADER_SIZE)) + (fieldIndex << (SHIFT_FOR_WORD)));
}


/*	Return the stackPointer of a Context or BlockContext. */

sqInt fetchStackPointerOf(sqInt aContext) {
    sqInt sp;

	sp = longAt((aContext + (BASE_HEADER_SIZE)) + (StackPointerIndex << (SHIFT_FOR_WORD)));
	if (!((sp & 1))) {
		return 0;
	}
	return (sp >> 1);
}


/*	NOTE: this gives size appropriate for fetchPointer: n, but not in general for, eg, fetchLong32, etc. */

sqInt fetchWordLengthOf(sqInt objectPointer) {
    sqInt sz;
    sqInt header;

	/* begin sizeBitsOf: */
	header = longAt(objectPointer);
	if ((header & TypeMask) == HeaderTypeSizeAndClass) {
		sz = (longAt(objectPointer - ((BYTES_PER_WORD) * 2))) & (LONG_SIZE_MASK);
		goto l1;
	} else {
		sz = header & (SIZE_MASK);
		goto l1;
	}
l1:	/* end sizeBitsOf: */;
	return ((usqInt) (sz - (BASE_HEADER_SIZE))) >> (SHIFT_FOR_WORD);
}


/*	During sweep phase we have encountered a weak reference. 
	Check if  its object has gone away (or is about to) and if so, signal a 
	semaphore.  */
/*	Do *not* inline this in sweepPhase - it is quite an unlikely 
	case to run into a weak reference */

sqInt finalizeReference(usqInt oop) {
register struct foo * foo = &fum;
    sqInt chunk;
    sqInt firstField;
    sqInt i;
    sqInt lastField;
    sqInt nonWeakCnt;
    sqInt oopGone;
    usqInt weakOop;
    sqInt listItemOop;
    sqInt listOop;
    sqInt contextSize;
    sqInt fmt;
    sqInt header;
    sqInt methodHeader;
    sqInt sz;
    sqInt sp;
    sqInt header1;
    sqInt type;

	nonWeakCnt = nonWeakFieldsOf(oop);
	firstField = (BASE_HEADER_SIZE) + (nonWeakCnt << (SHIFT_FOR_WORD));
	/* begin lastPointerOf: */
	header = longAt(oop);
	fmt = (((usqInt) header) >> 8) & 15;
	if (fmt <= 4) {
		if ((fmt == 3) && ((((((usqInt) header) >> 12) & 31) == 13) || ((((((usqInt) header) >> 12) & 31) == 14) || (((((usqInt) header) >> 12) & 31) == 4)))) {
			/* begin fetchStackPointerOf: */
			sp = longAt((oop + (BASE_HEADER_SIZE)) + (StackPointerIndex << (SHIFT_FOR_WORD)));
			if (!((sp & 1))) {
				contextSize = 0;
				goto l1;
			}
			contextSize = (sp >> 1);
		l1:	/* end fetchStackPointerOf: */;
			lastField = (CtxtTempFrameStart + contextSize) * (BYTES_PER_WORD);
			goto l2;
		}
		/* begin sizeBitsOfSafe: */
		header1 = longAt(oop);
		/* begin rightType: */
		if ((header1 & (SIZE_MASK)) == 0) {
			type = HeaderTypeSizeAndClass;
			goto l3;
		} else {
			if ((header1 & CompactClassMask) == 0) {
				type = HeaderTypeClass;
				goto l3;
			} else {
				type = HeaderTypeShort;
				goto l3;
			}
		}
	l3:	/* end rightType: */;
		if (type == HeaderTypeSizeAndClass) {
			sz = (longAt(oop - ((BYTES_PER_WORD) * 2))) & (ALL_BUT_TYPE_MASK);
			goto l4;
		} else {
			sz = header1 & (SIZE_MASK);
			goto l4;
		}
	l4:	/* end sizeBitsOfSafe: */;
		lastField = sz - (BASE_HEADER_SIZE);
		goto l2;
	}
	if (fmt < 12) {
		lastField = 0;
		goto l2;
	}
	methodHeader = longAt(oop + (BASE_HEADER_SIZE));
	lastField = (((((usqInt) methodHeader) >> 10) & 255) * (BYTES_PER_WORD)) + (BASE_HEADER_SIZE);
l2:	/* end lastPointerOf: */;
	for (i = firstField; i <= lastField; i += (BYTES_PER_WORD)) {

		/* ar 1/18/2005: Added oop < youngStart test to make sure we're not testing
			objects in non-GCable region. This could lead to a forward reference in
			old space with the oop pointed to not being marked and thus treated as free. */

		weakOop = longAt(oop + i);
		if (!((weakOop == foo->nilObj) || (((weakOop & 1)) || (weakOop < foo->youngStart)))) {
			if (weakOop < oop) {

				/* Check if the object is being collected. 
					If the weak reference points  
					* backward: check if the weakOops chunk is free
					* forward: check if the weakOoop has been marked by GC */

				chunk = weakOop - (foo->headerTypeBytes[(longAt(weakOop)) & TypeMask]);
				oopGone = ((longAt(chunk)) & TypeMask) == HeaderTypeFree;
			} else {
				oopGone = ((longAt(weakOop)) & (MARK_BIT)) == 0;
			}
			if (oopGone) {
				longAtput(oop + i, foo->nilObj);
				if (nonWeakCnt >= 2) {
					/* begin weakFinalizerCheck: */
					listOop = longAt((oop + (BASE_HEADER_SIZE)) + (0 << (SHIFT_FOR_WORD)));
					if ((fetchClassOf(listOop)) == (fetchPointerofObject(ClassWeakFinalizer, foo->specialObjectsOop))) {
						listItemOop = longAt((listOop + (BASE_HEADER_SIZE)) + (0 << (SHIFT_FOR_WORD)));
						/* begin storePointer:ofObject:withValue: */
						if ((((usqInt) oop)) < (((usqInt) foo->youngStart))) {
							possibleRootStoreIntovalue(oop, listItemOop);
						}
						longAtput((oop + (BASE_HEADER_SIZE)) + (1 << (SHIFT_FOR_WORD)), listItemOop);
						/* begin storePointer:ofObject:withValue: */
						if ((((usqInt) listOop)) < (((usqInt) foo->youngStart))) {
							possibleRootStoreIntovalue(listOop, oop);
						}
						longAtput((listOop + (BASE_HEADER_SIZE)) + (0 << (SHIFT_FOR_WORD)), oop);
					}
				}
				/* begin signalFinalization: */
				/* begin forceInterruptCheck */
				foo->interruptCheckCounter = -1000;
				foo->nextPollTick = 0;
				foo->pendingFinalizationSignals += 1;
			}
		}
	}
}

sqInt findClassOfMethodforReceiver(sqInt meth, sqInt rcvr) {
register struct foo * foo = &fum;
    sqInt classDict;
    sqInt classDictSize;
    sqInt currClass;
    sqInt done;
    sqInt i;
    sqInt methodArray;
    sqInt sz;
    sqInt ccIndex;
    sqInt ccIndex1;
    sqInt oop;
    sqInt oop1;
    sqInt header;
    sqInt oop2;
    sqInt oop3;
    sqInt oop4;
    sqInt oop5;

	/* begin fetchClassOf: */
	if ((rcvr & 1)) {
		/* begin fetchPointer:ofObject: */
		oop = foo->specialObjectsOop;
		currClass = longAt((oop + (BASE_HEADER_SIZE)) + (ClassInteger << (SHIFT_FOR_WORD)));
		goto l1;
	}
	ccIndex = (((usqInt) (longAt(rcvr))) >> 12) & 31;
	if (ccIndex == 0) {
		currClass = (longAt(rcvr - (BASE_HEADER_SIZE))) & (ALL_BUT_TYPE_MASK);
		goto l1;
	} else {
		/* begin fetchPointer:ofObject: */
		/* begin fetchPointer:ofObject: */
		oop4 = foo->specialObjectsOop;
		oop1 = longAt((oop4 + (BASE_HEADER_SIZE)) + (CompactClasses << (SHIFT_FOR_WORD)));
		currClass = longAt((oop1 + (BASE_HEADER_SIZE)) + ((ccIndex - 1) << (SHIFT_FOR_WORD)));
		goto l1;
	}
l1:	/* end fetchClassOf: */;
	done = 0;
	while (!(done)) {
		classDict = longAt((currClass + (BASE_HEADER_SIZE)) + (MessageDictionaryIndex << (SHIFT_FOR_WORD)));
		/* begin fetchWordLengthOf: */
		/* begin sizeBitsOf: */
		header = longAt(classDict);
		if ((header & TypeMask) == HeaderTypeSizeAndClass) {
			sz = (longAt(classDict - ((BYTES_PER_WORD) * 2))) & (LONG_SIZE_MASK);
			goto l2;
		} else {
			sz = header & (SIZE_MASK);
			goto l2;
		}
	l2:	/* end sizeBitsOf: */;
		classDictSize = ((usqInt) (sz - (BASE_HEADER_SIZE))) >> (SHIFT_FOR_WORD);
		methodArray = longAt((classDict + (BASE_HEADER_SIZE)) + (MethodArrayIndex << (SHIFT_FOR_WORD)));
		i = 0;
		while (i < (classDictSize - SelectorStart)) {
			if (meth == (longAt((methodArray + (BASE_HEADER_SIZE)) + (i << (SHIFT_FOR_WORD))))) {
				return currClass;
			}
			i += 1;
		}
		currClass = longAt((currClass + (BASE_HEADER_SIZE)) + (SuperclassIndex << (SHIFT_FOR_WORD)));
		done = currClass == foo->nilObj;
	}
	/* begin fetchClassOf: */
	if ((rcvr & 1)) {
		/* begin fetchPointer:ofObject: */
		oop2 = foo->specialObjectsOop;
		return longAt((oop2 + (BASE_HEADER_SIZE)) + (ClassInteger << (SHIFT_FOR_WORD)));
	}
	ccIndex1 = (((usqInt) (longAt(rcvr))) >> 12) & 31;
	if (ccIndex1 == 0) {
		return (longAt(rcvr - (BASE_HEADER_SIZE))) & (ALL_BUT_TYPE_MASK);
	} else {
		/* begin fetchPointer:ofObject: */
		/* begin fetchPointer:ofObject: */
		oop5 = foo->specialObjectsOop;
		oop3 = longAt((oop5 + (BASE_HEADER_SIZE)) + (CompactClasses << (SHIFT_FOR_WORD)));
		return longAt((oop3 + (BASE_HEADER_SIZE)) + ((ccIndex1 - 1) << (SHIFT_FOR_WORD)));
	}
	return null;
}


/*	Find the compiled method to be run when the current 
	messageSelector is sent to the given class, setting the values 
	of 'newMethod' and 'primitiveIndex'. */

sqInt findNewMethodInClass(sqInt class) {
register struct foo * foo = &fum;
    sqInt ok;
    sqInt hash;
    sqInt probe;

	/* begin lookupInMethodCacheSel:class: */
	hash = foo->messageSelector ^ class;
	probe = hash & MethodCacheMask;
	if (((foo->methodCache[probe + MethodCacheSelector]) == foo->messageSelector) && ((foo->methodCache[probe + MethodCacheClass]) == class)) {
		foo->newMethod = foo->methodCache[probe + MethodCacheMethod];
		foo->primitiveIndex = foo->methodCache[probe + MethodCachePrim];
		foo->newNativeMethod = foo->methodCache[probe + MethodCacheNative];
		foo->primitiveFunctionPointer = ((void *) (foo->methodCache[probe + MethodCachePrimFunction]));
		ok = 1;
		goto l1;
	}
	probe = (((usqInt) hash) >> 1) & MethodCacheMask;
	if (((foo->methodCache[probe + MethodCacheSelector]) == foo->messageSelector) && ((foo->methodCache[probe + MethodCacheClass]) == class)) {
		foo->newMethod = foo->methodCache[probe + MethodCacheMethod];
		foo->primitiveIndex = foo->methodCache[probe + MethodCachePrim];
		foo->newNativeMethod = foo->methodCache[probe + MethodCacheNative];
		foo->primitiveFunctionPointer = ((void *) (foo->methodCache[probe + MethodCachePrimFunction]));
		ok = 1;
		goto l1;
	}
	probe = (((usqInt) hash) >> 2) & MethodCacheMask;
	if (((foo->methodCache[probe + MethodCacheSelector]) == foo->messageSelector) && ((foo->methodCache[probe + MethodCacheClass]) == class)) {
		foo->newMethod = foo->methodCache[probe + MethodCacheMethod];
		foo->primitiveIndex = foo->methodCache[probe + MethodCachePrim];
		foo->newNativeMethod = foo->methodCache[probe + MethodCacheNative];
		foo->primitiveFunctionPointer = ((void *) (foo->methodCache[probe + MethodCachePrimFunction]));
		ok = 1;
		goto l1;
	}
	ok = 0;
l1:	/* end lookupInMethodCacheSel:class: */;
	if (!(ok)) {
		lookupMethodInClass(class);
		foo->lkupClass = class;
		addNewMethodToCache();
	}
}

sqInt findSelectorOfMethodforReceiver(sqInt meth, sqInt rcvr) {
register struct foo * foo = &fum;
    sqInt classDict;
    sqInt classDictSize;
    sqInt currClass;
    sqInt done;
    sqInt i;
    sqInt methodArray;
    sqInt sz;
    sqInt ccIndex;
    sqInt oop;
    sqInt oop1;
    sqInt header;
    sqInt oop2;

	/* begin fetchClassOf: */
	if ((rcvr & 1)) {
		/* begin fetchPointer:ofObject: */
		oop = foo->specialObjectsOop;
		currClass = longAt((oop + (BASE_HEADER_SIZE)) + (ClassInteger << (SHIFT_FOR_WORD)));
		goto l1;
	}
	ccIndex = (((usqInt) (longAt(rcvr))) >> 12) & 31;
	if (ccIndex == 0) {
		currClass = (longAt(rcvr - (BASE_HEADER_SIZE))) & (ALL_BUT_TYPE_MASK);
		goto l1;
	} else {
		/* begin fetchPointer:ofObject: */
		/* begin fetchPointer:ofObject: */
		oop2 = foo->specialObjectsOop;
		oop1 = longAt((oop2 + (BASE_HEADER_SIZE)) + (CompactClasses << (SHIFT_FOR_WORD)));
		currClass = longAt((oop1 + (BASE_HEADER_SIZE)) + ((ccIndex - 1) << (SHIFT_FOR_WORD)));
		goto l1;
	}
l1:	/* end fetchClassOf: */;
	done = 0;
	while (!(done)) {
		classDict = longAt((currClass + (BASE_HEADER_SIZE)) + (MessageDictionaryIndex << (SHIFT_FOR_WORD)));
		/* begin fetchWordLengthOf: */
		/* begin sizeBitsOf: */
		header = longAt(classDict);
		if ((header & TypeMask) == HeaderTypeSizeAndClass) {
			sz = (longAt(classDict - ((BYTES_PER_WORD) * 2))) & (LONG_SIZE_MASK);
			goto l2;
		} else {
			sz = header & (SIZE_MASK);
			goto l2;
		}
	l2:	/* end sizeBitsOf: */;
		classDictSize = ((usqInt) (sz - (BASE_HEADER_SIZE))) >> (SHIFT_FOR_WORD);
		methodArray = longAt((classDict + (BASE_HEADER_SIZE)) + (MethodArrayIndex << (SHIFT_FOR_WORD)));
		i = 0;
		while (i <= (classDictSize - SelectorStart)) {
			if (meth == (longAt((methodArray + (BASE_HEADER_SIZE)) + (i << (SHIFT_FOR_WORD))))) {
				return longAt((classDict + (BASE_HEADER_SIZE)) + ((i + SelectorStart) << (SHIFT_FOR_WORD)));
			}
			i += 1;
		}
		currClass = longAt((currClass + (BASE_HEADER_SIZE)) + (SuperclassIndex << (SHIFT_FOR_WORD)));
		done = currClass == foo->nilObj;
	}
	return foo->nilObj;
}


/*	Return the first accessible object in the heap. */

sqInt firstAccessibleObject(void) {
register struct foo * foo = &fum;
    sqInt obj;
    sqInt sz;
    sqInt header;

	obj = memory + (foo->headerTypeBytes[(longAt(memory)) & TypeMask]);
	while ((((usqInt) obj)) < (((usqInt) foo->endOfMemory))) {
		if (!(((longAt(obj)) & TypeMask) == HeaderTypeFree)) {
			return obj;
		}
		/* begin objectAfter: */
		if (DoAssertionChecks) {
			if ((((usqInt) obj)) >= (((usqInt) foo->endOfMemory))) {
				error("no objects after the end of memory");
			}
		}
		if (((longAt(obj)) & TypeMask) == HeaderTypeFree) {
			sz = (longAt(obj)) & (ALL_BUT_TYPE_MASK);
		} else {
			/* begin sizeBitsOf: */
			header = longAt(obj);
			if ((header & TypeMask) == HeaderTypeSizeAndClass) {
				sz = (longAt(obj - ((BYTES_PER_WORD) * 2))) & (LONG_SIZE_MASK);
				goto l1;
			} else {
				sz = header & (SIZE_MASK);
				goto l1;
			}
		l1:	/* end sizeBitsOf: */;
		}
		obj = (obj + sz) + (foo->headerTypeBytes[(longAt(obj + sz)) & TypeMask]);
	}
	error("heap is empty");
}

char * firstFixedField(sqInt oop) {
	return pointerForOop(oop + (BASE_HEADER_SIZE));
}


/*	NOTE: copied in InterpreterSimulator, so please duplicate any changes */

char * firstIndexableField(sqInt oop) {
register struct foo * foo = &fum;
    sqInt fixedFields;
    sqInt fmt;
    sqInt hdr;
    sqInt totalLength;
    sqInt sz;
    sqInt class;
    sqInt classFormat;
    sqInt ccIndex;
    sqInt oop1;
    sqInt oop2;
    sqInt oop3;

	hdr = longAt(oop);
	fmt = (((usqInt) hdr) >> 8) & 15;
	/* begin lengthOf:baseHeader:format: */
	if ((hdr & TypeMask) == HeaderTypeSizeAndClass) {
		sz = (longAt(oop - ((BYTES_PER_WORD) * 2))) & (LONG_SIZE_MASK);
	} else {
		sz = hdr & (SIZE_MASK);
	}
	sz -= hdr & (SIZE_4_BIT);
	if (fmt <= 4) {
		totalLength = ((usqInt) (sz - (BASE_HEADER_SIZE))) >> (SHIFT_FOR_WORD);
		goto l1;
	}
	if (fmt < 8) {
		totalLength = ((usqInt) (sz - (BASE_HEADER_SIZE))) >> 2;
		goto l1;
	} else {
		totalLength = (sz - (BASE_HEADER_SIZE)) - (fmt & 3);
		goto l1;
	}
l1:	/* end lengthOf:baseHeader:format: */;
	/* begin fixedFieldsOf:format:length: */
	if ((fmt > 4) || (fmt == 2)) {
		fixedFields = 0;
		goto l3;
	}
	if (fmt < 2) {
		fixedFields = totalLength;
		goto l3;
	}
	/* begin fetchClassOf: */
	if ((oop & 1)) {
		/* begin fetchPointer:ofObject: */
		oop1 = foo->specialObjectsOop;
		class = longAt((oop1 + (BASE_HEADER_SIZE)) + (ClassInteger << (SHIFT_FOR_WORD)));
		goto l2;
	}
	ccIndex = (((usqInt) (longAt(oop))) >> 12) & 31;
	if (ccIndex == 0) {
		class = (longAt(oop - (BASE_HEADER_SIZE))) & (ALL_BUT_TYPE_MASK);
		goto l2;
	} else {
		/* begin fetchPointer:ofObject: */
		/* begin fetchPointer:ofObject: */
		oop3 = foo->specialObjectsOop;
		oop2 = longAt((oop3 + (BASE_HEADER_SIZE)) + (CompactClasses << (SHIFT_FOR_WORD)));
		class = longAt((oop2 + (BASE_HEADER_SIZE)) + ((ccIndex - 1) << (SHIFT_FOR_WORD)));
		goto l2;
	}
l2:	/* end fetchClassOf: */;
	classFormat = (longAt((class + (BASE_HEADER_SIZE)) + (InstanceSpecificationIndex << (SHIFT_FOR_WORD)))) - 1;
	fixedFields = (((((usqInt) classFormat) >> 11) & 192) + ((((usqInt) classFormat) >> 2) & 63)) - 1;
l3:	/* end fixedFieldsOf:format:length: */;
	if (fmt < 8) {
		if (fmt == 6) {
			return pointerForOop((oop + (BASE_HEADER_SIZE)) + (fixedFields << 2));
		}
		return pointerForOop((oop + (BASE_HEADER_SIZE)) + (fixedFields << (SHIFT_FOR_WORD)));
	} else {
		return pointerForOop((oop + (BASE_HEADER_SIZE)) + fixedFields);
	}
}

sqInt floatObjectOf(double  aFloat) {
    sqInt newFloatObj;

	flag("Dan");
	newFloatObj = instantiateSmallClasssizeInBytes(fetchPointerofObject(ClassFloat, foo->specialObjectsOop), 8 + (BASE_HEADER_SIZE));
	storeFloatAtfrom(newFloatObj + (BASE_HEADER_SIZE), aFloat);
	return newFloatObj;
}


/*	Fetch the instance variable at the given index of the given object. Return the C double precision floating point value of that instance variable, or fail if it is not a Float. */
/*	Note: May be called by translated primitive code. */

double floatValueOf(sqInt oop) {
register struct foo * foo = &fum;
    double  result;
    sqInt classOop;
    sqInt ccIndex;
    sqInt cl;
    sqInt oop1;
    sqInt oop2;
    sqInt oop3;

	flag("Dan");
	/* begin assertClassOf:is: */
	/* begin fetchPointer:ofObject: */
	oop3 = foo->specialObjectsOop;
	classOop = longAt((oop3 + (BASE_HEADER_SIZE)) + (ClassFloat << (SHIFT_FOR_WORD)));
	if ((oop & 1)) {
		foo->successFlag = 0;
		goto l1;
	}
	ccIndex = (((usqInt) (longAt(oop))) >> 12) & 31;
	if (ccIndex == 0) {
		cl = (longAt(oop - (BASE_HEADER_SIZE))) & (ALL_BUT_TYPE_MASK);
	} else {
		/* begin fetchPointer:ofObject: */
		/* begin fetchPointer:ofObject: */
		oop2 = foo->specialObjectsOop;
		oop1 = longAt((oop2 + (BASE_HEADER_SIZE)) + (CompactClasses << (SHIFT_FOR_WORD)));
		cl = longAt((oop1 + (BASE_HEADER_SIZE)) + ((ccIndex - 1) << (SHIFT_FOR_WORD)));
	}
	/* begin success: */
	foo->successFlag = (cl == classOop) && foo->successFlag;
l1:	/* end assertClassOf:is: */;
	if (foo->successFlag) {
		;
		fetchFloatAtinto(oop + (BASE_HEADER_SIZE), result);
	} else {
		result = 0.0;
	}
	return result;
}


/*	methodPtr is a CompiledMethod containing an external primitive. Flush the function address and session ID of the CM */

sqInt flushExternalPrimitiveOf(sqInt methodPtr) {
    sqInt lit;

	if (!((literalCountOfHeader(longAt((methodPtr + (BASE_HEADER_SIZE)) + (HeaderIndex << (SHIFT_FOR_WORD))))) > 0)) {
		return null;
	}
	lit = longAt((methodPtr + (BASE_HEADER_SIZE)) + ((0 + LiteralStart) << (SHIFT_FOR_WORD)));
	if (!((((lit & 1) == 0) && (((((usqInt) (longAt(lit))) >> 8) & 15) == 2)) && ((lengthOf(lit)) == 4))) {
		return null;
	}
	longAtput((lit + (BASE_HEADER_SIZE)) + (2 << (SHIFT_FOR_WORD)), ConstZero);
	longAtput((lit + (BASE_HEADER_SIZE)) + (3 << (SHIFT_FOR_WORD)), ConstZero);
}


/*	Flush the references to external functions from plugin 
	primitives. This will force a reload of those primitives when 
	accessed next. 
	Note: We must flush the method cache here so that any 
	failed primitives are looked up again. */

sqInt flushExternalPrimitives(void) {
register struct foo * foo = &fum;
    sqInt oop;
    sqInt primIdx;
    sqInt primBits;
    sqInt i;
    sqInt i1;
    sqInt i2;
    sqInt sz;
    sqInt header;

	oop = memory + (foo->headerTypeBytes[(longAt(memory)) & TypeMask]);
	while ((((usqInt) oop)) < (((usqInt) foo->endOfMemory))) {
		if (!(((longAt(oop)) & TypeMask) == HeaderTypeFree)) {
			if (((((usqInt) (longAt(oop))) >> 8) & 15) >= 12) {
				/* begin primitiveIndexOf: */
				primBits = (((usqInt) (longAt((oop + (BASE_HEADER_SIZE)) + (HeaderIndex << (SHIFT_FOR_WORD))))) >> 1) & 268435967;
				primIdx = (primBits & 511) + (((usqInt) primBits) >> 19);
				if (primIdx == PrimitiveExternalCallIndex) {
					flushExternalPrimitiveOf(oop);
				}
			}
		}
		/* begin objectAfter: */
		if (DoAssertionChecks) {
			if ((((usqInt) oop)) >= (((usqInt) foo->endOfMemory))) {
				error("no objects after the end of memory");
			}
		}
		if (((longAt(oop)) & TypeMask) == HeaderTypeFree) {
			sz = (longAt(oop)) & (ALL_BUT_TYPE_MASK);
		} else {
			/* begin sizeBitsOf: */
			header = longAt(oop);
			if ((header & TypeMask) == HeaderTypeSizeAndClass) {
				sz = (longAt(oop - ((BYTES_PER_WORD) * 2))) & (LONG_SIZE_MASK);
				goto l1;
			} else {
				sz = header & (SIZE_MASK);
				goto l1;
			}
		l1:	/* end sizeBitsOf: */;
		}
		oop = (oop + sz) + (foo->headerTypeBytes[(longAt(oop + sz)) & TypeMask]);
	}
	/* begin flushMethodCache */
	for (i = 1; i <= MethodCacheSize; i += 1) {
		foo->methodCache[i] = 0;
	}
	/* begin flushAtCache */
	for (i1 = 1; i1 <= AtCacheTotalSize; i1 += 1) {
		foo->atCache[i1] = 0;
	}
	/* begin flushExternalPrimitiveTable */
	for (i2 = 0; i2 <= (MaxExternalPrimitiveTableSize - 1); i2 += 1) {
		foo->externalPrimitiveTable[i2] = 0;
	}
}


/*	force an interrupt check ASAP - setting interruptCheckCounter to a large -ve number is used as a flag to skip messing with the feedback mechanism and nextPollTick resetting makes sure that ioProcess gets called as near immediately as we can manage */

sqInt forceInterruptCheck(void) {
register struct foo * foo = &fum;
	foo->interruptCheckCounter = -1000;
	foo->nextPollTick = 0;
}


/*	Repaint the entire smalltalk screen, ignoring the affected rectangle. Used in some platform's code when the Smalltalk window is brought to the front or uncovered. */

sqInt fullDisplayUpdate(void) {
    sqInt displayObj;
    sqInt h;
    sqInt w;
    sqInt oop;

	/* begin fetchPointer:ofObject: */
	oop = foo->specialObjectsOop;
	displayObj = longAt((oop + (BASE_HEADER_SIZE)) + (TheDisplay << (SHIFT_FOR_WORD)));
	if ((((displayObj & 1) == 0) && (((((usqInt) (longAt(displayObj))) >> 8) & 15) <= 4)) && ((lengthOf(displayObj)) >= 4)) {
		w = fetchIntegerofObject(1, displayObj);
		h = fetchIntegerofObject(2, displayObj);
		displayBitsOfLeftTopRightBottom(displayObj, 0, 0, w, h);
		ioForceDisplayUpdate();
	}
}


/*	Do a mark/sweep garbage collection of the entire object memory. Free inaccessible objects but do not move them. */

sqInt fullGC(void) {
register struct foo * foo = &fum;
    sqLong startTime;
    sqInt i;
    sqInt oop;
    sqInt sz;
    sqInt activeCntx;
    sqInt valuePointer;
    sqInt valuePointer1;

	if (DoAssertionChecks) {
		reverseDisplayFromto(0, 7);
	}
	/* begin preGCAction: */
	if (foo->compilerInitialized) {
		compilerPreGC(1);
	} else {
		/* begin storeContextRegisters: */
		activeCntx = foo->activeContext;
		/* begin storePointerUnchecked:ofObject:withValue: */
		valuePointer = ((((foo->instructionPointer - foo->method) - ((BASE_HEADER_SIZE) - 2)) << 1) | 1);
		longAtput((activeCntx + (BASE_HEADER_SIZE)) + (InstructionPointerIndex << (SHIFT_FOR_WORD)), valuePointer);
		/* begin storePointerUnchecked:ofObject:withValue: */
		valuePointer1 = (((((((usqInt) ((foo->stackPointer - foo->activeContext) - (BASE_HEADER_SIZE))) >> (SHIFT_FOR_WORD)) - TempFrameStart) + 1) << 1) | 1);
		longAtput((activeCntx + (BASE_HEADER_SIZE)) + (StackPointerIndex << (SHIFT_FOR_WORD)), valuePointer1);
	}
	startTime = ioMicroSecondClock();
	foo->statSweepCount = foo->statMarkCount = foo->statMkFwdCount = foo->statCompMoveCount = 0;
	/* begin clearRootsTable */
	for (i = 1; i <= foo->rootTableCount; i += 1) {
		oop = foo->rootTable[i];
		longAtput(oop, (longAt(oop)) & (ALL_BUT_ROOT_BIT));
		foo->rootTable[i] = 0;
	}
	foo->rootTableCount = 0;

	/* process all of memory */

	foo->youngStart = memory;
	markPhase();
	foo->totalObjectCount = sweepPhase();
	/* begin fullCompaction */
	foo->compStart = lowestFreeAfter(memory);
	if (foo->compStart == foo->freeBlock) {
		initializeMemoryFirstFree(foo->freeBlock);
		goto l1;
	}
	if ((sz = fwdTableSize(8)) < foo->totalObjectCount) {
		growObjectMemory(((foo->totalObjectCount - sz) + 10000) * 8);
	}
	while (foo->compStart < foo->freeBlock) {
		foo->compStart = incCompBody();
	}
l1:	/* end fullCompaction */;
	foo->allocationCount = 0;
	foo->statFullGCs += 1;
	foo->statGCTime = ioMicroSecondClock();
	foo->statFullGCMSecs += foo->statGCTime - startTime;
	/* begin capturePendingFinalizationSignals */
	foo->statpendingFinalizationSignals = foo->pendingFinalizationSignals;

	/* reset the young object boundary */

	foo->youngStart = foo->freeBlock;
	postGCAction();
	if (DoAssertionChecks) {
		reverseDisplayFromto(0, 7);
	}
}


/*	Set the limits for a table of two- or three-word forwarding blocks above the last used oop. The pointer fwdTableNext moves up to fwdTableLast. Used for compaction of memory and become-ing objects. Returns the number of forwarding blocks available. */

sqInt fwdTableInit(sqInt blkSize) {
register struct foo * foo = &fum;
	/* begin setSizeOfFree:to: */
	longAtput(foo->freeBlock, ((BASE_HEADER_SIZE) & (ALL_BUT_TYPE_MASK)) | HeaderTypeFree);

	/* make a fake free chunk at endOfMemory for use as a sentinal in memory scans */

	foo->endOfMemory = foo->freeBlock + (BASE_HEADER_SIZE);
	/* begin setSizeOfFree:to: */
	longAtput(foo->endOfMemory, ((BASE_HEADER_SIZE) & (ALL_BUT_TYPE_MASK)) | HeaderTypeFree);
	foo->fwdTableNext = ((foo->endOfMemory + (BASE_HEADER_SIZE)) + 7) & ((WORD_MASK) - 7);
	flag("Dan");

	/* last forwarding table entry */
	/* return the number of forwarding blocks available */

	foo->fwdTableLast = foo->memoryLimit - blkSize;
	return (foo->fwdTableLast - foo->fwdTableNext) / blkSize;
}


/*	Estimate the number of forwarding blocks available for compaction */

sqInt fwdTableSize(sqInt blkSize) {
register struct foo * foo = &fum;
    sqInt eom;
    sqInt fwdFirst;
    sqInt fwdLast;


	/* use all memory free between freeBlock and memoryLimit for forwarding table */
	/* Note: Forward blocks must be quadword aligned. */

	eom = foo->freeBlock + (BASE_HEADER_SIZE);
	fwdFirst = ((eom + (BASE_HEADER_SIZE)) + 7) & ((WORD_MASK) - 7);
	flag("Dan");

	/* last forwarding table entry */
	/* return the number of forwarding blocks available */

	fwdLast = foo->memoryLimit - blkSize;
	return (fwdLast - fwdFirst) / blkSize;
}


/*	currentBytecode will be private to the main dispatch loop in the generated code. This method allows the currentBytecode to be retrieved from global variables. */

sqInt getCurrentBytecode(void) {
	return byteAt(foo->instructionPointer);
}

sqInt getFullScreenFlag(void) {
	return foo->fullScreenFlag;
}

sqInt getInterruptCheckCounter(void) {
	return foo->interruptCheckCounter;
}

sqInt getInterruptKeycode(void) {
	return foo->interruptKeycode;
}

sqInt getInterruptPending(void) {
	return foo->interruptPending;
}


/*	Answer the next word read from aFile, byte-swapped according to the swapFlag. */

sqInt getLongFromFileswap(sqImageFile  aFile, sqInt swapFlag) {
    sqInt w;

	w = 0;
	sqImageFileRead(&w, sizeof(w), 1, aFile);
	if (swapFlag) {
		/* begin byteSwapped: */
		
# if (BYTES_PER_WORD == 4)  // swap bytes in an object word
		return ((((((usqInt) w >> 24)) & Byte0Mask) + ((((usqInt) w >> 8)) & Byte1Mask)) + ((((usqInt) w << 8)) & Byte2Mask)) + ((((usqInt) w << 24)) & Byte3Mask);
# else
		return ((((((((((usqInt) w >> 56)) & Byte0Mask) + ((((usqInt) w >> 40)) & Byte1Mask)) + ((((usqInt) w >> 24)) & Byte2Mask)) + ((((usqInt) w >> 8)) & Byte3Mask)) + ((((usqInt) w << 8)) & Byte4Mask)) + ((((usqInt) w << 24)) & Byte5Mask)) + ((((usqInt) w << 40)) & Byte6Mask)) + ((((usqInt) w << 56)) & Byte7Mask);
# endif  // BYTES_PER_WORD == 4
		
		return null;
	} else {
		return w;
	}
}

sqInt getNextWakeupTick(void) {
	return foo->nextWakeupTick;
}

sqInt getSavedWindowSize(void) {
	return foo->savedWindowSize;
}


/*	For Newsqueak FFI */

EXPORT(sqInt) getStackPointer(void) {
	return foo->stackPointer;
}


/*	return the global session ID value */

sqInt getThisSessionID(void) {
	return foo->globalSessionID;
}


/*	Attempt to grow the object memory by the given delta 
	amount  */

sqInt growObjectMemory(usqInt delta) {
register struct foo * foo = &fum;
    usqInt limit;

	if (!(isExcessiveAllocationRequestshift(delta, 0))) {
		foo->statGrowMemory += 1;
		limit = sqGrowMemoryBy(foo->memoryLimit, delta);
		if (!(limit == foo->memoryLimit)) {

			/* remove a tad for safety */

			foo->memoryLimit = limit - 24;
			initializeMemoryFirstFree(foo->freeBlock);
		}
	}
}

sqInt headerOf(sqInt methodPointer) {
	return longAt((methodPointer + (BASE_HEADER_SIZE)) + (HeaderIndex << (SHIFT_FOR_WORD)));
}


/*	a more complex version that tells both the word reversal and the endianness of the machine it came from.  Low half of word is 6502.  Top byte is top byte of #doesNotUnderstand: on this machine. ($d on the Mac or $s on the PC) */

sqInt imageSegmentVersion(void) {
    sqInt wholeWord;


	/* first data word, 'does'  */

	wholeWord = longAt((fetchPointerofObject(SelectorDoesNotUnderstand, foo->specialObjectsOop)) + (BASE_HEADER_SIZE));
	return imageFormatVersionNumber | (wholeWord & 4278190080U);
}


/*	Move objects to consolidate free space into one big chunk. Return the newly created free chunk. */

sqInt incCompBody(void) {
register struct foo * foo = &fum;
    sqInt bytesFreed;

	fwdTableInit((BYTES_PER_WORD) * 2);

	/* update pointers to point at new oops */

	bytesFreed = incCompMakeFwd();
	mapPointersInObjectsFromto(foo->youngStart, foo->endOfMemory);
	return incCompMove(bytesFreed);
}


/*	Create and initialize forwarding blocks for all non-free objects  
	following compStart. If the supply of forwarding blocks is exhausted,  
	set compEnd to the first chunk above the area to be 
	compacted; otherwise, set it to endOfMemory. Return the number of 
	bytes to be freed. */

sqInt incCompMakeFwd(void) {
register struct foo * foo = &fum;
    sqInt bytesFreed;
    sqInt fwdBlock;
    sqInt newOop;
    sqInt oop;
    sqInt originalHeader;
    sqInt originalHeaderType;
    sqInt fwdBlock1;
    sqInt header;
    sqInt realHeader;
    sqInt sz;
    sqInt sz1;
    sqInt header1;

	bytesFreed = 0;
	oop = foo->compStart + (foo->headerTypeBytes[(longAt(foo->compStart)) & TypeMask]);
	while ((((usqInt) oop)) < (((usqInt) foo->endOfMemory))) {
		foo->statMkFwdCount += 1;
		if (((longAt(oop)) & TypeMask) == HeaderTypeFree) {
			bytesFreed += (longAt(oop)) & (ALL_BUT_TYPE_MASK);
		} else {
			/* begin fwdBlockGet: */
			foo->fwdTableNext += (BYTES_PER_WORD) * 2;
			if (foo->fwdTableNext <= foo->fwdTableLast) {
				fwdBlock = foo->fwdTableNext;
				goto l1;
			} else {
				fwdBlock = null;
				goto l1;
			}
		l1:	/* end fwdBlockGet: */;
			if (fwdBlock == null) {

				/* stop; we have used all available forwarding blocks */

				foo->compEnd = oop - (foo->headerTypeBytes[(longAt(oop)) & TypeMask]);
				return bytesFreed;
			}
			newOop = oop - bytesFreed;
			/* begin initForwardBlock:mapping:to:withBackPtr: */
			originalHeader = longAt(oop);
			if (DoAssertionChecks) {
				if (fwdBlock == null) {
					error("ran out of forwarding blocks in become");
				}
				if ((originalHeader & (MARK_BIT)) != 0) {
					error("object already has a forwarding table entry");
				}
			}
			originalHeaderType = originalHeader & TypeMask;
			longAtput(fwdBlock, newOop);
			longAtput(fwdBlock + (BYTES_PER_WORD), originalHeader);
			if (0) {
				longAtput(fwdBlock + ((BYTES_PER_WORD) * 2), oop);
			}
			longAtput(oop, (((usqInt) fwdBlock) >> 1) | ((MARK_BIT) | originalHeaderType));
		}
		/* begin objectAfterWhileForwarding: */
		header = longAt(oop);
		if ((header & (MARK_BIT)) == 0) {
			/* begin objectAfter: */
			if (DoAssertionChecks) {
				if ((((usqInt) oop)) >= (((usqInt) foo->endOfMemory))) {
					error("no objects after the end of memory");
				}
			}
			if (((longAt(oop)) & TypeMask) == HeaderTypeFree) {
				sz1 = (longAt(oop)) & (ALL_BUT_TYPE_MASK);
			} else {
				/* begin sizeBitsOf: */
				header1 = longAt(oop);
				if ((header1 & TypeMask) == HeaderTypeSizeAndClass) {
					sz1 = (longAt(oop - ((BYTES_PER_WORD) * 2))) & (LONG_SIZE_MASK);
					goto l3;
				} else {
					sz1 = header1 & (SIZE_MASK);
					goto l3;
				}
			l3:	/* end sizeBitsOf: */;
			}
			oop = (oop + sz1) + (foo->headerTypeBytes[(longAt(oop + sz1)) & TypeMask]);
			goto l2;
		}
		fwdBlock1 = (header & (ALL_BUT_MARK_BIT_AND_TYPE_MASK)) << 1;
		if (DoAssertionChecks) {
			/* begin fwdBlockValidate: */
			if (!(((((usqInt) fwdBlock1)) > (((usqInt) foo->endOfMemory))) && (((((usqInt) fwdBlock1)) <= (((usqInt) foo->fwdTableNext))) && ((fwdBlock1 & 3) == 0)))) {
				error("invalid fwd table entry");
			}
		}
		realHeader = longAt(fwdBlock1 + (BYTES_PER_WORD));
		if ((realHeader & TypeMask) == HeaderTypeSizeAndClass) {
			sz = (longAt(oop - ((BYTES_PER_WORD) * 2))) & (LONG_SIZE_MASK);
		} else {
			sz = realHeader & (SIZE_MASK);
		}
		oop = (oop + sz) + (foo->headerTypeBytes[(longAt(oop + sz)) & TypeMask]);
	l2:	/* end objectAfterWhileForwarding: */;
	}
	foo->compEnd = foo->endOfMemory;
	return bytesFreed;
}


/*	Move all non-free objects between compStart and compEnd to their new  
	locations, restoring their headers in the process. Create a new free  
	block at the end of memory. Return the newly created free chunk.  */
/*	Note: The free block used by the allocator always must be the last free  
	block in memory. It may take several compaction passes to make all  
	free space bubble up to the end of memory. */

sqInt incCompMove(sqInt bytesFreed) {
register struct foo * foo = &fum;
    sqInt bytesToMove;
    usqInt firstWord;
    sqInt fwdBlock;
    sqInt header;
    usqInt lastWord;
    sqInt newFreeChunk;
    sqInt newOop;
    sqInt next;
    sqInt oop;
    sqInt sz;
    sqInt target;
    usqInt w;
    sqInt header1;
    sqInt fwdBlock1;
    sqInt header2;
    sqInt realHeader;
    sqInt sz1;
    sqInt sz2;
    sqInt header3;

	newOop = null;
	oop = foo->compStart + (foo->headerTypeBytes[(longAt(foo->compStart)) & TypeMask]);
	while ((((usqInt) oop)) < (((usqInt) foo->compEnd))) {
		foo->statCompMoveCount += 1;
		/* begin objectAfterWhileForwarding: */
		header2 = longAt(oop);
		if ((header2 & (MARK_BIT)) == 0) {
			/* begin objectAfter: */
			if (DoAssertionChecks) {
				if ((((usqInt) oop)) >= (((usqInt) foo->endOfMemory))) {
					error("no objects after the end of memory");
				}
			}
			if (((longAt(oop)) & TypeMask) == HeaderTypeFree) {
				sz2 = (longAt(oop)) & (ALL_BUT_TYPE_MASK);
			} else {
				/* begin sizeBitsOf: */
				header3 = longAt(oop);
				if ((header3 & TypeMask) == HeaderTypeSizeAndClass) {
					sz2 = (longAt(oop - ((BYTES_PER_WORD) * 2))) & (LONG_SIZE_MASK);
					goto l3;
				} else {
					sz2 = header3 & (SIZE_MASK);
					goto l3;
				}
			l3:	/* end sizeBitsOf: */;
			}
			next = (oop + sz2) + (foo->headerTypeBytes[(longAt(oop + sz2)) & TypeMask]);
			goto l2;
		}
		fwdBlock1 = (header2 & (ALL_BUT_MARK_BIT_AND_TYPE_MASK)) << 1;
		if (DoAssertionChecks) {
			/* begin fwdBlockValidate: */
			if (!(((((usqInt) fwdBlock1)) > (((usqInt) foo->endOfMemory))) && (((((usqInt) fwdBlock1)) <= (((usqInt) foo->fwdTableNext))) && ((fwdBlock1 & 3) == 0)))) {
				error("invalid fwd table entry");
			}
		}
		realHeader = longAt(fwdBlock1 + (BYTES_PER_WORD));
		if ((realHeader & TypeMask) == HeaderTypeSizeAndClass) {
			sz1 = (longAt(oop - ((BYTES_PER_WORD) * 2))) & (LONG_SIZE_MASK);
		} else {
			sz1 = realHeader & (SIZE_MASK);
		}
		next = (oop + sz1) + (foo->headerTypeBytes[(longAt(oop + sz1)) & TypeMask]);
	l2:	/* end objectAfterWhileForwarding: */;
		if (!(((longAt(oop)) & TypeMask) == HeaderTypeFree)) {

			/* a moving object; unwind its forwarding block */

			fwdBlock = ((longAt(oop)) & (ALL_BUT_MARK_BIT_AND_TYPE_MASK)) << 1;
			if (DoAssertionChecks) {
				/* begin fwdBlockValidate: */
				if (!(((((usqInt) fwdBlock)) > (((usqInt) foo->endOfMemory))) && (((((usqInt) fwdBlock)) <= (((usqInt) foo->fwdTableNext))) && ((fwdBlock & 3) == 0)))) {
					error("invalid fwd table entry");
				}
			}
			newOop = longAt(fwdBlock);
			header = longAt(fwdBlock + (BYTES_PER_WORD));
			longAtput(oop, header);

			/* move the oop (including any extra header words)  */

			bytesToMove = oop - newOop;
			/* begin sizeBitsOf: */
			header1 = longAt(oop);
			if ((header1 & TypeMask) == HeaderTypeSizeAndClass) {
				sz = (longAt(oop - ((BYTES_PER_WORD) * 2))) & (LONG_SIZE_MASK);
				goto l1;
			} else {
				sz = header1 & (SIZE_MASK);
				goto l1;
			}
		l1:	/* end sizeBitsOf: */;
			firstWord = oop - (foo->headerTypeBytes[(longAt(oop)) & TypeMask]);
			lastWord = (oop + sz) - (BASE_HEADER_SIZE);
			target = firstWord - bytesToMove;
			for (w = firstWord; w <= lastWord; w += (BYTES_PER_WORD)) {
				longAtput(target, longAt(w));
				target += BYTES_PER_WORD;
			}
		}
		oop = next;
	}
	if (newOop == null) {

		/* no objects moved */

		oop = foo->compStart + (foo->headerTypeBytes[(longAt(foo->compStart)) & TypeMask]);
		if ((((longAt(oop)) & TypeMask) == HeaderTypeFree) && ((objectAfter(oop)) == (foo->compEnd + (foo->headerTypeBytes[(longAt(foo->compEnd)) & TypeMask])))) {
			newFreeChunk = oop;
		} else {
			newFreeChunk = foo->freeBlock;
		}
	} else {

		/* initialize the newly freed memory chunk */
		/* newOop is the last object moved; free chunk starts 
			right after it */

		newFreeChunk = newOop + (sizeBitsOf(newOop));
		/* begin setSizeOfFree:to: */
		longAtput(newFreeChunk, (bytesFreed & (ALL_BUT_TYPE_MASK)) | HeaderTypeFree);
	}
	if (DoAssertionChecks) {
		if (!((objectAfter(newFreeChunk)) == (foo->compEnd + (foo->headerTypeBytes[(longAt(foo->compEnd)) & TypeMask])))) {
			error("problem creating free chunk after compaction");
		}
	}
	if ((objectAfter(newFreeChunk)) == foo->endOfMemory) {
		initializeMemoryFirstFree(newFreeChunk);
	} else {
		initializeMemoryFirstFree(foo->freeBlock);
	}
	return newFreeChunk;
}


/*	Return the equivalent of 
		aClass includesBehavior: aSuperclass.
	Note: written for efficiency and better inlining (only 1 temp) */

sqInt includesBehaviorThatOf(sqInt aClass, sqInt aSuperclass) {
register struct foo * foo = &fum;
    sqInt theClass;

	if (((theClass = aClass) == aSuperclass) || (aSuperclass == foo->nilObj)) {
		return 1;
	}
	do {
		if ((theClass = longAt((theClass + (BASE_HEADER_SIZE)) + (SuperclassIndex << (SHIFT_FOR_WORD)))) == aSuperclass) {
			return 1;
		}
	} while(theClass != foo->nilObj);
	return 0;
}


/*	Do a mark/sweep garbage collection of just the young object 
	area of object memory (i.e., objects above youngStart), using 
	the root table to identify objects containing pointers to 
	young objects from the old object area. */

sqInt incrementalGC(void) {
register struct foo * foo = &fum;
    sqInt i;
    sqLong startTime;
    sqInt survivorCount;
    sqInt weDidGrow;
    sqInt growth;
    sqInt i1;
    sqInt oop;
    sqInt activeCntx;
    sqInt valuePointer;
    sqInt valuePointer1;

	if (foo->rootTableCount >= RootTableSize) {

		/* root table overflow; cannot do an incremental GC (this should be very rare) */

		foo->statRootTableOverflows += 1;
		return fullGC();
	}
	if (DoAssertionChecks) {
		reverseDisplayFromto(8, 15);
		validateRoots();
		/* begin validate */
	}
	/* begin preGCAction: */
	if (foo->compilerInitialized) {
		compilerPreGC(0);
	} else {
		/* begin storeContextRegisters: */
		activeCntx = foo->activeContext;
		/* begin storePointerUnchecked:ofObject:withValue: */
		valuePointer = ((((foo->instructionPointer - foo->method) - ((BASE_HEADER_SIZE) - 2)) << 1) | 1);
		longAtput((activeCntx + (BASE_HEADER_SIZE)) + (InstructionPointerIndex << (SHIFT_FOR_WORD)), valuePointer);
		/* begin storePointerUnchecked:ofObject:withValue: */
		valuePointer1 = (((((((usqInt) ((foo->stackPointer - foo->activeContext) - (BASE_HEADER_SIZE))) >> (SHIFT_FOR_WORD)) - TempFrameStart) + 1) << 1) | 1);
		longAtput((activeCntx + (BASE_HEADER_SIZE)) + (StackPointerIndex << (SHIFT_FOR_WORD)), valuePointer1);
	}
	startTime = ioMicroSecondClock();
	foo->weakRootCount = 0;
	foo->statSweepCount = foo->statMarkCount = foo->statMkFwdCount = foo->statCompMoveCount = 0;
	markPhase();
	for (i = 1; i <= foo->weakRootCount; i += 1) {
		finalizeReference(foo->weakRoots[i]);
	}
	survivorCount = sweepPhase();
	/* begin incrementalCompaction */
	if (foo->compStart == foo->freeBlock) {
		initializeMemoryFirstFree(foo->freeBlock);
	} else {
		incCompBody();
	}
	foo->statAllocationCount = foo->allocationCount;
	foo->allocationCount = 0;
	foo->statIncrGCs += 1;
	foo->statGCTime = ioMicroSecondClock();
	foo->statIGCDeltaTime = foo->statGCTime - startTime;
	foo->statIncrGCMSecs += foo->statIGCDeltaTime;
	/* begin capturePendingFinalizationSignals */
	foo->statpendingFinalizationSignals = foo->pendingFinalizationSignals;
	/* begin forceInterruptCheck */
	foo->interruptCheckCounter = -1000;
	foo->nextPollTick = 0;
	foo->statRootTableCount = foo->rootTableCount;
	foo->statSurvivorCount = survivorCount;
	weDidGrow = 0;
	if (((survivorCount > foo->tenuringThreshold) || (foo->rootTableCount >= RootTableRedZone)) || (foo->forceTenureFlag == 1)) {

		/* move up the young space boundary if 
			* there are too many survivors: 
			this limits the number of objects that must be 
			processed on future incremental GC's 
			* we're about to overflow the roots table 
			this limits the number of full GCs that may be caused 
			by root table overflows in the near future */

		foo->forceTenureFlag = 0;
		foo->statTenures += 1;
		/* begin clearRootsTable */
		for (i1 = 1; i1 <= foo->rootTableCount; i1 += 1) {
			oop = foo->rootTable[i1];
			longAtput(oop, (longAt(oop)) & (ALL_BUT_ROOT_BIT));
			foo->rootTable[i1] = 0;
		}
		foo->rootTableCount = 0;
		if ((foo->freeBlock < foo->growHeadroom) && (foo->gcBiasToGrow > 0)) {
			biasToGrow();
			weDidGrow = 1;
		}
		foo->youngStart = foo->freeBlock;
	}
	postGCAction();
	if (DoAssertionChecks) {
		validateRoots();
		/* begin validate */
		reverseDisplayFromto(8, 15);
	}
	if (weDidGrow) {
		/* begin biasToGrowCheckGCLimit */
		growth = (foo->youngStart - memory) - foo->gcBiasToGrowThreshold;
		if (growth < 0) {
			foo->gcBiasToGrowThreshold = foo->youngStart - memory;
		}
		if (growth > foo->gcBiasToGrowGCLimit) {
			fullGC();
			foo->gcBiasToGrowThreshold = foo->youngStart - memory;
		}
	}
}


/*	Initialize hooks for the 'null compiler' */

sqInt initCompilerHooks(void) {
	compilerHooks[1]= nullCompilerHook;
	compilerHooks[2]= nullCompilerHook;
	compilerHooks[3]= nullCompilerHook;
	compilerHooks[4]= nullCompilerHook;
	compilerHooks[5]= nullCompilerHook;
	compilerHooks[6]= nullCompilerHook;
	compilerHooks[7]= nullCompilerHook;
	compilerHooks[8]= nullCompilerHook;
	compilerHooks[9]= nullCompilerHook;
	compilerHooks[10]= nullCompilerHook;
	compilerHooks[11]= nullCompilerHook;
	compilerHooks[12]= nullCompilerHook;
	compilerHooks[13]= nullCompilerHook;
	compilerHooks[14]= nullCompilerHook;
	foo->compilerInitialized = 0;
}


/*	Set the imageFormatVersionNumber to a default value for this word
	size. Normally this will have been set at image load time, but set it to
	a reasonable default if this has not been done. */

sqInt initializeImageFormatVersionIfNeeded(void) {
	if (imageFormatVersionNumber == 0) {
		if ((BYTES_PER_WORD) == 8) {
			imageFormatVersionNumber = 68000;
		} else {
			imageFormatVersionNumber = 6502;
		}
	}
}


/*	Initialize Interpreter state before starting execution of a new image. */

sqInt initializeInterpreter(sqInt bytesToShift) {
register struct foo * foo = &fum;
    sqInt i;
    sqInt i1;
    sqInt proc;
    sqInt sched;
    sqInt oop;
    sqInt oop1;
    sqInt activeCntx;
    sqInt tmp;

	interpreterProxy = sqGetInterpreterProxy();
	dummyReferToProxy();
	initializeObjectMemory(bytesToShift);
	initCompilerHooks();
	foo->activeContext = foo->nilObj;
	foo->theHomeContext = foo->nilObj;
	foo->method = foo->nilObj;
	foo->receiver = foo->nilObj;
	foo->messageSelector = foo->nilObj;
	foo->newMethod = foo->nilObj;
	foo->methodClass = foo->nilObj;
	foo->lkupClass = foo->nilObj;
	foo->receiverClass = foo->nilObj;
	foo->newNativeMethod = foo->nilObj;
	/* begin flushMethodCache */
	for (i = 1; i <= MethodCacheSize; i += 1) {
		foo->methodCache[i] = 0;
	}
	/* begin flushAtCache */
	for (i1 = 1; i1 <= AtCacheTotalSize; i1 += 1) {
		foo->atCache[i1] = 0;
	}
	/* begin loadInitialContext */
	/* begin fetchPointer:ofObject: */
	/* begin fetchPointer:ofObject: */
	oop1 = foo->specialObjectsOop;
	oop = longAt((oop1 + (BASE_HEADER_SIZE)) + (SchedulerAssociation << (SHIFT_FOR_WORD)));
	sched = longAt((oop + (BASE_HEADER_SIZE)) + (ValueIndex << (SHIFT_FOR_WORD)));
	proc = longAt((sched + (BASE_HEADER_SIZE)) + (ActiveProcessIndex << (SHIFT_FOR_WORD)));
	foo->activeContext = longAt((proc + (BASE_HEADER_SIZE)) + (SuspendedContextIndex << (SHIFT_FOR_WORD)));
	if ((((usqInt) foo->activeContext)) < (((usqInt) foo->youngStart))) {
		beRootIfOld(foo->activeContext);
	}
	/* begin fetchContextRegisters: */
	activeCntx = foo->activeContext;
	tmp = longAt((activeCntx + (BASE_HEADER_SIZE)) + (MethodIndex << (SHIFT_FOR_WORD)));
	if ((tmp & 1)) {
		tmp = longAt((activeCntx + (BASE_HEADER_SIZE)) + (HomeIndex << (SHIFT_FOR_WORD)));
		if ((((usqInt) tmp)) < (((usqInt) foo->youngStart))) {
			beRootIfOld(tmp);
		}
	} else {
		tmp = activeCntx;
	}
	foo->theHomeContext = tmp;
	foo->receiver = longAt((tmp + (BASE_HEADER_SIZE)) + (ReceiverIndex << (SHIFT_FOR_WORD)));
	foo->method = longAt((tmp + (BASE_HEADER_SIZE)) + (MethodIndex << (SHIFT_FOR_WORD)));
	tmp = ((longAt((activeCntx + (BASE_HEADER_SIZE)) + (InstructionPointerIndex << (SHIFT_FOR_WORD)))) >> 1);
	foo->instructionPointer = ((foo->method + tmp) + (BASE_HEADER_SIZE)) - 2;
	tmp = ((longAt((activeCntx + (BASE_HEADER_SIZE)) + (StackPointerIndex << (SHIFT_FOR_WORD)))) >> 1);
	foo->stackPointer = (activeCntx + (BASE_HEADER_SIZE)) + (((TempFrameStart + tmp) - 1) * (BYTES_PER_WORD));
	foo->reclaimableContextCount = 0;
	/* begin initialCleanup */
	if (((longAt(foo->activeContext)) & (ROOT_BIT)) == 0) {
		goto l1;
	}
	longAtput(foo->activeContext, (longAt(foo->activeContext)) & (ALL_BUT_ROOT_BIT));
	flushExternalPrimitives();
l1:	/* end initialCleanup */;
	foo->interruptCheckCounter = 0;
	foo->interruptCheckCounterFeedBackReset = 1000;
	foo->interruptChecksEveryNms = 1;
	foo->nextPollTick = 0;
	foo->nextWakeupTick = 0;
	foo->lastTick = 0;

	/* cmd-. as used for Mac but no other OS */

	foo->interruptKeycode = 2094;
	foo->interruptPending = 0;
	foo->semaphoresUseBufferA = 1;
	foo->semaphoresToSignalCountA = 0;
	foo->semaphoresToSignalCountB = 0;
	foo->deferDisplayUpdates = 0;
	foo->pendingFinalizationSignals = 0;
	foo->globalSessionID = 0;
	while (foo->globalSessionID == 0) {
		foo->globalSessionID = time(NULL) + ioMSecs();
	}
	foo->jmpDepth = 0;
	foo->jmpMax = MaxJumpBuf;
}


/*	Initialize endOfMemory to the top of oop storage space, reserving some space for forwarding blocks, and create the freeBlock from which space is allocated. Also create a fake free chunk at endOfMemory to act as a sentinal for memory scans.  */
/*	Note: The amount of space reserved for forwarding blocks should be chosen to ensure that incremental compactions can usually be done in a single pass. However, there should be enough forwarding blocks so a full compaction can be done in a reasonable number of passes, say ten. (A full compaction requires N object-moving passes, where N = number of non-garbage objects / number of forwarding blocks). 
	di 11/18/2000 Re totalObjectCount: Provide a margin of one byte per object to be used for forwarding pointers at GC time. Since fwd blocks are 8 bytes, this means an absolute worst case of 8 passes to compact memory. In most cases it will be adequate to do compaction in a single pass.  */

sqInt initializeMemoryFirstFree(usqInt firstFree) {
register struct foo * foo = &fum;
    usqInt fwdBlockBytes;


	/* reserve space for forwarding blocks */

	fwdBlockBytes = foo->totalObjectCount & (((WORD_MASK) - (BYTES_PER_WORD)) + 1);
	if (!((((usqInt) (foo->memoryLimit - fwdBlockBytes))) >= (((usqInt) (firstFree + (BASE_HEADER_SIZE)))))) {

		/* reserve enough space for a minimal free block of BaseHeaderSize bytes */

		fwdBlockBytes = foo->memoryLimit - (firstFree + (BASE_HEADER_SIZE));
	}
	foo->endOfMemory = foo->memoryLimit - fwdBlockBytes;
	foo->freeBlock = firstFree;
	/* begin setSizeOfFree:to: */
	longAtput(foo->freeBlock, ((foo->endOfMemory - firstFree) & (ALL_BUT_TYPE_MASK)) | HeaderTypeFree);
	/* begin setSizeOfFree:to: */
	longAtput(foo->endOfMemory, ((BASE_HEADER_SIZE) & (ALL_BUT_TYPE_MASK)) | HeaderTypeFree);
	if (DoAssertionChecks) {
		if (!((foo->freeBlock < foo->endOfMemory) && (foo->endOfMemory < foo->memoryLimit))) {
			error("error in free space computation");
		}
		if (!((foo->endOfMemory + (foo->headerTypeBytes[(longAt(foo->endOfMemory)) & TypeMask])) == foo->endOfMemory)) {
			error("header format must have changed");
		}
		if (!((objectAfter(foo->freeBlock)) == foo->endOfMemory)) {
			error("free block not properly initialized");
		}
	}
}


/*	Initialize object memory variables at startup time. Assume endOfMemory is initially set (by the image-reading code) to the end of the last object in the image. Initialization redefines endOfMemory to be the end of the object allocation area based on the total available memory, but reserving some space for forwarding blocks. */
/*	Assume: image reader initializes the following variables:
		memory
		endOfMemory
		memoryLimit
		specialObjectsOop
		lastHash
	 */
/*	di 11/18/2000 fix slow full GC */
/*	set the start of the young object space */

sqInt initializeObjectMemory(sqInt bytesToShift) {
register struct foo * foo = &fum;
    sqInt oop;
    sqInt oop1;
    sqInt oop2;


	/* image may be at a different address; adjust oops for new location */

	foo->youngStart = foo->endOfMemory;
	foo->totalObjectCount = adjustAllOopsBy(bytesToShift);
	initializeMemoryFirstFree(foo->endOfMemory);

	/* heavily used special objects */

	foo->specialObjectsOop += bytesToShift;
	/* begin fetchPointer:ofObject: */
	oop = foo->specialObjectsOop;
	foo->nilObj = longAt((oop + (BASE_HEADER_SIZE)) + (NilObject << (SHIFT_FOR_WORD)));
	/* begin fetchPointer:ofObject: */
	oop1 = foo->specialObjectsOop;
	foo->falseObj = longAt((oop1 + (BASE_HEADER_SIZE)) + (FalseObject << (SHIFT_FOR_WORD)));
	/* begin fetchPointer:ofObject: */
	oop2 = foo->specialObjectsOop;
	foo->trueObj = longAt((oop2 + (BASE_HEADER_SIZE)) + (TrueObject << (SHIFT_FOR_WORD)));
	foo->rootTableCount = 0;
	foo->freeContexts = NilContext;
	foo->freeLargeContexts = NilContext;
	foo->allocationCount = 0;
	foo->lowSpaceThreshold = 0;
	foo->signalLowSpace = 0;
	foo->compStart = 0;
	foo->compEnd = 0;
	foo->fwdTableNext = 0;
	foo->fwdTableLast = 0;
	foo->remapBufferCount = 0;

	/* do incremental GC after this many allocations */

	foo->allocationsBetweenGCs = 4000;

	/* tenure all suriving objects if count is over this threshold */

	foo->tenuringThreshold = 2000;

	/* four megabyte of headroom when growing */

	foo->growHeadroom = (4 * 1024) * 1024;

	/* eight megabyte of free space before shrinking */
	/* garbage collection statistics */

	foo->shrinkThreshold = (8 * 1024) * 1024;
	foo->statFullGCs = 0;
	foo->statFullGCMSecs = 0;
	foo->statIncrGCs = 0;
	foo->statIncrGCMSecs = 0;
	foo->statTenures = 0;
	foo->statRootTableOverflows = 0;
	foo->statGrowMemory = 0;
	foo->statShrinkMemory = 0;
	foo->forceTenureFlag = 0;
	foo->gcBiasToGrow = 0;
	foo->gcBiasToGrowGCLimit = 0;
	foo->extraRootCount = 0;
}


/*	Install the oop of this object in the given cache (at or atPut), along with
	its size, format and fixedSize */

sqInt installinAtCacheatstring(sqInt rcvr, sqInt *cache, sqInt atIx, sqInt stringy) {
register struct foo * foo = &fum;
    sqInt fixedFields;
    sqInt fmt;
    sqInt hdr;
    sqInt totalLength;
    sqInt sz;
    sqInt class;
    sqInt classFormat;
    sqInt ccIndex;
    sqInt oop1;
    sqInt oop2;
    sqInt oop3;

	hdr = longAt(rcvr);
	fmt = (((usqInt) hdr) >> 8) & 15;
	if ((fmt == 3) && ((((((usqInt) hdr) >> 12) & 31) == 13) || ((((((usqInt) hdr) >> 12) & 31) == 14) || (((((usqInt) hdr) >> 12) & 31) == 4)))) {
		/* begin primitiveFail */
		foo->successFlag = 0;
		return null;
	}
	/* begin lengthOf:baseHeader:format: */
	if ((hdr & TypeMask) == HeaderTypeSizeAndClass) {
		sz = (longAt(rcvr - ((BYTES_PER_WORD) * 2))) & (LONG_SIZE_MASK);
	} else {
		sz = hdr & (SIZE_MASK);
	}
	sz -= hdr & (SIZE_4_BIT);
	if (fmt <= 4) {
		totalLength = ((usqInt) (sz - (BASE_HEADER_SIZE))) >> (SHIFT_FOR_WORD);
		goto l1;
	}
	if (fmt < 8) {
		totalLength = ((usqInt) (sz - (BASE_HEADER_SIZE))) >> 2;
		goto l1;
	} else {
		totalLength = (sz - (BASE_HEADER_SIZE)) - (fmt & 3);
		goto l1;
	}
l1:	/* end lengthOf:baseHeader:format: */;
	/* begin fixedFieldsOf:format:length: */
	if ((fmt > 4) || (fmt == 2)) {
		fixedFields = 0;
		goto l3;
	}
	if (fmt < 2) {
		fixedFields = totalLength;
		goto l3;
	}
	/* begin fetchClassOf: */
	if ((rcvr & 1)) {
		/* begin fetchPointer:ofObject: */
		oop1 = foo->specialObjectsOop;
		class = longAt((oop1 + (BASE_HEADER_SIZE)) + (ClassInteger << (SHIFT_FOR_WORD)));
		goto l2;
	}
	ccIndex = (((usqInt) (longAt(rcvr))) >> 12) & 31;
	if (ccIndex == 0) {
		class = (longAt(rcvr - (BASE_HEADER_SIZE))) & (ALL_BUT_TYPE_MASK);
		goto l2;
	} else {
		/* begin fetchPointer:ofObject: */
		/* begin fetchPointer:ofObject: */
		oop3 = foo->specialObjectsOop;
		oop2 = longAt((oop3 + (BASE_HEADER_SIZE)) + (CompactClasses << (SHIFT_FOR_WORD)));
		class = longAt((oop2 + (BASE_HEADER_SIZE)) + ((ccIndex - 1) << (SHIFT_FOR_WORD)));
		goto l2;
	}
l2:	/* end fetchClassOf: */;
	classFormat = (longAt((class + (BASE_HEADER_SIZE)) + (InstanceSpecificationIndex << (SHIFT_FOR_WORD)))) - 1;
	fixedFields = (((((usqInt) classFormat) >> 11) & 192) + ((((usqInt) classFormat) >> 2) & 63)) - 1;
l3:	/* end fixedFieldsOf:format:length: */;
	cache[atIx + AtCacheOop] = rcvr;
	if (stringy) {
		cache[atIx + AtCacheFmt] = (fmt + 16);
	} else {
		cache[atIx + AtCacheFmt] = fmt;
	}
	cache[atIx + AtCacheFixedFields] = fixedFields;
	cache[atIx + AtCacheSize] = (totalLength - fixedFields);
}


/*	NOTE: This method supports the backward-compatible split instSize field of the 
	class format word. The sizeHiBits will go away and other shifts change by 2 
	when the split fields get merged in an (incompatible) image change. */

sqInt instantiateClassindexableSize(sqInt classPointer, sqInt size) {
register struct foo * foo = &fum;
    sqInt binc;
    sqInt bm1;
    sqInt byteSize;
    sqInt cClass;
    sqInt classFormat;
    sqInt fillWord;
    sqInt format;
    sqInt hash;
    sqInt hdrSize;
    sqInt header1;
    sqInt header2;
    sqInt header3;
    sqInt newObj;
    sqInt sizeHiBits;
    usqInt end;
    usqInt i;
    sqInt newObj1;
    sqInt remappedClassOop;
    sqInt enoughSpace;
    sqInt newChunk;
    sqInt newFreeSize;
    sqInt oop;
    usqInt minFree;
    sqInt currentProc;
    sqInt lastSavedProcess;
    sqInt sched;
    sqInt oop4;
    sqInt oop1;
    sqInt oop2;
    sqInt oop3;

	if (DoAssertionChecks) {
		if (size < 0) {
			error("cannot have a negative indexable field count");
		}
	}
	/* begin newObjectHash */
	foo->lastHash = (13849 + (27181 * foo->lastHash)) & 65535;
	hash = foo->lastHash;

	/* Low 2 bits are 0 */

	classFormat = (longAt((classPointer + (BASE_HEADER_SIZE)) + (InstanceSpecificationIndex << (SHIFT_FOR_WORD)))) - 1;
	header1 = (classFormat & 130816) | ((hash << HashBitsOffset) & HashBits);
	header2 = classPointer;
	header3 = 0;
	sizeHiBits = ((usqInt) (classFormat & 393216)) >> 9;

	/* compact class field from format word */

	cClass = header1 & CompactClassMask;

	/* size in bytes -- low 2 bits are 0 */
	/* Note this byteSize comes from the format word of the class which is pre-shifted
		to 4 bytes per field.  Need another shift for 8 bytes per word... */

	byteSize = (classFormat & ((SIZE_MASK) + (SIZE_4_BIT))) + sizeHiBits;
	byteSize = byteSize << ((SHIFT_FOR_WORD) - 2);
	format = (((usqInt) classFormat) >> 8) & 15;
	flag("sizeLowBits");
	if (format < 8) {
		if (format == 6) {

			/* long32 bitmaps */

			bm1 = (BYTES_PER_WORD) - 1;

			/* round up */

			byteSize = ((byteSize + (size * 4)) + bm1) & (LONG_SIZE_MASK);

			/* odd bytes */
			/* extra low bit (4) for 64-bit VM goes in 4-bit (betw hdr bits and sizeBits) */

			binc = bm1 - (((size * 4) + bm1) & bm1);
			header1 = header1 | (binc & 4);
		} else {

			/* Arrays and 64-bit bitmaps */

			byteSize += size * (BYTES_PER_WORD);
		}
	} else {

		/* Strings and Methods */

		bm1 = (BYTES_PER_WORD) - 1;

		/* round up */

		byteSize = ((byteSize + size) + bm1) & (LONG_SIZE_MASK);

		/* odd bytes */
		/* low bits of byte size go in format field */

		binc = bm1 - ((size + bm1) & bm1);

		/* extra low bit (4) for 64-bit VM goes in 4-bit (betw hdr bits and sizeBits) */

		header1 = header1 | ((binc & 3) << 8);
		header1 = header1 | (binc & 4);
	}
	if (byteSize > 255) {

		/* requires size header word */

		header3 = byteSize;
		header1 = header1;
	} else {
		header1 = header1 | byteSize;
	}
	if (header3 > 0) {

		/* requires full header */

		hdrSize = 3;
	} else {
		if (cClass == 0) {
			hdrSize = 2;
		} else {
			hdrSize = 1;
		}
	}
	if (format <= 4) {

		/* if pointers, fill with nil oop */

		fillWord = foo->nilObj;
	} else {
		fillWord = 0;
	}
	/* begin allocate:headerSize:h1:h2:h3:doFill:with: */
	if (hdrSize > 1) {
		/* begin pushRemappableOop: */
		foo->remapBuffer[(foo->remapBufferCount += 1)] = header2;
	}
	/* begin allocateChunk: */
	if (foo->allocationCount >= foo->allocationsBetweenGCs) {
		incrementalGC();
	}
	/* begin sufficientSpaceToAllocate: */
	minFree = (foo->lowSpaceThreshold + (byteSize + ((hdrSize - 1) * (BYTES_PER_WORD)))) + (BASE_HEADER_SIZE);
	if (oopisGreaterThanOrEqualTo((longAt(foo->freeBlock)) & (ALL_BUT_TYPE_MASK), minFree)) {
		enoughSpace = 1;
		goto l1;
	} else {
		enoughSpace = sufficientSpaceAfterGC(minFree);
		goto l1;
	}
l1:	/* end sufficientSpaceToAllocate: */;
	if (!(enoughSpace)) {
		foo->signalLowSpace = 1;
		foo->lowSpaceThreshold = 0;
		/* begin saveProcessSignalingLowSpace */
		/* begin fetchPointer:ofObject: */
		oop2 = foo->specialObjectsOop;
		lastSavedProcess = longAt((oop2 + (BASE_HEADER_SIZE)) + (ProcessSignalingLowSpace << (SHIFT_FOR_WORD)));
		if (lastSavedProcess == foo->nilObj) {
			/* begin fetchPointer:ofObject: */
			/* begin fetchPointer:ofObject: */
			oop3 = foo->specialObjectsOop;
			oop4 = longAt((oop3 + (BASE_HEADER_SIZE)) + (SchedulerAssociation << (SHIFT_FOR_WORD)));
			sched = longAt((oop4 + (BASE_HEADER_SIZE)) + (ValueIndex << (SHIFT_FOR_WORD)));
			currentProc = longAt((sched + (BASE_HEADER_SIZE)) + (ActiveProcessIndex << (SHIFT_FOR_WORD)));
			/* begin storePointer:ofObject:withValue: */
			oop1 = foo->specialObjectsOop;
			if ((((usqInt) oop1)) < (((usqInt) foo->youngStart))) {
				possibleRootStoreIntovalue(oop1, currentProc);
			}
			longAtput((oop1 + (BASE_HEADER_SIZE)) + (ProcessSignalingLowSpace << (SHIFT_FOR_WORD)), currentProc);
		}
		/* begin forceInterruptCheck */
		foo->interruptCheckCounter = -1000;
		foo->nextPollTick = 0;
	}
	if (oopisLessThan((longAt(foo->freeBlock)) & (ALL_BUT_TYPE_MASK), (byteSize + ((hdrSize - 1) * (BYTES_PER_WORD))) + (BASE_HEADER_SIZE))) {
		error("out of memory");
	}
	newFreeSize = ((longAt(foo->freeBlock)) & (ALL_BUT_TYPE_MASK)) - (byteSize + ((hdrSize - 1) * (BYTES_PER_WORD)));
	newChunk = foo->freeBlock;
	foo->freeBlock += byteSize + ((hdrSize - 1) * (BYTES_PER_WORD));
	/* begin setSizeOfFree:to: */
	longAtput(foo->freeBlock, (newFreeSize & (ALL_BUT_TYPE_MASK)) | HeaderTypeFree);
	foo->allocationCount += 1;
	newObj1 = newChunk;
	if (hdrSize > 1) {
		/* begin popRemappableOop */
		oop = foo->remapBuffer[foo->remapBufferCount];
		foo->remapBufferCount -= 1;
		remappedClassOop = oop;
	}
	if (hdrSize == 3) {
		longAtput(newObj1, header3 | HeaderTypeSizeAndClass);
		longAtput(newObj1 + (BYTES_PER_WORD), remappedClassOop | HeaderTypeSizeAndClass);
		longAtput(newObj1 + ((BYTES_PER_WORD) * 2), header1 | HeaderTypeSizeAndClass);
		newObj1 += (BYTES_PER_WORD) * 2;
	}
	if (hdrSize == 2) {
		longAtput(newObj1, remappedClassOop | HeaderTypeClass);
		longAtput(newObj1 + (BYTES_PER_WORD), header1 | HeaderTypeClass);
		newObj1 += BYTES_PER_WORD;
	}
	if (hdrSize == 1) {
		longAtput(newObj1, header1 | HeaderTypeShort);
	}
	if (1) {
		end = newObj1 + byteSize;
		i = newObj1 + (BYTES_PER_WORD);
		while (i < end) {
			longAtput(i, fillWord);
			i += BYTES_PER_WORD;
		}
	}
	if (DoAssertionChecks) {
		okayOop(newObj1);
		oopHasOkayClass(newObj1);
		if (!((objectAfter(newObj1)) == foo->freeBlock)) {
			error("allocate bug: did not set header of new oop correctly");
		}
		if (!((objectAfter(foo->freeBlock)) == foo->endOfMemory)) {
			error("allocate bug: did not set header of freeBlock correctly");
		}
	}
	newObj = newObj1;
	return newObj;
}


/*	This version of instantiateClass assumes that the total object 
	size is under 256 bytes, the limit for objects with only one or 
	two header words. Note that the size is specified in bytes 
	and should include four bytes for the base header word. */

sqInt instantiateContextsizeInBytes(sqInt classPointer, sqInt sizeInBytes) {
register struct foo * foo = &fum;
    sqInt hash;
    sqInt hdrSize;
    sqInt header1;
    sqInt header2;
    sqInt extendedSize;
    usqInt end;
    usqInt i;
    sqInt newObj;
    sqInt remappedClassOop;
    sqInt enoughSpace;
    sqInt newChunk;
    sqInt newFreeSize;
    sqInt oop;
    usqInt minFree;
    sqInt currentProc;
    sqInt lastSavedProcess;
    sqInt sched;
    sqInt oop4;
    sqInt oop1;
    sqInt oop2;
    sqInt oop3;

	/* begin newObjectHash */
	foo->lastHash = (13849 + (27181 * foo->lastHash)) & 65535;
	hash = foo->lastHash;
	header1 = ((hash << HashBitsOffset) & HashBits) | ((longAt((classPointer + (BASE_HEADER_SIZE)) + (InstanceSpecificationIndex << (SHIFT_FOR_WORD)))) - 1);
	header2 = classPointer;
	if ((header1 & CompactClassMask) > 0) {

		/* are contexts compact? */

		hdrSize = 1;
	} else {
		hdrSize = 2;
	}
	if (sizeInBytes <= (SIZE_MASK)) {

		/* OR size into header1.  Must not do this if size > SizeMask */

		header1 += sizeInBytes - (header1 & (SIZE_MASK));
	} else {

		/* Zero the size field of header1 if large */

		hdrSize = 3;
		header1 -= header1 & (SIZE_MASK);
	}
	flag("Dan");
	/* begin allocate:headerSize:h1:h2:h3:doFill:with: */
	extendedSize = LARGE_CONTEXT_SIZE;
	if (hdrSize > 1) {
		/* begin pushRemappableOop: */
		foo->remapBuffer[(foo->remapBufferCount += 1)] = header2;
	}
	/* begin allocateChunk: */
	if (foo->allocationCount >= foo->allocationsBetweenGCs) {
		incrementalGC();
	}
	/* begin sufficientSpaceToAllocate: */
	minFree = (foo->lowSpaceThreshold + (sizeInBytes + ((hdrSize - 1) * (BYTES_PER_WORD)))) + (BASE_HEADER_SIZE);
	if (oopisGreaterThanOrEqualTo((longAt(foo->freeBlock)) & (ALL_BUT_TYPE_MASK), minFree)) {
		enoughSpace = 1;
		goto l1;
	} else {
		enoughSpace = sufficientSpaceAfterGC(minFree);
		goto l1;
	}
l1:	/* end sufficientSpaceToAllocate: */;
	if (!(enoughSpace)) {
		foo->signalLowSpace = 1;
		foo->lowSpaceThreshold = 0;
		/* begin saveProcessSignalingLowSpace */
		/* begin fetchPointer:ofObject: */
		oop2 = foo->specialObjectsOop;
		lastSavedProcess = longAt((oop2 + (BASE_HEADER_SIZE)) + (ProcessSignalingLowSpace << (SHIFT_FOR_WORD)));
		if (lastSavedProcess == foo->nilObj) {
			/* begin fetchPointer:ofObject: */
			/* begin fetchPointer:ofObject: */
			oop3 = foo->specialObjectsOop;
			oop4 = longAt((oop3 + (BASE_HEADER_SIZE)) + (SchedulerAssociation << (SHIFT_FOR_WORD)));
			sched = longAt((oop4 + (BASE_HEADER_SIZE)) + (ValueIndex << (SHIFT_FOR_WORD)));
			currentProc = longAt((sched + (BASE_HEADER_SIZE)) + (ActiveProcessIndex << (SHIFT_FOR_WORD)));
			/* begin storePointer:ofObject:withValue: */
			oop1 = foo->specialObjectsOop;
			if ((((usqInt) oop1)) < (((usqInt) foo->youngStart))) {
				possibleRootStoreIntovalue(oop1, currentProc);
			}
			longAtput((oop1 + (BASE_HEADER_SIZE)) + (ProcessSignalingLowSpace << (SHIFT_FOR_WORD)), currentProc);
		}
		/* begin forceInterruptCheck */
		foo->interruptCheckCounter = -1000;
		foo->nextPollTick = 0;
	}
	if (oopisLessThan((longAt(foo->freeBlock)) & (ALL_BUT_TYPE_MASK), (sizeInBytes + ((hdrSize - 1) * (BYTES_PER_WORD))) + (BASE_HEADER_SIZE))) {
		error("out of memory");
	}
	newFreeSize = ((longAt(foo->freeBlock)) & (ALL_BUT_TYPE_MASK)) - (sizeInBytes + ((hdrSize - 1) * (BYTES_PER_WORD)));
	newChunk = foo->freeBlock;
	foo->freeBlock += sizeInBytes + ((hdrSize - 1) * (BYTES_PER_WORD));
	/* begin setSizeOfFree:to: */
	longAtput(foo->freeBlock, (newFreeSize & (ALL_BUT_TYPE_MASK)) | HeaderTypeFree);
	foo->allocationCount += 1;
	newObj = newChunk;
	if (hdrSize > 1) {
		/* begin popRemappableOop */
		oop = foo->remapBuffer[foo->remapBufferCount];
		foo->remapBufferCount -= 1;
		remappedClassOop = oop;
	}
	if (hdrSize == 3) {
		longAtput(newObj, extendedSize | HeaderTypeSizeAndClass);
		longAtput(newObj + (BYTES_PER_WORD), remappedClassOop | HeaderTypeSizeAndClass);
		longAtput(newObj + ((BYTES_PER_WORD) * 2), header1 | HeaderTypeSizeAndClass);
		newObj += (BYTES_PER_WORD) * 2;
	}
	if (hdrSize == 2) {
		longAtput(newObj, remappedClassOop | HeaderTypeClass);
		longAtput(newObj + (BYTES_PER_WORD), header1 | HeaderTypeClass);
		newObj += BYTES_PER_WORD;
	}
	if (hdrSize == 1) {
		longAtput(newObj, header1 | HeaderTypeShort);
	}
	if (0) {
		end = newObj + sizeInBytes;
		i = newObj + (BYTES_PER_WORD);
		while (i < end) {
			longAtput(i, 0);
			i += BYTES_PER_WORD;
		}
	}
	if (DoAssertionChecks) {
		okayOop(newObj);
		oopHasOkayClass(newObj);
		if (!((objectAfter(newObj)) == foo->freeBlock)) {
			error("allocate bug: did not set header of new oop correctly");
		}
		if (!((objectAfter(foo->freeBlock)) == foo->endOfMemory)) {
			error("allocate bug: did not set header of freeBlock correctly");
		}
	}
	return newObj;
}


/*	This version of instantiateClass assumes that the total object 
	size is under 256 bytes, the limit for objects with only one or 
	two header words. Note that the size is specified in bytes 
	and should include 4 or 8 bytes for the base header word. 
	NOTE this code will only work for sizes that are an integral number of words
		(like not a 32-bit LargeInteger in a 64-bit system). 
	May cause a GC.
	Note that the created small object IS NOT FILLED and must be completed before returning it to Squeak. Since this call is used in routines that do jsut that we are safe. Break this rule and die. */

sqInt instantiateSmallClasssizeInBytes(sqInt classPointer, sqInt sizeInBytes) {
register struct foo * foo = &fum;
    sqInt hash;
    sqInt hdrSize;
    sqInt header1;
    sqInt header2;
    usqInt end;
    usqInt i;
    sqInt newObj;
    sqInt remappedClassOop;
    sqInt enoughSpace;
    sqInt newChunk;
    sqInt newFreeSize;
    sqInt oop;
    usqInt minFree;
    sqInt currentProc;
    sqInt lastSavedProcess;
    sqInt sched;
    sqInt oop4;
    sqInt oop1;
    sqInt oop2;
    sqInt oop3;

	if (!((sizeInBytes & ((BYTES_PER_WORD) - 1)) == 0)) {
		error("size must be integral number of words");
	}
	/* begin newObjectHash */
	foo->lastHash = (13849 + (27181 * foo->lastHash)) & 65535;
	hash = foo->lastHash;
	header1 = ((hash << HashBitsOffset) & HashBits) | ((longAt((classPointer + (BASE_HEADER_SIZE)) + (InstanceSpecificationIndex << (SHIFT_FOR_WORD)))) - 1);
	header2 = classPointer;
	if ((header1 & CompactClassMask) > 0) {

		/* is this a compact class */

		hdrSize = 1;
	} else {
		hdrSize = 2;
	}
	header1 += sizeInBytes - (header1 & ((SIZE_MASK) + (SIZE_4_BIT)));
	/* begin allocate:headerSize:h1:h2:h3:doFill:with: */
	if (hdrSize > 1) {
		/* begin pushRemappableOop: */
		foo->remapBuffer[(foo->remapBufferCount += 1)] = header2;
	}
	/* begin allocateChunk: */
	if (foo->allocationCount >= foo->allocationsBetweenGCs) {
		incrementalGC();
	}
	/* begin sufficientSpaceToAllocate: */
	minFree = (foo->lowSpaceThreshold + (sizeInBytes + ((hdrSize - 1) * (BYTES_PER_WORD)))) + (BASE_HEADER_SIZE);
	if (oopisGreaterThanOrEqualTo((longAt(foo->freeBlock)) & (ALL_BUT_TYPE_MASK), minFree)) {
		enoughSpace = 1;
		goto l1;
	} else {
		enoughSpace = sufficientSpaceAfterGC(minFree);
		goto l1;
	}
l1:	/* end sufficientSpaceToAllocate: */;
	if (!(enoughSpace)) {
		foo->signalLowSpace = 1;
		foo->lowSpaceThreshold = 0;
		/* begin saveProcessSignalingLowSpace */
		/* begin fetchPointer:ofObject: */
		oop2 = foo->specialObjectsOop;
		lastSavedProcess = longAt((oop2 + (BASE_HEADER_SIZE)) + (ProcessSignalingLowSpace << (SHIFT_FOR_WORD)));
		if (lastSavedProcess == foo->nilObj) {
			/* begin fetchPointer:ofObject: */
			/* begin fetchPointer:ofObject: */
			oop3 = foo->specialObjectsOop;
			oop4 = longAt((oop3 + (BASE_HEADER_SIZE)) + (SchedulerAssociation << (SHIFT_FOR_WORD)));
			sched = longAt((oop4 + (BASE_HEADER_SIZE)) + (ValueIndex << (SHIFT_FOR_WORD)));
			currentProc = longAt((sched + (BASE_HEADER_SIZE)) + (ActiveProcessIndex << (SHIFT_FOR_WORD)));
			/* begin storePointer:ofObject:withValue: */
			oop1 = foo->specialObjectsOop;
			if ((((usqInt) oop1)) < (((usqInt) foo->youngStart))) {
				possibleRootStoreIntovalue(oop1, currentProc);
			}
			longAtput((oop1 + (BASE_HEADER_SIZE)) + (ProcessSignalingLowSpace << (SHIFT_FOR_WORD)), currentProc);
		}
		/* begin forceInterruptCheck */
		foo->interruptCheckCounter = -1000;
		foo->nextPollTick = 0;
	}
	if (oopisLessThan((longAt(foo->freeBlock)) & (ALL_BUT_TYPE_MASK), (sizeInBytes + ((hdrSize - 1) * (BYTES_PER_WORD))) + (BASE_HEADER_SIZE))) {
		error("out of memory");
	}
	newFreeSize = ((longAt(foo->freeBlock)) & (ALL_BUT_TYPE_MASK)) - (sizeInBytes + ((hdrSize - 1) * (BYTES_PER_WORD)));
	newChunk = foo->freeBlock;
	foo->freeBlock += sizeInBytes + ((hdrSize - 1) * (BYTES_PER_WORD));
	/* begin setSizeOfFree:to: */
	longAtput(foo->freeBlock, (newFreeSize & (ALL_BUT_TYPE_MASK)) | HeaderTypeFree);
	foo->allocationCount += 1;
	newObj = newChunk;
	if (hdrSize > 1) {
		/* begin popRemappableOop */
		oop = foo->remapBuffer[foo->remapBufferCount];
		foo->remapBufferCount -= 1;
		remappedClassOop = oop;
	}
	if (hdrSize == 3) {
		longAtput(newObj, 0 | HeaderTypeSizeAndClass);
		longAtput(newObj + (BYTES_PER_WORD), remappedClassOop | HeaderTypeSizeAndClass);
		longAtput(newObj + ((BYTES_PER_WORD) * 2), header1 | HeaderTypeSizeAndClass);
		newObj += (BYTES_PER_WORD) * 2;
	}
	if (hdrSize == 2) {
		longAtput(newObj, remappedClassOop | HeaderTypeClass);
		longAtput(newObj + (BYTES_PER_WORD), header1 | HeaderTypeClass);
		newObj += BYTES_PER_WORD;
	}
	if (hdrSize == 1) {
		longAtput(newObj, header1 | HeaderTypeShort);
	}
	if (0) {
		end = newObj + sizeInBytes;
		i = newObj + (BYTES_PER_WORD);
		while (i < end) {
			longAtput(i, 0);
			i += BYTES_PER_WORD;
		}
	}
	if (DoAssertionChecks) {
		okayOop(newObj);
		oopHasOkayClass(newObj);
		if (!((objectAfter(newObj)) == foo->freeBlock)) {
			error("allocate bug: did not set header of new oop correctly");
		}
		if (!((objectAfter(foo->freeBlock)) == foo->endOfMemory)) {
			error("allocate bug: did not set header of freeBlock correctly");
		}
	}
	return newObj;
}

sqInt integerObjectOf(sqInt value) {
	return (value << 1) + 1;
}


/*	Translator produces 'objectPointer >> 1' */

sqInt integerValueOf(sqInt objectPointer) {
	if ((objectPointer & 2147483648U) != 0) {
		return ((((usqInt) (objectPointer & 2147483647U)) >> 1) - 1073741823) - 1;
	} else {
		return ((usqInt) objectPointer) >> 1;
	}
}

EXPORT(sqInt) internalIsImmutable(sqInt oop) {
	return 0;
}

EXPORT(sqInt) internalIsMutable(sqInt oop) {
	return 1;
}


/*	This is the main interpreter loop. It normally loops forever, fetching and executing bytecodes. When running in the context of a browser plugin VM, however, it must return control to the browser periodically. This should done only when the state of the currently running Squeak thread is safely stored in the object heap. Since this is the case at the moment that a check for interrupts is performed, that is when we return to the browser if it is time to do so. Interrupt checks happen quite frequently. */
/*	should not be inlined into any senders */
/*	record entry time when running as a browser plug-in */

sqInt interpret(void) {
register struct foo * foo = &fum;
    sqInt localReturnValue;
    sqInt localReturnContext;
    sqInt localHomeContext;
    char* localSP;
    char* localIP;
    sqInt currentBytecode;

	browserPluginInitialiseIfNeeded();
	initializeImageFormatVersionIfNeeded();
	/* begin internalizeIPandSP */
	localIP = pointerForOop(foo->instructionPointer);
	localSP = pointerForOop(foo->stackPointer);
	localHomeContext = foo->theHomeContext;
	/* begin fetchNextBytecode */
	currentBytecode = byteAtPointer(++localIP);
	while (1) {
		switch (currentBytecode) {
		case 0:
			/* pushReceiverVariableBytecode */
			{
				sqInt fieldIndex;
				sqInt object;
				sqInt oop;
				flag("requires currentBytecode to be expanded to a constant");
				/* begin fetchNextBytecode */
				currentBytecode = byteAtPointer(++localIP);
				/* begin pushReceiverVariable: */
				fieldIndex = 0 & 15;
				/* begin internalPush: */
				/* begin fetchPointer:ofObject: */
				oop = foo->receiver;
				object = longAt((oop + (BASE_HEADER_SIZE)) + (fieldIndex << (SHIFT_FOR_WORD)));
				longAtPointerput(localSP += BYTES_PER_WORD, object);
			}
;
			break;
		case 1:
			/* pushReceiverVariableBytecode */
			{
				sqInt fieldIndex;
				sqInt object;
				sqInt oop;
				flag("requires currentBytecode to be expanded to a constant");
				/* begin fetchNextBytecode */
				currentBytecode = byteAtPointer(++localIP);
				/* begin pushReceiverVariable: */
				fieldIndex = 1 & 15;
				/* begin internalPush: */
				/* begin fetchPointer:ofObject: */
				oop = foo->receiver;
				object = longAt((oop + (BASE_HEADER_SIZE)) + (fieldIndex << (SHIFT_FOR_WORD)));
				longAtPointerput(localSP += BYTES_PER_WORD, object);
			}
;
			break;
		case 2:
			/* pushReceiverVariableBytecode */
			{
				sqInt fieldIndex;
				sqInt object;
				sqInt oop;
				flag("requires currentBytecode to be expanded to a constant");
				/* begin fetchNextBytecode */
				currentBytecode = byteAtPointer(++localIP);
				/* begin pushReceiverVariable: */
				fieldIndex = 2 & 15;
				/* begin internalPush: */
				/* begin fetchPointer:ofObject: */
				oop = foo->receiver;
				object = longAt((oop + (BASE_HEADER_SIZE)) + (fieldIndex << (SHIFT_FOR_WORD)));
				longAtPointerput(localSP += BYTES_PER_WORD, object);
			}
;
			break;
		case 3:
			/* pushReceiverVariableBytecode */
			{
				sqInt fieldIndex;
				sqInt object;
				sqInt oop;
				flag("requires currentBytecode to be expanded to a constant");
				/* begin fetchNextBytecode */
				currentBytecode = byteAtPointer(++localIP);
				/* begin pushReceiverVariable: */
				fieldIndex = 3 & 15;
				/* begin internalPush: */
				/* begin fetchPointer:ofObject: */
				oop = foo->receiver;
				object = longAt((oop + (BASE_HEADER_SIZE)) + (fieldIndex << (SHIFT_FOR_WORD)));
				longAtPointerput(localSP += BYTES_PER_WORD, object);
			}
;
			break;
		case 4:
			/* pushReceiverVariableBytecode */
			{
				sqInt fieldIndex;
				sqInt object;
				sqInt oop;
				flag("requires currentBytecode to be expanded to a constant");
				/* begin fetchNextBytecode */
				currentBytecode = byteAtPointer(++localIP);
				/* begin pushReceiverVariable: */
				fieldIndex = 4 & 15;
				/* begin internalPush: */
				/* begin fetchPointer:ofObject: */
				oop = foo->receiver;
				object = longAt((oop + (BASE_HEADER_SIZE)) + (fieldIndex << (SHIFT_FOR_WORD)));
				longAtPointerput(localSP += BYTES_PER_WORD, object);
			}
;
			break;
		case 5:
			/* pushReceiverVariableBytecode */
			{
				sqInt fieldIndex;
				sqInt object;
				sqInt oop;
				flag("requires currentBytecode to be expanded to a constant");
				/* begin fetchNextBytecode */
				currentBytecode = byteAtPointer(++localIP);
				/* begin pushReceiverVariable: */
				fieldIndex = 5 & 15;
				/* begin internalPush: */
				/* begin fetchPointer:ofObject: */
				oop = foo->receiver;
				object = longAt((oop + (BASE_HEADER_SIZE)) + (fieldIndex << (SHIFT_FOR_WORD)));
				longAtPointerput(localSP += BYTES_PER_WORD, object);
			}
;
			break;
		case 6:
			/* pushReceiverVariableBytecode */
			{
				sqInt fieldIndex;
				sqInt object;
				sqInt oop;
				flag("requires currentBytecode to be expanded to a constant");
				/* begin fetchNextBytecode */
				currentBytecode = byteAtPointer(++localIP);
				/* begin pushReceiverVariable: */
				fieldIndex = 6 & 15;
				/* begin internalPush: */
				/* begin fetchPointer:ofObject: */
				oop = foo->receiver;
				object = longAt((oop + (BASE_HEADER_SIZE)) + (fieldIndex << (SHIFT_FOR_WORD)));
				longAtPointerput(localSP += BYTES_PER_WORD, object);
			}
;
			break;
		case 7:
			/* pushReceiverVariableBytecode */
			{
				sqInt fieldIndex;
				sqInt object;
				sqInt oop;
				flag("requires currentBytecode to be expanded to a constant");
				/* begin fetchNextBytecode */
				currentBytecode = byteAtPointer(++localIP);
				/* begin pushReceiverVariable: */
				fieldIndex = 7 & 15;
				/* begin internalPush: */
				/* begin fetchPointer:ofObject: */
				oop = foo->receiver;
				object = longAt((oop + (BASE_HEADER_SIZE)) + (fieldIndex << (SHIFT_FOR_WORD)));
				longAtPointerput(localSP += BYTES_PER_WORD, object);
			}
;
			break;
		case 8:
			/* pushReceiverVariableBytecode */
			{
				sqInt fieldIndex;
				sqInt object;
				sqInt oop;
				flag("requires currentBytecode to be expanded to a constant");
				/* begin fetchNextBytecode */
				currentBytecode = byteAtPointer(++localIP);
				/* begin pushReceiverVariable: */
				fieldIndex = 8 & 15;
				/* begin internalPush: */
				/* begin fetchPointer:ofObject: */
				oop = foo->receiver;
				object = longAt((oop + (BASE_HEADER_SIZE)) + (fieldIndex << (SHIFT_FOR_WORD)));
				longAtPointerput(localSP += BYTES_PER_WORD, object);
			}
;
			break;
		case 9:
			/* pushReceiverVariableBytecode */
			{
				sqInt fieldIndex;
				sqInt object;
				sqInt oop;
				flag("requires currentBytecode to be expanded to a constant");
				/* begin fetchNextBytecode */
				currentBytecode = byteAtPointer(++localIP);
				/* begin pushReceiverVariable: */
				fieldIndex = 9 & 15;
				/* begin internalPush: */
				/* begin fetchPointer:ofObject: */
				oop = foo->receiver;
				object = longAt((oop + (BASE_HEADER_SIZE)) + (fieldIndex << (SHIFT_FOR_WORD)));
				longAtPointerput(localSP += BYTES_PER_WORD, object);
			}
;
			break;
		case 10:
			/* pushReceiverVariableBytecode */
			{
				sqInt fieldIndex;
				sqInt object;
				sqInt oop;
				flag("requires currentBytecode to be expanded to a constant");
				/* begin fetchNextBytecode */
				currentBytecode = byteAtPointer(++localIP);
				/* begin pushReceiverVariable: */
				fieldIndex = 10 & 15;
				/* begin internalPush: */
				/* begin fetchPointer:ofObject: */
				oop = foo->receiver;
				object = longAt((oop + (BASE_HEADER_SIZE)) + (fieldIndex << (SHIFT_FOR_WORD)));
				longAtPointerput(localSP += BYTES_PER_WORD, object);
			}
;
			break;
		case 11:
			/* pushReceiverVariableBytecode */
			{
				sqInt fieldIndex;
				sqInt object;
				sqInt oop;
				flag("requires currentBytecode to be expanded to a constant");
				/* begin fetchNextBytecode */
				currentBytecode = byteAtPointer(++localIP);
				/* begin pushReceiverVariable: */
				fieldIndex = 11 & 15;
				/* begin internalPush: */
				/* begin fetchPointer:ofObject: */
				oop = foo->receiver;
				object = longAt((oop + (BASE_HEADER_SIZE)) + (fieldIndex << (SHIFT_FOR_WORD)));
				longAtPointerput(localSP += BYTES_PER_WORD, object);
			}
;
			break;
		case 12:
			/* pushReceiverVariableBytecode */
			{
				sqInt fieldIndex;
				sqInt object;
				sqInt oop;
				flag("requires currentBytecode to be expanded to a constant");
				/* begin fetchNextBytecode */
				currentBytecode = byteAtPointer(++localIP);
				/* begin pushReceiverVariable: */
				fieldIndex = 12 & 15;
				/* begin internalPush: */
				/* begin fetchPointer:ofObject: */
				oop = foo->receiver;
				object = longAt((oop + (BASE_HEADER_SIZE)) + (fieldIndex << (SHIFT_FOR_WORD)));
				longAtPointerput(localSP += BYTES_PER_WORD, object);
			}
;
			break;
		case 13:
			/* pushReceiverVariableBytecode */
			{
				sqInt fieldIndex;
				sqInt object;
				sqInt oop;
				flag("requires currentBytecode to be expanded to a constant");
				/* begin fetchNextBytecode */
				currentBytecode = byteAtPointer(++localIP);
				/* begin pushReceiverVariable: */
				fieldIndex = 13 & 15;
				/* begin internalPush: */
				/* begin fetchPointer:ofObject: */
				oop = foo->receiver;
				object = longAt((oop + (BASE_HEADER_SIZE)) + (fieldIndex << (SHIFT_FOR_WORD)));
				longAtPointerput(localSP += BYTES_PER_WORD, object);
			}
;
			break;
		case 14:
			/* pushReceiverVariableBytecode */
			{
				sqInt fieldIndex;
				sqInt object;
				sqInt oop;
				flag("requires currentBytecode to be expanded to a constant");
				/* begin fetchNextBytecode */
				currentBytecode = byteAtPointer(++localIP);
				/* begin pushReceiverVariable: */
				fieldIndex = 14 & 15;
				/* begin internalPush: */
				/* begin fetchPointer:ofObject: */
				oop = foo->receiver;
				object = longAt((oop + (BASE_HEADER_SIZE)) + (fieldIndex << (SHIFT_FOR_WORD)));
				longAtPointerput(localSP += BYTES_PER_WORD, object);
			}
;
			break;
		case 15:
			/* pushReceiverVariableBytecode */
			{
				sqInt fieldIndex;
				sqInt object;
				sqInt oop;
				flag("requires currentBytecode to be expanded to a constant");
				/* begin fetchNextBytecode */
				currentBytecode = byteAtPointer(++localIP);
				/* begin pushReceiverVariable: */
				fieldIndex = 15 & 15;
				/* begin internalPush: */
				/* begin fetchPointer:ofObject: */
				oop = foo->receiver;
				object = longAt((oop + (BASE_HEADER_SIZE)) + (fieldIndex << (SHIFT_FOR_WORD)));
				longAtPointerput(localSP += BYTES_PER_WORD, object);
			}
;
			break;
		case 16:
			/* pushTemporaryVariableBytecode */
			{
				sqInt temporaryIndex;
				sqInt object;
				sqInt oop;
				flag("requires currentBytecode to be expanded to a constant");
				/* begin fetchNextBytecode */
				currentBytecode = byteAtPointer(++localIP);
				/* begin pushTemporaryVariable: */
				temporaryIndex = 16 & 15;
				/* begin internalPush: */
				/* begin fetchPointer:ofObject: */
				oop = localHomeContext;
				object = longAt((oop + (BASE_HEADER_SIZE)) + ((temporaryIndex + TempFrameStart) << (SHIFT_FOR_WORD)));
				longAtPointerput(localSP += BYTES_PER_WORD, object);
			}
;
			break;
		case 17:
			/* pushTemporaryVariableBytecode */
			{
				sqInt temporaryIndex;
				sqInt object;
				sqInt oop;
				flag("requires currentBytecode to be expanded to a constant");
				/* begin fetchNextBytecode */
				currentBytecode = byteAtPointer(++localIP);
				/* begin pushTemporaryVariable: */
				temporaryIndex = 17 & 15;
				/* begin internalPush: */
				/* begin fetchPointer:ofObject: */
				oop = localHomeContext;
				object = longAt((oop + (BASE_HEADER_SIZE)) + ((temporaryIndex + TempFrameStart) << (SHIFT_FOR_WORD)));
				longAtPointerput(localSP += BYTES_PER_WORD, object);
			}
;
			break;
		case 18:
			/* pushTemporaryVariableBytecode */
			{
				sqInt temporaryIndex;
				sqInt object;
				sqInt oop;
				flag("requires currentBytecode to be expanded to a constant");
				/* begin fetchNextBytecode */
				currentBytecode = byteAtPointer(++localIP);
				/* begin pushTemporaryVariable: */
				temporaryIndex = 18 & 15;
				/* begin internalPush: */
				/* begin fetchPointer:ofObject: */
				oop = localHomeContext;
				object = longAt((oop + (BASE_HEADER_SIZE)) + ((temporaryIndex + TempFrameStart) << (SHIFT_FOR_WORD)));
				longAtPointerput(localSP += BYTES_PER_WORD, object);
			}
;
			break;
		case 19:
			/* pushTemporaryVariableBytecode */
			{
				sqInt temporaryIndex;
				sqInt object;
				sqInt oop;
				flag("requires currentBytecode to be expanded to a constant");
				/* begin fetchNextBytecode */
				currentBytecode = byteAtPointer(++localIP);
				/* begin pushTemporaryVariable: */
				temporaryIndex = 19 & 15;
				/* begin internalPush: */
				/* begin fetchPointer:ofObject: */
				oop = localHomeContext;
				object = longAt((oop + (BASE_HEADER_SIZE)) + ((temporaryIndex + TempFrameStart) << (SHIFT_FOR_WORD)));
				longAtPointerput(localSP += BYTES_PER_WORD, object);
			}
;
			break;
		case 20:
			/* pushTemporaryVariableBytecode */
			{
				sqInt temporaryIndex;
				sqInt object;
				sqInt oop;
				flag("requires currentBytecode to be expanded to a constant");
				/* begin fetchNextBytecode */
				currentBytecode = byteAtPointer(++localIP);
				/* begin pushTemporaryVariable: */
				temporaryIndex = 20 & 15;
				/* begin internalPush: */
				/* begin fetchPointer:ofObject: */
				oop = localHomeContext;
				object = longAt((oop + (BASE_HEADER_SIZE)) + ((temporaryIndex + TempFrameStart) << (SHIFT_FOR_WORD)));
				longAtPointerput(localSP += BYTES_PER_WORD, object);
			}
;
			break;
		case 21:
			/* pushTemporaryVariableBytecode */
			{
				sqInt temporaryIndex;
				sqInt object;
				sqInt oop;
				flag("requires currentBytecode to be expanded to a constant");
				/* begin fetchNextBytecode */
				currentBytecode = byteAtPointer(++localIP);
				/* begin pushTemporaryVariable: */
				temporaryIndex = 21 & 15;
				/* begin internalPush: */
				/* begin fetchPointer:ofObject: */
				oop = localHomeContext;
				object = longAt((oop + (BASE_HEADER_SIZE)) + ((temporaryIndex + TempFrameStart) << (SHIFT_FOR_WORD)));
				longAtPointerput(localSP += BYTES_PER_WORD, object);
			}
;
			break;
		case 22:
			/* pushTemporaryVariableBytecode */
			{
				sqInt temporaryIndex;
				sqInt object;
				sqInt oop;
				flag("requires currentBytecode to be expanded to a constant");
				/* begin fetchNextBytecode */
				currentBytecode = byteAtPointer(++localIP);
				/* begin pushTemporaryVariable: */
				temporaryIndex = 22 & 15;
				/* begin internalPush: */
				/* begin fetchPointer:ofObject: */
				oop = localHomeContext;
				object = longAt((oop + (BASE_HEADER_SIZE)) + ((temporaryIndex + TempFrameStart) << (SHIFT_FOR_WORD)));
				longAtPointerput(localSP += BYTES_PER_WORD, object);
			}
;
			break;
		case 23:
			/* pushTemporaryVariableBytecode */
			{
				sqInt temporaryIndex;
				sqInt object;
				sqInt oop;
				flag("requires currentBytecode to be expanded to a constant");
				/* begin fetchNextBytecode */
				currentBytecode = byteAtPointer(++localIP);
				/* begin pushTemporaryVariable: */
				temporaryIndex = 23 & 15;
				/* begin internalPush: */
				/* begin fetchPointer:ofObject: */
				oop = localHomeContext;
				object = longAt((oop + (BASE_HEADER_SIZE)) + ((temporaryIndex + TempFrameStart) << (SHIFT_FOR_WORD)));
				longAtPointerput(localSP += BYTES_PER_WORD, object);
			}
;
			break;
		case 24:
			/* pushTemporaryVariableBytecode */
			{
				sqInt temporaryIndex;
				sqInt object;
				sqInt oop;
				flag("requires currentBytecode to be expanded to a constant");
				/* begin fetchNextBytecode */
				currentBytecode = byteAtPointer(++localIP);
				/* begin pushTemporaryVariable: */
				temporaryIndex = 24 & 15;
				/* begin internalPush: */
				/* begin fetchPointer:ofObject: */
				oop = localHomeContext;
				object = longAt((oop + (BASE_HEADER_SIZE)) + ((temporaryIndex + TempFrameStart) << (SHIFT_FOR_WORD)));
				longAtPointerput(localSP += BYTES_PER_WORD, object);
			}
;
			break;
		case 25:
			/* pushTemporaryVariableBytecode */
			{
				sqInt temporaryIndex;
				sqInt object;
				sqInt oop;
				flag("requires currentBytecode to be expanded to a constant");
				/* begin fetchNextBytecode */
				currentBytecode = byteAtPointer(++localIP);
				/* begin pushTemporaryVariable: */
				temporaryIndex = 25 & 15;
				/* begin internalPush: */
				/* begin fetchPointer:ofObject: */
				oop = localHomeContext;
				object = longAt((oop + (BASE_HEADER_SIZE)) + ((temporaryIndex + TempFrameStart) << (SHIFT_FOR_WORD)));
				longAtPointerput(localSP += BYTES_PER_WORD, object);
			}
;
			break;
		case 26:
			/* pushTemporaryVariableBytecode */
			{
				sqInt temporaryIndex;
				sqInt object;
				sqInt oop;
				flag("requires currentBytecode to be expanded to a constant");
				/* begin fetchNextBytecode */
				currentBytecode = byteAtPointer(++localIP);
				/* begin pushTemporaryVariable: */
				temporaryIndex = 26 & 15;
				/* begin internalPush: */
				/* begin fetchPointer:ofObject: */
				oop = localHomeContext;
				object = longAt((oop + (BASE_HEADER_SIZE)) + ((temporaryIndex + TempFrameStart) << (SHIFT_FOR_WORD)));
				longAtPointerput(localSP += BYTES_PER_WORD, object);
			}
;
			break;
		case 27:
			/* pushTemporaryVariableBytecode */
			{
				sqInt temporaryIndex;
				sqInt object;
				sqInt oop;
				flag("requires currentBytecode to be expanded to a constant");
				/* begin fetchNextBytecode */
				currentBytecode = byteAtPointer(++localIP);
				/* begin pushTemporaryVariable: */
				temporaryIndex = 27 & 15;
				/* begin internalPush: */
				/* begin fetchPointer:ofObject: */
				oop = localHomeContext;
				object = longAt((oop + (BASE_HEADER_SIZE)) + ((temporaryIndex + TempFrameStart) << (SHIFT_FOR_WORD)));
				longAtPointerput(localSP += BYTES_PER_WORD, object);
			}
;
			break;
		case 28:
			/* pushTemporaryVariableBytecode */
			{
				sqInt temporaryIndex;
				sqInt object;
				sqInt oop;
				flag("requires currentBytecode to be expanded to a constant");
				/* begin fetchNextBytecode */
				currentBytecode = byteAtPointer(++localIP);
				/* begin pushTemporaryVariable: */
				temporaryIndex = 28 & 15;
				/* begin internalPush: */
				/* begin fetchPointer:ofObject: */
				oop = localHomeContext;
				object = longAt((oop + (BASE_HEADER_SIZE)) + ((temporaryIndex + TempFrameStart) << (SHIFT_FOR_WORD)));
				longAtPointerput(localSP += BYTES_PER_WORD, object);
			}
;
			break;
		case 29:
			/* pushTemporaryVariableBytecode */
			{
				sqInt temporaryIndex;
				sqInt object;
				sqInt oop;
				flag("requires currentBytecode to be expanded to a constant");
				/* begin fetchNextBytecode */
				currentBytecode = byteAtPointer(++localIP);
				/* begin pushTemporaryVariable: */
				temporaryIndex = 29 & 15;
				/* begin internalPush: */
				/* begin fetchPointer:ofObject: */
				oop = localHomeContext;
				object = longAt((oop + (BASE_HEADER_SIZE)) + ((temporaryIndex + TempFrameStart) << (SHIFT_FOR_WORD)));
				longAtPointerput(localSP += BYTES_PER_WORD, object);
			}
;
			break;
		case 30:
			/* pushTemporaryVariableBytecode */
			{
				sqInt temporaryIndex;
				sqInt object;
				sqInt oop;
				flag("requires currentBytecode to be expanded to a constant");
				/* begin fetchNextBytecode */
				currentBytecode = byteAtPointer(++localIP);
				/* begin pushTemporaryVariable: */
				temporaryIndex = 30 & 15;
				/* begin internalPush: */
				/* begin fetchPointer:ofObject: */
				oop = localHomeContext;
				object = longAt((oop + (BASE_HEADER_SIZE)) + ((temporaryIndex + TempFrameStart) << (SHIFT_FOR_WORD)));
				longAtPointerput(localSP += BYTES_PER_WORD, object);
			}
;
			break;
		case 31:
			/* pushTemporaryVariableBytecode */
			{
				sqInt temporaryIndex;
				sqInt object;
				sqInt oop;
				flag("requires currentBytecode to be expanded to a constant");
				/* begin fetchNextBytecode */
				currentBytecode = byteAtPointer(++localIP);
				/* begin pushTemporaryVariable: */
				temporaryIndex = 31 & 15;
				/* begin internalPush: */
				/* begin fetchPointer:ofObject: */
				oop = localHomeContext;
				object = longAt((oop + (BASE_HEADER_SIZE)) + ((temporaryIndex + TempFrameStart) << (SHIFT_FOR_WORD)));
				longAtPointerput(localSP += BYTES_PER_WORD, object);
			}
;
			break;
		case 32:
			/* pushLiteralConstantBytecode */
			{
				sqInt literalIndex;
				sqInt object;
				sqInt methodPointer;
				flag("requires currentBytecode to be expanded to a constant");
				/* begin fetchNextBytecode */
				currentBytecode = byteAtPointer(++localIP);
				/* begin pushLiteralConstant: */
				literalIndex = 32 & 31;
				/* begin internalPush: */
				/* begin literal:ofMethod: */
				methodPointer = foo->method;
				object = longAt((methodPointer + (BASE_HEADER_SIZE)) + ((literalIndex + LiteralStart) << (SHIFT_FOR_WORD)));
				longAtPointerput(localSP += BYTES_PER_WORD, object);
			}
;
			break;
		case 33:
			/* pushLiteralConstantBytecode */
			{
				sqInt literalIndex;
				sqInt object;
				sqInt methodPointer;
				flag("requires currentBytecode to be expanded to a constant");
				/* begin fetchNextBytecode */
				currentBytecode = byteAtPointer(++localIP);
				/* begin pushLiteralConstant: */
				literalIndex = 33 & 31;
				/* begin internalPush: */
				/* begin literal:ofMethod: */
				methodPointer = foo->method;
				object = longAt((methodPointer + (BASE_HEADER_SIZE)) + ((literalIndex + LiteralStart) << (SHIFT_FOR_WORD)));
				longAtPointerput(localSP += BYTES_PER_WORD, object);
			}
;
			break;
		case 34:
			/* pushLiteralConstantBytecode */
			{
				sqInt literalIndex;
				sqInt object;
				sqInt methodPointer;
				flag("requires currentBytecode to be expanded to a constant");
				/* begin fetchNextBytecode */
				currentBytecode = byteAtPointer(++localIP);
				/* begin pushLiteralConstant: */
				literalIndex = 34 & 31;
				/* begin internalPush: */
				/* begin literal:ofMethod: */
				methodPointer = foo->method;
				object = longAt((methodPointer + (BASE_HEADER_SIZE)) + ((literalIndex + LiteralStart) << (SHIFT_FOR_WORD)));
				longAtPointerput(localSP += BYTES_PER_WORD, object);
			}
;
			break;
		case 35:
			/* pushLiteralConstantBytecode */
			{
				sqInt literalIndex;
				sqInt object;
				sqInt methodPointer;
				flag("requires currentBytecode to be expanded to a constant");
				/* begin fetchNextBytecode */
				currentBytecode = byteAtPointer(++localIP);
				/* begin pushLiteralConstant: */
				literalIndex = 35 & 31;
				/* begin internalPush: */
				/* begin literal:ofMethod: */
				methodPointer = foo->method;
				object = longAt((methodPointer + (BASE_HEADER_SIZE)) + ((literalIndex + LiteralStart) << (SHIFT_FOR_WORD)));
				longAtPointerput(localSP += BYTES_PER_WORD, object);
			}
;
			break;
		case 36:
			/* pushLiteralConstantBytecode */
			{
				sqInt literalIndex;
				sqInt object;
				sqInt methodPointer;
				flag("requires currentBytecode to be expanded to a constant");
				/* begin fetchNextBytecode */
				currentBytecode = byteAtPointer(++localIP);
				/* begin pushLiteralConstant: */
				literalIndex = 36 & 31;
				/* begin internalPush: */
				/* begin literal:ofMethod: */
				methodPointer = foo->method;
				object = longAt((methodPointer + (BASE_HEADER_SIZE)) + ((literalIndex + LiteralStart) << (SHIFT_FOR_WORD)));
				longAtPointerput(localSP += BYTES_PER_WORD, object);
			}
;
			break;
		case 37:
			/* pushLiteralConstantBytecode */
			{
				sqInt literalIndex;
				sqInt object;
				sqInt methodPointer;
				flag("requires currentBytecode to be expanded to a constant");
				/* begin fetchNextBytecode */
				currentBytecode = byteAtPointer(++localIP);
				/* begin pushLiteralConstant: */
				literalIndex = 37 & 31;
				/* begin internalPush: */
				/* begin literal:ofMethod: */
				methodPointer = foo->method;
				object = longAt((methodPointer + (BASE_HEADER_SIZE)) + ((literalIndex + LiteralStart) << (SHIFT_FOR_WORD)));
				longAtPointerput(localSP += BYTES_PER_WORD, object);
			}
;
			break;
		case 38:
			/* pushLiteralConstantBytecode */
			{
				sqInt literalIndex;
				sqInt object;
				sqInt methodPointer;
				flag("requires currentBytecode to be expanded to a constant");
				/* begin fetchNextBytecode */
				currentBytecode = byteAtPointer(++localIP);
				/* begin pushLiteralConstant: */
				literalIndex = 38 & 31;
				/* begin internalPush: */
				/* begin literal:ofMethod: */
				methodPointer = foo->method;
				object = longAt((methodPointer + (BASE_HEADER_SIZE)) + ((literalIndex + LiteralStart) << (SHIFT_FOR_WORD)));
				longAtPointerput(localSP += BYTES_PER_WORD, object);
			}
;
			break;
		case 39:
			/* pushLiteralConstantBytecode */
			{
				sqInt literalIndex;
				sqInt object;
				sqInt methodPointer;
				flag("requires currentBytecode to be expanded to a constant");
				/* begin fetchNextBytecode */
				currentBytecode = byteAtPointer(++localIP);
				/* begin pushLiteralConstant: */
				literalIndex = 39 & 31;
				/* begin internalPush: */
				/* begin literal:ofMethod: */
				methodPointer = foo->method;
				object = longAt((methodPointer + (BASE_HEADER_SIZE)) + ((literalIndex + LiteralStart) << (SHIFT_FOR_WORD)));
				longAtPointerput(localSP += BYTES_PER_WORD, object);
			}
;
			break;
		case 40:
			/* pushLiteralConstantBytecode */
			{
				sqInt literalIndex;
				sqInt object;
				sqInt methodPointer;
				flag("requires currentBytecode to be expanded to a constant");
				/* begin fetchNextBytecode */
				currentBytecode = byteAtPointer(++localIP);
				/* begin pushLiteralConstant: */
				literalIndex = 40 & 31;
				/* begin internalPush: */
				/* begin literal:ofMethod: */
				methodPointer = foo->method;
				object = longAt((methodPointer + (BASE_HEADER_SIZE)) + ((literalIndex + LiteralStart) << (SHIFT_FOR_WORD)));
				longAtPointerput(localSP += BYTES_PER_WORD, object);
			}
;
			break;
		case 41:
			/* pushLiteralConstantBytecode */
			{
				sqInt literalIndex;
				sqInt object;
				sqInt methodPointer;
				flag("requires currentBytecode to be expanded to a constant");
				/* begin fetchNextBytecode */
				currentBytecode = byteAtPointer(++localIP);
				/* begin pushLiteralConstant: */
				literalIndex = 41 & 31;
				/* begin internalPush: */
				/* begin literal:ofMethod: */
				methodPointer = foo->method;
				object = longAt((methodPointer + (BASE_HEADER_SIZE)) + ((literalIndex + LiteralStart) << (SHIFT_FOR_WORD)));
				longAtPointerput(localSP += BYTES_PER_WORD, object);
			}
;
			break;
		case 42:
			/* pushLiteralConstantBytecode */
			{
				sqInt literalIndex;
				sqInt object;
				sqInt methodPointer;
				flag("requires currentBytecode to be expanded to a constant");
				/* begin fetchNextBytecode */
				currentBytecode = byteAtPointer(++localIP);
				/* begin pushLiteralConstant: */
				literalIndex = 42 & 31;
				/* begin internalPush: */
				/* begin literal:ofMethod: */
				methodPointer = foo->method;
				object = longAt((methodPointer + (BASE_HEADER_SIZE)) + ((literalIndex + LiteralStart) << (SHIFT_FOR_WORD)));
				longAtPointerput(localSP += BYTES_PER_WORD, object);
			}
;
			break;
		case 43:
			/* pushLiteralConstantBytecode */
			{
				sqInt literalIndex;
				sqInt object;
				sqInt methodPointer;
				flag("requires currentBytecode to be expanded to a constant");
				/* begin fetchNextBytecode */
				currentBytecode = byteAtPointer(++localIP);
				/* begin pushLiteralConstant: */
				literalIndex = 43 & 31;
				/* begin internalPush: */
				/* begin literal:ofMethod: */
				methodPointer = foo->method;
				object = longAt((methodPointer + (BASE_HEADER_SIZE)) + ((literalIndex + LiteralStart) << (SHIFT_FOR_WORD)));
				longAtPointerput(localSP += BYTES_PER_WORD, object);
			}
;
			break;
		case 44:
			/* pushLiteralConstantBytecode */
			{
				sqInt literalIndex;
				sqInt object;
				sqInt methodPointer;
				flag("requires currentBytecode to be expanded to a constant");
				/* begin fetchNextBytecode */
				currentBytecode = byteAtPointer(++localIP);
				/* begin pushLiteralConstant: */
				literalIndex = 44 & 31;
				/* begin internalPush: */
				/* begin literal:ofMethod: */
				methodPointer = foo->method;
				object = longAt((methodPointer + (BASE_HEADER_SIZE)) + ((literalIndex + LiteralStart) << (SHIFT_FOR_WORD)));
				longAtPointerput(localSP += BYTES_PER_WORD, object);
			}
;
			break;
		case 45:
			/* pushLiteralConstantBytecode */
			{
				sqInt literalIndex;
				sqInt object;
				sqInt methodPointer;
				flag("requires currentBytecode to be expanded to a constant");
				/* begin fetchNextBytecode */
				currentBytecode = byteAtPointer(++localIP);
				/* begin pushLiteralConstant: */
				literalIndex = 45 & 31;
				/* begin internalPush: */
				/* begin literal:ofMethod: */
				methodPointer = foo->method;
				object = longAt((methodPointer + (BASE_HEADER_SIZE)) + ((literalIndex + LiteralStart) << (SHIFT_FOR_WORD)));
				longAtPointerput(localSP += BYTES_PER_WORD, object);
			}
;
			break;
		case 46:
			/* pushLiteralConstantBytecode */
			{
				sqInt literalIndex;
				sqInt object;
				sqInt methodPointer;
				flag("requires currentBytecode to be expanded to a constant");
				/* begin fetchNextBytecode */
				currentBytecode = byteAtPointer(++localIP);
				/* begin pushLiteralConstant: */
				literalIndex = 46 & 31;
				/* begin internalPush: */
				/* begin literal:ofMethod: */
				methodPointer = foo->method;
				object = longAt((methodPointer + (BASE_HEADER_SIZE)) + ((literalIndex + LiteralStart) << (SHIFT_FOR_WORD)));
				longAtPointerput(localSP += BYTES_PER_WORD, object);
			}
;
			break;
		case 47:
			/* pushLiteralConstantBytecode */
			{
				sqInt literalIndex;
				sqInt object;
				sqInt methodPointer;
				flag("requires currentBytecode to be expanded to a constant");
				/* begin fetchNextBytecode */
				currentBytecode = byteAtPointer(++localIP);
				/* begin pushLiteralConstant: */
				literalIndex = 47 & 31;
				/* begin internalPush: */
				/* begin literal:ofMethod: */
				methodPointer = foo->method;
				object = longAt((methodPointer + (BASE_HEADER_SIZE)) + ((literalIndex + LiteralStart) << (SHIFT_FOR_WORD)));
				longAtPointerput(localSP += BYTES_PER_WORD, object);
			}
;
			break;
		case 48:
			/* pushLiteralConstantBytecode */
			{
				sqInt literalIndex;
				sqInt object;
				sqInt methodPointer;
				flag("requires currentBytecode to be expanded to a constant");
				/* begin fetchNextBytecode */
				currentBytecode = byteAtPointer(++localIP);
				/* begin pushLiteralConstant: */
				literalIndex = 48 & 31;
				/* begin internalPush: */
				/* begin literal:ofMethod: */
				methodPointer = foo->method;
				object = longAt((methodPointer + (BASE_HEADER_SIZE)) + ((literalIndex + LiteralStart) << (SHIFT_FOR_WORD)));
				longAtPointerput(localSP += BYTES_PER_WORD, object);
			}
;
			break;
		case 49:
			/* pushLiteralConstantBytecode */
			{
				sqInt literalIndex;
				sqInt object;
				sqInt methodPointer;
				flag("requires currentBytecode to be expanded to a constant");
				/* begin fetchNextBytecode */
				currentBytecode = byteAtPointer(++localIP);
				/* begin pushLiteralConstant: */
				literalIndex = 49 & 31;
				/* begin internalPush: */
				/* begin literal:ofMethod: */
				methodPointer = foo->method;
				object = longAt((methodPointer + (BASE_HEADER_SIZE)) + ((literalIndex + LiteralStart) << (SHIFT_FOR_WORD)));
				longAtPointerput(localSP += BYTES_PER_WORD, object);
			}
;
			break;
		case 50:
			/* pushLiteralConstantBytecode */
			{
				sqInt literalIndex;
				sqInt object;
				sqInt methodPointer;
				flag("requires currentBytecode to be expanded to a constant");
				/* begin fetchNextBytecode */
				currentBytecode = byteAtPointer(++localIP);
				/* begin pushLiteralConstant: */
				literalIndex = 50 & 31;
				/* begin internalPush: */
				/* begin literal:ofMethod: */
				methodPointer = foo->method;
				object = longAt((methodPointer + (BASE_HEADER_SIZE)) + ((literalIndex + LiteralStart) << (SHIFT_FOR_WORD)));
				longAtPointerput(localSP += BYTES_PER_WORD, object);
			}
;
			break;
		case 51:
			/* pushLiteralConstantBytecode */
			{
				sqInt literalIndex;
				sqInt object;
				sqInt methodPointer;
				flag("requires currentBytecode to be expanded to a constant");
				/* begin fetchNextBytecode */
				currentBytecode = byteAtPointer(++localIP);
				/* begin pushLiteralConstant: */
				literalIndex = 51 & 31;
				/* begin internalPush: */
				/* begin literal:ofMethod: */
				methodPointer = foo->method;
				object = longAt((methodPointer + (BASE_HEADER_SIZE)) + ((literalIndex + LiteralStart) << (SHIFT_FOR_WORD)));
				longAtPointerput(localSP += BYTES_PER_WORD, object);
			}
;
			break;
		case 52:
			/* pushLiteralConstantBytecode */
			{
				sqInt literalIndex;
				sqInt object;
				sqInt methodPointer;
				flag("requires currentBytecode to be expanded to a constant");
				/* begin fetchNextBytecode */
				currentBytecode = byteAtPointer(++localIP);
				/* begin pushLiteralConstant: */
				literalIndex = 52 & 31;
				/* begin internalPush: */
				/* begin literal:ofMethod: */
				methodPointer = foo->method;
				object = longAt((methodPointer + (BASE_HEADER_SIZE)) + ((literalIndex + LiteralStart) << (SHIFT_FOR_WORD)));
				longAtPointerput(localSP += BYTES_PER_WORD, object);
			}
;
			break;
		case 53:
			/* pushLiteralConstantBytecode */
			{
				sqInt literalIndex;
				sqInt object;
				sqInt methodPointer;
				flag("requires currentBytecode to be expanded to a constant");
				/* begin fetchNextBytecode */
				currentBytecode = byteAtPointer(++localIP);
				/* begin pushLiteralConstant: */
				literalIndex = 53 & 31;
				/* begin internalPush: */
				/* begin literal:ofMethod: */
				methodPointer = foo->method;
				object = longAt((methodPointer + (BASE_HEADER_SIZE)) + ((literalIndex + LiteralStart) << (SHIFT_FOR_WORD)));
				longAtPointerput(localSP += BYTES_PER_WORD, object);
			}
;
			break;
		case 54:
			/* pushLiteralConstantBytecode */
			{
				sqInt literalIndex;
				sqInt object;
				sqInt methodPointer;
				flag("requires currentBytecode to be expanded to a constant");
				/* begin fetchNextBytecode */
				currentBytecode = byteAtPointer(++localIP);
				/* begin pushLiteralConstant: */
				literalIndex = 54 & 31;
				/* begin internalPush: */
				/* begin literal:ofMethod: */
				methodPointer = foo->method;
				object = longAt((methodPointer + (BASE_HEADER_SIZE)) + ((literalIndex + LiteralStart) << (SHIFT_FOR_WORD)));
				longAtPointerput(localSP += BYTES_PER_WORD, object);
			}
;
			break;
		case 55:
			/* pushLiteralConstantBytecode */
			{
				sqInt literalIndex;
				sqInt object;
				sqInt methodPointer;
				flag("requires currentBytecode to be expanded to a constant");
				/* begin fetchNextBytecode */
				currentBytecode = byteAtPointer(++localIP);
				/* begin pushLiteralConstant: */
				literalIndex = 55 & 31;
				/* begin internalPush: */
				/* begin literal:ofMethod: */
				methodPointer = foo->method;
				object = longAt((methodPointer + (BASE_HEADER_SIZE)) + ((literalIndex + LiteralStart) << (SHIFT_FOR_WORD)));
				longAtPointerput(localSP += BYTES_PER_WORD, object);
			}
;
			break;
		case 56:
			/* pushLiteralConstantBytecode */
			{
				sqInt literalIndex;
				sqInt object;
				sqInt methodPointer;
				flag("requires currentBytecode to be expanded to a constant");
				/* begin fetchNextBytecode */
				currentBytecode = byteAtPointer(++localIP);
				/* begin pushLiteralConstant: */
				literalIndex = 56 & 31;
				/* begin internalPush: */
				/* begin literal:ofMethod: */
				methodPointer = foo->method;
				object = longAt((methodPointer + (BASE_HEADER_SIZE)) + ((literalIndex + LiteralStart) << (SHIFT_FOR_WORD)));
				longAtPointerput(localSP += BYTES_PER_WORD, object);
			}
;
			break;
		case 57:
			/* pushLiteralConstantBytecode */
			{
				sqInt literalIndex;
				sqInt object;
				sqInt methodPointer;
				flag("requires currentBytecode to be expanded to a constant");
				/* begin fetchNextBytecode */
				currentBytecode = byteAtPointer(++localIP);
				/* begin pushLiteralConstant: */
				literalIndex = 57 & 31;
				/* begin internalPush: */
				/* begin literal:ofMethod: */
				methodPointer = foo->method;
				object = longAt((methodPointer + (BASE_HEADER_SIZE)) + ((literalIndex + LiteralStart) << (SHIFT_FOR_WORD)));
				longAtPointerput(localSP += BYTES_PER_WORD, object);
			}
;
			break;
		case 58:
			/* pushLiteralConstantBytecode */
			{
				sqInt literalIndex;
				sqInt object;
				sqInt methodPointer;
				flag("requires currentBytecode to be expanded to a constant");
				/* begin fetchNextBytecode */
				currentBytecode = byteAtPointer(++localIP);
				/* begin pushLiteralConstant: */
				literalIndex = 58 & 31;
				/* begin internalPush: */
				/* begin literal:ofMethod: */
				methodPointer = foo->method;
				object = longAt((methodPointer + (BASE_HEADER_SIZE)) + ((literalIndex + LiteralStart) << (SHIFT_FOR_WORD)));
				longAtPointerput(localSP += BYTES_PER_WORD, object);
			}
;
			break;
		case 59:
			/* pushLiteralConstantBytecode */
			{
				sqInt literalIndex;
				sqInt object;
				sqInt methodPointer;
				flag("requires currentBytecode to be expanded to a constant");
				/* begin fetchNextBytecode */
				currentBytecode = byteAtPointer(++localIP);
				/* begin pushLiteralConstant: */
				literalIndex = 59 & 31;
				/* begin internalPush: */
				/* begin literal:ofMethod: */
				methodPointer = foo->method;
				object = longAt((methodPointer + (BASE_HEADER_SIZE)) + ((literalIndex + LiteralStart) << (SHIFT_FOR_WORD)));
				longAtPointerput(localSP += BYTES_PER_WORD, object);
			}
;
			break;
		case 60:
			/* pushLiteralConstantBytecode */
			{
				sqInt literalIndex;
				sqInt object;
				sqInt methodPointer;
				flag("requires currentBytecode to be expanded to a constant");
				/* begin fetchNextBytecode */
				currentBytecode = byteAtPointer(++localIP);
				/* begin pushLiteralConstant: */
				literalIndex = 60 & 31;
				/* begin internalPush: */
				/* begin literal:ofMethod: */
				methodPointer = foo->method;
				object = longAt((methodPointer + (BASE_HEADER_SIZE)) + ((literalIndex + LiteralStart) << (SHIFT_FOR_WORD)));
				longAtPointerput(localSP += BYTES_PER_WORD, object);
			}
;
			break;
		case 61:
			/* pushLiteralConstantBytecode */
			{
				sqInt literalIndex;
				sqInt object;
				sqInt methodPointer;
				flag("requires currentBytecode to be expanded to a constant");
				/* begin fetchNextBytecode */
				currentBytecode = byteAtPointer(++localIP);
				/* begin pushLiteralConstant: */
				literalIndex = 61 & 31;
				/* begin internalPush: */
				/* begin literal:ofMethod: */
				methodPointer = foo->method;
				object = longAt((methodPointer + (BASE_HEADER_SIZE)) + ((literalIndex + LiteralStart) << (SHIFT_FOR_WORD)));
				longAtPointerput(localSP += BYTES_PER_WORD, object);
			}
;
			break;
		case 62:
			/* pushLiteralConstantBytecode */
			{
				sqInt literalIndex;
				sqInt object;
				sqInt methodPointer;
				flag("requires currentBytecode to be expanded to a constant");
				/* begin fetchNextBytecode */
				currentBytecode = byteAtPointer(++localIP);
				/* begin pushLiteralConstant: */
				literalIndex = 62 & 31;
				/* begin internalPush: */
				/* begin literal:ofMethod: */
				methodPointer = foo->method;
				object = longAt((methodPointer + (BASE_HEADER_SIZE)) + ((literalIndex + LiteralStart) << (SHIFT_FOR_WORD)));
				longAtPointerput(localSP += BYTES_PER_WORD, object);
			}
;
			break;
		case 63:
			/* pushLiteralConstantBytecode */
			{
				sqInt literalIndex;
				sqInt object;
				sqInt methodPointer;
				flag("requires currentBytecode to be expanded to a constant");
				/* begin fetchNextBytecode */
				currentBytecode = byteAtPointer(++localIP);
				/* begin pushLiteralConstant: */
				literalIndex = 63 & 31;
				/* begin internalPush: */
				/* begin literal:ofMethod: */
				methodPointer = foo->method;
				object = longAt((methodPointer + (BASE_HEADER_SIZE)) + ((literalIndex + LiteralStart) << (SHIFT_FOR_WORD)));
				longAtPointerput(localSP += BYTES_PER_WORD, object);
			}
;
			break;
		case 64:
			/* pushLiteralVariableBytecode */
			{
				sqInt literalIndex;
				sqInt object;
				sqInt oop;
				sqInt methodPointer;
				flag("requires currentBytecode to be expanded to a constant");
				/* begin fetchNextBytecode */
				currentBytecode = byteAtPointer(++localIP);
				/* begin pushLiteralVariable: */
				literalIndex = 64 & 31;
				/* begin internalPush: */
				/* begin fetchPointer:ofObject: */
				/* begin literal:ofMethod: */
				methodPointer = foo->method;
				oop = longAt((methodPointer + (BASE_HEADER_SIZE)) + ((literalIndex + LiteralStart) << (SHIFT_FOR_WORD)));
				object = longAt((oop + (BASE_HEADER_SIZE)) + (ValueIndex << (SHIFT_FOR_WORD)));
				longAtPointerput(localSP += BYTES_PER_WORD, object);
			}
;
			break;
		case 65:
			/* pushLiteralVariableBytecode */
			{
				sqInt literalIndex;
				sqInt object;
				sqInt oop;
				sqInt methodPointer;
				flag("requires currentBytecode to be expanded to a constant");
				/* begin fetchNextBytecode */
				currentBytecode = byteAtPointer(++localIP);
				/* begin pushLiteralVariable: */
				literalIndex = 65 & 31;
				/* begin internalPush: */
				/* begin fetchPointer:ofObject: */
				/* begin literal:ofMethod: */
				methodPointer = foo->method;
				oop = longAt((methodPointer + (BASE_HEADER_SIZE)) + ((literalIndex + LiteralStart) << (SHIFT_FOR_WORD)));
				object = longAt((oop + (BASE_HEADER_SIZE)) + (ValueIndex << (SHIFT_FOR_WORD)));
				longAtPointerput(localSP += BYTES_PER_WORD, object);
			}
;
			break;
		case 66:
			/* pushLiteralVariableBytecode */
			{
				sqInt literalIndex;
				sqInt object;
				sqInt oop;
				sqInt methodPointer;
				flag("requires currentBytecode to be expanded to a constant");
				/* begin fetchNextBytecode */
				currentBytecode = byteAtPointer(++localIP);
				/* begin pushLiteralVariable: */
				literalIndex = 66 & 31;
				/* begin internalPush: */
				/* begin fetchPointer:ofObject: */
				/* begin literal:ofMethod: */
				methodPointer = foo->method;
				oop = longAt((methodPointer + (BASE_HEADER_SIZE)) + ((literalIndex + LiteralStart) << (SHIFT_FOR_WORD)));
				object = longAt((oop + (BASE_HEADER_SIZE)) + (ValueIndex << (SHIFT_FOR_WORD)));
				longAtPointerput(localSP += BYTES_PER_WORD, object);
			}
;
			break;
		case 67:
			/* pushLiteralVariableBytecode */
			{
				sqInt literalIndex;
				sqInt object;
				sqInt oop;
				sqInt methodPointer;
				flag("requires currentBytecode to be expanded to a constant");
				/* begin fetchNextBytecode */
				currentBytecode = byteAtPointer(++localIP);
				/* begin pushLiteralVariable: */
				literalIndex = 67 & 31;
				/* begin internalPush: */
				/* begin fetchPointer:ofObject: */
				/* begin literal:ofMethod: */
				methodPointer = foo->method;
				oop = longAt((methodPointer + (BASE_HEADER_SIZE)) + ((literalIndex + LiteralStart) << (SHIFT_FOR_WORD)));
				object = longAt((oop + (BASE_HEADER_SIZE)) + (ValueIndex << (SHIFT_FOR_WORD)));
				longAtPointerput(localSP += BYTES_PER_WORD, object);
			}
;
			break;
		case 68:
			/* pushLiteralVariableBytecode */
			{
				sqInt literalIndex;
				sqInt object;
				sqInt oop;
				sqInt methodPointer;
				flag("requires currentBytecode to be expanded to a constant");
				/* begin fetchNextBytecode */
				currentBytecode = byteAtPointer(++localIP);
				/* begin pushLiteralVariable: */
				literalIndex = 68 & 31;
				/* begin internalPush: */
				/* begin fetchPointer:ofObject: */
				/* begin literal:ofMethod: */
				methodPointer = foo->method;
				oop = longAt((methodPointer + (BASE_HEADER_SIZE)) + ((literalIndex + LiteralStart) << (SHIFT_FOR_WORD)));
				object = longAt((oop + (BASE_HEADER_SIZE)) + (ValueIndex << (SHIFT_FOR_WORD)));
				longAtPointerput(localSP += BYTES_PER_WORD, object);
			}
;
			break;
		case 69:
			/* pushLiteralVariableBytecode */
			{
				sqInt literalIndex;
				sqInt object;
				sqInt oop;
				sqInt methodPointer;
				flag("requires currentBytecode to be expanded to a constant");
				/* begin fetchNextBytecode */
				currentBytecode = byteAtPointer(++localIP);
				/* begin pushLiteralVariable: */
				literalIndex = 69 & 31;
				/* begin internalPush: */
				/* begin fetchPointer:ofObject: */
				/* begin literal:ofMethod: */
				methodPointer = foo->method;
				oop = longAt((methodPointer + (BASE_HEADER_SIZE)) + ((literalIndex + LiteralStart) << (SHIFT_FOR_WORD)));
				object = longAt((oop + (BASE_HEADER_SIZE)) + (ValueIndex << (SHIFT_FOR_WORD)));
				longAtPointerput(localSP += BYTES_PER_WORD, object);
			}
;
			break;
		case 70:
			/* pushLiteralVariableBytecode */
			{
				sqInt literalIndex;
				sqInt object;
				sqInt oop;
				sqInt methodPointer;
				flag("requires currentBytecode to be expanded to a constant");
				/* begin fetchNextBytecode */
				currentBytecode = byteAtPointer(++localIP);
				/* begin pushLiteralVariable: */
				literalIndex = 70 & 31;
				/* begin internalPush: */
				/* begin fetchPointer:ofObject: */
				/* begin literal:ofMethod: */
				methodPointer = foo->method;
				oop = longAt((methodPointer + (BASE_HEADER_SIZE)) + ((literalIndex + LiteralStart) << (SHIFT_FOR_WORD)));
				object = longAt((oop + (BASE_HEADER_SIZE)) + (ValueIndex << (SHIFT_FOR_WORD)));
				longAtPointerput(localSP += BYTES_PER_WORD, object);
			}
;
			break;
		case 71:
			/* pushLiteralVariableBytecode */
			{
				sqInt literalIndex;
				sqInt object;
				sqInt oop;
				sqInt methodPointer;
				flag("requires currentBytecode to be expanded to a constant");
				/* begin fetchNextBytecode */
				currentBytecode = byteAtPointer(++localIP);
				/* begin pushLiteralVariable: */
				literalIndex = 71 & 31;
				/* begin internalPush: */
				/* begin fetchPointer:ofObject: */
				/* begin literal:ofMethod: */
				methodPointer = foo->method;
				oop = longAt((methodPointer + (BASE_HEADER_SIZE)) + ((literalIndex + LiteralStart) << (SHIFT_FOR_WORD)));
				object = longAt((oop + (BASE_HEADER_SIZE)) + (ValueIndex << (SHIFT_FOR_WORD)));
				longAtPointerput(localSP += BYTES_PER_WORD, object);
			}
;
			break;
		case 72:
			/* pushLiteralVariableBytecode */
			{
				sqInt literalIndex;
				sqInt object;
				sqInt oop;
				sqInt methodPointer;
				flag("requires currentBytecode to be expanded to a constant");
				/* begin fetchNextBytecode */
				currentBytecode = byteAtPointer(++localIP);
				/* begin pushLiteralVariable: */
				literalIndex = 72 & 31;
				/* begin internalPush: */
				/* begin fetchPointer:ofObject: */
				/* begin literal:ofMethod: */
				methodPointer = foo->method;
				oop = longAt((methodPointer + (BASE_HEADER_SIZE)) + ((literalIndex + LiteralStart) << (SHIFT_FOR_WORD)));
				object = longAt((oop + (BASE_HEADER_SIZE)) + (ValueIndex << (SHIFT_FOR_WORD)));
				longAtPointerput(localSP += BYTES_PER_WORD, object);
			}
;
			break;
		case 73:
			/* pushLiteralVariableBytecode */
			{
				sqInt literalIndex;
				sqInt object;
				sqInt oop;
				sqInt methodPointer;
				flag("requires currentBytecode to be expanded to a constant");
				/* begin fetchNextBytecode */
				currentBytecode = byteAtPointer(++localIP);
				/* begin pushLiteralVariable: */
				literalIndex = 73 & 31;
				/* begin internalPush: */
				/* begin fetchPointer:ofObject: */
				/* begin literal:ofMethod: */
				methodPointer = foo->method;
				oop = longAt((methodPointer + (BASE_HEADER_SIZE)) + ((literalIndex + LiteralStart) << (SHIFT_FOR_WORD)));
				object = longAt((oop + (BASE_HEADER_SIZE)) + (ValueIndex << (SHIFT_FOR_WORD)));
				longAtPointerput(localSP += BYTES_PER_WORD, object);
			}
;
			break;
		case 74:
			/* pushLiteralVariableBytecode */
			{
				sqInt literalIndex;
				sqInt object;
				sqInt oop;
				sqInt methodPointer;
				flag("requires currentBytecode to be expanded to a constant");
				/* begin fetchNextBytecode */
				currentBytecode = byteAtPointer(++localIP);
				/* begin pushLiteralVariable: */
				literalIndex = 74 & 31;
				/* begin internalPush: */
				/* begin fetchPointer:ofObject: */
				/* begin literal:ofMethod: */
				methodPointer = foo->method;
				oop = longAt((methodPointer + (BASE_HEADER_SIZE)) + ((literalIndex + LiteralStart) << (SHIFT_FOR_WORD)));
				object = longAt((oop + (BASE_HEADER_SIZE)) + (ValueIndex << (SHIFT_FOR_WORD)));
				longAtPointerput(localSP += BYTES_PER_WORD, object);
			}
;
			break;
		case 75:
			/* pushLiteralVariableBytecode */
			{
				sqInt literalIndex;
				sqInt object;
				sqInt oop;
				sqInt methodPointer;
				flag("requires currentBytecode to be expanded to a constant");
				/* begin fetchNextBytecode */
				currentBytecode = byteAtPointer(++localIP);
				/* begin pushLiteralVariable: */
				literalIndex = 75 & 31;
				/* begin internalPush: */
				/* begin fetchPointer:ofObject: */
				/* begin literal:ofMethod: */
				methodPointer = foo->method;
				oop = longAt((methodPointer + (BASE_HEADER_SIZE)) + ((literalIndex + LiteralStart) << (SHIFT_FOR_WORD)));
				object = longAt((oop + (BASE_HEADER_SIZE)) + (ValueIndex << (SHIFT_FOR_WORD)));
				longAtPointerput(localSP += BYTES_PER_WORD, object);
			}
;
			break;
		case 76:
			/* pushLiteralVariableBytecode */
			{
				sqInt literalIndex;
				sqInt object;
				sqInt oop;
				sqInt methodPointer;
				flag("requires currentBytecode to be expanded to a constant");
				/* begin fetchNextBytecode */
				currentBytecode = byteAtPointer(++localIP);
				/* begin pushLiteralVariable: */
				literalIndex = 76 & 31;
				/* begin internalPush: */
				/* begin fetchPointer:ofObject: */
				/* begin literal:ofMethod: */
				methodPointer = foo->method;
				oop = longAt((methodPointer + (BASE_HEADER_SIZE)) + ((literalIndex + LiteralStart) << (SHIFT_FOR_WORD)));
				object = longAt((oop + (BASE_HEADER_SIZE)) + (ValueIndex << (SHIFT_FOR_WORD)));
				longAtPointerput(localSP += BYTES_PER_WORD, object);
			}
;
			break;
		case 77:
			/* pushLiteralVariableBytecode */
			{
				sqInt literalIndex;
				sqInt object;
				sqInt oop;
				sqInt methodPointer;
				flag("requires currentBytecode to be expanded to a constant");
				/* begin fetchNextBytecode */
				currentBytecode = byteAtPointer(++localIP);
				/* begin pushLiteralVariable: */
				literalIndex = 77 & 31;
				/* begin internalPush: */
				/* begin fetchPointer:ofObject: */
				/* begin literal:ofMethod: */
				methodPointer = foo->method;
				oop = longAt((methodPointer + (BASE_HEADER_SIZE)) + ((literalIndex + LiteralStart) << (SHIFT_FOR_WORD)));
				object = longAt((oop + (BASE_HEADER_SIZE)) + (ValueIndex << (SHIFT_FOR_WORD)));
				longAtPointerput(localSP += BYTES_PER_WORD, object);
			}
;
			break;
		case 78:
			/* pushLiteralVariableBytecode */
			{
				sqInt literalIndex;
				sqInt object;
				sqInt oop;
				sqInt methodPointer;
				flag("requires currentBytecode to be expanded to a constant");
				/* begin fetchNextBytecode */
				currentBytecode = byteAtPointer(++localIP);
				/* begin pushLiteralVariable: */
				literalIndex = 78 & 31;
				/* begin internalPush: */
				/* begin fetchPointer:ofObject: */
				/* begin literal:ofMethod: */
				methodPointer = foo->method;
				oop = longAt((methodPointer + (BASE_HEADER_SIZE)) + ((literalIndex + LiteralStart) << (SHIFT_FOR_WORD)));
				object = longAt((oop + (BASE_HEADER_SIZE)) + (ValueIndex << (SHIFT_FOR_WORD)));
				longAtPointerput(localSP += BYTES_PER_WORD, object);
			}
;
			break;
		case 79:
			/* pushLiteralVariableBytecode */
			{
				sqInt literalIndex;
				sqInt object;
				sqInt oop;
				sqInt methodPointer;
				flag("requires currentBytecode to be expanded to a constant");
				/* begin fetchNextBytecode */
				currentBytecode = byteAtPointer(++localIP);
				/* begin pushLiteralVariable: */
				literalIndex = 79 & 31;
				/* begin internalPush: */
				/* begin fetchPointer:ofObject: */
				/* begin literal:ofMethod: */
				methodPointer = foo->method;
				oop = longAt((methodPointer + (BASE_HEADER_SIZE)) + ((literalIndex + LiteralStart) << (SHIFT_FOR_WORD)));
				object = longAt((oop + (BASE_HEADER_SIZE)) + (ValueIndex << (SHIFT_FOR_WORD)));
				longAtPointerput(localSP += BYTES_PER_WORD, object);
			}
;
			break;
		case 80:
			/* pushLiteralVariableBytecode */
			{
				sqInt literalIndex;
				sqInt object;
				sqInt oop;
				sqInt methodPointer;
				flag("requires currentBytecode to be expanded to a constant");
				/* begin fetchNextBytecode */
				currentBytecode = byteAtPointer(++localIP);
				/* begin pushLiteralVariable: */
				literalIndex = 80 & 31;
				/* begin internalPush: */
				/* begin fetchPointer:ofObject: */
				/* begin literal:ofMethod: */
				methodPointer = foo->method;
				oop = longAt((methodPointer + (BASE_HEADER_SIZE)) + ((literalIndex + LiteralStart) << (SHIFT_FOR_WORD)));
				object = longAt((oop + (BASE_HEADER_SIZE)) + (ValueIndex << (SHIFT_FOR_WORD)));
				longAtPointerput(localSP += BYTES_PER_WORD, object);
			}
;
			break;
		case 81:
			/* pushLiteralVariableBytecode */
			{
				sqInt literalIndex;
				sqInt object;
				sqInt oop;
				sqInt methodPointer;
				flag("requires currentBytecode to be expanded to a constant");
				/* begin fetchNextBytecode */
				currentBytecode = byteAtPointer(++localIP);
				/* begin pushLiteralVariable: */
				literalIndex = 81 & 31;
				/* begin internalPush: */
				/* begin fetchPointer:ofObject: */
				/* begin literal:ofMethod: */
				methodPointer = foo->method;
				oop = longAt((methodPointer + (BASE_HEADER_SIZE)) + ((literalIndex + LiteralStart) << (SHIFT_FOR_WORD)));
				object = longAt((oop + (BASE_HEADER_SIZE)) + (ValueIndex << (SHIFT_FOR_WORD)));
				longAtPointerput(localSP += BYTES_PER_WORD, object);
			}
;
			break;
		case 82:
			/* pushLiteralVariableBytecode */
			{
				sqInt literalIndex;
				sqInt object;
				sqInt oop;
				sqInt methodPointer;
				flag("requires currentBytecode to be expanded to a constant");
				/* begin fetchNextBytecode */
				currentBytecode = byteAtPointer(++localIP);
				/* begin pushLiteralVariable: */
				literalIndex = 82 & 31;
				/* begin internalPush: */
				/* begin fetchPointer:ofObject: */
				/* begin literal:ofMethod: */
				methodPointer = foo->method;
				oop = longAt((methodPointer + (BASE_HEADER_SIZE)) + ((literalIndex + LiteralStart) << (SHIFT_FOR_WORD)));
				object = longAt((oop + (BASE_HEADER_SIZE)) + (ValueIndex << (SHIFT_FOR_WORD)));
				longAtPointerput(localSP += BYTES_PER_WORD, object);
			}
;
			break;
		case 83:
			/* pushLiteralVariableBytecode */
			{
				sqInt literalIndex;
				sqInt object;
				sqInt oop;
				sqInt methodPointer;
				flag("requires currentBytecode to be expanded to a constant");
				/* begin fetchNextBytecode */
				currentBytecode = byteAtPointer(++localIP);
				/* begin pushLiteralVariable: */
				literalIndex = 83 & 31;
				/* begin internalPush: */
				/* begin fetchPointer:ofObject: */
				/* begin literal:ofMethod: */
				methodPointer = foo->method;
				oop = longAt((methodPointer + (BASE_HEADER_SIZE)) + ((literalIndex + LiteralStart) << (SHIFT_FOR_WORD)));
				object = longAt((oop + (BASE_HEADER_SIZE)) + (ValueIndex << (SHIFT_FOR_WORD)));
				longAtPointerput(localSP += BYTES_PER_WORD, object);
			}
;
			break;
		case 84:
			/* pushLiteralVariableBytecode */
			{
				sqInt literalIndex;
				sqInt object;
				sqInt oop;
				sqInt methodPointer;
				flag("requires currentBytecode to be expanded to a constant");
				/* begin fetchNextBytecode */
				currentBytecode = byteAtPointer(++localIP);
				/* begin pushLiteralVariable: */
				literalIndex = 84 & 31;
				/* begin internalPush: */
				/* begin fetchPointer:ofObject: */
				/* begin literal:ofMethod: */
				methodPointer = foo->method;
				oop = longAt((methodPointer + (BASE_HEADER_SIZE)) + ((literalIndex + LiteralStart) << (SHIFT_FOR_WORD)));
				object = longAt((oop + (BASE_HEADER_SIZE)) + (ValueIndex << (SHIFT_FOR_WORD)));
				longAtPointerput(localSP += BYTES_PER_WORD, object);
			}
;
			break;
		case 85:
			/* pushLiteralVariableBytecode */
			{
				sqInt literalIndex;
				sqInt object;
				sqInt oop;
				sqInt methodPointer;
				flag("requires currentBytecode to be expanded to a constant");
				/* begin fetchNextBytecode */
				currentBytecode = byteAtPointer(++localIP);
				/* begin pushLiteralVariable: */
				literalIndex = 85 & 31;
				/* begin internalPush: */
				/* begin fetchPointer:ofObject: */
				/* begin literal:ofMethod: */
				methodPointer = foo->method;
				oop = longAt((methodPointer + (BASE_HEADER_SIZE)) + ((literalIndex + LiteralStart) << (SHIFT_FOR_WORD)));
				object = longAt((oop + (BASE_HEADER_SIZE)) + (ValueIndex << (SHIFT_FOR_WORD)));
				longAtPointerput(localSP += BYTES_PER_WORD, object);
			}
;
			break;
		case 86:
			/* pushLiteralVariableBytecode */
			{
				sqInt literalIndex;
				sqInt object;
				sqInt oop;
				sqInt methodPointer;
				flag("requires currentBytecode to be expanded to a constant");
				/* begin fetchNextBytecode */
				currentBytecode = byteAtPointer(++localIP);
				/* begin pushLiteralVariable: */
				literalIndex = 86 & 31;
				/* begin internalPush: */
				/* begin fetchPointer:ofObject: */
				/* begin literal:ofMethod: */
				methodPointer = foo->method;
				oop = longAt((methodPointer + (BASE_HEADER_SIZE)) + ((literalIndex + LiteralStart) << (SHIFT_FOR_WORD)));
				object = longAt((oop + (BASE_HEADER_SIZE)) + (ValueIndex << (SHIFT_FOR_WORD)));
				longAtPointerput(localSP += BYTES_PER_WORD, object);
			}
;
			break;
		case 87:
			/* pushLiteralVariableBytecode */
			{
				sqInt literalIndex;
				sqInt object;
				sqInt oop;
				sqInt methodPointer;
				flag("requires currentBytecode to be expanded to a constant");
				/* begin fetchNextBytecode */
				currentBytecode = byteAtPointer(++localIP);
				/* begin pushLiteralVariable: */
				literalIndex = 87 & 31;
				/* begin internalPush: */
				/* begin fetchPointer:ofObject: */
				/* begin literal:ofMethod: */
				methodPointer = foo->method;
				oop = longAt((methodPointer + (BASE_HEADER_SIZE)) + ((literalIndex + LiteralStart) << (SHIFT_FOR_WORD)));
				object = longAt((oop + (BASE_HEADER_SIZE)) + (ValueIndex << (SHIFT_FOR_WORD)));
				longAtPointerput(localSP += BYTES_PER_WORD, object);
			}
;
			break;
		case 88:
			/* pushLiteralVariableBytecode */
			{
				sqInt literalIndex;
				sqInt object;
				sqInt oop;
				sqInt methodPointer;
				flag("requires currentBytecode to be expanded to a constant");
				/* begin fetchNextBytecode */
				currentBytecode = byteAtPointer(++localIP);
				/* begin pushLiteralVariable: */
				literalIndex = 88 & 31;
				/* begin internalPush: */
				/* begin fetchPointer:ofObject: */
				/* begin literal:ofMethod: */
				methodPointer = foo->method;
				oop = longAt((methodPointer + (BASE_HEADER_SIZE)) + ((literalIndex + LiteralStart) << (SHIFT_FOR_WORD)));
				object = longAt((oop + (BASE_HEADER_SIZE)) + (ValueIndex << (SHIFT_FOR_WORD)));
				longAtPointerput(localSP += BYTES_PER_WORD, object);
			}
;
			break;
		case 89:
			/* pushLiteralVariableBytecode */
			{
				sqInt literalIndex;
				sqInt object;
				sqInt oop;
				sqInt methodPointer;
				flag("requires currentBytecode to be expanded to a constant");
				/* begin fetchNextBytecode */
				currentBytecode = byteAtPointer(++localIP);
				/* begin pushLiteralVariable: */
				literalIndex = 89 & 31;
				/* begin internalPush: */
				/* begin fetchPointer:ofObject: */
				/* begin literal:ofMethod: */
				methodPointer = foo->method;
				oop = longAt((methodPointer + (BASE_HEADER_SIZE)) + ((literalIndex + LiteralStart) << (SHIFT_FOR_WORD)));
				object = longAt((oop + (BASE_HEADER_SIZE)) + (ValueIndex << (SHIFT_FOR_WORD)));
				longAtPointerput(localSP += BYTES_PER_WORD, object);
			}
;
			break;
		case 90:
			/* pushLiteralVariableBytecode */
			{
				sqInt literalIndex;
				sqInt object;
				sqInt oop;
				sqInt methodPointer;
				flag("requires currentBytecode to be expanded to a constant");
				/* begin fetchNextBytecode */
				currentBytecode = byteAtPointer(++localIP);
				/* begin pushLiteralVariable: */
				literalIndex = 90 & 31;
				/* begin internalPush: */
				/* begin fetchPointer:ofObject: */
				/* begin literal:ofMethod: */
				methodPointer = foo->method;
				oop = longAt((methodPointer + (BASE_HEADER_SIZE)) + ((literalIndex + LiteralStart) << (SHIFT_FOR_WORD)));
				object = longAt((oop + (BASE_HEADER_SIZE)) + (ValueIndex << (SHIFT_FOR_WORD)));
				longAtPointerput(localSP += BYTES_PER_WORD, object);
			}
;
			break;
		case 91:
			/* pushLiteralVariableBytecode */
			{
				sqInt literalIndex;
				sqInt object;
				sqInt oop;
				sqInt methodPointer;
				flag("requires currentBytecode to be expanded to a constant");
				/* begin fetchNextBytecode */
				currentBytecode = byteAtPointer(++localIP);
				/* begin pushLiteralVariable: */
				literalIndex = 91 & 31;
				/* begin internalPush: */
				/* begin fetchPointer:ofObject: */
				/* begin literal:ofMethod: */
				methodPointer = foo->method;
				oop = longAt((methodPointer + (BASE_HEADER_SIZE)) + ((literalIndex + LiteralStart) << (SHIFT_FOR_WORD)));
				object = longAt((oop + (BASE_HEADER_SIZE)) + (ValueIndex << (SHIFT_FOR_WORD)));
				longAtPointerput(localSP += BYTES_PER_WORD, object);
			}
;
			break;
		case 92:
			/* pushLiteralVariableBytecode */
			{
				sqInt literalIndex;
				sqInt object;
				sqInt oop;
				sqInt methodPointer;
				flag("requires currentBytecode to be expanded to a constant");
				/* begin fetchNextBytecode */
				currentBytecode = byteAtPointer(++localIP);
				/* begin pushLiteralVariable: */
				literalIndex = 92 & 31;
				/* begin internalPush: */
				/* begin fetchPointer:ofObject: */
				/* begin literal:ofMethod: */
				methodPointer = foo->method;
				oop = longAt((methodPointer + (BASE_HEADER_SIZE)) + ((literalIndex + LiteralStart) << (SHIFT_FOR_WORD)));
				object = longAt((oop + (BASE_HEADER_SIZE)) + (ValueIndex << (SHIFT_FOR_WORD)));
				longAtPointerput(localSP += BYTES_PER_WORD, object);
			}
;
			break;
		case 93:
			/* pushLiteralVariableBytecode */
			{
				sqInt literalIndex;
				sqInt object;
				sqInt oop;
				sqInt methodPointer;
				flag("requires currentBytecode to be expanded to a constant");
				/* begin fetchNextBytecode */
				currentBytecode = byteAtPointer(++localIP);
				/* begin pushLiteralVariable: */
				literalIndex = 93 & 31;
				/* begin internalPush: */
				/* begin fetchPointer:ofObject: */
				/* begin literal:ofMethod: */
				methodPointer = foo->method;
				oop = longAt((methodPointer + (BASE_HEADER_SIZE)) + ((literalIndex + LiteralStart) << (SHIFT_FOR_WORD)));
				object = longAt((oop + (BASE_HEADER_SIZE)) + (ValueIndex << (SHIFT_FOR_WORD)));
				longAtPointerput(localSP += BYTES_PER_WORD, object);
			}
;
			break;
		case 94:
			/* pushLiteralVariableBytecode */
			{
				sqInt literalIndex;
				sqInt object;
				sqInt oop;
				sqInt methodPointer;
				flag("requires currentBytecode to be expanded to a constant");
				/* begin fetchNextBytecode */
				currentBytecode = byteAtPointer(++localIP);
				/* begin pushLiteralVariable: */
				literalIndex = 94 & 31;
				/* begin internalPush: */
				/* begin fetchPointer:ofObject: */
				/* begin literal:ofMethod: */
				methodPointer = foo->method;
				oop = longAt((methodPointer + (BASE_HEADER_SIZE)) + ((literalIndex + LiteralStart) << (SHIFT_FOR_WORD)));
				object = longAt((oop + (BASE_HEADER_SIZE)) + (ValueIndex << (SHIFT_FOR_WORD)));
				longAtPointerput(localSP += BYTES_PER_WORD, object);
			}
;
			break;
		case 95:
			/* pushLiteralVariableBytecode */
			{
				sqInt literalIndex;
				sqInt object;
				sqInt oop;
				sqInt methodPointer;
				flag("requires currentBytecode to be expanded to a constant");
				/* begin fetchNextBytecode */
				currentBytecode = byteAtPointer(++localIP);
				/* begin pushLiteralVariable: */
				literalIndex = 95 & 31;
				/* begin internalPush: */
				/* begin fetchPointer:ofObject: */
				/* begin literal:ofMethod: */
				methodPointer = foo->method;
				oop = longAt((methodPointer + (BASE_HEADER_SIZE)) + ((literalIndex + LiteralStart) << (SHIFT_FOR_WORD)));
				object = longAt((oop + (BASE_HEADER_SIZE)) + (ValueIndex << (SHIFT_FOR_WORD)));
				longAtPointerput(localSP += BYTES_PER_WORD, object);
			}
;
			break;
		case 96:
			/* storeAndPopReceiverVariableBytecode */
			{
				sqInt rcvr;
				sqInt top;
				sqInt fieldIndex;
				flag("requires currentBytecode to be expanded to a constant");
				/* begin fetchNextBytecode */
				currentBytecode = byteAtPointer(++localIP);
				rcvr = foo->receiver;
				top = longAtPointer(localSP);
				if ((((usqInt) rcvr)) < (((usqInt) foo->youngStart))) {
					possibleRootStoreIntovalue(rcvr, top);
				}
				/* begin storePointerUnchecked:ofObject:withValue: */
				fieldIndex = 96 & 7;
				longAtput((rcvr + (BASE_HEADER_SIZE)) + (fieldIndex << (SHIFT_FOR_WORD)), top);
				/* begin internalPop: */
				localSP -= 1 * (BYTES_PER_WORD);
			}
;
			break;
		case 97:
			/* storeAndPopReceiverVariableBytecode */
			{
				sqInt rcvr;
				sqInt top;
				sqInt fieldIndex;
				flag("requires currentBytecode to be expanded to a constant");
				/* begin fetchNextBytecode */
				currentBytecode = byteAtPointer(++localIP);
				rcvr = foo->receiver;
				top = longAtPointer(localSP);
				if ((((usqInt) rcvr)) < (((usqInt) foo->youngStart))) {
					possibleRootStoreIntovalue(rcvr, top);
				}
				/* begin storePointerUnchecked:ofObject:withValue: */
				fieldIndex = 97 & 7;
				longAtput((rcvr + (BASE_HEADER_SIZE)) + (fieldIndex << (SHIFT_FOR_WORD)), top);
				/* begin internalPop: */
				localSP -= 1 * (BYTES_PER_WORD);
			}
;
			break;
		case 98:
			/* storeAndPopReceiverVariableBytecode */
			{
				sqInt rcvr;
				sqInt top;
				sqInt fieldIndex;
				flag("requires currentBytecode to be expanded to a constant");
				/* begin fetchNextBytecode */
				currentBytecode = byteAtPointer(++localIP);
				rcvr = foo->receiver;
				top = longAtPointer(localSP);
				if ((((usqInt) rcvr)) < (((usqInt) foo->youngStart))) {
					possibleRootStoreIntovalue(rcvr, top);
				}
				/* begin storePointerUnchecked:ofObject:withValue: */
				fieldIndex = 98 & 7;
				longAtput((rcvr + (BASE_HEADER_SIZE)) + (fieldIndex << (SHIFT_FOR_WORD)), top);
				/* begin internalPop: */
				localSP -= 1 * (BYTES_PER_WORD);
			}
;
			break;
		case 99:
			/* storeAndPopReceiverVariableBytecode */
			{
				sqInt rcvr;
				sqInt top;
				sqInt fieldIndex;
				flag("requires currentBytecode to be expanded to a constant");
				/* begin fetchNextBytecode */
				currentBytecode = byteAtPointer(++localIP);
				rcvr = foo->receiver;
				top = longAtPointer(localSP);
				if ((((usqInt) rcvr)) < (((usqInt) foo->youngStart))) {
					possibleRootStoreIntovalue(rcvr, top);
				}
				/* begin storePointerUnchecked:ofObject:withValue: */
				fieldIndex = 99 & 7;
				longAtput((rcvr + (BASE_HEADER_SIZE)) + (fieldIndex << (SHIFT_FOR_WORD)), top);
				/* begin internalPop: */
				localSP -= 1 * (BYTES_PER_WORD);
			}
;
			break;
		case 100:
			/* storeAndPopReceiverVariableBytecode */
			{
				sqInt rcvr;
				sqInt top;
				sqInt fieldIndex;
				flag("requires currentBytecode to be expanded to a constant");
				/* begin fetchNextBytecode */
				currentBytecode = byteAtPointer(++localIP);
				rcvr = foo->receiver;
				top = longAtPointer(localSP);
				if ((((usqInt) rcvr)) < (((usqInt) foo->youngStart))) {
					possibleRootStoreIntovalue(rcvr, top);
				}
				/* begin storePointerUnchecked:ofObject:withValue: */
				fieldIndex = 100 & 7;
				longAtput((rcvr + (BASE_HEADER_SIZE)) + (fieldIndex << (SHIFT_FOR_WORD)), top);
				/* begin internalPop: */
				localSP -= 1 * (BYTES_PER_WORD);
			}
;
			break;
		case 101:
			/* storeAndPopReceiverVariableBytecode */
			{
				sqInt rcvr;
				sqInt top;
				sqInt fieldIndex;
				flag("requires currentBytecode to be expanded to a constant");
				/* begin fetchNextBytecode */
				currentBytecode = byteAtPointer(++localIP);
				rcvr = foo->receiver;
				top = longAtPointer(localSP);
				if ((((usqInt) rcvr)) < (((usqInt) foo->youngStart))) {
					possibleRootStoreIntovalue(rcvr, top);
				}
				/* begin storePointerUnchecked:ofObject:withValue: */
				fieldIndex = 101 & 7;
				longAtput((rcvr + (BASE_HEADER_SIZE)) + (fieldIndex << (SHIFT_FOR_WORD)), top);
				/* begin internalPop: */
				localSP -= 1 * (BYTES_PER_WORD);
			}
;
			break;
		case 102:
			/* storeAndPopReceiverVariableBytecode */
			{
				sqInt rcvr;
				sqInt top;
				sqInt fieldIndex;
				flag("requires currentBytecode to be expanded to a constant");
				/* begin fetchNextBytecode */
				currentBytecode = byteAtPointer(++localIP);
				rcvr = foo->receiver;
				top = longAtPointer(localSP);
				if ((((usqInt) rcvr)) < (((usqInt) foo->youngStart))) {
					possibleRootStoreIntovalue(rcvr, top);
				}
				/* begin storePointerUnchecked:ofObject:withValue: */
				fieldIndex = 102 & 7;
				longAtput((rcvr + (BASE_HEADER_SIZE)) + (fieldIndex << (SHIFT_FOR_WORD)), top);
				/* begin internalPop: */
				localSP -= 1 * (BYTES_PER_WORD);
			}
;
			break;
		case 103:
			/* storeAndPopReceiverVariableBytecode */
			{
				sqInt rcvr;
				sqInt top;
				sqInt fieldIndex;
				flag("requires currentBytecode to be expanded to a constant");
				/* begin fetchNextBytecode */
				currentBytecode = byteAtPointer(++localIP);
				rcvr = foo->receiver;
				top = longAtPointer(localSP);
				if ((((usqInt) rcvr)) < (((usqInt) foo->youngStart))) {
					possibleRootStoreIntovalue(rcvr, top);
				}
				/* begin storePointerUnchecked:ofObject:withValue: */
				fieldIndex = 103 & 7;
				longAtput((rcvr + (BASE_HEADER_SIZE)) + (fieldIndex << (SHIFT_FOR_WORD)), top);
				/* begin internalPop: */
				localSP -= 1 * (BYTES_PER_WORD);
			}
;
			break;
		case 104:
			/* storeAndPopTemporaryVariableBytecode */
			{
				sqInt fieldIndex;
				sqInt oop;
				sqInt valuePointer;
				flag("requires currentBytecode to be expanded to a constant");
				/* begin fetchNextBytecode */
				currentBytecode = byteAtPointer(++localIP);
				/* begin storePointerUnchecked:ofObject:withValue: */
				fieldIndex = (104 & 7) + TempFrameStart;
				oop = localHomeContext;
				valuePointer = longAtPointer(localSP);
				longAtput((oop + (BASE_HEADER_SIZE)) + (fieldIndex << (SHIFT_FOR_WORD)), valuePointer);
				/* begin internalPop: */
				localSP -= 1 * (BYTES_PER_WORD);
			}
;
			break;
		case 105:
			/* storeAndPopTemporaryVariableBytecode */
			{
				sqInt fieldIndex;
				sqInt oop;
				sqInt valuePointer;
				flag("requires currentBytecode to be expanded to a constant");
				/* begin fetchNextBytecode */
				currentBytecode = byteAtPointer(++localIP);
				/* begin storePointerUnchecked:ofObject:withValue: */
				fieldIndex = (105 & 7) + TempFrameStart;
				oop = localHomeContext;
				valuePointer = longAtPointer(localSP);
				longAtput((oop + (BASE_HEADER_SIZE)) + (fieldIndex << (SHIFT_FOR_WORD)), valuePointer);
				/* begin internalPop: */
				localSP -= 1 * (BYTES_PER_WORD);
			}
;
			break;
		case 106:
			/* storeAndPopTemporaryVariableBytecode */
			{
				sqInt fieldIndex;
				sqInt oop;
				sqInt valuePointer;
				flag("requires currentBytecode to be expanded to a constant");
				/* begin fetchNextBytecode */
				currentBytecode = byteAtPointer(++localIP);
				/* begin storePointerUnchecked:ofObject:withValue: */
				fieldIndex = (106 & 7) + TempFrameStart;
				oop = localHomeContext;
				valuePointer = longAtPointer(localSP);
				longAtput((oop + (BASE_HEADER_SIZE)) + (fieldIndex << (SHIFT_FOR_WORD)), valuePointer);
				/* begin internalPop: */
				localSP -= 1 * (BYTES_PER_WORD);
			}
;
			break;
		case 107:
			/* storeAndPopTemporaryVariableBytecode */
			{
				sqInt fieldIndex;
				sqInt oop;
				sqInt valuePointer;
				flag("requires currentBytecode to be expanded to a constant");
				/* begin fetchNextBytecode */
				currentBytecode = byteAtPointer(++localIP);
				/* begin storePointerUnchecked:ofObject:withValue: */
				fieldIndex = (107 & 7) + TempFrameStart;
				oop = localHomeContext;
				valuePointer = longAtPointer(localSP);
				longAtput((oop + (BASE_HEADER_SIZE)) + (fieldIndex << (SHIFT_FOR_WORD)), valuePointer);
				/* begin internalPop: */
				localSP -= 1 * (BYTES_PER_WORD);
			}
;
			break;
		case 108:
			/* storeAndPopTemporaryVariableBytecode */
			{
				sqInt fieldIndex;
				sqInt oop;
				sqInt valuePointer;
				flag("requires currentBytecode to be expanded to a constant");
				/* begin fetchNextBytecode */
				currentBytecode = byteAtPointer(++localIP);
				/* begin storePointerUnchecked:ofObject:withValue: */
				fieldIndex = (108 & 7) + TempFrameStart;
				oop = localHomeContext;
				valuePointer = longAtPointer(localSP);
				longAtput((oop + (BASE_HEADER_SIZE)) + (fieldIndex << (SHIFT_FOR_WORD)), valuePointer);
				/* begin internalPop: */
				localSP -= 1 * (BYTES_PER_WORD);
			}
;
			break;
		case 109:
			/* storeAndPopTemporaryVariableBytecode */
			{
				sqInt fieldIndex;
				sqInt oop;
				sqInt valuePointer;
				flag("requires currentBytecode to be expanded to a constant");
				/* begin fetchNextBytecode */
				currentBytecode = byteAtPointer(++localIP);
				/* begin storePointerUnchecked:ofObject:withValue: */
				fieldIndex = (109 & 7) + TempFrameStart;
				oop = localHomeContext;
				valuePointer = longAtPointer(localSP);
				longAtput((oop + (BASE_HEADER_SIZE)) + (fieldIndex << (SHIFT_FOR_WORD)), valuePointer);
				/* begin internalPop: */
				localSP -= 1 * (BYTES_PER_WORD);
			}
;
			break;
		case 110:
			/* storeAndPopTemporaryVariableBytecode */
			{
				sqInt fieldIndex;
				sqInt oop;
				sqInt valuePointer;
				flag("requires currentBytecode to be expanded to a constant");
				/* begin fetchNextBytecode */
				currentBytecode = byteAtPointer(++localIP);
				/* begin storePointerUnchecked:ofObject:withValue: */
				fieldIndex = (110 & 7) + TempFrameStart;
				oop = localHomeContext;
				valuePointer = longAtPointer(localSP);
				longAtput((oop + (BASE_HEADER_SIZE)) + (fieldIndex << (SHIFT_FOR_WORD)), valuePointer);
				/* begin internalPop: */
				localSP -= 1 * (BYTES_PER_WORD);
			}
;
			break;
		case 111:
			/* storeAndPopTemporaryVariableBytecode */
			{
				sqInt fieldIndex;
				sqInt oop;
				sqInt valuePointer;
				flag("requires currentBytecode to be expanded to a constant");
				/* begin fetchNextBytecode */
				currentBytecode = byteAtPointer(++localIP);
				/* begin storePointerUnchecked:ofObject:withValue: */
				fieldIndex = (111 & 7) + TempFrameStart;
				oop = localHomeContext;
				valuePointer = longAtPointer(localSP);
				longAtput((oop + (BASE_HEADER_SIZE)) + (fieldIndex << (SHIFT_FOR_WORD)), valuePointer);
				/* begin internalPop: */
				localSP -= 1 * (BYTES_PER_WORD);
			}
;
			break;
		case 112:
			/* pushReceiverBytecode */
			{
				/* begin fetchNextBytecode */
				currentBytecode = byteAtPointer(++localIP);
				/* begin internalPush: */
				longAtPointerput(localSP += BYTES_PER_WORD, foo->receiver);
			}
;
			break;
		case 113:
			/* pushConstantTrueBytecode */
			{
				/* begin fetchNextBytecode */
				currentBytecode = byteAtPointer(++localIP);
				/* begin internalPush: */
				longAtPointerput(localSP += BYTES_PER_WORD, foo->trueObj);
			}
;
			break;
		case 114:
			/* pushConstantFalseBytecode */
			{
				/* begin fetchNextBytecode */
				currentBytecode = byteAtPointer(++localIP);
				/* begin internalPush: */
				longAtPointerput(localSP += BYTES_PER_WORD, foo->falseObj);
			}
;
			break;
		case 115:
			/* pushConstantNilBytecode */
			{
				/* begin fetchNextBytecode */
				currentBytecode = byteAtPointer(++localIP);
				/* begin internalPush: */
				longAtPointerput(localSP += BYTES_PER_WORD, foo->nilObj);
			}
;
			break;
		case 116:
			/* pushConstantMinusOneBytecode */
			{
				/* begin fetchNextBytecode */
				currentBytecode = byteAtPointer(++localIP);
				/* begin internalPush: */
				longAtPointerput(localSP += BYTES_PER_WORD, ConstMinusOne);
			}
;
			break;
		case 117:
			/* pushConstantZeroBytecode */
			{
				/* begin fetchNextBytecode */
				currentBytecode = byteAtPointer(++localIP);
				/* begin internalPush: */
				longAtPointerput(localSP += BYTES_PER_WORD, ConstZero);
			}
;
			break;
		case 118:
			/* pushConstantOneBytecode */
			{
				/* begin fetchNextBytecode */
				currentBytecode = byteAtPointer(++localIP);
				/* begin internalPush: */
				longAtPointerput(localSP += BYTES_PER_WORD, ConstOne);
			}
;
			break;
		case 119:
			/* pushConstantTwoBytecode */
			{
				/* begin fetchNextBytecode */
				currentBytecode = byteAtPointer(++localIP);
				/* begin internalPush: */
				longAtPointerput(localSP += BYTES_PER_WORD, ConstTwo);
			}
;
			break;
		case 120:
			/* returnReceiver */
			{
				sqInt closureOrNil;
				sqInt context;
				/* begin sender */
				context = localHomeContext;
				while ((closureOrNil = longAt((context + (BASE_HEADER_SIZE)) + (ClosureIndex << (SHIFT_FOR_WORD)))) != foo->nilObj) {
					context = longAt((closureOrNil + (BASE_HEADER_SIZE)) + (ClosureOuterContextIndex << (SHIFT_FOR_WORD)));
				}
				localReturnContext = longAt((context + (BASE_HEADER_SIZE)) + (SenderIndex << (SHIFT_FOR_WORD)));
				localReturnValue = foo->receiver;
				/* goto commonReturn */
			}
;
			
		commonReturn:
			/* commonReturn */
			{
				sqInt contextOfCaller;
				sqInt localCntx;
				sqInt localVal;
				sqInt nilOop;
				sqInt thisCntx;
				sqInt unwindMarked;
				sqInt header;
				sqInt meth;
				sqInt pIndex;
				sqInt header1;
				sqInt oop;
				sqInt oop1;
				sqInt oop2;
				sqInt oop3;
				sqInt primBits;
				sqInt valuePointer;
				sqInt valuePointer1;
				sqInt tmp;
				nilOop = foo->nilObj;
				thisCntx = foo->activeContext;
				localCntx = localReturnContext;
				localVal = localReturnValue;
				if ((localCntx == nilOop) || ((longAt((localCntx + (BASE_HEADER_SIZE)) + (InstructionPointerIndex << (SHIFT_FOR_WORD)))) == nilOop)) {
					/* begin internalCannotReturn: */
					/* begin internalPush: */
					longAtPointerput(localSP += BYTES_PER_WORD, foo->activeContext);
					/* begin internalPush: */
					longAtPointerput(localSP += BYTES_PER_WORD, localVal);
					/* begin fetchPointer:ofObject: */
					oop1 = foo->specialObjectsOop;
					foo->messageSelector = longAt((oop1 + (BASE_HEADER_SIZE)) + (SelectorCannotReturn << (SHIFT_FOR_WORD)));
					foo->argumentCount = 1;
					goto normalSend;
					goto l42;
				}
				/* begin fetchPointer:ofObject: */
				oop = foo->activeContext;
				thisCntx = longAt((oop + (BASE_HEADER_SIZE)) + (SenderIndex << (SHIFT_FOR_WORD)));
				while (!(thisCntx == localCntx)) {
					if (thisCntx == nilOop) {
						/* begin internalCannotReturn: */
						/* begin internalPush: */
						longAtPointerput(localSP += BYTES_PER_WORD, foo->activeContext);
						/* begin internalPush: */
						longAtPointerput(localSP += BYTES_PER_WORD, localVal);
						/* begin fetchPointer:ofObject: */
						oop2 = foo->specialObjectsOop;
						foo->messageSelector = longAt((oop2 + (BASE_HEADER_SIZE)) + (SelectorCannotReturn << (SHIFT_FOR_WORD)));
						foo->argumentCount = 1;
						goto normalSend;
						goto l42;
					}
					/* begin isUnwindMarked: */
					header = longAt(thisCntx);
					if (!(((((usqInt) header) >> 12) & 31) == 14)) {
						unwindMarked = 0;
						goto l43;
					}
					meth = longAt((thisCntx + (BASE_HEADER_SIZE)) + (MethodIndex << (SHIFT_FOR_WORD)));
					/* begin primitiveIndexOf: */
					primBits = (((usqInt) (longAt((meth + (BASE_HEADER_SIZE)) + (HeaderIndex << (SHIFT_FOR_WORD))))) >> 1) & 268435967;
					pIndex = (primBits & 511) + (((usqInt) primBits) >> 19);
					unwindMarked = pIndex == 198;
				l43:	/* end isUnwindMarked: */;
					if (unwindMarked) {
						/* begin internalAboutToReturn:through: */
						/* begin internalPush: */
						longAtPointerput(localSP += BYTES_PER_WORD, foo->activeContext);
						/* begin internalPush: */
						longAtPointerput(localSP += BYTES_PER_WORD, localVal);
						/* begin internalPush: */
						longAtPointerput(localSP += BYTES_PER_WORD, thisCntx);
						/* begin fetchPointer:ofObject: */
						oop3 = foo->specialObjectsOop;
						foo->messageSelector = longAt((oop3 + (BASE_HEADER_SIZE)) + (SelectorAboutToReturn << (SHIFT_FOR_WORD)));
						foo->argumentCount = 2;
						goto normalSend;
						goto l42;
					}
					thisCntx = longAt((thisCntx + (BASE_HEADER_SIZE)) + (SenderIndex << (SHIFT_FOR_WORD)));
				}
				thisCntx = foo->activeContext;
				while (!(thisCntx == localCntx)) {
					contextOfCaller = longAt((thisCntx + (BASE_HEADER_SIZE)) + (SenderIndex << (SHIFT_FOR_WORD)));
					longAtput((thisCntx + (BASE_HEADER_SIZE)) + (SenderIndex << (SHIFT_FOR_WORD)), nilOop);
					longAtput((thisCntx + (BASE_HEADER_SIZE)) + (InstructionPointerIndex << (SHIFT_FOR_WORD)), nilOop);
					if (foo->reclaimableContextCount > 0) {
						foo->reclaimableContextCount -= 1;
						/* begin recycleContextIfPossible: */
						if ((((usqInt) thisCntx)) >= (((usqInt) foo->youngStart))) {
							header1 = longAt(thisCntx);
							if (((((usqInt) header1) >> 12) & 31) == 14) {
								if ((header1 & (SIZE_MASK)) == (SMALL_CONTEXT_SIZE)) {
									/* begin storePointerUnchecked:ofObject:withValue: */
									valuePointer = foo->freeContexts;
									longAtput((thisCntx + (BASE_HEADER_SIZE)) + (0 << (SHIFT_FOR_WORD)), valuePointer);
									foo->freeContexts = thisCntx;
								}
								if ((header1 & (SIZE_MASK)) == (LARGE_CONTEXT_SIZE)) {
									/* begin storePointerUnchecked:ofObject:withValue: */
									valuePointer1 = foo->freeLargeContexts;
									longAtput((thisCntx + (BASE_HEADER_SIZE)) + (0 << (SHIFT_FOR_WORD)), valuePointer1);
									foo->freeLargeContexts = thisCntx;
								}
							}
						}
					}
					thisCntx = contextOfCaller;
				}
				foo->activeContext = thisCntx;
				if ((((usqInt) thisCntx)) < (((usqInt) foo->youngStart))) {
					beRootIfOld(thisCntx);
				}
				/* begin internalFetchContextRegisters: */
				tmp = longAt((thisCntx + (BASE_HEADER_SIZE)) + (MethodIndex << (SHIFT_FOR_WORD)));
				if ((tmp & 1)) {
					tmp = longAt((thisCntx + (BASE_HEADER_SIZE)) + (HomeIndex << (SHIFT_FOR_WORD)));
					if ((((usqInt) tmp)) < (((usqInt) foo->youngStart))) {
						beRootIfOld(tmp);
					}
				} else {
					tmp = thisCntx;
				}
				localHomeContext = tmp;
				foo->receiver = longAt((tmp + (BASE_HEADER_SIZE)) + (ReceiverIndex << (SHIFT_FOR_WORD)));
				foo->method = longAt((tmp + (BASE_HEADER_SIZE)) + (MethodIndex << (SHIFT_FOR_WORD)));
				tmp = ((longAt((thisCntx + (BASE_HEADER_SIZE)) + (InstructionPointerIndex << (SHIFT_FOR_WORD)))) >> 1);
				localIP = pointerForOop(((foo->method + tmp) + (BASE_HEADER_SIZE)) - 2);
				tmp = ((longAt((thisCntx + (BASE_HEADER_SIZE)) + (StackPointerIndex << (SHIFT_FOR_WORD)))) >> 1);
				localSP = pointerForOop((thisCntx + (BASE_HEADER_SIZE)) + (((TempFrameStart + tmp) - 1) * (BYTES_PER_WORD)));
				/* begin fetchNextBytecode */
				currentBytecode = byteAtPointer(++localIP);
				/* begin internalPush: */
				longAtPointerput(localSP += BYTES_PER_WORD, localVal);
			}
;
		l42:	/* end case */;
			break;
		case 121:
			/* returnTrue */
			{
				sqInt closureOrNil;
				sqInt context;
				/* begin sender */
				context = localHomeContext;
				while ((closureOrNil = longAt((context + (BASE_HEADER_SIZE)) + (ClosureIndex << (SHIFT_FOR_WORD)))) != foo->nilObj) {
					context = longAt((closureOrNil + (BASE_HEADER_SIZE)) + (ClosureOuterContextIndex << (SHIFT_FOR_WORD)));
				}
				localReturnContext = longAt((context + (BASE_HEADER_SIZE)) + (SenderIndex << (SHIFT_FOR_WORD)));
				localReturnValue = foo->trueObj;
				goto commonReturn;
			}
;
			break;
		case 122:
			/* returnFalse */
			{
				sqInt closureOrNil;
				sqInt context;
				/* begin sender */
				context = localHomeContext;
				while ((closureOrNil = longAt((context + (BASE_HEADER_SIZE)) + (ClosureIndex << (SHIFT_FOR_WORD)))) != foo->nilObj) {
					context = longAt((closureOrNil + (BASE_HEADER_SIZE)) + (ClosureOuterContextIndex << (SHIFT_FOR_WORD)));
				}
				localReturnContext = longAt((context + (BASE_HEADER_SIZE)) + (SenderIndex << (SHIFT_FOR_WORD)));
				localReturnValue = foo->falseObj;
				goto commonReturn;
			}
;
			break;
		case 123:
			/* returnNil */
			{
				sqInt closureOrNil;
				sqInt context;
				/* begin sender */
				context = localHomeContext;
				while ((closureOrNil = longAt((context + (BASE_HEADER_SIZE)) + (ClosureIndex << (SHIFT_FOR_WORD)))) != foo->nilObj) {
					context = longAt((closureOrNil + (BASE_HEADER_SIZE)) + (ClosureOuterContextIndex << (SHIFT_FOR_WORD)));
				}
				localReturnContext = longAt((context + (BASE_HEADER_SIZE)) + (SenderIndex << (SHIFT_FOR_WORD)));
				localReturnValue = foo->nilObj;
				goto commonReturn;
			}
;
			break;
		case 124:
			/* returnTopFromMethod */
			{
				sqInt closureOrNil;
				sqInt context;
				/* begin sender */
				context = localHomeContext;
				while ((closureOrNil = longAt((context + (BASE_HEADER_SIZE)) + (ClosureIndex << (SHIFT_FOR_WORD)))) != foo->nilObj) {
					context = longAt((closureOrNil + (BASE_HEADER_SIZE)) + (ClosureOuterContextIndex << (SHIFT_FOR_WORD)));
				}
				localReturnContext = longAt((context + (BASE_HEADER_SIZE)) + (SenderIndex << (SHIFT_FOR_WORD)));
				localReturnValue = longAtPointer(localSP);
				goto commonReturn;
			}
;
			break;
		case 125:
			/* returnTopFromBlock */
			{
				sqInt oop;
				/* begin fetchPointer:ofObject: */
				oop = foo->activeContext;
				localReturnContext = longAt((oop + (BASE_HEADER_SIZE)) + (CallerIndex << (SHIFT_FOR_WORD)));
				localReturnValue = longAtPointer(localSP);
				goto commonReturn;
			}
;
			break;
		case 126:
		case 127:
			/* unknownBytecode */
			{
				error("Unknown bytecode");
			}
;
			break;
		case 128:
			/* extendedPushBytecode */
			{
				sqInt descriptor;
				sqInt variableIndex;
				sqInt variableType;
				sqInt object;
				sqInt oop;
				sqInt object1;
				sqInt oop1;
				sqInt object2;
				sqInt methodPointer;
				sqInt object3;
				sqInt oop2;
				sqInt methodPointer1;
				descriptor = byteAtPointer(++localIP);
				/* begin fetchNextBytecode */
				currentBytecode = byteAtPointer(++localIP);
				variableType = (((usqInt) descriptor) >> 6) & 3;
				variableIndex = descriptor & 63;
				if (variableType == 0) {
					/* begin pushReceiverVariable: */
					/* begin internalPush: */
					/* begin fetchPointer:ofObject: */
					oop = foo->receiver;
					object = longAt((oop + (BASE_HEADER_SIZE)) + (variableIndex << (SHIFT_FOR_WORD)));
					longAtPointerput(localSP += BYTES_PER_WORD, object);
					goto l1;
				}
				if (variableType == 1) {
					/* begin pushTemporaryVariable: */
					/* begin internalPush: */
					/* begin fetchPointer:ofObject: */
					oop1 = localHomeContext;
					object1 = longAt((oop1 + (BASE_HEADER_SIZE)) + ((variableIndex + TempFrameStart) << (SHIFT_FOR_WORD)));
					longAtPointerput(localSP += BYTES_PER_WORD, object1);
					goto l1;
				}
				if (variableType == 2) {
					/* begin pushLiteralConstant: */
					/* begin internalPush: */
					/* begin literal:ofMethod: */
					methodPointer = foo->method;
					object2 = longAt((methodPointer + (BASE_HEADER_SIZE)) + ((variableIndex + LiteralStart) << (SHIFT_FOR_WORD)));
					longAtPointerput(localSP += BYTES_PER_WORD, object2);
					goto l1;
				}
				if (variableType == 3) {
					/* begin pushLiteralVariable: */
					/* begin internalPush: */
					/* begin fetchPointer:ofObject: */
					/* begin literal:ofMethod: */
					methodPointer1 = foo->method;
					oop2 = longAt((methodPointer1 + (BASE_HEADER_SIZE)) + ((variableIndex + LiteralStart) << (SHIFT_FOR_WORD)));
					object3 = longAt((oop2 + (BASE_HEADER_SIZE)) + (ValueIndex << (SHIFT_FOR_WORD)));
					longAtPointerput(localSP += BYTES_PER_WORD, object3);
					goto l1;
				}
			}
;
		l1:	/* end case */;
			break;
		case 129:
			/* extendedStoreBytecode */
			{
				sqInt association;
				sqInt descriptor;
				sqInt variableIndex;
				sqInt variableType;
				sqInt oop;
				sqInt valuePointer;
				sqInt oop1;
				sqInt valuePointer1;
				sqInt methodPointer;
				sqInt valuePointer2;
				descriptor = byteAtPointer(++localIP);
				/* begin fetchNextBytecode */
				currentBytecode = byteAtPointer(++localIP);
				variableType = (((usqInt) descriptor) >> 6) & 3;
				variableIndex = descriptor & 63;
				if (variableType == 0) {
					/* begin storePointer:ofObject:withValue: */
					oop = foo->receiver;
					valuePointer = longAtPointer(localSP);
					if ((((usqInt) oop)) < (((usqInt) foo->youngStart))) {
						possibleRootStoreIntovalue(oop, valuePointer);
					}
					longAtput((oop + (BASE_HEADER_SIZE)) + (variableIndex << (SHIFT_FOR_WORD)), valuePointer);
					goto l2;
				}
				if (variableType == 1) {
					/* begin storePointerUnchecked:ofObject:withValue: */
					oop1 = localHomeContext;
					valuePointer1 = longAtPointer(localSP);
					longAtput((oop1 + (BASE_HEADER_SIZE)) + ((variableIndex + TempFrameStart) << (SHIFT_FOR_WORD)), valuePointer1);
					goto l2;
				}
				if (variableType == 2) {
					error("illegal store");
				}
				if (variableType == 3) {
					/* begin literal:ofMethod: */
					methodPointer = foo->method;
					association = longAt((methodPointer + (BASE_HEADER_SIZE)) + ((variableIndex + LiteralStart) << (SHIFT_FOR_WORD)));
					/* begin storePointer:ofObject:withValue: */
					valuePointer2 = longAtPointer(localSP);
					if ((((usqInt) association)) < (((usqInt) foo->youngStart))) {
						possibleRootStoreIntovalue(association, valuePointer2);
					}
					longAtput((association + (BASE_HEADER_SIZE)) + (ValueIndex << (SHIFT_FOR_WORD)), valuePointer2);
					goto l2;
				}
			}
;
		l2:	/* end case */;
			break;
		case 130:
			/* extendedStoreAndPopBytecode */
			{
				sqInt association;
				sqInt descriptor;
				sqInt variableIndex;
				sqInt variableType;
				sqInt oop;
				sqInt valuePointer;
				sqInt oop1;
				sqInt valuePointer1;
				sqInt methodPointer;
				sqInt valuePointer2;
				/* begin extendedStoreBytecode */
				descriptor = byteAtPointer(++localIP);
				/* begin fetchNextBytecode */
				currentBytecode = byteAtPointer(++localIP);
				variableType = (((usqInt) descriptor) >> 6) & 3;
				variableIndex = descriptor & 63;
				if (variableType == 0) {
					/* begin storePointer:ofObject:withValue: */
					oop = foo->receiver;
					valuePointer = longAtPointer(localSP);
					if ((((usqInt) oop)) < (((usqInt) foo->youngStart))) {
						possibleRootStoreIntovalue(oop, valuePointer);
					}
					longAtput((oop + (BASE_HEADER_SIZE)) + (variableIndex << (SHIFT_FOR_WORD)), valuePointer);
					goto l3;
				}
				if (variableType == 1) {
					/* begin storePointerUnchecked:ofObject:withValue: */
					oop1 = localHomeContext;
					valuePointer1 = longAtPointer(localSP);
					longAtput((oop1 + (BASE_HEADER_SIZE)) + ((variableIndex + TempFrameStart) << (SHIFT_FOR_WORD)), valuePointer1);
					goto l3;
				}
				if (variableType == 2) {
					error("illegal store");
				}
				if (variableType == 3) {
					/* begin literal:ofMethod: */
					methodPointer = foo->method;
					association = longAt((methodPointer + (BASE_HEADER_SIZE)) + ((variableIndex + LiteralStart) << (SHIFT_FOR_WORD)));
					/* begin storePointer:ofObject:withValue: */
					valuePointer2 = longAtPointer(localSP);
					if ((((usqInt) association)) < (((usqInt) foo->youngStart))) {
						possibleRootStoreIntovalue(association, valuePointer2);
					}
					longAtput((association + (BASE_HEADER_SIZE)) + (ValueIndex << (SHIFT_FOR_WORD)), valuePointer2);
					goto l3;
				}
			l3:	/* end extendedStoreBytecode */;
				/* begin internalPop: */
				localSP -= 1 * (BYTES_PER_WORD);
			}
;
			break;
		case 131:
			/* singleExtendedSendBytecode */
			{
				sqInt descriptor;
				sqInt methodPointer;
				descriptor = byteAtPointer(++localIP);
				/* begin literal:ofMethod: */
				methodPointer = foo->method;
				foo->messageSelector = longAt((methodPointer + (BASE_HEADER_SIZE)) + (((descriptor & 31) + LiteralStart) << (SHIFT_FOR_WORD)));
				foo->argumentCount = ((usqInt) descriptor) >> 5;
				/* goto normalSend */
			}
;
			
		normalSend:
			/* normalSend */
			{
				sqInt rcvr;
				sqInt ccIndex;
				sqInt oop;
				sqInt oop1;
				sqInt oop2;
				rcvr = longAtPointer(localSP - (foo->argumentCount * (BYTES_PER_WORD)));
				/* begin fetchClassOf: */
				if ((rcvr & 1)) {
					/* begin fetchPointer:ofObject: */
					oop = foo->specialObjectsOop;
					foo->lkupClass = longAt((oop + (BASE_HEADER_SIZE)) + (ClassInteger << (SHIFT_FOR_WORD)));
					goto l44;
				}
				ccIndex = (((usqInt) (longAt(rcvr))) >> 12) & 31;
				if (ccIndex == 0) {
					foo->lkupClass = (longAt(rcvr - (BASE_HEADER_SIZE))) & (ALL_BUT_TYPE_MASK);
					goto l44;
				} else {
					/* begin fetchPointer:ofObject: */
					/* begin fetchPointer:ofObject: */
					oop2 = foo->specialObjectsOop;
					oop1 = longAt((oop2 + (BASE_HEADER_SIZE)) + (CompactClasses << (SHIFT_FOR_WORD)));
					foo->lkupClass = longAt((oop1 + (BASE_HEADER_SIZE)) + ((ccIndex - 1) << (SHIFT_FOR_WORD)));
					goto l44;
				}
			l44:	/* end fetchClassOf: */;
				foo->receiverClass = foo->lkupClass;
				/* goto commonSend */
			}
;
			
		commonSend:
			/* commonSend */
			{
				sqInt ok;
				sqInt hash;
				sqInt probe;
				sqInt delta;
				sqInt localPrimIndex;
				sqInt nArgs;
				sqInt oop;
				sqInt oop1;
				sqInt argCount2;
				sqInt i;
				sqInt methodHeader;
				sqInt needsLarge;
				sqInt newContext;
				sqInt tempCount;
				sqInt where;
				sqInt methodPointer;
				sqInt activeCntx;
				sqInt valuePointer;
				sqInt valuePointer1;
				sqInt tmp;
				/* begin internalFindNewMethod */
				/* begin lookupInMethodCacheSel:class: */
				hash = foo->messageSelector ^ foo->lkupClass;
				probe = hash & MethodCacheMask;
				if (((foo->methodCache[probe + MethodCacheSelector]) == foo->messageSelector) && ((foo->methodCache[probe + MethodCacheClass]) == foo->lkupClass)) {
					foo->newMethod = foo->methodCache[probe + MethodCacheMethod];
					foo->primitiveIndex = foo->methodCache[probe + MethodCachePrim];
					foo->newNativeMethod = foo->methodCache[probe + MethodCacheNative];
					foo->primitiveFunctionPointer = ((void *) (foo->methodCache[probe + MethodCachePrimFunction]));
					ok = 1;
					goto l45;
				}
				probe = (((usqInt) hash) >> 1) & MethodCacheMask;
				if (((foo->methodCache[probe + MethodCacheSelector]) == foo->messageSelector) && ((foo->methodCache[probe + MethodCacheClass]) == foo->lkupClass)) {
					foo->newMethod = foo->methodCache[probe + MethodCacheMethod];
					foo->primitiveIndex = foo->methodCache[probe + MethodCachePrim];
					foo->newNativeMethod = foo->methodCache[probe + MethodCacheNative];
					foo->primitiveFunctionPointer = ((void *) (foo->methodCache[probe + MethodCachePrimFunction]));
					ok = 1;
					goto l45;
				}
				probe = (((usqInt) hash) >> 2) & MethodCacheMask;
				if (((foo->methodCache[probe + MethodCacheSelector]) == foo->messageSelector) && ((foo->methodCache[probe + MethodCacheClass]) == foo->lkupClass)) {
					foo->newMethod = foo->methodCache[probe + MethodCacheMethod];
					foo->primitiveIndex = foo->methodCache[probe + MethodCachePrim];
					foo->newNativeMethod = foo->methodCache[probe + MethodCacheNative];
					foo->primitiveFunctionPointer = ((void *) (foo->methodCache[probe + MethodCachePrimFunction]));
					ok = 1;
					goto l45;
				}
				ok = 0;
			l45:	/* end lookupInMethodCacheSel:class: */;
				if (!(ok)) {
					/* begin externalizeIPandSP */
					foo->instructionPointer = oopForPointer(localIP);
					foo->stackPointer = oopForPointer(localSP);
					foo->theHomeContext = localHomeContext;
					lookupMethodInClass(foo->lkupClass);
					/* begin internalizeIPandSP */
					localIP = pointerForOop(foo->instructionPointer);
					localSP = pointerForOop(foo->stackPointer);
					localHomeContext = foo->theHomeContext;
					addNewMethodToCache();
				}
				/* begin internalExecuteNewMethod */
				localPrimIndex = foo->primitiveIndex;
				if (localPrimIndex > 0) {
					if ((localPrimIndex > 255) && (localPrimIndex < 520)) {
						if (localPrimIndex >= 264) {
							/* begin internalPop:thenPush: */
							/* begin fetchPointer:ofObject: */
							oop1 = longAtPointer(localSP);
							oop = longAt((oop1 + (BASE_HEADER_SIZE)) + ((localPrimIndex - 264) << (SHIFT_FOR_WORD)));
							longAtPointerput(localSP -= (1 - 1) * (BYTES_PER_WORD), oop);
							goto l46;
						} else {
							if (localPrimIndex == 256) {
								goto l46;
							}
							if (localPrimIndex == 257) {
								/* begin internalPop:thenPush: */
								longAtPointerput(localSP -= (1 - 1) * (BYTES_PER_WORD), foo->trueObj);
								goto l46;
							}
							if (localPrimIndex == 258) {
								/* begin internalPop:thenPush: */
								longAtPointerput(localSP -= (1 - 1) * (BYTES_PER_WORD), foo->falseObj);
								goto l46;
							}
							if (localPrimIndex == 259) {
								/* begin internalPop:thenPush: */
								longAtPointerput(localSP -= (1 - 1) * (BYTES_PER_WORD), foo->nilObj);
								goto l46;
							}
							/* begin internalPop:thenPush: */
							longAtPointerput(localSP -= (1 - 1) * (BYTES_PER_WORD), (((localPrimIndex - 261) << 1) | 1));
							goto l46;
						}
					} else {
						/* begin externalizeIPandSP */
						foo->instructionPointer = oopForPointer(localIP);
						foo->stackPointer = oopForPointer(localSP);
						foo->theHomeContext = localHomeContext;
						if (DoBalanceChecks) {
							nArgs = foo->argumentCount;
							delta = foo->stackPointer - foo->activeContext;
						}
						foo->successFlag = 1;
						dispatchFunctionPointer(foo->primitiveFunctionPointer);
						if (DoBalanceChecks) {
							if (!(balancedStackafterPrimitivewithArgs(delta, localPrimIndex, nArgs))) {
								printUnbalancedStack(localPrimIndex);
							}
						}
						/* begin internalizeIPandSP */
						localIP = pointerForOop(foo->instructionPointer);
						localSP = pointerForOop(foo->stackPointer);
						localHomeContext = foo->theHomeContext;
						if (foo->successFlag) {
							browserPluginReturnIfNeeded();
							goto l46;
						}
					}
				}
				/* begin internalActivateNewMethod */
				/* begin headerOf: */
				methodPointer = foo->newMethod;
				methodHeader = longAt((methodPointer + (BASE_HEADER_SIZE)) + (HeaderIndex << (SHIFT_FOR_WORD)));
				needsLarge = methodHeader & LargeContextBit;
				if ((needsLarge == 0) && (foo->freeContexts != NilContext)) {
					newContext = foo->freeContexts;
					foo->freeContexts = longAt((newContext + (BASE_HEADER_SIZE)) + (0 << (SHIFT_FOR_WORD)));
				} else {
					/* begin externalizeIPandSP */
					foo->instructionPointer = oopForPointer(localIP);
					foo->stackPointer = oopForPointer(localSP);
					foo->theHomeContext = localHomeContext;
					newContext = allocateOrRecycleContext(needsLarge);
					/* begin internalizeIPandSP */
					localIP = pointerForOop(foo->instructionPointer);
					localSP = pointerForOop(foo->stackPointer);
					localHomeContext = foo->theHomeContext;
				}
				tempCount = (((usqInt) methodHeader) >> 19) & 63;
				where = newContext + (BASE_HEADER_SIZE);
				longAtput(where + (SenderIndex << (SHIFT_FOR_WORD)), foo->activeContext);
				longAtput(where + (InstructionPointerIndex << (SHIFT_FOR_WORD)), (((((LiteralStart + ((((usqInt) methodHeader) >> 10) & 255)) * (BYTES_PER_WORD)) + 1) << 1) | 1));
				longAtput(where + (StackPointerIndex << (SHIFT_FOR_WORD)), ((tempCount << 1) | 1));
				longAtput(where + (MethodIndex << (SHIFT_FOR_WORD)), foo->newMethod);
				longAtput(where + (ClosureIndex << (SHIFT_FOR_WORD)), foo->nilObj);
				argCount2 = foo->argumentCount;
				for (i = 0; i <= argCount2; i += 1) {
					longAtput(where + ((ReceiverIndex + i) << (SHIFT_FOR_WORD)), longAtPointer(localSP - ((argCount2 - i) * (BYTES_PER_WORD))));
				}
				methodHeader = foo->nilObj;
				for (i = ((argCount2 + 1) + ReceiverIndex); i <= (tempCount + ReceiverIndex); i += 1) {
					longAtput(where + (i << (SHIFT_FOR_WORD)), methodHeader);
				}
				/* begin internalPop: */
				localSP -= (argCount2 + 1) * (BYTES_PER_WORD);
				foo->reclaimableContextCount += 1;
				/* begin internalNewActiveContext: */
				/* begin internalStoreContextRegisters: */
				activeCntx = foo->activeContext;
				/* begin storePointerUnchecked:ofObject:withValue: */
				valuePointer = (((((oopForPointer(localIP)) + 2) - (foo->method + (BASE_HEADER_SIZE))) << 1) | 1);
				longAtput((activeCntx + (BASE_HEADER_SIZE)) + (InstructionPointerIndex << (SHIFT_FOR_WORD)), valuePointer);
				/* begin storePointerUnchecked:ofObject:withValue: */
				valuePointer1 = (((((((usqInt) ((oopForPointer(localSP)) - (activeCntx + (BASE_HEADER_SIZE)))) >> (SHIFT_FOR_WORD)) - TempFrameStart) + 1) << 1) | 1);
				longAtput((activeCntx + (BASE_HEADER_SIZE)) + (StackPointerIndex << (SHIFT_FOR_WORD)), valuePointer1);
				if ((((usqInt) newContext)) < (((usqInt) foo->youngStart))) {
					beRootIfOld(newContext);
				}
				foo->activeContext = newContext;
				/* begin internalFetchContextRegisters: */
				tmp = longAt((newContext + (BASE_HEADER_SIZE)) + (MethodIndex << (SHIFT_FOR_WORD)));
				if ((tmp & 1)) {
					tmp = longAt((newContext + (BASE_HEADER_SIZE)) + (HomeIndex << (SHIFT_FOR_WORD)));
					if ((((usqInt) tmp)) < (((usqInt) foo->youngStart))) {
						beRootIfOld(tmp);
					}
				} else {
					tmp = newContext;
				}
				localHomeContext = tmp;
				foo->receiver = longAt((tmp + (BASE_HEADER_SIZE)) + (ReceiverIndex << (SHIFT_FOR_WORD)));
				foo->method = longAt((tmp + (BASE_HEADER_SIZE)) + (MethodIndex << (SHIFT_FOR_WORD)));
				tmp = ((longAt((newContext + (BASE_HEADER_SIZE)) + (InstructionPointerIndex << (SHIFT_FOR_WORD)))) >> 1);
				localIP = pointerForOop(((foo->method + tmp) + (BASE_HEADER_SIZE)) - 2);
				tmp = ((longAt((newContext + (BASE_HEADER_SIZE)) + (StackPointerIndex << (SHIFT_FOR_WORD)))) >> 1);
				localSP = pointerForOop((newContext + (BASE_HEADER_SIZE)) + (((TempFrameStart + tmp) - 1) * (BYTES_PER_WORD)));
				/* begin internalQuickCheckForInterrupts */
				if ((foo->interruptCheckCounter -= 1) <= 0) {
					/* begin externalizeIPandSP */
					foo->instructionPointer = oopForPointer(localIP);
					foo->stackPointer = oopForPointer(localSP);
					foo->theHomeContext = localHomeContext;
					checkForInterrupts();
					browserPluginReturnIfNeeded();
					/* begin internalizeIPandSP */
					localIP = pointerForOop(foo->instructionPointer);
					localSP = pointerForOop(foo->stackPointer);
					localHomeContext = foo->theHomeContext;
				}
			l46:	/* end internalExecuteNewMethod */;
				/* begin fetchNextBytecode */
				currentBytecode = byteAtPointer(++localIP);
			}
;
			break;
		case 132:
			/* doubleExtendedDoAnythingBytecode */
			{
				sqInt byte2;
				sqInt byte3;
				sqInt opType;
				sqInt top;
				sqInt methodPointer;
				sqInt methodPointer1;
				sqInt oop;
				sqInt oop1;
				sqInt oop2;
				sqInt object;
				sqInt oop3;
				sqInt methodPointer2;
				sqInt object1;
				sqInt methodPointer3;
				sqInt object2;
				sqInt oop4;
				sqInt methodPointer4;
				byte2 = byteAtPointer(++localIP);
				byte3 = byteAtPointer(++localIP);
				opType = ((usqInt) byte2) >> 5;
				if (opType == 0) {
					/* begin literal:ofMethod: */
					methodPointer = foo->method;
					foo->messageSelector = longAt((methodPointer + (BASE_HEADER_SIZE)) + ((byte3 + LiteralStart) << (SHIFT_FOR_WORD)));
					foo->argumentCount = byte2 & 31;
					goto normalSend;
					goto l4;
				}
				if (opType == 1) {
					/* begin literal:ofMethod: */
					methodPointer1 = foo->method;
					foo->messageSelector = longAt((methodPointer1 + (BASE_HEADER_SIZE)) + ((byte3 + LiteralStart) << (SHIFT_FOR_WORD)));
					foo->argumentCount = byte2 & 31;
					goto commonSupersend;
					goto l4;
				}
				/* begin fetchNextBytecode */
				currentBytecode = byteAtPointer(++localIP);
				if (opType == 2) {
					/* begin pushReceiverVariable: */
					/* begin internalPush: */
					/* begin fetchPointer:ofObject: */
					oop3 = foo->receiver;
					object = longAt((oop3 + (BASE_HEADER_SIZE)) + (byte3 << (SHIFT_FOR_WORD)));
					longAtPointerput(localSP += BYTES_PER_WORD, object);
					goto l4;
				}
				if (opType == 3) {
					/* begin pushLiteralConstant: */
					/* begin internalPush: */
					/* begin literal:ofMethod: */
					methodPointer3 = foo->method;
					object1 = longAt((methodPointer3 + (BASE_HEADER_SIZE)) + ((byte3 + LiteralStart) << (SHIFT_FOR_WORD)));
					longAtPointerput(localSP += BYTES_PER_WORD, object1);
					goto l4;
				}
				if (opType == 4) {
					/* begin pushLiteralVariable: */
					/* begin internalPush: */
					/* begin fetchPointer:ofObject: */
					/* begin literal:ofMethod: */
					methodPointer4 = foo->method;
					oop4 = longAt((methodPointer4 + (BASE_HEADER_SIZE)) + ((byte3 + LiteralStart) << (SHIFT_FOR_WORD)));
					object2 = longAt((oop4 + (BASE_HEADER_SIZE)) + (ValueIndex << (SHIFT_FOR_WORD)));
					longAtPointerput(localSP += BYTES_PER_WORD, object2);
					goto l4;
				}
				if (opType == 5) {
					top = longAtPointer(localSP);
					/* begin storePointer:ofObject:withValue: */
					oop = foo->receiver;
					if ((((usqInt) oop)) < (((usqInt) foo->youngStart))) {
						possibleRootStoreIntovalue(oop, top);
					}
					longAtput((oop + (BASE_HEADER_SIZE)) + (byte3 << (SHIFT_FOR_WORD)), top);
					goto l4;
				}
				if (opType == 6) {
					top = longAtPointer(localSP);
					/* begin internalPop: */
					localSP -= 1 * (BYTES_PER_WORD);
					/* begin storePointer:ofObject:withValue: */
					oop1 = foo->receiver;
					if ((((usqInt) oop1)) < (((usqInt) foo->youngStart))) {
						possibleRootStoreIntovalue(oop1, top);
					}
					longAtput((oop1 + (BASE_HEADER_SIZE)) + (byte3 << (SHIFT_FOR_WORD)), top);
					goto l4;
				}
				if (opType == 7) {
					top = longAtPointer(localSP);
					/* begin storePointer:ofObject:withValue: */
					/* begin literal:ofMethod: */
					methodPointer2 = foo->method;
					oop2 = longAt((methodPointer2 + (BASE_HEADER_SIZE)) + ((byte3 + LiteralStart) << (SHIFT_FOR_WORD)));
					if ((((usqInt) oop2)) < (((usqInt) foo->youngStart))) {
						possibleRootStoreIntovalue(oop2, top);
					}
					longAtput((oop2 + (BASE_HEADER_SIZE)) + (ValueIndex << (SHIFT_FOR_WORD)), top);
					goto l4;
				}
			}
;
		l4:	/* end case */;
			break;
		case 133:
			/* singleExtendedSuperBytecode */
			{
				sqInt descriptor;
				sqInt methodPointer;
				descriptor = byteAtPointer(++localIP);
				/* begin literal:ofMethod: */
				methodPointer = foo->method;
				foo->messageSelector = longAt((methodPointer + (BASE_HEADER_SIZE)) + (((descriptor & 31) + LiteralStart) << (SHIFT_FOR_WORD)));
				foo->argumentCount = ((usqInt) descriptor) >> 5;
				/* goto commonSupersend */
			}
;
			
		commonSupersend:
			/* superclassSend */
			{
				sqInt rcvr;
				sqInt classPointer;
				sqInt ccIndex;
				sqInt oop;
				sqInt oop1;
				sqInt oop2;
				sqInt methodPointer;
				sqInt oop3;
				sqInt offset;
				/* begin superclassOf: */
				/* begin methodClassOf: */
				methodPointer = foo->method;
				/* begin fetchPointer:ofObject: */
				/* begin literal:ofMethod: */
				offset = (literalCountOfHeader(longAt((methodPointer + (BASE_HEADER_SIZE)) + (HeaderIndex << (SHIFT_FOR_WORD))))) - 1;
				oop3 = longAt((methodPointer + (BASE_HEADER_SIZE)) + ((offset + LiteralStart) << (SHIFT_FOR_WORD)));
				classPointer = longAt((oop3 + (BASE_HEADER_SIZE)) + (ValueIndex << (SHIFT_FOR_WORD)));
				foo->lkupClass = longAt((classPointer + (BASE_HEADER_SIZE)) + (SuperclassIndex << (SHIFT_FOR_WORD)));
				rcvr = longAtPointer(localSP - (foo->argumentCount * (BYTES_PER_WORD)));
				/* begin fetchClassOf: */
				if ((rcvr & 1)) {
					/* begin fetchPointer:ofObject: */
					oop = foo->specialObjectsOop;
					foo->receiverClass = longAt((oop + (BASE_HEADER_SIZE)) + (ClassInteger << (SHIFT_FOR_WORD)));
					goto l47;
				}
				ccIndex = (((usqInt) (longAt(rcvr))) >> 12) & 31;
				if (ccIndex == 0) {
					foo->receiverClass = (longAt(rcvr - (BASE_HEADER_SIZE))) & (ALL_BUT_TYPE_MASK);
					goto l47;
				} else {
					/* begin fetchPointer:ofObject: */
					/* begin fetchPointer:ofObject: */
					oop2 = foo->specialObjectsOop;
					oop1 = longAt((oop2 + (BASE_HEADER_SIZE)) + (CompactClasses << (SHIFT_FOR_WORD)));
					foo->receiverClass = longAt((oop1 + (BASE_HEADER_SIZE)) + ((ccIndex - 1) << (SHIFT_FOR_WORD)));
					goto l47;
				}
			l47:	/* end fetchClassOf: */;
				goto commonSend;
			}
;
			break;
		case 134:
			/* secondExtendedSendBytecode */
			{
				sqInt descriptor;
				sqInt methodPointer;
				descriptor = byteAtPointer(++localIP);
				/* begin literal:ofMethod: */
				methodPointer = foo->method;
				foo->messageSelector = longAt((methodPointer + (BASE_HEADER_SIZE)) + (((descriptor & 63) + LiteralStart) << (SHIFT_FOR_WORD)));
				foo->argumentCount = ((usqInt) descriptor) >> 6;
				goto normalSend;
			}
;
			break;
		case 135:
			/* popStackBytecode */
			{
				/* begin fetchNextBytecode */
				currentBytecode = byteAtPointer(++localIP);
				/* begin internalPop: */
				localSP -= 1 * (BYTES_PER_WORD);
			}
;
			break;
		case 136:
			/* duplicateTopBytecode */
			{
				sqInt object;
				/* begin fetchNextBytecode */
				currentBytecode = byteAtPointer(++localIP);
				/* begin internalPush: */
				object = longAtPointer(localSP);
				longAtPointerput(localSP += BYTES_PER_WORD, object);
			}
;
			break;
		case 137:
			/* pushActiveContextBytecode */
			{
				/* begin fetchNextBytecode */
				currentBytecode = byteAtPointer(++localIP);
				foo->reclaimableContextCount = 0;
				/* begin internalPush: */
				longAtPointerput(localSP += BYTES_PER_WORD, foo->activeContext);
			}
;
			break;
		case 138:
			/* pushNewArrayBytecode */
			{
				sqInt array;
				sqInt i;
				sqInt popValues;
				sqInt size;
				sqInt valuePointer;
				size = byteAtPointer(++localIP);
				popValues = size > 127;
				size = size & 127;
				/* begin fetchNextBytecode */
				currentBytecode = byteAtPointer(++localIP);
				/* begin externalizeIPandSP */
				foo->instructionPointer = oopForPointer(localIP);
				foo->stackPointer = oopForPointer(localSP);
				foo->theHomeContext = localHomeContext;
				array = instantiateClassindexableSize(fetchPointerofObject(ClassArray, foo->specialObjectsOop), size);
				/* begin internalizeIPandSP */
				localIP = pointerForOop(foo->instructionPointer);
				localSP = pointerForOop(foo->stackPointer);
				localHomeContext = foo->theHomeContext;
				if (popValues) {
					for (i = 0; i <= (size - 1); i += 1) {
						/* begin storePointerUnchecked:ofObject:withValue: */
						valuePointer = longAtPointer(localSP - (((size - i) - 1) * (BYTES_PER_WORD)));
						longAtput((array + (BASE_HEADER_SIZE)) + (i << (SHIFT_FOR_WORD)), valuePointer);
					}
					/* begin internalPop: */
					localSP -= size * (BYTES_PER_WORD);
				}
				/* begin internalPush: */
				longAtPointerput(localSP += BYTES_PER_WORD, array);
			}
;
			break;
		case 139:
			/* unknownBytecode */
			{
				error("Unknown bytecode");
			}
;
			break;
		case 140:
			/* pushRemoteTempLongBytecode */
			{
				sqInt remoteTempIndex;
				sqInt tempVectorIndex;
				sqInt tempVector;
				sqInt oop;
				sqInt object;
				remoteTempIndex = byteAtPointer(++localIP);
				tempVectorIndex = byteAtPointer(++localIP);
				/* begin fetchNextBytecode */
				currentBytecode = byteAtPointer(++localIP);
				/* begin pushRemoteTemp:inVectorAt: */
				/* begin fetchPointer:ofObject: */
				oop = localHomeContext;
				tempVector = longAt((oop + (BASE_HEADER_SIZE)) + ((tempVectorIndex + TempFrameStart) << (SHIFT_FOR_WORD)));
				/* begin internalPush: */
				object = longAt((tempVector + (BASE_HEADER_SIZE)) + (remoteTempIndex << (SHIFT_FOR_WORD)));
				longAtPointerput(localSP += BYTES_PER_WORD, object);
			}
;
			break;
		case 141:
			/* storeRemoteTempLongBytecode */
			{
				sqInt remoteTempIndex;
				sqInt tempVectorIndex;
				sqInt tempVector;
				sqInt oop;
				sqInt valuePointer;
				remoteTempIndex = byteAtPointer(++localIP);
				tempVectorIndex = byteAtPointer(++localIP);
				/* begin fetchNextBytecode */
				currentBytecode = byteAtPointer(++localIP);
				/* begin storeRemoteTemp:inVectorAt: */
				/* begin fetchPointer:ofObject: */
				oop = localHomeContext;
				tempVector = longAt((oop + (BASE_HEADER_SIZE)) + ((tempVectorIndex + TempFrameStart) << (SHIFT_FOR_WORD)));
				/* begin storePointer:ofObject:withValue: */
				valuePointer = longAtPointer(localSP);
				if ((((usqInt) tempVector)) < (((usqInt) foo->youngStart))) {
					possibleRootStoreIntovalue(tempVector, valuePointer);
				}
				longAtput((tempVector + (BASE_HEADER_SIZE)) + (remoteTempIndex << (SHIFT_FOR_WORD)), valuePointer);
			}
;
			break;
		case 142:
			/* storeAndPopRemoteTempLongBytecode */
			{
				sqInt remoteTempIndex;
				sqInt tempVectorIndex;
				sqInt tempVector;
				sqInt oop;
				sqInt valuePointer;
				/* begin storeRemoteTempLongBytecode */
				remoteTempIndex = byteAtPointer(++localIP);
				tempVectorIndex = byteAtPointer(++localIP);
				/* begin fetchNextBytecode */
				currentBytecode = byteAtPointer(++localIP);
				/* begin storeRemoteTemp:inVectorAt: */
				/* begin fetchPointer:ofObject: */
				oop = localHomeContext;
				tempVector = longAt((oop + (BASE_HEADER_SIZE)) + ((tempVectorIndex + TempFrameStart) << (SHIFT_FOR_WORD)));
				/* begin storePointer:ofObject:withValue: */
				valuePointer = longAtPointer(localSP);
				if ((((usqInt) tempVector)) < (((usqInt) foo->youngStart))) {
					possibleRootStoreIntovalue(tempVector, valuePointer);
				}
				longAtput((tempVector + (BASE_HEADER_SIZE)) + (remoteTempIndex << (SHIFT_FOR_WORD)), valuePointer);
				/* begin internalPop: */
				localSP -= 1 * (BYTES_PER_WORD);
			}
;
			break;
		case 143:
			/* pushClosureCopyCopiedValuesBytecode */
			{
				sqInt blockSize;
				sqInt i;
				sqInt newClosure;
				sqInt numArgs;
				sqInt numArgsNumCopied;
				sqInt numCopied;
				sqInt valuePointer;
				sqInt initialIP;
				sqInt newClosure1;
				sqInt valuePointer1;
				if ((BYTES_PER_WORD) == 4) {
					imageFormatVersionNumber = 6504;
				} else {
					imageFormatVersionNumber = 68002;
				}
				numArgsNumCopied = byteAtPointer(++localIP);
				numArgs = numArgsNumCopied & 15;
				numCopied = ((usqInt) numArgsNumCopied >> 4);
				blockSize = (byteAtPointer(++localIP)) << 8;
				blockSize += byteAtPointer(++localIP);
				/* begin externalizeIPandSP */
				foo->instructionPointer = oopForPointer(localIP);
				foo->stackPointer = oopForPointer(localSP);
				foo->theHomeContext = localHomeContext;
				/* begin closureNumArgs:instructionPointer:numCopiedValues: */
				initialIP = ((oopForPointer(localIP)) + 2) - (foo->method + (BASE_HEADER_SIZE));
				newClosure1 = instantiateSmallClasssizeInBytes(fetchPointerofObject(ClassBlockClosure, foo->specialObjectsOop), ((BYTES_PER_WORD) * (ClosureFirstCopiedValueIndex + numCopied)) + (BASE_HEADER_SIZE));
				longAtput((newClosure1 + (BASE_HEADER_SIZE)) + (ClosureStartPCIndex << (SHIFT_FOR_WORD)), ((initialIP << 1) | 1));
				longAtput((newClosure1 + (BASE_HEADER_SIZE)) + (ClosureNumArgsIndex << (SHIFT_FOR_WORD)), ((numArgs << 1) | 1));
				newClosure = newClosure1;
				/* begin internalizeIPandSP */
				localIP = pointerForOop(foo->instructionPointer);
				localSP = pointerForOop(foo->stackPointer);
				localHomeContext = foo->theHomeContext;
				/* begin storePointerUnchecked:ofObject:withValue: */
				valuePointer1 = foo->activeContext;
				longAtput((newClosure + (BASE_HEADER_SIZE)) + (ClosureOuterContextIndex << (SHIFT_FOR_WORD)), valuePointer1);
				foo->reclaimableContextCount = 0;
				if (numCopied > 0) {
					for (i = 0; i <= (numCopied - 1); i += 1) {
						/* begin storePointerUnchecked:ofObject:withValue: */
						valuePointer = longAtPointer(localSP - (((numCopied - i) - 1) * (BYTES_PER_WORD)));
						longAtput((newClosure + (BASE_HEADER_SIZE)) + ((i + ClosureFirstCopiedValueIndex) << (SHIFT_FOR_WORD)), valuePointer);
					}
					/* begin internalPop: */
					localSP -= numCopied * (BYTES_PER_WORD);
				}
				localIP += blockSize;
				/* begin fetchNextBytecode */
				currentBytecode = byteAtPointer(++localIP);
				/* begin internalPush: */
				longAtPointerput(localSP += BYTES_PER_WORD, newClosure);
			}
;
			break;
		case 144:
			/* shortUnconditionalJump */
			{
				sqInt offset;
				/* begin jump: */
				offset = (144 & 7) + 1;
				localIP = (localIP + offset) + 1;
				currentBytecode = byteAtPointer(localIP);
			}
;
			break;
		case 145:
			/* shortUnconditionalJump */
			{
				sqInt offset;
				/* begin jump: */
				offset = (145 & 7) + 1;
				localIP = (localIP + offset) + 1;
				currentBytecode = byteAtPointer(localIP);
			}
;
			break;
		case 146:
			/* shortUnconditionalJump */
			{
				sqInt offset;
				/* begin jump: */
				offset = (146 & 7) + 1;
				localIP = (localIP + offset) + 1;
				currentBytecode = byteAtPointer(localIP);
			}
;
			break;
		case 147:
			/* shortUnconditionalJump */
			{
				sqInt offset;
				/* begin jump: */
				offset = (147 & 7) + 1;
				localIP = (localIP + offset) + 1;
				currentBytecode = byteAtPointer(localIP);
			}
;
			break;
		case 148:
			/* shortUnconditionalJump */
			{
				sqInt offset;
				/* begin jump: */
				offset = (148 & 7) + 1;
				localIP = (localIP + offset) + 1;
				currentBytecode = byteAtPointer(localIP);
			}
;
			break;
		case 149:
			/* shortUnconditionalJump */
			{
				sqInt offset;
				/* begin jump: */
				offset = (149 & 7) + 1;
				localIP = (localIP + offset) + 1;
				currentBytecode = byteAtPointer(localIP);
			}
;
			break;
		case 150:
			/* shortUnconditionalJump */
			{
				sqInt offset;
				/* begin jump: */
				offset = (150 & 7) + 1;
				localIP = (localIP + offset) + 1;
				currentBytecode = byteAtPointer(localIP);
			}
;
			break;
		case 151:
			/* shortUnconditionalJump */
			{
				sqInt offset;
				/* begin jump: */
				offset = (151 & 7) + 1;
				localIP = (localIP + offset) + 1;
				currentBytecode = byteAtPointer(localIP);
			}
;
			break;
		case 152:
		case 153:
		case 154:
		case 155:
		case 156:
		case 157:
		case 158:
		case 159:
			/* shortConditionalJump */
			{
				sqInt offset;
				sqInt boolean;
				sqInt oop;
				/* begin jumplfFalseBy: */
				offset = (currentBytecode & 7) + 1;
				boolean = longAtPointer(localSP);
				if (boolean == foo->falseObj) {
					/* begin jump: */
					localIP = (localIP + offset) + 1;
					currentBytecode = byteAtPointer(localIP);
				} else {
					if (!(boolean == foo->trueObj)) {
						/* begin fetchPointer:ofObject: */
						oop = foo->specialObjectsOop;
						foo->messageSelector = longAt((oop + (BASE_HEADER_SIZE)) + (SelectorMustBeBoolean << (SHIFT_FOR_WORD)));
						foo->argumentCount = 0;
						goto normalSend;
						goto l5;
					}
					/* begin fetchNextBytecode */
					currentBytecode = byteAtPointer(++localIP);
				}
				/* begin internalPop: */
				localSP -= 1 * (BYTES_PER_WORD);
			l5:	/* end jumplfFalseBy: */;
			}
;
			break;
		case 160:
		case 161:
		case 162:
		case 163:
		case 164:
		case 165:
		case 166:
		case 167:
			/* longUnconditionalJump */
			{
				sqInt offset;
				offset = (((currentBytecode & 7) - 4) * 256) + (byteAtPointer(++localIP));
				localIP += offset;
				if (offset < 0) {
					/* begin internalQuickCheckForInterrupts */
					if ((foo->interruptCheckCounter -= 1) <= 0) {
						/* begin externalizeIPandSP */
						foo->instructionPointer = oopForPointer(localIP);
						foo->stackPointer = oopForPointer(localSP);
						foo->theHomeContext = localHomeContext;
						checkForInterrupts();
						browserPluginReturnIfNeeded();
						/* begin internalizeIPandSP */
						localIP = pointerForOop(foo->instructionPointer);
						localSP = pointerForOop(foo->stackPointer);
						localHomeContext = foo->theHomeContext;
					}
				}
				/* begin fetchNextBytecode */
				currentBytecode = byteAtPointer(++localIP);
			}
;
			break;
		case 168:
		case 169:
		case 170:
		case 171:
			/* longJumpIfTrue */
			{
				sqInt offset;
				sqInt boolean;
				sqInt oop;
				/* begin jumplfTrueBy: */
				offset = ((currentBytecode & 3) * 256) + (byteAtPointer(++localIP));
				boolean = longAtPointer(localSP);
				if (boolean == foo->trueObj) {
					/* begin jump: */
					localIP = (localIP + offset) + 1;
					currentBytecode = byteAtPointer(localIP);
				} else {
					if (!(boolean == foo->falseObj)) {
						/* begin fetchPointer:ofObject: */
						oop = foo->specialObjectsOop;
						foo->messageSelector = longAt((oop + (BASE_HEADER_SIZE)) + (SelectorMustBeBoolean << (SHIFT_FOR_WORD)));
						foo->argumentCount = 0;
						goto normalSend;
						goto l6;
					}
					/* begin fetchNextBytecode */
					currentBytecode = byteAtPointer(++localIP);
				}
				/* begin internalPop: */
				localSP -= 1 * (BYTES_PER_WORD);
			l6:	/* end jumplfTrueBy: */;
			}
;
			break;
		case 172:
		case 173:
		case 174:
		case 175:
			/* longJumpIfFalse */
			{
				sqInt offset;
				sqInt boolean;
				sqInt oop;
				/* begin jumplfFalseBy: */
				offset = ((currentBytecode & 3) * 256) + (byteAtPointer(++localIP));
				boolean = longAtPointer(localSP);
				if (boolean == foo->falseObj) {
					/* begin jump: */
					localIP = (localIP + offset) + 1;
					currentBytecode = byteAtPointer(localIP);
				} else {
					if (!(boolean == foo->trueObj)) {
						/* begin fetchPointer:ofObject: */
						oop = foo->specialObjectsOop;
						foo->messageSelector = longAt((oop + (BASE_HEADER_SIZE)) + (SelectorMustBeBoolean << (SHIFT_FOR_WORD)));
						foo->argumentCount = 0;
						goto normalSend;
						goto l7;
					}
					/* begin fetchNextBytecode */
					currentBytecode = byteAtPointer(++localIP);
				}
				/* begin internalPop: */
				localSP -= 1 * (BYTES_PER_WORD);
			l7:	/* end jumplfFalseBy: */;
			}
;
			break;
		case 176:
			/* bytecodePrimAdd */
			{
				sqInt arg;
				sqInt rcvr;
				sqInt result;
				sqInt oop;
				sqInt oop1;
				rcvr = longAtPointer(localSP - (1 * (BYTES_PER_WORD)));
				arg = longAtPointer(localSP - (0 * (BYTES_PER_WORD)));
				if (((rcvr & arg) & 1) != 0) {
					result = ((rcvr >> 1)) + ((arg >> 1));
					if (
# ifdef SQ_HOST32  // cast to int for 64 bit image on 32 bit host
						(((((int) result)) ^ ((((int) result)) << 1)) >= 0)
# else
						((result >= -1073741824) && (result <= 1073741823))
# endif  // SQ_HOST32
					) {
						/* begin internalPop:thenPush: */
						longAtPointerput(localSP -= (2 - 1) * (BYTES_PER_WORD), ((result << 1) | 1));
						/* begin fetchNextBytecode */
						currentBytecode = byteAtPointer(++localIP);
						goto l8;
					}
				} else {
					foo->successFlag = 1;
					/* begin externalizeIPandSP */
					foo->instructionPointer = oopForPointer(localIP);
					foo->stackPointer = oopForPointer(localSP);
					foo->theHomeContext = localHomeContext;
					primitiveFloatAddtoArg(rcvr, arg);
					/* begin internalizeIPandSP */
					localIP = pointerForOop(foo->instructionPointer);
					localSP = pointerForOop(foo->stackPointer);
					localHomeContext = foo->theHomeContext;
					if (foo->successFlag) {
						/* begin fetchNextBytecode */
						currentBytecode = byteAtPointer(++localIP);
						goto l8;
					}
				}
				/* begin fetchPointer:ofObject: */
				/* begin fetchPointer:ofObject: */
				oop1 = foo->specialObjectsOop;
				oop = longAt((oop1 + (BASE_HEADER_SIZE)) + (SpecialSelectors << (SHIFT_FOR_WORD)));
				foo->messageSelector = longAt((oop + (BASE_HEADER_SIZE)) + ((0 * 2) << (SHIFT_FOR_WORD)));
				foo->argumentCount = 1;
				goto normalSend;
			}
;
		l8:	/* end case */;
			break;
		case 177:
			/* bytecodePrimSubtract */
			{
				sqInt arg;
				sqInt rcvr;
				sqInt result;
				sqInt oop;
				sqInt oop1;
				rcvr = longAtPointer(localSP - (1 * (BYTES_PER_WORD)));
				arg = longAtPointer(localSP - (0 * (BYTES_PER_WORD)));
				if (((rcvr & arg) & 1) != 0) {
					result = ((rcvr >> 1)) - ((arg >> 1));
					if (
# ifdef SQ_HOST32  // cast to int for 64 bit image on 32 bit host
						(((((int) result)) ^ ((((int) result)) << 1)) >= 0)
# else
						((result >= -1073741824) && (result <= 1073741823))
# endif  // SQ_HOST32
					) {
						/* begin internalPop:thenPush: */
						longAtPointerput(localSP -= (2 - 1) * (BYTES_PER_WORD), ((result << 1) | 1));
						/* begin fetchNextBytecode */
						currentBytecode = byteAtPointer(++localIP);
						goto l9;
					}
				} else {
					foo->successFlag = 1;
					/* begin externalizeIPandSP */
					foo->instructionPointer = oopForPointer(localIP);
					foo->stackPointer = oopForPointer(localSP);
					foo->theHomeContext = localHomeContext;
					primitiveFloatSubtractfromArg(rcvr, arg);
					/* begin internalizeIPandSP */
					localIP = pointerForOop(foo->instructionPointer);
					localSP = pointerForOop(foo->stackPointer);
					localHomeContext = foo->theHomeContext;
					if (foo->successFlag) {
						/* begin fetchNextBytecode */
						currentBytecode = byteAtPointer(++localIP);
						goto l9;
					}
				}
				/* begin fetchPointer:ofObject: */
				/* begin fetchPointer:ofObject: */
				oop1 = foo->specialObjectsOop;
				oop = longAt((oop1 + (BASE_HEADER_SIZE)) + (SpecialSelectors << (SHIFT_FOR_WORD)));
				foo->messageSelector = longAt((oop + (BASE_HEADER_SIZE)) + ((1 * 2) << (SHIFT_FOR_WORD)));
				foo->argumentCount = 1;
				goto normalSend;
			}
;
		l9:	/* end case */;
			break;
		case 178:
			/* bytecodePrimLessThan */
			{
				sqInt aBool;
				sqInt arg;
				sqInt rcvr;
				sqInt oop;
				sqInt bytecode;
				sqInt offset;
				sqInt bytecode1;
				sqInt offset1;
				sqInt bytecode2;
				sqInt offset2;
				sqInt oop1;
				rcvr = longAtPointer(localSP - (1 * (BYTES_PER_WORD)));
				arg = longAtPointer(localSP - (0 * (BYTES_PER_WORD)));
				if (((rcvr & arg) & 1) != 0) {
					;
					/* begin booleanCheat: */
					bytecode1 = byteAtPointer(++localIP);
					/* begin internalPop: */
					localSP -= 2 * (BYTES_PER_WORD);
					if ((bytecode1 < 160) && (bytecode1 > 151)) {
						if (rcvr < arg) {
							/* begin fetchNextBytecode */
							currentBytecode = byteAtPointer(++localIP);
							goto l10;
						} else {
							/* begin jump: */
							localIP = (localIP + (bytecode1 - 151)) + 1;
							currentBytecode = byteAtPointer(localIP);
							goto l10;
						}
					}
					if (bytecode1 == 172) {
						offset1 = byteAtPointer(++localIP);
						if (rcvr < arg) {
							/* begin fetchNextBytecode */
							currentBytecode = byteAtPointer(++localIP);
							goto l10;
						} else {
							/* begin jump: */
							localIP = (localIP + offset1) + 1;
							currentBytecode = byteAtPointer(localIP);
							goto l10;
						}
					}
					localIP -= 1;
					/* begin fetchNextBytecode */
					currentBytecode = byteAtPointer(++localIP);
					if (rcvr < arg) {
						/* begin internalPush: */
						longAtPointerput(localSP += BYTES_PER_WORD, foo->trueObj);
					} else {
						/* begin internalPush: */
						longAtPointerput(localSP += BYTES_PER_WORD, foo->falseObj);
					}
					goto l10;
				}
				foo->successFlag = 1;
				aBool = primitiveFloatLessthanArg(rcvr, arg);
				if (foo->successFlag) {
					/* begin booleanCheat: */
					bytecode2 = byteAtPointer(++localIP);
					/* begin internalPop: */
					localSP -= 2 * (BYTES_PER_WORD);
					if ((bytecode2 < 160) && (bytecode2 > 151)) {
						if (aBool) {
							/* begin fetchNextBytecode */
							currentBytecode = byteAtPointer(++localIP);
							goto l10;
						} else {
							/* begin jump: */
							localIP = (localIP + (bytecode2 - 151)) + 1;
							currentBytecode = byteAtPointer(localIP);
							goto l10;
						}
					}
					if (bytecode2 == 172) {
						offset2 = byteAtPointer(++localIP);
						if (aBool) {
							/* begin fetchNextBytecode */
							currentBytecode = byteAtPointer(++localIP);
							goto l10;
						} else {
							/* begin jump: */
							localIP = (localIP + offset2) + 1;
							currentBytecode = byteAtPointer(localIP);
							goto l10;
						}
					}
					localIP -= 1;
					/* begin fetchNextBytecode */
					currentBytecode = byteAtPointer(++localIP);
					if (aBool) {
						/* begin internalPush: */
						longAtPointerput(localSP += BYTES_PER_WORD, foo->trueObj);
					} else {
						/* begin internalPush: */
						longAtPointerput(localSP += BYTES_PER_WORD, foo->falseObj);
					}
					goto l10;
				}
				/* begin fetchPointer:ofObject: */
				/* begin fetchPointer:ofObject: */
				oop1 = foo->specialObjectsOop;
				oop = longAt((oop1 + (BASE_HEADER_SIZE)) + (SpecialSelectors << (SHIFT_FOR_WORD)));
				foo->messageSelector = longAt((oop + (BASE_HEADER_SIZE)) + ((2 * 2) << (SHIFT_FOR_WORD)));
				foo->argumentCount = 1;
				goto normalSend;
			}
;
		l10:	/* end case */;
			break;
		case 179:
			/* bytecodePrimGreaterThan */
			{
				sqInt aBool;
				sqInt arg;
				sqInt rcvr;
				sqInt oop;
				sqInt bytecode;
				sqInt offset;
				sqInt bytecode1;
				sqInt offset1;
				sqInt bytecode2;
				sqInt offset2;
				sqInt oop1;
				rcvr = longAtPointer(localSP - (1 * (BYTES_PER_WORD)));
				arg = longAtPointer(localSP - (0 * (BYTES_PER_WORD)));
				if (((rcvr & arg) & 1) != 0) {
					;
					/* begin booleanCheat: */
					bytecode1 = byteAtPointer(++localIP);
					/* begin internalPop: */
					localSP -= 2 * (BYTES_PER_WORD);
					if ((bytecode1 < 160) && (bytecode1 > 151)) {
						if (rcvr > arg) {
							/* begin fetchNextBytecode */
							currentBytecode = byteAtPointer(++localIP);
							goto l11;
						} else {
							/* begin jump: */
							localIP = (localIP + (bytecode1 - 151)) + 1;
							currentBytecode = byteAtPointer(localIP);
							goto l11;
						}
					}
					if (bytecode1 == 172) {
						offset1 = byteAtPointer(++localIP);
						if (rcvr > arg) {
							/* begin fetchNextBytecode */
							currentBytecode = byteAtPointer(++localIP);
							goto l11;
						} else {
							/* begin jump: */
							localIP = (localIP + offset1) + 1;
							currentBytecode = byteAtPointer(localIP);
							goto l11;
						}
					}
					localIP -= 1;
					/* begin fetchNextBytecode */
					currentBytecode = byteAtPointer(++localIP);
					if (rcvr > arg) {
						/* begin internalPush: */
						longAtPointerput(localSP += BYTES_PER_WORD, foo->trueObj);
					} else {
						/* begin internalPush: */
						longAtPointerput(localSP += BYTES_PER_WORD, foo->falseObj);
					}
					goto l11;
				}
				foo->successFlag = 1;
				aBool = primitiveFloatGreaterthanArg(rcvr, arg);
				if (foo->successFlag) {
					/* begin booleanCheat: */
					bytecode2 = byteAtPointer(++localIP);
					/* begin internalPop: */
					localSP -= 2 * (BYTES_PER_WORD);
					if ((bytecode2 < 160) && (bytecode2 > 151)) {
						if (aBool) {
							/* begin fetchNextBytecode */
							currentBytecode = byteAtPointer(++localIP);
							goto l11;
						} else {
							/* begin jump: */
							localIP = (localIP + (bytecode2 - 151)) + 1;
							currentBytecode = byteAtPointer(localIP);
							goto l11;
						}
					}
					if (bytecode2 == 172) {
						offset2 = byteAtPointer(++localIP);
						if (aBool) {
							/* begin fetchNextBytecode */
							currentBytecode = byteAtPointer(++localIP);
							goto l11;
						} else {
							/* begin jump: */
							localIP = (localIP + offset2) + 1;
							currentBytecode = byteAtPointer(localIP);
							goto l11;
						}
					}
					localIP -= 1;
					/* begin fetchNextBytecode */
					currentBytecode = byteAtPointer(++localIP);
					if (aBool) {
						/* begin internalPush: */
						longAtPointerput(localSP += BYTES_PER_WORD, foo->trueObj);
					} else {
						/* begin internalPush: */
						longAtPointerput(localSP += BYTES_PER_WORD, foo->falseObj);
					}
					goto l11;
				}
				/* begin fetchPointer:ofObject: */
				/* begin fetchPointer:ofObject: */
				oop1 = foo->specialObjectsOop;
				oop = longAt((oop1 + (BASE_HEADER_SIZE)) + (SpecialSelectors << (SHIFT_FOR_WORD)));
				foo->messageSelector = longAt((oop + (BASE_HEADER_SIZE)) + ((3 * 2) << (SHIFT_FOR_WORD)));
				foo->argumentCount = 1;
				goto normalSend;
			}
;
		l11:	/* end case */;
			break;
		case 180:
			/* bytecodePrimLessOrEqual */
			{
				sqInt aBool;
				sqInt arg;
				sqInt rcvr;
				sqInt oop;
				sqInt bytecode;
				sqInt offset;
				sqInt bytecode1;
				sqInt offset1;
				sqInt bytecode2;
				sqInt offset2;
				sqInt oop1;
				rcvr = longAtPointer(localSP - (1 * (BYTES_PER_WORD)));
				arg = longAtPointer(localSP - (0 * (BYTES_PER_WORD)));
				if (((rcvr & arg) & 1) != 0) {
					;
					/* begin booleanCheat: */
					bytecode1 = byteAtPointer(++localIP);
					/* begin internalPop: */
					localSP -= 2 * (BYTES_PER_WORD);
					if ((bytecode1 < 160) && (bytecode1 > 151)) {
						if (rcvr <= arg) {
							/* begin fetchNextBytecode */
							currentBytecode = byteAtPointer(++localIP);
							goto l12;
						} else {
							/* begin jump: */
							localIP = (localIP + (bytecode1 - 151)) + 1;
							currentBytecode = byteAtPointer(localIP);
							goto l12;
						}
					}
					if (bytecode1 == 172) {
						offset1 = byteAtPointer(++localIP);
						if (rcvr <= arg) {
							/* begin fetchNextBytecode */
							currentBytecode = byteAtPointer(++localIP);
							goto l12;
						} else {
							/* begin jump: */
							localIP = (localIP + offset1) + 1;
							currentBytecode = byteAtPointer(localIP);
							goto l12;
						}
					}
					localIP -= 1;
					/* begin fetchNextBytecode */
					currentBytecode = byteAtPointer(++localIP);
					if (rcvr <= arg) {
						/* begin internalPush: */
						longAtPointerput(localSP += BYTES_PER_WORD, foo->trueObj);
					} else {
						/* begin internalPush: */
						longAtPointerput(localSP += BYTES_PER_WORD, foo->falseObj);
					}
					goto l12;
				}
				foo->successFlag = 1;
				aBool = primitiveFloatLessOrEqualtoArg(rcvr, arg);
				if (foo->successFlag) {
					/* begin booleanCheat: */
					bytecode2 = byteAtPointer(++localIP);
					/* begin internalPop: */
					localSP -= 2 * (BYTES_PER_WORD);
					if ((bytecode2 < 160) && (bytecode2 > 151)) {
						if (aBool) {
							/* begin fetchNextBytecode */
							currentBytecode = byteAtPointer(++localIP);
							goto l12;
						} else {
							/* begin jump: */
							localIP = (localIP + (bytecode2 - 151)) + 1;
							currentBytecode = byteAtPointer(localIP);
							goto l12;
						}
					}
					if (bytecode2 == 172) {
						offset2 = byteAtPointer(++localIP);
						if (aBool) {
							/* begin fetchNextBytecode */
							currentBytecode = byteAtPointer(++localIP);
							goto l12;
						} else {
							/* begin jump: */
							localIP = (localIP + offset2) + 1;
							currentBytecode = byteAtPointer(localIP);
							goto l12;
						}
					}
					localIP -= 1;
					/* begin fetchNextBytecode */
					currentBytecode = byteAtPointer(++localIP);
					if (aBool) {
						/* begin internalPush: */
						longAtPointerput(localSP += BYTES_PER_WORD, foo->trueObj);
					} else {
						/* begin internalPush: */
						longAtPointerput(localSP += BYTES_PER_WORD, foo->falseObj);
					}
					goto l12;
				}
				/* begin fetchPointer:ofObject: */
				/* begin fetchPointer:ofObject: */
				oop1 = foo->specialObjectsOop;
				oop = longAt((oop1 + (BASE_HEADER_SIZE)) + (SpecialSelectors << (SHIFT_FOR_WORD)));
				foo->messageSelector = longAt((oop + (BASE_HEADER_SIZE)) + ((4 * 2) << (SHIFT_FOR_WORD)));
				foo->argumentCount = 1;
				goto normalSend;
			}
;
		l12:	/* end case */;
			break;
		case 181:
			/* bytecodePrimGreaterOrEqual */
			{
				sqInt aBool;
				sqInt arg;
				sqInt rcvr;
				sqInt oop;
				sqInt bytecode;
				sqInt offset;
				sqInt bytecode1;
				sqInt offset1;
				sqInt bytecode2;
				sqInt offset2;
				sqInt oop1;
				rcvr = longAtPointer(localSP - (1 * (BYTES_PER_WORD)));
				arg = longAtPointer(localSP - (0 * (BYTES_PER_WORD)));
				if (((rcvr & arg) & 1) != 0) {
					;
					/* begin booleanCheat: */
					bytecode1 = byteAtPointer(++localIP);
					/* begin internalPop: */
					localSP -= 2 * (BYTES_PER_WORD);
					if ((bytecode1 < 160) && (bytecode1 > 151)) {
						if (rcvr >= arg) {
							/* begin fetchNextBytecode */
							currentBytecode = byteAtPointer(++localIP);
							goto l13;
						} else {
							/* begin jump: */
							localIP = (localIP + (bytecode1 - 151)) + 1;
							currentBytecode = byteAtPointer(localIP);
							goto l13;
						}
					}
					if (bytecode1 == 172) {
						offset1 = byteAtPointer(++localIP);
						if (rcvr >= arg) {
							/* begin fetchNextBytecode */
							currentBytecode = byteAtPointer(++localIP);
							goto l13;
						} else {
							/* begin jump: */
							localIP = (localIP + offset1) + 1;
							currentBytecode = byteAtPointer(localIP);
							goto l13;
						}
					}
					localIP -= 1;
					/* begin fetchNextBytecode */
					currentBytecode = byteAtPointer(++localIP);
					if (rcvr >= arg) {
						/* begin internalPush: */
						longAtPointerput(localSP += BYTES_PER_WORD, foo->trueObj);
					} else {
						/* begin internalPush: */
						longAtPointerput(localSP += BYTES_PER_WORD, foo->falseObj);
					}
					goto l13;
				}
				foo->successFlag = 1;
				aBool = primitiveFloatGreaterOrEqualtoArg(rcvr, arg);
				if (foo->successFlag) {
					/* begin booleanCheat: */
					bytecode2 = byteAtPointer(++localIP);
					/* begin internalPop: */
					localSP -= 2 * (BYTES_PER_WORD);
					if ((bytecode2 < 160) && (bytecode2 > 151)) {
						if (aBool) {
							/* begin fetchNextBytecode */
							currentBytecode = byteAtPointer(++localIP);
							goto l13;
						} else {
							/* begin jump: */
							localIP = (localIP + (bytecode2 - 151)) + 1;
							currentBytecode = byteAtPointer(localIP);
							goto l13;
						}
					}
					if (bytecode2 == 172) {
						offset2 = byteAtPointer(++localIP);
						if (aBool) {
							/* begin fetchNextBytecode */
							currentBytecode = byteAtPointer(++localIP);
							goto l13;
						} else {
							/* begin jump: */
							localIP = (localIP + offset2) + 1;
							currentBytecode = byteAtPointer(localIP);
							goto l13;
						}
					}
					localIP -= 1;
					/* begin fetchNextBytecode */
					currentBytecode = byteAtPointer(++localIP);
					if (aBool) {
						/* begin internalPush: */
						longAtPointerput(localSP += BYTES_PER_WORD, foo->trueObj);
					} else {
						/* begin internalPush: */
						longAtPointerput(localSP += BYTES_PER_WORD, foo->falseObj);
					}
					goto l13;
				}
				/* begin fetchPointer:ofObject: */
				/* begin fetchPointer:ofObject: */
				oop1 = foo->specialObjectsOop;
				oop = longAt((oop1 + (BASE_HEADER_SIZE)) + (SpecialSelectors << (SHIFT_FOR_WORD)));
				foo->messageSelector = longAt((oop + (BASE_HEADER_SIZE)) + ((5 * 2) << (SHIFT_FOR_WORD)));
				foo->argumentCount = 1;
				goto normalSend;
			}
;
		l13:	/* end case */;
			break;
		case 182:
			/* bytecodePrimEqual */
			{
				sqInt aBool;
				sqInt arg;
				sqInt rcvr;
				sqInt oop;
				sqInt bytecode;
				sqInt offset;
				sqInt bytecode1;
				sqInt offset1;
				sqInt oop1;
				rcvr = longAtPointer(localSP - (1 * (BYTES_PER_WORD)));
				arg = longAtPointer(localSP - (0 * (BYTES_PER_WORD)));
				if (((rcvr & arg) & 1) != 0) {
					/* begin booleanCheat: */
					bytecode = byteAtPointer(++localIP);
					/* begin internalPop: */
					localSP -= 2 * (BYTES_PER_WORD);
					if ((bytecode < 160) && (bytecode > 151)) {
						if (rcvr == arg) {
							/* begin fetchNextBytecode */
							currentBytecode = byteAtPointer(++localIP);
							goto l14;
						} else {
							/* begin jump: */
							localIP = (localIP + (bytecode - 151)) + 1;
							currentBytecode = byteAtPointer(localIP);
							goto l14;
						}
					}
					if (bytecode == 172) {
						offset = byteAtPointer(++localIP);
						if (rcvr == arg) {
							/* begin fetchNextBytecode */
							currentBytecode = byteAtPointer(++localIP);
							goto l14;
						} else {
							/* begin jump: */
							localIP = (localIP + offset) + 1;
							currentBytecode = byteAtPointer(localIP);
							goto l14;
						}
					}
					localIP -= 1;
					/* begin fetchNextBytecode */
					currentBytecode = byteAtPointer(++localIP);
					if (rcvr == arg) {
						/* begin internalPush: */
						longAtPointerput(localSP += BYTES_PER_WORD, foo->trueObj);
					} else {
						/* begin internalPush: */
						longAtPointerput(localSP += BYTES_PER_WORD, foo->falseObj);
					}
					goto l14;
				}
				foo->successFlag = 1;
				aBool = primitiveFloatEqualtoArg(rcvr, arg);
				if (foo->successFlag) {
					/* begin booleanCheat: */
					bytecode1 = byteAtPointer(++localIP);
					/* begin internalPop: */
					localSP -= 2 * (BYTES_PER_WORD);
					if ((bytecode1 < 160) && (bytecode1 > 151)) {
						if (aBool) {
							/* begin fetchNextBytecode */
							currentBytecode = byteAtPointer(++localIP);
							goto l14;
						} else {
							/* begin jump: */
							localIP = (localIP + (bytecode1 - 151)) + 1;
							currentBytecode = byteAtPointer(localIP);
							goto l14;
						}
					}
					if (bytecode1 == 172) {
						offset1 = byteAtPointer(++localIP);
						if (aBool) {
							/* begin fetchNextBytecode */
							currentBytecode = byteAtPointer(++localIP);
							goto l14;
						} else {
							/* begin jump: */
							localIP = (localIP + offset1) + 1;
							currentBytecode = byteAtPointer(localIP);
							goto l14;
						}
					}
					localIP -= 1;
					/* begin fetchNextBytecode */
					currentBytecode = byteAtPointer(++localIP);
					if (aBool) {
						/* begin internalPush: */
						longAtPointerput(localSP += BYTES_PER_WORD, foo->trueObj);
					} else {
						/* begin internalPush: */
						longAtPointerput(localSP += BYTES_PER_WORD, foo->falseObj);
					}
					goto l14;
				}
				/* begin fetchPointer:ofObject: */
				/* begin fetchPointer:ofObject: */
				oop1 = foo->specialObjectsOop;
				oop = longAt((oop1 + (BASE_HEADER_SIZE)) + (SpecialSelectors << (SHIFT_FOR_WORD)));
				foo->messageSelector = longAt((oop + (BASE_HEADER_SIZE)) + ((6 * 2) << (SHIFT_FOR_WORD)));
				foo->argumentCount = 1;
				goto normalSend;
			}
;
		l14:	/* end case */;
			break;
		case 183:
			/* bytecodePrimNotEqual */
			{
				sqInt aBool;
				sqInt arg;
				sqInt rcvr;
				sqInt oop;
				sqInt bytecode;
				sqInt offset;
				sqInt bytecode1;
				sqInt offset1;
				sqInt oop1;
				rcvr = longAtPointer(localSP - (1 * (BYTES_PER_WORD)));
				arg = longAtPointer(localSP - (0 * (BYTES_PER_WORD)));
				if (((rcvr & arg) & 1) != 0) {
					/* begin booleanCheat: */
					bytecode = byteAtPointer(++localIP);
					/* begin internalPop: */
					localSP -= 2 * (BYTES_PER_WORD);
					if ((bytecode < 160) && (bytecode > 151)) {
						if (rcvr != arg) {
							/* begin fetchNextBytecode */
							currentBytecode = byteAtPointer(++localIP);
							goto l15;
						} else {
							/* begin jump: */
							localIP = (localIP + (bytecode - 151)) + 1;
							currentBytecode = byteAtPointer(localIP);
							goto l15;
						}
					}
					if (bytecode == 172) {
						offset = byteAtPointer(++localIP);
						if (rcvr != arg) {
							/* begin fetchNextBytecode */
							currentBytecode = byteAtPointer(++localIP);
							goto l15;
						} else {
							/* begin jump: */
							localIP = (localIP + offset) + 1;
							currentBytecode = byteAtPointer(localIP);
							goto l15;
						}
					}
					localIP -= 1;
					/* begin fetchNextBytecode */
					currentBytecode = byteAtPointer(++localIP);
					if (rcvr != arg) {
						/* begin internalPush: */
						longAtPointerput(localSP += BYTES_PER_WORD, foo->trueObj);
					} else {
						/* begin internalPush: */
						longAtPointerput(localSP += BYTES_PER_WORD, foo->falseObj);
					}
					goto l15;
				}
				foo->successFlag = 1;
				aBool = primitiveFloatEqualtoArg(rcvr, arg);
				if (foo->successFlag) {
					/* begin booleanCheat: */
					bytecode1 = byteAtPointer(++localIP);
					/* begin internalPop: */
					localSP -= 2 * (BYTES_PER_WORD);
					if ((bytecode1 < 160) && (bytecode1 > 151)) {
						if (!aBool) {
							/* begin fetchNextBytecode */
							currentBytecode = byteAtPointer(++localIP);
							goto l15;
						} else {
							/* begin jump: */
							localIP = (localIP + (bytecode1 - 151)) + 1;
							currentBytecode = byteAtPointer(localIP);
							goto l15;
						}
					}
					if (bytecode1 == 172) {
						offset1 = byteAtPointer(++localIP);
						if (!aBool) {
							/* begin fetchNextBytecode */
							currentBytecode = byteAtPointer(++localIP);
							goto l15;
						} else {
							/* begin jump: */
							localIP = (localIP + offset1) + 1;
							currentBytecode = byteAtPointer(localIP);
							goto l15;
						}
					}
					localIP -= 1;
					/* begin fetchNextBytecode */
					currentBytecode = byteAtPointer(++localIP);
					if (!aBool) {
						/* begin internalPush: */
						longAtPointerput(localSP += BYTES_PER_WORD, foo->trueObj);
					} else {
						/* begin internalPush: */
						longAtPointerput(localSP += BYTES_PER_WORD, foo->falseObj);
					}
					goto l15;
				}
				/* begin fetchPointer:ofObject: */
				/* begin fetchPointer:ofObject: */
				oop1 = foo->specialObjectsOop;
				oop = longAt((oop1 + (BASE_HEADER_SIZE)) + (SpecialSelectors << (SHIFT_FOR_WORD)));
				foo->messageSelector = longAt((oop + (BASE_HEADER_SIZE)) + ((7 * 2) << (SHIFT_FOR_WORD)));
				foo->argumentCount = 1;
				goto normalSend;
			}
;
		l15:	/* end case */;
			break;
		case 184:
			/* bytecodePrimMultiply */
			{
				sqInt arg;
				sqInt rcvr;
				sqInt result;
				sqInt oop;
				sqInt oop1;
				rcvr = longAtPointer(localSP - (1 * (BYTES_PER_WORD)));
				arg = longAtPointer(localSP - (0 * (BYTES_PER_WORD)));
				if (((rcvr & arg) & 1) != 0) {
					rcvr = (rcvr >> 1);
					arg = (arg >> 1);
					result = rcvr * arg;
					if (((arg == 0) || ((result / arg) == rcvr)) && (
# ifdef SQ_HOST32  // cast to int for 64 bit image on 32 bit host
	(((((int) result)) ^ ((((int) result)) << 1)) >= 0)
# else
	((result >= -1073741824) && (result <= 1073741823))
# endif  // SQ_HOST32
)) {
						/* begin internalPop:thenPush: */
						longAtPointerput(localSP -= (2 - 1) * (BYTES_PER_WORD), ((result << 1) | 1));
						/* begin fetchNextBytecode */
						currentBytecode = byteAtPointer(++localIP);
						goto l16;
					}
				} else {
					foo->successFlag = 1;
					/* begin externalizeIPandSP */
					foo->instructionPointer = oopForPointer(localIP);
					foo->stackPointer = oopForPointer(localSP);
					foo->theHomeContext = localHomeContext;
					primitiveFloatMultiplybyArg(rcvr, arg);
					/* begin internalizeIPandSP */
					localIP = pointerForOop(foo->instructionPointer);
					localSP = pointerForOop(foo->stackPointer);
					localHomeContext = foo->theHomeContext;
					if (foo->successFlag) {
						/* begin fetchNextBytecode */
						currentBytecode = byteAtPointer(++localIP);
						goto l16;
					}
				}
				/* begin fetchPointer:ofObject: */
				/* begin fetchPointer:ofObject: */
				oop1 = foo->specialObjectsOop;
				oop = longAt((oop1 + (BASE_HEADER_SIZE)) + (SpecialSelectors << (SHIFT_FOR_WORD)));
				foo->messageSelector = longAt((oop + (BASE_HEADER_SIZE)) + ((8 * 2) << (SHIFT_FOR_WORD)));
				foo->argumentCount = 1;
				goto normalSend;
			}
;
		l16:	/* end case */;
			break;
		case 185:
			/* bytecodePrimDivide */
			{
				sqInt arg;
				sqInt rcvr;
				sqInt result;
				sqInt oop;
				sqInt oop1;
				rcvr = longAtPointer(localSP - (1 * (BYTES_PER_WORD)));
				arg = longAtPointer(localSP - (0 * (BYTES_PER_WORD)));
				if (((rcvr & arg) & 1) != 0) {
					rcvr = (rcvr >> 1);
					arg = (arg >> 1);
					if ((arg != 0) && ((rcvr % arg) == 0)) {
						result = rcvr / arg;
						if (
# ifdef SQ_HOST32  // cast to int for 64 bit image on 32 bit host
							(((((int) result)) ^ ((((int) result)) << 1)) >= 0)
# else
							((result >= -1073741824) && (result <= 1073741823))
# endif  // SQ_HOST32
						) {
							/* begin internalPop:thenPush: */
							longAtPointerput(localSP -= (2 - 1) * (BYTES_PER_WORD), ((result << 1) | 1));
							/* begin fetchNextBytecode */
							currentBytecode = byteAtPointer(++localIP);
							goto l17;
						}
					}
				} else {
					foo->successFlag = 1;
					/* begin externalizeIPandSP */
					foo->instructionPointer = oopForPointer(localIP);
					foo->stackPointer = oopForPointer(localSP);
					foo->theHomeContext = localHomeContext;
					primitiveFloatDividebyArg(rcvr, arg);
					/* begin internalizeIPandSP */
					localIP = pointerForOop(foo->instructionPointer);
					localSP = pointerForOop(foo->stackPointer);
					localHomeContext = foo->theHomeContext;
					if (foo->successFlag) {
						/* begin fetchNextBytecode */
						currentBytecode = byteAtPointer(++localIP);
						goto l17;
					}
				}
				/* begin fetchPointer:ofObject: */
				/* begin fetchPointer:ofObject: */
				oop1 = foo->specialObjectsOop;
				oop = longAt((oop1 + (BASE_HEADER_SIZE)) + (SpecialSelectors << (SHIFT_FOR_WORD)));
				foo->messageSelector = longAt((oop + (BASE_HEADER_SIZE)) + ((9 * 2) << (SHIFT_FOR_WORD)));
				foo->argumentCount = 1;
				goto normalSend;
			}
;
		l17:	/* end case */;
			break;
		case 186:
			/* bytecodePrimMod */
			{
				sqInt mod;
				sqInt oop;
				sqInt oop1;
				foo->successFlag = 1;
				mod = doPrimitiveModby(longAtPointer(localSP - (1 * (BYTES_PER_WORD))), longAtPointer(localSP - (0 * (BYTES_PER_WORD))));
				if (foo->successFlag) {
					/* begin internalPop:thenPush: */
					longAtPointerput(localSP -= (2 - 1) * (BYTES_PER_WORD), ((mod << 1) | 1));
					/* begin fetchNextBytecode */
					currentBytecode = byteAtPointer(++localIP);
					goto l18;
				}
				/* begin fetchPointer:ofObject: */
				/* begin fetchPointer:ofObject: */
				oop1 = foo->specialObjectsOop;
				oop = longAt((oop1 + (BASE_HEADER_SIZE)) + (SpecialSelectors << (SHIFT_FOR_WORD)));
				foo->messageSelector = longAt((oop + (BASE_HEADER_SIZE)) + ((10 * 2) << (SHIFT_FOR_WORD)));
				foo->argumentCount = 1;
				goto normalSend;
			}
;
		l18:	/* end case */;
			break;
		case 187:
			/* bytecodePrimMakePoint */
			{
				sqInt oop;
				sqInt oop1;
				sqInt argument;
				sqInt pt;
				sqInt rcvr;
				sqInt sp;
				sqInt pointResult;
				sqInt pointResult1;
				sqInt valuePointer;
				sqInt pointResult2;
				sqInt valuePointer1;
				sqInt valuePointer2;
				foo->successFlag = 1;
				/* begin externalizeIPandSP */
				foo->instructionPointer = oopForPointer(localIP);
				foo->stackPointer = oopForPointer(localSP);
				foo->theHomeContext = localHomeContext;
				/* begin primitiveMakePoint */
				argument = longAt(foo->stackPointer);
				rcvr = longAt(foo->stackPointer - (1 * (BYTES_PER_WORD)));
				if ((rcvr & 1)) {
					if ((argument & 1)) {
						/* begin makePointwithxValue:yValue: */
						pointResult = instantiateSmallClasssizeInBytes(fetchPointerofObject(ClassPoint, foo->specialObjectsOop), 3 * (BYTES_PER_WORD));
						longAtput((pointResult + (BASE_HEADER_SIZE)) + (XIndex << (SHIFT_FOR_WORD)), ((((rcvr >> 1)) << 1) | 1));
						longAtput((pointResult + (BASE_HEADER_SIZE)) + (YIndex << (SHIFT_FOR_WORD)), ((((argument >> 1)) << 1) | 1));
						pt = pointResult;
					} else {
						/* begin makePointwithxValue:yValue: */
						pointResult1 = instantiateSmallClasssizeInBytes(fetchPointerofObject(ClassPoint, foo->specialObjectsOop), 3 * (BYTES_PER_WORD));
						longAtput((pointResult1 + (BASE_HEADER_SIZE)) + (XIndex << (SHIFT_FOR_WORD)), ((((rcvr >> 1)) << 1) | 1));
						longAtput((pointResult1 + (BASE_HEADER_SIZE)) + (YIndex << (SHIFT_FOR_WORD)), ((0 << 1) | 1));
						pt = pointResult1;
						/* begin storePointer:ofObject:withValue: */
						valuePointer = longAt(foo->stackPointer - (0 * (BYTES_PER_WORD)));
						if ((((usqInt) pt)) < (((usqInt) foo->youngStart))) {
							possibleRootStoreIntovalue(pt, valuePointer);
						}
						longAtput((pt + (BASE_HEADER_SIZE)) + (1 << (SHIFT_FOR_WORD)), valuePointer);
					}
				} else {
					if (!((fetchClassOf(rcvr)) == (fetchPointerofObject(ClassFloat, foo->specialObjectsOop)))) {
						/* begin success: */
						foo->successFlag = 0 && foo->successFlag;
						goto l20;
					}
					/* begin makePointwithxValue:yValue: */
					pointResult2 = instantiateSmallClasssizeInBytes(fetchPointerofObject(ClassPoint, foo->specialObjectsOop), 3 * (BYTES_PER_WORD));
					longAtput((pointResult2 + (BASE_HEADER_SIZE)) + (XIndex << (SHIFT_FOR_WORD)), ((0 << 1) | 1));
					longAtput((pointResult2 + (BASE_HEADER_SIZE)) + (YIndex << (SHIFT_FOR_WORD)), ((0 << 1) | 1));
					pt = pointResult2;
					/* begin storePointer:ofObject:withValue: */
					valuePointer1 = longAt(foo->stackPointer - (1 * (BYTES_PER_WORD)));
					if ((((usqInt) pt)) < (((usqInt) foo->youngStart))) {
						possibleRootStoreIntovalue(pt, valuePointer1);
					}
					longAtput((pt + (BASE_HEADER_SIZE)) + (0 << (SHIFT_FOR_WORD)), valuePointer1);
					/* begin storePointer:ofObject:withValue: */
					valuePointer2 = longAt(foo->stackPointer - (0 * (BYTES_PER_WORD)));
					if ((((usqInt) pt)) < (((usqInt) foo->youngStart))) {
						possibleRootStoreIntovalue(pt, valuePointer2);
					}
					longAtput((pt + (BASE_HEADER_SIZE)) + (1 << (SHIFT_FOR_WORD)), valuePointer2);
				}
				/* begin pop:thenPush: */
				longAtput(sp = foo->stackPointer - ((2 - 1) * (BYTES_PER_WORD)), pt);
				foo->stackPointer = sp;
			l20:	/* end primitiveMakePoint */;
				/* begin internalizeIPandSP */
				localIP = pointerForOop(foo->instructionPointer);
				localSP = pointerForOop(foo->stackPointer);
				localHomeContext = foo->theHomeContext;
				if (foo->successFlag) {
					/* begin fetchNextBytecode */
					currentBytecode = byteAtPointer(++localIP);
					goto l19;
				}
				/* begin fetchPointer:ofObject: */
				/* begin fetchPointer:ofObject: */
				oop1 = foo->specialObjectsOop;
				oop = longAt((oop1 + (BASE_HEADER_SIZE)) + (SpecialSelectors << (SHIFT_FOR_WORD)));
				foo->messageSelector = longAt((oop + (BASE_HEADER_SIZE)) + ((11 * 2) << (SHIFT_FOR_WORD)));
				foo->argumentCount = 1;
				goto normalSend;
			}
;
		l19:	/* end case */;
			break;
		case 188:
			/* bytecodePrimBitShift */
			{
				sqInt oop;
				sqInt oop1;
				sqInt integerArgument;
				sqInt integerReceiver;
				sqInt shifted;
				sqInt top;
				sqInt object;
				sqInt sp;
				sqInt top1;
				sqInt integerPointer;
				sqInt top2;
				foo->successFlag = 1;
				/* begin externalizeIPandSP */
				foo->instructionPointer = oopForPointer(localIP);
				foo->stackPointer = oopForPointer(localSP);
				foo->theHomeContext = localHomeContext;
				/* begin primitiveBitShift */
				/* begin popInteger */
				/* begin popStack */
				top2 = longAt(foo->stackPointer);
				foo->stackPointer -= BYTES_PER_WORD;
				integerPointer = top2;
				/* begin checkedIntegerValueOf: */
				if ((integerPointer & 1)) {
					integerArgument = (integerPointer >> 1);
					goto l22;
				} else {
					/* begin primitiveFail */
					foo->successFlag = 0;
					integerArgument = 0;
					goto l22;
				}
				integerArgument = null;
			l22:	/* end popInteger */;
				/* begin popPos32BitInteger */
				/* begin popStack */
				top1 = longAt(foo->stackPointer);
				foo->stackPointer -= BYTES_PER_WORD;
				top = top1;
				integerReceiver = positive32BitValueOf(top);
				if (foo->successFlag) {
					if (integerArgument >= 0) {
						/* begin success: */
						foo->successFlag = (integerArgument <= 31) && foo->successFlag;
						shifted = integerReceiver << integerArgument;
						/* begin success: */
						foo->successFlag = ((((usqInt) shifted) >> integerArgument) == integerReceiver) && foo->successFlag;
					} else {
						/* begin success: */
						foo->successFlag = (integerArgument >= -31) && foo->successFlag;
						shifted = ((integerArgument < 0) ? ((usqInt) integerReceiver >> -integerArgument) : ((usqInt) integerReceiver << integerArgument));
					}
				}
				if (foo->successFlag) {
					/* begin push: */
					object = positive32BitIntegerFor(shifted);
					longAtput(sp = foo->stackPointer + (BYTES_PER_WORD), object);
					foo->stackPointer = sp;
				} else {
					/* begin unPop: */
					foo->stackPointer += 2 * (BYTES_PER_WORD);
				}
				/* begin internalizeIPandSP */
				localIP = pointerForOop(foo->instructionPointer);
				localSP = pointerForOop(foo->stackPointer);
				localHomeContext = foo->theHomeContext;
				if (foo->successFlag) {
					/* begin fetchNextBytecode */
					currentBytecode = byteAtPointer(++localIP);
					goto l21;
				}
				/* begin fetchPointer:ofObject: */
				/* begin fetchPointer:ofObject: */
				oop1 = foo->specialObjectsOop;
				oop = longAt((oop1 + (BASE_HEADER_SIZE)) + (SpecialSelectors << (SHIFT_FOR_WORD)));
				foo->messageSelector = longAt((oop + (BASE_HEADER_SIZE)) + ((12 * 2) << (SHIFT_FOR_WORD)));
				foo->argumentCount = 1;
				goto normalSend;
			}
;
		l21:	/* end case */;
			break;
		case 189:
			/* bytecodePrimDiv */
			{
				sqInt quotient;
				sqInt oop;
				sqInt oop1;
				foo->successFlag = 1;
				quotient = doPrimitiveDivby(longAtPointer(localSP - (1 * (BYTES_PER_WORD))), longAtPointer(localSP - (0 * (BYTES_PER_WORD))));
				if (foo->successFlag) {
					/* begin internalPop:thenPush: */
					longAtPointerput(localSP -= (2 - 1) * (BYTES_PER_WORD), ((quotient << 1) | 1));
					/* begin fetchNextBytecode */
					currentBytecode = byteAtPointer(++localIP);
					goto l23;
				}
				/* begin fetchPointer:ofObject: */
				/* begin fetchPointer:ofObject: */
				oop1 = foo->specialObjectsOop;
				oop = longAt((oop1 + (BASE_HEADER_SIZE)) + (SpecialSelectors << (SHIFT_FOR_WORD)));
				foo->messageSelector = longAt((oop + (BASE_HEADER_SIZE)) + ((13 * 2) << (SHIFT_FOR_WORD)));
				foo->argumentCount = 1;
				goto normalSend;
			}
;
		l23:	/* end case */;
			break;
		case 190:
			/* bytecodePrimBitAnd */
			{
				sqInt oop;
				sqInt integerArgument;
				sqInt integerReceiver;
				sqInt top;
				sqInt top1;
				sqInt object;
				sqInt sp;
				sqInt top2;
				sqInt top3;
				sqInt oop1;
				foo->successFlag = 1;
				/* begin externalizeIPandSP */
				foo->instructionPointer = oopForPointer(localIP);
				foo->stackPointer = oopForPointer(localSP);
				foo->theHomeContext = localHomeContext;
				/* begin primitiveBitAnd */
				/* begin popPos32BitInteger */
				/* begin popStack */
				top2 = longAt(foo->stackPointer);
				foo->stackPointer -= BYTES_PER_WORD;
				top = top2;
				integerArgument = positive32BitValueOf(top);
				/* begin popPos32BitInteger */
				/* begin popStack */
				top3 = longAt(foo->stackPointer);
				foo->stackPointer -= BYTES_PER_WORD;
				top1 = top3;
				integerReceiver = positive32BitValueOf(top1);
				if (foo->successFlag) {
					/* begin push: */
					object = positive32BitIntegerFor(integerReceiver & integerArgument);
					longAtput(sp = foo->stackPointer + (BYTES_PER_WORD), object);
					foo->stackPointer = sp;
				} else {
					/* begin unPop: */
					foo->stackPointer += 2 * (BYTES_PER_WORD);
				}
				/* begin internalizeIPandSP */
				localIP = pointerForOop(foo->instructionPointer);
				localSP = pointerForOop(foo->stackPointer);
				localHomeContext = foo->theHomeContext;
				if (foo->successFlag) {
					/* begin fetchNextBytecode */
					currentBytecode = byteAtPointer(++localIP);
					goto l24;
				}
				/* begin fetchPointer:ofObject: */
				/* begin fetchPointer:ofObject: */
				oop1 = foo->specialObjectsOop;
				oop = longAt((oop1 + (BASE_HEADER_SIZE)) + (SpecialSelectors << (SHIFT_FOR_WORD)));
				foo->messageSelector = longAt((oop + (BASE_HEADER_SIZE)) + ((14 * 2) << (SHIFT_FOR_WORD)));
				foo->argumentCount = 1;
				goto normalSend;
			}
;
		l24:	/* end case */;
			break;
		case 191:
			/* bytecodePrimBitOr */
			{
				sqInt oop;
				sqInt integerArgument;
				sqInt integerReceiver;
				sqInt top;
				sqInt top1;
				sqInt object;
				sqInt sp;
				sqInt top2;
				sqInt top3;
				sqInt oop1;
				foo->successFlag = 1;
				/* begin externalizeIPandSP */
				foo->instructionPointer = oopForPointer(localIP);
				foo->stackPointer = oopForPointer(localSP);
				foo->theHomeContext = localHomeContext;
				/* begin primitiveBitOr */
				/* begin popPos32BitInteger */
				/* begin popStack */
				top2 = longAt(foo->stackPointer);
				foo->stackPointer -= BYTES_PER_WORD;
				top = top2;
				integerArgument = positive32BitValueOf(top);
				/* begin popPos32BitInteger */
				/* begin popStack */
				top3 = longAt(foo->stackPointer);
				foo->stackPointer -= BYTES_PER_WORD;
				top1 = top3;
				integerReceiver = positive32BitValueOf(top1);
				if (foo->successFlag) {
					/* begin push: */
					object = positive32BitIntegerFor(integerReceiver | integerArgument);
					longAtput(sp = foo->stackPointer + (BYTES_PER_WORD), object);
					foo->stackPointer = sp;
				} else {
					/* begin unPop: */
					foo->stackPointer += 2 * (BYTES_PER_WORD);
				}
				/* begin internalizeIPandSP */
				localIP = pointerForOop(foo->instructionPointer);
				localSP = pointerForOop(foo->stackPointer);
				localHomeContext = foo->theHomeContext;
				if (foo->successFlag) {
					/* begin fetchNextBytecode */
					currentBytecode = byteAtPointer(++localIP);
					goto l25;
				}
				/* begin fetchPointer:ofObject: */
				/* begin fetchPointer:ofObject: */
				oop1 = foo->specialObjectsOop;
				oop = longAt((oop1 + (BASE_HEADER_SIZE)) + (SpecialSelectors << (SHIFT_FOR_WORD)));
				foo->messageSelector = longAt((oop + (BASE_HEADER_SIZE)) + ((15 * 2) << (SHIFT_FOR_WORD)));
				foo->argumentCount = 1;
				goto normalSend;
			}
;
		l25:	/* end case */;
			break;
		case 192:
			/* bytecodePrimAt */
			{
				sqInt atIx;
				sqInt index;
				sqInt rcvr;
				sqInt result;
				sqInt oop;
				sqInt oop1;
				sqInt fixedFields;
				sqInt fmt;
				sqInt result1;
				sqInt stSize;
				sqInt oop2;
				sqInt oop11;
				index = longAtPointer(localSP);
				rcvr = longAtPointer(localSP - (1 * (BYTES_PER_WORD)));
				foo->successFlag = (!((rcvr & 1))) && ((index & 1));
				if (foo->successFlag) {
					atIx = rcvr & AtCacheMask;
					if ((foo->atCache[atIx + AtCacheOop]) == rcvr) {
						/* begin commonVariableInternal:at:cacheIndex: */
						stSize = foo->atCache[atIx + AtCacheSize];
						if (((((usqInt) ((index >> 1)))) >= (((usqInt) 1))) && ((((usqInt) ((index >> 1)))) <= (((usqInt) stSize)))) {
							fmt = foo->atCache[atIx + AtCacheFmt];
							if (fmt <= 4) {
								fixedFields = foo->atCache[atIx + AtCacheFixedFields];
								result = longAt((rcvr + (BASE_HEADER_SIZE)) + (((((index >> 1)) + fixedFields) - 1) << (SHIFT_FOR_WORD)));
								goto l27;
							}
							if (fmt < 8) {
								result1 = long32At((rcvr + (BASE_HEADER_SIZE)) + ((((index >> 1)) - 1) << 2));
								/* begin externalizeIPandSP */
								foo->instructionPointer = oopForPointer(localIP);
								foo->stackPointer = oopForPointer(localSP);
								foo->theHomeContext = localHomeContext;
								result1 = positive32BitIntegerFor(result1);
								/* begin internalizeIPandSP */
								localIP = pointerForOop(foo->instructionPointer);
								localSP = pointerForOop(foo->stackPointer);
								localHomeContext = foo->theHomeContext;
								result = result1;
								goto l27;
							}
							if (fmt >= 16) {
								/* begin fetchPointer:ofObject: */
								/* begin fetchPointer:ofObject: */
								oop11 = foo->specialObjectsOop;
								oop2 = longAt((oop11 + (BASE_HEADER_SIZE)) + (CharacterTable << (SHIFT_FOR_WORD)));
								result = longAt((oop2 + (BASE_HEADER_SIZE)) + ((byteAt((rcvr + (BASE_HEADER_SIZE)) + (((index >> 1)) - 1))) << (SHIFT_FOR_WORD)));
								goto l27;
							} else {
								result = (((byteAt((rcvr + (BASE_HEADER_SIZE)) + (((index >> 1)) - 1))) << 1) | 1);
								goto l27;
							}
						}
						/* begin primitiveFail */
						foo->successFlag = 0;
					l27:	/* end commonVariableInternal:at:cacheIndex: */;
						if (foo->successFlag) {
							/* begin fetchNextBytecode */
							currentBytecode = byteAtPointer(++localIP);
							/* begin internalPop:thenPush: */
							longAtPointerput(localSP -= (2 - 1) * (BYTES_PER_WORD), result);
							goto l26;
						}
					}
				}
				/* begin fetchPointer:ofObject: */
				/* begin fetchPointer:ofObject: */
				oop1 = foo->specialObjectsOop;
				oop = longAt((oop1 + (BASE_HEADER_SIZE)) + (SpecialSelectors << (SHIFT_FOR_WORD)));
				foo->messageSelector = longAt((oop + (BASE_HEADER_SIZE)) + ((16 * 2) << (SHIFT_FOR_WORD)));
				foo->argumentCount = 1;
				goto normalSend;
			}
;
		l26:	/* end case */;
			break;
		case 193:
			/* bytecodePrimAtPut */
			{
				sqInt atIx;
				sqInt index;
				sqInt rcvr;
				sqInt value;
				sqInt oop;
				sqInt oop1;
				sqInt fixedFields;
				sqInt fmt;
				sqInt stSize;
				sqInt valToPut;
				value = longAtPointer(localSP);
				index = longAtPointer(localSP - (1 * (BYTES_PER_WORD)));
				rcvr = longAtPointer(localSP - (2 * (BYTES_PER_WORD)));
				foo->successFlag = (!((rcvr & 1))) && ((index & 1));
				if (foo->successFlag) {
					atIx = (rcvr & AtCacheMask) + AtPutBase;
					if ((foo->atCache[atIx + AtCacheOop]) == rcvr) {
						/* begin commonVariable:at:put:cacheIndex: */
						stSize = foo->atCache[atIx + AtCacheSize];
						if (((((usqInt) ((index >> 1)))) >= (((usqInt) 1))) && ((((usqInt) ((index >> 1)))) <= (((usqInt) stSize)))) {
							fmt = foo->atCache[atIx + AtCacheFmt];
							if (fmt <= 4) {
								fixedFields = foo->atCache[atIx + AtCacheFixedFields];
								/* begin storePointer:ofObject:withValue: */
								if ((((usqInt) rcvr)) < (((usqInt) foo->youngStart))) {
									possibleRootStoreIntovalue(rcvr, value);
								}
								longAtput((rcvr + (BASE_HEADER_SIZE)) + (((((index >> 1)) + fixedFields) - 1) << (SHIFT_FOR_WORD)), value);
								goto l29;
							}
							if (fmt < 8) {
								valToPut = positive32BitValueOf(value);
								if (foo->successFlag) {
									long32Atput((rcvr + (BASE_HEADER_SIZE)) + ((((index >> 1)) - 1) << 2), valToPut);
								}
								goto l29;
							}
							if (fmt >= 16) {
								valToPut = asciiOfCharacter(value);
								if (!(foo->successFlag)) {
									goto l29;
								}
							} else {
								valToPut = value;
							}
							if ((valToPut & 1)) {
								valToPut = (valToPut >> 1);
								if (!((valToPut >= 0) && (valToPut <= 255))) {
									/* begin primitiveFail */
									foo->successFlag = 0;
									goto l29;
								}
								byteAtput((rcvr + (BASE_HEADER_SIZE)) + (((index >> 1)) - 1), valToPut);
								goto l29;
							}
						}
						/* begin primitiveFail */
						foo->successFlag = 0;
					l29:	/* end commonVariable:at:put:cacheIndex: */;
						if (foo->successFlag) {
							/* begin fetchNextBytecode */
							currentBytecode = byteAtPointer(++localIP);
							/* begin internalPop:thenPush: */
							longAtPointerput(localSP -= (3 - 1) * (BYTES_PER_WORD), value);
							goto l28;
						}
					}
				}
				/* begin fetchPointer:ofObject: */
				/* begin fetchPointer:ofObject: */
				oop1 = foo->specialObjectsOop;
				oop = longAt((oop1 + (BASE_HEADER_SIZE)) + (SpecialSelectors << (SHIFT_FOR_WORD)));
				foo->messageSelector = longAt((oop + (BASE_HEADER_SIZE)) + ((17 * 2) << (SHIFT_FOR_WORD)));
				foo->argumentCount = 2;
				goto normalSend;
			}
;
		l28:	/* end case */;
			break;
		case 194:
			/* bytecodePrimSize */
			{
				sqInt oop;
				sqInt oop1;
				/* begin fetchPointer:ofObject: */
				/* begin fetchPointer:ofObject: */
				oop1 = foo->specialObjectsOop;
				oop = longAt((oop1 + (BASE_HEADER_SIZE)) + (SpecialSelectors << (SHIFT_FOR_WORD)));
				foo->messageSelector = longAt((oop + (BASE_HEADER_SIZE)) + ((18 * 2) << (SHIFT_FOR_WORD)));
				foo->argumentCount = 0;
				goto normalSend;
			}
;
			break;
		case 195:
			/* bytecodePrimNext */
			{
				sqInt oop;
				sqInt oop1;
				/* begin fetchPointer:ofObject: */
				/* begin fetchPointer:ofObject: */
				oop1 = foo->specialObjectsOop;
				oop = longAt((oop1 + (BASE_HEADER_SIZE)) + (SpecialSelectors << (SHIFT_FOR_WORD)));
				foo->messageSelector = longAt((oop + (BASE_HEADER_SIZE)) + ((19 * 2) << (SHIFT_FOR_WORD)));
				foo->argumentCount = 0;
				goto normalSend;
			}
;
			break;
		case 196:
			/* bytecodePrimNextPut */
			{
				sqInt oop;
				sqInt oop1;
				/* begin fetchPointer:ofObject: */
				/* begin fetchPointer:ofObject: */
				oop1 = foo->specialObjectsOop;
				oop = longAt((oop1 + (BASE_HEADER_SIZE)) + (SpecialSelectors << (SHIFT_FOR_WORD)));
				foo->messageSelector = longAt((oop + (BASE_HEADER_SIZE)) + ((20 * 2) << (SHIFT_FOR_WORD)));
				foo->argumentCount = 1;
				goto normalSend;
			}
;
			break;
		case 197:
			/* bytecodePrimAtEnd */
			{
				sqInt oop;
				sqInt oop1;
				/* begin fetchPointer:ofObject: */
				/* begin fetchPointer:ofObject: */
				oop1 = foo->specialObjectsOop;
				oop = longAt((oop1 + (BASE_HEADER_SIZE)) + (SpecialSelectors << (SHIFT_FOR_WORD)));
				foo->messageSelector = longAt((oop + (BASE_HEADER_SIZE)) + ((21 * 2) << (SHIFT_FOR_WORD)));
				foo->argumentCount = 0;
				goto normalSend;
			}
;
			break;
		case 198:
			/* bytecodePrimEquivalent */
			{
				sqInt arg;
				sqInt rcvr;
				sqInt bytecode;
				sqInt offset;
				rcvr = longAtPointer(localSP - (1 * (BYTES_PER_WORD)));
				arg = longAtPointer(localSP - (0 * (BYTES_PER_WORD)));
				/* begin booleanCheat: */
				bytecode = byteAtPointer(++localIP);
				/* begin internalPop: */
				localSP -= 2 * (BYTES_PER_WORD);
				if ((bytecode < 160) && (bytecode > 151)) {
					if (rcvr == arg) {
						/* begin fetchNextBytecode */
						currentBytecode = byteAtPointer(++localIP);
						goto l30;
					} else {
						/* begin jump: */
						localIP = (localIP + (bytecode - 151)) + 1;
						currentBytecode = byteAtPointer(localIP);
						goto l30;
					}
				}
				if (bytecode == 172) {
					offset = byteAtPointer(++localIP);
					if (rcvr == arg) {
						/* begin fetchNextBytecode */
						currentBytecode = byteAtPointer(++localIP);
						goto l30;
					} else {
						/* begin jump: */
						localIP = (localIP + offset) + 1;
						currentBytecode = byteAtPointer(localIP);
						goto l30;
					}
				}
				localIP -= 1;
				/* begin fetchNextBytecode */
				currentBytecode = byteAtPointer(++localIP);
				if (rcvr == arg) {
					/* begin internalPush: */
					longAtPointerput(localSP += BYTES_PER_WORD, foo->trueObj);
				} else {
					/* begin internalPush: */
					longAtPointerput(localSP += BYTES_PER_WORD, foo->falseObj);
				}
			l30:	/* end booleanCheat: */;
			}
;
			break;
		case 199:
			/* bytecodePrimClass */
			{
				sqInt rcvr;
				sqInt oop;
				sqInt ccIndex;
				sqInt oop1;
				sqInt oop2;
				sqInt oop3;
				rcvr = longAtPointer(localSP);
				/* begin internalPop:thenPush: */
				/* begin fetchClassOf: */
				if ((rcvr & 1)) {
					/* begin fetchPointer:ofObject: */
					oop1 = foo->specialObjectsOop;
					oop = longAt((oop1 + (BASE_HEADER_SIZE)) + (ClassInteger << (SHIFT_FOR_WORD)));
					goto l31;
				}
				ccIndex = (((usqInt) (longAt(rcvr))) >> 12) & 31;
				if (ccIndex == 0) {
					oop = (longAt(rcvr - (BASE_HEADER_SIZE))) & (ALL_BUT_TYPE_MASK);
					goto l31;
				} else {
					/* begin fetchPointer:ofObject: */
					/* begin fetchPointer:ofObject: */
					oop3 = foo->specialObjectsOop;
					oop2 = longAt((oop3 + (BASE_HEADER_SIZE)) + (CompactClasses << (SHIFT_FOR_WORD)));
					oop = longAt((oop2 + (BASE_HEADER_SIZE)) + ((ccIndex - 1) << (SHIFT_FOR_WORD)));
					goto l31;
				}
			l31:	/* end fetchClassOf: */;
				longAtPointerput(localSP -= (1 - 1) * (BYTES_PER_WORD), oop);
				/* begin fetchNextBytecode */
				currentBytecode = byteAtPointer(++localIP);
			}
;
			break;
		case 200:
			/* bytecodePrimBlockCopy */
			{
				sqInt hdr;
				sqInt rcvr;
				sqInt oop;
				sqInt successValue;
				sqInt oop1;
				sqInt context;
				sqInt contextSize;
				sqInt initialIP;
				sqInt methodContext;
				sqInt newContext;
				sqInt header;
				sqInt oop2;
				sqInt valuePointer;
				sqInt valuePointer1;
				sqInt sp;
				rcvr = longAtPointer(localSP - (1 * (BYTES_PER_WORD)));
				foo->successFlag = 1;
				hdr = longAt(rcvr);
				/* begin success: */
				successValue = (((((usqInt) hdr) >> 12) & 31) == 13) || ((((((usqInt) hdr) >> 12) & 31) == 14) || (((((usqInt) hdr) >> 12) & 31) == 4));
				foo->successFlag = successValue && foo->successFlag;
				if (foo->successFlag) {
					/* begin externalizeIPandSP */
					foo->instructionPointer = oopForPointer(localIP);
					foo->stackPointer = oopForPointer(localSP);
					foo->theHomeContext = localHomeContext;
					/* begin primitiveBlockCopy */
					context = longAt(foo->stackPointer - (1 * (BYTES_PER_WORD)));
					if (((longAt((context + (BASE_HEADER_SIZE)) + (MethodIndex << (SHIFT_FOR_WORD)))) & 1)) {
						methodContext = longAt((context + (BASE_HEADER_SIZE)) + (HomeIndex << (SHIFT_FOR_WORD)));
					} else {
						methodContext = context;
					}
					/* begin sizeBitsOf: */
					header = longAt(methodContext);
					if ((header & TypeMask) == HeaderTypeSizeAndClass) {
						contextSize = (longAt(methodContext - ((BYTES_PER_WORD) * 2))) & (LONG_SIZE_MASK);
						goto l33;
					} else {
						contextSize = header & (SIZE_MASK);
						goto l33;
					}
				l33:	/* end sizeBitsOf: */;
					context = null;
					/* begin pushRemappableOop: */
					foo->remapBuffer[(foo->remapBufferCount += 1)] = methodContext;
					newContext = instantiateContextsizeInBytes(fetchPointerofObject(ClassBlockContext, foo->specialObjectsOop), contextSize);
					/* begin popRemappableOop */
					oop2 = foo->remapBuffer[foo->remapBufferCount];
					foo->remapBufferCount -= 1;
					methodContext = oop2;
					initialIP = (((((foo->instructionPointer + 1) + 3) - (foo->method + (BASE_HEADER_SIZE))) << 1) | 1);
					longAtput((newContext + (BASE_HEADER_SIZE)) + (InitialIPIndex << (SHIFT_FOR_WORD)), initialIP);
					longAtput((newContext + (BASE_HEADER_SIZE)) + (InstructionPointerIndex << (SHIFT_FOR_WORD)), initialIP);
					/* begin storeStackPointerValue:inContext: */
					longAtput((newContext + (BASE_HEADER_SIZE)) + (StackPointerIndex << (SHIFT_FOR_WORD)), ((0 << 1) | 1));
					/* begin storePointerUnchecked:ofObject:withValue: */
					valuePointer = longAt(foo->stackPointer - (0 * (BYTES_PER_WORD)));
					longAtput((newContext + (BASE_HEADER_SIZE)) + (BlockArgumentCountIndex << (SHIFT_FOR_WORD)), valuePointer);
					longAtput((newContext + (BASE_HEADER_SIZE)) + (HomeIndex << (SHIFT_FOR_WORD)), methodContext);
					/* begin storePointerUnchecked:ofObject:withValue: */
					valuePointer1 = foo->nilObj;
					longAtput((newContext + (BASE_HEADER_SIZE)) + (SenderIndex << (SHIFT_FOR_WORD)), valuePointer1);
					/* begin pop:thenPush: */
					longAtput(sp = foo->stackPointer - ((2 - 1) * (BYTES_PER_WORD)), newContext);
					foo->stackPointer = sp;
					/* begin internalizeIPandSP */
					localIP = pointerForOop(foo->instructionPointer);
					localSP = pointerForOop(foo->stackPointer);
					localHomeContext = foo->theHomeContext;
				}
				if (!(foo->successFlag)) {
					/* begin fetchPointer:ofObject: */
					/* begin fetchPointer:ofObject: */
					oop1 = foo->specialObjectsOop;
					oop = longAt((oop1 + (BASE_HEADER_SIZE)) + (SpecialSelectors << (SHIFT_FOR_WORD)));
					foo->messageSelector = longAt((oop + (BASE_HEADER_SIZE)) + ((24 * 2) << (SHIFT_FOR_WORD)));
					foo->argumentCount = 1;
					goto normalSend;
					goto l32;
				}
				/* begin fetchNextBytecode */
				currentBytecode = byteAtPointer(++localIP);
			}
;
		l32:	/* end case */;
			break;
		case 201:
			/* bytecodePrimValue */
			{
				sqInt maybeBlock;
				sqInt rcvrClass;
				sqInt ccIndex;
				sqInt oop;
				sqInt oop1;
				sqInt oop2;
				sqInt oop3;
				maybeBlock = longAtPointer(localSP);
				foo->argumentCount = 0;
				foo->successFlag = 1;
				if ((maybeBlock & 1) == 0) {
					/* begin fetchClassOfNonInt: */
					ccIndex = (((usqInt) (longAt(maybeBlock))) >> 12) & 31;
					if (ccIndex == 0) {
						rcvrClass = (longAt(maybeBlock - (BASE_HEADER_SIZE))) & (ALL_BUT_TYPE_MASK);
						goto l35;
					} else {
						/* begin fetchPointer:ofObject: */
						/* begin fetchPointer:ofObject: */
						oop3 = foo->specialObjectsOop;
						oop1 = longAt((oop3 + (BASE_HEADER_SIZE)) + (CompactClasses << (SHIFT_FOR_WORD)));
						rcvrClass = longAt((oop1 + (BASE_HEADER_SIZE)) + ((ccIndex - 1) << (SHIFT_FOR_WORD)));
						goto l35;
					}
				l35:	/* end fetchClassOfNonInt: */;
					if (rcvrClass == (fetchPointerofObject(ClassBlockClosure, foo->specialObjectsOop))) {
						/* begin externalizeIPandSP */
						foo->instructionPointer = oopForPointer(localIP);
						foo->stackPointer = oopForPointer(localSP);
						foo->theHomeContext = localHomeContext;
						primitiveClosureValue();
						/* begin internalizeIPandSP */
						localIP = pointerForOop(foo->instructionPointer);
						localSP = pointerForOop(foo->stackPointer);
						localHomeContext = foo->theHomeContext;
					} else {
						if (rcvrClass == (fetchPointerofObject(ClassBlockContext, foo->specialObjectsOop))) {
							/* begin externalizeIPandSP */
							foo->instructionPointer = oopForPointer(localIP);
							foo->stackPointer = oopForPointer(localSP);
							foo->theHomeContext = localHomeContext;
							primitiveValue();
							/* begin internalizeIPandSP */
							localIP = pointerForOop(foo->instructionPointer);
							localSP = pointerForOop(foo->stackPointer);
							localHomeContext = foo->theHomeContext;
						} else {
							foo->successFlag = 0;
						}
					}
				}
				if (!(foo->successFlag)) {
					/* begin fetchPointer:ofObject: */
					/* begin fetchPointer:ofObject: */
					oop2 = foo->specialObjectsOop;
					oop = longAt((oop2 + (BASE_HEADER_SIZE)) + (SpecialSelectors << (SHIFT_FOR_WORD)));
					foo->messageSelector = longAt((oop + (BASE_HEADER_SIZE)) + ((25 * 2) << (SHIFT_FOR_WORD)));
					goto normalSend;
					goto l34;
				}
				/* begin fetchNextBytecode */
				currentBytecode = byteAtPointer(++localIP);
			}
;
		l34:	/* end case */;
			break;
		case 202:
			/* bytecodePrimValueWithArg */
			{
				sqInt maybeBlock;
				sqInt rcvrClass;
				sqInt ccIndex;
				sqInt oop;
				sqInt oop1;
				sqInt oop2;
				sqInt oop3;
				maybeBlock = longAtPointer(localSP - (1 * (BYTES_PER_WORD)));
				foo->argumentCount = 1;
				foo->successFlag = 1;
				if ((maybeBlock & 1) == 0) {
					/* begin fetchClassOfNonInt: */
					ccIndex = (((usqInt) (longAt(maybeBlock))) >> 12) & 31;
					if (ccIndex == 0) {
						rcvrClass = (longAt(maybeBlock - (BASE_HEADER_SIZE))) & (ALL_BUT_TYPE_MASK);
						goto l37;
					} else {
						/* begin fetchPointer:ofObject: */
						/* begin fetchPointer:ofObject: */
						oop3 = foo->specialObjectsOop;
						oop1 = longAt((oop3 + (BASE_HEADER_SIZE)) + (CompactClasses << (SHIFT_FOR_WORD)));
						rcvrClass = longAt((oop1 + (BASE_HEADER_SIZE)) + ((ccIndex - 1) << (SHIFT_FOR_WORD)));
						goto l37;
					}
				l37:	/* end fetchClassOfNonInt: */;
					if (rcvrClass == (fetchPointerofObject(ClassBlockClosure, foo->specialObjectsOop))) {
						/* begin externalizeIPandSP */
						foo->instructionPointer = oopForPointer(localIP);
						foo->stackPointer = oopForPointer(localSP);
						foo->theHomeContext = localHomeContext;
						primitiveClosureValue();
						/* begin internalizeIPandSP */
						localIP = pointerForOop(foo->instructionPointer);
						localSP = pointerForOop(foo->stackPointer);
						localHomeContext = foo->theHomeContext;
					} else {
						if (rcvrClass == (fetchPointerofObject(ClassBlockContext, foo->specialObjectsOop))) {
							/* begin externalizeIPandSP */
							foo->instructionPointer = oopForPointer(localIP);
							foo->stackPointer = oopForPointer(localSP);
							foo->theHomeContext = localHomeContext;
							primitiveValue();
							/* begin internalizeIPandSP */
							localIP = pointerForOop(foo->instructionPointer);
							localSP = pointerForOop(foo->stackPointer);
							localHomeContext = foo->theHomeContext;
						} else {
							foo->successFlag = 0;
						}
					}
				}
				if (!(foo->successFlag)) {
					/* begin fetchPointer:ofObject: */
					/* begin fetchPointer:ofObject: */
					oop2 = foo->specialObjectsOop;
					oop = longAt((oop2 + (BASE_HEADER_SIZE)) + (SpecialSelectors << (SHIFT_FOR_WORD)));
					foo->messageSelector = longAt((oop + (BASE_HEADER_SIZE)) + ((26 * 2) << (SHIFT_FOR_WORD)));
					goto normalSend;
					goto l36;
				}
				/* begin fetchNextBytecode */
				currentBytecode = byteAtPointer(++localIP);
			}
;
		l36:	/* end case */;
			break;
		case 203:
			/* bytecodePrimDo */
			{
				sqInt oop;
				sqInt oop1;
				/* begin fetchPointer:ofObject: */
				/* begin fetchPointer:ofObject: */
				oop1 = foo->specialObjectsOop;
				oop = longAt((oop1 + (BASE_HEADER_SIZE)) + (SpecialSelectors << (SHIFT_FOR_WORD)));
				foo->messageSelector = longAt((oop + (BASE_HEADER_SIZE)) + ((27 * 2) << (SHIFT_FOR_WORD)));
				foo->argumentCount = 1;
				goto normalSend;
			}
;
			break;
		case 204:
			/* bytecodePrimNew */
			{
				sqInt oop;
				sqInt oop1;
				/* begin fetchPointer:ofObject: */
				/* begin fetchPointer:ofObject: */
				oop1 = foo->specialObjectsOop;
				oop = longAt((oop1 + (BASE_HEADER_SIZE)) + (SpecialSelectors << (SHIFT_FOR_WORD)));
				foo->messageSelector = longAt((oop + (BASE_HEADER_SIZE)) + ((28 * 2) << (SHIFT_FOR_WORD)));
				foo->argumentCount = 0;
				goto normalSend;
			}
;
			break;
		case 205:
			/* bytecodePrimNewWithArg */
			{
				sqInt oop;
				sqInt oop1;
				/* begin fetchPointer:ofObject: */
				/* begin fetchPointer:ofObject: */
				oop1 = foo->specialObjectsOop;
				oop = longAt((oop1 + (BASE_HEADER_SIZE)) + (SpecialSelectors << (SHIFT_FOR_WORD)));
				foo->messageSelector = longAt((oop + (BASE_HEADER_SIZE)) + ((29 * 2) << (SHIFT_FOR_WORD)));
				foo->argumentCount = 1;
				goto normalSend;
			}
;
			break;
		case 206:
			/* bytecodePrimPointX */
			{
				sqInt rcvr;
				sqInt oop;
				sqInt oop1;
				sqInt oop2;
				sqInt classOop;
				sqInt ccIndex;
				sqInt cl;
				sqInt oop11;
				sqInt oop21;
				sqInt oop3;
				foo->successFlag = 1;
				rcvr = longAtPointer(localSP);
				/* begin assertClassOf:is: */
				/* begin fetchPointer:ofObject: */
				oop3 = foo->specialObjectsOop;
				classOop = longAt((oop3 + (BASE_HEADER_SIZE)) + (ClassPoint << (SHIFT_FOR_WORD)));
				if ((rcvr & 1)) {
					foo->successFlag = 0;
					goto l39;
				}
				ccIndex = (((usqInt) (longAt(rcvr))) >> 12) & 31;
				if (ccIndex == 0) {
					cl = (longAt(rcvr - (BASE_HEADER_SIZE))) & (ALL_BUT_TYPE_MASK);
				} else {
					/* begin fetchPointer:ofObject: */
					/* begin fetchPointer:ofObject: */
					oop21 = foo->specialObjectsOop;
					oop11 = longAt((oop21 + (BASE_HEADER_SIZE)) + (CompactClasses << (SHIFT_FOR_WORD)));
					cl = longAt((oop11 + (BASE_HEADER_SIZE)) + ((ccIndex - 1) << (SHIFT_FOR_WORD)));
				}
				/* begin success: */
				foo->successFlag = (cl == classOop) && foo->successFlag;
			l39:	/* end assertClassOf:is: */;
				if (foo->successFlag) {
					/* begin internalPop:thenPush: */
					oop = longAt((rcvr + (BASE_HEADER_SIZE)) + (XIndex << (SHIFT_FOR_WORD)));
					longAtPointerput(localSP -= (1 - 1) * (BYTES_PER_WORD), oop);
					/* begin fetchNextBytecode */
					currentBytecode = byteAtPointer(++localIP);
					goto l38;
				}
				/* begin fetchPointer:ofObject: */
				/* begin fetchPointer:ofObject: */
				oop2 = foo->specialObjectsOop;
				oop1 = longAt((oop2 + (BASE_HEADER_SIZE)) + (SpecialSelectors << (SHIFT_FOR_WORD)));
				foo->messageSelector = longAt((oop1 + (BASE_HEADER_SIZE)) + ((30 * 2) << (SHIFT_FOR_WORD)));
				foo->argumentCount = 0;
				goto normalSend;
			}
;
		l38:	/* end case */;
			break;
		case 207:
			/* bytecodePrimPointY */
			{
				sqInt rcvr;
				sqInt oop;
				sqInt oop1;
				sqInt oop2;
				sqInt classOop;
				sqInt ccIndex;
				sqInt cl;
				sqInt oop11;
				sqInt oop21;
				sqInt oop3;
				foo->successFlag = 1;
				rcvr = longAtPointer(localSP);
				/* begin assertClassOf:is: */
				/* begin fetchPointer:ofObject: */
				oop3 = foo->specialObjectsOop;
				classOop = longAt((oop3 + (BASE_HEADER_SIZE)) + (ClassPoint << (SHIFT_FOR_WORD)));
				if ((rcvr & 1)) {
					foo->successFlag = 0;
					goto l41;
				}
				ccIndex = (((usqInt) (longAt(rcvr))) >> 12) & 31;
				if (ccIndex == 0) {
					cl = (longAt(rcvr - (BASE_HEADER_SIZE))) & (ALL_BUT_TYPE_MASK);
				} else {
					/* begin fetchPointer:ofObject: */
					/* begin fetchPointer:ofObject: */
					oop21 = foo->specialObjectsOop;
					oop11 = longAt((oop21 + (BASE_HEADER_SIZE)) + (CompactClasses << (SHIFT_FOR_WORD)));
					cl = longAt((oop11 + (BASE_HEADER_SIZE)) + ((ccIndex - 1) << (SHIFT_FOR_WORD)));
				}
				/* begin success: */
				foo->successFlag = (cl == classOop) && foo->successFlag;
			l41:	/* end assertClassOf:is: */;
				if (foo->successFlag) {
					/* begin internalPop:thenPush: */
					oop = longAt((rcvr + (BASE_HEADER_SIZE)) + (YIndex << (SHIFT_FOR_WORD)));
					longAtPointerput(localSP -= (1 - 1) * (BYTES_PER_WORD), oop);
					/* begin fetchNextBytecode */
					currentBytecode = byteAtPointer(++localIP);
					goto l40;
				}
				/* begin fetchPointer:ofObject: */
				/* begin fetchPointer:ofObject: */
				oop2 = foo->specialObjectsOop;
				oop1 = longAt((oop2 + (BASE_HEADER_SIZE)) + (SpecialSelectors << (SHIFT_FOR_WORD)));
				foo->messageSelector = longAt((oop1 + (BASE_HEADER_SIZE)) + ((31 * 2) << (SHIFT_FOR_WORD)));
				foo->argumentCount = 0;
				goto normalSend;
			}
;
		l40:	/* end case */;
			break;
		case 208:
			/* sendLiteralSelectorBytecode */
			{
				sqInt offset;
				sqInt methodPointer;
				/* begin literal: */
				offset = 208 & 15;
				/* begin literal:ofMethod: */
				methodPointer = foo->method;
				foo->messageSelector = longAt((methodPointer + (BASE_HEADER_SIZE)) + ((offset + LiteralStart) << (SHIFT_FOR_WORD)));
				foo->argumentCount = ((((usqInt) 208) >> 4) & 3) - 1;
				goto normalSend;
			}
;
			break;
		case 209:
			/* sendLiteralSelectorBytecode */
			{
				sqInt offset;
				sqInt methodPointer;
				/* begin literal: */
				offset = 209 & 15;
				/* begin literal:ofMethod: */
				methodPointer = foo->method;
				foo->messageSelector = longAt((methodPointer + (BASE_HEADER_SIZE)) + ((offset + LiteralStart) << (SHIFT_FOR_WORD)));
				foo->argumentCount = ((((usqInt) 209) >> 4) & 3) - 1;
				goto normalSend;
			}
;
			break;
		case 210:
			/* sendLiteralSelectorBytecode */
			{
				sqInt offset;
				sqInt methodPointer;
				/* begin literal: */
				offset = 210 & 15;
				/* begin literal:ofMethod: */
				methodPointer = foo->method;
				foo->messageSelector = longAt((methodPointer + (BASE_HEADER_SIZE)) + ((offset + LiteralStart) << (SHIFT_FOR_WORD)));
				foo->argumentCount = ((((usqInt) 210) >> 4) & 3) - 1;
				goto normalSend;
			}
;
			break;
		case 211:
			/* sendLiteralSelectorBytecode */
			{
				sqInt offset;
				sqInt methodPointer;
				/* begin literal: */
				offset = 211 & 15;
				/* begin literal:ofMethod: */
				methodPointer = foo->method;
				foo->messageSelector = longAt((methodPointer + (BASE_HEADER_SIZE)) + ((offset + LiteralStart) << (SHIFT_FOR_WORD)));
				foo->argumentCount = ((((usqInt) 211) >> 4) & 3) - 1;
				goto normalSend;
			}
;
			break;
		case 212:
			/* sendLiteralSelectorBytecode */
			{
				sqInt offset;
				sqInt methodPointer;
				/* begin literal: */
				offset = 212 & 15;
				/* begin literal:ofMethod: */
				methodPointer = foo->method;
				foo->messageSelector = longAt((methodPointer + (BASE_HEADER_SIZE)) + ((offset + LiteralStart) << (SHIFT_FOR_WORD)));
				foo->argumentCount = ((((usqInt) 212) >> 4) & 3) - 1;
				goto normalSend;
			}
;
			break;
		case 213:
			/* sendLiteralSelectorBytecode */
			{
				sqInt offset;
				sqInt methodPointer;
				/* begin literal: */
				offset = 213 & 15;
				/* begin literal:ofMethod: */
				methodPointer = foo->method;
				foo->messageSelector = longAt((methodPointer + (BASE_HEADER_SIZE)) + ((offset + LiteralStart) << (SHIFT_FOR_WORD)));
				foo->argumentCount = ((((usqInt) 213) >> 4) & 3) - 1;
				goto normalSend;
			}
;
			break;
		case 214:
			/* sendLiteralSelectorBytecode */
			{
				sqInt offset;
				sqInt methodPointer;
				/* begin literal: */
				offset = 214 & 15;
				/* begin literal:ofMethod: */
				methodPointer = foo->method;
				foo->messageSelector = longAt((methodPointer + (BASE_HEADER_SIZE)) + ((offset + LiteralStart) << (SHIFT_FOR_WORD)));
				foo->argumentCount = ((((usqInt) 214) >> 4) & 3) - 1;
				goto normalSend;
			}
;
			break;
		case 215:
			/* sendLiteralSelectorBytecode */
			{
				sqInt offset;
				sqInt methodPointer;
				/* begin literal: */
				offset = 215 & 15;
				/* begin literal:ofMethod: */
				methodPointer = foo->method;
				foo->messageSelector = longAt((methodPointer + (BASE_HEADER_SIZE)) + ((offset + LiteralStart) << (SHIFT_FOR_WORD)));
				foo->argumentCount = ((((usqInt) 215) >> 4) & 3) - 1;
				goto normalSend;
			}
;
			break;
		case 216:
			/* sendLiteralSelectorBytecode */
			{
				sqInt offset;
				sqInt methodPointer;
				/* begin literal: */
				offset = 216 & 15;
				/* begin literal:ofMethod: */
				methodPointer = foo->method;
				foo->messageSelector = longAt((methodPointer + (BASE_HEADER_SIZE)) + ((offset + LiteralStart) << (SHIFT_FOR_WORD)));
				foo->argumentCount = ((((usqInt) 216) >> 4) & 3) - 1;
				goto normalSend;
			}
;
			break;
		case 217:
			/* sendLiteralSelectorBytecode */
			{
				sqInt offset;
				sqInt methodPointer;
				/* begin literal: */
				offset = 217 & 15;
				/* begin literal:ofMethod: */
				methodPointer = foo->method;
				foo->messageSelector = longAt((methodPointer + (BASE_HEADER_SIZE)) + ((offset + LiteralStart) << (SHIFT_FOR_WORD)));
				foo->argumentCount = ((((usqInt) 217) >> 4) & 3) - 1;
				goto normalSend;
			}
;
			break;
		case 218:
			/* sendLiteralSelectorBytecode */
			{
				sqInt offset;
				sqInt methodPointer;
				/* begin literal: */
				offset = 218 & 15;
				/* begin literal:ofMethod: */
				methodPointer = foo->method;
				foo->messageSelector = longAt((methodPointer + (BASE_HEADER_SIZE)) + ((offset + LiteralStart) << (SHIFT_FOR_WORD)));
				foo->argumentCount = ((((usqInt) 218) >> 4) & 3) - 1;
				goto normalSend;
			}
;
			break;
		case 219:
			/* sendLiteralSelectorBytecode */
			{
				sqInt offset;
				sqInt methodPointer;
				/* begin literal: */
				offset = 219 & 15;
				/* begin literal:ofMethod: */
				methodPointer = foo->method;
				foo->messageSelector = longAt((methodPointer + (BASE_HEADER_SIZE)) + ((offset + LiteralStart) << (SHIFT_FOR_WORD)));
				foo->argumentCount = ((((usqInt) 219) >> 4) & 3) - 1;
				goto normalSend;
			}
;
			break;
		case 220:
			/* sendLiteralSelectorBytecode */
			{
				sqInt offset;
				sqInt methodPointer;
				/* begin literal: */
				offset = 220 & 15;
				/* begin literal:ofMethod: */
				methodPointer = foo->method;
				foo->messageSelector = longAt((methodPointer + (BASE_HEADER_SIZE)) + ((offset + LiteralStart) << (SHIFT_FOR_WORD)));
				foo->argumentCount = ((((usqInt) 220) >> 4) & 3) - 1;
				goto normalSend;
			}
;
			break;
		case 221:
			/* sendLiteralSelectorBytecode */
			{
				sqInt offset;
				sqInt methodPointer;
				/* begin literal: */
				offset = 221 & 15;
				/* begin literal:ofMethod: */
				methodPointer = foo->method;
				foo->messageSelector = longAt((methodPointer + (BASE_HEADER_SIZE)) + ((offset + LiteralStart) << (SHIFT_FOR_WORD)));
				foo->argumentCount = ((((usqInt) 221) >> 4) & 3) - 1;
				goto normalSend;
			}
;
			break;
		case 222:
			/* sendLiteralSelectorBytecode */
			{
				sqInt offset;
				sqInt methodPointer;
				/* begin literal: */
				offset = 222 & 15;
				/* begin literal:ofMethod: */
				methodPointer = foo->method;
				foo->messageSelector = longAt((methodPointer + (BASE_HEADER_SIZE)) + ((offset + LiteralStart) << (SHIFT_FOR_WORD)));
				foo->argumentCount = ((((usqInt) 222) >> 4) & 3) - 1;
				goto normalSend;
			}
;
			break;
		case 223:
			/* sendLiteralSelectorBytecode */
			{
				sqInt offset;
				sqInt methodPointer;
				/* begin literal: */
				offset = 223 & 15;
				/* begin literal:ofMethod: */
				methodPointer = foo->method;
				foo->messageSelector = longAt((methodPointer + (BASE_HEADER_SIZE)) + ((offset + LiteralStart) << (SHIFT_FOR_WORD)));
				foo->argumentCount = ((((usqInt) 223) >> 4) & 3) - 1;
				goto normalSend;
			}
;
			break;
		case 224:
			/* sendLiteralSelectorBytecode */
			{
				sqInt offset;
				sqInt methodPointer;
				/* begin literal: */
				offset = 224 & 15;
				/* begin literal:ofMethod: */
				methodPointer = foo->method;
				foo->messageSelector = longAt((methodPointer + (BASE_HEADER_SIZE)) + ((offset + LiteralStart) << (SHIFT_FOR_WORD)));
				foo->argumentCount = ((((usqInt) 224) >> 4) & 3) - 1;
				goto normalSend;
			}
;
			break;
		case 225:
			/* sendLiteralSelectorBytecode */
			{
				sqInt offset;
				sqInt methodPointer;
				/* begin literal: */
				offset = 225 & 15;
				/* begin literal:ofMethod: */
				methodPointer = foo->method;
				foo->messageSelector = longAt((methodPointer + (BASE_HEADER_SIZE)) + ((offset + LiteralStart) << (SHIFT_FOR_WORD)));
				foo->argumentCount = ((((usqInt) 225) >> 4) & 3) - 1;
				goto normalSend;
			}
;
			break;
		case 226:
			/* sendLiteralSelectorBytecode */
			{
				sqInt offset;
				sqInt methodPointer;
				/* begin literal: */
				offset = 226 & 15;
				/* begin literal:ofMethod: */
				methodPointer = foo->method;
				foo->messageSelector = longAt((methodPointer + (BASE_HEADER_SIZE)) + ((offset + LiteralStart) << (SHIFT_FOR_WORD)));
				foo->argumentCount = ((((usqInt) 226) >> 4) & 3) - 1;
				goto normalSend;
			}
;
			break;
		case 227:
			/* sendLiteralSelectorBytecode */
			{
				sqInt offset;
				sqInt methodPointer;
				/* begin literal: */
				offset = 227 & 15;
				/* begin literal:ofMethod: */
				methodPointer = foo->method;
				foo->messageSelector = longAt((methodPointer + (BASE_HEADER_SIZE)) + ((offset + LiteralStart) << (SHIFT_FOR_WORD)));
				foo->argumentCount = ((((usqInt) 227) >> 4) & 3) - 1;
				goto normalSend;
			}
;
			break;
		case 228:
			/* sendLiteralSelectorBytecode */
			{
				sqInt offset;
				sqInt methodPointer;
				/* begin literal: */
				offset = 228 & 15;
				/* begin literal:ofMethod: */
				methodPointer = foo->method;
				foo->messageSelector = longAt((methodPointer + (BASE_HEADER_SIZE)) + ((offset + LiteralStart) << (SHIFT_FOR_WORD)));
				foo->argumentCount = ((((usqInt) 228) >> 4) & 3) - 1;
				goto normalSend;
			}
;
			break;
		case 229:
			/* sendLiteralSelectorBytecode */
			{
				sqInt offset;
				sqInt methodPointer;
				/* begin literal: */
				offset = 229 & 15;
				/* begin literal:ofMethod: */
				methodPointer = foo->method;
				foo->messageSelector = longAt((methodPointer + (BASE_HEADER_SIZE)) + ((offset + LiteralStart) << (SHIFT_FOR_WORD)));
				foo->argumentCount = ((((usqInt) 229) >> 4) & 3) - 1;
				goto normalSend;
			}
;
			break;
		case 230:
			/* sendLiteralSelectorBytecode */
			{
				sqInt offset;
				sqInt methodPointer;
				/* begin literal: */
				offset = 230 & 15;
				/* begin literal:ofMethod: */
				methodPointer = foo->method;
				foo->messageSelector = longAt((methodPointer + (BASE_HEADER_SIZE)) + ((offset + LiteralStart) << (SHIFT_FOR_WORD)));
				foo->argumentCount = ((((usqInt) 230) >> 4) & 3) - 1;
				goto normalSend;
			}
;
			break;
		case 231:
			/* sendLiteralSelectorBytecode */
			{
				sqInt offset;
				sqInt methodPointer;
				/* begin literal: */
				offset = 231 & 15;
				/* begin literal:ofMethod: */
				methodPointer = foo->method;
				foo->messageSelector = longAt((methodPointer + (BASE_HEADER_SIZE)) + ((offset + LiteralStart) << (SHIFT_FOR_WORD)));
				foo->argumentCount = ((((usqInt) 231) >> 4) & 3) - 1;
				goto normalSend;
			}
;
			break;
		case 232:
			/* sendLiteralSelectorBytecode */
			{
				sqInt offset;
				sqInt methodPointer;
				/* begin literal: */
				offset = 232 & 15;
				/* begin literal:ofMethod: */
				methodPointer = foo->method;
				foo->messageSelector = longAt((methodPointer + (BASE_HEADER_SIZE)) + ((offset + LiteralStart) << (SHIFT_FOR_WORD)));
				foo->argumentCount = ((((usqInt) 232) >> 4) & 3) - 1;
				goto normalSend;
			}
;
			break;
		case 233:
			/* sendLiteralSelectorBytecode */
			{
				sqInt offset;
				sqInt methodPointer;
				/* begin literal: */
				offset = 233 & 15;
				/* begin literal:ofMethod: */
				methodPointer = foo->method;
				foo->messageSelector = longAt((methodPointer + (BASE_HEADER_SIZE)) + ((offset + LiteralStart) << (SHIFT_FOR_WORD)));
				foo->argumentCount = ((((usqInt) 233) >> 4) & 3) - 1;
				goto normalSend;
			}
;
			break;
		case 234:
			/* sendLiteralSelectorBytecode */
			{
				sqInt offset;
				sqInt methodPointer;
				/* begin literal: */
				offset = 234 & 15;
				/* begin literal:ofMethod: */
				methodPointer = foo->method;
				foo->messageSelector = longAt((methodPointer + (BASE_HEADER_SIZE)) + ((offset + LiteralStart) << (SHIFT_FOR_WORD)));
				foo->argumentCount = ((((usqInt) 234) >> 4) & 3) - 1;
				goto normalSend;
			}
;
			break;
		case 235:
			/* sendLiteralSelectorBytecode */
			{
				sqInt offset;
				sqInt methodPointer;
				/* begin literal: */
				offset = 235 & 15;
				/* begin literal:ofMethod: */
				methodPointer = foo->method;
				foo->messageSelector = longAt((methodPointer + (BASE_HEADER_SIZE)) + ((offset + LiteralStart) << (SHIFT_FOR_WORD)));
				foo->argumentCount = ((((usqInt) 235) >> 4) & 3) - 1;
				goto normalSend;
			}
;
			break;
		case 236:
			/* sendLiteralSelectorBytecode */
			{
				sqInt offset;
				sqInt methodPointer;
				/* begin literal: */
				offset = 236 & 15;
				/* begin literal:ofMethod: */
				methodPointer = foo->method;
				foo->messageSelector = longAt((methodPointer + (BASE_HEADER_SIZE)) + ((offset + LiteralStart) << (SHIFT_FOR_WORD)));
				foo->argumentCount = ((((usqInt) 236) >> 4) & 3) - 1;
				goto normalSend;
			}
;
			break;
		case 237:
			/* sendLiteralSelectorBytecode */
			{
				sqInt offset;
				sqInt methodPointer;
				/* begin literal: */
				offset = 237 & 15;
				/* begin literal:ofMethod: */
				methodPointer = foo->method;
				foo->messageSelector = longAt((methodPointer + (BASE_HEADER_SIZE)) + ((offset + LiteralStart) << (SHIFT_FOR_WORD)));
				foo->argumentCount = ((((usqInt) 237) >> 4) & 3) - 1;
				goto normalSend;
			}
;
			break;
		case 238:
			/* sendLiteralSelectorBytecode */
			{
				sqInt offset;
				sqInt methodPointer;
				/* begin literal: */
				offset = 238 & 15;
				/* begin literal:ofMethod: */
				methodPointer = foo->method;
				foo->messageSelector = longAt((methodPointer + (BASE_HEADER_SIZE)) + ((offset + LiteralStart) << (SHIFT_FOR_WORD)));
				foo->argumentCount = ((((usqInt) 238) >> 4) & 3) - 1;
				goto normalSend;
			}
;
			break;
		case 239:
			/* sendLiteralSelectorBytecode */
			{
				sqInt offset;
				sqInt methodPointer;
				/* begin literal: */
				offset = 239 & 15;
				/* begin literal:ofMethod: */
				methodPointer = foo->method;
				foo->messageSelector = longAt((methodPointer + (BASE_HEADER_SIZE)) + ((offset + LiteralStart) << (SHIFT_FOR_WORD)));
				foo->argumentCount = ((((usqInt) 239) >> 4) & 3) - 1;
				goto normalSend;
			}
;
			break;
		case 240:
			/* sendLiteralSelectorBytecode */
			{
				sqInt offset;
				sqInt methodPointer;
				/* begin literal: */
				offset = 240 & 15;
				/* begin literal:ofMethod: */
				methodPointer = foo->method;
				foo->messageSelector = longAt((methodPointer + (BASE_HEADER_SIZE)) + ((offset + LiteralStart) << (SHIFT_FOR_WORD)));
				foo->argumentCount = ((((usqInt) 240) >> 4) & 3) - 1;
				goto normalSend;
			}
;
			break;
		case 241:
			/* sendLiteralSelectorBytecode */
			{
				sqInt offset;
				sqInt methodPointer;
				/* begin literal: */
				offset = 241 & 15;
				/* begin literal:ofMethod: */
				methodPointer = foo->method;
				foo->messageSelector = longAt((methodPointer + (BASE_HEADER_SIZE)) + ((offset + LiteralStart) << (SHIFT_FOR_WORD)));
				foo->argumentCount = ((((usqInt) 241) >> 4) & 3) - 1;
				goto normalSend;
			}
;
			break;
		case 242:
			/* sendLiteralSelectorBytecode */
			{
				sqInt offset;
				sqInt methodPointer;
				/* begin literal: */
				offset = 242 & 15;
				/* begin literal:ofMethod: */
				methodPointer = foo->method;
				foo->messageSelector = longAt((methodPointer + (BASE_HEADER_SIZE)) + ((offset + LiteralStart) << (SHIFT_FOR_WORD)));
				foo->argumentCount = ((((usqInt) 242) >> 4) & 3) - 1;
				goto normalSend;
			}
;
			break;
		case 243:
			/* sendLiteralSelectorBytecode */
			{
				sqInt offset;
				sqInt methodPointer;
				/* begin literal: */
				offset = 243 & 15;
				/* begin literal:ofMethod: */
				methodPointer = foo->method;
				foo->messageSelector = longAt((methodPointer + (BASE_HEADER_SIZE)) + ((offset + LiteralStart) << (SHIFT_FOR_WORD)));
				foo->argumentCount = ((((usqInt) 243) >> 4) & 3) - 1;
				goto normalSend;
			}
;
			break;
		case 244:
			/* sendLiteralSelectorBytecode */
			{
				sqInt offset;
				sqInt methodPointer;
				/* begin literal: */
				offset = 244 & 15;
				/* begin literal:ofMethod: */
				methodPointer = foo->method;
				foo->messageSelector = longAt((methodPointer + (BASE_HEADER_SIZE)) + ((offset + LiteralStart) << (SHIFT_FOR_WORD)));
				foo->argumentCount = ((((usqInt) 244) >> 4) & 3) - 1;
				goto normalSend;
			}
;
			break;
		case 245:
			/* sendLiteralSelectorBytecode */
			{
				sqInt offset;
				sqInt methodPointer;
				/* begin literal: */
				offset = 245 & 15;
				/* begin literal:ofMethod: */
				methodPointer = foo->method;
				foo->messageSelector = longAt((methodPointer + (BASE_HEADER_SIZE)) + ((offset + LiteralStart) << (SHIFT_FOR_WORD)));
				foo->argumentCount = ((((usqInt) 245) >> 4) & 3) - 1;
				goto normalSend;
			}
;
			break;
		case 246:
			/* sendLiteralSelectorBytecode */
			{
				sqInt offset;
				sqInt methodPointer;
				/* begin literal: */
				offset = 246 & 15;
				/* begin literal:ofMethod: */
				methodPointer = foo->method;
				foo->messageSelector = longAt((methodPointer + (BASE_HEADER_SIZE)) + ((offset + LiteralStart) << (SHIFT_FOR_WORD)));
				foo->argumentCount = ((((usqInt) 246) >> 4) & 3) - 1;
				goto normalSend;
			}
;
			break;
		case 247:
			/* sendLiteralSelectorBytecode */
			{
				sqInt offset;
				sqInt methodPointer;
				/* begin literal: */
				offset = 247 & 15;
				/* begin literal:ofMethod: */
				methodPointer = foo->method;
				foo->messageSelector = longAt((methodPointer + (BASE_HEADER_SIZE)) + ((offset + LiteralStart) << (SHIFT_FOR_WORD)));
				foo->argumentCount = ((((usqInt) 247) >> 4) & 3) - 1;
				goto normalSend;
			}
;
			break;
		case 248:
			/* sendLiteralSelectorBytecode */
			{
				sqInt offset;
				sqInt methodPointer;
				/* begin literal: */
				offset = 248 & 15;
				/* begin literal:ofMethod: */
				methodPointer = foo->method;
				foo->messageSelector = longAt((methodPointer + (BASE_HEADER_SIZE)) + ((offset + LiteralStart) << (SHIFT_FOR_WORD)));
				foo->argumentCount = ((((usqInt) 248) >> 4) & 3) - 1;
				goto normalSend;
			}
;
			break;
		case 249:
			/* sendLiteralSelectorBytecode */
			{
				sqInt offset;
				sqInt methodPointer;
				/* begin literal: */
				offset = 249 & 15;
				/* begin literal:ofMethod: */
				methodPointer = foo->method;
				foo->messageSelector = longAt((methodPointer + (BASE_HEADER_SIZE)) + ((offset + LiteralStart) << (SHIFT_FOR_WORD)));
				foo->argumentCount = ((((usqInt) 249) >> 4) & 3) - 1;
				goto normalSend;
			}
;
			break;
		case 250:
			/* sendLiteralSelectorBytecode */
			{
				sqInt offset;
				sqInt methodPointer;
				/* begin literal: */
				offset = 250 & 15;
				/* begin literal:ofMethod: */
				methodPointer = foo->method;
				foo->messageSelector = longAt((methodPointer + (BASE_HEADER_SIZE)) + ((offset + LiteralStart) << (SHIFT_FOR_WORD)));
				foo->argumentCount = ((((usqInt) 250) >> 4) & 3) - 1;
				goto normalSend;
			}
;
			break;
		case 251:
			/* sendLiteralSelectorBytecode */
			{
				sqInt offset;
				sqInt methodPointer;
				/* begin literal: */
				offset = 251 & 15;
				/* begin literal:ofMethod: */
				methodPointer = foo->method;
				foo->messageSelector = longAt((methodPointer + (BASE_HEADER_SIZE)) + ((offset + LiteralStart) << (SHIFT_FOR_WORD)));
				foo->argumentCount = ((((usqInt) 251) >> 4) & 3) - 1;
				goto normalSend;
			}
;
			break;
		case 252:
			/* sendLiteralSelectorBytecode */
			{
				sqInt offset;
				sqInt methodPointer;
				/* begin literal: */
				offset = 252 & 15;
				/* begin literal:ofMethod: */
				methodPointer = foo->method;
				foo->messageSelector = longAt((methodPointer + (BASE_HEADER_SIZE)) + ((offset + LiteralStart) << (SHIFT_FOR_WORD)));
				foo->argumentCount = ((((usqInt) 252) >> 4) & 3) - 1;
				goto normalSend;
			}
;
			break;
		case 253:
			/* sendLiteralSelectorBytecode */
			{
				sqInt offset;
				sqInt methodPointer;
				/* begin literal: */
				offset = 253 & 15;
				/* begin literal:ofMethod: */
				methodPointer = foo->method;
				foo->messageSelector = longAt((methodPointer + (BASE_HEADER_SIZE)) + ((offset + LiteralStart) << (SHIFT_FOR_WORD)));
				foo->argumentCount = ((((usqInt) 253) >> 4) & 3) - 1;
				goto normalSend;
			}
;
			break;
		case 254:
			/* sendLiteralSelectorBytecode */
			{
				sqInt offset;
				sqInt methodPointer;
				/* begin literal: */
				offset = 254 & 15;
				/* begin literal:ofMethod: */
				methodPointer = foo->method;
				foo->messageSelector = longAt((methodPointer + (BASE_HEADER_SIZE)) + ((offset + LiteralStart) << (SHIFT_FOR_WORD)));
				foo->argumentCount = ((((usqInt) 254) >> 4) & 3) - 1;
				goto normalSend;
			}
;
			break;
		case 255:
			/* sendLiteralSelectorBytecode */
			{
				sqInt offset;
				sqInt methodPointer;
				/* begin literal: */
				offset = 255 & 15;
				/* begin literal:ofMethod: */
				methodPointer = foo->method;
				foo->messageSelector = longAt((methodPointer + (BASE_HEADER_SIZE)) + ((offset + LiteralStart) << (SHIFT_FOR_WORD)));
				foo->argumentCount = ((((usqInt) 255) >> 4) & 3) - 1;
				goto normalSend;
			}
;
			break;
		}
	}

	/* undo the pre-increment of IP before returning */

	localIP -= 1;
	/* begin externalizeIPandSP */
	foo->instructionPointer = oopForPointer(localIP);
	foo->stackPointer = oopForPointer(localSP);
	foo->theHomeContext = localHomeContext;
}


/*	the vm has to convert aFilenameString via any canonicalization and char-mapping and put the result in aCharBuffer.
Note the resolveAliases flag - this is an awful artefact of OSX and Apples demented alias handling. When opening a file, the flag must be  true, when closing or renaming it must be false. Sigh. */

sqInt ioFilenamefromStringofLengthresolveAliases(char *aCharBuffer, char *aFilenameString, sqInt filenameLength, sqInt aBoolean) {
	sqGetFilenameFromString(aCharBuffer, aFilenameString, filenameLength, aBoolean);
}


/*	Support for external primitives. */

sqInt isKindOf(sqInt oop, char *className) {
register struct foo * foo = &fum;
    sqInt oopClass;
    sqInt ccIndex;
    sqInt oop1;
    sqInt oop2;
    sqInt oop3;

	/* begin fetchClassOf: */
	if ((oop & 1)) {
		/* begin fetchPointer:ofObject: */
		oop1 = foo->specialObjectsOop;
		oopClass = longAt((oop1 + (BASE_HEADER_SIZE)) + (ClassInteger << (SHIFT_FOR_WORD)));
		goto l1;
	}
	ccIndex = (((usqInt) (longAt(oop))) >> 12) & 31;
	if (ccIndex == 0) {
		oopClass = (longAt(oop - (BASE_HEADER_SIZE))) & (ALL_BUT_TYPE_MASK);
		goto l1;
	} else {
		/* begin fetchPointer:ofObject: */
		/* begin fetchPointer:ofObject: */
		oop3 = foo->specialObjectsOop;
		oop2 = longAt((oop3 + (BASE_HEADER_SIZE)) + (CompactClasses << (SHIFT_FOR_WORD)));
		oopClass = longAt((oop2 + (BASE_HEADER_SIZE)) + ((ccIndex - 1) << (SHIFT_FOR_WORD)));
		goto l1;
	}
l1:	/* end fetchClassOf: */;
	while (!(oopClass == foo->nilObj)) {
		if (classNameOfIs(oopClass, className)) {
			return 1;
		}
		oopClass = longAt((oopClass + (BASE_HEADER_SIZE)) + (SuperclassIndex << (SHIFT_FOR_WORD)));
	}
	return 0;
}


/*	Support for external primitives */

sqInt isMemberOf(sqInt oop, char *className) {
register struct foo * foo = &fum;
    sqInt oopClass;
    sqInt ccIndex;
    sqInt oop1;
    sqInt oop2;
    sqInt oop3;

	/* begin fetchClassOf: */
	if ((oop & 1)) {
		/* begin fetchPointer:ofObject: */
		oop1 = foo->specialObjectsOop;
		oopClass = longAt((oop1 + (BASE_HEADER_SIZE)) + (ClassInteger << (SHIFT_FOR_WORD)));
		goto l1;
	}
	ccIndex = (((usqInt) (longAt(oop))) >> 12) & 31;
	if (ccIndex == 0) {
		oopClass = (longAt(oop - (BASE_HEADER_SIZE))) & (ALL_BUT_TYPE_MASK);
		goto l1;
	} else {
		/* begin fetchPointer:ofObject: */
		/* begin fetchPointer:ofObject: */
		oop3 = foo->specialObjectsOop;
		oop2 = longAt((oop3 + (BASE_HEADER_SIZE)) + (CompactClasses << (SHIFT_FOR_WORD)));
		oopClass = longAt((oop2 + (BASE_HEADER_SIZE)) + ((ccIndex - 1) << (SHIFT_FOR_WORD)));
		goto l1;
	}
l1:	/* end fetchClassOf: */;
	return classNameOfIs(oopClass, className);
}


/*	Answer true if this is an indexable object with pointer elements, e.g., an array */

sqInt isArray(sqInt oop) {
	return ((oop & 1) == 0) && (((((usqInt) (longAt(oop))) >> 8) & 15) == 2);
}


/*	Answer true (non-zero) if running on a big endian machine. */

sqInt isBigEnder(void) {
    sqInt anInt;
    char *cString;
    static sqInt endianness = -1;
    sqInt i;
    sqInt len;

	if (!(endianness == -1)) {
		return endianness;
	}
	len = sizeof(anInt);
	cString = (char *) &anInt;
	i = 0;
	while (i < len) {
		cString[i] = i;
		i += 1;
	}
	endianness = anInt & 255;
	return endianness;
}


/*	Answer true if the argument contains indexable bytes. See comment in formatOf: */
/*	Note: Includes CompiledMethods. */

sqInt isBytes(sqInt oop) {
	return ((oop & 1) == 0) && (((((usqInt) (longAt(oop))) >> 8) & 15) >= 8);
}


/*	Answer true if size is greater than (((2 raisedTo: 31) - 1) >> bits). Used
	to limit size of allocation requests to 31 bit integer maximum to prevent
	arithmetic overflow in subsequent calculations. Always answers false
	in interpreter simulation.
	
	In the case of a 64-bit object memory running on a 64-bit host platform,
	allow larger allocation requests.

	Assumes that sizeof(int) is 4 for all platforms. */

sqInt isExcessiveAllocationRequestshift(sqInt size, sqInt bits) {
    int int32;
    sqInt int64;
    sqInt shiftCount;

	
# ifdef SQ_IMAGE64  // a 64-bit object memory word size
	
# ifdef SQ_HOST64  // running on a 64-bit host platform

	/* use 64 bit check if both image and host are 64 bits */

	int64 = size;
	shiftCount = 0;
	if (int64 < 0) {
		return 1;
	}
	while (shiftCount < bits) {
		int64 = int64 << 1;
		if (int64 < 0) {
			return 1;
		}
		shiftCount += 1;
	}
	return 0;
# else
	if (size > 4294967295U) {
		return 0;
	}
# endif  // SQ_HOST64
	
# else

	/* common case of 32 bit image on either 32 or 64 bit host */

	int32 = size;
	shiftCount = 0;
	if (int32 < 0) {
		return 1;
	}
	while (shiftCount < bits) {
		int32 = int32 << 1;
		if (int32 < 0) {
			return 1;
		}
		shiftCount += 1;
	}
	return 0;
# endif  // SQ_IMAGE64
	
}

sqInt isFloatObject(sqInt oop) {
	return (fetchClassOf(oop)) == (fetchPointerofObject(ClassFloat, foo->specialObjectsOop));
}


/*	Is this a MethodContext whose meth has a primitive number of 199? */
/*	NB: the use of a primitive number for marking the method is pretty grungy, but it is simple to use for a test sytem, not too expensive and we don't actually have the two spare method header bits we need. We can probably obtain them when the method format is changed.
	NB 2: actually, the jitter will probably implement the prim to actually mark the volatile frame by changing the return function pointer. */

sqInt isHandlerMarked(sqInt aContext) {
    sqInt header;
    sqInt meth;
    sqInt pIndex;
    sqInt primBits;

	header = longAt(aContext);
	if (!(((((usqInt) header) >> 12) & 31) == 14)) {
		return 0;
	}
	meth = longAt((aContext + (BASE_HEADER_SIZE)) + (MethodIndex << (SHIFT_FOR_WORD)));
	/* begin primitiveIndexOf: */
	primBits = (((usqInt) (longAt((meth + (BASE_HEADER_SIZE)) + (HeaderIndex << (SHIFT_FOR_WORD))))) >> 1) & 268435967;
	pIndex = (primBits & 511) + (((usqInt) primBits) >> 19);
	return pIndex == 199;
}


/*	Return true if the given address is in ST object memory */

sqInt isInMemory(sqInt address) {
	return ((((usqInt) address)) >= (((usqInt) memory))) && ((((usqInt) address)) < (((usqInt) foo->endOfMemory)));
}

sqInt isIndexable(sqInt oop) {
	return ((((usqInt) (longAt(oop))) >> 8) & 15) >= 2;
}

sqInt isIntegerObject(sqInt objectPointer) {
	return (objectPointer & 1) > 0;
}


/*	Return true if the given value can be represented as a Smalltalk integer value. */
/*	Use a shift and XOR to set the sign bit if and only if the top two bits of the given
	value are the same, then test the sign bit. Note that the top two bits are equal for
	exactly those integers in the range that can be represented in 31-bits or 63-bits.

	Operands are coerced to machine integer size so the test will work with 64 bit
	images on 32 bit hosts. When running on a 32 bit host, the cast to int has little
	or no performance impact for either 32 bit or 64 bit images.

	On a 64 bit host, the shift and XOR test is replaced by an explicit range check,
	which provides the best performance for both 32 bit and 64 bit images.

	If the range of small integers is enlarged for 64 bit images, this method must
	be updated accordingly. */

sqInt isIntegerValue(sqInt intValue) {
	return 
# ifdef SQ_HOST32  // cast to int for 64 bit image on 32 bit host
		(((((int) intValue)) ^ ((((int) intValue)) << 1)) >= 0)
# else
		((intValue >= -1073741824) && (intValue <= 1073741823))
# endif  // SQ_HOST32
	;
}


/*	Answer true if the argument has only fields that can hold oops. See comment in formatOf: */

sqInt isPointers(sqInt oop) {
	return ((oop & 1) == 0) && (((((usqInt) (longAt(oop))) >> 8) & 15) <= 4);
}


/*	Answer true if the argument has only weak fields that can hold oops. See comment in formatOf: */

sqInt isWeak(sqInt oop) {
	return ((oop & 1) == 0) && (((((usqInt) (longAt(oop))) >> 8) & 15) == 4);
}


/*	Answer true if the argument contains only indexable words (no oops). See comment in formatOf: */

sqInt isWords(sqInt oop) {
	return ((oop & 1) == 0) && (((((usqInt) (longAt(oop))) >> 8) & 15) == 6);
}


/*	Answer true if the contains only indexable words or bytes (no oops). See comment in formatOf: */
/*	Note: Excludes CompiledMethods. */

sqInt isWordsOrBytes(sqInt oop) {
	return ((oop & 1) == 0) && (isWordsOrBytesNonInt(oop));
}


/*	Answer true if the contains only indexable words or bytes (no oops). See comment in formatOf: */
/*	Note: Excludes CompiledMethods. */

sqInt isWordsOrBytesNonInt(sqInt oop) {
    sqInt fmt;

	fmt = (((usqInt) (longAt(oop))) >> 8) & 15;
	return (fmt == 6) || ((fmt >= 8) && (fmt <= 11));
}


/*	Return the byte offset of the last pointer field of the given object.  
	Works with CompiledMethods, as well as ordinary objects. 
	Can be used even when the type bits are not correct. */

sqInt lastPointerOf(sqInt oop) {
    sqInt contextSize;
    sqInt fmt;
    sqInt header;
    sqInt methodHeader;
    sqInt sz;
    sqInt sp;
    sqInt header1;
    sqInt type;

	header = longAt(oop);
	fmt = (((usqInt) header) >> 8) & 15;
	if (fmt <= 4) {
		if ((fmt == 3) && ((((((usqInt) header) >> 12) & 31) == 13) || ((((((usqInt) header) >> 12) & 31) == 14) || (((((usqInt) header) >> 12) & 31) == 4)))) {
			/* begin fetchStackPointerOf: */
			sp = longAt((oop + (BASE_HEADER_SIZE)) + (StackPointerIndex << (SHIFT_FOR_WORD)));
			if (!((sp & 1))) {
				contextSize = 0;
				goto l1;
			}
			contextSize = (sp >> 1);
		l1:	/* end fetchStackPointerOf: */;
			return (CtxtTempFrameStart + contextSize) * (BYTES_PER_WORD);
		}
		/* begin sizeBitsOfSafe: */
		header1 = longAt(oop);
		/* begin rightType: */
		if ((header1 & (SIZE_MASK)) == 0) {
			type = HeaderTypeSizeAndClass;
			goto l2;
		} else {
			if ((header1 & CompactClassMask) == 0) {
				type = HeaderTypeClass;
				goto l2;
			} else {
				type = HeaderTypeShort;
				goto l2;
			}
		}
	l2:	/* end rightType: */;
		if (type == HeaderTypeSizeAndClass) {
			sz = (longAt(oop - ((BYTES_PER_WORD) * 2))) & (ALL_BUT_TYPE_MASK);
			goto l3;
		} else {
			sz = header1 & (SIZE_MASK);
			goto l3;
		}
	l3:	/* end sizeBitsOfSafe: */;
		return sz - (BASE_HEADER_SIZE);
	}
	if (fmt < 12) {
		return 0;
	}
	methodHeader = longAt(oop + (BASE_HEADER_SIZE));
	return (((((usqInt) methodHeader) >> 10) & 255) * (BYTES_PER_WORD)) + (BASE_HEADER_SIZE);
}


/*	Return the number of indexable bytes or words in the given object. Assume the argument is not an integer. For a CompiledMethod, the size of the method header (in bytes) should be subtracted from the result. */

sqInt lengthOf(sqInt oop) {
    sqInt header;
    sqInt sz;

	header = longAt(oop);
	/* begin lengthOf:baseHeader:format: */
	if ((header & TypeMask) == HeaderTypeSizeAndClass) {
		sz = (longAt(oop - ((BYTES_PER_WORD) * 2))) & (LONG_SIZE_MASK);
	} else {
		sz = header & (SIZE_MASK);
	}
	sz -= header & (SIZE_4_BIT);
	if (((((usqInt) header) >> 8) & 15) <= 4) {
		return ((usqInt) (sz - (BASE_HEADER_SIZE))) >> (SHIFT_FOR_WORD);
	}
	if (((((usqInt) header) >> 8) & 15) < 8) {
		return ((usqInt) (sz - (BASE_HEADER_SIZE))) >> 2;
	} else {
		return (sz - (BASE_HEADER_SIZE)) - (((((usqInt) header) >> 8) & 15) & 3);
	}
	return null;
}

sqInt literalofMethod(sqInt offset, sqInt methodPointer) {
	return longAt((methodPointer + (BASE_HEADER_SIZE)) + ((offset + LiteralStart) << (SHIFT_FOR_WORD)));
}

sqInt literalCountOf(sqInt methodPointer) {
    sqInt headerPointer;

	/* begin literalCountOfHeader: */
	headerPointer = longAt((methodPointer + (BASE_HEADER_SIZE)) + (HeaderIndex << (SHIFT_FOR_WORD)));
	return (((usqInt) headerPointer) >> 10) & 255;
}

sqInt literalCountOfHeader(sqInt headerPointer) {
	return (((usqInt) headerPointer) >> 10) & 255;
}


/*	This entry point needs to be implemented for the interpreter proxy.
	Since BitBlt is now a plugin we need to look up BitBltPlugin:=loadBitBltFrom
	and call it. This entire mechanism should eventually go away and be
	replaced with a dynamic lookup from BitBltPlugin itself but for backward
	compatibility this stub is provided */

sqInt loadBitBltFrom(sqInt bb) {
    void *fn;

	fn = ioLoadFunctionFrom("loadBitBltFrom", "BitBltPlugin");
	if (fn == 0) {
		/* begin primitiveFail */
		foo->successFlag = 0;
		return null;
	}
	return ((sqInt (*)(sqInt))fn)(bb);
}

sqInt loadInitialContext(void) {
register struct foo * foo = &fum;
    sqInt proc;
    sqInt sched;
    sqInt oop;
    sqInt oop1;
    sqInt activeCntx;
    sqInt tmp;

	/* begin fetchPointer:ofObject: */
	/* begin fetchPointer:ofObject: */
	oop1 = foo->specialObjectsOop;
	oop = longAt((oop1 + (BASE_HEADER_SIZE)) + (SchedulerAssociation << (SHIFT_FOR_WORD)));
	sched = longAt((oop + (BASE_HEADER_SIZE)) + (ValueIndex << (SHIFT_FOR_WORD)));
	proc = longAt((sched + (BASE_HEADER_SIZE)) + (ActiveProcessIndex << (SHIFT_FOR_WORD)));
	foo->activeContext = longAt((proc + (BASE_HEADER_SIZE)) + (SuspendedContextIndex << (SHIFT_FOR_WORD)));
	if ((((usqInt) foo->activeContext)) < (((usqInt) foo->youngStart))) {
		beRootIfOld(foo->activeContext);
	}
	/* begin fetchContextRegisters: */
	activeCntx = foo->activeContext;
	tmp = longAt((activeCntx + (BASE_HEADER_SIZE)) + (MethodIndex << (SHIFT_FOR_WORD)));
	if ((tmp & 1)) {
		tmp = longAt((activeCntx + (BASE_HEADER_SIZE)) + (HomeIndex << (SHIFT_FOR_WORD)));
		if ((((usqInt) tmp)) < (((usqInt) foo->youngStart))) {
			beRootIfOld(tmp);
		}
	} else {
		tmp = activeCntx;
	}
	foo->theHomeContext = tmp;
	foo->receiver = longAt((tmp + (BASE_HEADER_SIZE)) + (ReceiverIndex << (SHIFT_FOR_WORD)));
	foo->method = longAt((tmp + (BASE_HEADER_SIZE)) + (MethodIndex << (SHIFT_FOR_WORD)));
	tmp = ((longAt((activeCntx + (BASE_HEADER_SIZE)) + (InstructionPointerIndex << (SHIFT_FOR_WORD)))) >> 1);
	foo->instructionPointer = ((foo->method + tmp) + (BASE_HEADER_SIZE)) - 2;
	tmp = ((longAt((activeCntx + (BASE_HEADER_SIZE)) + (StackPointerIndex << (SHIFT_FOR_WORD)))) >> 1);
	foo->stackPointer = (activeCntx + (BASE_HEADER_SIZE)) + (((TempFrameStart + tmp) - 1) * (BYTES_PER_WORD));
	foo->reclaimableContextCount = 0;
}


/*	This method implements a simple method lookup cache. If an entry for the given selector and class is found in the cache, set the values of 'newMethod' and 'primitiveIndex' and return true. Otherwise, return false. */
/*	About the re-probe scheme: The hash is the low bits of the XOR of two large addresses, minus their useless lowest two bits. If a probe doesn't get a hit, the hash is shifted right one bit to compute the next probe, introducing a new randomish bit. The cache is probed CacheProbeMax times before giving up. */
/*	WARNING: Since the hash computation is based on the object addresses of the class and selector, we must rehash or flush when compacting storage. We've chosen to flush, since that also saves the trouble of updating the addresses of the objects in the cache. */

sqInt lookupInMethodCacheSelclass(sqInt selector, sqInt class) {
register struct foo * foo = &fum;
    sqInt hash;
    sqInt probe;


	/* shift drops two low-order zeros from addresses */

	hash = selector ^ class;

	/* first probe */

	probe = hash & MethodCacheMask;
	if (((foo->methodCache[probe + MethodCacheSelector]) == selector) && ((foo->methodCache[probe + MethodCacheClass]) == class)) {
		foo->newMethod = foo->methodCache[probe + MethodCacheMethod];
		foo->primitiveIndex = foo->methodCache[probe + MethodCachePrim];
		foo->newNativeMethod = foo->methodCache[probe + MethodCacheNative];
		foo->primitiveFunctionPointer = ((void *) (foo->methodCache[probe + MethodCachePrimFunction]));
		return 1;
	}

	/* second probe */

	probe = (((usqInt) hash) >> 1) & MethodCacheMask;
	if (((foo->methodCache[probe + MethodCacheSelector]) == selector) && ((foo->methodCache[probe + MethodCacheClass]) == class)) {
		foo->newMethod = foo->methodCache[probe + MethodCacheMethod];
		foo->primitiveIndex = foo->methodCache[probe + MethodCachePrim];
		foo->newNativeMethod = foo->methodCache[probe + MethodCacheNative];
		foo->primitiveFunctionPointer = ((void *) (foo->methodCache[probe + MethodCachePrimFunction]));
		return 1;
	}
	probe = (((usqInt) hash) >> 2) & MethodCacheMask;
	if (((foo->methodCache[probe + MethodCacheSelector]) == selector) && ((foo->methodCache[probe + MethodCacheClass]) == class)) {
		foo->newMethod = foo->methodCache[probe + MethodCacheMethod];
		foo->primitiveIndex = foo->methodCache[probe + MethodCachePrim];
		foo->newNativeMethod = foo->methodCache[probe + MethodCacheNative];
		foo->primitiveFunctionPointer = ((void *) (foo->methodCache[probe + MethodCachePrimFunction]));
		return 1;
	}
	return 0;
}

sqInt lookupMethodInClass(sqInt class) {
register struct foo * foo = &fum;
    sqInt currentClass;
    sqInt dictionary;
    sqInt found;
    sqInt rclass;
    sqInt oop;
    sqInt oop1;
    sqInt oop2;
    sqInt oop3;
    sqInt index;
    sqInt length;
    sqInt mask;
    sqInt methodArray;
    sqInt nextSelector;
    sqInt wrapAround;
    sqInt sz;
    sqInt methodPointer;
    sqInt primBits;
    sqInt header;

	currentClass = class;
	while (currentClass != foo->nilObj) {
		dictionary = longAt((currentClass + (BASE_HEADER_SIZE)) + (MessageDictionaryIndex << (SHIFT_FOR_WORD)));
		if (dictionary == foo->nilObj) {
			/* begin pushRemappableOop: */
			foo->remapBuffer[(foo->remapBufferCount += 1)] = currentClass;
			createActualMessageTo(class);
			/* begin popRemappableOop */
			oop = foo->remapBuffer[foo->remapBufferCount];
			foo->remapBufferCount -= 1;
			currentClass = oop;
			/* begin fetchPointer:ofObject: */
			oop1 = foo->specialObjectsOop;
			foo->messageSelector = longAt((oop1 + (BASE_HEADER_SIZE)) + (SelectorCannotInterpret << (SHIFT_FOR_WORD)));
			return lookupMethodInClass(longAt((currentClass + (BASE_HEADER_SIZE)) + (SuperclassIndex << (SHIFT_FOR_WORD))));
		}
		/* begin lookupMethodInDictionary: */
		/* begin fetchWordLengthOf: */
		/* begin sizeBitsOf: */
		header = longAt(dictionary);
		if ((header & TypeMask) == HeaderTypeSizeAndClass) {
			sz = (longAt(dictionary - ((BYTES_PER_WORD) * 2))) & (LONG_SIZE_MASK);
			goto l1;
		} else {
			sz = header & (SIZE_MASK);
			goto l1;
		}
	l1:	/* end sizeBitsOf: */;
		length = ((usqInt) (sz - (BASE_HEADER_SIZE))) >> (SHIFT_FOR_WORD);
		mask = (length - SelectorStart) - 1;
		if ((foo->messageSelector & 1)) {
			index = (mask & ((foo->messageSelector >> 1))) + SelectorStart;
		} else {
			index = (mask & ((((usqInt) (longAt(foo->messageSelector))) >> 17) & 4095)) + SelectorStart;
		}
		wrapAround = 0;
		while (1) {
			nextSelector = longAt((dictionary + (BASE_HEADER_SIZE)) + (index << (SHIFT_FOR_WORD)));
			if (nextSelector == foo->nilObj) {
				found = 0;
				goto l2;
			}
			if (nextSelector == foo->messageSelector) {
				methodArray = longAt((dictionary + (BASE_HEADER_SIZE)) + (MethodArrayIndex << (SHIFT_FOR_WORD)));
				foo->newMethod = longAt((methodArray + (BASE_HEADER_SIZE)) + ((index - SelectorStart) << (SHIFT_FOR_WORD)));
				if (((((usqInt) (longAt(foo->newMethod))) >> 8) & 15) >= 12) {
					/* begin primitiveIndexOf: */
					methodPointer = foo->newMethod;
					primBits = (((usqInt) (longAt((methodPointer + (BASE_HEADER_SIZE)) + (HeaderIndex << (SHIFT_FOR_WORD))))) >> 1) & 268435967;
					foo->primitiveIndex = (primBits & 511) + (((usqInt) primBits) >> 19);
					if (foo->primitiveIndex > MaxPrimitiveIndex) {
						foo->primitiveIndex = 0;
					}
				} else {
					foo->primitiveIndex = 248;
				}
				found = 1;
				goto l2;
			}
			index += 1;
			if (index == length) {
				if (wrapAround) {
					found = 0;
					goto l2;
				}
				wrapAround = 1;
				index = SelectorStart;
			}
		}
	l2:	/* end lookupMethodInDictionary: */;
		if (found) {
			return foo->methodClass = currentClass;
		}
		currentClass = longAt((currentClass + (BASE_HEADER_SIZE)) + (SuperclassIndex << (SHIFT_FOR_WORD)));
	}
	if (foo->messageSelector == (fetchPointerofObject(SelectorDoesNotUnderstand, foo->specialObjectsOop))) {
		error("Recursive not understood error encountered");
	}
	/* begin pushRemappableOop: */
	foo->remapBuffer[(foo->remapBufferCount += 1)] = class;
	createActualMessageTo(class);
	/* begin popRemappableOop */
	oop2 = foo->remapBuffer[foo->remapBufferCount];
	foo->remapBufferCount -= 1;
	rclass = oop2;
	/* begin fetchPointer:ofObject: */
	oop3 = foo->specialObjectsOop;
	foo->messageSelector = longAt((oop3 + (BASE_HEADER_SIZE)) + (SelectorDoesNotUnderstand << (SHIFT_FOR_WORD)));
	return lookupMethodInClass(rclass);
}


/*	This method lookup tolerates integers as Dictionary keys to 
	support execution of images in which Symbols have been 
	compacted out */

sqInt lookupMethodInDictionary(sqInt dictionary) {
register struct foo * foo = &fum;
    sqInt index;
    sqInt length;
    sqInt mask;
    sqInt methodArray;
    sqInt nextSelector;
    sqInt wrapAround;
    sqInt sz;
    sqInt methodPointer;
    sqInt primBits;
    sqInt header;

	/* begin fetchWordLengthOf: */
	/* begin sizeBitsOf: */
	header = longAt(dictionary);
	if ((header & TypeMask) == HeaderTypeSizeAndClass) {
		sz = (longAt(dictionary - ((BYTES_PER_WORD) * 2))) & (LONG_SIZE_MASK);
		goto l1;
	} else {
		sz = header & (SIZE_MASK);
		goto l1;
	}
l1:	/* end sizeBitsOf: */;
	length = ((usqInt) (sz - (BASE_HEADER_SIZE))) >> (SHIFT_FOR_WORD);
	mask = (length - SelectorStart) - 1;
	if ((foo->messageSelector & 1)) {
		index = (mask & ((foo->messageSelector >> 1))) + SelectorStart;
	} else {
		index = (mask & ((((usqInt) (longAt(foo->messageSelector))) >> 17) & 4095)) + SelectorStart;
	}
	wrapAround = 0;
	while (1) {
		nextSelector = longAt((dictionary + (BASE_HEADER_SIZE)) + (index << (SHIFT_FOR_WORD)));
		if (nextSelector == foo->nilObj) {
			return 0;
		}
		if (nextSelector == foo->messageSelector) {
			methodArray = longAt((dictionary + (BASE_HEADER_SIZE)) + (MethodArrayIndex << (SHIFT_FOR_WORD)));

			/* Check if newMethod is a CompiledMethod. */

			foo->newMethod = longAt((methodArray + (BASE_HEADER_SIZE)) + ((index - SelectorStart) << (SHIFT_FOR_WORD)));
			if (((((usqInt) (longAt(foo->newMethod))) >> 8) & 15) >= 12) {
				/* begin primitiveIndexOf: */
				methodPointer = foo->newMethod;
				primBits = (((usqInt) (longAt((methodPointer + (BASE_HEADER_SIZE)) + (HeaderIndex << (SHIFT_FOR_WORD))))) >> 1) & 268435967;
				foo->primitiveIndex = (primBits & 511) + (((usqInt) primBits) >> 19);
				if (foo->primitiveIndex > MaxPrimitiveIndex) {

					/* If primitiveIndex is out of range, set to zero before putting in 
									cache. This is equiv to primFail, and avoids the need to check on 
									every send. */

					foo->primitiveIndex = 0;
				}
			} else {

				/* indicate that this is no compiled method - use primitiveInvokeObjectAsMethod */

				foo->primitiveIndex = 248;
			}
			return 1;
		}
		index += 1;
		if (index == length) {
			if (wrapAround) {
				return 0;
			}
			wrapAround = 1;
			index = SelectorStart;
		}
	}
}


/*	Lookup.  Answer false on failure father than performing MNU processing etc. */

sqInt lookupMethodNoMNUEtcInClass(sqInt class) {
register struct foo * foo = &fum;
    sqInt currentClass;
    sqInt dictionary;

	currentClass = class;
	while (currentClass != foo->nilObj) {
		dictionary = longAt((currentClass + (BASE_HEADER_SIZE)) + (MessageDictionaryIndex << (SHIFT_FOR_WORD)));
		if ((dictionary != foo->nilObj) && (lookupMethodInDictionary(dictionary))) {
			foo->methodClass = currentClass;
			return 1;
		}
		currentClass = longAt((currentClass + (BASE_HEADER_SIZE)) + (SuperclassIndex << (SHIFT_FOR_WORD)));
	}
	return 0;
}


/*	Return the first free block after the given chunk in memory. */

sqInt lowestFreeAfter(sqInt chunk) {
register struct foo * foo = &fum;
    sqInt oop;
    sqInt oopHeader;
    sqInt oopHeaderType;
    sqInt oopSize;

	oop = chunk + (foo->headerTypeBytes[(longAt(chunk)) & TypeMask]);
	while ((((usqInt) oop)) < (((usqInt) foo->endOfMemory))) {
		oopHeader = longAt(oop);
		oopHeaderType = oopHeader & TypeMask;
		if (oopHeaderType == HeaderTypeFree) {
			return oop;
		} else {
			if (oopHeaderType == HeaderTypeSizeAndClass) {
				oopSize = (longAt(oop - ((BYTES_PER_WORD) * 2))) & (ALL_BUT_TYPE_MASK);
			} else {
				oopSize = oopHeader & (SIZE_MASK);
			}
		}
		oop = (oop + oopSize) + (foo->headerTypeBytes[(longAt(oop + oopSize)) & TypeMask]);
	}
	error("expected to find at least one free object");
}


/*	make a Point xValue@yValue.
We know both will be integers so no value nor root checking is needed */

sqInt makePointwithxValueyValue(sqInt xValue, sqInt yValue) {
    sqInt pointResult;

	pointResult = instantiateSmallClasssizeInBytes(fetchPointerofObject(ClassPoint, foo->specialObjectsOop), 3 * (BYTES_PER_WORD));
	longAtput((pointResult + (BASE_HEADER_SIZE)) + (XIndex << (SHIFT_FOR_WORD)), ((xValue << 1) | 1));
	longAtput((pointResult + (BASE_HEADER_SIZE)) + (YIndex << (SHIFT_FOR_WORD)), ((yValue << 1) | 1));
	return pointResult;
}


/*	Use the forwarding table to update the pointers of all non-free objects in the given range of memory. Also remap pointers in root objects which may contains pointers into the given memory range, and don't forget to flush the method cache based on the range */

sqInt mapPointersInObjectsFromto(sqInt memStart, sqInt memEnd) {
register struct foo * foo = &fum;
    sqInt i;
    sqInt oop;
    sqInt i1;
    sqInt oop1;
    sqInt i2;
    sqInt probe;

	/* begin compilerMapHookFrom:to: */
	if (foo->compilerInitialized) {
		compilerMapFromto(memStart, memEnd);
	}
	/* begin mapInterpreterOops */
	foo->nilObj = remap(foo->nilObj);
	foo->falseObj = remap(foo->falseObj);
	foo->trueObj = remap(foo->trueObj);
	foo->specialObjectsOop = remap(foo->specialObjectsOop);
	if (!(foo->compilerInitialized)) {
		foo->stackPointer -= foo->activeContext;
		foo->activeContext = remap(foo->activeContext);
		foo->stackPointer += foo->activeContext;
		foo->theHomeContext = remap(foo->theHomeContext);
	}
	foo->instructionPointer -= foo->method;
	foo->method = remap(foo->method);
	foo->instructionPointer += foo->method;
	foo->receiver = remap(foo->receiver);
	foo->messageSelector = remap(foo->messageSelector);
	foo->newMethod = remap(foo->newMethod);
	foo->methodClass = remap(foo->methodClass);
	foo->lkupClass = remap(foo->lkupClass);
	foo->receiverClass = remap(foo->receiverClass);
	for (i1 = 1; i1 <= foo->remapBufferCount; i1 += 1) {
		oop1 = foo->remapBuffer[i1];
		if (!((oop1 & 1))) {
			foo->remapBuffer[i1] = (remap(oop1));
		}
	}
	for (i1 = 1; i1 <= foo->jmpDepth; i1 += 1) {
		oop1 = foo->suspendedCallbacks[i1];
		if (!((oop1 & 1))) {
			foo->suspendedCallbacks[i1] = (remap(oop1));
		}
		oop1 = foo->suspendedMethods[i1];
		if (!((oop1 & 1))) {
			foo->suspendedMethods[i1] = (remap(oop1));
		}
	}
	for (i = 1; i <= foo->extraRootCount; i += 1) {
		oop = (foo->extraRoots[i])[0];
		if (!((oop & 1))) {
			(foo->extraRoots[i])[0] = (remap(oop));
		}
	}
	/* begin flushMethodCacheFrom:to: */
	probe = 0;
	for (i2 = 1; i2 <= MethodCacheEntries; i2 += 1) {
		if (!((foo->methodCache[probe + MethodCacheSelector]) == 0)) {
			if ((((((((usqInt) (foo->methodCache[probe + MethodCacheSelector]))) >= (((usqInt) memStart))) && ((((usqInt) (foo->methodCache[probe + MethodCacheSelector]))) < (((usqInt) memEnd)))) || (((((usqInt) (foo->methodCache[probe + MethodCacheClass]))) >= (((usqInt) memStart))) && ((((usqInt) (foo->methodCache[probe + MethodCacheClass]))) < (((usqInt) memEnd))))) || (((((usqInt) (foo->methodCache[probe + MethodCacheMethod]))) >= (((usqInt) memStart))) && ((((usqInt) (foo->methodCache[probe + MethodCacheMethod]))) < (((usqInt) memEnd))))) || (((((usqInt) (foo->methodCache[probe + MethodCacheNative]))) >= (((usqInt) memStart))) && ((((usqInt) (foo->methodCache[probe + MethodCacheNative]))) < (((usqInt) memEnd))))) {
				foo->methodCache[probe + MethodCacheSelector] = 0;
			}
		}
		probe += MethodCacheEntrySize;
	}
	for (i2 = 1; i2 <= AtCacheTotalSize; i2 += 1) {
		foo->atCache[i2] = 0;
	}
	updatePointersInRootObjectsFromto(memStart, memEnd);
	updatePointersInRangeFromto(memStart, memEnd);
}


/*	Mark all objects reachable from the given one.
	Trace from the given object even if it is old.
	Do not trace if it is already marked.
	Mark it only if it is a young object. */
/*	Tracer state variables:
		child		object being examined
		field		next field of child to examine
		parentField	field where child was stored in its referencing object */

sqInt markAndTrace(sqInt oop) {
register struct foo * foo = &fum;
    sqInt action;
    sqInt header;
    sqInt lastFieldOffset;
    sqInt statMarkCountLocal;
    sqInt contextSize;
    sqInt fmt;
    sqInt header1;
    sqInt methodHeader;
    sqInt sz;
    sqInt sp;
    sqInt header2;
    sqInt lastFieldOffset1;
    sqInt oop1;
    sqInt header3;
    sqInt type;
    sqInt childType;
    sqInt typeBits;
    sqInt contextSize1;
    sqInt fmt1;
    sqInt header4;
    sqInt methodHeader1;
    sqInt sz1;
    sqInt sp1;
    sqInt header11;
    sqInt type1;
    sqInt header5;
    sqInt type2;
    sqInt child;
    usqInt youngStartLocal;
    sqInt parentField;
    sqInt field;

	header = longAt(oop);
	if (!((header & (MARK_BIT)) == 0)) {
		return 0;
	}
	header = (header & (ALL_BUT_TYPE_MASK)) | HeaderTypeGC;
	if ((((usqInt) oop)) >= (((usqInt) foo->youngStart))) {
		header = header | (MARK_BIT);
	}
	longAtput(oop, header);
	parentField = GCTopMarker;
	child = oop;
	if (((((usqInt) (longAt(oop))) >> 8) & 15) == 4) {

		/* Set lastFieldOffset before the weak fields in the receiver */
		/* And remember as weak root */

		lastFieldOffset = (nonWeakFieldsOf(oop)) << (SHIFT_FOR_WORD);
		foo->weakRootCount += 1;
		foo->weakRoots[foo->weakRootCount] = oop;
	} else {
		/* begin lastPointerOf: */
		header1 = longAt(oop);
		fmt = (((usqInt) header1) >> 8) & 15;
		if (fmt <= 4) {
			if ((fmt == 3) && ((((((usqInt) header1) >> 12) & 31) == 13) || ((((((usqInt) header1) >> 12) & 31) == 14) || (((((usqInt) header1) >> 12) & 31) == 4)))) {
				/* begin fetchStackPointerOf: */
				sp = longAt((oop + (BASE_HEADER_SIZE)) + (StackPointerIndex << (SHIFT_FOR_WORD)));
				if (!((sp & 1))) {
					contextSize = 0;
					goto l1;
				}
				contextSize = (sp >> 1);
			l1:	/* end fetchStackPointerOf: */;
				lastFieldOffset = (CtxtTempFrameStart + contextSize) * (BYTES_PER_WORD);
				goto l2;
			}
			/* begin sizeBitsOfSafe: */
			header3 = longAt(oop);
			/* begin rightType: */
			if ((header3 & (SIZE_MASK)) == 0) {
				type = HeaderTypeSizeAndClass;
				goto l4;
			} else {
				if ((header3 & CompactClassMask) == 0) {
					type = HeaderTypeClass;
					goto l4;
				} else {
					type = HeaderTypeShort;
					goto l4;
				}
			}
		l4:	/* end rightType: */;
			if (type == HeaderTypeSizeAndClass) {
				sz = (longAt(oop - ((BYTES_PER_WORD) * 2))) & (ALL_BUT_TYPE_MASK);
				goto l5;
			} else {
				sz = header3 & (SIZE_MASK);
				goto l5;
			}
		l5:	/* end sizeBitsOfSafe: */;
			lastFieldOffset = sz - (BASE_HEADER_SIZE);
			goto l2;
		}
		if (fmt < 12) {
			lastFieldOffset = 0;
			goto l2;
		}
		methodHeader = longAt(oop + (BASE_HEADER_SIZE));
		lastFieldOffset = (((((usqInt) methodHeader) >> 10) & 255) * (BYTES_PER_WORD)) + (BASE_HEADER_SIZE);
	l2:	/* end lastPointerOf: */;
	}
	field = oop + lastFieldOffset;
	action = StartField;
	youngStartLocal = foo->youngStart;

	/* run the tracer state machine until all objects reachable from oop are marked */

	statMarkCountLocal = foo->statMarkCount;
	while (!(action == Done)) {
		statMarkCountLocal += 1;
		if (action == StartField) {
			/* begin startField */
			child = longAt(field);
			typeBits = child & TypeMask;
			if ((typeBits & 1) == 1) {
				field -= BYTES_PER_WORD;
				action = StartField;
				goto l7;
			}
			if (typeBits == 0) {
				longAtput(field, parentField);
				parentField = field;
				action = StartObj;
				goto l7;
			}
			if (typeBits == 2) {
				if ((child & CompactClassMask) != 0) {
					child = child & (ALL_BUT_TYPE_MASK);
					/* begin rightType: */
					if ((child & (SIZE_MASK)) == 0) {
						childType = HeaderTypeSizeAndClass;
						goto l6;
					} else {
						if ((child & CompactClassMask) == 0) {
							childType = HeaderTypeClass;
							goto l6;
						} else {
							childType = HeaderTypeShort;
							goto l6;
						}
					}
				l6:	/* end rightType: */;
					longAtput(field, child | childType);
					action = Upward;
					goto l7;
				} else {
					child = longAt(field - (BYTES_PER_WORD));
					child = child & (ALL_BUT_TYPE_MASK);
					longAtput(field - (BYTES_PER_WORD), parentField);
					parentField = (field - (BYTES_PER_WORD)) | 1;
					action = StartObj;
					goto l7;
				}
			}
		l7:	/* end startField */;
		}
		if (action == StartObj) {
			/* begin startObj */
			oop1 = child;
			if ((((usqInt) oop1)) < (((usqInt) youngStartLocal))) {
				field = oop1;
				action = Upward;
				goto l3;
			}
			header2 = longAt(oop1);
			if ((header2 & (MARK_BIT)) == 0) {
				if (((((usqInt) (longAt(oop1))) >> 8) & 15) == 4) {
					lastFieldOffset1 = (nonWeakFieldsOf(oop1)) << (SHIFT_FOR_WORD);
				} else {
					/* begin lastPointerOf: */
					header4 = longAt(oop1);
					fmt1 = (((usqInt) header4) >> 8) & 15;
					if (fmt1 <= 4) {
						if ((fmt1 == 3) && ((((((usqInt) header4) >> 12) & 31) == 13) || ((((((usqInt) header4) >> 12) & 31) == 14) || (((((usqInt) header4) >> 12) & 31) == 4)))) {
							/* begin fetchStackPointerOf: */
							sp1 = longAt((oop1 + (BASE_HEADER_SIZE)) + (StackPointerIndex << (SHIFT_FOR_WORD)));
							if (!((sp1 & 1))) {
								contextSize1 = 0;
								goto l8;
							}
							contextSize1 = (sp1 >> 1);
						l8:	/* end fetchStackPointerOf: */;
							lastFieldOffset1 = (CtxtTempFrameStart + contextSize1) * (BYTES_PER_WORD);
							goto l11;
						}
						/* begin sizeBitsOfSafe: */
						header11 = longAt(oop1);
						/* begin rightType: */
						if ((header11 & (SIZE_MASK)) == 0) {
							type1 = HeaderTypeSizeAndClass;
							goto l9;
						} else {
							if ((header11 & CompactClassMask) == 0) {
								type1 = HeaderTypeClass;
								goto l9;
							} else {
								type1 = HeaderTypeShort;
								goto l9;
							}
						}
					l9:	/* end rightType: */;
						if (type1 == HeaderTypeSizeAndClass) {
							sz1 = (longAt(oop1 - ((BYTES_PER_WORD) * 2))) & (ALL_BUT_TYPE_MASK);
							goto l10;
						} else {
							sz1 = header11 & (SIZE_MASK);
							goto l10;
						}
					l10:	/* end sizeBitsOfSafe: */;
						lastFieldOffset1 = sz1 - (BASE_HEADER_SIZE);
						goto l11;
					}
					if (fmt1 < 12) {
						lastFieldOffset1 = 0;
						goto l11;
					}
					methodHeader1 = longAt(oop1 + (BASE_HEADER_SIZE));
					lastFieldOffset1 = (((((usqInt) methodHeader1) >> 10) & 255) * (BYTES_PER_WORD)) + (BASE_HEADER_SIZE);
				l11:	/* end lastPointerOf: */;
				}
				header2 = header2 & (ALL_BUT_TYPE_MASK);
				header2 = (header2 | (MARK_BIT)) | HeaderTypeGC;
				longAtput(oop1, header2);
				field = oop1 + lastFieldOffset1;
				action = StartField;
				goto l3;
			} else {
				field = oop1;
				action = Upward;
				goto l3;
			}
		l3:	/* end startObj */;
		}
		if (action == Upward) {
			/* begin upward */
			if ((parentField & 1) == 1) {
				if (parentField == GCTopMarker) {
					header5 = (longAt(field)) & (ALL_BUT_TYPE_MASK);
					/* begin rightType: */
					if ((header5 & (SIZE_MASK)) == 0) {
						type2 = HeaderTypeSizeAndClass;
						goto l12;
					} else {
						if ((header5 & CompactClassMask) == 0) {
							type2 = HeaderTypeClass;
							goto l12;
						} else {
							type2 = HeaderTypeShort;
							goto l12;
						}
					}
				l12:	/* end rightType: */;
					longAtput(field, header5 | type2);
					action = Done;
					goto l14;
				} else {
					child = field;
					field = parentField - 1;
					parentField = longAt(field);
					header5 = longAt(field + (BYTES_PER_WORD));
					/* begin rightType: */
					if ((header5 & (SIZE_MASK)) == 0) {
						type2 = HeaderTypeSizeAndClass;
						goto l13;
					} else {
						if ((header5 & CompactClassMask) == 0) {
							type2 = HeaderTypeClass;
							goto l13;
						} else {
							type2 = HeaderTypeShort;
							goto l13;
						}
					}
				l13:	/* end rightType: */;
					longAtput(field, child | type2);
					field += BYTES_PER_WORD;
					header5 = header5 & (ALL_BUT_TYPE_MASK);
					longAtput(field, header5 | type2);
					action = Upward;
					goto l14;
				}
			} else {
				child = field;
				field = parentField;
				parentField = longAt(field);
				longAtput(field, child);
				field -= BYTES_PER_WORD;
				action = StartField;
				goto l14;
			}
		l14:	/* end upward */;
		}
	}
	foo->statMarkCount = statMarkCountLocal;
}


/*	Mark and trace all oops in the interpreter's state. */
/*	Assume: All traced variables contain valid oops. */

sqInt markAndTraceInterpreterOops(void) {
register struct foo * foo = &fum;
    sqInt i;
    sqInt oop;

	/* begin compilerMarkHook */
	if (foo->compilerInitialized) {
		compilerMark();
	}
	markAndTrace(foo->specialObjectsOop);
	if (foo->compilerInitialized) {
		markAndTrace(foo->receiver);
		markAndTrace(foo->method);
	} else {
		markAndTrace(foo->activeContext);
	}
	markAndTrace(foo->messageSelector);
	markAndTrace(foo->newMethod);
	markAndTrace(foo->methodClass);
	markAndTrace(foo->lkupClass);
	markAndTrace(foo->receiverClass);
	for (i = 1; i <= foo->remapBufferCount; i += 1) {
		oop = foo->remapBuffer[i];
		if (!((oop & 1))) {
			markAndTrace(oop);
		}
	}
	for (i = 1; i <= foo->jmpDepth; i += 1) {
		oop = foo->suspendedCallbacks[i];
		if (!((oop & 1))) {
			markAndTrace(oop);
		}
		oop = foo->suspendedMethods[i];
		if (!((oop & 1))) {
			markAndTrace(oop);
		}
	}
}


/*	Mark phase of the mark and sweep garbage collector. Set 
	the mark bits of all reachable objects. Free chunks are 
	untouched by this process. */
/*	Assume: All non-free objects are initially unmarked. Root 
	objects were unmarked when they were made roots. (Make 
	sure this stays true!!). */

sqInt markPhase(void) {
register struct foo * foo = &fum;
    sqInt i;
    sqInt oop;


	/* clear the recycled context lists */

	foo->freeContexts = NilContext;

	/* trace the interpreter's objects, including the active stack 
	and special objects array */

	foo->freeLargeContexts = NilContext;
	markAndTraceInterpreterOops();

	/* trace the roots */

	foo->statSpecialMarkCount = foo->statMarkCount;
	for (i = 1; i <= foo->rootTableCount; i += 1) {
		oop = foo->rootTable[i];
		markAndTrace(oop);
	}
	for (i = 1; i <= foo->extraRootCount; i += 1) {
		oop = (foo->extraRoots[i])[0];
		if (!((oop & 1))) {
			markAndTrace(oop);
		}
	}
}

sqInt methodArgumentCount(void) {
	return foo->argumentCount;
}

sqInt methodPrimitiveIndex(void) {
	return foo->primitiveIndex;
}


/*	The module with the given name was just unloaded. 
	Make sure we have no dangling references. */

EXPORT(sqInt) moduleUnloaded(char *aModuleName) {
	if ((strcmp(aModuleName, "SurfacePlugin")) == 0) {

		/* Surface plugin went away. Should never happen. But  then, who knows */

		showSurfaceFn = 0;
	}
}


/*	For access from BitBlt module */

sqInt nilObject(void) {
	return foo->nilObj;
}


/*	Return the number of non-weak fields in oop (i.e. the number of fixed fields).
	Note: The following is copied from fixedFieldsOf:format:length: since we do know
	the format of the oop (e.g. format = 4) and thus don't need the length. */

sqInt nonWeakFieldsOf(sqInt oop) {
register struct foo * foo = &fum;
    sqInt class;
    sqInt classFormat;
    sqInt ccIndex;
    sqInt oop1;
    sqInt oop2;
    sqInt oop3;

	if (!(((((usqInt) (longAt(oop))) >> 8) & 15) == 4)) {
		error("Called fixedFieldsOfWeak: with a non-weak oop");
	}
	/* begin fetchClassOf: */
	if ((oop & 1)) {
		/* begin fetchPointer:ofObject: */
		oop1 = foo->specialObjectsOop;
		class = longAt((oop1 + (BASE_HEADER_SIZE)) + (ClassInteger << (SHIFT_FOR_WORD)));
		goto l1;
	}
	ccIndex = (((usqInt) (longAt(oop))) >> 12) & 31;
	if (ccIndex == 0) {
		class = (longAt(oop - (BASE_HEADER_SIZE))) & (ALL_BUT_TYPE_MASK);
		goto l1;
	} else {
		/* begin fetchPointer:ofObject: */
		/* begin fetchPointer:ofObject: */
		oop3 = foo->specialObjectsOop;
		oop2 = longAt((oop3 + (BASE_HEADER_SIZE)) + (CompactClasses << (SHIFT_FOR_WORD)));
		class = longAt((oop2 + (BASE_HEADER_SIZE)) + ((ccIndex - 1) << (SHIFT_FOR_WORD)));
		goto l1;
	}
l1:	/* end fetchClassOf: */;
	classFormat = (longAt((class + (BASE_HEADER_SIZE)) + (InstanceSpecificationIndex << (SHIFT_FOR_WORD)))) - 1;
	return (((((usqInt) classFormat) >> 11) & 192) + ((((usqInt) classFormat) >> 2) & 63)) - 1;
}


/*	Float objects were saved in platform word ordering. Reorder them into the
	traditional object format. */

sqInt normalizeFloatOrderingInImage(void) {
register struct foo * foo = &fum;
    unsigned int *floatData;
    sqInt oop;
    unsigned int val;
    sqInt obj;
    sqInt sz;
    sqInt header;

	if (!(isBigEnder())) {
		/* begin firstAccessibleObject */
		obj = memory + (foo->headerTypeBytes[(longAt(memory)) & TypeMask]);
		while ((((usqInt) obj)) < (((usqInt) foo->endOfMemory))) {
			if (!(((longAt(obj)) & TypeMask) == HeaderTypeFree)) {
				oop = obj;
				goto l1;
			}
			/* begin objectAfter: */
			if (DoAssertionChecks) {
				if ((((usqInt) obj)) >= (((usqInt) foo->endOfMemory))) {
					error("no objects after the end of memory");
				}
			}
			if (((longAt(obj)) & TypeMask) == HeaderTypeFree) {
				sz = (longAt(obj)) & (ALL_BUT_TYPE_MASK);
			} else {
				/* begin sizeBitsOf: */
				header = longAt(obj);
				if ((header & TypeMask) == HeaderTypeSizeAndClass) {
					sz = (longAt(obj - ((BYTES_PER_WORD) * 2))) & (LONG_SIZE_MASK);
					goto l2;
				} else {
					sz = header & (SIZE_MASK);
					goto l2;
				}
			l2:	/* end sizeBitsOf: */;
			}
			obj = (obj + sz) + (foo->headerTypeBytes[(longAt(obj + sz)) & TypeMask]);
		}
		error("heap is empty");
	l1:	/* end firstAccessibleObject */;
		while (!(oop == null)) {
			if (!(((longAt(oop)) & TypeMask) == HeaderTypeFree)) {
				if ((fetchClassOf(oop)) == (fetchPointerofObject(ClassFloat, foo->specialObjectsOop))) {
					floatData = ((unsigned int *) (firstIndexableField(oop)));
					val = floatData[0];
					floatData[0] = (floatData[1]);
					floatData[1] = val;
				}
				oop = accessibleObjectAfter(oop);
			}
		}
	}
}


/*	Record that the given oop in the old object area points to an 
	object in the young area. 
	HeaderLoc is usually = oop, but may be an addr in a 
	forwarding block. */

sqInt noteAsRootheaderLoc(sqInt oop, sqInt headerLoc) {
register struct foo * foo = &fum;
    sqInt header;

	header = longAt(headerLoc);
	if ((header & (ROOT_BIT)) == 0) {
		if (foo->rootTableCount < RootTableRedZone) {

			/* record oop as root only if not already recorded */
			/* record root if there is enough room in the roots 
					table  */

			foo->rootTableCount += 1;
			foo->rootTable[foo->rootTableCount] = oop;
			longAtput(headerLoc, header | (ROOT_BIT));
		} else {
			if (foo->rootTableCount < RootTableSize) {

				/* we're getting in the red zone */
				/* but there's still space to record it */

				foo->rootTableCount += 1;
				foo->rootTable[foo->rootTableCount] = oop;
				longAtput(headerLoc, header | (ROOT_BIT));
				foo->allocationCount = foo->allocationsBetweenGCs + 1;
			}
		}
	}
}


/*	This should never be called: either the compiler is uninitialised (in which case the hooks should never be reached) or the compiler initialisation should have replaced all the hook with their external implementations. */

sqInt nullCompilerHook(void) {
	error("uninitialised compiler hook called");
	return 0;
}


/*	Return the object or free chunk immediately following the 
	given object or free chunk in memory. Return endOfMemory 
	when enumeration is complete. */

sqInt objectAfter(sqInt oop) {
register struct foo * foo = &fum;
    sqInt sz;
    sqInt header;

	if (DoAssertionChecks) {
		if ((((usqInt) oop)) >= (((usqInt) foo->endOfMemory))) {
			error("no objects after the end of memory");
		}
	}
	if (((longAt(oop)) & TypeMask) == HeaderTypeFree) {
		sz = (longAt(oop)) & (ALL_BUT_TYPE_MASK);
	} else {
		/* begin sizeBitsOf: */
		header = longAt(oop);
		if ((header & TypeMask) == HeaderTypeSizeAndClass) {
			sz = (longAt(oop - ((BYTES_PER_WORD) * 2))) & (LONG_SIZE_MASK);
			goto l1;
		} else {
			sz = header & (SIZE_MASK);
			goto l1;
		}
	l1:	/* end sizeBitsOf: */;
	}
	return (oop + sz) + (foo->headerTypeBytes[(longAt(oop + sz)) & TypeMask]);
}


/*	This message is deprecated but supported for a while via a tweak to sqVirtualMachine.[ch] Use fetchLong32, fetchLong64 or fetchPointer instead for new code */

sqInt obsoleteDontUseThisFetchWordofObject(sqInt fieldIndex, sqInt oop) {
	return long32At((oop + (BASE_HEADER_SIZE)) + (fieldIndex << 2));
}


/*	If this is a pointers object, check that its fields are all okay oops. */

sqInt okayFields(sqInt oop) {
register struct foo * foo = &fum;
    sqInt c;
    sqInt fieldOop;
    sqInt i;
    sqInt ccIndex;
    sqInt oop1;
    sqInt oop2;
    sqInt oop3;

	if ((oop == null) || (oop == 0)) {
		return 1;
	}
	if ((oop & 1)) {
		return 1;
	}
	okayOop(oop);
	oopHasOkayClass(oop);
	if (!(((oop & 1) == 0) && (((((usqInt) (longAt(oop))) >> 8) & 15) <= 4))) {
		return 1;
	}
	/* begin fetchClassOf: */
	if ((oop & 1)) {
		/* begin fetchPointer:ofObject: */
		oop1 = foo->specialObjectsOop;
		c = longAt((oop1 + (BASE_HEADER_SIZE)) + (ClassInteger << (SHIFT_FOR_WORD)));
		goto l1;
	}
	ccIndex = (((usqInt) (longAt(oop))) >> 12) & 31;
	if (ccIndex == 0) {
		c = (longAt(oop - (BASE_HEADER_SIZE))) & (ALL_BUT_TYPE_MASK);
		goto l1;
	} else {
		/* begin fetchPointer:ofObject: */
		/* begin fetchPointer:ofObject: */
		oop3 = foo->specialObjectsOop;
		oop2 = longAt((oop3 + (BASE_HEADER_SIZE)) + (CompactClasses << (SHIFT_FOR_WORD)));
		c = longAt((oop2 + (BASE_HEADER_SIZE)) + ((ccIndex - 1) << (SHIFT_FOR_WORD)));
		goto l1;
	}
l1:	/* end fetchClassOf: */;
	if ((c == (fetchPointerofObject(ClassMethodContext, foo->specialObjectsOop))) || (c == (fetchPointerofObject(ClassBlockContext, foo->specialObjectsOop)))) {
		i = (CtxtTempFrameStart + (fetchStackPointerOf(oop))) - 1;
	} else {
		i = (lengthOf(oop)) - 1;
	}
	while (i >= 0) {
		fieldOop = longAt((oop + (BASE_HEADER_SIZE)) + (i << (SHIFT_FOR_WORD)));
		if (!((fieldOop & 1))) {
			okayOop(fieldOop);
			oopHasOkayClass(fieldOop);
		}
		i -= 1;
	}
}


/*	Verify that the given oop is legitimate. Check address, header, and size but not class. */

sqInt okayOop(sqInt signedOop) {
register struct foo * foo = &fum;
    sqInt fmt;
    usqInt oop;
    sqInt sz;
    sqInt type;
    sqInt unusedBit;
    sqInt header;


	/* address and size checks */

	oop = ((usqInt) signedOop);
	if ((oop & 1)) {
		return 1;
	}
	if (!(oop < foo->endOfMemory)) {
		error("oop is not a valid address");
	}
	if (!((oop % (BYTES_PER_WORD)) == 0)) {
		error("oop is not a word-aligned address");
	}
	/* begin sizeBitsOf: */
	header = longAt(oop);
	if ((header & TypeMask) == HeaderTypeSizeAndClass) {
		sz = (longAt(oop - ((BYTES_PER_WORD) * 2))) & (LONG_SIZE_MASK);
		goto l1;
	} else {
		sz = header & (SIZE_MASK);
		goto l1;
	}
l1:	/* end sizeBitsOf: */;
	if (!((oop + sz) < foo->endOfMemory)) {
		error("oop size would make it extend beyond the end of memory");
	}
	type = (longAt(oop)) & TypeMask;
	if (type == HeaderTypeFree) {
		error("oop is a free chunk, not an object");
	}
	if (type == HeaderTypeShort) {
		if (((((usqInt) (longAt(oop))) >> 12) & 31) == 0) {
			error("cannot have zero compact class field in a short header");
		}
	}
	if (type == HeaderTypeClass) {
		if (!((oop >= (BYTES_PER_WORD)) && (((longAt(oop - (BYTES_PER_WORD))) & TypeMask) == type))) {
			error("class header word has wrong type");
		}
	}
	if (type == HeaderTypeSizeAndClass) {
		if (!((oop >= ((BYTES_PER_WORD) * 2)) && ((((longAt(oop - ((BYTES_PER_WORD) * 2))) & TypeMask) == type) && (((longAt(oop - (BYTES_PER_WORD))) & TypeMask) == type)))) {
			error("class header word has wrong type");
		}
	}
	fmt = (((usqInt) (longAt(oop))) >> 8) & 15;
	if ((fmt == 5) || (fmt == 7)) {
		error("oop has an unknown format type");
	}
	unusedBit = 536870912;
	if ((BYTES_PER_WORD) == 8) {
		unusedBit = unusedBit << 16;
		unusedBit = unusedBit << 16;
	}
	if (!(((longAt(oop)) & unusedBit) == 0)) {
		error("unused header bit 30 is set; should be zero");
	}
	if ((((longAt(oop)) & (ROOT_BIT)) == 1) && (oop >= foo->youngStart)) {
		error("root bit is set in a young object");
	}
	return 1;
}


/*	Compare two oop values, treating them as object memory locations.
	Use #cCoerce:to: to ensure comparison of unsigned magnitudes. This
	method will be inlined during C translation. */

sqInt oopisGreaterThan(sqInt anOop, sqInt otherOop) {
	return (((usqInt) anOop)) > (((usqInt) otherOop));
}


/*	Compare two oop values, treating them as object memory locations.
	Use #cCoerce:to: to ensure comparison of unsigned magnitudes. This
	method will be inlined during C translation. */

sqInt oopisGreaterThanOrEqualTo(sqInt anOop, sqInt otherOop) {
	return (((usqInt) anOop)) >= (((usqInt) otherOop));
}


/*	Compare two oop values, treating them as object memory locations.
	Use #cCoerce:to: to ensure comparison of unsigned magnitudes. This
	method will be inlined during C translation. */

sqInt oopisLessThan(sqInt anOop, sqInt otherOop) {
	return (((usqInt) anOop)) < (((usqInt) otherOop));
}


/*	Similar to oopHasOkayClass:, except that it only returns true or false. */

sqInt oopHasAcceptableClass(sqInt signedOop) {
register struct foo * foo = &fum;
    sqInt behaviorFormatBits;
    sqInt formatMask;
    usqInt oop;
    usqInt oopClass;
    sqInt oopFormatBits;

	if ((signedOop & 1)) {
		return 1;
	}
	oop = ((usqInt) signedOop);
	if (!(oop < foo->endOfMemory)) {
		return 0;
	}
	if (!((oop % (BYTES_PER_WORD)) == 0)) {
		return 0;
	}
	if (!((oop + (sizeBitsOf(oop))) < foo->endOfMemory)) {
		return 0;
	}
	oopClass = ((usqInt) (fetchClassOf(oop)));
	if ((oopClass & 1)) {
		return 0;
	}
	if (!(oopClass < foo->endOfMemory)) {
		return 0;
	}
	if (!((oopClass % (BYTES_PER_WORD)) == 0)) {
		return 0;
	}
	if (!((oopClass + (sizeBitsOf(oopClass))) < foo->endOfMemory)) {
		return 0;
	}
	if (!((((oopClass & 1) == 0) && (((((usqInt) (longAt(oopClass))) >> 8) & 15) <= 4)) && ((lengthOf(oopClass)) >= 3))) {
		return 0;
	}
	if (((oop & 1) == 0) && (((((usqInt) (longAt(oop))) >> 8) & 15) >= 8)) {

		/* ignore extra bytes size bits */

		formatMask = 3072;
	} else {
		formatMask = 3840;
	}
	behaviorFormatBits = ((longAt((oopClass + (BASE_HEADER_SIZE)) + (InstanceSpecificationIndex << (SHIFT_FOR_WORD)))) - 1) & formatMask;
	oopFormatBits = (longAt(oop)) & formatMask;
	if (!(behaviorFormatBits == oopFormatBits)) {
		return 0;
	}
	return 1;
}


/*	Attempt to verify that the given oop has a reasonable behavior. The class must be a valid, non-integer oop and must not be nilObj. It must be a pointers object with three or more fields. Finally, the instance specification field of the behavior must match that of the instance. */

sqInt oopHasOkayClass(sqInt signedOop) {
    sqInt behaviorFormatBits;
    sqInt formatMask;
    usqInt oop;
    usqInt oopClass;
    sqInt oopFormatBits;

	oop = ((usqInt) signedOop);
	okayOop(oop);
	oopClass = ((usqInt) (fetchClassOf(oop)));
	if ((oopClass & 1)) {
		error("a SmallInteger is not a valid class or behavior");
	}
	okayOop(oopClass);
	if (!((((oopClass & 1) == 0) && (((((usqInt) (longAt(oopClass))) >> 8) & 15) <= 4)) && ((lengthOf(oopClass)) >= 3))) {
		error("a class (behavior) must be a pointers object of size >= 3");
	}
	if (((oop & 1) == 0) && (((((usqInt) (longAt(oop))) >> 8) & 15) >= 8)) {

		/* ignore extra bytes size bits */

		formatMask = 3072;
	} else {
		formatMask = 3840;
	}
	behaviorFormatBits = ((longAt((oopClass + (BASE_HEADER_SIZE)) + (InstanceSpecificationIndex << (SHIFT_FOR_WORD)))) - 1) & formatMask;
	oopFormatBits = (longAt(oop)) & formatMask;
	if (!(behaviorFormatBits == oopFormatBits)) {
		error("object and its class (behavior) formats differ");
	}
	return 1;
}


/*	Note: May be called by translated primitive code. */

sqInt pop(sqInt nItems) {
register struct foo * foo = &fum;
	foo->stackPointer -= nItems * (BYTES_PER_WORD);
}

sqInt popthenPush(sqInt nItems, sqInt oop) {
register struct foo * foo = &fum;
    sqInt sp;

	longAtput(sp = foo->stackPointer - ((nItems - 1) * (BYTES_PER_WORD)), oop);
	foo->stackPointer = sp;
}


/*	Note: May be called by translated primitive code. */

double popFloat(void) {
register struct foo * foo = &fum;
    double  result;
    sqInt top;
    sqInt top1;
    sqInt classOop;
    sqInt ccIndex;
    sqInt cl;
    sqInt oop1;
    sqInt oop2;
    sqInt oop;

	/* begin popStack */
	top1 = longAt(foo->stackPointer);
	foo->stackPointer -= BYTES_PER_WORD;
	top = top1;
	/* begin assertClassOf:is: */
	/* begin fetchPointer:ofObject: */
	oop = foo->specialObjectsOop;
	classOop = longAt((oop + (BASE_HEADER_SIZE)) + (ClassFloat << (SHIFT_FOR_WORD)));
	if ((top & 1)) {
		foo->successFlag = 0;
		goto l1;
	}
	ccIndex = (((usqInt) (longAt(top))) >> 12) & 31;
	if (ccIndex == 0) {
		cl = (longAt(top - (BASE_HEADER_SIZE))) & (ALL_BUT_TYPE_MASK);
	} else {
		/* begin fetchPointer:ofObject: */
		/* begin fetchPointer:ofObject: */
		oop2 = foo->specialObjectsOop;
		oop1 = longAt((oop2 + (BASE_HEADER_SIZE)) + (CompactClasses << (SHIFT_FOR_WORD)));
		cl = longAt((oop1 + (BASE_HEADER_SIZE)) + ((ccIndex - 1) << (SHIFT_FOR_WORD)));
	}
	/* begin success: */
	foo->successFlag = (cl == classOop) && foo->successFlag;
l1:	/* end assertClassOf:is: */;
	if (foo->successFlag) {
		;
		fetchFloatAtinto(top + (BASE_HEADER_SIZE), result);
	}
	return result;
}


/*	Pop and return the possibly remapped object from the remap buffer. */

sqInt popRemappableOop(void) {
register struct foo * foo = &fum;
    sqInt oop;

	oop = foo->remapBuffer[foo->remapBufferCount];
	foo->remapBufferCount -= 1;
	return oop;
}

sqInt popStack(void) {
register struct foo * foo = &fum;
    sqInt top;

	top = longAt(foo->stackPointer);
	foo->stackPointer -= BYTES_PER_WORD;
	return top;
}


/*	Note - integerValue is interpreted as POSITIVE, eg, as the result of
		Bitmap>at:, or integer>bitAnd:. */

sqInt positive32BitIntegerFor(sqInt integerValue) {
register struct foo * foo = &fum;
    sqInt newLargeInteger;

	if (integerValue >= 0) {
		if (
# ifdef SQ_HOST32  // cast to int for 64 bit image on 32 bit host
			(((((int) integerValue)) ^ ((((int) integerValue)) << 1)) >= 0)
# else
			((integerValue >= -1073741824) && (integerValue <= 1073741823))
# endif  // SQ_HOST32
		) {
			return ((integerValue << 1) | 1);
		}
	}
	if ((BYTES_PER_WORD) == 4) {

		/* Faster instantiateSmallClass: currently only works with integral word size. */

		newLargeInteger = instantiateSmallClasssizeInBytes(fetchPointerofObject(ClassLargePositiveInteger, foo->specialObjectsOop), (BASE_HEADER_SIZE) + 4);
	} else {

		/* Cant use instantiateSmallClass: due to integral word requirement. */

		newLargeInteger = instantiateClassindexableSize(fetchPointerofObject(ClassLargePositiveInteger, foo->specialObjectsOop), 4);
	}
	byteAtput((newLargeInteger + (BASE_HEADER_SIZE)) + 3, (((usqInt) integerValue) >> 24) & 255);
	byteAtput((newLargeInteger + (BASE_HEADER_SIZE)) + 2, (((usqInt) integerValue) >> 16) & 255);
	byteAtput((newLargeInteger + (BASE_HEADER_SIZE)) + 1, (((usqInt) integerValue) >> 8) & 255);
	byteAtput((newLargeInteger + (BASE_HEADER_SIZE)) + 0, integerValue & 255);
	return newLargeInteger;
}


/*	Convert the given object into an integer value.
	The object may be either a positive ST integer or a four-byte LargePositiveInteger. */

sqInt positive32BitValueOf(sqInt oop) {
register struct foo * foo = &fum;
    sqInt sz;
    sqInt value;
    sqInt header;
    sqInt sz1;
    sqInt classOop;
    sqInt ccIndex;
    sqInt cl;
    sqInt oop1;
    sqInt oop2;
    sqInt oop3;

	if ((oop & 1)) {
		value = (oop >> 1);
		if (value < 0) {
			/* begin primitiveFail */
			foo->successFlag = 0;
			return null;
		}
		return value;
	}
	/* begin assertClassOf:is: */
	/* begin fetchPointer:ofObject: */
	oop3 = foo->specialObjectsOop;
	classOop = longAt((oop3 + (BASE_HEADER_SIZE)) + (ClassLargePositiveInteger << (SHIFT_FOR_WORD)));
	if ((oop & 1)) {
		foo->successFlag = 0;
		goto l2;
	}
	ccIndex = (((usqInt) (longAt(oop))) >> 12) & 31;
	if (ccIndex == 0) {
		cl = (longAt(oop - (BASE_HEADER_SIZE))) & (ALL_BUT_TYPE_MASK);
	} else {
		/* begin fetchPointer:ofObject: */
		/* begin fetchPointer:ofObject: */
		oop2 = foo->specialObjectsOop;
		oop1 = longAt((oop2 + (BASE_HEADER_SIZE)) + (CompactClasses << (SHIFT_FOR_WORD)));
		cl = longAt((oop1 + (BASE_HEADER_SIZE)) + ((ccIndex - 1) << (SHIFT_FOR_WORD)));
	}
	/* begin success: */
	foo->successFlag = (cl == classOop) && foo->successFlag;
l2:	/* end assertClassOf:is: */;
	if (foo->successFlag) {
		/* begin lengthOf: */
		header = longAt(oop);
		/* begin lengthOf:baseHeader:format: */
		if ((header & TypeMask) == HeaderTypeSizeAndClass) {
			sz1 = (longAt(oop - ((BYTES_PER_WORD) * 2))) & (LONG_SIZE_MASK);
		} else {
			sz1 = header & (SIZE_MASK);
		}
		sz1 -= header & (SIZE_4_BIT);
		if (((((usqInt) header) >> 8) & 15) <= 4) {
			sz = ((usqInt) (sz1 - (BASE_HEADER_SIZE))) >> (SHIFT_FOR_WORD);
			goto l1;
		}
		if (((((usqInt) header) >> 8) & 15) < 8) {
			sz = ((usqInt) (sz1 - (BASE_HEADER_SIZE))) >> 2;
			goto l1;
		} else {
			sz = (sz1 - (BASE_HEADER_SIZE)) - (((((usqInt) header) >> 8) & 15) & 3);
			goto l1;
		}
	l1:	/* end lengthOf:baseHeader:format: */;
		if (!(sz == 4)) {
			/* begin primitiveFail */
			foo->successFlag = 0;
			return null;
		}
	}
	if (foo->successFlag) {
		return (((byteAt((oop + (BASE_HEADER_SIZE)) + 0)) + ((byteAt((oop + (BASE_HEADER_SIZE)) + 1)) << 8)) + ((byteAt((oop + (BASE_HEADER_SIZE)) + 2)) << 16)) + ((byteAt((oop + (BASE_HEADER_SIZE)) + 3)) << 24);
	}
}


/*	Note - integerValue is interpreted as POSITIVE, eg, as the result of
		Bitmap>at:, or integer>bitAnd:. */

sqInt positive64BitIntegerFor(sqLong integerValue) {
    sqInt highWord;
    sqInt i;
    sqInt newLargeInteger;
    sqInt sz;
    sqInt value;

	if ((sizeof(integerValue)) == 4) {
		return positive32BitIntegerFor(integerValue);
	}

	/* shift is coerced to usqInt otherwise */

	highWord = integerValue >> 32;
	if (highWord == 0) {
		return positive32BitIntegerFor(integerValue);
	}
	sz = 5;
	if (!((highWord = ((usqInt) highWord) >> 8) == 0)) {
		sz += 1;
	}
	if (!((highWord = ((usqInt) highWord) >> 8) == 0)) {
		sz += 1;
	}
	if (!((highWord = ((usqInt) highWord) >> 8) == 0)) {
		sz += 1;
	}
	newLargeInteger = instantiateClassindexableSize(fetchPointerofObject(ClassLargePositiveInteger, foo->specialObjectsOop), sz);
	for (i = 0; i <= (sz - 1); i += 1) {
		value = (integerValue >> (i * 8)) & 255;
		byteAtput((newLargeInteger + (BASE_HEADER_SIZE)) + i, value);
	}
	return newLargeInteger;
}


/*	Convert the given object into an integer value.
	The object may be either a positive ST integer or a eight-byte LargePositiveInteger. */

sqLong positive64BitValueOf(sqInt oop) {
register struct foo * foo = &fum;
    sqInt i;
    sqInt sz;
    sqInt szsqLong;
    sqLong value;
    sqInt header;
    sqInt sz1;
    sqInt classOop;
    sqInt ccIndex;
    sqInt cl;
    sqInt oop1;
    sqInt oop2;
    sqInt oop3;

	if ((oop & 1)) {
		value = (oop >> 1);
		if (value < 0) {
			/* begin primitiveFail */
			foo->successFlag = 0;
			return null;
		}
		return value;
	}
	/* begin assertClassOf:is: */
	/* begin fetchPointer:ofObject: */
	oop3 = foo->specialObjectsOop;
	classOop = longAt((oop3 + (BASE_HEADER_SIZE)) + (ClassLargePositiveInteger << (SHIFT_FOR_WORD)));
	if ((oop & 1)) {
		foo->successFlag = 0;
		goto l2;
	}
	ccIndex = (((usqInt) (longAt(oop))) >> 12) & 31;
	if (ccIndex == 0) {
		cl = (longAt(oop - (BASE_HEADER_SIZE))) & (ALL_BUT_TYPE_MASK);
	} else {
		/* begin fetchPointer:ofObject: */
		/* begin fetchPointer:ofObject: */
		oop2 = foo->specialObjectsOop;
		oop1 = longAt((oop2 + (BASE_HEADER_SIZE)) + (CompactClasses << (SHIFT_FOR_WORD)));
		cl = longAt((oop1 + (BASE_HEADER_SIZE)) + ((ccIndex - 1) << (SHIFT_FOR_WORD)));
	}
	/* begin success: */
	foo->successFlag = (cl == classOop) && foo->successFlag;
l2:	/* end assertClassOf:is: */;
	if (!(foo->successFlag)) {
		/* begin primitiveFail */
		foo->successFlag = 0;
		return null;
	}
	szsqLong = sizeof(sqLong);
	/* begin lengthOf: */
	header = longAt(oop);
	/* begin lengthOf:baseHeader:format: */
	if ((header & TypeMask) == HeaderTypeSizeAndClass) {
		sz1 = (longAt(oop - ((BYTES_PER_WORD) * 2))) & (LONG_SIZE_MASK);
	} else {
		sz1 = header & (SIZE_MASK);
	}
	sz1 -= header & (SIZE_4_BIT);
	if (((((usqInt) header) >> 8) & 15) <= 4) {
		sz = ((usqInt) (sz1 - (BASE_HEADER_SIZE))) >> (SHIFT_FOR_WORD);
		goto l1;
	}
	if (((((usqInt) header) >> 8) & 15) < 8) {
		sz = ((usqInt) (sz1 - (BASE_HEADER_SIZE))) >> 2;
		goto l1;
	} else {
		sz = (sz1 - (BASE_HEADER_SIZE)) - (((((usqInt) header) >> 8) & 15) & 3);
		goto l1;
	}
l1:	/* end lengthOf:baseHeader:format: */;
	if (sz > szsqLong) {
		/* begin primitiveFail */
		foo->successFlag = 0;
		return null;
	}
	value = 0;
	for (i = 0; i <= (sz - 1); i += 1) {
		value += (((sqLong) (byteAt((oop + (BASE_HEADER_SIZE)) + i)))) << (i * 8);
	}
	return value;
}


/*	oop is an old object. If valueObj is young, mark the object as a root. */

sqInt possibleRootStoreIntovalue(sqInt oop, sqInt valueObj) {
register struct foo * foo = &fum;
    sqInt header;

	if (((((usqInt) valueObj)) >= (((usqInt) foo->youngStart))) && (!((valueObj & 1)))) {
		/* begin noteAsRoot:headerLoc: */
		header = longAt(oop);
		if ((header & (ROOT_BIT)) == 0) {
			if (foo->rootTableCount < RootTableRedZone) {
				foo->rootTableCount += 1;
				foo->rootTable[foo->rootTableCount] = oop;
				longAtput(oop, header | (ROOT_BIT));
			} else {
				if (foo->rootTableCount < RootTableSize) {
					foo->rootTableCount += 1;
					foo->rootTable[foo->rootTableCount] = oop;
					longAtput(oop, header | (ROOT_BIT));
					foo->allocationCount = foo->allocationsBetweenGCs + 1;
				}
			}
		}
	}
}


/*	Mark the active and home contexts as roots if old. This 
	allows the interpreter to use storePointerUnchecked to 
	store into them. */

sqInt postGCAction(void) {
register struct foo * foo = &fum;
    sqInt delta;
    sqInt limit;

	if (foo->compilerInitialized) {
		compilerPostGC();
	} else {
		if ((((usqInt) foo->activeContext)) < (((usqInt) foo->youngStart))) {
			beRootIfOld(foo->activeContext);
		}
		if ((((usqInt) foo->theHomeContext)) < (((usqInt) foo->youngStart))) {
			beRootIfOld(foo->theHomeContext);
		}
	}
	if (oopisGreaterThan((longAt(foo->freeBlock)) & (ALL_BUT_TYPE_MASK), foo->shrinkThreshold)) {
		/* begin shrinkObjectMemory: */
		delta = ((longAt(foo->freeBlock)) & (ALL_BUT_TYPE_MASK)) - foo->growHeadroom;
		foo->statShrinkMemory += 1;
		limit = sqShrinkMemoryBy(foo->memoryLimit, delta);
		if (!(limit == foo->memoryLimit)) {
			foo->memoryLimit = limit - 24;
			initializeMemoryFirstFree(foo->freeBlock);
		}
	}
	/* begin signalSemaphoreWithIndex: */
	if (foo->gcSemaphoreIndex <= 0) {
		goto l1;
	}
	if (foo->semaphoresUseBufferA) {
		if (foo->semaphoresToSignalCountA < SemaphoresToSignalSize) {
			foo->semaphoresToSignalCountA += 1;
			foo->semaphoresToSignalA[foo->semaphoresToSignalCountA] = foo->gcSemaphoreIndex;
		}
	} else {
		if (foo->semaphoresToSignalCountB < SemaphoresToSignalSize) {
			foo->semaphoresToSignalCountB += 1;
			foo->semaphoresToSignalB[foo->semaphoresToSignalCountB] = foo->gcSemaphoreIndex;
		}
	}
	/* begin forceInterruptCheck */
	foo->interruptCheckCounter = -1000;
	foo->nextPollTick = 0;
l1:	/* end signalSemaphoreWithIndex: */;
}


/*	Ensure that there are enough forwarding blocks to 
	accomodate this become, then prepare forwarding blocks for 
	the pointer swap. Return true if successful. */
/*	Details: Doing a GC might generate enough space for 
	forwarding blocks if we're short. However, this is an 
	uncommon enough case that it is better handled by primitive 
	fail code at the Smalltalk level. */
/*	Important note on multiple references to same object  - since the preparation of
	fwdBlocks is NOT idempotent we get VM crashes if the same object is referenced more
	than once in such a way as to require multiple fwdBlocks.
	oop1 forwardBecome: oop1 is ok since only a single fwdBlock is needed.
	oop1 become: oop1 would fail because the second fwdBlock woudl not have the actual object
	header but rather the mutated ref to the first fwdBlock.
	Further problems can arise with an array1 or array2 that refer multiply to the same 
	object. This would notbe expected input for programmer writen code but might arise from
	automatic usage such as in ImageSegment loading.
	To avoid the simple and rather common case of oop1 become*: oop1, we skip such pairs
	and simply avoid making fwdBlocks - it is redundant anyway */

sqInt prepareForwardingTableForBecomingwithtwoWay(sqInt array1, sqInt array2, sqInt twoWayFlag) {
register struct foo * foo = &fum;
    sqInt entriesAvailable;
    sqInt entriesNeeded;
    sqInt fieldOffset;
    sqInt fwdBlkSize;
    sqInt fwdBlock;
    sqInt oop1;
    sqInt oop2;
    sqInt originalHeader;
    sqInt originalHeaderType;
    sqInt originalHeader1;
    sqInt originalHeaderType1;
    sqInt contextSize;
    sqInt fmt;
    sqInt header;
    sqInt methodHeader;
    sqInt sz;
    sqInt sp;
    sqInt header1;
    sqInt type;


	/* need enough entries for all oops */
	/* Note: Forward blocks must be quadword aligned - see fwdTableInit:. */

	entriesNeeded = (lastPointerOf(array1)) / (BYTES_PER_WORD);
	if (twoWayFlag) {

		/* Double the number of blocks for two-way become */

		entriesNeeded = entriesNeeded * 2;
		fwdBlkSize = (BYTES_PER_WORD) * 2;
	} else {

		/* One-way become needs backPointers in fwd blocks. */

		fwdBlkSize = (BYTES_PER_WORD) * 4;
	}
	entriesAvailable = fwdTableInit(fwdBlkSize);
	if (entriesAvailable < entriesNeeded) {
		initializeMemoryFirstFree(foo->freeBlock);
		return 0;
	}
	/* begin lastPointerOf: */
	header = longAt(array1);
	fmt = (((usqInt) header) >> 8) & 15;
	if (fmt <= 4) {
		if ((fmt == 3) && ((((((usqInt) header) >> 12) & 31) == 13) || ((((((usqInt) header) >> 12) & 31) == 14) || (((((usqInt) header) >> 12) & 31) == 4)))) {
			/* begin fetchStackPointerOf: */
			sp = longAt((array1 + (BASE_HEADER_SIZE)) + (StackPointerIndex << (SHIFT_FOR_WORD)));
			if (!((sp & 1))) {
				contextSize = 0;
				goto l3;
			}
			contextSize = (sp >> 1);
		l3:	/* end fetchStackPointerOf: */;
			fieldOffset = (CtxtTempFrameStart + contextSize) * (BYTES_PER_WORD);
			goto l4;
		}
		/* begin sizeBitsOfSafe: */
		header1 = longAt(array1);
		/* begin rightType: */
		if ((header1 & (SIZE_MASK)) == 0) {
			type = HeaderTypeSizeAndClass;
			goto l5;
		} else {
			if ((header1 & CompactClassMask) == 0) {
				type = HeaderTypeClass;
				goto l5;
			} else {
				type = HeaderTypeShort;
				goto l5;
			}
		}
	l5:	/* end rightType: */;
		if (type == HeaderTypeSizeAndClass) {
			sz = (longAt(array1 - ((BYTES_PER_WORD) * 2))) & (ALL_BUT_TYPE_MASK);
			goto l6;
		} else {
			sz = header1 & (SIZE_MASK);
			goto l6;
		}
	l6:	/* end sizeBitsOfSafe: */;
		fieldOffset = sz - (BASE_HEADER_SIZE);
		goto l4;
	}
	if (fmt < 12) {
		fieldOffset = 0;
		goto l4;
	}
	methodHeader = longAt(array1 + (BASE_HEADER_SIZE));
	fieldOffset = (((((usqInt) methodHeader) >> 10) & 255) * (BYTES_PER_WORD)) + (BASE_HEADER_SIZE);
l4:	/* end lastPointerOf: */;
	while (fieldOffset >= (BASE_HEADER_SIZE)) {
		oop1 = longAt(array1 + fieldOffset);

		/* if oop1 == oop2, no need to do any work for this pair.
			May still be other entries in the arrays though so keep looking */

		oop2 = longAt(array2 + fieldOffset);
		if (!(oop1 == oop2)) {
			/* begin fwdBlockGet: */
			foo->fwdTableNext += fwdBlkSize;
			if (foo->fwdTableNext <= foo->fwdTableLast) {
				fwdBlock = foo->fwdTableNext;
				goto l2;
			} else {
				fwdBlock = null;
				goto l2;
			}
		l2:	/* end fwdBlockGet: */;
			/* begin initForwardBlock:mapping:to:withBackPtr: */
			originalHeader1 = longAt(oop1);
			if (DoAssertionChecks) {
				if (fwdBlock == null) {
					error("ran out of forwarding blocks in become");
				}
				if ((originalHeader1 & (MARK_BIT)) != 0) {
					error("object already has a forwarding table entry");
				}
			}
			originalHeaderType1 = originalHeader1 & TypeMask;
			longAtput(fwdBlock, oop2);
			longAtput(fwdBlock + (BYTES_PER_WORD), originalHeader1);
			if (!twoWayFlag) {
				longAtput(fwdBlock + ((BYTES_PER_WORD) * 2), oop1);
			}
			longAtput(oop1, (((usqInt) fwdBlock) >> 1) | ((MARK_BIT) | originalHeaderType1));
			if (twoWayFlag) {
				/* begin fwdBlockGet: */
				foo->fwdTableNext += fwdBlkSize;
				if (foo->fwdTableNext <= foo->fwdTableLast) {
					fwdBlock = foo->fwdTableNext;
					goto l1;
				} else {
					fwdBlock = null;
					goto l1;
				}
			l1:	/* end fwdBlockGet: */;
				/* begin initForwardBlock:mapping:to:withBackPtr: */
				originalHeader = longAt(oop2);
				if (DoAssertionChecks) {
					if (fwdBlock == null) {
						error("ran out of forwarding blocks in become");
					}
					if ((originalHeader & (MARK_BIT)) != 0) {
						error("object already has a forwarding table entry");
					}
				}
				originalHeaderType = originalHeader & TypeMask;
				longAtput(fwdBlock, oop1);
				longAtput(fwdBlock + (BYTES_PER_WORD), originalHeader);
				if (!twoWayFlag) {
					longAtput(fwdBlock + ((BYTES_PER_WORD) * 2), oop2);
				}
				longAtput(oop2, (((usqInt) fwdBlock) >> 1) | ((MARK_BIT) | originalHeaderType));
			}
		}
		fieldOffset -= BYTES_PER_WORD;
	}
	return 1;
}

sqInt primitiveAdd(void) {
register struct foo * foo = &fum;
    sqInt integerResult;
    sqInt sp;

	/* begin pop2AndPushIntegerIfOK: */
	integerResult = (stackIntegerValue(1)) + (stackIntegerValue(0));
	if (foo->successFlag) {
		if (
# ifdef SQ_HOST32  // cast to int for 64 bit image on 32 bit host
			(((((int) integerResult)) ^ ((((int) integerResult)) << 1)) >= 0)
# else
			((integerResult >= -1073741824) && (integerResult <= 1073741823))
# endif  // SQ_HOST32
		) {
			/* begin pop:thenPush: */
			longAtput(sp = foo->stackPointer - ((2 - 1) * (BYTES_PER_WORD)), ((integerResult << 1) | 1));
			foo->stackPointer = sp;
		} else {
			foo->successFlag = 0;
		}
	}
}


/*	Primitive arithmetic operations for large integers in 64 bit range */

EXPORT(sqInt) primitiveAddLargeIntegers(void) {
register struct foo * foo = &fum;
    sqLong integerArg;
    sqLong integerRcvr;
    sqInt oopResult;
    sqLong result;
    sqInt sp;

	integerArg = signed64BitValueOf(longAt(foo->stackPointer - (0 * (BYTES_PER_WORD))));
	integerRcvr = signed64BitValueOf(longAt(foo->stackPointer - (1 * (BYTES_PER_WORD))));
	if (!(foo->successFlag)) {
		return null;
	}

	/* Now check overflow conditions. First is whether rcvr and arg are of the same sign.
	If they are we need to check for overflow more carefully. */

	result = integerRcvr + integerArg;
	if (!((integerRcvr ^ integerArg) < 0)) {
		if ((integerRcvr ^ result) < 0) {
			/* begin primitiveFail */
			foo->successFlag = 0;
		}
	}
	if (!(foo->successFlag)) {
		return null;
	}
	oopResult = signed64BitIntegerFor(result);
	if (foo->successFlag) {
		/* begin pop:thenPush: */
		longAtput(sp = foo->stackPointer - ((2 - 1) * (BYTES_PER_WORD)), oopResult);
		foo->stackPointer = sp;
	}
}


/*	Primitive. Change the class of the argument to make it an instance of the receiver
	 given that the format of the receiver matches the format of the argument's class.
	 Fail if receiver or argument are SmallIntegers, or the receiver is an instance of a
	 compact class and the argument isn't, or when the argument's class is compact and
	 the receiver isn't, or when the format of the receiver is different from the format of
	 the argument's class, or when the arguments class is fixed and the receiver's size
	 differs from the size that an instance of the argument's class should have. */

sqInt primitiveAdoptInstance(void) {
register struct foo * foo = &fum;
    sqInt arg;
    sqInt err;
    sqInt rcvr;
    sqInt i;
    sqInt oop;
    sqInt oop1;

	/* begin stackObjectValue: */
	oop = longAt(foo->stackPointer - (0 * (BYTES_PER_WORD)));
	if ((oop & 1)) {
		/* begin primitiveFail */
		foo->successFlag = 0;
		arg = null;
		goto l1;
	}
	arg = oop;
l1:	/* end stackObjectValue: */;
	/* begin stackObjectValue: */
	oop1 = longAt(foo->stackPointer - (1 * (BYTES_PER_WORD)));
	if ((oop1 & 1)) {
		/* begin primitiveFail */
		foo->successFlag = 0;
		rcvr = null;
		goto l2;
	}
	rcvr = oop1;
l2:	/* end stackObjectValue: */;
	err = changeClassOfto(arg, rcvr);
	if (err == 0) {
		/* begin flushAtCache */
		for (i = 1; i <= AtCacheTotalSize; i += 1) {
			foo->atCache[i] = 0;
		}
		/* begin pop: */
		foo->stackPointer -= foo->argumentCount * (BYTES_PER_WORD);
	} else {
		/* begin primitiveFail */
		foo->successFlag = 0;
	}
	return null;
}

sqInt primitiveArctan(void) {
register struct foo * foo = &fum;
    double  rcvr;

	rcvr = popFloat();
	if (foo->successFlag) {
		pushFloat(atan(rcvr));
	} else {
		/* begin unPop: */
		foo->stackPointer += 1 * (BYTES_PER_WORD);
	}
}


/*	We must flush the method cache here, to eliminate stale references
	to mutated classes and/or selectors. */

sqInt primitiveArrayBecome(void) {
register struct foo * foo = &fum;
    sqInt arg;
    sqInt rcvr;
    sqInt successValue;

	arg = longAt(foo->stackPointer);
	rcvr = longAt(foo->stackPointer - (1 * (BYTES_PER_WORD)));
	/* begin success: */
	successValue = becomewithtwoWaycopyHash(rcvr, arg, 1, 1);
	foo->successFlag = successValue && foo->successFlag;
	if (foo->successFlag) {
		/* begin pop: */
		foo->stackPointer -= 1 * (BYTES_PER_WORD);
	}
}


/*	We must flush the method cache here, to eliminate stale references
	to mutated classes and/or selectors. */

sqInt primitiveArrayBecomeOneWay(void) {
register struct foo * foo = &fum;
    sqInt arg;
    sqInt rcvr;
    sqInt successValue;

	arg = longAt(foo->stackPointer);
	rcvr = longAt(foo->stackPointer - (1 * (BYTES_PER_WORD)));
	/* begin success: */
	successValue = becomewithtwoWaycopyHash(rcvr, arg, 0, 1);
	foo->successFlag = successValue && foo->successFlag;
	if (foo->successFlag) {
		/* begin pop: */
		foo->stackPointer -= 1 * (BYTES_PER_WORD);
	}
}


/*	Similar to primitiveArrayBecomeOneWay but accepts a third argument whether to copy
	the receiver's identity hash over the argument's identity hash. */

sqInt primitiveArrayBecomeOneWayCopyHash(void) {
register struct foo * foo = &fum;
    sqInt arg;
    sqInt copyHashFlag;
    sqInt rcvr;
    sqInt successValue;

	/* begin booleanValueOf: */
	if ((longAt(foo->stackPointer)) == foo->trueObj) {
		copyHashFlag = 1;
		goto l1;
	}
	if ((longAt(foo->stackPointer)) == foo->falseObj) {
		copyHashFlag = 0;
		goto l1;
	}
	foo->successFlag = 0;
	copyHashFlag = null;
l1:	/* end booleanValueOf: */;
	arg = longAt(foo->stackPointer - (1 * (BYTES_PER_WORD)));
	rcvr = longAt(foo->stackPointer - (2 * (BYTES_PER_WORD)));
	/* begin success: */
	successValue = becomewithtwoWaycopyHash(rcvr, arg, 0, copyHashFlag);
	foo->successFlag = successValue && foo->successFlag;
	if (foo->successFlag) {
		/* begin pop: */
		foo->stackPointer -= 2 * (BYTES_PER_WORD);
	}
}

sqInt primitiveAsFloat(void) {
register struct foo * foo = &fum;
    sqInt arg;
    sqInt integerPointer;
    sqInt top;

	/* begin popInteger */
	/* begin popStack */
	top = longAt(foo->stackPointer);
	foo->stackPointer -= BYTES_PER_WORD;
	integerPointer = top;
	/* begin checkedIntegerValueOf: */
	if ((integerPointer & 1)) {
		arg = (integerPointer >> 1);
		goto l1;
	} else {
		/* begin primitiveFail */
		foo->successFlag = 0;
		arg = 0;
		goto l1;
	}
	arg = null;
l1:	/* end popInteger */;
	if (foo->successFlag) {
		pushFloat(((double) arg));
	} else {
		/* begin unPop: */
		foo->stackPointer += 1 * (BYTES_PER_WORD);
	}
}

sqInt primitiveAsOop(void) {
register struct foo * foo = &fum;
    sqInt thisReceiver;
    sqInt sp;

	thisReceiver = longAt(foo->stackPointer);
	/* begin success: */
	foo->successFlag = (!((thisReceiver & 1))) && foo->successFlag;
	if (foo->successFlag) {
		/* begin pop:thenPushInteger: */
		longAtput(sp = foo->stackPointer - ((1 - 1) * (BYTES_PER_WORD)), ((((((usqInt) (longAt(thisReceiver))) >> 17) & 4095) << 1) | 1));
		foo->stackPointer = sp;
	}
}

sqInt primitiveAt(void) {
	commonAt(0);
}

sqInt primitiveAtPut(void) {
	commonAtPut(0);
}


/*	Set the cursor to the given shape. The Mac only supports 16x16 pixel cursors. Cursor offsets are handled by Smalltalk. */

sqInt primitiveBeCursor(void) {
register struct foo * foo = &fum;
    sqInt bitsObj;
    sqInt cursorBitsIndex;
    sqInt cursorObj;
    sqInt depth;
    sqInt extentX;
    sqInt extentY;
    sqInt i;
    sqInt maskBitsIndex;
    sqInt maskObj;
    sqInt offsetObj;
    sqInt offsetX;
    sqInt offsetY;
    sqInt ourCursor;
    sqInt successValue;
    sqInt successValue1;
    sqInt successValue2;
    sqInt successValue3;
    sqInt successValue4;
    sqInt successValue5;
    sqInt successValue6;
    sqInt successValue7;
    sqInt successValue8;
    sqInt successValue9;
    sqInt successValue10;
    sqInt successValue11;
    sqInt successValue12;

	flag("Dan");
	if ((BYTES_PER_WORD) == 8) {
		/* begin pop: */
		foo->stackPointer -= foo->argumentCount * (BYTES_PER_WORD);
		return null;
	}
	if (foo->argumentCount == 0) {
		cursorObj = longAt(foo->stackPointer);
		maskBitsIndex = null;
	}
	if (foo->argumentCount == 1) {
		cursorObj = longAt(foo->stackPointer - (1 * (BYTES_PER_WORD)));
		maskObj = longAt(foo->stackPointer);
	}
	/* begin success: */
	foo->successFlag = (foo->argumentCount < 2) && foo->successFlag;
	/* begin success: */
	successValue11 = (((cursorObj & 1) == 0) && (((((usqInt) (longAt(cursorObj))) >> 8) & 15) <= 4)) && ((lengthOf(cursorObj)) >= 5);
	foo->successFlag = successValue11 && foo->successFlag;
	if (foo->successFlag) {
		bitsObj = longAt((cursorObj + (BASE_HEADER_SIZE)) + (0 << (SHIFT_FOR_WORD)));
		extentX = fetchIntegerofObject(1, cursorObj);
		extentY = fetchIntegerofObject(2, cursorObj);
		depth = fetchIntegerofObject(3, cursorObj);
		offsetObj = longAt((cursorObj + (BASE_HEADER_SIZE)) + (4 << (SHIFT_FOR_WORD)));
	}
	/* begin success: */
	successValue12 = (((offsetObj & 1) == 0) && (((((usqInt) (longAt(offsetObj))) >> 8) & 15) <= 4)) && ((lengthOf(offsetObj)) >= 2);
	foo->successFlag = successValue12 && foo->successFlag;
	if (foo->successFlag) {
		offsetX = fetchIntegerofObject(0, offsetObj);
		offsetY = fetchIntegerofObject(1, offsetObj);
		if ((foo->argumentCount == 0) && (depth == 32)) {
			/* begin success: */
			successValue = (extentX > 0) && (extentY > 0);
			foo->successFlag = successValue && foo->successFlag;
			/* begin success: */
			successValue1 = (offsetX >= (extentX * -1)) && (offsetX <= 0);
			foo->successFlag = successValue1 && foo->successFlag;
			/* begin success: */
			successValue2 = (offsetY >= (extentY * -1)) && (offsetY <= 0);
			foo->successFlag = successValue2 && foo->successFlag;
			cursorBitsIndex = bitsObj + (BASE_HEADER_SIZE);
			/* begin success: */
			successValue3 = (((bitsObj & 1) == 0) && (((((usqInt) (longAt(bitsObj))) >> 8) & 15) == 6)) && ((lengthOf(bitsObj)) == (extentX * extentY));
			foo->successFlag = successValue3 && foo->successFlag;
			;
		} else {
			/* begin success: */
			successValue4 = (extentX == 16) && ((extentY == 16) && (depth == 1));
			foo->successFlag = successValue4 && foo->successFlag;
			/* begin success: */
			successValue5 = (offsetX >= -16) && (offsetX <= 0);
			foo->successFlag = successValue5 && foo->successFlag;
			/* begin success: */
			successValue6 = (offsetY >= -16) && (offsetY <= 0);
			foo->successFlag = successValue6 && foo->successFlag;
			/* begin success: */
			successValue7 = (((bitsObj & 1) == 0) && (((((usqInt) (longAt(bitsObj))) >> 8) & 15) == 6)) && ((lengthOf(bitsObj)) == 16);
			foo->successFlag = successValue7 && foo->successFlag;
			cursorBitsIndex = bitsObj + (BASE_HEADER_SIZE);
			;
		}
	}
	if (foo->argumentCount == 1) {
		/* begin success: */
		successValue10 = (((maskObj & 1) == 0) && (((((usqInt) (longAt(maskObj))) >> 8) & 15) <= 4)) && ((lengthOf(maskObj)) >= 5);
		foo->successFlag = successValue10 && foo->successFlag;
		if (foo->successFlag) {
			bitsObj = longAt((maskObj + (BASE_HEADER_SIZE)) + (0 << (SHIFT_FOR_WORD)));
			extentX = fetchIntegerofObject(1, maskObj);
			extentY = fetchIntegerofObject(2, maskObj);
			depth = fetchIntegerofObject(3, maskObj);
		}
		if (foo->successFlag) {
			/* begin success: */
			successValue8 = (extentX == 16) && ((extentY == 16) && (depth == 1));
			foo->successFlag = successValue8 && foo->successFlag;
			/* begin success: */
			successValue9 = (((bitsObj & 1) == 0) && (((((usqInt) (longAt(bitsObj))) >> 8) & 15) == 6)) && ((lengthOf(bitsObj)) == 16);
			foo->successFlag = successValue9 && foo->successFlag;
			maskBitsIndex = bitsObj + (BASE_HEADER_SIZE);
		}
	}
	if (foo->successFlag) {
		if (foo->argumentCount == 0) {
			if (depth == 32) {
				if (!(ioSetCursorARGB(cursorBitsIndex, extentX, extentY, offsetX, offsetY))) {
					/* begin success: */
					foo->successFlag = 0 && foo->successFlag;
					return null;
				}
			} else {
				ioSetCursor(cursorBitsIndex, offsetX, offsetY);
			}
		} else {
			ioSetCursorWithMask(cursorBitsIndex, maskBitsIndex, offsetX, offsetY);
		}
		/* begin pop: */
		foo->stackPointer -= foo->argumentCount * (BYTES_PER_WORD);
	}
}


/*	Record the system Display object in the specialObjectsTable. */

sqInt primitiveBeDisplay(void) {
register struct foo * foo = &fum;
    sqInt rcvr;
    sqInt successValue;
    sqInt oop;

	rcvr = longAt(foo->stackPointer);
	/* begin success: */
	successValue = (((rcvr & 1) == 0) && (((((usqInt) (longAt(rcvr))) >> 8) & 15) <= 4)) && ((lengthOf(rcvr)) >= 4);
	foo->successFlag = successValue && foo->successFlag;
	if (foo->successFlag) {
		/* begin storePointer:ofObject:withValue: */
		oop = foo->specialObjectsOop;
		if ((((usqInt) oop)) < (((usqInt) foo->youngStart))) {
			possibleRootStoreIntovalue(oop, rcvr);
		}
		longAtput((oop + (BASE_HEADER_SIZE)) + (TheDisplay << (SHIFT_FOR_WORD)), rcvr);
	}
}


/*	make the basic beep noise */

sqInt primitiveBeep(void) {
	ioBeep();
}

sqInt primitiveBitAnd(void) {
register struct foo * foo = &fum;
    sqInt integerArgument;
    sqInt integerReceiver;
    sqInt top;
    sqInt top1;
    sqInt object;
    sqInt sp;
    sqInt top2;
    sqInt top3;

	/* begin popPos32BitInteger */
	/* begin popStack */
	top2 = longAt(foo->stackPointer);
	foo->stackPointer -= BYTES_PER_WORD;
	top = top2;
	integerArgument = positive32BitValueOf(top);
	/* begin popPos32BitInteger */
	/* begin popStack */
	top3 = longAt(foo->stackPointer);
	foo->stackPointer -= BYTES_PER_WORD;
	top1 = top3;
	integerReceiver = positive32BitValueOf(top1);
	if (foo->successFlag) {
		/* begin push: */
		object = positive32BitIntegerFor(integerReceiver & integerArgument);
		longAtput(sp = foo->stackPointer + (BYTES_PER_WORD), object);
		foo->stackPointer = sp;
	} else {
		/* begin unPop: */
		foo->stackPointer += 2 * (BYTES_PER_WORD);
	}
}


/*	Primitive logical operations for large integers in 64 bit range */

EXPORT(sqInt) primitiveBitAndLargeIntegers(void) {
register struct foo * foo = &fum;
    sqLong integerArg;
    sqLong integerRcvr;
    sqInt oopResult;
    sqInt sp;

	integerArg = positive64BitValueOf(longAt(foo->stackPointer - (0 * (BYTES_PER_WORD))));
	integerRcvr = positive64BitValueOf(longAt(foo->stackPointer - (1 * (BYTES_PER_WORD))));
	if (!(foo->successFlag)) {
		return null;
	}
	oopResult = positive64BitIntegerFor(integerRcvr & integerArg);
	if (foo->successFlag) {
		/* begin pop:thenPush: */
		longAtput(sp = foo->stackPointer - ((2 - 1) * (BYTES_PER_WORD)), oopResult);
		foo->stackPointer = sp;
	}
}

sqInt primitiveBitOr(void) {
register struct foo * foo = &fum;
    sqInt integerArgument;
    sqInt integerReceiver;
    sqInt top;
    sqInt top1;
    sqInt object;
    sqInt sp;
    sqInt top2;
    sqInt top3;

	/* begin popPos32BitInteger */
	/* begin popStack */
	top2 = longAt(foo->stackPointer);
	foo->stackPointer -= BYTES_PER_WORD;
	top = top2;
	integerArgument = positive32BitValueOf(top);
	/* begin popPos32BitInteger */
	/* begin popStack */
	top3 = longAt(foo->stackPointer);
	foo->stackPointer -= BYTES_PER_WORD;
	top1 = top3;
	integerReceiver = positive32BitValueOf(top1);
	if (foo->successFlag) {
		/* begin push: */
		object = positive32BitIntegerFor(integerReceiver | integerArgument);
		longAtput(sp = foo->stackPointer + (BYTES_PER_WORD), object);
		foo->stackPointer = sp;
	} else {
		/* begin unPop: */
		foo->stackPointer += 2 * (BYTES_PER_WORD);
	}
}


/*	Primitive logical operations for large integers in 64 bit range */

EXPORT(sqInt) primitiveBitOrLargeIntegers(void) {
register struct foo * foo = &fum;
    sqLong integerArg;
    sqLong integerRcvr;
    sqInt oopResult;
    sqInt sp;

	integerArg = positive64BitValueOf(longAt(foo->stackPointer - (0 * (BYTES_PER_WORD))));
	integerRcvr = positive64BitValueOf(longAt(foo->stackPointer - (1 * (BYTES_PER_WORD))));
	if (!(foo->successFlag)) {
		return null;
	}
	oopResult = positive64BitIntegerFor(integerRcvr | integerArg);
	if (foo->successFlag) {
		/* begin pop:thenPush: */
		longAtput(sp = foo->stackPointer - ((2 - 1) * (BYTES_PER_WORD)), oopResult);
		foo->stackPointer = sp;
	}
}

sqInt primitiveBitShift(void) {
register struct foo * foo = &fum;
    sqInt integerArgument;
    sqInt integerReceiver;
    sqInt shifted;
    sqInt top;
    sqInt object;
    sqInt sp;
    sqInt top1;
    sqInt integerPointer;
    sqInt top2;

	/* begin popInteger */
	/* begin popStack */
	top2 = longAt(foo->stackPointer);
	foo->stackPointer -= BYTES_PER_WORD;
	integerPointer = top2;
	/* begin checkedIntegerValueOf: */
	if ((integerPointer & 1)) {
		integerArgument = (integerPointer >> 1);
		goto l1;
	} else {
		/* begin primitiveFail */
		foo->successFlag = 0;
		integerArgument = 0;
		goto l1;
	}
	integerArgument = null;
l1:	/* end popInteger */;
	/* begin popPos32BitInteger */
	/* begin popStack */
	top1 = longAt(foo->stackPointer);
	foo->stackPointer -= BYTES_PER_WORD;
	top = top1;
	integerReceiver = positive32BitValueOf(top);
	if (foo->successFlag) {
		if (integerArgument >= 0) {
			/* begin success: */
			foo->successFlag = (integerArgument <= 31) && foo->successFlag;
			shifted = integerReceiver << integerArgument;
			/* begin success: */
			foo->successFlag = ((((usqInt) shifted) >> integerArgument) == integerReceiver) && foo->successFlag;
		} else {
			/* begin success: */
			foo->successFlag = (integerArgument >= -31) && foo->successFlag;
			shifted = ((integerArgument < 0) ? ((usqInt) integerReceiver >> -integerArgument) : ((usqInt) integerReceiver << integerArgument));
		}
	}
	if (foo->successFlag) {
		/* begin push: */
		object = positive32BitIntegerFor(shifted);
		longAtput(sp = foo->stackPointer + (BYTES_PER_WORD), object);
		foo->stackPointer = sp;
	} else {
		/* begin unPop: */
		foo->stackPointer += 2 * (BYTES_PER_WORD);
	}
}


/*	Primitive logical operations for large integers in 64 bit range */

EXPORT(sqInt) primitiveBitShiftLargeIntegers(void) {
register struct foo * foo = &fum;
    sqLong integerArg;
    sqLong integerRcvr;
    sqInt oopResult;
    sqLong shifted;
    sqInt sp;
    sqInt integerPointer;

	/* begin stackIntegerValue: */
	integerPointer = longAt(foo->stackPointer - (0 * (BYTES_PER_WORD)));
	/* begin checkedIntegerValueOf: */
	if ((integerPointer & 1)) {
		integerArg = (integerPointer >> 1);
		goto l1;
	} else {
		/* begin primitiveFail */
		foo->successFlag = 0;
		integerArg = 0;
		goto l1;
	}
	integerArg = null;
l1:	/* end stackIntegerValue: */;
	integerRcvr = signed64BitValueOf(longAt(foo->stackPointer - (1 * (BYTES_PER_WORD))));
	if (foo->successFlag) {
		if (integerArg >= 0) {
			/* begin success: */
			foo->successFlag = (integerArg < 64) && foo->successFlag;
			shifted = integerRcvr << integerArg;
			/* begin success: */
			foo->successFlag = ((shifted >> integerArg) == integerRcvr) && foo->successFlag;
		} else {
			/* begin success: */
			foo->successFlag = (integerArg > -64) && foo->successFlag;
			shifted = integerRcvr >> (0 - integerArg);
		}
	}
	if (!(foo->successFlag)) {
		return null;
	}
	oopResult = signed64BitIntegerFor(shifted);
	if (foo->successFlag) {
		/* begin pop:thenPush: */
		longAtput(sp = foo->stackPointer - ((2 - 1) * (BYTES_PER_WORD)), oopResult);
		foo->stackPointer = sp;
	}
}

sqInt primitiveBitXor(void) {
register struct foo * foo = &fum;
    sqInt integerArgument;
    sqInt integerReceiver;
    sqInt top;
    sqInt top1;
    sqInt object;
    sqInt sp;
    sqInt top2;
    sqInt top3;

	/* begin popPos32BitInteger */
	/* begin popStack */
	top2 = longAt(foo->stackPointer);
	foo->stackPointer -= BYTES_PER_WORD;
	top = top2;
	integerArgument = positive32BitValueOf(top);
	/* begin popPos32BitInteger */
	/* begin popStack */
	top3 = longAt(foo->stackPointer);
	foo->stackPointer -= BYTES_PER_WORD;
	top1 = top3;
	integerReceiver = positive32BitValueOf(top1);
	if (foo->successFlag) {
		/* begin push: */
		object = positive32BitIntegerFor(integerReceiver ^ integerArgument);
		longAtput(sp = foo->stackPointer + (BYTES_PER_WORD), object);
		foo->stackPointer = sp;
	} else {
		/* begin unPop: */
		foo->stackPointer += 2 * (BYTES_PER_WORD);
	}
}


/*	Primitive logical operations for large integers in 64 bit range */

EXPORT(sqInt) primitiveBitXorLargeIntegers(void) {
register struct foo * foo = &fum;
    sqLong integerArg;
    sqLong integerRcvr;
    sqInt oopResult;
    sqInt sp;

	integerArg = positive64BitValueOf(longAt(foo->stackPointer - (0 * (BYTES_PER_WORD))));
	integerRcvr = positive64BitValueOf(longAt(foo->stackPointer - (1 * (BYTES_PER_WORD))));
	if (!(foo->successFlag)) {
		return null;
	}
	oopResult = positive64BitIntegerFor(integerRcvr ^ integerArg);
	if (foo->successFlag) {
		/* begin pop:thenPush: */
		longAtput(sp = foo->stackPointer - ((2 - 1) * (BYTES_PER_WORD)), oopResult);
		foo->stackPointer = sp;
	}
}

sqInt primitiveBlockCopy(void) {
register struct foo * foo = &fum;
    sqInt context;
    sqInt contextSize;
    sqInt initialIP;
    sqInt methodContext;
    sqInt newContext;
    sqInt header;
    sqInt oop;
    sqInt valuePointer;
    sqInt valuePointer1;
    sqInt sp;

	context = longAt(foo->stackPointer - (1 * (BYTES_PER_WORD)));
	if (((longAt((context + (BASE_HEADER_SIZE)) + (MethodIndex << (SHIFT_FOR_WORD)))) & 1)) {

		/* context is a block; get the context of its enclosing method */

		methodContext = longAt((context + (BASE_HEADER_SIZE)) + (HomeIndex << (SHIFT_FOR_WORD)));
	} else {
		methodContext = context;
	}
	/* begin sizeBitsOf: */
	header = longAt(methodContext);
	if ((header & TypeMask) == HeaderTypeSizeAndClass) {
		contextSize = (longAt(methodContext - ((BYTES_PER_WORD) * 2))) & (LONG_SIZE_MASK);
		goto l1;
	} else {
		contextSize = header & (SIZE_MASK);
		goto l1;
	}
l1:	/* end sizeBitsOf: */;

	/* context is no longer needed and is not preserved across allocation */
	/* remap methodContext in case GC happens during allocation */

	context = null;
	/* begin pushRemappableOop: */
	foo->remapBuffer[(foo->remapBufferCount += 1)] = methodContext;
	newContext = instantiateContextsizeInBytes(fetchPointerofObject(ClassBlockContext, foo->specialObjectsOop), contextSize);
	/* begin popRemappableOop */
	oop = foo->remapBuffer[foo->remapBufferCount];
	foo->remapBufferCount -= 1;
	methodContext = oop;

	/* Was instructionPointer + 3, but now it's greater by 1 due to preIncrement */
	/* Assume: have just allocated a new context; it must be young.
	 Thus, can use uncheck stores. See the comment in fetchContextRegisters. */

	initialIP = (((((foo->instructionPointer + 1) + 3) - (foo->method + (BASE_HEADER_SIZE))) << 1) | 1);
	longAtput((newContext + (BASE_HEADER_SIZE)) + (InitialIPIndex << (SHIFT_FOR_WORD)), initialIP);
	longAtput((newContext + (BASE_HEADER_SIZE)) + (InstructionPointerIndex << (SHIFT_FOR_WORD)), initialIP);
	/* begin storeStackPointerValue:inContext: */
	longAtput((newContext + (BASE_HEADER_SIZE)) + (StackPointerIndex << (SHIFT_FOR_WORD)), ((0 << 1) | 1));
	/* begin storePointerUnchecked:ofObject:withValue: */
	valuePointer = longAt(foo->stackPointer - (0 * (BYTES_PER_WORD)));
	longAtput((newContext + (BASE_HEADER_SIZE)) + (BlockArgumentCountIndex << (SHIFT_FOR_WORD)), valuePointer);
	longAtput((newContext + (BASE_HEADER_SIZE)) + (HomeIndex << (SHIFT_FOR_WORD)), methodContext);
	/* begin storePointerUnchecked:ofObject:withValue: */
	valuePointer1 = foo->nilObj;
	longAtput((newContext + (BASE_HEADER_SIZE)) + (SenderIndex << (SHIFT_FOR_WORD)), valuePointer1);
	/* begin pop:thenPush: */
	longAtput(sp = foo->stackPointer - ((2 - 1) * (BYTES_PER_WORD)), newContext);
	foo->stackPointer = sp;
}


/*	Reports bytes available at this moment. For more meaningful 
	results, calls to this primitive should be preceeded by a full 
	or incremental garbage collection. */

sqInt primitiveBytesLeft(void) {
register struct foo * foo = &fum;
    sqInt aBool;
    sqInt oop;
    sqInt sp;
    sqInt oop1;
    sqInt sp1;

	if (foo->argumentCount == 0) {
		/* begin pop:thenPush: */
		oop = positive64BitIntegerFor((longAt(foo->freeBlock)) & (ALL_BUT_TYPE_MASK));
		longAtput(sp = foo->stackPointer - ((1 - 1) * (BYTES_PER_WORD)), oop);
		foo->stackPointer = sp;
		return null;
	}
	if (foo->argumentCount == 1) {
		/* begin booleanValueOf: */
		if ((longAt(foo->stackPointer)) == foo->trueObj) {
			aBool = 1;
			goto l1;
		}
		if ((longAt(foo->stackPointer)) == foo->falseObj) {
			aBool = 0;
			goto l1;
		}
		foo->successFlag = 0;
		aBool = null;
	l1:	/* end booleanValueOf: */;
		if (!(foo->successFlag)) {
			return null;
		}
		/* begin pop:thenPush: */
		oop1 = positive64BitIntegerFor(((longAt(foo->freeBlock)) & (ALL_BUT_TYPE_MASK)) + (sqMemoryExtraBytesLeft(aBool)));
		longAtput(sp1 = foo->stackPointer - ((2 - 1) * (BYTES_PER_WORD)), oop1);
		foo->stackPointer = sp1;
		return null;
	}
	/* begin primitiveFail */
	foo->successFlag = 0;
	return null;
}


/*	Perform a function call to a foreign function.
	Only invoked from method containing explicit external call spec.
	Due to this we use the pluggable prim mechanism explicitly here
	(the first literal of any FFI spec'ed method is an ExternalFunction
	and not an array as used in the pluggable primitive mechanism). */

sqInt primitiveCalloutToFFI(void) {
    static void *function = 0;
    static char *functionName = "primitiveCallout";
    static char *moduleName = "SqueakFFIPrims";

	if (function == 0) {
		function = ioLoadExternalFunctionOfLengthFromModuleOfLength(oopForPointer(functionName), 16, oopForPointer(moduleName), 14);
		if (function == 0) {
			/* begin primitiveFail */
			foo->successFlag = 0;
			return null;
		}
	}
	return ((sqInt (*)(void))function)();
}


/*	Primitive. Change the class of the receiver into the class of the argument given that the format of the receiver matches the format of the argument's class. Fail if receiver or argument are SmallIntegers, or the receiver is an instance of a compact class and the argument isn't, or when the argument's class is compact and the receiver isn't, or when the format of the receiver is different from the format of the argument's class, or when the arguments class is fixed and the receiver's size differs from the size that an instance of the argument's class should have. */

sqInt primitiveChangeClass(void) {
register struct foo * foo = &fum;
    sqInt arg;
    sqInt argClass;
    sqInt rcvr;
    sqInt ccIndex;
    sqInt oop;
    sqInt oop1;
    sqInt oop2;
    sqInt oop3;
    sqInt oop4;

	if (!(foo->argumentCount == 1)) {
		/* begin primitiveFail */
		foo->successFlag = 0;
		return null;
	}
	/* begin stackObjectValue: */
	oop2 = longAt(foo->stackPointer - (0 * (BYTES_PER_WORD)));
	if ((oop2 & 1)) {
		/* begin primitiveFail */
		foo->successFlag = 0;
		arg = null;
		goto l2;
	}
	arg = oop2;
l2:	/* end stackObjectValue: */;
	/* begin stackObjectValue: */
	oop3 = longAt(foo->stackPointer - (1 * (BYTES_PER_WORD)));
	if ((oop3 & 1)) {
		/* begin primitiveFail */
		foo->successFlag = 0;
		rcvr = null;
		goto l3;
	}
	rcvr = oop3;
l3:	/* end stackObjectValue: */;
	/* begin fetchClassOf: */
	if ((arg & 1)) {
		/* begin fetchPointer:ofObject: */
		oop = foo->specialObjectsOop;
		argClass = longAt((oop + (BASE_HEADER_SIZE)) + (ClassInteger << (SHIFT_FOR_WORD)));
		goto l1;
	}
	ccIndex = (((usqInt) (longAt(arg))) >> 12) & 31;
	if (ccIndex == 0) {
		argClass = (longAt(arg - (BASE_HEADER_SIZE))) & (ALL_BUT_TYPE_MASK);
		goto l1;
	} else {
		/* begin fetchPointer:ofObject: */
		/* begin fetchPointer:ofObject: */
		oop4 = foo->specialObjectsOop;
		oop1 = longAt((oop4 + (BASE_HEADER_SIZE)) + (CompactClasses << (SHIFT_FOR_WORD)));
		argClass = longAt((oop1 + (BASE_HEADER_SIZE)) + ((ccIndex - 1) << (SHIFT_FOR_WORD)));
		goto l1;
	}
l1:	/* end fetchClassOf: */;
	changeClassOfto(rcvr, argClass);
	if (foo->successFlag) {
		/* begin pop: */
		foo->stackPointer -= 1 * (BYTES_PER_WORD);
	}
	return null;
}


/*	Primitive. Change the class of the receiver into the class of the argument given that the format of the receiver matches the format of the argument's class. Fail if receiver or argument are SmallIntegers, or the receiver is an instance of a compact class and the argument isn't, or when the argument's class is compact and the receiver isn't, or when the format of the receiver is different from the format of the argument's class, or when the arguments class is fixed and the receiver's size differs from the size that an instance of the argument's class should have. */

EXPORT(sqInt) primitiveChangeClassWithClass(void) {
register struct foo * foo = &fum;
    sqInt argClass;
    sqInt rcvr;
    sqInt oop;
    sqInt oop1;

	if (!(foo->argumentCount == 1)) {
		/* begin primitiveFail */
		foo->successFlag = 0;
		return null;
	}
	/* begin stackObjectValue: */
	oop = longAt(foo->stackPointer - (0 * (BYTES_PER_WORD)));
	if ((oop & 1)) {
		/* begin primitiveFail */
		foo->successFlag = 0;
		argClass = null;
		goto l1;
	}
	argClass = oop;
l1:	/* end stackObjectValue: */;
	/* begin stackObjectValue: */
	oop1 = longAt(foo->stackPointer - (1 * (BYTES_PER_WORD)));
	if ((oop1 & 1)) {
		/* begin primitiveFail */
		foo->successFlag = 0;
		rcvr = null;
		goto l2;
	}
	rcvr = oop1;
l2:	/* end stackObjectValue: */;
	changeClassOfto(rcvr, argClass);
	if (foo->successFlag) {
		/* begin pop: */
		foo->stackPointer -= 1 * (BYTES_PER_WORD);
	}
	return null;
}

sqInt primitiveClass(void) {
register struct foo * foo = &fum;
    sqInt instance;
    sqInt oop;
    sqInt sp;
    sqInt ccIndex;
    sqInt oop1;
    sqInt oop2;
    sqInt oop3;

	instance = longAt(foo->stackPointer);
	/* begin pop:thenPush: */
	/* begin fetchClassOf: */
	if ((instance & 1)) {
		/* begin fetchPointer:ofObject: */
		oop1 = foo->specialObjectsOop;
		oop = longAt((oop1 + (BASE_HEADER_SIZE)) + (ClassInteger << (SHIFT_FOR_WORD)));
		goto l1;
	}
	ccIndex = (((usqInt) (longAt(instance))) >> 12) & 31;
	if (ccIndex == 0) {
		oop = (longAt(instance - (BASE_HEADER_SIZE))) & (ALL_BUT_TYPE_MASK);
		goto l1;
	} else {
		/* begin fetchPointer:ofObject: */
		/* begin fetchPointer:ofObject: */
		oop3 = foo->specialObjectsOop;
		oop2 = longAt((oop3 + (BASE_HEADER_SIZE)) + (CompactClasses << (SHIFT_FOR_WORD)));
		oop = longAt((oop2 + (BASE_HEADER_SIZE)) + ((ccIndex - 1) << (SHIFT_FOR_WORD)));
		goto l1;
	}
l1:	/* end fetchClassOf: */;
	longAtput(sp = foo->stackPointer - (((foo->argumentCount + 1) - 1) * (BYTES_PER_WORD)), oop);
	foo->stackPointer = sp;
}


/*	When called with a single string argument, post the string to 
	the clipboard. When called with zero arguments, return a 
	string containing the current clipboard contents. */

sqInt primitiveClipboardText(void) {
register struct foo * foo = &fum;
    sqInt s;
    sqInt sz;
    sqInt sp;

	if (foo->argumentCount == 1) {
		s = longAt(foo->stackPointer);
		if (!(((s & 1) == 0) && (((((usqInt) (longAt(s))) >> 8) & 15) >= 8))) {
			/* begin primitiveFail */
			foo->successFlag = 0;
			return null;
		}
		if (foo->successFlag) {
			sz = stSizeOf(s);
			clipboardWriteFromAt(sz, s + (BASE_HEADER_SIZE), 0);
			/* begin pop: */
			foo->stackPointer -= 1 * (BYTES_PER_WORD);
		}
	} else {
		sz = clipboardSize();
		if (!(sufficientSpaceToAllocate(sz))) {
			/* begin primitiveFail */
			foo->successFlag = 0;
			return null;
		}
		s = instantiateClassindexableSize(fetchPointerofObject(ClassString, foo->specialObjectsOop), sz);
		clipboardReadIntoAt(sz, s + (BASE_HEADER_SIZE), 0);
		/* begin pop:thenPush: */
		longAtput(sp = foo->stackPointer - ((1 - 1) * (BYTES_PER_WORD)), s);
		foo->stackPointer = sp;
	}
}


/*	Return a shallow copy of the receiver. */

sqInt primitiveClone(void) {
register struct foo * foo = &fum;
    sqInt newCopy;
    sqInt sp;

	newCopy = clone(longAt(foo->stackPointer));
	if (newCopy == 0) {
		/* begin primitiveFail */
		foo->successFlag = 0;
		return null;
	}
	/* begin pop:thenPush: */
	longAtput(sp = foo->stackPointer - ((1 - 1) * (BYTES_PER_WORD)), newCopy);
	foo->stackPointer = sp;
}

sqInt primitiveClosureCopyWithCopiedValues(void) {
register struct foo * foo = &fum;
    sqInt copiedValues;
    sqInt i;
    sqInt newClosure;
    sqInt numArgs;
    sqInt numCopiedValues;
    sqInt successValue;
    sqInt sz;
    sqInt sp;
    sqInt valuePointer;
    sqInt header;
    sqInt initialIP;
    sqInt newClosure1;
    sqInt valuePointer1;
    sqInt integerPointer;

	/* begin stackIntegerValue: */
	integerPointer = longAt(foo->stackPointer - (1 * (BYTES_PER_WORD)));
	/* begin checkedIntegerValueOf: */
	if ((integerPointer & 1)) {
		numArgs = (integerPointer >> 1);
		goto l2;
	} else {
		/* begin primitiveFail */
		foo->successFlag = 0;
		numArgs = 0;
		goto l2;
	}
	numArgs = null;
l2:	/* end stackIntegerValue: */;
	copiedValues = longAt(foo->stackPointer);
	/* begin success: */
	successValue = (fetchClassOf(copiedValues)) == (fetchPointerofObject(ClassArray, foo->specialObjectsOop));
	foo->successFlag = successValue && foo->successFlag;
	if (!(foo->successFlag)) {
		/* begin primitiveFail */
		foo->successFlag = 0;
		return null;
	}
	/* begin fetchWordLengthOf: */
	/* begin sizeBitsOf: */
	header = longAt(copiedValues);
	if ((header & TypeMask) == HeaderTypeSizeAndClass) {
		sz = (longAt(copiedValues - ((BYTES_PER_WORD) * 2))) & (LONG_SIZE_MASK);
		goto l1;
	} else {
		sz = header & (SIZE_MASK);
		goto l1;
	}
l1:	/* end sizeBitsOf: */;
	numCopiedValues = ((usqInt) (sz - (BASE_HEADER_SIZE))) >> (SHIFT_FOR_WORD);
	/* begin closureNumArgs:instructionPointer:numCopiedValues: */
	initialIP = (foo->instructionPointer + 2) - (foo->method + (BASE_HEADER_SIZE));
	newClosure1 = instantiateSmallClasssizeInBytes(fetchPointerofObject(ClassBlockClosure, foo->specialObjectsOop), ((BYTES_PER_WORD) * (ClosureFirstCopiedValueIndex + numCopiedValues)) + (BASE_HEADER_SIZE));
	longAtput((newClosure1 + (BASE_HEADER_SIZE)) + (ClosureStartPCIndex << (SHIFT_FOR_WORD)), ((initialIP << 1) | 1));
	longAtput((newClosure1 + (BASE_HEADER_SIZE)) + (ClosureNumArgsIndex << (SHIFT_FOR_WORD)), ((numArgs << 1) | 1));
	newClosure = newClosure1;
	/* begin storePointerUnchecked:ofObject:withValue: */
	valuePointer1 = longAt(foo->stackPointer - (2 * (BYTES_PER_WORD)));
	longAtput((newClosure + (BASE_HEADER_SIZE)) + (ClosureOuterContextIndex << (SHIFT_FOR_WORD)), valuePointer1);
	if (numCopiedValues > 0) {

		/* Allocation may have done a GC and copiedValues may have moved. */

		copiedValues = longAt(foo->stackPointer);
		for (i = 0; i <= (numCopiedValues - 1); i += 1) {
			/* begin storePointerUnchecked:ofObject:withValue: */
			valuePointer = longAt((copiedValues + (BASE_HEADER_SIZE)) + (i << (SHIFT_FOR_WORD)));
			longAtput((newClosure + (BASE_HEADER_SIZE)) + ((i + ClosureFirstCopiedValueIndex) << (SHIFT_FOR_WORD)), valuePointer);
		}
	}
	/* begin pop:thenPush: */
	longAtput(sp = foo->stackPointer - ((3 - 1) * (BYTES_PER_WORD)), newClosure);
	foo->stackPointer = sp;
}

sqInt primitiveClosureValue(void) {
register struct foo * foo = &fum;
    sqInt blockArgumentCount;
    sqInt blockClosure;
    sqInt closureMethod;
    sqInt outerContext;

	blockClosure = longAt(foo->stackPointer - (foo->argumentCount * (BYTES_PER_WORD)));
	blockArgumentCount = ((longAt((blockClosure + (BASE_HEADER_SIZE)) + (ClosureNumArgsIndex << (SHIFT_FOR_WORD)))) >> 1);
	if (!(foo->argumentCount == blockArgumentCount)) {
		/* begin primitiveFail */
		foo->successFlag = 0;
		return null;
	}
	outerContext = longAt((blockClosure + (BASE_HEADER_SIZE)) + (ClosureOuterContextIndex << (SHIFT_FOR_WORD)));
	if (!(((outerContext & 1) == 0) && ((((((usqInt) (longAt(outerContext))) >> 12) & 31) == 13) || ((((((usqInt) (longAt(outerContext))) >> 12) & 31) == 14) || (((((usqInt) (longAt(outerContext))) >> 12) & 31) == 4))))) {
		/* begin primitiveFail */
		foo->successFlag = 0;
		return null;
	}

	/* Check if the closure's method is actually a CompiledMethod. */

	closureMethod = longAt((outerContext + (BASE_HEADER_SIZE)) + (MethodIndex << (SHIFT_FOR_WORD)));
	if (!(((closureMethod & 1) == 0) && (((((usqInt) (longAt(closureMethod))) >> 8) & 15) >= 12))) {
		/* begin primitiveFail */
		foo->successFlag = 0;
		return null;
	}
	activateNewClosureMethod(blockClosure);
	/* begin quickCheckForInterrupts */
	if ((foo->interruptCheckCounter -= 1) <= 0) {
		checkForInterrupts();
	}
}


/*	An exact clone of primitiveClosureValue except that this version will not
	 check for interrupts on stack overflow. */

sqInt primitiveClosureValueNoContextSwitch(void) {
register struct foo * foo = &fum;
    sqInt blockArgumentCount;
    sqInt blockClosure;
    sqInt closureMethod;
    sqInt outerContext;

	blockClosure = longAt(foo->stackPointer - (foo->argumentCount * (BYTES_PER_WORD)));
	blockArgumentCount = ((longAt((blockClosure + (BASE_HEADER_SIZE)) + (ClosureNumArgsIndex << (SHIFT_FOR_WORD)))) >> 1);
	if (!(foo->argumentCount == blockArgumentCount)) {
		/* begin primitiveFail */
		foo->successFlag = 0;
		return null;
	}
	outerContext = longAt((blockClosure + (BASE_HEADER_SIZE)) + (ClosureOuterContextIndex << (SHIFT_FOR_WORD)));
	if (!(((outerContext & 1) == 0) && ((((((usqInt) (longAt(outerContext))) >> 12) & 31) == 13) || ((((((usqInt) (longAt(outerContext))) >> 12) & 31) == 14) || (((((usqInt) (longAt(outerContext))) >> 12) & 31) == 4))))) {
		/* begin primitiveFail */
		foo->successFlag = 0;
		return null;
	}

	/* Check if the closure's method is actually a CompiledMethod. */

	closureMethod = longAt((outerContext + (BASE_HEADER_SIZE)) + (MethodIndex << (SHIFT_FOR_WORD)));
	if (!(((closureMethod & 1) == 0) && (((((usqInt) (longAt(closureMethod))) >> 8) & 15) >= 12))) {
		/* begin primitiveFail */
		foo->successFlag = 0;
		return null;
	}
	activateNewClosureMethod(blockClosure);
}

sqInt primitiveClosureValueWithArgs(void) {
register struct foo * foo = &fum;
    sqInt argumentArray;
    sqInt arraySize;
    sqInt blockArgumentCount;
    sqInt blockClosure;
    sqInt closureMethod;
    sqInt cntxSize;
    sqInt index;
    sqInt outerContext;
    sqInt object;
    sqInt sp;
    sqInt sz;
    sqInt header;
    sqInt objectPointer;
    sqInt sz1;
    sqInt header1;
    sqInt top;

	argumentArray = longAt(foo->stackPointer);
	if (!(((argumentArray & 1) == 0) && (((((usqInt) (longAt(argumentArray))) >> 8) & 15) == 2))) {
		/* begin primitiveFail */
		foo->successFlag = 0;
		return null;
	}
	/* begin fetchWordLengthOf: */
	/* begin sizeBitsOf: */
	header = longAt(argumentArray);
	if ((header & TypeMask) == HeaderTypeSizeAndClass) {
		sz = (longAt(argumentArray - ((BYTES_PER_WORD) * 2))) & (LONG_SIZE_MASK);
		goto l1;
	} else {
		sz = header & (SIZE_MASK);
		goto l1;
	}
l1:	/* end sizeBitsOf: */;
	arraySize = ((usqInt) (sz - (BASE_HEADER_SIZE))) >> (SHIFT_FOR_WORD);
	/* begin fetchWordLengthOf: */
	objectPointer = foo->activeContext;
	/* begin sizeBitsOf: */
	header1 = longAt(objectPointer);
	if ((header1 & TypeMask) == HeaderTypeSizeAndClass) {
		sz1 = (longAt(objectPointer - ((BYTES_PER_WORD) * 2))) & (LONG_SIZE_MASK);
		goto l2;
	} else {
		sz1 = header1 & (SIZE_MASK);
		goto l2;
	}
l2:	/* end sizeBitsOf: */;
	cntxSize = ((usqInt) (sz1 - (BASE_HEADER_SIZE))) >> (SHIFT_FOR_WORD);
	if (!(((((usqInt) ((foo->stackPointer - foo->activeContext) - (BASE_HEADER_SIZE))) >> (SHIFT_FOR_WORD)) + arraySize) < cntxSize)) {
		/* begin primitiveFail */
		foo->successFlag = 0;
		return null;
	}
	blockClosure = longAt(foo->stackPointer - (foo->argumentCount * (BYTES_PER_WORD)));
	blockArgumentCount = ((longAt((blockClosure + (BASE_HEADER_SIZE)) + (ClosureNumArgsIndex << (SHIFT_FOR_WORD)))) >> 1);
	if (!(arraySize == blockArgumentCount)) {
		/* begin primitiveFail */
		foo->successFlag = 0;
		return null;
	}
	outerContext = longAt((blockClosure + (BASE_HEADER_SIZE)) + (ClosureOuterContextIndex << (SHIFT_FOR_WORD)));
	if (!(((outerContext & 1) == 0) && ((((((usqInt) (longAt(outerContext))) >> 12) & 31) == 13) || ((((((usqInt) (longAt(outerContext))) >> 12) & 31) == 14) || (((((usqInt) (longAt(outerContext))) >> 12) & 31) == 4))))) {
		/* begin primitiveFail */
		foo->successFlag = 0;
		return null;
	}

	/* Check if the closure's method is actually a CompiledMethod. */

	closureMethod = longAt((outerContext + (BASE_HEADER_SIZE)) + (MethodIndex << (SHIFT_FOR_WORD)));
	if (!(((closureMethod & 1) == 0) && (((((usqInt) (longAt(closureMethod))) >> 8) & 15) >= 12))) {
		/* begin primitiveFail */
		foo->successFlag = 0;
		return null;
	}
	/* begin popStack */
	top = longAt(foo->stackPointer);
	foo->stackPointer -= BYTES_PER_WORD;
	index = 1;
	while (index <= arraySize) {
		/* begin push: */
		object = longAt((argumentArray + (BASE_HEADER_SIZE)) + ((index - 1) << (SHIFT_FOR_WORD)));
		longAtput(sp = foo->stackPointer + (BYTES_PER_WORD), object);
		foo->stackPointer = sp;
		index += 1;
	}
	foo->argumentCount = arraySize;
	activateNewClosureMethod(blockClosure);
	/* begin quickCheckForInterrupts */
	if ((foo->interruptCheckCounter -= 1) <= 0) {
		checkForInterrupts();
	}
}


/*	Fill the receiver, which must be an indexable bytes or words 
	objects, with the given integer value. */

sqInt primitiveConstantFill(void) {
register struct foo * foo = &fum;
    usqInt end;
    sqInt fillValue;
    usqInt i;
    sqInt rcvr;
    sqInt rcvrIsBytes;
    sqInt successValue;
    sqInt successValue1;

	fillValue = positive32BitValueOf(longAt(foo->stackPointer));
	rcvr = longAt(foo->stackPointer - (1 * (BYTES_PER_WORD)));
	/* begin success: */
	successValue1 = ((rcvr & 1) == 0) && (isWordsOrBytesNonInt(rcvr));
	foo->successFlag = successValue1 && foo->successFlag;
	rcvrIsBytes = ((rcvr & 1) == 0) && (((((usqInt) (longAt(rcvr))) >> 8) & 15) >= 8);
	if (rcvrIsBytes) {
		/* begin success: */
		successValue = (fillValue >= 0) && (fillValue <= 255);
		foo->successFlag = successValue && foo->successFlag;
	}
	if (foo->successFlag) {
		end = rcvr + (sizeBitsOf(rcvr));
		i = rcvr + (BASE_HEADER_SIZE);
		if (rcvrIsBytes) {
			while (i < end) {
				byteAtput(i, fillValue);
				i += 1;
			}
		} else {
			while (i < end) {
				long32Atput(i, fillValue);
				i += 4;
			}
		}
		/* begin pop: */
		foo->stackPointer -= 1 * (BYTES_PER_WORD);
	}
}


/*	Primitive. Copy the state of the receiver from the argument. 
		Fail if receiver and argument are of a different class. 
		Fail if the receiver or argument are non-pointer objects.
		Fail if receiver and argument have different lengths (for indexable objects).
	 */

sqInt primitiveCopyObject(void) {
register struct foo * foo = &fum;
    sqInt arg;
    sqInt i;
    sqInt length;
    sqInt rcvr;
    sqInt header;
    sqInt valuePointer;
    sqInt oop;
    sqInt oop1;
    sqInt sz;

	if (!(foo->argumentCount == 1)) {
		/* begin primitiveFail */
		foo->successFlag = 0;
		return null;
	}
	/* begin stackObjectValue: */
	oop = longAt(foo->stackPointer - (0 * (BYTES_PER_WORD)));
	if ((oop & 1)) {
		/* begin primitiveFail */
		foo->successFlag = 0;
		arg = null;
		goto l1;
	}
	arg = oop;
l1:	/* end stackObjectValue: */;
	/* begin stackObjectValue: */
	oop1 = longAt(foo->stackPointer - (1 * (BYTES_PER_WORD)));
	if ((oop1 & 1)) {
		/* begin primitiveFail */
		foo->successFlag = 0;
		rcvr = null;
		goto l2;
	}
	rcvr = oop1;
l2:	/* end stackObjectValue: */;
	if (!foo->successFlag) {
		return null;
	}
	if (!(((rcvr & 1) == 0) && (((((usqInt) (longAt(rcvr))) >> 8) & 15) <= 4))) {
		/* begin primitiveFail */
		foo->successFlag = 0;
		return null;
	}
	if (!((fetchClassOf(rcvr)) == (fetchClassOf(arg)))) {
		/* begin primitiveFail */
		foo->successFlag = 0;
		return null;
	}
	/* begin lengthOf: */
	header = longAt(rcvr);
	/* begin lengthOf:baseHeader:format: */
	if ((header & TypeMask) == HeaderTypeSizeAndClass) {
		sz = (longAt(rcvr - ((BYTES_PER_WORD) * 2))) & (LONG_SIZE_MASK);
	} else {
		sz = header & (SIZE_MASK);
	}
	sz -= header & (SIZE_4_BIT);
	if (((((usqInt) header) >> 8) & 15) <= 4) {
		length = ((usqInt) (sz - (BASE_HEADER_SIZE))) >> (SHIFT_FOR_WORD);
		goto l3;
	}
	if (((((usqInt) header) >> 8) & 15) < 8) {
		length = ((usqInt) (sz - (BASE_HEADER_SIZE))) >> 2;
		goto l3;
	} else {
		length = (sz - (BASE_HEADER_SIZE)) - (((((usqInt) header) >> 8) & 15) & 3);
		goto l3;
	}
l3:	/* end lengthOf:baseHeader:format: */;
	if (!(length == (lengthOf(arg)))) {
		/* begin primitiveFail */
		foo->successFlag = 0;
		return null;
	}
	for (i = 0; i <= (length - 1); i += 1) {
		/* begin storePointer:ofObject:withValue: */
		valuePointer = longAt((arg + (BASE_HEADER_SIZE)) + (i << (SHIFT_FOR_WORD)));
		if ((((usqInt) rcvr)) < (((usqInt) foo->youngStart))) {
			possibleRootStoreIntovalue(rcvr, valuePointer);
		}
		longAtput((rcvr + (BASE_HEADER_SIZE)) + (i << (SHIFT_FOR_WORD)), valuePointer);
	}
	/* begin pop: */
	foo->stackPointer -= 1 * (BYTES_PER_WORD);
}


/*	Set or clear the flag that controls whether modifications of 
	the Display object are propagated to the underlying 
	platform's screen. */

sqInt primitiveDeferDisplayUpdates(void) {
register struct foo * foo = &fum;
    sqInt flag;

	flag = longAt(foo->stackPointer);
	if (flag == foo->trueObj) {
		foo->deferDisplayUpdates = 1;
	} else {
		if (flag == foo->falseObj) {
			foo->deferDisplayUpdates = 0;
		} else {
			/* begin primitiveFail */
			foo->successFlag = 0;
		}
	}
	if (foo->successFlag) {
		/* begin pop: */
		foo->stackPointer -= 1 * (BYTES_PER_WORD);
	}
}


/*	Pass in a non-negative value to disable the architectures powermanager if any, zero to enable. This is a named (not numbered) primitive in the null module (ie the VM) */

EXPORT(sqInt) primitiveDisablePowerManager(void) {
register struct foo * foo = &fum;
    sqInt integer;
    sqInt integerPointer;

	/* begin stackIntegerValue: */
	integerPointer = longAt(foo->stackPointer - (0 * (BYTES_PER_WORD)));
	/* begin checkedIntegerValueOf: */
	if ((integerPointer & 1)) {
		integer = (integerPointer >> 1);
		goto l1;
	} else {
		/* begin primitiveFail */
		foo->successFlag = 0;
		integer = 0;
		goto l1;
	}
	integer = null;
l1:	/* end stackIntegerValue: */;
	if (foo->successFlag) {
		ioDisablePowerManager(integer);
		/* begin pop: */
		foo->stackPointer -= 1 * (BYTES_PER_WORD);
	}
}

sqInt primitiveDiv(void) {
register struct foo * foo = &fum;
    sqInt quotient;
    sqInt sp;

	quotient = doPrimitiveDivby(longAt(foo->stackPointer - (1 * (BYTES_PER_WORD))), longAt(foo->stackPointer));
	/* begin pop2AndPushIntegerIfOK: */
	if (foo->successFlag) {
		if (
# ifdef SQ_HOST32  // cast to int for 64 bit image on 32 bit host
			(((((int) quotient)) ^ ((((int) quotient)) << 1)) >= 0)
# else
			((quotient >= -1073741824) && (quotient <= 1073741823))
# endif  // SQ_HOST32
		) {
			/* begin pop:thenPush: */
			longAtput(sp = foo->stackPointer - ((2 - 1) * (BYTES_PER_WORD)), ((quotient << 1) | 1));
			foo->stackPointer = sp;
		} else {
			foo->successFlag = 0;
		}
	}
}


/*	Primitive arithmetic operations for large integers in 64 bit range */

EXPORT(sqInt) primitiveDivLargeIntegers(void) {
register struct foo * foo = &fum;
    sqLong integerArg;
    sqLong integerRcvr;
    sqInt oopResult;
    sqLong posArg;
    sqLong posRcvr;
    sqLong result;
    sqInt sp;

	integerArg = signed64BitValueOf(longAt(foo->stackPointer - (0 * (BYTES_PER_WORD))));
	integerRcvr = signed64BitValueOf(longAt(foo->stackPointer - (1 * (BYTES_PER_WORD))));
	if (integerArg == 0) {
		/* begin primitiveFail */
		foo->successFlag = 0;
	}
	if (!(foo->successFlag)) {
		return null;
	}
	if (integerRcvr > 0) {
		if (integerArg > 0) {
			result = integerRcvr / integerArg;
		} else {

			/* round negative result toward negative infinity */

			posArg = 0 - integerArg;

			/* can overflow! */

			posRcvr = integerRcvr + (posArg - 1);
			if (posRcvr < 0) {
				/* begin primitiveFail */
				foo->successFlag = 0;
			}
			result = 0 - (posRcvr / posArg);
		}
	} else {
		posRcvr = 0 - integerRcvr;
		if (integerArg > 0) {

			/* round negative result toward negative infinity */
			/* can overflow! */

			posRcvr += integerArg - 1;
			if (posRcvr < 0) {
				/* begin primitiveFail */
				foo->successFlag = 0;
			}
			result = 0 - (posRcvr / integerArg);
		} else {
			posArg = 0 - integerArg;
			result = posRcvr / posArg;
		}
	}
	if (foo->successFlag) {
		oopResult = signed64BitIntegerFor(result);
	}
	if (foo->successFlag) {
		/* begin pop:thenPush: */
		longAtput(sp = foo->stackPointer - ((2 - 1) * (BYTES_PER_WORD)), oopResult);
		foo->stackPointer = sp;
	}
}

sqInt primitiveDivide(void) {
register struct foo * foo = &fum;
    sqInt integerArgument;
    sqInt integerReceiver;
    sqInt sp;
    sqInt integerPointer;
    sqInt integerPointer1;

	/* begin stackIntegerValue: */
	integerPointer = longAt(foo->stackPointer - (1 * (BYTES_PER_WORD)));
	/* begin checkedIntegerValueOf: */
	if ((integerPointer & 1)) {
		integerReceiver = (integerPointer >> 1);
		goto l1;
	} else {
		/* begin primitiveFail */
		foo->successFlag = 0;
		integerReceiver = 0;
		goto l1;
	}
	integerReceiver = null;
l1:	/* end stackIntegerValue: */;
	/* begin stackIntegerValue: */
	integerPointer1 = longAt(foo->stackPointer - (0 * (BYTES_PER_WORD)));
	/* begin checkedIntegerValueOf: */
	if ((integerPointer1 & 1)) {
		integerArgument = (integerPointer1 >> 1);
		goto l2;
	} else {
		/* begin primitiveFail */
		foo->successFlag = 0;
		integerArgument = 0;
		goto l2;
	}
	integerArgument = null;
l2:	/* end stackIntegerValue: */;
	if ((integerArgument != 0) && ((integerReceiver % integerArgument) == 0)) {
		/* begin pop2AndPushIntegerIfOK: */
		if (foo->successFlag) {
			if (
# ifdef SQ_HOST32  // cast to int for 64 bit image on 32 bit host
				(((((int) (integerReceiver / integerArgument))) ^ ((((int) (integerReceiver / integerArgument))) << 1)) >= 0)
# else
				(((integerReceiver / integerArgument) >= -1073741824) && ((integerReceiver / integerArgument) <= 1073741823))
# endif  // SQ_HOST32
			) {
				/* begin pop:thenPush: */
				longAtput(sp = foo->stackPointer - ((2 - 1) * (BYTES_PER_WORD)), (((integerReceiver / integerArgument) << 1) | 1));
				foo->stackPointer = sp;
			} else {
				foo->successFlag = 0;
			}
		}
	} else {
		/* begin primitiveFail */
		foo->successFlag = 0;
	}
}


/*	Primitive arithmetic operations for large integers in 64 bit range */

EXPORT(sqInt) primitiveDivideLargeIntegers(void) {
register struct foo * foo = &fum;
    sqLong integerArg;
    sqLong integerRcvr;
    sqInt oopResult;
    sqLong result;
    sqInt sp;

	integerArg = signed64BitValueOf(longAt(foo->stackPointer - (0 * (BYTES_PER_WORD))));
	integerRcvr = signed64BitValueOf(longAt(foo->stackPointer - (1 * (BYTES_PER_WORD))));
	if (!((integerArg != 0) && ((integerRcvr % integerArg) == 0))) {
		/* begin primitiveFail */
		foo->successFlag = 0;
	}
	if (!(foo->successFlag)) {
		return null;
	}
	result = integerRcvr / integerArg;
	oopResult = signed64BitIntegerFor(result);
	if (foo->successFlag) {
		/* begin pop:thenPush: */
		longAtput(sp = foo->stackPointer - ((2 - 1) * (BYTES_PER_WORD)), oopResult);
		foo->stackPointer = sp;
	}
}

sqInt primitiveDoPrimitiveWithArgs(void) {
register struct foo * foo = &fum;
    sqInt argumentArray;
    sqInt arraySize;
    sqInt cntxSize;
    sqInt index;
    sqInt primIdx;
    sqInt object;
    sqInt sp;
    sqInt sp1;
    sqInt sp2;
    sqInt sz;
    sqInt header;
    sqInt objectPointer;
    sqInt sz1;
    sqInt header1;
    sqInt successValue;
    sqInt oop;
    sqInt integerPointer;

	argumentArray = longAt(foo->stackPointer);
	/* begin fetchWordLengthOf: */
	/* begin sizeBitsOf: */
	header = longAt(argumentArray);
	if ((header & TypeMask) == HeaderTypeSizeAndClass) {
		sz = (longAt(argumentArray - ((BYTES_PER_WORD) * 2))) & (LONG_SIZE_MASK);
		goto l1;
	} else {
		sz = header & (SIZE_MASK);
		goto l1;
	}
l1:	/* end sizeBitsOf: */;
	arraySize = ((usqInt) (sz - (BASE_HEADER_SIZE))) >> (SHIFT_FOR_WORD);
	/* begin fetchWordLengthOf: */
	objectPointer = foo->activeContext;
	/* begin sizeBitsOf: */
	header1 = longAt(objectPointer);
	if ((header1 & TypeMask) == HeaderTypeSizeAndClass) {
		sz1 = (longAt(objectPointer - ((BYTES_PER_WORD) * 2))) & (LONG_SIZE_MASK);
		goto l2;
	} else {
		sz1 = header1 & (SIZE_MASK);
		goto l2;
	}
l2:	/* end sizeBitsOf: */;
	cntxSize = ((usqInt) (sz1 - (BASE_HEADER_SIZE))) >> (SHIFT_FOR_WORD);
	/* begin success: */
	successValue = ((((usqInt) ((foo->stackPointer - foo->activeContext) - (BASE_HEADER_SIZE))) >> (SHIFT_FOR_WORD)) + arraySize) < cntxSize;
	foo->successFlag = successValue && foo->successFlag;
	if (!(((argumentArray & 1) == 0) && (((((usqInt) (longAt(argumentArray))) >> 8) & 15) == 2))) {
		/* begin primitiveFail */
		foo->successFlag = 0;
		return null;
	}
	/* begin stackIntegerValue: */
	integerPointer = longAt(foo->stackPointer - (1 * (BYTES_PER_WORD)));
	/* begin checkedIntegerValueOf: */
	if ((integerPointer & 1)) {
		primIdx = (integerPointer >> 1);
		goto l3;
	} else {
		/* begin primitiveFail */
		foo->successFlag = 0;
		primIdx = 0;
		goto l3;
	}
	primIdx = null;
l3:	/* end stackIntegerValue: */;
	if (!(foo->successFlag)) {
		/* begin primitiveFail */
		foo->successFlag = 0;
		return null;
	}
	/* begin pop: */
	foo->stackPointer -= 2 * (BYTES_PER_WORD);
	foo->primitiveIndex = primIdx;
	foo->argumentCount = arraySize;
	index = 1;
	while (index <= foo->argumentCount) {
		/* begin push: */
		object = longAt((argumentArray + (BASE_HEADER_SIZE)) + ((index - 1) << (SHIFT_FOR_WORD)));
		longAtput(sp = foo->stackPointer + (BYTES_PER_WORD), object);
		foo->stackPointer = sp;
		index += 1;
	}
	/* begin pushRemappableOop: */
	foo->remapBuffer[(foo->remapBufferCount += 1)] = argumentArray;
	foo->lkupClass = foo->nilObj;
	primitiveResponse();
	/* begin popRemappableOop */
	oop = foo->remapBuffer[foo->remapBufferCount];
	foo->remapBufferCount -= 1;
	argumentArray = oop;
	if (!(foo->successFlag)) {
		/* begin pop: */
		foo->stackPointer -= arraySize * (BYTES_PER_WORD);
		/* begin pushInteger: */
		/* begin push: */
		longAtput(sp1 = foo->stackPointer + (BYTES_PER_WORD), ((primIdx << 1) | 1));
		foo->stackPointer = sp1;
		/* begin push: */
		longAtput(sp2 = foo->stackPointer + (BYTES_PER_WORD), argumentArray);
		foo->stackPointer = sp2;
		foo->argumentCount = 2;
	}
}

sqInt primitiveEqual(void) {
register struct foo * foo = &fum;
    sqInt integerArgument;
    sqInt integerReceiver;
    sqInt result;
    sqInt top;
    sqInt top1;
    sqInt sp;
    sqInt sp1;

	/* begin popStack */
	top = longAt(foo->stackPointer);
	foo->stackPointer -= BYTES_PER_WORD;
	integerArgument = top;
	/* begin popStack */
	top1 = longAt(foo->stackPointer);
	foo->stackPointer -= BYTES_PER_WORD;
	integerReceiver = top1;
	/* begin compare31or32Bits:equal: */
	if (((integerReceiver & 1)) && ((integerArgument & 1))) {
		result = integerReceiver == integerArgument;
		goto l1;
	}
	result = (positive32BitValueOf(integerReceiver)) == (positive32BitValueOf(integerArgument));
l1:	/* end compare31or32Bits:equal: */;
	/* begin checkBooleanResult: */
	if (foo->successFlag) {
		/* begin pushBool: */
		if (result) {
			/* begin push: */
			longAtput(sp = foo->stackPointer + (BYTES_PER_WORD), foo->trueObj);
			foo->stackPointer = sp;
		} else {
			/* begin push: */
			longAtput(sp1 = foo->stackPointer + (BYTES_PER_WORD), foo->falseObj);
			foo->stackPointer = sp1;
		}
	} else {
		/* begin unPop: */
		foo->stackPointer += 2 * (BYTES_PER_WORD);
	}
}


/*	Primitive comparison operations for large integers in 64 bit range */

EXPORT(sqInt) primitiveEqualLargeIntegers(void) {
register struct foo * foo = &fum;
    sqLong integerArg;
    sqLong integerRcvr;
    sqInt sp;
    sqInt sp1;

	integerArg = signed64BitValueOf(longAt(foo->stackPointer - (0 * (BYTES_PER_WORD))));
	integerRcvr = signed64BitValueOf(longAt(foo->stackPointer - (1 * (BYTES_PER_WORD))));
	if (foo->successFlag) {
		/* begin pop: */
		foo->stackPointer -= 2 * (BYTES_PER_WORD);
		/* begin pushBool: */
		if (integerRcvr == integerArg) {
			/* begin push: */
			longAtput(sp = foo->stackPointer + (BYTES_PER_WORD), foo->trueObj);
			foo->stackPointer = sp;
		} else {
			/* begin push: */
			longAtput(sp1 = foo->stackPointer + (BYTES_PER_WORD), foo->falseObj);
			foo->stackPointer = sp1;
		}
	}
}


/*	is the receiver the same object as the argument? */

sqInt primitiveEquivalent(void) {
register struct foo * foo = &fum;
    sqInt otherObject;
    sqInt thisObject;
    sqInt top;
    sqInt top1;
    sqInt sp;
    sqInt sp1;

	/* begin popStack */
	top = longAt(foo->stackPointer);
	foo->stackPointer -= BYTES_PER_WORD;
	otherObject = top;
	/* begin popStack */
	top1 = longAt(foo->stackPointer);
	foo->stackPointer -= BYTES_PER_WORD;
	thisObject = top1;
	/* begin pushBool: */
	if (thisObject == otherObject) {
		/* begin push: */
		longAtput(sp = foo->stackPointer + (BYTES_PER_WORD), foo->trueObj);
		foo->stackPointer = sp;
	} else {
		/* begin push: */
		longAtput(sp1 = foo->stackPointer + (BYTES_PER_WORD), foo->falseObj);
		foo->stackPointer = sp1;
	}
}


/*	receiver, args, then method are on top of stack. Execute method against receiver and args */

sqInt primitiveExecuteMethod(void) {
register struct foo * foo = &fum;
    sqInt top;
    sqInt successValue;
    sqInt methodPointer;
    sqInt primBits;

	/* begin popStack */
	top = longAt(foo->stackPointer);
	foo->stackPointer -= BYTES_PER_WORD;
	foo->newMethod = top;
	/* begin primitiveIndexOf: */
	methodPointer = foo->newMethod;
	primBits = (((usqInt) (longAt((methodPointer + (BASE_HEADER_SIZE)) + (HeaderIndex << (SHIFT_FOR_WORD))))) >> 1) & 268435967;
	foo->primitiveIndex = (primBits & 511) + (((usqInt) primBits) >> 19);
	/* begin success: */
	successValue = (foo->argumentCount - 1) == (argumentCountOf(foo->newMethod));
	foo->successFlag = successValue && foo->successFlag;
	if (foo->successFlag) {
		foo->argumentCount -= 1;
		/* begin executeNewMethod */
		if (foo->primitiveIndex > 0) {
			primitiveResponse();
			if (foo->successFlag) {
				goto l1;
			}
		}
		activateNewMethod();
		/* begin quickCheckForInterrupts */
		if ((foo->interruptCheckCounter -= 1) <= 0) {
			checkForInterrupts();
		}
	l1:	/* end executeNewMethod */;
	} else {
		/* begin unPop: */
		foo->stackPointer += 1 * (BYTES_PER_WORD);
	}
}


/*	receiver, argsArray, then method are on top of stack.  Execute method against receiver and args */

sqInt primitiveExecuteMethodArgsArray(void) {
register struct foo * foo = &fum;
    sqInt argCnt;
    sqInt argumentArray;
    sqInt methodArgument;
    sqInt top;
    sqInt top1;
    sqInt dst;
    sqInt in;
    sqInt lastIn;
    sqInt out;
    sqInt methodPointer;
    sqInt primBits;

	/* begin popStack */
	top = longAt(foo->stackPointer);
	foo->stackPointer -= BYTES_PER_WORD;
	methodArgument = top;
	/* begin popStack */
	top1 = longAt(foo->stackPointer);
	foo->stackPointer -= BYTES_PER_WORD;
	argumentArray = top1;
	if (!((((methodArgument & 1) == 0) && (((((usqInt) (longAt(methodArgument))) >> 8) & 15) >= 12)) && (((argumentArray & 1) == 0) && (((((usqInt) (longAt(argumentArray))) >> 8) & 15) == 2)))) {
		/* begin unPop: */
		foo->stackPointer += 2 * (BYTES_PER_WORD);
		/* begin primitiveFail */
		foo->successFlag = 0;
		return null;
	}
	argCnt = (((usqInt) (longAt((methodArgument + (BASE_HEADER_SIZE)) + (HeaderIndex << (SHIFT_FOR_WORD))))) >> 25) & 15;
	if (!(argCnt == (fetchWordLengthOf(argumentArray)))) {
		/* begin unPop: */
		foo->stackPointer += 2 * (BYTES_PER_WORD);
		/* begin primitiveFail */
		foo->successFlag = 0;
		return null;
	}
	/* begin transfer:from:to: */
	dst = foo->stackPointer + (BYTES_PER_WORD);
	flag("Dan");
	in = (argumentArray + (BASE_HEADER_SIZE)) - (BYTES_PER_WORD);
	lastIn = in + (argCnt * (BYTES_PER_WORD));
	out = dst - (BYTES_PER_WORD);
	while ((((usqInt) in)) < (((usqInt) lastIn))) {
		longAtput(out += BYTES_PER_WORD, longAt(in += BYTES_PER_WORD));
	}
	/* begin unPop: */
	foo->stackPointer += argCnt * (BYTES_PER_WORD);
	foo->newMethod = methodArgument;
	/* begin primitiveIndexOf: */
	methodPointer = foo->newMethod;
	primBits = (((usqInt) (longAt((methodPointer + (BASE_HEADER_SIZE)) + (HeaderIndex << (SHIFT_FOR_WORD))))) >> 1) & 268435967;
	foo->primitiveIndex = (primBits & 511) + (((usqInt) primBits) >> 19);
	foo->argumentCount = argCnt;
	/* begin executeNewMethod */
	if (foo->primitiveIndex > 0) {
		primitiveResponse();
		if (foo->successFlag) {
			goto l1;
		}
	}
	activateNewMethod();
	/* begin quickCheckForInterrupts */
	if ((foo->interruptCheckCounter -= 1) <= 0) {
		checkForInterrupts();
	}
l1:	/* end executeNewMethod */;
	foo->successFlag = 1;
}

sqInt primitiveExitToDebugger(void) {
	error("Exit to debugger at user request");
}


/*	Computes E raised to the receiver power. */

sqInt primitiveExp(void) {
register struct foo * foo = &fum;
    double  rcvr;

	rcvr = popFloat();
	if (foo->successFlag) {
		pushFloat(exp(rcvr));
	} else {
		/* begin unPop: */
		foo->stackPointer += 1 * (BYTES_PER_WORD);
	}
}


/*	Exponent part of this float. */

sqInt primitiveExponent(void) {
register struct foo * foo = &fum;
    double  frac;
    int  pwr;
    double  rcvr;
    sqInt sp;

	rcvr = popFloat();
	if (foo->successFlag) {
		frac = frexp(rcvr, &pwr);
		/* begin pushInteger: */
		/* begin push: */
		longAtput(sp = foo->stackPointer + (BYTES_PER_WORD), (((pwr - 1) << 1) | 1));
		foo->stackPointer = sp;
	} else {
		/* begin unPop: */
		foo->stackPointer += 1 * (BYTES_PER_WORD);
	}
}


/*	Call an external primitive. The external primitive methods 
	contain as first literal an array consisting of: 
	* The module name (String | Symbol) 
	* The function name (String | Symbol) 
	* The session ID (SmallInteger) [OBSOLETE] 
	* The function index (Integer) in the externalPrimitiveTable 
	For fast failures the primitive index of any method where the 
	external prim is not found is rewritten in the method cache 
	with zero. This allows for ultra fast responses as long as the 
	method stays in the cache. 
	The fast failure response relies on lkupClass being properly 
	set. This is done in 
	#addToMethodCacheSel:class:method:primIndex: to 
	compensate for execution of methods that are looked up in a 
	superclass (such as in primitivePerformAt). 
	With the latest modifications (e.g., actually flushing the 
	function addresses from the VM), the session ID is obsolete. 
	But for backward compatibility it is still kept around. Also, a 
	failed lookup is reported specially. If a method has been 
	looked up and not been found, the function address is stored 
	as -1 (e.g., the SmallInteger -1 to distinguish from 
	16rFFFFFFFF which may be returned from the lookup). 
	It is absolutely okay to remove the rewrite if we run into any 
	problems later on. It has an approximate speed difference of 
	30% per failed primitive call which may be noticable but if, 
	for any reasons, we run into problems (like with J3) we can 
	always remove the rewrite. 
	 */

sqInt primitiveExternalCall(void) {
register struct foo * foo = &fum;
    void *addr;
    sqInt functionLength;
    sqInt functionName;
    sqInt index;
    sqInt lit;
    sqInt moduleLength;
    sqInt moduleName;
    sqInt successValue;
    sqInt header;
    sqInt successValue1;
    sqInt methodPointer;
    sqInt successValue2;
    sqInt successValue3;
    sqInt header1;
    sqInt sz;
    sqInt sz1;

	/* begin success: */
	successValue1 = (literalCountOf(foo->newMethod)) > 0;
	foo->successFlag = successValue1 && foo->successFlag;
	if (!(foo->successFlag)) {
		return null;
	}
	/* begin literal:ofMethod: */
	methodPointer = foo->newMethod;
	lit = longAt((methodPointer + (BASE_HEADER_SIZE)) + ((0 + LiteralStart) << (SHIFT_FOR_WORD)));
	/* begin success: */
	successValue2 = (((lit & 1) == 0) && (((((usqInt) (longAt(lit))) >> 8) & 15) == 2)) && ((lengthOf(lit)) == 4);
	foo->successFlag = successValue2 && foo->successFlag;
	if (!(foo->successFlag)) {
		return null;
	}
	index = longAt((lit + (BASE_HEADER_SIZE)) + (3 << (SHIFT_FOR_WORD)));
	/* begin checkedIntegerValueOf: */
	if ((index & 1)) {
		index = (index >> 1);
		goto l1;
	} else {
		/* begin primitiveFail */
		foo->successFlag = 0;
		index = 0;
		goto l1;
	}
l1:	/* end checkedIntegerValueOf: */;
	if (!(foo->successFlag)) {
		return null;
	}
	if (index < 0) {
		rewriteMethodCacheSelclassprimIndex(foo->messageSelector, foo->lkupClass, 0);
		/* begin success: */
		foo->successFlag = 0 && foo->successFlag;
		return null;
	}
	if ((index > 0) && (index <= MaxExternalPrimitiveTableSize)) {
		addr = foo->externalPrimitiveTable[index - 1];
		if (addr != 0) {
			rewriteMethodCacheSelclassprimIndexprimFunction(foo->messageSelector, foo->lkupClass, 1000 + index, addr);
			callExternalPrimitive(addr);
			return null;
		}
		/* begin primitiveFail */
		foo->successFlag = 0;
		return null;
	}
	longAtput((lit + (BASE_HEADER_SIZE)) + (2 << (SHIFT_FOR_WORD)), ConstZero);
	longAtput((lit + (BASE_HEADER_SIZE)) + (3 << (SHIFT_FOR_WORD)), ConstZero);
	moduleName = longAt((lit + (BASE_HEADER_SIZE)) + (0 << (SHIFT_FOR_WORD)));
	if (moduleName == foo->nilObj) {
		moduleLength = 0;
	} else {
		/* begin success: */
		successValue = ((moduleName & 1) == 0) && (((((usqInt) (longAt(moduleName))) >> 8) & 15) >= 8);
		foo->successFlag = successValue && foo->successFlag;
		/* begin lengthOf: */
		header = longAt(moduleName);
		/* begin lengthOf:baseHeader:format: */
		if ((header & TypeMask) == HeaderTypeSizeAndClass) {
			sz = (longAt(moduleName - ((BYTES_PER_WORD) * 2))) & (LONG_SIZE_MASK);
		} else {
			sz = header & (SIZE_MASK);
		}
		sz -= header & (SIZE_4_BIT);
		if (((((usqInt) header) >> 8) & 15) <= 4) {
			moduleLength = ((usqInt) (sz - (BASE_HEADER_SIZE))) >> (SHIFT_FOR_WORD);
			goto l2;
		}
		if (((((usqInt) header) >> 8) & 15) < 8) {
			moduleLength = ((usqInt) (sz - (BASE_HEADER_SIZE))) >> 2;
			goto l2;
		} else {
			moduleLength = (sz - (BASE_HEADER_SIZE)) - (((((usqInt) header) >> 8) & 15) & 3);
			goto l2;
		}
	l2:	/* end lengthOf:baseHeader:format: */;
		;
	}
	functionName = longAt((lit + (BASE_HEADER_SIZE)) + (1 << (SHIFT_FOR_WORD)));
	/* begin success: */
	successValue3 = ((functionName & 1) == 0) && (((((usqInt) (longAt(functionName))) >> 8) & 15) >= 8);
	foo->successFlag = successValue3 && foo->successFlag;
	/* begin lengthOf: */
	header1 = longAt(functionName);
	/* begin lengthOf:baseHeader:format: */
	if ((header1 & TypeMask) == HeaderTypeSizeAndClass) {
		sz1 = (longAt(functionName - ((BYTES_PER_WORD) * 2))) & (LONG_SIZE_MASK);
	} else {
		sz1 = header1 & (SIZE_MASK);
	}
	sz1 -= header1 & (SIZE_4_BIT);
	if (((((usqInt) header1) >> 8) & 15) <= 4) {
		functionLength = ((usqInt) (sz1 - (BASE_HEADER_SIZE))) >> (SHIFT_FOR_WORD);
		goto l3;
	}
	if (((((usqInt) header1) >> 8) & 15) < 8) {
		functionLength = ((usqInt) (sz1 - (BASE_HEADER_SIZE))) >> 2;
		goto l3;
	} else {
		functionLength = (sz1 - (BASE_HEADER_SIZE)) - (((((usqInt) header1) >> 8) & 15) & 3);
		goto l3;
	}
l3:	/* end lengthOf:baseHeader:format: */;
	if (!(foo->successFlag)) {
		return null;
	}
	addr = ioLoadExternalFunctionOfLengthFromModuleOfLength(functionName + (BASE_HEADER_SIZE), functionLength, moduleName + (BASE_HEADER_SIZE), moduleLength);
	if (addr == 0) {
		index = -1;
	} else {

		/* add the function to the external primitive table */

		index = addToExternalPrimitiveTable(addr);
	}
	/* begin success: */
	foo->successFlag = (index >= 0) && foo->successFlag;
	longAtput((lit + (BASE_HEADER_SIZE)) + (3 << (SHIFT_FOR_WORD)), ((index << 1) | 1));
	if (foo->successFlag && (addr != 0)) {
		rewriteMethodCacheSelclassprimIndexprimFunction(foo->messageSelector, foo->lkupClass, 1000 + index, addr);
		callExternalPrimitive(addr);
	} else {
		rewriteMethodCacheSelclassprimIndex(foo->messageSelector, foo->lkupClass, 0);
	}
}

sqInt primitiveFail(void) {
	foo->successFlag = 0;
}


/*	Set specific primitive failure. */

sqInt primitiveFailFor(sqInt reasonCode) {
register struct foo * foo = &fum;
    sqInt primFailCode;

	primFailCode = reasonCode;
	/* begin primitiveFail */
	foo->successFlag = 0;
}


/*	Primitive. Search up the context stack for the next method context marked for exception handling starting at the receiver. Return nil if none found */

sqInt primitiveFindHandlerContext(void) {
register struct foo * foo = &fum;
    sqInt nilOop;
    sqInt thisCntx;
    sqInt sp;
    sqInt top;
    sqInt sp1;

	/* begin popStack */
	top = longAt(foo->stackPointer);
	foo->stackPointer -= BYTES_PER_WORD;
	thisCntx = top;
	nilOop = foo->nilObj;
	do {
		if (isHandlerMarked(thisCntx)) {
			/* begin push: */
			longAtput(sp = foo->stackPointer + (BYTES_PER_WORD), thisCntx);
			foo->stackPointer = sp;
			return null;
		}
		thisCntx = longAt((thisCntx + (BASE_HEADER_SIZE)) + (SenderIndex << (SHIFT_FOR_WORD)));
	} while(!(thisCntx == nilOop));
	/* begin push: */
	longAtput(sp1 = foo->stackPointer + (BYTES_PER_WORD), foo->nilObj);
	foo->stackPointer = sp1;
	return null;
}


/*	Primitive. Search up the context stack for the next method context marked for unwind handling from the receiver up to but not including the argument. Return nil if none found. */

sqInt primitiveFindNextUnwindContext(void) {
register struct foo * foo = &fum;
    sqInt aContext;
    sqInt nilOop;
    sqInt thisCntx;
    sqInt unwindMarked;
    sqInt sp;
    sqInt header;
    sqInt meth;
    sqInt pIndex;
    sqInt top;
    sqInt oop;
    sqInt sp1;
    sqInt primBits;
    sqInt top1;

	/* begin popStack */
	top = longAt(foo->stackPointer);
	foo->stackPointer -= BYTES_PER_WORD;
	aContext = top;
	/* begin fetchPointer:ofObject: */
	/* begin popStack */
	top1 = longAt(foo->stackPointer);
	foo->stackPointer -= BYTES_PER_WORD;
	oop = top1;
	thisCntx = longAt((oop + (BASE_HEADER_SIZE)) + (SenderIndex << (SHIFT_FOR_WORD)));
	nilOop = foo->nilObj;
	while (!((thisCntx == aContext) || (thisCntx == nilOop))) {
		/* begin isUnwindMarked: */
		header = longAt(thisCntx);
		if (!(((((usqInt) header) >> 12) & 31) == 14)) {
			unwindMarked = 0;
			goto l1;
		}
		meth = longAt((thisCntx + (BASE_HEADER_SIZE)) + (MethodIndex << (SHIFT_FOR_WORD)));
		/* begin primitiveIndexOf: */
		primBits = (((usqInt) (longAt((meth + (BASE_HEADER_SIZE)) + (HeaderIndex << (SHIFT_FOR_WORD))))) >> 1) & 268435967;
		pIndex = (primBits & 511) + (((usqInt) primBits) >> 19);
		unwindMarked = pIndex == 198;
	l1:	/* end isUnwindMarked: */;
		if (unwindMarked) {
			/* begin push: */
			longAtput(sp = foo->stackPointer + (BYTES_PER_WORD), thisCntx);
			foo->stackPointer = sp;
			return null;
		}
		thisCntx = longAt((thisCntx + (BASE_HEADER_SIZE)) + (SenderIndex << (SHIFT_FOR_WORD)));
	}
	/* begin push: */
	longAtput(sp1 = foo->stackPointer + (BYTES_PER_WORD), nilOop);
	foo->stackPointer = sp1;
	return null;
}

sqInt primitiveFloatAdd(void) {
register struct foo * foo = &fum;
	return primitiveFloatAddtoArg(longAt(foo->stackPointer - (1 * (BYTES_PER_WORD))), longAt(foo->stackPointer));
}

sqInt primitiveFloatAddtoArg(sqInt rcvrOop, sqInt argOop) {
register struct foo * foo = &fum;
    double arg;
    double rcvr;

	/* begin loadFloatOrIntFrom: */
	if ((rcvrOop & 1)) {
		rcvr = ((double) ((rcvrOop >> 1)) );
		goto l1;
	}
	if ((fetchClassOfNonInt(rcvrOop)) == (fetchPointerofObject(ClassFloat, foo->specialObjectsOop))) {
		rcvr = floatValueOf(rcvrOop);
		goto l1;
	}
	foo->successFlag = 0;
l1:	/* end loadFloatOrIntFrom: */;
	/* begin loadFloatOrIntFrom: */
	if ((argOop & 1)) {
		arg = ((double) ((argOop >> 1)) );
		goto l2;
	}
	if ((fetchClassOfNonInt(argOop)) == (fetchPointerofObject(ClassFloat, foo->specialObjectsOop))) {
		arg = floatValueOf(argOop);
		goto l2;
	}
	foo->successFlag = 0;
l2:	/* end loadFloatOrIntFrom: */;
	if (foo->successFlag) {
		/* begin pop: */
		foo->stackPointer -= 2 * (BYTES_PER_WORD);
		pushFloat(rcvr + arg);
	}
}

sqInt primitiveFloatDivide(void) {
register struct foo * foo = &fum;
	return primitiveFloatDividebyArg(longAt(foo->stackPointer - (1 * (BYTES_PER_WORD))), longAt(foo->stackPointer));
}

sqInt primitiveFloatDividebyArg(sqInt rcvrOop, sqInt argOop) {
register struct foo * foo = &fum;
    double arg;
    double rcvr;

	/* begin loadFloatOrIntFrom: */
	if ((rcvrOop & 1)) {
		rcvr = ((double) ((rcvrOop >> 1)) );
		goto l1;
	}
	if ((fetchClassOfNonInt(rcvrOop)) == (fetchPointerofObject(ClassFloat, foo->specialObjectsOop))) {
		rcvr = floatValueOf(rcvrOop);
		goto l1;
	}
	foo->successFlag = 0;
l1:	/* end loadFloatOrIntFrom: */;
	/* begin loadFloatOrIntFrom: */
	if ((argOop & 1)) {
		arg = ((double) ((argOop >> 1)) );
		goto l2;
	}
	if ((fetchClassOfNonInt(argOop)) == (fetchPointerofObject(ClassFloat, foo->specialObjectsOop))) {
		arg = floatValueOf(argOop);
		goto l2;
	}
	foo->successFlag = 0;
l2:	/* end loadFloatOrIntFrom: */;
	if (foo->successFlag) {
		/* begin success: */
		foo->successFlag = (arg != 0.0) && foo->successFlag;
		if (foo->successFlag) {
			/* begin pop: */
			foo->stackPointer -= 2 * (BYTES_PER_WORD);
			pushFloat(rcvr / arg);
		}
	}
}

sqInt primitiveFloatEqual(void) {
register struct foo * foo = &fum;
    sqInt aBool;
    sqInt sp;
    sqInt sp1;

	aBool = primitiveFloatEqualtoArg(longAt(foo->stackPointer - (1 * (BYTES_PER_WORD))), longAt(foo->stackPointer));
	if (foo->successFlag) {
		/* begin pop: */
		foo->stackPointer -= 2 * (BYTES_PER_WORD);
		/* begin pushBool: */
		if (aBool) {
			/* begin push: */
			longAtput(sp = foo->stackPointer + (BYTES_PER_WORD), foo->trueObj);
			foo->stackPointer = sp;
		} else {
			/* begin push: */
			longAtput(sp1 = foo->stackPointer + (BYTES_PER_WORD), foo->falseObj);
			foo->stackPointer = sp1;
		}
	}
}

sqInt primitiveFloatEqualtoArg(sqInt rcvrOop, sqInt argOop) {
register struct foo * foo = &fum;
    double arg;
    double rcvr;

	/* begin loadFloatOrIntFrom: */
	if ((rcvrOop & 1)) {
		rcvr = ((double) ((rcvrOop >> 1)) );
		goto l1;
	}
	if ((fetchClassOfNonInt(rcvrOop)) == (fetchPointerofObject(ClassFloat, foo->specialObjectsOop))) {
		rcvr = floatValueOf(rcvrOop);
		goto l1;
	}
	foo->successFlag = 0;
l1:	/* end loadFloatOrIntFrom: */;
	/* begin loadFloatOrIntFrom: */
	if ((argOop & 1)) {
		arg = ((double) ((argOop >> 1)) );
		goto l2;
	}
	if ((fetchClassOfNonInt(argOop)) == (fetchPointerofObject(ClassFloat, foo->specialObjectsOop))) {
		arg = floatValueOf(argOop);
		goto l2;
	}
	foo->successFlag = 0;
l2:	/* end loadFloatOrIntFrom: */;
	if (foo->successFlag) {
		return rcvr == arg;
	}
}

sqInt primitiveFloatGreaterthanArg(sqInt rcvrOop, sqInt argOop) {
register struct foo * foo = &fum;
    double arg;
    double rcvr;

	/* begin loadFloatOrIntFrom: */
	if ((rcvrOop & 1)) {
		rcvr = ((double) ((rcvrOop >> 1)) );
		goto l1;
	}
	if ((fetchClassOfNonInt(rcvrOop)) == (fetchPointerofObject(ClassFloat, foo->specialObjectsOop))) {
		rcvr = floatValueOf(rcvrOop);
		goto l1;
	}
	foo->successFlag = 0;
l1:	/* end loadFloatOrIntFrom: */;
	/* begin loadFloatOrIntFrom: */
	if ((argOop & 1)) {
		arg = ((double) ((argOop >> 1)) );
		goto l2;
	}
	if ((fetchClassOfNonInt(argOop)) == (fetchPointerofObject(ClassFloat, foo->specialObjectsOop))) {
		arg = floatValueOf(argOop);
		goto l2;
	}
	foo->successFlag = 0;
l2:	/* end loadFloatOrIntFrom: */;
	if (foo->successFlag) {
		return rcvr > arg;
	}
}

sqInt primitiveFloatGreaterOrEqual(void) {
register struct foo * foo = &fum;
    sqInt aBool;
    sqInt sp;
    sqInt sp1;

	aBool = primitiveFloatGreaterOrEqualtoArg(longAt(foo->stackPointer - (1 * (BYTES_PER_WORD))), longAt(foo->stackPointer));
	if (foo->successFlag) {
		/* begin pop: */
		foo->stackPointer -= 2 * (BYTES_PER_WORD);
		/* begin pushBool: */
		if (aBool) {
			/* begin push: */
			longAtput(sp = foo->stackPointer + (BYTES_PER_WORD), foo->trueObj);
			foo->stackPointer = sp;
		} else {
			/* begin push: */
			longAtput(sp1 = foo->stackPointer + (BYTES_PER_WORD), foo->falseObj);
			foo->stackPointer = sp1;
		}
	}
}

sqInt primitiveFloatGreaterOrEqualtoArg(sqInt rcvrOop, sqInt argOop) {
register struct foo * foo = &fum;
    double arg;
    double rcvr;

	/* begin loadFloatOrIntFrom: */
	if ((rcvrOop & 1)) {
		rcvr = ((double) ((rcvrOop >> 1)) );
		goto l1;
	}
	if ((fetchClassOfNonInt(rcvrOop)) == (fetchPointerofObject(ClassFloat, foo->specialObjectsOop))) {
		rcvr = floatValueOf(rcvrOop);
		goto l1;
	}
	foo->successFlag = 0;
l1:	/* end loadFloatOrIntFrom: */;
	/* begin loadFloatOrIntFrom: */
	if ((argOop & 1)) {
		arg = ((double) ((argOop >> 1)) );
		goto l2;
	}
	if ((fetchClassOfNonInt(argOop)) == (fetchPointerofObject(ClassFloat, foo->specialObjectsOop))) {
		arg = floatValueOf(argOop);
		goto l2;
	}
	foo->successFlag = 0;
l2:	/* end loadFloatOrIntFrom: */;
	if (foo->successFlag) {
		return rcvr >= arg;
	}
}

sqInt primitiveFloatGreaterThan(void) {
register struct foo * foo = &fum;
    sqInt aBool;
    sqInt sp;
    sqInt sp1;

	aBool = primitiveFloatGreaterthanArg(longAt(foo->stackPointer - (1 * (BYTES_PER_WORD))), longAt(foo->stackPointer));
	if (foo->successFlag) {
		/* begin pop: */
		foo->stackPointer -= 2 * (BYTES_PER_WORD);
		/* begin pushBool: */
		if (aBool) {
			/* begin push: */
			longAtput(sp = foo->stackPointer + (BYTES_PER_WORD), foo->trueObj);
			foo->stackPointer = sp;
		} else {
			/* begin push: */
			longAtput(sp1 = foo->stackPointer + (BYTES_PER_WORD), foo->falseObj);
			foo->stackPointer = sp1;
		}
	}
}

sqInt primitiveFloatLessthanArg(sqInt rcvrOop, sqInt argOop) {
register struct foo * foo = &fum;
    double arg;
    double rcvr;

	/* begin loadFloatOrIntFrom: */
	if ((rcvrOop & 1)) {
		rcvr = ((double) ((rcvrOop >> 1)) );
		goto l1;
	}
	if ((fetchClassOfNonInt(rcvrOop)) == (fetchPointerofObject(ClassFloat, foo->specialObjectsOop))) {
		rcvr = floatValueOf(rcvrOop);
		goto l1;
	}
	foo->successFlag = 0;
l1:	/* end loadFloatOrIntFrom: */;
	/* begin loadFloatOrIntFrom: */
	if ((argOop & 1)) {
		arg = ((double) ((argOop >> 1)) );
		goto l2;
	}
	if ((fetchClassOfNonInt(argOop)) == (fetchPointerofObject(ClassFloat, foo->specialObjectsOop))) {
		arg = floatValueOf(argOop);
		goto l2;
	}
	foo->successFlag = 0;
l2:	/* end loadFloatOrIntFrom: */;
	if (foo->successFlag) {
		return rcvr < arg;
	}
}

sqInt primitiveFloatLessOrEqual(void) {
register struct foo * foo = &fum;
    sqInt aBool;
    sqInt sp;
    sqInt sp1;

	aBool = primitiveFloatLessOrEqualtoArg(longAt(foo->stackPointer - (1 * (BYTES_PER_WORD))), longAt(foo->stackPointer));
	if (foo->successFlag) {
		/* begin pop: */
		foo->stackPointer -= 2 * (BYTES_PER_WORD);
		/* begin pushBool: */
		if (aBool) {
			/* begin push: */
			longAtput(sp = foo->stackPointer + (BYTES_PER_WORD), foo->trueObj);
			foo->stackPointer = sp;
		} else {
			/* begin push: */
			longAtput(sp1 = foo->stackPointer + (BYTES_PER_WORD), foo->falseObj);
			foo->stackPointer = sp1;
		}
	}
}

sqInt primitiveFloatLessOrEqualtoArg(sqInt rcvrOop, sqInt argOop) {
register struct foo * foo = &fum;
    double arg;
    double rcvr;

	/* begin loadFloatOrIntFrom: */
	if ((rcvrOop & 1)) {
		rcvr = ((double) ((rcvrOop >> 1)) );
		goto l1;
	}
	if ((fetchClassOfNonInt(rcvrOop)) == (fetchPointerofObject(ClassFloat, foo->specialObjectsOop))) {
		rcvr = floatValueOf(rcvrOop);
		goto l1;
	}
	foo->successFlag = 0;
l1:	/* end loadFloatOrIntFrom: */;
	/* begin loadFloatOrIntFrom: */
	if ((argOop & 1)) {
		arg = ((double) ((argOop >> 1)) );
		goto l2;
	}
	if ((fetchClassOfNonInt(argOop)) == (fetchPointerofObject(ClassFloat, foo->specialObjectsOop))) {
		arg = floatValueOf(argOop);
		goto l2;
	}
	foo->successFlag = 0;
l2:	/* end loadFloatOrIntFrom: */;
	if (foo->successFlag) {
		return rcvr <= arg;
	}
}

sqInt primitiveFloatLessThan(void) {
register struct foo * foo = &fum;
    sqInt aBool;
    sqInt sp;
    sqInt sp1;

	aBool = primitiveFloatLessthanArg(longAt(foo->stackPointer - (1 * (BYTES_PER_WORD))), longAt(foo->stackPointer));
	if (foo->successFlag) {
		/* begin pop: */
		foo->stackPointer -= 2 * (BYTES_PER_WORD);
		/* begin pushBool: */
		if (aBool) {
			/* begin push: */
			longAtput(sp = foo->stackPointer + (BYTES_PER_WORD), foo->trueObj);
			foo->stackPointer = sp;
		} else {
			/* begin push: */
			longAtput(sp1 = foo->stackPointer + (BYTES_PER_WORD), foo->falseObj);
			foo->stackPointer = sp1;
		}
	}
}

sqInt primitiveFloatMultiply(void) {
register struct foo * foo = &fum;
	return primitiveFloatMultiplybyArg(longAt(foo->stackPointer - (1 * (BYTES_PER_WORD))), longAt(foo->stackPointer));
}

sqInt primitiveFloatMultiplybyArg(sqInt rcvrOop, sqInt argOop) {
register struct foo * foo = &fum;
    double arg;
    double rcvr;

	/* begin loadFloatOrIntFrom: */
	if ((rcvrOop & 1)) {
		rcvr = ((double) ((rcvrOop >> 1)) );
		goto l1;
	}
	if ((fetchClassOfNonInt(rcvrOop)) == (fetchPointerofObject(ClassFloat, foo->specialObjectsOop))) {
		rcvr = floatValueOf(rcvrOop);
		goto l1;
	}
	foo->successFlag = 0;
l1:	/* end loadFloatOrIntFrom: */;
	/* begin loadFloatOrIntFrom: */
	if ((argOop & 1)) {
		arg = ((double) ((argOop >> 1)) );
		goto l2;
	}
	if ((fetchClassOfNonInt(argOop)) == (fetchPointerofObject(ClassFloat, foo->specialObjectsOop))) {
		arg = floatValueOf(argOop);
		goto l2;
	}
	foo->successFlag = 0;
l2:	/* end loadFloatOrIntFrom: */;
	if (foo->successFlag) {
		/* begin pop: */
		foo->stackPointer -= 2 * (BYTES_PER_WORD);
		pushFloat(rcvr * arg);
	}
}

sqInt primitiveFloatNotEqual(void) {
register struct foo * foo = &fum;
    sqInt aBool;
    sqInt sp;
    sqInt sp1;

	aBool = primitiveFloatEqualtoArg(longAt(foo->stackPointer - (1 * (BYTES_PER_WORD))), longAt(foo->stackPointer));
	if (foo->successFlag) {
		/* begin pop: */
		foo->stackPointer -= 2 * (BYTES_PER_WORD);
		/* begin pushBool: */
		if (!aBool) {
			/* begin push: */
			longAtput(sp = foo->stackPointer + (BYTES_PER_WORD), foo->trueObj);
			foo->stackPointer = sp;
		} else {
			/* begin push: */
			longAtput(sp1 = foo->stackPointer + (BYTES_PER_WORD), foo->falseObj);
			foo->stackPointer = sp1;
		}
	}
}

sqInt primitiveFloatSubtract(void) {
register struct foo * foo = &fum;
	return primitiveFloatSubtractfromArg(longAt(foo->stackPointer - (1 * (BYTES_PER_WORD))), longAt(foo->stackPointer));
}

sqInt primitiveFloatSubtractfromArg(sqInt rcvrOop, sqInt argOop) {
register struct foo * foo = &fum;
    double arg;
    double rcvr;

	/* begin loadFloatOrIntFrom: */
	if ((rcvrOop & 1)) {
		rcvr = ((double) ((rcvrOop >> 1)) );
		goto l1;
	}
	if ((fetchClassOfNonInt(rcvrOop)) == (fetchPointerofObject(ClassFloat, foo->specialObjectsOop))) {
		rcvr = floatValueOf(rcvrOop);
		goto l1;
	}
	foo->successFlag = 0;
l1:	/* end loadFloatOrIntFrom: */;
	/* begin loadFloatOrIntFrom: */
	if ((argOop & 1)) {
		arg = ((double) ((argOop >> 1)) );
		goto l2;
	}
	if ((fetchClassOfNonInt(argOop)) == (fetchPointerofObject(ClassFloat, foo->specialObjectsOop))) {
		arg = floatValueOf(argOop);
		goto l2;
	}
	foo->successFlag = 0;
l2:	/* end loadFloatOrIntFrom: */;
	if (foo->successFlag) {
		/* begin pop: */
		foo->stackPointer -= 2 * (BYTES_PER_WORD);
		pushFloat(rcvr - arg);
	}
}


/*	Clear the method lookup cache. This must be done after every programming change. */

sqInt primitiveFlushCache(void) {
register struct foo * foo = &fum;
    sqInt aCompiledMethod;
    sqInt i;
    sqInt i1;

	/* begin flushMethodCache */
	for (i = 1; i <= MethodCacheSize; i += 1) {
		foo->methodCache[i] = 0;
	}
	/* begin flushAtCache */
	for (i1 = 1; i1 <= AtCacheTotalSize; i1 += 1) {
		foo->atCache[i1] = 0;
	}
	/* begin compilerFlushCacheHook: */
	aCompiledMethod = null;
	if (foo->compilerInitialized) {
		compilerFlushCache(aCompiledMethod);
	}
}


/*	The receiver is a compiledMethod.  Clear all entries in the method lookup cache that refer to this method, presumably because it has been redefined, overridden or removed. */

sqInt primitiveFlushCacheByMethod(void) {
register struct foo * foo = &fum;
    sqInt i;
    sqInt oldMethod;
    sqInt probe;

	oldMethod = longAt(foo->stackPointer);
	probe = 0;
	for (i = 1; i <= MethodCacheEntries; i += 1) {
		if ((foo->methodCache[probe + MethodCacheMethod]) == oldMethod) {
			foo->methodCache[probe + MethodCacheSelector] = 0;
		}
		probe += MethodCacheEntrySize;
	}
	/* begin compilerFlushCacheHook: */
	if (foo->compilerInitialized) {
		compilerFlushCache(oldMethod);
	}
}


/*	The receiver is a message selector.  Clear all entries in the method lookup cache with this selector, presumably because an associated method has been redefined. */

sqInt primitiveFlushCacheSelective(void) {
register struct foo * foo = &fum;
    sqInt i;
    sqInt probe;
    sqInt selector;

	selector = longAt(foo->stackPointer);
	probe = 0;
	for (i = 1; i <= MethodCacheEntries; i += 1) {
		if ((foo->methodCache[probe + MethodCacheSelector]) == selector) {
			foo->methodCache[probe + MethodCacheSelector] = 0;
		}
		probe += MethodCacheEntrySize;
	}
}


/*	Primitive. Flush all the existing external primitives in the image thus forcing a reload on next invokation. */

sqInt primitiveFlushExternalPrimitives(void) {
	return flushExternalPrimitives();
}


/*	On some platforms, this primitive forces enqueued display updates to be processed immediately. On others, it does nothing. */

sqInt primitiveForceDisplayUpdate(void) {
	ioForceDisplayUpdate();
}


/*	Set force tenure flag to true, this forces a tenure operation on the next incremental GC */

EXPORT(sqInt) primitiveForceTenure(void) {
	foo->forceTenureFlag = 1;
}


/*	On platforms that support it, this primitive prints the receiver, assumed to be a Form, to the default printer. */

sqInt primitiveFormPrint(void) {
register struct foo * foo = &fum;
    sqInt bitsArray;
    sqInt bitsArraySize;
    sqInt depth;
    sqInt h;
    double  hScale;
    sqInt landscapeFlag;
    sqInt ok;
    sqInt pixelsPerWord;
    sqInt rcvr;
    double  vScale;
    sqInt w;
    sqInt wordsPerLine;
    sqInt fmt;
    sqInt header;
    sqInt sz;

	/* begin booleanValueOf: */
	if ((longAt(foo->stackPointer)) == foo->trueObj) {
		landscapeFlag = 1;
		goto l2;
	}
	if ((longAt(foo->stackPointer)) == foo->falseObj) {
		landscapeFlag = 0;
		goto l2;
	}
	foo->successFlag = 0;
	landscapeFlag = null;
l2:	/* end booleanValueOf: */;
	vScale = floatValueOf(longAt(foo->stackPointer - (1 * (BYTES_PER_WORD))));
	hScale = floatValueOf(longAt(foo->stackPointer - (2 * (BYTES_PER_WORD))));
	rcvr = longAt(foo->stackPointer - (3 * (BYTES_PER_WORD)));
	if ((rcvr & 1)) {
		/* begin success: */
		foo->successFlag = 0 && foo->successFlag;
	}
	if (foo->successFlag) {
		if (!((((rcvr & 1) == 0) && (((((usqInt) (longAt(rcvr))) >> 8) & 15) <= 4)) && ((lengthOf(rcvr)) >= 4))) {
			/* begin success: */
			foo->successFlag = 0 && foo->successFlag;
		}
	}
	if (foo->successFlag) {
		bitsArray = longAt((rcvr + (BASE_HEADER_SIZE)) + (0 << (SHIFT_FOR_WORD)));
		w = fetchIntegerofObject(1, rcvr);
		h = fetchIntegerofObject(2, rcvr);
		depth = fetchIntegerofObject(3, rcvr);
		if (!((w > 0) && (h > 0))) {
			/* begin success: */
			foo->successFlag = 0 && foo->successFlag;
		}
		pixelsPerWord = 32 / depth;
		wordsPerLine = (w + (pixelsPerWord - 1)) / pixelsPerWord;
		if ((!((rcvr & 1))) && (((bitsArray & 1) == 0) && (isWordsOrBytesNonInt(bitsArray)))) {
			/* begin byteLengthOf: */
			header = longAt(bitsArray);
			if ((header & TypeMask) == HeaderTypeSizeAndClass) {
				sz = (longAt(bitsArray - ((BYTES_PER_WORD) * 2))) & (ALL_BUT_TYPE_MASK);
			} else {
				sz = header & (SIZE_MASK);
			}
			fmt = (((usqInt) header) >> 8) & 15;
			if (fmt < 8) {
				bitsArraySize = sz - (BASE_HEADER_SIZE);
				goto l1;
			} else {
				bitsArraySize = (sz - (BASE_HEADER_SIZE)) - (fmt & 3);
				goto l1;
			}
		l1:	/* end byteLengthOf: */;
			/* begin success: */
			foo->successFlag = (bitsArraySize == ((wordsPerLine * h) * 4)) && foo->successFlag;
		} else {
			/* begin success: */
			foo->successFlag = 0 && foo->successFlag;
		}
	}
	if (foo->successFlag) {
		if ((BYTES_PER_WORD) == 8) {
			ok = ioFormPrint(bitsArray + 8, w, h, depth, hScale, vScale, landscapeFlag);
		} else {
			ok = ioFormPrint(bitsArray + 4, w, h, depth, hScale, vScale, landscapeFlag);
		}
		/* begin success: */
		foo->successFlag = ok && foo->successFlag;
	}
	if (foo->successFlag) {
		/* begin pop: */
		foo->stackPointer -= 3 * (BYTES_PER_WORD);
	}
}

sqInt primitiveFractionalPart(void) {
register struct foo * foo = &fum;
    double  frac;
    double  rcvr;
    double  trunc;

	rcvr = popFloat();
	if (foo->successFlag) {
		frac = modf(rcvr, &trunc);
		pushFloat(frac);
	} else {
		/* begin unPop: */
		foo->stackPointer += 1 * (BYTES_PER_WORD);
	}
}


/*	Do a full garbage collection and return the number of bytes available (including swap space if dynamic memory management is supported). */

sqInt primitiveFullGC(void) {
register struct foo * foo = &fum;
    sqInt object;
    sqInt sp;

	/* begin pop: */
	foo->stackPointer -= 1 * (BYTES_PER_WORD);
	incrementalGC();
	fullGC();
	/* begin push: */
	object = positive64BitIntegerFor(((longAt(foo->freeBlock)) & (ALL_BUT_TYPE_MASK)) + (sqMemoryExtraBytesLeft(1)));
	longAtput(sp = foo->stackPointer + (BYTES_PER_WORD), object);
	foo->stackPointer = sp;
}


/*	Fetch the system attribute with the given integer ID. The 
	result is a string, which will be empty if the attribute is not 
	defined. */

sqInt primitiveGetAttribute(void) {
register struct foo * foo = &fum;
    sqInt attr;
    sqInt s;
    sqInt sz;
    sqInt sp;
    sqInt integerPointer;

	/* begin stackIntegerValue: */
	integerPointer = longAt(foo->stackPointer - (0 * (BYTES_PER_WORD)));
	/* begin checkedIntegerValueOf: */
	if ((integerPointer & 1)) {
		attr = (integerPointer >> 1);
		goto l1;
	} else {
		/* begin primitiveFail */
		foo->successFlag = 0;
		attr = 0;
		goto l1;
	}
	attr = null;
l1:	/* end stackIntegerValue: */;
	if (foo->successFlag) {
		sz = attributeSize(attr);
	}
	if (foo->successFlag) {
		s = instantiateClassindexableSize(fetchPointerofObject(ClassString, foo->specialObjectsOop), sz);
		getAttributeIntoLength(attr, s + (BASE_HEADER_SIZE), sz);
		/* begin pop:thenPush: */
		longAtput(sp = foo->stackPointer - ((2 - 1) * (BYTES_PER_WORD)), s);
		foo->stackPointer = sp;
	}
}


/*	Primitive. Return the next input event from the VM event queue. */

sqInt primitiveGetNextEvent(void) {
register struct foo * foo = &fum;
    sqInt arg;
    sqInt eventTypeIs;
    int evtBuf[8] = { 0, 0, 0, 0, 0, 0, 0, 0 };
    sqInt i;
    sqInt value;
    sqInt oop;

	;
	arg = longAt(foo->stackPointer);
	if (!((((arg & 1) == 0) && (((((usqInt) (longAt(arg))) >> 8) & 15) == 2)) && ((slotSizeOf(arg)) == 8))) {
		/* begin primitiveFail */
		foo->successFlag = 0;
		return null;
	}
	ioGetNextEvent(((sqInputEvent*) evtBuf));
	if (!(foo->successFlag)) {
		return null;
	}
	eventTypeIs = evtBuf[0];
	/* begin storeInteger:ofObject:withValue: */
	if (
# ifdef SQ_HOST32  // cast to int for 64 bit image on 32 bit host
		(((((int) (evtBuf[0]))) ^ ((((int) (evtBuf[0]))) << 1)) >= 0)
# else
		(((evtBuf[0]) >= -1073741824) && ((evtBuf[0]) <= 1073741823))
# endif  // SQ_HOST32
	) {
		longAtput((arg + (BASE_HEADER_SIZE)) + (0 << (SHIFT_FOR_WORD)), (((evtBuf[0]) << 1) | 1));
	} else {
		/* begin primitiveFail */
		foo->successFlag = 0;
	}
	if (!(foo->successFlag)) {
		return null;
	}
	if (eventTypeIs == 6) {
		for (i = 1; i <= 7; i += 1) {
			value = evtBuf[i];
			/* begin storePointer:ofObject:withValue: */
			if ((((usqInt) arg)) < (((usqInt) foo->youngStart))) {
				possibleRootStoreIntovalue(arg, value);
			}
			longAtput((arg + (BASE_HEADER_SIZE)) + (i << (SHIFT_FOR_WORD)), value);
		}
	} else {
		/* begin storeInteger:ofObject:withValue: */
		if (
# ifdef SQ_HOST32  // cast to int for 64 bit image on 32 bit host
			(((((int) ((evtBuf[1]) & MillisecondClockMask))) ^ ((((int) ((evtBuf[1]) & MillisecondClockMask))) << 1)) >= 0)
# else
			((((evtBuf[1]) & MillisecondClockMask) >= -1073741824) && (((evtBuf[1]) & MillisecondClockMask) <= 1073741823))
# endif  // SQ_HOST32
		) {
			longAtput((arg + (BASE_HEADER_SIZE)) + (1 << (SHIFT_FOR_WORD)), ((((evtBuf[1]) & MillisecondClockMask) << 1) | 1));
		} else {
			/* begin primitiveFail */
			foo->successFlag = 0;
		}
		if (!(foo->successFlag)) {
			return null;
		}
		for (i = 2; i <= 7; i += 1) {
			value = evtBuf[i];
			if (
# ifdef SQ_HOST32  // cast to int for 64 bit image on 32 bit host
				(((((int) value)) ^ ((((int) value)) << 1)) >= 0)
# else
				((value >= -1073741824) && (value <= 1073741823))
# endif  // SQ_HOST32
			) {
				/* begin storeInteger:ofObject:withValue: */
				if (
# ifdef SQ_HOST32  // cast to int for 64 bit image on 32 bit host
					(((((int) value)) ^ ((((int) value)) << 1)) >= 0)
# else
					((value >= -1073741824) && (value <= 1073741823))
# endif  // SQ_HOST32
				) {
					longAtput((arg + (BASE_HEADER_SIZE)) + (i << (SHIFT_FOR_WORD)), ((value << 1) | 1));
				} else {
					/* begin primitiveFail */
					foo->successFlag = 0;
				}
			} else {
				/* begin pushRemappableOop: */
				foo->remapBuffer[(foo->remapBufferCount += 1)] = arg;
				value = positive32BitIntegerFor(value);
				/* begin popRemappableOop */
				oop = foo->remapBuffer[foo->remapBufferCount];
				foo->remapBufferCount -= 1;
				arg = oop;
				/* begin storePointer:ofObject:withValue: */
				if ((((usqInt) arg)) < (((usqInt) foo->youngStart))) {
					possibleRootStoreIntovalue(arg, value);
				}
				longAtput((arg + (BASE_HEADER_SIZE)) + (i << (SHIFT_FOR_WORD)), value);
			}
		}
	}
	if (!(foo->successFlag)) {
		return null;
	}
	/* begin pop: */
	foo->stackPointer -= 1 * (BYTES_PER_WORD);
}

sqInt primitiveGreaterOrEqual(void) {
register struct foo * foo = &fum;
    sqInt integerArgument;
    sqInt integerReceiver;
    sqInt sp;
    sqInt sp1;
    sqInt integerPointer;
    sqInt top;
    sqInt integerPointer1;
    sqInt top1;

	/* begin popInteger */
	/* begin popStack */
	top = longAt(foo->stackPointer);
	foo->stackPointer -= BYTES_PER_WORD;
	integerPointer = top;
	/* begin checkedIntegerValueOf: */
	if ((integerPointer & 1)) {
		integerArgument = (integerPointer >> 1);
		goto l1;
	} else {
		/* begin primitiveFail */
		foo->successFlag = 0;
		integerArgument = 0;
		goto l1;
	}
	integerArgument = null;
l1:	/* end popInteger */;
	/* begin popInteger */
	/* begin popStack */
	top1 = longAt(foo->stackPointer);
	foo->stackPointer -= BYTES_PER_WORD;
	integerPointer1 = top1;
	/* begin checkedIntegerValueOf: */
	if ((integerPointer1 & 1)) {
		integerReceiver = (integerPointer1 >> 1);
		goto l2;
	} else {
		/* begin primitiveFail */
		foo->successFlag = 0;
		integerReceiver = 0;
		goto l2;
	}
	integerReceiver = null;
l2:	/* end popInteger */;
	/* begin checkBooleanResult: */
	if (foo->successFlag) {
		/* begin pushBool: */
		if (integerReceiver >= integerArgument) {
			/* begin push: */
			longAtput(sp = foo->stackPointer + (BYTES_PER_WORD), foo->trueObj);
			foo->stackPointer = sp;
		} else {
			/* begin push: */
			longAtput(sp1 = foo->stackPointer + (BYTES_PER_WORD), foo->falseObj);
			foo->stackPointer = sp1;
		}
	} else {
		/* begin unPop: */
		foo->stackPointer += 2 * (BYTES_PER_WORD);
	}
}


/*	Primitive comparison operations for large integers in 64 bit range */

EXPORT(sqInt) primitiveGreaterOrEqualLargeIntegers(void) {
register struct foo * foo = &fum;
    sqLong integerArg;
    sqLong integerRcvr;
    sqInt sp;
    sqInt sp1;

	integerArg = signed64BitValueOf(longAt(foo->stackPointer - (0 * (BYTES_PER_WORD))));
	integerRcvr = signed64BitValueOf(longAt(foo->stackPointer - (1 * (BYTES_PER_WORD))));
	if (foo->successFlag) {
		/* begin pop: */
		foo->stackPointer -= 2 * (BYTES_PER_WORD);
		/* begin pushBool: */
		if (integerRcvr >= integerArg) {
			/* begin push: */
			longAtput(sp = foo->stackPointer + (BYTES_PER_WORD), foo->trueObj);
			foo->stackPointer = sp;
		} else {
			/* begin push: */
			longAtput(sp1 = foo->stackPointer + (BYTES_PER_WORD), foo->falseObj);
			foo->stackPointer = sp1;
		}
	}
}

sqInt primitiveGreaterThan(void) {
register struct foo * foo = &fum;
    sqInt integerArgument;
    sqInt integerReceiver;
    sqInt sp;
    sqInt sp1;
    sqInt integerPointer;
    sqInt top;
    sqInt integerPointer1;
    sqInt top1;

	/* begin popInteger */
	/* begin popStack */
	top = longAt(foo->stackPointer);
	foo->stackPointer -= BYTES_PER_WORD;
	integerPointer = top;
	/* begin checkedIntegerValueOf: */
	if ((integerPointer & 1)) {
		integerArgument = (integerPointer >> 1);
		goto l1;
	} else {
		/* begin primitiveFail */
		foo->successFlag = 0;
		integerArgument = 0;
		goto l1;
	}
	integerArgument = null;
l1:	/* end popInteger */;
	/* begin popInteger */
	/* begin popStack */
	top1 = longAt(foo->stackPointer);
	foo->stackPointer -= BYTES_PER_WORD;
	integerPointer1 = top1;
	/* begin checkedIntegerValueOf: */
	if ((integerPointer1 & 1)) {
		integerReceiver = (integerPointer1 >> 1);
		goto l2;
	} else {
		/* begin primitiveFail */
		foo->successFlag = 0;
		integerReceiver = 0;
		goto l2;
	}
	integerReceiver = null;
l2:	/* end popInteger */;
	/* begin checkBooleanResult: */
	if (foo->successFlag) {
		/* begin pushBool: */
		if (integerReceiver > integerArgument) {
			/* begin push: */
			longAtput(sp = foo->stackPointer + (BYTES_PER_WORD), foo->trueObj);
			foo->stackPointer = sp;
		} else {
			/* begin push: */
			longAtput(sp1 = foo->stackPointer + (BYTES_PER_WORD), foo->falseObj);
			foo->stackPointer = sp1;
		}
	} else {
		/* begin unPop: */
		foo->stackPointer += 2 * (BYTES_PER_WORD);
	}
}


/*	Primitive comparison operations for large integers in 64 bit range */

EXPORT(sqInt) primitiveGreaterThanLargeIntegers(void) {
register struct foo * foo = &fum;
    sqLong integerArg;
    sqLong integerRcvr;
    sqInt sp;
    sqInt sp1;

	integerArg = signed64BitValueOf(longAt(foo->stackPointer - (0 * (BYTES_PER_WORD))));
	integerRcvr = signed64BitValueOf(longAt(foo->stackPointer - (1 * (BYTES_PER_WORD))));
	if (foo->successFlag) {
		/* begin pop: */
		foo->stackPointer -= 2 * (BYTES_PER_WORD);
		/* begin pushBool: */
		if (integerRcvr > integerArg) {
			/* begin push: */
			longAtput(sp = foo->stackPointer + (BYTES_PER_WORD), foo->trueObj);
			foo->stackPointer = sp;
		} else {
			/* begin push: */
			longAtput(sp1 = foo->stackPointer + (BYTES_PER_WORD), foo->falseObj);
			foo->stackPointer = sp1;
		}
	}
}


/*	Answer an integer identifying the type of image. The image version number may
	identify the format of the image (e.g. 32 or 64-bit word size) or specific requirements
	of the image (e.g. block closure support required).
	
	This is a named (not numbered) primitive in the null module (ie the VM) */

EXPORT(sqInt) primitiveImageFormatVersion(void) {
register struct foo * foo = &fum;
    sqInt oop;
    sqInt sp;

	/* begin pop:thenPush: */
	oop = positive32BitIntegerFor(imageFormatVersionNumber);
	longAtput(sp = foo->stackPointer - ((1 - 1) * (BYTES_PER_WORD)), oop);
	foo->stackPointer = sp;
}


/*	When called with a single string argument, record the string as the current image file name. When called with zero arguments, return a string containing the current image file name. */

sqInt primitiveImageName(void) {
register struct foo * foo = &fum;
    sqInt okToRename;
    sqInt s;
    void *sCRIfn;
    sqInt sz;
    sqInt sp;
    sqInt classOop;
    sqInt ccIndex;
    sqInt cl;
    sqInt oop1;
    sqInt oop2;
    sqInt oop;

	if (foo->argumentCount == 1) {

		/* If the security plugin can be loaded, use it to check for rename permission.
		If not, assume it's ok */

		sCRIfn = ioLoadFunctionFrom("secCanRenameImage", "SecurityPlugin");
		if (sCRIfn != 0) {
			okToRename =  ((sqInt (*)(void))sCRIfn)();
			if (!(okToRename)) {
				/* begin primitiveFail */
				foo->successFlag = 0;
				return null;
			}
		}
		s = longAt(foo->stackPointer);
		/* begin assertClassOf:is: */
		/* begin fetchPointer:ofObject: */
		oop = foo->specialObjectsOop;
		classOop = longAt((oop + (BASE_HEADER_SIZE)) + (ClassString << (SHIFT_FOR_WORD)));
		if ((s & 1)) {
			foo->successFlag = 0;
			goto l1;
		}
		ccIndex = (((usqInt) (longAt(s))) >> 12) & 31;
		if (ccIndex == 0) {
			cl = (longAt(s - (BASE_HEADER_SIZE))) & (ALL_BUT_TYPE_MASK);
		} else {
			/* begin fetchPointer:ofObject: */
			/* begin fetchPointer:ofObject: */
			oop2 = foo->specialObjectsOop;
			oop1 = longAt((oop2 + (BASE_HEADER_SIZE)) + (CompactClasses << (SHIFT_FOR_WORD)));
			cl = longAt((oop1 + (BASE_HEADER_SIZE)) + ((ccIndex - 1) << (SHIFT_FOR_WORD)));
		}
		/* begin success: */
		foo->successFlag = (cl == classOop) && foo->successFlag;
	l1:	/* end assertClassOf:is: */;
		if (foo->successFlag) {
			sz = stSizeOf(s);
			imageNamePutLength(s + (BASE_HEADER_SIZE), sz);
			/* begin pop: */
			foo->stackPointer -= 1 * (BYTES_PER_WORD);
		}
	} else {
		sz = imageNameSize();
		s = instantiateClassindexableSize(fetchPointerofObject(ClassString, foo->specialObjectsOop), sz);
		imageNameGetLength(s + (BASE_HEADER_SIZE), sz);
		/* begin pop: */
		foo->stackPointer -= 1 * (BYTES_PER_WORD);
		/* begin push: */
		longAtput(sp = foo->stackPointer + (BYTES_PER_WORD), s);
		foo->stackPointer = sp;
	}
}


/*	Do a quick, incremental garbage collection and return the number of bytes immediately available. (Note: more space may be made available by doing a full garbage collection. */

sqInt primitiveIncrementalGC(void) {
register struct foo * foo = &fum;
    sqInt object;
    sqInt sp;

	/* begin pop: */
	foo->stackPointer -= 1 * (BYTES_PER_WORD);
	incrementalGC();
	/* begin push: */
	object = positive64BitIntegerFor(((longAt(foo->freeBlock)) & (ALL_BUT_TYPE_MASK)) + (sqMemoryExtraBytesLeft(0)));
	longAtput(sp = foo->stackPointer + (BYTES_PER_WORD), object);
	foo->stackPointer = sp;
}


/*	Note: We now have 10 bits of primitive index, but they are in two places
	for temporary backward compatibility.  The time to unpack is negligible,
	since the reconstituted full index is stored in the method cache. */

sqInt primitiveIndexOf(sqInt methodPointer) {
    sqInt primBits;

	primBits = (((usqInt) (longAt((methodPointer + (BASE_HEADER_SIZE)) + (HeaderIndex << (SHIFT_FOR_WORD))))) >> 1) & 268435967;
	return (primBits & 511) + (((usqInt) primBits) >> 19);
}


/*	Register the input semaphore. The argument is an index into the ExternalObjectsArray part of the specialObjectsArray and must have been allocated via 'Smalltalk registerExternalObject: the Semaphore'  */

sqInt primitiveInputSemaphore(void) {
register struct foo * foo = &fum;
    sqInt arg;

	arg = longAt(foo->stackPointer);
	if ((arg & 1)) {
		ioSetInputSemaphore((arg >> 1));
		if (foo->successFlag) {
			/* begin pop: */
			foo->stackPointer -= 1 * (BYTES_PER_WORD);
		}
		return null;
	}
}


/*	Return an integer indicating the reason for the most recent input interrupt. */

sqInt primitiveInputWord(void) {
register struct foo * foo = &fum;
    sqInt sp;

	/* begin pop:thenPushInteger: */
	longAtput(sp = foo->stackPointer - ((1 - 1) * (BYTES_PER_WORD)), ((0 << 1) | 1));
	foo->stackPointer = sp;
}

sqInt primitiveInstVarAt(void) {
register struct foo * foo = &fum;
    sqInt fixedFields;
    sqInt fmt;
    sqInt hdr;
    sqInt index;
    sqInt rcvr;
    sqInt totalLength;
    sqInt value;
    sqInt sp;
    sqInt sz;
    sqInt integerPointer;
    sqInt class;
    sqInt classFormat;
    sqInt ccIndex;
    sqInt oop1;
    sqInt oop2;
    sqInt oop3;

	/* begin stackIntegerValue: */
	integerPointer = longAt(foo->stackPointer - (0 * (BYTES_PER_WORD)));
	/* begin checkedIntegerValueOf: */
	if ((integerPointer & 1)) {
		index = (integerPointer >> 1);
		goto l3;
	} else {
		/* begin primitiveFail */
		foo->successFlag = 0;
		index = 0;
		goto l3;
	}
	index = null;
l3:	/* end stackIntegerValue: */;
	rcvr = longAt(foo->stackPointer - (1 * (BYTES_PER_WORD)));
	if (foo->successFlag) {
		hdr = longAt(rcvr);
		fmt = (((usqInt) hdr) >> 8) & 15;
		/* begin lengthOf:baseHeader:format: */
		if ((hdr & TypeMask) == HeaderTypeSizeAndClass) {
			sz = (longAt(rcvr - ((BYTES_PER_WORD) * 2))) & (LONG_SIZE_MASK);
		} else {
			sz = hdr & (SIZE_MASK);
		}
		sz -= hdr & (SIZE_4_BIT);
		if (fmt <= 4) {
			totalLength = ((usqInt) (sz - (BASE_HEADER_SIZE))) >> (SHIFT_FOR_WORD);
			goto l1;
		}
		if (fmt < 8) {
			totalLength = ((usqInt) (sz - (BASE_HEADER_SIZE))) >> 2;
			goto l1;
		} else {
			totalLength = (sz - (BASE_HEADER_SIZE)) - (fmt & 3);
			goto l1;
		}
	l1:	/* end lengthOf:baseHeader:format: */;
		/* begin fixedFieldsOf:format:length: */
		if ((fmt > 4) || (fmt == 2)) {
			fixedFields = 0;
			goto l5;
		}
		if (fmt < 2) {
			fixedFields = totalLength;
			goto l5;
		}
		/* begin fetchClassOf: */
		if ((rcvr & 1)) {
			/* begin fetchPointer:ofObject: */
			oop1 = foo->specialObjectsOop;
			class = longAt((oop1 + (BASE_HEADER_SIZE)) + (ClassInteger << (SHIFT_FOR_WORD)));
			goto l4;
		}
		ccIndex = (((usqInt) (longAt(rcvr))) >> 12) & 31;
		if (ccIndex == 0) {
			class = (longAt(rcvr - (BASE_HEADER_SIZE))) & (ALL_BUT_TYPE_MASK);
			goto l4;
		} else {
			/* begin fetchPointer:ofObject: */
			/* begin fetchPointer:ofObject: */
			oop3 = foo->specialObjectsOop;
			oop2 = longAt((oop3 + (BASE_HEADER_SIZE)) + (CompactClasses << (SHIFT_FOR_WORD)));
			class = longAt((oop2 + (BASE_HEADER_SIZE)) + ((ccIndex - 1) << (SHIFT_FOR_WORD)));
			goto l4;
		}
	l4:	/* end fetchClassOf: */;
		classFormat = (longAt((class + (BASE_HEADER_SIZE)) + (InstanceSpecificationIndex << (SHIFT_FOR_WORD)))) - 1;
		fixedFields = (((((usqInt) classFormat) >> 11) & 192) + ((((usqInt) classFormat) >> 2) & 63)) - 1;
	l5:	/* end fixedFieldsOf:format:length: */;
		if (!((index >= 1) && (index <= fixedFields))) {
			foo->successFlag = 0;
		}
	}
	if (foo->successFlag) {
		/* begin subscript:with:format: */
		if (fmt <= 4) {
			value = longAt((rcvr + (BASE_HEADER_SIZE)) + ((index - 1) << (SHIFT_FOR_WORD)));
			goto l2;
		}
		if (fmt < 8) {
			value = positive32BitIntegerFor(long32At((rcvr + (BASE_HEADER_SIZE)) + ((index - 1) << 2)));
			goto l2;
		} else {
			value = (((byteAt((rcvr + (BASE_HEADER_SIZE)) + (index - 1))) << 1) | 1);
			goto l2;
		}
	l2:	/* end subscript:with:format: */;
	}
	if (foo->successFlag) {
		/* begin pop:thenPush: */
		longAtput(sp = foo->stackPointer - (((foo->argumentCount + 1) - 1) * (BYTES_PER_WORD)), value);
		foo->stackPointer = sp;
	}
}

sqInt primitiveInstVarAtPut(void) {
register struct foo * foo = &fum;
    sqInt fixedFields;
    sqInt fmt;
    sqInt hdr;
    sqInt index;
    sqInt newValue;
    sqInt rcvr;
    sqInt totalLength;
    sqInt sp;
    sqInt sz;
    sqInt valueToStore;
    sqInt integerPointer;
    sqInt class;
    sqInt classFormat;
    sqInt ccIndex;
    sqInt oop1;
    sqInt oop2;
    sqInt oop3;

	newValue = longAt(foo->stackPointer);
	/* begin stackIntegerValue: */
	integerPointer = longAt(foo->stackPointer - (1 * (BYTES_PER_WORD)));
	/* begin checkedIntegerValueOf: */
	if ((integerPointer & 1)) {
		index = (integerPointer >> 1);
		goto l2;
	} else {
		/* begin primitiveFail */
		foo->successFlag = 0;
		index = 0;
		goto l2;
	}
	index = null;
l2:	/* end stackIntegerValue: */;
	rcvr = longAt(foo->stackPointer - (2 * (BYTES_PER_WORD)));
	if (foo->successFlag) {
		hdr = longAt(rcvr);
		fmt = (((usqInt) hdr) >> 8) & 15;
		/* begin lengthOf:baseHeader:format: */
		if ((hdr & TypeMask) == HeaderTypeSizeAndClass) {
			sz = (longAt(rcvr - ((BYTES_PER_WORD) * 2))) & (LONG_SIZE_MASK);
		} else {
			sz = hdr & (SIZE_MASK);
		}
		sz -= hdr & (SIZE_4_BIT);
		if (fmt <= 4) {
			totalLength = ((usqInt) (sz - (BASE_HEADER_SIZE))) >> (SHIFT_FOR_WORD);
			goto l1;
		}
		if (fmt < 8) {
			totalLength = ((usqInt) (sz - (BASE_HEADER_SIZE))) >> 2;
			goto l1;
		} else {
			totalLength = (sz - (BASE_HEADER_SIZE)) - (fmt & 3);
			goto l1;
		}
	l1:	/* end lengthOf:baseHeader:format: */;
		/* begin fixedFieldsOf:format:length: */
		if ((fmt > 4) || (fmt == 2)) {
			fixedFields = 0;
			goto l4;
		}
		if (fmt < 2) {
			fixedFields = totalLength;
			goto l4;
		}
		/* begin fetchClassOf: */
		if ((rcvr & 1)) {
			/* begin fetchPointer:ofObject: */
			oop1 = foo->specialObjectsOop;
			class = longAt((oop1 + (BASE_HEADER_SIZE)) + (ClassInteger << (SHIFT_FOR_WORD)));
			goto l3;
		}
		ccIndex = (((usqInt) (longAt(rcvr))) >> 12) & 31;
		if (ccIndex == 0) {
			class = (longAt(rcvr - (BASE_HEADER_SIZE))) & (ALL_BUT_TYPE_MASK);
			goto l3;
		} else {
			/* begin fetchPointer:ofObject: */
			/* begin fetchPointer:ofObject: */
			oop3 = foo->specialObjectsOop;
			oop2 = longAt((oop3 + (BASE_HEADER_SIZE)) + (CompactClasses << (SHIFT_FOR_WORD)));
			class = longAt((oop2 + (BASE_HEADER_SIZE)) + ((ccIndex - 1) << (SHIFT_FOR_WORD)));
			goto l3;
		}
	l3:	/* end fetchClassOf: */;
		classFormat = (longAt((class + (BASE_HEADER_SIZE)) + (InstanceSpecificationIndex << (SHIFT_FOR_WORD)))) - 1;
		fixedFields = (((((usqInt) classFormat) >> 11) & 192) + ((((usqInt) classFormat) >> 2) & 63)) - 1;
	l4:	/* end fixedFieldsOf:format:length: */;
		if (!((index >= 1) && (index <= fixedFields))) {
			foo->successFlag = 0;
		}
	}
	if (foo->successFlag) {
		/* begin subscript:with:storing:format: */
		if (fmt <= 4) {
			/* begin storePointer:ofObject:withValue: */
			if ((((usqInt) rcvr)) < (((usqInt) foo->youngStart))) {
				possibleRootStoreIntovalue(rcvr, newValue);
			}
			longAtput((rcvr + (BASE_HEADER_SIZE)) + ((index - 1) << (SHIFT_FOR_WORD)), newValue);
		} else {
			if (fmt < 8) {
				valueToStore = positive32BitValueOf(newValue);
				if (foo->successFlag) {
					long32Atput((rcvr + (BASE_HEADER_SIZE)) + ((index - 1) << 2), valueToStore);
				}
			} else {
				if (!((newValue & 1))) {
					foo->successFlag = 0;
				}
				valueToStore = (newValue >> 1);
				if (!((valueToStore >= 0) && (valueToStore <= 255))) {
					foo->successFlag = 0;
				}
				if (foo->successFlag) {
					byteAtput((rcvr + (BASE_HEADER_SIZE)) + (index - 1), valueToStore);
				}
			}
		}
	}
	if (foo->successFlag) {
		/* begin pop:thenPush: */
		longAtput(sp = foo->stackPointer - (((foo->argumentCount + 1) - 1) * (BYTES_PER_WORD)), newValue);
		foo->stackPointer = sp;
	}
}


/*	Note:  this primitive has been decommissioned.  It is only here for short-term compatibility with an internal 2.3beta-d image that used this.  It did not save much time and it complicated several things.  Plus Jitter will do it right anyway. */

sqInt primitiveInstVarsPutFromStack(void) {
register struct foo * foo = &fum;
    sqInt i;
    sqInt offsetBits;
    sqInt rcvr;
    sqInt valuePointer;


	/* Mark dirty so stores below can be unchecked */

	rcvr = longAt(foo->stackPointer - (foo->argumentCount * (BYTES_PER_WORD)));
	if ((((usqInt) rcvr)) < (((usqInt) foo->youngStart))) {
		beRootIfOld(rcvr);
	}
	for (i = 0; i <= (foo->argumentCount - 1); i += 1) {
		if ((i & 3) == 0) {
			offsetBits = positive32BitValueOf(literalofMethod(((sqInt) i >> 2), foo->newMethod));
		}
		/* begin storePointerUnchecked:ofObject:withValue: */
		valuePointer = longAt(foo->stackPointer - (i * (BYTES_PER_WORD)));
		longAtput((rcvr + (BASE_HEADER_SIZE)) + ((offsetBits & 255) << (SHIFT_FOR_WORD)), valuePointer);
		offsetBits = ((usqInt) offsetBits) >> 8;
	}
	/* begin pop: */
	foo->stackPointer -= foo->argumentCount * (BYTES_PER_WORD);
}


/*	Return the 32bit signed integer contents of a words receiver */

sqInt primitiveIntegerAt(void) {
register struct foo * foo = &fum;
    sqInt addr;
    sqInt index;
    int intValue;
    sqInt rcvr;
    sqInt sz;
    sqInt value;
    sqInt object;
    sqInt sp;
    sqInt header;
    sqInt successValue;
    sqInt sp1;
    sqInt sz1;
    sqInt integerPointer;

	/* begin stackIntegerValue: */
	integerPointer = longAt(foo->stackPointer - (0 * (BYTES_PER_WORD)));
	/* begin checkedIntegerValueOf: */
	if ((integerPointer & 1)) {
		index = (integerPointer >> 1);
		goto l2;
	} else {
		/* begin primitiveFail */
		foo->successFlag = 0;
		index = 0;
		goto l2;
	}
	index = null;
l2:	/* end stackIntegerValue: */;
	rcvr = longAt(foo->stackPointer - (1 * (BYTES_PER_WORD)));
	if ((rcvr & 1)) {
		/* begin success: */
		foo->successFlag = 0 && foo->successFlag;
		return null;
	}
	if (!(((rcvr & 1) == 0) && (((((usqInt) (longAt(rcvr))) >> 8) & 15) == 6))) {
		/* begin success: */
		foo->successFlag = 0 && foo->successFlag;
		return null;
	}
	/* begin lengthOf: */
	header = longAt(rcvr);
	/* begin lengthOf:baseHeader:format: */
	if ((header & TypeMask) == HeaderTypeSizeAndClass) {
		sz1 = (longAt(rcvr - ((BYTES_PER_WORD) * 2))) & (LONG_SIZE_MASK);
	} else {
		sz1 = header & (SIZE_MASK);
	}
	sz1 -= header & (SIZE_4_BIT);
	if (((((usqInt) header) >> 8) & 15) <= 4) {
		sz = ((usqInt) (sz1 - (BASE_HEADER_SIZE))) >> (SHIFT_FOR_WORD);
		goto l1;
	}
	if (((((usqInt) header) >> 8) & 15) < 8) {
		sz = ((usqInt) (sz1 - (BASE_HEADER_SIZE))) >> 2;
		goto l1;
	} else {
		sz = (sz1 - (BASE_HEADER_SIZE)) - (((((usqInt) header) >> 8) & 15) & 3);
		goto l1;
	}
l1:	/* end lengthOf:baseHeader:format: */;
	/* begin success: */
	successValue = (index >= 1) && (index <= sz);
	foo->successFlag = successValue && foo->successFlag;
	if (foo->successFlag) {

		/* for zero indexing */

		addr = ((rcvr + (BASE_HEADER_SIZE)) - 4) + (index * 4);
		value = intAt(addr);
		/* begin pop: */
		foo->stackPointer -= 2 * (BYTES_PER_WORD);
		if (
# ifdef SQ_HOST32  // cast to int for 64 bit image on 32 bit host
			(((((int) value)) ^ ((((int) value)) << 1)) >= 0)
# else
			((value >= -1073741824) && (value <= 1073741823))
# endif  // SQ_HOST32
		) {
			/* begin pushInteger: */
			/* begin push: */
			longAtput(sp1 = foo->stackPointer + (BYTES_PER_WORD), ((value << 1) | 1));
			foo->stackPointer = sp1;
		} else {

			/* 32 bit int may have been stored in 32 or 64 bit sqInt */

			intValue = value;
			/* begin push: */
			object = signed32BitIntegerFor(intValue);
			longAtput(sp = foo->stackPointer + (BYTES_PER_WORD), object);
			foo->stackPointer = sp;
		}
	}
}


/*	Return the 32bit signed integer contents of a words receiver */

sqInt primitiveIntegerAtPut(void) {
register struct foo * foo = &fum;
    sqInt addr;
    sqInt index;
    sqInt rcvr;
    sqInt sz;
    sqInt value;
    sqInt valueOop;
    sqInt sp;
    sqInt header;
    sqInt sz1;
    sqInt integerPointer;

	valueOop = longAt(foo->stackPointer - (0 * (BYTES_PER_WORD)));
	/* begin stackIntegerValue: */
	integerPointer = longAt(foo->stackPointer - (1 * (BYTES_PER_WORD)));
	/* begin checkedIntegerValueOf: */
	if ((integerPointer & 1)) {
		index = (integerPointer >> 1);
		goto l2;
	} else {
		/* begin primitiveFail */
		foo->successFlag = 0;
		index = 0;
		goto l2;
	}
	index = null;
l2:	/* end stackIntegerValue: */;
	rcvr = longAt(foo->stackPointer - (2 * (BYTES_PER_WORD)));
	if ((rcvr & 1)) {
		/* begin success: */
		foo->successFlag = 0 && foo->successFlag;
		return null;
	}
	if (!(((rcvr & 1) == 0) && (((((usqInt) (longAt(rcvr))) >> 8) & 15) == 6))) {
		/* begin success: */
		foo->successFlag = 0 && foo->successFlag;
		return null;
	}
	/* begin lengthOf: */
	header = longAt(rcvr);
	/* begin lengthOf:baseHeader:format: */
	if ((header & TypeMask) == HeaderTypeSizeAndClass) {
		sz1 = (longAt(rcvr - ((BYTES_PER_WORD) * 2))) & (LONG_SIZE_MASK);
	} else {
		sz1 = header & (SIZE_MASK);
	}
	sz1 -= header & (SIZE_4_BIT);
	if (((((usqInt) header) >> 8) & 15) <= 4) {
		sz = ((usqInt) (sz1 - (BASE_HEADER_SIZE))) >> (SHIFT_FOR_WORD);
		goto l1;
	}
	if (((((usqInt) header) >> 8) & 15) < 8) {
		sz = ((usqInt) (sz1 - (BASE_HEADER_SIZE))) >> 2;
		goto l1;
	} else {
		sz = (sz1 - (BASE_HEADER_SIZE)) - (((((usqInt) header) >> 8) & 15) & 3);
		goto l1;
	}
l1:	/* end lengthOf:baseHeader:format: */;
	if (!((index >= 1) && (index <= sz))) {
		/* begin success: */
		foo->successFlag = 0 && foo->successFlag;
		return null;
	}
	if ((valueOop & 1)) {
		value = (valueOop >> 1);
	} else {
		value = signed32BitValueOf(valueOop);
	}
	if (foo->successFlag) {

		/* for zero indexing */

		addr = ((rcvr + (BASE_HEADER_SIZE)) - 4) + (index * 4);
		value = intAtput(addr, value);
		/* begin pop:thenPush: */
		longAtput(sp = foo->stackPointer - ((3 - 1) * (BYTES_PER_WORD)), valueOop);
		foo->stackPointer = sp;
	}
}


/*	Answer a string corresponding to the version of the interpreter source. This
	represents the version level of the Smalltalk source code (interpreter and various
	plugins) that is translated to C by a CCodeGenerator, as distinct from the external
	platform source code, typically written in C and managed separately for each platform.
	This is a named (not numbered) primitive in the null module (ie the VM) */

EXPORT(sqInt) primitiveInterpreterSourceVersion(void) {
register struct foo * foo = &fum;
    char *cString;
    sqInt len;
    void * p;
    sqInt versionString;
    sqInt sp;

	cString = InterpreterSourceVersion;
	len = strlen(cString);
	versionString = instantiateClassindexableSize(fetchPointerofObject(ClassString, foo->specialObjectsOop), len);
	/* begin arrayValueOf: */
	if ((!((versionString & 1))) && (((versionString & 1) == 0) && (isWordsOrBytesNonInt(versionString)))) {
		p = pointerForOop(versionString + (BASE_HEADER_SIZE));
		goto l1;
	}
	/* begin primitiveFail */
	foo->successFlag = 0;
l1:	/* end arrayValueOf: */;
	strncpy(p, cString, len);
	/* begin pop:thenPush: */
	longAtput(sp = foo->stackPointer - ((1 - 1) * (BYTES_PER_WORD)), versionString);
	foo->stackPointer = sp;
}


/*	Register the user interrupt semaphore. If the argument is 
	not a Semaphore, unregister the current interrupt 
	semaphore.  */

sqInt primitiveInterruptSemaphore(void) {
register struct foo * foo = &fum;
    sqInt arg;
    sqInt top;
    sqInt oop;
    sqInt oop1;
    sqInt valuePointer;

	/* begin popStack */
	top = longAt(foo->stackPointer);
	foo->stackPointer -= BYTES_PER_WORD;
	arg = top;
	if ((fetchClassOf(arg)) == (fetchPointerofObject(ClassSemaphore, foo->specialObjectsOop))) {
		/* begin storePointer:ofObject:withValue: */
		oop = foo->specialObjectsOop;
		if ((((usqInt) oop)) < (((usqInt) foo->youngStart))) {
			possibleRootStoreIntovalue(oop, arg);
		}
		longAtput((oop + (BASE_HEADER_SIZE)) + (TheInterruptSemaphore << (SHIFT_FOR_WORD)), arg);
	} else {
		/* begin storePointer:ofObject:withValue: */
		oop1 = foo->specialObjectsOop;
		valuePointer = foo->nilObj;
		if ((((usqInt) oop1)) < (((usqInt) foo->youngStart))) {
			possibleRootStoreIntovalue(oop1, valuePointer);
		}
		longAtput((oop1 + (BASE_HEADER_SIZE)) + (TheInterruptSemaphore << (SHIFT_FOR_WORD)), valuePointer);
	}
}


/*	Primitive. 'Invoke' an object like a function, sending the special message 
		run: originalSelector with: arguments in: aReceiver.
	 */

sqInt primitiveInvokeObjectAsMethod(void) {
register struct foo * foo = &fum;
    sqInt lookupClass;
    sqInt newReceiver;
    sqInt runArgs;
    sqInt runReceiver;
    sqInt runSelector;
    sqInt oop;
    sqInt sp;
    sqInt sp1;
    sqInt sp2;
    sqInt sp3;
    sqInt ccIndex;
    sqInt oop1;
    sqInt oop2;
    sqInt count;
    sqInt src;
    sqInt in;
    sqInt lastIn;
    sqInt out;
    sqInt oop3;

	runArgs = instantiateClassindexableSize(fetchPointerofObject(ClassArray, foo->specialObjectsOop), foo->argumentCount);
	beRootIfOld(runArgs);
	/* begin transfer:from:to: */
	count = foo->argumentCount;
	src = foo->stackPointer - ((foo->argumentCount - 1) * (BYTES_PER_WORD));
	flag("Dan");
	in = src - (BYTES_PER_WORD);
	lastIn = in + (count * (BYTES_PER_WORD));
	out = (runArgs + (BASE_HEADER_SIZE)) - (BYTES_PER_WORD);
	while ((((usqInt) in)) < (((usqInt) lastIn))) {
		longAtput(out += BYTES_PER_WORD, longAt(in += BYTES_PER_WORD));
	}
	runSelector = foo->messageSelector;
	runReceiver = longAt(foo->stackPointer - (foo->argumentCount * (BYTES_PER_WORD)));
	/* begin pop: */
	foo->stackPointer -= (foo->argumentCount + 1) * (BYTES_PER_WORD);
	newReceiver = foo->newMethod;
	/* begin fetchPointer:ofObject: */
	oop = foo->specialObjectsOop;
	foo->messageSelector = longAt((oop + (BASE_HEADER_SIZE)) + (SelectorRunWithIn << (SHIFT_FOR_WORD)));
	foo->argumentCount = 3;
	/* begin push: */
	longAtput(sp = foo->stackPointer + (BYTES_PER_WORD), newReceiver);
	foo->stackPointer = sp;
	/* begin push: */
	longAtput(sp1 = foo->stackPointer + (BYTES_PER_WORD), runSelector);
	foo->stackPointer = sp1;
	/* begin push: */
	longAtput(sp2 = foo->stackPointer + (BYTES_PER_WORD), runArgs);
	foo->stackPointer = sp2;
	/* begin push: */
	longAtput(sp3 = foo->stackPointer + (BYTES_PER_WORD), runReceiver);
	foo->stackPointer = sp3;
	/* begin fetchClassOf: */
	if ((newReceiver & 1)) {
		/* begin fetchPointer:ofObject: */
		oop1 = foo->specialObjectsOop;
		lookupClass = longAt((oop1 + (BASE_HEADER_SIZE)) + (ClassInteger << (SHIFT_FOR_WORD)));
		goto l1;
	}
	ccIndex = (((usqInt) (longAt(newReceiver))) >> 12) & 31;
	if (ccIndex == 0) {
		lookupClass = (longAt(newReceiver - (BASE_HEADER_SIZE))) & (ALL_BUT_TYPE_MASK);
		goto l1;
	} else {
		/* begin fetchPointer:ofObject: */
		/* begin fetchPointer:ofObject: */
		oop3 = foo->specialObjectsOop;
		oop2 = longAt((oop3 + (BASE_HEADER_SIZE)) + (CompactClasses << (SHIFT_FOR_WORD)));
		lookupClass = longAt((oop2 + (BASE_HEADER_SIZE)) + ((ccIndex - 1) << (SHIFT_FOR_WORD)));
		goto l1;
	}
l1:	/* end fetchClassOf: */;
	findNewMethodInClass(lookupClass);
	executeNewMethodFromCache();
	foo->successFlag = 1;
}


/*	Primitive. Answer whether the argument to the primitive is a root for young space */

EXPORT(sqInt) primitiveIsRoot(void) {
register struct foo * foo = &fum;
    sqInt oop;
    sqInt trueOrFalse;
    sqInt sp;
    sqInt sp1;
    sqInt oop1;

	/* begin stackObjectValue: */
	oop1 = longAt(foo->stackPointer - (0 * (BYTES_PER_WORD)));
	if ((oop1 & 1)) {
		/* begin primitiveFail */
		foo->successFlag = 0;
		oop = null;
		goto l1;
	}
	oop = oop1;
l1:	/* end stackObjectValue: */;
	if (foo->successFlag) {
		/* begin pop: */
		foo->stackPointer -= (foo->argumentCount + 1) * (BYTES_PER_WORD);
		/* begin pushBool: */
		trueOrFalse = (longAt(oop)) & (ROOT_BIT);
		if (trueOrFalse) {
			/* begin push: */
			longAtput(sp = foo->stackPointer + (BYTES_PER_WORD), foo->trueObj);
			foo->stackPointer = sp;
		} else {
			/* begin push: */
			longAtput(sp1 = foo->stackPointer + (BYTES_PER_WORD), foo->falseObj);
			foo->stackPointer = sp1;
		}
	}
}


/*	Primitive. Answer whether the argument to the primitive resides in young space. */

EXPORT(sqInt) primitiveIsYoung(void) {
register struct foo * foo = &fum;
    sqInt oop;
    sqInt trueOrFalse;
    sqInt sp;
    sqInt sp1;
    sqInt oop1;

	/* begin stackObjectValue: */
	oop1 = longAt(foo->stackPointer - (0 * (BYTES_PER_WORD)));
	if ((oop1 & 1)) {
		/* begin primitiveFail */
		foo->successFlag = 0;
		oop = null;
		goto l1;
	}
	oop = oop1;
l1:	/* end stackObjectValue: */;
	if (foo->successFlag) {
		/* begin pop: */
		foo->stackPointer -= (foo->argumentCount + 1) * (BYTES_PER_WORD);
		/* begin pushBool: */
		trueOrFalse = (((usqInt) oop)) >= (((usqInt) foo->youngStart));
		if (trueOrFalse) {
			/* begin push: */
			longAtput(sp = foo->stackPointer + (BYTES_PER_WORD), foo->trueObj);
			foo->stackPointer = sp;
		} else {
			/* begin push: */
			longAtput(sp1 = foo->stackPointer + (BYTES_PER_WORD), foo->falseObj);
			foo->stackPointer = sp1;
		}
	}
}


/*	Obsolete on virtually all platforms; old style input polling code.
	Return the next keycode and remove it from the input buffer. The low byte is the 8-bit ISO character. The next four bits are the Smalltalk modifier bits <cmd><option><ctrl><shift>. */

sqInt primitiveKbdNext(void) {
register struct foo * foo = &fum;
    sqInt keystrokeWord;
    sqInt sp;
    sqInt sp1;

	/* begin pop: */
	foo->stackPointer -= 1 * (BYTES_PER_WORD);
	keystrokeWord = ioGetKeystroke();
	if (keystrokeWord >= 0) {
		/* begin pushInteger: */
		/* begin push: */
		longAtput(sp1 = foo->stackPointer + (BYTES_PER_WORD), ((keystrokeWord << 1) | 1));
		foo->stackPointer = sp1;
	} else {
		/* begin push: */
		longAtput(sp = foo->stackPointer + (BYTES_PER_WORD), foo->nilObj);
		foo->stackPointer = sp;
	}
}


/*	Obsolete on virtually all platforms; old style input polling code.
	Return the next keycode and without removing it from the input buffer. The low byte is the 8-bit ISO character. The next four bits are the Smalltalk modifier bits <cmd><option><ctrl><shift>. */

sqInt primitiveKbdPeek(void) {
register struct foo * foo = &fum;
    sqInt keystrokeWord;
    sqInt sp;
    sqInt sp1;

	/* begin pop: */
	foo->stackPointer -= 1 * (BYTES_PER_WORD);
	keystrokeWord = ioPeekKeystroke();
	if (keystrokeWord >= 0) {
		/* begin pushInteger: */
		/* begin push: */
		longAtput(sp1 = foo->stackPointer + (BYTES_PER_WORD), ((keystrokeWord << 1) | 1));
		foo->stackPointer = sp1;
	} else {
		/* begin push: */
		longAtput(sp = foo->stackPointer + (BYTES_PER_WORD), foo->nilObj);
		foo->stackPointer = sp;
	}
}

sqInt primitiveLessOrEqual(void) {
register struct foo * foo = &fum;
    sqInt integerArgument;
    sqInt integerReceiver;
    sqInt sp;
    sqInt sp1;
    sqInt integerPointer;
    sqInt top;
    sqInt integerPointer1;
    sqInt top1;

	/* begin popInteger */
	/* begin popStack */
	top = longAt(foo->stackPointer);
	foo->stackPointer -= BYTES_PER_WORD;
	integerPointer = top;
	/* begin checkedIntegerValueOf: */
	if ((integerPointer & 1)) {
		integerArgument = (integerPointer >> 1);
		goto l1;
	} else {
		/* begin primitiveFail */
		foo->successFlag = 0;
		integerArgument = 0;
		goto l1;
	}
	integerArgument = null;
l1:	/* end popInteger */;
	/* begin popInteger */
	/* begin popStack */
	top1 = longAt(foo->stackPointer);
	foo->stackPointer -= BYTES_PER_WORD;
	integerPointer1 = top1;
	/* begin checkedIntegerValueOf: */
	if ((integerPointer1 & 1)) {
		integerReceiver = (integerPointer1 >> 1);
		goto l2;
	} else {
		/* begin primitiveFail */
		foo->successFlag = 0;
		integerReceiver = 0;
		goto l2;
	}
	integerReceiver = null;
l2:	/* end popInteger */;
	/* begin checkBooleanResult: */
	if (foo->successFlag) {
		/* begin pushBool: */
		if (integerReceiver <= integerArgument) {
			/* begin push: */
			longAtput(sp = foo->stackPointer + (BYTES_PER_WORD), foo->trueObj);
			foo->stackPointer = sp;
		} else {
			/* begin push: */
			longAtput(sp1 = foo->stackPointer + (BYTES_PER_WORD), foo->falseObj);
			foo->stackPointer = sp1;
		}
	} else {
		/* begin unPop: */
		foo->stackPointer += 2 * (BYTES_PER_WORD);
	}
}


/*	Primitive comparison operations for large integers in 64 bit range */

EXPORT(sqInt) primitiveLessOrEqualLargeIntegers(void) {
register struct foo * foo = &fum;
    sqLong integerArg;
    sqLong integerRcvr;
    sqInt sp;
    sqInt sp1;

	integerArg = signed64BitValueOf(longAt(foo->stackPointer - (0 * (BYTES_PER_WORD))));
	integerRcvr = signed64BitValueOf(longAt(foo->stackPointer - (1 * (BYTES_PER_WORD))));
	if (foo->successFlag) {
		/* begin pop: */
		foo->stackPointer -= 2 * (BYTES_PER_WORD);
		/* begin pushBool: */
		if (integerRcvr <= integerArg) {
			/* begin push: */
			longAtput(sp = foo->stackPointer + (BYTES_PER_WORD), foo->trueObj);
			foo->stackPointer = sp;
		} else {
			/* begin push: */
			longAtput(sp1 = foo->stackPointer + (BYTES_PER_WORD), foo->falseObj);
			foo->stackPointer = sp1;
		}
	}
}

sqInt primitiveLessThan(void) {
register struct foo * foo = &fum;
    sqInt integerArgument;
    sqInt integerReceiver;
    sqInt sp;
    sqInt sp1;
    sqInt integerPointer;
    sqInt top;
    sqInt integerPointer1;
    sqInt top1;

	/* begin popInteger */
	/* begin popStack */
	top = longAt(foo->stackPointer);
	foo->stackPointer -= BYTES_PER_WORD;
	integerPointer = top;
	/* begin checkedIntegerValueOf: */
	if ((integerPointer & 1)) {
		integerArgument = (integerPointer >> 1);
		goto l1;
	} else {
		/* begin primitiveFail */
		foo->successFlag = 0;
		integerArgument = 0;
		goto l1;
	}
	integerArgument = null;
l1:	/* end popInteger */;
	/* begin popInteger */
	/* begin popStack */
	top1 = longAt(foo->stackPointer);
	foo->stackPointer -= BYTES_PER_WORD;
	integerPointer1 = top1;
	/* begin checkedIntegerValueOf: */
	if ((integerPointer1 & 1)) {
		integerReceiver = (integerPointer1 >> 1);
		goto l2;
	} else {
		/* begin primitiveFail */
		foo->successFlag = 0;
		integerReceiver = 0;
		goto l2;
	}
	integerReceiver = null;
l2:	/* end popInteger */;
	/* begin checkBooleanResult: */
	if (foo->successFlag) {
		/* begin pushBool: */
		if (integerReceiver < integerArgument) {
			/* begin push: */
			longAtput(sp = foo->stackPointer + (BYTES_PER_WORD), foo->trueObj);
			foo->stackPointer = sp;
		} else {
			/* begin push: */
			longAtput(sp1 = foo->stackPointer + (BYTES_PER_WORD), foo->falseObj);
			foo->stackPointer = sp1;
		}
	} else {
		/* begin unPop: */
		foo->stackPointer += 2 * (BYTES_PER_WORD);
	}
}


/*	Primitive comparison operations for large integers in 64 bit range */

EXPORT(sqInt) primitiveLessThanLargeIntegers(void) {
register struct foo * foo = &fum;
    sqLong integerArg;
    sqLong integerRcvr;
    sqInt sp;
    sqInt sp1;

	integerArg = signed64BitValueOf(longAt(foo->stackPointer - (0 * (BYTES_PER_WORD))));
	integerRcvr = signed64BitValueOf(longAt(foo->stackPointer - (1 * (BYTES_PER_WORD))));
	if (foo->successFlag) {
		/* begin pop: */
		foo->stackPointer -= 2 * (BYTES_PER_WORD);
		/* begin pushBool: */
		if (integerRcvr < integerArg) {
			/* begin push: */
			longAtput(sp = foo->stackPointer + (BYTES_PER_WORD), foo->trueObj);
			foo->stackPointer = sp;
		} else {
			/* begin push: */
			longAtput(sp1 = foo->stackPointer + (BYTES_PER_WORD), foo->falseObj);
			foo->stackPointer = sp1;
		}
	}
}


/*	Primitive. Return the n-th builtin module name. */

sqInt primitiveListBuiltinModule(void) {
register struct foo * foo = &fum;
    sqInt i;
    sqInt index;
    sqInt length;
    char *moduleName;
    sqInt nameOop;
    sqInt sp;
    sqInt sp1;
    sqInt integerPointer;

	if (!(foo->argumentCount == 1)) {
		/* begin primitiveFail */
		foo->successFlag = 0;
		return null;
	}
	/* begin stackIntegerValue: */
	integerPointer = longAt(foo->stackPointer - (0 * (BYTES_PER_WORD)));
	/* begin checkedIntegerValueOf: */
	if ((integerPointer & 1)) {
		index = (integerPointer >> 1);
		goto l1;
	} else {
		/* begin primitiveFail */
		foo->successFlag = 0;
		index = 0;
		goto l1;
	}
	index = null;
l1:	/* end stackIntegerValue: */;
	if (index <= 0) {
		/* begin primitiveFail */
		foo->successFlag = 0;
		return null;
	}
	moduleName = ioListBuiltinModule(index);
	if (moduleName == null) {
		/* begin pop: */
		foo->stackPointer -= 2 * (BYTES_PER_WORD);
		/* begin push: */
		longAtput(sp = foo->stackPointer + (BYTES_PER_WORD), foo->nilObj);
		foo->stackPointer = sp;
		return null;
	}
	length = strlen(moduleName);
	nameOop = instantiateClassindexableSize(fetchPointerofObject(ClassString, foo->specialObjectsOop), length);
	for (i = 0; i <= (length - 1); i += 1) {
		byteAtput((nameOop + (BASE_HEADER_SIZE)) + i, moduleName[i]);
	}
	/* begin forceInterruptCheck */
	foo->interruptCheckCounter = -1000;
	foo->nextPollTick = 0;
	/* begin pop:thenPush: */
	longAtput(sp1 = foo->stackPointer - ((2 - 1) * (BYTES_PER_WORD)), nameOop);
	foo->stackPointer = sp1;
}


/*	Primitive. Return the n-th loaded external module name. */

sqInt primitiveListExternalModule(void) {
register struct foo * foo = &fum;
    sqInt i;
    sqInt index;
    sqInt length;
    char *moduleName;
    sqInt nameOop;
    sqInt sp;
    sqInt sp1;
    sqInt integerPointer;

	if (!(foo->argumentCount == 1)) {
		/* begin primitiveFail */
		foo->successFlag = 0;
		return null;
	}
	/* begin stackIntegerValue: */
	integerPointer = longAt(foo->stackPointer - (0 * (BYTES_PER_WORD)));
	/* begin checkedIntegerValueOf: */
	if ((integerPointer & 1)) {
		index = (integerPointer >> 1);
		goto l1;
	} else {
		/* begin primitiveFail */
		foo->successFlag = 0;
		index = 0;
		goto l1;
	}
	index = null;
l1:	/* end stackIntegerValue: */;
	if (index <= 0) {
		/* begin primitiveFail */
		foo->successFlag = 0;
		return null;
	}
	moduleName = ioListLoadedModule(index);
	if (moduleName == null) {
		/* begin pop: */
		foo->stackPointer -= 2 * (BYTES_PER_WORD);
		/* begin push: */
		longAtput(sp = foo->stackPointer + (BYTES_PER_WORD), foo->nilObj);
		foo->stackPointer = sp;
		return null;
	}
	length = strlen(moduleName);
	nameOop = instantiateClassindexableSize(fetchPointerofObject(ClassString, foo->specialObjectsOop), length);
	for (i = 0; i <= (length - 1); i += 1) {
		byteAtput((nameOop + (BASE_HEADER_SIZE)) + i, moduleName[i]);
	}
	/* begin forceInterruptCheck */
	foo->interruptCheckCounter = -1000;
	foo->nextPollTick = 0;
	/* begin pop:thenPush: */
	longAtput(sp1 = foo->stackPointer - ((2 - 1) * (BYTES_PER_WORD)), nameOop);
	foo->stackPointer = sp1;
}


/*	This primitive is called from Squeak as...
		<imageSegment> loadSegmentFrom: aWordArray outPointers: anArray. */
/*	This primitive will load a binary image segment created by primitiveStoreImageSegment.  It expects the outPointer array to be of the proper size, and the wordArray to be well formed.  It will return as its value the original array of roots, and the erstwhile segmentWordArray will have been truncated to a size of zero.  If this primitive should fail, the segmentWordArray will, sadly, have been reduced to an unrecognizable and unusable jumble.  But what more could you have done with it anyway? */

sqInt primitiveLoadImageSegment(void) {
register struct foo * foo = &fum;
    sqInt data;
    sqInt doingClass;
    usqInt endSeg;
    sqInt extraSize;
    sqInt fieldOop;
    usqInt fieldPtr;
    sqInt hdrTypeBits;
    sqInt header;
    usqInt lastOut;
    usqInt lastPtr;
    sqInt mapOop;
    sqInt outPointerArray;
    usqInt outPtr;
    usqInt segOop;
    sqInt segmentWordArray;
    sqInt sp;
    sqInt addr;
    sqInt addr1;
    sqInt sz;
    sqInt header1;
    sqInt sz1;
    sqInt header2;

	if (DoAssertionChecks) {
		verifyCleanHeaders();
	}
	outPointerArray = longAt(foo->stackPointer);
	lastOut = outPointerArray + (lastPointerOf(outPointerArray));
	segmentWordArray = longAt(foo->stackPointer - (1 * (BYTES_PER_WORD)));

	/* Essential type checks */

	endSeg = (segmentWordArray + (sizeBitsOf(segmentWordArray))) - (BASE_HEADER_SIZE);
	if (!((((((usqInt) (longAt(outPointerArray))) >> 8) & 15) == 2) && (((((usqInt) (longAt(segmentWordArray))) >> 8) & 15) == 6))) {
		/* begin primitiveFail */
		foo->successFlag = 0;
		return null;
	}
	data = longAt(segmentWordArray + (BASE_HEADER_SIZE));
	if (!(readableFormat(data & 65535))) {
		/* begin reverseBytesFrom:to: */
		flag("Dan");
		addr1 = segmentWordArray + (BASE_HEADER_SIZE);
		while ((((usqInt) addr1)) < (((usqInt) (endSeg + (BYTES_PER_WORD))))) {
			longAtput(addr1, byteSwapped(longAt(addr1)));
			addr1 += BYTES_PER_WORD;
		}
		data = longAt(segmentWordArray + (BASE_HEADER_SIZE));
		if (!(readableFormat(data & 65535))) {
			/* begin reverseBytesFrom:to: */
			flag("Dan");
			addr = segmentWordArray + (BASE_HEADER_SIZE);
			while ((((usqInt) addr)) < (((usqInt) (endSeg + (BYTES_PER_WORD))))) {
				longAtput(addr, byteSwapped(longAt(addr)));
				addr += BYTES_PER_WORD;
			}
			if (DoAssertionChecks) {
				verifyCleanHeaders();
			}
			/* begin primitiveFail */
			foo->successFlag = 0;
			return null;
		}
	}
	if (!((((usqInt) data) >> 16) == (((usqInt) (imageSegmentVersion())) >> 16))) {

		/* Reverse the byte-type objects once */
		/* Oop of first embedded object */

		segOop = ((segmentWordArray + (BASE_HEADER_SIZE)) + (BYTES_PER_WORD)) + (foo->headerTypeBytes[(longAt((segmentWordArray + (BASE_HEADER_SIZE)) + (BYTES_PER_WORD))) & TypeMask]);
		byteSwapByteObjectsFromto(segOop, endSeg + (BYTES_PER_WORD));
	}
	segOop = ((segmentWordArray + (BASE_HEADER_SIZE)) + (BYTES_PER_WORD)) + (foo->headerTypeBytes[(longAt((segmentWordArray + (BASE_HEADER_SIZE)) + (BYTES_PER_WORD))) & TypeMask]);
	while (segOop <= endSeg) {
		if (((longAt(segOop)) & TypeMask) <= 1) {

			/* This object has a class field (type = 0 or 1) -- start with that. */

			fieldPtr = segOop - (BYTES_PER_WORD);
			doingClass = 1;
		} else {

			/* No class field -- start with first data field */

			fieldPtr = segOop + (BASE_HEADER_SIZE);
			doingClass = 0;
		}

		/* last field */

		lastPtr = segOop + (lastPointerOf(segOop));
		if (lastPtr > endSeg) {
			if (DoAssertionChecks) {
				verifyCleanHeaders();
			}
			/* begin primitiveFail */
			foo->successFlag = 0;
			return null;
		}
		while (!(fieldPtr > lastPtr)) {

			/* Examine each pointer field */

			fieldOop = longAt(fieldPtr);
			if (doingClass) {
				hdrTypeBits = (longAt(fieldPtr)) & TypeMask;
				fieldOop -= hdrTypeBits;
			}
			if ((fieldOop & 1)) {

				/* Integer -- nothing to do */

				fieldPtr += BYTES_PER_WORD;
			} else {
				if (!((fieldOop & 3) == 0)) {
					/* begin primitiveFail */
					foo->successFlag = 0;
					return null;
				}
				if ((fieldOop & 2147483648U) == 0) {

					/* Internal pointer -- add segment offset */

					mapOop = fieldOop + segmentWordArray;
				} else {

					/* External pointer -- look it up in outPointers */

					outPtr = outPointerArray + (fieldOop & 2147483647U);
					if (outPtr > lastOut) {
						/* begin primitiveFail */
						foo->successFlag = 0;
						return null;
					}
					mapOop = longAt(outPtr);
				}
				if (doingClass) {
					longAtput(fieldPtr, mapOop + hdrTypeBits);
					fieldPtr += 8;
					doingClass = 0;
				} else {
					longAtput(fieldPtr, mapOop);
					fieldPtr += BYTES_PER_WORD;
				}
				if (segOop < foo->youngStart) {
					possibleRootStoreIntovalue(segOop, mapOop);
				}
			}
		}
		/* begin objectAfter: */
		if (DoAssertionChecks) {
			if ((((usqInt) segOop)) >= (((usqInt) foo->endOfMemory))) {
				error("no objects after the end of memory");
			}
		}
		if (((longAt(segOop)) & TypeMask) == HeaderTypeFree) {
			sz = (longAt(segOop)) & (ALL_BUT_TYPE_MASK);
		} else {
			/* begin sizeBitsOf: */
			header1 = longAt(segOop);
			if ((header1 & TypeMask) == HeaderTypeSizeAndClass) {
				sz = (longAt(segOop - ((BYTES_PER_WORD) * 2))) & (LONG_SIZE_MASK);
				goto l1;
			} else {
				sz = header1 & (SIZE_MASK);
				goto l1;
			}
		l1:	/* end sizeBitsOf: */;
		}
		segOop = (segOop + sz) + (foo->headerTypeBytes[(longAt(segOop + sz)) & TypeMask]);
	}
	segOop = ((segmentWordArray + (BASE_HEADER_SIZE)) + (BYTES_PER_WORD)) + (foo->headerTypeBytes[(longAt((segmentWordArray + (BASE_HEADER_SIZE)) + (BYTES_PER_WORD))) & TypeMask]);
	while (segOop <= endSeg) {
		if (!(oopHasAcceptableClass(segOop))) {
			/* begin primitiveFail */
			foo->successFlag = 0;
			return null;
		}

		/* first field */

		fieldPtr = segOop + (BASE_HEADER_SIZE);

		/* last field */
		/* Go through all oops, remapping them... */

		lastPtr = segOop + (lastPointerOf(segOop));
		while (!(fieldPtr > lastPtr)) {

			/* Examine each pointer field */

			fieldOop = longAt(fieldPtr);
			if (!(oopHasAcceptableClass(fieldOop))) {
				/* begin primitiveFail */
				foo->successFlag = 0;
				return null;
			}
			fieldPtr += BYTES_PER_WORD;
		}
		/* begin objectAfter: */
		if (DoAssertionChecks) {
			if ((((usqInt) segOop)) >= (((usqInt) foo->endOfMemory))) {
				error("no objects after the end of memory");
			}
		}
		if (((longAt(segOop)) & TypeMask) == HeaderTypeFree) {
			sz1 = (longAt(segOop)) & (ALL_BUT_TYPE_MASK);
		} else {
			/* begin sizeBitsOf: */
			header2 = longAt(segOop);
			if ((header2 & TypeMask) == HeaderTypeSizeAndClass) {
				sz1 = (longAt(segOop - ((BYTES_PER_WORD) * 2))) & (LONG_SIZE_MASK);
				goto l2;
			} else {
				sz1 = header2 & (SIZE_MASK);
				goto l2;
			}
		l2:	/* end sizeBitsOf: */;
		}
		segOop = (segOop + sz1) + (foo->headerTypeBytes[(longAt(segOop + sz1)) & TypeMask]);
	}
	extraSize = foo->headerTypeBytes[(longAt(segmentWordArray)) & TypeMask];
	hdrTypeBits = (longAt(segmentWordArray)) & TypeMask;
	if (extraSize == 8) {
		longAtput(segmentWordArray - extraSize, ((BASE_HEADER_SIZE) + (BYTES_PER_WORD)) + hdrTypeBits);
	} else {
		header = longAt(segmentWordArray);
		longAtput(segmentWordArray, ((header - (header & (SIZE_MASK))) + (BASE_HEADER_SIZE)) + (BYTES_PER_WORD));
	}
	if (DoAssertionChecks) {
		verifyCleanHeaders();
	}
	/* begin pop:thenPush: */
	longAtput(sp = foo->stackPointer - ((3 - 1) * (BYTES_PER_WORD)), ((segmentWordArray + (BASE_HEADER_SIZE)) + (BYTES_PER_WORD)) + (foo->headerTypeBytes[(longAt((segmentWordArray + (BASE_HEADER_SIZE)) + (BYTES_PER_WORD))) & TypeMask]));
	foo->stackPointer = sp;
}

sqInt primitiveLoadInstVar(void) {
register struct foo * foo = &fum;
    sqInt thisReceiver;
    sqInt top;
    sqInt object;
    sqInt sp;
    sqInt fieldIndex;

	/* begin popStack */
	top = longAt(foo->stackPointer);
	foo->stackPointer -= BYTES_PER_WORD;
	thisReceiver = top;
	/* begin push: */
	/* begin fetchPointer:ofObject: */
	fieldIndex = foo->primitiveIndex - 264;
	object = longAt((thisReceiver + (BASE_HEADER_SIZE)) + (fieldIndex << (SHIFT_FOR_WORD)));
	longAtput(sp = foo->stackPointer + (BYTES_PER_WORD), object);
	foo->stackPointer = sp;
}


/*	Natural log. */

sqInt primitiveLogN(void) {
register struct foo * foo = &fum;
    double  rcvr;

	rcvr = popFloat();
	if (foo->successFlag) {
		pushFloat(log(rcvr));
	} else {
		/* begin unPop: */
		foo->stackPointer += 1 * (BYTES_PER_WORD);
	}
}


/*	Register the low-space semaphore. If the argument is not a 
	Semaphore, unregister the current low-space Semaphore. */

sqInt primitiveLowSpaceSemaphore(void) {
register struct foo * foo = &fum;
    sqInt arg;
    sqInt top;
    sqInt oop;
    sqInt oop1;
    sqInt valuePointer;

	/* begin popStack */
	top = longAt(foo->stackPointer);
	foo->stackPointer -= BYTES_PER_WORD;
	arg = top;
	if ((fetchClassOf(arg)) == (fetchPointerofObject(ClassSemaphore, foo->specialObjectsOop))) {
		/* begin storePointer:ofObject:withValue: */
		oop = foo->specialObjectsOop;
		if ((((usqInt) oop)) < (((usqInt) foo->youngStart))) {
			possibleRootStoreIntovalue(oop, arg);
		}
		longAtput((oop + (BASE_HEADER_SIZE)) + (TheLowSpaceSemaphore << (SHIFT_FOR_WORD)), arg);
	} else {
		/* begin storePointer:ofObject:withValue: */
		oop1 = foo->specialObjectsOop;
		valuePointer = foo->nilObj;
		if ((((usqInt) oop1)) < (((usqInt) foo->youngStart))) {
			possibleRootStoreIntovalue(oop1, valuePointer);
		}
		longAtput((oop1 + (BASE_HEADER_SIZE)) + (TheLowSpaceSemaphore << (SHIFT_FOR_WORD)), valuePointer);
	}
}

sqInt primitiveMakePoint(void) {
register struct foo * foo = &fum;
    sqInt argument;
    sqInt pt;
    sqInt rcvr;
    sqInt sp;
    sqInt pointResult;
    sqInt pointResult1;
    sqInt valuePointer;
    sqInt pointResult2;
    sqInt valuePointer1;
    sqInt valuePointer2;

	argument = longAt(foo->stackPointer);
	rcvr = longAt(foo->stackPointer - (1 * (BYTES_PER_WORD)));
	if ((rcvr & 1)) {
		if ((argument & 1)) {
			/* begin makePointwithxValue:yValue: */
			pointResult = instantiateSmallClasssizeInBytes(fetchPointerofObject(ClassPoint, foo->specialObjectsOop), 3 * (BYTES_PER_WORD));
			longAtput((pointResult + (BASE_HEADER_SIZE)) + (XIndex << (SHIFT_FOR_WORD)), ((((rcvr >> 1)) << 1) | 1));
			longAtput((pointResult + (BASE_HEADER_SIZE)) + (YIndex << (SHIFT_FOR_WORD)), ((((argument >> 1)) << 1) | 1));
			pt = pointResult;
		} else {
			/* begin makePointwithxValue:yValue: */
			pointResult1 = instantiateSmallClasssizeInBytes(fetchPointerofObject(ClassPoint, foo->specialObjectsOop), 3 * (BYTES_PER_WORD));
			longAtput((pointResult1 + (BASE_HEADER_SIZE)) + (XIndex << (SHIFT_FOR_WORD)), ((((rcvr >> 1)) << 1) | 1));
			longAtput((pointResult1 + (BASE_HEADER_SIZE)) + (YIndex << (SHIFT_FOR_WORD)), ((0 << 1) | 1));
			pt = pointResult1;
			/* begin storePointer:ofObject:withValue: */
			valuePointer = longAt(foo->stackPointer - (0 * (BYTES_PER_WORD)));
			if ((((usqInt) pt)) < (((usqInt) foo->youngStart))) {
				possibleRootStoreIntovalue(pt, valuePointer);
			}
			longAtput((pt + (BASE_HEADER_SIZE)) + (1 << (SHIFT_FOR_WORD)), valuePointer);
		}
	} else {
		if (!((fetchClassOf(rcvr)) == (fetchPointerofObject(ClassFloat, foo->specialObjectsOop)))) {
			/* begin success: */
			foo->successFlag = 0 && foo->successFlag;
			return null;
		}
		/* begin makePointwithxValue:yValue: */
		pointResult2 = instantiateSmallClasssizeInBytes(fetchPointerofObject(ClassPoint, foo->specialObjectsOop), 3 * (BYTES_PER_WORD));
		longAtput((pointResult2 + (BASE_HEADER_SIZE)) + (XIndex << (SHIFT_FOR_WORD)), ((0 << 1) | 1));
		longAtput((pointResult2 + (BASE_HEADER_SIZE)) + (YIndex << (SHIFT_FOR_WORD)), ((0 << 1) | 1));
		pt = pointResult2;
		/* begin storePointer:ofObject:withValue: */
		valuePointer1 = longAt(foo->stackPointer - (1 * (BYTES_PER_WORD)));
		if ((((usqInt) pt)) < (((usqInt) foo->youngStart))) {
			possibleRootStoreIntovalue(pt, valuePointer1);
		}
		longAtput((pt + (BASE_HEADER_SIZE)) + (0 << (SHIFT_FOR_WORD)), valuePointer1);
		/* begin storePointer:ofObject:withValue: */
		valuePointer2 = longAt(foo->stackPointer - (0 * (BYTES_PER_WORD)));
		if ((((usqInt) pt)) < (((usqInt) foo->youngStart))) {
			possibleRootStoreIntovalue(pt, valuePointer2);
		}
		longAtput((pt + (BASE_HEADER_SIZE)) + (1 << (SHIFT_FOR_WORD)), valuePointer2);
	}
	/* begin pop:thenPush: */
	longAtput(sp = foo->stackPointer - ((2 - 1) * (BYTES_PER_WORD)), pt);
	foo->stackPointer = sp;
}


/*	Primitive. Mark the method for exception handling. The primitive must fail after marking the context so that the regular code is run. */

sqInt primitiveMarkHandlerMethod(void) {
	/* begin primitiveFail */
	foo->successFlag = 0;
	return null;
}


/*	Primitive. Mark the method for exception unwinding. The primitive must fail after marking the context so that the regular code is run. */

sqInt primitiveMarkUnwindMethod(void) {
	/* begin primitiveFail */
	foo->successFlag = 0;
	return null;
}


/*	Return the method an external primitive was defined in */

sqInt primitiveMethod(void) {
	return foo->newMethod;
}


/*	This is a named (not numbered) primitive in the null module (ie the VM) */

EXPORT(sqInt) primitiveMicrosecondClock(void) {
register struct foo * foo = &fum;
    sqInt oop;
    sqInt sp;

	/* begin pop:thenPush: */
	oop = positive64BitIntegerFor(ioMicroSecondClock());
	longAtput(sp = foo->stackPointer - ((1 - 1) * (BYTES_PER_WORD)), oop);
	foo->stackPointer = sp;
}


/*	Return the value of the millisecond clock as an integer. Note that the millisecond clock wraps around periodically. On some platforms it can wrap daily. The range is limited to SmallInteger maxVal / 2 to allow delays of up to that length without overflowing a SmallInteger. */

sqInt primitiveMillisecondClock(void) {
register struct foo * foo = &fum;
    sqInt oop;
    sqInt sp;

	/* begin pop:thenPush: */
	oop = ((((ioMSecs()) & MillisecondClockMask) << 1) | 1);
	longAtput(sp = foo->stackPointer - ((1 - 1) * (BYTES_PER_WORD)), oop);
	foo->stackPointer = sp;
}

sqInt primitiveMod(void) {
register struct foo * foo = &fum;
    sqInt mod;
    sqInt sp;

	mod = doPrimitiveModby(longAt(foo->stackPointer - (1 * (BYTES_PER_WORD))), longAt(foo->stackPointer));
	/* begin pop2AndPushIntegerIfOK: */
	if (foo->successFlag) {
		if (
# ifdef SQ_HOST32  // cast to int for 64 bit image on 32 bit host
			(((((int) mod)) ^ ((((int) mod)) << 1)) >= 0)
# else
			((mod >= -1073741824) && (mod <= 1073741823))
# endif  // SQ_HOST32
		) {
			/* begin pop:thenPush: */
			longAtput(sp = foo->stackPointer - ((2 - 1) * (BYTES_PER_WORD)), ((mod << 1) | 1));
			foo->stackPointer = sp;
		} else {
			foo->successFlag = 0;
		}
	}
}


/*	Primitive arithmetic operations for large integers in 64 bit range */

EXPORT(sqInt) primitiveModLargeIntegers(void) {
register struct foo * foo = &fum;
    sqLong integerArg;
    sqLong integerRcvr;
    sqInt oopResult;
    sqLong result;
    sqInt sp;

	integerArg = signed64BitValueOf(longAt(foo->stackPointer - (0 * (BYTES_PER_WORD))));
	integerRcvr = signed64BitValueOf(longAt(foo->stackPointer - (1 * (BYTES_PER_WORD))));
	if (integerArg == 0) {
		/* begin primitiveFail */
		foo->successFlag = 0;
	}
	if (!(foo->successFlag)) {
		return null;
	}

	/* ensure that the result has the same sign as the integerArg */

	result = integerRcvr % integerArg;
	if (integerArg < 0) {
		if (result > 0) {
			result += integerArg;
		}
	} else {
		if (result < 0) {
			result += integerArg;
		}
	}
	oopResult = signed64BitIntegerFor(result);
	if (foo->successFlag) {
		/* begin pop:thenPush: */
		longAtput(sp = foo->stackPointer - ((2 - 1) * (BYTES_PER_WORD)), oopResult);
		foo->stackPointer = sp;
	}
}


/*	Obsolete on virtually all platforms; old style input polling code.
	Return the mouse button state. The low three bits encode the state of the <red><yellow><blue> mouse buttons. The next four bits encode the Smalltalk modifier bits <cmd><option><ctrl><shift>. */

sqInt primitiveMouseButtons(void) {
register struct foo * foo = &fum;
    sqInt buttonWord;
    sqInt sp;

	/* begin pop: */
	foo->stackPointer -= 1 * (BYTES_PER_WORD);
	buttonWord = ioGetButtonState();
	/* begin pushInteger: */
	/* begin push: */
	longAtput(sp = foo->stackPointer + (BYTES_PER_WORD), ((buttonWord << 1) | 1));
	foo->stackPointer = sp;
}


/*	Obsolete on virtually all platforms; old style input polling code.
	Return a Point indicating current position of the mouse. Note that mouse coordinates may be negative if the mouse moves above or to the left of the top-left corner of the Smalltalk window. */

sqInt primitiveMousePoint(void) {
register struct foo * foo = &fum;
    sqInt pointWord;
    sqInt x;
    sqInt y;
    sqInt object;
    sqInt sp;
    sqInt pointResult;

	/* begin pop: */
	foo->stackPointer -= 1 * (BYTES_PER_WORD);
	pointWord = ioMousePoint();
	/* begin signExtend16: */
	if ((((((usqInt) pointWord) >> 16) & 65535) & 32768) == 0) {
		x = (((usqInt) pointWord) >> 16) & 65535;
		goto l1;
	} else {
		x = ((((usqInt) pointWord) >> 16) & 65535) - 65536;
		goto l1;
	}
l1:	/* end signExtend16: */;
	/* begin signExtend16: */
	if (((pointWord & 65535) & 32768) == 0) {
		y = pointWord & 65535;
		goto l2;
	} else {
		y = (pointWord & 65535) - 65536;
		goto l2;
	}
l2:	/* end signExtend16: */;
	/* begin push: */
	/* begin makePointwithxValue:yValue: */
	pointResult = instantiateSmallClasssizeInBytes(fetchPointerofObject(ClassPoint, foo->specialObjectsOop), 3 * (BYTES_PER_WORD));
	longAtput((pointResult + (BASE_HEADER_SIZE)) + (XIndex << (SHIFT_FOR_WORD)), ((x << 1) | 1));
	longAtput((pointResult + (BASE_HEADER_SIZE)) + (YIndex << (SHIFT_FOR_WORD)), ((y << 1) | 1));
	object = pointResult;
	longAtput(sp = foo->stackPointer + (BYTES_PER_WORD), object);
	foo->stackPointer = sp;
}

sqInt primitiveMultiply(void) {
register struct foo * foo = &fum;
    sqInt integerArg;
    sqInt integerRcvr;
    sqInt integerResult;
    sqInt sp;
    sqInt integerPointer;
    sqInt integerPointer1;

	/* begin stackIntegerValue: */
	integerPointer = longAt(foo->stackPointer - (1 * (BYTES_PER_WORD)));
	/* begin checkedIntegerValueOf: */
	if ((integerPointer & 1)) {
		integerRcvr = (integerPointer >> 1);
		goto l1;
	} else {
		/* begin primitiveFail */
		foo->successFlag = 0;
		integerRcvr = 0;
		goto l1;
	}
	integerRcvr = null;
l1:	/* end stackIntegerValue: */;
	/* begin stackIntegerValue: */
	integerPointer1 = longAt(foo->stackPointer - (0 * (BYTES_PER_WORD)));
	/* begin checkedIntegerValueOf: */
	if ((integerPointer1 & 1)) {
		integerArg = (integerPointer1 >> 1);
		goto l2;
	} else {
		/* begin primitiveFail */
		foo->successFlag = 0;
		integerArg = 0;
		goto l2;
	}
	integerArg = null;
l2:	/* end stackIntegerValue: */;
	if (foo->successFlag) {

		/* check for C overflow by seeing if computation is reversible */

		integerResult = integerRcvr * integerArg;
		if ((integerArg == 0) || ((integerResult / integerArg) == integerRcvr)) {
			/* begin pop2AndPushIntegerIfOK: */
			if (foo->successFlag) {
				if (
# ifdef SQ_HOST32  // cast to int for 64 bit image on 32 bit host
					(((((int) integerResult)) ^ ((((int) integerResult)) << 1)) >= 0)
# else
					((integerResult >= -1073741824) && (integerResult <= 1073741823))
# endif  // SQ_HOST32
				) {
					/* begin pop:thenPush: */
					longAtput(sp = foo->stackPointer - ((2 - 1) * (BYTES_PER_WORD)), ((integerResult << 1) | 1));
					foo->stackPointer = sp;
				} else {
					foo->successFlag = 0;
				}
			}
		} else {
			/* begin primitiveFail */
			foo->successFlag = 0;
		}
	}
}


/*	Primitive arithmetic operations for large integers in 64 bit range */

EXPORT(sqInt) primitiveMultiplyLargeIntegers(void) {
register struct foo * foo = &fum;
    sqLong integerArg;
    sqLong integerRcvr;
    sqInt oopResult;
    sqLong result;
    sqInt sp;

	integerArg = signed64BitValueOf(longAt(foo->stackPointer - (0 * (BYTES_PER_WORD))));
	integerRcvr = signed64BitValueOf(longAt(foo->stackPointer - (1 * (BYTES_PER_WORD))));
	if (!(foo->successFlag)) {
		return null;
	}

	/* check for C overflow by seeing if computation is reversible */

	result = integerRcvr * integerArg;
	if ((integerArg == 0) || ((result / integerArg) == integerRcvr)) {
		oopResult = signed64BitIntegerFor(result);
	} else {
		/* begin primitiveFail */
		foo->successFlag = 0;
	}
	if (foo->successFlag) {
		/* begin pop:thenPush: */
		longAtput(sp = foo->stackPointer - ((2 - 1) * (BYTES_PER_WORD)), oopResult);
		foo->stackPointer = sp;
	}
}


/*	Allocate a new fixed-size instance. Fail if the allocation would leave less than lowSpaceThreshold bytes free. May cause a GC */

sqInt primitiveNew(void) {
register struct foo * foo = &fum;
    sqInt class;
    sqInt spaceOkay;
    sqInt object;
    sqInt sp;
    sqInt format;
    usqInt minFree;
    usqInt minFree1;


	/* The following may cause GC! */

	class = longAt(foo->stackPointer);
	/* begin sufficientSpaceToInstantiate:indexableSize: */
	format = (((usqInt) ((longAt((class + (BASE_HEADER_SIZE)) + (InstanceSpecificationIndex << (SHIFT_FOR_WORD)))) - 1)) >> 8) & 15;
	if ((0 > 0) && (format < 2)) {
		spaceOkay = 0;
		goto l1;
	}
	if (format < 8) {
		if (isExcessiveAllocationRequestshift(0, SHIFT_FOR_WORD)) {
			spaceOkay = 0;
			goto l1;
		}
		/* begin sufficientSpaceToAllocate: */
		minFree = (foo->lowSpaceThreshold + (2500 + (0 * (BYTES_PER_WORD)))) + (BASE_HEADER_SIZE);
		if (oopisGreaterThanOrEqualTo((longAt(foo->freeBlock)) & (ALL_BUT_TYPE_MASK), minFree)) {
			spaceOkay = 1;
			goto l1;
		} else {
			spaceOkay = sufficientSpaceAfterGC(minFree);
			goto l1;
		}
		spaceOkay = null;
		goto l1;
	} else {
		if (isExcessiveAllocationRequestshift(0, 0)) {
			spaceOkay = 0;
			goto l1;
		}
		/* begin sufficientSpaceToAllocate: */
		minFree1 = (foo->lowSpaceThreshold + (2500 + 0)) + (BASE_HEADER_SIZE);
		if (oopisGreaterThanOrEqualTo((longAt(foo->freeBlock)) & (ALL_BUT_TYPE_MASK), minFree1)) {
			spaceOkay = 1;
			goto l1;
		} else {
			spaceOkay = sufficientSpaceAfterGC(minFree1);
			goto l1;
		}
		spaceOkay = null;
		goto l1;
	}
l1:	/* end sufficientSpaceToInstantiate:indexableSize: */;
	/* begin success: */
	foo->successFlag = spaceOkay && foo->successFlag;
	if (foo->successFlag) {
		/* begin push: */
		object = instantiateClassindexableSize(popStack(), 0);
		longAtput(sp = foo->stackPointer + (BYTES_PER_WORD), object);
		foo->stackPointer = sp;
	}
}

sqInt primitiveNewMethod(void) {
register struct foo * foo = &fum;
    sqInt bytecodeCount;
    sqInt class;
    sqInt header;
    sqInt i;
    sqInt literalCount;
    sqInt size;
    sqInt theMethod;
    sqInt valuePointer;
    sqInt top;
    sqInt integerPointer;
    sqInt top1;
    sqInt top2;
    sqInt sp;

	/* begin popStack */
	top = longAt(foo->stackPointer);
	foo->stackPointer -= BYTES_PER_WORD;
	header = top;
	/* begin popInteger */
	/* begin popStack */
	top1 = longAt(foo->stackPointer);
	foo->stackPointer -= BYTES_PER_WORD;
	integerPointer = top1;
	/* begin checkedIntegerValueOf: */
	if ((integerPointer & 1)) {
		bytecodeCount = (integerPointer >> 1);
		goto l1;
	} else {
		/* begin primitiveFail */
		foo->successFlag = 0;
		bytecodeCount = 0;
		goto l1;
	}
	bytecodeCount = null;
l1:	/* end popInteger */;
	/* begin success: */
	foo->successFlag = ((header & 1)) && foo->successFlag;
	if (!(foo->successFlag)) {
		/* begin unPop: */
		foo->stackPointer += 2 * (BYTES_PER_WORD);
		return null;
	}
	/* begin popStack */
	top2 = longAt(foo->stackPointer);
	foo->stackPointer -= BYTES_PER_WORD;
	class = top2;
	size = ((((((usqInt) header) >> 10) & 255) + 1) * (BYTES_PER_WORD)) + bytecodeCount;
	theMethod = instantiateClassindexableSize(class, size);
	longAtput((theMethod + (BASE_HEADER_SIZE)) + (HeaderIndex << (SHIFT_FOR_WORD)), header);
	literalCount = (((usqInt) header) >> 10) & 255;
	for (i = 1; i <= literalCount; i += 1) {
		/* begin storePointer:ofObject:withValue: */
		valuePointer = foo->nilObj;
		if ((((usqInt) theMethod)) < (((usqInt) foo->youngStart))) {
			possibleRootStoreIntovalue(theMethod, valuePointer);
		}
		longAtput((theMethod + (BASE_HEADER_SIZE)) + (i << (SHIFT_FOR_WORD)), valuePointer);
	}
	/* begin push: */
	longAtput(sp = foo->stackPointer + (BYTES_PER_WORD), theMethod);
	foo->stackPointer = sp;
}


/*	Allocate a new indexable instance. Fail if the allocation would leave less than lowSpaceThreshold bytes free. */

sqInt primitiveNewWithArg(void) {
register struct foo * foo = &fum;
    sqInt class;
    usqInt size;
    sqInt spaceOkay;
    sqInt oop;
    sqInt sp;
    sqInt format;
    usqInt minFree;
    usqInt minFree1;

	
# if (SQ_IMAGE64 && SQ_HOST64)  // permit large object allocation on 64 bit image and host
	size = positive64BitValueOf(longAt(foo->stackPointer));
# else
	size = positive32BitValueOf(longAt(foo->stackPointer));
# endif  // SQ_IMAGE64 && SQ_HOST64
	
	class = longAt(foo->stackPointer - (1 * (BYTES_PER_WORD)));
	/* begin success: */
	foo->successFlag = (size >= 0) && foo->successFlag;
	if (foo->successFlag) {
		/* begin sufficientSpaceToInstantiate:indexableSize: */
		format = (((usqInt) ((longAt((class + (BASE_HEADER_SIZE)) + (InstanceSpecificationIndex << (SHIFT_FOR_WORD)))) - 1)) >> 8) & 15;
		if ((size > 0) && (format < 2)) {
			spaceOkay = 0;
			goto l1;
		}
		if (format < 8) {
			if (isExcessiveAllocationRequestshift(size, SHIFT_FOR_WORD)) {
				spaceOkay = 0;
				goto l1;
			}
			/* begin sufficientSpaceToAllocate: */
			minFree = (foo->lowSpaceThreshold + (2500 + (size * (BYTES_PER_WORD)))) + (BASE_HEADER_SIZE);
			if (oopisGreaterThanOrEqualTo((longAt(foo->freeBlock)) & (ALL_BUT_TYPE_MASK), minFree)) {
				spaceOkay = 1;
				goto l1;
			} else {
				spaceOkay = sufficientSpaceAfterGC(minFree);
				goto l1;
			}
			spaceOkay = null;
			goto l1;
		} else {
			if (isExcessiveAllocationRequestshift(size, 0)) {
				spaceOkay = 0;
				goto l1;
			}
			/* begin sufficientSpaceToAllocate: */
			minFree1 = (foo->lowSpaceThreshold + (2500 + size)) + (BASE_HEADER_SIZE);
			if (oopisGreaterThanOrEqualTo((longAt(foo->freeBlock)) & (ALL_BUT_TYPE_MASK), minFree1)) {
				spaceOkay = 1;
				goto l1;
			} else {
				spaceOkay = sufficientSpaceAfterGC(minFree1);
				goto l1;
			}
			spaceOkay = null;
			goto l1;
		}
	l1:	/* end sufficientSpaceToInstantiate:indexableSize: */;
		/* begin success: */
		foo->successFlag = spaceOkay && foo->successFlag;
		class = longAt(foo->stackPointer - (1 * (BYTES_PER_WORD)));
	}
	if (foo->successFlag) {
		/* begin pop:thenPush: */
		oop = instantiateClassindexableSize(class, size);
		longAtput(sp = foo->stackPointer - ((2 - 1) * (BYTES_PER_WORD)), oop);
		foo->stackPointer = sp;
	}
}

sqInt primitiveNextInstance(void) {
register struct foo * foo = &fum;
    sqInt instance;
    sqInt object;
    sqInt sp;
    sqInt classPointer;
    sqInt thisClass;
    sqInt thisObj;
    sqInt ccIndex;
    sqInt ccIndex1;
    sqInt oop;
    sqInt oop1;
    sqInt oop2;
    sqInt oop3;
    sqInt oop4;
    sqInt oop5;

	object = longAt(foo->stackPointer);
	/* begin instanceAfter: */
	/* begin fetchClassOf: */
	if ((object & 1)) {
		/* begin fetchPointer:ofObject: */
		oop = foo->specialObjectsOop;
		classPointer = longAt((oop + (BASE_HEADER_SIZE)) + (ClassInteger << (SHIFT_FOR_WORD)));
		goto l2;
	}
	ccIndex1 = (((usqInt) (longAt(object))) >> 12) & 31;
	if (ccIndex1 == 0) {
		classPointer = (longAt(object - (BASE_HEADER_SIZE))) & (ALL_BUT_TYPE_MASK);
		goto l2;
	} else {
		/* begin fetchPointer:ofObject: */
		/* begin fetchPointer:ofObject: */
		oop4 = foo->specialObjectsOop;
		oop1 = longAt((oop4 + (BASE_HEADER_SIZE)) + (CompactClasses << (SHIFT_FOR_WORD)));
		classPointer = longAt((oop1 + (BASE_HEADER_SIZE)) + ((ccIndex1 - 1) << (SHIFT_FOR_WORD)));
		goto l2;
	}
l2:	/* end fetchClassOf: */;
	thisObj = accessibleObjectAfter(object);
	while (!(thisObj == null)) {
		/* begin fetchClassOf: */
		if ((thisObj & 1)) {
			/* begin fetchPointer:ofObject: */
			oop2 = foo->specialObjectsOop;
			thisClass = longAt((oop2 + (BASE_HEADER_SIZE)) + (ClassInteger << (SHIFT_FOR_WORD)));
			goto l1;
		}
		ccIndex = (((usqInt) (longAt(thisObj))) >> 12) & 31;
		if (ccIndex == 0) {
			thisClass = (longAt(thisObj - (BASE_HEADER_SIZE))) & (ALL_BUT_TYPE_MASK);
			goto l1;
		} else {
			/* begin fetchPointer:ofObject: */
			/* begin fetchPointer:ofObject: */
			oop5 = foo->specialObjectsOop;
			oop3 = longAt((oop5 + (BASE_HEADER_SIZE)) + (CompactClasses << (SHIFT_FOR_WORD)));
			thisClass = longAt((oop3 + (BASE_HEADER_SIZE)) + ((ccIndex - 1) << (SHIFT_FOR_WORD)));
			goto l1;
		}
	l1:	/* end fetchClassOf: */;
		if (thisClass == classPointer) {
			instance = thisObj;
			goto l3;
		}
		thisObj = accessibleObjectAfter(thisObj);
	}
	instance = foo->nilObj;
l3:	/* end instanceAfter: */;
	if (instance == foo->nilObj) {
		/* begin primitiveFail */
		foo->successFlag = 0;
	} else {
		/* begin pop:thenPush: */
		longAtput(sp = foo->stackPointer - (((foo->argumentCount + 1) - 1) * (BYTES_PER_WORD)), instance);
		foo->stackPointer = sp;
	}
}


/*	Return the object following the receiver in the heap. Return the SmallInteger zero when there are no more objects. */

sqInt primitiveNextObject(void) {
register struct foo * foo = &fum;
    sqInt instance;
    sqInt object;
    sqInt sp;
    sqInt sp1;

	object = longAt(foo->stackPointer);
	instance = accessibleObjectAfter(object);
	if (instance == null) {
		/* begin pop:thenPushInteger: */
		longAtput(sp = foo->stackPointer - (((foo->argumentCount + 1) - 1) * (BYTES_PER_WORD)), ((0 << 1) | 1));
		foo->stackPointer = sp;
	} else {
		/* begin pop:thenPush: */
		longAtput(sp1 = foo->stackPointer - (((foo->argumentCount + 1) - 1) * (BYTES_PER_WORD)), instance);
		foo->stackPointer = sp1;
	}
}


/*	A placeholder for primitives that haven't been implemented or are being withdrawn gradually. Just absorbs any arguments and returns the receiver. */

sqInt primitiveNoop(void) {
register struct foo * foo = &fum;
	/* begin pop: */
	foo->stackPointer -= foo->argumentCount * (BYTES_PER_WORD);
}

sqInt primitiveNotEqual(void) {
register struct foo * foo = &fum;
    sqInt integerArgument;
    sqInt integerReceiver;
    sqInt result;
    sqInt top;
    sqInt top1;
    sqInt sp;
    sqInt sp1;

	/* begin popStack */
	top = longAt(foo->stackPointer);
	foo->stackPointer -= BYTES_PER_WORD;
	integerArgument = top;
	/* begin popStack */
	top1 = longAt(foo->stackPointer);
	foo->stackPointer -= BYTES_PER_WORD;
	integerReceiver = top1;
	result = !(compare31or32Bitsequal(integerReceiver, integerArgument));
	/* begin checkBooleanResult: */
	if (foo->successFlag) {
		/* begin pushBool: */
		if (result) {
			/* begin push: */
			longAtput(sp = foo->stackPointer + (BYTES_PER_WORD), foo->trueObj);
			foo->stackPointer = sp;
		} else {
			/* begin push: */
			longAtput(sp1 = foo->stackPointer + (BYTES_PER_WORD), foo->falseObj);
			foo->stackPointer = sp1;
		}
	} else {
		/* begin unPop: */
		foo->stackPointer += 2 * (BYTES_PER_WORD);
	}
}


/*	Primitive comparison operations for large integers in 64 bit range */

EXPORT(sqInt) primitiveNotEqualLargeIntegers(void) {
register struct foo * foo = &fum;
    sqLong integerArg;
    sqLong integerRcvr;
    sqInt sp;
    sqInt sp1;

	integerArg = signed64BitValueOf(longAt(foo->stackPointer - (0 * (BYTES_PER_WORD))));
	integerRcvr = signed64BitValueOf(longAt(foo->stackPointer - (1 * (BYTES_PER_WORD))));
	if (foo->successFlag) {
		/* begin pop: */
		foo->stackPointer -= 2 * (BYTES_PER_WORD);
		/* begin pushBool: */
		if (integerRcvr != integerArg) {
			/* begin push: */
			longAtput(sp = foo->stackPointer + (BYTES_PER_WORD), foo->trueObj);
			foo->stackPointer = sp;
		} else {
			/* begin push: */
			longAtput(sp1 = foo->stackPointer + (BYTES_PER_WORD), foo->falseObj);
			foo->stackPointer = sp1;
		}
	}
}


/*	Defined for CompiledMethods only */

sqInt primitiveObjectAt(void) {
register struct foo * foo = &fum;
    sqInt index;
    sqInt thisReceiver;
    sqInt object;
    sqInt sp;
    sqInt top;
    sqInt successValue;
    sqInt integerPointer;
    sqInt top1;

	/* begin popInteger */
	/* begin popStack */
	top1 = longAt(foo->stackPointer);
	foo->stackPointer -= BYTES_PER_WORD;
	integerPointer = top1;
	/* begin checkedIntegerValueOf: */
	if ((integerPointer & 1)) {
		index = (integerPointer >> 1);
		goto l1;
	} else {
		/* begin primitiveFail */
		foo->successFlag = 0;
		index = 0;
		goto l1;
	}
	index = null;
l1:	/* end popInteger */;
	/* begin popStack */
	top = longAt(foo->stackPointer);
	foo->stackPointer -= BYTES_PER_WORD;
	thisReceiver = top;
	/* begin success: */
	foo->successFlag = (index > 0) && foo->successFlag;
	/* begin success: */
	successValue = index <= ((literalCountOfHeader(longAt((thisReceiver + (BASE_HEADER_SIZE)) + (HeaderIndex << (SHIFT_FOR_WORD))))) + LiteralStart);
	foo->successFlag = successValue && foo->successFlag;
	if (foo->successFlag) {
		/* begin push: */
		object = longAt((thisReceiver + (BASE_HEADER_SIZE)) + ((index - 1) << (SHIFT_FOR_WORD)));
		longAtput(sp = foo->stackPointer + (BYTES_PER_WORD), object);
		foo->stackPointer = sp;
	} else {
		/* begin unPop: */
		foo->stackPointer += 2 * (BYTES_PER_WORD);
	}
}


/*	Defined for CompiledMethods only */

sqInt primitiveObjectAtPut(void) {
register struct foo * foo = &fum;
    sqInt index;
    sqInt newValue;
    sqInt thisReceiver;
    sqInt sp;
    sqInt top;
    sqInt top1;
    sqInt successValue;
    sqInt integerPointer;
    sqInt top2;

	/* begin popStack */
	top = longAt(foo->stackPointer);
	foo->stackPointer -= BYTES_PER_WORD;
	newValue = top;
	/* begin popInteger */
	/* begin popStack */
	top2 = longAt(foo->stackPointer);
	foo->stackPointer -= BYTES_PER_WORD;
	integerPointer = top2;
	/* begin checkedIntegerValueOf: */
	if ((integerPointer & 1)) {
		index = (integerPointer >> 1);
		goto l1;
	} else {
		/* begin primitiveFail */
		foo->successFlag = 0;
		index = 0;
		goto l1;
	}
	index = null;
l1:	/* end popInteger */;
	/* begin popStack */
	top1 = longAt(foo->stackPointer);
	foo->stackPointer -= BYTES_PER_WORD;
	thisReceiver = top1;
	/* begin success: */
	foo->successFlag = (index > 0) && foo->successFlag;
	/* begin success: */
	successValue = index <= ((literalCountOfHeader(longAt((thisReceiver + (BASE_HEADER_SIZE)) + (HeaderIndex << (SHIFT_FOR_WORD))))) + LiteralStart);
	foo->successFlag = successValue && foo->successFlag;
	if (foo->successFlag) {
		/* begin storePointer:ofObject:withValue: */
		if ((((usqInt) thisReceiver)) < (((usqInt) foo->youngStart))) {
			possibleRootStoreIntovalue(thisReceiver, newValue);
		}
		longAtput((thisReceiver + (BASE_HEADER_SIZE)) + ((index - 1) << (SHIFT_FOR_WORD)), newValue);
		/* begin push: */
		longAtput(sp = foo->stackPointer + (BYTES_PER_WORD), newValue);
		foo->stackPointer = sp;
	} else {
		/* begin unPop: */
		foo->stackPointer += 3 * (BYTES_PER_WORD);
	}
}

sqInt primitiveObjectPointsTo(void) {
register struct foo * foo = &fum;
    sqInt i;
    sqInt lastField;
    sqInt rcvr;
    sqInt thang;
    sqInt top;
    sqInt top1;
    sqInt sp;
    sqInt sp1;
    sqInt sp2;
    sqInt sp3;
    sqInt sp4;
    sqInt sp5;
    sqInt contextSize;
    sqInt fmt;
    sqInt header;
    sqInt methodHeader;
    sqInt sz;
    sqInt sp6;
    sqInt header1;
    sqInt type;

	/* begin popStack */
	top = longAt(foo->stackPointer);
	foo->stackPointer -= BYTES_PER_WORD;
	thang = top;
	/* begin popStack */
	top1 = longAt(foo->stackPointer);
	foo->stackPointer -= BYTES_PER_WORD;
	rcvr = top1;
	if ((rcvr & 1)) {
		/* begin pushBool: */
		if (0) {
			/* begin push: */
			longAtput(sp = foo->stackPointer + (BYTES_PER_WORD), foo->trueObj);
			foo->stackPointer = sp;
		} else {
			/* begin push: */
			longAtput(sp1 = foo->stackPointer + (BYTES_PER_WORD), foo->falseObj);
			foo->stackPointer = sp1;
		}
		return null;
	}
	/* begin lastPointerOf: */
	header = longAt(rcvr);
	fmt = (((usqInt) header) >> 8) & 15;
	if (fmt <= 4) {
		if ((fmt == 3) && ((((((usqInt) header) >> 12) & 31) == 13) || ((((((usqInt) header) >> 12) & 31) == 14) || (((((usqInt) header) >> 12) & 31) == 4)))) {
			/* begin fetchStackPointerOf: */
			sp6 = longAt((rcvr + (BASE_HEADER_SIZE)) + (StackPointerIndex << (SHIFT_FOR_WORD)));
			if (!((sp6 & 1))) {
				contextSize = 0;
				goto l1;
			}
			contextSize = (sp6 >> 1);
		l1:	/* end fetchStackPointerOf: */;
			lastField = (CtxtTempFrameStart + contextSize) * (BYTES_PER_WORD);
			goto l2;
		}
		/* begin sizeBitsOfSafe: */
		header1 = longAt(rcvr);
		/* begin rightType: */
		if ((header1 & (SIZE_MASK)) == 0) {
			type = HeaderTypeSizeAndClass;
			goto l3;
		} else {
			if ((header1 & CompactClassMask) == 0) {
				type = HeaderTypeClass;
				goto l3;
			} else {
				type = HeaderTypeShort;
				goto l3;
			}
		}
	l3:	/* end rightType: */;
		if (type == HeaderTypeSizeAndClass) {
			sz = (longAt(rcvr - ((BYTES_PER_WORD) * 2))) & (ALL_BUT_TYPE_MASK);
			goto l4;
		} else {
			sz = header1 & (SIZE_MASK);
			goto l4;
		}
	l4:	/* end sizeBitsOfSafe: */;
		lastField = sz - (BASE_HEADER_SIZE);
		goto l2;
	}
	if (fmt < 12) {
		lastField = 0;
		goto l2;
	}
	methodHeader = longAt(rcvr + (BASE_HEADER_SIZE));
	lastField = (((((usqInt) methodHeader) >> 10) & 255) * (BYTES_PER_WORD)) + (BASE_HEADER_SIZE);
l2:	/* end lastPointerOf: */;
	for (i = (BASE_HEADER_SIZE); i <= lastField; i += (BYTES_PER_WORD)) {
		if ((longAt(rcvr + i)) == thang) {
			/* begin pushBool: */
			if (1) {
				/* begin push: */
				longAtput(sp2 = foo->stackPointer + (BYTES_PER_WORD), foo->trueObj);
				foo->stackPointer = sp2;
			} else {
				/* begin push: */
				longAtput(sp3 = foo->stackPointer + (BYTES_PER_WORD), foo->falseObj);
				foo->stackPointer = sp3;
			}
			return null;
		}
	}
	/* begin pushBool: */
	if (0) {
		/* begin push: */
		longAtput(sp4 = foo->stackPointer + (BYTES_PER_WORD), foo->trueObj);
		foo->stackPointer = sp4;
	} else {
		/* begin push: */
		longAtput(sp5 = foo->stackPointer + (BYTES_PER_WORD), foo->falseObj);
		foo->stackPointer = sp5;
	}
}

sqInt primitivePerform(void) {
register struct foo * foo = &fum;
    sqInt i;
    sqInt lookupClass;
    sqInt newReceiver;
    sqInt performMethod;
    sqInt performSelector;
    sqInt selectorIndex;
    sqInt successValue;
    sqInt fieldIndex;
    sqInt oop;
    sqInt valuePointer;
    sqInt oop1;
    sqInt valuePointer1;
    sqInt count;
    sqInt fromOop;
    sqInt toOop;
    sqInt fromIndex;
    sqInt lastFrom;
    sqInt toIndex;
    sqInt ccIndex;
    sqInt oop11;
    sqInt oop2;
    sqInt oop3;
    sqInt fieldIndex1;
    sqInt oop4;

	performSelector = foo->messageSelector;
	performMethod = foo->newMethod;
	foo->messageSelector = longAt(foo->stackPointer - ((foo->argumentCount - 1) * (BYTES_PER_WORD)));

	/* NOTE: the following lookup may fail and be converted to #doesNotUnderstand:, so we must adjust argumentCount and slide args now, so that would work. */
	/* Slide arguments down over selector */

	newReceiver = longAt(foo->stackPointer - (foo->argumentCount * (BYTES_PER_WORD)));
	foo->argumentCount -= 1;
	selectorIndex = (((usqInt) ((foo->stackPointer - foo->activeContext) - (BASE_HEADER_SIZE))) >> (SHIFT_FOR_WORD)) - foo->argumentCount;
	/* begin transfer:fromIndex:ofObject:toIndex:ofObject: */
	count = foo->argumentCount;
	fromOop = foo->activeContext;
	toOop = foo->activeContext;
	flag("Dan");
	fromIndex = fromOop + ((selectorIndex + 1) * (BYTES_PER_WORD));
	toIndex = toOop + (selectorIndex * (BYTES_PER_WORD));
	lastFrom = fromIndex + (count * (BYTES_PER_WORD));
	while ((((usqInt) fromIndex)) < (((usqInt) lastFrom))) {
		fromIndex += BYTES_PER_WORD;
		toIndex += BYTES_PER_WORD;
		longAtput(toIndex, longAt(fromIndex));
	}
	/* begin pop: */
	foo->stackPointer -= 1 * (BYTES_PER_WORD);
	/* begin fetchClassOf: */
	if ((newReceiver & 1)) {
		/* begin fetchPointer:ofObject: */
		oop11 = foo->specialObjectsOop;
		lookupClass = longAt((oop11 + (BASE_HEADER_SIZE)) + (ClassInteger << (SHIFT_FOR_WORD)));
		goto l1;
	}
	ccIndex = (((usqInt) (longAt(newReceiver))) >> 12) & 31;
	if (ccIndex == 0) {
		lookupClass = (longAt(newReceiver - (BASE_HEADER_SIZE))) & (ALL_BUT_TYPE_MASK);
		goto l1;
	} else {
		/* begin fetchPointer:ofObject: */
		/* begin fetchPointer:ofObject: */
		oop3 = foo->specialObjectsOop;
		oop2 = longAt((oop3 + (BASE_HEADER_SIZE)) + (CompactClasses << (SHIFT_FOR_WORD)));
		lookupClass = longAt((oop2 + (BASE_HEADER_SIZE)) + ((ccIndex - 1) << (SHIFT_FOR_WORD)));
		goto l1;
	}
l1:	/* end fetchClassOf: */;
	findNewMethodInClass(lookupClass);
	if (((foo->newMethod & 1) == 0) && (((((usqInt) (longAt(foo->newMethod))) >> 8) & 15) >= 12)) {
		/* begin success: */
		successValue = (argumentCountOf(foo->newMethod)) == foo->argumentCount;
		foo->successFlag = successValue && foo->successFlag;
	}
	if (foo->successFlag) {
		executeNewMethodFromCache();
		foo->successFlag = 1;
	} else {
		for (i = 1; i <= foo->argumentCount; i += 1) {
			/* begin storePointer:ofObject:withValue: */
			fieldIndex = ((foo->argumentCount - i) + 1) + selectorIndex;
			oop = foo->activeContext;
			/* begin fetchPointer:ofObject: */
			fieldIndex1 = (foo->argumentCount - i) + selectorIndex;
			oop4 = foo->activeContext;
			valuePointer = longAt((oop4 + (BASE_HEADER_SIZE)) + (fieldIndex1 << (SHIFT_FOR_WORD)));
			if ((((usqInt) oop)) < (((usqInt) foo->youngStart))) {
				possibleRootStoreIntovalue(oop, valuePointer);
			}
			longAtput((oop + (BASE_HEADER_SIZE)) + (fieldIndex << (SHIFT_FOR_WORD)), valuePointer);
		}
		/* begin unPop: */
		foo->stackPointer += 1 * (BYTES_PER_WORD);
		/* begin storePointer:ofObject:withValue: */
		oop1 = foo->activeContext;
		valuePointer1 = foo->messageSelector;
		if ((((usqInt) oop1)) < (((usqInt) foo->youngStart))) {
			possibleRootStoreIntovalue(oop1, valuePointer1);
		}
		longAtput((oop1 + (BASE_HEADER_SIZE)) + (selectorIndex << (SHIFT_FOR_WORD)), valuePointer1);
		foo->argumentCount += 1;
		foo->newMethod = performMethod;
		foo->messageSelector = performSelector;
	}
}


/*	Common routine used by perform:withArgs: and perform:withArgs:inSuperclass: */
/*	NOTE:  The case of doesNotUnderstand: is not a failure to perform.
	The only failures are arg types and consistency of argumentCount. */

sqInt primitivePerformAt(sqInt lookupClass) {
register struct foo * foo = &fum;
    sqInt argumentArray;
    sqInt arraySize;
    sqInt cntxSize;
    sqInt index;
    sqInt performArgCount;
    sqInt performMethod;
    sqInt performSelector;
    sqInt sz;
    sqInt header;
    sqInt objectPointer;
    sqInt sz1;
    sqInt header1;
    sqInt successValue;
    sqInt object;
    sqInt sp;
    sqInt successValue1;
    sqInt sp1;
    sqInt sp2;
    sqInt top;
    sqInt top1;

	argumentArray = longAt(foo->stackPointer);
	if (!(((argumentArray & 1) == 0) && (((((usqInt) (longAt(argumentArray))) >> 8) & 15) == 2))) {
		/* begin primitiveFail */
		foo->successFlag = 0;
		return null;
	}
	if (foo->successFlag) {
		/* begin fetchWordLengthOf: */
		/* begin sizeBitsOf: */
		header = longAt(argumentArray);
		if ((header & TypeMask) == HeaderTypeSizeAndClass) {
			sz = (longAt(argumentArray - ((BYTES_PER_WORD) * 2))) & (LONG_SIZE_MASK);
			goto l1;
		} else {
			sz = header & (SIZE_MASK);
			goto l1;
		}
	l1:	/* end sizeBitsOf: */;
		arraySize = ((usqInt) (sz - (BASE_HEADER_SIZE))) >> (SHIFT_FOR_WORD);
		/* begin fetchWordLengthOf: */
		objectPointer = foo->activeContext;
		/* begin sizeBitsOf: */
		header1 = longAt(objectPointer);
		if ((header1 & TypeMask) == HeaderTypeSizeAndClass) {
			sz1 = (longAt(objectPointer - ((BYTES_PER_WORD) * 2))) & (LONG_SIZE_MASK);
			goto l2;
		} else {
			sz1 = header1 & (SIZE_MASK);
			goto l2;
		}
	l2:	/* end sizeBitsOf: */;
		cntxSize = ((usqInt) (sz1 - (BASE_HEADER_SIZE))) >> (SHIFT_FOR_WORD);
		/* begin success: */
		successValue = ((((usqInt) ((foo->stackPointer - foo->activeContext) - (BASE_HEADER_SIZE))) >> (SHIFT_FOR_WORD)) + arraySize) < cntxSize;
		foo->successFlag = successValue && foo->successFlag;
	}
	if (!(foo->successFlag)) {
		return null;
	}
	performSelector = foo->messageSelector;
	performMethod = foo->newMethod;

	/* pop the arg array and the selector, then push the args out of the array, as if they were on the stack */

	performArgCount = foo->argumentCount;
	/* begin popStack */
	top = longAt(foo->stackPointer);
	foo->stackPointer -= BYTES_PER_WORD;
	/* begin popStack */
	top1 = longAt(foo->stackPointer);
	foo->stackPointer -= BYTES_PER_WORD;
	foo->messageSelector = top1;
	index = 1;
	while (index <= arraySize) {
		/* begin push: */
		object = longAt((argumentArray + (BASE_HEADER_SIZE)) + ((index - 1) << (SHIFT_FOR_WORD)));
		longAtput(sp = foo->stackPointer + (BYTES_PER_WORD), object);
		foo->stackPointer = sp;
		index += 1;
	}
	foo->argumentCount = arraySize;
	findNewMethodInClass(lookupClass);
	if (((foo->newMethod & 1) == 0) && (((((usqInt) (longAt(foo->newMethod))) >> 8) & 15) >= 12)) {
		/* begin success: */
		successValue1 = (argumentCountOf(foo->newMethod)) == foo->argumentCount;
		foo->successFlag = successValue1 && foo->successFlag;
	}
	if (foo->successFlag) {
		executeNewMethodFromCache();
		foo->successFlag = 1;
	} else {
		/* begin pop: */
		foo->stackPointer -= foo->argumentCount * (BYTES_PER_WORD);
		/* begin push: */
		longAtput(sp1 = foo->stackPointer + (BYTES_PER_WORD), foo->messageSelector);
		foo->stackPointer = sp1;
		/* begin push: */
		longAtput(sp2 = foo->stackPointer + (BYTES_PER_WORD), argumentArray);
		foo->stackPointer = sp2;
		foo->messageSelector = performSelector;
		foo->newMethod = performMethod;
		foo->argumentCount = performArgCount;
	}
}

sqInt primitivePerformInSuperclass(void) {
register struct foo * foo = &fum;
    sqInt currentClass;
    sqInt lookupClass;
    sqInt rcvr;
    sqInt sp;
    sqInt ccIndex;
    sqInt oop1;
    sqInt oop2;
    sqInt top;
    sqInt oop;

	lookupClass = longAt(foo->stackPointer);
	rcvr = longAt(foo->stackPointer - (foo->argumentCount * (BYTES_PER_WORD)));
	/* begin fetchClassOf: */
	if ((rcvr & 1)) {
		/* begin fetchPointer:ofObject: */
		oop1 = foo->specialObjectsOop;
		currentClass = longAt((oop1 + (BASE_HEADER_SIZE)) + (ClassInteger << (SHIFT_FOR_WORD)));
		goto l1;
	}
	ccIndex = (((usqInt) (longAt(rcvr))) >> 12) & 31;
	if (ccIndex == 0) {
		currentClass = (longAt(rcvr - (BASE_HEADER_SIZE))) & (ALL_BUT_TYPE_MASK);
		goto l1;
	} else {
		/* begin fetchPointer:ofObject: */
		/* begin fetchPointer:ofObject: */
		oop = foo->specialObjectsOop;
		oop2 = longAt((oop + (BASE_HEADER_SIZE)) + (CompactClasses << (SHIFT_FOR_WORD)));
		currentClass = longAt((oop2 + (BASE_HEADER_SIZE)) + ((ccIndex - 1) << (SHIFT_FOR_WORD)));
		goto l1;
	}
l1:	/* end fetchClassOf: */;
	while (currentClass != lookupClass) {
		currentClass = longAt((currentClass + (BASE_HEADER_SIZE)) + (SuperclassIndex << (SHIFT_FOR_WORD)));
		if (currentClass == foo->nilObj) {
			/* begin primitiveFail */
			foo->successFlag = 0;
			return null;
		}
	}
	/* begin popStack */
	top = longAt(foo->stackPointer);
	foo->stackPointer -= BYTES_PER_WORD;
	primitivePerformAt(lookupClass);
	if (!(foo->successFlag)) {
		/* begin push: */
		longAtput(sp = foo->stackPointer + (BYTES_PER_WORD), lookupClass);
		foo->stackPointer = sp;
	}
}

sqInt primitivePerformWithArgs(void) {
register struct foo * foo = &fum;
    sqInt lookupClass;
    sqInt rcvr;
    sqInt ccIndex;
    sqInt oop;
    sqInt oop1;
    sqInt oop2;

	rcvr = longAt(foo->stackPointer - (foo->argumentCount * (BYTES_PER_WORD)));
	/* begin fetchClassOf: */
	if ((rcvr & 1)) {
		/* begin fetchPointer:ofObject: */
		oop = foo->specialObjectsOop;
		lookupClass = longAt((oop + (BASE_HEADER_SIZE)) + (ClassInteger << (SHIFT_FOR_WORD)));
		goto l1;
	}
	ccIndex = (((usqInt) (longAt(rcvr))) >> 12) & 31;
	if (ccIndex == 0) {
		lookupClass = (longAt(rcvr - (BASE_HEADER_SIZE))) & (ALL_BUT_TYPE_MASK);
		goto l1;
	} else {
		/* begin fetchPointer:ofObject: */
		/* begin fetchPointer:ofObject: */
		oop2 = foo->specialObjectsOop;
		oop1 = longAt((oop2 + (BASE_HEADER_SIZE)) + (CompactClasses << (SHIFT_FOR_WORD)));
		lookupClass = longAt((oop1 + (BASE_HEADER_SIZE)) + ((ccIndex - 1) << (SHIFT_FOR_WORD)));
		goto l1;
	}
l1:	/* end fetchClassOf: */;
	primitivePerformAt(lookupClass);
}


/*	Answer a string corresponding to the version of the external platform source
	code, typically written in C and managed separately for each platform.
	This is a named (not numbered) primitive in the null module (ie the VM) */

EXPORT(sqInt) primitivePlatformSourceVersion(void) {
register struct foo * foo = &fum;
    sqInt len;
    void * p;
    sqInt versionString;
    sqInt sp;

	
# ifdef PLATFORM_SOURCE_VERSION  // version level of platform support code
	len = strlen(PLATFORM_SOURCE_VERSION);
	versionString = instantiateClassindexableSize(fetchPointerofObject(ClassString, foo->specialObjectsOop), len);
	/* begin arrayValueOf: */
	if ((!((versionString & 1))) && (((versionString & 1) == 0) && (isWordsOrBytesNonInt(versionString)))) {
		p = pointerForOop(versionString + (BASE_HEADER_SIZE));
		goto l1;
	}
	/* begin primitiveFail */
	foo->successFlag = 0;
l1:	/* end arrayValueOf: */;
	strncpy(p, PLATFORM_SOURCE_VERSION, len);
# else
	/* begin primitiveFail */
	foo->successFlag = 0;
	return null;
# endif  // PLATFORM_SOURCE_VERSION
	
	/* begin pop:thenPush: */
	longAtput(sp = foo->stackPointer - ((1 - 1) * (BYTES_PER_WORD)), versionString);
	foo->stackPointer = sp;
}

sqInt primitivePushFalse(void) {
register struct foo * foo = &fum;
    sqInt top;
    sqInt sp;

	/* begin popStack */
	top = longAt(foo->stackPointer);
	foo->stackPointer -= BYTES_PER_WORD;
	/* begin push: */
	longAtput(sp = foo->stackPointer + (BYTES_PER_WORD), foo->falseObj);
	foo->stackPointer = sp;
}

sqInt primitivePushMinusOne(void) {
register struct foo * foo = &fum;
    sqInt top;
    sqInt sp;

	/* begin popStack */
	top = longAt(foo->stackPointer);
	foo->stackPointer -= BYTES_PER_WORD;
	/* begin push: */
	longAtput(sp = foo->stackPointer + (BYTES_PER_WORD), ConstMinusOne);
	foo->stackPointer = sp;
}

sqInt primitivePushNil(void) {
register struct foo * foo = &fum;
    sqInt top;
    sqInt sp;

	/* begin popStack */
	top = longAt(foo->stackPointer);
	foo->stackPointer -= BYTES_PER_WORD;
	/* begin push: */
	longAtput(sp = foo->stackPointer + (BYTES_PER_WORD), foo->nilObj);
	foo->stackPointer = sp;
}

sqInt primitivePushOne(void) {
register struct foo * foo = &fum;
    sqInt top;
    sqInt sp;

	/* begin popStack */
	top = longAt(foo->stackPointer);
	foo->stackPointer -= BYTES_PER_WORD;
	/* begin push: */
	longAtput(sp = foo->stackPointer + (BYTES_PER_WORD), ConstOne);
	foo->stackPointer = sp;
}


/*		no-op, really...
	thisReceiver := self popStack.
	self push: thisReceiver
 */

sqInt primitivePushSelf(void) {
}

sqInt primitivePushTrue(void) {
register struct foo * foo = &fum;
    sqInt top;
    sqInt sp;

	/* begin popStack */
	top = longAt(foo->stackPointer);
	foo->stackPointer -= BYTES_PER_WORD;
	/* begin push: */
	longAtput(sp = foo->stackPointer + (BYTES_PER_WORD), foo->trueObj);
	foo->stackPointer = sp;
}

sqInt primitivePushTwo(void) {
register struct foo * foo = &fum;
    sqInt top;
    sqInt sp;

	/* begin popStack */
	top = longAt(foo->stackPointer);
	foo->stackPointer -= BYTES_PER_WORD;
	/* begin push: */
	longAtput(sp = foo->stackPointer + (BYTES_PER_WORD), ConstTwo);
	foo->stackPointer = sp;
}

sqInt primitivePushZero(void) {
register struct foo * foo = &fum;
    sqInt top;
    sqInt sp;

	/* begin popStack */
	top = longAt(foo->stackPointer);
	foo->stackPointer -= BYTES_PER_WORD;
	/* begin push: */
	longAtput(sp = foo->stackPointer + (BYTES_PER_WORD), ConstZero);
	foo->stackPointer = sp;
}

sqInt primitiveQuit(void) {
	ioExit();
}


/*	Rounds negative results towards zero. */

sqInt primitiveQuo(void) {
register struct foo * foo = &fum;
    sqInt integerArg;
    sqInt integerRcvr;
    sqInt integerResult;
    sqInt sp;
    sqInt integerPointer;
    sqInt integerPointer1;

	/* begin stackIntegerValue: */
	integerPointer = longAt(foo->stackPointer - (1 * (BYTES_PER_WORD)));
	/* begin checkedIntegerValueOf: */
	if ((integerPointer & 1)) {
		integerRcvr = (integerPointer >> 1);
		goto l1;
	} else {
		/* begin primitiveFail */
		foo->successFlag = 0;
		integerRcvr = 0;
		goto l1;
	}
	integerRcvr = null;
l1:	/* end stackIntegerValue: */;
	/* begin stackIntegerValue: */
	integerPointer1 = longAt(foo->stackPointer - (0 * (BYTES_PER_WORD)));
	/* begin checkedIntegerValueOf: */
	if ((integerPointer1 & 1)) {
		integerArg = (integerPointer1 >> 1);
		goto l2;
	} else {
		/* begin primitiveFail */
		foo->successFlag = 0;
		integerArg = 0;
		goto l2;
	}
	integerArg = null;
l2:	/* end stackIntegerValue: */;
	/* begin success: */
	foo->successFlag = (integerArg != 0) && foo->successFlag;
	if (foo->successFlag) {
		if (integerRcvr > 0) {
			if (integerArg > 0) {
				integerResult = integerRcvr / integerArg;
			} else {
				integerResult = 0 - (integerRcvr / (0 - integerArg));
			}
		} else {
			if (integerArg > 0) {
				integerResult = 0 - ((0 - integerRcvr) / integerArg);
			} else {
				integerResult = (0 - integerRcvr) / (0 - integerArg);
			}
		}
	}
	/* begin pop2AndPushIntegerIfOK: */
	if (foo->successFlag) {
		if (
# ifdef SQ_HOST32  // cast to int for 64 bit image on 32 bit host
			(((((int) integerResult)) ^ ((((int) integerResult)) << 1)) >= 0)
# else
			((integerResult >= -1073741824) && (integerResult <= 1073741823))
# endif  // SQ_HOST32
		) {
			/* begin pop:thenPush: */
			longAtput(sp = foo->stackPointer - ((2 - 1) * (BYTES_PER_WORD)), ((integerResult << 1) | 1));
			foo->stackPointer = sp;
		} else {
			foo->successFlag = 0;
		}
	}
}


/*	Primitive arithmetic operations for large integers in 64 bit range */

EXPORT(sqInt) primitiveQuoLargeIntegers(void) {
register struct foo * foo = &fum;
    sqLong integerArg;
    sqLong integerRcvr;
    sqInt oopResult;
    sqLong result;
    sqInt sp;

	integerArg = signed64BitValueOf(longAt(foo->stackPointer - (0 * (BYTES_PER_WORD))));
	integerRcvr = signed64BitValueOf(longAt(foo->stackPointer - (1 * (BYTES_PER_WORD))));
	if (integerArg == 0) {
		/* begin primitiveFail */
		foo->successFlag = 0;
	}
	if (!(foo->successFlag)) {
		return null;
	}
	if (integerRcvr > 0) {
		if (integerArg > 0) {
			result = integerRcvr / integerArg;
		} else {
			result = 0 - (integerRcvr / (0 - integerArg));
		}
	} else {
		if (integerArg > 0) {
			result = 0 - ((0 - integerRcvr) / integerArg);
		} else {
			result = (0 - integerRcvr) / (0 - integerArg);
		}
	}
	oopResult = signed64BitIntegerFor(result);
	if (foo->successFlag) {
		/* begin pop:thenPush: */
		longAtput(sp = foo->stackPointer - ((2 - 1) * (BYTES_PER_WORD)), oopResult);
		foo->stackPointer = sp;
	}
}


/*	Relinquish the processor for up to the given number of microseconds. The exact behavior of this primitive is platform dependent. */

sqInt primitiveRelinquishProcessor(void) {
register struct foo * foo = &fum;
    sqInt microSecs;
    sqInt integerPointer;

	/* begin stackIntegerValue: */
	integerPointer = longAt(foo->stackPointer - (0 * (BYTES_PER_WORD)));
	/* begin checkedIntegerValueOf: */
	if ((integerPointer & 1)) {
		microSecs = (integerPointer >> 1);
		goto l1;
	} else {
		/* begin primitiveFail */
		foo->successFlag = 0;
		microSecs = 0;
		goto l1;
	}
	microSecs = null;
l1:	/* end stackIntegerValue: */;
	if (foo->successFlag) {
		ioRelinquishProcessorForMicroseconds(microSecs);
		/* begin pop: */
		foo->stackPointer -= 1 * (BYTES_PER_WORD);
	}
}


/*	NB: tpr removed the timer checks here and moved them to the primitiveExternalCall method.
	We make the possibly unwarranted assumption that numbered prims are quick and external prims are slow. */

sqInt primitiveResponse(void) {
register struct foo * foo = &fum;
    sqInt delta;
    sqInt nArgs;
    sqInt primIdx;

	if (DoBalanceChecks) {

		/* check stack balance */

		nArgs = foo->argumentCount;
		delta = foo->stackPointer - foo->activeContext;
	}
	primIdx = foo->primitiveIndex;

	/* self dispatchOn: primitiveIndex in: primitiveTable. */

	foo->successFlag = 1;
	dispatchFunctionPointerOnin(primIdx, primitiveTable);
	if (DoBalanceChecks) {
		if (!(balancedStackafterPrimitivewithArgs(delta, primIdx, nArgs))) {
			printUnbalancedStack(primIdx);
		}
	}

	/* clear out primIndex so VM knows we're no longer in primitive */

	foo->primitiveIndex = 0;
	return foo->successFlag;
}


/*	put this process on the scheduler's lists thus allowing it to proceed next time there is a chance for processes of it's priority level */

sqInt primitiveResume(void) {
register struct foo * foo = &fum;
    sqInt proc;


	/* rcvr */
	/* self success: ((self fetchClassOf: proc) = (self splObj: ClassProcess)). */

	proc = longAt(foo->stackPointer);
	if (foo->successFlag) {
		resume(proc);
	}
}


/*	Primitive. Answer a copy (snapshot) element of the root table.
	The primitive can cause GC itself and if so the return value may
	be inaccurate - in this case one should guard the read operation
	by looking at the gc counter statistics. */

EXPORT(sqInt) primitiveRootTable(void) {
register struct foo * foo = &fum;
    sqInt i;
    sqInt oop;
    sqInt sz;
    sqInt sp;
    sqInt valuePointer;

	sz = foo->rootTableCount;

	/* can cause GC */

	oop = instantiateClassindexableSize(fetchPointerofObject(ClassArray, foo->specialObjectsOop), sz);
	if (sz > foo->rootTableCount) {
		sz = foo->rootTableCount;
	}
	for (i = 1; i <= sz; i += 1) {
		/* begin storePointer:ofObject:withValue: */
		valuePointer = foo->rootTable[i];
		if ((((usqInt) oop)) < (((usqInt) foo->youngStart))) {
			possibleRootStoreIntovalue(oop, valuePointer);
		}
		longAtput((oop + (BASE_HEADER_SIZE)) + ((i - 1) << (SHIFT_FOR_WORD)), valuePointer);
	}
	/* begin pop: */
	foo->stackPointer -= (foo->argumentCount + 1) * (BYTES_PER_WORD);
	/* begin push: */
	longAtput(sp = foo->stackPointer + (BYTES_PER_WORD), oop);
	foo->stackPointer = sp;
}


/*	Primitive. Answer the nth element of the root table.
	This primitive avoids the creation of an extra array;
	it is intended for enumerations of the form:
		index := 1.
		[root := Smalltalk rootTableAt: index.
		root == nil] whileFalse:[index := index + 1].
	 */

EXPORT(sqInt) primitiveRootTableAt(void) {
register struct foo * foo = &fum;
    sqInt index;
    sqInt sp;
    sqInt successValue;
    sqInt integerPointer;

	/* begin stackIntegerValue: */
	integerPointer = longAt(foo->stackPointer - (0 * (BYTES_PER_WORD)));
	/* begin checkedIntegerValueOf: */
	if ((integerPointer & 1)) {
		index = (integerPointer >> 1);
		goto l1;
	} else {
		/* begin primitiveFail */
		foo->successFlag = 0;
		index = 0;
		goto l1;
	}
	index = null;
l1:	/* end stackIntegerValue: */;
	/* begin success: */
	successValue = (index > 0) && (index <= foo->rootTableCount);
	foo->successFlag = successValue && foo->successFlag;
	if (foo->successFlag) {
		/* begin pop: */
		foo->stackPointer -= (foo->argumentCount + 1) * (BYTES_PER_WORD);
		/* begin push: */
		longAtput(sp = foo->stackPointer + (BYTES_PER_WORD), foo->rootTable[index]);
		foo->stackPointer = sp;
	}
}


/*	The character scanner primitive. */

sqInt primitiveScanCharacters(void) {
register struct foo * foo = &fum;
    sqInt ascii;
    sqInt glyphIndex;
    sqInt kernDelta;
    sqInt maxGlyph;
    sqInt nextDestX;
    sqInt nilOop;
    sqInt rcvr;
    sqInt scanDestX;
    sqInt scanLastIndex;
    sqInt scanMap;
    sqInt scanRightX;
    sqInt scanStartIndex;
    sqInt scanStopIndex;
    sqInt scanXTable;
    sqInt sourceString;
    sqInt sourceX;
    sqInt sourceX2;
    sqInt stopReason;
    sqInt stops;
    sqInt sp;
    sqInt object;
    sqInt sp1;
    sqInt object1;
    sqInt sp2;
    sqInt oop;
    sqInt oop1;
    sqInt oop2;
    sqInt integerPointer;
    sqInt integerPointer1;
    sqInt integerPointer2;
    sqInt integerPointer3;

	if (!(foo->argumentCount == 6)) {
		/* begin primitiveFail */
		foo->successFlag = 0;
		return null;
	}
	/* begin stackIntegerValue: */
	integerPointer = longAt(foo->stackPointer - (0 * (BYTES_PER_WORD)));
	/* begin checkedIntegerValueOf: */
	if ((integerPointer & 1)) {
		kernDelta = (integerPointer >> 1);
		goto l4;
	} else {
		/* begin primitiveFail */
		foo->successFlag = 0;
		kernDelta = 0;
		goto l4;
	}
	kernDelta = null;
l4:	/* end stackIntegerValue: */;
	/* begin stackObjectValue: */
	oop = longAt(foo->stackPointer - (1 * (BYTES_PER_WORD)));
	if ((oop & 1)) {
		/* begin primitiveFail */
		foo->successFlag = 0;
		stops = null;
		goto l1;
	}
	stops = oop;
l1:	/* end stackObjectValue: */;
	if (!(((stops & 1) == 0) && (((((usqInt) (longAt(stops))) >> 8) & 15) == 2))) {
		/* begin primitiveFail */
		foo->successFlag = 0;
		return null;
	}
	if (!((slotSizeOf(stops)) >= 258)) {
		/* begin primitiveFail */
		foo->successFlag = 0;
		return null;
	}
	/* begin stackIntegerValue: */
	integerPointer1 = longAt(foo->stackPointer - (2 * (BYTES_PER_WORD)));
	/* begin checkedIntegerValueOf: */
	if ((integerPointer1 & 1)) {
		scanRightX = (integerPointer1 >> 1);
		goto l5;
	} else {
		/* begin primitiveFail */
		foo->successFlag = 0;
		scanRightX = 0;
		goto l5;
	}
	scanRightX = null;
l5:	/* end stackIntegerValue: */;
	/* begin stackObjectValue: */
	oop1 = longAt(foo->stackPointer - (3 * (BYTES_PER_WORD)));
	if ((oop1 & 1)) {
		/* begin primitiveFail */
		foo->successFlag = 0;
		sourceString = null;
		goto l2;
	}
	sourceString = oop1;
l2:	/* end stackObjectValue: */;
	if (!(((sourceString & 1) == 0) && (((((usqInt) (longAt(sourceString))) >> 8) & 15) >= 8))) {
		/* begin primitiveFail */
		foo->successFlag = 0;
		return null;
	}
	/* begin stackIntegerValue: */
	integerPointer2 = longAt(foo->stackPointer - (4 * (BYTES_PER_WORD)));
	/* begin checkedIntegerValueOf: */
	if ((integerPointer2 & 1)) {
		scanStopIndex = (integerPointer2 >> 1);
		goto l6;
	} else {
		/* begin primitiveFail */
		foo->successFlag = 0;
		scanStopIndex = 0;
		goto l6;
	}
	scanStopIndex = null;
l6:	/* end stackIntegerValue: */;
	/* begin stackIntegerValue: */
	integerPointer3 = longAt(foo->stackPointer - (5 * (BYTES_PER_WORD)));
	/* begin checkedIntegerValueOf: */
	if ((integerPointer3 & 1)) {
		scanStartIndex = (integerPointer3 >> 1);
		goto l7;
	} else {
		/* begin primitiveFail */
		foo->successFlag = 0;
		scanStartIndex = 0;
		goto l7;
	}
	scanStartIndex = null;
l7:	/* end stackIntegerValue: */;
	if (!((scanStartIndex > 0) && ((scanStopIndex > 0) && (scanStopIndex <= (byteSizeOf(sourceString)))))) {
		/* begin primitiveFail */
		foo->successFlag = 0;
		return null;
	}
	/* begin stackObjectValue: */
	oop2 = longAt(foo->stackPointer - (6 * (BYTES_PER_WORD)));
	if ((oop2 & 1)) {
		/* begin primitiveFail */
		foo->successFlag = 0;
		rcvr = null;
		goto l3;
	}
	rcvr = oop2;
l3:	/* end stackObjectValue: */;
	if (!((((rcvr & 1) == 0) && (((((usqInt) (longAt(rcvr))) >> 8) & 15) <= 4)) && ((slotSizeOf(rcvr)) >= 4))) {
		/* begin primitiveFail */
		foo->successFlag = 0;
		return null;
	}
	scanDestX = fetchIntegerofObject(0, rcvr);
	scanLastIndex = fetchIntegerofObject(1, rcvr);
	scanXTable = longAt((rcvr + (BASE_HEADER_SIZE)) + (2 << (SHIFT_FOR_WORD)));
	scanMap = longAt((rcvr + (BASE_HEADER_SIZE)) + (3 << (SHIFT_FOR_WORD)));
	if (!((((scanXTable & 1) == 0) && (((((usqInt) (longAt(scanXTable))) >> 8) & 15) == 2)) && (((scanMap & 1) == 0) && (((((usqInt) (longAt(scanMap))) >> 8) & 15) == 2)))) {
		/* begin primitiveFail */
		foo->successFlag = 0;
		return null;
	}
	if (!((slotSizeOf(scanMap)) == 256)) {
		/* begin primitiveFail */
		foo->successFlag = 0;
		return null;
	}
	if (!(foo->successFlag)) {
		return null;
	}

	/* Okay, here we go. We have eliminated nearly all failure 
	conditions, to optimize the inner fetches. */

	maxGlyph = (slotSizeOf(scanXTable)) - 2;
	scanLastIndex = scanStartIndex;
	nilOop = foo->nilObj;
	while (scanLastIndex <= scanStopIndex) {

		/* Known to be okay since scanStartIndex > 0 and scanStopIndex <= sourceString size */
		/* Known to be okay since stops size >= 258 */

		ascii = byteAt((sourceString + (BASE_HEADER_SIZE)) + (scanLastIndex - 1));
		if (!((stopReason = longAt((stops + (BASE_HEADER_SIZE)) + (ascii << (SHIFT_FOR_WORD)))) == nilOop)) {
			if (!(
# ifdef SQ_HOST32  // cast to int for 64 bit image on 32 bit host
					(((((int) scanDestX)) ^ ((((int) scanDestX)) << 1)) >= 0)
# else
					((scanDestX >= -1073741824) && (scanDestX <= 1073741823))
# endif  // SQ_HOST32
				)) {
				/* begin primitiveFail */
				foo->successFlag = 0;
				return null;
			}
			/* begin storeInteger:ofObject:withValue: */
			if (
# ifdef SQ_HOST32  // cast to int for 64 bit image on 32 bit host
				(((((int) scanDestX)) ^ ((((int) scanDestX)) << 1)) >= 0)
# else
				((scanDestX >= -1073741824) && (scanDestX <= 1073741823))
# endif  // SQ_HOST32
			) {
				longAtput((rcvr + (BASE_HEADER_SIZE)) + (0 << (SHIFT_FOR_WORD)), ((scanDestX << 1) | 1));
			} else {
				/* begin primitiveFail */
				foo->successFlag = 0;
			}
			/* begin storeInteger:ofObject:withValue: */
			if (
# ifdef SQ_HOST32  // cast to int for 64 bit image on 32 bit host
				(((((int) scanLastIndex)) ^ ((((int) scanLastIndex)) << 1)) >= 0)
# else
				((scanLastIndex >= -1073741824) && (scanLastIndex <= 1073741823))
# endif  // SQ_HOST32
			) {
				longAtput((rcvr + (BASE_HEADER_SIZE)) + (1 << (SHIFT_FOR_WORD)), ((scanLastIndex << 1) | 1));
			} else {
				/* begin primitiveFail */
				foo->successFlag = 0;
			}
			/* begin pop: */
			foo->stackPointer -= 7 * (BYTES_PER_WORD);
			/* begin push: */
			longAtput(sp = foo->stackPointer + (BYTES_PER_WORD), stopReason);
			foo->stackPointer = sp;
			return null;
		}

		/* fail if the glyphIndex is out of range */

		glyphIndex = fetchIntegerofObject(ascii, scanMap);
		if ((!foo->successFlag) || ((glyphIndex < 0) || (glyphIndex > maxGlyph))) {
			/* begin primitiveFail */
			foo->successFlag = 0;
			return null;
		}
		sourceX = fetchIntegerofObject(glyphIndex, scanXTable);

		/* Above may fail if non-integer entries in scanXTable */

		sourceX2 = fetchIntegerofObject(glyphIndex + 1, scanXTable);
		if (!foo->successFlag) {
			return null;
		}
		nextDestX = (scanDestX + sourceX2) - sourceX;
		if (nextDestX > scanRightX) {
			if (!(
# ifdef SQ_HOST32  // cast to int for 64 bit image on 32 bit host
					(((((int) scanDestX)) ^ ((((int) scanDestX)) << 1)) >= 0)
# else
					((scanDestX >= -1073741824) && (scanDestX <= 1073741823))
# endif  // SQ_HOST32
				)) {
				/* begin primitiveFail */
				foo->successFlag = 0;
				return null;
			}
			/* begin storeInteger:ofObject:withValue: */
			if (
# ifdef SQ_HOST32  // cast to int for 64 bit image on 32 bit host
				(((((int) scanDestX)) ^ ((((int) scanDestX)) << 1)) >= 0)
# else
				((scanDestX >= -1073741824) && (scanDestX <= 1073741823))
# endif  // SQ_HOST32
			) {
				longAtput((rcvr + (BASE_HEADER_SIZE)) + (0 << (SHIFT_FOR_WORD)), ((scanDestX << 1) | 1));
			} else {
				/* begin primitiveFail */
				foo->successFlag = 0;
			}
			/* begin storeInteger:ofObject:withValue: */
			if (
# ifdef SQ_HOST32  // cast to int for 64 bit image on 32 bit host
				(((((int) scanLastIndex)) ^ ((((int) scanLastIndex)) << 1)) >= 0)
# else
				((scanLastIndex >= -1073741824) && (scanLastIndex <= 1073741823))
# endif  // SQ_HOST32
			) {
				longAtput((rcvr + (BASE_HEADER_SIZE)) + (1 << (SHIFT_FOR_WORD)), ((scanLastIndex << 1) | 1));
			} else {
				/* begin primitiveFail */
				foo->successFlag = 0;
			}
			/* begin pop: */
			foo->stackPointer -= 7 * (BYTES_PER_WORD);
			/* begin push: */
			object = longAt((stops + (BASE_HEADER_SIZE)) + ((CrossedX - 1) << (SHIFT_FOR_WORD)));
			longAtput(sp1 = foo->stackPointer + (BYTES_PER_WORD), object);
			foo->stackPointer = sp1;
			return null;
		}
		scanDestX = nextDestX + kernDelta;
		scanLastIndex += 1;
	}
	if (!(
# ifdef SQ_HOST32  // cast to int for 64 bit image on 32 bit host
			(((((int) scanDestX)) ^ ((((int) scanDestX)) << 1)) >= 0)
# else
			((scanDestX >= -1073741824) && (scanDestX <= 1073741823))
# endif  // SQ_HOST32
		)) {
		/* begin primitiveFail */
		foo->successFlag = 0;
		return null;
	}
	/* begin storeInteger:ofObject:withValue: */
	if (
# ifdef SQ_HOST32  // cast to int for 64 bit image on 32 bit host
		(((((int) scanDestX)) ^ ((((int) scanDestX)) << 1)) >= 0)
# else
		((scanDestX >= -1073741824) && (scanDestX <= 1073741823))
# endif  // SQ_HOST32
	) {
		longAtput((rcvr + (BASE_HEADER_SIZE)) + (0 << (SHIFT_FOR_WORD)), ((scanDestX << 1) | 1));
	} else {
		/* begin primitiveFail */
		foo->successFlag = 0;
	}
	/* begin storeInteger:ofObject:withValue: */
	if (
# ifdef SQ_HOST32  // cast to int for 64 bit image on 32 bit host
		(((((int) scanStopIndex)) ^ ((((int) scanStopIndex)) << 1)) >= 0)
# else
		((scanStopIndex >= -1073741824) && (scanStopIndex <= 1073741823))
# endif  // SQ_HOST32
	) {
		longAtput((rcvr + (BASE_HEADER_SIZE)) + (1 << (SHIFT_FOR_WORD)), ((scanStopIndex << 1) | 1));
	} else {
		/* begin primitiveFail */
		foo->successFlag = 0;
	}
	/* begin pop: */
	foo->stackPointer -= 7 * (BYTES_PER_WORD);
	/* begin push: */
	object1 = longAt((stops + (BASE_HEADER_SIZE)) + ((EndOfRun - 1) << (SHIFT_FOR_WORD)));
	longAtput(sp2 = foo->stackPointer + (BYTES_PER_WORD), object1);
	foo->stackPointer = sp2;
	return null;
}


/*	Return a SmallInteger indicating the current depth of the OS screen. Negative values are used to imply LSB type pixel format an there is some support in the VM for handling either MSB or LSB */

EXPORT(sqInt) primitiveScreenDepth(void) {
register struct foo * foo = &fum;
    sqInt depth;
    sqInt sp;

	depth = ioScreenDepth();
	if (!foo->successFlag) {
		/* begin primitiveFail */
		foo->successFlag = 0;
		return null;
	}
	/* begin pop:thenPushInteger: */
	longAtput(sp = foo->stackPointer - ((1 - 1) * (BYTES_PER_WORD)), ((depth << 1) | 1));
	foo->stackPointer = sp;
}


/*	Return a point indicating the current size of the Smalltalk window. Currently there is a limit of 65535 in each direction because the point is encoded into a single 32bit value in the image header. This might well become a problem one day */

sqInt primitiveScreenSize(void) {
register struct foo * foo = &fum;
    sqInt pointWord;
    sqInt object;
    sqInt sp;
    sqInt pointResult;

	/* begin pop: */
	foo->stackPointer -= 1 * (BYTES_PER_WORD);
	pointWord = ioScreenSize();
	/* begin push: */
	/* begin makePointwithxValue:yValue: */
	pointResult = instantiateSmallClasssizeInBytes(fetchPointerofObject(ClassPoint, foo->specialObjectsOop), 3 * (BYTES_PER_WORD));
	longAtput((pointResult + (BASE_HEADER_SIZE)) + (XIndex << (SHIFT_FOR_WORD)), ((((((usqInt) pointWord) >> 16) & 65535) << 1) | 1));
	longAtput((pointResult + (BASE_HEADER_SIZE)) + (YIndex << (SHIFT_FOR_WORD)), (((pointWord & 65535) << 1) | 1));
	object = pointResult;
	longAtput(sp = foo->stackPointer + (BYTES_PER_WORD), object);
	foo->stackPointer = sp;
}


/*	Return the number of seconds since January 1, 1901 as an integer. */

sqInt primitiveSecondsClock(void) {
register struct foo * foo = &fum;
    sqInt oop;
    sqInt sp;

	/* begin pop:thenPush: */
	oop = positive32BitIntegerFor(ioSeconds());
	longAtput(sp = foo->stackPointer - ((1 - 1) * (BYTES_PER_WORD)), oop);
	foo->stackPointer = sp;
}


/*	Set to OS to the requested display mode.
	See also DisplayScreen setDisplayDepth:extent:fullscreen: */

sqInt primitiveSetDisplayMode(void) {
register struct foo * foo = &fum;
    sqInt d;
    sqInt fsFlag;
    sqInt h;
    sqInt okay;
    sqInt w;
    sqInt sp;
    sqInt sp1;
    sqInt integerPointer;
    sqInt integerPointer1;
    sqInt integerPointer2;

	/* begin booleanValueOf: */
	if ((longAt(foo->stackPointer)) == foo->trueObj) {
		fsFlag = 1;
		goto l1;
	}
	if ((longAt(foo->stackPointer)) == foo->falseObj) {
		fsFlag = 0;
		goto l1;
	}
	foo->successFlag = 0;
	fsFlag = null;
l1:	/* end booleanValueOf: */;
	/* begin stackIntegerValue: */
	integerPointer = longAt(foo->stackPointer - (1 * (BYTES_PER_WORD)));
	/* begin checkedIntegerValueOf: */
	if ((integerPointer & 1)) {
		h = (integerPointer >> 1);
		goto l2;
	} else {
		/* begin primitiveFail */
		foo->successFlag = 0;
		h = 0;
		goto l2;
	}
	h = null;
l2:	/* end stackIntegerValue: */;
	/* begin stackIntegerValue: */
	integerPointer1 = longAt(foo->stackPointer - (2 * (BYTES_PER_WORD)));
	/* begin checkedIntegerValueOf: */
	if ((integerPointer1 & 1)) {
		w = (integerPointer1 >> 1);
		goto l3;
	} else {
		/* begin primitiveFail */
		foo->successFlag = 0;
		w = 0;
		goto l3;
	}
	w = null;
l3:	/* end stackIntegerValue: */;
	/* begin stackIntegerValue: */
	integerPointer2 = longAt(foo->stackPointer - (3 * (BYTES_PER_WORD)));
	/* begin checkedIntegerValueOf: */
	if ((integerPointer2 & 1)) {
		d = (integerPointer2 >> 1);
		goto l4;
	} else {
		/* begin primitiveFail */
		foo->successFlag = 0;
		d = 0;
		goto l4;
	}
	d = null;
l4:	/* end stackIntegerValue: */;
	if (foo->successFlag) {
		okay = ioSetDisplayMode(w, h, d, fsFlag);
	}
	if (foo->successFlag) {
		/* begin pop: */
		foo->stackPointer -= 5 * (BYTES_PER_WORD);
		/* begin pushBool: */
		if (okay) {
			/* begin push: */
			longAtput(sp = foo->stackPointer + (BYTES_PER_WORD), foo->trueObj);
			foo->stackPointer = sp;
		} else {
			/* begin push: */
			longAtput(sp1 = foo->stackPointer + (BYTES_PER_WORD), foo->falseObj);
			foo->stackPointer = sp1;
		}
	}
}


/*	On platforms that support it, set full-screen mode to the value of the boolean argument. */

sqInt primitiveSetFullScreen(void) {
register struct foo * foo = &fum;
    sqInt argOop;

	argOop = longAt(foo->stackPointer);
	if (argOop == foo->trueObj) {
		ioSetFullScreen(1);
	} else {
		if (argOop == foo->falseObj) {
			ioSetFullScreen(0);
		} else {
			/* begin primitiveFail */
			foo->successFlag = 0;
		}
	}
	if (foo->successFlag) {
		/* begin pop: */
		foo->stackPointer -= 1 * (BYTES_PER_WORD);
	}
}


/*	Primitive. Indicate if the GC logic should have bias to grow */

EXPORT(sqInt) primitiveSetGCBiasToGrow(void) {
register struct foo * foo = &fum;
    sqInt flag;
    sqInt integerPointer;

	/* begin stackIntegerValue: */
	integerPointer = longAt(foo->stackPointer - (0 * (BYTES_PER_WORD)));
	/* begin checkedIntegerValueOf: */
	if ((integerPointer & 1)) {
		flag = (integerPointer >> 1);
		goto l1;
	} else {
		/* begin primitiveFail */
		foo->successFlag = 0;
		flag = 0;
		goto l1;
	}
	flag = null;
l1:	/* end stackIntegerValue: */;
	if (foo->successFlag) {
		foo->gcBiasToGrow = flag;
		/* begin pop: */
		foo->stackPointer -= foo->argumentCount * (BYTES_PER_WORD);
	}
}


/*	Primitive. If the GC logic has  bias to grow, set growth limit */

EXPORT(sqInt) primitiveSetGCBiasToGrowGCLimit(void) {
register struct foo * foo = &fum;
    sqInt value;
    sqInt integerPointer;

	/* begin stackIntegerValue: */
	integerPointer = longAt(foo->stackPointer - (0 * (BYTES_PER_WORD)));
	/* begin checkedIntegerValueOf: */
	if ((integerPointer & 1)) {
		value = (integerPointer >> 1);
		goto l1;
	} else {
		/* begin primitiveFail */
		foo->successFlag = 0;
		value = 0;
		goto l1;
	}
	value = null;
l1:	/* end stackIntegerValue: */;
	if (foo->successFlag) {
		foo->gcBiasToGrowGCLimit = value;
		foo->gcBiasToGrowThreshold = foo->youngStart - (((int) memory));
		/* begin pop: */
		foo->stackPointer -= foo->argumentCount * (BYTES_PER_WORD);
	}
}


/*	Primitive. Indicate the semaphore to be signalled for upon garbage collection */

EXPORT(sqInt) primitiveSetGCSemaphore(void) {
register struct foo * foo = &fum;
    sqInt index;
    sqInt integerPointer;

	/* begin stackIntegerValue: */
	integerPointer = longAt(foo->stackPointer - (0 * (BYTES_PER_WORD)));
	/* begin checkedIntegerValueOf: */
	if ((integerPointer & 1)) {
		index = (integerPointer >> 1);
		goto l1;
	} else {
		/* begin primitiveFail */
		foo->successFlag = 0;
		index = 0;
		goto l1;
	}
	index = null;
l1:	/* end stackIntegerValue: */;
	if (foo->successFlag) {
		foo->gcSemaphoreIndex = index;
		/* begin pop: */
		foo->stackPointer -= foo->argumentCount * (BYTES_PER_WORD);
	}
}


/*	Set the user interrupt keycode. The keycode is an integer whose encoding is described in the comment for primitiveKbdNext. */

sqInt primitiveSetInterruptKey(void) {
register struct foo * foo = &fum;
    sqInt keycode;
    sqInt integerPointer;
    sqInt top;

	/* begin popInteger */
	/* begin popStack */
	top = longAt(foo->stackPointer);
	foo->stackPointer -= BYTES_PER_WORD;
	integerPointer = top;
	/* begin checkedIntegerValueOf: */
	if ((integerPointer & 1)) {
		keycode = (integerPointer >> 1);
		goto l1;
	} else {
		/* begin primitiveFail */
		foo->successFlag = 0;
		keycode = 0;
		goto l1;
	}
	keycode = null;
l1:	/* end popInteger */;
	if (foo->successFlag) {
		foo->interruptKeycode = keycode;
	} else {
		/* begin unPop: */
		foo->stackPointer += 1 * (BYTES_PER_WORD);
	}
}


/*	Treat the receiver, which can be indexible by either bytes or words, as an array of signed 16-bit values. Return the contents of the given index. Note that the index specifies the i-th 16-bit entry, not the i-th byte or word. */

sqInt primitiveShortAt(void) {
register struct foo * foo = &fum;
    sqInt addr;
    sqInt index;
    sqInt rcvr;
    sqInt sz;
    sqInt value;
    sqInt sp;
    sqInt successValue;
    sqInt successValue1;
    sqInt integerPointer;

	/* begin stackIntegerValue: */
	integerPointer = longAt(foo->stackPointer - (0 * (BYTES_PER_WORD)));
	/* begin checkedIntegerValueOf: */
	if ((integerPointer & 1)) {
		index = (integerPointer >> 1);
		goto l1;
	} else {
		/* begin primitiveFail */
		foo->successFlag = 0;
		index = 0;
		goto l1;
	}
	index = null;
l1:	/* end stackIntegerValue: */;
	rcvr = longAt(foo->stackPointer - (1 * (BYTES_PER_WORD)));
	/* begin success: */
	successValue = (!((rcvr & 1))) && (((rcvr & 1) == 0) && (isWordsOrBytesNonInt(rcvr)));
	foo->successFlag = successValue && foo->successFlag;
	if (!(foo->successFlag)) {
		return null;
	}

	/* number of 16-bit fields */

	sz = ((sqInt) ((sizeBitsOf(rcvr)) - (BASE_HEADER_SIZE)) >> 1);
	/* begin success: */
	successValue1 = (index >= 1) && (index <= sz);
	foo->successFlag = successValue1 && foo->successFlag;
	if (foo->successFlag) {
		addr = (rcvr + (BASE_HEADER_SIZE)) + (2 * (index - 1));
		value = shortAt(addr);
		/* begin pop:thenPushInteger: */
		longAtput(sp = foo->stackPointer - ((2 - 1) * (BYTES_PER_WORD)), ((value << 1) | 1));
		foo->stackPointer = sp;
	}
}


/*	Treat the receiver, which can be indexible by either bytes or words, as an array of signed 16-bit values. Set the contents of the given index to the given value. Note that the index specifies the i-th 16-bit entry, not the i-th byte or word. */

sqInt primitiveShortAtPut(void) {
register struct foo * foo = &fum;
    sqInt addr;
    sqInt index;
    sqInt rcvr;
    sqInt sz;
    sqInt value;
    sqInt successValue;
    sqInt successValue1;
    sqInt successValue2;
    sqInt integerPointer;
    sqInt integerPointer1;

	/* begin stackIntegerValue: */
	integerPointer = longAt(foo->stackPointer - (0 * (BYTES_PER_WORD)));
	/* begin checkedIntegerValueOf: */
	if ((integerPointer & 1)) {
		value = (integerPointer >> 1);
		goto l1;
	} else {
		/* begin primitiveFail */
		foo->successFlag = 0;
		value = 0;
		goto l1;
	}
	value = null;
l1:	/* end stackIntegerValue: */;
	/* begin stackIntegerValue: */
	integerPointer1 = longAt(foo->stackPointer - (1 * (BYTES_PER_WORD)));
	/* begin checkedIntegerValueOf: */
	if ((integerPointer1 & 1)) {
		index = (integerPointer1 >> 1);
		goto l2;
	} else {
		/* begin primitiveFail */
		foo->successFlag = 0;
		index = 0;
		goto l2;
	}
	index = null;
l2:	/* end stackIntegerValue: */;
	rcvr = longAt(foo->stackPointer - (2 * (BYTES_PER_WORD)));
	/* begin success: */
	successValue = (!((rcvr & 1))) && (((rcvr & 1) == 0) && (isWordsOrBytesNonInt(rcvr)));
	foo->successFlag = successValue && foo->successFlag;
	if (!(foo->successFlag)) {
		return null;
	}

	/* number of 16-bit fields */

	sz = ((sqInt) ((sizeBitsOf(rcvr)) - (BASE_HEADER_SIZE)) >> 1);
	/* begin success: */
	successValue1 = (index >= 1) && (index <= sz);
	foo->successFlag = successValue1 && foo->successFlag;
	/* begin success: */
	successValue2 = (value >= -32768) && (value <= 32767);
	foo->successFlag = successValue2 && foo->successFlag;
	if (foo->successFlag) {
		addr = (rcvr + (BASE_HEADER_SIZE)) + (2 * (index - 1));
		shortAtput(addr, value);
		/* begin pop: */
		foo->stackPointer -= 2 * (BYTES_PER_WORD);
	}
}


/*	Force the given rectangular section of the Display to be 
	copied to the screen. */

sqInt primitiveShowDisplayRect(void) {
register struct foo * foo = &fum;
    sqInt bottom;
    sqInt left;
    sqInt right;
    sqInt top;
    sqInt integerPointer;
    sqInt integerPointer1;
    sqInt integerPointer2;
    sqInt integerPointer3;

	/* begin stackIntegerValue: */
	integerPointer = longAt(foo->stackPointer - (0 * (BYTES_PER_WORD)));
	/* begin checkedIntegerValueOf: */
	if ((integerPointer & 1)) {
		bottom = (integerPointer >> 1);
		goto l1;
	} else {
		/* begin primitiveFail */
		foo->successFlag = 0;
		bottom = 0;
		goto l1;
	}
	bottom = null;
l1:	/* end stackIntegerValue: */;
	/* begin stackIntegerValue: */
	integerPointer1 = longAt(foo->stackPointer - (1 * (BYTES_PER_WORD)));
	/* begin checkedIntegerValueOf: */
	if ((integerPointer1 & 1)) {
		top = (integerPointer1 >> 1);
		goto l2;
	} else {
		/* begin primitiveFail */
		foo->successFlag = 0;
		top = 0;
		goto l2;
	}
	top = null;
l2:	/* end stackIntegerValue: */;
	/* begin stackIntegerValue: */
	integerPointer2 = longAt(foo->stackPointer - (2 * (BYTES_PER_WORD)));
	/* begin checkedIntegerValueOf: */
	if ((integerPointer2 & 1)) {
		right = (integerPointer2 >> 1);
		goto l3;
	} else {
		/* begin primitiveFail */
		foo->successFlag = 0;
		right = 0;
		goto l3;
	}
	right = null;
l3:	/* end stackIntegerValue: */;
	/* begin stackIntegerValue: */
	integerPointer3 = longAt(foo->stackPointer - (3 * (BYTES_PER_WORD)));
	/* begin checkedIntegerValueOf: */
	if ((integerPointer3 & 1)) {
		left = (integerPointer3 >> 1);
		goto l4;
	} else {
		/* begin primitiveFail */
		foo->successFlag = 0;
		left = 0;
		goto l4;
	}
	left = null;
l4:	/* end stackIntegerValue: */;
	displayBitsOfLeftTopRightBottom(fetchPointerofObject(TheDisplay, foo->specialObjectsOop), left, top, right, bottom);
	if (foo->successFlag) {
		ioForceDisplayUpdate();
		/* begin pop: */
		foo->stackPointer -= 4 * (BYTES_PER_WORD);
	}
}


/*	synchromously signal the semaphore. This may change the active process as a result */

sqInt primitiveSignal(void) {
register struct foo * foo = &fum;
    sqInt sema;
    sqInt classOop;
    sqInt ccIndex;
    sqInt cl;
    sqInt oop1;
    sqInt oop2;
    sqInt oop;


	/* rcvr */

	sema = longAt(foo->stackPointer);
	/* begin assertClassOf:is: */
	/* begin fetchPointer:ofObject: */
	oop = foo->specialObjectsOop;
	classOop = longAt((oop + (BASE_HEADER_SIZE)) + (ClassSemaphore << (SHIFT_FOR_WORD)));
	if ((sema & 1)) {
		foo->successFlag = 0;
		goto l1;
	}
	ccIndex = (((usqInt) (longAt(sema))) >> 12) & 31;
	if (ccIndex == 0) {
		cl = (longAt(sema - (BASE_HEADER_SIZE))) & (ALL_BUT_TYPE_MASK);
	} else {
		/* begin fetchPointer:ofObject: */
		/* begin fetchPointer:ofObject: */
		oop2 = foo->specialObjectsOop;
		oop1 = longAt((oop2 + (BASE_HEADER_SIZE)) + (CompactClasses << (SHIFT_FOR_WORD)));
		cl = longAt((oop1 + (BASE_HEADER_SIZE)) + ((ccIndex - 1) << (SHIFT_FOR_WORD)));
	}
	/* begin success: */
	foo->successFlag = (cl == classOop) && foo->successFlag;
l1:	/* end assertClassOf:is: */;
	if (foo->successFlag) {
		synchronousSignal(sema);
	}
}


/*	Set the low-water mark for free space. When the free space 
	falls below this level, the new and new: primitives fail and 
	system attempts to allocate space (e.g., to create a method 
	context) cause the low-space semaphore (if one is 
	registered) to be signalled. */

sqInt primitiveSignalAtBytesLeft(void) {
register struct foo * foo = &fum;
    sqInt bytes;
    sqInt integerPointer;
    sqInt top;

	/* begin popInteger */
	/* begin popStack */
	top = longAt(foo->stackPointer);
	foo->stackPointer -= BYTES_PER_WORD;
	integerPointer = top;
	/* begin checkedIntegerValueOf: */
	if ((integerPointer & 1)) {
		bytes = (integerPointer >> 1);
		goto l1;
	} else {
		/* begin primitiveFail */
		foo->successFlag = 0;
		bytes = 0;
		goto l1;
	}
	bytes = null;
l1:	/* end popInteger */;
	if (foo->successFlag) {
		foo->lowSpaceThreshold = bytes;
	} else {
		foo->lowSpaceThreshold = 0;
		/* begin unPop: */
		foo->stackPointer += 1 * (BYTES_PER_WORD);
	}
}


/*	Cause the time semaphore, if one has been registered, to
	be signalled when the millisecond clock is greater than or
	equal to the given tick value. A tick value of zero turns off
	timer interrupts. */

sqInt primitiveSignalAtMilliseconds(void) {
register struct foo * foo = &fum;
    sqInt sema;
    sqInt tick;
    sqInt top;
    sqInt oop;
    sqInt oop1;
    sqInt valuePointer;
    sqInt integerPointer;
    sqInt top1;

	/* begin popInteger */
	/* begin popStack */
	top1 = longAt(foo->stackPointer);
	foo->stackPointer -= BYTES_PER_WORD;
	integerPointer = top1;
	/* begin checkedIntegerValueOf: */
	if ((integerPointer & 1)) {
		tick = (integerPointer >> 1);
		goto l1;
	} else {
		/* begin primitiveFail */
		foo->successFlag = 0;
		tick = 0;
		goto l1;
	}
	tick = null;
l1:	/* end popInteger */;
	/* begin popStack */
	top = longAt(foo->stackPointer);
	foo->stackPointer -= BYTES_PER_WORD;
	sema = top;
	if (foo->successFlag) {
		if ((fetchClassOf(sema)) == (fetchPointerofObject(ClassSemaphore, foo->specialObjectsOop))) {
			/* begin storePointer:ofObject:withValue: */
			oop = foo->specialObjectsOop;
			if ((((usqInt) oop)) < (((usqInt) foo->youngStart))) {
				possibleRootStoreIntovalue(oop, sema);
			}
			longAtput((oop + (BASE_HEADER_SIZE)) + (TheTimerSemaphore << (SHIFT_FOR_WORD)), sema);
			foo->nextWakeupTick = tick;
		} else {
			/* begin storePointer:ofObject:withValue: */
			oop1 = foo->specialObjectsOop;
			valuePointer = foo->nilObj;
			if ((((usqInt) oop1)) < (((usqInt) foo->youngStart))) {
				possibleRootStoreIntovalue(oop1, valuePointer);
			}
			longAtput((oop1 + (BASE_HEADER_SIZE)) + (TheTimerSemaphore << (SHIFT_FOR_WORD)), valuePointer);
			foo->nextWakeupTick = 0;
		}
	} else {
		/* begin unPop: */
		foo->stackPointer += 2 * (BYTES_PER_WORD);
	}
}

sqInt primitiveSine(void) {
register struct foo * foo = &fum;
    double  rcvr;

	rcvr = popFloat();
	if (foo->successFlag) {
		pushFloat(sin(rcvr));
	} else {
		/* begin unPop: */
		foo->stackPointer += 1 * (BYTES_PER_WORD);
	}
}

sqInt primitiveSize(void) {
register struct foo * foo = &fum;
    sqInt rcvr;
    sqInt sz;
    sqInt oop;
    sqInt sp;

	rcvr = longAt(foo->stackPointer);
	if ((rcvr & 1)) {
		/* begin primitiveFail */
		foo->successFlag = 0;
		return null;
	}
	if (((((usqInt) (longAt(rcvr))) >> 8) & 15) < 2) {
		/* begin primitiveFail */
		foo->successFlag = 0;
		return null;
	}
	sz = stSizeOf(rcvr);
	if (foo->successFlag) {
		/* begin pop:thenPush: */
		oop = positive32BitIntegerFor(sz);
		longAtput(sp = foo->stackPointer - ((1 - 1) * (BYTES_PER_WORD)), oop);
		foo->stackPointer = sp;
	}
}


/*	save a normal snapshot under the same name as it was loaded unless it has been renamed by the last primitiveImageName */

sqInt primitiveSnapshot(void) {
	return snapshot(0);
}


/*	save an embedded snapshot */

sqInt primitiveSnapshotEmbedded(void) {
	return snapshot(1);
}

sqInt primitiveSomeInstance(void) {
register struct foo * foo = &fum;
    sqInt class;
    sqInt instance;
    sqInt sp;
    sqInt thisClass;
    sqInt thisObj;
    sqInt ccIndex;
    sqInt oop;
    sqInt oop1;
    sqInt oop2;
    sqInt obj;
    sqInt sz;
    sqInt header;

	class = longAt(foo->stackPointer);
	/* begin initialInstanceOf: */
	/* begin firstAccessibleObject */
	obj = memory + (foo->headerTypeBytes[(longAt(memory)) & TypeMask]);
	while ((((usqInt) obj)) < (((usqInt) foo->endOfMemory))) {
		if (!(((longAt(obj)) & TypeMask) == HeaderTypeFree)) {
			thisObj = obj;
			goto l3;
		}
		/* begin objectAfter: */
		if (DoAssertionChecks) {
			if ((((usqInt) obj)) >= (((usqInt) foo->endOfMemory))) {
				error("no objects after the end of memory");
			}
		}
		if (((longAt(obj)) & TypeMask) == HeaderTypeFree) {
			sz = (longAt(obj)) & (ALL_BUT_TYPE_MASK);
		} else {
			/* begin sizeBitsOf: */
			header = longAt(obj);
			if ((header & TypeMask) == HeaderTypeSizeAndClass) {
				sz = (longAt(obj - ((BYTES_PER_WORD) * 2))) & (LONG_SIZE_MASK);
				goto l4;
			} else {
				sz = header & (SIZE_MASK);
				goto l4;
			}
		l4:	/* end sizeBitsOf: */;
		}
		obj = (obj + sz) + (foo->headerTypeBytes[(longAt(obj + sz)) & TypeMask]);
	}
	error("heap is empty");
l3:	/* end firstAccessibleObject */;
	while (!(thisObj == null)) {
		/* begin fetchClassOf: */
		if ((thisObj & 1)) {
			/* begin fetchPointer:ofObject: */
			oop = foo->specialObjectsOop;
			thisClass = longAt((oop + (BASE_HEADER_SIZE)) + (ClassInteger << (SHIFT_FOR_WORD)));
			goto l1;
		}
		ccIndex = (((usqInt) (longAt(thisObj))) >> 12) & 31;
		if (ccIndex == 0) {
			thisClass = (longAt(thisObj - (BASE_HEADER_SIZE))) & (ALL_BUT_TYPE_MASK);
			goto l1;
		} else {
			/* begin fetchPointer:ofObject: */
			/* begin fetchPointer:ofObject: */
			oop2 = foo->specialObjectsOop;
			oop1 = longAt((oop2 + (BASE_HEADER_SIZE)) + (CompactClasses << (SHIFT_FOR_WORD)));
			thisClass = longAt((oop1 + (BASE_HEADER_SIZE)) + ((ccIndex - 1) << (SHIFT_FOR_WORD)));
			goto l1;
		}
	l1:	/* end fetchClassOf: */;
		if (thisClass == class) {
			instance = thisObj;
			goto l2;
		}
		thisObj = accessibleObjectAfter(thisObj);
	}
	instance = foo->nilObj;
l2:	/* end initialInstanceOf: */;
	if (instance == foo->nilObj) {
		/* begin primitiveFail */
		foo->successFlag = 0;
	} else {
		/* begin pop:thenPush: */
		longAtput(sp = foo->stackPointer - (((foo->argumentCount + 1) - 1) * (BYTES_PER_WORD)), instance);
		foo->stackPointer = sp;
	}
}


/*	Return the first object in the heap. */

sqInt primitiveSomeObject(void) {
register struct foo * foo = &fum;
    sqInt object;
    sqInt sp;
    sqInt obj;
    sqInt sz;
    sqInt header;

	/* begin pop: */
	foo->stackPointer -= (foo->argumentCount + 1) * (BYTES_PER_WORD);
	/* begin push: */
	/* begin firstAccessibleObject */
	obj = memory + (foo->headerTypeBytes[(longAt(memory)) & TypeMask]);
	while ((((usqInt) obj)) < (((usqInt) foo->endOfMemory))) {
		if (!(((longAt(obj)) & TypeMask) == HeaderTypeFree)) {
			object = obj;
			goto l1;
		}
		/* begin objectAfter: */
		if (DoAssertionChecks) {
			if ((((usqInt) obj)) >= (((usqInt) foo->endOfMemory))) {
				error("no objects after the end of memory");
			}
		}
		if (((longAt(obj)) & TypeMask) == HeaderTypeFree) {
			sz = (longAt(obj)) & (ALL_BUT_TYPE_MASK);
		} else {
			/* begin sizeBitsOf: */
			header = longAt(obj);
			if ((header & TypeMask) == HeaderTypeSizeAndClass) {
				sz = (longAt(obj - ((BYTES_PER_WORD) * 2))) & (LONG_SIZE_MASK);
				goto l2;
			} else {
				sz = header & (SIZE_MASK);
				goto l2;
			}
		l2:	/* end sizeBitsOf: */;
		}
		obj = (obj + sz) + (foo->headerTypeBytes[(longAt(obj + sz)) & TypeMask]);
	}
	error("heap is empty");
l1:	/* end firstAccessibleObject */;
	longAtput(sp = foo->stackPointer + (BYTES_PER_WORD), object);
	foo->stackPointer = sp;
}


/*	Return the oop of the SpecialObjectsArray. */

sqInt primitiveSpecialObjectsOop(void) {
register struct foo * foo = &fum;
    sqInt sp;

	/* begin pop:thenPush: */
	longAtput(sp = foo->stackPointer - ((1 - 1) * (BYTES_PER_WORD)), foo->specialObjectsOop);
	foo->stackPointer = sp;
}

sqInt primitiveSquareRoot(void) {
register struct foo * foo = &fum;
    double  rcvr;

	rcvr = popFloat();
	/* begin success: */
	foo->successFlag = (rcvr >= 0.0) && foo->successFlag;
	if (foo->successFlag) {
		pushFloat(sqrt(rcvr));
	} else {
		/* begin unPop: */
		foo->stackPointer += 1 * (BYTES_PER_WORD);
	}
}


/*	This primitive is called from Squeak as...
		<imageSegment> storeSegmentFor: arrayOfRoots into: aWordArray outPointers: anArray. */
/*	This primitive will store a binary image segment (in the same format as the Squeak image file) of the receiver and every object in its proper tree of subParts (ie, that is not refered to from anywhere else outside the tree).  All pointers from within the tree to objects outside the tree will be copied into the array of outpointers.  In their place in the image segment will be an oop equal to the offset in the outPointer array (the first would be 4). but with the high bit set. */
/*	The primitive expects the array and wordArray to be more than adequately long.  In this case it returns normally, and truncates the two arrays to exactly the right size.  To simplify truncation, both incoming arrays are required to be 256 bytes or more long (ie with 3-word headers).  If either array is too small, the primitive will fail, but in no other case.

During operation of the primitive, it is necessary to convert from both internal and external oops to their mapped values.  To make this fast, the headers of the original objects in question are replaced by the mapped values (and this is noted by adding the forbidden XX header type).  Tables are kept of both kinds of oops, as well as of the original headers for restoration.

To be specific, there are two similar two-part tables, the outpointer array, and one in the upper fifth of the segmentWordArray.  Each grows oops from the bottom up, and preserved headers from halfway up.

In case of either success or failure, the headers must be restored.  In the event of primitive failure, the table of outpointers must also be nilled out (since the garbage in the high half will not have been discarded. */

sqInt primitiveStoreImageSegment(void) {
register struct foo * foo = &fum;
    sqInt arrayOfRoots;
    sqInt doingClass;
    usqInt endSeg;
    sqInt extraSize;
    sqInt fieldOop;
    usqInt fieldPtr;
    usqInt firstIn;
    usqInt firstOut;
    usqInt hdrBaseIn;
    usqInt hdrBaseOut;
    sqInt hdrTypeBits;
    sqInt header;
    usqInt lastIn;
    usqInt lastOut;
    usqInt lastPtr;
    usqInt lastSeg;
    sqInt mapOop;
    sqInt outPointerArray;
    usqInt savedYoungStart;
    usqInt segOop;
    sqInt segmentWordArray;
    sqInt versionOffset;
    sqInt i;
    sqInt lastAddr;
    sqInt i1;
    sqInt lastAddr1;
    sqInt i2;
    sqInt lastAddr2;
    sqInt i3;
    sqInt lastAddr3;
    sqInt in;
    sqInt lastIn1;
    sqInt out;
    sqInt in1;
    sqInt lastIn2;
    sqInt out1;
    sqInt sz;
    sqInt header1;

	outPointerArray = longAt(foo->stackPointer);
	segmentWordArray = longAt(foo->stackPointer - (1 * (BYTES_PER_WORD)));

	/* Essential type checks */

	arrayOfRoots = longAt(foo->stackPointer - (2 * (BYTES_PER_WORD)));
	if (!((((((usqInt) (longAt(arrayOfRoots))) >> 8) & 15) == 2) && ((((((usqInt) (longAt(outPointerArray))) >> 8) & 15) == 2) && (((((usqInt) (longAt(segmentWordArray))) >> 8) & 15) == 6)))) {
		/* begin primitiveFail */
		foo->successFlag = 0;
		return null;
	}
	if (!((((longAt(outPointerArray)) & TypeMask) == HeaderTypeSizeAndClass) && (((longAt(segmentWordArray)) & TypeMask) == HeaderTypeSizeAndClass))) {
		/* begin primitiveFail */
		foo->successFlag = 0;
		return null;
	}
	if (DoAssertionChecks) {
		verifyCleanHeaders();
	}
	firstOut = outPointerArray + (BASE_HEADER_SIZE);
	lastOut = firstOut - (BYTES_PER_WORD);

	/* top half */

	hdrBaseOut = outPointerArray + (((lastPointerOf(outPointerArray)) / ((BYTES_PER_WORD) * 2)) * (BYTES_PER_WORD));
	lastSeg = segmentWordArray;

	/* Write a version number for byte order and version check */

	endSeg = (segmentWordArray + (sizeBitsOf(segmentWordArray))) - (BYTES_PER_WORD);
	versionOffset = BYTES_PER_WORD;
	lastSeg += versionOffset;
	if (lastSeg > endSeg) {
		/* begin primitiveFail */
		foo->successFlag = 0;
		return null;
	}
	longAtput(lastSeg, imageSegmentVersion());

	/* Take 1/8 of seg */

	firstIn = endSeg - (((sizeBitsOf(segmentWordArray)) / ((BYTES_PER_WORD) * 8)) * (BYTES_PER_WORD));
	lastIn = firstIn - (BYTES_PER_WORD);

	/* top half of that */
	/* First mark the rootArray and all root objects. */

	hdrBaseIn = firstIn + (((sizeBitsOf(segmentWordArray)) / ((BYTES_PER_WORD) * 16)) * (BYTES_PER_WORD));
	longAtput(arrayOfRoots, (longAt(arrayOfRoots)) | (MARK_BIT));
	lastPtr = arrayOfRoots + (lastPointerOf(arrayOfRoots));
	fieldPtr = arrayOfRoots + (BASE_HEADER_SIZE);
	while (fieldPtr <= lastPtr) {
		fieldOop = longAt(fieldPtr);
		if (!((fieldOop & 1))) {
			longAtput(fieldOop, (longAt(fieldOop)) | (MARK_BIT));
		}
		fieldPtr += BYTES_PER_WORD;
	}
	savedYoungStart = foo->youngStart;

	/* process all of memory */
	/* clear the recycled context lists */

	foo->youngStart = memory;
	foo->freeContexts = NilContext;
	foo->freeLargeContexts = NilContext;
	markAndTraceInterpreterOops();

	/* Finally unmark the rootArray and all root objects. */

	foo->youngStart = savedYoungStart;
	longAtput(arrayOfRoots, (longAt(arrayOfRoots)) & (ALL_BUT_MARK_BIT));
	fieldPtr = arrayOfRoots + (BASE_HEADER_SIZE);
	while (fieldPtr <= lastPtr) {
		fieldOop = longAt(fieldPtr);
		if (!((fieldOop & 1))) {
			longAtput(fieldOop, (longAt(fieldOop)) & (ALL_BUT_MARK_BIT));
		}
		fieldPtr += BYTES_PER_WORD;
	}
	lastIn += BYTES_PER_WORD;
	if (lastIn >= hdrBaseIn) {
		foo->successFlag = 0;
	}
	lastSeg = copyObjtoSegmentaddrstopAtsaveOopAtheaderAt(arrayOfRoots, segmentWordArray, lastSeg, firstIn, lastIn, hdrBaseIn + (lastIn - firstIn));
	if (!(foo->successFlag)) {
		lastIn -= BYTES_PER_WORD;
		restoreHeadersFromtofromandtofrom(firstIn, lastIn, hdrBaseIn, firstOut, lastOut, hdrBaseOut);
		/* begin primitiveFailAfterCleanup: */
		lastAddr = outPointerArray + (lastPointerOf(outPointerArray));
		i = outPointerArray + (BASE_HEADER_SIZE);
		while (i <= lastAddr) {
			longAtput(i, foo->nilObj);
			i += BYTES_PER_WORD;
		}
		if (DoAssertionChecks) {
			verifyCleanHeaders();
		}
		/* begin primitiveFail */
		foo->successFlag = 0;
		return null;
	}
	segOop = ((segmentWordArray + versionOffset) + (BASE_HEADER_SIZE)) + (foo->headerTypeBytes[(longAt((segmentWordArray + versionOffset) + (BASE_HEADER_SIZE))) & TypeMask]);
	while (segOop <= lastSeg) {
		if (((longAt(segOop)) & TypeMask) <= 1) {

			/* This object has a class field (type=0 or 1) -- start with that. */

			fieldPtr = segOop - (BYTES_PER_WORD);
			doingClass = 1;
		} else {

			/* No class field -- start with first data field */

			fieldPtr = segOop + (BASE_HEADER_SIZE);
			doingClass = 0;
		}

		/* last field */
		/* Go through all oops, remapping them... */

		lastPtr = segOop + (lastPointerOf(segOop));
		while (!(fieldPtr > lastPtr)) {

			/* Examine each pointer field */

			fieldOop = longAt(fieldPtr);
			if (doingClass) {
				hdrTypeBits = fieldOop & TypeMask;
				fieldOop -= hdrTypeBits;
			}
			if ((fieldOop & 1)) {

				/* Just an integer -- nothing to do */

				fieldPtr += BYTES_PER_WORD;
			} else {
				header = longAt(fieldOop);
				if ((header & TypeMask) == HeaderTypeFree) {

					/* Has already been forwarded -- this is the link */

					mapOop = header & (ALL_BUT_TYPE_MASK);
				} else {
					if (((longAt(fieldOop)) & (MARK_BIT)) == 0) {

						/* Points to an unmarked obj -- an internal pointer.
							Copy the object into the segment, and forward its oop. */

						lastIn += BYTES_PER_WORD;
						if (lastIn >= hdrBaseIn) {
							foo->successFlag = 0;
						}
						lastSeg = copyObjtoSegmentaddrstopAtsaveOopAtheaderAt(fieldOop, segmentWordArray, lastSeg, firstIn, lastIn, hdrBaseIn + (lastIn - firstIn));
						if (!(foo->successFlag)) {

							/* Out of space in segment */

							lastIn -= BYTES_PER_WORD;
							restoreHeadersFromtofromandtofrom(firstIn, lastIn, hdrBaseIn, firstOut, lastOut, hdrBaseOut);
							/* begin primitiveFailAfterCleanup: */
							lastAddr1 = outPointerArray + (lastPointerOf(outPointerArray));
							i1 = outPointerArray + (BASE_HEADER_SIZE);
							while (i1 <= lastAddr1) {
								longAtput(i1, foo->nilObj);
								i1 += BYTES_PER_WORD;
							}
							if (DoAssertionChecks) {
								verifyCleanHeaders();
							}
							/* begin primitiveFail */
							foo->successFlag = 0;
							return null;
						}
						mapOop = (longAt(fieldOop)) & (ALL_BUT_TYPE_MASK);
					} else {

						/* Points to a marked obj -- an external pointer.
							Map it as a tagged index in outPointers, and forward its oop. */

						lastOut += BYTES_PER_WORD;
						if (lastOut >= hdrBaseOut) {

							/* Out of space in outPointerArray */

							lastOut -= BYTES_PER_WORD;
							restoreHeadersFromtofromandtofrom(firstIn, lastIn, hdrBaseIn, firstOut, lastOut, hdrBaseOut);
							/* begin primitiveFailAfterCleanup: */
							lastAddr2 = outPointerArray + (lastPointerOf(outPointerArray));
							i2 = outPointerArray + (BASE_HEADER_SIZE);
							while (i2 <= lastAddr2) {
								longAtput(i2, foo->nilObj);
								i2 += BYTES_PER_WORD;
							}
							if (DoAssertionChecks) {
								verifyCleanHeaders();
							}
							/* begin primitiveFail */
							foo->successFlag = 0;
							return null;
						}
						mapOop = (lastOut - outPointerArray) | 2147483648U;
						/* begin forward:to:savingOopAt:andHeaderAt: */
						longAtput(lastOut, fieldOop);
						longAtput(hdrBaseOut + (lastOut - firstOut), longAt(fieldOop));
						longAtput(fieldOop, mapOop + HeaderTypeFree);
					}
				}
				if (doingClass) {
					longAtput(fieldPtr, mapOop + hdrTypeBits);
					fieldPtr += (BYTES_PER_WORD) * 2;
					doingClass = 0;
				} else {
					longAtput(fieldPtr, mapOop);
					fieldPtr += BYTES_PER_WORD;
				}
			}
		}
		/* begin objectAfter: */
		if (DoAssertionChecks) {
			if ((((usqInt) segOop)) >= (((usqInt) foo->endOfMemory))) {
				error("no objects after the end of memory");
			}
		}
		if (((longAt(segOop)) & TypeMask) == HeaderTypeFree) {
			sz = (longAt(segOop)) & (ALL_BUT_TYPE_MASK);
		} else {
			/* begin sizeBitsOf: */
			header1 = longAt(segOop);
			if ((header1 & TypeMask) == HeaderTypeSizeAndClass) {
				sz = (longAt(segOop - ((BYTES_PER_WORD) * 2))) & (LONG_SIZE_MASK);
				goto l1;
			} else {
				sz = header1 & (SIZE_MASK);
				goto l1;
			}
		l1:	/* end sizeBitsOf: */;
		}
		segOop = (segOop + sz) + (foo->headerTypeBytes[(longAt(segOop + sz)) & TypeMask]);
	}
	restoreHeadersFromtofromandtofrom(firstIn, lastIn, hdrBaseIn, firstOut, lastOut, hdrBaseOut);
	if ((((outPointerArray + (lastPointerOf(outPointerArray))) - lastOut) < 12) || ((endSeg - lastSeg) < 12)) {
		/* begin primitiveFailAfterCleanup: */
		lastAddr3 = outPointerArray + (lastPointerOf(outPointerArray));
		i3 = outPointerArray + (BASE_HEADER_SIZE);
		while (i3 <= lastAddr3) {
			longAtput(i3, foo->nilObj);
			i3 += BYTES_PER_WORD;
		}
		if (DoAssertionChecks) {
			verifyCleanHeaders();
		}
		/* begin primitiveFail */
		foo->successFlag = 0;
		return null;
	}
	extraSize = foo->headerTypeBytes[(longAt(segmentWordArray)) & TypeMask];

	/* Copy the 3-word wordArray header to establish a free chunk. */

	hdrTypeBits = (longAt(segmentWordArray)) & TypeMask;
	/* begin transfer:from:to: */
	flag("Dan");
	in = (segmentWordArray - extraSize) - (BYTES_PER_WORD);
	lastIn1 = in + (3 * (BYTES_PER_WORD));
	out = (lastOut + (BYTES_PER_WORD)) - (BYTES_PER_WORD);
	while ((((usqInt) in)) < (((usqInt) lastIn1))) {
		longAtput(out += BYTES_PER_WORD, longAt(in += BYTES_PER_WORD));
	}
	longAtput(lastOut + (BYTES_PER_WORD), (((outPointerArray + (lastPointerOf(outPointerArray))) - lastOut) - extraSize) + hdrTypeBits);
	longAtput(outPointerArray - extraSize, ((lastOut - firstOut) + ((BYTES_PER_WORD) * 2)) + hdrTypeBits);
	beRootIfOld(outPointerArray);
	/* begin transfer:from:to: */
	flag("Dan");
	in1 = (segmentWordArray - extraSize) - (BYTES_PER_WORD);
	lastIn2 = in1 + (3 * (BYTES_PER_WORD));
	out1 = (lastSeg + (BYTES_PER_WORD)) - (BYTES_PER_WORD);
	while ((((usqInt) in1)) < (((usqInt) lastIn2))) {
		longAtput(out1 += BYTES_PER_WORD, longAt(in1 += BYTES_PER_WORD));
	}
	longAtput(segmentWordArray - extraSize, ((lastSeg - segmentWordArray) + (BASE_HEADER_SIZE)) + hdrTypeBits);
	longAtput(lastSeg + (BYTES_PER_WORD), ((endSeg - lastSeg) - extraSize) + hdrTypeBits);
	if (DoAssertionChecks) {
		verifyCleanHeaders();
	}
	/* begin pop: */
	foo->stackPointer -= 3 * (BYTES_PER_WORD);
}


/*	Atomic store into context stackPointer. 
	Also ensures that any newly accessible cells are initialized to nil  */

sqInt primitiveStoreStackp(void) {
register struct foo * foo = &fum;
    sqInt ctxt;
    sqInt i;
    sqInt newStackp;
    sqInt stackp;
    sqInt successValue;
    sqInt sp;
    sqInt valuePointer;
    sqInt otherOop;
    sqInt integerPointer;

	ctxt = longAt(foo->stackPointer - (1 * (BYTES_PER_WORD)));
	/* begin stackIntegerValue: */
	integerPointer = longAt(foo->stackPointer - (0 * (BYTES_PER_WORD)));
	/* begin checkedIntegerValueOf: */
	if ((integerPointer & 1)) {
		newStackp = (integerPointer >> 1);
		goto l2;
	} else {
		/* begin primitiveFail */
		foo->successFlag = 0;
		newStackp = 0;
		goto l2;
	}
	newStackp = null;
l2:	/* end stackIntegerValue: */;
	/* begin success: */
	foo->successFlag = ((((usqInt) newStackp)) >= (((usqInt) 0))) && foo->successFlag;
	/* begin success: */
	/* begin oop:isLessThanOrEqualTo: */
	otherOop = (((LARGE_CONTEXT_SIZE) - (BASE_HEADER_SIZE)) / (BYTES_PER_WORD)) - CtxtTempFrameStart;
	successValue = (((usqInt) newStackp)) <= (((usqInt) otherOop));
	foo->successFlag = successValue && foo->successFlag;
	if (!(foo->successFlag)) {
		/* begin primitiveFail */
		foo->successFlag = 0;
		return null;
	}
	/* begin fetchStackPointerOf: */
	sp = longAt((ctxt + (BASE_HEADER_SIZE)) + (StackPointerIndex << (SHIFT_FOR_WORD)));
	if (!((sp & 1))) {
		stackp = 0;
		goto l1;
	}
	stackp = (sp >> 1);
l1:	/* end fetchStackPointerOf: */;
	if ((((usqInt) newStackp)) > (((usqInt) stackp))) {
		for (i = (stackp + 1); i <= newStackp; i += 1) {
			/* begin storePointer:ofObject:withValue: */
			valuePointer = foo->nilObj;
			if ((((usqInt) ctxt)) < (((usqInt) foo->youngStart))) {
				possibleRootStoreIntovalue(ctxt, valuePointer);
			}
			longAtput((ctxt + (BASE_HEADER_SIZE)) + (((i + CtxtTempFrameStart) - 1) << (SHIFT_FOR_WORD)), valuePointer);
		}
	}
	/* begin storeStackPointerValue:inContext: */
	longAtput((ctxt + (BASE_HEADER_SIZE)) + (StackPointerIndex << (SHIFT_FOR_WORD)), ((newStackp << 1) | 1));
	/* begin pop: */
	foo->stackPointer -= 1 * (BYTES_PER_WORD);
}

sqInt primitiveStringAt(void) {
	commonAt(1);
}

sqInt primitiveStringAtPut(void) {
	commonAtPut(1);
}


/*	 
	<array> primReplaceFrom: start to: stop with: replacement 
	startingAt: repStart  
	<primitive: 105>
	 */

sqInt primitiveStringReplace(void) {
register struct foo * foo = &fum;
    sqInt array;
    sqInt arrayFmt;
    sqInt arrayInstSize;
    sqInt hdr;
    sqInt i;
    sqInt repl;
    sqInt replFmt;
    sqInt replInstSize;
    sqInt replStart;
    sqInt srcIndex;
    sqInt start;
    sqInt stop;
    sqInt totalLength;
    sqInt valuePointer;
    sqInt valueWord;
    sqInt sz;
    sqInt sz1;
    sqInt integerPointer;
    sqInt integerPointer1;
    sqInt integerPointer2;
    sqInt class;
    sqInt classFormat;
    sqInt ccIndex;
    sqInt oop1;
    sqInt oop2;
    sqInt oop3;
    sqInt class1;
    sqInt classFormat1;
    sqInt ccIndex1;
    sqInt oop11;
    sqInt oop21;
    sqInt oop31;

	array = longAt(foo->stackPointer - (4 * (BYTES_PER_WORD)));
	/* begin stackIntegerValue: */
	integerPointer = longAt(foo->stackPointer - (3 * (BYTES_PER_WORD)));
	/* begin checkedIntegerValueOf: */
	if ((integerPointer & 1)) {
		start = (integerPointer >> 1);
		goto l3;
	} else {
		/* begin primitiveFail */
		foo->successFlag = 0;
		start = 0;
		goto l3;
	}
	start = null;
l3:	/* end stackIntegerValue: */;
	/* begin stackIntegerValue: */
	integerPointer1 = longAt(foo->stackPointer - (2 * (BYTES_PER_WORD)));
	/* begin checkedIntegerValueOf: */
	if ((integerPointer1 & 1)) {
		stop = (integerPointer1 >> 1);
		goto l4;
	} else {
		/* begin primitiveFail */
		foo->successFlag = 0;
		stop = 0;
		goto l4;
	}
	stop = null;
l4:	/* end stackIntegerValue: */;
	repl = longAt(foo->stackPointer - (1 * (BYTES_PER_WORD)));
	/* begin stackIntegerValue: */
	integerPointer2 = longAt(foo->stackPointer - (0 * (BYTES_PER_WORD)));
	/* begin checkedIntegerValueOf: */
	if ((integerPointer2 & 1)) {
		replStart = (integerPointer2 >> 1);
		goto l5;
	} else {
		/* begin primitiveFail */
		foo->successFlag = 0;
		replStart = 0;
		goto l5;
	}
	replStart = null;
l5:	/* end stackIntegerValue: */;
	if (!(foo->successFlag)) {
		/* begin primitiveFail */
		foo->successFlag = 0;
		return null;
	}
	if ((repl & 1)) {
		/* begin primitiveFail */
		foo->successFlag = 0;
		return null;
	}
	hdr = longAt(array);
	arrayFmt = (((usqInt) hdr) >> 8) & 15;
	/* begin lengthOf:baseHeader:format: */
	if ((hdr & TypeMask) == HeaderTypeSizeAndClass) {
		sz = (longAt(array - ((BYTES_PER_WORD) * 2))) & (LONG_SIZE_MASK);
	} else {
		sz = hdr & (SIZE_MASK);
	}
	sz -= hdr & (SIZE_4_BIT);
	if (arrayFmt <= 4) {
		totalLength = ((usqInt) (sz - (BASE_HEADER_SIZE))) >> (SHIFT_FOR_WORD);
		goto l1;
	}
	if (arrayFmt < 8) {
		totalLength = ((usqInt) (sz - (BASE_HEADER_SIZE))) >> 2;
		goto l1;
	} else {
		totalLength = (sz - (BASE_HEADER_SIZE)) - (arrayFmt & 3);
		goto l1;
	}
l1:	/* end lengthOf:baseHeader:format: */;
	/* begin fixedFieldsOf:format:length: */
	if ((arrayFmt > 4) || (arrayFmt == 2)) {
		arrayInstSize = 0;
		goto l7;
	}
	if (arrayFmt < 2) {
		arrayInstSize = totalLength;
		goto l7;
	}
	/* begin fetchClassOf: */
	if ((array & 1)) {
		/* begin fetchPointer:ofObject: */
		oop1 = foo->specialObjectsOop;
		class = longAt((oop1 + (BASE_HEADER_SIZE)) + (ClassInteger << (SHIFT_FOR_WORD)));
		goto l6;
	}
	ccIndex = (((usqInt) (longAt(array))) >> 12) & 31;
	if (ccIndex == 0) {
		class = (longAt(array - (BASE_HEADER_SIZE))) & (ALL_BUT_TYPE_MASK);
		goto l6;
	} else {
		/* begin fetchPointer:ofObject: */
		/* begin fetchPointer:ofObject: */
		oop3 = foo->specialObjectsOop;
		oop2 = longAt((oop3 + (BASE_HEADER_SIZE)) + (CompactClasses << (SHIFT_FOR_WORD)));
		class = longAt((oop2 + (BASE_HEADER_SIZE)) + ((ccIndex - 1) << (SHIFT_FOR_WORD)));
		goto l6;
	}
l6:	/* end fetchClassOf: */;
	classFormat = (longAt((class + (BASE_HEADER_SIZE)) + (InstanceSpecificationIndex << (SHIFT_FOR_WORD)))) - 1;
	arrayInstSize = (((((usqInt) classFormat) >> 11) & 192) + ((((usqInt) classFormat) >> 2) & 63)) - 1;
l7:	/* end fixedFieldsOf:format:length: */;
	if (!((start >= 1) && (((start - 1) <= stop) && ((stop + arrayInstSize) <= totalLength)))) {
		/* begin primitiveFail */
		foo->successFlag = 0;
		return null;
	}
	hdr = longAt(repl);
	replFmt = (((usqInt) hdr) >> 8) & 15;
	/* begin lengthOf:baseHeader:format: */
	if ((hdr & TypeMask) == HeaderTypeSizeAndClass) {
		sz1 = (longAt(repl - ((BYTES_PER_WORD) * 2))) & (LONG_SIZE_MASK);
	} else {
		sz1 = hdr & (SIZE_MASK);
	}
	sz1 -= hdr & (SIZE_4_BIT);
	if (replFmt <= 4) {
		totalLength = ((usqInt) (sz1 - (BASE_HEADER_SIZE))) >> (SHIFT_FOR_WORD);
		goto l2;
	}
	if (replFmt < 8) {
		totalLength = ((usqInt) (sz1 - (BASE_HEADER_SIZE))) >> 2;
		goto l2;
	} else {
		totalLength = (sz1 - (BASE_HEADER_SIZE)) - (replFmt & 3);
		goto l2;
	}
l2:	/* end lengthOf:baseHeader:format: */;
	/* begin fixedFieldsOf:format:length: */
	if ((replFmt > 4) || (replFmt == 2)) {
		replInstSize = 0;
		goto l9;
	}
	if (replFmt < 2) {
		replInstSize = totalLength;
		goto l9;
	}
	/* begin fetchClassOf: */
	if ((repl & 1)) {
		/* begin fetchPointer:ofObject: */
		oop11 = foo->specialObjectsOop;
		class1 = longAt((oop11 + (BASE_HEADER_SIZE)) + (ClassInteger << (SHIFT_FOR_WORD)));
		goto l8;
	}
	ccIndex1 = (((usqInt) (longAt(repl))) >> 12) & 31;
	if (ccIndex1 == 0) {
		class1 = (longAt(repl - (BASE_HEADER_SIZE))) & (ALL_BUT_TYPE_MASK);
		goto l8;
	} else {
		/* begin fetchPointer:ofObject: */
		/* begin fetchPointer:ofObject: */
		oop31 = foo->specialObjectsOop;
		oop21 = longAt((oop31 + (BASE_HEADER_SIZE)) + (CompactClasses << (SHIFT_FOR_WORD)));
		class1 = longAt((oop21 + (BASE_HEADER_SIZE)) + ((ccIndex1 - 1) << (SHIFT_FOR_WORD)));
		goto l8;
	}
l8:	/* end fetchClassOf: */;
	classFormat1 = (longAt((class1 + (BASE_HEADER_SIZE)) + (InstanceSpecificationIndex << (SHIFT_FOR_WORD)))) - 1;
	replInstSize = (((((usqInt) classFormat1) >> 11) & 192) + ((((usqInt) classFormat1) >> 2) & 63)) - 1;
l9:	/* end fixedFieldsOf:format:length: */;
	if (!((replStart >= 1) && ((((stop - start) + replStart) + replInstSize) <= totalLength))) {
		/* begin primitiveFail */
		foo->successFlag = 0;
		return null;
	}
	if (arrayFmt < 8) {
		if (!(arrayFmt == replFmt)) {
			/* begin primitiveFail */
			foo->successFlag = 0;
			return null;
		}
	} else {
		if (!((arrayFmt & 12) == (replFmt & 12))) {
			/* begin primitiveFail */
			foo->successFlag = 0;
			return null;
		}
	}

	/* - 1 for 0-based access */

	srcIndex = (replStart + replInstSize) - 1;
	if (arrayFmt <= 4) {
		for (i = ((start + arrayInstSize) - 1); i <= ((stop + arrayInstSize) - 1); i += 1) {
			/* begin storePointer:ofObject:withValue: */
			valuePointer = longAt((repl + (BASE_HEADER_SIZE)) + (srcIndex << (SHIFT_FOR_WORD)));
			if ((((usqInt) array)) < (((usqInt) foo->youngStart))) {
				possibleRootStoreIntovalue(array, valuePointer);
			}
			longAtput((array + (BASE_HEADER_SIZE)) + (i << (SHIFT_FOR_WORD)), valuePointer);
			srcIndex += 1;
		}
	} else {
		if (arrayFmt < 8) {
			for (i = ((start + arrayInstSize) - 1); i <= ((stop + arrayInstSize) - 1); i += 1) {
				/* begin storeLong32:ofObject:withValue: */
				valueWord = long32At((repl + (BASE_HEADER_SIZE)) + (srcIndex << 2));
				long32Atput((array + (BASE_HEADER_SIZE)) + (i << 2), valueWord);
				srcIndex += 1;
			}
		} else {
			for (i = ((start + arrayInstSize) - 1); i <= ((stop + arrayInstSize) - 1); i += 1) {
				byteAtput((array + (BASE_HEADER_SIZE)) + i, byteAt((repl + (BASE_HEADER_SIZE)) + srcIndex));
				srcIndex += 1;
			}
		}
	}
	/* begin pop: */
	foo->stackPointer -= foo->argumentCount * (BYTES_PER_WORD);
}

sqInt primitiveSubtract(void) {
register struct foo * foo = &fum;
    sqInt integerResult;
    sqInt sp;

	/* begin pop2AndPushIntegerIfOK: */
	integerResult = (stackIntegerValue(1)) - (stackIntegerValue(0));
	if (foo->successFlag) {
		if (
# ifdef SQ_HOST32  // cast to int for 64 bit image on 32 bit host
			(((((int) integerResult)) ^ ((((int) integerResult)) << 1)) >= 0)
# else
			((integerResult >= -1073741824) && (integerResult <= 1073741823))
# endif  // SQ_HOST32
		) {
			/* begin pop:thenPush: */
			longAtput(sp = foo->stackPointer - ((2 - 1) * (BYTES_PER_WORD)), ((integerResult << 1) | 1));
			foo->stackPointer = sp;
		} else {
			foo->successFlag = 0;
		}
	}
}


/*	Primitive arithmetic operations for large integers in 64 bit range */

EXPORT(sqInt) primitiveSubtractLargeIntegers(void) {
register struct foo * foo = &fum;
    sqLong integerArg;
    sqLong integerArgNegated;
    sqLong integerRcvr;
    sqInt oopResult;
    sqLong result;
    sqInt sp;

	integerArg = signed64BitValueOf(longAt(foo->stackPointer - (0 * (BYTES_PER_WORD))));
	integerRcvr = signed64BitValueOf(longAt(foo->stackPointer - (1 * (BYTES_PER_WORD))));
	if (!(foo->successFlag)) {
		return null;
	}
	if (integerArg == 0) {
		result = integerRcvr;
	} else {

		/* Reverse the argument so that we can recycle the overflow code from addition.
			 But the most -ve 64-bit value can overflow, so check; 0 - most -ve = most -ve */

		integerArgNegated = 0 - integerArg;
		if (integerArgNegated == integerArg) {
			/* begin primitiveFail */
			foo->successFlag = 0;
			return null;
		}

		/* Now check overflow conditions. First is whether rcvr and arg are of the same sign.
			 If they are we need to check for overflow more carefully. */

		result = integerRcvr + integerArgNegated;
		if (!((integerRcvr ^ integerArgNegated) < 0)) {
			if ((integerRcvr ^ result) < 0) {
				/* begin primitiveFail */
				foo->successFlag = 0;
				return null;
			}
		}
	}
	oopResult = signed64BitIntegerFor(result);
	if (foo->successFlag) {
		/* begin pop:thenPush: */
		longAtput(sp = foo->stackPointer - ((2 - 1) * (BYTES_PER_WORD)), oopResult);
		foo->stackPointer = sp;
	}
}


/*	Primitive. Suspend the receiver, aProcess such that it can be executed again
	by sending #resume. If the given process is not currently running, take it off
	its corresponding list. The primitive returns the list the receiver was previously on. */

sqInt primitiveSuspend(void) {
register struct foo * foo = &fum;
    sqInt activeProc;
    sqInt myList;
    sqInt process;
    sqInt sp;
    sqInt valuePointer;
    sqInt sp1;
    sqInt oop;
    sqInt oop1;
    sqInt firstLink;
    sqInt lastLink;
    sqInt nextLink;
    sqInt tempLink;
    sqInt valuePointer2;
    sqInt valuePointer1;
    sqInt oop2;

	process = longAt(foo->stackPointer);
	/* begin fetchPointer:ofObject: */
	/* begin fetchPointer:ofObject: */
	/* begin fetchPointer:ofObject: */
	oop2 = foo->specialObjectsOop;
	oop1 = longAt((oop2 + (BASE_HEADER_SIZE)) + (SchedulerAssociation << (SHIFT_FOR_WORD)));
	oop = longAt((oop1 + (BASE_HEADER_SIZE)) + (ValueIndex << (SHIFT_FOR_WORD)));
	activeProc = longAt((oop + (BASE_HEADER_SIZE)) + (ActiveProcessIndex << (SHIFT_FOR_WORD)));
	if (process == activeProc) {
		/* begin pop: */
		foo->stackPointer -= 1 * (BYTES_PER_WORD);
		/* begin push: */
		longAtput(sp = foo->stackPointer + (BYTES_PER_WORD), foo->nilObj);
		foo->stackPointer = sp;
		transferTo(wakeHighestPriority());
	} else {

		/* XXXX Fixme. We should really check whether myList is a kind of LinkedList or not
		but we can't easily so just do a quick check for nil which is the most common case. */

		myList = longAt((process + (BASE_HEADER_SIZE)) + (MyListIndex << (SHIFT_FOR_WORD)));
		if (myList == foo->nilObj) {
			/* begin primitiveFail */
			foo->successFlag = 0;
			return null;
		}
		/* begin removeProcess:fromList: */
		firstLink = longAt((myList + (BASE_HEADER_SIZE)) + (FirstLinkIndex << (SHIFT_FOR_WORD)));
		lastLink = longAt((myList + (BASE_HEADER_SIZE)) + (LastLinkIndex << (SHIFT_FOR_WORD)));
		if (process == firstLink) {
			nextLink = longAt((process + (BASE_HEADER_SIZE)) + (NextLinkIndex << (SHIFT_FOR_WORD)));
			/* begin storePointer:ofObject:withValue: */
			if ((((usqInt) myList)) < (((usqInt) foo->youngStart))) {
				possibleRootStoreIntovalue(myList, nextLink);
			}
			longAtput((myList + (BASE_HEADER_SIZE)) + (FirstLinkIndex << (SHIFT_FOR_WORD)), nextLink);
			if (process == lastLink) {
				/* begin storePointer:ofObject:withValue: */
				valuePointer2 = foo->nilObj;
				if ((((usqInt) myList)) < (((usqInt) foo->youngStart))) {
					possibleRootStoreIntovalue(myList, valuePointer2);
				}
				longAtput((myList + (BASE_HEADER_SIZE)) + (LastLinkIndex << (SHIFT_FOR_WORD)), valuePointer2);
			}
		} else {
			tempLink = firstLink;
					while (1) {
				if (tempLink == foo->nilObj) {
					/* begin success: */
					foo->successFlag = 0 && foo->successFlag;
					goto l1;
				}
				nextLink = longAt((tempLink + (BASE_HEADER_SIZE)) + (NextLinkIndex << (SHIFT_FOR_WORD)));
				if (nextLink == process) break;
				tempLink = longAt((tempLink + (BASE_HEADER_SIZE)) + (NextLinkIndex << (SHIFT_FOR_WORD)));
			}
			nextLink = longAt((process + (BASE_HEADER_SIZE)) + (NextLinkIndex << (SHIFT_FOR_WORD)));
			/* begin storePointer:ofObject:withValue: */
			if ((((usqInt) tempLink)) < (((usqInt) foo->youngStart))) {
				possibleRootStoreIntovalue(tempLink, nextLink);
			}
			longAtput((tempLink + (BASE_HEADER_SIZE)) + (NextLinkIndex << (SHIFT_FOR_WORD)), nextLink);
			if (process == lastLink) {
				/* begin storePointer:ofObject:withValue: */
				if ((((usqInt) myList)) < (((usqInt) foo->youngStart))) {
					possibleRootStoreIntovalue(myList, tempLink);
				}
				longAtput((myList + (BASE_HEADER_SIZE)) + (LastLinkIndex << (SHIFT_FOR_WORD)), tempLink);
			}
		}
		/* begin storePointer:ofObject:withValue: */
		valuePointer1 = foo->nilObj;
		if ((((usqInt) process)) < (((usqInt) foo->youngStart))) {
			possibleRootStoreIntovalue(process, valuePointer1);
		}
		longAtput((process + (BASE_HEADER_SIZE)) + (NextLinkIndex << (SHIFT_FOR_WORD)), valuePointer1);
	l1:	/* end removeProcess:fromList: */;
		if (foo->successFlag) {
			/* begin storePointer:ofObject:withValue: */
			valuePointer = foo->nilObj;
			if ((((usqInt) process)) < (((usqInt) foo->youngStart))) {
				possibleRootStoreIntovalue(process, valuePointer);
			}
			longAtput((process + (BASE_HEADER_SIZE)) + (MyListIndex << (SHIFT_FOR_WORD)), valuePointer);
			/* begin pop: */
			foo->stackPointer -= 1 * (BYTES_PER_WORD);
			/* begin push: */
			longAtput(sp1 = foo->stackPointer + (BYTES_PER_WORD), myList);
			foo->stackPointer = sp1;
		}
	}
}


/*	Primitive. Terminate up the context stack from the receiver up to but not including the argument, if previousContext is on my Context stack. Make previousContext my sender. This prim has to shadow the code in ContextPart>terminateTo: to be correct */

sqInt primitiveTerminateTo(void) {
register struct foo * foo = &fum;
    sqInt aContext;
    sqInt currentCntx;
    sqInt nextCntx;
    sqInt nilOop;
    sqInt thisCntx;
    sqInt top;
    sqInt top1;
    sqInt sp;

	/* begin popStack */
	top = longAt(foo->stackPointer);
	foo->stackPointer -= BYTES_PER_WORD;
	aContext = top;
	/* begin popStack */
	top1 = longAt(foo->stackPointer);
	foo->stackPointer -= BYTES_PER_WORD;
	thisCntx = top1;
	if (contexthasSender(thisCntx, aContext)) {
		nilOop = foo->nilObj;
		currentCntx = longAt((thisCntx + (BASE_HEADER_SIZE)) + (SenderIndex << (SHIFT_FOR_WORD)));
		while (!(currentCntx == aContext)) {
			nextCntx = longAt((currentCntx + (BASE_HEADER_SIZE)) + (SenderIndex << (SHIFT_FOR_WORD)));
			/* begin storePointer:ofObject:withValue: */
			if ((((usqInt) currentCntx)) < (((usqInt) foo->youngStart))) {
				possibleRootStoreIntovalue(currentCntx, nilOop);
			}
			longAtput((currentCntx + (BASE_HEADER_SIZE)) + (SenderIndex << (SHIFT_FOR_WORD)), nilOop);
			/* begin storePointer:ofObject:withValue: */
			if ((((usqInt) currentCntx)) < (((usqInt) foo->youngStart))) {
				possibleRootStoreIntovalue(currentCntx, nilOop);
			}
			longAtput((currentCntx + (BASE_HEADER_SIZE)) + (InstructionPointerIndex << (SHIFT_FOR_WORD)), nilOop);
			currentCntx = nextCntx;
		}
	}
	/* begin storePointer:ofObject:withValue: */
	if ((((usqInt) thisCntx)) < (((usqInt) foo->youngStart))) {
		possibleRootStoreIntovalue(thisCntx, aContext);
	}
	longAtput((thisCntx + (BASE_HEADER_SIZE)) + (SenderIndex << (SHIFT_FOR_WORD)), aContext);
	/* begin push: */
	longAtput(sp = foo->stackPointer + (BYTES_PER_WORD), thisCntx);
	foo->stackPointer = sp;
	return null;
}


/*	Return true if the host OS does support the given display depth. */

sqInt primitiveTestDisplayDepth(void) {
register struct foo * foo = &fum;
    sqInt bitsPerPixel;
    sqInt okay;
    sqInt sp;
    sqInt sp1;
    sqInt integerPointer;

	/* begin stackIntegerValue: */
	integerPointer = longAt(foo->stackPointer - (0 * (BYTES_PER_WORD)));
	/* begin checkedIntegerValueOf: */
	if ((integerPointer & 1)) {
		bitsPerPixel = (integerPointer >> 1);
		goto l1;
	} else {
		/* begin primitiveFail */
		foo->successFlag = 0;
		bitsPerPixel = 0;
		goto l1;
	}
	bitsPerPixel = null;
l1:	/* end stackIntegerValue: */;
	if (foo->successFlag) {
		okay = ioHasDisplayDepth(bitsPerPixel);
	}
	if (foo->successFlag) {
		/* begin pop: */
		foo->stackPointer -= 2 * (BYTES_PER_WORD);
		/* begin pushBool: */
		if (okay) {
			/* begin push: */
			longAtput(sp = foo->stackPointer + (BYTES_PER_WORD), foo->trueObj);
			foo->stackPointer = sp;
		} else {
			/* begin push: */
			longAtput(sp1 = foo->stackPointer + (BYTES_PER_WORD), foo->falseObj);
			foo->stackPointer = sp1;
		}
	}
}

sqInt primitiveTimesTwoPower(void) {
register struct foo * foo = &fum;
    sqInt arg;
    double  rcvr;
    sqInt integerPointer;
    sqInt top;

	/* begin popInteger */
	/* begin popStack */
	top = longAt(foo->stackPointer);
	foo->stackPointer -= BYTES_PER_WORD;
	integerPointer = top;
	/* begin checkedIntegerValueOf: */
	if ((integerPointer & 1)) {
		arg = (integerPointer >> 1);
		goto l1;
	} else {
		/* begin primitiveFail */
		foo->successFlag = 0;
		arg = 0;
		goto l1;
	}
	arg = null;
l1:	/* end popInteger */;
	rcvr = popFloat();
	if (foo->successFlag) {
		pushFloat(ldexp(rcvr, arg));
	} else {
		/* begin unPop: */
		foo->stackPointer += 2 * (BYTES_PER_WORD);
	}
}

sqInt primitiveTruncated(void) {
register struct foo * foo = &fum;
    double  frac;
    double  rcvr;
    double  trunc;
    sqInt successValue;
    sqInt sp;

	rcvr = popFloat();
	if (foo->successFlag) {
		frac = modf(rcvr, &trunc);
		flag("Dan");
		success((-1073741824.0 <= trunc) && (trunc <= 1073741823.0));
	}
	if (foo->successFlag) {
		pushInteger((sqInt) trunc);
	} else {
		/* begin unPop: */
		foo->stackPointer += 1 * (BYTES_PER_WORD);
	}
}


/*	Primitive. Unload the module with the given name. */
/*	Reloading of the module will happen *later* automatically, when a 
	function from it is called. This is ensured by invalidating current sessionID. */

sqInt primitiveUnloadModule(void) {
register struct foo * foo = &fum;
    sqInt moduleName;

	if (!(foo->argumentCount == 1)) {
		/* begin primitiveFail */
		foo->successFlag = 0;
		return null;
	}
	moduleName = longAt(foo->stackPointer);
	if ((moduleName & 1)) {
		/* begin primitiveFail */
		foo->successFlag = 0;
		return null;
	}
	if (!(((moduleName & 1) == 0) && (((((usqInt) (longAt(moduleName))) >> 8) & 15) >= 8))) {
		/* begin primitiveFail */
		foo->successFlag = 0;
		return null;
	}
	if (!(ioUnloadModuleOfLength(oopForPointer(firstIndexableField(moduleName)), byteSizeOf(moduleName)))) {
		/* begin primitiveFail */
		foo->successFlag = 0;
		return null;
	}
	flushExternalPrimitives();
	/* begin forceInterruptCheck */
	foo->interruptCheckCounter = -1000;
	foo->nextPollTick = 0;
	/* begin pop: */
	foo->stackPointer -= 1 * (BYTES_PER_WORD);
}


/*	Answer an array with UTC microseconds since the Posix epoch and
	the current seconds offset from GMT in the local time zone.
	This is a named (not numbered) primitive in the null module (ie the VM) */

EXPORT(sqInt) primitiveUtcWithOffset(void) {
register struct foo * foo = &fum;
    sqLong clock;
    int offset;
    sqInt resultArray;
    sqInt oop;
    sqInt sp;

	if ((ioUtcWithOffset(&clock, &offset)) == -1) {
		/* begin primitiveFail */
		foo->successFlag = 0;
		return null;
	}
	/* begin pushRemappableOop: */
	oop = positive64BitIntegerFor(clock);
	foo->remapBuffer[(foo->remapBufferCount += 1)] = oop;
	resultArray = instantiateClassindexableSize(fetchPointerofObject(ClassArray, foo->specialObjectsOop), 2);
	stObjectatput(resultArray, 1, popRemappableOop());
	stObjectatput(resultArray, 2, ((offset << 1) | 1));
	/* begin pop:thenPush: */
	longAtput(sp = foo->stackPointer - ((1 - 1) * (BYTES_PER_WORD)), resultArray);
	foo->stackPointer = sp;
}


/*	Behaviour depends on argument count:
		0 args:	return an Array of VM parameter values;
		1 arg:	return the indicated VM parameter;
		2 args:	set the VM indicated parameter.
	VM parameters are numbered as follows:
		1	end of old-space (0-based, read-only)
		2	end of young-space (read-only)
		3	end of memory (read-only)
		4	allocationCount (read-only)
		5	allocations between GCs (read-write)
		6	survivor count tenuring threshold (read-write)
		7	full GCs since startup (read-only)
		8	total milliseconds in full GCs since startup (read-only)
		9	incremental GCs since startup (read-only)
		10	total milliseconds in incremental GCs since startup (read-only)
		11	tenures of surving objects since startup (read-only)
		12-20 specific to the translating VM
		21	root table size (read-only)
		22	root table overflows since startup (read-only)
		23	bytes of extra memory to reserve for VM buffers, plugins, etc.
		24	memory threshold above which shrinking object memory (rw)
		25	memory headroom when growing object memory (rw)
		26  interruptChecksEveryNms - force an ioProcessEvents every N milliseconds, in case the image  is not calling getNextEvent often (rw)
		27	number of times mark loop iterated for current IGC/FGC (read-only) includes ALL marking
		28	number of times sweep loop iterated  for current IGC/FGC (read-only)
		29	number of times make forward loop iterated for current IGC/FGC (read-only)
		30	number of times compact move loop iterated for current IGC/FGC (read-only)
		31	number of grow memory requests (read-only)
		32	number of shrink memory requests (read-only)
		33	number of root table entries used for current IGC/FGC (read-only)
		34	number of allocations done before current IGC/FGC (read-only)
		35	number of survivor objects after current IGC/FGC (read-only)
		36  millisecond clock when current IGC/FGC completed (read-only)
		37  number of marked objects for Roots of the world, not including Root Table entries for current IGC/FGC (read-only)
		38  milliseconds taken by current IGC  (read-only)
		39  Number of finalization signals for Weak Objects pending when current IGC/FGC completed (read-only)
		40 BytesPerWord for this image
		
	Note: Thanks to Ian Piumarta for this primitive. */

sqInt primitiveVMParameter(void) {
register struct foo * foo = &fum;
    sqInt arg;
    sqInt i;
    sqInt index;
    sqInt mem;
    sqInt paramsArraySize;
    sqInt result;
    sqLong resultLargePositiveInteger;
    sqInt statFullGCMSecsObj;
    sqInt statGCTimeObj;
    sqInt statIGCDeltaTimeObj;
    sqInt statIncrGCMSecsObj;
    sqInt oop;
    sqInt oop1;
    sqInt oop2;
    sqInt oop3;
    sqInt oop4;
    sqInt oop5;
    sqInt oop6;
    sqInt oop7;
    sqInt oop8;
    sqInt sp;
    sqInt sp1;
    sqInt oop9;
    sqInt sp2;
    sqInt sp3;
    sqInt valuePointer;
    sqInt valuePointer1;
    sqInt valuePointer2;
    sqInt valuePointer3;
    sqInt valuePointer4;
    sqInt valuePointer5;
    sqInt valuePointer6;
    sqInt valuePointer7;
    sqInt valuePointer8;
    sqInt valuePointer9;
    sqInt valuePointer10;
    sqInt valuePointer11;
    sqInt valuePointer12;
    sqInt valuePointer13;
    sqInt valuePointer14;
    sqInt valuePointer15;
    sqInt valuePointer16;
    sqInt valuePointer17;
    sqInt valuePointer18;
    sqInt valuePointer19;
    sqInt valuePointer20;
    sqInt valuePointer21;
    sqInt valuePointer22;
    sqInt valuePointer23;
    sqInt valuePointer24;
    sqInt valuePointer25;

	mem = memory;
	paramsArraySize = 40;
	if (foo->argumentCount == 0) {
		result = instantiateClassindexableSize(fetchPointerofObject(ClassArray, foo->specialObjectsOop), paramsArraySize);
		/* begin pushRemappableOop: */
		foo->remapBuffer[(foo->remapBufferCount += 1)] = result;
		/* begin pushRemappableOop: */
		oop = positive64BitIntegerFor(foo->statFullGCMSecs);
		foo->remapBuffer[(foo->remapBufferCount += 1)] = oop;
		/* begin pushRemappableOop: */
		oop1 = positive64BitIntegerFor(foo->statIncrGCMSecs);
		foo->remapBuffer[(foo->remapBufferCount += 1)] = oop1;
		/* begin pushRemappableOop: */
		oop2 = positive64BitIntegerFor(foo->statGCTime);
		foo->remapBuffer[(foo->remapBufferCount += 1)] = oop2;
		/* begin pushRemappableOop: */
		oop3 = positive64BitIntegerFor(foo->statIGCDeltaTime);
		foo->remapBuffer[(foo->remapBufferCount += 1)] = oop3;
		/* begin popRemappableOop */
		oop4 = foo->remapBuffer[foo->remapBufferCount];
		foo->remapBufferCount -= 1;
		statIGCDeltaTimeObj = oop4;
		/* begin popRemappableOop */
		oop5 = foo->remapBuffer[foo->remapBufferCount];
		foo->remapBufferCount -= 1;
		statGCTimeObj = oop5;
		/* begin popRemappableOop */
		oop6 = foo->remapBuffer[foo->remapBufferCount];
		foo->remapBufferCount -= 1;
		statIncrGCMSecsObj = oop6;
		/* begin popRemappableOop */
		oop7 = foo->remapBuffer[foo->remapBufferCount];
		foo->remapBufferCount -= 1;
		statFullGCMSecsObj = oop7;
		/* begin popRemappableOop */
		oop8 = foo->remapBuffer[foo->remapBufferCount];
		foo->remapBufferCount -= 1;
		result = oop8;
		for (i = 0; i <= (paramsArraySize - 1); i += 1) {
			/* begin storePointer:ofObject:withValue: */
			if ((((usqInt) result)) < (((usqInt) foo->youngStart))) {
				possibleRootStoreIntovalue(result, ConstZero);
			}
			longAtput((result + (BASE_HEADER_SIZE)) + (i << (SHIFT_FOR_WORD)), ConstZero);
		}
		/* begin storePointer:ofObject:withValue: */
		valuePointer = positive64BitIntegerFor(foo->youngStart - mem);
		if ((((usqInt) result)) < (((usqInt) foo->youngStart))) {
			possibleRootStoreIntovalue(result, valuePointer);
		}
		longAtput((result + (BASE_HEADER_SIZE)) + (0 << (SHIFT_FOR_WORD)), valuePointer);
		/* begin storePointer:ofObject:withValue: */
		valuePointer1 = positive64BitIntegerFor(foo->freeBlock - mem);
		if ((((usqInt) result)) < (((usqInt) foo->youngStart))) {
			possibleRootStoreIntovalue(result, valuePointer1);
		}
		longAtput((result + (BASE_HEADER_SIZE)) + (1 << (SHIFT_FOR_WORD)), valuePointer1);
		/* begin storePointer:ofObject:withValue: */
		valuePointer2 = positive64BitIntegerFor(foo->endOfMemory - mem);
		if ((((usqInt) result)) < (((usqInt) foo->youngStart))) {
			possibleRootStoreIntovalue(result, valuePointer2);
		}
		longAtput((result + (BASE_HEADER_SIZE)) + (2 << (SHIFT_FOR_WORD)), valuePointer2);
		/* begin storePointer:ofObject:withValue: */
		valuePointer3 = ((foo->allocationCount << 1) | 1);
		if ((((usqInt) result)) < (((usqInt) foo->youngStart))) {
			possibleRootStoreIntovalue(result, valuePointer3);
		}
		longAtput((result + (BASE_HEADER_SIZE)) + (3 << (SHIFT_FOR_WORD)), valuePointer3);
		/* begin storePointer:ofObject:withValue: */
		valuePointer4 = ((foo->allocationsBetweenGCs << 1) | 1);
		if ((((usqInt) result)) < (((usqInt) foo->youngStart))) {
			possibleRootStoreIntovalue(result, valuePointer4);
		}
		longAtput((result + (BASE_HEADER_SIZE)) + (4 << (SHIFT_FOR_WORD)), valuePointer4);
		/* begin storePointer:ofObject:withValue: */
		valuePointer5 = ((foo->tenuringThreshold << 1) | 1);
		if ((((usqInt) result)) < (((usqInt) foo->youngStart))) {
			possibleRootStoreIntovalue(result, valuePointer5);
		}
		longAtput((result + (BASE_HEADER_SIZE)) + (5 << (SHIFT_FOR_WORD)), valuePointer5);
		/* begin storePointer:ofObject:withValue: */
		valuePointer6 = ((foo->statFullGCs << 1) | 1);
		if ((((usqInt) result)) < (((usqInt) foo->youngStart))) {
			possibleRootStoreIntovalue(result, valuePointer6);
		}
		longAtput((result + (BASE_HEADER_SIZE)) + (6 << (SHIFT_FOR_WORD)), valuePointer6);
		/* begin storePointer:ofObject:withValue: */
		if ((((usqInt) result)) < (((usqInt) foo->youngStart))) {
			possibleRootStoreIntovalue(result, statFullGCMSecsObj);
		}
		longAtput((result + (BASE_HEADER_SIZE)) + (7 << (SHIFT_FOR_WORD)), statFullGCMSecsObj);
		/* begin storePointer:ofObject:withValue: */
		valuePointer7 = ((foo->statIncrGCs << 1) | 1);
		if ((((usqInt) result)) < (((usqInt) foo->youngStart))) {
			possibleRootStoreIntovalue(result, valuePointer7);
		}
		longAtput((result + (BASE_HEADER_SIZE)) + (8 << (SHIFT_FOR_WORD)), valuePointer7);
		/* begin storePointer:ofObject:withValue: */
		if ((((usqInt) result)) < (((usqInt) foo->youngStart))) {
			possibleRootStoreIntovalue(result, statIncrGCMSecsObj);
		}
		longAtput((result + (BASE_HEADER_SIZE)) + (9 << (SHIFT_FOR_WORD)), statIncrGCMSecsObj);
		/* begin storePointer:ofObject:withValue: */
		valuePointer8 = ((foo->statTenures << 1) | 1);
		if ((((usqInt) result)) < (((usqInt) foo->youngStart))) {
			possibleRootStoreIntovalue(result, valuePointer8);
		}
		longAtput((result + (BASE_HEADER_SIZE)) + (10 << (SHIFT_FOR_WORD)), valuePointer8);
		/* begin storePointer:ofObject:withValue: */
		valuePointer9 = ((foo->rootTableCount << 1) | 1);
		if ((((usqInt) result)) < (((usqInt) foo->youngStart))) {
			possibleRootStoreIntovalue(result, valuePointer9);
		}
		longAtput((result + (BASE_HEADER_SIZE)) + (20 << (SHIFT_FOR_WORD)), valuePointer9);
		/* begin storePointer:ofObject:withValue: */
		valuePointer10 = ((foo->statRootTableOverflows << 1) | 1);
		if ((((usqInt) result)) < (((usqInt) foo->youngStart))) {
			possibleRootStoreIntovalue(result, valuePointer10);
		}
		longAtput((result + (BASE_HEADER_SIZE)) + (21 << (SHIFT_FOR_WORD)), valuePointer10);
		/* begin storePointer:ofObject:withValue: */
		valuePointer11 = positive64BitIntegerFor(extraVMMemory);
		if ((((usqInt) result)) < (((usqInt) foo->youngStart))) {
			possibleRootStoreIntovalue(result, valuePointer11);
		}
		longAtput((result + (BASE_HEADER_SIZE)) + (22 << (SHIFT_FOR_WORD)), valuePointer11);
		/* begin storePointer:ofObject:withValue: */
		valuePointer12 = positive64BitIntegerFor(foo->shrinkThreshold);
		if ((((usqInt) result)) < (((usqInt) foo->youngStart))) {
			possibleRootStoreIntovalue(result, valuePointer12);
		}
		longAtput((result + (BASE_HEADER_SIZE)) + (23 << (SHIFT_FOR_WORD)), valuePointer12);
		/* begin storePointer:ofObject:withValue: */
		valuePointer13 = positive64BitIntegerFor(foo->growHeadroom);
		if ((((usqInt) result)) < (((usqInt) foo->youngStart))) {
			possibleRootStoreIntovalue(result, valuePointer13);
		}
		longAtput((result + (BASE_HEADER_SIZE)) + (24 << (SHIFT_FOR_WORD)), valuePointer13);
		/* begin storePointer:ofObject:withValue: */
		valuePointer14 = ((foo->interruptChecksEveryNms << 1) | 1);
		if ((((usqInt) result)) < (((usqInt) foo->youngStart))) {
			possibleRootStoreIntovalue(result, valuePointer14);
		}
		longAtput((result + (BASE_HEADER_SIZE)) + (25 << (SHIFT_FOR_WORD)), valuePointer14);
		/* begin storePointer:ofObject:withValue: */
		valuePointer15 = ((foo->statMarkCount << 1) | 1);
		if ((((usqInt) result)) < (((usqInt) foo->youngStart))) {
			possibleRootStoreIntovalue(result, valuePointer15);
		}
		longAtput((result + (BASE_HEADER_SIZE)) + (26 << (SHIFT_FOR_WORD)), valuePointer15);
		/* begin storePointer:ofObject:withValue: */
		valuePointer16 = ((foo->statSweepCount << 1) | 1);
		if ((((usqInt) result)) < (((usqInt) foo->youngStart))) {
			possibleRootStoreIntovalue(result, valuePointer16);
		}
		longAtput((result + (BASE_HEADER_SIZE)) + (27 << (SHIFT_FOR_WORD)), valuePointer16);
		/* begin storePointer:ofObject:withValue: */
		valuePointer17 = ((foo->statMkFwdCount << 1) | 1);
		if ((((usqInt) result)) < (((usqInt) foo->youngStart))) {
			possibleRootStoreIntovalue(result, valuePointer17);
		}
		longAtput((result + (BASE_HEADER_SIZE)) + (28 << (SHIFT_FOR_WORD)), valuePointer17);
		/* begin storePointer:ofObject:withValue: */
		valuePointer18 = ((foo->statCompMoveCount << 1) | 1);
		if ((((usqInt) result)) < (((usqInt) foo->youngStart))) {
			possibleRootStoreIntovalue(result, valuePointer18);
		}
		longAtput((result + (BASE_HEADER_SIZE)) + (29 << (SHIFT_FOR_WORD)), valuePointer18);
		/* begin storePointer:ofObject:withValue: */
		valuePointer19 = ((foo->statGrowMemory << 1) | 1);
		if ((((usqInt) result)) < (((usqInt) foo->youngStart))) {
			possibleRootStoreIntovalue(result, valuePointer19);
		}
		longAtput((result + (BASE_HEADER_SIZE)) + (30 << (SHIFT_FOR_WORD)), valuePointer19);
		/* begin storePointer:ofObject:withValue: */
		valuePointer20 = ((foo->statShrinkMemory << 1) | 1);
		if ((((usqInt) result)) < (((usqInt) foo->youngStart))) {
			possibleRootStoreIntovalue(result, valuePointer20);
		}
		longAtput((result + (BASE_HEADER_SIZE)) + (31 << (SHIFT_FOR_WORD)), valuePointer20);
		/* begin storePointer:ofObject:withValue: */
		valuePointer21 = ((foo->statRootTableCount << 1) | 1);
		if ((((usqInt) result)) < (((usqInt) foo->youngStart))) {
			possibleRootStoreIntovalue(result, valuePointer21);
		}
		longAtput((result + (BASE_HEADER_SIZE)) + (32 << (SHIFT_FOR_WORD)), valuePointer21);
		/* begin storePointer:ofObject:withValue: */
		valuePointer22 = ((foo->statAllocationCount << 1) | 1);
		if ((((usqInt) result)) < (((usqInt) foo->youngStart))) {
			possibleRootStoreIntovalue(result, valuePointer22);
		}
		longAtput((result + (BASE_HEADER_SIZE)) + (33 << (SHIFT_FOR_WORD)), valuePointer22);
		/* begin storePointer:ofObject:withValue: */
		valuePointer23 = ((foo->statSurvivorCount << 1) | 1);
		if ((((usqInt) result)) < (((usqInt) foo->youngStart))) {
			possibleRootStoreIntovalue(result, valuePointer23);
		}
		longAtput((result + (BASE_HEADER_SIZE)) + (34 << (SHIFT_FOR_WORD)), valuePointer23);
		/* begin storePointer:ofObject:withValue: */
		if ((((usqInt) result)) < (((usqInt) foo->youngStart))) {
			possibleRootStoreIntovalue(result, statGCTimeObj);
		}
		longAtput((result + (BASE_HEADER_SIZE)) + (35 << (SHIFT_FOR_WORD)), statGCTimeObj);
		/* begin storePointer:ofObject:withValue: */
		valuePointer24 = ((foo->statSpecialMarkCount << 1) | 1);
		if ((((usqInt) result)) < (((usqInt) foo->youngStart))) {
			possibleRootStoreIntovalue(result, valuePointer24);
		}
		longAtput((result + (BASE_HEADER_SIZE)) + (36 << (SHIFT_FOR_WORD)), valuePointer24);
		/* begin storePointer:ofObject:withValue: */
		if ((((usqInt) result)) < (((usqInt) foo->youngStart))) {
			possibleRootStoreIntovalue(result, statIGCDeltaTimeObj);
		}
		longAtput((result + (BASE_HEADER_SIZE)) + (37 << (SHIFT_FOR_WORD)), statIGCDeltaTimeObj);
		/* begin storePointer:ofObject:withValue: */
		valuePointer25 = ((foo->statpendingFinalizationSignals << 1) | 1);
		if ((((usqInt) result)) < (((usqInt) foo->youngStart))) {
			possibleRootStoreIntovalue(result, valuePointer25);
		}
		longAtput((result + (BASE_HEADER_SIZE)) + (38 << (SHIFT_FOR_WORD)), valuePointer25);
		/* begin storePointer:ofObject:withValue: */
		if ((((usqInt) result)) < (((usqInt) foo->youngStart))) {
			possibleRootStoreIntovalue(result, (((BYTES_PER_WORD) << 1) | 1));
		}
		longAtput((result + (BASE_HEADER_SIZE)) + (39 << (SHIFT_FOR_WORD)), (((BYTES_PER_WORD) << 1) | 1));
		/* begin pop:thenPush: */
		longAtput(sp = foo->stackPointer - ((1 - 1) * (BYTES_PER_WORD)), result);
		foo->stackPointer = sp;
		return null;
	}
	arg = longAt(foo->stackPointer);
	if (!((arg & 1))) {
		/* begin primitiveFail */
		foo->successFlag = 0;
		return null;
	}
	arg = (arg >> 1);
	resultLargePositiveInteger = -1;
	if (foo->argumentCount == 1) {
		if ((arg < 1) || (arg > paramsArraySize)) {
			/* begin primitiveFail */
			foo->successFlag = 0;
			return null;
		}
		if (arg == 1) {
			resultLargePositiveInteger = foo->youngStart - mem;
		}
		if (arg == 2) {
			resultLargePositiveInteger = foo->freeBlock - mem;
		}
		if (arg == 3) {
			resultLargePositiveInteger = foo->endOfMemory - mem;
		}
		if (arg == 4) {
			result = foo->allocationCount;
		}
		if (arg == 5) {
			result = foo->allocationsBetweenGCs;
		}
		if (arg == 6) {
			result = foo->tenuringThreshold;
		}
		if (arg == 7) {
			result = foo->statFullGCs;
		}
		if (arg == 8) {
			resultLargePositiveInteger = foo->statFullGCMSecs;
		}
		if (arg == 9) {
			result = foo->statIncrGCs;
		}
		if (arg == 10) {
			resultLargePositiveInteger = foo->statIncrGCMSecs;
		}
		if (arg == 11) {
			result = foo->statTenures;
		}
		if ((arg >= 12) && (arg <= 20)) {
			result = 0;
		}
		if (arg == 21) {
			result = foo->rootTableCount;
		}
		if (arg == 22) {
			result = foo->statRootTableOverflows;
		}
		if (arg == 23) {
			resultLargePositiveInteger = extraVMMemory;
		}
		if (arg == 24) {
			resultLargePositiveInteger = foo->shrinkThreshold;
		}
		if (arg == 25) {
			resultLargePositiveInteger = foo->growHeadroom;
		}
		if (arg == 26) {
			result = foo->interruptChecksEveryNms;
		}
		if (arg == 27) {
			result = foo->statMarkCount;
		}
		if (arg == 28) {
			result = foo->statSweepCount;
		}
		if (arg == 29) {
			result = foo->statMkFwdCount;
		}
		if (arg == 30) {
			result = foo->statCompMoveCount;
		}
		if (arg == 31) {
			result = foo->statGrowMemory;
		}
		if (arg == 32) {
			result = foo->statShrinkMemory;
		}
		if (arg == 33) {
			result = foo->statRootTableCount;
		}
		if (arg == 34) {
			result = foo->statAllocationCount;
		}
		if (arg == 35) {
			result = foo->statSurvivorCount;
		}
		if (arg == 36) {
			resultLargePositiveInteger = foo->statGCTime;
		}
		if (arg == 37) {
			result = foo->statSpecialMarkCount;
		}
		if (arg == 38) {
			resultLargePositiveInteger = foo->statIGCDeltaTime;
		}
		if (arg == 39) {
			result = foo->statpendingFinalizationSignals;
		}
		if (arg == 40) {
			result = BYTES_PER_WORD;
		}
		if (resultLargePositiveInteger == -1) {
			/* begin pop:thenPush: */
			longAtput(sp1 = foo->stackPointer - ((2 - 1) * (BYTES_PER_WORD)), ((result << 1) | 1));
			foo->stackPointer = sp1;
		} else {
			/* begin pop:thenPush: */
			oop9 = positive64BitIntegerFor(resultLargePositiveInteger);
			longAtput(sp2 = foo->stackPointer - ((2 - 1) * (BYTES_PER_WORD)), oop9);
			foo->stackPointer = sp2;
		}
		return null;
	}
	if (!(foo->argumentCount == 2)) {
		/* begin primitiveFail */
		foo->successFlag = 0;
		return null;
	}
	index = longAt(foo->stackPointer - (1 * (BYTES_PER_WORD)));
	if (!((index & 1))) {
		/* begin primitiveFail */
		foo->successFlag = 0;
		return null;
	}
	index = (index >> 1);
	if (index <= 0) {
		/* begin primitiveFail */
		foo->successFlag = 0;
		return null;
	}
	foo->successFlag = 0;
	if (index == 5) {
		result = foo->allocationsBetweenGCs;
		foo->allocationsBetweenGCs = arg;
		foo->successFlag = 1;
	}
	if (index == 6) {
		result = foo->tenuringThreshold;
		foo->tenuringThreshold = arg;
		foo->successFlag = 1;
	}
	if (index == 23) {
		result = extraVMMemory;
		extraVMMemory = arg;
		foo->successFlag = 1;
	}
	if (index == 24) {
		result = foo->shrinkThreshold;
		if (arg > 0) {
			foo->shrinkThreshold = arg;
			foo->successFlag = 1;
		}
	}
	if (index == 25) {
		result = foo->growHeadroom;
		if (arg > 0) {
			foo->growHeadroom = arg;
			foo->successFlag = 1;
		}
	}
	if (index == 26) {
		if (arg > 1) {
			result = foo->interruptChecksEveryNms;
			foo->interruptChecksEveryNms = arg;
			foo->successFlag = 1;
		}
	}
	if (foo->successFlag) {
		/* begin pop:thenPush: */
		longAtput(sp3 = foo->stackPointer - ((3 - 1) * (BYTES_PER_WORD)), ((result << 1) | 1));
		foo->stackPointer = sp3;
		return null;
	}
	/* begin primitiveFail */
	foo->successFlag = 0;
}


/*	Return a string containing the path name of VM's directory. */

sqInt primitiveVMPath(void) {
register struct foo * foo = &fum;
    sqInt s;
    sqInt sz;
    sqInt sp;

	sz = vmPathSize();
	s = instantiateClassindexableSize(fetchPointerofObject(ClassString, foo->specialObjectsOop), sz);
	vmPathGetLength(s + (BASE_HEADER_SIZE), sz);
	/* begin pop:thenPush: */
	longAtput(sp = foo->stackPointer - ((1 - 1) * (BYTES_PER_WORD)), s);
	foo->stackPointer = sp;
}


/*	Answer a string corresponding to the version of virtual machine. This
	represents the version level of the Smalltalk source code (interpreter and various
	plugins) that is translated to C by a CCodeGenerator,  in addition to the external
	platform source code, typically written in C and managed separately for each platform.
	By convention, this is a string composed of the interpreter source version and the
	platform source version, e.g. '4.0.2-2172'.
	
	This is a named (not numbered) primitive in the null module (ie the VM) */

EXPORT(sqInt) primitiveVMVersion(void) {
register struct foo * foo = &fum;
    sqInt len;
    void * p;
    sqInt versionString;
    sqInt sp;

	
# ifdef VM_VERSION  // version level of interpreter plus platform support code
	len = strlen(VM_VERSION);
	versionString = instantiateClassindexableSize(fetchPointerofObject(ClassString, foo->specialObjectsOop), len);
	/* begin arrayValueOf: */
	if ((!((versionString & 1))) && (((versionString & 1) == 0) && (isWordsOrBytesNonInt(versionString)))) {
		p = pointerForOop(versionString + (BASE_HEADER_SIZE));
		goto l1;
	}
	/* begin primitiveFail */
	foo->successFlag = 0;
l1:	/* end arrayValueOf: */;
	strncpy(p, VM_VERSION, len);
# else
	/* begin primitiveFail */
	foo->successFlag = 0;
	return null;
# endif  // VM_VERSION
	
	/* begin pop:thenPush: */
	longAtput(sp = foo->stackPointer - ((1 - 1) * (BYTES_PER_WORD)), versionString);
	foo->stackPointer = sp;
}

sqInt primitiveValue(void) {
register struct foo * foo = &fum;
    sqInt blockArgumentCount;
    sqInt blockContext;
    sqInt initialIP;
    sqInt count;
    sqInt firstFrom;
    sqInt fromOop;
    sqInt fromIndex;
    sqInt lastFrom;
    sqInt toIndex;
    sqInt value;
    sqInt valuePointer;
    sqInt activeCntx;
    sqInt tmp;
    sqInt successValue;
    sqInt valuePointer1;
    sqInt valuePointer2;
    sqInt localArgCount;

	blockContext = longAt(foo->stackPointer - (foo->argumentCount * (BYTES_PER_WORD)));
	/* begin argumentCountOfBlock: */
	localArgCount = longAt((blockContext + (BASE_HEADER_SIZE)) + (BlockArgumentCountIndex << (SHIFT_FOR_WORD)));
	/* begin checkedIntegerValueOf: */
	if ((localArgCount & 1)) {
		blockArgumentCount = (localArgCount >> 1);
		goto l1;
	} else {
		/* begin primitiveFail */
		foo->successFlag = 0;
		blockArgumentCount = 0;
		goto l1;
	}
	blockArgumentCount = null;
l1:	/* end argumentCountOfBlock: */;
	/* begin success: */
	successValue = (foo->argumentCount == blockArgumentCount) && ((longAt((blockContext + (BASE_HEADER_SIZE)) + (CallerIndex << (SHIFT_FOR_WORD)))) == foo->nilObj);
	foo->successFlag = successValue && foo->successFlag;
	if (foo->successFlag) {
		/* begin transfer:fromIndex:ofObject:toIndex:ofObject: */
		count = foo->argumentCount;
		firstFrom = ((((usqInt) ((foo->stackPointer - foo->activeContext) - (BASE_HEADER_SIZE))) >> (SHIFT_FOR_WORD)) - foo->argumentCount) + 1;
		fromOop = foo->activeContext;
		flag("Dan");
		fromIndex = fromOop + (firstFrom * (BYTES_PER_WORD));
		toIndex = blockContext + (TempFrameStart * (BYTES_PER_WORD));
		lastFrom = fromIndex + (count * (BYTES_PER_WORD));
		while ((((usqInt) fromIndex)) < (((usqInt) lastFrom))) {
			fromIndex += BYTES_PER_WORD;
			toIndex += BYTES_PER_WORD;
			longAtput(toIndex, longAt(fromIndex));
		}
		/* begin pop: */
		foo->stackPointer -= (foo->argumentCount + 1) * (BYTES_PER_WORD);
		initialIP = longAt((blockContext + (BASE_HEADER_SIZE)) + (InitialIPIndex << (SHIFT_FOR_WORD)));
		longAtput((blockContext + (BASE_HEADER_SIZE)) + (InstructionPointerIndex << (SHIFT_FOR_WORD)), initialIP);
		/* begin storeStackPointerValue:inContext: */
		value = foo->argumentCount;
		longAtput((blockContext + (BASE_HEADER_SIZE)) + (StackPointerIndex << (SHIFT_FOR_WORD)), ((value << 1) | 1));
		/* begin storePointerUnchecked:ofObject:withValue: */
		valuePointer = foo->activeContext;
		longAtput((blockContext + (BASE_HEADER_SIZE)) + (CallerIndex << (SHIFT_FOR_WORD)), valuePointer);
		/* begin newActiveContext: */
		/* begin storeContextRegisters: */
		activeCntx = foo->activeContext;
		/* begin storePointerUnchecked:ofObject:withValue: */
		valuePointer1 = ((((foo->instructionPointer - foo->method) - ((BASE_HEADER_SIZE) - 2)) << 1) | 1);
		longAtput((activeCntx + (BASE_HEADER_SIZE)) + (InstructionPointerIndex << (SHIFT_FOR_WORD)), valuePointer1);
		/* begin storePointerUnchecked:ofObject:withValue: */
		valuePointer2 = (((((((usqInt) ((foo->stackPointer - foo->activeContext) - (BASE_HEADER_SIZE))) >> (SHIFT_FOR_WORD)) - TempFrameStart) + 1) << 1) | 1);
		longAtput((activeCntx + (BASE_HEADER_SIZE)) + (StackPointerIndex << (SHIFT_FOR_WORD)), valuePointer2);
		if ((((usqInt) blockContext)) < (((usqInt) foo->youngStart))) {
			beRootIfOld(blockContext);
		}
		foo->activeContext = blockContext;
		/* begin fetchContextRegisters: */
		tmp = longAt((blockContext + (BASE_HEADER_SIZE)) + (MethodIndex << (SHIFT_FOR_WORD)));
		if ((tmp & 1)) {
			tmp = longAt((blockContext + (BASE_HEADER_SIZE)) + (HomeIndex << (SHIFT_FOR_WORD)));
			if ((((usqInt) tmp)) < (((usqInt) foo->youngStart))) {
				beRootIfOld(tmp);
			}
		} else {
			tmp = blockContext;
		}
		foo->theHomeContext = tmp;
		foo->receiver = longAt((tmp + (BASE_HEADER_SIZE)) + (ReceiverIndex << (SHIFT_FOR_WORD)));
		foo->method = longAt((tmp + (BASE_HEADER_SIZE)) + (MethodIndex << (SHIFT_FOR_WORD)));
		tmp = ((longAt((blockContext + (BASE_HEADER_SIZE)) + (InstructionPointerIndex << (SHIFT_FOR_WORD)))) >> 1);
		foo->instructionPointer = ((foo->method + tmp) + (BASE_HEADER_SIZE)) - 2;
		tmp = ((longAt((blockContext + (BASE_HEADER_SIZE)) + (StackPointerIndex << (SHIFT_FOR_WORD)))) >> 1);
		foo->stackPointer = (blockContext + (BASE_HEADER_SIZE)) + (((TempFrameStart + tmp) - 1) * (BYTES_PER_WORD));
	}
}


/*	The only purpose of this primitive is to indicate that the new EH mechanisms are supported. */

sqInt primitiveValueUninterruptably(void) {
	return primitiveValue();
}

sqInt primitiveValueWithArgs(void) {
register struct foo * foo = &fum;
    sqInt argumentArray;
    sqInt arrayArgumentCount;
    sqInt blockArgumentCount;
    sqInt blockContext;
    sqInt initialIP;
    sqInt sz;
    sqInt header;
    sqInt successValue;
    sqInt fromIndex;
    sqInt lastFrom;
    sqInt toIndex;
    sqInt valuePointer;
    sqInt activeCntx;
    sqInt tmp;
    sqInt top;
    sqInt top1;
    sqInt valuePointer1;
    sqInt valuePointer2;
    sqInt localArgCount;

	/* begin popStack */
	top = longAt(foo->stackPointer);
	foo->stackPointer -= BYTES_PER_WORD;
	argumentArray = top;
	/* begin popStack */
	top1 = longAt(foo->stackPointer);
	foo->stackPointer -= BYTES_PER_WORD;
	blockContext = top1;
	/* begin argumentCountOfBlock: */
	localArgCount = longAt((blockContext + (BASE_HEADER_SIZE)) + (BlockArgumentCountIndex << (SHIFT_FOR_WORD)));
	/* begin checkedIntegerValueOf: */
	if ((localArgCount & 1)) {
		blockArgumentCount = (localArgCount >> 1);
		goto l2;
	} else {
		/* begin primitiveFail */
		foo->successFlag = 0;
		blockArgumentCount = 0;
		goto l2;
	}
	blockArgumentCount = null;
l2:	/* end argumentCountOfBlock: */;
	if (!(((argumentArray & 1) == 0) && (((((usqInt) (longAt(argumentArray))) >> 8) & 15) == 2))) {
		/* begin unPop: */
		foo->stackPointer += 2 * (BYTES_PER_WORD);
		/* begin primitiveFail */
		foo->successFlag = 0;
		return null;
	}
	if (foo->successFlag) {
		/* begin fetchWordLengthOf: */
		/* begin sizeBitsOf: */
		header = longAt(argumentArray);
		if ((header & TypeMask) == HeaderTypeSizeAndClass) {
			sz = (longAt(argumentArray - ((BYTES_PER_WORD) * 2))) & (LONG_SIZE_MASK);
			goto l1;
		} else {
			sz = header & (SIZE_MASK);
			goto l1;
		}
	l1:	/* end sizeBitsOf: */;
		arrayArgumentCount = ((usqInt) (sz - (BASE_HEADER_SIZE))) >> (SHIFT_FOR_WORD);
		/* begin success: */
		successValue = (arrayArgumentCount == blockArgumentCount) && ((longAt((blockContext + (BASE_HEADER_SIZE)) + (CallerIndex << (SHIFT_FOR_WORD)))) == foo->nilObj);
		foo->successFlag = successValue && foo->successFlag;
	}
	if (foo->successFlag) {
		/* begin transfer:fromIndex:ofObject:toIndex:ofObject: */
		flag("Dan");
		fromIndex = argumentArray + (0 * (BYTES_PER_WORD));
		toIndex = blockContext + (TempFrameStart * (BYTES_PER_WORD));
		lastFrom = fromIndex + (arrayArgumentCount * (BYTES_PER_WORD));
		while ((((usqInt) fromIndex)) < (((usqInt) lastFrom))) {
			fromIndex += BYTES_PER_WORD;
			toIndex += BYTES_PER_WORD;
			longAtput(toIndex, longAt(fromIndex));
		}
		initialIP = longAt((blockContext + (BASE_HEADER_SIZE)) + (InitialIPIndex << (SHIFT_FOR_WORD)));
		longAtput((blockContext + (BASE_HEADER_SIZE)) + (InstructionPointerIndex << (SHIFT_FOR_WORD)), initialIP);
		/* begin storeStackPointerValue:inContext: */
		longAtput((blockContext + (BASE_HEADER_SIZE)) + (StackPointerIndex << (SHIFT_FOR_WORD)), ((arrayArgumentCount << 1) | 1));
		/* begin storePointerUnchecked:ofObject:withValue: */
		valuePointer = foo->activeContext;
		longAtput((blockContext + (BASE_HEADER_SIZE)) + (CallerIndex << (SHIFT_FOR_WORD)), valuePointer);
		/* begin newActiveContext: */
		/* begin storeContextRegisters: */
		activeCntx = foo->activeContext;
		/* begin storePointerUnchecked:ofObject:withValue: */
		valuePointer1 = ((((foo->instructionPointer - foo->method) - ((BASE_HEADER_SIZE) - 2)) << 1) | 1);
		longAtput((activeCntx + (BASE_HEADER_SIZE)) + (InstructionPointerIndex << (SHIFT_FOR_WORD)), valuePointer1);
		/* begin storePointerUnchecked:ofObject:withValue: */
		valuePointer2 = (((((((usqInt) ((foo->stackPointer - foo->activeContext) - (BASE_HEADER_SIZE))) >> (SHIFT_FOR_WORD)) - TempFrameStart) + 1) << 1) | 1);
		longAtput((activeCntx + (BASE_HEADER_SIZE)) + (StackPointerIndex << (SHIFT_FOR_WORD)), valuePointer2);
		if ((((usqInt) blockContext)) < (((usqInt) foo->youngStart))) {
			beRootIfOld(blockContext);
		}
		foo->activeContext = blockContext;
		/* begin fetchContextRegisters: */
		tmp = longAt((blockContext + (BASE_HEADER_SIZE)) + (MethodIndex << (SHIFT_FOR_WORD)));
		if ((tmp & 1)) {
			tmp = longAt((blockContext + (BASE_HEADER_SIZE)) + (HomeIndex << (SHIFT_FOR_WORD)));
			if ((((usqInt) tmp)) < (((usqInt) foo->youngStart))) {
				beRootIfOld(tmp);
			}
		} else {
			tmp = blockContext;
		}
		foo->theHomeContext = tmp;
		foo->receiver = longAt((tmp + (BASE_HEADER_SIZE)) + (ReceiverIndex << (SHIFT_FOR_WORD)));
		foo->method = longAt((tmp + (BASE_HEADER_SIZE)) + (MethodIndex << (SHIFT_FOR_WORD)));
		tmp = ((longAt((blockContext + (BASE_HEADER_SIZE)) + (InstructionPointerIndex << (SHIFT_FOR_WORD)))) >> 1);
		foo->instructionPointer = ((foo->method + tmp) + (BASE_HEADER_SIZE)) - 2;
		tmp = ((longAt((blockContext + (BASE_HEADER_SIZE)) + (StackPointerIndex << (SHIFT_FOR_WORD)))) >> 1);
		foo->stackPointer = (blockContext + (BASE_HEADER_SIZE)) + (((TempFrameStart + tmp) - 1) * (BYTES_PER_WORD));
	} else {
		/* begin unPop: */
		foo->stackPointer += 2 * (BYTES_PER_WORD);
	}
}

sqInt primitiveWait(void) {
register struct foo * foo = &fum;
    sqInt activeProc;
    sqInt excessSignals;
    sqInt sema;
    sqInt oop;
    sqInt oop1;
    sqInt lastLink;
    sqInt oop2;
    sqInt classOop;
    sqInt ccIndex;
    sqInt cl;
    sqInt oop11;
    sqInt oop21;
    sqInt oop3;


	/* rcvr */

	sema = longAt(foo->stackPointer);
	/* begin assertClassOf:is: */
	/* begin fetchPointer:ofObject: */
	oop3 = foo->specialObjectsOop;
	classOop = longAt((oop3 + (BASE_HEADER_SIZE)) + (ClassSemaphore << (SHIFT_FOR_WORD)));
	if ((sema & 1)) {
		foo->successFlag = 0;
		goto l1;
	}
	ccIndex = (((usqInt) (longAt(sema))) >> 12) & 31;
	if (ccIndex == 0) {
		cl = (longAt(sema - (BASE_HEADER_SIZE))) & (ALL_BUT_TYPE_MASK);
	} else {
		/* begin fetchPointer:ofObject: */
		/* begin fetchPointer:ofObject: */
		oop21 = foo->specialObjectsOop;
		oop11 = longAt((oop21 + (BASE_HEADER_SIZE)) + (CompactClasses << (SHIFT_FOR_WORD)));
		cl = longAt((oop11 + (BASE_HEADER_SIZE)) + ((ccIndex - 1) << (SHIFT_FOR_WORD)));
	}
	/* begin success: */
	foo->successFlag = (cl == classOop) && foo->successFlag;
l1:	/* end assertClassOf:is: */;
	if (foo->successFlag) {
		excessSignals = fetchIntegerofObject(ExcessSignalsIndex, sema);
		if (excessSignals > 0) {
			/* begin storeInteger:ofObject:withValue: */
			if (
# ifdef SQ_HOST32  // cast to int for 64 bit image on 32 bit host
				(((((int) (excessSignals - 1))) ^ ((((int) (excessSignals - 1))) << 1)) >= 0)
# else
				(((excessSignals - 1) >= -1073741824) && ((excessSignals - 1) <= 1073741823))
# endif  // SQ_HOST32
			) {
				longAtput((sema + (BASE_HEADER_SIZE)) + (ExcessSignalsIndex << (SHIFT_FOR_WORD)), (((excessSignals - 1) << 1) | 1));
			} else {
				/* begin primitiveFail */
				foo->successFlag = 0;
			}
		} else {
			/* begin fetchPointer:ofObject: */
			/* begin fetchPointer:ofObject: */
			/* begin fetchPointer:ofObject: */
			oop2 = foo->specialObjectsOop;
			oop1 = longAt((oop2 + (BASE_HEADER_SIZE)) + (SchedulerAssociation << (SHIFT_FOR_WORD)));
			oop = longAt((oop1 + (BASE_HEADER_SIZE)) + (ValueIndex << (SHIFT_FOR_WORD)));
			activeProc = longAt((oop + (BASE_HEADER_SIZE)) + (ActiveProcessIndex << (SHIFT_FOR_WORD)));
			/* begin addLastLink:toList: */
			if ((longAt((sema + (BASE_HEADER_SIZE)) + (FirstLinkIndex << (SHIFT_FOR_WORD)))) == foo->nilObj) {
				/* begin storePointer:ofObject:withValue: */
				if ((((usqInt) sema)) < (((usqInt) foo->youngStart))) {
					possibleRootStoreIntovalue(sema, activeProc);
				}
				longAtput((sema + (BASE_HEADER_SIZE)) + (FirstLinkIndex << (SHIFT_FOR_WORD)), activeProc);
			} else {
				lastLink = longAt((sema + (BASE_HEADER_SIZE)) + (LastLinkIndex << (SHIFT_FOR_WORD)));
				/* begin storePointer:ofObject:withValue: */
				if ((((usqInt) lastLink)) < (((usqInt) foo->youngStart))) {
					possibleRootStoreIntovalue(lastLink, activeProc);
				}
				longAtput((lastLink + (BASE_HEADER_SIZE)) + (NextLinkIndex << (SHIFT_FOR_WORD)), activeProc);
			}
			/* begin storePointer:ofObject:withValue: */
			if ((((usqInt) sema)) < (((usqInt) foo->youngStart))) {
				possibleRootStoreIntovalue(sema, activeProc);
			}
			longAtput((sema + (BASE_HEADER_SIZE)) + (LastLinkIndex << (SHIFT_FOR_WORD)), activeProc);
			/* begin storePointer:ofObject:withValue: */
			if ((((usqInt) activeProc)) < (((usqInt) foo->youngStart))) {
				possibleRootStoreIntovalue(activeProc, sema);
			}
			longAtput((activeProc + (BASE_HEADER_SIZE)) + (MyListIndex << (SHIFT_FOR_WORD)), sema);
			transferTo(wakeHighestPriority());
		}
	}
}


/*	primitively do the equivalent of Process>yield */

sqInt primitiveYield(void) {
register struct foo * foo = &fum;
    sqInt activeProc;
    sqInt priority;
    sqInt processList;
    sqInt processLists;
    sqInt oop;
    sqInt oop1;
    sqInt lastLink;
    sqInt oop2;
    sqInt oop3;
    sqInt oop4;
    sqInt oop5;

	/* begin fetchPointer:ofObject: */
	/* begin fetchPointer:ofObject: */
	/* begin fetchPointer:ofObject: */
	oop4 = foo->specialObjectsOop;
	oop2 = longAt((oop4 + (BASE_HEADER_SIZE)) + (SchedulerAssociation << (SHIFT_FOR_WORD)));
	oop = longAt((oop2 + (BASE_HEADER_SIZE)) + (ValueIndex << (SHIFT_FOR_WORD)));
	activeProc = longAt((oop + (BASE_HEADER_SIZE)) + (ActiveProcessIndex << (SHIFT_FOR_WORD)));
	priority = ((longAt((activeProc + (BASE_HEADER_SIZE)) + (PriorityIndex << (SHIFT_FOR_WORD)))) >> 1);
	/* begin fetchPointer:ofObject: */
	/* begin fetchPointer:ofObject: */
	/* begin fetchPointer:ofObject: */
	oop5 = foo->specialObjectsOop;
	oop3 = longAt((oop5 + (BASE_HEADER_SIZE)) + (SchedulerAssociation << (SHIFT_FOR_WORD)));
	oop1 = longAt((oop3 + (BASE_HEADER_SIZE)) + (ValueIndex << (SHIFT_FOR_WORD)));
	processLists = longAt((oop1 + (BASE_HEADER_SIZE)) + (ProcessListsIndex << (SHIFT_FOR_WORD)));
	processList = longAt((processLists + (BASE_HEADER_SIZE)) + ((priority - 1) << (SHIFT_FOR_WORD)));
	if (!((longAt((processList + (BASE_HEADER_SIZE)) + (FirstLinkIndex << (SHIFT_FOR_WORD)))) == foo->nilObj)) {
		/* begin addLastLink:toList: */
		if ((longAt((processList + (BASE_HEADER_SIZE)) + (FirstLinkIndex << (SHIFT_FOR_WORD)))) == foo->nilObj) {
			/* begin storePointer:ofObject:withValue: */
			if ((((usqInt) processList)) < (((usqInt) foo->youngStart))) {
				possibleRootStoreIntovalue(processList, activeProc);
			}
			longAtput((processList + (BASE_HEADER_SIZE)) + (FirstLinkIndex << (SHIFT_FOR_WORD)), activeProc);
		} else {
			lastLink = longAt((processList + (BASE_HEADER_SIZE)) + (LastLinkIndex << (SHIFT_FOR_WORD)));
			/* begin storePointer:ofObject:withValue: */
			if ((((usqInt) lastLink)) < (((usqInt) foo->youngStart))) {
				possibleRootStoreIntovalue(lastLink, activeProc);
			}
			longAtput((lastLink + (BASE_HEADER_SIZE)) + (NextLinkIndex << (SHIFT_FOR_WORD)), activeProc);
		}
		/* begin storePointer:ofObject:withValue: */
		if ((((usqInt) processList)) < (((usqInt) foo->youngStart))) {
			possibleRootStoreIntovalue(processList, activeProc);
		}
		longAtput((processList + (BASE_HEADER_SIZE)) + (LastLinkIndex << (SHIFT_FOR_WORD)), activeProc);
		/* begin storePointer:ofObject:withValue: */
		if ((((usqInt) activeProc)) < (((usqInt) foo->youngStart))) {
			possibleRootStoreIntovalue(activeProc, processList);
		}
		longAtput((activeProc + (BASE_HEADER_SIZE)) + (MyListIndex << (SHIFT_FOR_WORD)), processList);
		transferTo(wakeHighestPriority());
	}
}


/*	For testing in Smalltalk, this method should be overridden in a subclass. */

sqInt print(char *s) {
	printf("%s", s);
}


/*	Print all the stacks of all running processes, including those that are currently suspended. */

EXPORT(sqInt) printAllStacks(void) {
register struct foo * foo = &fum;
    sqInt ctx;
    sqInt oop;
    sqInt proc;
    sqInt oop1;
    sqInt sz;
    sqInt header;
    sqInt oop2;
    sqInt oop3;

	/* begin fetchPointer:ofObject: */
	/* begin fetchPointer:ofObject: */
	/* begin fetchPointer:ofObject: */
	oop3 = foo->specialObjectsOop;
	oop2 = longAt((oop3 + (BASE_HEADER_SIZE)) + (SchedulerAssociation << (SHIFT_FOR_WORD)));
	oop1 = longAt((oop2 + (BASE_HEADER_SIZE)) + (ValueIndex << (SHIFT_FOR_WORD)));
	proc = longAt((oop1 + (BASE_HEADER_SIZE)) + (ActiveProcessIndex << (SHIFT_FOR_WORD)));
	printNameOfClasscount(fetchClassOf(proc), 5);
	/* begin cr */
	printf("\n");
	printCallStackOf(foo->activeContext);
	oop = memory + (foo->headerTypeBytes[(longAt(memory)) & TypeMask]);
	while ((((usqInt) oop)) < (((usqInt) foo->endOfMemory))) {
		if ((fetchClassOf(oop)) == (fetchPointerofObject(ClassSemaphore, foo->specialObjectsOop))) {
			/* begin cr */
			printf("\n");
			proc = longAt((oop + (BASE_HEADER_SIZE)) + (FirstLinkIndex << (SHIFT_FOR_WORD)));
			while (!(proc == foo->nilObj)) {
				printNameOfClasscount(fetchClassOf(proc), 5);
				/* begin cr */
				printf("\n");
				ctx = longAt((proc + (BASE_HEADER_SIZE)) + (SuspendedContextIndex << (SHIFT_FOR_WORD)));
				if (!(ctx == foo->nilObj)) {
					printCallStackOf(ctx);
				}
				proc = longAt((proc + (BASE_HEADER_SIZE)) + (NextLinkIndex << (SHIFT_FOR_WORD)));
			}
		}
		/* begin objectAfter: */
		if (DoAssertionChecks) {
			if ((((usqInt) oop)) >= (((usqInt) foo->endOfMemory))) {
				error("no objects after the end of memory");
			}
		}
		if (((longAt(oop)) & TypeMask) == HeaderTypeFree) {
			sz = (longAt(oop)) & (ALL_BUT_TYPE_MASK);
		} else {
			/* begin sizeBitsOf: */
			header = longAt(oop);
			if ((header & TypeMask) == HeaderTypeSizeAndClass) {
				sz = (longAt(oop - ((BYTES_PER_WORD) * 2))) & (LONG_SIZE_MASK);
				goto l1;
			} else {
				sz = header & (SIZE_MASK);
				goto l1;
			}
		l1:	/* end sizeBitsOf: */;
		}
		oop = (oop + sz) + (foo->headerTypeBytes[(longAt(oop + sz)) & TypeMask]);
	}
}

sqInt printCallStack(void) {
	return printCallStackOf(foo->activeContext);
}

sqInt printCallStackOf(sqInt aContext) {
register struct foo * foo = &fum;
    sqInt ctxt;
    sqInt home;
    sqInt message;
    sqInt methClass;
    sqInt methodSel;
    sqInt meth;
    sqInt rcvr;
    sqInt classDict;
    sqInt classDictSize;
    sqInt currClass;
    sqInt done;
    sqInt i;
    sqInt methodArray;
    sqInt sz;
    sqInt ccIndex;
    sqInt ccIndex1;
    sqInt oop;
    sqInt oop1;
    sqInt header;
    sqInt oop2;
    sqInt oop3;
    sqInt oop4;
    sqInt oop5;
    sqInt meth1;
    sqInt rcvr1;
    sqInt classDict1;
    sqInt classDictSize1;
    sqInt currClass1;
    sqInt done1;
    sqInt i1;
    sqInt methodArray1;
    sqInt sz1;
    sqInt ccIndex2;
    sqInt oop6;
    sqInt oop11;
    sqInt header1;
    sqInt oop21;

	ctxt = aContext;
	while (!(ctxt == foo->nilObj)) {
		if ((fetchClassOf(ctxt)) == (fetchPointerofObject(ClassBlockContext, foo->specialObjectsOop))) {
			home = longAt((ctxt + (BASE_HEADER_SIZE)) + (HomeIndex << (SHIFT_FOR_WORD)));
		} else {
			home = ctxt;
		}
		/* begin findClassOfMethod:forReceiver: */
		meth = longAt((home + (BASE_HEADER_SIZE)) + (MethodIndex << (SHIFT_FOR_WORD)));
		rcvr = longAt((home + (BASE_HEADER_SIZE)) + (ReceiverIndex << (SHIFT_FOR_WORD)));
		/* begin fetchClassOf: */
		if ((rcvr & 1)) {
			/* begin fetchPointer:ofObject: */
			oop = foo->specialObjectsOop;
			currClass = longAt((oop + (BASE_HEADER_SIZE)) + (ClassInteger << (SHIFT_FOR_WORD)));
			goto l1;
		}
		ccIndex = (((usqInt) (longAt(rcvr))) >> 12) & 31;
		if (ccIndex == 0) {
			currClass = (longAt(rcvr - (BASE_HEADER_SIZE))) & (ALL_BUT_TYPE_MASK);
			goto l1;
		} else {
			/* begin fetchPointer:ofObject: */
			/* begin fetchPointer:ofObject: */
			oop4 = foo->specialObjectsOop;
			oop1 = longAt((oop4 + (BASE_HEADER_SIZE)) + (CompactClasses << (SHIFT_FOR_WORD)));
			currClass = longAt((oop1 + (BASE_HEADER_SIZE)) + ((ccIndex - 1) << (SHIFT_FOR_WORD)));
			goto l1;
		}
	l1:	/* end fetchClassOf: */;
		done = 0;
		while (!(done)) {
			classDict = longAt((currClass + (BASE_HEADER_SIZE)) + (MessageDictionaryIndex << (SHIFT_FOR_WORD)));
			/* begin fetchWordLengthOf: */
			/* begin sizeBitsOf: */
			header = longAt(classDict);
			if ((header & TypeMask) == HeaderTypeSizeAndClass) {
				sz = (longAt(classDict - ((BYTES_PER_WORD) * 2))) & (LONG_SIZE_MASK);
				goto l2;
			} else {
				sz = header & (SIZE_MASK);
				goto l2;
			}
		l2:	/* end sizeBitsOf: */;
			classDictSize = ((usqInt) (sz - (BASE_HEADER_SIZE))) >> (SHIFT_FOR_WORD);
			methodArray = longAt((classDict + (BASE_HEADER_SIZE)) + (MethodArrayIndex << (SHIFT_FOR_WORD)));
			i = 0;
			while (i < (classDictSize - SelectorStart)) {
				if (meth == (longAt((methodArray + (BASE_HEADER_SIZE)) + (i << (SHIFT_FOR_WORD))))) {
					methClass = currClass;
					goto l3;
				}
				i += 1;
			}
			currClass = longAt((currClass + (BASE_HEADER_SIZE)) + (SuperclassIndex << (SHIFT_FOR_WORD)));
			done = currClass == foo->nilObj;
		}
		/* begin fetchClassOf: */
		if ((rcvr & 1)) {
			/* begin fetchPointer:ofObject: */
			oop2 = foo->specialObjectsOop;
			methClass = longAt((oop2 + (BASE_HEADER_SIZE)) + (ClassInteger << (SHIFT_FOR_WORD)));
			goto l3;
		}
		ccIndex1 = (((usqInt) (longAt(rcvr))) >> 12) & 31;
		if (ccIndex1 == 0) {
			methClass = (longAt(rcvr - (BASE_HEADER_SIZE))) & (ALL_BUT_TYPE_MASK);
			goto l3;
		} else {
			/* begin fetchPointer:ofObject: */
			/* begin fetchPointer:ofObject: */
			oop5 = foo->specialObjectsOop;
			oop3 = longAt((oop5 + (BASE_HEADER_SIZE)) + (CompactClasses << (SHIFT_FOR_WORD)));
			methClass = longAt((oop3 + (BASE_HEADER_SIZE)) + ((ccIndex1 - 1) << (SHIFT_FOR_WORD)));
			goto l3;
		}
		methClass = null;
	l3:	/* end findClassOfMethod:forReceiver: */;
		/* begin findSelectorOfMethod:forReceiver: */
		meth1 = longAt((home + (BASE_HEADER_SIZE)) + (MethodIndex << (SHIFT_FOR_WORD)));
		rcvr1 = longAt((home + (BASE_HEADER_SIZE)) + (ReceiverIndex << (SHIFT_FOR_WORD)));
		/* begin fetchClassOf: */
		if ((rcvr1 & 1)) {
			/* begin fetchPointer:ofObject: */
			oop6 = foo->specialObjectsOop;
			currClass1 = longAt((oop6 + (BASE_HEADER_SIZE)) + (ClassInteger << (SHIFT_FOR_WORD)));
			goto l4;
		}
		ccIndex2 = (((usqInt) (longAt(rcvr1))) >> 12) & 31;
		if (ccIndex2 == 0) {
			currClass1 = (longAt(rcvr1 - (BASE_HEADER_SIZE))) & (ALL_BUT_TYPE_MASK);
			goto l4;
		} else {
			/* begin fetchPointer:ofObject: */
			/* begin fetchPointer:ofObject: */
			oop21 = foo->specialObjectsOop;
			oop11 = longAt((oop21 + (BASE_HEADER_SIZE)) + (CompactClasses << (SHIFT_FOR_WORD)));
			currClass1 = longAt((oop11 + (BASE_HEADER_SIZE)) + ((ccIndex2 - 1) << (SHIFT_FOR_WORD)));
			goto l4;
		}
	l4:	/* end fetchClassOf: */;
		done1 = 0;
		while (!(done1)) {
			classDict1 = longAt((currClass1 + (BASE_HEADER_SIZE)) + (MessageDictionaryIndex << (SHIFT_FOR_WORD)));
			/* begin fetchWordLengthOf: */
			/* begin sizeBitsOf: */
			header1 = longAt(classDict1);
			if ((header1 & TypeMask) == HeaderTypeSizeAndClass) {
				sz1 = (longAt(classDict1 - ((BYTES_PER_WORD) * 2))) & (LONG_SIZE_MASK);
				goto l5;
			} else {
				sz1 = header1 & (SIZE_MASK);
				goto l5;
			}
		l5:	/* end sizeBitsOf: */;
			classDictSize1 = ((usqInt) (sz1 - (BASE_HEADER_SIZE))) >> (SHIFT_FOR_WORD);
			methodArray1 = longAt((classDict1 + (BASE_HEADER_SIZE)) + (MethodArrayIndex << (SHIFT_FOR_WORD)));
			i1 = 0;
			while (i1 <= (classDictSize1 - SelectorStart)) {
				if (meth1 == (longAt((methodArray1 + (BASE_HEADER_SIZE)) + (i1 << (SHIFT_FOR_WORD))))) {
					methodSel = longAt((classDict1 + (BASE_HEADER_SIZE)) + ((i1 + SelectorStart) << (SHIFT_FOR_WORD)));
					goto l6;
				}
				i1 += 1;
			}
			currClass1 = longAt((currClass1 + (BASE_HEADER_SIZE)) + (SuperclassIndex << (SHIFT_FOR_WORD)));
			done1 = currClass1 == foo->nilObj;
		}
		methodSel = foo->nilObj;
	l6:	/* end findSelectorOfMethod:forReceiver: */;
		printNum(ctxt);
		print(" ");
		if (!(ctxt == home)) {
			print("[] in ");
		}
		printNameOfClasscount(methClass, 5);
		print(">");
		if (methodSel == foo->nilObj) {
			print("?");
		} else {
			printStringOf(methodSel);
		}
		if (methodSel == (fetchPointerofObject(SelectorDoesNotUnderstand, foo->specialObjectsOop))) {

			/* print arg message selector */

			message = longAt((home + (BASE_HEADER_SIZE)) + ((0 + TempFrameStart) << (SHIFT_FOR_WORD)));
			methodSel = longAt((message + (BASE_HEADER_SIZE)) + (MessageSelectorIndex << (SHIFT_FOR_WORD)));
			print(" ");
			printStringOf(methodSel);
		}
		/* begin cr */
		printf("\n");
		ctxt = longAt((ctxt + (BASE_HEADER_SIZE)) + (SenderIndex << (SHIFT_FOR_WORD)));
	}
}


/*	Details: The count argument is used to avoid a possible infinite recursion if classOop is a corrupted object. */

sqInt printNameOfClasscount(sqInt classOop, sqInt cnt) {
	if (cnt <= 0) {
		return print("bad class");
	}
	if ((sizeBitsOf(classOop)) == (7 * (BYTES_PER_WORD))) {
		printNameOfClasscount(longAt((classOop + (BASE_HEADER_SIZE)) + (5 << (SHIFT_FOR_WORD))), cnt - 1);
		print(" class");
	} else {
		printStringOf(longAt((classOop + (BASE_HEADER_SIZE)) + (6 << (SHIFT_FOR_WORD))));
	}
}


/*	For testing in Smalltalk, this method should be overridden in a subclass. */

sqInt printNum(sqInt n) {
	printf("%ld", (long) n);
}

sqInt printStringOf(sqInt oop) {
    sqInt cnt;
    sqInt fmt;
    sqInt i;

	if ((oop & 1)) {
		return null;
	}
	fmt = (((usqInt) (longAt(oop))) >> 8) & 15;
	if (fmt < 8) {
		return null;
	}
	cnt = ((100 < (lengthOf(oop))) ? 100 : (lengthOf(oop)));
	i = 0;
	while (i < cnt) {
		/* begin printChar: */
		putchar(byteAt((oop + (BASE_HEADER_SIZE)) + i));
		i += 1;
	}
}

sqInt printUnbalancedStack(sqInt primIdx) {
	print("Stack unbalanced after ");
	if (foo->successFlag) {
		print("successful primitive ");
	} else {
		print("failed primitive ");
	}
	printNum(primIdx);
	/* begin cr */
	printf("\n");
}

sqInt push(sqInt object) {
register struct foo * foo = &fum;
    sqInt sp;

	longAtput(sp = foo->stackPointer + (BYTES_PER_WORD), object);
	foo->stackPointer = sp;
}

sqInt pushBool(sqInt trueOrFalse) {
register struct foo * foo = &fum;
    sqInt sp;
    sqInt sp1;

	if (trueOrFalse) {
		/* begin push: */
		longAtput(sp = foo->stackPointer + (BYTES_PER_WORD), foo->trueObj);
		foo->stackPointer = sp;
	} else {
		/* begin push: */
		longAtput(sp1 = foo->stackPointer + (BYTES_PER_WORD), foo->falseObj);
		foo->stackPointer = sp1;
	}
}

sqInt pushFloat(double  f) {
register struct foo * foo = &fum;
    sqInt object;
    sqInt sp;

	/* begin push: */
	object = floatObjectOf(f);
	longAtput(sp = foo->stackPointer + (BYTES_PER_WORD), object);
	foo->stackPointer = sp;
}

sqInt pushInteger(sqInt integerValue) {
register struct foo * foo = &fum;
    sqInt sp;

	/* begin push: */
	longAtput(sp = foo->stackPointer + (BYTES_PER_WORD), ((integerValue << 1) | 1));
	foo->stackPointer = sp;
}


/*	Record the given object in a the remap buffer. Objects in this buffer are remapped when a compaction occurs. This facility is used by the interpreter to ensure that objects in temporary variables are properly remapped. */

sqInt pushRemappableOop(sqInt oop) {
register struct foo * foo = &fum;
	foo->remapBuffer[(foo->remapBufferCount += 1)] = oop;
}


/*	Append aWord to aFile in this platforms 'natural' byte order.  (Bytes will be swapped, if
	necessary, when the image is read on a different platform.) Set successFlag to false if
	the write fails. */

sqInt putLongtoFile(sqInt aWord, sqImageFile  aFile) {
register struct foo * foo = &fum;
    sqInt objectsWritten;

	objectsWritten = sqImageFileWrite(&aWord, sizeof(aWord), 1, aFile);
	/* begin success: */
	foo->successFlag = (objectsWritten == 1) && foo->successFlag;
}


/*	Read an image header from the given file stream, and answer the image format
	version number for the saved image. Exported to allow platform support code to
	query image files for image format number. */

EXPORT(sqInt) readImageFormatFromFileStartingAt(sqImageFile  f, squeakFileOffsetType  imageOffset) {
	checkImageVersionFromstartingAt(f, imageOffset);
	return imageFormatInitialVersion;
}


/*	Read an image from the given file stream, allocating the given amount of memory to its object heap. Fail if the image has an unknown format or requires more than the given amount of memory. */
/*	Details: This method detects when the image was stored on a machine with the opposite byte ordering from this machine and swaps the bytes automatically. Furthermore, it allows the header information to start 512 bytes into the file, since some file transfer programs for the Macintosh apparently prepend a Mac-specific header of this size. Note that this same 512 bytes of prefix area could also be used to store an exec command on Unix systems, allowing one to launch Smalltalk by invoking the image name as a command. */
/*	This code is based on C code by Ian Piumarta and Smalltalk code by Tim Rowledge. Many thanks to both of you!! */

sqInt readImageFromFileHeapSizeStartingAt(sqImageFile  f, usqInt desiredHeapSize, squeakFileOffsetType  imageOffset) {
register struct foo * foo = &fum;
    size_t bytesRead;
    sqInt bytesToShift;
    size_t  dataSize;
    sqInt headerSize;
    squeakFileOffsetType  headerStart;
    sqInt heapSize;
    sqInt memStart;
    sqInt minimumMemory;
    sqInt oldBaseAddr;
    sqInt swapBytes;
    sqInt flagsWord;
    char *memoryAddress;
    sqInt startAddr;
    sqInt stopAddr;
    sqInt addr;

	swapBytes = checkImageVersionFromstartingAt(f, imageOffset);

	/* record header start position */

	headerStart = (sqImageFilePosition(f)) - (BYTES_PER_WORD);
	headerSize = getLongFromFileswap(f, swapBytes);
	dataSize = getLongFromFileswap(f, swapBytes);
	oldBaseAddr = getLongFromFileswap(f, swapBytes);
	foo->specialObjectsOop = getLongFromFileswap(f, swapBytes);
	foo->lastHash = getLongFromFileswap(f, swapBytes);
	foo->savedWindowSize = getLongFromFileswap(f, swapBytes);
	/* begin oldFormatFullScreenFlag: */
	flagsWord = getLongFromFileswap(f, swapBytes);
	foo->fullScreenFlag = flagsWord & 1;
	extraVMMemory = getLongFromFileswap(f, swapBytes);
	if (foo->lastHash == 0) {

		/* lastHash wasn't stored (e.g. by the cloner); use 999 as the seed */

		foo->lastHash = 999;
	}
	heapSize = reserveExtraCHeapBytes(desiredHeapSize, extraVMMemory);

	/* need at least 100K of breathing room */

	minimumMemory = dataSize + 100000;
	if (heapSize < minimumMemory) {
		insufficientMemorySpecifiedError();
	}
	memory = allocateMemoryMinimumImageFileHeaderSize(heapSize, minimumMemory, f, headerSize);
	if (memory == null) {
		insufficientMemoryAvailableError();
	}
	memStart = memory;

	/* decrease memoryLimit a tad for safety */

	foo->memoryLimit = (memStart + heapSize) - 24;

	/* position file after the header */

	foo->endOfMemory = memStart + dataSize;
	sqImageFileSeek(f, headerStart + headerSize);
	/* begin sqImage:read:size:length: */
	memoryAddress = pointerForOop(memory);
	bytesRead = sqImageFileReadEntireImage(memoryAddress, sizeof(unsigned char), dataSize, f);
	if (bytesRead != dataSize) {
		unableToReadImageError();
	}
	foo->headerTypeBytes[0] = ((BYTES_PER_WORD) * 2);
	foo->headerTypeBytes[1] = (BYTES_PER_WORD);
	foo->headerTypeBytes[2] = 0;
	foo->headerTypeBytes[3] = 0;
	if (swapBytes) {
		/* begin reverseBytesInImage */
		/* begin reverseBytesFrom:to: */
		startAddr = memory;
		stopAddr = foo->endOfMemory;
		flag("Dan");
		addr = startAddr;
		while ((((usqInt) addr)) < (((usqInt) stopAddr))) {
			longAtput(addr, byteSwapped(longAt(addr)));
			addr += BYTES_PER_WORD;
		}
		/* begin byteSwapByteObjects */
		byteSwapByteObjectsFromto(memory + (foo->headerTypeBytes[(longAt(memory)) & TypeMask]), foo->endOfMemory);
	}
	bytesToShift = memStart - oldBaseAddr;
	initializeInterpreter(bytesToShift);
	isBigEnder();
	if ((imageFormatInitialVersion & 1) == 1) {
		normalizeFloatOrderingInImage();
	}
	return dataSize;
}


/*	Anwer true if images of the given format are readable by this interpreter. Allows
	a virtual machine to accept selected older image formats.  In our case we can
	select a newer (closure) image format as well as the existing format. Images with
	platform-ordered floats (StackInterpreter and Cog format) are readable but will be
	converted to traditional word ordering. */

sqInt readableFormat(sqInt imageVersion) {
	if ((BYTES_PER_WORD) == 4) {
		return ((imageVersion == 6502) || (imageVersion == 6504)) || (imageVersion == 6505);
	} else {
		return ((imageVersion == 68000) || (imageVersion == 68002)) || (imageVersion == 68003);
	}
}


/*	callbackContext is an activation of invokeCallback:stack:registers:jmpbuf:.  Its sender
	 is the interpreter's state prior to the callback.  Reestablish that state. */

EXPORT(sqInt) reestablishContextPriorToCallback(sqInt callbackContext) {
register struct foo * foo = &fum;
    sqInt calloutContext;
    sqInt activeCntx;
    sqInt tmp;
    sqInt valuePointer;
    sqInt valuePointer1;

	if ((fetchClassOf(callbackContext)) != (fetchPointerofObject(ClassMethodContext, foo->specialObjectsOop))) {
		return 0;
	}
	calloutContext = longAt((callbackContext + (BASE_HEADER_SIZE)) + (SenderIndex << (SHIFT_FOR_WORD)));
	/* begin newActiveContext: */
	/* begin storeContextRegisters: */
	activeCntx = foo->activeContext;
	/* begin storePointerUnchecked:ofObject:withValue: */
	valuePointer = ((((foo->instructionPointer - foo->method) - ((BASE_HEADER_SIZE) - 2)) << 1) | 1);
	longAtput((activeCntx + (BASE_HEADER_SIZE)) + (InstructionPointerIndex << (SHIFT_FOR_WORD)), valuePointer);
	/* begin storePointerUnchecked:ofObject:withValue: */
	valuePointer1 = (((((((usqInt) ((foo->stackPointer - foo->activeContext) - (BASE_HEADER_SIZE))) >> (SHIFT_FOR_WORD)) - TempFrameStart) + 1) << 1) | 1);
	longAtput((activeCntx + (BASE_HEADER_SIZE)) + (StackPointerIndex << (SHIFT_FOR_WORD)), valuePointer1);
	if ((((usqInt) calloutContext)) < (((usqInt) foo->youngStart))) {
		beRootIfOld(calloutContext);
	}
	foo->activeContext = calloutContext;
	/* begin fetchContextRegisters: */
	tmp = longAt((calloutContext + (BASE_HEADER_SIZE)) + (MethodIndex << (SHIFT_FOR_WORD)));
	if ((tmp & 1)) {
		tmp = longAt((calloutContext + (BASE_HEADER_SIZE)) + (HomeIndex << (SHIFT_FOR_WORD)));
		if ((((usqInt) tmp)) < (((usqInt) foo->youngStart))) {
			beRootIfOld(tmp);
		}
	} else {
		tmp = calloutContext;
	}
	foo->theHomeContext = tmp;
	foo->receiver = longAt((tmp + (BASE_HEADER_SIZE)) + (ReceiverIndex << (SHIFT_FOR_WORD)));
	foo->method = longAt((tmp + (BASE_HEADER_SIZE)) + (MethodIndex << (SHIFT_FOR_WORD)));
	tmp = ((longAt((calloutContext + (BASE_HEADER_SIZE)) + (InstructionPointerIndex << (SHIFT_FOR_WORD)))) >> 1);
	foo->instructionPointer = ((foo->method + tmp) + (BASE_HEADER_SIZE)) - 2;
	tmp = ((longAt((calloutContext + (BASE_HEADER_SIZE)) + (StackPointerIndex << (SHIFT_FOR_WORD)))) >> 1);
	foo->stackPointer = (calloutContext + (BASE_HEADER_SIZE)) + (((TempFrameStart + tmp) - 1) * (BYTES_PER_WORD));
	return 1;
}


/*	Map the given oop to its new value during a compaction or 
	become: operation. If it has no forwarding table entry, 
	return the oop itself. */

sqInt remap(sqInt oop) {
register struct foo * foo = &fum;
    sqInt fwdBlock;

	if (((oop & 1) == 0) && (((longAt(oop)) & (MARK_BIT)) != 0)) {

		/* get the new value for oop from its forwarding block */

		fwdBlock = ((longAt(oop)) & (ALL_BUT_MARK_BIT_AND_TYPE_MASK)) << 1;
		if (DoAssertionChecks) {
			/* begin fwdBlockValidate: */
			if (!(((((usqInt) fwdBlock)) > (((usqInt) foo->endOfMemory))) && (((((usqInt) fwdBlock)) <= (((usqInt) foo->fwdTableNext))) && ((fwdBlock & 3) == 0)))) {
				error("invalid fwd table entry");
			}
		}
		return longAt(fwdBlock);
	}
	return oop;
}


/*	Remove the first process from the given linked list. */

sqInt removeFirstLinkOfList(sqInt aList) {
register struct foo * foo = &fum;
    sqInt first;
    sqInt last;
    sqInt next;
    sqInt valuePointer;
    sqInt valuePointer1;
    sqInt valuePointer2;

	first = longAt((aList + (BASE_HEADER_SIZE)) + (FirstLinkIndex << (SHIFT_FOR_WORD)));
	last = longAt((aList + (BASE_HEADER_SIZE)) + (LastLinkIndex << (SHIFT_FOR_WORD)));
	if (first == last) {
		/* begin storePointer:ofObject:withValue: */
		valuePointer = foo->nilObj;
		if ((((usqInt) aList)) < (((usqInt) foo->youngStart))) {
			possibleRootStoreIntovalue(aList, valuePointer);
		}
		longAtput((aList + (BASE_HEADER_SIZE)) + (FirstLinkIndex << (SHIFT_FOR_WORD)), valuePointer);
		/* begin storePointer:ofObject:withValue: */
		valuePointer1 = foo->nilObj;
		if ((((usqInt) aList)) < (((usqInt) foo->youngStart))) {
			possibleRootStoreIntovalue(aList, valuePointer1);
		}
		longAtput((aList + (BASE_HEADER_SIZE)) + (LastLinkIndex << (SHIFT_FOR_WORD)), valuePointer1);
	} else {
		next = longAt((first + (BASE_HEADER_SIZE)) + (NextLinkIndex << (SHIFT_FOR_WORD)));
		/* begin storePointer:ofObject:withValue: */
		if ((((usqInt) aList)) < (((usqInt) foo->youngStart))) {
			possibleRootStoreIntovalue(aList, next);
		}
		longAtput((aList + (BASE_HEADER_SIZE)) + (FirstLinkIndex << (SHIFT_FOR_WORD)), next);
	}
	/* begin storePointer:ofObject:withValue: */
	valuePointer2 = foo->nilObj;
	if ((((usqInt) first)) < (((usqInt) foo->youngStart))) {
		possibleRootStoreIntovalue(first, valuePointer2);
	}
	longAtput((first + (BASE_HEADER_SIZE)) + (NextLinkIndex << (SHIFT_FOR_WORD)), valuePointer2);
	return first;
}


/*	Remove the given variable location to the extra roots table */

EXPORT(sqInt) removeGCRoot(sqInt *varLoc) {
register struct foo * foo = &fum;
    sqInt i;
    sqInt *root;

	for (i = 1; i <= foo->extraRootCount; i += 1) {
		root = foo->extraRoots[i];
		if (root == varLoc) {
			foo->extraRoots[i] = (foo->extraRoots[foo->extraRootCount]);
			foo->extraRootCount -= 1;
			return 1;
		}
	}
	return 0;
}


/*	Restore the original header of the given oop from its 
	forwarding block. */

sqInt restoreHeaderOf(sqInt oop) {
register struct foo * foo = &fum;
    sqInt fwdBlock;
    sqInt fwdHeader;

	fwdHeader = longAt(oop);
	fwdBlock = (fwdHeader & (ALL_BUT_MARK_BIT_AND_TYPE_MASK)) << 1;
	if (DoAssertionChecks) {
		if ((fwdHeader & (MARK_BIT)) == 0) {
			error("attempting to restore the header of an object that has no forwarding block");
		}
		/* begin fwdBlockValidate: */
		if (!(((((usqInt) fwdBlock)) > (((usqInt) foo->endOfMemory))) && (((((usqInt) fwdBlock)) <= (((usqInt) foo->fwdTableNext))) && ((fwdBlock & 3) == 0)))) {
			error("invalid fwd table entry");
		}
	}
	longAtput(oop, longAt(fwdBlock + (BYTES_PER_WORD)));
}


/*	Restore headers smashed by forwarding links */

sqInt restoreHeadersFromtofromandtofrom(sqInt firstIn, sqInt lastIn, sqInt hdrBaseIn, sqInt firstOut, sqInt lastOut, sqInt hdrBaseOut) {
register struct foo * foo = &fum;
    sqInt header;
    sqInt oop;
    sqInt tablePtr;
    sqInt sz;
    sqInt header1;

	tablePtr = firstIn;
	while ((((usqInt) tablePtr)) <= (((usqInt) lastIn))) {
		oop = longAt(tablePtr);
		header = longAt(hdrBaseIn + (tablePtr - firstIn));
		longAtput(oop, header);
		tablePtr += BYTES_PER_WORD;
	}
	tablePtr = firstOut;
	while ((((usqInt) tablePtr)) <= (((usqInt) lastOut))) {
		oop = longAt(tablePtr);
		header = longAt(hdrBaseOut + (tablePtr - firstOut));
		longAtput(oop, header);
		tablePtr += BYTES_PER_WORD;
	}
	oop = memory + (foo->headerTypeBytes[(longAt(memory)) & TypeMask]);
	while ((((usqInt) oop)) < (((usqInt) foo->endOfMemory))) {
		if (!(((longAt(oop)) & TypeMask) == HeaderTypeFree)) {
			longAtput(oop, (longAt(oop)) & (ALL_BUT_MARK_BIT));
		}
		/* begin objectAfter: */
		if (DoAssertionChecks) {
			if ((((usqInt) oop)) >= (((usqInt) foo->endOfMemory))) {
				error("no objects after the end of memory");
			}
		}
		if (((longAt(oop)) & TypeMask) == HeaderTypeFree) {
			sz = (longAt(oop)) & (ALL_BUT_TYPE_MASK);
		} else {
			/* begin sizeBitsOf: */
			header1 = longAt(oop);
			if ((header1 & TypeMask) == HeaderTypeSizeAndClass) {
				sz = (longAt(oop - ((BYTES_PER_WORD) * 2))) & (LONG_SIZE_MASK);
				goto l1;
			} else {
				sz = header1 & (SIZE_MASK);
				goto l1;
			}
		l1:	/* end sizeBitsOf: */;
		}
		oop = (oop + sz) + (foo->headerTypeBytes[(longAt(oop + sz)) & TypeMask]);
	}
}

sqInt resume(sqInt aProcess) {
register struct foo * foo = &fum;
    sqInt activePriority;
    sqInt activeProc;
    sqInt newPriority;
    sqInt oop;
    sqInt oop1;
    sqInt oop2;
    sqInt priority;
    sqInt processList;
    sqInt processLists;
    sqInt oop3;
    sqInt oop11;
    sqInt lastLink;
    sqInt oop21;
    sqInt priority1;
    sqInt processList1;
    sqInt processLists1;
    sqInt oop4;
    sqInt oop12;
    sqInt lastLink1;
    sqInt oop22;

	/* begin fetchPointer:ofObject: */
	/* begin fetchPointer:ofObject: */
	/* begin fetchPointer:ofObject: */
	oop2 = foo->specialObjectsOop;
	oop1 = longAt((oop2 + (BASE_HEADER_SIZE)) + (SchedulerAssociation << (SHIFT_FOR_WORD)));
	oop = longAt((oop1 + (BASE_HEADER_SIZE)) + (ValueIndex << (SHIFT_FOR_WORD)));
	activeProc = longAt((oop + (BASE_HEADER_SIZE)) + (ActiveProcessIndex << (SHIFT_FOR_WORD)));
	activePriority = ((longAt((activeProc + (BASE_HEADER_SIZE)) + (PriorityIndex << (SHIFT_FOR_WORD)))) >> 1);
	newPriority = ((longAt((aProcess + (BASE_HEADER_SIZE)) + (PriorityIndex << (SHIFT_FOR_WORD)))) >> 1);
	if (newPriority > activePriority) {
		/* begin putToSleep: */
		priority = ((longAt((activeProc + (BASE_HEADER_SIZE)) + (PriorityIndex << (SHIFT_FOR_WORD)))) >> 1);
		/* begin fetchPointer:ofObject: */
		/* begin fetchPointer:ofObject: */
		/* begin fetchPointer:ofObject: */
		oop21 = foo->specialObjectsOop;
		oop11 = longAt((oop21 + (BASE_HEADER_SIZE)) + (SchedulerAssociation << (SHIFT_FOR_WORD)));
		oop3 = longAt((oop11 + (BASE_HEADER_SIZE)) + (ValueIndex << (SHIFT_FOR_WORD)));
		processLists = longAt((oop3 + (BASE_HEADER_SIZE)) + (ProcessListsIndex << (SHIFT_FOR_WORD)));
		processList = longAt((processLists + (BASE_HEADER_SIZE)) + ((priority - 1) << (SHIFT_FOR_WORD)));
		/* begin addLastLink:toList: */
		if ((longAt((processList + (BASE_HEADER_SIZE)) + (FirstLinkIndex << (SHIFT_FOR_WORD)))) == foo->nilObj) {
			/* begin storePointer:ofObject:withValue: */
			if ((((usqInt) processList)) < (((usqInt) foo->youngStart))) {
				possibleRootStoreIntovalue(processList, activeProc);
			}
			longAtput((processList + (BASE_HEADER_SIZE)) + (FirstLinkIndex << (SHIFT_FOR_WORD)), activeProc);
		} else {
			lastLink = longAt((processList + (BASE_HEADER_SIZE)) + (LastLinkIndex << (SHIFT_FOR_WORD)));
			/* begin storePointer:ofObject:withValue: */
			if ((((usqInt) lastLink)) < (((usqInt) foo->youngStart))) {
				possibleRootStoreIntovalue(lastLink, activeProc);
			}
			longAtput((lastLink + (BASE_HEADER_SIZE)) + (NextLinkIndex << (SHIFT_FOR_WORD)), activeProc);
		}
		/* begin storePointer:ofObject:withValue: */
		if ((((usqInt) processList)) < (((usqInt) foo->youngStart))) {
			possibleRootStoreIntovalue(processList, activeProc);
		}
		longAtput((processList + (BASE_HEADER_SIZE)) + (LastLinkIndex << (SHIFT_FOR_WORD)), activeProc);
		/* begin storePointer:ofObject:withValue: */
		if ((((usqInt) activeProc)) < (((usqInt) foo->youngStart))) {
			possibleRootStoreIntovalue(activeProc, processList);
		}
		longAtput((activeProc + (BASE_HEADER_SIZE)) + (MyListIndex << (SHIFT_FOR_WORD)), processList);
		transferTo(aProcess);
	} else {
		/* begin putToSleep: */
		priority1 = ((longAt((aProcess + (BASE_HEADER_SIZE)) + (PriorityIndex << (SHIFT_FOR_WORD)))) >> 1);
		/* begin fetchPointer:ofObject: */
		/* begin fetchPointer:ofObject: */
		/* begin fetchPointer:ofObject: */
		oop22 = foo->specialObjectsOop;
		oop12 = longAt((oop22 + (BASE_HEADER_SIZE)) + (SchedulerAssociation << (SHIFT_FOR_WORD)));
		oop4 = longAt((oop12 + (BASE_HEADER_SIZE)) + (ValueIndex << (SHIFT_FOR_WORD)));
		processLists1 = longAt((oop4 + (BASE_HEADER_SIZE)) + (ProcessListsIndex << (SHIFT_FOR_WORD)));
		processList1 = longAt((processLists1 + (BASE_HEADER_SIZE)) + ((priority1 - 1) << (SHIFT_FOR_WORD)));
		/* begin addLastLink:toList: */
		if ((longAt((processList1 + (BASE_HEADER_SIZE)) + (FirstLinkIndex << (SHIFT_FOR_WORD)))) == foo->nilObj) {
			/* begin storePointer:ofObject:withValue: */
			if ((((usqInt) processList1)) < (((usqInt) foo->youngStart))) {
				possibleRootStoreIntovalue(processList1, aProcess);
			}
			longAtput((processList1 + (BASE_HEADER_SIZE)) + (FirstLinkIndex << (SHIFT_FOR_WORD)), aProcess);
		} else {
			lastLink1 = longAt((processList1 + (BASE_HEADER_SIZE)) + (LastLinkIndex << (SHIFT_FOR_WORD)));
			/* begin storePointer:ofObject:withValue: */
			if ((((usqInt) lastLink1)) < (((usqInt) foo->youngStart))) {
				possibleRootStoreIntovalue(lastLink1, aProcess);
			}
			longAtput((lastLink1 + (BASE_HEADER_SIZE)) + (NextLinkIndex << (SHIFT_FOR_WORD)), aProcess);
		}
		/* begin storePointer:ofObject:withValue: */
		if ((((usqInt) processList1)) < (((usqInt) foo->youngStart))) {
			possibleRootStoreIntovalue(processList1, aProcess);
		}
		longAtput((processList1 + (BASE_HEADER_SIZE)) + (LastLinkIndex << (SHIFT_FOR_WORD)), aProcess);
		/* begin storePointer:ofObject:withValue: */
		if ((((usqInt) aProcess)) < (((usqInt) foo->youngStart))) {
			possibleRootStoreIntovalue(aProcess, processList1);
		}
		longAtput((aProcess + (BASE_HEADER_SIZE)) + (MyListIndex << (SHIFT_FOR_WORD)), processList1);
	}
}


/*	Reverse the given range of Display words (at different bit 
	depths, this will reverse different numbers of pixels). Used to 
	give feedback during VM activities such as garbage 
	collection when debugging. It is assumed that the given 
	word range falls entirely within the first line of the Display. */

sqInt reverseDisplayFromto(sqInt startIndex, sqInt endIndex) {
register struct foo * foo = &fum;
    sqInt dispBitsPtr;
    sqInt displayObj;
    sqInt ptr;
    sqInt reversed;
    sqInt w;
    sqInt oop;

	/* begin fetchPointer:ofObject: */
	oop = foo->specialObjectsOop;
	displayObj = longAt((oop + (BASE_HEADER_SIZE)) + (TheDisplay << (SHIFT_FOR_WORD)));
	if (!((((displayObj & 1) == 0) && (((((usqInt) (longAt(displayObj))) >> 8) & 15) <= 4)) && ((lengthOf(displayObj)) >= 4))) {
		return null;
	}
	w = fetchIntegerofObject(1, displayObj);
	dispBitsPtr = longAt((displayObj + (BASE_HEADER_SIZE)) + (0 << (SHIFT_FOR_WORD)));
	if ((dispBitsPtr & 1)) {
		return null;
	}
	dispBitsPtr += BASE_HEADER_SIZE;
	for (ptr = (dispBitsPtr + (startIndex * 4)); ptr <= (dispBitsPtr + (endIndex * 4)); ptr += 4) {
		reversed = (long32At(ptr)) ^ 4294967295U;
		longAtput(ptr, reversed);
	}
	foo->successFlag = 1;
	displayBitsOfLeftTopRightBottom(displayObj, 0, 0, w, 1);
	ioForceDisplayUpdate();
}


/*	Rewrite the cache entry with the given primitive index and matching function pointer */

sqInt rewriteMethodCacheSelclassprimIndex(sqInt selector, sqInt class, sqInt localPrimIndex) {
    void *primPtr;

	if (localPrimIndex == 0) {
		primPtr = 0;
	} else {
		primPtr = primitiveTable[localPrimIndex];
	}
	rewriteMethodCacheSelclassprimIndexprimFunction(selector, class, localPrimIndex, primPtr);
}


/*	Rewrite an existing entry in the method cache with a new primitive 
	index & function address. Used by primExternalCall to make direct jumps to found external prims */

sqInt rewriteMethodCacheSelclassprimIndexprimFunction(sqInt selector, sqInt class, sqInt localPrimIndex, void *localPrimAddress) {
register struct foo * foo = &fum;
    sqInt hash;
    sqInt p;
    sqInt probe;

	hash = selector ^ class;
	for (p = 0; p <= (CacheProbeMax - 1); p += 1) {
		probe = (((usqInt) hash) >> p) & MethodCacheMask;
		if (((foo->methodCache[probe + MethodCacheSelector]) == selector) && ((foo->methodCache[probe + MethodCacheClass]) == class)) {
			foo->methodCache[probe + MethodCachePrim] = localPrimIndex;
			foo->methodCache[probe + MethodCachePrimFunction] = (((long) localPrimAddress));
			return null;
		}
	}
}


/*	Send the 4 argument callback message invokeCallback:stack:registers:jmpbuf:
	 to Alien class with the supplied args.  The arguments are raw C addresses
	 and are converted to integer objects on the way. */

EXPORT(sqInt) sendInvokeCallbackStackRegistersJmpbuf(sqInt thunkPtr, sqInt stackPtr, sqInt regsPtr, sqInt jmpBufPtr) {
register struct foo * foo = &fum;
    sqInt where;
    sqInt oop;
    sqInt oop1;
    sqInt oop2;
    sqInt oop3;
    sqInt oop4;
    sqInt oop5;
    sqInt ccIndex;
    sqInt oop6;
    sqInt oop7;
    sqInt activeCntx;
    sqInt i;
    sqInt initialIP;
    sqInt methodHeader;
    sqInt needsLarge;
    sqInt newContext;
    sqInt tempCount;
    sqInt where1;
    sqInt methodPointer;
    sqInt activeCntx1;
    sqInt tmp;
    sqInt oop8;
    sqInt valuePointer;
    sqInt valuePointer1;

	/* begin pushRemappableOop: */
	oop = positive32BitIntegerFor(jmpBufPtr);
	foo->remapBuffer[(foo->remapBufferCount += 1)] = oop;
	/* begin pushRemappableOop: */
	oop1 = positive32BitIntegerFor(regsPtr);
	foo->remapBuffer[(foo->remapBufferCount += 1)] = oop1;
	/* begin pushRemappableOop: */
	oop2 = positive32BitIntegerFor(stackPtr);
	foo->remapBuffer[(foo->remapBufferCount += 1)] = oop2;
	/* begin pushRemappableOop: */
	oop3 = positive32BitIntegerFor(thunkPtr);
	foo->remapBuffer[(foo->remapBufferCount += 1)] = oop3;
	/* begin fetchPointer:ofObject: */
	oop4 = foo->specialObjectsOop;
	foo->receiver = longAt((oop4 + (BASE_HEADER_SIZE)) + (ClassAlien << (SHIFT_FOR_WORD)));
	/* begin fetchClassOfNonInt: */
	oop5 = foo->receiver;
	ccIndex = (((usqInt) (longAt(oop5))) >> 12) & 31;
	if (ccIndex == 0) {
		foo->lkupClass = (longAt(oop5 - (BASE_HEADER_SIZE))) & (ALL_BUT_TYPE_MASK);
		goto l1;
	} else {
		/* begin fetchPointer:ofObject: */
		/* begin fetchPointer:ofObject: */
		oop8 = foo->specialObjectsOop;
		oop7 = longAt((oop8 + (BASE_HEADER_SIZE)) + (CompactClasses << (SHIFT_FOR_WORD)));
		foo->lkupClass = longAt((oop7 + (BASE_HEADER_SIZE)) + ((ccIndex - 1) << (SHIFT_FOR_WORD)));
		goto l1;
	}
l1:	/* end fetchClassOfNonInt: */;
	/* begin fetchPointer:ofObject: */
	oop6 = foo->specialObjectsOop;
	foo->messageSelector = longAt((oop6 + (BASE_HEADER_SIZE)) + (InvokeCallbackSelector << (SHIFT_FOR_WORD)));
	if (!(lookupInMethodCacheSelclass(foo->messageSelector, foo->lkupClass))) {
		if (!(lookupMethodNoMNUEtcInClass(foo->lkupClass))) {
			return 0;
		}
	}
	if (foo->primitiveIndex != 0) {
		return 0;
	}
	/* begin storeContextRegisters: */
	activeCntx = foo->activeContext;
	/* begin storePointerUnchecked:ofObject:withValue: */
	valuePointer = ((((foo->instructionPointer - foo->method) - ((BASE_HEADER_SIZE) - 2)) << 1) | 1);
	longAtput((activeCntx + (BASE_HEADER_SIZE)) + (InstructionPointerIndex << (SHIFT_FOR_WORD)), valuePointer);
	/* begin storePointerUnchecked:ofObject:withValue: */
	valuePointer1 = (((((((usqInt) ((foo->stackPointer - foo->activeContext) - (BASE_HEADER_SIZE))) >> (SHIFT_FOR_WORD)) - TempFrameStart) + 1) << 1) | 1);
	longAtput((activeCntx + (BASE_HEADER_SIZE)) + (StackPointerIndex << (SHIFT_FOR_WORD)), valuePointer1);
	/* begin internalJustActivateNewMethod */
	/* begin headerOf: */
	methodPointer = foo->newMethod;
	methodHeader = longAt((methodPointer + (BASE_HEADER_SIZE)) + (HeaderIndex << (SHIFT_FOR_WORD)));
	needsLarge = methodHeader & LargeContextBit;
	if ((needsLarge == 0) && (foo->freeContexts != NilContext)) {
		newContext = foo->freeContexts;
		foo->freeContexts = longAt((newContext + (BASE_HEADER_SIZE)) + (0 << (SHIFT_FOR_WORD)));
	} else {
		newContext = allocateOrRecycleContext(needsLarge);
	}
	initialIP = ((LiteralStart + ((((usqInt) methodHeader) >> 10) & 255)) * (BYTES_PER_WORD)) + 1;
	tempCount = (((usqInt) methodHeader) >> 19) & 63;
	where1 = newContext + (BASE_HEADER_SIZE);
	longAtput(where1 + (SenderIndex << (SHIFT_FOR_WORD)), foo->activeContext);
	longAtput(where1 + (InstructionPointerIndex << (SHIFT_FOR_WORD)), ((initialIP << 1) | 1));
	longAtput(where1 + (StackPointerIndex << (SHIFT_FOR_WORD)), ((tempCount << 1) | 1));
	longAtput(where1 + (MethodIndex << (SHIFT_FOR_WORD)), foo->newMethod);
	longAtput(where1 + (ReceiverIndex << (SHIFT_FOR_WORD)), foo->receiver);
	needsLarge = foo->nilObj;
	for (i = (ReceiverIndex + 1); i <= (tempCount + ReceiverIndex); i += 1) {
		longAtput(where1 + (i << (SHIFT_FOR_WORD)), needsLarge);
	}
	foo->reclaimableContextCount += 1;
	foo->activeContext = newContext;
	where = (foo->activeContext + (BASE_HEADER_SIZE)) + (ReceiverIndex << (SHIFT_FOR_WORD));
	longAtput(where + (1 << (SHIFT_FOR_WORD)), popRemappableOop());
	longAtput(where + (2 << (SHIFT_FOR_WORD)), popRemappableOop());
	longAtput(where + (3 << (SHIFT_FOR_WORD)), popRemappableOop());
	longAtput(where + (4 << (SHIFT_FOR_WORD)), popRemappableOop());
	/* begin fetchContextRegisters: */
	activeCntx1 = foo->activeContext;
	tmp = longAt((activeCntx1 + (BASE_HEADER_SIZE)) + (MethodIndex << (SHIFT_FOR_WORD)));
	if ((tmp & 1)) {
		tmp = longAt((activeCntx1 + (BASE_HEADER_SIZE)) + (HomeIndex << (SHIFT_FOR_WORD)));
		if ((((usqInt) tmp)) < (((usqInt) foo->youngStart))) {
			beRootIfOld(tmp);
		}
	} else {
		tmp = activeCntx1;
	}
	foo->theHomeContext = tmp;
	foo->receiver = longAt((tmp + (BASE_HEADER_SIZE)) + (ReceiverIndex << (SHIFT_FOR_WORD)));
	foo->method = longAt((tmp + (BASE_HEADER_SIZE)) + (MethodIndex << (SHIFT_FOR_WORD)));
	tmp = ((longAt((activeCntx1 + (BASE_HEADER_SIZE)) + (InstructionPointerIndex << (SHIFT_FOR_WORD)))) >> 1);
	foo->instructionPointer = ((foo->method + tmp) + (BASE_HEADER_SIZE)) - 2;
	tmp = ((longAt((activeCntx1 + (BASE_HEADER_SIZE)) + (StackPointerIndex << (SHIFT_FOR_WORD)))) >> 1);
	foo->stackPointer = (activeCntx1 + (BASE_HEADER_SIZE)) + (((TempFrameStart + tmp) - 1) * (BYTES_PER_WORD));
	callInterpreter();
	return 1;
}

sqInt setCompilerInitialized(sqInt newFlag) {
register struct foo * foo = &fum;
    sqInt oldFlag;

	oldFlag = foo->compilerInitialized;
	foo->compilerInitialized = newFlag;
	return oldFlag;
}

sqInt setFullScreenFlag(sqInt value) {
	foo->fullScreenFlag = value;
}

sqInt setInterruptCheckCounter(sqInt value) {
	foo->interruptCheckCounter = value;
}

sqInt setInterruptKeycode(sqInt value) {
	foo->interruptKeycode = value;
}

sqInt setInterruptPending(sqInt value) {
	foo->interruptPending = value;
}


/*	A default substitute for unimplemented ioUtcWithOffset external function. */

sqInt setMicroSecondsandOffset(sqLong *microSeconds, int *utcOffset) {
	flag("toRemove");
	return -1;
}

sqInt setNextWakeupTick(sqInt value) {
	foo->nextWakeupTick = value;
}

sqInt setSavedWindowSize(sqInt value) {
	foo->savedWindowSize = value;
}


/*	Repaint the portion of the Smalltalk screen bounded by the affected rectangle. Used to synchronize the screen after a Bitblt to the Smalltalk Display object. */

sqInt showDisplayBitsLeftTopRightBottom(sqInt aForm, sqInt l, sqInt t, sqInt r, sqInt b) {
	if (foo->deferDisplayUpdates) {
		return null;
	}
	displayBitsOfLeftTopRightBottom(aForm, l, t, r, b);
}


/*	Record the given semaphore index in the double buffer semaphores array to be signaled at the next convenient moment. Force a real interrupt check as soon as possible. */

sqInt signalSemaphoreWithIndex(sqInt index) {
register struct foo * foo = &fum;
	if (index <= 0) {
		return null;
	}
	if (foo->semaphoresUseBufferA) {
		if (foo->semaphoresToSignalCountA < SemaphoresToSignalSize) {
			foo->semaphoresToSignalCountA += 1;
			foo->semaphoresToSignalA[foo->semaphoresToSignalCountA] = index;
		}
	} else {
		if (foo->semaphoresToSignalCountB < SemaphoresToSignalSize) {
			foo->semaphoresToSignalCountB += 1;
			foo->semaphoresToSignalB[foo->semaphoresToSignalCountB] = index;
		}
	}
	/* begin forceInterruptCheck */
	foo->interruptCheckCounter = -1000;
	foo->nextPollTick = 0;
}


/*	Return a full 32 bit integer object for the given integer value */

sqInt signed32BitIntegerFor(int integerValue) {
register struct foo * foo = &fum;
    sqInt largeClass;
    sqInt newLargeInteger;
    sqInt value;
    sqInt oop;
    sqInt oop1;

	if (
# ifdef SQ_HOST32  // cast to int for 64 bit image on 32 bit host
		(((((int) integerValue)) ^ ((((int) integerValue)) << 1)) >= 0)
# else
		((integerValue >= -1073741824) && (integerValue <= 1073741823))
# endif  // SQ_HOST32
	) {
		return ((integerValue << 1) | 1);
	}
	if (integerValue < 0) {
		/* begin fetchPointer:ofObject: */
		oop = foo->specialObjectsOop;
		largeClass = longAt((oop + (BASE_HEADER_SIZE)) + (ClassLargeNegativeInteger << (SHIFT_FOR_WORD)));
		value = 0 - integerValue;
	} else {
		/* begin fetchPointer:ofObject: */
		oop1 = foo->specialObjectsOop;
		largeClass = longAt((oop1 + (BASE_HEADER_SIZE)) + (ClassLargePositiveInteger << (SHIFT_FOR_WORD)));
		value = integerValue;
	}
	newLargeInteger = instantiateClassindexableSize(largeClass, 4);
	byteAtput((newLargeInteger + (BASE_HEADER_SIZE)) + 3, (((usqInt) value) >> 24) & 255);
	byteAtput((newLargeInteger + (BASE_HEADER_SIZE)) + 2, (((usqInt) value) >> 16) & 255);
	byteAtput((newLargeInteger + (BASE_HEADER_SIZE)) + 1, (((usqInt) value) >> 8) & 255);
	byteAtput((newLargeInteger + (BASE_HEADER_SIZE)) + 0, value & 255);
	return newLargeInteger;
}


/*	Convert the given object into an integer value.
	The object may be either a positive ST integer or a four-byte LargeInteger. */

int signed32BitValueOf(sqInt oop) {
register struct foo * foo = &fum;
    sqInt largeClass;
    sqInt negative;
    sqInt sz;
    int value;
    sqInt ccIndex;
    sqInt header;
    sqInt oop1;
    sqInt oop2;
    sqInt sz1;
    sqInt oop3;

	if ((oop & 1)) {
		return (oop >> 1);
	}
	if ((lengthOf(oop)) > 4) {
		/* begin primitiveFail */
		foo->successFlag = 0;
		return null;
	}
	/* begin fetchClassOf: */
	if ((oop & 1)) {
		/* begin fetchPointer:ofObject: */
		oop1 = foo->specialObjectsOop;
		largeClass = longAt((oop1 + (BASE_HEADER_SIZE)) + (ClassInteger << (SHIFT_FOR_WORD)));
		goto l1;
	}
	ccIndex = (((usqInt) (longAt(oop))) >> 12) & 31;
	if (ccIndex == 0) {
		largeClass = (longAt(oop - (BASE_HEADER_SIZE))) & (ALL_BUT_TYPE_MASK);
		goto l1;
	} else {
		/* begin fetchPointer:ofObject: */
		/* begin fetchPointer:ofObject: */
		oop3 = foo->specialObjectsOop;
		oop2 = longAt((oop3 + (BASE_HEADER_SIZE)) + (CompactClasses << (SHIFT_FOR_WORD)));
		largeClass = longAt((oop2 + (BASE_HEADER_SIZE)) + ((ccIndex - 1) << (SHIFT_FOR_WORD)));
		goto l1;
	}
l1:	/* end fetchClassOf: */;
	if (largeClass == (fetchPointerofObject(ClassLargePositiveInteger, foo->specialObjectsOop))) {
		negative = 0;
	} else {
		if (largeClass == (fetchPointerofObject(ClassLargeNegativeInteger, foo->specialObjectsOop))) {
			negative = 1;
		} else {
			/* begin primitiveFail */
			foo->successFlag = 0;
			return null;
		}
	}
	/* begin lengthOf: */
	header = longAt(oop);
	/* begin lengthOf:baseHeader:format: */
	if ((header & TypeMask) == HeaderTypeSizeAndClass) {
		sz1 = (longAt(oop - ((BYTES_PER_WORD) * 2))) & (LONG_SIZE_MASK);
	} else {
		sz1 = header & (SIZE_MASK);
	}
	sz1 -= header & (SIZE_4_BIT);
	if (((((usqInt) header) >> 8) & 15) <= 4) {
		sz = ((usqInt) (sz1 - (BASE_HEADER_SIZE))) >> (SHIFT_FOR_WORD);
		goto l2;
	}
	if (((((usqInt) header) >> 8) & 15) < 8) {
		sz = ((usqInt) (sz1 - (BASE_HEADER_SIZE))) >> 2;
		goto l2;
	} else {
		sz = (sz1 - (BASE_HEADER_SIZE)) - (((((usqInt) header) >> 8) & 15) & 3);
		goto l2;
	}
l2:	/* end lengthOf:baseHeader:format: */;
	if (!(sz == 4)) {
		/* begin primitiveFail */
		foo->successFlag = 0;
		return null;
	}

	/* Fail if value exceeds range of a 32-bit two's-complement signed integer. */

	value = (((byteAt((oop + (BASE_HEADER_SIZE)) + 0)) + ((byteAt((oop + (BASE_HEADER_SIZE)) + 1)) << 8)) + ((byteAt((oop + (BASE_HEADER_SIZE)) + 2)) << 16)) + ((byteAt((oop + (BASE_HEADER_SIZE)) + 3)) << 24);
	if (negative) {
		value = 0 - value;
		if (value >= 0) {
			/* begin primitiveFail */
			foo->successFlag = 0;
			return null;
		}
	} else {
		if (value < 0) {
			/* begin primitiveFail */
			foo->successFlag = 0;
			return null;
		}
	}
	return value;
}


/*	Return a Large Integer object for the given integer value */

sqInt signed64BitIntegerFor(sqLong integerValue) {
register struct foo * foo = &fum;
    usqInt highWord;
    sqInt i;
    sqInt intValue;
    sqInt largeClass;
    unsigned sqLong magnitude;
    sqInt newLargeInteger;
    sqInt sz;
    sqInt oop;
    sqInt oop1;

	if (integerValue < 0) {
		/* begin fetchPointer:ofObject: */
		oop = foo->specialObjectsOop;
		largeClass = longAt((oop + (BASE_HEADER_SIZE)) + (ClassLargeNegativeInteger << (SHIFT_FOR_WORD)));
		magnitude = 0 - integerValue;
	} else {
		/* begin fetchPointer:ofObject: */
		oop1 = foo->specialObjectsOop;
		largeClass = longAt((oop1 + (BASE_HEADER_SIZE)) + (ClassLargePositiveInteger << (SHIFT_FOR_WORD)));
		magnitude = integerValue;
	}
	if (magnitude <= 2147483647U) {
		return signed32BitIntegerFor(integerValue);
	}

	/* shift is coerced to usqInt otherwise */

	highWord = magnitude >> 32;
	if (highWord == 0) {
		sz = 4;
	} else {
		sz = 5;
		if (!((highWord = ((usqInt) highWord) >> 8) == 0)) {
			sz += 1;
		}
		if (!((highWord = ((usqInt) highWord) >> 8) == 0)) {
			sz += 1;
		}
		if (!((highWord = ((usqInt) highWord) >> 8) == 0)) {
			sz += 1;
		}
	}
	newLargeInteger = instantiateClassindexableSize(largeClass, sz);
	for (i = 0; i <= (sz - 1); i += 1) {
		intValue = (magnitude >> (i * 8)) & 255;
		byteAtput((newLargeInteger + (BASE_HEADER_SIZE)) + i, intValue);
	}
	return newLargeInteger;
}


/*	Convert the given object into an integer value.
	The object may be either a positive ST integer or a eight-byte LargeInteger. */

sqLong signed64BitValueOf(sqInt oop) {
register struct foo * foo = &fum;
    sqInt i;
    sqInt largeClass;
    sqInt negative;
    sqInt sz;
    sqInt szsqLong;
    sqLong value;
    sqInt header;
    sqInt ccIndex;
    sqInt oop1;
    sqInt oop2;
    sqInt sz1;
    sqInt oop3;

	if ((oop & 1)) {
		return ((sqLong) ((oop >> 1)));
	}
	/* begin lengthOf: */
	header = longAt(oop);
	/* begin lengthOf:baseHeader:format: */
	if ((header & TypeMask) == HeaderTypeSizeAndClass) {
		sz1 = (longAt(oop - ((BYTES_PER_WORD) * 2))) & (LONG_SIZE_MASK);
	} else {
		sz1 = header & (SIZE_MASK);
	}
	sz1 -= header & (SIZE_4_BIT);
	if (((((usqInt) header) >> 8) & 15) <= 4) {
		sz = ((usqInt) (sz1 - (BASE_HEADER_SIZE))) >> (SHIFT_FOR_WORD);
		goto l2;
	}
	if (((((usqInt) header) >> 8) & 15) < 8) {
		sz = ((usqInt) (sz1 - (BASE_HEADER_SIZE))) >> 2;
		goto l2;
	} else {
		sz = (sz1 - (BASE_HEADER_SIZE)) - (((((usqInt) header) >> 8) & 15) & 3);
		goto l2;
	}
l2:	/* end lengthOf:baseHeader:format: */;
	if (sz > 8) {
		/* begin primitiveFail */
		foo->successFlag = 0;
		return null;
	}
	/* begin fetchClassOf: */
	if ((oop & 1)) {
		/* begin fetchPointer:ofObject: */
		oop1 = foo->specialObjectsOop;
		largeClass = longAt((oop1 + (BASE_HEADER_SIZE)) + (ClassInteger << (SHIFT_FOR_WORD)));
		goto l1;
	}
	ccIndex = (((usqInt) (longAt(oop))) >> 12) & 31;
	if (ccIndex == 0) {
		largeClass = (longAt(oop - (BASE_HEADER_SIZE))) & (ALL_BUT_TYPE_MASK);
		goto l1;
	} else {
		/* begin fetchPointer:ofObject: */
		/* begin fetchPointer:ofObject: */
		oop3 = foo->specialObjectsOop;
		oop2 = longAt((oop3 + (BASE_HEADER_SIZE)) + (CompactClasses << (SHIFT_FOR_WORD)));
		largeClass = longAt((oop2 + (BASE_HEADER_SIZE)) + ((ccIndex - 1) << (SHIFT_FOR_WORD)));
		goto l1;
	}
l1:	/* end fetchClassOf: */;
	if (largeClass == (fetchPointerofObject(ClassLargePositiveInteger, foo->specialObjectsOop))) {
		negative = 0;
	} else {
		if (largeClass == (fetchPointerofObject(ClassLargeNegativeInteger, foo->specialObjectsOop))) {
			negative = 1;
		} else {
			/* begin primitiveFail */
			foo->successFlag = 0;
			return null;
		}
	}
	szsqLong = sizeof(sqLong);
	if (sz > szsqLong) {
		/* begin primitiveFail */
		foo->successFlag = 0;
		return null;
	}
	value = 0;
	for (i = 0; i <= (sz - 1); i += 1) {
		value += (((sqLong) (byteAt((oop + (BASE_HEADER_SIZE)) + i)))) << (i * 8);
	}
	if (negative) {
		value = 0 - value;
		if (value >= 0) {
			/* begin primitiveFail */
			foo->successFlag = 0;
			return null;
		}
	} else {
		if (value < 0) {
			/* begin primitiveFail */
			foo->successFlag = 0;
			return null;
		}
	}
	return value;
}


/*	Answer the number of bytes in the given object, including its base header, rounded up to an integral number of words. */
/*	Note: byte indexable objects need to have low bits subtracted from this size. */

sqInt sizeBitsOf(sqInt oop) {
    sqInt header;

	header = longAt(oop);
	if ((header & TypeMask) == HeaderTypeSizeAndClass) {
		return (longAt(oop - ((BYTES_PER_WORD) * 2))) & (LONG_SIZE_MASK);
	} else {
		return header & (SIZE_MASK);
	}
}


/*	Return the number of indexable fields of the given object. This method is to be called from an automatically generated C primitive. The argument is assumed to be a pointer to the first indexable field of a words or bytes object; the object header starts 4 bytes before that. */
/*	Note: Only called by translated primitive code. */

sqInt sizeOfSTArrayFromCPrimitive(void *cPtr) {
    sqInt oop;
    sqInt header;
    sqInt sz;

	oop = (oopForPointer(((char *) cPtr))) - (BASE_HEADER_SIZE);
	if (!(((oop & 1) == 0) && (isWordsOrBytesNonInt(oop)))) {
		/* begin primitiveFail */
		foo->successFlag = 0;
		return 0;
	}
	/* begin lengthOf: */
	header = longAt(oop);
	/* begin lengthOf:baseHeader:format: */
	if ((header & TypeMask) == HeaderTypeSizeAndClass) {
		sz = (longAt(oop - ((BYTES_PER_WORD) * 2))) & (LONG_SIZE_MASK);
	} else {
		sz = header & (SIZE_MASK);
	}
	sz -= header & (SIZE_4_BIT);
	if (((((usqInt) header) >> 8) & 15) <= 4) {
		return ((usqInt) (sz - (BASE_HEADER_SIZE))) >> (SHIFT_FOR_WORD);
	}
	if (((((usqInt) header) >> 8) & 15) < 8) {
		return ((usqInt) (sz - (BASE_HEADER_SIZE))) >> 2;
	} else {
		return (sz - (BASE_HEADER_SIZE)) - (((((usqInt) header) >> 8) & 15) & 3);
	}
	return null;
}


/*	Returns the number of slots in the receiver.
	If the receiver is a byte object, return the number of bytes.
	Otherwise return the number of words. */

sqInt slotSizeOf(sqInt oop) {
    sqInt header;
    sqInt sz;

	if ((oop & 1)) {
		return 0;
	}
	/* begin lengthOf: */
	header = longAt(oop);
	/* begin lengthOf:baseHeader:format: */
	if ((header & TypeMask) == HeaderTypeSizeAndClass) {
		sz = (longAt(oop - ((BYTES_PER_WORD) * 2))) & (LONG_SIZE_MASK);
	} else {
		sz = header & (SIZE_MASK);
	}
	sz -= header & (SIZE_4_BIT);
	if (((((usqInt) header) >> 8) & 15) <= 4) {
		return ((usqInt) (sz - (BASE_HEADER_SIZE))) >> (SHIFT_FOR_WORD);
	}
	if (((((usqInt) header) >> 8) & 15) < 8) {
		return ((usqInt) (sz - (BASE_HEADER_SIZE))) >> 2;
	} else {
		return (sz - (BASE_HEADER_SIZE)) - (((((usqInt) header) >> 8) & 15) & 3);
	}
	return null;
}


/*	update state of active context */

sqInt snapshot(sqInt embedded) {
register struct foo * foo = &fum;
    sqInt activeProc;
    sqInt dataSize;
    sqInt rcvr;
    void *setMacType;
    sqInt top;
    sqInt sp;
    sqInt sp1;
    sqInt sp2;
    sqInt oop;
    sqInt activeCntx;
    sqInt oop1;
    sqInt valuePointer;
    sqInt valuePointer1;
    sqInt valuePointer2;
    sqInt oop2;
    sqInt fmt;
    sqInt header;
    sqInt i;
    sqInt oop3;
    sqInt sz;
    sqInt header1;
    sqInt i1;
    sqInt oop11;
    sqInt sz1;
    sqInt header2;

	if (foo->compilerInitialized) {
		compilerPreSnapshot();
	} else {
		/* begin storeContextRegisters: */
		activeCntx = foo->activeContext;
		/* begin storePointerUnchecked:ofObject:withValue: */
		valuePointer1 = ((((foo->instructionPointer - foo->method) - ((BASE_HEADER_SIZE) - 2)) << 1) | 1);
		longAtput((activeCntx + (BASE_HEADER_SIZE)) + (InstructionPointerIndex << (SHIFT_FOR_WORD)), valuePointer1);
		/* begin storePointerUnchecked:ofObject:withValue: */
		valuePointer2 = (((((((usqInt) ((foo->stackPointer - foo->activeContext) - (BASE_HEADER_SIZE))) >> (SHIFT_FOR_WORD)) - TempFrameStart) + 1) << 1) | 1);
		longAtput((activeCntx + (BASE_HEADER_SIZE)) + (StackPointerIndex << (SHIFT_FOR_WORD)), valuePointer2);
	}
	/* begin fetchPointer:ofObject: */
	/* begin fetchPointer:ofObject: */
	/* begin fetchPointer:ofObject: */
	oop2 = foo->specialObjectsOop;
	oop1 = longAt((oop2 + (BASE_HEADER_SIZE)) + (SchedulerAssociation << (SHIFT_FOR_WORD)));
	oop = longAt((oop1 + (BASE_HEADER_SIZE)) + (ValueIndex << (SHIFT_FOR_WORD)));
	activeProc = longAt((oop + (BASE_HEADER_SIZE)) + (ActiveProcessIndex << (SHIFT_FOR_WORD)));
	/* begin storePointer:ofObject:withValue: */
	valuePointer = foo->activeContext;
	if ((((usqInt) activeProc)) < (((usqInt) foo->youngStart))) {
		possibleRootStoreIntovalue(activeProc, valuePointer);
	}
	longAtput((activeProc + (BASE_HEADER_SIZE)) + (SuspendedContextIndex << (SHIFT_FOR_WORD)), valuePointer);
	incrementalGC();
	fullGC();
	/* begin snapshotCleanUp */
	oop3 = memory + (foo->headerTypeBytes[(longAt(memory)) & TypeMask]);
	while ((((usqInt) oop3)) < (((usqInt) foo->endOfMemory))) {
		if (!(((longAt(oop3)) & TypeMask) == HeaderTypeFree)) {
			header = longAt(oop3);
			fmt = (((usqInt) header) >> 8) & 15;
			if ((fmt == 3) && ((((((usqInt) header) >> 12) & 31) == 13) || ((((((usqInt) header) >> 12) & 31) == 14) || (((((usqInt) header) >> 12) & 31) == 4)))) {
				/* begin sizeBitsOf: */
				header1 = longAt(oop3);
				if ((header1 & TypeMask) == HeaderTypeSizeAndClass) {
					sz = (longAt(oop3 - ((BYTES_PER_WORD) * 2))) & (LONG_SIZE_MASK);
					goto l1;
				} else {
					sz = header1 & (SIZE_MASK);
					goto l1;
				}
			l1:	/* end sizeBitsOf: */;
				for (i = ((lastPointerOf(oop3)) + (BYTES_PER_WORD)); i <= (sz - (BASE_HEADER_SIZE)); i += (BYTES_PER_WORD)) {
					longAtput(oop3 + i, foo->nilObj);
				}
			}
			if (fmt >= 12) {
				if ((primitiveIndexOf(oop3)) == PrimitiveExternalCallIndex) {
					flushExternalPrimitiveOf(oop3);
				}
			}
		}
		/* begin objectAfter: */
		if (DoAssertionChecks) {
			if ((((usqInt) oop3)) >= (((usqInt) foo->endOfMemory))) {
				error("no objects after the end of memory");
			}
		}
		if (((longAt(oop3)) & TypeMask) == HeaderTypeFree) {
			sz1 = (longAt(oop3)) & (ALL_BUT_TYPE_MASK);
		} else {
			/* begin sizeBitsOf: */
			header2 = longAt(oop3);
			if ((header2 & TypeMask) == HeaderTypeSizeAndClass) {
				sz1 = (longAt(oop3 - ((BYTES_PER_WORD) * 2))) & (LONG_SIZE_MASK);
				goto l2;
			} else {
				sz1 = header2 & (SIZE_MASK);
				goto l2;
			}
		l2:	/* end sizeBitsOf: */;
		}
		oop3 = (oop3 + sz1) + (foo->headerTypeBytes[(longAt(oop3 + sz1)) & TypeMask]);
	}
	/* begin clearRootsTable */
	for (i1 = 1; i1 <= foo->rootTableCount; i1 += 1) {
		oop11 = foo->rootTable[i1];
		longAtput(oop11, (longAt(oop11)) & (ALL_BUT_ROOT_BIT));
		foo->rootTable[i1] = 0;
	}
	foo->rootTableCount = 0;

	/* Assume all objects are below the start of the free block */

	dataSize = foo->freeBlock - memory;
	if (foo->successFlag) {
		/* begin popStack */
		top = longAt(foo->stackPointer);
		foo->stackPointer -= BYTES_PER_WORD;
		rcvr = top;
		/* begin push: */
		longAtput(sp = foo->stackPointer + (BYTES_PER_WORD), foo->trueObj);
		foo->stackPointer = sp;
		writeImageFile(dataSize);
		if (!(embedded)) {

			/* set Mac file type and creator; this is a noop on other platforms */

			setMacType = ioLoadFunctionFrom("setMacFileTypeAndCreator", "FilePlugin");
			if (!(setMacType == 0)) {
				((sqInt (*)(char *, char *, char *))setMacType)(imageName, "STim", "FAST");
			}
		}
		/* begin pop: */
		foo->stackPointer -= 1 * (BYTES_PER_WORD);
	}
	beRootIfOld(foo->activeContext);
	if (foo->successFlag) {
		/* begin push: */
		longAtput(sp1 = foo->stackPointer + (BYTES_PER_WORD), foo->falseObj);
		foo->stackPointer = sp1;
	} else {
		/* begin push: */
		longAtput(sp2 = foo->stackPointer + (BYTES_PER_WORD), rcvr);
		foo->stackPointer = sp2;
	}
	if (foo->compilerInitialized) {
		compilerPostSnapshot();
	}
}


/*	Return one of the objects in the SpecialObjectsArray */

sqInt splObj(sqInt index) {
    sqInt oop;

	/* begin fetchPointer:ofObject: */
	oop = foo->specialObjectsOop;
	return longAt((oop + (BASE_HEADER_SIZE)) + (index << (SHIFT_FOR_WORD)));
}


/*	Return what ST would return for <obj> at: index. */

sqInt stObjectat(sqInt array, sqInt index) {
register struct foo * foo = &fum;
    sqInt fixedFields;
    sqInt fmt;
    sqInt hdr;
    sqInt stSize;
    sqInt totalLength;
    sqInt sp;
    sqInt sz;
    sqInt class;
    sqInt classFormat;
    sqInt ccIndex;
    sqInt oop1;
    sqInt oop2;
    sqInt oop3;

	hdr = longAt(array);
	fmt = (((usqInt) hdr) >> 8) & 15;
	/* begin lengthOf:baseHeader:format: */
	if ((hdr & TypeMask) == HeaderTypeSizeAndClass) {
		sz = (longAt(array - ((BYTES_PER_WORD) * 2))) & (LONG_SIZE_MASK);
	} else {
		sz = hdr & (SIZE_MASK);
	}
	sz -= hdr & (SIZE_4_BIT);
	if (fmt <= 4) {
		totalLength = ((usqInt) (sz - (BASE_HEADER_SIZE))) >> (SHIFT_FOR_WORD);
		goto l2;
	}
	if (fmt < 8) {
		totalLength = ((usqInt) (sz - (BASE_HEADER_SIZE))) >> 2;
		goto l2;
	} else {
		totalLength = (sz - (BASE_HEADER_SIZE)) - (fmt & 3);
		goto l2;
	}
l2:	/* end lengthOf:baseHeader:format: */;
	/* begin fixedFieldsOf:format:length: */
	if ((fmt > 4) || (fmt == 2)) {
		fixedFields = 0;
		goto l4;
	}
	if (fmt < 2) {
		fixedFields = totalLength;
		goto l4;
	}
	/* begin fetchClassOf: */
	if ((array & 1)) {
		/* begin fetchPointer:ofObject: */
		oop1 = foo->specialObjectsOop;
		class = longAt((oop1 + (BASE_HEADER_SIZE)) + (ClassInteger << (SHIFT_FOR_WORD)));
		goto l3;
	}
	ccIndex = (((usqInt) (longAt(array))) >> 12) & 31;
	if (ccIndex == 0) {
		class = (longAt(array - (BASE_HEADER_SIZE))) & (ALL_BUT_TYPE_MASK);
		goto l3;
	} else {
		/* begin fetchPointer:ofObject: */
		/* begin fetchPointer:ofObject: */
		oop3 = foo->specialObjectsOop;
		oop2 = longAt((oop3 + (BASE_HEADER_SIZE)) + (CompactClasses << (SHIFT_FOR_WORD)));
		class = longAt((oop2 + (BASE_HEADER_SIZE)) + ((ccIndex - 1) << (SHIFT_FOR_WORD)));
		goto l3;
	}
l3:	/* end fetchClassOf: */;
	classFormat = (longAt((class + (BASE_HEADER_SIZE)) + (InstanceSpecificationIndex << (SHIFT_FOR_WORD)))) - 1;
	fixedFields = (((((usqInt) classFormat) >> 11) & 192) + ((((usqInt) classFormat) >> 2) & 63)) - 1;
l4:	/* end fixedFieldsOf:format:length: */;
	if ((fmt == 3) && ((((((usqInt) hdr) >> 12) & 31) == 13) || ((((((usqInt) hdr) >> 12) & 31) == 14) || (((((usqInt) hdr) >> 12) & 31) == 4)))) {
		/* begin fetchStackPointerOf: */
		sp = longAt((array + (BASE_HEADER_SIZE)) + (StackPointerIndex << (SHIFT_FOR_WORD)));
		if (!((sp & 1))) {
			stSize = 0;
			goto l1;
		}
		stSize = (sp >> 1);
	l1:	/* end fetchStackPointerOf: */;
	} else {
		stSize = totalLength - fixedFields;
	}
	if (((((usqInt) index)) >= (((usqInt) 1))) && ((((usqInt) index)) <= (((usqInt) stSize)))) {
		/* begin subscript:with:format: */
		if (fmt <= 4) {
			return longAt((array + (BASE_HEADER_SIZE)) + (((index + fixedFields) - 1) << (SHIFT_FOR_WORD)));
		}
		if (fmt < 8) {
			return positive32BitIntegerFor(long32At((array + (BASE_HEADER_SIZE)) + (((index + fixedFields) - 1) << 2)));
		} else {
			return (((byteAt((array + (BASE_HEADER_SIZE)) + ((index + fixedFields) - 1))) << 1) | 1);
		}
		return null;
	} else {
		foo->successFlag = 0;
		return 0;
	}
}


/*	Do what ST would return for <obj> at: index put: value. */

sqInt stObjectatput(sqInt array, sqInt index, sqInt value) {
register struct foo * foo = &fum;
    sqInt fixedFields;
    sqInt fmt;
    sqInt hdr;
    sqInt stSize;
    sqInt totalLength;
    sqInt sp;
    sqInt sz;
    sqInt valueToStore;
    sqInt class;
    sqInt classFormat;
    sqInt ccIndex;
    sqInt oop1;
    sqInt oop2;
    sqInt oop3;

	hdr = longAt(array);
	fmt = (((usqInt) hdr) >> 8) & 15;
	/* begin lengthOf:baseHeader:format: */
	if ((hdr & TypeMask) == HeaderTypeSizeAndClass) {
		sz = (longAt(array - ((BYTES_PER_WORD) * 2))) & (LONG_SIZE_MASK);
	} else {
		sz = hdr & (SIZE_MASK);
	}
	sz -= hdr & (SIZE_4_BIT);
	if (fmt <= 4) {
		totalLength = ((usqInt) (sz - (BASE_HEADER_SIZE))) >> (SHIFT_FOR_WORD);
		goto l2;
	}
	if (fmt < 8) {
		totalLength = ((usqInt) (sz - (BASE_HEADER_SIZE))) >> 2;
		goto l2;
	} else {
		totalLength = (sz - (BASE_HEADER_SIZE)) - (fmt & 3);
		goto l2;
	}
l2:	/* end lengthOf:baseHeader:format: */;
	/* begin fixedFieldsOf:format:length: */
	if ((fmt > 4) || (fmt == 2)) {
		fixedFields = 0;
		goto l4;
	}
	if (fmt < 2) {
		fixedFields = totalLength;
		goto l4;
	}
	/* begin fetchClassOf: */
	if ((array & 1)) {
		/* begin fetchPointer:ofObject: */
		oop1 = foo->specialObjectsOop;
		class = longAt((oop1 + (BASE_HEADER_SIZE)) + (ClassInteger << (SHIFT_FOR_WORD)));
		goto l3;
	}
	ccIndex = (((usqInt) (longAt(array))) >> 12) & 31;
	if (ccIndex == 0) {
		class = (longAt(array - (BASE_HEADER_SIZE))) & (ALL_BUT_TYPE_MASK);
		goto l3;
	} else {
		/* begin fetchPointer:ofObject: */
		/* begin fetchPointer:ofObject: */
		oop3 = foo->specialObjectsOop;
		oop2 = longAt((oop3 + (BASE_HEADER_SIZE)) + (CompactClasses << (SHIFT_FOR_WORD)));
		class = longAt((oop2 + (BASE_HEADER_SIZE)) + ((ccIndex - 1) << (SHIFT_FOR_WORD)));
		goto l3;
	}
l3:	/* end fetchClassOf: */;
	classFormat = (longAt((class + (BASE_HEADER_SIZE)) + (InstanceSpecificationIndex << (SHIFT_FOR_WORD)))) - 1;
	fixedFields = (((((usqInt) classFormat) >> 11) & 192) + ((((usqInt) classFormat) >> 2) & 63)) - 1;
l4:	/* end fixedFieldsOf:format:length: */;
	if ((fmt == 3) && ((((((usqInt) hdr) >> 12) & 31) == 13) || ((((((usqInt) hdr) >> 12) & 31) == 14) || (((((usqInt) hdr) >> 12) & 31) == 4)))) {
		/* begin fetchStackPointerOf: */
		sp = longAt((array + (BASE_HEADER_SIZE)) + (StackPointerIndex << (SHIFT_FOR_WORD)));
		if (!((sp & 1))) {
			stSize = 0;
			goto l1;
		}
		stSize = (sp >> 1);
	l1:	/* end fetchStackPointerOf: */;
	} else {
		stSize = totalLength - fixedFields;
	}
	if (((((usqInt) index)) >= (((usqInt) 1))) && ((((usqInt) index)) <= (((usqInt) stSize)))) {
		/* begin subscript:with:storing:format: */
		if (fmt <= 4) {
			/* begin storePointer:ofObject:withValue: */
			if ((((usqInt) array)) < (((usqInt) foo->youngStart))) {
				possibleRootStoreIntovalue(array, value);
			}
			longAtput((array + (BASE_HEADER_SIZE)) + (((index + fixedFields) - 1) << (SHIFT_FOR_WORD)), value);
		} else {
			if (fmt < 8) {
				valueToStore = positive32BitValueOf(value);
				if (foo->successFlag) {
					long32Atput((array + (BASE_HEADER_SIZE)) + (((index + fixedFields) - 1) << 2), valueToStore);
				}
			} else {
				if (!((value & 1))) {
					foo->successFlag = 0;
				}
				valueToStore = (value >> 1);
				if (!((valueToStore >= 0) && (valueToStore <= 255))) {
					foo->successFlag = 0;
				}
				if (foo->successFlag) {
					byteAtput((array + (BASE_HEADER_SIZE)) + ((index + fixedFields) - 1), valueToStore);
				}
			}
		}
	} else {
		foo->successFlag = 0;
	}
}


/*	Return the number of indexable fields in the given object. (i.e., what Smalltalk would return for <obj> size). */
/*	Note: Assume oop is not a SmallInteger! */

sqInt stSizeOf(sqInt oop) {
register struct foo * foo = &fum;
    sqInt fixedFields;
    sqInt fmt;
    sqInt hdr;
    sqInt totalLength;
    sqInt sp;
    sqInt sz;
    sqInt class;
    sqInt classFormat;
    sqInt ccIndex;
    sqInt oop1;
    sqInt oop2;
    sqInt oop3;

	hdr = longAt(oop);
	fmt = (((usqInt) hdr) >> 8) & 15;
	/* begin lengthOf:baseHeader:format: */
	if ((hdr & TypeMask) == HeaderTypeSizeAndClass) {
		sz = (longAt(oop - ((BYTES_PER_WORD) * 2))) & (LONG_SIZE_MASK);
	} else {
		sz = hdr & (SIZE_MASK);
	}
	sz -= hdr & (SIZE_4_BIT);
	if (fmt <= 4) {
		totalLength = ((usqInt) (sz - (BASE_HEADER_SIZE))) >> (SHIFT_FOR_WORD);
		goto l1;
	}
	if (fmt < 8) {
		totalLength = ((usqInt) (sz - (BASE_HEADER_SIZE))) >> 2;
		goto l1;
	} else {
		totalLength = (sz - (BASE_HEADER_SIZE)) - (fmt & 3);
		goto l1;
	}
l1:	/* end lengthOf:baseHeader:format: */;
	/* begin fixedFieldsOf:format:length: */
	if ((fmt > 4) || (fmt == 2)) {
		fixedFields = 0;
		goto l3;
	}
	if (fmt < 2) {
		fixedFields = totalLength;
		goto l3;
	}
	/* begin fetchClassOf: */
	if ((oop & 1)) {
		/* begin fetchPointer:ofObject: */
		oop1 = foo->specialObjectsOop;
		class = longAt((oop1 + (BASE_HEADER_SIZE)) + (ClassInteger << (SHIFT_FOR_WORD)));
		goto l2;
	}
	ccIndex = (((usqInt) (longAt(oop))) >> 12) & 31;
	if (ccIndex == 0) {
		class = (longAt(oop - (BASE_HEADER_SIZE))) & (ALL_BUT_TYPE_MASK);
		goto l2;
	} else {
		/* begin fetchPointer:ofObject: */
		/* begin fetchPointer:ofObject: */
		oop3 = foo->specialObjectsOop;
		oop2 = longAt((oop3 + (BASE_HEADER_SIZE)) + (CompactClasses << (SHIFT_FOR_WORD)));
		class = longAt((oop2 + (BASE_HEADER_SIZE)) + ((ccIndex - 1) << (SHIFT_FOR_WORD)));
		goto l2;
	}
l2:	/* end fetchClassOf: */;
	classFormat = (longAt((class + (BASE_HEADER_SIZE)) + (InstanceSpecificationIndex << (SHIFT_FOR_WORD)))) - 1;
	fixedFields = (((((usqInt) classFormat) >> 11) & 192) + ((((usqInt) classFormat) >> 2) & 63)) - 1;
l3:	/* end fixedFieldsOf:format:length: */;
	if ((fmt == 3) && ((((((usqInt) hdr) >> 12) & 31) == 13) || ((((((usqInt) hdr) >> 12) & 31) == 14) || (((((usqInt) hdr) >> 12) & 31) == 4)))) {
		/* begin fetchStackPointerOf: */
		sp = longAt((oop + (BASE_HEADER_SIZE)) + (StackPointerIndex << (SHIFT_FOR_WORD)));
		if (!((sp & 1))) {
			return 0;
		}
		return (sp >> 1);
	} else {
		return totalLength - fixedFields;
	}
}


/*	Note: May be called by translated primitive code. */

double stackFloatValue(sqInt offset) {
register struct foo * foo = &fum;
    sqInt floatPointer;
    double  result;

	floatPointer = longAt(foo->stackPointer - (offset * (BYTES_PER_WORD)));
	if (!((fetchClassOf(floatPointer)) == (fetchPointerofObject(ClassFloat, foo->specialObjectsOop)))) {
		/* begin primitiveFail */
		foo->successFlag = 0;
		return 0.0;
	}
	;
	fetchFloatAtinto(floatPointer + (BASE_HEADER_SIZE), result);
	return result;
}

sqInt stackIntegerValue(sqInt offset) {
register struct foo * foo = &fum;
    sqInt integerPointer;

	integerPointer = longAt(foo->stackPointer - (offset * (BYTES_PER_WORD)));
	/* begin checkedIntegerValueOf: */
	if ((integerPointer & 1)) {
		return (integerPointer >> 1);
	} else {
		/* begin primitiveFail */
		foo->successFlag = 0;
		return 0;
	}
	return null;
}


/*	Ensures that the given object is a real object, not a SmallInteger. */

sqInt stackObjectValue(sqInt offset) {
register struct foo * foo = &fum;
    sqInt oop;

	oop = longAt(foo->stackPointer - (offset * (BYTES_PER_WORD)));
	if ((oop & 1)) {
		/* begin primitiveFail */
		foo->successFlag = 0;
		return null;
	}
	return oop;
}

sqInt stackValue(sqInt offset) {
	return longAt(foo->stackPointer - (offset * (BYTES_PER_WORD)));
}


/*	Note: May be called by translated primitive code. */

sqInt storeIntegerofObjectwithValue(sqInt fieldIndex, sqInt objectPointer, sqInt integerValue) {
	if (
# ifdef SQ_HOST32  // cast to int for 64 bit image on 32 bit host
		(((((int) integerValue)) ^ ((((int) integerValue)) << 1)) >= 0)
# else
		((integerValue >= -1073741824) && (integerValue <= 1073741823))
# endif  // SQ_HOST32
	) {
		longAtput((objectPointer + (BASE_HEADER_SIZE)) + (fieldIndex << (SHIFT_FOR_WORD)), ((integerValue << 1) | 1));
	} else {
		/* begin primitiveFail */
		foo->successFlag = 0;
	}
}


/*	Note must check here for stores of young objects into old ones. */

sqInt storePointerofObjectwithValue(sqInt fieldIndex, sqInt oop, sqInt valuePointer) {
	if ((((usqInt) oop)) < (((usqInt) foo->youngStart))) {
		possibleRootStoreIntovalue(oop, valuePointer);
	}
	return longAtput((oop + (BASE_HEADER_SIZE)) + (fieldIndex << (SHIFT_FOR_WORD)), valuePointer);
}

sqInt success(sqInt successValue) {
register struct foo * foo = &fum;
	foo->successFlag = successValue && foo->successFlag;
}


/*	Return true if there is enough free space after doing a garbage collection. If not, signal that space is low. */

sqInt sufficientSpaceAfterGC(usqInt minFree) {
register struct foo * foo = &fum;
    usqInt growSize;
    usqInt minFreePlus;

	incrementalGC();
	if (oopisLessThan((longAt(foo->freeBlock)) & (ALL_BUT_TYPE_MASK), minFree)) {
		if (foo->signalLowSpace) {
			return 0;
		}
		fullGC();
		minFreePlus = minFree + 15000;
		if (minFreePlus < minFree) {
			return 0;
		}
		if (oopisGreaterThanOrEqualTo((longAt(foo->freeBlock)) & (ALL_BUT_TYPE_MASK), minFreePlus)) {
			return 1;
		}
		growSize = (minFree - ((longAt(foo->freeBlock)) & (ALL_BUT_TYPE_MASK))) + foo->growHeadroom;
		growObjectMemory(growSize);
		if (oopisGreaterThanOrEqualTo((longAt(foo->freeBlock)) & (ALL_BUT_TYPE_MASK), minFreePlus)) {
			return 1;
		}
		return 0;
	}
	return 1;
}


/*	Return true if there is enough space to allocate the given number of bytes,
	perhaps after doing a garbage collection. Sender is responsible for ensuring
	that requested size does result in arithmetic overflow, see note below. */

sqInt sufficientSpaceToAllocate(usqInt bytes) {
register struct foo * foo = &fum;
    usqInt minFree;


	/* Note: Arithmetic overflow may occur in calculation of minFree (indicated by
	minFree < bytes after calculation of minFree). The check is performed by sender
	to avoid redundant test here. */
	/* check for low-space */

	minFree = (foo->lowSpaceThreshold + bytes) + (BASE_HEADER_SIZE);
	if (oopisGreaterThanOrEqualTo((longAt(foo->freeBlock)) & (ALL_BUT_TYPE_MASK), minFree)) {
		return 1;
	} else {
		return sufficientSpaceAfterGC(minFree);
	}
}

sqInt superclassOf(sqInt classPointer) {
	return longAt((classPointer + (BASE_HEADER_SIZE)) + (SuperclassIndex << (SHIFT_FOR_WORD)));
}


/*	Sweep memory from youngStart through the end of memory. Free all 
	inaccessible objects and coalesce adjacent free chunks. Clear the mark 
	bits of accessible objects. Compute the starting point for the first pass of 
	incremental compaction (compStart). Return the number of surviving 
	objects.  */
/*	Details: Each time a non-free object is encountered, decrement the 
	number of available forward table entries. If all entries are spoken for 
	(i.e., entriesAvailable reaches zero), set compStart to the last free 
	chunk before that object or, if there is no free chunk before the given 
	object, the first free chunk after it. Thus, at the end of the sweep 
	phase, compStart through compEnd spans the highest collection of 
	non-free objects that can be accomodated by the forwarding table. This 
	information is used by the first pass of incremental compaction to 
	ensure that space is initially freed at the end of memory. Note that 
	there should always be at least one free chunk--the one at the end of 
	the heap. */

sqInt sweepPhase(void) {
register struct foo * foo = &fum;
    usqInt endOfMemoryLocal;
    sqInt entriesAvailable;
    sqInt firstFree;
    sqInt freeChunk;
    sqInt freeChunkSize;
    sqInt hdrBytes;
    usqInt oop;
    sqInt oopHeader;
    sqInt oopHeaderType;
    sqInt oopSize;
    sqInt survivors;

	entriesAvailable = fwdTableInit((BYTES_PER_WORD) * 2);
	survivors = 0;

	/* an invalid object pointer, note that 0 may refer to a meaningful slot */

	freeChunk = -1;

	/* will be updated later */

	firstFree = -1;
	endOfMemoryLocal = foo->endOfMemory;
	oop = foo->youngStart + (foo->headerTypeBytes[(longAt(foo->youngStart)) & TypeMask]);
	while (oop < endOfMemoryLocal) {

		/* get oop's header, header type, size, and header size */

		foo->statSweepCount += 1;
		oopHeader = longAt(oop);
		oopHeaderType = oopHeader & TypeMask;
		hdrBytes = foo->headerTypeBytes[oopHeaderType];
		if ((oopHeaderType & 1) == 1) {
			oopSize = oopHeader & (SIZE_MASK);
		} else {
			if (oopHeaderType == HeaderTypeSizeAndClass) {
				oopSize = (longAt(oop - ((BYTES_PER_WORD) * 2))) & (LONG_SIZE_MASK);
			} else {

				/* free chunk */

				oopSize = oopHeader & (LONG_SIZE_MASK);
			}
		}
		if ((oopHeader & (MARK_BIT)) == 0) {
			longAtput(oop - hdrBytes, HeaderTypeFree);
			if (freeChunk != -1) {

				/* enlarge current free chunk to include this oop */

				freeChunkSize = (freeChunkSize + oopSize) + hdrBytes;
			} else {

				/* start a new free chunk */
				/* chunk may start 4 or 8 bytes before oop */

				freeChunk = oop - hdrBytes;

				/* adjust size for possible extra header bytes */

				freeChunkSize = oopSize + (oop - freeChunk);
				if (firstFree == -1) {
					firstFree = freeChunk;
				}
			}
		} else {
			longAtput(oop, oopHeader & (ALL_BUT_MARK_BIT));
			if (((((usqInt) (longAt(oop))) >> 8) & 15) == 4) {
				finalizeReference(oop);
			}
			if (entriesAvailable > 0) {
				entriesAvailable -= 1;
			} else {

				/* start compaction at the last free chunk before this object */

				firstFree = freeChunk;
			}
			if (freeChunk != -1) {
				longAtput(freeChunk, (freeChunkSize & (LONG_SIZE_MASK)) | HeaderTypeFree);
				freeChunk = -1;
			}
			survivors += 1;
		}
		oop = (oop + oopSize) + (foo->headerTypeBytes[(longAt(oop + oopSize)) & TypeMask]);
	}
	if (freeChunk != -1) {
		longAtput(freeChunk, (freeChunkSize & (LONG_SIZE_MASK)) | HeaderTypeFree);
	}
	if (!(oop == foo->endOfMemory)) {
		error("sweep failed to find exact end of memory");
	}
	if (firstFree == -1) {
		error("expected to find at least one free object");
	} else {
		foo->compStart = firstFree;
	}
	return survivors;
}


/*	Signal the given semaphore from within the interpreter. */

sqInt synchronousSignal(sqInt aSemaphore) {
register struct foo * foo = &fum;
    sqInt excessSignals;

	if ((longAt((aSemaphore + (BASE_HEADER_SIZE)) + (FirstLinkIndex << (SHIFT_FOR_WORD)))) == foo->nilObj) {

		/* no process is waiting on this semaphore */

		excessSignals = fetchIntegerofObject(ExcessSignalsIndex, aSemaphore);
		/* begin storeInteger:ofObject:withValue: */
		if (
# ifdef SQ_HOST32  // cast to int for 64 bit image on 32 bit host
			(((((int) (excessSignals + 1))) ^ ((((int) (excessSignals + 1))) << 1)) >= 0)
# else
			(((excessSignals + 1) >= -1073741824) && ((excessSignals + 1) <= 1073741823))
# endif  // SQ_HOST32
		) {
			longAtput((aSemaphore + (BASE_HEADER_SIZE)) + (ExcessSignalsIndex << (SHIFT_FOR_WORD)), (((excessSignals + 1) << 1) | 1));
		} else {
			/* begin primitiveFail */
			foo->successFlag = 0;
		}
	} else {
		resume(removeFirstLinkOfList(aSemaphore));
	}
}


/*	Record a process to be awoken on the next interpreter cycle. 
	ikp 11/24/1999 06:07 -- added hook for external runtime 
	compiler  */

sqInt transferTo(sqInt aProc) {
register struct foo * foo = &fum;
    sqInt newProc;
    sqInt oldProc;
    sqInt sched;
    sqInt valuePointer;
    sqInt aContext;
    sqInt valuePointer1;
    sqInt oop;
    sqInt activeCntx;
    sqInt valuePointer2;
    sqInt valuePointer11;
    sqInt tmp;
    sqInt oop1;

	newProc = aProc;
	/* begin fetchPointer:ofObject: */
	/* begin fetchPointer:ofObject: */
	oop1 = foo->specialObjectsOop;
	oop = longAt((oop1 + (BASE_HEADER_SIZE)) + (SchedulerAssociation << (SHIFT_FOR_WORD)));
	sched = longAt((oop + (BASE_HEADER_SIZE)) + (ValueIndex << (SHIFT_FOR_WORD)));
	oldProc = longAt((sched + (BASE_HEADER_SIZE)) + (ActiveProcessIndex << (SHIFT_FOR_WORD)));
	/* begin storePointer:ofObject:withValue: */
	if ((((usqInt) sched)) < (((usqInt) foo->youngStart))) {
		possibleRootStoreIntovalue(sched, newProc);
	}
	longAtput((sched + (BASE_HEADER_SIZE)) + (ActiveProcessIndex << (SHIFT_FOR_WORD)), newProc);
	if (foo->compilerInitialized) {
		compilerProcessChangeto(oldProc, newProc);
	} else {
		/* begin storePointer:ofObject:withValue: */
		valuePointer = foo->activeContext;
		if ((((usqInt) oldProc)) < (((usqInt) foo->youngStart))) {
			possibleRootStoreIntovalue(oldProc, valuePointer);
		}
		longAtput((oldProc + (BASE_HEADER_SIZE)) + (SuspendedContextIndex << (SHIFT_FOR_WORD)), valuePointer);
		/* begin newActiveContext: */
		aContext = longAt((newProc + (BASE_HEADER_SIZE)) + (SuspendedContextIndex << (SHIFT_FOR_WORD)));
		/* begin storeContextRegisters: */
		activeCntx = foo->activeContext;
		/* begin storePointerUnchecked:ofObject:withValue: */
		valuePointer2 = ((((foo->instructionPointer - foo->method) - ((BASE_HEADER_SIZE) - 2)) << 1) | 1);
		longAtput((activeCntx + (BASE_HEADER_SIZE)) + (InstructionPointerIndex << (SHIFT_FOR_WORD)), valuePointer2);
		/* begin storePointerUnchecked:ofObject:withValue: */
		valuePointer11 = (((((((usqInt) ((foo->stackPointer - foo->activeContext) - (BASE_HEADER_SIZE))) >> (SHIFT_FOR_WORD)) - TempFrameStart) + 1) << 1) | 1);
		longAtput((activeCntx + (BASE_HEADER_SIZE)) + (StackPointerIndex << (SHIFT_FOR_WORD)), valuePointer11);
		if ((((usqInt) aContext)) < (((usqInt) foo->youngStart))) {
			beRootIfOld(aContext);
		}
		foo->activeContext = aContext;
		/* begin fetchContextRegisters: */
		tmp = longAt((aContext + (BASE_HEADER_SIZE)) + (MethodIndex << (SHIFT_FOR_WORD)));
		if ((tmp & 1)) {
			tmp = longAt((aContext + (BASE_HEADER_SIZE)) + (HomeIndex << (SHIFT_FOR_WORD)));
			if ((((usqInt) tmp)) < (((usqInt) foo->youngStart))) {
				beRootIfOld(tmp);
			}
		} else {
			tmp = aContext;
		}
		foo->theHomeContext = tmp;
		foo->receiver = longAt((tmp + (BASE_HEADER_SIZE)) + (ReceiverIndex << (SHIFT_FOR_WORD)));
		foo->method = longAt((tmp + (BASE_HEADER_SIZE)) + (MethodIndex << (SHIFT_FOR_WORD)));
		tmp = ((longAt((aContext + (BASE_HEADER_SIZE)) + (InstructionPointerIndex << (SHIFT_FOR_WORD)))) >> 1);
		foo->instructionPointer = ((foo->method + tmp) + (BASE_HEADER_SIZE)) - 2;
		tmp = ((longAt((aContext + (BASE_HEADER_SIZE)) + (StackPointerIndex << (SHIFT_FOR_WORD)))) >> 1);
		foo->stackPointer = (aContext + (BASE_HEADER_SIZE)) + (((TempFrameStart + tmp) - 1) * (BYTES_PER_WORD));
		/* begin storePointer:ofObject:withValue: */
		valuePointer1 = foo->nilObj;
		if ((((usqInt) newProc)) < (((usqInt) foo->youngStart))) {
			possibleRootStoreIntovalue(newProc, valuePointer1);
		}
		longAtput((newProc + (BASE_HEADER_SIZE)) + (SuspendedContextIndex << (SHIFT_FOR_WORD)), valuePointer1);
	}
	foo->reclaimableContextCount = 0;
}

sqInt trueObject(void) {
	return foo->trueObj;
}


/*	update pointers in the given memory range */

sqInt updatePointersInRangeFromto(sqInt memStart, sqInt memEnd) {
register struct foo * foo = &fum;
    sqInt oop;
    sqInt fwdBlock;
    sqInt header;
    sqInt realHeader;
    sqInt sz;
    sqInt fieldOffset;
    sqInt fieldOop;
    sqInt fwdBlock3;
    sqInt newOop;
    sqInt contextSize;
    sqInt fmt;
    sqInt fwdBlock1;
    sqInt header1;
    sqInt methodHeader;
    sqInt size;
    sqInt sp;
    sqInt classHeader;
    sqInt classOop;
    sqInt fwdBlock2;
    sqInt newClassHeader;
    sqInt newClassOop;
    sqInt sz1;
    sqInt header2;

	oop = memStart + (foo->headerTypeBytes[(longAt(memStart)) & TypeMask]);
	while ((((usqInt) oop)) < (((usqInt) memEnd))) {
		if (!(((longAt(oop)) & TypeMask) == HeaderTypeFree)) {
			/* begin remapFieldsAndClassOf: */
			/* begin lastPointerWhileForwarding: */
			header1 = longAt(oop);
			if ((header1 & (MARK_BIT)) != 0) {
				fwdBlock1 = (header1 & (ALL_BUT_MARK_BIT_AND_TYPE_MASK)) << 1;
				if (DoAssertionChecks) {
					/* begin fwdBlockValidate: */
					if (!(((((usqInt) fwdBlock1)) > (((usqInt) foo->endOfMemory))) && (((((usqInt) fwdBlock1)) <= (((usqInt) foo->fwdTableNext))) && ((fwdBlock1 & 3) == 0)))) {
						error("invalid fwd table entry");
					}
				}
				header1 = longAt(fwdBlock1 + (BYTES_PER_WORD));
			}
			fmt = (((usqInt) header1) >> 8) & 15;
			if (fmt <= 4) {
				if ((fmt == 3) && ((((((usqInt) header1) >> 12) & 31) == 13) || ((((((usqInt) header1) >> 12) & 31) == 14) || (((((usqInt) header1) >> 12) & 31) == 4)))) {
					/* begin fetchStackPointerOf: */
					sp = longAt((oop + (BASE_HEADER_SIZE)) + (StackPointerIndex << (SHIFT_FOR_WORD)));
					if (!((sp & 1))) {
						contextSize = 0;
						goto l4;
					}
					contextSize = (sp >> 1);
				l4:	/* end fetchStackPointerOf: */;
					fieldOffset = (CtxtTempFrameStart + contextSize) * (BYTES_PER_WORD);
					goto l2;
				}
				if ((header1 & TypeMask) == HeaderTypeSizeAndClass) {
					size = (longAt(oop - ((BYTES_PER_WORD) * 2))) & (ALL_BUT_TYPE_MASK);
				} else {
					size = header1 & (SIZE_MASK);
				}
				fieldOffset = size - (BASE_HEADER_SIZE);
				goto l2;
			}
			if (fmt < 12) {
				fieldOffset = 0;
				goto l2;
			}
			methodHeader = longAt(oop + (BASE_HEADER_SIZE));
			fieldOffset = (((((usqInt) methodHeader) >> 10) & 255) * (BYTES_PER_WORD)) + (BASE_HEADER_SIZE);
		l2:	/* end lastPointerWhileForwarding: */;
			while (fieldOffset >= (BASE_HEADER_SIZE)) {
				fieldOop = longAt(oop + fieldOffset);
				if (((fieldOop & 1) == 0) && (((longAt(fieldOop)) & (MARK_BIT)) != 0)) {
					fwdBlock3 = ((longAt(fieldOop)) & (ALL_BUT_MARK_BIT_AND_TYPE_MASK)) << 1;
					if (DoAssertionChecks) {
						/* begin fwdBlockValidate: */
						if (!(((((usqInt) fwdBlock3)) > (((usqInt) foo->endOfMemory))) && (((((usqInt) fwdBlock3)) <= (((usqInt) foo->fwdTableNext))) && ((fwdBlock3 & 3) == 0)))) {
							error("invalid fwd table entry");
						}
					}
					newOop = longAt(fwdBlock3);
					longAtput(oop + fieldOffset, newOop);
					if (((((usqInt) oop)) < (((usqInt) foo->youngStart))) && ((((usqInt) newOop)) >= (((usqInt) foo->youngStart)))) {
						beRootWhileForwarding(oop);
					}
				}
				fieldOffset -= BYTES_PER_WORD;
			}
			/* begin remapClassOf: */
			if (((longAt(oop)) & TypeMask) == HeaderTypeShort) {
				goto l3;
			}
			classHeader = longAt(oop - (BYTES_PER_WORD));
			classOop = classHeader & (ALL_BUT_TYPE_MASK);
			if (((classOop & 1) == 0) && (((longAt(classOop)) & (MARK_BIT)) != 0)) {
				fwdBlock2 = ((longAt(classOop)) & (ALL_BUT_MARK_BIT_AND_TYPE_MASK)) << 1;
				if (DoAssertionChecks) {
					/* begin fwdBlockValidate: */
					if (!(((((usqInt) fwdBlock2)) > (((usqInt) foo->endOfMemory))) && (((((usqInt) fwdBlock2)) <= (((usqInt) foo->fwdTableNext))) && ((fwdBlock2 & 3) == 0)))) {
						error("invalid fwd table entry");
					}
				}
				newClassOop = longAt(fwdBlock2);
				newClassHeader = newClassOop | (classHeader & TypeMask);
				longAtput(oop - (BYTES_PER_WORD), newClassHeader);
				if (((((usqInt) oop)) < (((usqInt) foo->youngStart))) && ((((usqInt) newClassOop)) >= (((usqInt) foo->youngStart)))) {
					beRootWhileForwarding(oop);
				}
			}
		l3:	/* end remapClassOf: */;
		}
		/* begin objectAfterWhileForwarding: */
		header = longAt(oop);
		if ((header & (MARK_BIT)) == 0) {
			/* begin objectAfter: */
			if (DoAssertionChecks) {
				if ((((usqInt) oop)) >= (((usqInt) foo->endOfMemory))) {
					error("no objects after the end of memory");
				}
			}
			if (((longAt(oop)) & TypeMask) == HeaderTypeFree) {
				sz1 = (longAt(oop)) & (ALL_BUT_TYPE_MASK);
			} else {
				/* begin sizeBitsOf: */
				header2 = longAt(oop);
				if ((header2 & TypeMask) == HeaderTypeSizeAndClass) {
					sz1 = (longAt(oop - ((BYTES_PER_WORD) * 2))) & (LONG_SIZE_MASK);
					goto l5;
				} else {
					sz1 = header2 & (SIZE_MASK);
					goto l5;
				}
			l5:	/* end sizeBitsOf: */;
			}
			oop = (oop + sz1) + (foo->headerTypeBytes[(longAt(oop + sz1)) & TypeMask]);
			goto l1;
		}
		fwdBlock = (header & (ALL_BUT_MARK_BIT_AND_TYPE_MASK)) << 1;
		if (DoAssertionChecks) {
			/* begin fwdBlockValidate: */
			if (!(((((usqInt) fwdBlock)) > (((usqInt) foo->endOfMemory))) && (((((usqInt) fwdBlock)) <= (((usqInt) foo->fwdTableNext))) && ((fwdBlock & 3) == 0)))) {
				error("invalid fwd table entry");
			}
		}
		realHeader = longAt(fwdBlock + (BYTES_PER_WORD));
		if ((realHeader & TypeMask) == HeaderTypeSizeAndClass) {
			sz = (longAt(oop - ((BYTES_PER_WORD) * 2))) & (LONG_SIZE_MASK);
		} else {
			sz = realHeader & (SIZE_MASK);
		}
		oop = (oop + sz) + (foo->headerTypeBytes[(longAt(oop + sz)) & TypeMask]);
	l1:	/* end objectAfterWhileForwarding: */;
	}
}


/*	update pointers in root objects */

sqInt updatePointersInRootObjectsFromto(sqInt memStart, sqInt memEnd) {
register struct foo * foo = &fum;
    sqInt i;
    sqInt oop;
    sqInt fieldOffset;
    sqInt fieldOop;
    sqInt fwdBlock;
    sqInt newOop;
    sqInt contextSize;
    sqInt fmt;
    sqInt fwdBlock1;
    sqInt header;
    sqInt methodHeader;
    sqInt size;
    sqInt sp;
    sqInt classHeader;
    sqInt classOop;
    sqInt fwdBlock2;
    sqInt newClassHeader;
    sqInt newClassOop;

	for (i = 1; i <= foo->rootTableCount; i += 1) {
		oop = foo->rootTable[i];
		if (((((usqInt) oop)) < (((usqInt) memStart))) || ((((usqInt) oop)) >= (((usqInt) memEnd)))) {
			/* begin remapFieldsAndClassOf: */
			/* begin lastPointerWhileForwarding: */
			header = longAt(oop);
			if ((header & (MARK_BIT)) != 0) {
				fwdBlock1 = (header & (ALL_BUT_MARK_BIT_AND_TYPE_MASK)) << 1;
				if (DoAssertionChecks) {
					/* begin fwdBlockValidate: */
					if (!(((((usqInt) fwdBlock1)) > (((usqInt) foo->endOfMemory))) && (((((usqInt) fwdBlock1)) <= (((usqInt) foo->fwdTableNext))) && ((fwdBlock1 & 3) == 0)))) {
						error("invalid fwd table entry");
					}
				}
				header = longAt(fwdBlock1 + (BYTES_PER_WORD));
			}
			fmt = (((usqInt) header) >> 8) & 15;
			if (fmt <= 4) {
				if ((fmt == 3) && ((((((usqInt) header) >> 12) & 31) == 13) || ((((((usqInt) header) >> 12) & 31) == 14) || (((((usqInt) header) >> 12) & 31) == 4)))) {
					/* begin fetchStackPointerOf: */
					sp = longAt((oop + (BASE_HEADER_SIZE)) + (StackPointerIndex << (SHIFT_FOR_WORD)));
					if (!((sp & 1))) {
						contextSize = 0;
						goto l1;
					}
					contextSize = (sp >> 1);
				l1:	/* end fetchStackPointerOf: */;
					fieldOffset = (CtxtTempFrameStart + contextSize) * (BYTES_PER_WORD);
					goto l2;
				}
				if ((header & TypeMask) == HeaderTypeSizeAndClass) {
					size = (longAt(oop - ((BYTES_PER_WORD) * 2))) & (ALL_BUT_TYPE_MASK);
				} else {
					size = header & (SIZE_MASK);
				}
				fieldOffset = size - (BASE_HEADER_SIZE);
				goto l2;
			}
			if (fmt < 12) {
				fieldOffset = 0;
				goto l2;
			}
			methodHeader = longAt(oop + (BASE_HEADER_SIZE));
			fieldOffset = (((((usqInt) methodHeader) >> 10) & 255) * (BYTES_PER_WORD)) + (BASE_HEADER_SIZE);
		l2:	/* end lastPointerWhileForwarding: */;
			while (fieldOffset >= (BASE_HEADER_SIZE)) {
				fieldOop = longAt(oop + fieldOffset);
				if (((fieldOop & 1) == 0) && (((longAt(fieldOop)) & (MARK_BIT)) != 0)) {
					fwdBlock = ((longAt(fieldOop)) & (ALL_BUT_MARK_BIT_AND_TYPE_MASK)) << 1;
					if (DoAssertionChecks) {
						/* begin fwdBlockValidate: */
						if (!(((((usqInt) fwdBlock)) > (((usqInt) foo->endOfMemory))) && (((((usqInt) fwdBlock)) <= (((usqInt) foo->fwdTableNext))) && ((fwdBlock & 3) == 0)))) {
							error("invalid fwd table entry");
						}
					}
					newOop = longAt(fwdBlock);
					longAtput(oop + fieldOffset, newOop);
					if (((((usqInt) oop)) < (((usqInt) foo->youngStart))) && ((((usqInt) newOop)) >= (((usqInt) foo->youngStart)))) {
						beRootWhileForwarding(oop);
					}
				}
				fieldOffset -= BYTES_PER_WORD;
			}
			/* begin remapClassOf: */
			if (((longAt(oop)) & TypeMask) == HeaderTypeShort) {
				goto l3;
			}
			classHeader = longAt(oop - (BYTES_PER_WORD));
			classOop = classHeader & (ALL_BUT_TYPE_MASK);
			if (((classOop & 1) == 0) && (((longAt(classOop)) & (MARK_BIT)) != 0)) {
				fwdBlock2 = ((longAt(classOop)) & (ALL_BUT_MARK_BIT_AND_TYPE_MASK)) << 1;
				if (DoAssertionChecks) {
					/* begin fwdBlockValidate: */
					if (!(((((usqInt) fwdBlock2)) > (((usqInt) foo->endOfMemory))) && (((((usqInt) fwdBlock2)) <= (((usqInt) foo->fwdTableNext))) && ((fwdBlock2 & 3) == 0)))) {
						error("invalid fwd table entry");
					}
				}
				newClassOop = longAt(fwdBlock2);
				newClassHeader = newClassOop | (classHeader & TypeMask);
				longAtput(oop - (BYTES_PER_WORD), newClassHeader);
				if (((((usqInt) oop)) < (((usqInt) foo->youngStart))) && ((((usqInt) newClassOop)) >= (((usqInt) foo->youngStart)))) {
					beRootWhileForwarding(oop);
				}
			}
		l3:	/* end remapClassOf: */;
		}
	}
}


/*	Verify that every old object that points to a new object 
		has its root bit set, and
		appears in the rootTable.
	This method should not be called if the rootTable is full, because roots
	are no longer recorded, and incremental collections are not attempted.
	If DoAssertionChecks is true, this routine will halt on an unmarked root.
	Otherwise, this routine will merely return true in that case. */

sqInt validateRoots(void) {
register struct foo * foo = &fum;
    sqInt badRoot;
    usqInt fieldAddr;
    usqInt fieldOop;
    sqInt header;
    usqInt oop;
    sqInt sz;
    sqInt header1;

	badRoot = 0;
	oop = memory + (foo->headerTypeBytes[(longAt(memory)) & TypeMask]);
	while (oop < foo->youngStart) {
		if (!(((longAt(oop)) & TypeMask) == HeaderTypeFree)) {
			fieldAddr = oop + (lastPointerOf(oop));
			while (fieldAddr > oop) {
				fieldOop = longAt(fieldAddr);
				if ((fieldOop >= foo->youngStart) && (!((fieldOop & 1)))) {

					/* fieldOop is a pointer to a young object */

					header = longAt(oop);
					if ((header & (ROOT_BIT)) == 0) {
						if (DoAssertionChecks) {
							error("root bit not set");
						}
						badRoot = 1;
					} else {
						null;
					}
				}
				fieldAddr -= BYTES_PER_WORD;
			}
		}
		/* begin objectAfter: */
		if (DoAssertionChecks) {
			if ((((usqInt) oop)) >= (((usqInt) foo->endOfMemory))) {
				error("no objects after the end of memory");
			}
		}
		if (((longAt(oop)) & TypeMask) == HeaderTypeFree) {
			sz = (longAt(oop)) & (ALL_BUT_TYPE_MASK);
		} else {
			/* begin sizeBitsOf: */
			header1 = longAt(oop);
			if ((header1 & TypeMask) == HeaderTypeSizeAndClass) {
				sz = (longAt(oop - ((BYTES_PER_WORD) * 2))) & (LONG_SIZE_MASK);
				goto l1;
			} else {
				sz = header1 & (SIZE_MASK);
				goto l1;
			}
		l1:	/* end sizeBitsOf: */;
		}
		oop = (oop + sz) + (foo->headerTypeBytes[(longAt(oop + sz)) & TypeMask]);
	}
	return badRoot;
}

sqInt verifyCleanHeaders(void) {
register struct foo * foo = &fum;
    sqInt oop;
    sqInt sz;
    sqInt header;

	oop = memory + (foo->headerTypeBytes[(longAt(memory)) & TypeMask]);
	while ((((usqInt) oop)) < (((usqInt) foo->endOfMemory))) {
		if (((longAt(oop)) & TypeMask) == HeaderTypeFree) {
			if (!((objectAfter(oop)) == foo->endOfMemory)) {
				error("Invalid obj with HeaderTypeBits = Free.");
			}
		} else {
			if (!(((longAt(oop)) & (MARK_BIT)) == 0)) {
				error("Invalid obj with MarkBit set.");
			}
		}
		/* begin objectAfter: */
		if (DoAssertionChecks) {
			if ((((usqInt) oop)) >= (((usqInt) foo->endOfMemory))) {
				error("no objects after the end of memory");
			}
		}
		if (((longAt(oop)) & TypeMask) == HeaderTypeFree) {
			sz = (longAt(oop)) & (ALL_BUT_TYPE_MASK);
		} else {
			/* begin sizeBitsOf: */
			header = longAt(oop);
			if ((header & TypeMask) == HeaderTypeSizeAndClass) {
				sz = (longAt(oop - ((BYTES_PER_WORD) * 2))) & (LONG_SIZE_MASK);
				goto l1;
			} else {
				sz = header & (SIZE_MASK);
				goto l1;
			}
		l1:	/* end sizeBitsOf: */;
		}
		oop = (oop + sz) + (foo->headerTypeBytes[(longAt(oop + sz)) & TypeMask]);
	}
}


/*	return 0 for little endian, 1 for big endian */

sqInt vmEndianness(void) {
	if (isBigEnder()) {
		return 1;
	} else {
		return 0;
	}
}


/*	Return the highest priority process that is ready to run. */
/*	Note: It is a fatal VM error if there is no runnable process. */

sqInt wakeHighestPriority(void) {
register struct foo * foo = &fum;
    sqInt p;
    sqInt processList;
    sqInt schedLists;
    sqInt oop;
    sqInt sz;
    sqInt oop1;
    sqInt header;
    sqInt oop2;

	/* begin fetchPointer:ofObject: */
	/* begin fetchPointer:ofObject: */
	/* begin fetchPointer:ofObject: */
	oop2 = foo->specialObjectsOop;
	oop1 = longAt((oop2 + (BASE_HEADER_SIZE)) + (SchedulerAssociation << (SHIFT_FOR_WORD)));
	oop = longAt((oop1 + (BASE_HEADER_SIZE)) + (ValueIndex << (SHIFT_FOR_WORD)));
	schedLists = longAt((oop + (BASE_HEADER_SIZE)) + (ProcessListsIndex << (SHIFT_FOR_WORD)));
	/* begin fetchWordLengthOf: */
	/* begin sizeBitsOf: */
	header = longAt(schedLists);
	if ((header & TypeMask) == HeaderTypeSizeAndClass) {
		sz = (longAt(schedLists - ((BYTES_PER_WORD) * 2))) & (LONG_SIZE_MASK);
		goto l1;
	} else {
		sz = header & (SIZE_MASK);
		goto l1;
	}
l1:	/* end sizeBitsOf: */;
	p = ((usqInt) (sz - (BASE_HEADER_SIZE))) >> (SHIFT_FOR_WORD);

	/* index of last indexable field */

	p -= 1;
	processList = longAt((schedLists + (BASE_HEADER_SIZE)) + (p << (SHIFT_FOR_WORD)));
	while ((longAt((processList + (BASE_HEADER_SIZE)) + (FirstLinkIndex << (SHIFT_FOR_WORD)))) == foo->nilObj) {
		p -= 1;
		if (p < 0) {
			error("scheduler could not find a runnable process");
		}
		processList = longAt((schedLists + (BASE_HEADER_SIZE)) + (p << (SHIFT_FOR_WORD)));
	}
	return removeFirstLinkOfList(processList);
}


/*	Return the given 64-bit integer with its halves in the reverse order. */

sqInt wordSwapped(sqInt w) {
	
# if (BYTES_PER_WORD == 8)  // swap 32-bit ends of a 64-bit object word
	return ((((usqInt) w >> 32)) & Bytes3to0Mask) + ((((usqInt) w << 32)) & Bytes7to4Mask);
# else
	error("This cannot happen.");
# endif  // BYTES_PER_WORD == 8
	
}

sqInt writeImageFile(sqInt imageBytes) {
    void *fn;

	writeImageFileIO(imageBytes);
	fn = ioLoadFunctionFrom("setMacFileTypeAndCreator", "FilePlugin");
	if (!(fn == 0)) {
		((sqInt (*)(char*, char*, char*))fn)(imageName, "STim", "FAST");
	}
}

sqInt writeImageFileIO(sqInt imageBytes) {
register struct foo * foo = &fum;
    size_t bytesWritten;
    sqImageFile f;
    sqInt headerSize;
    squeakFileOffsetType  headerStart;
    sqInt i;
    sqInt okToWrite;
    void *sCWIfn;
    char *memoryAddress;


	/* If the security plugin can be loaded, use it to check for write permission.
	If not, assume it's ok */

	sCWIfn = ioLoadFunctionFrom("secCanWriteImage", "SecurityPlugin");
	if (sCWIfn != 0) {
		okToWrite = ((sqInt (*)(void))sCWIfn)();
		if (!(okToWrite)) {
			/* begin primitiveFail */
			foo->successFlag = 0;
			return null;
		}
	}
	headerStart = 0;

	/* header size in bytes; do not change! */

	headerSize = 16 * (BYTES_PER_WORD);
	f = sqImageFileOpen(imageName, "wb");
	if (f == null) {
		/* begin success: */
		foo->successFlag = 0 && foo->successFlag;
		return null;
	}
	headerStart = sqImageFileStartLocation(f,imageName,headerSize+imageBytes);
	/* Note: on Unix systems one could put an exec command here, padded to 512 bytes */;
	sqImageFileSeek(f, headerStart);
	putLongtoFile(imageFormatVersionNumber, f);
	putLongtoFile(headerSize, f);
	putLongtoFile(imageBytes, f);
	putLongtoFile(memory, f);
	putLongtoFile(foo->specialObjectsOop, f);
	putLongtoFile(foo->lastHash, f);
	putLongtoFile(ioScreenSize(), f);
	putLongtoFile(foo->fullScreenFlag, f);
	putLongtoFile(extraVMMemory, f);
	for (i = 1; i <= 7; i += 1) {
		putLongtoFile(0, f);
	}
	if (!(foo->successFlag)) {
		sqImageFileClose(f);
		return null;
	}
	sqImageFileSeek(f, headerStart + headerSize);
	/* begin sqImage:write:size:length: */
	memoryAddress = pointerForOop(memory);
	bytesWritten = sqImageFileWrite(memoryAddress, sizeof(unsigned char), imageBytes, f);
	/* begin success: */
	foo->successFlag = (bytesWritten == imageBytes) && foo->successFlag;
	sqImageFileClose(f);
}


void* vm_exports[][3] = {
	{"", "primitiveLessOrEqualLargeIntegers", (void*)primitiveLessOrEqualLargeIntegers},
	{"", "primitiveLessThanLargeIntegers", (void*)primitiveLessThanLargeIntegers},
	{"", "internalIsMutable", (void*)internalIsMutable},
	{"", "primitiveGreaterOrEqualLargeIntegers", (void*)primitiveGreaterOrEqualLargeIntegers},
	{"", "primitiveDisablePowerManager", (void*)primitiveDisablePowerManager},
	{"", "primitiveRootTable", (void*)primitiveRootTable},
	{"", "primitiveImageFormatVersion", (void*)primitiveImageFormatVersion},
	{"", "dumpImage", (void*)dumpImage},
	{"", "callInterpreter", (void*)callInterpreter},
	{"", "primitiveDivLargeIntegers", (void*)primitiveDivLargeIntegers},
	{"", "sendInvokeCallbackStackRegistersJmpbuf", (void*)sendInvokeCallbackStackRegistersJmpbuf},
	{"", "removeGCRoot", (void*)removeGCRoot},
	{"", "primitiveDivideLargeIntegers", (void*)primitiveDivideLargeIntegers},
	{"", "internalIsImmutable", (void*)internalIsImmutable},
	{"", "primitiveQuoLargeIntegers", (void*)primitiveQuoLargeIntegers},
	{"", "readImageFormatFromFileStartingAt", (void*)readImageFormatFromFileStartingAt},
	{"", "primitiveAddLargeIntegers", (void*)primitiveAddLargeIntegers},
	{"", "primitiveSubtractLargeIntegers", (void*)primitiveSubtractLargeIntegers},
	{"", "primitiveMicrosecondClock", (void*)primitiveMicrosecondClock},
	{"", "primitiveSetGCBiasToGrow", (void*)primitiveSetGCBiasToGrow},
	{"", "primitiveScreenDepth", (void*)primitiveScreenDepth},
	{"", "primitiveForceTenure", (void*)primitiveForceTenure},
	{"", "primitiveMultiplyLargeIntegers", (void*)primitiveMultiplyLargeIntegers},
	{"", "primitiveIsRoot", (void*)primitiveIsRoot},
	{"", "moduleUnloaded", (void*)moduleUnloaded},
	{"", "primitiveRootTableAt", (void*)primitiveRootTableAt},
	{"", "addGCRoot", (void*)addGCRoot},
	{"", "getStackPointer", (void*)getStackPointer},
	{"", "primitiveNotEqualLargeIntegers", (void*)primitiveNotEqualLargeIntegers},
	{"", "callbackEnter", (void*)callbackEnter},
	{"", "extraHeaderBytes", (void*)extraHeaderBytes},
	{"", "primitiveVMVersion", (void*)primitiveVMVersion},
	{"", "primitiveBitOrLargeIntegers", (void*)primitiveBitOrLargeIntegers},
	{"", "primitiveBitXorLargeIntegers", (void*)primitiveBitXorLargeIntegers},
	{"", "reestablishContextPriorToCallback", (void*)reestablishContextPriorToCallback},
	{"", "primitiveBitShiftLargeIntegers", (void*)primitiveBitShiftLargeIntegers},
	{"", "primitiveSetGCSemaphore", (void*)primitiveSetGCSemaphore},
	{"", "primitivePlatformSourceVersion", (void*)primitivePlatformSourceVersion},
	{"", "primitiveSetGCBiasToGrowGCLimit", (void*)primitiveSetGCBiasToGrowGCLimit},
	{"", "primitiveChangeClassWithClass", (void*)primitiveChangeClassWithClass},
	{"", "primitiveUtcWithOffset", (void*)primitiveUtcWithOffset},
	{"", "primitiveBitAndLargeIntegers", (void*)primitiveBitAndLargeIntegers},
	{"", "primitiveInterpreterSourceVersion", (void*)primitiveInterpreterSourceVersion},
	{"", "callbackLeave", (void*)callbackLeave},
	{"", "primitiveEqualLargeIntegers", (void*)primitiveEqualLargeIntegers},
	{"", "primitiveModLargeIntegers", (void*)primitiveModLargeIntegers},
	{"", "primitiveGreaterThanLargeIntegers", (void*)primitiveGreaterThanLargeIntegers},
	{"", "primitiveIsYoung", (void*)primitiveIsYoung},
	{"", "printAllStacks", (void*)printAllStacks},
	{NULL, NULL, NULL}
};
