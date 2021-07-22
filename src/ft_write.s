global      _ft_write
extern      ___error
section     .text

_ft_write:					; ssize_t ft_write(int rdi, const void *rsi, size_t rdx)
    mov     rax, 0x2000004	; number of sys_call of write
    syscall					; interrupt
    jc      .return_error	; jump if carry is set up (CF = 1) -> if sys_write return err
    jmp     .return			; jump if all ok

.return_error:
    mov     r12, rax		; save return errno in r12
    call    ___error		; RAX = the address of the errno, int *__errno_location(void)
    mov     [rax], r12		; set the value of errno
    mov     rax, -1			; set return = -1
    ret						; return(-1)

.return:
    ret