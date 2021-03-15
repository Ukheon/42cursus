section		.text
	global _ft_strcpy

_ft_strcpy: ;dest rdi, src rsi
	mov		rcx, 0
	jmp		loop

loop:
    cmp	BYTE [rsi + rcx], 0
    je end
    mov dl, BYTE[rsi + rcx]
    mov BYTE[rdi + rcx], dl
	inc	rcx
	jmp	loop
end:
    mov rax, rdi
	ret
