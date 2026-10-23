#include <stdint.h>

#include <framebuffer.h>
#include <helpers/colors.h>
#include <private/tty.h>

void tty_putchar(char c) {
    if (!fb.base || fb.width < 8 || fb.height < 16) return;

    if (c == '\b') {
        if (cursor.x >= 8) {
            cursor.x -= 8;
        } else if (cursor.y >= 16) {
            cursor.y -= 16;
            cursor.x = ((int)(fb.width / 8u) - 1) * 8;
        } else {
            return;
        }
        for (int y = 0; y < 16; ++y)
            for (int x = 0; x < 8; ++x)
                fb.base[(cursor.y + y) * fb.pitch_pixels + cursor.x + x] = COLOR_BLACK;
    } else if (c == '\n') {
        cursor.x = 0;
        cursor.y += 16;
    } else if (c == '\t') {
        for (int i = 0; i < 4; ++i) tty_putchar(' ');
        return;
    } else if (c >= 32 && c <= 126) {
        if (cursor.x + 8 > (int)fb.width) {
            cursor.x = 0;
            cursor.y += 16;
        }
        tty_ensure_visible();
        framebuffer_putchar(cursor.x, cursor.y, c, cursor.color);
        cursor.x += 8;
        if (cursor.x + 8 > (int)fb.width) {
            cursor.x = 0;
            cursor.y += 16;
        }
    }
    tty_ensure_visible();
}
