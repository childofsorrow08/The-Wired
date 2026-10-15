#include <stdint.h>
#include <stdarg.h>

#include <helpers.h>
#include <framebuffer.h>
#include <helpers/colors.h>
#include <private/tty.h>

void tty_print(char *msg, ...) {
    va_list args;
    va_start(args, msg);

    for (int i = 0; msg[i] != '\0'; i++) {
        if (msg[i] == '%') {
            i++;

            switch (msg[i]) {

				// string
                case 's': {
                    char *str = va_arg(args, char *);

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

                    break;
                }

				// decimal
                case 'd': {
                    int value = va_arg(args, int);
                    char *str = int_to_str(value);
                    framebuffer_putstring(cursor.x, cursor.y, str, cursor.color);
                    while (*str++) { cursor.x += 8; }
                    break;
                }

				// char
                case 'c': {
                    char c = (char)va_arg(args, int);
                    framebuffer_putchar(cursor.x, cursor.y, c, cursor.color);
                    cursor.x += 8;
                    break;
                }

				// %%%%%%%%%%%%%%%%%
                case '%': {
                    framebuffer_putchar(cursor.x, cursor.y, '%', cursor.color);
                    cursor.x += 8;
                    break;
                }

                default:
                    framebuffer_putchar(cursor.x, cursor.y, '%', cursor.color);
                    cursor.x += 8;

                    if (msg[i] != '\0') {
                        framebuffer_putchar(cursor.x, cursor.y, msg[i], cursor.color);
                        cursor.x += 8;
                    }

                    break;
            }
        } else if (msg[i] == '\n') {
            cursor.y += 16;
            cursor.x = 0;
        } else {
            framebuffer_putchar(cursor.x, cursor.y, msg[i], cursor.color);
            cursor.x += 8;
        }
    }

    va_end(args);
}
