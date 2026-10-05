runiso32: iso32
	@rm -f $(ROOT_DIR)/qemu.log

	@qemu-system-x86_64 						\
		-cdrom $(X32_BIN_DIR)/wired.iso			\
		-m 512M									\
		-serial file:$(ROOT_DIR)/qemu.log		\
		-boot d									\
		-no-reboot								\
		-rtc base=localtime
