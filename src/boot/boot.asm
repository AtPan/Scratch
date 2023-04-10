[bits 16]
[org 0x7c00]

call boot_init
call kernel_load
call switch_to_32bit

; void boot_init(void)
; Initializes bootloader. NOTE: Will squash register bx.
boot_init:
    KERNEL_OFFSET: equ 0x1000

    ; Save disk number of boot drive
    mov [BOOT_DRIVE], dl

    ; Setup stack pointers
    pop bx
    mov bp, 0x9000
    mov sp, bp
    jmp bx

REQUESTED_SECTORS: db 0
BOOT_DRIVE: db 0
DISK_ERROR: db "Error occured reading from disk, aborting", 0
SECTOR_ERROR: db "Incorrect number of sectors read, aborting", 0
BAD_WRITE: db "Reading from disk could not be verified, aborting", 0

%include "src/boot/print_string.asm"
%include "src/boot/disk_read.asm"
%include "src/boot/gdt.asm"
%include "src/boot/switch_modes.asm"

times 510 - ($ - $$) db 0
dw 0xaa55
