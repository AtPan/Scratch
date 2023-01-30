# File Constants ---------------------
SRC := ./src
BIN := ./bin
TARGET := $(BIN)/image.iso

BOOT_SECTOR := $(SRC)/boot
STDLIB := $(SRC)/lib
KERNEL := $(SRC)/kernel

# File Wildcards ---------------------

BOOT_SECTOR_SRC := $(wildcard $(BOOT_SECTOR)/*.asm)
STDLIB_SRC := $(wildcard $(STDLIB)/*/*.c)
KERNEL_SRC := $(wildcard $(KERNEL)/*/*.c)

BOOT_SECTOR_OBJ := ${BOOT_SECTOR_SRC:%.asm=%.o}
STDLIB_OBJ := ${STDLIB_SRC:%.c=%.o}
KERNEL_OBJ := ${KERNEL_SRC:%.c=%.o}

# Compiler Constants -----------------

CC := gcc
fCC := -m32 -O2 -ffreestanding -Wall -Wextra -I ./include/ -nostdlib

AS := nasm
fAS :=

LD := ld
fLD :=

EMU := qemu-system-i386
fEMU := -m 4G -fda

# Build Wildcards -------------------

.PHONY: all clean

clean:
	@for obj_file in $(BOOT_SECTOR_OBJ) ; do \
		if [ -f $$obj_file ] ; then \
			rm $$obj_file ; \
		fi; \
	done;
	@for obj_file in $(STDLIB_OBJ) ; do \
		if [ -f $$obj_file ] ; then \
			rm $$obj_file ; \
		fi; \
	done;
	@for obj_file in $(KERNEL_OBJ) ; do \
		if [ -f $$obj_file ] ; then \
			rm $$obj_file ; \
		fi; \
	done;
	@rm $(BIN)/*
