/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef ADDRESS_MAP_H_
#define ADDRESS_MAP_H_

#ifdef __KERNEL__
#include <linux/types.h>
#else
#include <stdint.h>
#endif

#define SYSRAM_BASE 0xFFE00000
#define AXIQOS0_BASE 0x81320000
#define AXIQOS1_BASE 0x81330000

/*HW IP Base address*/
#define CK_BASE 0x80000000
#define RST_BASE 0x80000400
#define SYSCFG_BASE 0x80000800
#define PIOC_BASE 0x80001000
#define PLL_CASCADE_BASE 0x80010000
#define PLL_DDR_BASE 0x80011000
#define PLL_CPU_BASE 0x80012000
#define PLL_SENSOR_BASE 0x80015000
#define PLL_AUDIO_BASE 0x80017000
#define FM_CASCADE_BASE 0x80010400
#define FM_DDR_BASE 0x80011400
#define FM_CPU_BASE 0x80012400
#define FM_SENSOR_BASE 0x80015400
#define FM_AUDIO_BASE 0x80017400
#define PERI_BASE 0x80020000
#define I2CSLAVEM_BASE 0x80040000
#define TIMER_BASE 0x80050000
#define PWM_BASE 0x80060000
#define I2CM0_BASE 0x80070000
#define I2CM1_BASE 0x80080000
#define EFUSE_CTRL_BASE 0x80100000
#define TZPC_BASE 0x80270000
#define TZASC_BASE 0x80271000
#define CPU_CFG_BASE 0x80272000
#define TZ_IRQ_BASE 0x80273000
#define PMU_RTC_BASE 0x80290000
#define PMU_BASE 0x80290400
#define PMU_WDT_BASE 0x80290800
#define PMU_CTRL_BASE 0x80290C00
#define AON_RTC_BASE 0x80300000
#define AON_BASE 0x80300400
#define AON_WDT_BASE 0x80300800
#define AON_WDT_STABLE_BASE 0x80300C00
#define UART0_BASE 0x80820000
#define UART1_BASE 0x80830000
#define UART2_BASE 0x80840000
#define LPMD_BASE 0x80510000
#define PSD_BASE 0x80520000
#define AMC_BASE 0x80530000
#define DARB_SECURE_0_DARB_SECURE_BASE 0x812F0000
#define DARB0_DARB_BASE 0x81300000
#define SDC_CFG0_BASE 0x81340000
#define SDC_CFG1_BASE 0x81350000
#define USBCFG_BASE 0x81370000
#define EMAC_QOS_CONTROLLER_BASE 0x81880000
#define SDC0_BASE 0x818A0000
#define SDC1_BASE 0x818C0000
#define RXPHY0_RX_PHYCFG_BASE 0x83500000
#define RXPHY0_RX_CTRL_BASE 0x83500400
#define LVDS0_RX_BASE 0x83520000
#define LVDS0_DEC_BASE 0x83520400
#define LVDS1_DEC_BASE 0x83530000
#define PS_BASE 0x83540000
#define SLB0_BASE 0x83550000
#define SLB1_BASE 0x83560000
#define SENIF_SYSCFG_BASE 0x83570000
#define SENIF_CTRL_BASE 0x83570400
#define DMA_BASE 0x83600000
#define DMA_SYSCFG_BASE 0x83601000
#define QSPI_BASE 0x83610000
#define QSPIR_BASE 0x83620000
#define QSPIW_BASE 0x83630000
#define GIC_BASE 0x84000000
#define FPGA_CFG_BASE 0x80FF0000
#define FPGA_ROUTE_BASE 0x80FF0400
#define ENC_ENC_BASE 0x81000000

/* clang-format off */

// IS
#define IS_IS_BASE              0x83000000
#define IS_IS_CFG_BASE          0x83000400
#define IS_IS_CHECKSUM_BASE     0x83000800
#define IS_LPMD_BASE            0x83000C00
#define IS_CCQ_BASE             0x83010000
#define IS_CCQR_BASE            0x83010400
#define IS_CCQW_BASE            0x83010800
#define IS_PG0_BASE             0x83020000
#define IS_TG0_BASE             0x83020400
#define IS_EDP0_BASE            0x83020800
#define IS_PG1_BASE             0x83030000
#define IS_TG1_BASE             0x83030400
#define IS_EDP1_BASE            0x83030800
#define IS_ISR0_BASE            0x83040000
#define IS_ISR1_BASE            0x83050000
#define IS_ISW0_BASE            0x83060000
#define IS_ISW1_BASE            0x83070000
#define IS_ISW2_BASE            0x83080000
#define IS_ISW3_BASE            0x83090000
#define IS_LUP0_BASE            0x83092000
#define IS_LUP1_BASE            0x83094000
#define IS_ISK0_BASE            0x83100000
#define IS_ISK0_CFG_BASE        0x83100400
#define IS_ISK0_CHECKSUM_BASE   0x83100800
#define IS_CROP0_BASE           0x83118000
#define IS_BLS0_BASE            0x83120000
#define IS_DBC0_BASE            0x83128000
#define IS_DCC0_BASE            0x83130000
#define IS_LSC0_BASE            0x83138000
#define IS_BSP0_BASE            0x83140000
#define IS_DFK0_BASE            0x83148000
#define IS_CVS0_BASE            0x83150000
#define IS_CS0_BASE             0x83158000
#define IS_FSC0_BASE            0x83160000
#define IS_ISK1_BASE            0x83180000
#define IS_ISK1_CFG_BASE        0x83180400
#define IS_ISK1_CHECKSUM_BASE   0x83180800
#define IS_CROP1_BASE           0x83198000
#define IS_BLS1_BASE            0x831A0000
#define IS_DBC1_BASE            0x831A8000
#define IS_DCC1_BASE            0x831B0000
#define IS_LSC1_BASE            0x831B8000
#define IS_BSP1_BASE            0x831C0000
#define IS_DFK1_BASE            0x831C8000
#define IS_CVS1_BASE            0x831D0000
#define IS_CS1_BASE             0x831D8000
#define IS_FSC1_BASE            0x831E0000
#define IS_FGMA0_BASE           0x83100000
#define IS_FGMA1_BASE           0x83180000

// ISPVP
#define ISP_ISP_BASE            0x82000000
#define ISP_ISP_CFG_BASE        0x82000400
#define ISP_ISP_CHECKSUM_BASE   0x82000800
#define ISP_ISPIN_CHECKSUM_BASE 0x82000C00
#define ISP_CCQ_BASE            0x82010000
#define ISP_CCQR_BASE           0x82010400
#define ISP_CCQW_BASE           0x82010800
#define ISP_PG0_BASE            0x82020000
#define ISP_PG1_BASE            0x82030000
#define ISP_ISPR0_BASE          0x82060000
#define ISP_ISPR1_BASE          0x82070000
#define ISP_CS0_BASE            0x820A0000
#define ISP_CS1_BASE            0x820B0000
#define ISP_GFX0_BASE           0x820E0000
#define ISP_COORDR0_BASE        0x820E0400
#define ISP_BLD_BASE            0x82110000
#define ISP_HDR_BASE            0x82130000
#define ISP_DMS_BASE            0x82140000
#define ISP_FCS_BASE            0x82150000
#define ISP_DBF_BASE            0x82160000
#define ISP_CCM_BASE            0x82170000
#define ISP_PCA_BASE            0x82190000
#define ISP_CST_BASE            0x821A0000
#define ISP_SC_BASE             0x821B0000
#define ISP_CUS_BASE            0x821D0000
#define ISP_CDS_BASE            0x821E0000

#define VP_MCVP_BASE            0x82200000
#define VP_ME_BASE              0x82200400
#define VP_NR_BASE              0x82200800
#define VP_MER_BASE             0x82200C00
#define VP_NRW_BASE             0x82201000
#define VP_VP_BASE              0x82201400
#define VP_VP_CFG_BASE          0x82201800
#define VP_VP_CHECKSUM_BASE     0x82201C00
#define VP_MV8W_BASE            0x82210000
#define VP_MV8R_BASE            0x82220000
#define VP_VENC_MVW_BASE        0x82230000
#define VP_B2R_BASE             0x82240000
#define VP_PUP_BASE             0x82250000
#define VP_VPW0_BASE            0x82290000
#define VP_VPW1_BASE            0x822A0000
#define VP_VPW2_BASE            0x822B0000

#define ISP_NR2D_BASE           0x82300000
#define ISP_SHP_BASE            0x82310000
#define VP_DHZ_BASE             0x82320000

#endif /* ADDRESS_MAP_H_ */
