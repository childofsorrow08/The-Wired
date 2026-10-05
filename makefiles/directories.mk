ROOT_DIR := $(abspath $(SRC_DIR)/..)

MAKECFG_DIR := $(ROOT_DIR)/makefiles

BUILD_DIR := $(ROOT_DIR)/build
X32_BUILD_DIR := $(BUILD_DIR)/x32
X64_BUILD_DIR := $(BUILD_DIR)/x64
X32_OBJ_DIR := $(X32_BUILD_DIR)/obj
X64_OBJ_DIR := $(X64_BUILD_DIR)/obj
X32_BIN_DIR := $(X32_BUILD_DIR)/bin
X64_BIN_DIR := $(X64_BUILD_DIR)/bin

X32_ISO_DIR := $(X32_BUILD_DIR)/iso
X32_ISO_IMG := $(X32_BIN_DIR)/wired.iso

X32_ELF := $(X32_BIN_DIR)/wired.elf

LD_SCRIPT := $(MAKECFG_DIR)/linker/linker.ld
GRUB_CFG := $(MAKECFG_DIR)/grub/grub.cfg

# Used only for GitHub Actions
WEBKERNEL_DIR := $(ROOT_DIR)/web/kernel
