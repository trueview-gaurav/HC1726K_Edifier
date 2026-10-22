# Copyright Augentix Inc. Proprietary and confidential.
# Unauthorized use or distribution is prohibited.
# Please contact customer.support@augentix.com for any inquiries.

# MPP Shared Build Configuration
# -------------------------------------------------------------------------
#
# This file contains shared build variables and settings used across all
# Makefiles in mpp/, including both user space library and kernel module.
#
# Variables defined here can be used in both top-level builds and local
# builds. To use it, just include this file in any Makefile with:
#      include $(SDKSRC_DIR)/build/sdksrc.mk
#      include $(MPP_BUILD_PATH)/common.mk
#

# Chip Model Selection
# -------------------------------------------------------------------------

ifeq ($(CONFIG_HC1703_1723_1753_1783S),y)
CHIP_DIR := kyoto
DEFINE_ALL := HC17X3_SPECIFIC
else ifeq ($(CONFIG_SAPPORO),y)
CHIP_DIR := sapporo
DEFINE_ALL := HC17X6_SPECIFIC
else ifeq ($(CONFIG_KAMO),y)
CHIP_DIR := kamo
DEFINE_ALL := HC17X5L_SPECIFIC
else ifeq ($(CONFIG_OSAKA),y)
CHIP_DIR := osaka
DEFINE_ALL := HC1785_SPECIFIC
else
#error
endif

# Debug Features
# -------------------------------------------------------------------------

# MPI_DEV_DISABLE_DIP := y

# Debug Feature Enabling Warnings
# -------------------------------------------------------------------------

ifndef _COMMON_MK_DEBUG_SHOWN
ifdef MPI_DEV_DISABLE_DIP
$(warning ***********************************)
$(warning *  DIP is disabled for debugging  *)
$(warning ***********************************)
endif
export _COMMON_MK_DEBUG_SHOWN := 1
endif
