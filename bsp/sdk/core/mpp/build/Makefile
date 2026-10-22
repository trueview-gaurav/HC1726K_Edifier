# Copyright Augentix Inc. Proprietary and confidential.
# Unauthorized use or distribution is prohibited.
# Please contact customer.support@augentix.com for any inquiries.

################################################################################
# SDK related definitions
################################################################################

SDKSRC_DIR ?= $(realpath $(CURDIR)/../../../..)
include $(SDKSRC_DIR)/firmware/build/sdksrc.mk
include $(SDKSRC_DIR)/firmware/build/build_flags.mk
include $(SDKSRC_DIR)/firmware/build/build_utils/lib.mk
include $(ABIVER_MAKE)

ifneq ($(CONFIG_RELEASE),y)
include common.mk
endif

###############################################################################
# Chip type
###############################################################################
FPU_ENABLED :=
MPP_CHIP := $(call chip,$(CONFIG_CHIP))

################################################################################
# Build tools and commands
################################################################################

ifeq ($(CONFIG_KERNEL_V6_1),y)

ifeq ($(CONFIG_KERNEL_ARM64), y)
CROSS_COMPILE_LINUX := $(CROSS_COMPILE_5)
else
CROSS_COMPILE_LINUX := $(CROSS_COMPILE_2)
endif

else
CROSS_COMPILE_LINUX := $(CROSS_COMPILE)
endif

### First, specify the build tools.
ifeq ($(CONFIG_UCLIBC),y)
XTOOL_PATH := $(XTOOL_PATH_2)
CROSS_COMPILE := $(CROSS_COMPILE_2)
endif

CC := $(CROSS_COMPILE)gcc
CX := $(CROSS_COMPILE)g++
AR := $(CROSS_COMPILE)ar
RM := rm
LN := ln
MKDIR := mkdir
RMDIR := rmdir
STRIP := $(CROSS_COMPILE)strip
INSTALL := install
INSTALL_DATA := $(INSTALL) -c -m 644
TAR := tar
NICE := nice

NICENESS := 19
TAR_CHECKPOINT := 8000
NICE_TAR := $(NICE) -n $(NICENESS) $(TAR) --checkpoint=.$(TAR_CHECKPOINT)


### Then, define global compilation and linking flags.

CFLAGS_ALL := ${CFLAGS} -mcpu=$(CONFIG_TARGET_CPU) -fPIC -fno-omit-frame-pointer -g -MMD -Wall -D_GNU_SOURCE

ifeq ($(CONFIG_UCLIBC),y)
CFLAGS_ALL += -Os -DUCLIBC_SPECIFIC
else
CFLAGS_ALL += -O2
endif

### Check floating point support
ifeq ($(CROSS_COMPILE),arm-linux-gnueabihf-)
DEFINE_ALL += FPU_ENABLED
CFLAGS_ALL += -mfpu=neon-vfpv4 -flax-vector-conversions
endif

### Disable -Werror for uClibc toolchain
GCCVERSION := $(shell expr ` $(CROSS_COMPILE)gcc -dumpversion`)
ifeq (,$(findstring 10.3,$(GCCVERSION)))
CFLAGS_ALL += -Werror
else
ifeq ($(CROSS_COMPILE),arm-augentix-linux-uclibcgnueabihf-)
CFLAGS_ALL += -Werror
DEFINE_ALL += FPU_ENABLED
CFLAGS_ALL += -mfpu=neon-vfpv4
endif
CFLAGS_ALL += -flax-vector-conversions
endif

### If app link with -Wl,--gc-sections, then it will not link unsed function and data
CFLAGS_ALL += -ffunction-sections -fdata-sections
LFLAGS_ALL :=
RELRO_FLAGS :=
FORTIFY_FLAGS :=
NX_FLAGS :=

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

COMPILE = $(addprefix -D,$(DEFINE_ALL)) $(addprefix -D,$(DEFINE_LOCAL)) $(CFLAGS_ALL) $(CFLAGS_LOCAL) -o $@ -c $<
LINK = -o $@ $^ $(LFLAGS_ALL) $(LFLAGS_LOCAL)
ARCHIVE_STATIC = $(AR) rcsD $@ $^
ARCHIVE_SHARED = -shared $(RELRO_FLAGS) $(NX_FLAGS) -Wl,--build-id -Wl,--soname,$(basename $(basename $(notdir $@))) -o $@ \
                 -Wl,--whole-archive $^ -Wl,--no-whole-archive


################################################################################
# Prebuilt core lib rules
# ##############################################################################

LOCAL_TARBALL_FILENAME := core_lib.tgz
LOCAL_TARBALL := $(addprefix $(MPP_PATH)/, $(LOCAL_TARBALL_FILENAME))
REMOTE_TARBALL_PATH := /tools/core_lib/mpp

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
	@printf "MPP_PATH=$(MPP_PATH)"
	@printf "Packing pre-built core lib" && \
	tar -zcvf $(LOCAL_TARBALL) ../ko.* ../lib.* ../include ../build && \
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

.PHONY: all
all: primary

### Second, define variables for collecting outputs and temporarily objects.

TARGET_BINS   :=
TARGET_DOCS   :=
TARGET_MODS   :=
TARGET_SLIBS  :=
TARGET_DLIBS  :=
TARGET_TESTS  :=
CLEAN_FILES   :=
CLEAN_DIRS    :=
CLEAN_TARGETS :=

### Then, collect the knowledge about how to build all outputs.

root := $(MPP_PATH)
dir := $(root)/build

### Define helper variables if need.

VERSION_SCRIPT_PATH := $(root)/mpi/src/libmpp.map
CPVS_SRC := $(CPVS_PATH)/$(MPP_CHIP)/src

ifneq ($(CONFIG_RELEASE),y)
    ### In SDK manifest, traverse directory tree to include Rules.mk files.
    subdir := $(root)
    include $(subdir)/Rules.mk

    subdir := $(root)/dip
    include $(subdir)/Rules.mk

    subdir := $(root)/iva
    include $(subdir)/Rules.mk

    subdir := $(root)/libdebug
    include $(subdir)/Rules.mk

    subdir := $(root)/mpi
    include $(subdir)/Rules.mk

    subdir := $(root)/sensor
    include $(subdir)/Rules.mk

    subdir := $(root)/utrc
    include $(subdir)/Rules.mk

    subdir := $(root)/vb
    include $(subdir)/Rules.mk

    subdir := $(root)/vpc
    include $(subdir)/Rules.mk

    subdir := $(root)/enc
    include $(subdir)/Rules.mk

    subdir := $(root)/is
    include $(subdir)/Rules.mk

    subdir := $(root)/isp
    include $(subdir)/Rules.mk

    subdir := $(root)/osd
    include $(subdir)/Rules.mk

    subdir := $(root)/senif
    include $(subdir)/Rules.mk

ifneq ($(CONFIG_KERNEL_V6_1),y)
ifeq ($(CONFIG_HC1703_1723_1753_1783S),y)
    subdir := $(root)/disp
    include $(subdir)/Rules.mk
endif
endif #ifneq ($(CONFIG_KERNEL_V6_1),y)

    subdir := $(root)/sr
    include $(subdir)/Rules.mk

    subdir := $(root)/rc
    include $(subdir)/Rules.mk

    subdir := $(root)/audio
    include $(subdir)/Rules.mk

    CLEAN_FILES += $(root)/ko/mpp.ko

ifneq ($(CONFIG_KERNEL_V6_1),y)
ifeq ($(CONFIG_HC1703_1723_1753_1783S),y)
    CLEAN_FILES += $(root)/ko/disp.ko
endif
endif #ifneq ($(CONFIG_KERNEL_V6_1),y)

CLEAN_FILES += $(root)/ko/audio_pcm.ko

ifeq ($(CONFIG_HC1703_1723_1753_1783S),y)
CLEAN_FILES += $(root)/ko/adc.ko
endif


    CLEAN_DIRS  += $(root)/ko

endif # ifneq ($(CONFIG_RELEASE),y)

TARGET_MODS += $(root)/ko/mpp.ko

ifneq ($(CONFIG_KERNEL_V6_1),y)
ifeq ($(CONFIG_HC1703_1723_1753_1783S),y)
TARGET_MODS += $(root)/ko/disp.ko
endif
endif #ifneq ($(CONFIG_KERNEL_V6_1),y)

TARGET_MODS += $(root)/ko/audio_pcm.ko

ifeq ($(CONFIG_HC1703_1723_1753_1783S),y)
TARGET_MODS += $(root)/ko/adc.ko
endif

### Finally, define essential build targets.

################################################################################
# Dependency
################################################################################

# ------------------ Build and install custom sensor library -------------------

.PHONY: custom-sensor custom-sensor-clean custom-sensor-install custom-sensor-uninstall

custom-sensor:
	$(Q)$(MAKE) -C $(SENSOR_PATH)

custom-sensor-clean:
	$(Q)$(MAKE) -C $(SENSOR_PATH) clean

custom-sensor-install:
	$(Q)$(MAKE) -C $(SENSOR_PATH) install

custom-sensor-uninstall:
	$(Q)$(MAKE) -C $(SENSOR_PATH) uninstall

# --------------- Create symbolic links based on the chip model ----------------

.PHONY: ln-s-include ln-s-include-clean

ln-s-include:
	$(Q)$(LN) -sfT $(MPP_PATH)/dip/$(CHIP_DIR)/include $(MPP_PATH)/dip/include
	$(Q)$(LN) -sfT $(MPP_PATH)/enc/$(CHIP_DIR)/include $(MPP_PATH)/enc/include
	$(Q)$(LN) -sfT $(MPP_PATH)/is/$(CHIP_DIR)/include $(MPP_PATH)/is/include
	$(Q)$(LN) -sfT $(MPP_PATH)/isp/$(CHIP_DIR)/include $(MPP_PATH)/isp/include
	$(Q)$(LN) -sfT $(MPP_PATH)/osd/$(CHIP_DIR)/include $(MPP_PATH)/osd/include
	$(Q)$(LN) -sfT $(MPP_PATH)/senif/$(CHIP_DIR)/include $(MPP_PATH)/senif/include
	$(Q)$(LN) -sfT $(MPP_PATH)/rc/$(CHIP_DIR)/include $(MPP_PATH)/rc/include
ln-s-include-clean:
	$(Q)$(RM) -f $(MPP_PATH)/dip/include
	$(Q)$(RM) -f $(MPP_PATH)/enc/include
	$(Q)$(RM) -f $(MPP_PATH)/is/include
	$(Q)$(RM) -f $(MPP_PATH)/isp/include
	$(Q)$(RM) -f $(MPP_PATH)/osd/include
	$(Q)$(RM) -f $(MPP_PATH)/senif/include
	$(Q)$(RM) -f $(MPP_PATH)/rc/include

# ------------------------ Build and install libraries -------------------------

TARGET_SLIB_$(dir) := $(root)/lib/libmpp.a
TARGET_DLIB_$(dir) := $(root)/lib/libmpp.so.$(REAL_SUFFIX)

ifneq ($(CONFIG_RELEASE),y)

    $(TARGET_SLIB_$(dir)) $(TARGET_DLIB_$(dir)): $(OBJS_$(root)/dip) \
                                                 $(OBJS_$(root)/enc) \
                                                 $(OBJS_$(root)/is) \
                                                 $(OBJS_$(root)/isp) \
                                                 $(OBJS_$(root)/iva) \
                                                 $(OBJS_$(root)/libdebug) \
                                                 $(OBJS_$(root)/mpi) \
                                                 $(OBJS_$(root)/osd) \
                                                 $(OBJS_$(root)/senif) \
                                                 $(OBJS_$(root)/disp) \
                                                 $(OBJS_$(root)/sensor) \
                                                 $(OBJS_$(root)/sr) \
                                                 $(OBJS_$(root)/utrc) \
                                                 $(OBJS_$(root)/vb) \
                                                 $(OBJS_$(root)/vpc/otp) \
                                                 $(OBJS_$(root)/vpc/rs) \
                                                 $(OBJS_$(root)/vpc/utils) \
                                                 $(OBJS_$(root)/vpc/vplat) \
                                                 $(OBJS_$(root)/audio) \
                                                 $(OBJS_$(root)/rc)

    $(TARGET_SLIB_$(dir)):
	@printf "  %-8s$@\n" "AR"
	$(Q)$(MKDIR) -p $(@D)
	$(Q)$(ARCHIVE_STATIC)

    $(TARGET_DLIB_$(dir)):
	@printf "  %-8s$@\n" "CC"
	$(Q)$(MKDIR) -p $(@D)
	$(Q)$(CC) $(ARCHIVE_SHARED) -Wl,--version-script=$(VERSION_SCRIPT_PATH)
	$(Q)$(LN) -sfT $(notdir $@) $(basename $(basename $(basename $@)))

    CLEAN_FILES  += $(TARGET_SLIB_$(dir)) $(TARGET_DLIB_$(dir)) \
                    $(basename $(basename $(basename $(TARGET_DLIB_$(dir)))))
    CLEAN_DIRS   += $(dir $(TARGET_SLIB_$(dir))) $(dir $(TARGET_DLIB_$(dir)))

endif # ifneq ($(CONFIG_RELEASE),y)

TARGET_SLIBS += $(TARGET_SLIB_$(dir))
TARGET_DLIBS += $(TARGET_DLIB_$(dir))

################################################################################
# Targets (Must be placed after "Subdirectories" section)
################################################################################

.PHONY:	primary
ifneq ($(CONFIG_RELEASE),y)
    ### In SDK manifest, build primary outputs if necessary.
    primary: ln-s-include
	@echo mpp CROSS_COMPILE: $(CROSS_COMPILE)
	$(Q)$(MAKE) -s check
	$(Q)$(MAKE) $(TARGET_SLIBS) $(TARGET_DLIBS)
	$(MAKE) $(TARGET_MODS) CROSS_COMPILE=$(CROSS_COMPILE_LINUX)
else
    ### In APP manifest, create link to pre-built primary outputs.
    primary: install-corelib
	@echo - Override MPP configuration with $(MPP_CHIP)
	@echo mpp CROSS_COMPILE: $(CROSS_COMPILE)
ifeq ($(CONFIG_UCLIBC),y)
ifeq ($(CONFIG_KERNEL_V6_1),y)
	$(Q)$(LN) -sfT ko.$(MPP_CHIP).linux6.1.minimal $(root)/ko
	$(Q)$(LN) -sfT lib.$(MPP_CHIP).uclibc $(root)/lib
else
	$(Q)$(LN) -sfT ko.$(MPP_CHIP).minimal $(root)/ko
	$(Q)$(LN) -sfT lib.$(MPP_CHIP).uclibc $(root)/lib
endif
else
ifeq ($(CONFIG_KERNEL_V6_1),y)
	$(Q)$(LN) -sfT ko.$(MPP_CHIP).linux6.1 $(root)/ko
else
	$(Q)$(LN) -sfT ko.$(MPP_CHIP) $(root)/ko
endif
	$(Q)$(LN) -sfT lib.$(MPP_CHIP) $(root)/lib
endif
endif

.PHONY: test
ifneq ($(CONFIG_RELEASE),y)
    ### In SDK manifest, build the test outputs if necessary.
    test: primary $(TARGET_TESTS)
else
    ### In APP manifest, do nothing.
    test: ;
endif

.PHONY: doc
ifneq ($(CONFIG_RELEASE),y)
    ### In SDK manifest, build the doc outputs if necessary.
    doc: $(TARGET_DOCS)
else
    ### In APP manifest, do nothing.
    doc: ;
endif

.PHONY: clean
ifneq ($(CONFIG_RELEASE),y)
    ### In SDK manifest, remove primary outputs and temporarily objects.
    clean: $(CLEAN_TARGETS) ln-s-include-clean
	@printf "  %-8s$(root)\n" "CLEAN"
	$(Q)$(RM) -f $(CLEAN_FILES)
	$(Q)$(foreach d, $(CLEAN_DIRS), $(RM) -rf $(d); )
else
    ### In APP manifest, remove the link to pre-build primary outputs.
    clean:
	@printf "  %-8s$(root)\n" "CLEAN"
	$(Q)$(RM) -f $(root)/lib
	$(Q)$(RM) -f $(root)/ko
	$(Q)$(RM) -f $(root)/$(LOCAL_TARBALL_FILENAME)
endif

.PHONY: distclean
distclean: clean

.PHONY: install
install: primary
	$(Q)$(MKDIR) -p $(CUSTOM_LIB)
	$(Q)$(foreach f, $(TARGET_DLIBS), \
		printf "  %-8s$(CUSTOM_LIB)/$(notdir $(f))\n" "INSTALL"; \
		find $(CUSTOM_LIB) -type f \( -name $(basename $(basename $(basename $(notdir $(f))))).* -not -name $(notdir $(f)) \) -exec rm -rf {} \;; \
		$(INSTALL) -m 644 -t $(CUSTOM_LIB) $(f); \
		$(LN) -sfT $(notdir $(f)) $(CUSTOM_LIB)/$(basename $(basename $(notdir $(f)))); \
	)
	$(Q)$(foreach f, $(TARGET_MODS), \
		printf "  %-8s$(CUSTOM_LIB)/$(notdir $(f))\n" "INSTALL"; \
		$(INSTALL) -m 644 -t $(CUSTOM_LIB) $(f); \
	)
ifeq ($(filter y, $(CONFIG_SAPPORO) $(CONFIG_KAMO) $(CONFIG_OSAKA)), y)
ifeq ($(CONFIG_FPGA),y)
	$(INSTALL) -m 755 -t $(CUSTOM_LIB) $(root)/senif/$(CHIP_DIR)/ksrc/sapporo_tc_config.sh;
endif
endif

.PHONY: uninstall
uninstall:
	$(Q)$(foreach f, $(TARGET_DLIBS), \
		printf "  %-8s$(CUSTOM_LIB)/$(notdir $(f))\n" "RM"; \
		$(RM) -f $(CUSTOM_LIB)/$(basename $(basename $(basename $(notdir $(f))))).*; \
	)
	$(Q)$(foreach f, $(TARGET_MODS), \
		printf "  %-8s$(CUSTOM_LIB)/$(notdir $(f))\n" "RM"; \
		$(RM) -f $(CUSTOM_LIB)/$(notdir $(f)); \
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
	@echo "    test        Build test programs."
	@echo "    doc         Build documents."
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
ifeq ($(CONFIG_TARGET_CPU),)
	$(error Unknown parameter CONFIG_TARGET_CPU, please try setting product configuration)
endif

################################################################################
# General rules
################################################################################

%.o: %.c
	@printf "  %-8s$@\n" "CC"
	$(Q)$(CC) -std=gnu99 $(COMPILE)
%.o: %.cpp
	@printf "  %-8s$@\n" "CX"
	$(Q)$(CX) -std=c++11 $(COMPILE)

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
