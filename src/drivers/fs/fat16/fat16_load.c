#include <stdint.h>
#include <fs/fat16.h>

int fat16_load(fat16_fs_t *fs,
              const char *name,
              void *buffer,
              uint32_t buffer_size,
              uint32_t *file_size) {
    fat16_dir_entry_t entry;

    if (fat16_find_path(fs, name, &entry) != 0) { return -1; }
    if (entry.file_size > buffer_size) { return -1; }
    if (fat16_read_file(fs, &entry, buffer, buffer_size) != 0) { return -1; }
    if (file_size) { *file_size = entry.file_size; }

    return 0;
}
