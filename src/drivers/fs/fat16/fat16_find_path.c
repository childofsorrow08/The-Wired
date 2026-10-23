#include <fs/fat16.h>
#include <private/fs/fat16.h>
#include <ata.h>
#include <string.h>

/* cluster 0 denotes the fixed root directory. */
static int find_entry(fat16_fs_t *fs, uint16_t cluster, const char *name,
                      fat16_dir_entry_t *result) {
    uint8_t sector[512];
    uint32_t budget = fs->cluster_count;
    do {
        uint32_t lba, count;
        if (!cluster) {
            lba = fs->root_start_lba;
            count = fs->root_sector_count;
        } else {
            if (cluster < 2 || cluster >= 0xFFF0 ||
                cluster >= fs->cluster_count + 2 || !budget--)
                return -1;
            lba = fat16_cluster_to_lba(fs, cluster);
            count = fs->bpb.sectors_per_cluster;
        }
        for (uint32_t s = 0; s < count; ++s) {
            if (ata_pio_read28(lba + s, 1, sector)) return -1;
            for (uint32_t i = 0; i < 16; ++i) {
                if (!cluster && s * 16 + i >= fs->bpb.root_entry_count)
                    return -1;
                fat16_dir_entry_t *e = (fat16_dir_entry_t *)sector + i;
                if (!e->name[0]) return -1;
                if (e->name[0] == 0xE5 || (e->attributes & 0x08)) continue;
                if (fat16_name_match(e, name)) {
                    memcpy(result, e, sizeof(*result));
                    return 0;
                }
            }
        }
        if (!cluster) break;
        if (fat16_next_cluster(fs, cluster, &cluster)) return -1;
    } while (!fat16_is_eof(cluster));
    return -1;
}

int fat16_find_path(fat16_fs_t *fs, const char *path,
                     fat16_dir_entry_t *result) {
    uint16_t directory = 0;
    if (!fs || !path || !result) return -1;
    while (*path == '/') ++path;
    if (!*path) return -1;
    while (*path) {
        char name[11];
        unsigned base = 0, ext = 0;
        int dot = 0;
        for (unsigned i = 0; i < sizeof(name); ++i) name[i] = ' ';
        while (*path && *path != '/') {
            unsigned char c = *path++;
            if (c == '.') {
                if (dot || !base) return -1;
                dot = 1;
                continue;
            }
            if (c <= ' ' || c == '\\' || c == ':' || c == '*' || c == '?')
                return -1;
            if (c >= 'a' && c <= 'z') c -= 'a' - 'A';
            if (!dot) {
                if (base == 8) return -1;
                name[base++] = c;
            } else {
                if (ext == 3) return -1;
                name[8 + ext++] = c;
            }
        }
        if (!base || find_entry(fs, directory, name, result)) return -1;
        if (*path == '/') {
            if (!(result->attributes & 0x10)) return -1;
            directory = result->first_cluster;
            if (directory < 2) return -1;
            while (*path == '/') ++path;
        }
    }
    return 0;
}
