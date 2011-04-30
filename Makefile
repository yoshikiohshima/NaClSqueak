# Copyright 2010, The Native Client SDK Authors. All rights reserved.
# Use of this source code is governed by a BSD-style license that can
# be found in the LICENSE file.

# Makefile for the Squeak example.

.PHONY: all clean

PYTHON = python

SQCFILES = sqUnixMain.c sqNaClWindow.c sqNaClSound.c sqNaClFile.c sqUnixMemory.c sqUnixExternalPrims.c osExports.c
CROSSCFILES = sqVirtualMachine.c sqNamedPrims.c 

CFILES = squeak.c Etoys.c

NACL_SDK_ROOT = ../..

# common.mk has rules to build .o files from .cc files.
-include ../common.mk

AR = $(NACL_SDK_ROOT)/$(NACL_TOOLCHAIN_DIR)/bin/nacl-ar
RANLIB = $(NACL_SDK_ROOT)/$(NACL_TOOLCHAIN_DIR)/bin/nacl-ranlib

CFLAGS = -Wall -Wno-long-long -pthread -Werror
SQCFLAGS = -Wno-long-long -pthread -Wno-pragmas -DNO_STD_FILE_SUPPORT
INCLUDES = -Isrc/vm -I. -Ivm -ICross/vm
LDFLAGS = -lppruntime \
          -lpthread \
          -lplatform \
          -lgio \
          -lsrpc \
          $(ARCH_FLAGS)

LOCALSQCFILES = $(notdir $(SQCFILES))
LOCALCROSSCFILES = $(notdir $(CROSSCFILES))

VM_SQ_OBJECTS_X86_32_BASE = $(LOCALSQCFILES:%.c=%_x86_32.o)
VM_SQ_OBJECTS_X86_32 = $(addprefix bld/,$(VM_SQ_OBJECTS_X86_32_BASE))

VM_CROSS_OBJECTS_X86_32_BASE = $(LOCALCROSSCFILES:%.c=%_x86_32.o)
VM_CROSS_OBJECTS_X86_32 = $(addprefix bld/,$(VM_CROSS_OBJECTS_X86_32_BASE))

INTERP_X86_32 = bld/interp_x86_32.o

PLUGINDIRS	= $(wildcard src/vm/intplugins/*)
LOCALPLUGINNAMES = $(notdir $(PLUGINDIRS))

PLUGINS_X86_32 = $(addprefix bld/,$(LOCALPLUGINNAMES:%=%_x86_32.a))

all: squeak_x86_32.nexe
# check_variables #squeak.nmf squeak_dbg.nmf 

echo:
	@echo OBJECTS_X86_32 is $(OBJECTS_X86_32)

plugins: $(PLUGINS_X86_32)
vm: $(VM_SQ_OBJECTS_X86_32) $(VM_CROSS_OBJECTS_X86_32)
interp: $(INTERP_X86_32)

$(INTERP_X86_32): src/vm/interp.c
	$(CC) $(SQCFLAGS) -m32 $(INCLUDES) $(DEBUG_FLAGS) -c -o $@ $<

$(VM_SQ_OBJECTS_X86_32):
	$(CC) $(SQCFLAGS) -m32 $(INCLUDES) $(DEBUG_FLAGS) -c -o $@ vm/$(subst _x86_32.o,,$(notdir $@)).c

$(VM_CROSS_OBJECTS_X86_32):
	$(CC) $(SQCFLAGS) -m32 $(INCLUDES) $(DEBUG_FLAGS) -c -o $@ Cross/vm/$(subst _x86_32.o,,$(notdir $@)).c

$(PLUGINS_X86_32): bld/%_x86_32.a: src/vm/intplugins/%
	$(AR) rc $@
	for i in $^/$(notdir $^).c $(wildcard plugins/$(notdir $^)/*.c) $(wildcard vm/plugins/$(notdir $^)/*.c); do \
		$(CC) $(SQCFLAGS) -m32 $(INCLUDES) -DSQUEAK_BUILTIN_PLUGIN -Iplugins/$(notdir $^) $(DEBUG_FLAGS) -c -o bld/`basename $$i .c`.o $$i; \
	$(AR) r $@ bld/`basename $$i .c`.o; \
	done
	$(RANLIB) $@


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

squeak_x86_32.nexe: $(OBJECTS_X86_32) $(VM_SQ_OBJECTS_X86_32) $(VM_CROSS_OBJECTS_X86_32) $(INTERP_X86_32) $(PLUGINS_X86_32)
	$(CPP) $^ $(LDFLAGS) -m32 -o $@

squeak_x86_64.nexe: $(OBJECTS_X86_64)
	$(CPP) $^ $(LDFLAGS) -m64 -o $@

squeak_x86_32_dbg.nexe: $(OBJECTS_X86_32_DBG)
	$(CPP) $^ $(LDFLAGS) -m32 -o $@

squeak_x86_64_dbg.nexe: $(OBJECTS_X86_64_DBG)
	$(CPP) $^ $(LDFLAGS) -m64 -o $@

clean:
	-$(RM) *.o *.obj *.nexe bld/*

# This target is used by the SDK build system to produce a pre-built version
# of the .nexe.  You do not need to call this target.
install_prebuilt: squeak.nmf
	-$(RM) $(OBJECTS_X86_32) $(OBJECTS_X86_64)


Etoys.c:

#  On the host environment, compile mkimage.c and then execute it with your faviorite Squeak image to produce Etoys.c

