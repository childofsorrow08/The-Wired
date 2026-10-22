release:
	@echo "[INFO] Building X32 release..."
	@$(MAKE) ARCH=X32 all

#    @echo "[INFO] Building X64 release..."
#    $(MAKE) clean
#    $(MAKE) ARCH=X64 all

	@echo "[INFO] Copying binaries for release"
	@mkdir -p $(RELEASE_BIN_DIR)

	@mv $(X32_BIN_DIR)/* $(RELEASE_BIN_DIR)
	@mv $(RELEASE_BIN_DIR)/wired.elf $(RELEASE_BIN_DIR)/wired_x32.elf
	@mv $(RELEASE_BIN_DIR)/wired.iso $(RELEASE_BIN_DIR)/wired_x32.iso

# unused for now
#	@mv $(X64_BIN_DIR)/* $(RELEASE_BIN_DIR)
#	@mv $(RELEASE_BIN_DIR)/wired.elf $(RELEASE_BIN_DIR)/wired_x64.elf
#	@mv $(RELEASE_BIN_DIR)/wired.iso $(RELEASE_BIN_DIR)/wired_x64.iso
	@echo "[INFO] Success. Release files: "
	@ls $(RELEASE_BIN_DIR)

