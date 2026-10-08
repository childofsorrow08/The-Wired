.section .boot
	.global clear_screen

clear_screen:
	movl $2000, %ecx
	movw $0x0720, %ax
.clear_screen:
    movw %ax, (%edi)
    addl $2, %edi
    decl %ecx
    jnz .clear_screen
	movl $0xB8000, %edi
	ret
