.code32

// https://wiki.osdev.org/GDT_Tutorial

.section .data
#if defined(X32)
.align 8
gdt_start:
	.quad 0x0000000000000000 // Null Descriptor		||
	.quad 0x00cf9a000000ffff // Kernel Code Segment	|| 0x08
	.quad 0x00cf92000000ffff // Kernel Data Segment	|| 0x10
gdt_end:


gdtr:
    .word gdt_end - gdt_start - 1
    .long gdt_start
#endif

.section .boot, "ax", @progbits
	.global gdt_init

.align 2
#if defined(X32)

gdt_init:
	lgdt gdtr

	movw $0x10, %ax
    movw %ax, %ds
    movw %ax, %es
    movw %ax, %fs
    movw %ax, %gs
    movw %ax, %ss

	ljmp $0x08, $ljmp_label
ljmp_label:
    ret
#endif
