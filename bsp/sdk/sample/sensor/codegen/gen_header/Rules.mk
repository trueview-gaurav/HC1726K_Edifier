CODEGEN_HEADER_BIN := $(CODEGEN_HEADER_DIR)/codegen_header

CODEGEN_HEADER_SRCS := $(CODEGEN_HEADER_DIR)/gen_header.c \
                       $(CURDIR)/sensor_ctrl.c \
                       $(CURDIR)/sensor_cmos.c \
                       $(SENSOR_PATH)/sensor.c

CODEGEN_HEADER_INC := $(INC) \
                      -iquote$(MPP_INC)

CODEGEN_HEADER_TARGETS := $(HEADER_SENSOR_DIR)/sensor_ctrl.c \
                          $(HEADER_SENSOR_DIR)/sensor_cmos.c \
                          $(HEADER_SENSOR_DIR)/sensor_params.h \
                          $(HEADER_SENSOR_DIR)/sensor_settings.h \
                          $(HEADER_SENSOR_DIR)/sensor_power_on.c

$(CODEGEN_HEADER_BIN): FORCE
	$(Q)gcc $(CODEGEN_HEADER_SRCS) -o $@ $(CFLAGS) $(CODEGEN_HEADER_INC) $(DEF)
