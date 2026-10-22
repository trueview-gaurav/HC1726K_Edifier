CODEGEN_KERNEL_BIN := $(CODEGEN_KERNEL_DIR)/codegen_kernel

CODEGEN_KERNEL_SRCS := $(CODEGEN_KERNEL_DIR)/codegen_kernel.c \
                       $(CODEGEN_KERNEL_DIR)/codegen_kernel_pm.c

CODEGEN_KERNEL_INC := $(INC)

CODEGEN_KERNEL_CFLAGS := -DSENSOR_NAME=$(shell echo $(SNS) | tr '[:upper:]' '[:lower:]')

# TODO: define this path in sdksrc.mk?
SENSOR_KERNEL_DIR := $(SENSOR_PATH)/ksrc

ifeq ($(or $(CONFIG_SAPPORO),$(CONFIG_KAMO),$(CONFIG_OSAKA)),y)
ifeq ($(SNS_ID), 0)
CODEGEN_KERNEL_TARGETS := $(SENSOR_KERNEL_DIR)/sensor_pm_sns0.c
endif
ifeq ($(SNS_ID), 1)
CODEGEN_KERNEL_TARGETS := $(SENSOR_KERNEL_DIR)/sensor_pm_sns1.c
endif
ifeq ($(SNS_ID), 2)
CODEGEN_KERNEL_TARGETS := $(SENSOR_KERNEL_DIR)/sensor_pm_sns2.c
endif
ifeq ($(SNS_ID), 3)
CODEGEN_KERNEL_TARGETS := $(SENSOR_KERNEL_DIR)/sensor_pm_sns3.c
endif
endif

$(CODEGEN_KERNEL_BIN): FORCE
	$(Q)gcc $(CODEGEN_KERNEL_SRCS) -o $@ $(CFLAGS) $(CODEGEN_KERNEL_CFLAGS) $(CODEGEN_KERNEL_INC)
