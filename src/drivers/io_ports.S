.code32
.section .text
	.global outb
	.global inb

outb:
    movw 4(%esp), %dx
    movb 8(%esp), %al
    outb %al, %dx
    ret

inb:
    movw 4(%esp), %dx
    inb %dx, %al
    ret
