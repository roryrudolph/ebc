# The TI compiler and toolchain
CC := arm-none-eabi-gcc
GDB := arm-none-eabi-gdb

INSTALL_DIR := /home/rory/ti/ccsv7/ccs_base
GCC_MSP_INC_DIR ?= $(INSTALL_DIR)/arm/include
GCC_CMSIS_INC_DIR ?= $(GCC_MSP_INC_DIR)/CMSIS
LDDIR := $(GCC_MSP_INC_DIR)/$(shell echo $(DEVICE) | tr A-Z a-z)

DEVICE := MSP432P401R
STARTUP := startup_msp432p401r_gcc
SYSTEM := system_msp432p401r

BIN_DIR := bin
OBJ_DIR := obj
SRC_DIR := src
INC_DIR := src

BINS := $(BIN_DIR)/ebc
SRCS := $(shell find $(SRC_DIR) -type f -iname "*.c")
INCS := $(shell find $(INC_DIR) -type f -iname "*.h")
OBJS := $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS))

CFLAGS := -Wall -Wextra -mcpu=cortex-m4 -march=armv7e-m -mfloat-abi=hard -mfpu=fpv4-sp-d16 -mthumb -D__$(DEVICE)__ -DTARGET_IS_MSP432P4XX -Dgcc -g -gstrict-dwarf -Wall -ffunction-sections -fdata-sections -MD -std=c99
LDFLAGS := -mcpu=cortex-m4 -march=armv7e-m -mfloat-abi=hard -mfpu=fpv4-sp-d16 -mthumb -D__$(DEVICE)__ -DTARGET_IS_MSP432P4XX -Dgcc -g -gstrict-dwarf -Wall -T$(LDDIR).lds -l'c' -l'gcc' -l'nosys'

IFLAGS := -I$(INC_DIR) -I$(GCC_MSP_INC_DIR) -I$(GCC_CMSIS_INC_DIR)


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

