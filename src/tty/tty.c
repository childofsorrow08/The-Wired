#include <tty.h>

tty cursor = { 0, 0, COLOR_WHITE };

// all this shit is unused for now,
// but may be needed once shell will be written

int tty_x() { return cursor.x; }
int tty_y() { return cursor.y; }
void tty_new_x(int new_x) { cursor.x = new_x; }
void tty_new_y(int new_y) { cursor.y = new_y; }
void tty_add_x(int change) { cursor.x += change; }
void tty_add_y(int change) { cursor.y += change; }

// TODO: Add new color thingy
