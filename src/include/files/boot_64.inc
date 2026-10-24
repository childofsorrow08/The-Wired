#if !defined(THEWIRED_BOOT64_INC)
#define THEWIRED_BOOT64_INC

.code32

.section .start, "ax", @progbits
    .global _start32

                            // From:
    .extern _x64_stack_top  // src/boot/bss_64.S
    .extern _x64_main       // src/kernel_64.S

#endif
