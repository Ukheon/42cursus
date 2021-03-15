section		.text
	global _ft_strdup
	extern _ft_strlen
	extern _ft_strcpy
	extern _malloc


_ft_strdup: ;char		*ft_strdup(const char *str)
	call _ft_strlen	
	add	 rax, 1
	push rdi
	mov	rdi, rax
	call _malloc
	pop	rbx
	mov rdi, rax
	mov	rsi, rbx
	call _ft_strcpy
	ret