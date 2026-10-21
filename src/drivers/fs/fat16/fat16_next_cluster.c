#include <stdint.h>
#include <fs/fat16.h>
#include <private/fs/fat16.h>
#include <ata.h>

int fat16_next_cluster(const fat16_fs_t *fs, uint16_t cluster, uint16_t *next) {
    uint8_t sector[FAT16_SECTOR_SIZE];
    uint32_t fat_offset = (uint32_t)cluster * 2;
    uint32_t fat_sector = fs->fat_start_lba + (fat_offset / fs->bpb.bytes_per_sector);
    uint32_t entry_offset = fat_offset % fs->bpb.bytes_per_sector;
    if (ata_pio_read28(fat_sector, 1, sector) != 0) { return -1; }
    *next = (uint16_t)sector[entry_offset] | ((uint16_t)sector[entry_offset + 1] << 8);

    return 0;
}
