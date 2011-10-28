'From Squeak4.1 of 17 April 2010 [latest update: #9957] on 28 October 2011 at 12:12:34 am'!Smalltalk renameClassNamed: #NativeClientBridge as: #PepperPlugin!InterpreterPlugin subclass: #PepperPlugin	instanceVariableNames: ''	classVariableNames: ''	poolDictionaries: ''	category: 'NativeClientBridge-Plugin'!!PepperPlugin methodsFor: 'as yet unclassified' stamp: 'yo 10/27/2011 23:49'!postMessage	| sqStr sqOop stSize |	self export: true.	self inline: true.	self var: 'sqStr' declareC: 'char *sqStr'.	sqOop := interpreterProxy stackObjectValue: 0.	(interpreterProxy isBytes: sqOop) ifFalse: [		interpreterProxy primitiveFail.		^ nil].	sqStr := interpreterProxy firstIndexableField: sqOop.	stSize := interpreterProxy stSizeOf: sqOop.	self cCode: 'send_from_sq_to_browser(sqStr, stSize)'.! !!String methodsFor: '*NativeClientBridge' stamp: 'yo 10/27/2011 23:45'!postMessage	<primitive: 'postMessage' module: 'PepperPlugin'>	self primitiveFailed.! !!String reorganize!('accessing' byteAt: byteAt:put: byteSize do:toFieldNumber: endsWithDigit findAnySubStr:startingAt: findBetweenSubStrs: findCloseParenthesisFor: findDelimiters:startingAt: findLastOccurrenceOfString:startingAt: findString: findString:startingAt: findString:startingAt:caseSensitive: findTokens: findTokens:escapedBy: findTokens:includes: findTokens:keep: findWordStart:startingAt: includesSubString: includesSubstring:caseSensitive: indexOf: indexOf:startingAt: indexOf:startingAt:ifAbsent: indexOfSubCollection: indexOfSubCollection:startingAt:ifAbsent: lastIndexOfPKSignature: leadingCharRunLengthAt: lineCorrespondingToIndex: lineCount lineIndicesDo: lineNumber: linesDo: skipAnySubStr:startingAt: skipDelimiters:startingAt: startsWithDigit string tabDelimitedFieldsDo:)('arithmetic' * + - / // \\)('comparing' < <= = > >= alike: caseInsensitiveLessOrEqual: caseSensitiveLessOrEqual: charactersExactlyMatching: compare: compare:caseSensitive: compare:with:collated: crc16 endsWith: endsWithAnyOf: hash hashMappedBy: hashWithInitialHash: howManyMatch: match: sameAs: startingAt:match:startingAt:)('converting' , adaptToCollection:andSend: adaptToNumber:andSend: adaptToPoint:andSend: adaptToString:andSend: asAlphaNumeric:extraChars:mergeUID: asByteArray asByteString asCharacter asDate asDateAndTime asDecomposedUnicode asDisplayText asDuration asFileName asFourCode asHex asHtml asIdentifier: asInteger asLegalSelector asLowercase asNumber asOctetString asPacked asPluralBasedOn: asPrecomposedUnicode asSignedInteger asSmalltalkComment asSqueakPathName asString asStringOrText asSymbol asText asTime asTimeStamp asUnHtml asUnsignedInteger asUppercase asUrl asUrlRelativeTo: asVmPathName askIfAddStyle:req: asWideString base64Decoded base64Encoded capitalized compressWithTable: contractTo: convertFromEncoding: convertFromSuperSwikiServerString convertFromWithConverter: convertToEncoding: convertToSuperSwikiServerString convertToSystemString convertToWithConverter: correctAgainst: correctAgainst:continuedFrom: correctAgainstDictionary:continuedFrom: encodeForHTTP encodeForHTTPWithTextEncoding: encodeForHTTPWithTextEncoding:conditionBlock: findSelector initialIntegerOrNil keywords numericSuffix onlyLetters romanNumber sansPeriodSuffix splitInteger squeakToUtf8 stemAndNumericSuffix subStrings subStrings: substrings surroundedBySingleQuotes translateFrom:to:table: translateToLowercase translateToUppercase translateWith: truncateTo: truncateWithElipsisTo: unescapePercents unescapePercentsWithTextEncoding: unparenthetically unzipped utf8ToSqueak withBlanksCondensed withBlanksTrimmed withFirstCharacterDownshifted withNoLineLongerThan: withoutJustTrailingDigits withoutLeadingBlanks withSeparatorsCompacted withoutLeadingDigits withoutTrailingBlanks withoutTrailingDigits zipped)('copying' copyReplaceTokens:with: deepCopy padded:to:with:)('displaying' displayAt: displayOn: displayOn:at: displayOn:at:textColor: displayProgressAt:from:to:during:)('encoding' getInteger32: putInteger32:at: writeLeadingCharRunsOn:)('filter streaming' byteEncode: putOn:)('formatting' expandMacros expandMacrosWithArguments: expandMacrosWith: expandMacrosWith:with: expandMacrosWith:with:with: expandMacrosWith:with:with:with: format: withCRs)('internet' decodeMimeHeader decodeQuotedPrintable isoToSqueak isoToUtf8 macToSqueak squeakToIso squeakToMac utf8ToIso withInternetLineEndings withSqueakLineEndings withUnixLineEndings withoutQuoting)('paragraph support' indentationIfBlank:)('printing' encodeDoublingQuoteOn: isLiteral printOn: storeOn: stringRepresentation)('system primitives' endsWithAColon findSubstring:in:startingAt:matchTable: numArgs)('testing' includesUnifiedCharacter isAllDigits isAllSeparators isAsciiString isByteString isOctetString isString isWideString lastSpacePosition)('translating' translated translatedIfCorresponds translatedTo:)('user interface' asExplorerString openInWorkspaceWithTitle:)('*Morphic' asMorph asStringMorph)('*MorphicExtras-*morphic-Postscript Canvases' asPostscript)('*Morphic-converting' openAsMorph)('*monticello' extractNumber)('*network-uri' asURI)('*packageinfo-base' escapeEntities)('*services-base' service serviceOrNil)('*versionnumber' asVersion)('private' correctAgainstEnumerator:continuedFrom: evaluateExpression:parameters: replaceFrom:to:with:startingAt: stringhash)('*universes-model' uversionEqual: uversionLessThan:)('*Universes' asUVersion)('*Morphic-Explorer' hasContentsInExplorer)('deprecated-3.10' findLastOccuranceOfString:startingAt:)('*xml-parser' applyLanguageInfomation:)('*ST80-Support' asParagraph)('*system' suggestedTypeNames)('*Etoys-tiles' basicType newTileMorphRepresentative)('*VMMaker-Translation to C' replaceLastOccurrence:with:)('*Rome-PluginCanvas' asUTF8String)('*NativeClientBridge' postMessage)!