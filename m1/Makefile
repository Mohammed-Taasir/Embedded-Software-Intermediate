include sources.mk


TARGET = c1m1

CC = gcc
CFLAGS = -Wall -Wextra -std=c99
CPPFLAGS = -DHOST $(INCLUDES)
SIZE = size

OBJS = $(SOURCES:.c=.o)

.PHONY: compile-all build clean

build: $(TARGET).out
$(TARGET).out: $(OBJS)
	$(CC) $(CFLAGS) $(CPPFLAGS) $(OBJS) -o $@
	$(SIZE) $@
	
%.o: %.c
	$(CC) -c $< $(CFLAGS) $(CPPFLAGS) -o $@
	
compile-all: $(OBJS)

clean: 
	rm -f *.o *.out


