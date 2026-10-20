#include <stdint.h>
#include <private/tty.h>

void tty_print_hex(uint32_t value) {
    char buffer[9];
    int i = 0;

    if (value == 0) {
        tty_putchar('0');
        return;
    }

    while (value > 0) {
        uint32_t digit = value & 0xF;

        if (digit < 10)
            buffer[i++] = '0' + digit;
        else
            buffer[i++] = 'A' + (digit - 10);

        value >>= 4;
    }

    while (i > 0)
        tty_putchar(buffer[--i]);
}
