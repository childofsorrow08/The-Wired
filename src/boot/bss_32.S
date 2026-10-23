.code32

.section .bss
    .global _stack_top

.align 16
_stack_bottom:
    .skip 8192
_stack_top:

