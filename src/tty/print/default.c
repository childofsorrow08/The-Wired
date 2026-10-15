#include <stdint.h>
#include <framebuffer.h>
#include <helpers/colors.h>
#include <private/tty.h>

void tty_print_default(char c) {
	framebuffer_putchar(cursor.x, cursor.y, '%', cursor.color);
    cursor.x += 8;

	if (c != '\0') {
        framebuffer_putchar(cursor.x, cursor.y, c, cursor.color);
        cursor.x += 8;
    }
}
