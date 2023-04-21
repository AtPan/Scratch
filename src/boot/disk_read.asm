[bits 16]

; void kernel_load(void)
; Loads the kernel from the disk into memory at KERNEL_OFFSET
kernel_load:
    pusha

    mov al, 50
    mov bx, KERNEL_OFFSET
    mov ch, 0
    mov cl, 2
    mov dh, 0
    mov dl, [BOOT_DRIVE]

    call read_from_disk

    popa
    ret

; void disk_test(...)
; Parameters are as follows:
;   al - Number of sectors to read
;   bx - Memory address to put disk info
;   ch - disk cylinder to start reading from
;   cl - disk sector to start reading from
;   dh - disk head to start reading from
;   dl - disk number of disk to read from
read_from_disk:
    pusha
    mov [REQUESTED_SECTORS], al
    mov ah, 0x2
    int 0x13

    mov bx, DISK_ERROR
    jc _disk_test_L1

    mov bx, SECTOR_ERROR
    mov cl, [REQUESTED_SECTORS]
    cmp al, cl
    jne _disk_test_L1

    jmp _disk_test_L2

_disk_test_L1:
    call print_string
    jmp $

_disk_test_L2:
    popa
    ret
