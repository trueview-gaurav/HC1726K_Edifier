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
#include <stdint.h>
#include <string.h>

#include <unistd.h>

#include "sensor_settings.h"
#include "sensor_params.h"
#include "sensor_lvds.h"

#define SENSOR_PATH_MAX (4) // Should not be greater than MPI_MAX_INPUT_PATH_NUM

#if SENSOR_I2C_REG_LENGTH == 1 && SENSOR_I2C_DAT_LENGTH == 1
#define SENSOR_writeSeq(...) SENSOR_writeSeqBaddrBdata(__VA_ARGS__)
#elif SENSOR_I2C_REG_LENGTH == 1 && SENSOR_I2C_DAT_LENGTH == 2
#define SENSOR_writeSeq(...) SENSOR_writeSeqBaddrWdata(__VA_ARGS__)
#elif SENSOR_I2C_REG_LENGTH == 2 && SENSOR_I2C_DAT_LENGTH == 1
#define SENSOR_writeSeq(...) SENSOR_writeSeqWaddrBdata(__VA_ARGS__)
#elif SENSOR_I2C_REG_LENGTH == 2 && SENSOR_I2C_DAT_LENGTH == 2
#define SENSOR_writeSeq(...) SENSOR_writeSeqWaddrWdata(__VA_ARGS__)
#endif

/* For compatibility issues, k_i2c_slave_addr still holds I2C slave addresses from each sensor.
 * But g_i2c_fd only keeps the file descriptor for "this" libsensor.
 */

static int g_i2c_fd[1] = {
	-1,
};

static const uint16_t k_i2c_slave_addr[SENSOR_PATH_MAX] = {
	SENSOR_I2C_SLAVE_ADDR,
#ifdef SENSOR_I2C_SLAVE_ADDR1
	SENSOR_I2C_SLAVE_ADDR1,
#ifdef SENSOR_I2C_SLAVE_ADDR2
	SENSOR_I2C_SLAVE_ADDR2,
#ifdef SENSOR_I2C_SLAVE_ADDR3
	SENSOR_I2C_SLAVE_ADDR3,
#endif
#endif
#endif
};

#if defined SET_1920_1080_30fps_2lane || defined SET_1920_1080_15fps_2lane_PSEUDO_MASTER || defined SET_1920_1080_15fps_2lane_PSEUDO_SLAVE
// 1920x1080 30fps 2lane 396Mbps
static const SensCmd k_cmd_format_1080p_30fps[] = {
#ifndef DISABLE_SOFT_RESET
	{ 0x0103, 0x01 }, { SENSOR_DELAY_REG, 0x0a }, // sleep by miliseconds
#endif
	{ 0x0100, 0x00 }, { 0x36e9, 0x80 }, { 0x37f9, 0x80 }, { 0x301f, 0x09 }, { 0x3106, 0x05 },
	{ 0x320e, 0x04 }, { 0x320f, 0xb0 }, { 0x3248, 0x04 }, { 0x3249, 0x0b }, { 0x3253, 0x08 },
	{ 0x3301, 0x09 }, { 0x3302, 0xff }, { 0x3303, 0x10 }, { 0x3306, 0x80 }, { 0x3307, 0x02 },
	{ 0x3309, 0xc8 }, { 0x330a, 0x01 }, { 0x330b, 0x30 }, { 0x330c, 0x16 }, { 0x330d, 0xff },
	{ 0x3318, 0x02 }, { 0x331f, 0xb9 }, { 0x3321, 0x0a }, { 0x3327, 0x0e }, { 0x332b, 0x12 },
	{ 0x3333, 0x10 }, { 0x3334, 0x40 }, { 0x335e, 0x06 }, { 0x335f, 0x0a }, { 0x3364, 0x1f },
	{ 0x337c, 0x02 }, { 0x337d, 0x0e }, { 0x3390, 0x09 }, { 0x3391, 0x0f }, { 0x3392, 0x1f },
	{ 0x3393, 0x20 }, { 0x3394, 0x20 }, { 0x3395, 0xe0 }, { 0x33a2, 0x04 }, { 0x33b1, 0x80 },
	{ 0x33b2, 0x68 }, { 0x33b3, 0x42 }, { 0x33f9, 0x90 }, { 0x33fb, 0xd0 }, { 0x33fc, 0x0f },
	{ 0x33fd, 0x1f }, { 0x349f, 0x03 }, { 0x34a6, 0x0f }, { 0x34a7, 0x1f }, { 0x34a8, 0x42 },
	{ 0x34a9, 0x18 }, { 0x34aa, 0x01 }, { 0x34ab, 0x43 }, { 0x34ac, 0x01 }, { 0x34ad, 0x80 },
	{ 0x3630, 0xf4 }, { 0x3632, 0x44 }, { 0x3633, 0x22 }, { 0x3639, 0xf4 }, { 0x363c, 0x47 },
	{ 0x3670, 0x09 }, { 0x3674, 0xf4 }, { 0x3675, 0xfb }, { 0x3676, 0xed }, { 0x367c, 0x09 },
	{ 0x367d, 0x0f }, { 0x3690, 0x22 }, { 0x3691, 0x22 }, { 0x3692, 0x22 }, { 0x3698, 0x89 },
	{ 0x3699, 0x96 }, { 0x369a, 0xd0 }, { 0x369b, 0xd0 }, { 0x369c, 0x09 }, { 0x369d, 0x0f },
	{ 0x36a2, 0x09 }, { 0x36a3, 0x0f }, { 0x36a4, 0x1f }, { 0x36d0, 0x01 }, { 0x36ea, 0x0b },
	{ 0x36eb, 0x0c }, { 0x36ec, 0x1c }, { 0x36ed, 0x18 }, { 0x3722, 0xc1 }, { 0x3724, 0x41 },
	{ 0x3725, 0xc1 }, { 0x3728, 0x20 }, { 0x37fa, 0xcb }, { 0x37fb, 0x32 }, { 0x37fc, 0x11 },
	{ 0x37fd, 0x07 }, { 0x3900, 0x0d }, { 0x3905, 0x98 }, { 0x3919, 0x04 }, { 0x391b, 0x81 },
	{ 0x391c, 0x10 }, { 0x3933, 0x81 }, { 0x3934, 0xd0 }, { 0x3940, 0x75 }, { 0x3941, 0x00 },
	{ 0x3942, 0x01 }, { 0x3943, 0xd1 }, { 0x3952, 0x02 }, { 0x3953, 0x0f }, { 0x3e01, 0x4a },
	{ 0x3e02, 0xa0 }, { 0x3e08, 0x1f }, { 0x3e1b, 0x14 }, { 0x4509, 0x38 }, { 0x4819, 0x06 },
	{ 0x481b, 0x03 }, { 0x481d, 0x0b }, { 0x481f, 0x02 }, { 0x4821, 0x08 }, { 0x4823, 0x03 },
	{ 0x4825, 0x02 }, { 0x4827, 0x03 }, { 0x4829, 0x04 }, { 0x5799, 0x06 }, { 0x5ae0, 0xfe },
	{ 0x5ae1, 0x40 }, { 0x5ae2, 0x30 }, { 0x5ae3, 0x28 }, { 0x5ae4, 0x20 }, { 0x5ae5, 0x30 },
	{ 0x5ae6, 0x28 }, { 0x5ae7, 0x20 }, { 0x5ae8, 0x3c }, { 0x5ae9, 0x30 }, { 0x5aea, 0x28 },
	{ 0x5aeb, 0x3c }, { 0x5aec, 0x30 }, { 0x5aed, 0x28 }, { 0x5aee, 0xfe }, { 0x5aef, 0x40 },
	{ 0x5af4, 0x30 }, { 0x5af5, 0x28 }, { 0x5af6, 0x20 }, { 0x5af7, 0x30 }, { 0x5af8, 0x28 },
	{ 0x5af9, 0x20 }, { 0x5afa, 0x3c }, { 0x5afb, 0x30 }, { 0x5afc, 0x28 }, { 0x5afd, 0x3c },
	{ 0x5afe, 0x30 }, { 0x5aff, 0x28 }, { 0x36e9, 0x53 }, { 0x37f9, 0x33 },
#if defined SET_1920_1080_15fps_2lane_PSEUDO_MASTER
	{ 0x320e,0x09 }, { 0x320f,0x60 },
	// { 0x300a,0x24 }, //master fsync
	{ 0x300a,0x40 }, //master efsync
	{ 0x3032,0xa0 },
#elif defined(SET_1920_1080_15fps_2lane_PSEUDO_SLAVE)
	{ 0x320e,0x09 }, { 0x320f,0x60 },
	{ 0x3222,0x02 }, //Bit[1]:Slave mode en
	{ 0x322e,0x04 }, { 0x322f,0xb0 }, { 0x3230, 0x04 }, { 0x3231, 0xb0 },
	// { 0x3224,0x92 }, //slave  fsync
	{ 0x3224,0x82 }, // slave  efsync
	{ 0x300a,0x20 },
#endif
};
#endif

static const SensCmd k_cmd_start[] = {
	{ 0x0100, 0x01 },
	{ SENSOR_DELAY_REG, 1 }, //  Need delay 1 ,and then 0x02FF will write to sensor.
	{ 0x3944, 0x02 },
	{ 0x3945, 0xFF },
};

static const SensCmd k_cmd_stop[] = {
	{ 0x0100, 0x00 },
};

static void SENSOR_configInitSeq(uint8_t path_idx)
{
	int fd = g_i2c_fd[0];
	int slave_addr = k_i2c_slave_addr[path_idx];

#if defined SET_1920_1080_30fps_2lane || defined SET_1920_1080_15fps_2lane_PSEUDO_MASTER || defined SET_1920_1080_15fps_2lane_PSEUDO_SLAVE
	SENSOR_writeSeq(fd, sizeof(k_cmd_format_1080p_30fps) / sizeof(SensCmd), k_cmd_format_1080p_30fps, slave_addr);
#endif
	// TODO: verify if update_exp_cmd is required
#ifdef SNS0
	cmos_ctrl(SNS0_ID).update_exp_cmd(fd, path_idx);
#endif
#ifdef SNS1
	cmos_ctrl(SNS1_ID).update_exp_cmd(fd, path_idx);
#endif
#ifdef SNS2
	cmos_ctrl(SNS2_ID).update_exp_cmd(fd, path_idx);
#endif
#ifdef SNS3
	cmos_ctrl(SNS3_ID).update_exp_cmd(fd, path_idx);
#endif

	SENSOR_writeSeq(fd, sizeof(k_cmd_start) / sizeof(SensCmd), k_cmd_start, k_i2c_slave_addr[path_idx]);
}

static void SENSOR_configExitSeq(uint8_t path_idx)
{
	int fd = g_i2c_fd[0];
	int slave_addr = k_i2c_slave_addr[path_idx];

	SENSOR_writeSeq(fd, sizeof(k_cmd_stop) / sizeof(SensCmd), k_cmd_stop, slave_addr);
}

/* Global Interface */
void SENSOR_configInit(uint8_t path_idx)
{
	int ret = 0;
	int i2c_fd = -1;

	if (path_idx >= SENSOR_PATH_MAX) {
		sensor_log_err("Unsupported sensor index %d.", path_idx);
		return;
	}

	/* Open I2C device node */
	ret = SENSOR_openI2cDev(&i2c_fd, k_i2c_slave_addr[path_idx]);
	if (ret != MPI_SUCCESS) {
		return;
	}

	g_i2c_fd[0] = i2c_fd;

	/* Start sensor */
	SENSOR_configInitSeq(path_idx);
}

void SENSOR_configExit(uint8_t path_idx)
{
	int ret = 0;
	int i2c_fd = g_i2c_fd[0];

	if (path_idx >= SENSOR_PATH_MAX) {
		sensor_log_err("Unsupported sensor index %d.", path_idx);
		return;
	}

	/* Stop sensor */
	SENSOR_configExitSeq(path_idx);

	if (g_i2c_fd[0] != -1) {
		/* Close I2C device node */
		ret = SENSOR_closeI2cDev(i2c_fd);
		if (ret != MPI_SUCCESS) {
			return;
		}

		g_i2c_fd[0] = -1;
	}
}

int32_t SENSOR_getOpInfo(uint8_t path_idx, uint32_t sns_idx, MPI_SNS_OP_INFO_S *p_op_info)
{
	MPI_SNS_OP_INFO_S *p = p_op_info;
	float sensor_fps = SENSOR_FPS;
	int16_t frame_len_line = SENSOR_HEIGHT;
	int i;

	if (path_idx >= SENSOR_PATH_MAX) {
		sensor_log_err("Unsupported sensor index %d.", path_idx);
		return MPI_FAILURE;
	}

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
	p->sensor_fps = sensor_fps;
	p->frame_len_line = frame_len_line;
	p->i2c_slv_addr = k_i2c_slave_addr[path_idx];
	p->ob_enable = 0;
	p->reserved = 0;

	p->parl_lane = k_parl_lane[0];
	for (i = 0; i < MPI_MAX_LVDSRX_LANE_NUM; i++) {
		p->serl_lane[i] = k_serl_lane[0][i];
	}

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
