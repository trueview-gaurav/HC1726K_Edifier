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

// do NOT define g_i2c_fd as static for sensor_cmos.c to use I2C
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

// 1920x1080 30fps_2lane
static const SensCmd k_cmd_format_1080p_30fps[] = {
	{ 0x0103, 0x01 },
	{ SENSOR_DELAY_REG, 0x0A }, //delay 10ms
	{ 0x0100, 0x00 },

	// FAE's setting
	{ 0x36e9, 0x80 },
	{ 0x36f9, 0x80 },
	{ 0x3f00, 0x0d },
	{ 0x3f04, 0x02 },
	{ 0x3f05, 0x0e },
	{ 0x3316, 0x00 },
	{ 0x3338, 0x80 },
	{ 0x337e, 0x00 },
	{ 0x3271, 0x00 },
	{ 0x3273, 0x03 },
	{ 0x3249, 0x0f },
	{ 0x330f, 0x03 },
	{ 0x333a, 0x02 },
	{ 0x330d, 0x18 },
	{ 0x3301, 0x22 },
	{ 0x3302, 0x09 },
	{ 0x3304, 0x20 },
	{ 0x331e, 0x19 },
	{ 0x330b, 0xb0 },
	{ 0x330c, 0x08 },
	{ 0x332b, 0x08 },
	{ 0x3366, 0x62 },
	{ 0x33a2, 0x07 },
	{ 0x337c, 0x05 },
	{ 0x337d, 0x09 },
	{ 0x335f, 0x04 },
	{ 0x3207, 0x3f },
	{ 0x4505, 0x0a },
	{ 0x3f09, 0x48 },
	{ 0x3e01, 0x20 },
	{ 0x3e02, 0x00 },
	{ 0x3637, 0x20 },
	{ 0x330B, 0x88 },
	{ 0x391f, 0x18 },
	{ 0x3637, 0x20 },
	{ 0x3614, 0x00 },
	{ 0x3908, 0x82 },
	{ 0x3e01, 0x8c },
	{ 0x3e02, 0x20 },
	{ 0x3333, 0x10 },
	{ 0x3306, 0x2e },
	{ 0x330b, 0x84 },
	{ 0x3304, 0x28 },
	{ 0x331e, 0x21 },
	{ 0x33ac, 0x04 },
	{ 0x33ae, 0x14 },
	{ 0x330e, 0x14 },
	{ 0x334c, 0x04 },
	{ 0x3310, 0x06 },
	{ 0x330f, 0x05 },
	{ 0x333a, 0x04 },
	{ 0x3630, 0x68 },
	{ 0x481d, 0x0a },
	{ 0x4827, 0x03 },
	{ 0x5787, 0x10 },
	{ 0x5788, 0x06 },
	{ 0x578a, 0x10 },
	{ 0x578b, 0x06 },
	{ 0x5790, 0x10 },
	{ 0x5791, 0x10 },
	{ 0x5792, 0x00 },
	{ 0x5793, 0x10 },
	{ 0x5794, 0x10 },
	{ 0x5795, 0x00 },
	{ 0x5799, 0x00 },
	{ 0x57c7, 0x10 },
	{ 0x57c8, 0x06 },
	{ 0x57ca, 0x10 },
	{ 0x57cb, 0x06 },
	{ 0x57d1, 0x10 },
	{ 0x57d4, 0x10 },
	{ 0x57d9, 0x00 },
	{ 0x3364, 0x17 },
	{ 0x3390, 0x08 },
	{ 0x3391, 0x18 },
	{ 0x3392, 0x38 },
	{ 0x3301, 0x06 },
	{ 0x3393, 0x09 },
	{ 0x3394, 0x20 },
	{ 0x3395, 0x20 },
	{ 0x3670, 0x08 },
	{ 0x369c, 0x08 },
	{ 0x369d, 0x38 },
	{ 0x3690, 0x32 },
	{ 0x3691, 0x32 },
	{ 0x3692, 0x44 },
	{ 0x3670, 0x0c },
	{ 0x367e, 0x08 },
	{ 0x367f, 0x18 },
	{ 0x3677, 0x84 },
	{ 0x3678, 0x85 },
	{ 0x3679, 0x87 },
	{ 0x3670, 0x0e },
	{ 0x367c, 0x18 },
	{ 0x367d, 0x38 },
	{ 0x3674, 0xa1 },
	{ 0x3675, 0x9c },
	{ 0x3676, 0x9e },
	{ 0x301f, 0x02 },
	{ 0x363c, 0x0d },
	{ 0x3306, 0x2e },
	{ 0x3631, 0x84 },
	{ 0x3622, 0x16 },
	{ 0x363c, 0x0e },
	{ 0x3253, 0x08 },
	{ 0x330b, 0x94 },
	{ 0x4509, 0x20 },
	{ 0x3314, 0x96 },
	{ 0x363a, 0x1f },
	{ 0x3e01, 0x8c },
	{ 0x3e02, 0x00 },
	{ 0x3306, 0x30 },
	{ 0x301f, 0x04 },
	{ 0x36e9, 0x20 },
	{ 0x36f9, 0x27 },
	{ 0x36e9, 0x59 },
	{ 0x36ea, 0xf5 },
	{ 0x36f9, 0x5b },
	{ 0x36fa, 0xdf },
	{ 0x301f, 0x1b },

	// sensor control settings
	{ 0x320c, 0x04 }, // line length [15:8]
	{ 0x320d, 0x4c }, // line length [ 7:0] 0x044c x 2 = 1100 x 2 = 2200
	{ 0x320e, 0x04 }, // frame line [13:8]
	{ 0x320f, 0x65 }, // frame line [ 7:0] 0x465 = 1125
	{ 0x3e00, 0x00 }, // SHS1 [19:16]
	{ 0x3e01, 0x23 }, // SHS1 [15: 8]
	{ 0x3e02, 0x20 }, // SHS1 [ 7: 4] 0x022d = 232 = 8326 us
	{ 0x3e03, 0x0b },
	{ 0x3e08, 0x03 }, // analog coarse
	{ 0x3e09, 0x40 }, // analog fine
	{ 0x3e06, 0x00 }, // digital coarse
	{ 0x3e07, 0x80 }, // digital fine
	{ 0x363c, 0x0e }, // denoise logic
	{ 0x3802, 0x00 }, // group hold delay
	{ 0x3812, 0x30 }, // group hold

	// MIPI settings, same as default values
	{ 0x3018, 0x32 }, // 2 lane
	{ 0x3031, 0x0a }, // 10 bit
	{ 0x3037, 0x20 },
	{ 0x303f, 0x01 },
	{ 0x4603, 0x00 },

	// other functions
	{ 0x5000, 0x00 }, // disable DPC
	// { 0x5000, 0x06 }, // enable DPC
	{ 0x363c, 0x0e }, // bloom reduction
	{ 0x5799, 0x00 }, // high temperature DPC
	{ 0x3221, 0x00 }, // no flip
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

	SENSOR_writeSeqWaddrBdata(fd, sizeof(k_cmd_format_1080p_30fps) / sizeof(SensCmd), k_cmd_format_1080p_30fps,
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
	p->sensor_fps = (float)SENSOR_FPS;
	p->frame_len_line = 1125;
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
