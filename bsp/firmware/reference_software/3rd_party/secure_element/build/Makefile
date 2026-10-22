################################################################################
# SDK related definitions
################################################################################

SDKSRC_DIR ?= $(realpath $(CURDIR)/../../../../..)
include $(SDKSRC_DIR)/firmware/build/sdksrc.mk
include $(APP_PATH)/internal.mk

################################################################################
# Build tools and commands
################################################################################

MAKEFLAGS = -j

### First, specify the build tools.
ifeq ($(CONFIG_UCLIBC),y)
XTOOL_PATH := $(XTOOL_PATH_2)
CROSS_COMPILE := $(CROSS_COMPILE_2)
endif

CMAKE := cmake

CC := $(CROSS_COMPILE)gcc
CX := $(CROSS_COMPILE)g++
AR := $(CROSS_COMPILE)ar
RM := rm
LN := ln
CP := cp
CHMOD := chmod
MKDIR := mkdir
RMDIR := rmdir
INSTALL := install
INSTALL_DATA := $(INSTALL) -c -m 644
TAR := tar
NICE := nice

NICENESS := 19
TAR_CHECKPOINT := 8000
NICE_TAR := $(NICE) -n $(NICENESS) $(TAR) --checkpoint=.$(TAR_CHECKPOINT)

### Then, define global compilation and linking flags.

### If app link with -Wl,--gc-sections, then it will not link unsed function and data
CFLAGS_ALL := -MMD -ffunction-sections -fdata-sections -g
LFLAGS_ALL :=

### Finally, define complete commands for all actions.

COMPILE = $(CFLAGS_ALL) $(CFLAGS_LOCAL) -o $@ -c $<
LINK = -o $@ -Wl,--start-group $^ -Wl,--end-group $(LFLAGS_ALL) $(LFLAGS_LOCAL)
ARCHIVE_STATIC = $(AR) rcsD $@ $^
ARCHIVE_SHARED = -shared -Wl,--build-id -Wl,--soname,$(basename $(basename $(notdir $@))) -o $@ \
		-Wl,--whole-archive $^ -Wl,--no-whole-archive

################################################################################
# Build rules
################################################################################

### First, define default build target.

all: primary

### Second, define variables for collecting outputs and temporarily objects.

LIB_NAME = se
TARGET_SLIBS := 
TARGET_DLIBS :=
TARGET_TESTS :=
TARGET_DOCS :=
CLEAN_FILES :=
CLEAN_DIRS  :=

### Then, collect the knowledge about how to build all outputs.

root := $(realpath ..)
dir := $(root)/build

TARGET_DLIBS += $(root)/lib/lib$(LIB_NAME).so

### Finally, define essential build targets.

.PHONY: default
default: all

.PHONY: all
all: primary

.PHONY: build
build:

.PHONY: primary
primary:

.PHONY: clean
clean:

.PHONY: distclean
distclean: clean

.PHONY: install
install: all
	$(Q)$(MKDIR) -p $(CUSTOM_LIB)
	$(Q)$(foreach f, $(TARGET_DLIBS), \
		printf "  INSTALL\t$(CUSTOM_LIB)/$(notdir $(f))\n"; \
		$(INSTALL) -m 644 -t $(CUSTOM_LIB) $(f); \
		ln -sf $(notdir $(f)) $(CUSTOM_LIB)/lib$(LIB_NAME).so.3; \
	)

.PHONY: uninstall
uninstall:
	$(Q)$(foreach f, $(TARGET_DLIBS), \
		printf "  UNINSTALL\t$(CUSTOM_LIB)/$(notdir $(f))\n"; \
		$(RM) -f $(CUSTOM_LIB)/$(notdir $(f)); \
		$(RM) -f $(CUSTOM_LIB)/lib$(LIB_NAME).so.3; \
	)
	$(Q)if [ -d $(CUSTOM_LIB) ]; then \
		$(RMDIR) --ignore-fail-on-non-empty $(CUSTOM_LIB); \
	fi

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
	@echo "    all         Build primary outputs. (default)"
	@echo "    clean       Clean all outputs."
	@echo "    distclean   Clean all outputs and configurations."
	@echo "    install     Install primary outputs"
	@echo "    uninstall   Uninstall primary outputs"
	@echo "    pack        Pack primary outputs into tarball."
	@echo "    push        Push tarball to remote server."
	@echo "    help        Show help messages."
	@echo ""

################################################################################
# General rules
################################################################################

%.o: %.c
	@printf "  CC\t$@\n"
	$(Q)$(CC) $(COMPILE) $(CFLAGS)

%.o: %.cc
	@echo $(CXXFLAGS)
	@printf "  CXX\t$@\n"
	$(Q)$(CXX) $(COMPILE) $(CXXFLAGS)

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
