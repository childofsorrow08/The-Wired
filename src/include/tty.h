#if !defined(TTY_H)
#define TTY_H

#include <colors.h>

typedef struct tty {
	int x;
	int y;
	colors color;
} tty;

extern tty cursor;

extern int tty_x();
extern int tty_y();
extern void tty_new_x(int new_x);
extern void tty_new_y(int new_y);
extern void tty_add_x(int change);
extern void tty_add_y(int change);

/*
 * printf() implementation, but printmsg():
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
extern void printmsg(char *msg, ...);

#endif
