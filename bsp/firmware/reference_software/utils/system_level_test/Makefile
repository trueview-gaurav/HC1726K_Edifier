SDKSRC_DIR ?= $(realpath $(CURDIR)/../../../..)
include $(SDKSRC_DIR)/firmware/build/sdksrc.mk
include $(APP_PATH)/internal.mk
INSTALL := install -c

SLT_SCRIPT_DSTDIR = $(USRDATAFS)
TARGET_SCIPRTS := $(wildcard scripts/*.sh)

ifeq ($(CONFIG_CHIP), HC1785)
	SLT_SCRIPT_PFMDIR := $(CURDIR)/scripts/hc1785/*
else ifeq ($(CONFIG_CHIP), HC1706K)
	SLT_SCRIPT_PFMDIR := $(CURDIR)/scripts/hc1706/*
else ifeq ($(CONFIG_CHIP), HC1706K_ES)
	SLT_SCRIPT_PFMDIR := $(CURDIR)/scripts/hc1706/*
else ifeq ($(CONFIG_CHIP), HC1706)
	SLT_SCRIPT_PFMDIR := $(CURDIR)/scripts/hc1706/*
else ifeq ($(CONFIG_CHIP), HC1706H)
	SLT_SCRIPT_PFMDIR := $(CURDIR)/scripts/hc1706/*
else ifeq ($(CONFIG_CHIP), HC1726)
	SLT_SCRIPT_PFMDIR := $(CURDIR)/scripts/hc1726/*
else ifeq ($(CONFIG_CHIP), HC1705L)
	SLT_SCRIPT_PFMDIR := $(CURDIR)/scripts/hc1705l/*
else ifeq ($(CONFIG_CHIP), HC1783S)
	SLT_SCRIPT_PFMDIR := $(CURDIR)/scripts/hc1725s_53s_83s/*
else ifeq ($(CONFIG_CHIP), HC1725S)
	SLT_SCRIPT_PFMDIR := $(CURDIR)/scripts/hc1725s_53s_83s/*
else ifeq ($(CONFIG_CHIP), HC1753S)
	SLT_SCRIPT_PFMDIR := $(CURDIR)/scripts/hc1725s_53s_83s/*
else ifeq ($(CONFIG_CHIP), HC1705)
	SLT_SCRIPT_PFMDIR := $(CURDIR)/scripts/hc1703_05/*
else ifeq ($(CONFIG_CHIP), HC1705I)
	SLT_SCRIPT_PFMDIR := $(CURDIR)/scripts/hc1703_05/*
else ifeq ($(CONFIG_CHIP), HC1705K)
	SLT_SCRIPT_PFMDIR := $(CURDIR)/scripts/hc1703_05/*
else ifeq ($(CONFIG_CHIP), HC1703)
	SLT_SCRIPT_PFMDIR := $(CURDIR)/scripts/hc1703_05/*
else ifeq ($(CONFIG_CHIP), HC1703L)
	SLT_SCRIPT_PFMDIR := $(CURDIR)/scripts/hc1703l/*
else
	SLT_SCRIPT_PFMDIR := $(CURDIR)/scripts/hc1715_23_25_53/*
endif

GOLDEN_FILE := $(CURDIR)/golden/*

DST_TARGET_SCRIPTS := $(subst scripts,$(SLT_SCRIPT_DSTDIR),$(TARGET_SCIPRTS))

.DEFAULT_GOAL := default

.PHONY: default
default: all

.PHONY: all
all: ;

.PHONY: install
install:
	$(Q)echo "WARNING: ethtool_gclibc and ethtool_uclibc are not included in the SDK due to license issues. See #108435#note-7 if SLT is required."
	$(Q)$(INSTALL) -d $(SLT_SCRIPT_DSTDIR)
	$(Q)$(INSTALL) -m 755 $(TARGET_SCIPRTS) $(SLT_SCRIPT_DSTDIR)
	$(Q)$(INSTALL) -m 755 $(SLT_SCRIPT_PFMDIR) $(SLT_SCRIPT_DSTDIR)
	$(Q)$(INSTALL) $(GOLDEN_FILE) $(SLT_SCRIPT_DSTDIR)

.PHONY: uninstall
uninstall:
	$(Q)$(RM) $(DST_TARGET_SCRIPTS)

.PHONY: clean
clean: ;

.PHONY: distclean
distclean: uninstall clean
