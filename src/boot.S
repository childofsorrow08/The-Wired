.code32

.section .start, "ax", @progbits
    .global _start32

	.extern welcome_msg

_start32:
    cli

	movl $0xB8000, %edi
	call welcome_msg

.hang:
    hlt
    jmp .hang
