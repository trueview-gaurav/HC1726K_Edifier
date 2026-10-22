SDKSRC_DIR ?= $(realpath $(CURDIR)/../../../../../..)
include $(SDKSRC_DIR)/firmware/build/sdksrc.mk
APP_PATH=$(SDK_PATH)/application
EAIF_PATH=$(APP_PATH)/library/libeaif
INF_PATH=$(APP_PATH)/library/libinf
CC=gcc

INCS=\
-I$(INF_PATH)/src/inc \
-I$(EAIF_PATH)/src \
-I$(EAIF_PATH)/include \
-I$(MPP_INC)


BINS=test
SRCS=ut.c \
$(wildcard $(EAIF_PATH)/src/*.c) \
$(wildcard $(EAIF_PATH)/test/src/fake/*.c)

CFLAGS=-Wall -g $(INCS) -std=gnu99 -D_GNU_SOURCE -pthread

.PHONY: all
all:
	$(CC) -o $(BINS) $(SRCS) $(CFLAGS) -Wno-unused

.PHONY: clean
clean:
	rm -rf $(BINS)
