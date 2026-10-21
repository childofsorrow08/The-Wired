#include <stdint.h>

#include <helpers.h>
#include <framebuffer.h>
#include <keyboard.h>
#include <tty.h>
#include <elf.h>

#include <fs/fat16.h>

// test functions || TODO: delete commented shit
// extern void process_command(char buffer[256]); // ALREADY UNUSED
// extern void testfs(int result, fat16_fs_t fs, fat16_dir_entry_t entry);
// extern void userspace_init(void (*entry)(void)); // src/boot/userspace.S
// extern void user_test(void);
extern void load_yes_elf(fat16_dir_entry_t entry, fat16_fs_t fs);

void _main(void) {
    framebuffer_init();
    keyboard_init();

    welcome_msg();

    fat16_fs_t fs;
    fat16_dir_entry_t entry;
    int result = fat16_init(&fs);

    // now we're cooking
    load_yes_elf(entry, fs);

    while(1) {
        __asm__ volatile ("hlt");
    }
}
