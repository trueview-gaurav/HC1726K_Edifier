# The include declaration here will be used by this Makefile and kernel.
# We correct it if the kernel used this macro
SDKSRC_DIR ?= $(realpath $(CURDIR)/../../../..)
ifeq ("$(wildcard $(SDKSRC_DIR)/firmware/build/sdksrc.mk)","")
SDKSRC_DIR := $(realpath $(CURDIR)/../../..)
endif
include $(SDKSRC_DIR)/firmware/build/sdksrc.mk

DRV = pwm-consumer_test.ko

ccflags-y += -I. -I$(GEN_INC) -I$(SDK_INC)

obj-m += pwm-consumer_test.o

.PHONY: all
all: $(DRV)

.PHONY: clean
clean:
	$(Q)$(MAKE) -C $(KERNEL_PATH) M=$$PWD clean

.PHONY: distclean
distclean: clean

$(DRV):
	$(Q)$(MAKE) -C $(KERNEL_PATH) M=$$PWD modules
