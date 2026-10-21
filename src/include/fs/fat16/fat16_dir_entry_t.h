#if !defined(FAT16_DIR_ENTRY_T_H)
#define FAT16_DIR_ENTRY_T_H

typedef struct __attribute__((packed)) {
    uint8_t  name[8];
    uint8_t  extension[3];

    uint8_t  attributes;

    uint8_t  reserved;
    uint8_t  creation_time_tenths;

    uint16_t creation_time;
    uint16_t creation_date;
    uint16_t access_date;

    /*
     * Used by FAT32.
     * Should normally be zero on FAT16.
     */
    uint16_t reserved_fat32;

    uint16_t modification_time;
    uint16_t modification_date;

    uint16_t first_cluster;

    uint32_t file_size;
} fat16_dir_entry_t;

#endif
