/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef HW_PLL_H
#define HW_PLL_H

#include "address_map.h"

typedef enum {
	PLL_REF_XTAL = 0, // 24M
	PLL_REF_CAS3 = 3, // 27M
} PllRefClk;

typedef enum { PLL_RDIV_1, PLL_RDIV_2, PLL_RDIV_4 = 3 } PllRefDiv;

typedef enum {
	PLL_HDIV_1,
	PLL_HDIV_1P5,
} PllHalfDiv;

typedef enum {
	FPREDIV,
	FHALFDIV,
} PllPostClkinSel;

typedef enum {
	POST_DIV_1,
	POST_DIV_2,
	POST_DIV_3,
	POST_HALF_DIV_4,
} PllPostDiv;

typedef enum {
	FM_SEL_REF_CLK = 2,
	FM_SEL_FEEDBACK,
	FM_SEL_POST_DIV_1,
	FM_SEL_POST_DIV_2,
	FM_SEL_POST_DIV_3,
	FM_SEL_POST_DIV_4,
} PllFmSel;

typedef enum {
	CPU_PLL4_76_6M = 76600000,
	CPU_PLL4_90_5M = 90500000,
	CPU_PLL4_71_1M = 71100000,
	CPU_PLL4_83M = 83000000,
	CPU_PLL6_99_6M = 99600000,
} QSPI_TARGET_CLK;

void pll_en(uintptr_t pll_base, int en);
uint32_t pll_get_fvco_freq(uintptr_t pll_base);
void hw_pll_print_info(void);
void pll_all_setting_by_uart_boot(int arg);
void pll_all_setting_new_v2(int dram_mts);
uint32_t adjust_qspi_clk(uint32_t target_clk);

#endif
