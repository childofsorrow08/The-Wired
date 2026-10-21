#include <stdint.h>
#include <framebuffer.h>
#include <helpers/colors.h>
#include <private/tty.h>

void tty_print_default(char c) {
	tty_putchar('%');
	if (c != '\0') { tty_putchar(c); }
}
