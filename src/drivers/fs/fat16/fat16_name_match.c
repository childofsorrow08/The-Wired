#include <stdint.h>
#include <fs/fat16.h>

/*
 * Compare a FAT 8.3 directory entry against
 * an 11-character FAT filename
 *
 * "HELLO.TXT" becomes "HELLO   TXT"
 *
 * First 8 bytes filename, last 3 bytes extension
 */
int fat16_name_match(const fat16_dir_entry_t *entry,
                    const char *name) {
    for (uint32_t i = 0; i < 8; i++) {
        if (entry->name[i] != (uint8_t)name[i])
            return 0;
    }

    for (uint32_t i = 0; i < 3; i++) {
        if (entry->extension[i] != (uint8_t)name[8 + i])
            return 0;
    }

    return 1;
}
