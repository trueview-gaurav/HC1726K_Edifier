SDKSRC_DIR ?= $(realpath $(CURDIR)/../../../..)
include $(SDKSRC_DIR)/firmware/build/sdksrc.mk

include calib_ubifs.mk

# Filesystem image declarations

CALIBFS_SRC  := $(CALIBFS)
CALIBFS_BIN_PATH := $(CALIBFS_PATH)/bin
CALIBFS_IMAGE := calib.ubifs
CALIBFS_IMAGE_BIN := calib.bin
CALIBFS_CFG := calib_ubinize.cfg

DEST := $(BINPKG_DIR)
INSTALL_TRGTS := $(addprefix $(DEST)/, $(CALIBFS_IMAGE_BIN))

.PHONY: default
default: all

.PHONY: rebuild
rebuild: clean all

.PHONY: all
all: $(CALIBFS_BIN_PATH)/$(CALIBFS_IMAGE_BIN)

.PHONY: install
install: $(DEST) $(CALIBFS_BIN_PATH) FORCE
	$(Q)install -m 644 $(CALIBFS_BIN_PATH)/$(CALIBFS_IMAGE_BIN) $<

.PHONY: uninstall
uninstall:
	$(Q)rm -f $(INSTALL_TRGTS)

.PHONY: clean
clean: uninstall
	$(Q)rm -rf $(CALIBFS_BIN_PATH)

.PHONY: distclean
distclean: clean
	$(Q)rm -rf $(CALIBFS_SRC)

.PHONY: FORCE
FORCE:

$(CALIBFS_BIN_PATH)/$(CALIBFS_IMAGE_BIN): $(CALIBFS_BIN_PATH) $(CALIBFS_SRC)
	$(Q)mkdir -p $(CALIBFS_SRC)/factory_default
	$(Q)rm -f $(CALIBFS_BIN_PATH)/*
ifeq ($(CONFIG_CALIBFS_EXT4), y)
	$(Q)mkfs.ext4 -b $(CONFIG_CALIBFS_EXT4_BLKSIZE) -d $(CALIBFS_SRC) $(CALIBFS_BIN_PATH)/$(CALIBFS_IMAGE_BIN) $(CONFIG_CALIBFS_EXT4_BLKCNT)
	$(Q)e2fsck -fy $(CALIBFS_BIN_PATH)/$(CALIBFS_IMAGE_BIN)
	@echo "Checking for journal feature..."
	@tune2fs -l $(CALIBFS_BIN_PATH)/$(CALIBFS_IMAGE_BIN) | grep 'Filesystem features' | grep -q 'has_journal' && \
		echo -e "\e[32mENABLED\e[0m: Journal feature is enabled." || \
		echo -e "\e[31mDISABLED\e[0m: Ext4 Journal feature is disabled."
else
	$(Q)mkfs.ubifs -d $(CALIBFS_SRC) $(CALIB_UBIFS_OPTS) -o $(CALIBFS_BIN_PATH)/$(CALIBFS_IMAGE)
	$(Q)ubinize -o $(CALIBFS_BIN_PATH)/$(CALIBFS_IMAGE_BIN) $(CALIB_UBI_UBINIZE_OPTS) $(CALIBFS_CFG)
endif

$(CALIBFS_BIN_PATH) $(CALIBFS_SRC) $(DEST):
	$(Q)install -d $@

#===============================================================================
# SDKREL rules
# All rules with "-rel" postfix represents SDK release package rules
#===============================================================================

BINPKG_DIR_REL := $(CURDIR)/../output
BINPKG_DIR_DEBUG_REL := $(CURDIR)/../output_debug
DEST_REL := $(BINPKG_DIR_REL)
DEST_DEBUG_REL := $(BINPKG_DIR_DEBUG_REL)
INSTALL_TRGTS_REL := $(addprefix $(DEST_REL)/, $(CALIBFS_IMAGE_BIN))
INSTALL_TRGTS_DEBUG_REL := $(addprefix $(DEST_DEBUG_REL)/, $(CALIBFS_IMAGE_BIN))


.PHONY: rebuild-rel
rebuild-rel: clean-rel all

.PHONY: install-rel
install-rel:
	$(Q)install -d $(DEST_REL) $(DEST_DEBUG_REL)
	$(Q)install -m 644 $(CALIBFS_BIN_PATH)/$(CALIBFS_IMAGE_BIN) $(DEST_REL)
	$(Q)install -m 644 $(CALIBFS_BIN_PATH)/$(CALIBFS_IMAGE_BIN) $(DEST_DEBUG_REL)

.PHONY: uninstall-rel
uninstall-rel:
	$(Q)rm -f $(INSTALL_TRGTS_REL) $(INSTALL_TRGTS_DEBUG_REL)

.PHONY: clean-rel
clean-rel: uninstall-rel
	$(Q)rm -f $(CALIBFS_BIN_PATH)/$(CALIBFS_IMAGE_BIN)

.PHONY: distclean-rel
distclean-rel: clean-rel
	$(Q)rm -rf $(CALIBFS_SRC)/*
