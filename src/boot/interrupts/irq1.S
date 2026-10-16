.code32
.section .boot, "ax", @progbits
	.global set_irq1

	.extern keyboard_irq_handler
	.extern idt_start

#if defined(X32)
irq1_entry:
    pushal
    pushl %ds
    pushl %es

    movw $0x10, %ax
    movw %ax, %ds
    movw %ax, %es
    cld

    call keyboard_irq_handler

    popl %es
    popl %ds
    popal
    iret

set_irq1:
    movl $idt_start + (0x21 * 8), %edx
    movl $irq1_entry, %eax
    movw %ax, 0(%edx)
    movw $0x08, 2(%edx)
    movb $0, 4(%edx)
    movb $0x8E, 5(%edx)
    shrl $16, %eax
    movw %ax, 6(%edx)
	ret
#endif
