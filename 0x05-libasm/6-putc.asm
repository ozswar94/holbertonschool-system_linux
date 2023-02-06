BITS 64

global asm_putc
section .text

asm_putc:
    push rbp
    mov rbp, rsp

	mov rax, 1
    mov rdi, 1
	mov rsi, rdi
    mov rdx, 1
	syscall
    mov rax, 1
	mov rsp, rbp
    pop rbp
    ret
