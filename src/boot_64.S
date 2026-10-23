.code32

.section .start, "ax", @progbits
    .global _start32

    .extern _stack_top

    .extern _main

_start32:
    cli

    movl $_stack_top, %rsp

    call _main
