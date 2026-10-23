ifeq ($(ARCH),)
    ARCH = X32
    $(warning Binary arch not defined, using X32)
endif

ifeq ($(ARCH),X32)
	OBJ_DIR := $(X32_OBJ_DIR)
	ELF := $(X32_ELF)
else ifeq ($(ARCH),X64)
	OBJ_DIR := $(X64_OBJ_DIR)
	ELF := $(X64_ELF)
endif

ifeq ($(filter $(BIN_TYPE),release debug),)
    BIN_TYPE = debug
    $(warning Binary type not defined, using debug)
endif
