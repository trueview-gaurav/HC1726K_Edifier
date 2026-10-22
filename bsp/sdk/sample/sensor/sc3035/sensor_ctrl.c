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

// 2304x1536 30fps
static const SensCmd k_cmd_format_2304x1536_30fps[] = {
	// Remove this register since there's a problem writing to SC3035
	// { 0x0103, 0x01 },
	// { SENSOR_DELAY_REG, 0x0a },
	{ 0x0100, 0x00 },
	{ 0x3019, 0xff },
	{ 0x301a, 0xf8 },
	{ 0x301c, 0xa4 },
	{ 0x301e, 0xe0 },
	{ 0x3022, 0x13 },
	{ 0x3034, 0x01 },
	{ 0x3035, 0xba },
	{ 0x3036, 0x00 },
	{ 0x3038, 0xf8 },
	{ 0x3039, 0x33 },
	{ 0x303a, 0x75 },
	{ 0x303b, 0x10 },
	{ 0x303c, 0x00 },
	{ 0x303d, 0x03 },
	{ 0x303f, 0x82 },
	{ 0x3200, 0x00 },
	{ 0x3201, 0x94 },
	{ 0x3202, 0x00 },
	{ 0x3203, 0x0c },
	{ 0x3204, 0x09 },
	{ 0x3205, 0x9b },
	{ 0x3206, 0x06 },
	{ 0x3207, 0x13 },
	{ 0x3208, 0x09 },
	{ 0x3209, 0x00 },
	{ 0x320a, 0x06 },
	{ 0x320b, 0x00 },
	{ 0x320c, 0x04 },
	{ 0x320d, 0xe2 },
	{ 0x320e, 0x06 },
	{ 0x320f, 0x30 },
	{ 0x3210, 0x00 },
	{ 0x3211, 0x04 },
	{ 0x3212, 0x00 },
	{ 0x3213, 0x04 },
#if defined SENSOR_ROTATE_IMG && SENSOR_ROTATE_IMG == 1
	{ 0x3220, 0x06 },
	{ 0x3221, 0x06 },
#else
	{ 0x3220, 0x00 },
	{ 0x3221, 0x00 },
#endif
	{ 0x322e, 0x00 },
	{ 0x322f, 0xaf },
	{ 0x3300, 0x30 },
	{ 0x3303, 0x20 },
	{ 0x3306, 0x66 },
	{ 0x3307, 0x17 },
	{ 0x3308, 0x08 },
	{ 0x3309, 0x20 },
	{ 0x330a, 0x01 },
	{ 0x330b, 0x0e },
	{ 0x330c, 0x0b },
	{ 0x330e, 0x17 },
	{ 0x330f, 0x07 },
	{ 0x3310, 0x42 },
	{ 0x3312, 0x06 },
	{ 0x331e, 0x10 },
	{ 0x331f, 0x10 },
	{ 0x3320, 0x18 },
	{ 0x3321, 0x18 },
	{ 0x3322, 0x18 },
	{ 0x3323, 0x18 },
	{ 0x3324, 0x07 },
	{ 0x3325, 0x07 },
	{ 0x3333, 0x80 },
	{ 0x3334, 0x20 },
	{ 0x3340, 0x04 },
	{ 0x3341, 0x80 },
	{ 0x3342, 0x02 },
	{ 0x3343, 0x70 },
	{ 0x3348, 0x04 },
	{ 0x3349, 0xd2 },
	{ 0x334a, 0x02 },
	{ 0x334b, 0x70 },
	{ 0x335b, 0xca },
	{ 0x335d, 0x2a },
	{ 0x335e, 0x05 },
	{ 0x335f, 0x0e },
	{ 0x3367, 0x01 },
	{ 0x3368, 0x03 },
	{ 0x3369, 0x30 },
	{ 0x336a, 0x06 },
	{ 0x336b, 0x30 },
	{ 0x3416, 0x11 },
	{ 0x3620, 0x63 },
	{ 0x3621, 0x18 },
	{ 0x3622, 0x1e },
	{ 0x3626, 0x11 },
	{ 0x3627, 0x06 },
	{ 0x3630, 0x67 },
	{ 0x3631, 0x84 },
	{ 0x3633, 0x3d },
	{ 0x3635, 0x62 },
	{ 0x3636, 0x8d },
	{ 0x3637, 0xbe },
	{ 0x3638, 0x85 },
	{ 0x3639, 0x80 },
	{ 0x363a, 0x04 },
	{ 0x363c, 0x88 },
	{ 0x3640, 0x03 },
	{ 0x3641, 0x01 },
	{ 0x3662, 0x82 },
	{ 0x3c00, 0x45 },
	{ 0x3c03, 0x02 },
	{ 0x3d08, 0x00 },
	{ 0x3d0d, 0x00 },
	{ 0x3e01, 0x30 },
	{ 0x3e03, 0x03 },
	{ 0x3e08, 0x00 },
	{ 0x3e09, 0x10 },
	{ 0x3f01, 0x04 },
	{ 0x3f04, 0x01 },
	{ 0x3f05, 0xf8 },
	{ 0x4500, 0x31 },
	{ 0x4501, 0xa4 },
	{ 0x5000, 0x21 },
	{ 0x5780, 0xff },
	{ 0x5781, 0x04 },
	{ 0x5785, 0x10 },
};

// 1536x1536 30fps
static const SensCmd k_cmd_format_1536x1536_30fps[] = {

};

// 1536x1536 15fps
static const SensCmd k_cmd_format_1536x1536_15fps[] = {
	// Remove this register since there's a problem writing to SC3035
	// { 0x0103, 0x01 },
	// { SENSOR_DELAY_REG, 0x0a },
	{ 0x0100, 0x00 },
	{ 0x3019, 0xff },
	{ 0x301a, 0xf8 },
	{ 0x301c, 0xa4 },
	{ 0x301e, 0xe0 },
	{ 0x3022, 0x13 },
	{ 0x3034, 0x01 },
	{ 0x3035, 0xba },
	{ 0x3036, 0x00 },
	{ 0x3038, 0xf8 },
	{ 0x3039, 0x33 },
	{ 0x303a, 0x75 },
	{ 0x303b, 0x18 },
	{ 0x303c, 0x00 },
	{ 0x303d, 0x03 },
	{ 0x303f, 0x82 },
	{ 0x3200, 0x02 },
	{ 0x3201, 0x14 },
	{ 0x3202, 0x00 },
	{ 0x3203, 0x0c },
	{ 0x3204, 0x08 },
	{ 0x3205, 0x1b },
	{ 0x3206, 0x06 },
	{ 0x3207, 0x13 },
	{ 0x3208, 0x06 },
	{ 0x3209, 0x00 },
	{ 0x320a, 0x06 },
	{ 0x320b, 0x00 },
	{ 0x320c, 0x04 },
	{ 0x320d, 0xe2 },
	{ 0x320e, 0x06 },
	{ 0x320f, 0x30 },
	{ 0x3210, 0x00 },
	{ 0x3211, 0x04 },
	{ 0x3212, 0x00 },
	{ 0x3213, 0x04 },
#if defined SENSOR_ROTATE_IMG && SENSOR_ROTATE_IMG == 1
	{ 0x3220, 0x06 },
	{ 0x3221, 0x06 },
#else
	{ 0x3220, 0x00 },
	{ 0x3221, 0x00 },
#endif
	{ 0x322e, 0x00 },
	{ 0x322f, 0xaf },
	{ 0x3300, 0x30 },
	{ 0x3303, 0x20 },
	{ 0x3306, 0x30 },
	{ 0x3307, 0x17 },
	{ 0x3308, 0x08 },
	{ 0x3309, 0x20 },
	{ 0x330a, 0x00 },
	{ 0x330b, 0x78 },
	{ 0x330c, 0x0b },
	{ 0x330e, 0x17 },
	{ 0x330f, 0x07 },
	{ 0x3310, 0x42 },
	{ 0x3312, 0x06 },
	{ 0x331e, 0x10 },
	{ 0x331f, 0x10 },
	{ 0x3320, 0x18 },
	{ 0x3321, 0x18 },
	{ 0x3322, 0x18 },
	{ 0x3323, 0x18 },
	{ 0x3324, 0x07 },
	{ 0x3325, 0x07 },
	{ 0x3333, 0x80 },
	{ 0x3334, 0x20 },
	{ 0x3340, 0x04 },
	{ 0x3341, 0x80 },
	{ 0x3342, 0x02 },
	{ 0x3343, 0x70 },
	{ 0x3348, 0x04 },
	{ 0x3349, 0xd2 },
	{ 0x334a, 0x02 },
	{ 0x334b, 0x70 },
	{ 0x335b, 0xca },
	{ 0x335d, 0x2a },
	{ 0x335e, 0x05 },
	{ 0x335f, 0x0e },
	{ 0x3367, 0x01 },
	{ 0x3368, 0x03 },
	{ 0x3369, 0x30 },
	{ 0x336a, 0x06 },
	{ 0x336b, 0x30 },
	{ 0x3416, 0x11 },
	{ 0x3620, 0x63 },
	{ 0x3621, 0x18 },
	{ 0x3622, 0x1e },
	{ 0x3626, 0x11 },
	{ 0x3627, 0x06 },
	{ 0x3630, 0x67 },
	{ 0x3631, 0x84 },
	{ 0x3633, 0x3d },
	{ 0x3635, 0x62 },
	{ 0x3636, 0x8d },
	{ 0x3637, 0xbe },
	{ 0x3638, 0x85 },
	{ 0x3639, 0x80 },
	{ 0x363a, 0x04 },
	{ 0x363c, 0x88 },
	{ 0x3640, 0x03 },
	{ 0x3641, 0x01 },
	{ 0x3662, 0x82 },
	{ 0x3c00, 0x45 },
	{ 0x3c03, 0x02 },
	{ 0x3d08, 0x01 },
	{ 0x3d0d, 0x00 },
	{ 0x3e01, 0x30 },
	{ 0x3e03, 0x03 },
	{ 0x3e08, 0x00 },
	{ 0x3e09, 0x10 },
	{ 0x3f01, 0x04 },
	{ 0x3f04, 0x01 },
	{ 0x3f05, 0xf8 },
	{ 0x4500, 0x31 },
	{ 0x4501, 0xa4 },
	{ 0x5000, 0x21 },
	{ 0x5780, 0xff },
	{ 0x5781, 0x04 },
	{ 0x5785, 0x10 },
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
	int frate = SENSOR_FPS;

	if (width == 2304 && height == 1536 && frate == 30) {
		SENSOR_writeSeq(fd, sizeof(k_cmd_format_2304x1536_30fps) / sizeof(SensCmd),
		                k_cmd_format_2304x1536_30fps, k_i2c_slave_addr[path_idx]);
	} else if (width == 1536 && height == 1536 && frate == 30) {
		SENSOR_writeSeq(fd, sizeof(k_cmd_format_1536x1536_30fps) / sizeof(SensCmd),
		                k_cmd_format_1536x1536_30fps, k_i2c_slave_addr[path_idx]);
	} else if (width == 1536 && height == 1536 && frate == 15) {
		SENSOR_writeSeq(fd, sizeof(k_cmd_format_1536x1536_15fps) / sizeof(SensCmd),
		                k_cmd_format_1536x1536_15fps, k_i2c_slave_addr[path_idx]);
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
	// bit width of a dvp sensor is directly affected by the hardware wire connection
	// so it should be defined in sensor_params.h
	p->bit_width = SENSOR_DVP_BIT_WIDTH; // defined in sensor_params.h
	p->intf_ptcl = MPI_INTF_PTCL_DVP;
	// p->ptcl_mode = MPI_MIPI_CSI2; // not required in DVP mode
	p->hsync_plty = MPI_PLTY_HIGH;
	p->vsync_plty = MPI_PLTY_LOW;
	p->bayer = MPI_BAYER_PHASE_B;
	p->ext_clk_freq = SENSOR_EXT_CLK_FREQ;
	p->sensor_res.width = SENSOR_WIDTH;
	p->sensor_res.height = SENSOR_HEIGHT;
	p->sensor_fps = (float)SENSOR_FPS;
	p->frame_len_line = INIT_FRAME_LINE;
	p->i2c_slv_addr = k_i2c_slave_addr[path_idx];
	p->ob_enable = 0;
	p->reserved = 0;

	memcpy(&p->parl_lane, &k_parl_lane[path_idx], sizeof(MPI_PARL_LANE_INFO_S));
	memcpy(&p->serl_lane[0], &k_serl_lane[path_idx], MPI_MAX_LVDSRX_LANE_NUM * sizeof(MPI_SERL_LANE_INFO_S));
	SENSOR_getLvdsDelay(sns_idx, p->serl_lane);

	p->dvp.io_volt = MPI_VOLT_1P8V;

	return MPI_SUCCESS;
}
