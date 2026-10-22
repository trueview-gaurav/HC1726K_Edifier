# Copyright Augentix Inc. Proprietary and confidential.
# Unauthorized use or distribution is prohibited.
# Please contact customer.support@augentix.com for any inquiries.

################################################################################
# SDK related definitions
################################################################################

SDKSRC_DIR ?= $(realpath $(CURDIR)/../../../..)
include $(SDKSRC_DIR)/firmware/build/build_utils/lib.mk
include $(SDKSRC_DIR)/firmware/build/sdksrc.mk
include $(SDKSRC_DIR)/firmware/build/build_flags.mk
include $(SAMPLE_DEMO_PATH)/internal.mk
include $(ABIVER_MAKE)

CPU_FLAG=-mcpu=$(CONFIG_TARGET_CPU)

################################################################################
# Build tools and commands
################################################################################

MAKEFLAGS = -j

### First, specify the build tools.
ifeq ($(CONFIG_UCLIBC),y)
XTOOL_PATH := $(XTOOL_PATH_2)
CROSS_COMPILE := $(CROSS_COMPILE_2)
endif

CC := $(CROSS_COMPILE)gcc
CXX := $(CROSS_COMPILE)g++
STRIP := $(CROSS_COMPILE)strip
AR := $(CROSS_COMPILE)ar
RM := rm
LN := ln
MKDIR := mkdir
RMDIR := rmdir
INSTALL := install

### Then, define global compilation and linking flags.

### If app link with -Wl,--gc-sections, then it will not link unsed function and data
CFLAGS_COMMON := $(CPU_FLAG) -mfpu=neon-vfpv4 -O2 -Wall -Wextra -Werror -MMD -DSOCKLEN_T=socklen_t -D_LARGEFILE_SOURCE=1 -D_FILE_OFFSET_BITS=64 -DBSD=1 -g
CFLAGS_COMMON += -Wno-missing-field-initializers -Wno-unused-parameter -Wno-unused-function
CFLAGS_COMMON += -ffunction-sections -fdata-sections
LFLAGS_ALL :=
LDLIBS :=
RELRO_FLAGS :=
FORTIFY_FLAGS :=
NX_FLAGS :=

### Enable STQC option for kernel v6.1
ifeq ($(CONFIG_KERNEL_V6_1),y)
CANARY_FLAGS := -fstack-protector-strong
CFLAGS_COMMON += $(CANARY_FLAGS)
RELRO_FLAGS += -Wl,-z,relro,-z,now
FORTIFY_FLAGS += -D_FORTIFY_SOURCE=2 -O2
CFLAGS_COMMON   += $(FORTIFY_FLAGS)
NX_FLAGS += -Wl,-z,noexecstack -Wl,-z,noexecheap
endif
### Finally, define complete commands for all actions.

CFLAGS = $(CFLAGS_COMMON) $(CFLAGS_LOCAL) -std=gnu11
CXXFLAGS = $(CFLAGS_COMMON) $(CFLAGS_LOCAL) -std=c++14
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

TARGET_SLIBS :=
TARGET_DLIBS :=
TARGET_CD_DLIBS :=
TARGET_TESTS :=
TARGET_DOCS :=
CLEAN_FILES :=
CLEAN_DIRS  :=

### Then, collect the knowledge about how to build all outputs.

root := $(realpath ..)
dir := $(root)/build
chip_type := $(call chip,$(CONFIG_CHIP))

ifneq ($(CONFIG_RELEASE),y)
    ### In SDK manifest, traverse directory tree to include Rules.mk files.
    subdir := $(root)/doc
    include $(subdir)/Rules.mk

    subdir := $(root)/src
    include $(subdir)/Rules.mk
else
    ### In APP manifest, specify outputs manually.
    TARGET_SLIBS += $(root)/lib/libaftr.a $(root)/lib/libaftr_cd.a
    TARGET_DLIBS += $(root)/lib/libaftr.so.$(REAL_SUFFIX)
    TARGET_CD_DLIBS += $(root)/lib/libaftr_cd.so.$(REAL_SUFFIX)
endif

### Finally, define essential build targets.

.PHONY: primary
ifneq ($(CONFIG_RELEASE),y)
    ### In SDK manifest, build primary outputs if necessary.
    primary: $(TARGET_SLIBS) $(TARGET_DLIBS) $(TARGET_CD_DLIBS)
	@echo feature/audio CROSS_COMPILE: $(CROSS_COMPILE)
else
    ### In APP manifest, create link to pre-built primary outputs.
    primary:
	@echo feature/audio CROSS_COMPILE: $(CROSS_COMPILE)
ifeq ($(CONFIG_UCLIBC),y)
	$(Q)$(LN) -sfT lib.$(chip_type).uclibc $(root)/lib
else
	$(Q)$(LN) -sfT lib.$(chip_type) $(root)/lib
endif
endif

.PHONY: test
ifneq ($(CONFIG_RELEASE),y)
    ### In SDK manifest, build the test outputs if necessary.
    test: all $(TARGET_TESTS)
else
    ### In APP manifest, do nothing.
    test:
endif

.PHONY: doc
ifneq ($(CONFIG_RELEASE),y)
    ### In SDK manifest, build the doc outputs if necessary.
    doc: $(TARGET_DOCS)
else
    ### In APP manifest, do nothing.
    doc:
endif

.PHONY: clean
ifneq ($(CONFIG_RELEASE),y)
    ### In SDK manifest, remove primary outputs and temporarily objects.
    clean:
	@printf "  %-8s$(root)\n" "CLEAN"
	$(Q)$(RM) -f $(CLEAN_FILES)
	$(Q)$(foreach d, $(CLEAN_DIRS), $(RM) -rf $(d); )
else
    ### In APP manifest, remove the link to pre-build primary outputs.
    clean:
	@printf "  %-8s$(root)\n" "CLEAN"
	$(Q)$(RM) -f $(root)/lib
endif

.PHONY: distclean
distclean: clean

.PHONY: install
install: all
	$(Q)$(MKDIR) -p $(CUSTOM_LIB)
	$(Q)$(foreach f, $(TARGET_DLIBS), \
		printf "  %-8s$(CUSTOM_LIB)/$(notdir $(f))\n" "INSTALL"; \
		find $(CUSTOM_LIB) -type f \( -name $(basename $(basename $(basename $(notdir $(f))))).* -not -name $(notdir $(f)) \) -exec rm -rf {} \;; \
		$(INSTALL) -m 644 -t $(CUSTOM_LIB) $(f); \
		$(LN) -sfT $(notdir $(f)) $(CUSTOM_LIB)/$(basename $(basename $(notdir $(f)))); \
	)

.PHONY: install-cd
install-cd: all
	$(Q)$(MKDIR) -p $(CUSTOM_LIB)
	$(Q)$(foreach f, $(TARGET_CD_DLIBS), \
		printf "  %-8s$(CUSTOM_LIB)/$(notdir $(f))\n" "INSTALL"; \
		find $(CUSTOM_LIB) -type f \( -name $(basename $(basename $(basename $(notdir $(f))))).* -not -name $(notdir $(f)) \) -exec rm -rf {} \;; \
		$(INSTALL) -m 644 -t $(CUSTOM_LIB) $(f); \
		$(LN) -sfT $(notdir $(f)) $(CUSTOM_LIB)/$(basename $(basename $(notdir $(f)))); \
	)

.PHONY: uninstall
uninstall:
	$(Q)$(foreach f, $(TARGET_DLIBS), \
		printf "  %-8s$(CUSTOM_LIB)/$(notdir $(f))\n" "RM"; \
		$(RM) -f $(CUSTOM_LIB)/$(basename $(basename $(basename $(notdir $(f))))).*; \
	)
	$(Q)if [ -d $(CUSTOM_LIB) ]; then \
		$(RMDIR) --ignore-fail-on-non-empty $(CUSTOM_LIB); \
	fi

.PHONY: uninstall-cd
uninstall-cd:
	$(Q)$(foreach f, $(TARGET_CD_DLIBS), \
		printf "  %-8s$(CUSTOM_LIB)/$(notdir $(f))\n" "RM"; \
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
	@echo "    all                             Build primary outputs. (default)"
	@echo "    test                            Build test programs."
	@echo "    doc [SDK_VERSION=SDK_VERSION]   Build documents."
	@echo "    clean                           Clean all outputs."
	@echo "    distclean                       Clean all outputs and configurations."
	@echo "    install                         Install primary outputs"
	@echo "    uninstall                       Uninstall primary outputs"
	@echo "    help                            Show help messages."
	@echo ""

################################################################################
# General rules
################################################################################

%.o: %.c
	@printf "  %-8s$@\n" "CC"
	$(Q)$(CC) $(CFLAGS) -c $< -o $@ $(LDLIBS)

%.o: %.cc
	@printf "  %-8s$@\n" "CX"
	$(Q)$(CXX) $(CXXFLAGS) -c $< -o $@ $(LDLIBS)

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

check:
	@echo ALSA_INC: $(ALSA_INC)
	@echo ALSA_LIB: $(ALSA_LIB)
	@echo LDLIBS: $(LDLIBS)
	@echo CFLAGS: $(CFLAGS)
	@echo CXXFLAGS: $(CXXFLAGS)
