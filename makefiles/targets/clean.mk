clean:
	@rm -rf $(X32_BUILD_DIR)
	@rm -rf $(X64_BUILD_DIR)
	@echo "[INFO] Build dirs cleared"

	@rm -rf $(X32_OBJ_DIR)
	@rm -rf $(X64_OBJ_DIR)
	@echo "[INFO] Objects dirs cleared"

cleanbin:
	@rm -rf $(X32_BIN_DIR)
	@rm -rf $(X64_BIN_DIR)
	@echo "[INFO] Binary dirs cleared"

cleanall:
	@rm -rf $(BUILD_DIR)
	@echo "[INFO] Build dir cleared"
