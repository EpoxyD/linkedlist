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
CFLAGS = -Wall -W -O -I inc -fPIC -g
LIBS = linkedlist
LDFLAGS = -L$(LIB_FOLDER) -Wl,-rpath=$(LIB_FOLDER)
MKDIR = mkdir -p

# gcc -c -o obj/*.o -Wall -W -O -I inc -fPIC
# gcc -o bin/linkedlist -Iinc -Wall -Werror -fPIC
# gcc -shared -o ../lib/liblinkedlist.so linkedlist.c -I ../inc/

$(PROGRAM) : main.c $(LIBS).so
	$(MKDIR) $(BIN_FOLDER)
	$(CC) $(CFLAGS) $(LDFLAGS) $(LIBS:%=-l%) -o $(BIN_FOLDER)/$@ $<

$(LIBS).so : $(OBJECTS)
	$(MKDIR) $(LIB_FOLDER)
	$(CC) -shared $(CFLAGS) $(LDFLAGS) -o $(LIB_FOLDER)/lib$@ $^

$(OBJ_FOLDER)/%.o : $(SRC_FOLDER)/%.c $(HEADERS)
	$(MKDIR) $(OBJ_FOLDER)
	$(CC) $(CFLAGS) -c -o $@ $<

.PHONY : clean
clean :
	rm -rf $(BIN_FOLDER) $(OBJ_FOLDER) $(LIB_FOLDER)

