include $(MAKECFG_DIR)/sources/c.mk
include $(MAKECFG_DIR)/sources/S.mk
include $(MAKECFG_DIR)/sources/asm.mk

X32_C_SOURCES := 			\
	$(C_SOURCES)			\
	$(S_SOURCES)

X32_ASM_SOURCES := 			\
	$(ASM_SOURCES)

X32_SOURCES := 				\
	$(X32_C_SOURCES) 		\
	$(X32_ASM_SOURCES)

# I should have found another place for this, but still
X32_C_OBJ_FILES	:= $(patsubst $(SRC_DIR)/%.c, $(X32_OBJ_DIR)/%.o, $(C_SOURCES))
X32_S_OBJ_FILES	:= $(patsubst $(SRC_DIR)/%.S, $(X32_OBJ_DIR)/%.o, $(S_SOURCES))
X32_ASM_OBJ_FILES := $(patsubst $(SRC_DIR)/%.s, $(X32_OBJ_DIR)/%.o, $(ASM_SOURCES))

X32_OBJS := \
    $(X32_C_OBJ_FILES) \
    $(X32_S_OBJ_FILES) \
    $(X32_ASM_OBJ_FILES)
