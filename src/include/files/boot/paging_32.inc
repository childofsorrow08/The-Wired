#if !defined(THEWIRED_PAGING_32_INC)
#define THEWIRED_PAGING_32_INC

.code32

.section .boot, "ax", @progbits
    .global _x32_paging_init

    // From src/boot/bss_32.S
    .extern _x32_page_directory
    .extern _x32_page_table
    // ----------------------

#endif
