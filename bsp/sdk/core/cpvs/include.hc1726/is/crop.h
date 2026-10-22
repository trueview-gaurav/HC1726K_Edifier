/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef KYOTO_CROP_H_
#define KYOTO_CROP_H_

#include "is_utils.h"
#include "csr_bank_crop.h"

typedef struct is_crop_cfg {
	uint16_t crop_left;
	uint16_t crop_right;
	uint16_t crop_up;
	uint16_t crop_down;
} IsCropCfg;

/* Frame start */
void hw_is_crop_set_frame_start(const enum is_kel_no no);

/* Resolution */
void hw_is_crop_set_res(const enum is_kel_no no, const struct res *res);
void hw_is_crop_get_res(const enum is_kel_no no, struct res *res);

/* Crop */
void hw_is_crop_set_cfg(const enum is_kel_no no, const struct is_crop_cfg *cfg);
void hw_is_crop_get_cfg(const enum is_kel_no no, struct is_crop_cfg *cfg);

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//* for mpp is *//

/* Resolution */
void is_crop_set_res(volatile CsrBankCrop *csr, const struct res *res);
void is_crop_get_res(volatile CsrBankCrop *csr, struct res *res);

/* Crop */
void is_crop_set_cfg(volatile CsrBankCrop *csr, const struct is_crop_cfg *cfg);
void is_crop_get_cfg(volatile CsrBankCrop *csr, struct is_crop_cfg *cfg);

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//* need to remove *//
// Move to test
typedef struct is_crop_resolution {
	uint32_t width;
	uint32_t height;
} IsCropResolution;

typedef struct is_crop_ctx {
	IsCropResolution crop_res;
	uint32_t crop_up;
	uint32_t crop_down;
	uint32_t crop_left;
	uint32_t crop_right;

} IsCropCtx;

typedef struct is_crop_attr {
	uint32_t crop_width;
	uint32_t crop_height;
	uint32_t crop_up;
	uint32_t crop_down;
	uint32_t crop_left;
	uint32_t crop_right;

} IsCropAttr;

void hw_is_crop_frame_start(void);
void hw_is_crop_resolution(uint32_t width, uint32_t height);
void hw_is_crop_bypass(void);
void hw_is_crop_run(IsCropAttr *cropattr);
void hw_is_crop_set_ctx(IsCropCtx *cropctx, IsCropAttr *cropattr);
void hw_is_crop_set_reg(IsCropCtx *cropctx);

#endif /* KYOTO_CROP_H_ */
