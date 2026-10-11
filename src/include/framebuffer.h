#if !defined(FRAMEBUFFER_H)
#define FRAMEBUFFER_H

typedef struct {
    uint32_t *base;
    uint32_t width;
    uint32_t height;
    uint32_t pitch_pixels;
} framebuffer_t;

extern void framebuffer_init(void);
extern void framebuffer_putchar(int x, int y, char c, uint32_t color);
extern void framebuffer_putstring(int x, int y, const char* str, uint32_t color);

#endif
