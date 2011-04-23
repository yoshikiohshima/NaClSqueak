# Makefile for the core Squeak VM

.PHONY: all clean

PYTHON = python

CFILES = ../src/vm/interp.c

NACL_SDK_ROOT = ../../../..

INCLUDES	= -I../src/vm -I..  -I.
LDFLAGS = -lppruntime \
          -lpthread \
          -lgoogle_nacl_platform \
          -lgio \
          -lsrpc \
          $(ARCH_FLAGS)
OPT_FLAGS = -O2

all: check_variables $(OBJECTS_X86_32)

-include $(NACL_SDK_ROOT)/examples/common.mk

SQCFLAGS = -Wno-long-long -pthread -Wno-pragmas
LOCALCFILES = $(notdir $(CFILES))

OBJECTS_X86_32 = $(LOCALCFILES:%.c=%_x86_32.o)
OBJECTS_X86_64 = $(CFILES:%.c=%_x86_64.o) $(CCFILES:%.cc=%_x86_64.o)
OBJECTS_X86_32_DBG = $(CFILES:%.c=%_x86_32_dbg.o) $(CCFILES:%.cc=%_x86_32_dbg.o)
OBJECTS_X86_64_DBG = $(CFILES:%.c=%_x86_64_dbg.o) $(CCFILES:%.cc=%_x86_64_dbg.o)

INTERP = interp
PLUGINDIRS	= $(wildcard ../src/vm/intplugins/*)
LOCALPLUGINNAMES = $(notdir $(PLUGINDIRS))

PLUGINS_X86_32 = $(LOCALPLUGINNAMES:%=%_x86_32.o)

echo:
	@echo PLUGINS_X86_32 is $(PLUGINS_X86_32)

plugins: $(PLUGINS_X86_32)

interp_x86_32.o: ../src/vm/interp.c
	$(CC) $(SQCFLAGS) -m32 $(INCLUDES) $(DEBUG_FLAGS) -c -o $@ $<

$(PLUGINS_X86_32): 
	$(CC) $(SQCFLAGS) -m32 $(INCLUDES) -I../plugins/$(subst _x86_32.o,,$@) $(DEBUG_FLAGS) -c -o $@ ../src/vm/intplugins/$(subst _x86_32.o,,$@)/$(subst _x86_32.o,.c,$@)




#OBJS		= $(INTERP)$o sqNamedPrims$o sqVirtualMachine$o aio$o debug$o osExports$o \
#		  sqUnixExternalPrims$o sqUnixMemory$o sqUnixCharConv$o sqUnixMain$o

# GNUify the interpreter if needed

# gnu-interp$o : gnu-interp.c
# 	$(COMPILE) $@ gnu-interp.c

# gnu-interp.c : $(srcdir)/vm/interp.c
# 	tr '\015' '\012' < $(srcdir)/vm/interp.c > interp.c
# 	$(AWK) -f $(topdir)/platforms/unix/config/gnuify interp.c > $@.out
# 	mv $@.out $@


.force :
