#if !defined(PRIVATE_FAT16_H)
#define PRIVATE_FAT16_H

#define FAT16_SECTOR_SIZE 512
#define FAT16_ENTRY_FREE      0x00
#define FAT16_ENTRY_DELETED   0xE5
#define FAT16_ATTR_LFN        0x0F

extern int fat16_name_match(const fat16_dir_entry_t *entry,
                            const char *name);

extern int fat16_find_root(fat16_fs_t *fs,
                           const char *name,
                           fat16_dir_entry_t *result);

#endif
