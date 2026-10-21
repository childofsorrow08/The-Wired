#include <elf.h>
#include <fs/fat16.h>
#include <tty.h>

#define ELF_BUFFER_ADDRESS 0x00200000
#define ELF_BUFFER_SIZE    (128 * 1024)

extern void userspace_init(void (*entry)(void)); // src/boot/userspace.S

void load_yes_elf(fat16_dir_entry_t entry, fat16_fs_t fs) {
    if (fat16_find_root(&fs, "YES     ELF", &entry) != 0) {
        tty_print("YES.ELF not found\n");
        return;
    }

    tty_print("Found YES.ELF\n");
    tty_print("Size: %d bytes\n", entry.file_size);

    if (entry.file_size > ELF_BUFFER_SIZE) {
        tty_print("YES.ELF is too large\n");
        return;
    }

    void *elf_buffer = (void *)ELF_BUFFER_ADDRESS;

    if (fat16_read_file(&fs, &entry, elf_buffer, ELF_BUFFER_SIZE) != 0) {
        tty_print("Failed to read YES.ELF\n");
        return;
    }

    tty_print("YES.ELF read into memory\n");

    void *entry_point = elf_load(
        elf_buffer,
        entry.file_size
    );

    if (entry_point == 0) {
        tty_print("Failed to load YES.ELF\n");
        return;
    }

    tty_print(
        "ELF entry point: %x\n",
        (uint32_t)entry_point
    );

    userspace_init(
        (void (*)(void))entry_point
    );
}
