/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef CVS_H_
#define CVS_H_

#include "is_utils.h"

void hw_is_cvs_set_frame_start(const enum is_kel_no no);
/* IRQ clear */
void hw_is_cvs_set_irq_clear_frame_end(const enum is_kel_no no);

/* Status */
uint8_t hw_is_cvs_get_status_frame_end(const enum is_kel_no no);

/* IRQ mask */
void hw_is_cvs_set_irq_mask_frame_end(const enum is_kel_no no, uint8_t irq_mask_frame_end);
uint8_t hw_is_cvs_get_irq_mask_frame_end(const enum is_kel_no no);

/* Debug */
void hw_is_cvs_set_dbg_mon_sel(const enum is_kel_no no, uint8_t debug_mon_sel);
uint8_t hw_is_cvs_get_dbg_mon_sel(const enum is_kel_no no);

/* Mode */
void hw_is_cvs_set_mode(const enum is_kel_no no, uint8_t mode);
uint8_t hw_is_cvs_get_mode(const enum is_kel_no no);

#endif