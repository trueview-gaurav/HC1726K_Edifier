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
#include "sensor_params.h"
#include "sensor_lvds.h"

static int g_i2c_fd[1] = {
	-1,
};

static const uint16_t k_i2c_slave_addr[1] = {
	SENSOR_I2C_SLAVE_ADDR,
};

// 2304x1296 30fps 2lane 10bits
static const SensCmd k_cmd_format[] = {
	{ 0x0100, 0x00 }, { 0x36e9, 0x80 }, { 0x37f9, 0x80 }, { 0x3018, 0x3a }, { 0x3019, 0x0c }, { 0x301f, 0x07 },
	{ 0x3058, 0x21 }, { 0x3059, 0x53 }, { 0x305a, 0x40 }, { 0x320e, 0x08 }, { 0x320f, 0xca }, { 0x3250, 0x00 },
	{ 0x3301, 0x0c }, { 0x3304, 0x50 }, { 0x3305, 0x00 }, { 0x3306, 0x50 }, { 0x3307, 0x04 }, { 0x3308, 0x0a },
	{ 0x3309, 0x60 }, { 0x330b, 0xc8 }, { 0x330d, 0x08 }, { 0x330e, 0x38 }, { 0x331e, 0x41 }, { 0x331f, 0x51 },
	{ 0x3333, 0x10 }, { 0x3334, 0x40 }, { 0x3364, 0x5e }, { 0x338e, 0xe2 }, { 0x338f, 0x80 }, { 0x3390, 0x08 },
	{ 0x3391, 0x18 }, { 0x3392, 0xb8 }, { 0x3393, 0x12 }, { 0x3394, 0x14 }, { 0x3395, 0x10 }, { 0x3396, 0x88 },
	{ 0x3397, 0x98 }, { 0x3398, 0xb8 }, { 0x3399, 0x10 }, { 0x339a, 0x16 }, { 0x339b, 0x1c }, { 0x339c, 0x40 },
	{ 0x33ac, 0x0a }, { 0x33ad, 0x10 }, { 0x33ae, 0x4f }, { 0x33af, 0x5e }, { 0x33b2, 0x50 }, { 0x33b3, 0x10 },
	{ 0x33f8, 0x00 }, { 0x33f9, 0x50 }, { 0x33fa, 0x00 }, { 0x33fb, 0x50 }, { 0x33fc, 0x48 }, { 0x33fd, 0x78 },
	{ 0x349f, 0x03 }, { 0x34a6, 0x40 }, { 0x34a7, 0x58 }, { 0x34a8, 0x10 }, { 0x34a9, 0x10 }, { 0x34f8, 0x78 },
	{ 0x34f9, 0x10 }, { 0x3633, 0x44 }, { 0x363b, 0x8f }, { 0x363c, 0x02 }, { 0x3641, 0x08 }, { 0x3654, 0x20 },
	{ 0x3674, 0xc2 }, { 0x3675, 0xb4 }, { 0x3676, 0x88 }, { 0x367c, 0x88 }, { 0x367d, 0xb8 }, { 0x3690, 0x34 },
	{ 0x3691, 0x44 }, { 0x3692, 0x54 }, { 0x3693, 0x88 }, { 0x3694, 0x98 }, { 0x3696, 0x80 }, { 0x3697, 0x83 },
	{ 0x3698, 0x81 }, { 0x3699, 0x81 }, { 0x369a, 0x84 }, { 0x369b, 0x82 }, { 0x36a2, 0x80 }, { 0x36a3, 0x88 },
	{ 0x36a4, 0xf8 }, { 0x36a5, 0xb8 }, { 0x36a6, 0x98 }, { 0x36d0, 0x15 }, { 0x36ea, 0x23 }, { 0x36eb, 0x0d },
	{ 0x36ec, 0x55 }, { 0x36ed, 0x18 }, { 0x370f, 0x01 }, { 0x3722, 0x03 }, { 0x3724, 0x92 }, { 0x3727, 0x14 },
	{ 0x37b0, 0x17 }, { 0x37b1, 0x9b }, { 0x37b2, 0x9b }, { 0x37b3, 0x88 }, { 0x37b4, 0xb8 }, { 0x37fa, 0x23 },
	{ 0x37fb, 0x54 }, { 0x37fc, 0x21 }, { 0x37fd, 0x1c }, { 0x391f, 0x41 }, { 0x3926, 0xe0 }, { 0x3933, 0x80 },
	{ 0x3934, 0xf8 }, { 0x3935, 0x00 }, { 0x3936, 0x45 }, { 0x3937, 0x66 }, { 0x3938, 0x66 }, { 0x3939, 0x00 },
	{ 0x393a, 0x03 }, { 0x393b, 0x00 }, { 0x393c, 0x00 }, { 0x393d, 0x02 }, { 0x393e, 0x80 }, { 0x3e00, 0x00 },
	{ 0x3e01, 0xba }, { 0x3e02, 0xd0 }, { 0x3e16, 0x00 }, { 0x3e17, 0xc5 }, { 0x3e18, 0x00 }, { 0x3e19, 0xc5 },
	{ 0x4509, 0x20 }, { 0x450d, 0x0b }, { 0x4819, 0x08 }, { 0x481b, 0x05 }, { 0x481d, 0x11 }, { 0x481f, 0x04 },
	{ 0x4821, 0x09 }, { 0x4823, 0x05 }, { 0x4825, 0x04 }, { 0x4827, 0x04 }, { 0x4829, 0x07 }, { 0x5780, 0x76 },
	{ 0x5784, 0x0a }, { 0x5785, 0x04 }, { 0x5787, 0x0a }, { 0x5788, 0x0a }, { 0x5789, 0x08 }, { 0x578a, 0x0a },
	{ 0x578b, 0x0a }, { 0x578c, 0x08 }, { 0x578d, 0x40 }, { 0x5790, 0x08 }, { 0x5791, 0x04 }, { 0x5792, 0x04 },
	{ 0x5793, 0x08 }, { 0x5794, 0x04 }, { 0x5795, 0x04 }, { 0x57ac, 0x00 }, { 0x57ad, 0x00 }, { 0x36e9, 0x53 },
	{ 0x37f9, 0x53 },
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
