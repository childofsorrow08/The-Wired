#include <stdint.h>
#include <stddef.h>

#include <framebuffer.h>
#include <variables.h>
#include <tty.h>

void _main(void) {
	framebuffer_init();

#if defined(BUILD_TIME) || defined (CC_VERSION) || defined (AS_VERSION) || defined(ARCH)

	/*
	 * Just prints build metadata
	 * #if defined because i can delete this later,
	 * and forget about it
	 */

	printmsg(" -----------------------------------\n");
	printmsg(" --- Welcome to TheWired kernel! ---\n");
	printmsg(" -----------------------------------\n");
	printmsg(" Build date: %s                     \n", BUILD_TIME);
	printmsg(" C compiler version: %s             \n", CC_VERSION);
	printmsg(" Assembler version: %s              \n", AS_VERSION);
	printmsg(" Arch: %s                           \n", ARCH);
	printmsg(" -----------------------------------\n");
#endif

	while (1) {
		__asm__ volatile("hlt");
	}
}
