.section .bss
	.align 16
	.global stack_top

	stack_bottom:
#if defined(X32)
		.skip 8192
#elif defined(X64)
		.skip 16384
#endif
	stack_top:
