.code32

.section .start, "ax", @progbits
    .global _start32

	.extern welcome_msg
	.extern stack_top

	.extern _main

_start32:
    cli

	movl $0xB8000, %edi
	call welcome_msg

#if defined(X32)
	movl $stack_top, %esp
#elif defined(X64)
	movq $stack_top, %rsp
#endif

	call _main

.hang:
    hlt
    jmp .hang
