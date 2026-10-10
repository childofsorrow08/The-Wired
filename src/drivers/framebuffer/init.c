#include <stdint.h>

#include <multiboot.h>
#include <framebuffer.h>
#include <variables.h>
#include <helpers.h>

void framebuffer_init(void) {
    uint8_t *info = (uint8_t *)(uintptr_t)multiboot_info_ptr;
    uint32_t total_size = *(uint32_t *)info;

    uint32_t offset = 8;

    while (offset < total_size) {
        struct multiboot_tag *tag =
            (struct multiboot_tag *)(info + offset);

        if (tag->type == 0) {
            break;
        }

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


// test functions
// will be deleted or rewritten
void draw_cube(void) {
    uint32_t *fb_ptr = fb.base;

    for (uint32_t y = 0; y < fb.height; y++) {
        for (uint32_t x = 0; x < fb.width; x++) {
            fb_ptr[y * fb.pitch_pixels + x] = 0x00FF0000;
        }
    }
}

void draw_char(int x, int y, char c, uint32_t color) {
    const uint8_t* glyph = get_font_glyph(c);

    for (int row = 0; row < 16; row++) {
        uint8_t line_bits = glyph[row];
        for (int col = 0; col < 8; col++) {
            if (line_bits & (1 << (7 - col))) {
                int px = x + col;
                int py = y + row;
                if (px < fb.width && py < fb.height) {
                    fb.base[py * fb.pitch_pixels + px] = color;
                }
            }
        }
    }
}

void draw_string(int x, int y, const char* str, uint32_t color) {
    int cursor_x = x;
    while (*str) {
        draw_char(cursor_x, y, *str, color);
        cursor_x += 8;
        str++;
    }
}
