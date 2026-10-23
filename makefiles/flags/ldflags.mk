ifeq ($(ARCH),X32)
	ARCH_LDFLAGS =					\
    	-m32
else ifeq ($(ARCH),X64)

endif

LDFLAGS := 							\
	$(ARCH_LDFLAGS)					\
									\
    -nostdlib 						\
    -ffreestanding 					\
    -static 						\
    -T $(LD_SCRIPT)
