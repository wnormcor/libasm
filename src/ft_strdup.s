global		_ft_strdup
extern		_ft_strlen, _malloc, _ft_strcpy
section		.text

_ft_strdup:				; char *strdup(const char *rdi)
	mov	r12, rdi
	call _ft_strlen		; rax = len of rdi
	mov	rdi, rax		; save len in rdi
	inc	rdi				; len++

	call _malloc		; void *malloc(size_t rdi)
	cmp rax, 0			; if _malloc return NULL (rax == 0)
	je .return			; exit

	mov rdi, rax		; rdi -> distanation string (ptr of malloc)
	mov rsi, r12		; rsi -> source string (const char *rdi)
	call _ft_strcpy		; char *strcpy(char *rdi, const char *rsi)

.return:
	ret
