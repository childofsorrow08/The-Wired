#include <fs.h>

fs_type_t fs_detect(void) {
    fat16_fs_t candidate;
    return fat16_init(&candidate) == 0 ? FS_FAT16 : FS_UNKNOWN;
}
