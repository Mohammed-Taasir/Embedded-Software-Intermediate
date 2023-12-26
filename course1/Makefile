SHELL = /bin/bash


SOURCES = ./src/main.c \
		  ./src/memory.c \
		  ./src/data.c \
		  ./src/stats.c \
		  ./src/course1.c

INCLUDES = -I ./include/common



PLATFORM=HOST

# compile time switch flags
COURSE1=false
VERBOSE=false

# general flags for compilation on all platforms
GEN_FLAGS = -Wall \
			-g \
			-O0 \
			-std=c99 \
			-Werror

# name of final build output
TARGET = final_assesment

# checking platforms
ifeq ($(PLATFORM), MSP432)
# cpu architecture
	CPU = cortex-m4
	ARCH = armv7e-m

	SOURCES = ./src/*.c
#	SOURCES += $(SRC_DIR)/interrupts_msp432p401r_gcc.c \
#			   $(SRC_DIR)/startup_msp432p401r_gcc.c \
#			   $(SRC_DIR)/system_msp432p401r.c
	INCLUDES = -I ./include/CMSIS \
	   		   -I ./include/common \
	   		   -I ./include/msp432
#	INCLUDES += -I include/CMSIS \
#				-I include/msp432

# compiler
	CC = arm-none-eabi-gcc
# linker and size
	LD = arm-none-eabi-ld
	SIZE = arm-none-eabi-size

# linker flags
	LINKER_FILE = ./msp432p401r.lds
	LDFLAGS = -Wl, -Map=$(TARGET).map -T $(LINKER_FILE) -lm
# compiler flags
	CFLAGS = $(GEN_FLAGS) \
			 -mcpu=$(CPU) \
			 -mthumb \
			 -march=$(ARCH) \
			 -mfloat-abi=hard \
			 -mfpu=fpv4-sp-d16 \
			 --specs=nosys.specs
# preprocessor flags
	CPPFLAGS = -DMSP432 $(INCLUDES)

else
# compiler
	CC = gcc
# size
	SIZE = size
# linker flags
	LDFLAGS = -lm
# compiler flags
	CFLAGS = $(GEN_FLAGS)
# preprocessor flags
	CPPFLAGS = -DHOST $(INCLUDES)

endif



# checking compile time switch flag for course1
ifeq ($(COURSE1), true)
	CPPFLAGS += -DCOURSE1
endif

# checking compile time switch flag for verbose
ifeq ($(VERBOSE), true)
	CPPFLAGS += -DVERBOSE
endif

# building all in-between files
PREP = $(SOURCES:.c=.i) # preprocessed files
ASMS = $(SOURCES:.c=.asm) # assembly files
DEPS = $(SOURCES:.c=.d) # dependent files
OBJS = $(SOURCES:.c=.o) # object files

# writing target build rules
.PHONY: compile-all build clean run

# build rule
build: $(TARGET).out
$(TARGET).out: $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) -o $@
	$(SIZE) $@

# for preprocessed files
%.i: %.c
	$(CC) -E $< $(CFLAGS) $(CPPFLAGS) -o $@

# for assembly files
%.asm: %.c
	$(CC) -S $< $(CFLAGS) $(CPPFLAGS) -o $@

# for dependency files
%.d: %.c
	$(CC) -E -M $< $(CFLAGS) $(CPPFLAGS) -o $@

# for object files
%.o: %.c
	$(CC) -c $< $(CFLAGS) $(CPPFLAGS) -o $@

# compile all .c files
compile-all: $(OBJS)
#compile-all: $(SOURCES)
#	$(CC) $(CFLAGS) -o $@ $^


# force clean
clean:
	rm -f ./src/*{.o,.out,.map,.d,.asm,.i} $(TARGET).out



run: $(TARGET).out
	./$(TARGET).out
