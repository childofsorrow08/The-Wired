#include <stdint.h>

#include <ata.h>
#include <ports.h>

static int ata_wait_bsy(void) {
    for (uint32_t i = 0; i < 1000000; ++i) {
        uint8_t status = inb(ATA_PRIMARY_IO + ATA_REG_STATUS);
        if (status == 0 || status == 0xFF) return -1;
        if (!(status & ATA_SR_BSY)) return 0;
    }
    return -1;
}

static int ata_wait_drq(void) {
    uint8_t status;

    for (uint32_t i = 0; i < 1000000; ++i) {
        status = inb(ATA_PRIMARY_IO + ATA_REG_STATUS);
        if (status == 0 || status == 0xFF) return -1;
        if (status & ATA_SR_BSY) continue;

        if (status & ATA_SR_ERR) { return -1; }
        if (status & ATA_SR_DF) { return -2; }
        if (!(status & ATA_SR_BSY) && (status & ATA_SR_DRQ)) { return 0; }
    }
    return -3;
}

int ata_pio_read28(uint32_t lba, uint8_t sector_count, void *buffer) {
    if (lba > 0x0FFFFFFF) { return -1; }
    if (sector_count == 0) { return -2; }

    uint16_t *dst = (uint16_t *)buffer;

    outb(ATA_PRIMARY_IO + ATA_REG_HDDEVSEL, 0xE0 | ((lba >> 24) & 0x0F));
    /* BIOS may leave another drive selected. Allow 400 ns for selection. */
    for (unsigned i = 0; i < 4; ++i) (void)inb(0x3F6);
    if (ata_wait_bsy() != 0) { return -3; }

    outb(ATA_PRIMARY_IO + ATA_REG_SECCOUNT0, sector_count);
    outb(ATA_PRIMARY_IO + ATA_REG_LBA0, (uint8_t)(lba));
    outb(ATA_PRIMARY_IO + ATA_REG_LBA1, (uint8_t)(lba >> 8));
    outb(ATA_PRIMARY_IO + ATA_REG_LBA2, (uint8_t)(lba >> 16));
    outb(ATA_PRIMARY_IO + ATA_REG_COMMAND, ATA_CMD_READ_PIO);

    for (uint32_t sector = 0; sector < sector_count; sector++) {
        if (ata_wait_drq() != 0) { return -3; }

        for (uint32_t i = 0; i < 256; i++) { *dst++ = inw(ATA_PRIMARY_IO + ATA_REG_DATA); }
    }

    return 0;
}
