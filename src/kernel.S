#if defined(X32)
.code32
#endif

#if defined(X64)
.code64
#endif

.section .text
    .global _main

    .extern framebuffer_init
    .extern keyboard_init

    .extern welcome_msg

_main:
    call framebuffer_init
    call keyboard_init

    call welcome_msg

// Kernel don't want to be here:
.hang:
    hlt
    jmp .hang


