#SRC_DIR := ./src 
#INC_DIR := ./include
#OBJ_DIR := ./obj

#SOURCES = $(SRC_DIR)/main.c \
#		  $(SRC_DIR)/data.c \
#		  $(SRC_DIR)/course1.c \
#		  $(SRC_DIR)/memory.c \
#		  $(SRC_DIR)/stats.c 

#INCLUDES = -I include/common

SOURCES = ./src/main.c \
		  ./src/memory.c \
		  ./src/data.c \
		  ./src/stats.c \
		  ./src/course1.c

INCLUDES = -I ./include/common
