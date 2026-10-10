#include <stdint.h>
#include <stddef.h>

#include <framebuffer.h>
#include <variables.h>

// test function
// will be deleted
extern void draw_cube(void);

void _main(void) {
	framebuffer_init();
	draw_cube();

	while (1) {
		__asm__ volatile("hlt");
	}
}
