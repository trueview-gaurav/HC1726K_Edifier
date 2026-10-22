SDKSRC_DIR ?= $(realpath $(CURDIR)/../../../../../..)
include $(SDKSRC_DIR)/firmware/build/sdksrc.mk

# utils
MAKE := make
CP := cp
LN := ln
MKDIR := mkdir
MKDIR_P := $(MKDIR) -p
MV := mv
RM := rm -f

LIB_NAME = libmetal.a
LIB_OUT_PATH = $(LIBMETAL_SRC_PATH)/build/freertos/lib

.PHONY: default
default: all

.PHONY: linux-build
linux-build:
ifeq ("$(wildcard ./linux/Makefile)","")
	cmake .. -B ./linux -DCMAKE_TOOLCHAIN_FILE=../../hc21xx_linux.cmake
endif
	@echo build libmetal for Linux environment
	$(Q)$(MAKE) -C linux

.PHONY: linux-clean
linux-clean:
ifneq ("$(wildcard ./linux/Makefile)","")
	@echo clean libmetal for Linux environment
	$(Q)$(MAKE) -C linux -j clean
endif


.PHONY: rtos-build
rtos-build:
ifeq ("$(wildcard ./freertos/Makefile)","")
	cmake .. -B ./freertos -DCMAKE_TOOLCHAIN_FILE=../../hc21xx_freertos.cmake
endif
	@echo build libmetal for FreeRTOS environment
	$(Q)$(MAKE) -C freertos

.PHONY: rtos-clean
rtos-clean:
ifneq ("$(wildcard ./freertos/Makefile)","")
	@echo clean libmetal for FreeRTOS environment
	$(Q)$(MAKE) -C freertos -j clean
endif



.PHONY: all
all: rtos-build

.PHONY: clean
clean: rtos-clean

.PHONY: install
install: all

.PHONY: uninstall
uninstall:


.PHONY: distclean
distclean: clean uninstall
	$(Q)$(RM) -r freertos
