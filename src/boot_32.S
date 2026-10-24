#include <files/boot_32.inc>

_start32:
    cli

    movl $_stack_top, %esp

    call _main
