LIB_DIR := lib
OBJ_DIR := $(LIB_DIR)/obj
SRC_DIR := src
SRCS := $(wildcard $(SRC_DIR)/*.c)
OBJS := $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))
STANDARD := -std=c99
FLAGS := $(STANDARD) -L./lib -lpowerconsole

all: library test showObj showFun

library: $(OBJS) | $(LIB_DIR)
	ar -rc $(LIB_DIR)/libpowerconsole.a $^
	ranlib $(LIB_DIR)/libpowerconsole.a

test: library
	gcc test.c $(FLAGS) -o test.exe

showObj: library
	ar -t $(LIB_DIR)/libpowerconsole.a

showFun: library
	nm $(LIB_DIR)/libpowerconsole.a

$(OBJ_DIR): | $(LIB_DIR)
	mkdir $@

$(LIB_DIR):
	mkdir $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	gcc $(STANDARD) -c $< -o $@

clean:
	rm -rf $(LIB_DIR)