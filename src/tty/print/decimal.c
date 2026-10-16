#include <stdint.h>
#include <helpers.h>
#include <framebuffer.h>
#include <helpers/colors.h>
#include <private/tty.h>

void tty_print_decimal(int value) {
    char *str = int_to_str(value);
    framebuffer_putstring(cursor.x, cursor.y, str, cursor.color);
    while (*str++) { cursor.x += 8; }
}
