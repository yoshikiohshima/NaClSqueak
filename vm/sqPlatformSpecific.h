/* sqPlatformSpecific.h -- platform-specific modifications to sq.h
 * 
 *   Copyright (C) 1996-2005 by Ian Piumarta and other authors/contributors
 *                              listed elsewhere in this file.
 *   All rights reserved.
 *   
 *   This file is part of Unix Squeak.
 * 
 *   Permission is hereby granted, free of charge, to any person obtaining a copy
 *   of this software and associated documentation files (the "Software"), to deal
 *   in the Software without restriction, including without limitation the rights
 *   to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 *   copies of the Software, and to permit persons to whom the Software is
 *   furnished to do so, subject to the following conditions:
 * 
 *   The above copyright notice and this permission notice shall be included in
 *   all copies or substantial portions of the Software.
 * 
 *   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *   IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *   FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 *   AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 *   LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 *   OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 *   SOFTWARE.
 * 
 * Author: ian.piumarta@squeakland.org
 * 
 * Last edited: 2006-10-18 10:06:13 by piumarta on emilia.local
 */

/* undefine clock macros (these are implemented as functions) */

#undef ioMSecs
#undef ioMicroMSecs
#undef ioLowResMSecs

#undef sqAllocateMemory
#undef sqGrowMemoryBy
#undef sqShrinkMemoryBy
#undef sqMemoryExtraBytesLeft

#include "sqMemoryAccess.h"

extern sqInt sqAllocateMemory(sqInt minHeapSize, sqInt desiredHeapSize);
extern sqInt sqGrowMemoryBy(sqInt oldLimit, sqInt delta);
extern sqInt sqShrinkMemoryBy(sqInt oldLimit, sqInt delta);
extern sqInt sqMemoryExtraBytesLeft(sqInt includingSwap);

#include <sys/types.h>

typedef off_t squeakFileOffsetType;

#undef	sqFilenameFromString
#undef	sqFilenameFromStringOpen
#define sqFilenameFromStringOpen sqFilenameFromString

extern void sqFilenameFromString(char *uxName, sqInt stNameIndex, int sqNameLength);

#undef dispatchFunctionPointer
#undef dispatchFunctionPointerOnin
/* we'd like to untypedef fptr too, but such is life */

#include <unistd.h>

#undef	sqFTruncate
#ifndef NACL
#define	sqFTruncate(f,o) ftruncate(fileno(f), o)
#else
#define	sqFTruncate(f,o) 0
#endif

#ifdef NACL
#undef sqImageFile
#undef sqImageFileClose
#undef sqImageFileOpen
#undef sqImageFilePosition
#undef sqImageFileRead
#undef sqImageFileSeek
#undef sqImageFileWrite

struct NaClFile {
  char *buffer;
  int32_t index;
};

#define sqImageFile					   struct NaClFile*
#define sqImageFileClose(f)                  		   nacl_fclose(f)
#define sqImageFileOpen(fileName, mode)      		   nacl_fopen(fileName, mode)
#define sqImageFilePosition(f)               		   nacl_ftell(f)
#define sqImageFileRead(ptr, sz, count, f)   		   nacl_fread(ptr, sz, count, f)
#define sqImageFileSeek(f, pos)              		   nacl_fseek(f, pos);
#define sqImageFileWrite(ptr, sz, count, f)  		   nacl_fwrite(ptr, sz, count, f)
extern int nacl_fclose(sqImageFile f);
extern sqImageFile nacl_fopen(char *fileName, char* mode);
extern long nacl_ftell(sqImageFile f);
extern size_t nacl_fread(void *ptr, size_t sz, size_t count, sqImageFile f);
extern int nacl_fseek(sqImageFile f, off_t offset);
extern int nacl_fwrite(void *ptr, size_t sz, size_t count, sqImageFile f);
#endif

#ifndef __GNUC__
# if HAVE_ALLOCA_H
#   include <alloca.h>
# else
#   ifdef _AIX
#     pragma alloca
#   else
#     ifndef alloca /* predefined by HP cc +Olibcalls */
        char *alloca();
#     endif
#   endif
# endif
#endif
