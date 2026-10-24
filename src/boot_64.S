#include <files/boot_64.inc>

_start32:
    cli

    movl $_stack_top, %rsp

    call _main
