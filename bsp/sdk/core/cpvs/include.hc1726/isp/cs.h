/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef CS_H_
#define CS_H_

#include "isp_utils.h"
#include "csr_bank_cs.h"

typedef struct isp_cs_cfg {
	uint8_t legacy_420;
	uint8_t chroma_shift_sampling;
	uint8_t chroma_even_line;
} IspCsCfg;

/* Frame start */
void hw_isp_cs_set_frame_start(uint8_t view);

/* IRQ clear */
void hw_isp_cs_set_irq_clear_frame_end(uint8_t view);

/* Frame end*/
uint8_t hw_isp_cs_get_status_frame_end(uint8_t view);

/* IRQ mask */
void hw_isp_cs_set_irq_mask_frame_end(uint8_t view, uint8_t irq_mask_frame_end);
uint8_t hw_isp_cs_get_irq_mask_frame_end(uint8_t view);

/* Resolution */
void hw_isp_cs_set_res(uint8_t view, const struct res *res);
void hw_isp_cs_get_res(uint8_t view, struct res *res);

/* Chroma shift */
void hw_isp_cs_set_cfg(uint8_t view, const struct isp_cs_cfg *cfg);
void hw_isp_cs_get_cfg(uint8_t view, struct isp_cs_cfg *cfg);

/* Debug */
void hw_isp_cs_set_dbg_mon_sel(uint8_t view, uint8_t debug_mon_sel);
uint8_t hw_isp_cs_get_dbg_mon_sel(uint8_t view);

//
/* IRQ mask */
void isp_cs_set_irq_mask_frame_end(volatile CsrBankCs *csr, uint8_t irq_mask_frame_end);
uint8_t isp_cs_get_irq_mask_frame_end(volatile CsrBankCs *csr);

/* Resolution */
void isp_cs_set_res(volatile CsrBankCs *csr, const struct res *res);
void isp_cs_get_res(volatile CsrBankCs *csr, struct res *res);

/* Chroma shift */
void isp_cs_set_cfg(volatile CsrBankCs *csr, const struct isp_cs_cfg *cfg);
void isp_cs_get_cfg(volatile CsrBankCs *csr, struct isp_cs_cfg *cfg);

/* Debug */
void isp_cs_set_dbg_mon_sel(volatile CsrBankCs *csr, uint8_t debug_mon_sel);
uint8_t isp_cs_get_dbg_mon_sel(volatile CsrBankCs *csr);

//
void hw_isp_cs0_frame_start(void);
void hw_isp_cs0_irq_clear_frame_end(void);
uint32_t hw_isp_cs0_status_frame_end(void);
void hw_isp_cs0_irq_mask_frame_end(uint32_t irq_mask_frame_end);
void hw_isp_cs0_resolution(uint32_t width, uint32_t height);
void hw_isp_cs0_bypass(void);
void hw_isp_cs0_debug_mon_sel(uint32_t debug_mon_sel);

#endif