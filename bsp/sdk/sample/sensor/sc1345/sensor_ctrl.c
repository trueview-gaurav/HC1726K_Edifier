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
#include <assert.h>
#include "sensor_settings.h"
#include "sensor_params.h"
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

/* clang-format off */

// 1280x720 30fps 1lane 378Mbps
static const SensCmd k_cmd_format_720p_30fps[] = {
	{ 0x0103, 0x01 }, { SENSOR_DELAY_REG, 0x0A }, //delay 10ms
	{ 0x0100, 0x00 }, { 0x36e9, 0x80 }, { 0x301f, 0x04 }, { 0x320c, 0x06 }, { 0x320d, 0x90 }, { 0x320e, 0x02 },
	{ 0x320f, 0xee }, { 0x3253, 0x0a }, { 0x3301, 0x04 }, { 0x3306, 0x30 }, { 0x3309, 0x48 }, { 0x330b, 0xb0 },
	{ 0x330e, 0x18 }, { 0x331f, 0x41 }, { 0x3320, 0x05 }, { 0x3333, 0x10 }, { 0x3364, 0x17 }, { 0x3390, 0x08 },
	{ 0x3391, 0x18 }, { 0x3392, 0x38 }, { 0x3393, 0x06 }, { 0x3394, 0x10 }, { 0x3395, 0x40 }, { 0x3620, 0x08 },
	{ 0x3622, 0xc6 }, { 0x3630, 0xc0 }, { 0x3633, 0x33 }, { 0x3637, 0x14 }, { 0x3638, 0x0e }, { 0x363a, 0x00 },
	{ 0x363c, 0x05 }, { 0x3670, 0x1e }, { 0x3674, 0x90 }, { 0x3675, 0x90 }, { 0x3676, 0x90 }, { 0x3677, 0x82 },
	{ 0x3678, 0x86 }, { 0x3679, 0x8b }, { 0x367c, 0x18 }, { 0x367d, 0x38 }, { 0x367e, 0x18 }, { 0x367f, 0x38 },
	{ 0x3690, 0x33 }, { 0x3691, 0x33 }, { 0x3692, 0x32 }, { 0x369c, 0x08 }, { 0x369d, 0x38 }, { 0x36a4, 0x08 },
	{ 0x36a5, 0x18 }, { 0x36a8, 0x02 }, { 0x36a9, 0x04 }, { 0x36aa, 0x0e }, { 0x36ea, 0xc7 }, { 0x36eb, 0x88 },
	{ 0x36ec, 0x1d }, { 0x36ed, 0x07 }, { 0x3802, 0x00 }, { 0x3e00, 0x00 }, { 0x3e01, 0x2e }, { 0x3e02, 0x00 },
	{ 0x3e08, 0x03 }, { 0x3e09, 0x20 }, { 0x4509, 0x20 }, { 0x36e9, 0x23 },
	//{ 0x0100, 0x01 },
};

// 1280x720 60fps 1lane 720Mbps
static const SensCmd k_cmd_format_720p_60fps[] = {
	{ 0x0103, 0x01 }, { SENSOR_DELAY_REG, 0x0A }, //delay 10ms
	{ 0x0100, 0x00 }, { 0x36e9, 0x80 }, { 0x301f, 0x13 }, { 0x320c, 0x06 }, { 0x320d, 0x40 }, { 0x320e, 0x02 },
	{ 0x320f, 0xee }, { 0x3253, 0x0a }, { 0x3301, 0x06 }, { 0x3306, 0x38 }, { 0x330b, 0xaa }, { 0x330e, 0x18 },
	{ 0x3320, 0x05 }, { 0x3333, 0x10 }, { 0x3364, 0x17 }, { 0x3390, 0x08 }, { 0x3391, 0x18 }, { 0x3392, 0x38 },
	{ 0x3393, 0x09 }, { 0x3394, 0x0e }, { 0x3395, 0x26 }, { 0x3620, 0x08 }, { 0x3622, 0xc6 }, { 0x3630, 0x90 },
	{ 0x3631, 0x83 }, { 0x3633, 0x33 }, { 0x3637, 0x14 }, { 0x3638, 0x0e }, { 0x363a, 0x0c }, { 0x363c, 0x05 },
	{ 0x3670, 0x1e }, { 0x3674, 0x90 }, { 0x3675, 0x90 }, { 0x3676, 0x90 }, { 0x3677, 0x83 }, { 0x3678, 0x86 },
	{ 0x3679, 0x8b }, { 0x367c, 0x18 }, { 0x367d, 0x38 }, { 0x367e, 0x08 }, { 0x367f, 0x38 }, { 0x3690, 0x33 },
	{ 0x3691, 0x33 }, { 0x3692, 0x32 }, { 0x369c, 0x08 }, { 0x369d, 0x38 }, { 0x36a4, 0x08 }, { 0x36a5, 0x18 },
	{ 0x36a8, 0x00 }, { 0x36a9, 0x04 }, { 0x36aa, 0x0e }, { 0x36ea, 0x0f }, { 0x36eb, 0x80 }, { 0x36ec, 0x0c },
	{ 0x36ed, 0x14 }, { 0x3802, 0x00 }, { 0x391d, 0x8c }, { 0x3e00, 0x00 }, { 0x3e01, 0x5d }, { 0x3e02, 0x40 },
	{ 0x3e08, 0x03 }, { 0x3e09, 0x20 }, { 0x4509, 0x20 }, { 0x36e9, 0x20 },
	//{ 0x0100, 0x01 },
};

/* clang-format on */

static const SensCmd k_cmd_start[] = {
	{ 0x0100, 0x01 },
};

static const SensCmd k_cmd_stop[] = {
	{ 0x0100, 0x00 },
};

static void SENSOR_configInitSeq(uint8_t path_idx)
{
	int fd = g_i2c_fd[path_idx];
	int width = SENSOR_WIDTH;
	int height = SENSOR_HEIGHT;
	// int fps = SENSOR_FPS; // should check if this should be int or float

	if (width == 1280 && height == 720 && SENSOR_FPS == 30) {
		SENSOR_writeSeqWaddrBdata(fd, sizeof(k_cmd_format_720p_30fps) / sizeof(SensCmd),
		                          k_cmd_format_720p_30fps, k_i2c_slave_addr[path_idx]);
	} else if (width == 1280 && height == 720 && SENSOR_FPS == 60) {
		SENSOR_writeSeqWaddrBdata(fd, sizeof(k_cmd_format_720p_60fps) / sizeof(SensCmd),
		                          k_cmd_format_720p_60fps, k_i2c_slave_addr[path_idx]);
	} else {
		assert(0);
	}

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
	float sensor_fps = SENSOR_FPS;
	int16_t frame_len_line = SENSOR_HEIGHT;

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
