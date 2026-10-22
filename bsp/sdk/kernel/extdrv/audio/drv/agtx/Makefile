# The include declaratio here will be used by this Makefile and kernel.
# We correct it if the kernel used this macro
SDKSRC_DIR ?= $(realpath $(CURDIR)/../../../../../..)
ifeq ("$(wildcard $(SDKSRC_DIR)/firmware/build/sdksrc.mk)","")
SDKSRC_DIR := $(realpath $(CURDIR)/../../..)
endif
include $(SDKSRC_DIR)/firmware/build/sdksrc.mk

AUDIO_CODEC ?=

TARGETS := audio_machine
OBJS := $(TARGETS:%=%.o)
MODS := $(TARGETS:%=%.ko)
DEST := $(AUDIO_KO)
INSTALL_TRGTS := $(addprefix $(DEST)/, $(MODS))

KBUILD_EXTRA_SYMBOLS +=

ccflags-y += -gdwarf-2
ccflags-y += -I$(PWD) -I$(CPVS_INC)/audio -I$(CPVS_INC)/dram -I$(CPVS_CSR_INC)
ccflags-y += -I$(SDK_INC)
ccflags-y += -Wno-date-time

obj-m += $(OBJS)

.PHONY: all
all:
	$(Q)ln -sf $(KERNEL_PATH)/sound/soc/codecs/wm8731.h wm8731.h
	$(Q)$(MAKE) -C $(KERNEL_PATH) M=$$PWD modules

.PHONY: install
install: $(INSTALL_TRGTS)

$(DEST):
	$(Q)install -d $@

$(DEST)/%: % $(DEST)
	$(Q)install -m 666 $< $@

$(MODS): all

.PHONY: uninstall
uninstall:
	$(Q)rm -f $(INSTALL_TRGTS)
ifneq (,$(wildcard $(DEST)))
	$(Q)find $(DEST) -type d -empty -delete
endif

.PHONY: clean
clean: uninstall
	$(Q)$(MAKE) -C $(KERNEL_PATH) M=$$PWD clean
	$(Q)rm -f wm8731.h
