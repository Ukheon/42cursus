section		.text
	global _ft_strlen

_ft_strlen:
	mov		rax, 0
	jmp		check

check:
	cmp	BYTE [rdi + rax], 0
	je	end
	inc	rax
	jmp	check
end:
	ret