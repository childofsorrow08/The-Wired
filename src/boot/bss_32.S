.code32

.section .bss
    .global _x32_stack_top
    .global _x32_page_directory
    .global _x32_page_table

.align 16
_x32_stack_bottom:
    .skip 8192
_x32_stack_top:

.align 4096
_x32_page_directory:
    .skip 4096

_x32_page_table:
    .skip 1024 * 4096
