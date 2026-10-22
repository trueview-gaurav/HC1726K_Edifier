/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

/**
 * @file hw_pc.h
 * @brief pc 
 */

#ifndef HW_PC_H
#define HW_PC_H

#ifndef __KERNEL__
#include <stdint.h>
#else
#include <linux/types.h>
#endif

#include "csr_bank_ck.h"

#define GENERAL_SRC_XTAL 0

/*
 * for general,
 * CPU_PLL_1: 996M
 * CPU_PLL_3: 249M
 * CPU_PLL_4: decided by adjust_qspi_clk()
 * CPU_PLL_6: 398.4M
 *
 * CAS_PLL_3: 225M
 * CAS_PLL_5: 27M
 * CAS_PLL_6: 900M
 *
 * SENSOR_PLL_1: 891M
 * SENSOR_PLL_3: 74.25M
 * SENSOR_PLL_4: 297M
 * SENSOR_PLL_5: 222.75M
 *
 * AUDIO_PLL_3: 282.24M
 * AUDIO_PLL_4: 282.24M
 * AUDIO_PLL_5: 282.24M
 * AUDIO_PLL_6: 451.58M
 *
 * DDR_PLL_3: 399M
 * USB_PHY: 60M
 */
#define CPU_SRC_XTAL 1
#define CPU_SRC_CPU_PLL_1 2
#define CPU_SRC_SENSOR_PLL_1 8

#define AXI_SYS_SRC_CPU_PLL_3 1
#define AXI_DRAMC_SRC_DDR_PLL_3 1
#define PVT_SRC_CPU_PLL_3 1
#define USB_UTMI_SRC_USB_PHY 1
#define AHB_USB_SRC_CPU_PLL_3 1

#define QSPI_SRC_CPU_PLL_3 1
#define QSPI_SRC_CPU_PLL_4 2
#define QSPI_SRC_CPU_PLL_6 3
#define SPI_SRC_CPU_PLL_3 1
#define SPI_SRC_CPU_PLL_6 4
#define SPI_SRC_CPU_PLL_4 5

#define PWM_SRC_CPU_PLL_6 1
#define PWM_SRC_SENSOR_PLL_4 2
#define PWM_SRC_CAS_PLL_3 3

#define UART_SRC_CAS_PLL_3 1
#define UART_SRC_CPU_PLL_6 2

#define SDC_SRC_CPU_PLL_6 1
#define EMAC_SRC_CAS_PLL_6 1
#define SAADC_SRC_CPU_PLL_6 1
#define GENERAL_FM_SRC_PLL 1

#define AUDIO_SRC_AUDIO_PLL_3 1
#define AUDIO_SRC_AUDIO_PLL_4 2
#define AUDIO_SRC_AUDIO_PLL_5 3
#define AUDIO_SRC_AUDIO_PLL_6 4

#define SENSOR_SRC_SENSOR_PLL_3 1
#define SENIF_SRC_SENSOR_PLL_5 1
#define SENIF_SRC_CPU_PLL_4 3
#define MIPI_SRC_SENSOR_PLL_4 1

#define IS_SRC_SENSOR_PLL_4 1
#define ISP_SRC_CPU_PLL_3 1
#define ISP_SRC_CPU_PLL_6 3
#define VP_SRC_CPU_PLL_3 1
#define VP_SRC_CPU_PLL_6 3
#define ENC_SRC_CPU_PLL_3 1
#define ENC_SRC_CPU_PLL_6 3

void switch_cpu_clk_src_to_pll(void);
void switch_clk_src(void);
void cken_init(void);
void config_cpu_low_speed(int enable);
extern int g_is_cpu_low_speed;

#endif
