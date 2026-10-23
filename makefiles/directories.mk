SRC_DIR := $(abspath $(ROOT_DIR)/src)

MAKECFG_DIR := $(ROOT_DIR)/makefiles
SCRIPTS_DIR := $(ROOT_DIR)/scripts

BUILD_DIR := $(ROOT_DIR)/build
X32_BUILD_DIR := $(BUILD_DIR)/x32
X64_BUILD_DIR := $(BUILD_DIR)/x64
X32_OBJ_DIR := $(X32_BUILD_DIR)/obj
X64_OBJ_DIR := $(X64_BUILD_DIR)/obj
X32_BIN_DIR := $(X32_BUILD_DIR)/bin
X64_BIN_DIR := $(X64_BUILD_DIR)/bin

X32_ISO_DIR := $(X32_BUILD_DIR)/iso
X32_ISO_IMG := $(X32_BIN_DIR)/wired.iso

X64_ISO_DIR := $(X64_BUILD_DIR)/iso
X64_ISO_IMG := $(X64_BIN_DIR)/wired.iso

X32_ELF := $(X32_BIN_DIR)/wired.elf
X64_ELF := $(X64_BIN_DIR)/wired.elf

LD_SCRIPT := $(MAKECFG_DIR)/linker/linker.ld
GRUB_CFG := $(MAKECFG_DIR)/grub/grub.cfg
DISK_IMG := $(BUILD_DIR)/disk.img

# Used if you don't have cross compilers in your PATH
# and downloaded it via scripts
I686-TOOLS-DIR := $(BUILD_DIR)/i686-elf-tools
X86_64-TOOLS-DIR := $(BUILD_DIR)/x86_64-elf-tools

# Used only for GitHub Actions
WEBKERNEL_DIR := $(ROOT_DIR)/web/kernel
RELEASE_BIN_DIR := $(BUILD_DIR)/release

RELEASE_32_BIN_DIR := $(RELEASE_BIN_DIR)/x32
RELEASE_64_BIN_DIR := $(RELEASE_BIN_DIR)/x64
