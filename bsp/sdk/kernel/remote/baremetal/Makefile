# AugenTix SDK - Baremetal HC1785 Build System
# Copyright (c) AugenTix Inc.

TARGET = baremetal
# Use bare-metal toolchain for Cortex-M0 instead of Linux toolchain
BAREMETAL_CROSS_COMPILE ?= arm-none-eabi-
CC = $(BAREMETAL_CROSS_COMPILE)gcc
AS = $(BAREMETAL_CROSS_COMPILE)as
LD = $(BAREMETAL_CROSS_COMPILE)ld
OBJCOPY = $(BAREMETAL_CROSS_COMPILE)objcopy
SIZE = $(BAREMETAL_CROSS_COMPILE)size

# Cortex-M0 specific flags for HC1785 baremetal
CFLAGS = -mcpu=cortex-m0 -mthumb -mfloat-abi=soft -std=c99
CFLAGS += -O0 -g -Wall -Wextra -Iinclude
CFLAGS += -DCORTEX_M0_M4_UNIFIED -DUSE_SOFT_FLOAT -ffreestanding
CFLAGS += -fno-builtin -nostdlib

ASFLAGS = -mcpu=cortex-m0 -mthumb

LDFLAGS = -T$(TARGET).ld -nostartfiles -nostdlib -nodefaultlibs
LDFLAGS += -Wl,-Map=output/$(TARGET).map,--cref,--no-warn-mismatch

# Source files
C_SRCS = main.c src/cm_cpu.c src/cm_memory.c src/cm_csr.c src/printf.c src/uart.c
ASM_SRCS = start.S

# Object files (output to output/ directory)
C_OBJS = $(addprefix output/, $(notdir $(C_SRCS:.c=.o)))
ASM_OBJS = $(addprefix output/, $(notdir $(ASM_SRCS:.S=.o)))
OBJS = $(C_OBJS) $(ASM_OBJS)

# Dependencies
DEPS = $(TARGET).ld include/cm_conf.h include/memory_map.h

.PHONY: all clean info

# Default target
all: output/$(TARGET).elf output/$(TARGET).bin info

# Create output directory
output:
	@mkdir -p output

# Compile C source files
output/%.o: %.c $(DEPS) | output
	$(CC) $(CFLAGS) -c $< -o $@

output/%.o: src/%.c $(DEPS) | output
	$(CC) $(CFLAGS) -c $< -o $@

# Compile assembly source files
output/%.o: %.S $(DEPS) | output
	$(CC) $(ASFLAGS) -c $< -o $@

# Link ELF file
output/$(TARGET).elf: $(OBJS) $(DEPS) | output
	$(CC) $(LDFLAGS) $(OBJS) -lgcc -o $@

# Generate binary file
output/$(TARGET).bin: output/$(TARGET).elf
	$(OBJCOPY) -O binary $< $@

# Show build information
info: output/$(TARGET).elf output/$(TARGET).bin
	@$(SIZE) -B output/$(TARGET).elf | tail -n1 | awk '{printf "Size: %d bytes\n", $$4}'
	@echo "Build completed successfully."

# Clean build artifacts
clean:
	rm -rf output/*