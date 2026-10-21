#include <stdint.h>
#include <fs/fat16.h>
#include <private/fs/fat16.h>

int fat16_is_eof(uint16_t cluster) {
    return cluster >= FAT16_CLUSTER_EOF_MIN;
}
