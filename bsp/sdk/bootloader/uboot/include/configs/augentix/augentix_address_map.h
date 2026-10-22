/*
 * Configuation settings for augentix products.
 *
 * SPDX-License-Identifier: GPL-2.0+
 */

#ifndef __AUGENTIX_ADDRESSMAP_H
#define __AUGENTIX_ADDRESSMAP_H

/* QSPI driver */
#if defined(CONFIG_OSAKA)
#define QSPI_BASE 0x82160000
#define QSPIR_BASE 0x82170000
#define QSPIW_BASE 0x82180000
#define PC_SYSCFG_DBG_MON_BASE 0x8200081C
#else
#define QSPI_BASE 0x83610000
#define QSPIR_BASE 0x83620000
#define QSPIW_BASE 0x83630000
#define PC_SYSCFG_DBG_MON_BASE 0x8000081C
#endif

/* PWM driver */
#if defined(CONFIG_OSAKA)
#define PWM_BASE 0x81020000
#else
#define PWM_BASE 0x80060000
#endif

/* I2C driver */
#if defined(CONFIG_OSAKA)
#define I2CM0_BASE 0x81030000
#define I2CM1_BASE 0x81030400
#else
#define I2CM0_BASE 0x80070000
#define I2CM1_BASE 0x80080000
#endif

/* ADC driver */
#if defined(CONFIG_OSAKA)
#define SAADCCTRL_BASE 0x81260000
#define ADO_LDO_BASE 0x81140000
#elif defined(CONFIG_SAPPORO) || defined(CONFIG_KAMO)
#define SAADCCTRL_BASE 0x80110000
#define ADO_LDO_BASE 0x80250000
#else
#define ADCCFG_BASE 0x80100000
#define ADCCTR_BASE 0x80108000
#define ADOIN_BASE 0x80140000
#endif

/* GPIO driver */
#if defined(CONFIG_OSAKA)
#define GPIOC_BASE 0x80040400
#elif defined(CONFIG_SAPPORO) || defined(CONFIG_KAMO)
#define GPIOC_BASE 0x80001400
#else
#define GPIOC_BASE 0x80001800
#endif

/* Audio driver */
#if defined(CONFIG_OSAKA)
#define ADOLDO_AUDIO_LDO_BASE 0x81140000
#define ADOAADC_L_AADC_BASE 0x810D0000
#define ADOAADC_R_AADC_BASE 0x810E0000
#elif defined(CONFIG_SAPPORO) || defined(CONFIG_KAMO)
#define ADOLDO_AUDIO_LDO_BASE 0x80250000
#define ADOAADC_L_AADC_BASE 0x80180000
#define ADOAADC_R_AADC_BASE 0x80190000
#else
#define ADOPREAMP_BASE 0x80130000
#endif

/* Watchdog definitions */
#if defined(CONFIG_OSAKA)
#define CONFIG_AUGENTIX_WATCHDOG_V2
#define WDT_BASE 0x80010800
#elif defined(CONFIG_SAPPORO) || defined(CONFIG_KAMO)
#define CONFIG_AUGENTIX_WATCHDOG_V2
#define WDT_BASE 0x80300800
#else
#define CONFIG_AUGENTIX_WATCHDOG
#define AMC_BASE 0x80530000
#define WDT_BASE 0x80550000
#endif
#define CONFIG_WDT_CLK 24000000

/* ethernet definitions */
#if defined(CONFIG_OSAKA)
#define EQOS_CFG_BASE 0x820C0000
#define EQOS_CONTROLLER_BASE 0x820D0000
#elif defined(CONFIG_SAPPORO) || defined(CONFIG_KAMO)
#define EQOS_CFG_BASE 0x81360000
#define EQOS_CONTROLLER_BASE 0x81880000
#else
#define EQOS_CFG_BASE 0x81360000
#define EQOS_CONTROLLER_BASE 0x81880000
#endif

/* serial console */
#if defined(CONFIG_OSAKA)
#define CONSOLE_BASE 0x811D0000
#elif defined(CONFIG_SAPPORO) || defined(CONFIG_KAMO)
#define CONSOLE_BASE 0x80830000
#else
#define CONSOLE_BASE 0x80820000
#endif

/* MMC */
#if defined(CONFIG_OSAKA)
#define SDC0_BASE 0x82DFD000
#define SDC0_CFG_BASE 0x82130000
#define SDC_GPI_SEL_BASE (GPIOC_BASE + 0x58)
#else
#define SDC0_BASE 0x818A0000
#define SDC0_CFG_BASE 0x81340000
#define SDC_GPI_SEL_BASE (GPIOC_BASE + 0x34)
#endif

/* GIC */
#if defined(CONFIG_OSAKA)
#define GIC_BASE 0xA1900000
#define GICD_BASE (GIC_BASE + 0x1000)
#else
#define GIC_BASE 0x84000000
#endif

/* SEC BOOT */
#if defined(CONFIG_OSAKA)
#define SEC_BOOT_ADDR 0x80050014
#else
#define SEC_BOOT_ADDR 0x80000814
#endif

#endif
