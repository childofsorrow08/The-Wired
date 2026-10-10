CFLAGS := \
    -ffreestanding \
    -nostdlib \
    -fno-builtin \
    -fno-exceptions \
    -fno-stack-protector \
    -fno-pie \
    -fno-pic \
	-fshort-wchar \
    -Wall \
    -Wextra \
    -O2		\
	-I$(SRC_DIR)/include

# -Werror \
