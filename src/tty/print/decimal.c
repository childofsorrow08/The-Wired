#include <stdint.h>
#include <helpers.h>
#include <framebuffer.h>
#include <helpers/colors.h>
#include <private/tty.h>

void tty_print_decimal(int value) {
    char *str = int_to_str(value);
    while (*str) { tty_putchar(*str++); }
}
