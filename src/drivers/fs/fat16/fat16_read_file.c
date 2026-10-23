#include <stdint.h>
#include <fs/fat16.h>
#include <private/fs/fat16.h>
#include <string.h>
#include <ata.h>

int fat16_read_file(fat16_fs_t *fs,
                    const fat16_dir_entry_t *entry,
                    void *buffer,
                    uint32_t buffer_size) {

    if (!fs || !entry || !buffer) {return -1; }
    if (entry->attributes & 0x18) { return -1; }
    if (entry->file_size > buffer_size) { return -2; }
    if (entry->file_size == 0) { return 0; }

    uint16_t cluster = entry->first_cluster;
    uint32_t remaining = entry->file_size;
    uint8_t *dst = (uint8_t *)buffer;

    uint8_t sector[FAT16_SECTOR_SIZE];

    while (remaining > 0) {
        if (cluster < 2 || cluster >= fs->cluster_count + 2 || cluster >= 0xFFF0) { return -3; }
        if (cluster == FAT16_CLUSTER_BAD) { return -4; }
        if (fat16_is_eof(cluster)) { return -5; }

        uint32_t cluster_lba = fat16_cluster_to_lba(fs, cluster);

        for (uint32_t i = 0;
             i < fs->bpb.sectors_per_cluster && remaining > 0;
             i++) {
            if (ata_pio_read28(cluster_lba + i, 1, sector) != 0)
                return -6;

            uint32_t to_copy = remaining;

            if (to_copy > FAT16_SECTOR_SIZE)
                to_copy = FAT16_SECTOR_SIZE;

            memcpy(dst, sector, to_copy);

            dst += to_copy;
            remaining -= to_copy;
        }

        if (remaining == 0) { break; }

        uint16_t next;

        if (fat16_next_cluster(fs, cluster, &next) != 0) { return -7; }
        if (next == FAT16_CLUSTER_FREE) { return -8; }
        if (next == FAT16_CLUSTER_BAD) { return -9; }
        if (fat16_is_eof(next)) { return -10; }

        cluster = next;
    }

    return 0;
}
