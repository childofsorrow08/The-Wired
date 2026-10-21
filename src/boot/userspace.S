.code32

#if defined(X32)

.section .bss
    .align 16

user_stack_bottom:
    .skip 8192

.global user_stack_top
user_stack_top:

.section .text
    .global userspace_init

// void enter_userspace(void (*entry)(void));
userspace_init:
    cli
    movl 4(%esp), %eax

    movw $0x23, %dx
    movw %dx, %ds
    movw %dx, %es
    movw %dx, %fs
    movw %dx, %gs

    pushl $0x23
    pushl $user_stack_top

    pushfl

    orl $0x200, (%esp)

    pushl $0x1B
    pushl %eax

    iret

#endif
