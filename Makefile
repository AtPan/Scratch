# File Constants ---------------------
TARGET := os.bin
SRC := ./src
BIN := ./bin

BOOT := $(SRC)/boot/boot.asm
BOOT_BIN := $(BOOT:%.asm=%.bin)

KERNEL_ENTRY := $(SRC)/kernel/kernel_entry.elf
KERNEL_ENTRY_OBJ := $(KERNEL_ENTRY:%.elf=%.o)

C_SRC := $(wildcard $(SRC)/*/*.c) $(wildcard $(SRC)/lib/*/*.c)
C_OBJ := $(C_SRC:%.c=%.o)

OBJ := $(KERNEL_ENTRY_OBJ) $(C_OBJ)

# Compiler Constants -----------------
CC := gcc
fCC := -I./include -m32 -fno-pie -ffreestanding -c
fCC_debug := -g2 -O0
fCC_release := -g0 -O2

AS := nasm
fAS := -f bin

LD := ld

EMU := qemu-system-i386
fEMU := -m 4G

# Build Rules -------------------
.PHONY: all clean

debug: fCC := $(fCC) $(fCC_debug)
debug: all

release: fCC := $(fCC) $(fCC_release)
release: all

all: $(TARGET)
	$(EMU) $(fEMU) -drive format=raw,file=$<,index=0,if=floppy

$(TARGET): boot.bin kernel.bin
	@dd if=/dev/zero of=$@ bs=512 count=2880
	@dd if=boot.bin of=$@ bs=512 conv=notrunc
	@dd if=kernel.bin of=$@ bs=512 seek=1 conv=notrunc
	@if [ ! -d $(BIN) ]; then \
		mkdir $(BIN); \
	fi
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
