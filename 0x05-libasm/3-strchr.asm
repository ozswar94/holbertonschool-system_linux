BITS 64

global asm_strchr
section .text

asm_strchr:
    push rbp
    mov rbp, rsp
    mov rcx, 0
str_loop:
    xor rax, rax
    mov al, byte [rdi + rcx]
    test al, al
    jz null
    cmp al, sil
    je find
    inc rcx
    jmp str_loop
null:
    xor rax, rax
    jmp exit
find:
    lea rax, [rdi + rcx]
exit:
    mov rsp, rbp
    pop rbp
    ret
