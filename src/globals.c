#include <stdint.h>

#include <helpers/colors.h>

// Multiboot | For use anywhere where multiboot data is needed
unsigned long multiboot_info_ptr = 0;

// Framebuffer | For use in framebuffer driver
#include <framebuffer.h>
framebuffer_t fb = { 0, 0, 0, 0 };

// Keyboard | For use in keyboard driver
#include <private/keyboard.h>
keyboard_t kb = { "0", 0, 0, 0, 0, 0, 0, 0 };

// TTY | For use in TTY driver
#include <private/tty.h>
tty cursor = { 0, 0, COLOR_WHITE };
