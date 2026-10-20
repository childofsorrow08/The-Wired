#include <stdint.h>
#include <stdarg.h>

#include <framebuffer.h>
#include <helpers/colors.h>
#include <private/tty.h>

extern void tty_msg_string(char *str);
extern void tty_print_decimal(int value);
extern void tty_print_char(char c);
extern void tty_print_hex(uint32_t value);
extern void tty_print_default(char c);

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
					tty_msg_string(str);
                    break;
                }

				// decimal
                case 'd': {
                    int value = va_arg(args, int);
					tty_print_decimal(value);
                    break;
                }

				// char
                case 'c': {
                    char c = (char)va_arg(args, int);
					tty_print_char(c);
                    break;
                }

                // hexadecimal
                case 'x': {
                    uint32_t value = va_arg(args, uint32_t);
                    tty_print_hex(value);
                    break;
                }

				// %%%%%%%%%%%%%%%%%
                case '%': {
                    framebuffer_putchar(cursor.x, cursor.y, '%', cursor.color);
                    cursor.x += 8;
                    break;
                }

                default:
					tty_print_default(msg[i]);
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
