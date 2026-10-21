#include <stdint.h>

#include <fs/fat16.h>
#include <tty.h>

void testfs(int result, fat16_fs_t fs, fat16_dir_entry_t entry) {
    if (result != 0) {
        tty_print("FAT16 init failed: %d\n", result);
    } else {
        tty_print("FAT16 initialized\n");

        result = fat16_find_root(
            &fs,
            "HELLO   TXT",
            &entry
        );

        if (result == 0) {
            tty_print("Found HELLO.TXT\n");
            tty_print("Size: %d bytes\n", entry.file_size);
            tty_print(
                "First cluster: %d\n",
                entry.first_cluster
            );
        } else {
            tty_print(
                "HELLO.TXT not found: %d\n",
                result
            );
        }
    }
}
