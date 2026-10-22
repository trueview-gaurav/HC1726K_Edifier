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
static const uint16_t k_i2c_slave_addr[2] = {
	SENSOR_I2C_SLAVE_ADDR,
	SENSOR_I2C_SLAVE_ADDR1,
};
int g_i2c_fd[2] = {
	-1,
	-1,
};
#else
static const uint16_t k_i2c_slave_addr[1] = {
	SENSOR_I2C_SLAVE_ADDR,
};
int g_i2c_fd[1] = {
	-1,
};
#endif

// 2960x1440 30fps 2lane
static const SensCmd k_cmd_format_2960x1664_30fps[] = {
	{ 0x12 , 0x40 },{ 0x48 , 0xA2 },{ 0x48 , 0x22 },{ 0x0E , 0x11 },{ 0x0F , 0x0C },{ 0x10 , 0x48 },
	{ 0x11 , 0x80 },{ 0x46 , 0x18 },{ 0x0D , 0xA0 },{ 0x57 , 0x60 },{ 0x58 , 0x18 },{ 0x5F , 0x41 },
	{ 0x60 , 0x28 },{ 0x20 , 0x20 },{ 0x21 , 0x03 },{ 0x22 , 0x08 },{ 0x23 , 0x07 },{ 0x24 , 0xE4 },
	{ 0x25 , 0x80 },{ 0x26 , 0x62 },{ 0x27 , 0xAE },{ 0x28 , 0x19 },{ 0x29 , 0x02 },{ 0x2A , 0xA0 },
	{ 0x2B , 0x12 },{ 0x2C , 0x00 },{ 0x2D , 0x00 },{ 0x2E , 0xA8 },{ 0x2F , 0x44 },{ 0x41 , 0xE8 },
	{ 0x42 , 0x02 },{ 0x47 , 0x42 },{ 0x80 , 0x01 },{ 0xAF , 0x12 },{ 0xAA , 0x00 },{ 0xBF , 0x01 },
	{ 0x5B , 0x90 },{ 0x5C , 0x0B },{ 0xBF , 0x00 },{ 0x1D , 0x00 },{ 0x1E , 0x04 },{ 0x6C , 0x40 },
	{ 0x9E , 0x10 },{ 0x0C , 0x70 },{ 0x6F , 0x00 },{ 0x75 , 0x13 },{ 0x70 , 0xF9 },{ 0x71 , 0xBB },
	{ 0x72 , 0x6E },{ 0x73 , 0x6A },{ 0x74 , 0x12 },{ 0x78 , 0x80 },{ 0x89 , 0x14 },{ 0x6B , 0x10 },
	{ 0x08 , 0x02 },{ 0xBF , 0x01 },{ 0x54 , 0x01 },{ 0x63 , 0x3F },{ 0x69 , 0xFF },{ 0x67 , 0xB0 },
	{ 0x79 , 0x84 },{ 0x7A , 0x11 },{ 0xBF , 0x00 },{ 0xB6 , 0x00 },{ 0x31 , 0x0C },{ 0x32 , 0x24 },
	{ 0x33 , 0x18 },{ 0x34 , 0x30 },{ 0x35 , 0x38 },{ 0x3A , 0xAF },{ 0x56 , 0x12 },{ 0x59 , 0x38 },
	{ 0x61 , 0x18 },{ 0x64 , 0xE0 },{ 0x85 , 0x20 },{ 0x8D , 0x6F },{ 0x93 , 0x20 },{ 0x94 , 0xE0 },
	{ 0x9B , 0x8F },{ 0xA4 , 0x97 },{ 0xA5 , 0x47 },{ 0xA7 , 0x80 },{ 0xA9 , 0x48 },{ 0xBF , 0x01 },
	{ 0x5D , 0x84 },{ 0x5E , 0x14 },{ 0x5F , 0x41 },{ 0xBF , 0x00 },{ 0x5B , 0xE1 },{ 0x5C , 0x4C },
	{ 0x5D , 0x54 },{ 0x5E , 0x80 },{ 0x65 , 0x32 },{ 0x66 , 0x00 },{ 0x67 , 0x41 },{ 0x68 , 0x00 },
	{ 0x69 , 0x74 },{ 0x6A , 0x27 },{ 0x7A , 0x44 },{ 0x8F , 0x94 },{ 0xB0 , 0x80 },{ 0xBF , 0x01 },
	{ 0x5A , 0x19 },{ 0xBF , 0x00 },{ 0x97 , 0x20 },{ 0x13 , 0x81 },{ 0x96 , 0x84 },{ 0x4A , 0x01 },
	{ 0xBF , 0x01 },{ 0x57 , 0x00 },{ 0x62 , 0x00 },{ 0xBF , 0x00 },{ 0xA1 , 0x0F },{ 0x50 , 0x02 },
	{ 0x49 , 0x40 },{ 0x7E , 0x4C },{ 0x7F , 0x56 },{ 0x8E , 0x40 },{ 0x8C , 0xFF },{ 0xBF , 0x01 },
	{ 0x5E , 0x14 },{ 0x75 , 0x84 },{ 0x76 , 0x32 },{ 0x74 , 0x15 },{ 0xBF , 0x00 },{ 0xBC , 0x11 },
	{ 0x82 , 0x00 },{ 0x19 , 0x20 },{ 0xBF , 0x01 },{ 0x58 , 0x00 },{ 0xBF , 0x00 },{ 0x9F , 0x40 },
	{ 0x12 , 0x00 },{ 0x48 , 0xA2 },{ 0x48 , 0x22 },

};

static const SensCmd k_cmd_start[] = {
	{ 0x12, 0x00 },
};

static const SensCmd k_cmd_stop[] = {
	{ 0x12, 0x60 },
};

static void SENSOR_configInitSeq(uint8_t path_idx)
{
	int fd = g_i2c_fd[path_idx];
	SENSOR_writeSeqBaddrBdata(fd, sizeof(k_cmd_format_2960x1664_30fps) / sizeof(SensCmd),
			k_cmd_format_2960x1664_30fps, k_i2c_slave_addr[path_idx]);

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
	float sensor_fps = SENSOR_FPS;
	int16_t frame_len_line = SENSOR_HEIGHT;
	uint32_t t_hs_settle = 0xA;

	p->sensor_mode = MPI_SNS_MODE_MASTER;
	p->slv_sync_src = MPI_SLV_SYNC_SRC_NONE;
	p->bit_width = MPI_BITS_10;
	p->intf_ptcl = MPI_INTF_PTCL_MIPI;
	p->ptcl_mode = MPI_MIPI_CSI2;
	p->hsync_plty = MPI_PLTY_HIGH;
	p->vsync_plty = MPI_PLTY_HIGH;
	p->bayer = MPI_BAYER_PHASE_G1;
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

	p->mipi.dt_bmp = 0x0;
	p->mipi.vc_bmp = 0x1;
	p->mipi.t_hs_settle = t_hs_settle;
	p->mipi.t_hs_settle_ns = T_HS_SETTLE_NS;
	p->mipi.t_d_term_en_ns = T_D_TERM_EN_NS;
	p->mipi.t_clk_settle_ns = T_CLK_SETTLE_NS;
	p->mipi.t_clk_term_en_ns = T_CLK_TERM_EN_NS;

	return MPI_SUCCESS;
}
