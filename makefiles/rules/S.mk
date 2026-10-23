$(OBJ_DIR)/%.o: $(SRC_DIR)/%.S
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(METADATA_FLAGS_C) -c $< -o $@
