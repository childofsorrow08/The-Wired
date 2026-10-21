.code32

.section .boot, "ax", @progbits

.global set_syscall

.extern idt_start
.extern syscall_dispatch

#if defined(X32)

syscall_entry:
    /*
     * Userspace ABI:
     *
     * EAX = syscall number
     * EBX = arg1
     * ECX = arg2
     * EDX = arg3
     * ESI = arg4
     * EDI = arg5
     */

    pushal

    pushl %ds
    pushl %es
    pushl %fs
    pushl %gs

    movw $0x10, %ax
    movw %ax, %ds
    movw %ax, %es

    cld

    // pushal frame starts 16 bytes above current ESP
    leal 16(%esp), %ebp

    // cdecl: right-to-left
    pushl 0(%ebp)     // EDI = arg5
    pushl 4(%ebp)     // ESI = arg4
    pushl 20(%ebp)    // EDX = arg3
    pushl 24(%ebp)    // ECX = arg2
    pushl 16(%ebp)    // EBX = arg1
    pushl 28(%ebp)    // EAX = syscall number

    call syscall_dispatch
    addl $24, %esp
    movl %eax, 28(%ebp)

    popl %gs
    popl %fs
    popl %es
    popl %ds

    popal
    iret

set_syscall:
    // IDT[0x80]
    movl $idt_start + (0x80 * 8), %edx
    movl $syscall_entry, %eax

    movw %ax, 0(%edx)

    // Kernel code segment
    movw $0x08, 2(%edx)

    movb $0, 4(%edx)
    movb $0xEE, 5(%edx)
    shrl $16, %eax
    movw %ax, 6(%edx)

    ret

#endif
