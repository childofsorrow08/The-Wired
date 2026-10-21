#include <stdint.h>
#include <framebuffer.h>
#include <helpers/colors.h>
#include <private/tty.h>

// UNUSED
void tty_print_char(char c) {
    framebuffer_putchar(cursor.x, cursor.y, c, cursor.color);
    cursor.x += 8;
}
