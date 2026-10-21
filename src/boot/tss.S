.code32

.section .bss
.align 16

.global tss_entry

tss_entry:
    .skip 104

.section .boot, "ax", @progbits
    .global tss_init
    .extern gdt_tss
    .extern stack_top

tss_init:
    movl $tss_entry, %edi
    xorl %eax, %eax
    movl $26, %ecx
    rep stosl

    // SS0 = kernel data selector
    movw $0x10, tss_entry + 8

    // ESP0 = kernel stack
    movl $stack_top, %eax
    movl %eax, tss_entry + 4

    // I/O permission bitmap
    // offset >= sizeof(TSS) = there is no bitmap
    movw $104, tss_entry + 102

    movl $tss_entry, %eax

    // base 0..15
    movw %ax, gdt_tss + 2

    // base 16..23
    shrl $16, %eax
    movb %al, gdt_tss + 4

    // base 24..31
    movb %ah, gdt_tss + 7

    movw $0x28, %ax
    ltr %ax

    ret
