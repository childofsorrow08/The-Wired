#ifndef FAT16_H
#define FAT16_H

#include <fs/fat16/fat16_bpb_t.h>
#include <fs/fat16/fat16_dir_entry_t.h>
#include <fs/fat16/fat16_fs_t.h>

// returns 0 on success
// returns <0 on error
int fat16_init(fat16_fs_t *fs);

// Search for a file in the FAT16 root directory.
// Name must be in 8.3 format, e.g. "HELLO   TXT"
// Returns 0 if found, <0 value on error
int fat16_find_root(fat16_fs_t *fs,
                    const char *name,
                    fat16_dir_entry_t *result
);

#endif
