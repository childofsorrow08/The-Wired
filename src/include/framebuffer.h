#if !defined(FRAMEBUFFER_H)
#define FRAMEBUFFER_H

typedef struct {
    uint32_t *base;
    uint32_t width;
    uint32_t height;
    uint32_t pitch_pixels;
} framebuffer_t;

extern void framebuffer_init(void);

#endif
