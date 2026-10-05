iso32: $(X32_ELF)

iso32:
	@echo "[INFO] Building x32 ISO image"
	@mkdir -p $(X32_ISO_DIR)/boot/grub
	@mkdir -p $(X32_BIN_DIR)

	@cp $(X32_BIN_DIR)/wired.elf $(X32_ISO_DIR)/boot/wired.elf
	@cp $(GRUB_CFG) $(X32_ISO_DIR)/boot/grub/grub.cfg

	@grub-mkrescue -o $(X32_ISO_IMG) $(X32_ISO_DIR) 2>/dev/null
	@echo "[INFO] ISO created at: $(X32_ISO_IMG)"
