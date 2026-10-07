.section .boot
	.global paging_init
	.extern table_768

# maps 4 mb in 4 kb pages
# I think that's enough to get the base kernel up and running
# but just in case, it's a good idea to make a larger batch if needed
# https://wiki.osdev.org/X86_Paging

#if defined(X32)
paging_init:
	movl $0, %eax
    movl $0x100000, %ebx
.fill_table:
    movl %ebx, %ecx
    orl $3, %ecx
    movl %ecx, table_768(,%eax,4)
    addl $4096, %ebx
    incl %eax
    cmpl $1024, %eax
    jne .fill_table
.done:
	movl $table_768, %eax
	movl %eax, %cr3
	ret
#endif

