# Copyright Augentix Inc. Proprietary and confidential.
# Unauthorized use or distribution is prohibited.
# Please contact customer.support@augentix.com for any inquiries.

# SDK related definitions
################################################################################

SDKSRC_DIR ?= $(realpath $(CURDIR)/../../../../)
include $(SDKSRC_DIR)/firmware/build/sdksrc.mk
include $(SDKSRC_DIR)/firmware/build/build_utils/lib.mk
include $(SDKSRC_DIR)/firmware/build/build_flags.mk
include $(SAMPLE_DEMO_PATH)/internal.mk
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
CXX := $(CROSS_COMPILE)g++
RM := rm
LN := ln
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
CFLAGS_ALL := -MMD -ffunction-sections -fdata-sections
LFLAGS_ALL :=
RELRO_FLAGS :=
NX_FLAGS :=

$(info CROSS_COMPILE is [$(CROSS_COMPILE)])
ifeq ($(strip $(CROSS_COMPILE)),arm-linux-gnueabihf-)
$(info Defining USE_NEON)
CFLAGS_ALL += -DUSE_NEON
else ifeq ($(strip $(CROSS_COMPILE)),arm-augentix-linux-uclibcgnueabihf-) 
$(info Defining USE_NEON)
CFLAGS_ALL += -DUSE_NEON
else
$(info Not defining USE_NEON)
endif

### Enable STQC option for kernel v6.1
ifeq ($(CONFIG_KERNEL_V6_1),y)
CANARY_FLAGS := -fstack-protector-strong
CFLAGS_ALL  += $(CANARY_FLAGS)
RELRO_FLAGS += -Wl,-z,relro,-z,now
FORTIFY_FLAGS += -D_FORTIFY_SOURCE=2 -O2 -Wno-unused-result
CFLAGS_ALL   += $(FORTIFY_FLAGS)
NX_FLAGS +=  -Wl,-z,noexecstack -Wl,-z,noexecheap
endif

### Finally, define complete commands for all actions. 

COMPILE = $(CFLAGS_ALL) $(CFLAGS_LOCAL) -o $@ -c $<
LINK = $(CC) -o $@ -Wl,--start-group $^ -Wl,--end-group $(LFLAGS_ALL) $(LFLAGS_LOCAL)
ARCHIVE_STATIC = $(AR) rcsD $@ $^
ARCHIVE_SHARED = $(CC) -shared $(RELRO_FLAGS) $(NX_FLAGS) -Wl,--build-id -Wl,--soname,$(basename $(basename $(notdir $@))) -o $@ \
		-Wl,--whole-archive $^ -Wl,--no-whole-archive


################################################################################
# Prebuilt core lib rules
# ##############################################################################

LOCAL_TARBALL_FILENAME := core_lib.tgz
LOCAL_TARBALL := $(addprefix $(FEATURE_ML_PATH)/, $(LOCAL_TARBALL_FILENAME))
REMOTE_TARBALL_PATH := /tools/core_lib/ml

IS_INSIDE_WORK_TREE = $(shell git rev-parse --is-inside-work-tree > /dev/null 2>&1; echo $$?)
GIT_STATUS = $(shell git status --porcelain 2> /dev/null)
COMMIT_HASH = $(shell git rev-parse HEAD 2> /dev/null | cut -c1-8)

LOCAL_TARBALL_STAT = $(shell stat -c %Y $(LOCAL_TARBALL) 2>/dev/null)
LOCAL_TARBALL_MTIME = $(shell date '+%Y%m%d_%H%M%S' --date=@$(LOCAL_TARBALL_STAT) 2>/dev/null)
REMOTE_TARBALL_PATTERN = $(COMMIT_HASH)_????????_??????.tgz
REMOTE_TARBALL_FILENAME = $(COMMIT_HASH)_$(LOCAL_TARBALL_MTIME).tgz
REMOTE_TARBALL = $(shell ls $(REMOTE_TARBALL_PATH)/$(REMOTE_TARBALL_PATTERN) 2>/dev/null | sort | tail -1)
REMOTE_TARBALL_TARGET = $(addprefix $(REMOTE_TARBALL_PATH)/, $(REMOTE_TARBALL_FILENAME))

# $(pack_local_tarball)
define pack_local_tarball
	@printf "FEATURE_ML_PATH=$(FEATURE_ML_PATH)\n"
	@printf "$(LOCAL_TARBALL)\n"
	@printf "Packing pre-built core lib\n" && \
	tar -zcvf $(LOCAL_TARBALL) ../lib ../include ../build && \
	echo
endef

# $(unpack_local_tarball)
define unpack_local_tarball
	@printf "Unpacking pre-built core lib" && \
	$(NICE_TAR) -xf $(LOCAL_TARBALL) -C $(MPP_PATH) && \
	echo
endef


################################################################################
# Build rules
################################################################################

### First, define default build target.

all: primary

### Second, define variables for collecting outputs and temporarily objects.

LIB_NAME = ml
LIB_NAME_RTOS = ml_rtos
LIB_NAME_EARLY = ml_early

TARGET_SLIBS :=
TARGET_SLIBS_RTOS :=
TARGET_SLIBS_EARLY :=
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
    TARGET_SLIBS_RTOS += $(root)/lib/lib$(LIB_NAME_RTOS).a
    TARFET_SLIBS_EARLY += $(root)/lib/lib$(LIB_NAME_EARLY).a
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
    primary: $(TARGET_SLIBS) $(TARGET_DLIBS) $(TARGET_SLIBS_RTOS) $(TARGET_SLIBS_EARLY)
	@echo feature/ml CROSS_COMPILE: $(CROSS_COMPILE)
else
    ### In APP manifest, create link to pre-built primary outputs.
    primary: install-corelib
	@echo feature/ml CROSS_COMPILE: $(CROSS_COMPILE)
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
	$(Q)$(RM) -f $(root)/$(LOCAL_TARBALL_FILENAME)
endif

.PHONY: distclean
distclean: clean

.PHONY: install
install: all
	@printf "Skip install in this phase.\n"

.PHONY: uninstall
uninstall:
	@printf "Skip uninstall in this phase.\n"

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

.PHONY: check
check:
	@echo TARGET_SLIBS $(TARGET_SLIBS)
	@echo TARGET_SLIBS_RTOS $(TARGET_SLIBS_RTOS)
	@echo TARGET_SLIBS_EARLY $(TARGET_SLIBS_EARLY)
	@echo TARGET_DLIBS $(TARGET_DLIBS)
	@echo CLEAN_DIRS $(CLEAN_DIRS)
	@echo CLEAN_FILES $(CLEAN_FILES)
	@echo $(INCS_$(dir))

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

################################################################################
# Pre-built core lib
################################################################################

define install_prebuilt_corelib
	@if [ -e "$(REMOTE_TARBALL)" ]; \
	then \
		printf "Installing pre-built core lib" && \
		$(NICE_TAR) -xf $(REMOTE_TARBALL) -C $(MPP_PATH) && \
		echo The pre-built core lib has been installed successfully.; \
	else \
		echo No need to install pre-built core lib. Skipped installation.; \
	fi
endef

.PHONY: pack
pack:
	$(pack_local_tarball)

.PHONY: push
push: $(LOCAL_TARBALL)
	@echo Uploading pre-built core lib...
	$(INSTALL_DATA) $< $(REMOTE_TARBALL_TARGET)

.PHONY: install-corelib
install-corelib:
	$(install_prebuilt_corelib)
