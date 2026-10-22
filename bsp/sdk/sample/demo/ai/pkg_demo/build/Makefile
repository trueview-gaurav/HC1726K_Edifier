################################################################################
# SDK related definitions
################################################################################

SDKSRC_DIR ?= $(realpath $(CURDIR)/../../../../../..)
include $(SDKSRC_DIR)/firmware/build/sdksrc.mk
include $(SAMPLE_DEMO_PATH)/internal.mk
include $(APP_PATH)/internal.mk

KCONFIG_CONFIG ?= $(SAMPLE_DEMO_PATH)/.config
-include $(KCONFIG_CONFIG)

################################################################################
# Build tools and commands
################################################################################

MAKEFLAGS += -j

### First, specify the build tools.

CC := $(CROSS_COMPILE)gcc
CX := $(CROSS_COMPILE)g++
AR := $(CROSS_COMPILE)ar
RM := rm
LN := ln
MKDIR := mkdir
RMDIR := rmdir
STRIP := $(CROSS_COMPILE)strip
INSTALL := install

### Then, define global compilation and linking flags.

DEFINE_ALL :=
CFLAGS_ALL := $(CFLAGS) -MMD
LFLAGS_ALL :=

ifeq ($(CONFIG_KERNEL_V6_1)$(CONFIG_UCLIBC),yy)
CFLAGS_ALL += -fstack-protector-strong
endif

### Finally, define complete commands for all actions.

COMPILE = $(addprefix -D,$(DEFINE_ALL)) $(addprefix -D,$(DEFINE_LOCAL)) $(CFLAGS_ALL) $(CFLAGS_LOCAL) -o $@ -c $<
LINK = -o $@ $^ $(LFLAGS_ALL) $(LFLAGS_LOCAL)

################################################################################
# Build rules
################################################################################

TARGET_CONFIG_PATH = $(SYSTEMFS)/mpp/pkg_config
TARGET_MODELS += $(EAIF_SERV_PATH)/models/yolo/model.v5.2.flex.param.bin
TARGET_MODELS += $(EAIF_SERV_PATH)/models/yolo/model.v5.2.flex.bin.bin
TARGET_LIBS += ml_package
TARGET_ML_DLIBS := $(patsubst %,lib%.so,$(filter-out %rtos,$(filter ml_%,$(TARGET_LIBS))))
MODEL_INSTALL_DIR := $(SYSTEMFS)/eaif/models/yolo

### First, define default build target.

.PHONY: all
all: primary

### Second, define variables for collecting outputs and temporarily objects.

TARGET_BINS   :=
TARGET_ASSETS :=
CLEAN_FILES   :=
CLEAN_DIRS    :=
CLEAN_TARGETS :=

### Then, collect the knowledge about how to build all outputs.

root := $(realpath ..)
dir := $(root)/build

subdir := $(root)/src
include $(subdir)/Rules.mk

subdir := $(root)/utils/sei_support
# include $(subdir)/Rules.mk

TARGET_ASSETS += $(wildcard $(root)/assets/*)

################################################################################
# Targets (Must be placed after "Subdirectories" section)
################################################################################

.PHONY:	primary
primary: $(TARGET_BINS)

.PHONY: clean
clean:
	@printf "  %-8s$(root)\n" "CLEAN"
	$(Q)$(RM) -f $(CLEAN_FILES)
	$(Q)$(foreach d, $(CLEAN_DIRS), $(RM) -rf $(d); )

.PHONY: distclean
distclean: uninstall-all clean

.PHONY: install install-model install-libml
install: primary
	$(Q)$(MKDIR) -p $(CUSTOM_BIN)
	$(Q)$(foreach f, $(TARGET_BINS), \
		printf "  %-8s$(CUSTOM_BIN)/$(notdir $(f))\n" "INSTALL"; \
		$(INSTALL) -m 755 -t $(CUSTOM_BIN) $(f); \
	)
	$(Q)$(MKDIR) -p $(TARGET_CONFIG_PATH)
	$(Q)$(foreach f, $(TARGET_ASSETS), \
		printf "  %-8s$(TARGET_CONFIG_PATH)/$(notdir $(f))\n" "INSTALL"; \
		$(INSTALL) -m 644 -t $(TARGET_CONFIG_PATH) $(f); \
	)

install-model: $(TARGET_MODELS)
	$(Q)printf "  %-8s$(MODEL_INSTALL_DIR)\n" "MKDIR"
	$(Q)$(MKDIR) -p $(MODEL_INSTALL_DIR)
	$(Q)$(foreach f, $(TARGET_MODELS), \
	   printf "  %-8s$(notdir $(f))\n" "INSTALL"; \
	   cp -r $(f) $(MODEL_INSTALL_DIR)/; \
	)

install-libml:
	@echo INSTALL $(TARGET_ML_DLIBS)
	$(warning CUSTOM_LIB is set to: $(CUSTOM_LIB))
	$(warning TARGET_ML_DLIBS is set to: $(TARGET_ML_DLIBS))
	$(warning FEATURE_ML_LIB_PATH is set to: $(FEATURE_ML_LIB_PATH))
	$(Q)mkdir -p $(CUSTOM_LIB)
	$(Q)$(foreach f, $(TARGET_ML_DLIBS), \
		$(eval ACTUAL_LIB := $(shell find -L $(FEATURE_ML_LIB_PATH) -type f -name "$(basename $(f)).*" | grep "\.so\.")) \
		$(if $(ACTUAL_LIB), \
			$(eval MAJOR_VER := $(shell echo $(ACTUAL_LIB) | sed -E 's/.*\.so\.([0-9]+).*/\1/')) \
			$(if $(MAJOR_VER), \
				find $(CUSTOM_LIB) -type f -name "$(basename $(f)).so.*" -exec rm -rf {} \;; \
				install -m 644 -t $(CUSTOM_LIB) $(ACTUAL_LIB); \
				$(eval SHORT_NAME := $(f).$(MAJOR_VER)) \
				ln -sfT $(notdir $(ACTUAL_LIB)) $(CUSTOM_LIB)/$(SHORT_NAME); \
				printf "  %-8s$(CUSTOM_LIB)/$(notdir $(ACTUAL_LIB))\n" "INSTALL", \
				printf "ERROR: Cannot extract version number from $(ACTUAL_LIB)\n" \
			), \
			printf "WARNING: Library $(f).* not found in $(FEATURE_ML_LIB_PATH)\n" \
		) \
	)

install-all: install install-model install-libml

.PHONY: uninstall uninstall-model uninstall-libml
uninstall:
	$(Q)$(foreach f, $(TARGET_BINS), \
		printf "  %-8s$(CUSTOM_BIN)/$(notdir $(f))\n" "RM"; \
		$(RM) -f $(CUSTOM_BIN)/$(notdir $(f)); \
	)
	$(Q)$(foreach f, $(TARGET_ASSETS), \
		printf "  %-8s$(TARGET_CONFIG_PATH)/$(notdir $(f))\n" "RM"; \
		$(RM) -f $(TARGET_CONFIG_PATH)/$(notdir $(f)); \
	)
	$(Q)if [ -d $(TARGET_CONFIG_PATH) ]; then \
		$(RMDIR) --ignore-fail-on-non-empty $(TARGET_CONFIG_PATH); \
	fi
	$(Q)if [ -d $(CUSTOM_LIB) ]; then \
		$(RMDIR) --ignore-fail-on-non-empty $(CUSTOM_LIB); \
	fi

uninstall-model:
	$(Q)printf "  %-8s$(MODEL_INSTALL_DIR)\n" "RM"
	$(Q)$(RM) -rf $(MODEL_INSTALL_DIR)

uninstall-libml:
	$(Q)if [ -d "$(CUSTOM_LIB)" ]; then \
		$(foreach f, $(TARGET_ML_DLIBS), \
			$(eval BASE_NAME := $(basename $(f))) \
			find $(CUSTOM_LIB) -name "$(BASE_NAME).so.*" -exec rm -vf {} \;; \
		) \
		if [ -z "$$(ls -A $(CUSTOM_LIB))" ]; then \
			printf "  RM\t$(CUSTOM_LIB)\n"; \
			rmdir $(CUSTOM_LIB); \
		fi \
	fi

uninstall-all: uninstall uninstall-model uninstall-libml

# $(MODEL_INSTALL_DIR):
# 	$(Q)$(MKDIR_P) $@

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
	@printf "  %-8s$@\n" "CC"
	$(Q)$(CC) $(COMPILE)

$(root)/bin $(TARGET_CONFIG_PATH):
	@printf "  %-8s$@\n" "MKDIR"
	$(Q)$(MKDIR) $@

CLEAN_DIRS += $(root)/bin

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
