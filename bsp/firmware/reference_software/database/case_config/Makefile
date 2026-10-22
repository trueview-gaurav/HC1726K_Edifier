SDKSRC_DIR ?= $(realpath $(CURDIR)/../../../..)
include $(SDKSRC_DIR)/firmware/build/sdksrc.mk
include $(APP_PATH)/internal.mk
include $(SAMPLE_DEMO_PATH)/internal.mk

PRODUCT_DIR := $(CONFIG_MACH)
INSTALL_PATH := $(SYSTEMFS)/mpp/case_config

.PHONY: all
all: 

.PHONY: install
install:
	for item in $(CASE_CONFIG); do \
		if [ -e "$(CASE_CONFIG_PATH)/$(PRODUCT_DIR)/$$item" ]; then \
			cp -f "$(CASE_CONFIG_PATH)/$(PRODUCT_DIR)/$$item" "$(SYSTEMFS)/mpp/case_config/"; \
		fi \
	done


.PHONY: uninstall
uninstall: clean

.PHONY: clean
clean:
	for item in $(CASE_CONFIG); do \
		rm -f "$(SYSTEMFS)/mpp/case_config/$$item"; \
	done

.PHONY: distclean
distclean: uninstall clean

sinclude $(DEPS)
