#include <stdint.h>
#include <private/keyboard.h>

void enqueue(char c) {
    unsigned int next = (kb.key_head + 1u) & (KEYBOARD_BUFFER_SIZE - 1u);
    if (next == kb.key_tail) return;
    kb.key_buffer[kb.key_head] = c;
    kb.key_head = next;
}
