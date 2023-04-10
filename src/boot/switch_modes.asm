[bits 16]
; void switch_to_32bit(void)
; Switches the CPU to 32-bit mode
switch_to_32bit:
    pusha

    cli
    lgdt [gdt_descriptor]
    mov eax, cr0
    or eax, 1
    mov cr0, eax
    jmp CODE_SEGMENT_INDEX:begin_32bit_mode

    popa
    ret

[bits 32]
; void begin_32bit_mode(void)
; Finalizes setting the CPU to 32-bit mode
begin_32bit_mode:
    mov ax, DATA_SEGMENT_INDEX
    mov dx, ax
    mov ss, ax
    mov es, ax
    mov fs, ax
    mov gs, ax
    mov ebp, 0x90000
    mov esp, ebp
    jmp KERNEL_OFFSET
