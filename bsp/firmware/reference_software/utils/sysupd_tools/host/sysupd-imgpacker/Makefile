SDKSRC_DIR ?= $(realpath $(CURDIR)/../../../../../..)
include $(SDKSRC_DIR)/firmware/build/sdksrc.mk
include $(APP_PATH)/internal.mk
include $(APP_PATH)/common.mk

DEST := $(BINPKG_DIR)/sysupd-imgpacker

SRCDIR = script

TRGTS  := $(wildcard $(SRCDIR)/*)
INSTALL_TRGTS := $(addprefix $(DEST)/, $(notdir $(TRGTS)))
UPD_DESC := fwupd.desc

ifdef CONFIG_OPTEE
ROOTFS_VER ?= 0
TEE_VER ?= 0
endif

.PHONY: all
all:
ifeq ($(CONFIG_HC1702_1752_1772_1782), y)
	$(Q)$(LN) -sfr product/hc18xx.desc $(SRCDIR)/$(UPD_DESC)
else
	$(Q)$(LN) -sfr product/$(CONFIG_MACH).desc $(SRCDIR)/$(UPD_DESC)
endif

#===============================================================================
# SDKSRC rules
#===============================================================================

.PHONY: install
install: $(DEST) $(INSTALL_TRGTS)

$(DEST):
	$(Q)install -d $@

ifdef CONFIG_OPTEE
$(DEST)/%: $(SRCDIR)/%
	@if [ "$(notdir $<)" = "sysupd-imgpacker" ]; then \
		echo "Patching $< with ROOTFS_VERSION=$(ROOTFS_VER), TEE_VERSION=$(TEE_VER)"; \
		sed \
			-e 's/^ROOTFS_VERSION=.*/ROOTFS_VERSION=$(ROOTFS_VER)/' \
			-e 's/^TEE_VERSION=.*/TEE_VERSION=$(TEE_VER)/' \
			$< > $@.tmp; \
	else \
		cp $< $@.tmp; \
	fi
	@install $@.tmp $@
	@chmod +x $@
	@rm -f $@.tmp
else
$(DEST)/%: $(SRCDIR)/%
	$(Q)install $< $@
endif

.PHONY: uninstall
uninstall:
	$(Q)rm -f $(INSTALL_TRGTS)
	$(Q)rm -rf $(DEST)

.PHONY: clean
clean:
	$(Q)rm -rf *.swu *.bin $(SW_DESC)
	$(Q)rm -f $(SRCDIR)/$(UPD_DESC) 

.PHONY: distclean
distclean: uninstall clean
