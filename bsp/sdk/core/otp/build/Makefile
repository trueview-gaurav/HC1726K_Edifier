# Copyright Augentix Inc. Proprietary and confidential.
# Unauthorized use or distribution is prohibited.
# Please contact customer.support@augentix.com for any inquiries.

# The include declaration here will be used by this Makefile and kernel.
# We correct it if the kernel used this macro
SDKSRC_DIR ?= $(realpath $(CURDIR)/../../../..)
ifeq ("$(wildcard $(SDKSRC_DIR)/firmware/build/sdksrc.mk)","")
SDKSRC_DIR := $(realpath $(CURDIR)/../..)
endif
include $(SDKSRC_DIR)/firmware/build/sdksrc.mk
include $(SDKSRC_DIR)/firmware/build/build_utils/lib.mk

DRV = otp-agtx.ko otp-ep.ko
DEST := $(AGTX_MOD_PATH)
INSTALL_MODS := $(addprefix $(NRS_DRV_KO)/, $(DRV))
INSTALL_TRGTS := $(addprefix $(DEST)/, $(DRV))
NRS_CHIP := $(call chip,$(CONFIG_CHIP))

NRS_SCRIPT_DSTDIR = $(USRDATAFS)
ifeq ($(CONFIG_SAPPORO),y)
TARGET_SCIPRTS := $(wildcard ../scripts/sapporo/*.sh)
else
TARGET_SCIPRTS := $(wildcard ../scripts/kyoto/*.sh)
endif
ifeq ($(CONFIG_MACH), hc1783s-tb006-slt)
	NRS_SCRIPT_PFMDIR := $(NRS_DRV_SCRIPT)/hc1783s/*.sh
else ifeq ($(CONFIG_MACH), hc1753-tb007-slt)
	NRS_SCRIPT_PFMDIR := $(NRS_DRV_SCRIPT)/hc1753/*.sh
else ifeq ($(CONFIG_MACH), hc1725-tb007-slt)
	NRS_SCRIPT_PFMDIR := $(NRS_DRV_SCRIPT)/hc1725/*.sh
else ifeq ($(CONFIG_MACH), hc1723-tb007-slt)
	NRS_SCRIPT_PFMDIR := $(NRS_DRV_SCRIPT)/hc1723/*.sh
else ifeq ($(CONFIG_MACH), hc1715-tb007-slt)
	NRS_SCRIPT_PFMDIR := $(NRS_DRV_SCRIPT)/hc1715/*.sh
else ifeq ($(CONFIG_MACH), hc1705-tb008-slt)
	NRS_SCRIPT_PFMDIR := $(NRS_DRV_SCRIPT)/hc1705/*.sh
else ifeq ($(CONFIG_MACH), hc1705i-tb008-slt)
	NRS_SCRIPT_PFMDIR := $(NRS_DRV_SCRIPT)/hc1705i/*.sh
else ifeq ($(CONFIG_MACH), hc1705k-tb008-slt)
	NRS_SCRIPT_PFMDIR := $(NRS_DRV_SCRIPT)/hc1705k/*.sh
else ifeq ($(CONFIG_MACH), hc1703-tb008-slt)
	NRS_SCRIPT_PFMDIR := $(NRS_DRV_SCRIPT)/hc1703/*.sh
else ifeq ($(CONFIG_MACH), hc1703l-tb008-slt)
	NRS_SCRIPT_PFMDIR := $(NRS_DRV_SCRIPT)/hc1703l/*.sh
else ifeq ($(CONFIG_MACH), hc1723i-tb007-slt)
	NRS_SCRIPT_PFMDIR := $(NRS_DRV_SCRIPT)/hc1723i/*.sh
else ifeq ($(CONFIG_MACH), hc1725s-tb006-slt)
	NRS_SCRIPT_PFMDIR := $(NRS_DRV_SCRIPT)/hc1725s/*.sh
else ifeq ($(CONFIG_MACH), hc1753s-tb006-slt)
	NRS_SCRIPT_PFMDIR := $(NRS_DRV_SCRIPT)/hc1753s/*.sh
else ifeq ($(CONFIG_MACH), hc1706-tb010-slt)
	NRS_SCRIPT_PFMDIR := $(NRS_DRV_SCRIPT)/hc1706/*.sh
else ifeq ($(CONFIG_MACH), hc1706h-tb010-slt)
	NRS_SCRIPT_PFMDIR := $(NRS_DRV_SCRIPT)/hc1706h/*.sh
else ifeq ($(CONFIG_MACH), hc1706k-tb010-slt)
	ifeq ($(CONFIG_CHIP), HC1706K)
		NRS_SCRIPT_PFMDIR := $(NRS_DRV_SCRIPT)/hc1706k/*.sh
	else
		NRS_SCRIPT_PFMDIR := $(NRS_DRV_SCRIPT)/hc1706kes/*.sh
	endif
else ifeq ($(CONFIG_MACH), hc1726-tb012-slt)
	NRS_SCRIPT_PFMDIR := $(NRS_DRV_SCRIPT)/hc1726/*.sh
endif

.PHONY: all
all: build

.PHONY: build
build:
ifneq ($(CONFIG_RELEASE), y)
	$(Q)$(MAKE) -C $(NRS_DRV_SRC) all install
else
	@echo - Override nrs configuration with $(NRS_CHIP)
ifeq ("$(wildcard $(NRS_DRV_PATH)/ko.$(NRS_CHIP))", "")
ifeq ("$(wildcard $(NRS_DRV_PATH)/ko.$(NRS_CHIP).minimal)", "")
ifeq ("$(wildcard $(NRS_DRV_PATH)/ko.$(NRS_CHIP).linux6.1.minimal)", "")
ifeq ("$(wildcard $(NRS_DRV_PATH)/ko.$(NRS_CHIP).linux6.1)", "")
	$(error NRS error: ko.$(NRS_CHIP) or ko.$(NRS_CHIP).linux6.1.minimal or ko.$(NRS_CHIP).linux6.1 not found)
endif
endif
endif
endif
ifeq ($(CONFIG_UCLIBC),y)
ifeq ($(CONFIG_KERNEL_V6_1),y)
	$(Q)ln -nsf $(NRS_DRV_PATH)/ko.$(NRS_CHIP).linux6.1.minimal $(NRS_DRV_KO)
else
	$(Q)ln -nsf $(NRS_DRV_PATH)/ko.$(NRS_CHIP).minimal $(NRS_DRV_KO)
endif
else
ifeq ($(CONFIG_KERNEL_V6_1),y)
	$(Q)ln -nsf $(NRS_DRV_PATH)/ko.$(NRS_CHIP).linux6.1 $(NRS_DRV_KO)
else
	$(Q)ln -nsf $(NRS_DRV_PATH)/ko.$(NRS_CHIP) $(NRS_DRV_KO)
endif
endif
endif

.PHONY: rebuild
rebuild: clean build

.PHONY: clean
clean:
ifneq ($(CONFIG_RELEASE), y)
	$(Q)$(MAKE) -C $(NRS_DRV_SRC) clean
endif
	$(Q)rm -rf $(NRS_DRV_KO)

.PHONY: distclean
distclean: clean

.PHONY: install
install: $(DEST)
	$(Q)install -m 666 $(INSTALL_MODS) $(DEST)
ifneq ($(NRS_SCRIPT_PFMDIR), )
ifneq ($(wildcard $(TARGET_SCIPRTS)), )
	$(Q)install -d $(NRS_SCRIPT_DSTDIR)
	$(Q)install -m 755 $(TARGET_SCIPRTS) $(NRS_SCRIPT_DSTDIR)
	$(Q)install -m 755 $(NRS_SCRIPT_PFMDIR) $(NRS_SCRIPT_DSTDIR)
endif
endif

.PHONY: reinstall
reinstall: uninstall install

.PHONY: update
update: rebuild reinstall

.PHONY: uninstall
uninstall:
	$(Q)rm -rf $(INSTALL_TRGTS)
	$(Q)rm -rf $(NRS_SCRIPT_DSTDIR)/efuse_*.sh

$(DEST):
	$(Q)install -d $@
