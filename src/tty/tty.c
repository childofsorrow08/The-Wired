#include <stdint.h>

#include <helpers/colors.h>
#include <private/tty.h>

int tty_get_x(void) 		{ return cursor.x; }
int tty_get_y(void) 		{ return cursor.y; }
void tty_new_x(int new_x) 	{ cursor.x = new_x; }
void tty_new_y(int new_y) 	{ cursor.y = new_y; }
void tty_add_x(int change) 	{ cursor.x += change; }
void tty_add_y(int change) 	{ cursor.y += change; }

void tty_set_color(int color) { cursor.color = color; }
void tty_def_color(void) { cursor.color = COLOR_WHITE; }
