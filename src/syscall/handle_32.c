#include <stdint.h>

#include <syscall_numbers.h>
#include <syscall_32.h>
#include <private/tty.h>
#include <tty.h>

int32_t sys_write(uint32_t fd, const char *buffer, uint32_t count);
int32_t sys_read(uint32_t fd, char *buffer, uint32_t count);
int32_t sys_tty_clear(uint32_t fd);

int32_t syscall_dispatch(uint32_t number,
                        uint32_t arg1,
                        uint32_t arg2,
                        uint32_t arg3,
                        uint32_t arg4,
                        uint32_t arg5){
    (void)arg4;
    (void)arg5;

    switch (number) {
        case SYS_READ:
            return sys_read(arg1, (char *)arg2, arg3);
        case SYS_TTY_CLEAR:
            return sys_tty_clear(arg1);
        case SYS_WRITE:
            return sys_write(
                arg1,
                (const char *)arg2,
                arg3
            );

        default:
            return -1;
    }
}
