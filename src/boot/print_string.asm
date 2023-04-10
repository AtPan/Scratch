[bits 16]

; void print_string(const char *)
; Must put string pointer in bx
print_string:
    pusha
    mov ah, 0x0e

_print_string_L1:
    mov al, [bx]
    cmp al, 0
    je _print_string_L2
    int 0x10
    add bx, 1
    jmp _print_string_L1

_print_string_L2:
    popa
    ret
