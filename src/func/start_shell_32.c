#include <fs.h>
#include <elf.h>
#include <tty.h>

/* Keep the input separate from the shell's linked load address. */
static unsigned char shell_image[1024 * 1024] __attribute__((aligned(16)));

extern void userspace_init(void (*entry)(void));

void start_shell(void) {
    fat16_fs_t fs;
    uint32_t size;
    if (fs_detect() != FS_FAT16) {
        tty_print("[FS] Unsupported or unreadable filesystem\n");
        return;
    }
    if (fat16_init(&fs)) {
        tty_print("[FS] FAT16 mount failed\n");
        return;
    }
    tty_print("[FS] FAT16 mounted\n");
    if (fat16_load(&fs, "/bin/shell.elf", shell_image, sizeof(shell_image), &size)) {
        tty_print("[FS] Cannot read /bin/shell.elf\n");
        return;
    }
    void *entry = elf_load(shell_image, size);
    if (!entry) {
        tty_print("[ELF] Invalid shell executable\n");
        return;
    }
    tty_print("[ELF] Starting /bin/shell.elf\n");
    userspace_init((void (*)(void))entry);
}
