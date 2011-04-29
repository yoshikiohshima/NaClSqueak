#include "sq.h"
#include "../plugins/FilePlugin/FilePlugin.h"

int thisSession = 0;
extern struct VirtualMachine * interpreterProxy;

sqInt sqFileAtEnd(SQFile *f) {
  return interpreterProxy->success(false);
}

sqInt sqFileClose(SQFile *f) {
  return interpreterProxy->success(false);
}

sqInt sqFileDeleteNameSize(char* sqFileName, sqInt sqFileNameSize) {
  return interpreterProxy->success(false);
}

squeakFileOffsetType sqFileGetPosition(SQFile *f) {
  return interpreterProxy->success(false);
}

sqInt sqFileInit(void) {
	/* Create a session ID that is unlikely to be repeated.
	   Zero is never used for a valid session number.
	   Should be called once at startup time.
	*/
#if VM_PROXY_MINOR > 6
	thisSession = (int) interpreterProxy->getThisSessionID();
#else
	thisSession = ioLowResMSecs() + 10;
	if (thisSession == 0) thisSession = 1;	/* don't use 0 */
#endif
	return 1;
}

sqInt sqFileShutdown(void) {
	return 1;
}

static int setStdFilename(char* stdFilename, char *cFileName, char *sqFileName, sqInt sqFileNameSize)
{
    return 0;
}

sqInt sqFileOpen(SQFile *f, char* sqFileName, sqInt sqFileNameSize, sqInt writeFlag) {
	/* Opens the given file using the supplied sqFile structure
	   to record its state. Fails with no side effects if f is
	   already open. Files are always opened in binary mode;
	   Squeak must take care of any line-end character mapping.
	*/

  return interpreterProxy->success(false);
}

/*
 * Fill-in files with handles for stdin, stdout and stderr as available and
 * answer a bit-mask of the availability, 1 corresponding to stdin, 2 to stdout
 * and 4 to stderr, with 0 on error or unavailablity.
 */
sqInt
sqFileStdioHandlesInto(SQFile files[3])
{
  return 7;
}

size_t sqFileReadIntoAt(SQFile *f, size_t count, char* byteArrayIndex, size_t startIndex) {
	/* Read count bytes from the given file into byteArray starting at
	   startIndex. byteArray is the address of the first byte of a
	   Squeak bytes object (e.g. String or ByteArray). startIndex
	   is a zero-based index; that is a startIndex of 0 starts writing
	   at the first byte of byteArray.
	*/

  return interpreterProxy->success(false);
}

sqInt sqFileRenameOldSizeNewSize(char* oldNameIndex, sqInt oldNameSize, char* newNameIndex, sqInt newNameSize) {
  return interpreterProxy->success(false);
}

sqInt sqFileSetPosition(SQFile *f, squeakFileOffsetType position) {
  return interpreterProxy->success(false);
}

squeakFileOffsetType sqFileSize(SQFile *f) {
	/* Return the length of the given file. */

  return interpreterProxy->success(false);
}

sqInt sqFileFlush(SQFile *f) {
	/* Return the length of the given file. */

  return interpreterProxy->success(false);
}

sqInt sqFileTruncate(SQFile *f,squeakFileOffsetType offset) {
	/* Truncate the file*/

	return interpreterProxy->success(false);
}


sqInt sqFileValid(SQFile *f) {
  return false;
}

size_t sqFileWriteFromAt(SQFile *f, size_t count, char* byteArrayIndex, size_t startIndex) {
	/* Write count bytes to the given writable file starting at startIndex
	   in the given byteArray. (See comment in sqFileReadIntoAt for interpretation
	   of byteArray and startIndex).
	*/

  return interpreterProxy->success(false);
}

sqInt sqFileThisSession() {
	return thisSession;
}

