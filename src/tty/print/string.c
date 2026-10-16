#include <stdint.h>
#include <stdarg.h>

#include <framebuffer.h>
#include <helpers/colors.h>
#include <private/tty.h>

void tty_msg_string(char *str) {
    while (*str) {
		if (*str == '\n') {
			cursor.y += 16;
            cursor.x = 0;
		} else {
			framebuffer_putchar(cursor.x, cursor.y, *str, cursor.color);
			cursor.x += 8;
		}

		str++;
	}
}
