CC = gcc
SDKSRC_DIR := $(CURDIR)/../../../..

include  $(SDKSRC_DIR)/firmware/build/sdksrc.mk
HDR_OUTPUT_DIR := $(GEN_INC)

V ?= 0
ifeq ($(V),1)
	Q =
else
	Q = @
endif

.PHONY: conf generate-conf build-conf default all install clean

default: all

all: conf

conf: build-conf generate-conf install-conf

build-conf:
	$(Q)$(CC) -O2 -Wall -o conf conf.c

generate-conf:
	@mkdir -p generated
	$(Q)./conf $(FIRMWARE_BUILD_PATH)/.config generated/autoconf.h

install-conf:
	@mkdir -p $(HDR_OUTPUT_DIR)
	$(Q)cp -a generated/* $(HDR_OUTPUT_DIR)/

clean:
	$(Q)rm -rf conf generated

distclean: clean

#$(Q).SILENT:
