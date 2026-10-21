#include <helpers.h>
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
