DISK_SIZE := 32M

disk:
	@echo "[INFO] Creating FAT16 image..."
	@mkdir -p $(dir $(DISK_IMG))
	@rm -f $(DISK_IMG)
	@truncate -s $(DISK_SIZE) $(DISK_IMG)
	@mkfs.fat -F 16 $(DISK_IMG)
	@echo "[INFO] FAT16 image created at: $(DISK_IMG)"

    # include directory with all needed headers
	@echo "[INFO] Creating include directory..."
	@mmd -i $(DISK_IMG) ::/INCLUDE

    # libc
	@mcopy -s -i $(DISK_IMG) $(SRC_DIR)/libc/include/* ::/INCLUDE/

    # syscall numbers header
	@echo "[INFO] Copying syscall headers..."
	@mcopy -i $(DISK_IMG) \
		$(SRC_DIR)/syscall/include/syscall_numbers.h \
		::/INCLUDE/SYSCALL.H

ifneq ($(TEST),)
    # Test .txt file
	@echo "[INFO] Creating hello.txt for test"
	@echo "Hello from FAT16" > $(BUILD_DIR)/hello.txt
	@mcopy -i $(BUILD_DIR)/disk.img $(BUILD_DIR)/hello.txt ::HELLO.TXT

    # Test .elf binary
	@echo "[INFO] Building YES.ELF..."
	@printf '%s\n' \
		'.code32' \
		'.section .text' \
		'.global _start' \
		'_start:' \
		'    movl $$1, %eax' \
		'    movl $$1, %ebx' \
		'    movl $$message, %ecx' \
		'    movl $$message_len, %edx' \
		'    int $$0x80' \
		'' \
		'    movl $$1, %eax' \
		'    movl $$1, %ebx' \
		'    movl $$message2, %ecx' \
		'    movl $$message2_len, %edx' \
		'    int $$0x80' \
		'1:' \
		'    jmp 1b' \
		'' \
		'.section .rodata' \
		'message:' \
		'    .ascii "YES!\n"' \
		'.set message_len, . - message' \
		'message2:' \
		'    .ascii "NO!\n"' \
		'.set message2_len, . - message2' \
		> $(BUILD_DIR)/yes.S

	@i686-elf-as --32 \
		$(BUILD_DIR)/yes.S \
		-o $(BUILD_DIR)/yes.o

	@i686-elf-ld \
		-m elf_i386 \
		-Ttext 0x400000 \
		-e _start \
		-o $(BUILD_DIR)/yes.elf \
		$(BUILD_DIR)/yes.o

	@mcopy -i $(DISK_IMG) $(BUILD_DIR)/yes.elf ::YES.ELF
endif
