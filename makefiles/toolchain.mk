CROSS_CC_32 = i686-elf-gcc
CROSS_CC_64 = x86_64-elf-gcc
CROSS_AS_32 = i686-elf-as
CROSS_AS_64 = x86_64-elf-as

AS_32 := $(shell which $(CROSS_AS_32) 2>/dev/null)
AS_64 := $(shell which $(CROSS_AS_64) 2>/dev/null)
CC_32 := $(shell which $(CROSS_CC_32) 2>/dev/null)
CC_64 := $(shell which $(CROSS_CC_64) 2>/dev/null)

include $(MAKECFG_DIR)/toolchain/as32.mk
include $(MAKECFG_DIR)/toolchain/as64.mk
include $(MAKECFG_DIR)/toolchain/cc32.mk
include $(MAKECFG_DIR)/toolchain/cc64.mk
