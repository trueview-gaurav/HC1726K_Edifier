/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#include "sensor.h"
#include <stdio.h>
#include <unistd.h>
#include <stdint.h>
#include <string.h>

#include "sensor_settings.h"
#include "sensor_lvds.h"

#if SENSOR_I2C_REG_LENGTH == 1 && SENSOR_I2C_DAT_LENGTH == 1
#define SENSOR_writeSeq(...) SENSOR_writeSeqBaddrBdata(__VA_ARGS__)
#elif SENSOR_I2C_REG_LENGTH == 1 && SENSOR_I2C_DAT_LENGTH == 2
#define SENSOR_writeSeq(...) SENSOR_writeSeqBaddrWdata(__VA_ARGS__)
#elif SENSOR_I2C_REG_LENGTH == 2 && SENSOR_I2C_DAT_LENGTH == 1
#define SENSOR_writeSeq(...) SENSOR_writeSeqWaddrBdata(__VA_ARGS__)
#elif SENSOR_I2C_REG_LENGTH == 2 && SENSOR_I2C_DAT_LENGTH == 2
#define SENSOR_writeSeq(...) SENSOR_writeSeqWaddrWdata(__VA_ARGS__)
#endif

#ifdef DUAL_SENSOR_SUPPORT
int g_i2c_fd[2] = {
	-1,
	-1,
};

const uint16_t k_i2c_slave_addr[2] = {
	SENSOR_I2C_SLAVE_ADDR,
	SENSOR_I2C_SLAVE_ADDR1,
};
#else
int g_i2c_fd[1] = {
	-1,
};

const uint16_t k_i2c_slave_addr[1] = {
	SENSOR_I2C_SLAVE_ADDR,
};
#endif

// 1920x1080 30fps 2lane 720Mbps/lane
static const SensCmd k_cmd_format_1080p_30fps_2lane[] = {
	// { 0xfd, 0x00 },
	// { 0x36, 0x01 },
	// { SENSOR_DELAY_REG, 0x01 },
	// { 0xfd, 0x00 },
	// { 0x36, 0x00 },
	// { SENSOR_DELAY_REG, 0x01 },
	// { 0xfd, 0x00 },
	// { 0x20, 0x00 }, // reset
	// { SENSOR_DELAY_REG, 0x0a }, // wait 5ms

	{ 0xfd, 0x00 }, // P0: system register
	{ 0x30, 0x0a },
	{ 0x35, 0x04 },
	{ 0x38, 0x11 },
	{ 0x41, 0x06 },
	{ 0x44, 0x20 },
	// { 0x2e, 0x1b }, // mpll_nc, used to control MIPI clock rate

	{ 0xfd, 0x01 }, // P1: sensor ctrl
	{ 0x03, 0x02 }, // SHS[15:8]
	{ 0x04, 0x4c }, // SHS[ 7:0]
	{ 0x05, 0x00 }, // VBlank[15:8], not used in actual
	{ 0x06, 0x10 }, // VBlank[ 7:0]
	{ 0x0d, 0x10 }, // disable auto frame prolong
	{ 0x0e, 0x04 }, // VTS[15:8]
	{ 0x0f, 0x55 }, // VTS[ 7:0]
	{ 0x24, 0x10 }, // AGC[7:0], 0x10 - 0xF8 (15.5x), 1/16 step
	{ 0x37, 0x00 }, // DGC[10:8]
	// { 0x38, 0x00 }, // AGC[8], actually unused
	{ 0x39, 0x40 }, // DGC[ 7:0], 0x40 - 0x7ff (31.984x), 1/64 step
	{ 0x01, 0x01 }, // exposure update
	{ 0x4a, 0x00 },
	{ 0x4b, 0x04 },
	{ 0x4c, 0x04 },
	{ 0x4d, 0x38 },
	{ 0x19, 0x50 },
	{ 0x1a, 0x0c },
	{ 0x1b, 0x0d },
	{ 0x1c, 0x00 },
	{ 0x1d, 0x75 },
	{ 0x1e, 0x52 },
	{ 0x22, 0x14 },
	{ 0x25, 0x44 },
	{ 0x26, 0x0f },
	{ 0x3c, 0xca },
	{ 0x3d, 0x4a },
	{ 0x40, 0x0f },
	{ 0x43, 0x38 },
	{ 0x46, 0x01 },
	{ 0x47, 0x00 },
	{ 0x49, 0x32 },
	{ 0x50, 0x01 },
	{ 0x51, 0x28 },
	{ 0x52, 0x20 },
	{ 0x53, 0x03 },
	{ 0x57, 0x16 },
	{ 0x59, 0x01 },
	{ 0x5a, 0x01 },
	{ 0x5d, 0x04 },
	{ 0x6a, 0x04 },
	{ 0x6b, 0x03 },
	{ 0x6e, 0x28 },
	{ 0x71, 0xc2 },
	{ 0x72, 0x04 },
	{ 0x73, 0x38 },
	{ 0x74, 0x04 },
	{ 0x79, 0x00 },
	{ 0x7a, 0xb2 },
	{ 0x7b, 0x10 },
	{ 0x8f, 0x80 },
	{ 0x91, 0x38 },
	{ 0x92, 0x02 },
	{ 0x9d, 0x03 },
	{ 0x9e, 0x55 },
	{ 0xb8, 0x70 },
	{ 0xb9, 0x70 },
	{ 0xba, 0x70 },
	{ 0xbb, 0x70 },
	{ 0xbc, 0x00 },
	{ 0xc4, 0x6d },
	{ 0xc5, 0x6d },
	{ 0xc6, 0x6d },
	{ 0xc7, 0x6d },
	{ 0xcc, 0x11 },
	{ 0xcd, 0xe0 },
	{ 0xd0, 0x1b },
	{ 0xd2, 0x76 },
	{ 0xd3, 0x68 },
	{ 0xd4, 0x68 },
	{ 0xd5, 0x73 },
	{ 0xd6, 0x73 },
	{ 0xe8, 0x55 },
	{ 0xf0, 0x40 },
	{ 0xf1, 0x40 },
	{ 0xf2, 0x40 },
	{ 0xf3, 0x40 },
	{ 0xfa, 0x1c },
	{ 0xfb, 0x33 },
	{ 0xfc, 0x80 },
	{ 0xfe, 0x80 },

	{ 0xfd, 0x03 }, // P3: DAC
	{ 0x03, 0x67 },
	{ 0x00, 0x59 },
	{ 0x04, 0x11 },
	{ 0x05, 0x04 },
	{ 0x06, 0x0c },
	{ 0x07, 0x08 },
	{ 0x08, 0x08 },
	{ 0x09, 0x4f },
	{ 0x0b, 0x08 },
	{ 0x0d, 0x26 },
	{ 0x0f, 0x00 },

	{ 0xfd, 0x02 }, // P2: ISP
	{ 0x34, 0xfe },
	{ 0x5e, 0x22 },
	{ 0xa1, 0x06 },
	{ 0xa3, 0x38 },
	{ 0xa5, 0x02 },
	{ 0xa7, 0x80 },

	{ 0xfd, 0x01 }, // P1: sensor ctrl
	{ 0xa1, 0x05 },
	{ 0xb1, 0x01 },
};

static const SensCmd k_cmd_start[] = {
	{ 0xfd, 0x01 },
	{ 0xb1, 0x03 },
};

static const SensCmd k_cmd_stop[] = {
	{ 0xfd, 0x01 },
	{ 0xb1, 0x01 },
};

static void SENSOR_configInitSeq(uint8_t path_idx)
{
	int fd = g_i2c_fd[path_idx];

	SENSOR_writeSeq(fd, sizeof(k_cmd_format_1080p_30fps_2lane) / sizeof(SensCmd), k_cmd_format_1080p_30fps_2lane,
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

	SENSOR_writeSeq(fd, sizeof(k_cmd_start) / sizeof(SensCmd), k_cmd_start, k_i2c_slave_addr[path_idx]);
}

static void SENSOR_configExitSeq(uint8_t path_idx)
{
	int fd = g_i2c_fd[path_idx];

	SENSOR_writeSeq(fd, sizeof(k_cmd_stop) / sizeof(SensCmd), k_cmd_stop, k_i2c_slave_addr[path_idx]);
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
