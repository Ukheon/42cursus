section		.text
	global _ft_write
    extern ___error

_ft_write: ;int			ft_write(int fd, char *str, int len)
	jmp		loop

loop:
    mov rax, 0x2000004
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