.code32

.section .data
.align 8
idt_start:
    .fill 256, 8, 0
idt_end:

.align 2
idtp:
    .word idt_end - idt_start - 1
    .long idt_start

.section .boot, "ax", @progbits
	.global idt_init

default_handler:
    cli
    hlt
    jmp default_handler

#if defined(X32)
idt_init:
    movl $256, %ecx
    leal idt_start, %edx

.fill_idt_loop:
    movl $default_handler, %eax
    movw %ax, (%edx)
    movw $0x08, 2(%edx)
    movb $0, 4(%edx)
    movb $0x8E, 5(%edx)
    movl $default_handler, %eax
    shrl $16, %eax
    movw %ax, 6(%edx)
    addl $8, %edx
    decl %ecx
    jnz .fill_idt_loop

    lidt idtp
    sti
    ret

#endif
