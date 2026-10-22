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

// 2592x1944 30fps 2lane 828Mbps
static const SensCmd k_cmd_format_1944p_30fps[] = {	
	{ 0x0103, 0x01 },
	{ SENSOR_DELAY_REG, 0x0A }, //delay 10ms	
	{ 0x0100, 0x00 },
	{ 0x3039, 0x80 },
	{ 0x3029, 0x80 },
	{ 0x301f, 0x18 },
	{ 0x302a, 0x69 },
	{ 0x302b, 0x10 },
	{ 0x302c, 0x00 },
	{ 0x302d, 0x03 },
	{ 0x3037, 0x26 },
	{ 0x3038, 0x66 },
	{ 0x303a, 0x29 },
	{ 0x303b, 0x0a },
	{ 0x303c, 0x0e },
	{ 0x303d, 0x03 },
	{ 0x3200, 0x00 },
	{ 0x3201, 0x00 },
	{ 0x3202, 0x00 },
	{ 0x3203, 0x00 },
	{ 0x3204, 0x0a },
	{ 0x3205, 0x2b },
	{ 0x3206, 0x07 },
	{ 0x3207, 0x9f },
	{ 0x3208, 0x0a },
	{ 0x3209, 0x20 },
	{ 0x320a, 0x07 },
	{ 0x320b, 0x98 },
	{ 0x320c, 0x05 },
	{ 0x320d, 0x64 },
	{ 0x320e, 0x07 },
	{ 0x320f, 0xd0 },
	{ 0x3211, 0x08 },
	{ 0x3213, 0x04 },
	{ 0x3235, 0x0f },
	{ 0x3236, 0x9c },
	{ 0x3301, 0x38 },
	{ 0x3303, 0x20 },
	{ 0x3304, 0x10 },
	{ 0x3306, 0x58 },
	{ 0x3308, 0x10 },
	{ 0x3309, 0x60 },
	{ 0x330a, 0x00 },
	{ 0x330b, 0xb8 },
	{ 0x330d, 0x30 },
	{ 0x330e, 0x20 },
	{ 0x3314, 0x14 },
	{ 0x3315, 0x02 },
	{ 0x331b, 0x83 },
	{ 0x331e, 0x19 },
	{ 0x331f, 0x59 },
	{ 0x3320, 0x01 },
	{ 0x3321, 0x04 },
	{ 0x3326, 0x00 },
	{ 0x3332, 0x22 },
	{ 0x3333, 0x20 },
	{ 0x3334, 0x40 },
	{ 0x3350, 0x22 },
	{ 0x3359, 0x22 },
	{ 0x335c, 0x22 },
	{ 0x3364, 0x05 },
	{ 0x3366, 0xc8 },
	{ 0x3367, 0x08 },
	{ 0x3368, 0x03 },
	{ 0x3369, 0x00 },
	{ 0x336a, 0x00 },
	{ 0x336b, 0x00 },
	{ 0x336c, 0x01 },
	{ 0x336d, 0x40 },
	{ 0x337f, 0x03 },
	{ 0x338f, 0x40 },
	{ 0x33ae, 0x22 },
	{ 0x33af, 0x22 },
	{ 0x33b0, 0x22 },
	{ 0x33b4, 0x22 },
	{ 0x33b6, 0x07 },
	{ 0x33b7, 0x17 },
	{ 0x33b8, 0x20 },
	{ 0x33b9, 0x20 },
	{ 0x33ba, 0x44 },
	{ 0x3614, 0x00 },
	{ 0x3620, 0x28 },
	{ 0x3621, 0xac },
	{ 0x3622, 0xf6 },
	{ 0x3623, 0x08 },
	{ 0x3624, 0x47 },
	{ 0x3625, 0x0b },
	{ 0x3630, 0x30 },
	{ 0x3631, 0x88 },
	{ 0x3632, 0x18 },
	{ 0x3633, 0x34 },
	{ 0x3634, 0x86 },
	{ 0x3635, 0x4d },
	{ 0x3636, 0x21 },
	{ 0x3637, 0x20 },
	{ 0x3638, 0x18 },
	{ 0x3639, 0x09 },
	{ 0x363a, 0x83 },
	{ 0x363b, 0x02 },
	{ 0x363c, 0x07 },
	{ 0x363d, 0x03 },
	{ 0x3670, 0x00 },
	{ 0x3677, 0x86 },
	{ 0x3678, 0x86 },
	{ 0x3679, 0xa8 },
	{ 0x367e, 0x08 },
	{ 0x367f, 0x18 },
	{ 0x3802, 0x00 },
	{ 0x3905, 0x98 },
	{ 0x3907, 0x01 },
	{ 0x3908, 0x11 },
	{ 0x390a, 0x00 },
	{ 0x391c, 0x9f },
	{ 0x391d, 0x00 },
	{ 0x391e, 0x01 },
	{ 0x391f, 0xc0 },
	{ 0x3e00, 0x00 },
	{ 0x3e01, 0xf9 },
	{ 0x3e02, 0x80 },
	{ 0x3e03, 0x0b },
	{ 0x3e06, 0x00 },
	{ 0x3e07, 0x80 },
	{ 0x3e08, 0x03 },
	{ 0x3e09, 0x20 },
	{ 0x3e1e, 0x30 },
	{ 0x3e26, 0x20 },
	{ 0x3f00, 0x0d },
	{ 0x3f02, 0x05 },
	{ 0x3f04, 0x02 },
	{ 0x3f05, 0xaa },
	{ 0x3f06, 0x21 },
	{ 0x3f08, 0x04 },
	{ 0x4500, 0x5d },
	{ 0x4502, 0x10 },
	{ 0x4509, 0x10 },
	{ 0x4800, 0x64 },
	{ 0x4809, 0x01 },
	{ 0x4818, 0x00 },
	{ 0x4819, 0x34 },
	{ 0x481a, 0x00 },
	{ 0x481b, 0x1c },
	{ 0x481c, 0x00 },
	{ 0x481d, 0xc8 },
	{ 0x4821, 0x02 },
	{ 0x4822, 0x00 },
	{ 0x4823, 0x03 },
	{ 0x4828, 0x00 },
	{ 0x4829, 0x02 },
	{ 0x4837, 0x19 },
	{ 0x5000, 0x20 },
	{ 0x5002, 0x00 },
	{ 0x5988, 0x02 },
	{ 0x598e, 0x05 },
	{ 0x598f, 0x30 },
	{ 0x6000, 0x20 },
	{ 0x6002, 0x00 },
	{ 0x3039, 0x23 },
	{ 0x3029, 0x33 },
	// { 0x0100, 0x01 },
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

	if (width == 2592 && height == 1944 && SENSOR_FPS == 30) {
		SENSOR_writeSeqWaddrBdata(fd, sizeof(k_cmd_format_1944p_30fps) / sizeof(SensCmd),
		                          k_cmd_format_1944p_30fps, k_i2c_slave_addr[path_idx]);
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
