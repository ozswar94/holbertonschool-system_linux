BITS 64

global asm_strlen
section .text

asm_strlen:
    push rbp
    mov rbp, rsp
    mov rcx, 0
counter_char:
    xor rax, rax
    mov al, byte [rdi + rcx]
    inc rcx
    cmp al, 0
    jne counter_char
    dec rcx
    mov rax, rcx
    mov rsp, rbp
    pop rbp
    ret
