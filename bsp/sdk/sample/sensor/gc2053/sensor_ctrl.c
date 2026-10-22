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

#define FPS (30.0)

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

// 1920x1080 30fps_2lane
static const SensCmd k_cmd_format_1080p_30fps[] = {
	{ 0xfe, 0x80 },
	{ 0xfe, 0x80 },
	{ 0xfe, 0x80 },
	{ 0xfe, 0x00 },
	{ 0xf2, 0x00 },
	{ 0xf3, 0x00 },
	{ 0xf4, 0x36 },
	{ 0xf5, 0xc0 },
	{ 0xf6, 0x44 },
	{ 0xf7, 0x01 },
	{ 0xf8, 0x63 },
	{ 0xf9, 0x40 },
	{ 0xfc, 0x8e },
	//****CISCTL & ANALOG****
	{ 0xfe, 0x00 },
	{ 0x87, 0x18 },
	{ 0xee, 0x30 },
	{ 0xd0, 0xb7 },
	{ 0x03, 0x04 },
	{ 0x04, 0x00 },
	{ 0x05, 0x04 },
	{ 0x06, 0x4c },
	// { 0x07, 0x00 }, // use frame line instead of VB
	// { 0x08, 0x11 },
	{ 0x09, 0x00 },
	{ 0x0a, 0x02 },
	{ 0x0b, 0x00 },
	{ 0x0c, 0x02 },
	{ 0x0d, 0x04 },
	{ 0x0e, 0x40 },
	{ 0x12, 0xe2 },
	{ 0x13, 0x16 },
	{ 0x17, 0x80 }, // rotate the screen due to our chip design
	{ 0x19, 0x0a },
	{ 0x21, 0x1c },
	{ 0x28, 0x0a },
	{ 0x29, 0x24 },
	{ 0x2b, 0x04 },
	{ 0x32, 0xf8 },
	{ 0x37, 0x03 },
	{ 0x39, 0x15 },
	{ 0x41, 0x04 }, // frame line [13:8]
	{ 0x42, 0x65 }, // frame line [7:0]
	{ 0x43, 0x07 },
	{ 0x44, 0x40 },
	{ 0x46, 0x0b },
	{ 0x4b, 0x20 },
	{ 0x4e, 0x08 },
	{ 0x55, 0x20 },
	{ 0x66, 0x05 },
	{ 0x67, 0x05 },
	{ 0x77, 0x01 },
	{ 0x78, 0x00 },
	{ 0x7c, 0x93 },
	{ 0x8c, 0x12 },
	{ 0x8d, 0x92 },
	{ 0x90, 0x00 }, // disable frame line - shutter time syncronization
	{ 0x9d, 0x10 },
	{ 0xce, 0x7c },
	{ 0xd2, 0x41 },
	{ 0xd3, 0xdc },
	{ 0xe6, 0x50 },
	//*gain*
	{ 0xb6, 0xc0 },
	{ 0xb0, 0x70 },
	{ 0xb1, 0x01 },
	{ 0xb2, 0x00 },
	{ 0xb3, 0x00 },
	{ 0xb4, 0x00 },
	{ 0xb8, 0x01 },
	{ 0xb9, 0x00 },
	//*blk*
	{ 0x26, 0x30 },
	{ 0xfe, 0x01 },
	{ 0x40, 0x23 },
	{ 0x55, 0x07 },
	{ 0x60, 0x40 },
	{ 0xfe, 0x04 },
	{ 0x14, 0x78 },
	{ 0x15, 0x78 },
	{ 0x16, 0x78 },
	{ 0x17, 0x78 },
	//*window*
	{ 0xfe, 0x01 },
	{ 0x92, 0x00 },
	{ 0x94, 0x03 },
	{ 0x95, 0x04 },
	{ 0x96, 0x38 },
	{ 0x97, 0x07 },
	{ 0x98, 0x80 },
	//*ISP*
	{ 0xfe, 0x01 },
	{ 0x01, 0x05 },
	{ 0x02, 0x89 },
	{ 0x04, 0x01 },
	{ 0x07, 0xa6 },
	{ 0x08, 0xa9 },
	{ 0x09, 0xa8 },
	{ 0x0a, 0xa7 },
	{ 0x0b, 0xff },
	{ 0x0c, 0xff },
	{ 0x0f, 0x00 },
	{ 0x50, 0x1c },
	{ 0x89, 0x03 },
	{ 0xfe, 0x04 },
	{ 0x28, 0x86 },
	{ 0x29, 0x86 },
	{ 0x2a, 0x86 },
	{ 0x2b, 0x68 },
	{ 0x2c, 0x68 },
	{ 0x2d, 0x68 },
	{ 0x2e, 0x68 },
	{ 0x2f, 0x68 },
	{ 0x30, 0x4f },
	{ 0x31, 0x68 },
	{ 0x32, 0x67 },
	{ 0x33, 0x66 },
	{ 0x34, 0x66 },
	{ 0x35, 0x66 },
	{ 0x36, 0x66 },
	{ 0x37, 0x66 },
	{ 0x38, 0x62 },
	{ 0x39, 0x62 },
	{ 0x3a, 0x62 },
	{ 0x3b, 0x62 },
	{ 0x3c, 0x62 },
	{ 0x3d, 0x62 },
	{ 0x3e, 0x62 },
	{ 0x3f, 0x62 },
	//****DVP & MIPI****
	{ 0xfe, 0x01 },
	{ 0x9a, 0x06 },
	{ 0xfe, 0x00 },
	{ 0x7b, 0x2a },
	{ 0x23, 0x2d },
	{ 0xfe, 0x03 },
	{ 0x01, 0x27 },
	{ 0x02, 0x56 },
	{ 0x03, 0xb6 },
	{ 0x12, 0x80 },
	{ 0x13, 0x07 },
	{ 0x15, 0x12 },
	{ 0xfe, 0x00 },
	// { 0x3e, 0x91 },
};

static const SensCmd k_cmd_start[] = {
	{ 0x3e, 0x91 },
};

static const SensCmd k_cmd_stop[] = {
	{ 0x3e, 0x00 },
};

static void SENSOR_configInitSeq(uint8_t path_idx)
{
	int fd = g_i2c_fd[path_idx];

	SENSOR_writeSeqBaddrBdata(fd, sizeof(k_cmd_format_1080p_30fps) / sizeof(SensCmd), k_cmd_format_1080p_30fps,
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

	SENSOR_writeSeqBaddrBdata(fd, sizeof(k_cmd_start) / sizeof(SensCmd), k_cmd_start, k_i2c_slave_addr[path_idx]);
}

static void SENSOR_configExitSeq(uint8_t path_idx)
{
	int fd = g_i2c_fd[path_idx];

	SENSOR_writeSeqBaddrBdata(fd, sizeof(k_cmd_stop) / sizeof(SensCmd), k_cmd_stop, k_i2c_slave_addr[path_idx]);
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
	p->bayer = MPI_BAYER_PHASE_R;
	p->ext_clk_freq = SENSOR_EXT_CLK_FREQ;
	p->sensor_res.width = SENSOR_WIDTH;
	p->sensor_res.height = SENSOR_HEIGHT;
	p->sensor_fps = FPS;
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
