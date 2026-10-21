#include <stdint.h>
#include <tty.h>

int32_t sys_write(uint32_t fd,
                 const char *buffer,
                 uint32_t count) {

    if (buffer == 0) return -1;
    if (fd != 1 && fd != 2) return -1;

    for (uint32_t i = 0; i < count; i++) {
        tty_putchar(buffer[i]);
    }

    return (int32_t)count;
}
