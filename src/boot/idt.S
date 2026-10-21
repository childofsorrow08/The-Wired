.code32

#if defined(X32)
.section .data
.align 8
idt_start:
    .fill 256, 8, 0
idt_end:

.align 4
idtp:
    .word idt_end - idt_start - 1
    .long idt_start

.section .boot, "ax", @progbits
	.global idt_init
	.global idt_start

    .extern fill_default_idt
	.extern set_irq1
    .extern set_syscall

idt_init:
    movl $256, %ecx
    movl $idt_start, %edx

	call fill_default_idt
	call set_irq1
    call set_syscall

    lidt idtp
    ret
#endif
