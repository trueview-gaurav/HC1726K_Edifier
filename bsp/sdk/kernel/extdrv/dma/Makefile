.PHONY: all clean install

SDKSRC_DIR ?= $(realpath $(CURDIR)/../../../..)
ifeq ("$(wildcard $(SDKSRC_DIR)/firmware/build/sdksrc.mk)","")
SDKSRC_DIR := $(realpath $(CURDIR)/../../..)
endif
include $(SDKSRC_DIR)/firmware/build/sdksrc.mk

INSTALL_DIR := $(NFS)

ccflags-y += -gdwarf-2
ccflags-y += -I$(SDK_INC) -I$(KVPP_INC) -I$(KTRC_INC) -I$(UTRC_INC) -I$(UTRC_COMMON_INC) -I$(CPVS_INC)
ccflags-y += -D_DEBUG

obj-m += augentix-dma-client.o

all: test

install:
	@mkdir -p $(INSTALL_DIR)
	@cp -f *.ko $(INSTALL_DIR)

test:
	$(MAKE) -C $(KERNEL_PATH) M=$(PWD) modules

clean:
	$(MAKE) -C $(KERNEL_PATH) M=$(PWD) clean
