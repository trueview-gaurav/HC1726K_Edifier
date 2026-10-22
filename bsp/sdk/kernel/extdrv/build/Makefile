SDKSRC_DIR ?= $(realpath $(CURDIR)/../../../..)
include $(SDKSRC_DIR)/firmware/build/sdksrc.mk

TARGETS =
TARGETS_INSTALL := $(addsuffix -install, $(TARGETS))
TARGETS_CLEAN :=  $(addsuffix -clean, $(TARGETS))

# SDK source only
SDKSRC_TARGETS =
SDKSRC_INSTALL := $(addsuffix -install, $(SDKSRC_TARGETS))
SDKSRC_CLEAN :=  $(addsuffix -clean, $(SDKSRC_TARGETS))

################################################################################
# Temporary parser/iniparser/sample libs
################################################################################

.PHONY: default
default: all

.PHONY: all
all: $(TARGETS)

.PHONY: $(TARGETS) $(SDKSRC_TARGETS)
$(TARGETS) $(SDKSRC_TARGETS):
	$(Q)$(MAKE) -C ../$@ all

.PHONY: $(TARGETS_INSTALL) $(SDKSRC_INSTALL)
$(TARGETS_INSTALL) $(SDKSRC_INSTALL):
	$(Q)$(MAKE) -C ../$(patsubst %-install,%,$@) install

.PHONY: $(TARGETS_CLEAN) $(SDKSRC_CLEAN)
$(TARGETS_CLEAN) $(SDKSRC_CLEAN):
	$(Q)$(MAKE) -C ../$(patsubst %-clean,%,$@) clean

.PHONY: install
install: $(TARGETS_INSTALL)

.PHONY: clean
clean: $(TARGETS_CLEAN)
