SDKSRC_DIR ?= $(realpath $(CURDIR)/../../../../../..)
include $(SDKSRC_DIR)/firmware/build/sdksrc.mk

include $(SAMPLE_DEMO_PATH)/internal.mk
include $(SAMPLE_DEMO_PATH)/common.mk

# include build options
KCONFIG_CONFIG ?= $(SAMPLE_DEMO_PATH)/.config
-include $(KCONFIG_CONFIG)

# specify CFLAGS, LDFLAGS and LDLIBS
INC := -I$(LIBMP4V2_INC)../ -I$(AUDIO_INC) -I$(ALSA_INC) -I$(LAME_INC)
CFLAGS += $(INC) -pthread
CXXFLAGS += $(INC) -Wno-unused-parameter -Wno-missing-field-initializers -Wl,--gc-sections -pthread
LIBDIRS += $(LIBMP4V2_LIB) $(ALSA_LIB) $(LAME_LIB)
LDFLAGS += $(addprefix -L,$(LIBDIRS))
LDLIBS += :libmp4v2.a rt asound mp3lame
LINK_LIBS := $(addprefix -l,$(LDLIBS))

ifeq ($(CONFIG_KERNEL_V6_1)$(CONFIG_UCLIBC),yy)
CFLAGS += -fstack-protector-strong
endif

# source codes, objects, and dependencies
SRCS = $(wildcard $(SRC_PATH)/*.c)
OBJS = \
	$(patsubst $(SRC_PATH)/%.c,$(OBJ_PATH)/%.o, \
	$(patsubst $(SRC_PATH)/%.cc,$(OBJ_PATH)/%.o, \
	$(patsubst $(SRC_PATH)/%.cpp,$(OBJ_PATH)/%.o,$(SRCS))))
DEPS = \
	$(patsubst $(SRC_PATH)/%.c,$(DEP_PATH)/%.d, \
	$(patsubst $(SRC_PATH)/%.cc,$(DEP_PATH)/%.d, \
	$(patsubst $(SRC_PATH)/%.cpp,$(DEP_PATH)/%.d,$(SRCS))))

# specify bin
BIN_NAME := mp4_muxer

# paths
BIN_OUTPUT := $(addprefix $(BIN_OUT_PATH)/,$(BIN_NAME))
BIN_TARGET := $(addprefix $(bindir)/,$(BIN_NAME))

.DEFAULT_GOAL := default

.PHONY: default
default: all

.PHONY: all
all: $(BIN_OUTPUT)


.PHONY: check
check:
	@echo $(OBJ_PATH) $(SRC_PATH)
	@echo LDFLAG $(LDFLAGS)
	@echo INC $(INC)
	@echo LDLIBS $(LIBDIRS)
	@echo LINK_LIBS $(LINK_LIBS)

# Delete all files created by building the app.
.PHONY: clean
clean:
	$(Q)$(RM) -r $(BIN_OUT_PATH) $(DEP_PATH) $(OBJ_PATH)

# Delete all files created by configuring, installing or building.
.PHONY: distclean
distclean: uninstall clean

.PHONY: install
install: all $(BIN_TARGET)

.PHONY: uninstall
uninstall:
	$(Q)$(RM) $(BIN_TARGET)

$(BIN_OUTPUT): $(OBJS)
	$(Q)$(MKDIR_P) $(BIN_OUT_PATH)
	$(Q)$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS) $(LINK_LIBS)

-include $(DEPS)
