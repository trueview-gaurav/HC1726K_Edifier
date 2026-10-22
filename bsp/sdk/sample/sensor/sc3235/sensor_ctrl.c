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

#ifdef DUAL_SENSOR_SUPPORT
static int g_i2c_fd[2] = {
	-1, -1,
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

// 2304x1296 25fps_2lane
static const SensCmd k_cmd_format_1080p_30fps[] = {
	{0x0103,0x01,           },
	{ SENSOR_DELAY_REG, 0x0A }, //delay 10ms
	{0x0100,0x00,           },
	{0x301f,0x01,           },
	{0x3038,0x66,           },
	{0x320c,0x0b,           },
	{0x320d,0x40,           },
	{0x3253,0x08,           },
	{0x3301,0x11,           },
	{0x3304,0x30,           },
	{0x3306,0x50,           },
	{0x330a,0x00,           },
	{0x330b,0xd0,           },
	{0x330e,0x30,           },
	{0x3314,0x94,           },
	{0x331c,0x01,           },
	{0x331e,0x29,           },
	{0x3320,0x03,           },
	{0x3347,0x05,           },
	{0x334c,0x10,           },
	{0x3356,0x01,           },
	{0x3364,0x17,           },
	{0x3367,0x10,           },
	{0x3368,0x04,           },
	{0x3369,0x00,           },
	{0x336a,0x00,           },
	{0x336b,0x00,           },
	{0x3390,0x08,           },
	{0x3391,0x38,           },
	{0x3392,0x38,           },
	{0x3393,0x1a,           },
	{0x3394,0x88,           },
	{0x3395,0x88,           },
	{0x360f,0x05,           },
	{0x3614,0x80,           },
	{0x3622,0xf6,           },
	{0x3630,0xc3,           },
	{0x3631,0x8a,           },
	{0x3632,0x18,           },
	{0x3633,0x44,           },
	{0x3635,0x20,           },
	{0x3637,0x2c,           },
	{0x3638,0x28,           },
	{0x363a,0xa8,           },
	{0x363b,0x20,           },
	{0x363c,0x06,           },
	{0x3641,0x00,           },
	{0x3670,0x0a,           },
	{0x3671,0xf6,           },
	{0x3672,0x76,           },
	{0x3673,0x16,           },
	{0x3674,0xa0,           },
	{0x3675,0x98,           },
	{0x3676,0x6a,           },
	{0x367a,0x08,           },
	{0x367b,0x38,           },
	{0x367c,0x08,           },
	{0x367d,0x38,           },
	{0x3690,0x64,           },
	{0x3691,0x63,           },
	{0x3692,0x64,           },
	{0x369c,0x08,           },
	{0x369d,0x38,           },
	{0x36ea,0x25,           },
	{0x36eb,0x05,           },
	{0x36ec,0x15,           },
	{0x36ed,0x04,           },
	{0x36fa,0x25,           },
	{0x36fb,0x23,           },
	{0x36fc,0x01,           },
	{0x36fd,0x04,           },
	{0x3900,0x29,           },
	{0x3902,0xc5,           },
	{0x3905,0xd1,           },
	{0x3906,0x62,           },
	{0x3908,0x41,           },
	{0x3909,0x00,           },
	{0x390a,0x19,           },
	{0x390b,0x00,           },
	{0x390c,0x4c,           },
	{0x390d,0x00,           },
	{0x390e,0x19,           },
	{0x390f,0x00,           },
	{0x3910,0x4c,           },
	{0x391d,0x04,           },
	{0x391e,0x00,           },
	{0x3920,0x00,           },
	{0x3921,0x4c,           },
	{0x3922,0x00,           },
	{0x3923,0x19,           },
	{0x3924,0x00,           },
	{0x3925,0x4c,           },
	{0x3926,0x00,           },
	{0x3927,0x19,           },
	{0x3933,0x0a,           },
	{0x3934,0x28,           },
	{0x3935,0x18,           },
	{0x3936,0x08,           },
	{0x3937,0x13,           },
	{0x3940,0x68,           },
	{0x3942,0x02,           },
	{0x3943,0x33,           },
	{0x3e01,0xa8,           },
	{0x3e02,0x40,           },
	{0x3e09,0x20,           },
	{0x3e1b,0x35,           },
	{0x3e25,0x03,           },
	{0x3e26,0x20,           },
	{0x5781,0x04,           },
	{0x5782,0x04,           },
	{0x5783,0x02,           },
	{0x5784,0x02,           },
	{0x5785,0x40,           },
	{0x5786,0x20,           },
	{0x5787,0x18,           },
	{0x5788,0x10,           },
	{0x5789,0x10,           },
	{0x578a,0x30,           },
	{0x57a4,0xa0,           },
	{0x301f,0x20,           },
	{0x36e9,0x23,           },
	{0x36f9,0x33,           },
	//{0x0100,0x01,           },
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

	SENSOR_writeSeqWaddrBdata(fd, sizeof(k_cmd_format_1080p_30fps) / sizeof(SensCmd),
	                          k_cmd_format_1080p_30fps, k_i2c_slave_addr[path_idx]);

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

	SENSOR_writeSeqWaddrBdata(fd, sizeof(k_cmd_start) / sizeof(SensCmd),
	                          k_cmd_start, k_i2c_slave_addr[path_idx]);
}

static void SENSOR_configExitSeq(uint8_t path_idx)
{
	int fd = g_i2c_fd[path_idx];

	SENSOR_writeSeqWaddrBdata(fd, sizeof(k_cmd_stop) / sizeof(SensCmd),
				  k_cmd_stop, k_i2c_slave_addr[path_idx]);
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
	p->frame_len_line = 1350;
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

	p->mipi.dt_bmp = 0x0;
	p->mipi.vc_bmp = 0x1;
	p->mipi.t_hs_settle = 34;
	p->mipi.t_hs_settle_ns = T_HS_SETTLE_NS;
	p->mipi.t_d_term_en_ns = T_D_TERM_EN_NS;
	p->mipi.t_clk_settle_ns = T_CLK_SETTLE_NS;
	p->mipi.t_clk_term_en_ns = T_CLK_TERM_EN_NS;

	return MPI_SUCCESS;
}
