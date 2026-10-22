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

// 1920x1080 20fps 2lane 300Mbps
static const SensCmd OS02N10_MIPI_2LANE_1920x1080_300M_raw10_20fps_V09[] = {
	{ 0xfc, 0x01 }, { 0xfd, 0x00 }, { 0x2b, 0x03 }, { 0xba, 0x02 }, { 0xfd, 0x00 }, { 0xb1, 0x14 }, { 0xba, 0x00 },
	{ 0x1a, 0x00 }, { 0x1b, 0x13 }, { 0xfd, 0x01 }, { 0x0e, 0x00 }, { 0x0f, 0x02 }, { 0x14, 0x01 }, { 0x15, 0x0e },
	{ 0x24, 0xff }, { 0x2f, 0x30 }, { 0xfe, 0x02 }, { 0x2b, 0xff }, { 0x30, 0x00 }, { 0x31, 0x16 }, { 0x32, 0x25 },
	{ 0x33, 0xfb }, { 0xfd, 0x01 }, { 0x50, 0x03 }, { 0x51, 0x07 }, { 0x52, 0x04 }, { 0x53, 0x05 }, { 0x57, 0x40 },
	{ 0x66, 0x04 }, { 0x6d, 0x58 }, { 0x77, 0x01 }, { 0x79, 0x32 }, { 0x7c, 0x01 }, { 0x90, 0x3b }, { 0x91, 0x0b },
	{ 0x92, 0x18 }, { 0x95, 0x40 }, { 0x99, 0x05 }, { 0xaa, 0x0e }, { 0xab, 0x0c }, { 0xac, 0x10 }, { 0xad, 0x10 },
	{ 0xae, 0x20 }, { 0xb0, 0x0e }, { 0xb1, 0x0f }, { 0xb2, 0x1a }, { 0xb3, 0x1c }, { 0xfd, 0x00 }, { 0xb0, 0x00 },
	{ 0xb1, 0x14 }, { 0xb2, 0x00 }, { 0xb3, 0x10 }, { 0xfd, 0x03 }, { 0x08, 0x00 }, { 0x09, 0x20 }, { 0x0a, 0x02 },
	{ 0x0b, 0x80 }, { 0x11, 0x41 }, { 0x12, 0x41 }, { 0x13, 0x41 }, { 0x14, 0x41 }, { 0x17, 0x72 }, { 0x18, 0x6f },
	{ 0x19, 0x70 }, { 0x1a, 0x6f }, { 0x1b, 0xc0 }, { 0x1d, 0x01 }, { 0x1f, 0x80 }, { 0x20, 0x40 }, { 0x21, 0x80 },
	{ 0x22, 0x40 }, { 0x23, 0x88 }, { 0x4b, 0x06 }, { 0x0e, 0x03 }, { 0x58, 0x7b }, { 0x59, 0x17 }, { 0x5a, 0x32 },
	{ 0xfd, 0x03 }, { 0x4c, 0x01 }, { 0x4d, 0x01 }, { 0x4e, 0x01 }, { 0x4f, 0x02 }, { 0xfd, 0x00 }, { 0x08, 0x19 },
	{ 0x13, 0xbe }, { 0x14, 0x02 }, { 0x4c, 0x24 }, { 0xb6, 0x00 }, { 0xb7, 0x08 }, { 0xb9, 0xd6 }, { 0xc6, 0x95 },
	{ 0xc7, 0x77 }, { 0xc9, 0x22 }, { 0xca, 0x32 }, { 0xd7, 0xaa }, { 0xbc, 0x1f }, { 0xbd, 0x60 }, { 0xbe, 0x78 },
	{ 0xbf, 0xa5 }, { 0xcb, 0x00 }, { 0xcc, 0x00 }, { 0xce, 0x20 }, { 0xcf, 0x3f }, { 0xd0, 0x76 }, { 0xd1, 0xec },
	{ 0xfd, 0x04 }, { 0x1b, 0x01 }, { 0xfd, 0x03 }, { 0x01, 0x04 }, { 0x02, 0x07 }, { 0x03, 0x80 }, { 0x05, 0x04 },
	{ 0x06, 0x04 }, { 0x07, 0x38 }, { 0xfd, 0x00 }, { 0x1e, 0x0f }, { 0x1d, 0xa1 }, { 0x21, 0x04 }, { 0x24, 0x02 },
	{ 0x27, 0x07 }, { 0x28, 0x80 }, { 0x29, 0x04 }, { 0x2a, 0x38 }, { 0x2d, 0x04 }, { 0x2e, 0x03 }, { 0x2f, 0x0c },
	{ 0x31, 0x04 }, { 0x32, 0x1a }, { 0x33, 0x04 }, { 0x34, 0x05 }, { 0x3f, 0x40 }, { 0x40, 0x94 }, { 0x23, 0x01 },
	{ 0xfd, 0x03 }, { 0x26, 0x00 }, { 0x28, 0x0a }, { 0x29, 0x0a }, { 0x2a, 0x52 }, { 0x2b, 0x5a }, { 0x2c, 0x0a },
	{ 0x2d, 0x0a }, { 0x2e, 0x52 }, { 0x2f, 0x5a }, { 0x31, 0x0a }, { 0x32, 0x0a }, { 0x33, 0x52 }, { 0x34, 0x5a },
	{ 0x35, 0x0c }, { 0x36, 0x10 }, { 0x37, 0x07 }, { 0x38, 0x0a }, { 0x39, 0x0c }, { 0x3a, 0x10 }, { 0x3b, 0x07 },
	{ 0x3c, 0x0a }, { 0x3d, 0x0c }, { 0x3e, 0x10 }, { 0x3f, 0x07 }, { 0x40, 0x0a }, { 0x41, 0x07 }, { 0x42, 0x07 },
	{ 0x43, 0x07 }, { 0x44, 0x07 }, { 0x46, 0x10 }, { 0x47, 0xe2 }, { 0x45, 0x50 }, { 0xfb, 0x03 },
};

static const SensCmd k_cmd_start[] = {
	{ 0xfd, 0x00 },
	{ 0x23, 0x01 },
};

static const SensCmd k_cmd_stop[] = {
	{ 0xfd, 0x00 },
	{ 0x23, 0x00 },
};

static void SENSOR_configInitSeq(uint8_t path_idx)
{
	int fd = g_i2c_fd[path_idx];

	SENSOR_writeSeq(fd, sizeof(OS02N10_MIPI_2LANE_1920x1080_300M_raw10_20fps_V09) / sizeof(SensCmd),
	                OS02N10_MIPI_2LANE_1920x1080_300M_raw10_20fps_V09, k_i2c_slave_addr[path_idx]);

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
