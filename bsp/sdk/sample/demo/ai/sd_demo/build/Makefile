SDKSRC_DIR ?= $(realpath $(CURDIR)/../../../../../..)
include $(SDKSRC_DIR)/firmware/build/sdksrc.mk
include $(SAMPLE_DEMO_PATH)/internal.mk
include $(SAMPLE_DEMO_PATH)/common.mk
include $(APP_PATH)/internal.mk

KCONFIG_CONFIG ?= $(SAMPLE_DEMO_PATH)/.config
-include $(KCONFIG_CONFIG)

# TFLite inference engine for the CD (v2.0/YAM Net) backend in libaftr_cd.so.
# This is a product-layer choice owned here (alongside rm.list.d and libinf's
# engine choice), NOT in core/aftr. Map the Kconfig bool to the CD_TFLITE_OPTIM
# value forwarded to `install-cd` (see the install target below):
#   CONFIG_SAMPLE_DEMO_SD_DEMO_TFLITE_OPTIM=y -> optim (libtensorflow-lite-optim)
#   unset                                     -> full  (libtensorflow-lite)
CD_TFLITE_OPTIM := $(if $(CONFIG_SAMPLE_DEMO_SD_DEMO_TFLITE_OPTIM),y,n)

# specify CFLAGS and LDLIBS
INC := -I$(AUDIO_INC) -I$(ALSA_INC) -I$(FEATURE_AUDIO_INC_PATH) -I$(MPP_INC) -I$(JSON_INC)

LDLIBS := -L$(ALSA_LIB) -lasound -L$(FEATURE_AUDIO_LIB_PATH) -L$(MPP_LIB) -lmpp -L$(JSON_LIB) -ljson-c -lstdc++ -lpthread
# NOTE: sd_demo.cc does not call TFLite directly. The inference engine is a
# private dependency of libaftr_cd.so, selected by CONFIG_SAMPLE_DEMO_SD_DEMO_TFLITE_OPTIM
# (forwarded as CD_TFLITE_OPTIM to install-cd) and resolved transitively via
# -laftr_cd below. Do NOT link -ltensorflow-lite here: it forced the full
# engine to load alongside the engine libaftr_cd.so pulls in, and pinned the
# version in the wrong place. The RTOS variant (libaftr_rtos.a) uses SVM and
# needs no TFLite either.
# We still give the linker -rpath-link for both engine dirs so it can locate
# whichever engine libaftr_cd.so was built against (optim or full) to resolve
# that transitive DT_NEEDED. -rpath-link is link-time search only: it adds no
# DT_NEEDED to sd_demo and pulls in no engine symbols.
LDLIBS += -Wl,-rpath-link,$(TFLITE_OPTIM_LIB) -Wl,-rpath-link,$(TFLITE_LIB)

CFLAGS += $(INC) -g
CXXFLAGS += $(INC) -g

ifeq ($(CONFIG_KERNEL_V6_1)$(CONFIG_UCLIBC),yy)
CXXFLAGS += -fstack-protector-strong
endif

ifeq ($(CONFIG_SAMPLE_DEMO_SD_DEMO_REMOTE_CORE),y)
	LDLIBS += -l:libaftr_rtos.a
	LDLIBS += -L $(LIBAMPC_LIB)
	LDLIBS += -L $(LIBMETAL_LIB)
	LDLIBS += -L $(LIBOPENAMP_LIB)
	LDLIBS += -L $(firstword $(wildcard $(BUILDROOT_OUTPUT_BUILD_PATH)/libsysfs-2.*/lib/.libs))
	LDLIBS += -lampc_linux
	LDLIBS += -lmetal
	LDLIBS += -lopen_amp
	LDLIBS += -lsysfs

else
	LDLIBS += -laftr -laftr_cd
endif

SRCS = $(wildcard $(SRC_PATH)/*.cc)
OBJS = $(patsubst $(SRC_PATH)/%.cc,$(OBJ_PATH)/%.o,$(SRCS))
DEPS = $(patsubst $(SRC_PATH)/%.cc,$(DEP_PATH)/%.d,$(SRCS))

# specify bin
BIN_NAME = sd_demo

# bin paths
TARGET_CONFIG_PATH := $(SYSTEMFS)/mpp/sd_config
SRC_CONFIG_PATH := $(root)/assets
BIN_OUTPUT := $(addprefix $(BIN_OUT_PATH)/,$(BIN_NAME))
BIN_TARGET := $(addprefix $(bindir)/,$(BIN_NAME))
YAMNET_MODEL_SRC := $(EAIF_SERV_PATH)/models/classifiers/cd_yamnet
YAMNET_MODEL_INSTALL_DIR := $(SYSTEMFS)/eaif/models/yam-net
SVM_MODEL_SRC := $(EAIF_SERV_PATH)/models/svm
SVM_MODEL_INSTALL_DIR := $(SYSTEMFS)/eaif/models/svm

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

.PHONY: install-model
install-model:
	$(Q)printf "  %-8s$(YAMNET_MODEL_INSTALL_DIR)\n" "MKDIR"
	$(Q)$(MKDIR) -p $(YAMNET_MODEL_INSTALL_DIR)
	$(Q)cp -r $(YAMNET_MODEL_SRC)/. $(YAMNET_MODEL_INSTALL_DIR)/

.PHONY: uninstall-model
uninstall-model:
	$(Q)printf "  %-8s$(YAMNET_MODEL_INSTALL_DIR)\n" "RM"
	$(Q)$(RM) -rf $(YAMNET_MODEL_INSTALL_DIR)

.PHONY: install-svm-model
install-svm-model:
	$(Q)printf "  %-8s$(SVM_MODEL_INSTALL_DIR)\n" "MKDIR"
	$(Q)$(MKDIR) -p $(SVM_MODEL_INSTALL_DIR)
	$(Q)cp -r $(SVM_MODEL_SRC)/. $(SVM_MODEL_INSTALL_DIR)/

.PHONY: uninstall-svm-model
uninstall-svm-model:
	$(Q)printf "  %-8s$(SVM_MODEL_INSTALL_DIR)\n" "RM"
	$(Q)$(RM) -rf $(SVM_MODEL_INSTALL_DIR)

# CD backend selection follows the remote-core Kconfig:
#   REMOTE_CORE=y -> SVM (v1.0) on the RTOS core: install the SVM model only,
#                    no libaftr_cd.so / TFLite engine (would be an unresolvable
#                    orphan on engine-stripped targets -> loader "internal error").
#   otherwise     -> YAM Net (v2.0) on Linux: install the YAM Net model and
#                    libaftr_cd.so via install-cd.
ifeq ($(CONFIG_SAMPLE_DEMO_SD_DEMO_REMOTE_CORE),y)
.PHONY: install
install: all $(BIN_TARGET) install-config install-svm-model

.PHONY: uninstall
uninstall: uninstall-config uninstall-svm-model
	$(Q)$(RM) $(BIN_TARGET)
else
.PHONY: install
install: all $(BIN_TARGET) install-config install-model
	$(Q)$(MAKE) -C $(FEATURE_AUDIO_BUILD_PATH) install-cd CD_TFLITE_OPTIM=$(CD_TFLITE_OPTIM)

.PHONY: uninstall
uninstall: uninstall-config uninstall-model
	$(Q)$(RM) $(BIN_TARGET)
	$(Q)$(MAKE) -C $(FEATURE_AUDIO_BUILD_PATH) uninstall-cd
endif

# $(BIN_OUTPUT): $(OBJS)
# 	$(Q)$(MKDIR_P) $(BIN_OUT_PATH)
# 	$(Q)$(CC) $(DEPFLAGS) $(CFLAGS) -o $@ $^ $(LDLIBS)

$(BIN_OUTPUT): $(OBJS)
	$(Q)$(MKDIR_P) $(BIN_OUT_PATH)
	$(Q)$(CXX) $(DEPFLAGS) $(CXXFLAGS) -o $@ $^ $(LDLIBS)

.PHONY: check
check:
	@echo INC $(INC)
	@echo CFLAGS $(CFLAGS)
	@echo CXXFLAGS $(CXXFLAGS)
	@echo LDLIBS $(LDLIBS)

-include $(DEPS)

