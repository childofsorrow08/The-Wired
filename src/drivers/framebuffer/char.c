#include <stdint.h>

#include <multiboot.h>
#include <framebuffer.h>
#include <variables.h>
#include <helpers.h>

void framebuffer_putchar(int x, int y, char c, uint32_t color) {
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
