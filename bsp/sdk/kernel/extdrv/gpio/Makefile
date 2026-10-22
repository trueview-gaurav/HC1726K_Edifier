# The include declaration here will be used by this Makefile and kernel.
# We correct it if the kernel used this macro
SDKSRC_DIR ?= $(realpath $(CURDIR)/../../../..)
ifeq ("$(wildcard $(SDKSRC_DIR)/firmware/build/sdksrc.mk)","")
SDKSRC_DIR := $(realpath $(CURDIR)/../../..)
endif
include $(SDKSRC_DIR)/firmware/build/sdksrc.mk

DRV = gpio-hc1703_1723_1753_1783s-test.ko gpio-augentix-timer.ko gpio-augentix-v2-test.ko

ccflags-y += -I. -I$(GEN_INC) -I$(SDK_INC)

obj-m += gpio-hc1703_1723_1753_1783s-test.o gpio-augentix-timer.o gpio-augentix-v2-test.o

.PHONY: all
all: $(DRV)

.PHONY: clean
clean:
	$(Q)$(MAKE) -C $(KERNEL_PATH) M=$$PWD clean

.PHONY: distclean
distclean: clean

$(DRV):
	$(Q)$(MAKE) -C $(KERNEL_PATH) M=$$PWD modules
