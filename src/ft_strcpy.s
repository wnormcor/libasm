global		_ft_strcpy
section		.text

_ft_strcpy:
	xor rax, rax

.start:
	mov dl, [rsi + rax]
	mov [rdi + rax], dl
	inc rax
	cmp dl, 0
	jne .start

.exit:
	mov rax, rdi
	ret