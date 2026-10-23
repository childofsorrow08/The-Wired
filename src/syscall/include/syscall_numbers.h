#ifndef SYSCALL_NUMBERS_H
#define SYSCALL_NUMBERS_H

typedef enum {
    SYS_EXIT  = 0,
    SYS_WRITE = 1,
    SYS_READ = 2,
    SYS_TTY_CLEAR = 3,

    SYS_COUNT
} syscall_number_t;

#endif
