#include <stdint.h>
#include <stddef.h>

#include <helpers.h>
#include <framebuffer.h>
#include <keyboard.h>
#include <helpers/colors.h>
#include <tty.h>

void process_command(char buffer[256]) {
    int i = 0;
    if (strcmp(buffer, "help") == 0) {
        tty_print("Available commands: \n");
        i++;
    }

    if (strcmp(buffer, "clear") == 0) {
        // todo
        i++;
    }

    if (strcmp(buffer, "info") == 0) {
        tty_print("hi hello\n");
        i++;
    }

    if(i == 0) tty_print("Unknown command: %s \n", buffer);
}

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

	tty_set_color(COLOR_CYAN);
	tty_print("cyan\n");
	tty_set_color(COLOR_DARKGREEN);
	tty_print("dark green\n");
	tty_set_color(COLOR_MAGENTA);
	tty_print("magenta\n");
	tty_def_color();

    tty_print("Keyboard test:\n");
    tty_print("> ");

    char cmd_buffer[256];
    int cmd_index = 0;

	while(1) {
        char c = keyboard_getchar();
        tty_input(c);

        // Probably a bit messy, but i will rewrite shell in future
        if (c == '\n') {
            cmd_buffer[cmd_index] = '\0';
            process_command(cmd_buffer);
            tty_print("> ");
            cmd_index = 0;
        } else if (c == '\b') {
            if (cmd_index > 0) {
                cmd_index--;
            }
        } else {
            if (cmd_index < 256 - 1) {
                cmd_buffer[cmd_index] = c;
                cmd_index++;
            }
        }
    }
}
