#include <stdint.h>
#include <stddef.h>

#include <framebuffer.h>
#include <variables.h>
#include <tty.h>

void _main(void) {
	framebuffer_init();

	int i = 30;
	char* str = "Welcome to TheWired kernel btw \nI should work on my naming";
	printmsg("Some text for test, also random int: %d \n", i);
	printmsg("%s", str);
	printmsg("\nAlmost forgot to test this: %%");

	while (1) {
		__asm__ volatile("hlt");
	}
}
