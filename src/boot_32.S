/*
 * Copyright (C) 2026 Child of Sorrow
 *
 * This file is part of TheWired kernel.
 *
 * TheWired kernel is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 */

 .code32

.section .start, "ax", @progbits
    .global _start32

	.extern stack_top

	.extern multiboot_info_ptr

	.extern welcome_msg
	.extern paging_init
	.extern gdt_init
    .extern tss_init
	.extern idt_init
	.extern pic_init
	.extern _main

_start32:
    cli

	movl $stack_top, %esp

	// Multiboot info
    movl %ebx, multiboot_info_ptr

	call gdt_init
    call tss_init

	call idt_init
	call pic_init
	call paging_init

	call _main

.hang:
    hlt
    jmp .hang
