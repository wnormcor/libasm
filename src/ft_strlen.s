global		_ft_strlen
section		.text

_ft_strlen:						; size_t strlen(const char *rdi)
		xor rax, rax			; set to zero rax or: mov rax, 0

.loop:							; while (rdi[len] != '\0')
		cmp	byte[rdi + rax], 0	; 
		je	.return				;
		inc	rax					; len++;
		jmp	.loop				;

.return:
		ret						; return(len) -> ret(rax)