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

// 2304x1296 30fps 2lane 10bits
static const SensCmd k_cmd_format[] = {
	{ 0x0103, 0x01 }, // soft reset
	{ SENSOR_DELAY_REG, 0x0a }, // wait for the soft reset (it only needs 150ns but it's fine to wait 10ms)
	{ 0x0100, 0x00 }, // enter sleep mode
	{ 0x36e9, 0x80 },           { 0x37f9, 0x80 }, { 0x301f, 0x02 }, { 0x30b8, 0x33 }, { 0x320e, 0x05 },
	{ 0x320f, 0x50 },           { 0x3253, 0x10 }, { 0x325f, 0x20 }, { 0x3301, 0x04 }, { 0x3306, 0x50 },
	{ 0x3309, 0xa8 },           { 0x330a, 0x00 }, { 0x330b, 0xd8 }, { 0x3314, 0x13 }, { 0x331f, 0x99 },
	{ 0x3333, 0x10 },           { 0x3334, 0x40 }, { 0x335e, 0x06 }, { 0x335f, 0x0a }, { 0x3364, 0x5e },
	{ 0x337c, 0x02 },           { 0x337d, 0x0e }, { 0x3390, 0x01 }, { 0x3391, 0x03 }, { 0x3392, 0x07 },
	{ 0x3393, 0x04 },           { 0x3394, 0x04 }, { 0x3395, 0x04 }, { 0x3396, 0x08 }, { 0x3397, 0x0b },
	{ 0x3398, 0x1f },           { 0x3399, 0x04 }, { 0x339a, 0x0a }, { 0x339b, 0x3a }, { 0x339c, 0xb4 },
	{ 0x33a2, 0x04 },           { 0x33ac, 0x08 }, { 0x33ad, 0x1c }, { 0x33ae, 0x10 }, { 0x33af, 0x30 },
	{ 0x33b1, 0x80 },           { 0x33b3, 0x48 }, { 0x33f9, 0x60 }, { 0x33fb, 0x74 }, { 0x33fc, 0x4b },
	{ 0x33fd, 0x5f },           { 0x349f, 0x03 }, { 0x34a6, 0x4b }, { 0x34a7, 0x5f }, { 0x34a8, 0x20 },
	{ 0x34a9, 0x18 },           { 0x34ab, 0xe8 }, { 0x34ac, 0x01 }, { 0x34ad, 0x00 }, { 0x34f8, 0x5f },
	{ 0x34f9, 0x18 },           { 0x3630, 0xc0 }, { 0x3631, 0x84 }, { 0x3632, 0x64 }, { 0x3633, 0x32 },
	{ 0x363b, 0x03 },           { 0x363c, 0x08 }, { 0x3641, 0x38 }, { 0x3670, 0x4e }, { 0x3674, 0xc0 },
	{ 0x3675, 0xc0 },           { 0x3676, 0xc0 }, { 0x3677, 0x84 }, { 0x3678, 0x84 }, { 0x3679, 0x84 },
	{ 0x367c, 0x48 },           { 0x367d, 0x49 }, { 0x367e, 0x4b }, { 0x367f, 0x5f }, { 0x3690, 0x32 },
	{ 0x3691, 0x32 },           { 0x3692, 0x42 }, { 0x369c, 0x4b }, { 0x369d, 0x5f }, { 0x36b0, 0x87 },
	{ 0x36b1, 0x90 },           { 0x36b2, 0xa1 }, { 0x36b3, 0xd8 }, { 0x36b4, 0x49 }, { 0x36b5, 0x4b },
	{ 0x36b6, 0x4f },           { 0x36ea, 0x11 }, { 0x36eb, 0x0d }, { 0x36ec, 0x1c }, { 0x36ed, 0x26 },
	{ 0x370f, 0x01 },           { 0x3722, 0x09 }, { 0x3724, 0x41 }, { 0x3725, 0xc1 }, { 0x3771, 0x09 },
	{ 0x3772, 0x09 },           { 0x3773, 0x05 }, { 0x377a, 0x48 }, { 0x377b, 0x5f }, { 0x37fa, 0x11 },
	{ 0x37fb, 0x33 },           { 0x37fc, 0x11 }, { 0x37fd, 0x08 }, { 0x3904, 0x04 }, { 0x3905, 0x8c },
	{ 0x391d, 0x04 },           { 0x3921, 0x20 }, { 0x3926, 0x21 }, { 0x3933, 0x80 }, { 0x3934, 0x0a },
	{ 0x3935, 0x00 },           { 0x3936, 0x2a }, { 0x3937, 0x6a }, { 0x3938, 0x6a }, { 0x39dc, 0x02 },
	{ 0x3e01, 0x54 },           { 0x3e02, 0x80 }, { 0x3e09, 0x00 }, { 0x440e, 0x02 }, { 0x4509, 0x20 },
	{ 0x5ae0, 0xfe },           { 0x5ae1, 0x40 }, { 0x5ae2, 0x38 }, { 0x5ae3, 0x30 }, { 0x5ae4, 0x28 },
	{ 0x5ae5, 0x38 },           { 0x5ae6, 0x30 }, { 0x5ae7, 0x28 }, { 0x5ae8, 0x3f }, { 0x5ae9, 0x34 },
	{ 0x5aea, 0x2c },           { 0x5aeb, 0x3f }, { 0x5aec, 0x34 }, { 0x5aed, 0x2c }, { 0x36e9, 0x54 },
	{ 0x37f9, 0x47 },
	// { 0x0100, 0x01 }, // it should be ok to set this until we are ready to stream
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
