# The include declaration here will be used by this Makefile and kernel.
# We correct it if the kernel used this macro
SDKSRC_DIR ?= $(realpath $(CURDIR)/../../../..)
ifeq ("$(wildcard $(SDKSRC_DIR)/firmware/build/sdksrc.mk)","")
SDKSRC_DIR := $(realpath $(CURDIR)/../../..)
endif
include $(SDKSRC_DIR)/firmware/build/sdksrc.mk

DRV = eirq_pir.ko
DEST := $(CUSTOMFS)

ccflags-y += -I.

obj-m += eirq-pir-augentix.o

.PHONY: all
all:
	$(Q)$(MAKE) -C $(KERNEL_PATH) M=$$PWD modules

.PHONY: install
install:
	$(Q)$(MAKE) INSTALL_MOD_PATH=$(DEST) \
		INSTALL_MOD_DIR=augentix -C $(KERNEL_PATH) M=$$PWD modules_install

DRV_INSTALL_PATH=$(DEST)/lib/modules/$(SDK_KERNEL_VERSION)/augentix
INSTALL_TRGT := $(addprefix $(DRV_INSTALL_PATH)/, $(DRV))
.PHONY: uninstall
uninstall:
	@rm -rf $(INSTALL_TRGT)

.PHONY: clean
clean: uninstall
	$(Q)$(MAKE) -C $(KERNEL_PATH) M=$$PWD clean

