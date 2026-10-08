CROSS_CC_32 = i686-elf-gcc
CROSS_CC_64 = x86_64-elf-gcc
CROSS_AS_32 = i686-elf-as
CROSS_AS_64 = x86_64-elf-as

LOCAL_CC_32 = $(shell find $(I686-TOOLS-DIR) -name "i686-elf-gcc" 2>/dev/null)
LOCAL_CC_64 = $(shell find $(X86_64-TOOLS-DIR) -name "x86_64-elf-gcc" 2>/dev/null)
LOCAL_AS_32 = $(shell find $(I686-TOOLS-DIR) -name "i686-elf-as" 2>/dev/null)
LOCAL_AS_64 = $(shell find $(X86_64-TOOLS-DIR) -name "x86_64-elf-as" 2>/dev/null)

AS_32 := $(shell which $(CROSS_AS_32) 2>/dev/null)
AS_64 := $(shell which $(CROSS_AS_64) 2>/dev/null)
CC_32 := $(shell which $(CROSS_CC_32) 2>/dev/null)
CC_64 := $(shell which $(CROSS_CC_64) 2>/dev/null)

include $(MAKECFG_DIR)/toolchain/as32.mk
include $(MAKECFG_DIR)/toolchain/as64.mk
include $(MAKECFG_DIR)/toolchain/cc32.mk
include $(MAKECFG_DIR)/toolchain/cc64.mk

ifeq ($(CC32),gcc)
    ifeq ($(ARCH),X32)
        $(warning [WARNING] You don't have 32-bit cross-compiler installed)
        $(warning [WARNING] Please install it using your package manager or scripts in:)
        $(warning [WARNING] $(SCRIPTS_DIR))
    endif
endif

ifeq ($(CC64),gcc)
    ifeq ($(ARCH),X64)
        $(warning [WARNING] You don't have 64-bit cross-compiler installed)
        $(warning [WARNING] Please install it using your package manager or scripts in:)
        $(warning [WARNING] $(SCRIPTS_DIR))
    endif
endif

ifeq ($(AS32),as)
    ifeq ($(ARCH),X32)
        $(warning [WARNING] You don't have 32-bit cross-assembler installed)
        $(warning [WARNING] Please install it using your package manager or scripts in:)
        $(warning [WARNING] $(SCRIPTS_DIR))
    endif
endif

ifeq ($(AS64),as)
    ifeq ($(ARCH),X64)
        $(warning [WARNING] You don't have 64-bit cross-assembler installed)
        $(warning [WARNING] Please install it using your package manager or scripts in:)
        $(warning [WARNING] $(SCRIPTS_DIR))
    endif
endif
