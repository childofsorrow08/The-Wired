release:
	@echo "[INFO] Building X32 release..."
	@$(MAKE) ARCH=X32 build
	@$(MAKE) ARCH=X32 disk
	@$(MAKE) ARCH=X32 iso

	@echo "[INFO] Copying binaries for release"
	@mkdir -p $(RELEASE_BIN_DIR)
	@mkdir -p $(RELEASE_32_BIN_DIR)
	@mkdir -p $(RELEASE_64_BIN_DIR)

	@mv $(X32_BIN_DIR)/* $(RELEASE_BIN_DIR)

	@mv $(RELEASE_BIN_DIR)/bin \
		$(RELEASE_32_BIN_DIR)/bin

	@mv $(RELEASE_BIN_DIR)/wired.elf \
		$(RELEASE_32_BIN_DIR)/wired.elf

	@echo "[INFO] Creating X32 ELF release archive..."
	@tar -czf $(RELEASE_BIN_DIR)/wired_x32_elf.tar.gz \
		 -C $(RELEASE_32_BIN_DIR) \
		 bin wired.elf

	@rm -rf $(RELEASE_32_BIN_DIR)
	@mkdir -p $(RELEASE_32_BIN_DIR)

	@mv $(RELEASE_BIN_DIR)/wired.iso \
		$(RELEASE_32_BIN_DIR)/wired_x32.iso

	@mv $(BUILD_DIR)/disk.img \
		$(RELEASE_32_BIN_DIR)/disk.img

	@echo "[INFO] Creating X32 ISO release archive..."
	@tar -czf $(RELEASE_BIN_DIR)/wired_x32_iso.tar.gz \
		 -C $(RELEASE_32_BIN_DIR) \
		 wired_x32.iso disk.img

	@rm -rf $(RELEASE_32_BIN_DIR)
	@rm -rf $(RELEASE_64_BIN_DIR)
	@echo "[INFO] Success. Release files:"
	@ls -lh $(RELEASE_BIN_DIR)

