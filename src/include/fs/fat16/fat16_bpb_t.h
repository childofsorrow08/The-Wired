#if !defined(FAT16_BPB_T_H)
#define FAT16_BPB_T_H

/*
 * fat16 bios parameter block,
 * extended boot record
 *
 * maps directly onto beginning
 * of fat16 boot sector
 */
typedef struct __attribute__((packed)) {
    uint8_t  jump[3];
    uint8_t  oem_name[8];

    uint16_t bytes_per_sector;
    uint8_t  sectors_per_cluster;
    uint16_t reserved_sectors;
    uint8_t  fat_count;
    uint16_t root_entry_count;
    uint16_t total_sectors_16;
    uint8_t  media;
    uint16_t sectors_per_fat;
    uint16_t sectors_per_track;
    uint16_t head_count;
    uint32_t hidden_sectors;
    uint32_t total_sectors_32;

    // extended boot record
    uint8_t  drive_number;
    uint8_t  reserved;
    uint8_t  boot_signature;
    uint32_t volume_id;
    uint8_t  volume_label[11];
    uint8_t  fs_type[8];
} fat16_bpb_t;

#endif
