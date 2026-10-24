#if !defined(THEWIRED_BOOT32_INC)
#define THEWIRED_BOOT32_INC

.code32

.section .start, "ax", @progbits
    .global _start32

    .extern _stack_top

    .extern _main

#endif
