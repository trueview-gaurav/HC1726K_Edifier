SDKSRC_DIR ?= $(realpath $(CURDIR)/../../../..)
include $(wildcard $(SDKSRC_DIR)/firmware/build/sdksrc.mk)

TRGT := dbgif
SRCS := $(notdir $(wildcard ./*.c))
OBJS := $(SRCS:.c=.o)
DEST := $(SYSROOT)/root/verification
INSTALL_TRGT := $(addprefix $(DEST)/,$(TRGT).ko vrf.ko)

INC := -I$(CSR_DIR) -I$(SDK_INC)

ccflags-y += -gdwarf-2
ccflags-y += $(INC)

obj-m += $(TRGT).o
$(TRGT)-objs := debugif.o spi_hc18xx.o

obj-m += vrf.o
vrf-objs := vrf_debugif.o

.PHONY: all
all:
	$(MAKE) -C $(KERNEL_PATH) M=$(PWD) modules

.PHONY: install
install: $(DEST) $(INSTALL_TRGT)

$(DEST):
	$(Q)install -d $@

$(DEST)/%: %
	$(Q)install -m 644 $< $@

.PHONY: uninstall
uninstall:
	$(Q)rm -f $(INSTALL_TRGT)

.PHONY: clean
clean: uninstall
	$(MAKE) -C $(KERNEL_PATH) M=$(PWD) clean
