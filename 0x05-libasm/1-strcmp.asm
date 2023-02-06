BITS 64

global asm_strcmp
section .text

asm_strcmp:
    push rbp
    mov rbp, rsp
    mov rcx, 0
compare:
    xor rax, rax
    xor rbx, rbx
    mov al, byte [rdi + rcx]
    mov bl, byte [rsi + rcx]
    cmp al, bl
    je equal
    jl less
    jg greate
equal:
    cmp al, 0
    je exit
    inc rcx
    jmp compare
less:
    mov rax, -1
    jmp exit
greate:
    mov rax, 1
    jmp exit
exit:
    mov rsp, rbp
    pop rbp
    ret
