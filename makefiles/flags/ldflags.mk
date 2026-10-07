LDFLAGS := \
    -nostdlib \
    -ffreestanding \
    -static \
    -T $(LD_SCRIPT)
