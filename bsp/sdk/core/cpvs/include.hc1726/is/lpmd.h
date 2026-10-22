/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef SAPPORO_LPMD_H_
#define SAPPORO_LPMD_H_

#include "is_utils.h"
#include "csr_bank_lpmd.h"

typedef struct is_lpmd_cfg {
	uint8_t apl_iir_weight;
	uint8_t apl_alarm_max;
	uint8_t apl_step_shift_bw;
	uint8_t apl_coring_th;
	uint8_t frame_cnt_th;
	uint8_t status_th_high_detect;
	uint8_t status_th_high;
	uint8_t status_th_low;
	uint8_t status_max;
	uint8_t status_dec;
	uint8_t region_weight[LPMD_REGION_WEIGHT_ENTRY_NUM];
	uint16_t frame_alarm_th;
} IsLpmdCfg;

typedef struct is_lpmd_crop_cfg {
	uint16_t crop_left;
	uint16_t crop_right;
	uint16_t crop_up;
	uint16_t crop_down;
} IsLpmdCropCfg;

typedef struct is_lpmd_det_cfg {
	uint16_t det_width;
	uint16_t det_height;
} IsLpmdDetCfg;

typedef struct is_lpmd_rgl_cfg {
	uint8_t region_x_num_m1;
	uint16_t region_pix_num;
	uint8_t region_width;
	uint8_t region_height;
} IsLpmdRglCfg;

typedef struct is_lpmd_stat {
	uint8_t status_frame_alarm;
} IsLpmdStat;

/* IRQ mask */
void is_lpmd_set_irq_mask_frame_end(volatile CsrBankLpmd *csr, uint8_t irq_mask_frame_end);
uint8_t is_lpmd_get_irq_mask_frame_end(volatile CsrBankLpmd *csr);
void is_lpmd_set_irq_mask_frame_alarm(volatile CsrBankLpmd *csr, uint8_t irq_mask_frame_alarm);
uint8_t is_lpmd_get_irq_mask_frame_alarm(volatile CsrBankLpmd *csr);
void is_lpmd_set_irq_mask_pix_cnt_mismatch(volatile CsrBankLpmd *csr, uint8_t irq_mask_pix_cnt_mismatch);
uint8_t is_lpmd_get_irq_mask_mask_pix_cnt_mismatch(volatile CsrBankLpmd *csr);

/* Resolution */
void is_lpmd_set_res(volatile CsrBankLpmd *csr, const struct res *res);
void is_lpmd_get_res(volatile CsrBankLpmd *csr, struct res *res);

/* LPMD */
void is_lpmd_set_cfg(volatile CsrBankLpmd *csr, const struct is_lpmd_cfg *cfg);
void is_lpmd_get_cfg(volatile CsrBankLpmd *csr, struct is_lpmd_cfg *cfg);
void is_lpmd_set_crop_cfg(volatile CsrBankLpmd *csr, const struct is_lpmd_crop_cfg *cfg);
void is_lpmd_get_crop_cfg(volatile CsrBankLpmd *csr, struct is_lpmd_crop_cfg *cfg);
void is_lpmd_set_det_cfg(volatile CsrBankLpmd *csr, const struct is_lpmd_det_cfg *cfg);
void is_lpmd_get_det_cfg(volatile CsrBankLpmd *csr, struct is_lpmd_det_cfg *cfg);
void is_lpmd_set_rgl_cfg(volatile CsrBankLpmd *csr, const struct is_lpmd_rgl_cfg *cfg);
void is_lpmd_get_rgl_cfg(volatile CsrBankLpmd *csr, struct is_lpmd_rgl_cfg *cfg);
void is_lpmd_get_stat(volatile CsrBankLpmd *csr, struct is_lpmd_stat *stat);

/* Frame pix num */
void is_lpmd_set_frame_pix_num(volatile CsrBankLpmd *csr, uint32_t frame_pix_num);
uint32_t is_lpmd_get_frame_pix_num(volatile CsrBankLpmd *csr);

/* Debug */
void is_lpmd_set_dbg_mon_sel(volatile CsrBankLpmd *csr, uint8_t debug_mon_sel);
uint8_t is_lpmd_get_dbg_mon_sel(volatile CsrBankLpmd *csr);

/* reserved_0 */
void is_lpmd_set_reserved_0(volatile CsrBankLpmd *csr, uint8_t reserved_0);
uint8_t is_lpmd_get_reserved_0(volatile CsrBankLpmd *csr);

#endif /* SAPPORO_LPMD_H_ */