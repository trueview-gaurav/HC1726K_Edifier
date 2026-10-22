# Copyright Augentix Inc. Proprietary and confidential.
# Unauthorized use or distribution is prohibited.
# Please contact customer.support@augentix.com for any inquiries.

PLATFORM_FLAVOR ?= augentix

include core/arch/arm/cpu/cortex-a7.mk

$(call force,CFG_TEE_CORE_NB_CORE,2)
$(call force,CFG_ARM32_core,y)
$(call force,CFG_GIC,y)
$(call force,CFG_AGTX_UART,y)
$(call force,CFG_AGTX_TRNG,y)
$(call force,CFG_AGTX_MONO_COUNT,y)
$(call force,CFG_AGTX_SPI_DRIVERS,y)
ifeq ($(CFG_FLASH_NAND),y)
$(call force,CFG_AGTX_SPI_NAND_DRIVERS,y)
endif
ifeq ($(CFG_FLASH_NOR),y)
$(call force,CFG_AGTX_SPI_NOR_DRIVERS,y)
endif
$(call force,CFG_AGTX_CRYPTO_DRIVER,y)
$(call force,CFG_WITH_SOFTWARE_PRNG,n)
$(call force,CFG_SECURE_TIME_SOURCE_REE,y)

$(call force,CFG_SECONDARY_INIT_CNTFRQ,y)
$(call force,CFG_PSCI_ARM32,y)
$(call force,CFG_WITH_PAGER,n)
ifeq ($(CFG_SM_PLATFORM_HANDLER),y)
$(call force,CFG_IDENTITY_MAPPING,y)
endif

ifeq ($(CFG_SM_PLATFORM_SUSPEND),y)
ifneq ($(CFG_SM_PLATFORM_HANDLER),y)
$(error CFG_SM_PLATFORM_SUSPEND=y requires CFG_SM_PLATFORM_HANDLER=y)
endif
endif

# AOV uses SRAM identity mapping
ifeq ($(CFG_SM_PLATFORM_SUSPEND),y)
$(call force,CFG_IDENTITY_MAPPING,y)
endif

CFG_TZC400 ?= y
CFG_BOOT_SECONDARY_REQUEST ?= y
CFG_HW_UNQ_KEY_SUPPORT ?= y
# CFG_ENABLE_SCTLR_RR ?= y
CFG_TEE_VERSION ?= 0
CFG_INSECURE ?= n
ta-targets = ta_arm32
