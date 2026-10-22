SDKSRC_DIR ?= $(realpath $(CURDIR)/../../../../../..)
include $(SDKSRC_DIR)/firmware/build/sdksrc.mk
include $(APP_PATH)/internal.mk
include $(SAMPLE_DEMO_PATH)/internal.mk
include $(SAMPLE_DEMO_PATH)/common.mk
include $(LIBSAMPLE_PATH)/build/libosd.mk

# specify build flags
MAKEFLAGS += -j

# include build options
KCONFIG_CONFIG ?= $(SAMPLE_DEMO_PATH)/.config
-include $(KCONFIG_CONFIG)
include inf.mk

# specify build tools
CC = $(CROSS_COMPILE)gcc
AR = $(CROSS_COMPILE)ar

# specify CFLAGS
CFLAGS += -MMD -MP -D_FILE_OFFSET_BITS=64 -Wl,--gc-sections

# Enable SSP strong only for Kernel v6.1 + uClibc
ifeq ($(CONFIG_KERNEL_V6_1)$(CONFIG_UCLIBC),yy)
CFLAGS += -fstack-protector-strong
endif

# specify bin
APP_BIN            := mpi_stream
SIGN_BIN           := $(APP_BIN).sig

# paths
root = $(realpath $(CURDIR)/..)

SAMPLE    := $(root)/src/libsample
PARSER    := $(root)/src/parser
INIPARSER := $(root)/src/iniparser

APP_BIN_DIR        := $(root)
CONFIG_DIR         := $(root)/case_config
ASSETS_DIR         := $(root)/assets
ifeq ($(CONFIG_SAMPLE_DEMO_APPVERIFY),y)
TARGET_BIN_DIR     := $(BINPKG_DIR)/$(SECURE_APP_DIR)
TARGET_SIGN_DIR    := $(BINPKG_SIGN_DIR)/$(SECURE_APP_DIR)
else
TARGET_BIN_DIR     := $(SYSTEM_BIN)
endif
TARGET_CONFIG_DIR  := $(SYSTEMFS)/mpp/case_config
TARGET_ASSETS_DIR  := $(SYSTEMFS)/mpp/font

SRCS :=
INCS :=
LIBS :=
LIBDIRS :=

# specify product specific parameters
SNS := $(shell echo $(SENSOR) | tr '[A-Z]' '[a-z]')

DEFS := SNS=$(SNS) SNS0_ID=0
ifneq ($(SENSOR1),)
DEFS += SNS1=$(SENSOR1) SNS1_ID=1
endif
ifneq ($(SENSOR2),)
DEFS += SNS2=$(SENSOR2) SNS2_ID=2
endif
ifneq ($(SENSOR3),)
DEFS += SNS3=$(SENSOR3) SNS3_ID=3
endif

SENSOR_LIBS := sensor_0
ifneq ($(SENSOR1),)
    SENSOR_LIBS += sensor_1
endif
ifneq ($(SENSOR2),)
    SENSOR_LIBS += sensor_2
endif
ifneq ($(SENSOR3),)
    SENSOR_LIBS += sensor_3
endif

ifeq ($(CONFIG_SAMPLE_DEMO_MPI_STREAM_ENABLE_OSD),y)
DEFS += OSD_ENABLE
ifeq ($(CONFIG_LIBSAMPLE_USE_LIBOSD), y)
INCS += $(LIBOSD_DEPENDS_INC)
LIBDIRS += $(LIBOSD_DEPENDS_LIB)
LIBS += $(LIBOSD_DEPENDS_LDFLAG)
endif
endif

ifeq ($(CONFIG_SAMPLE_DEMO_MPI_STREAM_ENABLE_DYNAMIC_DIP),y)
DEFS += DIP_UPDATE_ENABLE
endif


ifeq ($(CONFIG_SAMPLE_DEMO_MPI_STREAM_MULTIPLE_IQ_SUPPORT),y)
DEFS += MULTIPLE_IQ_SUPPORT

ifeq ($(CONFIG_SAMPLE_DEMO_MPI_STREAM_SUPPORT_EXTERNAL_IQ_MODE_SWITCH),y)
DEFS += EXTERNAL_IQ_MODE_SWITCH_ENABLE
endif

ifeq ($(CONFIG_SAMPLE_DEMO_MPI_STREAM_SUPPORT_SOFTWARE_LIGHT_SENSOR),y)
DEFS += SOFTWARE_LIGHT_SENSOR
endif
ifeq ($(CONFIG_SAMPLE_DEMO_MPI_STREAM_SUPPORT_GPIO_LIGHT_SENSOR),y)
DEFS += GPIO_LIGHT_SENSOR
endif
ifeq ($(CONFIG_SAMPLE_DEMO_MPI_STREAM_SUPPORT_ADC_LIGHT_SENSOR),y)
DEFS += ADC_LIGHT_SENSOR
endif

endif

# specify source files and include directories
SRCS += $(wildcard $(root)/src/*.c) \
        $(wildcard $(root)/src/parser/*.c)
INCS += $(root)/src/parser \
        $(MPP_PATH)/include \
        $(SENSOR_PATH) \
        $(LIBSAMPLE_INC) \
        $(UDPS_INC) \
        $(LIBAVFTR_INC)\

ifeq ($(CONFIG_SAMPLE_DEMO_MPI_STREAM_ENABLE_ML),y)
INCS += $(FEATURE_ML_INC_PATH)
endif

ifeq ($(CONFIG_LIBINF_INSTALL_OBJECT_DETECTION_YOLO_MODELS),y)
INCS += $(CONFIG_INF_INCS)\
		$(LIBINF_INC)
endif

LIBS += $(SENSOR_LIBS)

ifeq ($(CONFIG_SAMPLE_DEMO_MPI_STREAM_ENABLE_ML),y)
LIBS += sample
DEFS += CB_BASED_OD
endif

ML_LOCAL_COMMON_LIBS := ncnn-compact \
						stdc++

ML_REMOTE_COMMON_LIBS := ampc_linux \
						 metal \
						 open_amp \
						 atomic \

ifeq ($(CONFIG_SAMPLE_DEMO_MPI_STREAM_USE_OD_PEOPLE_VEHICLE_PET_EARLY),y)
LIBDIRS += $(BUILDROOT_OUTPUT_PATH)/host/arm-buildroot-linux-uclibcgnueabi/sysroot/usr/lib
ML_REMOTE_COMMON_LIBS += :libsysfs.a \
                         :libstdc++.a
else
ML_REMOTE_COMMON_LIBS += sysfs \
                         stdc++
endif

ifeq ($(CONFIG_SAMPLE_DEMO_MPI_STREAM_ML_OD_PEOPLE_VEHICLE_PET_LOCAL),y)
LIBS += ml_peoplevehiclepet \
        $(ML_LOCAL_COMMON_LIBS)
DEFS += USE_PEOPLE_VEHICLE_PET_MODEL
endif

ifeq ($(CONFIG_SAMPLE_DEMO_MPI_STREAM_ML_OD_LITE_PEOPLE_VEHICLE_PET_LOCAL),y)
LIBS += ml_peoplevehiclepet_lite \
        $(ML_LOCAL_COMMON_LIBS)
DEFS += USE_PEOPLE_VEHICLE_PET_LITE_MODEL
endif

ifeq ($(CONFIG_SAMPLE_DEMO_MPI_STREAM_ML_OD_LITE_PEOPLE_LOCAL),y)
LIBS += ml_people_lite \
        $(ML_LOCAL_COMMON_LIBS)
DEFS += USE_PEOPLE_LITE_MODEL
endif

ifeq ($(CONFIG_SAMPLE_DEMO_MPI_STREAM_ML_OD_PEOPLE_VEHICLE_PET_REMOTE),y)
LIBS += ml_peoplevehiclepet_rtos \
        $(ML_REMOTE_COMMON_LIBS)
DEFS += USE_PEOPLE_VEHICLE_PET_MODEL
endif

ifeq ($(CONFIG_SAMPLE_DEMO_MPI_STREAM_ML_OD_LITE_PEOPLE_VEHICLE_PET_REMOTE),y)
LIBS += ml_peoplevehiclepet_lite_rtos \
        $(ML_REMOTE_COMMON_LIBS)
DEFS += USE_PEOPLE_VEHICLE_PET_LITE_MODEL
endif

ifeq ($(CONFIG_SAMPLE_DEMO_MPI_STREAM_ML_OD_LITE_PEOPLE_REMOTE),y)
LIBS += ml_people_lite_rtos \
        $(ML_REMOTE_COMMON_LIBS)
DEFS += USE_PEOPLE_LITE_MODEL
endif

ifeq ($(CONFIG_SAMPLE_DEMO_MPI_STREAM_USE_OD_PEOPLE_VEHICLE_PET_EARLY),y)
LIBS += ml_early_peoplevehiclepet_early \
        $(ML_REMOTE_COMMON_LIBS)
DEFS += USE_PEOPLE_VEHICLE_PET_EARLY_MODEL
endif

MODEL_SRC_PATH := $(EAIF_SERV_PATH)/models/yolo
MODEL_INSTALL_DIR := $(SYSTEMFS)/eaif/models/yolo
ifneq ($(filter USE_PEOPLE_VEHICLE_PET_MODEL, $(DEFS)),)
TARGET_MODELS += $(MODEL_SRC_PATH)/model.v5.2.2.param.bin
TARGET_MODELS += $(MODEL_SRC_PATH)/model.v5.2.2.bin.bin
endif

ifneq ($(filter USE_PEOPLE_VEHICLE_PET_LITE_MODEL, $(DEFS)),)
TARGET_MODELS += $(MODEL_SRC_PATH)/model.v5.2.2.lite.param.bin
TARGET_MODELS += $(MODEL_SRC_PATH)/model.v5.2.2.lite.bin.bin
endif

ifneq ($(filter USE_PEOPLE_LITE_MODEL, $(DEFS)),)
TARGET_MODELS += $(MODEL_SRC_PATH)/model.v5.2.2.hd.lite.param.bin
TARGET_MODELS += $(MODEL_SRC_PATH)/model.v5.2.2.hd.lite.bin.bin
endif

ifeq ($(CONFIG_LIBINF_INSTALL_OBJECT_DETECTION_YOLO_MODELS),y)
LIBS += $(CONFIG_INF_LIB) \
        inf \
        dl
endif

LIBS += pthread \
        m \
        sample\
        mpp \
        udps \
        vftr \
        rt


LIBDIRS += $(MPP_LIB) \
          $(LIBSENSOR_LIB) \
          $(UDPS_LIB) \
          $(LIBSAMPLE_LIB) \
          $(FILE_LIB) \
          $(FEATURE_VIDEO_LIB_PATH)

ifeq ($(CONFIG_LIBSAMPLE_ENABLE_MP4_RECORDING),y)
INCS += $(LIBMP4V2_INC) $(AUDIO_INC) $(ALSA_INC) $(LAME_INC)
LIBDIRS += $(LIBMP4V2_LIB) $(ALSA_LIB) $(LAME_LIB)
LIBS += mp4v2 asound mp3lame
endif

ifeq ($(CONFIG_LIBSAMPLE_ENABLE_AUDIO_RECORDING),y)
INCS += $(AUDIO_INC) $(ALSA_INC)
LIBDIRS += $(ALSA_LIB)
LIBS += asound
endif

ifeq ($(CONFIG_SAMPLE_DEMO_MPI_STREAM_ENABLE_ML),y)
LIBDIRS += $(FEATURE_ML_LIB_PATH)\
           $(NCNN_COMPACT_LIB) \
           $(LIBAMPC_LIB) \
           $(LIBMETAL_LIB) \
           $(LIBOPENAMP_LIB) \
           $(BUILDROOT_TARGET_LIB)
endif

ifeq ($(CONFIG_LIBINF_INSTALL_OBJECT_DETECTION_YOLO_MODELS),y)
LIBDIRS += $(CONFIG_INF_LIB_PATH) \
           $(LIBINF_LIB)
endif

# specify the corresponding libml_XXX.so to install, no need for static link
TARGET_ML_DLIBS :=

# Function: Check if libXXX.a exists in LIBDIRS; if yes, use -l:libXXX.a, else use -lXXX
define SELECT_LIB_LINK
$(foreach dir,$(LIBDIRS),\
  $(if $(wildcard $(dir)/lib$(1).a),-l:lib$(1).a,))$(if $(filter -l:lib$(1).a,$(foreach dir,$(LIBDIRS),$(if $(wildcard $(dir)/lib$(1).a),-l:lib$(1).a,))),,-l$(1))
endef

# Function: Use -l:libXXX.a for ml libraries, remaining libraries use -lXXX
define STATIC_LINK_ML_LIBS
$(if $(filter $(1),$(LIBML_FULL) $(LIBNCNN_FULL)),-l:lib$(1).a,-l$(1))
endef

ifeq ($(CONFIG_SAMPLE_DEMO_MPI_STREAM_STATIC_LINK_ALL_LIBS),y)
LINK_LIBS := $(foreach lib,$(LIBS),$(call SELECT_LIB_LINK,$(lib)))
else ifeq ($(CONFIG_SAMPLE_DEMO_MPI_STREAM_STATIC_LINK_ML_LIBS),y)
LIBML_FULL := $(filter ml_%, $(LIBS))
LIBNCNN_FULL := $(filter ncnn%, $(LIBS))
LINK_LIBS := $(foreach lib,$(LIBS),$(call STATIC_LINK_ML_LIBS,$(lib)))
else
LIBML_FULL := $(filter ml_%, $(LIBS))
LIBML_NO_RTOS := $(filter-out %rtos, $(LIBML_FULL))
TARGET_ML_DLIBS := $(patsubst %,lib%.so, $(LIBML_NO_RTOS))
LINK_LIBS := $(addprefix -l,$(LIBS))
endif


# [DON'T TOUCH] calculate corresponding object files and auto-dependencies
OBJS = $(SRCS:.c=.o)
DEPS = $(SRCS:.c=.d)

# sepcify targets
.DEFAULT_GOAL := default

.PHONY: default
default: all

.PHONY: all
all: build

build: $(APP_BIN_DIR)/$(APP_BIN)

.PHONY: check
check:
	@echo $(OBJ_PATH) $(SRC_PATH)
	@echo INCS $(INCS)
	@echo CC $(CC) $(CROSS_COMPILE) $(XTOOL_PATH)
	@echo DEPFLAGS $(DEPFLAGS)
	@echo CFLAGS $(CFLAGS)
	@echo CPPFLAGS $(CPPFLAGS)
	@echo SRCS $(SRCS)
	@echo LIBS $(LIBS)
	@echo OBJS $(OBJS)
	@echo DEPS $(DEPS)
	@echo LIBDIRS $(LIBDIRS)
	@echo LDFLAG $(LDFLAGS)
	@echo LINK_LIBS $(LINK_LIBS)

.PHONY: install
install: install-bin install-config install-assets install-libml install-model

.PHONY: install-bin
install-bin: $(TARGET_BIN_DIR)/$(APP_BIN)

.PHONY: install-config
install-config: | $(TARGET_CONFIG_DIR)
	@printf "  %-8s$(TARGET_CONFIG_DIR)/*\n" "INSTALL"
	$(Q)$(foreach f, $(wildcard $(CONFIG_DIR)/*), \
		cp -r $(f) $(TARGET_CONFIG_DIR)/$(notdir $(f)); \
	)

.PHONY: install-assets
install-assets: | $(TARGET_ASSETS_DIR)
	@printf "  %-8s$(TARGET_ASSETS_DIR)/*.ayuv\n" "INSTALL"
	$(Q)$(foreach f, $(wildcard $(ASSETS_DIR)/*.ayuv), \
		cp -r $(f) $(TARGET_ASSETS_DIR)/$(notdir $(f)); \
	)
	@printf "  %-8s$(TARGET_ASSETS_DIR)/*.imgayuv\n" "INSTALL"
	$(Q)$(foreach f, $(wildcard $(ASSETS_DIR)/*.imgayuv), \
		cp -r $(f) $(TARGET_ASSETS_DIR)/$(notdir $(f)); \
	)
	@printf "  %-8s$(TARGET_ASSETS_DIR)/palette\n" "INSTALL"
	$(Q)$(foreach f, $(wildcard $(ASSETS_DIR)/palette), \
		cp -r $(f) $(TARGET_ASSETS_DIR)/$(notdir $(f)); \
	)

.PHONY: install-libml
install-libml:
	@echo INSTALL $(TARGET_ML_DLIBS)
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

.PHONY: install-model
install-model: $(TARGET_MODELS) | $(MODEL_INSTALL_DIR)
	$(Q)$(foreach f, $(TARGET_MODELS), \
	   printf "  %-8s$(notdir $(f))\n" "INSTALL"; \
	   $(CP) $(f) $(MODEL_INSTALL_DIR)/; \
	)

.PHONY: app-sign
ifeq ($(CONFIG_SAMPLE_DEMO_APPVERIFY),y)
app-sign: $(TARGET_SIGN_DIR)/$(SIGN_BIN)
else
app-sign: ;
endif

.PHONY: uninstall
uninstall: uninstall-model uninstall-libml uninstall-config uninstall-assets
	@printf "  %-8s$(TARGET_BIN_DIR)/$(APP_BIN)\n" "RM"
	$(Q)rm -f $(TARGET_BIN_DIR)/$(APP_BIN)
	$(Q)if [ -d $(TARGET_BIN_DIR) ]; then \
		rmdir --ignore-fail-on-non-empty $(TARGET_BIN_DIR); \
	fi
	$(Q)if [ -d $(SYSTEMFS)/mpp ]; then \
		rmdir --ignore-fail-on-non-empty $(SYSTEMFS)/mpp; \
	fi

.PHONY: uninstall-config
uninstall-config:
	@printf "  %-8s$(TARGET_CONFIG_DIR)\n" "RM"
	$(Q)rm -rf $(TARGET_CONFIG_DIR)

.PHONY: uninstall-assets
uninstall-assets:
	@printf "  %-8s$(TARGET_ASSETS_DIR)\n" "RM"
	$(Q)rm -rf $(TARGET_ASSETS_DIR)

.PHONY: uninstall-libml
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

.PHONY: uninstall-model
uninstall-model:
	$(Q)printf "  %-8s$(MODEL_INSTALL_DIR)\n" "RM"
	$(Q)$(RM) -r $(MODEL_INSTALL_DIR)

.PHONY: clean
clean:
	@printf "  %-8s$(root)\n" "CLEAN"
	$(Q)rm -f $(APP_BIN_DIR)/$(APP_BIN)
	$(Q)find $(root) -name "*.[ado]" -exec rm -f {} \;

.PHONY: distclean
distclean: uninstall clean

# Install the application to 'TARGET_BIN_DIR'
$(TARGET_BIN_DIR)/$(APP_BIN): $(APP_BIN_DIR)/$(APP_BIN) | $(TARGET_BIN_DIR)
	@printf "  %-8s$@\n" "INSTALL"
	$(Q)install -m 777 $< $(dir $@)
ifeq ($(CONFIG_SAMPLE_DEMO_APPVERIFY),y)
	$(Q)ln -nsf $(SECURE_APP_PATH)/$(APP_BIN) $(SYSTEM_BIN)/$(APP_BIN)
	$(Q)$(CROSS_COMPILE)strip --strip-unneeded $(TARGET_BIN_DIR)/$(APP_BIN)
endif

# Sign the application and generate the signature to 'TARGET_SIGN_DIR'
$(TARGET_SIGN_DIR)/$(SIGN_BIN): $(TARGET_BIN_DIR)/$(APP_BIN)
	$(Q)$(SECURE_UTILS)/secure_app_sign.sh "$<" "$@" $(CUSTOM_APP_KEY)
	$(Q)$(SECURE_UTILS)/verify_sign.sh SHA256 "$<" "$@" $(APP_PUB_KEY)

$(APP_BIN_DIR)/$(APP_BIN): $(OBJS)
	@printf "  %-8s$@\n" "CC"
	$(Q)$(CC) $(CFLAGS) $^ -o $@ $(addprefix -L,$(LIBDIRS)) $(LINK_LIBS)

$(TARGET_CONFIG_DIR) \
$(TARGET_ASSETS_DIR) \
$(TARGET_SIGN_DIR) \
$(TARGET_BIN_DIR):
	@printf "  %-8s$@\n" "MKDIR"
	$(Q)mkdir -p $@
$(MODEL_INSTALL_DIR):
	$(Q)$(MKDIR_P) $@

# general directory independent targets
%.o: %.c
	@printf "  %-8s$@\n" "CC"
	$(Q)$(CC) $(CFLAGS) $(addprefix -D,$(DEFS)) $< -c -o $@ $(addprefix -iquote,$(INCS))

# Autodependencies
-include $(DEPS)
