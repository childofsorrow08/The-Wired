#include <stdint.h>

#include <framebuffer.h>
#include <helpers/colors.h>
#include <private/tty.h>

void tty_scroll(void) {
    if (!fb.base || fb.height < 16 || fb.width < 8) return;

    for (uint32_t y = 16; y < fb.height; ++y) {
        for (uint32_t x = 0; x < fb.width; ++x) {
            fb.base[(y - 16u) * fb.pitch_pixels + x] =
                fb.base[y * fb.pitch_pixels + x];
        }
    }
    for (uint32_t y = fb.height - 16u; y < fb.height; ++y) {
        for (uint32_t x = 0; x < fb.width; ++x) {
            fb.base[y * fb.pitch_pixels + x] = COLOR_BLACK;
        }
    }
    cursor.y -= 16;
}

void tty_ensure_visible(void) {
    while (fb.base && fb.height >= 16 && cursor.y + 16 > (int)fb.height)
        tty_scroll();
}
