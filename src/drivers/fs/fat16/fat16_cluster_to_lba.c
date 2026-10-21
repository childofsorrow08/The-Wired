#include <stdint.h>
#include <fs/fat16.h>
#include <private/fs/fat16.h>

uint32_t fat16_cluster_to_lba(const fat16_fs_t *fs, uint16_t cluster) {
    return fs->data_start_lba + ((uint32_t)(cluster - 2) * fs->bpb.sectors_per_cluster);
}
