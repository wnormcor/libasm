global		_ft_strcmp
section		.text

_ft_strcmp:							; int strcmp(const char *rdi, const char *rsi)
		xor rax, rax				; for *s1
		xor rdx, rdx				; for *s2

.loop:
		mov al, byte[rdi]			; copy low byte of rax
		mov dl, byte[rsi]			; copy to the low byte rdx
		sub rax, rdx				; rax = *s1 - *s2
		jnz .return					; if rax (*s1 - *s2) != 0 -> return(rax)
		cmp dl, 0					; if rdi == '\0'
		je	.return					; 	return(rax);
		inc rdi						; rdi++
		inc rsi						; rsi++;
		jmp .loop

.return:
		ret							; return(rax)