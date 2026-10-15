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

    	tty_print(" -----------------------------------\n");
    	tty_print(" --- Welcome to TheWired kernel! ---\n");
    	tty_print(" -----------------------------------\n");
    	tty_print(" Build date: %s                     \n", BUILD_TIME);
    	tty_print(" C compiler version: %s             \n", CC_VERSION);
    	tty_print(" Assembler version: %s              \n", AS_VERSION);
    	tty_print(" Arch: %s                           \n", ARCH);
    	tty_print(" -----------------------------------\n");
	#endif

    tty_print("Keyboard test:\n");
    tty_print("> ");

	while(1) {
        char c = keyboard_getchar();
        tty_input(c);
    }
}
