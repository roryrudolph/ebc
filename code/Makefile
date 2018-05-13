# The TI compiler and toolchain
CC := arm-linux-gnueabi-gcc

DEVICE := MSP432P401R

BIN_DIR := bin
OBJ_DIR := obj
SRC_DIR := src
INC_DIR := src

BINS := $(BIN_DIR)/ebc
SRCS := $(shell find $(SRC_DIR) -type f -iname "*.c")
INCS := $(shell find $(INC_DIR) -type f -iname "*.h")
OBJS := $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS))

CFLAGS := -Wall -Werror -Wextra
IFLAGS := -I$(INC_DIR)/
LDFLAGS := 


all: $(BINS)

$(BINS): $(OBJS) | $(BIN_DIR)/
	$(CC) -o $@ $^ $(LDFLAGS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INCS) | $(OBJ_DIR)/
	$(CC) -c -o $@ $(CFLAGS) $(IFLAGS) $<

$(BIN_DIR)/ $(OBJ_DIR)/:
	mkdir -p $@

.PHONY: all clean distclean

clean:
	rm -f $(BINS)
	rm -f $(OBJS)

distclean:
	rm -rf $(BIN_DIR)/
	rm -rf $(OBJ_DIR)/

