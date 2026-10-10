.section .rodata
welcome_message:
    .asciz "Welcome to TheWired kernel\n"

build_time_label:
    .asciz "Build Time: "

#ifdef X32
cc32_label:
    .asciz "C Compiler: "
as32_label:
    .asciz "Assembly: "
#endif

#ifdef X64
cc64_label:
    .asciz "C Compiler: "
as64_label:
    .asciz "Assembly: "
#endif

arch_label:
    .asciz "Arch: "

newline_str:
    .asciz "\n"


.section .boot
	.global welcome_msg

welcome_msg:
    movl $welcome_message, %esi
    call print_string

    movl $build_time_label, %esi
    call print_string
    movl $build_time, %esi
    call print_string
    movl $newline_str, %esi
    call print_string

#ifdef X32
    movl $cc32_label, %esi
    call print_string
    movl $cc32, %esi
    call print_string
    movl $newline_str, %esi
    call print_string

    movl $as32_label, %esi
    call print_string
    movl $as32, %esi
    call print_string
    movl $newline_str, %esi
    call print_string
#endif

#ifdef X64
    movl $cc64_label, %esi
    call print_string
    movl $cc64, %esi
    call print_string
    movl $newline_str, %esi
    call print_string

    movl $as64_label, %esi
    call print_string
    movl $as64, %esi
    call print_string
    movl $newline_str, %esi
    call print_string
#endif

    movl $arch_label, %esi
    call print_string
    movl $arch, %esi
    call print_string
    movl $newline_str, %esi
    call print_string

.hang:
    hlt
    jmp .hang

print_string:
    pushl %eax
    pushl %esi

.print_loop:
    movb (%esi), %al
    testb %al, %al
    jz .print_done

    cmpb $10, %al
    je .do_newline

    movb %al, (%edi)
    movb $0x0F, 1(%edi)
    addl $2, %edi
    jmp .next_char

.do_newline:
    pushl %ebx
    movl %edi, %eax
    subl $0xB8000, %eax
    movl $160, %ebx
    xorl %edx, %edx
    divl %ebx
    subl %edx, %edi
    addl $160, %edi
    popl %ebx
    jmp .next_char

.next_char:
    incl %esi
    jmp .print_loop

.print_done:
    popl %esi
    popl %eax
    ret
