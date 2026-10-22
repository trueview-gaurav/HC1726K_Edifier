/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef EDP_H_
#define EDP_H_

#include <stdint.h>
#include "is_utils.h"

typedef enum edp_mode {
	EDP_MODE_ALL_FRAME_TO_TARGET = 0,
	EDP_MODE_ALL_FRAME_BROADCASE = 1,
	EDP_MODE_ALL_FRAME_SKIP = 2,
	EDP_MODE_HALF_FRAME_SWITCH = 3,
	EDP_MODE_HALF_LINE_SIWTCH = 4,
	EDP_MODE_ONE_LINE_SWITCH = 5,
	EDP_MODE_TWO_LINE_SWITCH = 6,
	EDP_MODE_ONE_PIXEL_SWITCH = 7,
	EDP_MODE_TWO_PIXEL_SWITCH = 8,
	EDP_MODE_CROP = 9,
} EdpMode;

typedef enum edp_target {
	EDP_TARGET_MAIN = 0,
	EDP_TARGET_SUB = 1,
} EdpTarget;

typedef struct edp_mode_info {
	enum edp_mode mode;
	/* For mode 1, 4, 5, 6, 7, 8, 9 */
	enum edp_target target;
	/* For mode 5, 6, 7, 8 */
	uint32_t switch_offset;
	/* For mode 9 */
	uint32_t roi0_crop_x_start;
	uint32_t roi0_crop_x_end;
	uint32_t roi0_crop_y_start;
	uint32_t roi0_crop_y_end;
	uint32_t roi1_crop_x_start;
	uint32_t roi1_crop_x_end;
	uint32_t roi1_crop_y_start;
	uint32_t roi1_crop_y_end;
} EdpModeInfo;

void hw_is_edp_bypass(const enum is_kel_no no);
void hw_is_edp_set_res(const enum is_kel_no no, const struct res *res);
void hw_is_edp_set_irq_mask_frame_end(const enum is_kel_no no, uint8_t irq_mask_frame_end);
void hw_is_edp_set_irq_clear_frame_end(const enum is_kel_no no);
uint8_t hw_is_edp_get_status_frame_end(const enum is_kel_no no);

void hw_is_edp_frame_start(void);
void hw_is_edp_irq_clear_frame_end(void);
uint32_t hw_is_edp_status_frame_end(void);
void hw_is_edp_irq_mask_frame_end(uint32_t irq_mask_frame_end);
void hw_is_edp_resolution(uint32_t width, uint32_t height);
void hw_is_edp_test();
void hw_is_edp_crop_test();
int hw_is_edp_set_mode(const enum is_kel_no no, struct edp_mode_info info);

#endif
