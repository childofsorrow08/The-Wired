CFLAGS_32 := $(CFLAGS) \
    -m32 \
    -mno-sse \
    -mno-sse2 \
    -mno-mmx \
    -mno-avx \
	-DX32
