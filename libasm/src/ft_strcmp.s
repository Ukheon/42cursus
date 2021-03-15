section		.text
	global _ft_strcmp

_ft_strcmp:
	mov		rcx, 0
	jmp		loop

loop:
    cmp BYTE [rsi + rcx], 0
    je  calc
    cmp BYTE [rdi + rcx], 0
    je  calc
    mov dl, BYTE[rsi + rcx]
    cmp	BYTE [rdi + rcx], dl
    jne calc
    inc rcx
    jmp loop
calc:
    mov dl, BYTE [rdi + rcx]
    sub dl, BYTE [rsi + rcx]
    movsx rax, dl
    jmp end
end:
    ret