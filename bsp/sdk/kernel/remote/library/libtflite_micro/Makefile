SDKSRC_DIR ?= $(realpath $(CURDIR)/../../../../..)
include $(SDKSRC_DIR)/firmware/build/sdksrc.mk
include $(REMOTE_PATH)/internal.mk

MICROLITE_BUILD_PATH = build_microlite

TENSORFLOW_MICROLITE_MAKE_OPTS := \
	root=$(BUILDROOT_OUTPUT_BUILD_PATH)/tensorflow-2.6.0 \
	MICROLITE_BUILD_PREFIX=$(MICROLITE_BUILD_PATH) \
	TENSORFLOW_MICROLITE_TARGET=ARM \
	MICROLITE_OPTIMIZED_KERNEL_DIR=cmsis_nn \
	FREERTOS_DIR=$(FREERTOS_PATH)

.DEFAULT_GOAL := default

.PHONY: default
default: all

.PHONY: all
all:
	make -f Makefile.micro $(TENSORFLOW_MICROLITE_MAKE_OPTS) all V=1

.PHONY: clean
clean:
	rm -rf $(MICROLITE_BUILD_PATH)

.PHONY: distclean
distclean: uninstall clean

.PHONY: install
install: all

.PHONY: uninstall
uninstall: ;

