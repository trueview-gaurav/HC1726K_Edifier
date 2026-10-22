SDKSRC_DIR ?= $(realpath $(CURDIR)/../../..)
include $(SDKSRC_DIR)/firmware/build/sdksrc.mk
include $(SENSOR_PATH)/common.mk

# TODO: define this path in sdksrc.mk?
SENSOR_KERNEL_DIR := $(SENSOR_PATH)/ksrc
SENSOR_KO_DIR := $(SENSOR_PATH)/ko

CFLAGS = -Wall -g -std=gnu99

# Enumerate sensors
# TODO: iterate sensor definitions indefinitely?
ifneq ($(SENSOR),)
ifeq ($(LENS),)
LENS := DEF
endif
TARGETS := $(shell echo $(SENSOR) | tr '[A-Z]' '[a-z]')/$(shell echo '$(LENS)' | tr '[A-Z]' '[a-z]').0
SNS0 := $(shell echo $(SENSOR) | tr '[A-Z]' '[a-z]')
endif

ifneq ($(SENSOR1),)
ifeq ($(LENS1),)
LENS1 := DEF
endif
TARGETS += $(shell echo $(SENSOR1) | tr '[A-Z]' '[a-z]')/$(shell echo '$(LENS1)' | tr '[A-Z]' '[a-z]').1
SNS1 := $(shell echo $(SENSOR1) | tr '[A-Z]' '[a-z]')
endif

ifneq ($(SENSOR2),)
ifeq ($(LENS2),)
LENS2 := DEF
endif
TARGETS += $(shell echo $(SENSOR2) | tr '[A-Z]' '[a-z]')/$(shell echo '$(LENS2)' | tr '[A-Z]' '[a-z]').2
SNS2 := $(shell echo $(SENSOR2) | tr '[A-Z]' '[a-z]')
endif

ifneq ($(SENSOR3),)
ifeq ($(LENS3),)
LENS3 := DEF
endif
TARGETS += $(shell echo $(SENSOR3) | tr '[A-Z]' '[a-z]')/$(shell echo '$(LENS3)' | tr '[A-Z]' '[a-z]').3
SNS3 := $(shell echo $(SENSOR3) | tr '[A-Z]' '[a-z]')
endif

TARGET_MODS := sensor.ko

TARGETS_INSTALL := $(addsuffix -install, $(TARGETS))
TARGETS_UNINSTALL := $(addsuffix -uninstall, $(TARGETS))
TARGETS_CLEAN :=  $(addsuffix -clean, $(TARGETS))

.PHONY : default
default: all

.PHONY : all
all: clean lib uboot-header-install
ifeq ($(or $(CONFIG_SAPPORO),$(CONFIG_KAMO),$(CONFIG_OSAKA)),y)
all: ko
endif

.PHONY: lib
lib: $(TARGETS)
ifneq ($(SNS0),)
	$(Q)ln -sf libsensor_0_$(SNS0).so lib/libsensor_0.so
endif
ifneq ($(SNS1),)
	$(Q)ln -sf libsensor_1_$(SNS1).so lib/libsensor_1.so
endif
ifneq ($(SNS2),)
	$(Q)ln -sf libsensor_2_$(SNS2).so lib/libsensor_2.so
endif
ifneq ($(SNS3),)
	$(Q)ln -sf libsensor_3_$(SNS3).so lib/libsensor_3.so
endif

.PHONY: $(TARGETS)
$(TARGETS):
	$(Q)mkdir -p $(SENSOR_PATH)/gen_inc
	$(Q)mkdir -p $(LIBSENSOR_LIB)
	$(Q)$(MAKE) -C $(dir $@) all SNS_ARGU='$(notdir $@)'

.PHONY: $(TARGETS_INSTALL)
$(TARGETS_INSTALL):%-install:
	$(eval TMP := $(patsubst %/,%,$(dir $(subst -install,,$@))))
	$(eval ID := $(subst .,,$(suffix $(subst -install,,$@))))
	$(Q)$(MAKE) -C $(TMP) install SNS_ARGU='$(notdir $(subst -install,,$@))'
	$(Q)ln -sf sensor_$(ID)_$(TMP).ini $(TARGET_SCRIPT_DIR)/sensor_$(ID).ini
	$(Q)if [ -e '$(TARGET_SCRIPT_DIR)/sensor_light_$(ID)_$(TMP).ini' ]; then\
	    ln -sf sensor_light_$(ID)_$(TMP).ini $(TARGET_SCRIPT_DIR)/sensor_light_$(ID).ini; \
	    fi
	$(Q)if [ -e '$(TARGET_SCRIPT_DIR)/sensor_ir_$(ID)_$(TMP).ini' ]; then\
	    ln -sf sensor_ir_$(ID)_$(TMP).ini $(TARGET_SCRIPT_DIR)/sensor_ir_$(ID).ini; \
	    fi
	$(Q)if [ -e '$(TARGET_SCRIPT_DIR)/dip_extend_$(ID)_$(TMP).ini' ]; then\
	    ln -sf dip_extend_$(ID)_$(TMP).ini $(TARGET_SCRIPT_DIR)/dip_extend_$(ID).ini; \
	    fi
	$(Q)if [ -e '$(TARGET_SCRIPT_DIR)/dip_extend_ir_$(ID)_$(TMP).ini' ]; then\
	    ln -sf dip_extend_ir_$(ID)_$(TMP).ini $(TARGET_SCRIPT_DIR)/dip_extend_ir_$(ID).ini; \
	    fi
	$(Q)if [ -e '$(TARGET_SCRIPT_DIR)/dip_extend_light_$(ID)_$(TMP).ini' ]; then\
	    ln -sf dip_extend_light_$(ID)_$(TMP).ini $(TARGET_SCRIPT_DIR)/dip_extend_light_$(ID).ini; \
	    fi
	$(Q)if [ -e '$(TARGET_SCRIPT_DIR)/pca_cal_$(ID)_$(TMP).lut' ]; then\
	    ln -sf 'pca_cal_$(ID)_$(TMP).lut' '$(TARGET_SCRIPT_DIR)/pca_cal_$(ID).lut'; \
	    fi
	$(Q)if [ -e '$(TARGET_SCRIPT_DIR)/lsc_cal_$(ID)_$(TMP).lut' ]; then\
	    ln -sf 'lsc_cal_$(ID)_$(TMP).lut' '$(TARGET_SCRIPT_DIR)/lsc_cal_$(ID).lut'; \
		fi

.PHONY: $(TARGETS_UNINSTALL)
$(TARGETS_UNINSTALL):
	$(eval TMP := $(patsubst %/,%,$(dir $(subst -uninstall,,$@))))
	$(eval ID := $(subst .,,$(suffix $(subst -install,,$@))))
	$(Q)$(MAKE) -C $(TMP) uninstall SNS_ARGU='$(notdir $(subst -uninstall,,$@))'

.PHONY: $(TARGETS_CLEAN)
$(TARGETS_CLEAN):%-clean:
	$(eval TMP := $(patsubst %/,%,$(dir $(subst -clean,,$@))))
	$(Q)$(MAKE) -C $(TMP) clean SNS_ARGU='$(notdir $(subst -clean,,$@))'

# sensor.ko is set as a PHONY target, so it will always call the Makefile in ksrc/ to check the dependency
.PHONY: ko
ko:
	$(Q)mkdir -p $(SENSOR_KO_DIR)
	$(Q)$(MAKE) -C $(SENSOR_KERNEL_DIR)

.PHONY: ko-install
ko-install:
	$(Q)install -d $(CUSTOM_LIB)
	$(Q)install -m 0644 $(addprefix $(SENSOR_KO_DIR)/,$(TARGET_MODS)) $(CUSTOM_LIB)

.PHONY: ko-uninstall
ko-uninstall:
	$(Q)rm -f $(addprefix $(CUSTOM_LIB)/,$(TARGET_MODS))

.PHONY: ko-clean
ko-clean:
	$(Q)$(MAKE) -C $(SENSOR_KERNEL_DIR) clean
	$(Q)rm -rf $(SENSOR_KO_DIR)

UBOOT_SENSOR_DEF_TARGET := '$(UBOOT_PATH)/include/sensor_def.h'

.PHONY: uboot-header-install
uboot-header-install:
	$(Q):> $(SENSOR_PATH)/gen_inc/sensor_def.h
	$(Q)for f in $(SENSOR_PATH)/gen_inc/sensor_def_*.h; do \
		cat "$$f" >> $(SENSOR_PATH)/gen_inc/sensor_def.h; \
	done
ifeq ($(CONFIG_FASTBOOT),y)
	$(Q)cp -f $(SENSOR_PATH)/gen_inc/sensor_def.h $(UBOOT_SENSOR_DEF_TARGET)
endif

.PHONY: install
ifeq ($(or $(CONFIG_SAPPORO),$(CONFIG_KAMO),$(CONFIG_OSAKA)),y)
install: all uninstall $(TARGETS_INSTALL) ko-install
else
install: all uninstall $(TARGETS_INSTALL)
endif
	$(Q)install -d $(CUSTOM_LIB)
	$(Q)cp -P lib/* $(CUSTOM_LIB)

.PHONY: uninstall
ifeq ($(or $(CONFIG_SAPPORO),$(CONFIG_KAMO),$(CONFIG_OSAKA)),y)
uninstall: $(TARGETS_UNINSTALL) ko-uninstall
else
uninstall: $(TARGETS_UNINSTALL)
endif
	$(Q)rm -rf $(SENSOR_PATH)/gen_inc
	$(Q)rm -rf $(CUSTOM_LIB)/libsensor*.so

.PHONY: clean
ifeq ($(or $(CONFIG_SAPPORO),$(CONFIG_KAMO),$(CONFIG_OSAKA)),y)
clean: uninstall $(TARGETS_CLEAN) ko-clean
else
clean: uninstall $(TARGETS_CLEAN)
endif
	$(Q)rm -rf $(LIBSENSOR_LIB)
	$(Q)rm -rf $(SENSOR_PATH)/ko
	$(Q)if [ -e $(UBOOT_SENSOR_DEF_TARGET) ]; then \
		rm -rf $(UBOOT_SENSOR_DEF_TARGET); \
	fi
