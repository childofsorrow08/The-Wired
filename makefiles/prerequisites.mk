ifeq ($(ARCH),)
    ARCH = X32
    $(warning Binary arch not defined, using X32)
endif

ifeq ($(ARCH),X32)
	CUR_BUILD_DIR := $(X32_BUILD_DIR)
	CUR_BIN_DIR := $(X32_BIN_DIR)
	OBJ_DIR := $(X32_OBJ_DIR)
	ELF := $(X32_ELF)
else ifeq ($(ARCH),X64)
	CUR_BUILD_DIR := $(X64_BUILD_DIR)
	CUR_BIN_DIR := $(X64_BIN_DIR)
	OBJ_DIR := $(X64_OBJ_DIR)
	ELF := $(X64_ELF)
endif

ifeq ($(filter $(BIN_TYPE),release debug),)
    BIN_TYPE = debug
    $(warning Binary type not defined, using debug)
endif

ifeq ($(filter $(MODULES),min max),)
	MODULES = max
    $(warning The number of required modules is not specified, compiling them all)
endif
