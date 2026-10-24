.code32

.section .start, "ax", @progbits
    .global _start32

    .extern _stack_top

    .extern _main
