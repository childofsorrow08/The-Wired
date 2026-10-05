$(X32_OBJ_DIR)/%.o: $(SRC_DIR)/%.S
	@mkdir -p $(dir $@)
	@$(CC32) $(CFLAGS_32) $(METADATA_FLAGS_C) -c $< -o $@
