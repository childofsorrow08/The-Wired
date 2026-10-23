.code32
.section .boot, "ax", @progbits
	.global fill_default_idt

default_handler:
    cli
.halt:
    hlt
    jmp .halt

fill_default_idt:
    movl $default_handler, %eax
    movw %ax, 0(%edx)
    movw $0x08, 2(%edx)
    movb $0, 4(%edx)
    movb $0x8E, 5(%edx)
    shrl $16, %eax
    movw %ax, 6(%edx)
    addl $8, %edx
    decl %ecx
    jnz fill_default_idt
	ret
