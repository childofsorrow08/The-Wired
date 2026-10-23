ifeq ($(ARCH),X32)
	ARCH_SUFFIX := 32
else ifeq ($(ARCH),X64)
	ARCH_SUFFIX := 64
endif

ALL_C_SOURCES   := $(shell find $(SRC_DIR) -name "*.c")
ALL_S_SOURCES   := $(shell find $(SRC_DIR) -name "*.S")
ALL_ASM_SOURCES := $(shell find $(SRC_DIR) -name "*.s")

select_sources = $(filter-out %_32.$(2) %_64.$(2),$(1)) \
                 $(filter %_$(ARCH_SUFFIX).$(2),$(1))

C_SOURCES   := $(call select_sources,$(ALL_C_SOURCES),c)
S_SOURCES   := $(call select_sources,$(ALL_S_SOURCES),S)
ASM_SOURCES := $(call select_sources,$(ALL_ASM_SOURCES),s)

C_OBJ_FILES   := $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(C_SOURCES))
S_OBJ_FILES   := $(patsubst $(SRC_DIR)/%.S,$(OBJ_DIR)/%.o,$(S_SOURCES))
ASM_OBJ_FILES := $(patsubst $(SRC_DIR)/%.s,$(OBJ_DIR)/%.o,$(ASM_SOURCES))

OBJS := \
    $(C_OBJ_FILES) \
    $(S_OBJ_FILES) \
    $(ASM_OBJ_FILES)
