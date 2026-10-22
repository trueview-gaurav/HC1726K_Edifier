################################################################################
# SDK related definitions
################################################################################

SDKSRC_DIR ?= $(realpath $(CURDIR)/../../../../../..)
include $(SDKSRC_DIR)/firmware/build/sdksrc.mk
include $(SDKSRC_DIR)/firmware/build/build_utils/lib.mk
include $(ABIVER_MAKE)

################################################################################
# Build tools and commands
################################################################################

MAKEFLAGS = -j

### First, specify the build tools.
CC := $(CROSS_COMPILE)gcc
CX := $(CROSS_COMPILE)g++
AR := $(CROSS_COMPILE)ar
RM := rm -f
LN := ln
MKDIR := mkdir
RMDIR := rmdir
INSTALL := install


CFLAGS_ALL := -Wall -g -O2 -MMD ${PERF_NO_OMIT_FP} -D_GNU_SOURCE -mcpu=$(CONFIG_TARGET_CPU)
LFLAGS_ALL :=

### Finally, define complete commands for all actions. 

COMPILE = $(CFLAGS_ALL) $(CFLAGS_LOCAL) -o $@ -c $<
LINK = $(CC) -o $@ -Wl,--start-group $^ -Wl,--end-group $(LFLAGS_ALL) $(LFLAGS_LOCAL)
ARCHIVE_STATIC = $(AR) rcsD $@ $^
ARCHIVE_SHARED = $(CC) -shared -Wl,--build-id -Wl,--soname,$(basename $(basename $(notdir $@))) -o $@ \
		-Wl,--whole-archive $^ -Wl,--no-whole-archive

################################################################################
# Build rules
################################################################################

### First, define default build target.

all: primary

### Second, define variables for collecting outputs and temporarily objects.

TARGET_SLIBS :=
TARGET_DLIBS :=
TARGET_TESTS :=
TARGET_DOCS :=
CLEAN_FILES :=
CLEAN_DIRS  :=

### Then, collect the knowledge about how to build all outputs.

root := $(realpath ..)
dir := $(root)/build
chip_type := $(call chip,$(CONFIG_CHIP))


#    subdir := $(root)/src/linux
#    include $(subdir)/mod.mk

    subdir := $(root)/src/freertos
    include $(subdir)/mod.mk


.PHONY: primary
    primary: $(TARGET_SLIBS) $(TARGET_DLIBS)


.PHONY: clean
    clean: 
	@printf "  %-8s$(root)\n" "CLEAN"
	$(Q)$(RM) -f $(CLEAN_FILES)
	$(Q)$(foreach d, $(CLEAN_DIRS), $(RM) -rf $(d); )

.PHONY: install
install: all

.PHONY: uninstall
uninstall:

.PHONY: distclean
distclean: uninstall clean
	$(Q)$(RM) -rf $(root)/lib

.PHONY: help
help:
	@echo ""
	@echo "  Syntax:"
	@echo "    make [options] <target>"
	@echo ""
	@echo "  Options:"
	@echo "    V=0         Hide command lines. (default)"
	@echo "    V=1         Show command lines."
	@echo ""
	@echo "  Targets:"
	@echo "    all                             Build primary outputs. (default)"
	@echo "    clean                           Clean all outputs."
	@echo "    distclean                       Clean all outputs and configurations."
	@echo "    install                         Install primary outputs"
	@echo "    uninstall                       Uninstall primary outputs"
	@echo "    help                            Show help messages."
	@echo ""


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
# Prevent make from removing any build targets, including intermediate ones
################################################################################

.SECONDARY: $(CLEAN_FILES) $(CLEAN_DIRS)

