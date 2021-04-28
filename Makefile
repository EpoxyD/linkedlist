SRC_FOLDER = src
INC_FOLDER = inc
OBJ_FOLDER = obj
LIB_FOLDER = lib

SOURCES = $(wildcard $(SRC_FOLDER)/*.c)
OBJECTS = $(SOURCES:$(SRC_FOLDER)/%.c=$(OBJ_FOLDER)/%.o)
PROGRAM = $(shell basename `pwd`)

CC := gcc
CFLAGS = -g -Wall -Werror
LDFLAGS =

all: linkedlist.so

%.so: $(OBJECTS)
	mkdir -p $(LIB_FOLDER)
	$(CC) -shared -I $(INC_FOLDER) -L $(LIB_FOLDER) $(CFLAGS) $(LDFLAGS) -o $(LIB_FOLDER)/$@ $^
	rm -r $(OBJ_FOLDER)

%.o: $(SOURCES)
	mkdir -p $(OBJ_FOLDER)
	$(CC) -c -I $(INC_FOLDER) $(CFLAGS) -o $@ $<

.PHONY : all clean
clean :
	rm -rf $(OBJ_FOLDER) $(LIB_FOLDER)

