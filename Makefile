# Copyright 2010, The Native Client SDK Authors. All rights reserved.
# Use of this source code is governed by a BSD-style license that can
# be found in the LICENSE file.

# Heavily edited by Yoshiki Ohshima (yoshiki at vpri.org) for the
# Squeak VM There are a few complications as the sources are
# distributed a few different places and making vm plugins depends on
# some what files located far away.

# You can change the macro INTERP not to gnuify

.PHONY: all clean

PYTHON = python

SQCFILES = squeak.c sqUnixMain.c sqNaClWindow.c sqNaClSound.c sqNaClFile.c sqUnixMemory.c sqUnixExternalPrims.c osExports.c
CROSSCFILES = sqVirtualMachine.c sqNamedPrims.c 
CFILES = Etoys.c
#INTERP = interp.c
INTERP = gnu-interp.c

NACL_SDK_ROOT = ../..

# common.mk has rules to build .o files from .cc files.
-include ../common.mk

OPT_FLAGS = -O2 -fomit-frame-pointer

AR = $(NACL_SDK_ROOT)/$(NACL_TOOLCHAIN_DIR)/bin/nacl-ar
RANLIB = $(NACL_SDK_ROOT)/$(NACL_TOOLCHAIN_DIR)/bin/nacl-ranlib

CFLAGS = -Wall -Wno-long-long -pthread -Werror
SQCFLAGS = -Wno-long-long -pthread -Wno-pragmas -DNO_STD_FILE_SUPPORT -DEMBEDDED_IMAGE_FILE
INCLUDES = -Isrc/vm -I. -Ivm -ICross/vm
LDFLAGS = -lppruntime \
          -lpthread \
          -lplatform \
          -lgio \
          -lsrpc \
          $(ARCH_FLAGS)

X8632 = _x86_32
X8664 = _x86_64

INTERP_X86_32 = $(addprefix bld/,$(subst .c,$(X8632).o, $(INTERP)))
VM_SQ_OBJECTS_X86_32 = $(addprefix bld/,$(subst .c,$(X8632).o,$(notdir $(SQCFILES))))
VM_CROSS_OBJECTS_X86_32 = $(addprefix bld/,$(subst .c,$(X8632).o,$(notdir $(CROSSCFILES))))
PLUGINS_X86_32 = $(addprefix bld/,$(addsuffix $(X8632).a,$(notdir $(wildcard src/vm/intplugins/*))))

INTERP_X86_64 = $(addprefix bld/,$(subst .c,$(X8664).o, $(INTERP)))
VM_SQ_OBJECTS_X86_64 = $(addprefix bld/,$(subst .c,$(X8664).o,$(notdir $(SQCFILES))))
VM_CROSS_OBJECTS_X86_64 = $(addprefix bld/,$(subst .c,$(X8664).o,$(notdir $(CROSSCFILES))))
PLUGINS_X86_64 = $(addprefix bld/,$(addsuffix $(X8664).a,$(notdir $(wildcard src/vm/intplugins/*))))

all: t32 t64

t32: squeak$(X8632).nexe
t64: squeak$(X8664).nexe
# check_variables #squeak.nmf squeak_dbg.nmf 

bld/interp.c: src/vm/interp.c
	cp $@ $<

bld/gnu-interp.c: src/vm/interp.c
	awk -v RS="\r\n" -f gnuify $< > $@
#	awk -f gnuify $< > $@

# Intermediate Targets for 32 bit

$(INTERP_X86_32): bld/$(INTERP)
	$(CC) $(SQCFLAGS) -m32 $(INCLUDES) $(OPT_FLAGS) -c -o $@ $<

$(VM_SQ_OBJECTS_X86_32):
	$(CC) $(SQCFLAGS) -m32 $(INCLUDES) $(OPT_FLAGS) -c -o $@ vm/$(subst $(X8632).o,,$(notdir $@)).c

$(VM_CROSS_OBJECTS_X86_32):
	$(CC) $(SQCFLAGS) -m32 $(INCLUDES) $(OPT_FLAGS) -c -o $@ Cross/vm/$(subst $(X8632).o,,$(notdir $@)).c

$(PLUGINS_X86_32): bld/%_x86_32.a: src/vm/intplugins/%
	$(AR) rc $@
	for i in $^/$(notdir $^).c $(wildcard plugins/$(notdir $^)/*.c) $(wildcard vm/plugins/$(notdir $^)/*.c); do \
		$(CC) $(SQCFLAGS) -m32 $(INCLUDES) -DSQUEAK_BUILTIN_PLUGIN -Iplugins/$(notdir $^) $(OPT_FLAGS) -c -o bld/`basename $$i .c`$(X8632).o $$i; \
	$(AR) r $@ bld/`basename $$i .c`$(X8632).o; \
	done
	$(RANLIB) $@

# Intermediate Targets for 64 bit

$(INTERP_X86_64): bld/$(INTERP)
	$(CC) $(SQCFLAGS) -m64 $(INCLUDES) $(OPT_FLAGS) -c -o $@ $<

$(VM_SQ_OBJECTS_X86_64):
	$(CC) $(SQCFLAGS) -m64 $(INCLUDES) $(OPT_FLAGS) -c -o $@ vm/$(subst $(X8664).o,,$(notdir $@)).c

$(VM_CROSS_OBJECTS_X86_64):
	$(CC) $(SQCFLAGS) -m64 $(INCLUDES) $(OPT_FLAGS) -c -o $@ Cross/vm/$(subst $(X8664).o,,$(notdir $@)).c

$(PLUGINS_X86_64): bld/%_x86_64.a: src/vm/intplugins/%
	$(AR) rc $@
	for i in $^/$(notdir $^).c $(wildcard plugins/$(notdir $^)/*.c) $(wildcard vm/plugins/$(notdir $^)/*.c); do \
		$(CC) $(SQCFLAGS) -m64 $(INCLUDES) -DSQUEAK_BUILTIN_PLUGIN -Iplugins/$(notdir $^) $(OPT_FLAGS) -c -o bld/`basename $$i .c`$(X8664).o $$i; \
	$(AR) r $@ bld/`basename $$i .c`$(X8664).o; \
	done
	$(RANLIB) $@

# Have to link with g++: the implementation of the PPAPI proxy
# is a C++ implementation

squeak$(X8632).nexe: $(OBJECTS_X86_32) $(VM_SQ_OBJECTS_X86_32) $(VM_CROSS_OBJECTS_X86_32) $(INTERP_X86_32) $(PLUGINS_X86_32)
	$(CPP) $^ $(LDFLAGS) -m32 -o $@

squeak$(X8664).nexe: $(OBJECTS_X86_64) $(VM_SQ_OBJECTS_X86_64) $(VM_CROSS_OBJECTS_X86_64) $(INTERP_X86_64) $(PLUGINS_X86_64)
	$(CPP) $^ $(LDFLAGS) -m64 -o $@

squeak_x86_32_dbg.nexe: $(OBJECTS_X86_32_DBG)
	$(CPP) $^ $(LDFLAGS) -m32 -o $@

squeak_x86_64_dbg.nexe: $(OBJECTS_X86_64_DBG)
	$(CPP) $^ $(LDFLAGS) -m64 -o $@

squeak.nmf: squeak$(X8632).nexe squeak$(X8664).nexe
	@echo "Creating squeak.nmf..."
	$(PYTHON) ../generate_nmf.py --nmf $@ \
	 --x86-64 squeak$(X8664).nexe --x86-32 squeak$(X8632).nexe

squeak_dbg.nmf: squeak_x86_32_dbg.nexe squeak_x86_64_dbg.nexe
	@echo "Creating squeak_dbg.nmf..."
	$(PYTHON) ../generate_nmf.py --nmf $@ \
	 --x86-64 squeak_x86_64_dbg.nexe \
	 --x86-32 squeak_x86_32_dbg.nexe

clean:
	-$(RM) *.o *.obj *.nexe bld/* interp.c gnu-interp.c

# Some debug targets

echo:
	@echo VM_SQ_OBJECTS_X86_32 is $(VM_SQ_OBJECTS_X86_32)
	@echo VM_CROSS_OBJECTS_X86_32 is $(VM_CROSS_OBJECTS_X86_32)
	@echo PLUGINS_X86_32 is $(PLUGINS_X86_32)

plugins: $(PLUGINS_X86_32)
vm: $(VM_SQ_OBJECTS_X86_32) $(VM_CROSS_OBJECTS_X86_32)

Etoys.c:

#  On the host environment, compile mkimage.c and then execute it with your faviorite Squeak image to produce Etoys.c

