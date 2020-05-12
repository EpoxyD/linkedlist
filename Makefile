SRC_FOLDER = src
INC_FOLDER = inc
OBJ_FOLDER = obj
BIN_FOLDER = bin
LIB_FOLDER = lib

SOURCES = $(wildcard $(SRC_FOLDER)/*.c)
HEADERS = $(wildcard $(INC_FOLDER)/*.h)

OBJECTS = $(SOURCES:$(SRC_FOLDER)/%.c=$(OBJ_FOLDER)/%.o)
PROGRAM = $(shell basename `pwd`)

CC := $(shell which gcc)
CFLAGS = -Wall -Werror -I $(INC_FOLDER)
LDFLAGS = -L$(LIB_FOLDER)
LIBS = -llinkedlist
MKDIR = mkdir -p

ifdef DEBUG
CFLAGS += -g
endif

all: library

binary : main.c library
	$(MKDIR) $(BIN_FOLDER)
	$(CC) $(CFLAGS) $(LDFLAGS) $(LIBS) -o $(BIN_FOLDER)/linkedlist $<
	chmod +x $(BIN_FOLDER)/linkedlist

library : $(OBJECTS)
	$(MKDIR) $(LIB_FOLDER)
	$(CC) -shared $(CFLAGS) $(LDFLAGS) -o $(LIB_FOLDER)/liblinkedlist.so $^

$(OBJ_FOLDER)/%.o : $(SRC_FOLDER)/%.c $(HEADERS)
	$(MKDIR) $(OBJ_FOLDER)
	$(CC) $(CFLAGS) -c -o $@ $<

.PHONY : clean
clean :
	rm -rf $(BIN_FOLDER) $(OBJ_FOLDER) $(LIB_FOLDER)

