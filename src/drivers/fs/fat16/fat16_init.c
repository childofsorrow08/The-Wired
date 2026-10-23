#include <stdint.h>

#include <string.h>
#include <fs/fat16.h>
#include <private/fs/fat16.h>
#include <ata.h>

int fat16_init(fat16_fs_t *fs) {
    uint8_t sector[FAT16_SECTOR_SIZE];

    if (fs == 0) { return -1; }
    if (ata_pio_read28(0, 1, sector) != 0) { return -2; } // current disk img contains the FAT16 filesystem directly from LBA 0
    if (sector[510] != 0x55 || sector[511] != 0xAA) { return -3; } // standard boot sector signature

    // BPB begins at byte 0 of the boot sector
    memcpy(&fs->bpb, sector, sizeof(fat16_bpb_t));

    // ATA implementation currently assumes 512-byte sectors
    if (fs->bpb.bytes_per_sector != FAT16_SECTOR_SIZE) { return -4; }
    if (fs->bpb.sectors_per_cluster == 0) { return -5; }
    if (fs->bpb.reserved_sectors == 0) { return -6; }
    if (fs->bpb.fat_count == 0) { return -7; }
    if (fs->bpb.sectors_per_fat == 0) {return -8; }
    if (fs->bpb.root_entry_count == 0) { return -9; }

    fs->fat_start_lba = fs->bpb.reserved_sectors;

    // calculate how many sectors are occupied
    // every directory entry is exactly 32 bytes
    uint32_t root_bytes = (uint32_t)fs->bpb.root_entry_count *
                        sizeof(fat16_dir_entry_t);

    fs->root_sector_count =
        (root_bytes + fs->bpb.bytes_per_sector - 1) /
        fs->bpb.bytes_per_sector;

    fs->root_start_lba =
        fs->fat_start_lba +
        ((uint32_t)fs->bpb.fat_count *
        fs->bpb.sectors_per_fat);

    fs->data_start_lba =
        fs->root_start_lba +
        fs->root_sector_count;

    return 0;
}
