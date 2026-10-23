#ifndef FS_H
#define FS_H

#include <fs/fat16.h>

typedef enum {
    FS_UNKNOWN = 0,
    FS_FAT16
} fs_type_t;

/* Probe the filesystem at LBA 0 of the primary ATA disk. */
fs_type_t fs_detect(void);
#endif
