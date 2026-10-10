#include <stdint.h>

#include <multiboot.h>
#include <framebuffer.h>
#include <variables.h>
#include <helpers.h>

void framebuffer_putstring(int x, int y, const char* str, uint32_t color) {
    int cursor_x = x;
    while (*str) {
        framebuffer_putchar(cursor_x, y, *str, color);
        cursor_x += 8;
        str++;
    }
}
