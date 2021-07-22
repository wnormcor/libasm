global      _ft_read
extern      ___error
section     .text

_ft_read:
    mov     rax, 0x2000003
    syscall
    jc      .return_error
    jmp     .return

.return_error:
    mov     r12, rax            ; save errno
    call    ___error            ; get memory address for error errno
    mov     [rax], r12          ; put errno in memory address
    mov     rax, -1
    ret

.return:
    ret