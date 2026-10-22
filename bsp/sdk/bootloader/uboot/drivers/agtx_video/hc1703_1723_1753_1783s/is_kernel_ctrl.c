#include "agtx_video.h"

#include "csr_bank_bsp.h"
#include "csr_bank_dbc.h"
#include "csr_bank_dcc.h"
#include "is_setting.h"

/* General */
typedef struct res {
	uint16_t width;
	uint16_t height;
} Res;

typedef struct rect {
	uint16_t x;
	uint16_t y;
	uint16_t width;
	uint16_t height;
} Rect;

typedef struct rect_point {
	int16_t sx;
	int16_t sy;
	int16_t ex;
	int16_t ey;
} RectPoint;

/* BSP */
typedef enum is_pixel_format_o {
	IS_PIXEL_FORMAT_O_BAYER = 0,
	IS_PIXEL_FORMAT_O_MONO = 1,
	IS_PIXEL_FORMAT_O_NUM = 2,
} IsPixelFormatO;

typedef struct is_output_format {
	enum is_pixel_format_o mode;
	enum ini_bayer_phase bayer;
} IsOutputFormat;

typedef enum is_luma_input_mode {
	IS_LUMA_INPUT_MODE_AVG = 0,
	IS_LUMA_INPUT_MODE_SUM = 1,
	IS_LUMA_INPUT_MODE_MONO = 2,
	IS_LUMA_INPUT_MODE_NUM = 3,
} IsLumaInputMode;

typedef struct is_bsp_y_hist_roi_ctrl {
	enum is_luma_input_mode mode;
	uint16_t offset;
} IsBspYHistRoiCtrl;

typedef struct is_bsp_y_hist_roi_stat_frame_ctrl {
	struct rect_point roi;
} IsBspYHistRoiStatFrameCtrl;

typedef struct is_bsp_y_avg_roi_ctrl {
	enum is_luma_input_mode mode;
} IsBspYAvgRoiCtrl;

typedef struct is_bsp_y_avg_roi_stat_frame_ctrl {
	struct rect_point roi;
	uint32_t pix_num;
} IsBspYAvgRoiStatFrameCtrl;

extern struct earlyvideo_drvdata g_earlyvideo_drvdata;

static inline void __bsp_set_res(volatile CsrBankBsp *csr, const struct res *res)
{
	csr->width = res->width;
	csr->height = res->height;
}

static inline void __bsp_set_input_format(volatile CsrBankBsp *csr, const struct is_input_format *cfg)
{
	csr->cfa_mode = cfg->mode;
	csr->bayer_ini_phase_i = cfg->bayer;
	csr->cfa_phase_0 = cfg->cfa[0];
	csr->cfa_phase_1 = cfg->cfa[1];
	csr->cfa_phase_2 = cfg->cfa[2];
	csr->cfa_phase_3 = cfg->cfa[3];
	csr->cfa_phase_4 = cfg->cfa[4];
	csr->cfa_phase_5 = cfg->cfa[5];
	csr->cfa_phase_6 = cfg->cfa[6];
	csr->cfa_phase_7 = cfg->cfa[7];
	csr->cfa_phase_8 = cfg->cfa[8];
	csr->cfa_phase_9 = cfg->cfa[9];
	csr->cfa_phase_10 = cfg->cfa[10];
	csr->cfa_phase_11 = cfg->cfa[11];
	csr->cfa_phase_12 = cfg->cfa[12];
	csr->cfa_phase_13 = cfg->cfa[13];
	csr->cfa_phase_14 = cfg->cfa[14];
	csr->cfa_phase_15 = cfg->cfa[15];
}

static inline void __bsp_set_output_format(volatile CsrBankBsp *csr, const struct is_output_format *cfg)
{
	csr->mono_o = cfg->mode;
	csr->bayer_ini_phase_o = cfg->bayer;
}

static inline void __bsp_set_y_hist_roi_ctrl(volatile CsrBankBsp *csr, const struct is_bsp_y_hist_roi_ctrl *cfg)
{
	csr->y_hist_in_mode = cfg->mode;
	csr->y_hist_offset = cfg->offset;
}

static inline void __bsp_set_y_avg_roi_ctrl(volatile CsrBankBsp *csr, const struct is_bsp_y_avg_roi_ctrl *cfg)
{
	csr->roi_y_avg_in_mode = cfg->mode;
}

static inline void __bsp_set_y_hist_roi_stat_frame_ctrl(volatile CsrBankBsp *csr,
                                                        const struct is_bsp_y_hist_roi_stat_frame_ctrl *cfg)
{
	csr->y_hist_roi_sx = cfg->roi.sx;
	csr->y_hist_roi_ex = cfg->roi.ex;
	csr->y_hist_roi_sy = cfg->roi.sy;
	csr->y_hist_roi_ey = cfg->roi.ey;
}

static inline void __bsp_get_y_hist_roi_stat_frame_ctrl(volatile CsrBankBsp *csr,
                                                        struct is_bsp_y_hist_roi_stat_frame_ctrl *cfg)
{
	cfg->roi.sx = csr->y_hist_roi_sx;
	cfg->roi.ex = csr->y_hist_roi_ex;
	cfg->roi.sy = csr->y_hist_roi_sy;
	cfg->roi.ey = csr->y_hist_roi_ey;
}

static inline void __bsp_set_y_avg_roi_stat_frame_ctrl(volatile CsrBankBsp *csr, uint8_t idx,
                                                       const struct is_bsp_y_avg_roi_stat_frame_ctrl *cfg)
{
	switch (idx) {
	case 0:
		csr->roi_0_y_avg_sx = cfg->roi.sx;
		csr->roi_0_y_avg_ex = cfg->roi.ex;
		csr->roi_0_y_avg_sy = cfg->roi.sy;
		csr->roi_0_y_avg_ey = cfg->roi.ey;
		csr->roi_0_y_avg_pix_num = cfg->pix_num;
		break;
	case 1:
		csr->roi_1_y_avg_sx = cfg->roi.sx;
		csr->roi_1_y_avg_ex = cfg->roi.ex;
		csr->roi_1_y_avg_sy = cfg->roi.sy;
		csr->roi_1_y_avg_ey = cfg->roi.ey;
		csr->roi_1_y_avg_pix_num = cfg->pix_num;
		break;
	case 2:
		csr->roi_2_y_avg_sx = cfg->roi.sx;
		csr->roi_2_y_avg_ex = cfg->roi.ex;
		csr->roi_2_y_avg_sy = cfg->roi.sy;
		csr->roi_2_y_avg_ey = cfg->roi.ey;
		csr->roi_2_y_avg_pix_num = cfg->pix_num;
		break;
	case 3:
		csr->roi_3_y_avg_sx = cfg->roi.sx;
		csr->roi_3_y_avg_ex = cfg->roi.ex;
		csr->roi_3_y_avg_sy = cfg->roi.sy;
		csr->roi_3_y_avg_ey = cfg->roi.ey;
		csr->roi_3_y_avg_pix_num = cfg->pix_num;
		break;
	default:
		break;
	}
}

static inline void __bsp_get_y_avg_roi_stat_frame_ctrl(volatile CsrBankBsp *csr, uint8_t idx,
                                                       struct is_bsp_y_avg_roi_stat_frame_ctrl *cfg)
{
	switch (idx) {
	case 0:
		cfg->roi.sx = csr->roi_0_y_avg_sx;
		cfg->roi.ex = csr->roi_0_y_avg_ex;
		cfg->roi.sy = csr->roi_0_y_avg_sy;
		cfg->roi.ey = csr->roi_0_y_avg_ey;
		cfg->pix_num = csr->roi_0_y_avg_pix_num;
		break;
	case 1:
		cfg->roi.sx = csr->roi_1_y_avg_sx;
		cfg->roi.ex = csr->roi_1_y_avg_ex;
		cfg->roi.sy = csr->roi_1_y_avg_sy;
		cfg->roi.ey = csr->roi_1_y_avg_ey;
		cfg->pix_num = csr->roi_1_y_avg_pix_num;
		break;
	case 2:
		cfg->roi.sx = csr->roi_2_y_avg_sx;
		cfg->roi.ex = csr->roi_2_y_avg_ex;
		cfg->roi.sy = csr->roi_2_y_avg_sy;
		cfg->roi.ey = csr->roi_2_y_avg_ey;
		cfg->pix_num = csr->roi_2_y_avg_pix_num;
		break;
	case 3:
		cfg->roi.sx = csr->roi_3_y_avg_sx;
		cfg->roi.ex = csr->roi_3_y_avg_ex;
		cfg->roi.sy = csr->roi_3_y_avg_sy;
		cfg->roi.ey = csr->roi_3_y_avg_ey;
		cfg->pix_num = csr->roi_3_y_avg_pix_num;
		break;
	default:
		break;
	}
}

static inline void __y_hist_roi_stat_frame_ctrl(volatile struct csr_bank_bsp *csr, struct rect_point *roi)
{
	struct is_bsp_y_hist_roi_stat_frame_ctrl cfg;

	__bsp_get_y_hist_roi_stat_frame_ctrl(csr, &cfg);
	cfg.roi.sx = roi->sx;
	cfg.roi.ex = roi->ex;
	cfg.roi.sy = roi->sy;
	cfg.roi.ey = roi->ey;
	__bsp_set_y_hist_roi_stat_frame_ctrl(csr, &cfg);
}

static inline void __y_avg_roi_stat_frame_ctrl(volatile struct csr_bank_bsp *csr, struct rect_point *roi,
                                               uint8_t num_of_roi)
{
	int i;
	struct is_bsp_y_avg_roi_stat_frame_ctrl cfg;

	for (i = 0; i < num_of_roi; i++) {
		__bsp_get_y_avg_roi_stat_frame_ctrl(csr, i, &cfg);
		cfg.roi.sx = roi->sx;
		cfg.roi.ex = roi->ex;
		cfg.roi.sy = roi->sy;
		cfg.roi.ey = roi->ey;
		cfg.pix_num = (cfg.roi.ex - cfg.roi.sx + 1) * (cfg.roi.ey - cfg.roi.sy + 1);
		__bsp_set_y_avg_roi_stat_frame_ctrl(csr, i, &cfg);
	}
}

static inline void __reg_bsp_calc_stat_frame_ctrl(volatile CsrBankBsp *csr_bsp, struct rect_point *roi)
{
	__y_hist_roi_stat_frame_ctrl(csr_bsp, roi);
	__y_avg_roi_stat_frame_ctrl(csr_bsp, roi, 1);
}

void is_path_bsp_get_y_hist_roi_stat(int path, struct is_bsp_y_hist_roi_stat *stat)
{
	volatile struct csr_bank_bsp *csr = g_earlyvideo_drvdata.is_csr.bsp[path];

	stat->overflow = csr->y_hist_overflow;
	stat->hist[0] = csr->y_hist_hist_0;
	stat->hist[1] = csr->y_hist_hist_1;
	stat->hist[2] = csr->y_hist_hist_2;
	stat->hist[3] = csr->y_hist_hist_3;
	stat->hist[4] = csr->y_hist_hist_4;
	stat->hist[5] = csr->y_hist_hist_5;
	stat->hist[6] = csr->y_hist_hist_6;
	stat->hist[7] = csr->y_hist_hist_7;
	stat->hist[8] = csr->y_hist_hist_8;
	stat->hist[9] = csr->y_hist_hist_9;
	stat->hist[10] = csr->y_hist_hist_10;
	stat->hist[11] = csr->y_hist_hist_11;
	stat->hist[12] = csr->y_hist_hist_12;
	stat->hist[13] = csr->y_hist_hist_13;
	stat->hist[14] = csr->y_hist_hist_14;
	stat->hist[15] = csr->y_hist_hist_15;
	stat->hist[16] = csr->y_hist_hist_16;
	stat->hist[17] = csr->y_hist_hist_17;
	stat->hist[18] = csr->y_hist_hist_18;
	stat->hist[19] = csr->y_hist_hist_19;
	stat->hist[20] = csr->y_hist_hist_20;
	stat->hist[21] = csr->y_hist_hist_21;
	stat->hist[22] = csr->y_hist_hist_22;
	stat->hist[23] = csr->y_hist_hist_23;
	stat->hist[24] = csr->y_hist_hist_24;
	stat->hist[25] = csr->y_hist_hist_25;
	stat->hist[26] = csr->y_hist_hist_26;
	stat->hist[27] = csr->y_hist_hist_27;
	stat->hist[28] = csr->y_hist_hist_28;
	stat->hist[29] = csr->y_hist_hist_29;
	stat->hist[30] = csr->y_hist_hist_30;
	stat->hist[31] = csr->y_hist_hist_31;
	stat->hist[32] = csr->y_hist_hist_32;
	stat->hist[33] = csr->y_hist_hist_33;
	stat->hist[34] = csr->y_hist_hist_34;
	stat->hist[35] = csr->y_hist_hist_35;
	stat->hist[36] = csr->y_hist_hist_36;
	stat->hist[37] = csr->y_hist_hist_37;
	stat->hist[38] = csr->y_hist_hist_38;
	stat->hist[39] = csr->y_hist_hist_39;
	stat->hist[40] = csr->y_hist_hist_40;
	stat->hist[41] = csr->y_hist_hist_41;
	stat->hist[42] = csr->y_hist_hist_42;
	stat->hist[43] = csr->y_hist_hist_43;
	stat->hist[44] = csr->y_hist_hist_44;
	stat->hist[45] = csr->y_hist_hist_45;
	stat->hist[46] = csr->y_hist_hist_46;
	stat->hist[47] = csr->y_hist_hist_47;
	stat->hist[48] = csr->y_hist_hist_48;
	stat->hist[49] = csr->y_hist_hist_49;
	stat->hist[50] = csr->y_hist_hist_50;
	stat->hist[51] = csr->y_hist_hist_51;
	stat->hist[52] = csr->y_hist_hist_52;
	stat->hist[53] = csr->y_hist_hist_53;
	stat->hist[54] = csr->y_hist_hist_54;
	stat->hist[55] = csr->y_hist_hist_55;
	stat->hist[56] = csr->y_hist_hist_56;
	stat->hist[57] = csr->y_hist_hist_57;
	stat->hist[58] = csr->y_hist_hist_58;
	stat->hist[59] = csr->y_hist_hist_59;
}

void is_path_bsp_get_y_avg_roi_stat(int path, uint8_t idx, struct is_bsp_y_avg_roi_stat *stat)
{
	volatile struct csr_bank_bsp *csr = g_earlyvideo_drvdata.is_csr.bsp[path];

	switch (idx) {
	case 0:
		stat->avg = csr->roi_0_y_avg_avg;
		stat->remainder = csr->roi_0_y_avg_remainder;
		break;
	case 1:
		stat->avg = csr->roi_1_y_avg_avg;
		stat->remainder = csr->roi_1_y_avg_remainder;
		break;
	case 2:
		stat->avg = csr->roi_2_y_avg_avg;
		stat->remainder = csr->roi_2_y_avg_remainder;
		break;
	case 3:
		stat->avg = csr->roi_3_y_avg_avg;
		stat->remainder = csr->roi_3_y_avg_remainder;
		break;
	default:
		break;
	}
}

void is_initBspHwReg(volatile CsrBankBsp *csr, int width, int height)
{
	struct res bsp_res = {
		.width = width,
		.height = height,
	};
	struct is_input_format in = {
		.mode = IS_PIXEL_FORMAT_I_BAYER,
		.bayer = INI_BAYER_PHASE_B,
		.cfa = {
			CFA_PHASE_G0, CFA_PHASE_G0, CFA_PHASE_G0, CFA_PHASE_G0,
			CFA_PHASE_G0, CFA_PHASE_G0, CFA_PHASE_G0, CFA_PHASE_G0,
			CFA_PHASE_G0, CFA_PHASE_G0, CFA_PHASE_G0, CFA_PHASE_G0,
			CFA_PHASE_G0, CFA_PHASE_G0, CFA_PHASE_G0, CFA_PHASE_G0,
		},
	};
	struct is_output_format out = {
		.mode = IS_PIXEL_FORMAT_O_BAYER,
		.bayer = INI_BAYER_PHASE_B,
	};
	struct rect_point bsp_roi = {
		.sx = 0,
		.sy = 0,
		.ex = bsp_res.width - 1,
		.ey = bsp_res.height - 1,
	};
	struct is_bsp_y_hist_roi_ctrl y_hist_roi_ctrl = {
		.mode = IS_LUMA_INPUT_MODE_AVG,
		.offset = 0,
	};
	struct is_bsp_y_avg_roi_ctrl y_avg_roi_ctrl = {
		.mode = IS_LUMA_INPUT_MODE_AVG,
	};
	// uint8_t stat_enable = 1;

	__bsp_set_res(csr, &bsp_res);
	__bsp_set_input_format(csr, &in);
	__bsp_set_output_format(csr, &out);

	csr->sdpd_enable = 0;
	csr->sdpd_offset_x = 0;
	csr->sdpd_offset_y = 0;
	csr->ddpd_enable = 0;
	csr->ddpd_g_pattern_mode = 0;
	csr->ddpd_pix_num_mode = 1;
	csr->ddpd_diff_ratio = 0;
	csr->ddpd_avg_ratio = 0;
	csr->ddpd_edge_diff_ratio = 0;
	csr->ddpd_edge_avg_ratio = 0;
	csr->ddpd_edge_m = 2;
	csr->ddpd_dp_num = 0;
	csr->dpc_enable = 0;
	csr->dpc_dir_enable = 1;
	csr->dpc_dir_th_ratio = 0;
	csr->dpc_dir_str_m = 120;
	csr->ct_enable = 0;
	csr->ct_avg_lb = 256;
	csr->ct_avg_ratio = 16;
	csr->ct_str_lb = 256;
	csr->ct_str_ratio = 16;
	csr->ct_str_m = 0;
	csr->channel_weight_00 = 1;
	csr->channel_weight_01 = 4;
	csr->channel_weight_02 = 6;
	csr->channel_weight_11 = 16;
	csr->channel_weight_12 = 24;
	csr->channel_weight_22 = 36;
	csr->remos_enable = 1;
	csr->remos_r_r_coeff_2s = 4096;
	csr->remos_r_g_coeff_2s = 0;
	csr->remos_r_b_coeff_2s = 0;
	csr->remos_r_s_coeff_2s = 0;
	csr->remos_g_r_coeff_2s = 0;
	csr->remos_g_g_coeff_2s = 4096;
	csr->remos_g_b_coeff_2s = 0;
	csr->remos_g_s_coeff_2s = 0;
	csr->remos_b_r_coeff_2s = 0;
	csr->remos_b_g_coeff_2s = 0;
	csr->remos_b_b_coeff_2s = 4096;
	csr->remos_b_s_coeff_2s = 0;
	csr->y_est_mode = 0;
	csr->y_r_weight = 8;
	csr->y_g_weight = 16;
	csr->y_b_weight = 8;
	csr->y_s_weight = 0;

	__bsp_set_y_hist_roi_ctrl(csr, &y_hist_roi_ctrl);
	__bsp_set_y_avg_roi_ctrl(csr, &y_avg_roi_ctrl);
	__reg_bsp_calc_stat_frame_ctrl(csr, &bsp_roi);
	// is_bsp_set_y_hist_roi_stat_enable(csr, stat_enable);
	csr->y_hist_roi_en = 1;
	// is_bsp_set_y_avg_roi_stat_enable(csr, 0, stat_enable);
	csr->roi_0_y_avg_en = 1;
}

/* DBC */
void is_dbc_set_cfg(volatile CsrBankDbc *csr, const struct is_dbc_cfg *cfg)
{
	csr->mode = cfg->mode;
	csr->level_g0 = cfg->level[CFA_PHASE_G0];
	csr->level_r = cfg->level[CFA_PHASE_R];
	csr->level_b = cfg->level[CFA_PHASE_B];
	csr->level_g1 = cfg->level[CFA_PHASE_G1];
	csr->level_s = cfg->level[CFA_PHASE_S];
}

/* DCC */
void is_dcc_set_cfg(volatile CsrBankDcc *csr, const struct is_dcc_cfg *cfg)
{
	csr->mode = cfg->mode;
	csr->gain_g0 = cfg->gain[CFA_PHASE_G0];
	csr->gain_r = cfg->gain[CFA_PHASE_R];
	csr->gain_b = cfg->gain[CFA_PHASE_B];
	csr->gain_g1 = cfg->gain[CFA_PHASE_G1];
	csr->gain_s = cfg->gain[CFA_PHASE_S];
	csr->offset_g0_2s = cfg->offset_2s[CFA_PHASE_G0];
	csr->offset_r_2s = cfg->offset_2s[CFA_PHASE_R];
	csr->offset_b_2s = cfg->offset_2s[CFA_PHASE_B];
	csr->offset_g1_2s = cfg->offset_2s[CFA_PHASE_G1];
	csr->offset_s_2s = cfg->offset_2s[CFA_PHASE_S];
}

void is_dcc_set_gain_curve_cfg(volatile CsrBankDcc *csr, const enum cfa_phase phase,
                               const struct is_dcc_gain_curve_cfg *cfg)
{
	switch (phase) {
	case CFA_PHASE_G0:
		// mapping_curve_g0_x_ini is always equal 0
		csr->mapping_curve_g0_x_0 = cfg->x[1];
		csr->mapping_curve_g0_x_1 = cfg->x[2];
		csr->mapping_curve_g0_x_2 = cfg->x[3];
		csr->mapping_curve_g0_x_3 = cfg->x[4];
		csr->mapping_curve_g0_x_4 = cfg->x[5];
		csr->mapping_curve_g0_x_5 = cfg->x[6];
		csr->mapping_curve_g0_x_6 = cfg->x[7];
		csr->mapping_curve_g0_x_7 = cfg->x[8];
		csr->mapping_curve_g0_y_ini = cfg->y[0];
		csr->mapping_curve_g0_y_0 = cfg->y[1];
		csr->mapping_curve_g0_y_1 = cfg->y[2];
		csr->mapping_curve_g0_y_2 = cfg->y[3];
		csr->mapping_curve_g0_y_3 = cfg->y[4];
		csr->mapping_curve_g0_y_4 = cfg->y[5];
		csr->mapping_curve_g0_y_5 = cfg->y[6];
		csr->mapping_curve_g0_y_6 = cfg->y[7];
		csr->mapping_curve_g0_y_7 = cfg->y[8];
		csr->mapping_curve_g0_m_0 = cfg->m[0];
		csr->mapping_curve_g0_m_1 = cfg->m[1];
		csr->mapping_curve_g0_m_2 = cfg->m[2];
		csr->mapping_curve_g0_m_3 = cfg->m[3];
		csr->mapping_curve_g0_m_4 = cfg->m[4];
		csr->mapping_curve_g0_m_5 = cfg->m[5];
		csr->mapping_curve_g0_m_6 = cfg->m[6];
		csr->mapping_curve_g0_m_7 = cfg->m[7];
		break;
	case CFA_PHASE_R:
		// mapping_curve_r_x_ini is always equal 0
		csr->mapping_curve_r_x_0 = cfg->x[1];
		csr->mapping_curve_r_x_1 = cfg->x[2];
		csr->mapping_curve_r_x_2 = cfg->x[3];
		csr->mapping_curve_r_x_3 = cfg->x[4];
		csr->mapping_curve_r_x_4 = cfg->x[5];
		csr->mapping_curve_r_x_5 = cfg->x[6];
		csr->mapping_curve_r_x_6 = cfg->x[7];
		csr->mapping_curve_r_x_7 = cfg->x[8];
		csr->mapping_curve_r_y_ini = cfg->y[0];
		csr->mapping_curve_r_y_0 = cfg->y[1];
		csr->mapping_curve_r_y_1 = cfg->y[2];
		csr->mapping_curve_r_y_2 = cfg->y[3];
		csr->mapping_curve_r_y_3 = cfg->y[4];
		csr->mapping_curve_r_y_4 = cfg->y[5];
		csr->mapping_curve_r_y_5 = cfg->y[6];
		csr->mapping_curve_r_y_6 = cfg->y[7];
		csr->mapping_curve_r_y_7 = cfg->y[8];
		csr->mapping_curve_r_m_0 = cfg->m[0];
		csr->mapping_curve_r_m_1 = cfg->m[1];
		csr->mapping_curve_r_m_2 = cfg->m[2];
		csr->mapping_curve_r_m_3 = cfg->m[3];
		csr->mapping_curve_r_m_4 = cfg->m[4];
		csr->mapping_curve_r_m_5 = cfg->m[5];
		csr->mapping_curve_r_m_6 = cfg->m[6];
		csr->mapping_curve_r_m_7 = cfg->m[7];
		break;
	case CFA_PHASE_B:
		// mapping_curve_b_x_ini is always equal 0
		csr->mapping_curve_b_x_0 = cfg->x[1];
		csr->mapping_curve_b_x_1 = cfg->x[2];
		csr->mapping_curve_b_x_2 = cfg->x[3];
		csr->mapping_curve_b_x_3 = cfg->x[4];
		csr->mapping_curve_b_x_4 = cfg->x[5];
		csr->mapping_curve_b_x_5 = cfg->x[6];
		csr->mapping_curve_b_x_6 = cfg->x[7];
		csr->mapping_curve_b_x_7 = cfg->x[8];
		csr->mapping_curve_b_y_ini = cfg->y[0];
		csr->mapping_curve_b_y_0 = cfg->y[1];
		csr->mapping_curve_b_y_1 = cfg->y[2];
		csr->mapping_curve_b_y_2 = cfg->y[3];
		csr->mapping_curve_b_y_3 = cfg->y[4];
		csr->mapping_curve_b_y_4 = cfg->y[5];
		csr->mapping_curve_b_y_5 = cfg->y[6];
		csr->mapping_curve_b_y_6 = cfg->y[7];
		csr->mapping_curve_b_y_7 = cfg->y[8];
		csr->mapping_curve_b_m_0 = cfg->m[0];
		csr->mapping_curve_b_m_1 = cfg->m[1];
		csr->mapping_curve_b_m_2 = cfg->m[2];
		csr->mapping_curve_b_m_3 = cfg->m[3];
		csr->mapping_curve_b_m_4 = cfg->m[4];
		csr->mapping_curve_b_m_5 = cfg->m[5];
		csr->mapping_curve_b_m_6 = cfg->m[6];
		csr->mapping_curve_b_m_7 = cfg->m[7];
		break;
	case CFA_PHASE_G1:
		// mapping_curve_g1_x_ini is always equal 0
		csr->mapping_curve_g1_x_0 = cfg->x[1];
		csr->mapping_curve_g1_x_1 = cfg->x[2];
		csr->mapping_curve_g1_x_2 = cfg->x[3];
		csr->mapping_curve_g1_x_3 = cfg->x[4];
		csr->mapping_curve_g1_x_4 = cfg->x[5];
		csr->mapping_curve_g1_x_5 = cfg->x[6];
		csr->mapping_curve_g1_x_6 = cfg->x[7];
		csr->mapping_curve_g1_x_7 = cfg->x[8];
		csr->mapping_curve_g1_y_ini = cfg->y[0];
		csr->mapping_curve_g1_y_0 = cfg->y[1];
		csr->mapping_curve_g1_y_1 = cfg->y[2];
		csr->mapping_curve_g1_y_2 = cfg->y[3];
		csr->mapping_curve_g1_y_3 = cfg->y[4];
		csr->mapping_curve_g1_y_4 = cfg->y[5];
		csr->mapping_curve_g1_y_5 = cfg->y[6];
		csr->mapping_curve_g1_y_6 = cfg->y[7];
		csr->mapping_curve_g1_y_7 = cfg->y[8];
		csr->mapping_curve_g1_m_0 = cfg->m[0];
		csr->mapping_curve_g1_m_1 = cfg->m[1];
		csr->mapping_curve_g1_m_2 = cfg->m[2];
		csr->mapping_curve_g1_m_3 = cfg->m[3];
		csr->mapping_curve_g1_m_4 = cfg->m[4];
		csr->mapping_curve_g1_m_5 = cfg->m[5];
		csr->mapping_curve_g1_m_6 = cfg->m[6];
		csr->mapping_curve_g1_m_7 = cfg->m[7];
		break;
	case CFA_PHASE_S:
		// mapping_curve_s_x_ini is always equal 0
		csr->mapping_curve_s_x_0 = cfg->x[1];
		csr->mapping_curve_s_x_1 = cfg->x[2];
		csr->mapping_curve_s_x_2 = cfg->x[3];
		csr->mapping_curve_s_x_3 = cfg->x[4];
		csr->mapping_curve_s_x_4 = cfg->x[5];
		csr->mapping_curve_s_x_5 = cfg->x[6];
		csr->mapping_curve_s_x_6 = cfg->x[7];
		csr->mapping_curve_s_x_7 = cfg->x[8];
		csr->mapping_curve_s_y_ini = cfg->y[0];
		csr->mapping_curve_s_y_0 = cfg->y[1];
		csr->mapping_curve_s_y_1 = cfg->y[2];
		csr->mapping_curve_s_y_2 = cfg->y[3];
		csr->mapping_curve_s_y_3 = cfg->y[4];
		csr->mapping_curve_s_y_4 = cfg->y[5];
		csr->mapping_curve_s_y_5 = cfg->y[6];
		csr->mapping_curve_s_y_6 = cfg->y[7];
		csr->mapping_curve_s_y_7 = cfg->y[8];
		csr->mapping_curve_s_m_0 = cfg->m[0];
		csr->mapping_curve_s_m_1 = cfg->m[1];
		csr->mapping_curve_s_m_2 = cfg->m[2];
		csr->mapping_curve_s_m_3 = cfg->m[3];
		csr->mapping_curve_s_m_4 = cfg->m[4];
		csr->mapping_curve_s_m_5 = cfg->m[5];
		csr->mapping_curve_s_m_6 = cfg->m[6];
		csr->mapping_curve_s_m_7 = cfg->m[7];
		break;
	default:
		break;
	}
}