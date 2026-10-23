#include <stdint.h>
#include <framebuffer.h>
#include <private/tty.h>
#include <helpers/colors.h>

int32_t sys_tty_clear(uint32_t fd) {
    if (fd != 1 && fd != 2) return -1;
    if (!fb.base) return -1;
    for (uint32_t y = 0; y < fb.height; ++y)
        for (uint32_t x = 0; x < fb.width; ++x)
            fb.base[y * fb.pitch_pixels + x] = COLOR_BLACK;
    cursor.x = 0;
    cursor.y = 0;
    return 0;
}
