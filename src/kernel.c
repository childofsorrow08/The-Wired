#include <stdint.h>
#include <stddef.h>

#include <framebuffer.h>
#include <variables.h>

// test functions
// will be deleted or rewritten
extern void draw_cube(void);
extern void draw_char(int x, int y, char c, uint32_t color);
extern void draw_string(int x, int y, const char* str, uint32_t color);

void _main(void) {
	framebuffer_init();
	draw_cube();

	draw_string(100, 100, "SOME TEXT LOL", 0xFFFFFFFF);

	while (1) {
		__asm__ volatile("hlt");
	}
}
