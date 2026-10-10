#include <stdint.h>
#include <stddef.h>

#include <framebuffer.h>
#include <variables.h>

void _main(void) {
	framebuffer_init();

	framebuffer_putstring(0, 0, "Basic text", 0xFFFFFFFF);
	framebuffer_putstring(0, 16, "TheWired kernel", 0xFFFFFFFF);

	while (1) {
		__asm__ volatile("hlt");
	}
}
