#ifndef SYSCALL_H
#define SYSCALL_H

int32_t syscall_dispatch(
    uint32_t number,
    uint32_t arg1,
    uint32_t arg2,
    uint32_t arg3,
    uint32_t arg4,
    uint32_t arg5
);

#endif
