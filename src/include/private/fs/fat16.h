#if !defined(PRIVATE_FAT16_H)
#define PRIVATE_FAT16_H

#define FAT16_SECTOR_SIZE           512
#define FAT16_ENTRY_FREE            0x00
#define FAT16_ENTRY_DELETED         0xE5
#define FAT16_ATTR_LFN              0x0F
#define FAT16_CLUSTER_FREE          0x0000
#define FAT16_CLUSTER_BAD           0xFFF7
#define FAT16_CLUSTER_EOF_MIN       0xFFF8
#define FAT16_CLUSTER_EOF_MAX       0xFFFF

extern int fat16_name_match(const fat16_dir_entry_t *entry,
                            const char *name);

extern int fat16_find_root(fat16_fs_t *fs,
                           const char *name,
                           fat16_dir_entry_t *result);

extern uint32_t fat16_cluster_to_lba(const fat16_fs_t *fs,
                                     uint16_t cluster);

extern int fat16_next_cluster(const fat16_fs_t *fs,
                              uint16_t cluster,
                              uint16_t *next);

extern int fat16_is_eof(uint16_t cluster);

extern int fat16_read_file(fat16_fs_t *fs,
                           const fat16_dir_entry_t *entry,
                           void *buffer,
                           uint32_t buffer_size);

#endif
