ifeq ($(ARCH),X32)

runiso: iso disk
	@rm -f $(ROOT_DIR)/qemu.log

	@qemu-system-x86_64                         	\
		-cdrom $(X32_BIN_DIR)/wired.iso         	\
		-drive file=$(DISK_IMG),format=raw,if=ide 	\
		-m 512M                                 	\
		-serial file:$(ROOT_DIR)/serial.log     	\
		-boot d                                 	\
		-no-reboot                              	\
		-rtc base=localtime                     	\
		-d int,cpu_reset                        	\
		-D $(ROOT_DIR)/qemu.log
endif
