#include <stdint.h>

#include <framebuffer.h>
#include <helpers/colors.h>
#include <private/tty.h>

void tty_putchar(char c) {
    if (!fb.base || fb.width < 8 || fb.height < 16) return;

    if (c == '\n') {
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
