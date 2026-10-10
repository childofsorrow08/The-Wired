#include <stdint.h>

#include <resources/font_8x16.h>

const unsigned char *get_font_glyph(char c) {
    return &font_8x16[(unsigned char)c * 16];
}
