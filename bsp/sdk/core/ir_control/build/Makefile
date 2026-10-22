# Copyright Augentix Inc. Proprietary and confidential.
# Unauthorized use or distribution is prohibited.
# Please contact customer.support@augentix.com for any inquiries.

# SDK related definitions
################################################################################

SDKSRC_DIR ?= $(realpath $(CURDIR)/../../../../)
include $(SDKSRC_DIR)/firmware/build/sdksrc.mk
include $(SDKSRC_DIR)/firmware/build/build_utils/lib.mk
include $(SDKSRC_DIR)/firmware/build/build_flags.mk
include $(ABIVER_MAKE)

################################################################################
# Build tools and commands
################################################################################

### First, specify the build tools.
ifeq ($(CONFIG_UCLIBC),y)
XTOOL_PATH := $(XTOOL_PATH_2)
CROSS_COMPILE := $(CROSS_COMPILE_2)
endif

CC := $(CROSS_COMPILE)gcc
AR := $(CROSS_COMPILE)ar
RM := rm
LN := ln
MKDIR := mkdir
RMDIR := rmdir
INSTALL := install

### Then, define global compilation and linking flags.
CFLAGS_ALL := -MMD
LFLAGS_ALL :=
RELRO_FLAGS :=
NX_FLAGS :=

### Enable STQC option for kernel v6.1
ifeq ($(CONFIG_KERNEL_V6_1),y)
CANARY_FLAGS := -fstack-protector-strong
CFLAGS_ALL += $(CANARY_FLAGS)
RELRO_FLAGS += -Wl,-z,relro,-z,now
# FORTIFY
FORTIFY_FLAGS := -D_FORTIFY_SOURCE=2 -O2
CFLAGS_ALL   += $(FORTIFY_FLAGS)
# NX / DEP
NX_FLAGS += -z noexecstack
endif

### Finally, define complete commands for all actions. 

COMPILE = $(CFLAGS_ALL) $(CFLAGS_LOCAL) -o $@ -c $<
LINK = $(CC) -o $@ -Wl,--start-group $^ -Wl,--end-group $(LFLAGS_ALL) $(LFLAGS_LOCAL)
ARCHIVE_STATIC = $(AR) rcsD $@ $^
ARCHIVE_SHARED = $(CC) -shared $(RELRO_FLAGS) $(NX_FLAGS) -Wl,--build-id -Wl,--soname,$(basename $(basename $(notdir $@))) -o $@ \
		-Wl,--whole-archive $^ -Wl,--no-whole-archive

################################################################################
# Build rules
################################################################################

### First, define default build target.

all: primary

### Second, define variables for collecting outputs and temporarily objects.

LIB_NAME = ir_control
TARGET_SLIBS :=
TARGET_DLIBS :=
TARGET_TESTS :=
CLEAN_FILES :=
CLEAN_DIRS  :=

### Then, collect the knowledge about how to build all outputs.

root := ..
dir := $(root)/build
chip_type := $(call chip,$(CONFIG_CHIP))

ifneq ($(CONFIG_RELEASE),y)
    ### In SDK manifest, traverse directory tree to include Rules.mk files.
    subdir := $(root)/src
    include $(subdir)/Rules.mk
else
    ### In APP manifest, specify outputs manually.
    TARGET_SLIBS += $(root)/lib/lib$(LIB_NAME).a
    TARGET_DLIBS += $(root)/lib/lib$(LIB_NAME).so.$(REAL_SUFFIX)
endif

### Finally, define essential build targets.

.DEFAULT_GOAL := default

.PHONY: default
default: all

.PHONY: all
all: primary

.PHONY: primary
ifneq ($(CONFIG_RELEASE),y)
    ### In SDK manifest, build primary outputs if necessary. 
    primary: $(TARGET_SLIBS) $(TARGET_DLIBS)
	@echo feature/ir_control CROSS_COMPILE: $(CROSS_COMPILE)
else
    ### In APP manifest, create link to pre-built primary outputs.
    primary:
	@echo feature/ir_control CROSS_COMPILE: $(CROSS_COMPILE)
ifeq ($(CONFIG_UCLIBC),y)
	$(Q)$(LN) -sfT lib.$(chip_type).uclibc $(root)/lib
else
	$(Q)$(LN) -sfT lib.$(chip_type) $(root)/lib
endif
endif

.PHONY: clean
ifneq ($(CONFIG_RELEASE),y)
    ### In SDK manifest, remove primary outputs and temporarily objects.
    clean: 
	@printf "  CLEAN\t$(root)\n"
	$(Q)$(RM) -f $(CLEAN_FILES)
	$(Q)$(foreach d, $(CLEAN_DIRS), $(RM) -rf $(d); )
else
    ### In APP manifest, remove the link to pre-build primary outputs.
    clean:
	@printf "  CLEAN\t$(root)\n"
	$(Q)$(RM) -f $(root)/lib
endif

.PHONY: distclean
distclean: clean

.PHONY: install
install: all
	$(Q)$(MKDIR) -p $(CUSTOM_LIB)
	$(Q)$(foreach f, $(TARGET_DLIBS), \
		printf "  INSTALL\t$(CUSTOM_LIB)/$(notdir $(f))\n"; \
		find $(CUSTOM_LIB) -type f \( -name $(basename $(basename $(basename $(notdir $(f))))).* -not -name $(notdir $(f)) \) -exec rm -rf {} \;; \
		$(INSTALL) -m 644 -t $(CUSTOM_LIB) $(f); \
		$(LN) -sfT $(notdir $(f)) $(CUSTOM_LIB)/$(basename $(basename $(notdir $(f)))); \
	)

.PHONY: uninstall
uninstall:
	$(Q)$(foreach f, $(TARGET_DLIBS), \
		printf "  UNINSTALL\t$(CUSTOM_LIB)/$(notdir $(f))\n"; \
		$(RM) -f $(CUSTOM_LIB)/$(basename $(basename $(basename $(notdir $(f))))).*; \
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
	@echo "    help        Show help messages."
	@echo ""

################################################################################
# General rules
################################################################################

%.o: %.c
	@printf "  CC\t$@\n"
	$(Q)$(CC) $(COMPILE) $(CFLAGS)

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
