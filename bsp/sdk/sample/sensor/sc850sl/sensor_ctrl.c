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
#include "sensor_settings.h"
#include "sensor_params.h"
#include "sensor_lvds.h"

#ifdef DUAL_SENSOR_SUPPORT
static int g_i2c_fd[2] = {
	-1,
	-1,
};

static const uint16_t k_i2c_slave_addr[2] = {
	SENSOR_I2C_SLAVE_ADDR,
	SENSOR_I2C_SLAVE_ADDR1,
};
#else
static int g_i2c_fd[1] = {
	-1,
};

static const uint16_t k_i2c_slave_addr[1] = {
	SENSOR_I2C_SLAVE_ADDR,
};
#endif

// 3840x2160 30fps 4lane 10bits
static const SensCmd k_cmd_format[] = {
	{ 0x0103, 0x01 }, { SENSOR_DELAY_REG, 0x0a }, { 0x0100, 0x00 }, { 0x36e9, 0x80 },
	{ 0x36f9, 0x80 }, { 0x36ea, 0x0a },           { 0x36eb, 0x0c }, { 0x36ec, 0x4a },
	{ 0x36ed, 0x34 }, { 0x36fa, 0xcb },           { 0x36fb, 0x13 }, { 0x36fc, 0x00 },
	{ 0x36fd, 0x07 }, { 0x36e9, 0x20 },           { 0x36f9, 0x53 }, { 0x3018, 0x7a },
	{ 0x3019, 0xf0 }, { 0x301a, 0x30 },           { 0x301e, 0x3c }, { 0x301f, 0x21 },
	{ 0x302a, 0x00 }, { 0x3031, 0x0a },           { 0x3032, 0x20 }, { 0x3033, 0x22 },
	{ 0x3037, 0x00 }, { 0x303e, 0xb4 },           { 0x320c, 0x04 }, { 0x320d, 0x4c },
	{ 0x3226, 0x00 }, { 0x3227, 0x03 },           { 0x3250, 0x40 }, { 0x3253, 0x08 },
	{ 0x327e, 0x00 }, { 0x3280, 0x00 },           { 0x3281, 0x00 }, { 0x3301, 0x3c },
	{ 0x3304, 0x30 }, { 0x3306, 0xe8 },           { 0x3308, 0x10 }, { 0x3309, 0x70 },
	{ 0x330a, 0x01 }, { 0x330b, 0xe0 },           { 0x330d, 0x10 }, { 0x3314, 0x92 },
	{ 0x331e, 0x29 }, { 0x331f, 0x69 },           { 0x3333, 0x10 }, { 0x3347, 0x05 },
	{ 0x3348, 0xd0 }, { 0x3352, 0x01 },           { 0x3356, 0x38 }, { 0x335d, 0x60 },
	{ 0x3362, 0x70 }, { 0x338f, 0x80 },           { 0x33af, 0x48 }, { 0x33fe, 0x00 },
	{ 0x3400, 0x12 }, { 0x3406, 0x04 },           { 0x3410, 0x12 }, { 0x3416, 0x06 },
	{ 0x3433, 0x01 }, { 0x3440, 0x12 },           { 0x3446, 0x08 }, { 0x3478, 0x01 },
	{ 0x3479, 0x01 }, { 0x347a, 0x02 },           { 0x347b, 0x01 }, { 0x347c, 0x04 },
	{ 0x347d, 0x01 }, { 0x3616, 0x0c },           { 0x3620, 0x92 }, { 0x3622, 0x74 },
	{ 0x3629, 0x74 }, { 0x362a, 0xf0 },           { 0x362b, 0x0f }, { 0x362d, 0x00 },
	{ 0x3630, 0x68 }, { 0x3633, 0x22 },           { 0x3634, 0x22 }, { 0x3635, 0x20 },
	{ 0x3637, 0x06 }, { 0x3638, 0x26 },           { 0x363b, 0x06 }, { 0x363c, 0x07 },
	{ 0x363d, 0x05 }, { 0x363e, 0x8f },           { 0x3648, 0xe0 }, { 0x3649, 0x0a },
	{ 0x364a, 0x06 }, { 0x364c, 0x6a },           { 0x3650, 0x3d }, { 0x3654, 0x40 },
	{ 0x3656, 0x68 }, { 0x3657, 0x0f },           { 0x3658, 0x3d }, { 0x365c, 0x40 },
	{ 0x365e, 0x68 }, { 0x3901, 0x04 },           { 0x3904, 0x20 }, { 0x3905, 0x91 },
	{ 0x391e, 0x83 }, { 0x3928, 0x04 },           { 0x3933, 0x90 }, { 0x3934, 0x10 },
	{ 0x3935, 0x70 }, { 0x3936, 0x00 },           { 0x3937, 0x10 }, { 0x3938, 0x14 },
	{ 0x3946, 0x20 }, { 0x3961, 0x40 },           { 0x3962, 0x40 }, { 0x3963, 0xc8 },
	{ 0x3964, 0xc8 }, { 0x3965, 0x40 },           { 0x3966, 0x40 }, { 0x3967, 0x00 },
	{ 0x39cd, 0xc8 }, { 0x39ce, 0xc8 },           { 0x3e01, 0x82 }, { 0x3e02, 0x00 },
	{ 0x3e0e, 0x02 }, { 0x3e0f, 0x00 },           { 0x3e1c, 0x0f }, { 0x3e23, 0x00 },
	{ 0x3e24, 0x00 }, { 0x3e53, 0x00 },           { 0x3e54, 0x00 }, { 0x3e68, 0x00 },
	{ 0x3e69, 0x80 }, { 0x3e73, 0x00 },           { 0x3e74, 0x00 }, { 0x3e86, 0x03 },
	{ 0x3e87, 0x40 }, { 0x3f02, 0x24 },           { 0x4424, 0x02 }, { 0x4501, 0xc4 },
	{ 0x4509, 0x20 }, { 0x4561, 0x12 },           { 0x4800, 0x24 }, { 0x4837, 0x16 },
	{ 0x4900, 0x24 }, { 0x4937, 0x16 },           { 0x5000, 0x0e }, { 0x500f, 0x35 },
	{ 0x5020, 0x00 }, { 0x5787, 0x10 },           { 0x5788, 0x06 }, { 0x5789, 0x00 },
	{ 0x578a, 0x18 }, { 0x578b, 0x0c },           { 0x578c, 0x00 }, { 0x5790, 0x10 },
	{ 0x5791, 0x06 }, { 0x5792, 0x01 },           { 0x5793, 0x18 }, { 0x5794, 0x0c },
	{ 0x5795, 0x01 }, { 0x5799, 0x06 },           { 0x57a2, 0x60 }, { 0x59e0, 0xfe },
	{ 0x59e1, 0x40 }, { 0x59e2, 0x38 },           { 0x59e3, 0x30 }, { 0x59e4, 0x20 },
	{ 0x59e5, 0x38 }, { 0x59e6, 0x30 },           { 0x59e7, 0x20 }, { 0x59e8, 0x3f },
	{ 0x59e9, 0x38 }, { 0x59ea, 0x30 },           { 0x59eb, 0x3f }, { 0x59ec, 0x38 },
	{ 0x59ed, 0x30 }, { 0x59ee, 0xfe },           { 0x59ef, 0x40 }, { 0x59f4, 0x38 },
	{ 0x59f5, 0x30 }, { 0x59f6, 0x20 },           { 0x59f7, 0x38 }, { 0x59f8, 0x30 },
	{ 0x59f9, 0x20 }, { 0x59fa, 0x3f },           { 0x59fb, 0x38 }, { 0x59fc, 0x30 },
	{ 0x59fd, 0x3f }, { 0x59fe, 0x38 },           { 0x59ff, 0x30 }
};

static const SensCmd k_cmd_start[] = {
	{ 0x0100, 0x01 },
};

static const SensCmd k_cmd_stop[] = {
	{ 0x0100, 0x00 },
};

static void SENSOR_configInitSeq(uint8_t path_idx)
{
	int fd = g_i2c_fd[path_idx];

	SENSOR_writeSeqWaddrBdata(fd, sizeof(k_cmd_format) / sizeof(SensCmd), k_cmd_format, k_i2c_slave_addr[path_idx]);

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

	/* No need to wait according to vendor's comment */
	//	usleep(380000);

	SENSOR_writeSeqWaddrBdata(fd, sizeof(k_cmd_start) / sizeof(SensCmd), k_cmd_start, k_i2c_slave_addr[path_idx]);
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
	p->bit_width = MPI_BITS_10;
	p->intf_ptcl = MPI_INTF_PTCL_MIPI;
	p->ptcl_mode = MPI_MIPI_CSI2;
	p->hsync_plty = MPI_PLTY_HIGH;
	p->vsync_plty = MPI_PLTY_HIGH;
	p->bayer = MPI_BAYER_PHASE_B;
	p->ext_clk_freq = SENSOR_EXT_CLK_FREQ;
	p->sensor_res.width = SENSOR_WIDTH;
	p->sensor_res.height = SENSOR_HEIGHT;
	p->sensor_fps = SENSOR_FPS;
	p->frame_len_line = INIT_FRAME_LINE;
	p->i2c_slv_addr = k_i2c_slave_addr[path_idx];
	p->ob_enable = 0;
	p->reserved = 0;

	memcpy(&p->parl_lane, &k_parl_lane[path_idx], sizeof(MPI_PARL_LANE_INFO_S));
	memcpy(&p->serl_lane[0], &k_serl_lane[path_idx], MPI_MAX_LVDSRX_LANE_NUM * sizeof(MPI_SERL_LANE_INFO_S));
	SENSOR_getLvdsDelay(sns_idx, p->serl_lane);

	p->mipi.bp_img.hor = 0;
	p->mipi.bp_img.ver = 0;
	p->mipi.fp_img.hor = 0;
	p->mipi.fp_img.ver = 0;

	p->mipi.ob_conf.skipped_line_num = 0;
	p->mipi.ob_conf.pos = MPI_POS_NONE;
	p->mipi.ob_conf.region.x = 0;
	p->mipi.ob_conf.region.y = 0;
	p->mipi.ob_conf.region.width = 0;
	p->mipi.ob_conf.region.height = 0;

	p->mipi.vc_bmp = 0x1;
	p->mipi.dt_bmp = 0x0;
	p->mipi.t_hs_settle = 0xA;
	p->mipi.t_hs_settle_ns = T_HS_SETTLE_NS;
	p->mipi.t_d_term_en_ns = T_D_TERM_EN_NS;
	p->mipi.t_clk_settle_ns = T_CLK_SETTLE_NS;
	p->mipi.t_clk_term_en_ns = T_CLK_TERM_EN_NS;

	return MPI_SUCCESS;
}
