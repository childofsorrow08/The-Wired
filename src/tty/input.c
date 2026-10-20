// may be deleted or rewritten later

#include <stdint.h>

#include <framebuffer.h>
#include <helpers/colors.h>
#include <private/tty.h>

void tty_input(char c) {
    static unsigned int typed_chars = 0;

    if (c == '\b') {
        if (typed_chars == 0 || !fb.base) return;
        if (cursor.x >= 8) {
            cursor.x -= 8;
        } else {
            if (cursor.y < 16) return;
            cursor.y -= 16;
            cursor.x = ((int)(fb.width / 8u) - 1) * 8;
        }
        for (int y = 0; y < 16; ++y)
            for (int x = 0; x < 8; ++x)
                fb.base[(cursor.y + y) * fb.pitch_pixels + cursor.x + x] = COLOR_BLACK;
        --typed_chars;
        return;
    }
    if (c == '\n') {
        tty_putchar('\n');
        tty_putchar(' ');
        typed_chars = 0;
        return;
    }
    if (c == '\t') {
        for (int i = 0; i < 4; ++i) {
            tty_putchar(' ');
            ++typed_chars;
        }
        return;
    }
    if (c >= 32 && c <= 126) {
        tty_putchar(c);
        ++typed_chars;
    }
}
