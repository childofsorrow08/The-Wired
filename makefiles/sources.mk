C_SOURCES   := $(shell find $(SRC_DIR) -name "*.c")
S_SOURCES   := $(shell find $(SRC_DIR) -name "*.S")
ASM_SOURCES := $(shell find $(SRC_DIR) -name "*.s")

ifneq ($(ARCH),X32)
C_OBJ_FILES	:= $(patsubst $(SRC_DIR)/%.c, $(X32_OBJ_DIR)/%.o, $(C_SOURCES))
S_OBJ_FILES	:= $(patsubst $(SRC_DIR)/%.S, $(X32_OBJ_DIR)/%.o, $(S_SOURCES))
ASM_OBJ_FILES := $(patsubst $(SRC_DIR)/%.s, $(X32_OBJ_DIR)/%.o, $(ASM_SOURCES))
endif

ifneq ($(ARCH),X64)
C_OBJ_FILES	:= $(patsubst $(SRC_DIR)/%.c, $(X64_OBJ_DIR)/%.o, $(C_SOURCES))
S_OBJ_FILES	:= $(patsubst $(SRC_DIR)/%.S, $(X64_OBJ_DIR)/%.o, $(S_SOURCES))
ASM_OBJ_FILES := $(patsubst $(SRC_DIR)/%.s, $(X64_OBJ_DIR)/%.o, $(ASM_SOURCES))
endif

OBJS := \
    $(C_OBJ_FILES) \
    $(S_OBJ_FILES) \
    $(ASM_OBJ_FILES)
