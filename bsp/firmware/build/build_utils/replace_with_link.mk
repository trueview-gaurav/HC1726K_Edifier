SDKSRC_DIR ?= $(realpath $(CURDIR)/../../..)
include $(SDKSRC_DIR)/firmware/build/sdksrc.mk

# Copy a file to factory_default directory, and replace the original path with
# a symlink to its active_setting entry
# During userdatafs build flow, factory_default contents are copied to active setting,
# making the symlinks valid on target machine
# No warning if the file is not found
define replace_with_link
	$(Q)if [ ! -L $(1) ]; then \
		if [ -f $(1) ] || [ -d $(1) ]; then \
			cp -rf $(1) $(SYSTEMFS)/factory_default/; \
			rm -rf $(1); \
			ln -sf /usrdata/active_setting/`basename $(1)` $(1); \
		fi \
	fi
endef
