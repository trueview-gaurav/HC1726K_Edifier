SDKSRC_DIR ?= $(realpath $(CURDIR)/../../../../..)
include $(SDKSRC_DIR)/firmware/build/sdksrc.mk
include $(SAMPLE_DEMO_PATH)/internal.mk

# architecture dependent variables
# TODO: replace "sapporo" with proper config name
ifeq ($(filter y, $(CONFIG_OSAKA) $(CONFIG_SAPPORO) $(CONFIG_KAMO)), y)
LOAD_SCRIPT := $(CURDIR)/load_mpp_hc17x6.sh
CD_SCRIPT := $(CURDIR)/collect_data_hc17x6.sh
else
LOAD_SCRIPT := $(CURDIR)/load_mpp_hc17x3.sh
CD_SCRIPT := $(CURDIR)/collect_data.sh
endif

# specify build / install target
TARGET_PATH := $(SYSTEMFS)/mpp/script
SOURCES := $(filter-out load_mpp_%.sh collect_data%.sh, $(wildcard *.sh))
TARGETS := $(addprefix $(TARGET_PATH)/, load_mpp.sh collect_data.sh $(SOURCES))

# targets
.DEFAULT_GOAL := default

.PHONY: default
default: all

.PHONY: all
all: ;

.PHONY: clean
clean: ;

.PHONY: install
install: all $(TARGETS)

.PHONY: distclean
distclean: uninstall clean

$(TARGET_PATH)/%.sh: %.sh | $(TARGET_PATH)
	@printf "  %-8s$@\n" "INSTALL"
	$(Q)install -m 755 $< $@

$(TARGET_PATH)/load_mpp.sh: $(LOAD_SCRIPT) | $(TARGET_PATH)
	@printf "  %-8s$@\n" "INSTALL"
	$(Q)install -m 755 $< $@

$(TARGET_PATH)/collect_data.sh: $(CD_SCRIPT) | $(TARGET_PATH)
	@printf "  %-8s$@\n" "INSTALL"
	$(Q)install -m 755 $< $@

$(TARGET_PATH):
	@printf "  %-8s$@\n" "MKDIR"
	$(Q)mkdir -p $(TARGET_PATH)

.PHONY: uninstall
uninstall:
	@printf "  %-8s$(TARGET_PATH)\n" "RMDIR"
	$(Q)rm -f $(TARGETS)
	$(Q)if [ -d $(TARGET_PATH) ]; then \
		rmdir --ignore-fail-on-non-empty $(TARGET_PATH); \
	fi
