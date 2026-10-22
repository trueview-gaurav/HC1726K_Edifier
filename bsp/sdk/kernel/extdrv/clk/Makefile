# The include declaration here will be used by this Makefile and kernel.
# We correct it if the kernel used this macro
SDKSRC_DIR ?= $(realpath $(CURDIR)/../../../../)
ifeq ("$(wildcard $(SDKSRC_DIR)/firmware/build/sdksrc.mk)","")
SDKSRC_DIR := $(realpath $(CURDIR)/../../..)
endif
include $(SDKSRC_DIR)/firmware/build/sdksrc.mk

DRV = clk-augentix-test.ko

ccflags-y += -I.

obj-m += clk-augentix-test.o

.PHONY: all
all:
	$(Q)$(MAKE) -C $(KERNEL_PATH) M=$$PWD modules

.PHONY: install
install:
	$(Q)$(MAKE) INSTALL_MOD_PATH=$(SYSROOT) \
		INSTALL_MOD_DIR=augentix -C $(KERNEL_PATH) M=$$PWD modules_install

DRV_INSTALL_PATH=$(SYSROOT)/lib/modules/$(SDK_KERNEL_VERSION)/augentix
INSTALL_TRGT := $(addprefix $(DRV_INSTALL_PATH)/, $(DRV))

.PHONY: clean
clean:
	$(Q)$(MAKE) -C $(KERNEL_PATH) M=$$PWD clean

