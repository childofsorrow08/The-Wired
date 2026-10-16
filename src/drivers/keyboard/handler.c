#include <stdint.h>

#include <ports.h>
#include <private/keyboard.h>
#include <helpers/keyboard_maps/us.h>

void keyboard_irq_handler(void) {
    uint8_t scan = inb(PORT_PS2_DATA);

    if (kb.pause_remaining) { --kb.pause_remaining; goto done; }
    if (scan == 0xE1) { kb.pause_remaining = 5; goto done; }
    if (scan == 0xE0) { kb.extended = 1; goto done; }
    if (kb.extended) { kb.extended = 0; goto done; }

    uint8_t released = (scan & 0x80u) != 0;
    uint8_t code = scan & 0x7Fu;
    if (code == 0x2A) { kb.left_shift = !released; goto done; }
    if (code == 0x36) { kb.right_shift = !released; goto done; }
    if (code == 0x3A) { if (!released) kb.caps_lock = !kb.caps_lock; goto done; }
    if (released) goto done;

    char c = us_normal_map[code];
    if (!c) goto done;

    uint8_t shift = kb.left_shift || kb.right_shift;
    if (c >= 'a' && c <= 'z') {
        if ((shift != 0) != (kb.caps_lock != 0)) c = (char)(c - 'a' + 'A');
    } else if (shift && us_shift_map[code]) {
        c = us_shift_map[code];
    }
    keyboard_enqueue(c);

done:
    outb(PORT_PIC1_COMMAND, 0x20);
}
