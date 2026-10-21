#include <stdint.h>

#include <ata.h>
#include <ports.h>

static int ata_wait_bsy(void) {
    uint8_t status;
    do { status = inb(ATA_PRIMARY_IO + ATA_REG_STATUS); } while (status & ATA_SR_BSY);
    return 0;
}

static int ata_wait_drq(void) {
    uint8_t status;

    while(1) {
        status = inb(ATA_PRIMARY_IO + ATA_REG_STATUS);

        if (status & ATA_SR_ERR)
            return -1;

        if (status & ATA_SR_DF)
            return -2;

        if (!(status & ATA_SR_BSY) && (status & ATA_SR_DRQ))
            return 0;
    }
}

int ata_pio_read28(uint32_t lba, uint8_t sector_count, void *buffer) {
    if (lba > 0x0FFFFFFF)
        return -1;

    if (sector_count == 0)
        return -2;

    uint16_t *dst = (uint16_t *)buffer;

    ata_wait_bsy();

    outb(
        ATA_PRIMARY_IO + ATA_REG_HDDEVSEL,
        0xE0 | ((lba >> 24) & 0x0F)
    );

    outb(
        ATA_PRIMARY_IO + ATA_REG_SECCOUNT0,
        sector_count
    );

    outb(
        ATA_PRIMARY_IO + ATA_REG_LBA0,
        (uint8_t)(lba)
    );

    outb(
        ATA_PRIMARY_IO + ATA_REG_LBA1,
        (uint8_t)(lba >> 8)
    );

    outb(
        ATA_PRIMARY_IO + ATA_REG_LBA2,
        (uint8_t)(lba >> 16)
    );

    outb(
        ATA_PRIMARY_IO + ATA_REG_COMMAND,
        ATA_CMD_READ_PIO
    );

    for (uint32_t sector = 0; sector < sector_count; sector++) {
        if (ata_wait_drq() != 0)
            return -3;

        for (uint32_t i = 0; i < 256; i++) {
            *dst++ = inw(ATA_PRIMARY_IO + ATA_REG_DATA);
        }
    }

    return 0;
}
