.section .bss
	.align 16
	.global stack_top
	.global table_768

	stack_bottom:
#if defined(X32)
		.skip 8192
#elif defined(X64)
		.skip 16384
#endif
	stack_top:

#if defined(X32)
	.align 4096
	table_768:
		.skip 4096
#endif
