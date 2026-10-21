webkernel:
	@echo "[INFO] Building X32 Kernel..."
	@$(MAKE) ARCH=X32 iso
	@$(MAKE) ARCH=X32 disk TEST=1

	@echo "[INFO] Copying ISO image for GitHub Pages"
	@mkdir -p $(WEBKERNEL_DIR)
	@cp $(X32_ISO_IMG) $(WEBKERNEL_DIR)/wired.iso
	@echo "[INFO] Success: $(WEBKERNEL_DIR)/wired.iso"

	@echo "[INFO] Copying FAT16 disk image for GitHub Pages"
	@cp $(DISK_IMG) $(WEBKERNEL_DIR)/disk.img

# only x32 iso needed cause v86 works correctly
# only with x32 systenms
