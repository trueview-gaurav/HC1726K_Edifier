SENSOR_NUM :=1
ifneq ($(SENSOR1),)
SENSOR_NUM := 2
endif

CODEGEN_UBOOT_BIN := $(CODEGEN_UBOOT_DIR)/codegen_uboot

CODEGEN_UBOOT_SRCS := $(CODEGEN_UBOOT_DIR)/codegen_uboot.c \
                      $(CODEGEN_UBOOT_DIR)/function_wrapper.c \
                      $(CODEGEN_UBOOT_DIR)/write_file.c \
                      $(CURDIR)/sensor_ctrl.c \
                      $(CURDIR)/sensor_cmos.c

CODEGEN_UBOOT_INC := $(CODEGEN_UBOOT_DIR) \
                     $(SENSOR_PATH) \
                     $(CURDIR) \
                     '$(CURDIR)/lens/$(LNS)' \
                     $(SNS_DIR) \
                     $(MPP_INC)

CODEGEN_UBOOT_TARGETS := $(UBOOT_SENSOR_DIR)/sensor_ctrl.c \
                         $(UBOOT_SENSOR_DIR)/sensor_cmos.c \
                         $(UBOOT_SENSOR_DIR)/sensor_params.h \
                         $(UBOOT_PATH)/include/sensor_params.h \
                         $(UBOOT_SENSOR_DIR)/sensor_settings.h \
                         $(UBOOT_SENSOR_DIR)/sensor_power_on.c \
                         $(UBOOT_SENSOR_DIR)/sensor_cal.h

ifeq ($(SENSOR_NUM), 2)
CODEGEN_UBOOT_TARGETS += $(UBOOT_SENSOR_DIR)/sensor_ctrl_1.c \
                         $(UBOOT_SENSOR_DIR)/sensor_cmos_1.c \
                         $(UBOOT_SENSOR_DIR)/sensor_params_1.h \
                         $(UBOOT_PATH)/include/sensor_params_1.h \
                         $(UBOOT_SENSOR_DIR)/sensor_settings_1.h \
                         $(UBOOT_SENSOR_DIR)/sensor_cal_1.h
endif

$(CODEGEN_UBOOT_BIN): FORCE
	$(Q)gcc $(CODEGEN_UBOOT_SRCS) -o $@ $(CFLAGS) $(addprefix -iquote , $(CODEGEN_UBOOT_INC)) $(DEF) -Wno-unused-variable
