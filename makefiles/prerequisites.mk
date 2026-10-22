IGNORED_TARGETS := clean 		\
				cleanbin 	\
				cleanlocalt	\
				cleanall	\
							\
				release		\
				webkernel

ifeq ($(filter $(MAKECMDGOALS),$(IGNORED_TARGETS)),)
    ifeq ($(ARCH),)
        $(error ARCH is not defined! Use ARCH=X32 or ARCH=X64)
    endif
endif

ifneq ($(BIN_TYPE),release)
    BIN_TYPE = debug
endif
