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

/* SENSOR_writeSeq macro is a unified wrapper for different lengths of register addresses and data. */
#if SENSOR_I2C_REG_LENGTH == 1 && SENSOR_I2C_DAT_LENGTH == 1
#define SENSOR_writeSeq(...) SENSOR_writeSeqBaddrBdata(__VA_ARGS__)
#elif SENSOR_I2C_REG_LENGTH == 1 && SENSOR_I2C_DAT_LENGTH == 2
#define SENSOR_writeSeq(...) SENSOR_writeSeqBaddrWdata(__VA_ARGS__)
#elif SENSOR_I2C_REG_LENGTH == 2 && SENSOR_I2C_DAT_LENGTH == 1
#define SENSOR_writeSeq(...) SENSOR_writeSeqWaddrBdata(__VA_ARGS__)
#elif SENSOR_I2C_REG_LENGTH == 2 && SENSOR_I2C_DAT_LENGTH == 2
#define SENSOR_writeSeq(...) SENSOR_writeSeqWaddrWdata(__VA_ARGS__)
#endif

/* I2C slave address and fd. */
static int g_i2c_fd[1] = {
	-1,
};
static const uint16_t k_i2c_slave_addr[1] = {
	SENSOR_I2C_SLAVE_ADDR,
};

/* SensCmd is the I2C (or other kinds of) commands to configure the sensor
 * for specific settings or function.
 *
 * Usually there will be at least following commands:
 * - register settings for specific streaming settings
 * - commands to start the streaming
 * - commands to stop the streaming
 *
 * Commands for controlling the frame rate or exposure are covered in sensor_cmos.c.
 */
static const SensCmd k_cmd_format_1080p_30fps[] = {
	{ 0x0f00, 0xba }, { 0xdead, 0xbf },
	// ...
};

static const SensCmd k_cmd_start[] = {
	{ 0x0001, 0x01 },
};

static const SensCmd k_cmd_stop[] = {
	{ 0x0001, 0x00 },
};

/* start the sensor */
static void SENSOR_configInitSeq(uint8_t path_idx)
{
	int fd = g_i2c_fd[path_idx];

	SENSOR_writeSeq(fd, sizeof(k_cmd_format_1080p_30fps) / sizeof(SensCmd), k_cmd_format_1080p_30fps,
	                k_i2c_slave_addr[path_idx]);

	SENSOR_writeSeq(fd, sizeof(k_cmd_start) / sizeof(SensCmd), k_cmd_start, k_i2c_slave_addr[path_idx]);
}

/* stop the sensor */
static void SENSOR_configExitSeq(uint8_t path_idx)
{
	int fd = g_i2c_fd[path_idx];

	SENSOR_writeSeq(fd, sizeof(k_cmd_stop) / sizeof(SensCmd), k_cmd_stop, k_i2c_slave_addr[path_idx]);
}

/* interfaces that are usually called from libmpp */
void SENSOR_configInit(uint8_t path_idx)
{
	int ret = 0;
	int i2c_fd = -1;

	ret = SENSOR_openI2cDev(&i2c_fd, k_i2c_slave_addr[path_idx]);
	if (ret != MPI_SUCCESS) {
		return;
	}

	g_i2c_fd[path_idx] = i2c_fd;

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
	p->intf_ptcl = MPI_INTF_PTCL_MIPI; // MIPI/DVP/SPI
	p->ptcl_mode = MPI_MIPI_CSI2;
	p->hsync_plty = MPI_PLTY_HIGH;
	p->vsync_plty = MPI_PLTY_HIGH;
	p->bayer = MPI_BAYER_PHASE_R; // G0/R/B/G1
	p->ext_clk_freq = SENSOR_EXT_CLK_FREQ;
	// sensor_res requires the original resolution output from the sensor.
	// It might differ from the usual video resolution if there's unneeded pixel data or in an HDR setting.
	p->sensor_res.width = SENSOR_WIDTH; // Passed from sensor_settings.h
	p->sensor_res.height = SENSOR_HEIGHT; // Passed from sensor_settings.h
	p->sensor_fps = SENSOR_FPS; // Passed from sensor_settings.h
	p->frame_len_line = INIT_FRAME_LINE;
	p->i2c_slv_addr = k_i2c_slave_addr[path_idx];
	p->ob_enable = 0;
	p->reserved = 0;

	// Lane swap information, passed from sensor_lvds.h
	memcpy(&p->parl_lane, &k_parl_lane[path_idx], sizeof(MPI_PARL_LANE_INFO_S));
	memcpy(&p->serl_lane[0], &k_serl_lane[path_idx], MPI_MAX_LVDSRX_LANE_NUM * sizeof(MPI_SERL_LANE_INFO_S));

	// Legacy method to calibrate time delay for individual machine.
	// SENSOR_getLvdsDelay(sns_idx, p->serl_lane);

	// Cropping
	// These settings does not affect the resolution metioned in the sensor_res variable.
	p->mipi.bp_img.hor = 0; // Left
	p->mipi.bp_img.ver = 0; // Top
	p->mipi.fp_img.hor = 0; // Right
	p->mipi.fp_img.ver = 0; // Bottom

	p->mipi.ob_conf.skipped_line_num = 0;
	p->mipi.ob_conf.pos = MPI_POS_NONE;
	p->mipi.ob_conf.region.x = 0;
	p->mipi.ob_conf.region.y = 0;
	p->mipi.ob_conf.region.width = 0;
	p->mipi.ob_conf.region.height = 0;

	p->mipi.vc_bmp = 0x1;
	p->mipi.dt_bmp = 0x0;
	p->mipi.t_hs_settle = 0xA;
	// Timing information, passed from sensor_settings.h
	p->mipi.t_hs_settle_ns = T_HS_SETTLE_NS;
	p->mipi.t_d_term_en_ns = T_D_TERM_EN_NS;
	p->mipi.t_clk_settle_ns = T_CLK_SETTLE_NS;
	p->mipi.t_clk_term_en_ns = T_CLK_TERM_EN_NS;

	return MPI_SUCCESS;
}
