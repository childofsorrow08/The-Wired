<!-- --------------------------------------------------- -->
<!-- Only used if you use markdownlint VS Code extension -->

<!-- markdownlint-disable no-inline-html -->
<!-- --------------------------------------------------- -->

<h1 align="center">
    SYSCALLS.md
</h1>

So, my kernel, like any other, has its own system calls. In this file, you'll find all the rules for working with them, their numbers, which registers are used to pass arguments and return values, and so on.

> [!WARNING]
> Until the ABI is explicitly declared stable, any part of the syscall interface may change without notice between versions. This includes syscall numbers, calling conventions, register usage, argument and return value formats, data structures, and error handling.
>
> Userspace software should not rely on backward compatibility with older kernel versions at this stage of development.

## System call ranges

All calls will be divided into ranges by category:

| Range | Category |
| :--- | :--- |
| `0` | Reserved exclusively for `SYS_EXIT` |
| `1-100` | [I/O](#io-syscalls--range-from-1-to-100) |
| `101-200` | [Filesystem](#filesystem-syscalls--range-from-101-to-200) |
| TODO | TODO |

## Calling convention

The following registers are used for syscalls:

| Register | Purpose |
| :--- | :--- |
| `EAX` | System call number and return value |
| `EBX` | Argument 1 |
| `ECX` | Argument 2 |
| `EDX` | Argument 3 |
| `ESI` | Argument 4 |
| `EDI` | Argument 5 |

System calls are invoked using interrupt `0x80`.

## I/O syscalls | Range from 1 to 100

### Syscall 1: Write

**Args:**

| Register | Value |
| :--- | :--- |
| `EAX` | 1 |
| `EBX` | File descriptor |
| `ECX` | Pointer to the buffer |
| `EDX` | Number of bytes to write |
| `ESI` | Unused |
| `EDI` | Unused |

**Returns** number of bytes succesfully written in `EAX`
If a negative value is returned, an error occurred.

Example:

```gas
movl $1, %eax
movl $1, %ebx
movl $message, %ecx
movl $message_len, %edx
int $0x80
```

### Syscall 2: Read

Reads keyboard input from stdin. Blocks until one character is available and
returns one byte, even if the requested count is larger. Input is not echoed;
userspace handles echo, line editing, and command buffering with `SYS_WRITE`.
No null terminator is appended.

| Register | Value |
| :--- | :--- |
| `EAX` | 2 |
| `EBX` | File descriptor: 0 (stdin) |
| `ECX` | Pointer to a writable buffer |
| `EDX` | Buffer capacity in bytes |
| `ESI` | Unused |
| `EDI` | Unused |

Returns 1 on a successful read, 0 for a zero-length request, or -1 on error.

```gas
movl $2, %eax
xorl %ebx, %ebx
movl $input_buffer, %ecx
movl $1, %edx
int $0x80
```

### Syscall 3: Clear terminal

Clears the terminal to black and moves its cursor to the top left. The text
color is preserved. stdout and stderr currently share the same terminal.

| Register | Value |
| :--- | :--- |
| `EAX` | 3 |
| `EBX` | File descriptor: 1 (stdout) or 2 (stderr) |
| `ECX`–`EDI` | Unused |

Returns 0 on success or -1 on error.

```gas
movl $3, %eax
movl $1, %ebx
int $0x80
```

## Filesystem syscalls | Range from 101 to 200
