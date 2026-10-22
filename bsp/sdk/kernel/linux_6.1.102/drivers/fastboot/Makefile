#
# Makefile for the fast boot device drivers.
#
SDKSRC_DIR := $(realpath $(CURDIR)/../../..)

include $(SDKSRC_DIR)/firmware/build/sdksrc.mk

obj-y                           += augentix-earlyvideo.o
ccflags-y += -I$(GEN_INC)

obj-y                           += earlyaudio.o
