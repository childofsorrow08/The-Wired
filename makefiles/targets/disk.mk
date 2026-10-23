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

    # Various binaries
	@echo "[INFO] Copying bin directory..."
	@mcopy -s -i "$(DISK_IMG)" "$(CUR_BIN_DIR)/bin" ::/
