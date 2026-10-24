.code32

.section .bss
    .global _x64_stack_top

.align 16
_x64_stack_bottom:
    .skip 16384
_x64_stack_top:
