ft_strcmp
s1 s2

while (i)
    s1[i] != s2[i]
        return (s1[i] - s2[i])
return (s1[i] - s2[i]);


section		.text
	global _ft_strcmp

_ft_strcmp: ;dest rdi, src rsi
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
    sub dl, BYTE[rsi + rcx]
    mov rax, dl
    jmp end

end:
    ret