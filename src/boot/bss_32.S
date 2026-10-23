.section .bss
	.align 16
	.global stack_top
	.global table_768

	stack_bottom:
		.skip 8192
	stack_top:

	.align 4096
	table_768:
		.skip 4096
