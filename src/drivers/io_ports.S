.code32
.section .text
	.global outb
	.global inb
    .global inw

outb:
    movw 4(%esp), %dx
    movb 8(%esp), %al
    outb %al, %dx
    ret

inb:
    movw 4(%esp), %dx
    xorl %eax, %eax
    inb %dx, %al
    ret

inw:
    movw 4(%esp), %dx
    xorl %eax, %eax
    inw %dx, %ax
    ret
