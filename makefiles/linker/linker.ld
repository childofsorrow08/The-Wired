ENTRY(_start32)

SECTIONS
{
    . = 1M;

    .start : {
		*(.multiboot_header)
		*(.start)
		*(.boot)
	}

    .text : { *(.text) }
    .rodata : { *(.rodata) }
    .data : { *(.data) }
    .bss : { *(COMMON) *(.bss) }

	/DISCARD/ : {
        *(.comment)
        *(.note.*)
        *(.rel.*)
        *(.rela.*)
    }
}
