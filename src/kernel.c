#include <stdint.h>

#include <helpers.h>
#include <framebuffer.h>
#include <keyboard.h>
#include <tty.h>

#include <fs/fat16.h>

// test functions
extern void process_command(char buffer[256]);
extern void testfs(int result, fat16_fs_t fs, fat16_dir_entry_t entry);
extern void userspace_init(void (*entry)(void)); // src/boot/userspace.S
extern void user_test(void);

void _main(void) {
    framebuffer_init();
    keyboard_init();

    welcome_msg();

    fat16_fs_t fs;
    fat16_dir_entry_t entry;
    int result = fat16_init(&fs);

    testfs(result, fs, entry);

    userspace_init(user_test);

    while(1) {
        __asm__ volatile ("hlt");
    }
}
