BITS 64

global asm_putc
section .text

asm_putc:
    mov eax, 1
    mov rdi, 1
    mov rdx, rdi
	syscall
    mov rax, 1
    ret
