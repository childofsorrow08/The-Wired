#include <stdint.h>

#include <ports.h>
#include <private/keyboard.h>

// Discard stale controller bytes
// not really needed
void keyboard_init(void) {
    for (unsigned int i = 0; i < 32; ++i) {
        if (!(inb(PORT_PS2_STATUS) & 1u)) break;
        (void)inb(PORT_PS2_DATA);
    }
}
