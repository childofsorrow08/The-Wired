.code64

.section .text
    .global _main

_main:

.loop:
    hlt
    jmp .loop
