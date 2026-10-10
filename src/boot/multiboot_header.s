.code32

.section .multiboot_header, "a", @progbits

.set MB2_HEADER_MAGIC, 0xE85250D6
.set MB2_ARCHITECTURE, 0
.set MB2_HEADER_LENGTH, (header_end - header_start)
.set MB2_CHECKSUM, -(MB2_HEADER_MAGIC + MB2_ARCHITECTURE + MB2_HEADER_LENGTH)

.set FB_TAG, 5
.set FB_FLAG, 0
.set FB_FLAG_SIZE, (_fb_tag_end - _fb_tag_start)
.set FB_SCREEN_LENGTH, 800
.set FB_SCREEN_WIDTH, 600
.set FB_BPP, 32

header_start:
    .long MB2_HEADER_MAGIC
    .long MB2_ARCHITECTURE
    .long MB2_HEADER_LENGTH
    .long MB2_CHECKSUM

    .align 8
_fb_tag_start:
    .value FB_TAG
    .value FB_FLAG
    .long FB_FLAG_SIZE
    .long FB_SCREEN_LENGTH
    .long FB_SCREEN_WIDTH
    .long FB_BPP
_fb_tag_end:

    .align 8
    .word 0
    .word 0
    .long 8
header_end:
