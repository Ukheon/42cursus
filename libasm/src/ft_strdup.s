section		.text
	global _ft_strdup
	extern _malloc
	extern _ft_strlen
	extern _ft_strcpy

_ft_stdup:
	jmp main
	
main:
	call _ft_strlen
	mov rbx, rdi
	mov rdi, rax
	call _malloc
	mov rdi, rax
	mov rsi, rbx
	call _ft_strcpy
	mov rax, rdi
	ret

