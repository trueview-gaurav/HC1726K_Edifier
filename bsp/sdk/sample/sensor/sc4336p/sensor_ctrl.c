/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#include "sensor.h"
#include <stdio.h>
#include <stdint.h>
#include <string.h>

#include <unistd.h>

#include "sensor_settings.h"
#include "sensor_params.h"
#include "sensor_lvds.h"

#define SENSOR_PATH_MAX (4) // Should not be greater than MPI_MAX_INPUT_PATH_NUM

#if SENSOR_I2C_REG_LENGTH == 1 && SENSOR_I2C_DAT_LENGTH == 1
#define SENSOR_writeSeq(...) SENSOR_writeSeqBaddrBdata(__VA_ARGS__)
#elif SENSOR_I2C_REG_LENGTH == 1 && SENSOR_I2C_DAT_LENGTH == 2
#define SENSOR_writeSeq(...) SENSOR_writeSeqBaddrWdata(__VA_ARGS__)
#elif SENSOR_I2C_REG_LENGTH == 2 && SENSOR_I2C_DAT_LENGTH == 1
#define SENSOR_writeSeq(...) SENSOR_writeSeqWaddrBdata(__VA_ARGS__)
#elif SENSOR_I2C_REG_LENGTH == 2 && SENSOR_I2C_DAT_LENGTH == 2
#define SENSOR_writeSeq(...) SENSOR_writeSeqWaddrWdata(__VA_ARGS__)
#endif

/* For compatibility issues, k_i2c_slave_addr still holds I2C slave addresses from each sensor.
 * But g_i2c_fd only keeps the file descriptor for "this" libsensor.
 */

static int g_i2c_fd[1] = {
	-1,
};

static const uint16_t k_i2c_slave_addr[SENSOR_PATH_MAX] = {
	SENSOR_I2C_SLAVE_ADDR,
};

#if defined SET_2560_1440_30fps_2lane
// 2560x1440 30fps 2lane 630Mbps
static const SensCmd k_cmd_format_1440p_30fps[] = {
#ifndef DISABLE_SOFT_RESET
    {0x0103, 0x01}, {SENSOR_DELAY_REG, 0x0a}, // sleep by miliseconds
#endif
    {0x36e9, 0x80}, {0x37f9, 0x80}, {0x301f, 0x05}, {0x30b8, 0x44},
    {0x320e, 0x05}, {0x320f, 0xdc}, {0x3253, 0x10}, {0x3301, 0x0a},
    {0x3302, 0xff}, {0x3305, 0x00}, {0x3306, 0x90}, {0x3308, 0x08},
    {0x330a, 0x01}, {0x330b, 0xb0}, {0x330d, 0xf0}, {0x3314, 0x14},
    {0x3333, 0x10}, {0x3334, 0x40}, {0x335e, 0x06}, {0x335f, 0x0a},
    {0x3364, 0x5e}, {0x337d, 0x0e}, {0x338f, 0x20}, {0x3390, 0x08},
    {0x3391, 0x09}, {0x3392, 0x0f}, {0x3393, 0x18}, {0x3394, 0x60},
    {0x3395, 0xff}, {0x3396, 0x08}, {0x3397, 0x09}, {0x3398, 0x0f},
    {0x3399, 0x0a}, {0x339a, 0x18}, {0x339b, 0x60}, {0x339c, 0xff},
    {0x33a2, 0x04}, {0x33ad, 0x0c}, {0x33b2, 0x40}, {0x33b3, 0x30},
    {0x33f8, 0x00}, {0x33f9, 0xb0}, {0x33fa, 0x00}, {0x33fb, 0xf8},
    {0x33fc, 0x09}, {0x33fd, 0x1f}, {0x349f, 0x03}, {0x34a6, 0x09},
    {0x34a7, 0x1f}, {0x34a8, 0x28}, {0x34a9, 0x28}, {0x34aa, 0x01},
    {0x34ab, 0xe0}, {0x34ac, 0x02}, {0x34ad, 0x28}, {0x34f8, 0x1f},
    {0x34f9, 0x20}, {0x3630, 0xc0}, {0x3631, 0x84}, {0x3632, 0x54},
    {0x3633, 0x44}, {0x3637, 0x49}, {0x363f, 0xc0}, {0x3641, 0x28},
    {0x3670, 0x56}, {0x3674, 0xb0}, {0x3675, 0xa0}, {0x3676, 0xa0},
    {0x3677, 0x84}, {0x3678, 0x88}, {0x3679, 0x8d}, {0x367c, 0x09},
    {0x367d, 0x0b}, {0x367e, 0x08}, {0x367f, 0x0f}, {0x3696, 0x24},
    {0x3697, 0x34}, {0x3698, 0x34}, {0x36a0, 0x0f}, {0x36a1, 0x1f},
    {0x36b0, 0x81}, {0x36b1, 0x83}, {0x36b2, 0x85}, {0x36b3, 0x8b},
    {0x36b4, 0x09}, {0x36b5, 0x0b}, {0x36b6, 0x0f}, {0x370f, 0x01},
    {0x3722, 0x09}, {0x3724, 0x21}, {0x3771, 0x09}, {0x3772, 0x05},
    {0x3773, 0x05}, {0x377a, 0x0f}, {0x377b, 0x1f}, {0x3905, 0x8c},
    {0x391d, 0x02}, {0x391f, 0x49}, {0x3926, 0x21}, {0x3933, 0x80},
    {0x3934, 0x03}, {0x3937, 0x7b}, {0x3939, 0x00}, {0x393a, 0x00},
    {0x39dc, 0x02}, {0x3e00, 0x00}, {0x3e01, 0x5d}, {0x3e02, 0x40},
    {0x440d, 0x10}, {0x440e, 0x01}, {0x4509, 0x28}, {0x450d, 0x32},
    {0x5000, 0x06}, {0x5780, 0x76}, {0x5784, 0x10}, {0x5785, 0x04},
    {0x5787, 0x0a}, {0x5788, 0x0a}, {0x5789, 0x08}, {0x578a, 0x0a},
    {0x578b, 0x0a}, {0x578c, 0x08}, {0x578d, 0x40}, {0x5790, 0x08},
    {0x5791, 0x04}, {0x5792, 0x04}, {0x5793, 0x08}, {0x5794, 0x04},
    {0x5795, 0x04}, {0x5799, 0x46}, {0x579a, 0x77}, {0x57a1, 0x04},
    {0x57a8, 0xd2}, {0x57aa, 0x2a}, {0x57ab, 0x7f}, {0x57ac, 0x00},
    {0x57ad, 0x00}, {0x57d9, 0x46}, {0x57da, 0x77}, {0x59e2, 0x08},
    {0x59e3, 0x03}, {0x59e4, 0x00}, {0x59e5, 0x10}, {0x59e6, 0x06},
    {0x59e7, 0x00}, {0x59e8, 0x08}, {0x59e9, 0x02}, {0x59ea, 0x00},
    {0x59eb, 0x10}, {0x59ec, 0x04}, {0x59ed, 0x00}, {0x5ae0, 0xfe},
    {0x5ae1, 0x40}, {0x5ae2, 0x38}, {0x5ae3, 0x30}, {0x5ae4, 0x28},
    {0x5ae5, 0x38}, {0x5ae6, 0x30}, {0x5ae7, 0x28}, {0x5ae8, 0x3f},
    {0x5ae9, 0x34}, {0x5aea, 0x2c}, {0x5aeb, 0x3f}, {0x5aec, 0x34},
    {0x5aed, 0x2c}, {0x36e9, 0x53}, {0x37f9, 0x53},
};
#endif

/* clang-format on */

static const SensCmd k_cmd_start[] = {
	{ 0x0100, 0x01 },
	{ SENSOR_DELAY_REG, 1 }, //  Need delay 1 ,and then 0x02FF will write to sensor.
	{ 0x3944, 0x02 },
	{ 0x3945, 0xFF },
};

static const SensCmd k_cmd_stop[] = {
	{ 0x0100, 0x00 },
};

static void SENSOR_configInitSeq(uint8_t path_idx)
{
	int fd = g_i2c_fd[0];
	int slave_addr = k_i2c_slave_addr[path_idx];

#if defined SET_2560_1440_30fps_2lane
	SENSOR_writeSeq(fd, sizeof(k_cmd_format_1440p_30fps) / sizeof(SensCmd), k_cmd_format_1440p_30fps, slave_addr);
#endif

	// TODO: verify if update_exp_cmd is required
#ifdef SNS0
	cmos_ctrl(SNS0_ID).update_exp_cmd(fd, path_idx);
#endif
#ifdef SNS1
	cmos_ctrl(SNS1_ID).update_exp_cmd(fd, path_idx);
#endif
#ifdef SNS2
	cmos_ctrl(SNS2_ID).update_exp_cmd(fd, path_idx);
#endif
#ifdef SNS3
	cmos_ctrl(SNS3_ID).update_exp_cmd(fd, path_idx);
#endif

	SENSOR_writeSeq(fd, sizeof(k_cmd_start) / sizeof(SensCmd), k_cmd_start, k_i2c_slave_addr[path_idx]);
}

static void SENSOR_configExitSeq(uint8_t path_idx)
{
	int fd = g_i2c_fd[0];
	int slave_addr = k_i2c_slave_addr[path_idx];

	SENSOR_writeSeq(fd, sizeof(k_cmd_stop) / sizeof(SensCmd), k_cmd_stop, slave_addr);
}

/* Global Interface */
void SENSOR_configInit(uint8_t path_idx)
{
	int ret = 0;
	int i2c_fd = -1;

	if (path_idx >= SENSOR_PATH_MAX) {
		sensor_log_err("Unsupported sensor index %d.", path_idx);
		return;
	}

	/* Open I2C device node */
	ret = SENSOR_openI2cDev(&i2c_fd, k_i2c_slave_addr[path_idx]);
	if (ret != MPI_SUCCESS) {
		return;
	}

	g_i2c_fd[0] = i2c_fd;

	/* Start sensor */
	SENSOR_configInitSeq(path_idx);
}

void SENSOR_configExit(uint8_t path_idx)
{
	int ret = 0;
	int i2c_fd = g_i2c_fd[0];

	if (path_idx >= SENSOR_PATH_MAX) {
		sensor_log_err("Unsupported sensor index %d.", path_idx);
		return;
	}

	/* Stop sensor */
	SENSOR_configExitSeq(path_idx);

	if (g_i2c_fd[0] != -1) {
		/* Close I2C device node */
		ret = SENSOR_closeI2cDev(i2c_fd);
		if (ret != MPI_SUCCESS) {
			return;
		}

		g_i2c_fd[0] = -1;
	}
}

int32_t SENSOR_getOpInfo(uint8_t path_idx, uint32_t sns_idx, MPI_SNS_OP_INFO_S *p_op_info)
{
	MPI_SNS_OP_INFO_S *p = p_op_info;
	float sensor_fps = SENSOR_FPS;
	int16_t frame_len_line = SENSOR_HEIGHT;
	int i;

	if (path_idx >= SENSOR_PATH_MAX) {
		sensor_log_err("Unsupported sensor index %d.", path_idx);
		return MPI_FAILURE;
	}

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

	p->parl_lane = k_parl_lane[0];
	for (i = 0; i < MPI_MAX_LVDSRX_LANE_NUM; i++) {
		p->serl_lane[i] = k_serl_lane[0][i];
	}

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
