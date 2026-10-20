DISK_SIZE := 32M

disk:
	@echo "[DISK] Creating FAT16 image..."
	@mkdir -p $(dir $(DISK_IMG))
	@rm -f $(DISK_IMG)
	@truncate -s $(DISK_SIZE) $(DISK_IMG)
	@mkfs.fat -F 16 $(DISK_IMG)
	@echo "[DISK] FAT16 image created at: $(DISK_IMG)"
