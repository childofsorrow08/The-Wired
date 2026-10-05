webkernel: iso32
	@echo "[INFO] Copying ISO image for GitHub Pages"
	@mkdir -p $(WEBKERNEL_DIR)
	@rm -rf $(WEBKERNEL_DIR)/wired.iso
	@cp $(X32_ISO_IMG) $(WEBKERNEL_DIR)/wired.iso
	@echo "[INFO] Success: $(WEBKERNEL_DIR)/wired.iso"
