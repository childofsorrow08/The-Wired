#include <stdint.h>
#include <stddef.h>

#include <framebuffer.h>
#include <keyboard.h>
#include <tty.h>

void _main(void) {
    framebuffer_init();
    keyboard_init();

	#if defined(BUILD_TIME) || \
		defined(CC_VERSION) || \
		defined(AS_VERSION) || \
		defined(ARCH)

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

    printmsg("Keyboard test:\n");
    printmsg("> ");

	while(1) {
        char c = keyboard_getchar();
        tty_input(c);
    }
}
