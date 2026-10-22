/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef SAPPORO_DFK_H_
#define SAPPORO_DFK_H_

#include "is_utils.h"
#include "csr_bank_dfk.h"

typedef struct is_dfk_cfg {
	uint8_t enable;
	uint8_t bypass;
	uint16_t line_per_period;
	uint16_t phase_curr;
	struct flicker_amp {
		uint16_t x[DFK_AMP_ENTRY_NUM];
		uint8_t y[DFK_AMP_ENTRY_NUM];
		uint16_t slope[DFK_AMP_ENTRY_NUM - 1];
	} amp;
	struct sin_wave {
		uint8_t wave[DFK_SIN_WAVE_ENTRY_NUM];
		uint8_t wave_ds;
	} sin;
} IsDfkCfg;

typedef struct is_dfk_roi_stat_frame_ctrl {
	struct rect_point roi;
	uint32_t pix_num;
} IsDfkRoiStatFrameCtrl;

typedef struct is_dfk_roi_stat {
	uint32_t g_line_avg[DFK_G_LINE_AVG_ROI_STAT_MAX_NUM];
} IsDfkRoiStat;

/* IRQ mask */
void is_dfk_set_irq_mask_frame_end(volatile CsrBankDfk *csr, uint8_t irq_mask_frame_end);
uint8_t is_dfk_get_irq_mask_frame_end(volatile CsrBankDfk *csr);

/* Resolution */
void is_dfk_set_res(volatile CsrBankDfk *csr, const struct res *res);
void is_dfk_get_res(volatile CsrBankDfk *csr, struct res *res);

/* Input format */
void is_dfk_set_input_format(volatile CsrBankDfk *csr, const struct is_input_format *cfg);
void is_dfk_get_input_format(volatile CsrBankDfk *csr, struct is_input_format *cfg);

/* DFK */
void is_dfk_set_cfg(volatile CsrBankDfk *csr, const struct is_dfk_cfg *cfg);
void is_dfk_get_cfg(volatile CsrBankDfk *csr, struct is_dfk_cfg *cfg);

/* Statistics */
// CSR2SRAM
void is_dfk_set_csr2sram_sel(volatile CsrBankDfk *csr, uint8_t enable);
uint8_t is_dfk_get_csr2sram_sel(volatile CsrBankDfk *csr);

// ROI
void is_dfk_set_roi_stat_frame_ctrl(volatile CsrBankDfk *csr, uint8_t idx,
                                    const struct is_dfk_roi_stat_frame_ctrl *cfg);
void is_dfk_get_roi_stat_frame_ctrl(volatile CsrBankDfk *csr, uint8_t idx, struct is_dfk_roi_stat_frame_ctrl *cfg);
void is_dfk_set_roi_stat_enable(volatile CsrBankDfk *csr, uint8_t idx, uint8_t enable);
uint8_t is_dfk_get_roi_stat_enable(volatile CsrBankDfk *csr, uint8_t idx);
void is_dfk_get_roi_stat(volatile CsrBankDfk *csr, struct is_dfk_roi_stat *stat);

/* atpg_ctrl */
void is_dfk_set_atpg_ctrl(volatile CsrBankDfk *csr, uint8_t atpg_ctrl);
uint8_t is_dfk_get_atpg_ctrl(volatile CsrBankDfk *csr);

/* resevered_0 */
void is_dfk_set_reserved_0(volatile CsrBankDfk *csr, uint8_t reserved_0);
uint8_t is_dfk_get_reserved_0(volatile CsrBankDfk *csr);

/* resevered_1 */
void is_dfk_set_reserved_1(volatile CsrBankDfk *csr, uint8_t reserved_1);
uint8_t is_dfk_get_reserved_1(volatile CsrBankDfk *csr);

#endif /* SAPPORO_DFK_H_ */