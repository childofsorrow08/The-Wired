.code32

.section .start, "ax", @progbits
    .global _start32

	.extern welcome_msg
	.extern stack_top
	.extern paging_init

	.extern _main

_start32:
    cli

	movl $0xB8000, %edi
	call clear_screen
	call welcome_msg

#if defined(X32)
	movl $stack_top, %esp

	call paging_init
#elif defined(X64)
	movq $stack_top, %rsp
#endif

	call _main

.hang:
    hlt
    jmp .hang
