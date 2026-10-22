/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef ISP_BLD_H_
#define ISP_BLD_H_

#include "stdint.h"

void hw_isp_bld_frame_start();
void hw_isp_bld_irq_clear_frame_end();
uint32_t hw_isp_bld_status_frame_end();
void hw_isp_bld_irq_mask_frame_end(uint32_t irq_mask_frame_end);
void hw_isp_bld_resolution(uint32_t width, uint32_t height);
void hw_isp_bld_setting();
void hw_isp_bld_debug_mon_sel(uint32_t debug_mon_sel);

#endif