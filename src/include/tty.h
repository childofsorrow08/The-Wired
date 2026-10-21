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
 * %x - hexadecimal integer
 * %s - char*
 * %c - char
 * %% - %
 */
extern void tty_print(char *msg, ...);
extern void tty_putchar(char c);
extern void tty_input(char c);
extern void tty_set_color(int color);
extern void tty_def_color(void);

// extern foid
// ahahahahahahah

#endif
