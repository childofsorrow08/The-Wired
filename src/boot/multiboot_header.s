.code32

.section .multiboot_header, "a", @progbits

.set MB2_HEADER_MAGIC, 0xE85250D6
.set MB2_ARCHITECTURE_X86, 0
.set MB2_HEADER_LENGTH, (header_end - header_start)
.set MB2_CHECKSUM, -(MULTIBOOT2_HEADER_MAGIC + MULTIBOOT2_ARCHITECTURE_X86 + MULTIBOOT2_HEADER_LENGTH)

.set FB_TAG, 5
.set FB_FLAG, 0
.set FB_FLAG_SIZE, 20
.set FB_SCREEN_LENGTH, 0
.set FB_SCREEN_WIDTH, 0
.set FB_BPP, 32

header_start:
    .long MB2_HEADER_MAGIC
    .long MB2_ARCHITECTURE_X86
    .long MB2_HEADER_LENGTH
    .long MB2_CHECKSUM

	// Framebuffer
    .align 8
    .word FB_TAG
    .word FB_FLAG
    .long FB_FLAG_SIZE
    .long FB_SCREEN_LENGTH
    .long FB_SCREEN_WIDTH
    .long FB_BPP

    .word 0
    .word 0
    .long 8
header_end:
