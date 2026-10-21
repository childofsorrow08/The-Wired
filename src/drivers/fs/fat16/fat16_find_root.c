#include <stdint.h>
#include <fs/fat16.h>
#include <private/fs/fat16.h>
#include <string.h>
#include <ata.h>

int fat16_find_root(fat16_fs_t *fs,
                    const char *name,
                    fat16_dir_entry_t *result) {
    uint8_t sector[FAT16_SECTOR_SIZE];

    if (fs == 0 || name == 0 || result == 0)
        return -1;

    // Walk through every sector
    // FAT16 root directory
    for (uint32_t sector_index = 0;
        sector_index < fs->root_sector_count;
        sector_index++) {

        uint32_t lba = fs->root_start_lba + sector_index;

        if (ata_pio_read28(lba, 1, sector) != 0)
            return -2;

        // num of directory entries contained in one sector
        // usually 512 / 32 = 16
        uint32_t entries_per_sector =
            fs->bpb.bytes_per_sector /
            sizeof(fat16_dir_entry_t);

        for (uint32_t entry_index = 0;
            entry_index < entries_per_sector;
            entry_index++) {

            fat16_dir_entry_t *entry =
                (fat16_dir_entry_t *)(sector +(entry_index * sizeof(fat16_dir_entry_t)));

            // 0x00 = entry is unused and no more entries after it
            if (entry->name[0] == FAT16_ENTRY_FREE)
                return -3;

            // Deleted file
            if (entry->name[0] == FAT16_ENTRY_DELETED)
                continue;

            // Long File Name entry,
            // currently supported only FAT 8.3 names
            if ((entry->attributes & 0x0F) == FAT16_ATTR_LFN)
                continue;

            // compare the raw FAT 8.3 filename
            if (!fat16_name_match(entry, name))
                continue;

            memcpy(result, entry, sizeof(fat16_dir_entry_t));

            return 0;
        }
    }
    return -3;
}
