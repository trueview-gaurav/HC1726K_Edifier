OUTPUT_DIR := $(CURDIR)/out
MONO_CNT_SRC_DIR ?= $(CURDIR)/src

.PHONY: all
all: monotonic-cnt prepare-for-rootfs

.PHONY: clean
clean: monotonic-cnt-clean prepare-for-rootfs-clean

monotonic-cnt:
	$(MAKE) -C $(MONO_CNT_SRC_DIR);

monotonic-cnt-clean:
	$(MAKE) -C $(MONO_CNT_SRC_DIR) clean;

prepare-for-rootfs: monotonic-cnt
	@echo "Copying feature CA binaries to $(OUTPUT_DIR)..."
	@mkdir -p $(OUTPUT_DIR)
	@mkdir -p $(OUTPUT_DIR)/ca
	if [ -e $(MONO_CNT_SRC_DIR)/host/monotonic_counter ]; then \
		cp -p $(MONO_CNT_SRC_DIR)/host/monotonic_counter $(OUTPUT_DIR)/ca/; \
	fi;

prepare-for-rootfs-clean:
	@rm -rf $(OUTPUT_DIR)/ca
	@rmdir --ignore-fail-on-non-empty $(OUTPUT_DIR) || test ! -e $(OUTPUT_DIR)
