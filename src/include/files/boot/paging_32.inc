#if !defined(THEWIRED_PAGING_32_INC)
#define THEWIRED_PAGING_32_INC

.code32

.section .boot, "ax", @progbits
    .global _paging_init

    // From src/boot/bss_32.S
    .extern _page_directory
    .extern _page_table
    // ----------------------

#endif
