BITS 64

global asm_strchr
section .text

asm_strchr:
    push rbp
    mov rbp, rsp
    xor rax, rax
    mov rcx, 0
string_loop:
    mov al, byte [rdi + rcx]
    cmp al, 0 
    je exit
    cmp al, sil
    je find
    inc rcx
    mov rax, 0
    jmp string_loop
find:
    lea rax, [rdi + rcx]
exit:
    mov rsp, rbp
    pop rbp
    ret
