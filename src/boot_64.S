#include <files/boot_64.inc>

_start32:
    cli

    movl $_stack_top, %esp

    // todo
    ljmp $GDT64_CODE, $_start64

.code64

_start64:
    movabs $_stack_top, %rsp

    call _main
