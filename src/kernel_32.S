#include <files/kernel_32.inc>

_main:

.loop:
    hlt
    jmp .loop
