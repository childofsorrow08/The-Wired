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

.section .text
    .global _main

    .extern framebuffer_init
    .extern keyboard_init

    .extern welcome_msg

_main:
    subl $12, %esp

    call framebuffer_init
    call keyboard_init

    call welcome_msg
    call start_shell

// Kernel don't want to be here:
.hang:
    hlt
    jmp .hang


