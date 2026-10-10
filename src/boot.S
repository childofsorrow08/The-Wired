.code32

.section .start, "ax", @progbits
    .global _start32

	.extern stack_top

	.extern multiboot_info_ptr

	.extern welcome_msg
	.extern paging_init
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

	// movl $0xB8000, %edi
	// call clear_screen
	// call welcome_msg

#if defined(X32)
	call paging_init
#endif

	call _main

.hang:
    hlt
    jmp .hang
