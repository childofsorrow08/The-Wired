#include <stdint.h>

#include <helpers.h>
#include <framebuffer.h>
#include <keyboard.h>
#include <tty.h>
#include <elf.h>

#include <fs/fat16.h>

void _main(void) {
    framebuffer_init();
    keyboard_init();

    welcome_msg();

    fat16_fs_t fs;
    fat16_dir_entry_t entry;
    int result = fat16_init(&fs);

    // now we're cooking

    while(1) {
        __asm__ volatile ("hlt");
    }
}
