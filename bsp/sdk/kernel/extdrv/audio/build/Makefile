SDKSRC_DIR ?= $(realpath $(CURDIR)/../../../../..)
ifeq ("$(wildcard $(SDKSRC_DIR)/firmware/build/sdksrc.mk)","")
SDKSRC_DIR := $(realpath $(CURDIR)/../../..)
endif
include $(SDKSRC_DIR)/firmware/build/sdksrc.mk

DEST := $(AGTX_MOD_PATH)
KO_DIR = $(AUDIO_KO)
ADCDAC_DIR=$(AUDIO_PATH)/drv/agtx

TARGETS := $(ADCDAC_DIR)

TARGETS_INSTALL := $(addsuffix -install, $(TARGETS))
TARGETS_CLEAN :=  $(addsuffix -clean, $(TARGETS))

.PHONY: all
all: $(TARGETS)

$(TARGETS): %: FORCE
	$(MAKE) -C $@ all install

FORCE:
.PHONY: FORCE

.PHONY: install
install: all
	$(Q)if [ -d $(KO_DIR) ]; then \
		install -d $(DEST); \
		install -m 666 $(KO_DIR)/* $(DEST); \
	fi

.PHONY: uninstall
uninstall:
ifneq (,$(wildcard $(KO_DIR)))
	$(Q)find $(KO_DIR) -name *.ko -printf "$(DEST)/%f\n" | xargs rm -f
endif
ifneq (,$(wildcard $(DEST)))
	$(Q)find $(DEST) -type d -empty -delete
endif

.PHONY: clean
clean: uninstall $(TARGETS_CLEAN)
	$(Q)rm -f $(KO_DIR)/*

$(TARGETS_CLEAN): %:
	$(MAKE) -C $(subst -clean,,$@) clean

.PHONY: distclean
distclean: clean
