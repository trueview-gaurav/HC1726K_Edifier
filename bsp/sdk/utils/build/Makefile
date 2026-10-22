################################################################################
# SDK related definitions
################################################################################

SDKSRC_DIR ?= $(realpath $(CURDIR)/../../..)
include $(SDKSRC_DIR)/firmware/build/sdksrc.mk
include $(SDKSRC_DIR)/firmware/build/build_utils/lib.mk

###############################################################################
# Chip type
###############################################################################

UTILS_CHIP := $(call chip,$(CONFIG_CHIP))

################################################################################
# Build tools and commands
################################################################################

### First, specify the build tools.

CC := gcc
STRIP := strip

LN := ln
RM := rm
ECHO := echo
MKDIR := mkdir
RMDIR := rmdir
CHMOD := chmod
INSTALL := install -c
INSTALL_PROGRAM := $(INSTALL)
INSTALL_DATA := $(INSTALL) -m 644

### Then, define global compilation and linking flags.

HOST_CFLAGS_ALL   := -g -Wall -Wextra -Werror -MMD -O2 -std=gnu99 -fPIC -Wno-address-of-packed-member
HOST_LFLAGS_ALL   :=

TARGET_DEFINE_ALL := HC17X3_SPECIFIC
TARGET_CFLAGS_ALL := -g -mcpu=$(CONFIG_TARGET_CPU) \
                     -fstrict-volatile-bitfields -mno-unaligned-access \
                     -ffreestanding -ffunction-sections -fdata-sections -fno-short-enums \
                     -MMD -Os -std=gnu99 -fPIC -Wall -Wextra -Werror
TARGET_LFLAGS_ALL :=

### Enable STQC option for kernel v6.1
ifeq ($(CONFIG_KERNEL_V6_1),y)
CANARY_FLAGS := -fstack-protector-strong
RELRO_FLAGS += -Wl,-z,relro,-z,now
FORTIFY_FLAGS := -D_FORTIFY_SOURCE=2 -O2 -Wno-unused-result
NX_FLAGS := -Wl,-z,noexecstack -Wl,-z,noexecheap

HOST_CFLAGS_ALL   += $(CANARY_FLAGS) $(FORTIFY_FLAGS)
TARGET_CFLAGS_ALL += $(CANARY_FLAGS) $(FORTIFY_FLAGS)
HOST_LFLAGS_ALL   += $(RELRO_FLAGS) $(NX_FLAGS)
TARGET_LFLAGS_ALL += $(RELRO_FLAGS) $(NX_FLAGS)
endif

### Finally, define complete commands for all actions.

ifeq ($(CONFIG_UCLIBC),y)
XTOOL_PATH := $(XTOOL_PATH_2)
CROSS_COMPILE := $(CROSS_COMPILE_2)
endif

HOST_COMPILE   = $(CC) $(HOST_CFLAGS_ALL) $(HOST_CFLAGS_LOCAL) -o $@ -c $<
HOST_LINK      = $(CC) $(HOST_LFLAGS_ALL) $(HOST_LFLAGS_LOCAL) -o $@ $^

TARGET_COMPILE = $(CROSS_COMPILE)$(CC) $(TARGET_CFLAGS_ALL) $(TARGET_CFLAGS_LOCAL) $(addprefix -D,$(TARGET_DEFINE_ALL)) -o $@ -c $<
TARGET_LINK    = $(CROSS_COMPILE)$(CC) -o $@ $^ $(TARGET_LFLAGS_ALL) $(TARGET_LFLAGS_LOCAL)

################################################################################
# Build rules
################################################################################

### First, define default build targets.

.PHONY: all
all: primary

### Second, define variables for collecting outputs and temporarily objects.

TARGET_HOST_BINS         :=
TARGET_TARGET_BINS       :=
TARGET_SCRIPTS           :=

CLEAN_HOST_FILES         :=
CLEAN_HOST_DIRS          :=
CLEAN_TARGET_FILES       :=
CLEAN_TARGET_DIRS        :=

### Then, collect the knowledge about how to build all outputs.

root := $(UTILS_PATH)
dir  := $(root)/build

ifneq ($(CONFIG_RELEASE),y)
    ### In SDK manifest, traverse directory tree to include Rules.mk files.
    subdir := $(root)/host/gen_br
    include $(subdir)/Rules.mk

ifeq ($(GEN_BR_ONLY),)
    subdir := $(root)/host/bin2csr
    include $(subdir)/Rules.mk

    subdir := $(root)/target/acsr2
    include $(subdir)/Rules.mk

    subdir := $(root)/target/adc_read
    include $(subdir)/Rules.mk

    subdir := $(root)/target/ddr2pgm
    include $(subdir)/Rules.mk

    subdir := $(root)/target/dip_dump
    include $(subdir)/Rules.mk

    subdir := $(root)/target/dump
    include $(subdir)/Rules.mk

    subdir := $(root)/target/fill
    include $(subdir)/Rules.mk

    subdir := $(root)/target/get_clks
    include $(subdir)/Rules.mk

    subdir := $(root)/target/i2crw
    include $(subdir)/Rules.mk

    subdir := $(root)/target/nrw2yuv
    include $(subdir)/Rules.mk

    subdir := $(root)/target/scw2yuv
    include $(subdir)/Rules.mk
endif

else
    TARGET_HOST_BINS   += $(root)/host/bin/gen_br

    TARGET_TARGET_BINS += $(root)/target/bin/adc_read \
                          $(root)/target/bin/csr \
                          $(root)/target/bin/ddr2pgm \
                          $(root)/target/bin/dump \
                          $(root)/target/bin/dump_csr \
                          $(root)/target/bin/dip_dump \
                          $(root)/target/bin/fill \
                          $(root)/target/bin/get_clks \
                          $(root)/target/bin/i2crw \
                          $(root)/target/bin/nrw2yuv \
                          $(root)/target/bin/scw2yuv \
                          $(root)/target/bin/show_clks

endif # ifneq ($(CONFIG_RELEASE),y)

### Finally, define essential build targets.

.PHONY: primary
primary: host target

.PHONY: host
ifneq ($(CONFIG_RELEASE),y)
    ### In SDK manifest, build host outputs if necessary.
    host:
	$(Q)$(MAKE) --no-print-directory check
	$(Q)$(MAKE) $(TARGET_HOST_BINS)
else
    ### In APP manifest, create link to pre-built primary outputs.
    host:
	@echo - Override host utils configuration with $(UTILS_CHIP)
	$(Q)$(LN) -sfT bin.$(UTILS_CHIP) $(root)/host/bin
endif

.PHONY: target
ifneq ($(CONFIG_RELEASE), y)
    ### In SDK manifest, build target outputs if necessary.
    target:
	@echo utils/target CROSS_COMPILE: $(CROSS_COMPILE)
	$(Q)$(MAKE) --no-print-directory check
	$(Q)$(MAKE) $(TARGET_TARGET_BINS)
else
    ### In APP manifest, create link to pre-built primary outputs.
    target:
	@echo - Override target utils configuration with $(UTILS_CHIP)
	@echo utils/target CROSS_COMPILE: $(CROSS_COMPILE)
ifeq ($(CONFIG_UCLIBC),y)
	$(Q)$(LN) -sfT bin.$(UTILS_CHIP).uclibc $(root)/target/bin
else
	$(Q)$(LN) -sfT bin.$(UTILS_CHIP) $(root)/target/bin
endif
endif

.PHONY: clean
clean: host-clean target-clean

.PHONY: host-clean
ifneq ($(CONFIG_RELEASE),y)
    ### In SDK manifest, remove primary outputs and temporarily objects
    host-clean:
	@printf "  %-8s $(realpath $(root)/host)\n" "CLEAN"
	$(Q)$(RM) -f $(CLEAN_HOST_FILES)
	$(Q)$(foreach d, $(CLEAN_HOST_DIRS), $(RM) -rf $(d); )
else
    ### In APP manifest, do not remove the prebuilt libraries
    host-clean:
		$(Q)$(RM) -f $(root)/host/bin
endif

.PHONY: target-clean
ifneq ($(CONFIG_RELEASE),y)
    ### In SDK manifest, remove primary outputs and temporarily objects
    target-clean:
	@printf "  %-8s $(realpath $(root)/target)\n" "CLEAN"
	$(Q)$(RM) -f $(CLEAN_TARGET_FILES)
	$(Q)$(foreach d, $(CLEAN_TARGET_DIRS), $(RM) -rf $(d); )
else
    ### In APP manifest, do not remove the prebuilt libraries
    target-clean:
		$(Q)$(RM) -f $(root)/target/bin
endif

.PHONY: distclean
distclean: clean

.PHONY: install
install: host-install target-install

# Do not install host utils to $(SYSTEM_BIN)
.PHONY: host-install
host-install: $(TARGET_HOST_BINS)

.PHONY: target-install
target-install: $(TARGET_TARGET_BINS) $(TARGET_SCRIPTS)
	$(Q)$(MKDIR) -p $(SYSTEM_BIN)
	$(Q)$(foreach f, $(^), \
		printf "  %-8s $(SYSTEM_BIN)/$(notdir $(f))\n" "INSTALL"; \
		$(INSTALL_PROGRAM) -m 755 -t $(SYSTEM_BIN) $(f); \
	)

.PHONY: uninstall
uninstall: host-uninstall target-uninstall

.PHONY: host-uninstall
host-uninstall: ;

.PHONY: target-uninstall
target-uninstall: $(TARGET_UNINSTALL_TARGETS)
	$(Q)$(foreach f, $(TARGET_TARGET_BINS), \
		printf "  %-8s $(SYSTEM_BIN)/$(notdir $(f))\n" "RM"; \
		$(RM) -f $(SYSTEM_BIN)/$(notdir $(f)); \
	)
	$(Q)if [ -d $(SYSTEM_BIN) ]; then \
		$(RMDIR) --ignore-fail-on-non-empty $(SYSTEM_BIN); \
	fi

.PHONY: host-update
host-update: host-clean host host-install

.PHONY: target-update
target-update: target-clean target target-install

.PHONY: check
check:
ifeq ($(CONFIG_TARGET_CPU),)
	$(error Unknown parameter CONFIG_TARGET_CPU, please try setting product configuration)
endif
ifeq ($(CONFIG_CHIP),)
	$(error Unknown parameter CONFIG_CHIP, please try setting product configuration)
endif
	@true

.PHONY: help
help:
	@echo ""
	@echo "  Syntax:"
	@echo "    make [options] <target>"
	@echo ""
	@echo "  Options:"
	@echo "    V=0                 Hide command lines. (default)"
	@echo "    V=1                 Show command lines."
	@echo ""
	@echo "  Targets:"
	@echo "    all                 Build primary outputs. (default)"
	@echo "    host                Build host outputs."
	@echo "    target              Build target outputs."
	@echo ""
	@echo "    clean               Clean all outputs."
	@echo "    distclean           Clean all outputs and configurations."
	@echo ""
	@echo "    install             Install primary outputs"
	@echo "    host-install        Install host outputs"
	@echo "    target-install      Install target outputs"
	@echo ""
	@echo "    uninstall           Uninstall primary outputs"
	@echo "    host-uninstall      Uninstall host outputs"
	@echo "    target-uninstall    Uninstall target outputs"
	@echo ""
	@echo "    help                Show help messages."
	@echo "    check               Check the prerequest configuration / environment variables"
	@echo ""

################################################################################
# General directory independent targets
################################################################################

$(UTILS_PATH)/host/%.o: $(UTILS_PATH)/host/%.c
	@printf "  %-8s$@\n" "HOSTCC"
	$(Q)$(HOST_COMPILE)

$(UTILS_PATH)/target/%.o: $(UTILS_PATH)/target/%.c
	@printf "  %-8s$@\n" "CC"
	$(Q)$(TARGET_COMPILE)

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
