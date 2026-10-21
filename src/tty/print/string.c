#include <stdint.h>
#include <stdarg.h>

#include <framebuffer.h>
#include <helpers/colors.h>
#include <private/tty.h>

void tty_msg_string(char *str) {
    while (*str) { tty_putchar(*str++); }
}

