#include <stdint.h>
#include <framebuffer.h>
#include <keyboard.h>
#include <tty.h>

extern int _main_test(void);

void _main(void) {

#if defined(DEBUG)
    int i = _main_test();   // basically another _main
    if(i == 1) goto exec;   // but with tests
    if(i == 2) goto end;    // so i dont need to edit kernel.c
#endif

    framebuffer_init();
    keyboard_init();

exec:   // now we're cooking

end:    // kernel NEVER wants to be here
    while(1) { __asm__ volatile ("hlt"); }
}
