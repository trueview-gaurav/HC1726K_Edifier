/******************************************************************************
 * *
 * * Copyright (c) Augentix Inc. - All Rights Reserved
 * *
 * * Unauthorized copying of this file, via any medium is strictly prohibited.
 * *
 * * Proprietary and confidential.
 * *
 * *****************************************************************************/

#include "sensor.h"
#include <stdio.h>
#include <unistd.h>
#include <stdint.h>
#include <string.h>
#include "sensor_params.h"
#include "sensor_settings.h"
#include "sensor_lvds.h"

static int g_i2c_fd[1] = {
	-1,
};

static const uint16_t k_i2c_slave_addr[1] = {
	SENSOR_I2C_SLAVE_ADDR,
};

#if SET_3840_2160_30fps_4lane
static const SensCmd k_cmd_format_4lane_30fps[] = {
	{ 0x3000, 0x01 }, { 0x3001, 0x00 }, { 0x3002, 0x00 }, { 0x3014, 0x04 }, { 0x3015, 0x05 }, { 0x3018, 0x10 },
	{ 0x301A, 0x00 }, { 0x301B, 0x00 }, { 0x301C, 0x00 }, { 0x3020, 0x00 }, { 0x3021, 0x00 }, { 0x3022, 0x02 },
	{ 0x3023, 0x01 }, { 0x3024, 0x00 }, { 0x3028, 0xCA }, { 0x3029, 0x08 }, { 0x302A, 0x00 }, { 0x302C, 0x4C },
	{ 0x302D, 0x04 }, { 0x3030, 0x00 }, { 0x3031, 0x00 }, { 0x3032, 0x00 }, { 0x303C, 0x00 }, { 0x303D, 0x00 },
	{ 0x303E, 0x10 }, { 0x303F, 0x0F }, { 0x3040, 0x03 }, { 0x3042, 0x00 }, { 0x3043, 0x00 }, { 0x3044, 0x00 },
	{ 0x3045, 0x00 }, { 0x3046, 0x84 }, { 0x3047, 0x08 }, { 0x3050, 0x08 }, { 0x3051, 0x00 }, { 0x3052, 0x00 },
	{ 0x3054, 0x0E }, { 0x3055, 0x00 }, { 0x3056, 0x00 }, { 0x3058, 0x8A }, { 0x3059, 0x01 }, { 0x305A, 0x00 },
	{ 0x3060, 0x16 }, { 0x3061, 0x01 }, { 0x3062, 0x00 }, { 0x3064, 0xC4 }, { 0x3065, 0x0C }, { 0x3066, 0x00 },
	{ 0x3069, 0x00 }, { 0x306A, 0x00 }, { 0x306C, 0x00 }, { 0x306D, 0x00 }, { 0x306E, 0x00 }, { 0x306F, 0x00 },
	{ 0x3070, 0x00 }, { 0x3071, 0x00 }, { 0x3074, 0x64 }, { 0x3081, 0x00 }, { 0x308C, 0x00 }, { 0x308D, 0x01 },
	{ 0x3094, 0x00 }, { 0x3095, 0x00 }, { 0x3096, 0x00 }, { 0x3097, 0x00 }, { 0x309C, 0x00 }, { 0x309D, 0x00 },
	{ 0x30A4, 0xAA }, { 0x30A6, 0x00 }, { 0x30CC, 0x00 }, { 0x30CD, 0x00 }, { 0x30D5, 0x04 }, { 0x30DC, 0x32 },
	{ 0x30DD, 0x00 }, { 0x3400, 0x01 }, { 0x3444, 0xFF }, { 0x3445, 0x07 }, { 0x3460, 0x21 }, { 0x3478, 0xA1 },
	{ 0x347C, 0x01 }, { 0x3480, 0x01 }, { 0x36D0, 0x00 }, { 0x36D1, 0x10 }, { 0x36D4, 0x00 }, { 0x36D5, 0x10 },
	{ 0x36E2, 0x00 }, { 0x36E4, 0x00 }, { 0x36E5, 0x00 }, { 0x36E6, 0x00 }, { 0x36E8, 0x00 }, { 0x36E9, 0x00 },
	{ 0x36EA, 0x00 }, { 0x36EC, 0x00 }, { 0x36EE, 0x00 }, { 0x36EF, 0x00 }, { 0x3930, 0x0C }, { 0x3931, 0x01 },
	{ 0x3A26, 0x00 }, { 0x3A2A, 0x06 }, { 0x3AA4, 0x76 }, { 0x3AA6, 0x6A }, { 0x3AAC, 0x6A }, { 0x3AAE, 0x72 },
	{ 0x3AB0, 0x2D }, { 0x3AB2, 0x2D }, { 0x3B5A, 0x44 }, { 0x3C06, 0x96 }, { 0x3C3A, 0x94 }, { 0x3C84, 0xBD },
	{ 0x3C8C, 0xBD }, { 0x3E48, 0xA6 }, { 0x3E4C, 0xA6 }, { 0x3E56, 0x9A }, { 0x3E5A, 0x9A }, { 0x3F0A, 0x94 },
	{ 0x3F3A, 0x8C }, { 0x3F7E, 0x99 }, { 0x3F90, 0x8E }, { 0x3F92, 0x92 }, { 0x3FCA, 0x98 }, { 0x4142, 0x77 },
	{ 0x4143, 0xC7 }, { 0x421E, 0xA0 }, { 0x421F, 0x06 }, { 0x43A2, 0x91 }, { 0x43A6, 0x8B }, { 0x43B2, 0x91 },
	{ 0x43C0, 0x93 }, { 0x43C4, 0x8D }, { 0x43D0, 0x93 }, { 0x4408, 0xE1 }, { 0x452D, 0x34 }, { 0x471C, 0x08 },
	{ 0x47EB, 0x1C }, { 0x4844, 0xA4 }, { 0x4846, 0x9C }, { 0x4848, 0x98 }, { 0x484A, 0x92 }, { 0x484C, 0x8E },
	{ 0x484E, 0x88 }, { 0x4850, 0x82 }, { 0x4852, 0x82 }, { 0x4854, 0xA0 }, { 0x4856, 0x96 }, { 0x4858, 0x96 },
	{ 0x485A, 0x1A }, { 0x485C, 0x1A }, { 0x485E, 0x1A }, { 0x4860, 0x1A }, { 0x4862, 0x1A }, { 0x4864, 0x82 },
	{ 0x4866, 0x82 }, { 0x4868, 0x82 }, { 0x486A, 0x7C }, { 0x486C, 0x72 }, { 0x486E, 0x68 }, { 0x4870, 0x68 },
	{ 0x4872, 0x68 }, { 0x4874, 0x72 }, { 0x4876, 0x72 }, { 0x4878, 0x72 }, { 0x487A, 0x33 }, { 0x487C, 0x33 },
	{ 0x487E, 0x33 }, { 0x4880, 0x33 }, { 0x4882, 0x33 }, { 0x492C, 0xE2 }, { 0x492E, 0xD6 }, { 0x4930, 0x00 },
	{ 0x493C, 0x2D }, { 0x4940, 0x2D }, { 0x4DC1, 0x80 }, { 0x4DC2, 0x88 }, { 0x5B00, 0x11 }, { 0x5B3C, 0x07 },
};

#endif

static const SensCmd k_cmd_start[] = {
	{ 0x3000, 0x00 }, // operating mode
};

static const SensCmd k_cmd_stop[] = {
	{ 0x3000, 0x01 } //standby mode
};

static void SENSOR_configInitSeq(uint8_t path_idx)
{
	int fd = g_i2c_fd[path_idx];

	SENSOR_writeSeqWaddrBdata(fd, sizeof(k_cmd_format_4lane_30fps) / sizeof(SensCmd), k_cmd_format_4lane_30fps,
	                          k_i2c_slave_addr[path_idx]);

	/* Light up sensor, please comment this line */
	switch (path_idx) {
#ifdef SNS0
	case SNS0_ID:
		cmos_ctrl(SNS0_ID).update_exp_cmd(fd, path_idx);
		break;
#endif
#ifdef SNS1
	case SNS1_ID:
		cmos_ctrl(SNS1_ID).update_exp_cmd(fd, path_idx);
		break;
#endif
	default:
		break;
	}

	SENSOR_writeSeqWaddrBdata(fd, sizeof(k_cmd_start) / sizeof(SensCmd), k_cmd_start, k_i2c_slave_addr[path_idx]);

	/* Sensor needs 8 frames to output stable image */
	/* Not really have to skip those but should notice that there is a concern. */
	//	usleep(320000);
}

static void SENSOR_configExitSeq(uint8_t path_idx)
{
	int fd = g_i2c_fd[path_idx];

	SENSOR_writeSeqWaddrBdata(fd, sizeof(k_cmd_stop) / sizeof(SensCmd), k_cmd_stop, k_i2c_slave_addr[path_idx]);
}

/* Global Interface */
void SENSOR_configInit(uint8_t path_idx)
{
	int ret = 0;
	int i2c_fd = -1;

	/* Open I2C device node */
	ret = SENSOR_openI2cDev(&i2c_fd, k_i2c_slave_addr[path_idx]);
	if (ret != MPI_SUCCESS) {
		return;
	}

	g_i2c_fd[path_idx] = i2c_fd;

	/* Start sensor */
	SENSOR_configInitSeq(path_idx);
}

void SENSOR_configExit(uint8_t path_idx)
{
	int ret = 0;
	int i2c_fd = g_i2c_fd[path_idx];

	/* Stop sensor */
	SENSOR_configExitSeq(path_idx);

	/* Close I2C device node */
	ret = SENSOR_closeI2cDev(i2c_fd);
	if (ret != MPI_SUCCESS) {
		return;
	}

	g_i2c_fd[path_idx] = -1;
}

int32_t SENSOR_getOpInfo(uint8_t path_idx, uint32_t sns_idx, MPI_SNS_OP_INFO_S *p_op_info)
{
	MPI_SNS_OP_INFO_S *p = p_op_info;

	p->sensor_mode = MPI_SNS_MODE_MASTER;
	p->slv_sync_src = MPI_SLV_SYNC_SRC_NONE;
	p->bit_width = MPI_BITS_12;
	p->intf_ptcl = MPI_INTF_PTCL_MIPI;
	p->ptcl_mode = MPI_MIPI_CSI2;
	p->hsync_plty = MPI_PLTY_HIGH;
	p->vsync_plty = MPI_PLTY_HIGH;
	p->bayer = MPI_BAYER_PHASE_R;
	p->ext_clk_freq = SENSOR_EXT_CLK_FREQ;

// (Datasheet IMX835-AAQR1-C_E_Datasheet_E23202C54.pdf Page 36 (All-pixel mode))
#if SET_3840_2160_30fps_4lane
	p->sensor_res.width = 3856; // 8 + 3840 + 8
	p->sensor_res.height = 2180; // 4+8 + 2160 + 8
#endif
	p->sensor_fps = (float)SENSOR_FPS;
	p->frame_len_line = INIT_FRAME_LINE;
	p->i2c_slv_addr = k_i2c_slave_addr[path_idx];
	p->ob_enable = 0;
	p->reserved = 0;

	memcpy(&p->parl_lane, &k_parl_lane[path_idx], sizeof(MPI_PARL_LANE_INFO_S));
	memcpy(&p->serl_lane[0], &k_serl_lane[path_idx], MPI_MAX_LVDSRX_LANE_NUM * sizeof(MPI_SERL_LANE_INFO_S));
	SENSOR_getLvdsDelay(sns_idx, p->serl_lane);

// (Datasheet IMX835-AAQR1-C_E_Datasheet_E23202C54.pdf Page 36 (All-pixel mode))
#if SET_3840_2160_30fps_4lane
	p->mipi.bp_img.hor = 8;
	p->mipi.bp_img.ver = 12; // 4+8
	p->mipi.fp_img.hor = 8;
	p->mipi.fp_img.ver = 8;
#endif

	p->mipi.bp_eff_pix.hor = 0;
	p->mipi.bp_eff_pix.ver = 0;

	p->mipi.ob_conf.skipped_line_num = 0;
	p->mipi.ob_conf.pos = MPI_POS_NONE;
	p->mipi.ob_conf.region.x = 0;
	p->mipi.ob_conf.region.y = 0;
	p->mipi.ob_conf.region.width = 0;
	p->mipi.ob_conf.region.height = 0;

	p->mipi.dt_bmp = 0x0;
	p->mipi.vc_bmp = 0x1;
	p->mipi.t_hs_settle = 0xA;
	p->mipi.t_hs_settle_ns = T_HS_SETTLE_NS;
	p->mipi.t_d_term_en_ns = T_D_TERM_EN_NS;
	p->mipi.t_clk_settle_ns = T_CLK_SETTLE_NS;
	p->mipi.t_clk_term_en_ns = T_CLK_TERM_EN_NS;

	return MPI_SUCCESS;
}
