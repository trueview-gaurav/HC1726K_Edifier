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

// 1920x1080 60fps 2lane 10bits
static const SensCmd k_cmd_format[] = {
	{ 0x0103, 0x01 }, { SENSOR_DELAY_REG, 1 }, //delay 1 ms
	{ 0x0100, 0x00 }, { 0x36e9, 0x80 },        { 0x37f9, 0x80 }, { 0x301f, 0x23 }, { 0x3208, 0x07 },
	{ 0x3209, 0x80 }, { 0x320a, 0x04 },        { 0x320b, 0x38 }, { 0x320c, 0x09 }, { 0x320d, 0x60 },
	{ 0x3211, 0x04 }, { 0x3213, 0x04 },        { 0x3227, 0x03 }, { 0x3250, 0x00 }, { 0x3301, 0x09 },
	{ 0x3304, 0x50 }, { 0x3306, 0x48 },        { 0x3308, 0x18 }, { 0x3309, 0x68 }, { 0x330a, 0x00 },
	{ 0x330b, 0xc0 }, { 0x331e, 0x41 },        { 0x331f, 0x59 }, { 0x3333, 0x10 }, { 0x3334, 0x40 },
	{ 0x335d, 0x60 }, { 0x335e, 0x06 },        { 0x335f, 0x08 }, { 0x3364, 0x5e }, { 0x337c, 0x02 },
	{ 0x337d, 0x0a }, { 0x3390, 0x01 },        { 0x3391, 0x0b }, { 0x3392, 0x0f }, { 0x3393, 0x0c },
	{ 0x3394, 0x0d }, { 0x3395, 0x60 },        { 0x3396, 0x48 }, { 0x3397, 0x49 }, { 0x3398, 0x4f },
	{ 0x3399, 0x0a }, { 0x339a, 0x0f },        { 0x339b, 0x14 }, { 0x339c, 0x60 }, { 0x33a2, 0x04 },
	{ 0x33af, 0x40 }, { 0x33b1, 0x80 },        { 0x33b3, 0x40 }, { 0x33b9, 0x0a }, { 0x33f9, 0x70 },
	{ 0x33fb, 0x90 }, { 0x33fc, 0x4b },        { 0x33fd, 0x5f }, { 0x349f, 0x03 }, { 0x34a6, 0x4b },
	{ 0x34a7, 0x4f }, { 0x34a8, 0x30 },        { 0x34a9, 0x20 }, { 0x34aa, 0x00 }, { 0x34ab, 0xe0 },
	{ 0x34ac, 0x01 }, { 0x34ad, 0x00 },        { 0x34f8, 0x5f }, { 0x34f9, 0x10 }, { 0x3630, 0xc0 },
	{ 0x3633, 0x44 }, { 0x3637, 0x29 },        { 0x363b, 0x20 }, { 0x3670, 0x09 }, { 0x3674, 0xb0 },
	{ 0x3675, 0x80 }, { 0x3676, 0x88 },        { 0x367c, 0x40 }, { 0x367d, 0x49 }, { 0x3690, 0x54 },
	{ 0x3691, 0x44 }, { 0x3692, 0x55 },        { 0x369c, 0x49 }, { 0x369d, 0x4f }, { 0x36ae, 0x4b },
	{ 0x36af, 0x4f }, { 0x36b0, 0x87 },        { 0x36b1, 0x9b }, { 0x36b2, 0xb7 }, { 0x36d0, 0x01 },
	{ 0x36ea, 0x09 }, { 0x36eb, 0x04 },        { 0x36ec, 0x0c }, { 0x36ed, 0x24 }, { 0x370f, 0x01 },
	{ 0x3722, 0x17 }, { 0x3728, 0x90 },        { 0x37b0, 0x17 }, { 0x37b1, 0x17 }, { 0x37b2, 0x97 },
	{ 0x37b3, 0x4b }, { 0x37b4, 0x4f },        { 0x37fa, 0x09 }, { 0x37fb, 0x04 }, { 0x37fc, 0x00 },
	{ 0x37fd, 0x22 }, { 0x3901, 0x02 },        { 0x3902, 0xc5 }, { 0x3904, 0x04 }, { 0x3907, 0x00 },
	{ 0x3908, 0x41 }, { 0x3909, 0x00 },        { 0x390a, 0x00 }, { 0x391f, 0x04 }, { 0x3928, 0xc1 },
	{ 0x3933, 0x84 }, { 0x3934, 0x02 },        { 0x3940, 0x62 }, { 0x3941, 0x00 }, { 0x3942, 0x04 },
	{ 0x3943, 0x03 }, { 0x3e00, 0x00 },        { 0x3e01, 0x8c }, { 0x3e02, 0x10 }, { 0x440e, 0x02 },
	{ 0x450d, 0x11 }, { 0x4819, 0x0a },        { 0x481b, 0x06 }, { 0x481d, 0x16 }, { 0x481f, 0x05 },
	{ 0x4821, 0x0b }, { 0x4823, 0x05 },        { 0x4825, 0x05 }, { 0x4827, 0x05 }, { 0x4829, 0x09 },
	{ 0x5010, 0x01 }, { 0x5787, 0x08 },        { 0x5788, 0x03 }, { 0x5789, 0x00 }, { 0x578a, 0x10 },
	{ 0x578b, 0x08 }, { 0x578c, 0x00 },        { 0x5790, 0x08 }, { 0x5791, 0x04 }, { 0x5792, 0x00 },
	{ 0x5793, 0x10 }, { 0x5794, 0x08 },        { 0x5795, 0x00 }, { 0x5799, 0x06 }, { 0x57ad, 0x00 },
	{ 0x5ae0, 0xfe }, { 0x5ae1, 0x40 },        { 0x5ae2, 0x3f }, { 0x5ae3, 0x38 }, { 0x5ae4, 0x28 },
	{ 0x5ae5, 0x3f }, { 0x5ae6, 0x38 },        { 0x5ae7, 0x28 }, { 0x5ae8, 0x3f }, { 0x5ae9, 0x3c },
	{ 0x5aea, 0x2c }, { 0x5aeb, 0x3f },        { 0x5aec, 0x3c }, { 0x5aed, 0x2c }, { 0x5af4, 0x3f },
	{ 0x5af5, 0x38 }, { 0x5af6, 0x28 },        { 0x5af7, 0x3f }, { 0x5af8, 0x38 }, { 0x5af9, 0x28 },
	{ 0x5afa, 0x3f }, { 0x5afb, 0x3c },        { 0x5afc, 0x2c }, { 0x5afd, 0x3f }, { 0x5afe, 0x3c },
	{ 0x5aff, 0x2c }, { 0x36e9, 0x53 },        { 0x37f9, 0x53 },
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
