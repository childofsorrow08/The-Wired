#include <stdint.h>

void user_test(void) {
    const char msg[] = "i think this shit works!\n";

    uint32_t result;

    __asm__ volatile (
        "int $0x80"
        : "=a"(result)
        : "a"(1), // 1 - write
          "b"(1),
          "c"(msg),
          "d"(sizeof(msg) - 1)
        : "memory"
    );

    while(1) {
        __asm__ volatile ("nop");
    }
}
