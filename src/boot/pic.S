.code32
.section .boot, "ax", @progbits
	.global pic_init
	.extern outb

# Remap 8259 PIC:
# IRQ0-7  -> IDT 0x20-0x27
# IRQ8-15 -> IDT 0x28-0x2F

pic_init:
    pushl $0x11
    pushl $0x20
    call outb
    addl $8, %esp

    pushl $0x11
    pushl $0xA0
    call outb
    addl $8, %esp

    pushl $0x20
    pushl $0x21
    call outb
    addl $8, %esp

    pushl $0x28
    pushl $0xA1
    call outb
    addl $8, %esp

    pushl $0x04
    pushl $0x21
    call outb
    addl $8, %esp

    pushl $0x02
    pushl $0xA1
    call outb
    addl $8, %esp

    pushl $0x01
    pushl $0x21
    call outb
    addl $8, %esp

    pushl $0x01
    pushl $0xA1
    call outb
    addl $8, %esp

    pushl $0xFD
    pushl $0x21
    call outb
    addl $8, %esp

    pushl $0xFF
    pushl $0xA1
    call outb
    addl $8, %esp

    ret
