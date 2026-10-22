SDKSRC_DIR ?= $(realpath $(CURDIR)/../../../..)
include $(SDKSRC_DIR)/firmware/build/sdksrc.mk
include $(APP_PATH)/internal.mk

TARGET_BIN_PATH=$(CUSTOMFS)/bin

CC=$(CROSS_COMPILE)gcc
AR=$(CROSS_COMPILE)ar

INC :=
CFLAGS += -MMD $(INC)

BIN=fasync_user
SRCS:=fasync_user.c
OBJS=$(patsubst %.c,%.o,$(SRCS))
DEPS=$(patsubst %.c,%.d,$(SRCS))

BIN2=custom_msg
SRCS2:=custom_msg.c
OBJS2=$(patsubst %.c,%.o,$(SRCS2))
DEPS2=$(patsubst %.c,%.d,$(SRCS2))

.PHONY : all
all: $(BIN) $(BIN2)

$(BIN): $(OBJS)
	$(Q)$(CC) -o $@ $^

$(BIN2): $(OBJS2)
	$(Q)$(CC) -o $@ $^

sinclude $(DEPS)

%.o: %.c
	$(Q)$(CC) -c $(CFLAGS) -o $@ $<

.PHONY : install
install: all
	$(Q)mkdir -p $(TARGET_BIN_PATH)
	$(Q)cp -f $(BIN) $(TARGET_BIN_PATH)
	$(Q)cp -f $(BIN2) $(TARGET_BIN_PATH)

.PHONY : uninstall
uninstall:
	$(Q)rm -f $(TARGET_BIN_PATH)/$(BIN)
	$(Q)rm -f $(TARGET_BIN_PATH)/$(BIN2)

.PHONY: clean
clean:
	$(Q)find . -type f -name "*.[doa]" -exec rm -f {} \;
	$(Q)rm -f $(BIN)
	$(Q)rm -f $(BIN2)

.PHONY: distclean
distclean: uninstall clean
