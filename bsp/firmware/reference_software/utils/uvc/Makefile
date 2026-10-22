SDKSRC_DIR ?= $(realpath $(CURDIR)/../../../..)
include $(SDKSRC_DIR)/firmware/build/sdksrc.mk
include $(APP_PATH)/internal.mk
include $(SAMPLE_DEMO_PATH)/internal.mk

CONFIG_FILE = $(SDKSRC_DIR)/firmware/reference_software/.config
-include $(CONFIG_FILE)

LN := ln
CC = $(CROSS_COMPILE)gcc

UVC_INC:=$(KERNEL_PATH)/drivers/usb/gadget/function
INC := -I./include -I$(MPP_INC) -I$(UVC_INC) -I$(APP_INC) -I$(GEN_INC) -I$(DEBUG_INC) \
	-I$(LIBCM_INC) -isystem$(JSON_INC) -I$(CENTCTRL_INC) -I$(LIBAGTX_INC)
CFLAGS += -MMD $(INC)
LDFLAGS := -L$(MPP_LIB) -L$(DEBUG_PATH) -L$(LIBCM_PATH) -L$(JSON_LIB)
LDLIBS := -lmpp -lrt -lcm -ljson-c -pthread -lm -lstdc++

BIN = uvcd
SRCS := $(wildcard ./*.c)
OBJS = $(patsubst %.c,%.o,$(SRCS))
DEST := $(SYSTEM_BIN)
INSTALL_TRGT := $(addprefix $(DEST)/, $(BIN))
CAP_H = include/agtx_webcam_cap.h

.PHONY: all
all: $(BIN)

$(BIN): $(OBJS)
	$(Q)$(CC) -o $@ $^ $(LDFLAGS) $(LDLIBS)

#sinclude $(DEPS)

ifeq ($(CONFIG_WEBCAM_CAP_FIXED),y)
CFLAGS += -DCONFIG_WEBCAM_CAP_FIXED

%.o: %.c $(CONFIG_FILE) $(CAP_H)
	$(Q)$(CC) -c $(CFLAGS) -o $@ $<

$(CAP_H):
	$(Q)$(LN) -sf caps/webcam_cap_$(CONFIG_MACH).h include/agtx_webcam_cap.h
else
%.o: %.c $(CONFIG_FILE)
	$(Q)$(CC) -c $(CFLAGS) -o $@ $<
endif

.PHONY: install
install: all $(DEST) $(INSTALL_TRGT)

$(DEST):
	$(Q)install -d $@

$(DEST)/%: %
	$(Q)install -m 777 $< $@

.PHONY: uninstall
uninstall:
	$(Q)rm -f $(INSTALL_TRGT)

.PHONY: clean
clean:
	$(Q)find . -type f -name "*.[doa]" -exec rm -f {} \;
	$(Q)rm -f $(BIN) $(CAP_H)

.PHONY: distclean
distclean: uninstall clean
