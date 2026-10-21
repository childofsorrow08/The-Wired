DISK_SIZE := 32M

disk:
	@echo "[INFO] Creating FAT16 image..."
	@mkdir -p $(dir $(DISK_IMG))
	@rm -f $(DISK_IMG)
	@truncate -s $(DISK_SIZE) $(DISK_IMG)
	@mkfs.fat -F 16 $(DISK_IMG)
	@echo "[INFO] FAT16 image created at: $(DISK_IMG)"

	@echo "[INFO] Creating hello.txt for test"
	@echo "Hello from FAT16" > $(BUILD_DIR)/hello.txt
	@mcopy -i $(BUILD_DIR)/disk.img $(BUILD_DIR)/hello.txt ::HELLO.TXT

	@echo "[INFO] Creating include directory..."
	@mmd -i $(DISK_IMG) ::/INCLUDE

    # libc
	@mcopy -s -i $(DISK_IMG) $(SRC_DIR)/libc/include/* ::/INCLUDE/

    # syscall numbers header
	@echo "[INFO] Copying syscall headers..."
	@mcopy -i $(DISK_IMG) \
		$(SRC_DIR)/syscall/include/syscall_numbers.h \
		::/INCLUDE/SYSCALL.H
