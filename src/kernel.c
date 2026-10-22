#include <stdint.h>

#include <helpers.h>
#include <framebuffer.h>
#include <keyboard.h>
#include <tty.h>
#include <elf.h>

#include <fs/fat16.h>

extern int _main_test(void);

void _main(void) {

#if defined(TESTS)
    int i = _main_test();   // basically another _main
    if(i == 1) goto exec;   // but with tests
    if(i == 2) goto end;    // so i dont need to edit kernel.c
#endif

    framebuffer_init();
    keyboard_init();

    welcome_msg();

    fat16_fs_t fs;
    fat16_dir_entry_t entry;
    int result = fat16_init(&fs);

    // now we're cooking
exec:

    // kernel NEVER wants to be here
end:
    while(1) { __asm__ volatile ("hlt"); }
}
