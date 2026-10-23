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

    # Various binaries
	@echo "[INFO] Copying bin directory..."
	@mcopy -s -i "$(DISK_IMG)" "$(CUR_BIN_DIR)/bin" ::/
