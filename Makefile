# Copyright 2010, The Native Client SDK Authors. All rights reserved.
# Use of this source code is governed by a BSD-style license that can
# be found in the LICENSE file.

# Makefile for the Squeak example.

.PHONY: all clean

PYTHON = python

CFILES = squeak.c

NACL_SDK_ROOT = ../..

CFLAGS = -Wall -Wno-long-long -pthread -Werror
INCLUDES =
LDFLAGS = -lppruntime \
          -lpthread \
          -lgoogle_nacl_platform \
          -lgio \
          -lsrpc \
          $(ARCH_FLAGS)
OPT_FLAGS = -O2

all: check_variables squeak.nmf squeak_dbg.nmf

# common.mk has rules to build .o files from .cc files.
-include ../common.mk

squeak.nmf: squeak_x86_32.nexe squeak_x86_64.nexe
	@echo "Creating squeak.nmf..."
	$(PYTHON) ../generate_nmf.py --nmf $@ \
	 --x86-64 squeak_x86_64.nexe --x86-32 squeak_x86_32.nexe

squeak_dbg.nmf: squeak_x86_32_dbg.nexe squeak_x86_64_dbg.nexe
	@echo "Creating squeak_dbg.nmf..."
	$(PYTHON) ../generate_nmf.py --nmf $@ \
	 --x86-64 squeak_x86_64_dbg.nexe \
	 --x86-32 squeak_x86_32_dbg.nexe

# Have to link with g++: the implementation of the PPAPI proxy
# is a C++ implementation

squeak_x86_32.nexe: $(OBJECTS_X86_32)
	$(CPP) $^ $(LDFLAGS) -m32 -o $@

squeak_x86_64.nexe: $(OBJECTS_X86_64)
	$(CPP) $^ $(LDFLAGS) -m64 -o $@

squeak_x86_32_dbg.nexe: $(OBJECTS_X86_32_DBG)
	$(CPP) $^ $(LDFLAGS) -m32 -o $@

squeak_x86_64_dbg.nexe: $(OBJECTS_X86_64_DBG)
	$(CPP) $^ $(LDFLAGS) -m64 -o $@

clean:
	-$(RM) *.nmf *.o *.obj *.nexe

# This target is used by the SDK build system to produce a pre-built version
# of the .nexe.  You do not need to call this target.
install_prebuilt: squeak.nmf
	-$(RM) $(OBJECTS_X86_32) $(OBJECTS_X86_64)
