SDKSRC_DIR ?= $(realpath $(CURDIR)/../../../../../..)
include $(SDKSRC_DIR)/firmware/build/sdksrc.mk

include $(SAMPLE_DEMO_PATH)/internal.mk
include $(SAMPLE_DEMO_PATH)/common.mk

# specify CFLAGS and LDLIBS
INC := -I$(LIBFOO_INC)
CFLAGS += $(INC)
LDLIBS := -lm

ifeq ($(CONFIG_KERNEL_V6_1)$(CONFIG_UCLIBC),yy)
CFLAGS += -fstack-protector-strong
endif

# specify bin
BIN_NAME := g726

# bin paths
BIN_OUTPUT := $(addprefix $(BIN_OUT_PATH)/,$(BIN_NAME))
BIN_TARGET := $(addprefix $(bindir)/,$(BIN_NAME))

.DEFAULT_GOAL := default

.PHONY: default
default: all

.PHONY: all
all: $(BIN_OUTPUT)

# Delete all files created by building the app.
.PHONY: clean
clean:
	$(Q)$(RM) -r $(BIN_OUT_PATH) $(DEP_PATH) $(OBJ_PATH)

# Delete all files created by configuring, installing or building.
.PHONY: distclean
distclean: uninstall clean

.PHONY: install
install: all install-bin

.PHONY: install-bin
install-bin: $(BIN_TARGET)

.PHONY: uninstall
uninstall: uninstall-bin

.PHONY: uninstall-bin
uninstall-bin:
	$(Q)$(RM) $(BIN_TARGET)

$(BIN_OUTPUT): $(OBJS)
	$(Q)$(MKDIR_P) $(BIN_OUT_PATH)
	$(Q)$(CC) $(DEPFLAGS) $(CFLAGS) -o $@ $^ $(LDLIBS)

-include $(DEPS)
