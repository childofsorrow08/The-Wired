.code32

.section .bss
    .global _stack_top
    .global _page_directory
    .global _page_table

.align 16
_stack_bottom:
    .skip 8192
_stack_top:

.align 4096
_page_directory:
    .skip 4096

_page_table:
    .skip 1024 * 4096
