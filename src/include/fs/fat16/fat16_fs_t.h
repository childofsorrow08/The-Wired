#if !defined(FAT16_FS_T_H)
#define FAT16_FS_T_H

typedef struct {
    fat16_bpb_t bpb;

    uint32_t fat_start_lba;

    uint32_t root_start_lba;
    uint32_t root_sector_count;

    uint32_t data_start_lba;
} fat16_fs_t;

#endif
