/* Unix sqConfig.h -- platform identification and configuration */

/* This file has been superseded by autoconf for Unix variants. */

#define trace() fprintf(stderr, "%s:%d %s\n", __FILE__, __LINE__, __FUNCTION__)

#include "config.h"

#ifndef UNIX
# define UNIX
#endif
