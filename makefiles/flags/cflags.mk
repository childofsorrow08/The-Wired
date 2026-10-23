ifeq ($(BIN_TYPE),release)
	SITUATIONAL_CFLAGS := 			\
    	-O2 						\
		-Werror
else
	SITUATIONAL_CFLAGS := 			\
    	-Og 						\
    	-g3 						\
    	-fno-omit-frame-pointer 	\
    	-DDEBUG
endif

ifeq ($(ARCH),X32)
	ARCH_CFLAGS =					\
    	-m32 						\
    	-mno-sse 					\
    	-mno-sse2 					\
    	-mno-mmx 					\
    	-mno-avx 					\
		-DX32
else ifeq ($(ARCH),X64)

endif

CFLAGS := 							\
	$(SITUATIONAL_CFLAGS) 			\
	$(ARCH_CFLAGS) 					\
									\
    -ffreestanding 					\
    -nostdlib 						\
    -fno-builtin 					\
    -fno-exceptions 				\
    -fno-stack-protector 			\
    -fno-pie 						\
    -fno-pic 						\
	-fshort-wchar 					\
    -Wall 							\
    -Wextra 						\
									\
	-I$(SRC_DIR)/include
