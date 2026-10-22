SDKSRC_DIR ?= $(realpath $(CURDIR)/../../../..)
ifeq ("$(wildcard $(SDKSRC_DIR)/firmware/build/sdksrc.mk)","")
SDKSRC_DIR := $(realpath $(CURDIR)/../../..)
endif
include $(SDKSRC_DIR)/firmware/build/sdksrc.mk

DRV = clk-hc1703_1723_1753_1783s-test.ko
DRV_INSTALL_PATH=$(SYSROOT)/lib/modules/$(SDK_KERNEL_VERSION)/augentix
INSTALL_TRGT := $(addprefix $(DRV_INSTALL_PATH)/, $(DRV))

.PHONY: all clean install uninstall

KDIR?=$(KERNEL_PATH)

ccflags-y += -I
ccflags-y += -I/bmgr
ccflags-y += -I/$(CSR_DIR)

obj-m   += reset-user.o
pwm_test-y  := reset-user.o

all: target

target:
	$(MAKE) -C $(KERNEL_PATH) M=$$PWD modules

install:
	$(Q)$(MAKE) INSTALL_MOD_PATH=$(SYSROOT) \
		INSTALL_MOD_DIR=augentix -C $(KERNEL_PATH) M=$$PWD modules_install

clean:
	$(Q)$(MAKE) -C $(KERNEL_PATH) M=$$PWD clean

