#include <stdint.h>

#include <helpers.h>
#include <framebuffer.h>
#include <keyboard.h>
#include <tty.h>

#include <fs/fat16.h>

// test functions
extern void process_command(char buffer[256]);
extern void testfs(int result, fat16_fs_t fs, fat16_dir_entry_t entry);

void _main(void) {
    framebuffer_init();
    keyboard_init();

    welcome_msg();

    fat16_fs_t fs;
    fat16_dir_entry_t entry;
    int result = fat16_init(&fs);

    testfs(result, fs, entry);

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
