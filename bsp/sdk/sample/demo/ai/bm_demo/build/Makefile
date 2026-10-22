SDKSRC_DIR ?= $(realpath $(CURDIR)/../../../../../..)
include $(SDKSRC_DIR)/firmware/build/sdksrc.mk

include $(SAMPLE_DEMO_PATH)/internal.mk
include $(SAMPLE_DEMO_PATH)/common.mk

KCONFIG_CONFIG ?= $(SAMPLE_DEMO_PATH)/.config
-include $(KCONFIG_CONFIG)

# specify CFLAGS and LDLIBS
INC := \
	-isystem$(JSON_INC) \
	-I$(LIBAVFTR_INC) -I$(LIBEAIF_INC) \
	-I$(MPP_INC) -I$(FEATURE_AUDIO_INC_PATH) -I$(FEATURE_VIDEO_INC_PATH)

LDLIBS := -L$(FEATURE_VIDEO_LIB_PATH) -lvftr -L$(JSON_LIB) -ljson-c
LDLIBS += -L$(MPP_LIB) -lmpp -lm -lpthread -lrt

CFLAGS += $(INC)

ifeq ($(CONFIG_SAMPLE_DEMO_BM_SUPPORT_SEI),y)
	CPPFLAGS += -DCONFIG_SAMPLE_DEMO_BM_SUPPORT_SEI
endif

ifeq ($(CONFIG_KERNEL_V6_1)$(CONFIG_UCLIBC),yy)
CFLAGS += -fstack-protector-strong
endif

# specify bin
BIN_NAME = bm_demo

# bin paths
TARGET_CONFIG_PATH := $(SYSTEMFS)/mpp/bm_config
SRC_CONFIG_PATH := $(root)/assets
BIN_OUTPUT := $(addprefix $(BIN_OUT_PATH)/,$(BIN_NAME))
BIN_TARGET := $(addprefix $(bindir)/,$(BIN_NAME))

# sepcify targets
.DEFAULT_GOAL := default

.PHONY: default
default: all

.PHONY: all
all: $(BIN_OUTPUT)

.PHONY: clean
clean:
	$(Q)$(RM) -r $(BIN_OUT_PATH) $(DEP_PATH) $(OBJ_PATH)

.PHONY: distclean
distclean: uninstall clean

.PHONY: install-config
install-config:
	@printf "  %-8s$(TARGET_CONFIG_PATH)/*\n" "INSTALL"
	$(Q)$(MKDIR_P) $(TARGET_CONFIG_PATH)
	$(Q)$(foreach f, $(wildcard $(SRC_CONFIG_PATH)/*), \
		cp -r $(f) $(TARGET_CONFIG_PATH)/$(notdir $(f)); \
	)

.PHONY: uninstall-config
uninstall-config:
	@printf "  %-8s$(TARGET_CONFIG_PATH)\n" "RM"
	$(Q)rm -rf $(TARGET_CONFIG_PATH)

.PHONY: install
install: all $(BIN_TARGET) install-config

.PHONY: uninstall
uninstall: uninstall-config
	$(Q)$(RM) $(BIN_TARGET)

$(BIN_OUTPUT): $(OBJS)
	$(Q)$(MKDIR_P) $(BIN_OUT_PATH)
	@printf "  %-8s$@\n" "CC"
	$(Q)$(CC) $(DEPFLAGS) $(CFLAGS) $(CPPFLAGS) -o $@ $^ $(LDLIBS)

-include $(DEPS)
