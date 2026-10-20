#include <stdint.h>
#include <stddef.h>

#include <helpers.h>
#include <framebuffer.h>
#include <keyboard.h>
#include <helpers/colors.h>
#include <tty.h>
#include <ata.h>

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

    welcome_msg();


    uint8_t sector[512];

    int result = ata_pio_read28(0, 1, sector);

    if (result == 0) {
        tty_print("ATA read successful\n");

        tty_print("Signature 1: %x\n", sector[510]);
        tty_print("Signature 2: %x\n", sector[511]);
    } else {
        tty_print("ATA read failed: %d\n", result);
    }

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
