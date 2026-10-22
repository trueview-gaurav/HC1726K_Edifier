################################################################################
# SDK related definitions
################################################################################

SDKSRC_DIR ?= $(realpath $(CURDIR)/../../../../..)
include $(SDKSRC_DIR)/firmware/build/sdksrc.mk
include $(SDKSRC_DIR)/firmware/build/build_utils/lib.mk

################################################################################
# Build tools
################################################################################

RM := rm
LN := ln
MKDIR := mkdir
RMDIR := rmdir
INSTALL := install
CP := cp

################################################################################
# Quiet options
################################################################################

V ?= 0
ifeq ($(V),1)
	Q :=
	VOUT :=
else
	Q := @
	VOUT := 2>&1 1>/dev/null
endif

################################################################################
# Default target
################################################################################

.PHONY: all
all: target

# Name of actual product layout file
LAYOUT_SRC := $(patsubst "%",%,$(CONFIG_NVSP_LAYOUT))
# Name of product layout ini file
LAYOUT_PRODUCT_INI := $(patsubst "%.ini",%.h,$(CONFIG_NVSP_LAYOUT))

################################################################################
# Directory Definition
################################################################################

root := ..
dir := $(root)

CLIENT_PATH := $(root)/client
FLASH_PROGRAMMER_PATH := $(root)/flash_programmer
NVSP_SERVLET_PATH := $(root)/nvsp_servlet
PRODUCT_LAYOUT_PATH := $(root)/product

FLASH_PROGRAMMER_DEST := $(BINPKG_DIR)/flash_programmer
NVSP_SERVLET_DEST := $(BINPKG_DIR)/nvsp_servlet
################################################################################
# Targets
################################################################################

.PHONY: target
target:
	$(Q)$(MAKE) -C $(CLIENT_PATH) all

.PHONY: install
install: server-install client-install
	$(Q)$(INSTALL) -d $(BINPKG_DIR)
	$(Q)$(INSTALL) -m 777 $(root)/bin/*.bin $(BINPKG_DIR)

# Install server and product layout ini
.PHONY: server-install
server-install:
	$(Q)$(INSTALL) -d $(FLASH_PROGRAMMER_DEST)
	$(Q)$(INSTALL) -d $(NVSP_SERVLET_DEST)
	$(Q)$(CP) -r $(FLASH_PROGRAMMER_PATH)/* $(FLASH_PROGRAMMER_DEST)
	$(Q)$(CP) -r $(NVSP_SERVLET_PATH)/* $(NVSP_SERVLET_DEST)
	$(Q)$(INSTALL) $(PRODUCT_LAYOUT_PATH)/$(LAYOUT_SRC) $(BINPKG_DIR)

.PHONY: client-install
client-install:
	$(Q)$(MAKE) -C $(CLIENT_PATH) install

.PHONY: clean
clean:
	$(Q)$(MAKE) -C $(CLIENT_PATH) clean
	@rm -rf $(FLASH_PROGRAMMER_DEST)
	@rm -rf $(NVSP_SERVLET_DEST)

UHDR_DEST    := $(UBOOT_PATH)/include/configs/augentix/generated
UHDR_SRC_DIR := $(root)/product
UHDR_NAME    := flash_layout.h

$(UHDR_SRC_DIR)/$(UHDR_NAME):

.PHONY: gen_uhdr
gen_uhdr: $(UHDR_SRC_DIR)/$(UHDR_NAME)

.PHONY: gen_uhdr-install
gen_uhdr-install: gen_uhdr
	ln -f -s $(UHDR_SRC_DIR)/$(LAYOUT_PRODUCT_INI) $(UHDR_SRC_DIR)/$(UHDR_NAME)
	$(Q)$(INSTALL) -d $(UHDR_DEST)
	$(Q)$(INSTALL) $(UHDR_SRC_DIR)/$(UHDR_NAME) $(UHDR_DEST)/

.PHONY: gen_uhdr-uninstall
gen_uhdr-uninstall:
	@rm -f $(UHDR_DEST)/$(UHDR_NAME)

.PHONY: gen_uhdr-clean
gen_uhdr-clean: gen_uhdr-uninstall

################################################################################
# Prevent make from removing any build targets, including intermediate ones
################################################################################

.SECONDARY: $(CLEAN_FILES) $(CLEAN_DIRS)
