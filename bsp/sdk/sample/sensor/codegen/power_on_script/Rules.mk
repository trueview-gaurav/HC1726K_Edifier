CODEGEN_POWERON_BIN := $(CODEGEN_POWERON_DIR)/codegen_power_on

ifeq ($(SENSOR1),)
# Single sensor
CODEGEN_POWERON_SRCS := $(CODEGEN_POWERON_DIR)/codegen_power_on.c \
                        $(SNS_DIR)/sensor_power_on.c
else
# Dual sensors, use sensor_power_on_dual.c if possible
ifneq ("$(wildcard $(SNS_DIR)/sensor_power_on_dual.c)", "")
CODEGEN_POWERON_SRCS := $(CODEGEN_POWERON_DIR)/codegen_power_on.c \
                        $(SNS_DIR)/sensor_power_on_dual.c
else
CODEGEN_POWERON_SRCS := $(CODEGEN_POWERON_DIR)/codegen_power_on.c \
                        $(SNS_DIR)/sensor_power_on.c
endif

endif

CODEGEN_POWERON_INC := $(CODEGEN_POWERON_DIR)

$(CODEGEN_POWERON_BIN): FORCE
	$(Q)gcc $(CODEGEN_POWERON_SRCS) -o $@ $(CFLAGS) $(addprefix -iquote , $(CODEGEN_POWERON_INC)) $(DEF)
