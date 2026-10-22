# Copyright Augentix Inc. Proprietary and confidential.
# Unauthorized use or distribution is prohibited.
# Please contact customer.support@augentix.com for any inquiries.

################################################################################
# SDK related definitions
################################################################################

SDKSRC_DIR ?= $(realpath $(CURDIR)/../../../..)
include $(SDKSRC_DIR)/firmware/build/sdksrc.mk
include $(SDKSRC_DIR)/firmware/build/build_utils/lib.mk
include $(ABIVER_MAKE)

################################################################################
# Build tools and commands
################################################################################

### First, specify the build tools.

CC := $(CROSS_COMPILE)gcc
AS := $(CROSS_COMPILE)as
AR := $(CROSS_COMPILE)ar
NM := $(CROSS_COMPILE)nm
LD := $(CROSS_COMPILE)ld
OBJDUMP := $(CROSS_COMPILE)objdump
OBJCOPY := $(CROSS_COMPILE)objcopy
RANLIB := $(CROSS_COMPILE)ranlib
STRIP := $(CROSS_COMPILE)strip
RM := rm
LN := ln
MKDIR := mkdir
RMDIR := rmdir
CHMOD := chmod
INSTALL := install
GCCVERSION := $(shell expr ` $(CC) -dumpversion`)
CPVS_STARTUP_ARCH ?= CA55

### Then, define global compilation and linking flags.
# export CPVS_STARTUP_ARC for each Rule.mk using
export CPVS_STARTUP_ARCH

CPVS_CHIP  := $(call chip,$(CONFIG_CHIP))

AFLAGS_ALL := -g
CFLAGS_ALL := -g \
              -fstrict-volatile-bitfields \
              -ffreestanding -ffunction-sections -fdata-sections -fno-short-enums \
              -MMD -O2 -std=gnu99 -fPIC -I$(GEN_INC)

ifeq ($(CROSS_COMPILE), aarch64-none-linux-gnu-)
AFLAGS_ALL += -mcpu=cortex-a55 -DCPVS_ARCH_CA55
CFLAGS_ALL += -mstrict-align -mcpu=cortex-a55 -DCPVS_ARCH_CA55 -fno-zero-initialized-in-bss
else ifeq ($(CROSS_COMPILE), arm-none-eabi-)
ifeq ($(CPVS_STARTUP_ARCH),CM0)
AFLAGS_ALL += -mcpu=cortex-m0 -DCPVS_ARCH_CM0
CFLAGS_ALL += -mcpu=cortex-m0 -mthumb -mfloat-abi=soft -DCPVS_ARCH_CM0
else
AFLAGS_ALL += -mcpu=cortex-m7 -DCPVS_ARCH_CM7
CFLAGS_ALL += -mcpu=cortex-m7 -mthumb -mfloat-abi=hard -mfpu=fpv5-sp-d16 -DCPVS_ARCH_CM7
endif
else
AFLAGS_ALL += -mcpu=cortex-a7
CFLAGS_ALL += -mno-unaligned-access -mcpu=cortex-a7
endif

CFLAGS_ALL += -DCPVS_STARTUP_ARCH_STR=\"$(CPVS_STARTUP_ARCH)\"

ifeq ($(GCCVERSION), 10.3.0)
CFLAGS_ALL += -mgeneral-regs-only
endif

ifeq ($(CROSS_COMPILE), arm-linux-gnueabi-)
	LFLAGS_ALL := --gc-sections -L/tools/arm/gcc-linaro-4.9.4-2017.01-x86_64_arm-linux-gnueabi/lib/gcc/arm-linux-gnueabi/4.9.4 -lgcc
else ifeq ($(CROSS_COMPILE), arm-linux-gnueabihf-)
	LFLAGS_ALL := --gc-sections -L/tools/arm/gcc-linaro-4.9-2016.02-x86_64_arm-linux-gnueabihf/lib/gcc/arm-linux-gnueabihf/4.9.4 -lgcc
else ifeq ($(CROSS_COMPILE), arm-none-linux-gnueabihf-)
	LFLAGS_ALL := --gc-sections -L/tools/arm/gcc-arm-10.3-2021.07-x86_64-arm-none-linux-gnueabihf/lib/gcc/arm-none-linux-gnueabihf/10.3.1 -lgcc
else ifeq ($(CROSS_COMPILE), aarch64-none-linux-gnu-)
	LFLAGS_ALL := --gc-sections $(shell $(CROSS_COMPILE)gcc -print-libgcc-file-name)
else ifeq ($(CROSS_COMPILE), arm-none-eabi-)
	LFLAGS_ALL := --gc-sections -L/$(XTOOL_PATH_4)/lib/gcc/arm-none-eabi/13.2.1 -lgcc
else
	LFLAGS_ALL := --gc-sections -L/tools/arm/arm-augentix-linux-gnueabi/lib/gcc/arm-augentix-linux-gnueabi/4.9.3 -lgcc
endif


### Finally, define complete commands for all actions.

ASSEMBLE = $(COMPILE) $(AFLAGS_ALL) $(AFLAGS_LOCAL)
COMPILE = $(CC) $(CFLAGS_ALL) $(CFLAGS_LOCAL) -o $@ -c $<
LINK = $(LD) -o $@ --start-group $^ --end-group $(LFLAGS_ALL) $(LFLAGS_LOCAL)
ARCHIVE_STATIC = $(AR) rcsD $@ $^
ARCHIVE_SHARED = $(CC) -shared -Wl,--build-id -Wl,--soname,$(basename $(basename $(notdir $@))) -o $@ \
		-Wl,--whole-archive $^ -Wl,--no-whole-archive

################################################################################
# Build rules
################################################################################

### First, define default build target.

all: primary

### Second, define variables for collecting outputs and temporarily objects.

TARGET_SLIBS  :=
TARGET_DLIBS  :=
TARGET_MODS   :=
UNIT_TEST_PLAT :=
UNIT_TEST_SRC  :=
UNIT_TEST_EXE  :=
TARGET_DOCS   :=
CLEAN_FILES   :=
CLEAN_DIRS    :=
CLEAN_TARGETS :=

### Then, collect the knowledge about how to build all outputs.

root := $(realpath ..)
dir := $(root)/build
chip_dir := $(root)/$(CPVS_CHIP)

ifneq ($(CONFIG_RELEASE),y)
    ### In SDK manifest, traverse directory tree to include Rules.mk files.
    ifneq ($(CPVS_CHIP), ) ### To prevent doing distclean when no CPVS_CHIP exists
        subdir := $(root)/$(CPVS_CHIP)/src
        include $(subdir)/Rules.mk

        subdir := $(root)/$(CPVS_CHIP)/test
        include $(subdir)/Rules.mk

        subdir := $(root)/$(CPVS_CHIP)/doc
        include $(subdir)/Rules.mk
    endif
else
    ### In APP manifest, specify outputs manually.
    TARGET_SLIBS += $(root)/lib/libpid.a
    TARGET_SLIBS += $(root)/lib/libutil.a
    # TARGET_DLIBS += $(root)/lib/libpid.so.$(REAL_SUFFIX)
    # TARGET_DLIBS += $(root)/lib/libutil.so.$(REAL_SUFFIX)
endif # ifneq ($(CONFIG_RELEASE),y)

### Finally, define essential build targets.

CLEAN_FILES += $(root)/include
CLEAN_FILES += $(root)/src
CLEAN_FILES += $(root)/build/*.elf

.PHONY: primary
ifneq ($(CONFIG_RELEASE),y)
    ### In SDK manifest, build primary outputs if necessary.
    primary: $(TARGET_SLIBS) $(TARGET_DLIBS) $(TARGET_MODS)
	$(Q)$(LN) -sfT $(CPVS_CHIP)/include $(root)/include
	$(Q)$(LN) -sfT $(CPVS_CHIP)/src $(root)/src
else
    ### In APP manifest, create link to pre-built primary outputs.
    primary:
	$(Q)$(LN) -sfT include.$(CPVS_CHIP) $(root)/include
	$(Q)$(LN) -sfT $(CPVS_CHIP)/src $(root)/src
    ifeq ($(CONFIG_UCLIBC),y)
        ifeq ($(CONFIG_KERNEL_V6_1),y)
	$(Q)$(LN) -sfT lib.$(CPVS_CHIP).uclibc $(root)/lib
        else
	$(Q)$(LN) -sfT lib.$(CPVS_CHIP).uclibc $(root)/lib
        endif
    else
    ifeq ($(CONFIG_KERNEL_V6_1),y)
		$(Q)$(LN) -sfT ko.$(CPVS_CHIP).linux6.1 $(root)/ko
    else
		$(Q)$(LN) -sfT ko.$(CPVS_CHIP) $(root)/ko
    endif
	$(Q)$(LN) -sfT lib.$(CPVS_CHIP) $(root)/lib
    endif
endif


.PHONY: test
ifneq ($(CONFIG_RELEASE),y)
    ### In SDK manifest, build the test outputs if necessary.
    test: all $(UNIT_TEST_SRC) $(UNIT_TEST_PLAT) $(UNIT_TEST_EXE)
else
    ### In APP manifest, do nothing.
    test:
endif # ifneq ($(CONFIG_RELEASE),y)

.PHONY: doc
ifneq ($(CONFIG_RELEASE),y)
    ### In SDK manifest, build the doc outputs if necessary.
    doc: $(TARGET_DOCS)
else
    ### In APP manifest, do nothing.
    doc:
endif # ifneq ($(CONFIG_RELEASE),y)

.PHONY: clean
ifneq ($(CONFIG_RELEASE),y)
    ### In SDK manifest, remove primary outputs and temporarily objects.
    clean: $(CLEAN_TARGETS)
	@printf "  %-8s$(root)\n" "CLEAN"
	$(Q)$(RM) -f $(CLEAN_FILES)
	$(Q)$(foreach d, $(CLEAN_DIRS), $(RM) -rf $(d); )
else
    ### In APP manifest, remove the link to pre-build primary outputs.
    clean:
	@printf "  %-8s$(root)\n" "CLEAN"
	$(Q)$(RM) -f $(root)/src
	$(Q)$(RM) -f $(root)/include
	$(Q)$(RM) -f $(root)/lib
	$(Q)$(RM) -f $(root)/ko
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
	$(Q)$(foreach f, $(TARGET_MODS), \
		printf "  %-8s$(CUSTOM_LIB)/$(notdir $(f))\n" "INSTALL"; \
		$(INSTALL) -m 644 -t $(CUSTOM_LIB) $(f); \
	)

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
	@echo $(chip_dir)
	@echo ""
	@echo "  Syntax:"
	@echo "    make [options] <target>"
	@echo ""
	@echo "  Options:"
	@echo "    V=0                  Hide command lines. (default)"
	@echo "    V=1                  Show command lines."
	@echo "    CPVS_STARTUP_ARCH    Specify the CPU, CA55(default), CM7 or CM0"
	@echo ""
	@echo "  Targets:"
	@echo "    all         Build primary outputs. (default)"
	@echo "    test        Build test programs."
	@echo "    doc         Build documents."
	@echo "    clean       Clean all outputs."
	@echo "    distclean   Clean all outputs and configurations."
	@echo "    install     Install primary outputs"
	@echo "    uninstall   Uninstall primary outputs"
	@echo "    help        Show help messages."
	@echo ""

################################################################################
# General rules
################################################################################

%.obj: %.c
	@printf "  %-8s$@\n" "CC"
	$(Q)$(COMPILE)

%.obj: %.S
	@printf "  %-8s$@\n" "AS"
	$(Q)$(ASSEMBLE)

%.elf: $(UNIT_TEST_PLAT) $(TARGET_SLIBS) $(UNIT_TEST_SRC)
	@printf "  %-8s$@\n" "LD"
	$(LINK)

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

