#include <stdint.h>
#include <framebuffer.h>
#include <keyboard.h>
#include <tty.h>

#include <helpers.h>

int _main_test(void) {
    framebuffer_init();
    keyboard_init();

    welcome_msg();

    return 1;
}
