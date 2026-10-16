#include <stdint.h>
#include <private/keyboard.h>

char keyboard_getchar(void) {
    while(1) {
        __asm__ volatile ("cli" ::: "memory");

        if (kb.key_tail != kb.key_head) {
            char c = kb.key_buffer[kb.key_tail];
            kb.key_tail = (kb.key_tail + 1u) & (KEYBOARD_BUFFER_SIZE - 1u);
            __asm__ volatile ("sti" ::: "memory");
            return c;
        }

        __asm__ volatile ("sti; hlt" ::: "memory");
    }
}
