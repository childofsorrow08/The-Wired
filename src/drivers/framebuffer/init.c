#include <stdint.h>

#include <multiboot.h>
#include <framebuffer.h>
#include <helpers.h>

void framebuffer_init(void) {
    uint8_t *info = (uint8_t *)(uintptr_t)multiboot_info_ptr;
    uint32_t total_size = *(uint32_t *)info;

    uint32_t offset = 8;

    while (offset < total_size) {
        struct multiboot_tag *tag =
            (struct multiboot_tag *)(info + offset);

        if (tag->type == 0) { break; }

        if (tag->type == 8) {
            struct multiboot_tag_framebuffer *fb_tag =
                (struct multiboot_tag_framebuffer *)tag;

            fb.base = (uint32_t *)(uintptr_t)fb_tag->fb_addr;
            fb.width = fb_tag->fb_width;
            fb.height = fb_tag->fb_height;
            fb.pitch_pixels = fb_tag->fb_pitch / 4;

            return;
        }

        offset += (tag->size + 7u) & ~7u;
    }
}




