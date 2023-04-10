# File Constants ---------------------
TARGET := os.bin
SRC := ./src
BIN := ./bin

BOOT := $(SRC)/boot/boot.asm
BOOT_BIN := $(BOOT:%.asm=%.bin)

KERNEL_ENTRY := $(SRC)/kernel/kernel_entry.elf
KERNEL_ENTRY_OBJ := $(KERNEL_ENTRY:%.elf=%.o)

C_SRC := $(wildcard $(SRC)/*/*.c)
C_OBJ := $(C_SRC:%.c=%.o)

OBJ := $(KERNEL_ENTRY_OBJ) $(C_OBJ)

# Compiler Constants -----------------
CC := gcc
fCC := -I./include -m32 -fno-pie -ffreestanding -c

AS := nasm
fAS := -f bin

LD := ld

EMU := qemu-system-i386
fEMU := -m 4G

# Build Rules -------------------
.PHONY: all clean

all: $(TARGET)
	$(EMU) $(fEMU) -drive format=raw,file=$<,index=0,if=floppy

$(TARGET): boot.bin kernel.bin
	cat $^ > $@
	@mv $^ $(BIN)

boot.bin: $(BOOT)
	$(AS) -f bin -o $@ $^

kernel.bin: $(OBJ)
	$(LD) -m elf_i386 -s -o $@ -Ttext 0x1000 $^ --oformat binary

%.o: %.elf
	$(AS) -f elf -o $@ $^

%.o: %.c
	$(CC) $(fCC) -o $@ $^

clean:
	@rm -f $(BIN)/*
	@rm -f $(OBJ) $(TARGET)
