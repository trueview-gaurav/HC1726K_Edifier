# SPDX-License-Identifier: GPL-2.0+
#
# Copyright (C) 2015 Samsung Electronics
# Przemyslaw Marczak <p.marczak@samsung.com>
#

obj-$(CONFIG_$(PHASE_)ADC) += adc-uclass.o
obj-$(CONFIG_ADC_EXYNOS) += exynos-adc.o
obj-$(CONFIG_ADC_SANDBOX) += sandbox.o
obj-$(CONFIG_SARADC_ROCKCHIP) += rockchip-saradc.o
obj-$(CONFIG_SARADC_MESON) += meson-saradc.o
obj-$(CONFIG_STM32_ADC) += stm32-adc.o stm32-adc-core.o
obj-$(CONFIG_ADC_IMX93) += imx93-adc.o
obj-$(and $(CONFIG_ADC_AUGENTIX), $(CONFIG_AUGENTIX_FASTBOOT)) += augentix-adc.o
obj-$(and $(CONFIG_ADC_AUGENTIX_V2), $(CONFIG_AUGENTIX_FASTBOOT)) += augentix-adc-v2.o
