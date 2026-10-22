SDKSRC_DIR ?= $(realpath $(CURDIR)/../../../..)
include $(SDKSRC_DIR)/firmware/build/sdksrc.mk

include usrdata_ubifs.mk

# JFFs2 flash erase block size
EB_SIZE_64K = 0x10000
EB_SIZE_32K = 0x8000

# Filesystem image declarations

USRDATAFS_SRC  := $(USRDATAFS)
USRDATAFS_BIN_PATH := $(USRDATAFS_PATH)/bin
USRDATAFS_IMAGE := usrdata.ubifs
USRDATAFS_IMAGE_BIN := usrdata.bin
USRDATAFS_CFG := usrdata_ubifs.cfg
USRDATAFS_TEST_SCRIPT := $(USRDATAFS_PATH)/test_script
USRDATAFS_IMG_SRC=$(USRDATAFS_SRC)
USRDATAFS_IMG_OUT=$(USRDATAFS_BIN_PATH)/$(USRDATAFS_IMAGE_BIN)

DEST := $(BINPKG_DIR)
INSTALL_TRGTS := $(addprefix $(DEST)/, $(USRDATAFS_IMAGE_BIN))

.PHONY: default
default: all

.PHONY: rebuild
rebuild: clean all

.PHONY: dubuild
dubuild:
	$(Q)mkfs.ubifs -d $(USRDATAFS_SRC) $(USRDATA_UBIFS_OPTS) -o $(USRDATAFS_BIN_PATH)/$(USRDATAFS_IMAGE)
	$(Q)ubinize -o $(USRDATAFS_BIN_PATH)/$(USRDATAFS_IMAGE_BIN) $(USRDATA_UBI_UBINIZE_OPTS) $(USRDATAFS_CFG)

.PHONY: all
all: $(USRDATAFS_BIN_PATH)/$(USRDATAFS_IMAGE_BIN)

.PHONY: install
install: $(DEST) $(USRDATAFS_BIN_PATH) FORCE
	$(Q)install -m 644 $(USRDATAFS_BIN_PATH)/$(USRDATAFS_IMAGE_BIN) $<

.PHONY: uninstall
uninstall:
	$(Q)rm -f $(INSTALL_TRGTS)

.PHONY: clean
clean: uninstall
	$(Q)rm -rf $(USRDATAFS_BIN_PATH)

.PHONY: distclean
distclean: clean
	$(Q)rm -rf $(USRDATAFS_SRC)

.PHONY: FORCE
FORCE:

ifeq ($(CONFIG_SECURE_BOOT), y)
.PHONY: secure-unpack
secure-unpack:
	@echo "Checking image type of $(BINPKG_SIGN_DIR)/$(USRDATAFS_IMAGE_BIN)..."
	@if ! [ -f "$(BINPKG_SIGN_DIR)/$(USRDATAFS_IMAGE_BIN)" ]; then \
		echo "Error: Image file '$(BINPKG_SIGN_DIR)/$(USRDATAFS_IMAGE_BIN)' not found."; \
		exit 1; \
	fi
ifeq ($(CONFIG_USRDATA_JFFS2), y)
	@echo "Unpacking $(USRDATAFS_IMAGE_BIN) with jefferson..."
	@jefferson $(BINPKG_SIGN_DIR)/$(USRDATAFS_IMAGE_BIN) -d $(BINPKG_SIGN_DIR)/usrdata
	@rm -rf $(BINPKG_SIGN_DIR)/$(USRDATAFS_IMAGE_BIN)
else
	@echo "Unpacking $(USRDATAFS_IMAGE_BIN) with ubireader_extract_files..."
	@ubireader_extract_files $(BINPKG_SIGN_DIR)/$(USRDATAFS_IMAGE_BIN) -o $(BINPKG_SIGN_DIR)/ubi_output_tmp
	@mv $$(find $(BINPKG_SIGN_DIR)/ubi_output_tmp/* -type d -name usrdata -print -quit) $(BINPKG_SIGN_DIR)
	@rm -rf $(BINPKG_SIGN_DIR)/ubi_output_tmp
	@rm -rf $(BINPKG_SIGN_DIR)/$(USRDATAFS_IMAGE_BIN)
endif

.PHONY: secure-pack
secure-pack:
	$(Q)chmod 700 $(BINPKG_SIGN_DIR)/$(SECURE_APP_DIR)
	$(Q)cp -r $(BINPKG_SIGN_DIR)/$(SECURE_APP_DIR) $(BINPKG_SIGN_DIR)/$(SECURE_APP_PATH)
	$(Q)rm -rf $(BINPKG_SIGN_DIR)/$(SECURE_APP_DIR)
	$(Q)$(MAKE) build-img USRDATAFS_IMG_SRC=$(BINPKG_SIGN_DIR)/usrdata USRDATAFS_IMG_OUT=$(BINPKG_SIGN_DIR)/$(USRDATAFS_IMAGE_BIN)
	$(Q)rm -rf $(BINPKG_SIGN_DIR)/usrdata

endif # CONFIG_SECURE_BOOT

.PHONY: build-img
build-img:
ifeq ($(CONFIG_USRDATAFS_EXT4), y)
	$(Q)mkfs.ext4 -b $(CONFIG_USRDATAFS_EXT4_BLKSIZE) -d $(USRDATAFS_IMG_SRC) $(USRDATAFS_IMG_OUT) $(CONFIG_USRDATAFS_EXT4_BLKCNT)
	$(Q)e2fsck -fy $(USRDATAFS_IMG_OUT)
	@echo "Checking for journal feature..."
	@tune2fs -l $(USRDATAFS_IMG_OUT) | grep 'Filesystem features' | grep -q 'has_journal' && \
		echo -e "\e[32mENABLED\e[0m: Journal feature is enabled." || \
		echo -e "\e[31mDISABLED\e[0m: Ext4 Journal feature is disabled."
else ifeq ($(CONFIG_USRDATA_JFFS2), y)
ifeq ($(CONFIG_JFFS2_ERASEBLOCK_SIZE_32K),y)
	@echo "JFFS2 erase block size = 32K"
	$(Q)mkfs.jffs2 -d $(USRDATAFS_IMG_SRC) -e $(EB_SIZE_32K) -l -o $(USRDATAFS_IMG_OUT)
else
	@echo "JFFS2 erase block size = 64K"
	$(Q)mkfs.jffs2 -d $(USRDATAFS_IMG_SRC) -e $(EB_SIZE_64K) -l -o $(USRDATAFS_IMG_OUT)
endif
else
	$(Q)mkfs.ubifs -d $(USRDATAFS_IMG_SRC) $(USRDATA_UBIFS_OPTS) -o $(USRDATAFS_BIN_PATH)/$(USRDATAFS_IMAGE)
	$(Q)ubinize -o $(USRDATAFS_IMG_OUT) $(USRDATA_UBI_UBINIZE_OPTS) $(USRDATAFS_CFG)
endif

$(USRDATAFS_BIN_PATH)/$(USRDATAFS_IMAGE_BIN): $(USRDATAFS_BIN_PATH) $(USRDATAFS_SRC)
	$(Q)mkdir -p $(USRDATAFS_SRC)/active_setting
	$(Q)mkdir -p $(USRDATAFS_SRC)/root
	$(Q)mkdir -p $(USRDATAFS_SRC)/tee
	$(Q)cp -af $(USRDATAFS_TEST_SCRIPT) $(USRDATAFS_SRC)/
ifneq ("$(wildcard $(SYSTEMFS)/factory_default/*)","")
	$(Q)cp -rf $(SYSTEMFS)/factory_default/* $(USRDATAFS_SRC)/active_setting/
endif
	$(Q)rm -f $(USRDATAFS_BIN_PATH)/*
	$(Q)$(MAKE) build-img

$(USRDATAFS_BIN_PATH) $(USRDATAFS_SRC) $(DEST):
	$(Q)install -d $@

#===============================================================================
# SDKREL rules
# All rules with "-rel" postfix represents SDK release package rules
#===============================================================================

BINPKG_DIR_REL := $(CURDIR)/../output
BINPKG_DIR_DEBUG_REL := $(CURDIR)/../output_debug
DEST_REL := $(BINPKG_DIR_REL)
DEST_DEBUG_REL := $(BINPKG_DIR_DEBUG_REL)
INSTALL_TRGTS_REL := $(addprefix $(DEST_REL)/, $(USRDATAFS_IMAGE_BIN))
INSTALL_TRGTS_DEBUG_REL := $(addprefix $(DEST_DEBUG_REL)/, $(USRDATAFS_IMAGE_BIN))

.PHONY: rebuild-rel
rebuild-rel: clean-rel all

.PHONY: install-rel
install-rel:
	$(Q)install -d $(DEST_REL) $(DEST_DEBUG_REL)
	$(Q)install -m 644 $(USRDATAFS_BIN_PATH)/$(USRDATAFS_IMAGE_BIN) $(DEST_REL)
	$(Q)install -m 644 $(USRDATAFS_BIN_PATH)/$(USRDATAFS_IMAGE_BIN) $(DEST_DEBUG_REL)

.PHONY: uninstall-rel
uninstall-rel:
	$(Q)rm -f $(INSTALL_TRGTS_REL) $(INSTALL_TRGTS_DEBUG_REL)

.PHONY: clean-rel
clean-rel: uninstall-rel
	$(Q)rm -f $(USRDATAFS_BIN_PATH)/$(USRDATAFS_IMAGE_BIN)

.PHONY: distclean-rel
distclean-rel: clean-rel
	$(Q)rm -rf $(USRDATAFS_SRC)/*
