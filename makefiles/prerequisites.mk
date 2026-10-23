ifeq ($(ARCH),)
    ARCH = X32
    $(warning Binary arch not defined, using X32)
endif

ifeq ($(filter $(BIN_TYPE),release debug),)
    BIN_TYPE = debug
    $(warning Binary type not defined, using debug)
endif
