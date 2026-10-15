#if !defined(TTY_H)
#define TTY_H

/*
 * printf() implementation, but tty_print():
 *
 * - Takes any number of arguments and replaces %*
 * with the corresponding output
 * - Args must be written in the correct order
 * - Also can see newline symbol (\n)
 *
 * %d - int
 * %s - char*
 * %c - char
 * %% - %
 */
extern void tty_print(char *msg, ...);
extern void tty_input(char c);
#endif
