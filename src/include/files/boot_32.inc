#if !defined(THEWIRED_BOOT32_INC)
#define THEWIRED_BOOT32_INC

.code32

.section .start, "ax", @progbits
    .global _start32

                            // From:
    .extern _x32_stack_top  // src/boot/bss_32.S
    .extern _x32_main       // src/kernel_32.S

#endif
