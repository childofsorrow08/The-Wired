ifeq ($(ARCH),X32)
	ARCH_ASFLAGS =					\
    	--32
else ifeq ($(ARCH),X64)

endif

ASFLAGS :=							\
	$(ARCH_ASFLAGS)

