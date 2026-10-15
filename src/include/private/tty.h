#if !defined(PRIVATE_TTY_H)
#define PRIVATE_TTY_H

typedef struct tty {
	int x;
    int y;
    colors color;
} tty;

extern tty cursor;

extern int tty_get_x(void);
extern int tty_get_y(void);
extern void tty_new_x(int new_x);
extern void tty_new_y(int new_y);
extern void tty_add_x(int change);
extern void tty_add_y(int change);

extern void tty_scroll(void);
extern void tty_ensure_visible(void);
extern void tty_putchar(char c);
extern void tty_input(char c);

#endif
