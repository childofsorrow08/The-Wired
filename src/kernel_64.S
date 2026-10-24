#include <files/kernel_64.inc>

_main:

.loop:
    hlt
    jmp .loop
