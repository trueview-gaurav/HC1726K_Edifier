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

// 640x360 60fps_1lane
static const SensCmd k_cmd_format_360p_60fps[] = {
	{ 0x03fe, 0xf0 }, { 0x03fe, 0xf0 }, { 0x03fe, 0xf0 }, { 0x03fe, 0x00 }, { 0x03f2, 0x00 }, { 0x03f3, 0x00 },
	{ 0x03f4, 0x36 }, { 0x03f5, 0xc0 }, { 0x03f6, 0x13 }, { 0x03f7, 0x01 }, { 0x03f8, 0x32 }, { 0x03f9, 0x21 },
	{ 0x03fc, 0xae }, { 0x0d05, 0x08 }, { 0x0d06, 0xae }, { 0x0d08, 0x10 }, { 0x0d0a, 0x02 }, { 0x000c, 0x03 },
	{ 0x0d0d, 0x02 }, { 0x0d0e, 0xd0 }, { 0x000f, 0x05 }, { 0x0010, 0x00 }, { 0x0017, 0x08 }, { 0x0d73, 0x92 },
	{ 0x0076, 0x00 }, { 0x0d76, 0x00 }, { 0x0d41, 0x02 }, { 0x0d42, 0xee }, { 0x0d7a, 0x0a }, { 0x006b, 0x18 },
	{ 0x0db0, 0x9d }, { 0x0db1, 0x00 }, { 0x0db2, 0xac }, { 0x0db3, 0xd5 }, { 0x0db4, 0x00 }, { 0x0db5, 0x97 },
	{ 0x0db6, 0x09 }, { 0x00d2, 0xfc }, { 0x0d19, 0x31 }, { 0x0d20, 0x40 }, { 0x0d25, 0xcb }, { 0x0d27, 0x03 },
	{ 0x0d29, 0x40 }, { 0x0d43, 0x20 }, { 0x0058, 0x60 }, { 0x00d6, 0x66 }, { 0x00d7, 0x19 }, { 0x0093, 0x02 },
	{ 0x00d9, 0x14 }, { 0x00da, 0xc1 }, { 0x0d2a, 0x00 }, { 0x0d28, 0x04 }, { 0x0dc2, 0x84 }, { 0x0050, 0x30 },
	{ 0x0080, 0x07 }, { 0x008c, 0x05 }, { 0x008d, 0xa8 }, { 0x0077, 0x01 }, { 0x0078, 0xee }, { 0x0079, 0x02 },
	{ 0x0067, 0xc0 }, { 0x0054, 0x40 }, { 0x0055, 0x01 }, { 0x0056, 0x00 }, { 0x0057, 0x04 }, { 0x005a, 0xff },
	{ 0x005b, 0x07 }, { 0x00d5, 0x03 }, { 0x0102, 0xa9 }, { 0x0d03, 0x02 }, { 0x0d04, 0xe0 }, { 0x007a, 0x60 },
	{ 0x04e0, 0xff }, { 0x0414, 0x75 }, { 0x0415, 0x75 }, { 0x0416, 0x75 }, { 0x0417, 0x75 }, { 0x0122, 0x00 },
	{ 0x0121, 0x80 }, { 0x0428, 0x10 }, { 0x0429, 0x10 }, { 0x042a, 0x10 }, { 0x042b, 0x10 }, { 0x042c, 0x14 },
	{ 0x042d, 0x14 }, { 0x042e, 0x18 }, { 0x042f, 0x18 }, { 0x0430, 0x05 }, { 0x0431, 0x05 }, { 0x0432, 0x05 },
	{ 0x0433, 0x05 }, { 0x0434, 0x05 }, { 0x0435, 0x05 }, { 0x0436, 0x05 }, { 0x0437, 0x05 }, { 0x0153, 0x00 },
	{ 0x0190, 0x01 }, { 0x0192, 0x00 }, { 0x0194, 0x00 }, { 0x0195, 0x01 }, { 0x0196, 0x68 }, { 0x0197, 0x02 },
	{ 0x0198, 0x80 }, { 0x0201, 0x23 }, { 0x0202, 0x53 }, { 0x0203, 0xce }, { 0x0208, 0x39 }, { 0x0212, 0x03 },
	{ 0x0213, 0x20 }, { 0x0215, 0x12 }, { 0x0229, 0x05 }, { 0x023e, 0x98 }, { 0x0189, 0x23 },
	//{ 0x031e, 0x3e }, { 0x0040, 0x0a }, { 0x0015, 0x04 }, { 0x0d15, 0x04 }, { 0x03fc, 0x8e },
};

static const SensCmd k_cmd_start[] = {
	{ 0x031e, 0x3e }, { 0x0040, 0x0a }, { 0x0015, 0x04 }, { 0x0d15, 0x04 }, { 0x03fc, 0x8e },
};

static const SensCmd k_cmd_stop[] = {
	{ 0x031e, 0x00 },
};

static void SENSOR_configInitSeq(uint8_t path_idx)
{
	int fd = g_i2c_fd[path_idx];

	SENSOR_writeSeqWaddrBdata(fd, sizeof(k_cmd_format_360p_60fps) / sizeof(SensCmd), k_cmd_format_360p_60fps,
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
	// usleep(380000);

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
	p->bayer = MPI_BAYER_PHASE_G0;
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

	p->mipi.dt_bmp = 0x0;
	p->mipi.vc_bmp = 0x1;
	p->mipi.t_hs_settle = 0xA;
	p->mipi.t_hs_settle_ns = T_HS_SETTLE_NS;
	p->mipi.t_d_term_en_ns = T_D_TERM_EN_NS;
	p->mipi.t_clk_settle_ns = T_CLK_SETTLE_NS;
	p->mipi.t_clk_term_en_ns = T_CLK_TERM_EN_NS;

	return MPI_SUCCESS;
}
