root := $(CURDIR)

SDKSRC_DIR ?= $(realpath $(CURDIR)/../../../..)
APP_PATH ?= $(realpath $(SDKSRC_DIR)/firmware/reference_software)

include $(APP_PATH)/internal.mk
include $(root)/build_common.mk

# Set the default goal explicitly
.DEFAULT_GOAL := all

.PHONY: all
all: $(BIN)

.PHONY: install
install: all | $(SYSTEM_BIN)
	$(Q)$(INSTALL_PROGRAM) $(BIN) $(BIN_TARGET)

.PHONY: uninstall
uninstall:
	$(Q)$(RM) $(BIN_TARGET)

.PHONY: clean
clean:
	$(Q)$(RM_RF) $(OBJ_PATH) $(BIN_OUT_PATH) $(DEP_PATH) $(STAMP_PATH)

.PHONY: distclean
distclean: clean uninstall
