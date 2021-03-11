section		.text
	global _ft_read
    extern ___error
_ft_read: ;dest rdi, src rsi
	jmp		loop

loop:
    mov rax, 0x2000003
    syscall
    jc error
    ret
error:
    push rax
    call ___error
    pop rdx
    mov [rax], rdx
    mov rax, -1
    ret