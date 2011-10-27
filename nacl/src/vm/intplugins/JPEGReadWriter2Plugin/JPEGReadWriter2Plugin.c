/* Automatically generated from Squeak on 26 October 2011 5:13:58 pm 
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
#include "JPEGReadWriter2Plugin.h"

#include "sqMemoryAccess.h"


/*** Constants ***/

/*** Function Prototypes ***/
static VirtualMachine * getInterpreter(void);
#pragma export on
EXPORT(const char*) getModuleName(void);
#pragma export off
static sqInt halt(void);
#pragma export on
EXPORT(sqInt) initialiseModule(void);
#pragma export off
static sqInt msg(char *s);
#pragma export on
EXPORT(sqInt) primImageHeight(void);
EXPORT(sqInt) primImageWidth(void);
EXPORT(sqInt) primJPEGCompressStructSize(void);
EXPORT(sqInt) primJPEGDecompressStructSize(void);
EXPORT(sqInt) primJPEGErrorMgr2StructSize(void);
EXPORT(sqInt) primJPEGPluginIsPresent(void);
EXPORT(sqInt) primJPEGReadHeaderfromByteArrayerrorMgr(void);
EXPORT(sqInt) primJPEGReadImagefromByteArrayonFormdoDitheringerrorMgr(void);
EXPORT(sqInt) primJPEGWriteImageonByteArrayformqualityprogressiveJPEGerrorMgr(void);
EXPORT(sqInt) setInterpreter(struct VirtualMachine*anInterpreter);
EXPORT(sqInt) shutdownModule(void);
#pragma export off
static sqInt sqAssert(sqInt aBool);
/*** Variables ***/

#ifdef SQUEAK_BUILTIN_PLUGIN
extern
#endif
struct VirtualMachine* interpreterProxy;
static const char *moduleName =
#ifdef SQUEAK_BUILTIN_PLUGIN
	"JPEGReadWriter2Plugin 26 October 2011 (i)"
#else
	"JPEGReadWriter2Plugin 26 October 2011 (e)"
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

EXPORT(sqInt) initialiseModule(void) {
	return 1;
}

static sqInt msg(char *s) {
	fprintf(stderr, "\n%s: %s", moduleName, s);
}

EXPORT(sqInt) primImageHeight(void) {
	char *aJPEGDecompressStruct;
	sqInt _return_value;

	interpreterProxy->success(interpreterProxy->isBytes(interpreterProxy->stackValue(0)));
	aJPEGDecompressStruct = ((char *) (interpreterProxy->firstIndexableField(interpreterProxy->stackValue(0))));
	if (interpreterProxy->failed()) {
		return null;
	}
	
		interpreterProxy->success
			((interpreterProxy->stSizeOf(interpreterProxy->stackValue(0))) >= (sizeof(struct jpeg_decompress_struct))); 
		if (interpreterProxy->failed()) return null;
	;
	_return_value = interpreterProxy->integerObjectOf((((j_decompress_ptr)aJPEGDecompressStruct)->image_height));
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->popthenPush(2, _return_value);
	return null;
}

EXPORT(sqInt) primImageWidth(void) {
	char *aJPEGDecompressStruct;
	sqInt _return_value;

	interpreterProxy->success(interpreterProxy->isBytes(interpreterProxy->stackValue(0)));
	aJPEGDecompressStruct = ((char *) (interpreterProxy->firstIndexableField(interpreterProxy->stackValue(0))));
	if (interpreterProxy->failed()) {
		return null;
	}
	
		interpreterProxy->success
			((interpreterProxy->stSizeOf(interpreterProxy->stackValue(0))) >= (sizeof(struct jpeg_decompress_struct))); 
		if (interpreterProxy->failed()) return null;
	;
	_return_value = interpreterProxy->integerObjectOf((((j_decompress_ptr)aJPEGDecompressStruct)->image_width));
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->popthenPush(2, _return_value);
	return null;
}

EXPORT(sqInt) primJPEGCompressStructSize(void) {
	sqInt _return_value;

	_return_value = interpreterProxy->integerObjectOf((sizeof(struct jpeg_compress_struct)));
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->popthenPush(1, _return_value);
	return null;
}

EXPORT(sqInt) primJPEGDecompressStructSize(void) {
	sqInt _return_value;

	_return_value = interpreterProxy->integerObjectOf((sizeof(struct jpeg_decompress_struct)));
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->popthenPush(1, _return_value);
	return null;
}

EXPORT(sqInt) primJPEGErrorMgr2StructSize(void) {
	sqInt _return_value;

	_return_value = interpreterProxy->integerObjectOf((sizeof(struct error_mgr2)));
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->popthenPush(1, _return_value);
	return null;
}

EXPORT(sqInt) primJPEGPluginIsPresent(void) {
	sqInt _return_value;

	_return_value = (1? interpreterProxy->trueObject(): interpreterProxy->falseObject());
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->popthenPush(1, _return_value);
	return null;
}

EXPORT(sqInt) primJPEGReadHeaderfromByteArrayerrorMgr(void) {
	sqInt sourceSize;
	j_decompress_ptr  pcinfo;
	error_ptr2  pjerr;
	char *aJPEGDecompressStruct;
	char *source;
	char *aJPEGErrorMgr2Struct;

	interpreterProxy->success(interpreterProxy->isBytes(interpreterProxy->stackValue(2)));
	aJPEGDecompressStruct = ((char *) (interpreterProxy->firstIndexableField(interpreterProxy->stackValue(2))));
	interpreterProxy->success(interpreterProxy->isBytes(interpreterProxy->stackValue(1)));
	source = ((char *) (interpreterProxy->firstIndexableField(interpreterProxy->stackValue(1))));
	interpreterProxy->success(interpreterProxy->isBytes(interpreterProxy->stackValue(0)));
	aJPEGErrorMgr2Struct = ((char *) (interpreterProxy->firstIndexableField(interpreterProxy->stackValue(0))));
	if (interpreterProxy->failed()) {
		return null;
	}
	pcinfo = null;
	pjerr = null;
	sourceSize = null;
	pcinfo;
	pjerr;
	sourceSize;
	
		interpreterProxy->success
			((interpreterProxy->stSizeOf(interpreterProxy->stackValue(2))) >= (sizeof(struct jpeg_decompress_struct)));
		interpreterProxy->success
			((interpreterProxy->stSizeOf(interpreterProxy->stackValue(0))) >= (sizeof(struct error_mgr2))); 
		if (interpreterProxy->failed()) return null;
	;
	
		sourceSize = interpreterProxy->stSizeOf(interpreterProxy->stackValue(1));
		pcinfo = (j_decompress_ptr)aJPEGDecompressStruct;
		pjerr = (error_ptr2)aJPEGErrorMgr2Struct;
		if (sourceSize) {
			pcinfo->err = jpeg_std_error(&pjerr->pub);
			pjerr->pub.error_exit = error_exit;
			if (setjmp(pjerr->setjmp_buffer)) {
				jpeg_destroy_decompress(pcinfo);
				sourceSize = 0;
			}
			if (sourceSize) {
				jpeg_create_decompress(pcinfo);
				jpeg_mem_src(pcinfo, source, sourceSize);
				jpeg_read_header(pcinfo, TRUE);
			}
		}
	;
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->pop(3);
	return null;
}

EXPORT(sqInt) primJPEGReadImagefromByteArrayonFormdoDitheringerrorMgr(void) {
	unsigned *  formBits;
	sqInt ok;
	sqInt g1;
	sqInt gOff;
	error_ptr2  pjerr;
	sqInt bOff2;
	sqInt formWidth;
	sqInt formDepth;
	sqInt dmv1;
	sqInt formPix;
	sqInt dmo;
	sqInt formBitsOops;
	sqInt r2;
	sqInt dmi;
	sqInt r1;
	sqInt gOff2;
	sqInt j;
	sqInt formPitch;
	sqInt i;
	sqInt b2;
	sqInt rowStride;
	sqInt b1;
	sqInt formBitsSize;
	sqInt di;
	sqInt dmv2;
	sqInt rOff;
	JSAMPARRAY  buffer;
	sqInt pixPerWord;
	j_decompress_ptr  pcinfo;
	sqInt g2;
	sqInt bOff;
	sqInt sourceSize;
	sqInt rOff2;
	sqInt formHeight;
	char *aJPEGDecompressStruct;
	char *source;
	sqInt form;
	sqInt ditherFlag;
	char *aJPEGErrorMgr2Struct;

	interpreterProxy->success(interpreterProxy->isBytes(interpreterProxy->stackValue(4)));
	aJPEGDecompressStruct = ((char *) (interpreterProxy->firstIndexableField(interpreterProxy->stackValue(4))));
	interpreterProxy->success(interpreterProxy->isBytes(interpreterProxy->stackValue(3)));
	source = ((char *) (interpreterProxy->firstIndexableField(interpreterProxy->stackValue(3))));
	interpreterProxy->success(interpreterProxy->isKindOf(interpreterProxy->stackValue(2), "Form"));
	form = interpreterProxy->stackValue(2);
	ditherFlag = interpreterProxy->booleanValueOf(interpreterProxy->stackValue(1));
	interpreterProxy->success(interpreterProxy->isBytes(interpreterProxy->stackValue(0)));
	aJPEGErrorMgr2Struct = ((char *) (interpreterProxy->firstIndexableField(interpreterProxy->stackValue(0))));
	if (interpreterProxy->failed()) {
		return null;
	}
	pcinfo = null;
	pjerr = null;
	buffer = null;
	rowStride = null;
	formDepth = null;
	formBits = null;
	i = null;
	j = null;
	formPix = null;
	ok = null;
	rOff = null;
	gOff = null;
	bOff = null;
	rOff2 = null;
	gOff2 = null;
	bOff2 = null;
	sourceSize = null;
	r1 = null;
	r2 = null;
	g1 = null;
	g2 = null;
	b1 = null;
	b2 = null;
	dmv1 = null;
	dmv2 = null;
	di = null;
	dmi = null;
	dmo = null;
	pcinfo;
	pjerr;
	buffer;
	rowStride;
	formBits;
	formDepth;
	i;
	j;
	formPix;
	ok;
	rOff;
	gOff;
	bOff;
	rOff2;
	gOff2;
	bOff2;
	sourceSize;
	r1;
	r2;
	g1;
	g2;
	b1;
	b2;
	dmv1;
	dmv2;
	di;
	dmi;
	dmo;
	formBitsOops = interpreterProxy->fetchPointerofObject(0, form);

	/* Various parameter checks */

	formDepth = interpreterProxy->fetchIntegerofObject(3, form);
	
		interpreterProxy->success
			((interpreterProxy->stSizeOf(interpreterProxy->stackValue(4))) >= (sizeof(struct jpeg_decompress_struct)));
		interpreterProxy->success
			((interpreterProxy->stSizeOf(interpreterProxy->stackValue(0))) >= (sizeof(struct error_mgr2))); 
		if (interpreterProxy->failed()) return null;
	;
	formWidth = ((j_decompress_ptr)aJPEGDecompressStruct)->image_width;
	formHeight = ((j_decompress_ptr)aJPEGDecompressStruct)->image_height;
	pixPerWord = 32 / formDepth;
	formPitch = ((formWidth + (pixPerWord - 1)) / pixPerWord) * 4;
	formBitsSize = interpreterProxy->byteSizeOf(formBitsOops);
	interpreterProxy->success((interpreterProxy->isWordsOrBytes(formBitsOops)) && (formBitsSize == (formPitch * formHeight)));
	if (interpreterProxy->failed()) {
		return null;
	}
	formBits = interpreterProxy->firstIndexableField(formBitsOops);
	
		sourceSize = interpreterProxy->stSizeOf(interpreterProxy->stackValue(3));
		if (sourceSize == 0) {
			interpreterProxy->success(false);
			return null;
		}
		pcinfo = (j_decompress_ptr)aJPEGDecompressStruct;
		pjerr = (error_ptr2)aJPEGErrorMgr2Struct;
		pcinfo->err = jpeg_std_error(&pjerr->pub);
		pjerr->pub.error_exit = error_exit;
		ok = 1;
		if (setjmp(pjerr->setjmp_buffer)) {
			jpeg_destroy_decompress(pcinfo);
			ok = 0;
		}
		if (ok) {
			ok = jpeg_mem_src_newLocationOfData(pcinfo, source, sourceSize);
			if (ok) {
				/* Dither Matrix taken from Form>>orderedDither32To16, but rewritten for this method. */
				int ditherMatrix1[] = { 2, 0, 14, 12, 1, 3, 13, 15 };
				int ditherMatrix2[] = { 10, 8, 6, 4, 9, 11, 5, 7 };
 				jpeg_start_decompress(pcinfo);
				rowStride = pcinfo->output_width * pcinfo->output_components;
				if (pcinfo->out_color_components == 3) {
					rOff = 0; gOff = 1; bOff = 2;
					rOff2 = 3; gOff2 = 4; bOff2 = 5;
				} else {
					rOff = 0; gOff = 0; bOff = 0;
					rOff2 = 1; gOff2 = 1; bOff2 = 1;
				}
				/* Make a one-row-high sample array that will go away when done with image */
				buffer = (*(pcinfo->mem)->alloc_sarray)
					((j_common_ptr) pcinfo, JPOOL_IMAGE, rowStride, 1);

				/* Step 6: while (scan lines remain to be read) */
				/*           jpeg_read_scanlines(...); */

				/* Here we use the library state variable cinfo.output_scanline as the
				 * loop counter, so that we dont have to keep track ourselves.
				 */
				while (pcinfo->output_scanline < pcinfo->output_height) {
					/* jpeg_read_scanlines expects an array of pointers to scanlines.
					 * Here the array is only one element long, but you could ask for
					 * more than one scanline at a time if thats more convenient.
					 */
					(void) jpeg_read_scanlines(pcinfo, buffer, 1);

					switch (formDepth) {
						case 32:
							for(i = 0, j = 0; i < rowStride; i +=(pcinfo->out_color_components), j++) {
								formPix = (255 << 24) | (buffer[0][i+rOff] << 16) | (buffer[0][i+gOff] << 8) | buffer[0][i+bOff];
								if (formPix == 0) formPix = 1;
								formBits [ ((pcinfo->output_scanline - 1) * (pcinfo->image_width)) + j ] = formPix;
							}
							break;

						case 16:
							for(i = 0, j = 0; i < rowStride; i +=(pcinfo->out_color_components*2), j++) {
								r1 = buffer[0][i+rOff];
								r2 = buffer[0][i+rOff2];
								g1 = buffer[0][i+gOff];
								g2 = buffer[0][i+gOff2];
								b1 = buffer[0][i+bOff];
								b2 = buffer[0][i+bOff2];

								if (!ditherFlag) {
									r1 = r1 >> 3;
									r2 = r2 >> 3;
									g1 = g1 >> 3;
									g2 = g2 >> 3;
									b1 = b1 >> 3;
									b2 = b2 >> 3;
								} else {
									/* Do 4x4 ordered dithering. Taken from Form>>orderedDither32To16 */
									dmv1 = ditherMatrix1[ ((pcinfo->output_scanline & 3 )<< 1) | (j&1) ];
									dmv2 = ditherMatrix2[ ((pcinfo->output_scanline & 3 )<< 1) | (j&1) ];

									di = (r1 * 496) >> 8; dmi = di & 15; dmo = di >> 4;
									if(dmv1 < dmi) { r1 = dmo+1; } else { r1 = dmo; };
									di = (g1 * 496) >> 8; dmi = di & 15; dmo = di >> 4;
									if(dmv1 < dmi) { g1 = dmo+1; } else { g1 = dmo; };
									di = (b1 * 496) >> 8; dmi = di & 15; dmo = di >> 4;
									if(dmv1 < dmi) { b1 = dmo+1; } else { b1 = dmo; };

									di = (r2 * 496) >> 8; dmi = di & 15; dmo = di >> 4;
									if(dmv2 < dmi) { r2 = dmo+1; } else { r2 = dmo; };
									di = (g2 * 496) >> 8; dmi = di & 15; dmo = di >> 4;
									if(dmv2 < dmi) { g2 = dmo+1; } else { g2 = dmo; };
									di = (b2 * 496) >> 8; dmi = di & 15; dmo = di >> 4;
									if(dmv2 < dmi) { b2 = dmo+1; } else { b2 = dmo; };
								}

								formPix = (r1 << 10) | (g1 << 5) | b1;
								if (!formPix) formPix = 1;
								formPix = (formPix << 16) | (r2 << 10) | (g2 << 5) | b2;
								if (!(formPix & 65535)) formPix = formPix | 1;
								formBits [ ((pcinfo->output_scanline - 1) * (pcinfo->image_width)) / 2 + j ] = formPix;
							}
							break;
					}
				}
				jpeg_finish_decompress(pcinfo);
			}
			jpeg_destroy_decompress(pcinfo);
		}
	;
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->pop(5);
	return null;
}

EXPORT(sqInt) primJPEGWriteImageonByteArrayformqualityprogressiveJPEGerrorMgr(void) {
	sqInt formWidth;
	sqInt j;
	unsigned int destinationSize;
	sqInt i;
	sqInt formPix;
	sqInt formDepth;
	error_ptr2  pjerr;
	sqInt formPitch;
	sqInt rowStride;
	sqInt formBitsSize;
	sqInt formBitsOops;
	sqInt formHeight;
	unsigned *  formBits;
	sqInt pixPerWord;
	j_compress_ptr  pcinfo;
	JSAMPARRAY  buffer;
	char *aJPEGCompressStruct;
	char *destination;
	sqInt form;
	sqInt quality;
	sqInt progressiveFlag;
	char *aJPEGErrorMgr2Struct;
	sqInt _return_value;

	interpreterProxy->success(interpreterProxy->isBytes(interpreterProxy->stackValue(5)));
	aJPEGCompressStruct = ((char *) (interpreterProxy->firstIndexableField(interpreterProxy->stackValue(5))));
	interpreterProxy->success(interpreterProxy->isBytes(interpreterProxy->stackValue(4)));
	destination = ((char *) (interpreterProxy->firstIndexableField(interpreterProxy->stackValue(4))));
	interpreterProxy->success(interpreterProxy->isKindOf(interpreterProxy->stackValue(3), "Form"));
	form = interpreterProxy->stackValue(3);
	quality = interpreterProxy->stackIntegerValue(2);
	progressiveFlag = interpreterProxy->booleanValueOf(interpreterProxy->stackValue(1));
	interpreterProxy->success(interpreterProxy->isBytes(interpreterProxy->stackValue(0)));
	aJPEGErrorMgr2Struct = ((char *) (interpreterProxy->firstIndexableField(interpreterProxy->stackValue(0))));
	if (interpreterProxy->failed()) {
		return null;
	}
	pcinfo = null;
	pjerr = null;
	buffer = null;
	rowStride = null;
	formBits = null;
	formWidth = null;
	formHeight = null;
	formDepth = null;
	i = null;
	j = null;
	formPix = null;
	destinationSize = null;
	pcinfo;
	pjerr;
	buffer;
	rowStride;
	formBits;
	formWidth;
	formHeight;
	formDepth;
	i;
	j;
	formPix;
	destinationSize;
	formBitsOops = interpreterProxy->fetchPointerofObject(0, form);
	formWidth = interpreterProxy->fetchIntegerofObject(1, form);
	formHeight = interpreterProxy->fetchIntegerofObject(2, form);

	/* Various parameter checks */

	formDepth = interpreterProxy->fetchIntegerofObject(3, form);
	
		interpreterProxy->success
			((interpreterProxy->stSizeOf(interpreterProxy->stackValue(5))) >= (sizeof(struct jpeg_compress_struct)));
		interpreterProxy->success
			((interpreterProxy->stSizeOf(interpreterProxy->stackValue(0))) >= (sizeof(struct error_mgr2))); 
		if (interpreterProxy->failed()) return null;
	;
	pixPerWord = 32 / formDepth;
	formPitch = ((formWidth + (pixPerWord - 1)) / pixPerWord) * 4;
	formBitsSize = interpreterProxy->byteSizeOf(formBitsOops);
	interpreterProxy->success((interpreterProxy->isWordsOrBytes(formBitsOops)) && (formBitsSize == (formPitch * formHeight)));
	if (interpreterProxy->failed()) {
		return null;
	}
	formBits = interpreterProxy->firstIndexableField(formBitsOops);
	
		destinationSize = interpreterProxy->stSizeOf(interpreterProxy->stackValue(4));
		pcinfo = (j_compress_ptr)aJPEGCompressStruct;
		pjerr = (error_ptr2)aJPEGErrorMgr2Struct;
		if (destinationSize) {
			pcinfo->err = jpeg_std_error(&pjerr->pub);
			pjerr->pub.error_exit = error_exit;
			if (setjmp(pjerr->setjmp_buffer)) {
				jpeg_destroy_compress(pcinfo);
				destinationSize = 0;
			}
			if (destinationSize) {
				jpeg_create_compress(pcinfo);
				jpeg_mem_dest(pcinfo, destination, &destinationSize);
				pcinfo->image_width = formWidth;
				pcinfo->image_height = formHeight;
				pcinfo->input_components = 3;
				pcinfo->in_color_space = JCS_RGB;
				jpeg_set_defaults(pcinfo);
				if (quality > 0)
					jpeg_set_quality (pcinfo, quality, 1);
				if (progressiveFlag)
					jpeg_simple_progression(pcinfo);
				jpeg_start_compress(pcinfo, TRUE);
				rowStride = formWidth * 3;

				/* Make a one-row-high sample array that will go away 
				  when done with image */
				buffer = (*(pcinfo->mem)->alloc_sarray)
					((j_common_ptr) pcinfo, JPOOL_IMAGE, rowStride, 1);

				while (pcinfo->next_scanline < pcinfo->image_height) {
					switch (formDepth) {
						case 32:
							for(i = 0, j = 0; i < rowStride; i +=3, j++) {
								formPix = formBits [ ((pcinfo->next_scanline) * formWidth) + j ];
								buffer[0][i] = (formPix >> 16) & 255;
								buffer[0][i+1] = (formPix >> 8) & 255;
								buffer[0][i+2] = formPix & 255;
							}
							break;
						case 16:
							for(i = 0, j = 0; i < rowStride; i +=6, j++) {
								formPix = formBits [ ((pcinfo->next_scanline) * formWidth) / 2 + j ];
								buffer[0][i] = (formPix >> 23) & 248;
								buffer[0][i+1] = (formPix >> 18) & 248;
								buffer[0][i+2] = (formPix >> 13) & 248;
								buffer[0][i+3] = (formPix >> 7) & 248;
								buffer[0][i+4] = (formPix >> 2) & 248;
								buffer[0][i+5] = (formPix << 3) & 248;
							}
							break;
					}
					(void) jpeg_write_scanlines(pcinfo, buffer, 1);

				}
				jpeg_finish_compress(pcinfo);
				jpeg_destroy_compress(pcinfo);
			}
		}
	;
	_return_value = interpreterProxy->integerObjectOf((destinationSize));
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->popthenPush(7, _return_value);
	return null;
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

EXPORT(sqInt) shutdownModule(void) {
	return 1;
}

static sqInt sqAssert(sqInt aBool) {
	/* missing DebugCode */;
}


#ifdef SQUEAK_BUILTIN_PLUGIN


void* JPEGReadWriter2Plugin_exports[][3] = {
	{"JPEGReadWriter2Plugin", "primImageWidth", (void*)primImageWidth},
	{"JPEGReadWriter2Plugin", "getModuleName", (void*)getModuleName},
	{"JPEGReadWriter2Plugin", "primJPEGWriteImageonByteArrayformqualityprogressiveJPEGerrorMgr", (void*)primJPEGWriteImageonByteArrayformqualityprogressiveJPEGerrorMgr},
	{"JPEGReadWriter2Plugin", "primJPEGErrorMgr2StructSize", (void*)primJPEGErrorMgr2StructSize},
	{"JPEGReadWriter2Plugin", "primJPEGCompressStructSize", (void*)primJPEGCompressStructSize},
	{"JPEGReadWriter2Plugin", "setInterpreter", (void*)setInterpreter},
	{"JPEGReadWriter2Plugin", "primJPEGReadImagefromByteArrayonFormdoDitheringerrorMgr", (void*)primJPEGReadImagefromByteArrayonFormdoDitheringerrorMgr},
	{"JPEGReadWriter2Plugin", "primImageHeight", (void*)primImageHeight},
	{"JPEGReadWriter2Plugin", "primJPEGReadHeaderfromByteArrayerrorMgr", (void*)primJPEGReadHeaderfromByteArrayerrorMgr},
	{"JPEGReadWriter2Plugin", "shutdownModule", (void*)shutdownModule},
	{"JPEGReadWriter2Plugin", "primJPEGPluginIsPresent", (void*)primJPEGPluginIsPresent},
	{"JPEGReadWriter2Plugin", "initialiseModule", (void*)initialiseModule},
	{"JPEGReadWriter2Plugin", "primJPEGDecompressStructSize", (void*)primJPEGDecompressStructSize},
	{NULL, NULL, NULL}
};


#endif /* ifdef SQ_BUILTIN_PLUGIN */

