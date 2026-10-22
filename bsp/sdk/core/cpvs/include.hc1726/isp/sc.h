/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef SC_H_
#define SC_H_

#include "csr_bank_sc.h"

#include "da_define.h"

#include <linux/types.h>

#define SC_TAP (6)
#define SC_PHASE_PRECISION (20)

typedef struct tile_sc_param {
	__u16 frame_width_i;
	__u16 frame_width_o;
	__u16 frame_height_i;
	__u16 frame_height_o;

	__u32 up_scaling_ver;
	__s32 ini_phase_ver;
	__u32 phase_step_ver;
	__s32 ini_filt_phase_ds_ver;
	__u32 filt_phase_step_ds_ver;
	__s32 ini_cnt_ver[SC_TAP];

	__u16 tile_width_i[MAX_TILE_NUM];
	__u16 tile_width_o[MAX_TILE_NUM];
	__u32 up_scaling_hor;
	__s32 ini_phase_hor[MAX_TILE_NUM];
	__u32 phase_step_hor;
	__s32 ini_filt_phase_ds_hor[MAX_TILE_NUM];
	__s32 filt_phase_step_ds_hor;
	__s32 ini_cnt_hor[MAX_TILE_NUM][SC_TAP];
	__u32 crop_o_left[MAX_TILE_NUM];
} TileScParam;

typedef struct sc_double {
	int32_t integer;
	int32_t divisor;
	int32_t remainder;
} ScDouble;

void isp_sc_print_param(const TileScParam *sc_param, int tile_n);

void isp_sc_set_frame_csr(volatile CsrBankSc *csr, TileScParam *sc_param);
void isp_sc_set_tile_csr(volatile CsrBankSc *csr, TileScParam *sc_param, int t);

void isp_calc_sc_ver_param(TileScParam *sc_param, uint16_t frame_height_i, uint16_t frame_height_o);
void isp_calc_sc_hor_param(TileScParam *sc_param, uint16_t frame_width_i, uint16_t frame_width_o,
                           const TileInfo *tile_i, const TileInfo *tile_o, int tile_n);
#endif /* SC_H_ */
