#******************************************************************************
# Copyright (C) 2017 by Alex Fosdick - University of Colorado
#
# Redistribution, modification or use of this software in source or binary
# forms is permitted as long as the files maintain this copyright. Users are 
# permitted to modify this and use it to learn about the field of embedded
# software. Alex Fosdick and the University of Colorado are not liable for any
# misuse of this material. 
#
#*****************************************************************************

#------------------------------------------------------------------------------
# <Put a Description Here>
#
# Use: make [TARGET] [PLATFORM-OVERRIDES]
#
# Build Targets:
#      <Put a description of the supported targets here>
#
# Platform Overrides:
#      <Put a description of the supported Overrides here
#
#------------------------------------------------------------------------------
include sources.mk

# Platform Overrides
#PLATFORM = 

# Architectures Specific Flags
#LINKER_FILE = 
#CPU = 
#ARCH = 
#SPECS = 

# Compiler Flags and Defines
#CC = 
#LD = 
#LDFLAGS = 
#CFLAGS = 
#CPPFLAGs = 

BASENAME = c1m2

# Architecture specific flags
ifeq ($(PLATFORM), MSP432)
	LINKER_FILE = -T ../msp432p401r.lds
	CPU = cortex-m4
	ARCH = armv7e-m
	SPECS = nosys.specs
else
	CPU = x86_64
	ARCH:=$(shell arch)
endif

# Compiler flags and Defines
ifeq ($(PLATFORM), MSP432)
	CC = arm-none-eabi-gcc
	LD = arm-none-eabi-ld
	LDFLAGS = -Wl,-Map=$(BASENAME).map $(LINKER_FILE)
	CFLAGS = -mcpu=$(CPU) -march=$(ARCH) --specs=$(SPECS) -mfloat-abi=hard -mfpu=fpv4-sp-d16 -mthumb -Wall -Werror -O0 -g -std=c99
	CPPFLAGs = -M -MF test.d
	DEFINEFLAG = -DMSP432
else
	CC = gcc
	LDFLAGS = -Wl,-Map=$(BASENAME).map
	CLFAGS = -Wall -Werror -O0 -g -std=c99
	CPPFLAGs = -M -MF test2.d
	DEFINEFLAG = -DHOST
endif



# More declared variables
PPS := $(SOURCES: .c = .i)
ASM := $(SOURCES: .c = .s)
OBJ := $(SOURCES: .c = .o)
MAP := $(SOURCES: .c = .map)
OUT := $(SOURCES: .c = .out)


# Target build for preprocessed file .i
%.i : %.c
	$(CC) $(DEFINEFLAG) $(CPPFLAGs) -E -o $@ $<
	
# Target build for assembly file .s
%.asm : %.c
	$(CC) $(DEFINEFLAG) $(CFLAGS) -S -o $@ $<
	
# Target build for object file .o
$.o : %.c
	$(CC) $(DEFINEFLAG) $(CFLAGS) -c $<
	
# Target build for compile-all
.PHONY: compile-all
compile-all: $(SOURCES)
	$(CC) $(DEFINEFLAG) $(CFLAGS) -c $^
	
# Target build for build
.PHONY: build
build: $(OUT)
	$(CC) $(DEFINEFLAG) $(CFLAGS) $(LDFLAGS) -o c1m2.out $^
	size c1m2.out
	
# Target build for clean
.PHONY: clean
clean:
	rm -f *.i *.d *.map *.s *.out *.o
	
	








	
