OUTPUT_DIR := $(CURDIR)/out
EFUSE_SRC_DIR ?= $(CURDIR)/src

.PHONY: all
all: efuse prepare-for-rootfs

.PHONY: clean
clean: efuse-clean prepare-for-rootfs-clean

efuse:
	$(MAKE) -C $(EFUSE_SRC_DIR);

efuse-clean:
	$(MAKE) -C $(EFUSE_SRC_DIR) clean;

prepare-for-rootfs: efuse
	@echo "Copying feature CA binaries to $(OUTPUT_DIR)..."
	@mkdir -p $(OUTPUT_DIR)
	@mkdir -p $(OUTPUT_DIR)/ca
	if [ -e $(EFUSE_SRC_DIR)/host/uuid ]; then \
		cp -p $(EFUSE_SRC_DIR)/host/uuid $(OUTPUT_DIR)/ca/; \
	fi;

prepare-for-rootfs-clean:
	@rm -rf $(OUTPUT_DIR)/ca
	@rmdir --ignore-fail-on-non-empty $(OUTPUT_DIR) || test ! -e $(OUTPUT_DIR)
