#include <stdint.h>
#include <keyboard.h>

int32_t sys_read(uint32_t fd, char *buffer, uint32_t count) {
    if (fd != 0) return -1;
    if (count == 0) return 0;
    if (!buffer) return -1;

    /* A short read lets userspace handle editing and echo itself. */
    buffer[0] = keyboard_getchar();
    return 1;
}
