webkernel:
	@echo "[INFO] Building X32 Kernel..."
	@$(MAKE) ARCH=X32 iso

	@echo "[INFO] Copying ISO image for GitHub Pages"
	@mkdir -p $(WEBKERNEL_DIR)
	@rm -rf $(WEBKERNEL_DIR)/wired.iso
	@cp $(X32_ISO_IMG) $(WEBKERNEL_DIR)/wired.iso
	@echo "[INFO] Success: $(WEBKERNEL_DIR)/wired.iso"

# only x32 iso needed cause v86 works correctly
# only with x32 systenms
