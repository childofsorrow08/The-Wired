.section .rodata
    .global build_time
    .global cc32
    .global as32
    .global cc64
    .global as64
    .global arch

build_time:
    .asciz BUILD_TIME

cc32:
    .asciz CC32_VERSION

as32:
    .asciz AS32_VERSION

cc64:
    .asciz CC64_VERSION

as64:
    .asciz AS64_VERSION

arch:
    .asciz ARCH
