SDKSRC_DIR ?= $(realpath $(CURDIR)/../../../..)
include $(SDKSRC_DIR)/firmware/build/sdksrc.mk
include $(SENSOR_PATH)/common.mk
include $(SENSOR_PATH)/i2c_list.mk
UBOOT_SENSOR_DIR := $(UBOOT_PATH)/drivers/sensor

ifeq ($(CONFIG_UCLIBC),y)
XTOOL_PATH := $(XTOOL_PATH_2)
CROSS_COMPILE := $(CROSS_COMPILE_2)
endif
AR := $(CROSS_COMPILE)ar
CC := $(CROSS_COMPILE)gcc

# $(SNS) is an input argument from Makefile
# if lens is not specified, use the first lens in the lens list
LNS := $(notdir $(firstword $(wildcard lens/*)))
SNS_ID := 0
SNS := $(notdir $(CURDIR))
MB := $(shell echo $(MOTHERBOARD) | tr '[A-Z]' '[a-z]')
SNS_DIR := $(CURDIR)/$(SNS)_$(MB)

# Codegen paths
CODEGEN_HEADER_DIR := $(SENSOR_PATH)/codegen/gen_header
CODEGEN_POWERON_DIR := $(SENSOR_PATH)/codegen/power_on_script
CODEGEN_UBOOT_DIR := $(SENSOR_PATH)/codegen/uboot
CODEGEN_KERNEL_DIR := $(SENSOR_PATH)/codegen/kernel_module

# default INI file, and the definition may be changed in $(SNS_DIR)/sensor.mk
# for different applications, for example, dual-lens stitching case
SNS_INI := sensor_single.ini
SNS_IR_INI := sensor_single_ir.ini
SNS_LIGHT_INI := sensor_single_light.ini
DIP_EXTEND_INI := dip_extend.ini
DIP_EXTEND_IR_INI := dip_extend_ir.ini
DIP_EXTEND_LIGHT_INI := dip_extend_light.ini
PCA_LUT := pca_cal.lut
LSC_LUT := lsc_cal.lut

# parser argument
ifneq ($(SNS_ARGU),)
SNS_ID := $(subst .,,$(suffix $(SNS_ARGU)))
ifneq ("$(basename $(SNS_ARGU))","def")
LNS := $(basename $(SNS_ARGU))
endif
endif

# you can overwrite files or I2C device in sensor.mk
ifneq ($(strip $(wildcard $(SNS_DIR)/sensor.mk)),)
include $(SNS_DIR)/sensor.mk
endif

# file enumerations for ini, LSC table and PCA table
L_SNS_INI := l_sensor_$(SNS_ID).ini
T_SNS_INI := sensor_$(SNS_ID)_$(SNS).ini
L_SNS_IR_INI := l_sensor_ir_$(SNS_ID).ini
T_SNS_IR_INI := sensor_ir_$(SNS_ID)_$(SNS).ini
L_SNS_LIGHT_INI := l_sensor_light_$(SNS_ID).ini
T_SNS_LIGHT_INI := sensor_light_$(SNS_ID)_$(SNS).ini
L_DIP_EXTEND_INI := l_dip_extend_$(SNS_ID).ini
T_DIP_EXTEND_INI := dip_extend_$(SNS_ID)_$(SNS).ini
L_DIP_EXTEND_IR_INI := l_dip_extend_ir_$(SNS_ID).ini
T_DIP_EXTEND_IR_INI := dip_extend_ir_$(SNS_ID)_$(SNS).ini
L_DIP_EXTEND_LIGHT_INI := l_dip_extend_light_$(SNS_ID).ini
T_DIP_EXTEND_LIGHT_INI := dip_extend_light_$(SNS_ID)_$(SNS).ini
L_PCA_LUT := l_pca_cal_$(SNS_ID).lut
T_PCA_LUT := pca_cal_$(SNS_ID)_$(SNS).lut
L_LSC_LUT := l_lsc_cal_$(SNS_ID).lut
T_LSC_LUT := lsc_cal_$(SNS_ID)_$(SNS).lut

# If PWR_ON_SCRIPT has already been set by sensor.mk, it will still be the default
# one chosen for the power-on script.
ifneq ($(PWR_ON_SCRIPT),)
ifeq ($(wildcard $(SNS_DIR)/$(PWR_ON_SCRIPT)),)
# Fallback to auto mode if designated power-on script does not exist.
PWR_ON_SCRIPT :=
endif
endif

# Detect and determine the power-on script if it's not given nor exists.
ifeq ($(PWR_ON_SCRIPT),)
ifneq ($(wildcard $(SNS_DIR)/sensor_power_on.sh),)
# Use old-style power on script if possible for compatibility and stability.
PWR_ON_SCRIPT := sensor_power_on.sh
else ifneq ($(wildcard $(SNS_DIR)/sensor_power_on.c),)
# If sensor_power_on.c exists, use it for generating the power-on script.
# The generated script is called auto_sensor_power_on.sh.
PWR_ON_SCRIPT := auto_sensor_power_on.sh
else
# Still use sensor_power_on.sh as default if nothing valid was found,
# but it's most likely that it will fail.
PWR_ON_SCRIPT := sensor_power_on.sh
endif
endif

BIN := libsensor_$(SNS_ID)_$(SNS).so

SRCS = sensor_ctrl.c sensor_cmos.c $(wildcard $(SENSOR_PATH)/*.c)
OBJS = $(patsubst %.c,%.o,$(SRCS))

INC = -iquote . -iquote .. -iquote $(SNS_DIR) -iquote $(MPP_INC)

# lookup the current board name in the i2c board list
# use i2c-0 in default if the board cannot be found
# this logic will only be triggered if it isn't assigned in sensor.mk
ifeq ($(I2C_FLAG),)
ifneq ($(filter $(MOTHERBOARD),$(BOARD_I2C_1)),)
I2C_FLAG += -DSNS_I2C_1
endif
ifneq ($(filter $(MOTHERBOARD),$(BOARD_I2C_0)),)
I2C_FLAG += -DSNS_I2C_0
endif
endif

I2C_FLAG ?= -DSNS_I2C_0


CFLAGS += -DSNS=$(SNS) $(I2C_FLAG)

# The following logic looks like:
# if $(SNS_ID) == 0:
#   CFLAGS += -DSNS0=$(SENSOR) -DSNS0_ID=0
# if $(SNS_ID) == 1:
#   CFLAGS += -DSNS1=$(SENSOR) -DSNS1_ID=1
# if $(SNS_ID) == 2:
#   CFLAGS += -DSNS2=$(SENSOR) -DSNS2_ID=2
# ...
# But it can be used for any # of sensors.
CFLAGS += -DSNS$(SNS_ID)=$(SENSOR) -DSNS$(SNS_ID)_ID=$(SNS_ID)

# fastboot define
ifeq ($(CONFIG_FASTBOOT),y)
CFLAGS += -DCONFIG_FASTBOOT
endif

# secure measurement
ifeq ($(CONFIG_KERNEL_V6_1),y)
LDFLAGS += -Wl,-z,noexecstack
ifeq ($(CONFIG_UCLIBC),y)
CFLAGS += -fstack-protector-strong
endif
endif

.PHONY: default
default: all

.PHONY: all
all: check-sensor $(LIBSENSOR_LIB) header-install
ifneq ($(or $(CONFIG_SAPPORO),$(CONFIG_KAMO),$(CONFIG_OSAKA)),)
all: gen_kernel_src
endif

$(LIBSENSOR_LIB): $(BIN)
	$(Q)mkdir -p $(LIBSENSOR_LIB)
	$(Q)cp -f $(BIN) $(LIBSENSOR_LIB)

include $(CODEGEN_KERNEL_DIR)/Rules.mk

.PHONY: gen_kernel_src
ifeq ($(wildcard *_pm.c),)
gen_kernel_src:
else
gen_kernel_src:	$(CODEGEN_KERNEL_BIN)
	$(Q)$(CODEGEN_KERNEL_BIN) $(SNS_ID) $(SENSOR_PATH)/ksrc $(realpath .)
endif

$(BIN): $(OBJS)
	$(Q)$(CC) $(LDFLAGS) -Wl,--no-whole-archive -shared $^ -o $@

%.o: %.c FORCE
	$(Q)$(CC) $< -c -fPIC -fvisibility=hidden $(CFLAGS) $(DEF) $(INC) -o $@

.PHONY: FORCE
FORCE:

.PHONY : check-sensor
check-sensor:
ifeq ($(SNS),)
	$(error Sensor not specified!);
else
	@echo "SENSOR: $(SNS)"
endif
ifeq ("$(LNS)","")
	$(error "No IQ settings was found in directory '$(CURDIR)/lens/'.")
endif
ifeq ("$(wildcard $(CURDIR)/lens/$(LNS)/sensor_cal.h)","")
	$(error "Cannot find necessary IQ settings under directory '$(CURDIR)/lens/$(LNS)/', please check the settings or the name of the lens.")
else ifeq ("$(wildcard $(CURDIR)/lens/$(LNS)/sensor_single.ini)","")
	$(error "Cannot find necessary IQ settings under directory '$(CURDIR)/lens/$(LNS)/', please check the settings or the name of the lens.")
endif
	$(Q)ln -sfr '$(CURDIR)/lens/$(LNS)/sensor_cal.h' $(SNS_DIR)/l_sensor_cal.h
	$(Q)ln -sfr '$(CURDIR)/lens/$(LNS)/$(SNS_INI)' $(SNS_DIR)/$(L_SNS_INI)
	$(Q)if [ -e '$(CURDIR)/lens/$(LNS)/$(SNS_IR_INI)' ]; then \
	    ln -sfr '$(CURDIR)/lens/$(LNS)/$(SNS_IR_INI)' $(SNS_DIR)/$(L_SNS_IR_INI); \
	    fi
	$(Q)if [ -e '$(CURDIR)/lens/$(LNS)/$(SNS_LIGHT_INI)' ]; then \
	    ln -sfr '$(CURDIR)/lens/$(LNS)/$(SNS_LIGHT_INI)' $(SNS_DIR)/$(L_SNS_LIGHT_INI); \
	    fi
	$(Q)if [ -e '$(CURDIR)/lens/$(LNS)/$(DIP_EXTEND_INI)' ]; then \
	    ln -sfr '$(CURDIR)/lens/$(LNS)/$(DIP_EXTEND_INI)' $(SNS_DIR)/$(L_DIP_EXTEND_INI); \
	    fi
	$(Q)if [ -e '$(CURDIR)/lens/$(LNS)/$(DIP_EXTEND_IR_INI)' ]; then \
	    ln -sfr '$(CURDIR)/lens/$(LNS)/$(DIP_EXTEND_IR_INI)' $(SNS_DIR)/$(L_DIP_EXTEND_IR_INI); \
	    fi
	$(Q)if [ -e '$(CURDIR)/lens/$(LNS)/$(DIP_EXTEND_LIGHT_INI)' ]; then \
	    ln -sfr '$(CURDIR)/lens/$(LNS)/$(DIP_EXTEND_LIGHT_INI)' $(SNS_DIR)/$(L_DIP_EXTEND_LIGHT_INI); \
	    fi
	$(Q)if [ -e '$(CURDIR)/lens/$(LNS)/$(PCA_LUT)' ]; then \
	    ln -sfr '$(CURDIR)/lens/$(LNS)/$(PCA_LUT)' '$(SNS_DIR)/$(L_PCA_LUT)'; \
	    fi
	$(Q)if [ -e '$(CURDIR)/lens/$(LNS)/$(LSC_LUT)' ]; then \
	    ln -sfr '$(CURDIR)/lens/$(LNS)/$(LSC_LUT)' '$(SNS_DIR)/$(L_LSC_LUT)'; \
		fi


SEARCH_TEXT := table.table_coeff_file_path *=
REPLACE_TEXT := table.table_coeff_file_path = /system/mpp/script/$(T_LSC_LUT)

.PHONY : install
install: power_on-install
	$(Q)mkdir -p $(TARGET_SCRIPT_DIR)
	$(Q)cp -f $(SNS_DIR)/$(L_SNS_INI) $(TARGET_SCRIPT_DIR)/$(T_SNS_INI)
	$(Q)if [ -e "$(SNS_DIR)/$(L_SNS_IR_INI)" ]; then \
	    cp -f $(SNS_DIR)/$(L_SNS_IR_INI) $(TARGET_SCRIPT_DIR)/$(T_SNS_IR_INI); \
	    fi
	$(Q)if [ -e "$(SNS_DIR)/$(L_SNS_LIGHT_INI)" ]; then \
	    cp -f $(SNS_DIR)/$(L_SNS_LIGHT_INI) $(TARGET_SCRIPT_DIR)/$(T_SNS_LIGHT_INI); \
	    fi
	$(Q)if [ -e "$(SNS_DIR)/$(L_DIP_EXTEND_INI)" ]; then \
	    cp -f $(SNS_DIR)/$(L_DIP_EXTEND_INI) $(TARGET_SCRIPT_DIR)/$(T_DIP_EXTEND_INI); \
	    fi
	$(Q)if [ -e "$(SNS_DIR)/$(L_DIP_EXTEND_IR_INI)" ]; then \
	    cp -f $(SNS_DIR)/$(L_DIP_EXTEND_IR_INI) $(TARGET_SCRIPT_DIR)/$(T_DIP_EXTEND_IR_INI); \
	    fi
	$(Q)if [ -e "$(SNS_DIR)/$(L_DIP_EXTEND_LIGHT_INI)" ]; then \
	    cp -f $(SNS_DIR)/$(L_DIP_EXTEND_LIGHT_INI) $(TARGET_SCRIPT_DIR)/$(T_DIP_EXTEND_LIGHT_INI); \
	    fi
	$(Q)if [ -e '$(SNS_DIR)/$(L_PCA_LUT)' ]; then \
	    cp -f '$(SNS_DIR)/$(L_PCA_LUT)' '$(TARGET_SCRIPT_DIR)/$(T_PCA_LUT)'; \
	    fi
# Copy lsc table to target dir and update lsc table filepath in dip_extend file
	$(Q)if [ -e '$(SNS_DIR)/$(L_LSC_LUT)' ]; then \
	    cp -f '$(SNS_DIR)/$(L_LSC_LUT)' '$(TARGET_SCRIPT_DIR)/$(T_LSC_LUT)'; \
		if [ -e '$(TARGET_SCRIPT_DIR)/$(T_DIP_EXTEND_INI)' ]; then \
			sed -i -e 's@$(SEARCH_TEXT).*@$(REPLACE_TEXT)@g' '$(TARGET_SCRIPT_DIR)/$(T_DIP_EXTEND_INI)'; \
			fi; \
		if [ -e '$(TARGET_SCRIPT_DIR)/$(T_DIP_EXTEND_IR_INI)' ]; then \
			sed -i -e 's@$(SEARCH_TEXT).*@$(REPLACE_TEXT)@g' '$(TARGET_SCRIPT_DIR)/$(T_DIP_EXTEND_IR_INI)'; \
			fi; \
		if [ -e '$(TARGET_SCRIPT_DIR)/$(T_DIP_EXTEND_LIGHT_INI)' ]; then \
			sed -i -e 's@$(SEARCH_TEXT).*@$(REPLACE_TEXT)@g' '$(TARGET_SCRIPT_DIR)/$(T_DIP_EXTEND_LIGHT_INI)'; \
			fi; \
	    fi

# Make Makefile be able to compile auto_sensor_power_on.sh if it's required
.PHONY: power_on-install
power_on-install: $(SNS_DIR)/$(PWR_ON_SCRIPT)
	$(Q)mkdir -p $(TARGET_SCRIPT_DIR)
	$(Q)cp -f $(SNS_DIR)/$(PWR_ON_SCRIPT) $(TARGET_SCRIPT_DIR)/sensor_power_on_$(SNS).sh

.PHONY : uninstall
uninstall:
	$(Q)rm -f $(TARGET_SCRIPT_DIR)/sensor_*.ini
	$(Q)rm -f $(TARGET_SCRIPT_DIR)/dip_extend_*.ini
	$(Q)rm -f '$(TARGET_SCRIPT_DIR)'/pca_cal_*.lut
	$(Q)rm -f $(TARGET_SCRIPT_DIR)/lsc_cal_*.lut
	$(Q)rm -f $(TARGET_SCRIPT_DIR)/sensor_power_on_*.sh
	$(Q)rm -f $(LIBSENSOR_LIB)/$(BIN)
	$(Q)if [ -d "$(LIBSENSOR_LIB)" ]; then rmdir --ignore-fail-on-non-empty $(LIBSENSOR_LIB); fi
	$(Q)rm -rf $(SENSOR_PATH)/gen_inc
	$(Q)rm -f $(CODEGEN_UBOOT_TARGETS)

.PHONY : clean
clean:
	$(Q)rm -f "$(SENSOR_PATH)"/*.[ado]
	$(Q)find . -type f -name "*.[oad]" -exec rm -f {} +
	$(Q)rm -f *.so
	$(Q)find . -type l -name "l_sensor_*" -exec rm -f {} +
	$(Q)find . -type l -name "l_dip_extend_*" -exec rm -f {} +
	$(Q)find . -type l -name "l_pca_cal_*.lut" -exec rm -f {} +
	$(Q)find . -type l -name "l_lsc_cal_*.lut" -exec rm -f {} +
	$(Q)find . -type f -name "auto_sensor_power_on.sh" -exec rm -f {} +
	$(Q)rm -f $(CODEGEN_HEADER_BIN)
	$(Q)rm -f $(CODEGEN_POWERON_BIN)
	$(Q)rm -f $(CODEGEN_UBOOT_BIN)
	$(Q)rm -f $(CODEGEN_KERNEL_BIN)
	$(Q)rm -f $(SENSOR_KERNEL_DIR)/sensor_pm_sns*.c

# Codegen
include $(CODEGEN_HEADER_DIR)/Rules.mk
include $(CODEGEN_POWERON_DIR)/Rules.mk
include $(CODEGEN_UBOOT_DIR)/Rules.mk

ifeq ($(SENSOR1), )
POWER_ON_C_PATH = $(SNS_DIR)/sensor_power_on.c
else
POWER_ON_C_PATH = $(SNS_DIR)/sensor_power_on_dual.c
endif

# Generate header files for Early Video Driver
.PHONY: header-install
header-install: $(CODEGEN_HEADER_BIN)
	$(Q)mkdir -p $(SENSOR_PATH)/gen_inc
	$(Q)$(CODEGEN_HEADER_BIN) $(SENSOR_PATH)/gen_inc/sensor_def_$(SNS_ID).h $(SNS_ID)

# Generate power on script
$(SNS_DIR)/auto_sensor_power_on.sh: $(CODEGEN_POWERON_BIN) FORCE
	$(Q)$(CODEGEN_POWERON_BIN) $(SNS) $@

# Install required files for uboot sensor driver
ifeq ($(CONFIG_FASTBOOT),y)
all: uboot-install
endif

.PHONY: uboot-install
uboot-install: $(CODEGEN_UBOOT_BIN)
	$(Q)ln -sfr $(POWER_ON_C_PATH) $(UBOOT_SENSOR_DIR)/sensor_power_on.c
	$(Q)$(CODEGEN_UBOOT_BIN) $(UBOOT_SENSOR_DIR)
	$(Q)if [ -e '$(UBOOT_SENSOR_DIR)/sensor_params.h' ]; then \
		ln -sfr $(UBOOT_SENSOR_DIR)/sensor_params.h $(UBOOT_PATH)/include/sensor_params.h;\
	fi
	$(Q)if [ -e '$(UBOOT_SENSOR_DIR)/sensor_params_1.h' ]; then \
		ln -sfr $(UBOOT_SENSOR_DIR)/sensor_params_1.h $(UBOOT_PATH)/include/sensor_params_1.h;\
	fi

