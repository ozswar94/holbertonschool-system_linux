BITS 64

global asm_strncmp
section .text

asm_strncmp:
    push rbp
    mov rbp, rsp
    mov rcx, 0
compare:
    xor rax, rax
    xor rbx, rbx
    cmp rcx, rdx
    je exit
    mov al, byte [rdi + rcx]
    mov bl, byte [rsi + rcx]
    cmp al, bl
    je equal
    jne diff
equal:
    cmp al, 0
    je exit
    inc rcx
    jmp compare

diff:
    sub rax, rbx

exit:
    mov rsp, rbp
    pop rbp
    ret
