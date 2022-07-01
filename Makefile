CC=clang

C_FLAGS=-g
LD_FLAGS=-lSDL2

SRC=$(shell find src -name '*.c')
OBJ=$(SRC:.c=.o)

BIN_DIR=bin
BIN=baloon-quest

all: $(BIN_DIR) $(BIN)

run: all
	$(BIN_DIR)/$(BIN)

$(BIN_DIR):
	mkdir -p $@

$(BIN): $(OBJ)
	$(CC) $^ $(LD_FLAGS) -o $(BIN_DIR)/$@

%.o: %.c %.h
	$(CC) $(C_FLAGS) -c $< -o $@

%.o: %.c
	$(CC) $(C_FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)
	rm -rf $(BIN_DIR)

.PHONY: all run clean
