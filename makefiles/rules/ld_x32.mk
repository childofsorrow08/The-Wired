$(X32_ELF): $(X32_OBJS) $(LD_SCRIPT)
	@mkdir -p $(dir $@)
	@echo "[LD] Linking 32-bit kernel..."
	@$(CC32) $(LDFLAGS_32) -o $@ $(X32_OBJS)
