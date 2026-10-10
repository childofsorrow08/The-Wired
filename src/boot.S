.code32

.section .start, "ax", @progbits
    .global _start32

	.extern stack_top

	.extern multiboot_info_ptr

	.extern welcome_msg
	.extern paging_init
	.extern gdt_init
	.extern idt_init
	.extern _main

_start32:
    cli

#if defined(X32)
	movl $stack_top, %esp
#elif defined(X64)
	movq $stack_top, %rsp
#endif

	// Multiboot info
    movl %ebx, multiboot_info_ptr

	call gdt_init
	call idt_init
	call paging_init

	call _main

.hang:
    hlt
    jmp .hang
