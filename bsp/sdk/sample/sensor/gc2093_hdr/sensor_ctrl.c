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

//#define FPS (30.0)

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

// 1920x1080 30fps HDR 2lane
static const SensCmd k_cmd_format_1080p_30fps[] = {
	{ 0x03fe, 0xf0 }, { 0x03fe, 0xf0 }, { 0x03fe, 0xf0 }, { 0x03fe, 0x00 }, { 0x03f2, 0x00 }, { 0x03f3, 0x00 },
	{ 0x03f4, 0x36 }, { 0x03f5, 0xc0 }, { 0x03f6, 0x0B }, { 0x03f7, 0x01 }, { 0x03f8, 0x63 }, { 0x03f9, 0x40 },
	{ 0x03fc, 0x8e }, { 0x0087, 0x18 }, { 0x00ee, 0x30 }, { 0x00d0, 0xbf }, { 0x01a0, 0x00 }, { 0x01a4, 0x40 },
	{ 0x01a5, 0x40 }, { 0x01a6, 0x40 }, { 0x01af, 0x09 }, { 0x0001, 0x00 }, { 0x0002, 0x18 }, { 0x0003, 0x00 },
	{ 0x0004, 0xc0 }, { 0x0005, 0x02 }, { 0x0006, 0x94 }, { 0x0007, 0x00 }, { 0x0008, 0x11 }, { 0x0009, 0x00 },
	{ 0x000a, 0x02 }, { 0x000b, 0x00 }, { 0x000c, 0x04 }, { 0x000d, 0x04 }, { 0x000e, 0x40 }, { 0x000f, 0x07 },
	{ 0x0010, 0x8c }, { 0x0013, 0x15 }, { 0x0019, 0x0c }, { 0x0041, 0x04 }, { 0x0042, 0xE2 }, { 0x0053, 0x60 },
	{ 0x008d, 0x92 }, { 0x0090, 0x00 }, { 0x00c7, 0xe1 }, { 0x001b, 0x73 }, { 0x0028, 0x0d }, { 0x0029, 0x24 },
	{ 0x002b, 0x04 }, { 0x002e, 0x23 }, { 0x0037, 0x03 }, { 0x0043, 0x04 }, { 0x0044, 0x28 }, { 0x004a, 0x01 },
	{ 0x004b, 0x20 }, { 0x0055, 0x28 }, { 0x0066, 0x3f }, { 0x0068, 0x3f }, { 0x006b, 0x44 }, { 0x0077, 0x00 },
	{ 0x0078, 0x20 }, { 0x007c, 0xa1 }, { 0x00ce, 0x7c }, { 0x00d3, 0xd4 }, { 0x00e6, 0x50 }, { 0x00b0, 0x68 },
	{ 0x00b6, 0xc0 }, { 0x00b1, 0x01 }, { 0x00b2, 0x00 }, { 0x00b3, 0x00 }, { 0x00b8, 0x01 }, { 0x00b9, 0x00 },
	{ 0x0155, 0x08 }, { 0x00c2, 0x10 }, { 0x00cf, 0x08 }, { 0x00d9, 0x0a }, { 0x0101, 0x0c }, { 0x0102, 0x89 },
	{ 0x0104, 0x01 }, { 0x010e, 0x01 }, { 0x010f, 0x00 }, { 0x0158, 0x00 }, { 0x0123, 0x08 }, { 0x0123, 0x00 },
	{ 0x0120, 0x01 }, { 0x0121, 0x04 }, { 0x0122, 0xd8 }, { 0x0124, 0x03 }, { 0x0125, 0xff }, { 0x001a, 0x8c },
	{ 0x00c6, 0xe0 }, { 0x0026, 0x30 }, { 0x0142, 0x00 }, { 0x0149, 0x1e }, { 0x014a, 0x0f }, { 0x014b, 0x00 },
	{ 0x0414, 0x78 }, { 0x0415, 0x78 }, { 0x0416, 0x78 }, { 0x0417, 0x78 }, { 0x0454, 0x78 }, { 0x0455, 0x78 },
	{ 0x0456, 0x78 }, { 0x0457, 0x78 }, { 0x04e0, 0x18 }, { 0x0017, 0x00 }, { 0x0192, 0x02 }, { 0x0194, 0x03 },
	{ 0x0195, 0x04 }, { 0x0196, 0x38 }, { 0x0197, 0x07 }, { 0x0198, 0x80 }, { 0x019a, 0x06 }, { 0x007b, 0x2a },
	{ 0x0023, 0x2d }, { 0x0201, 0x27 }, { 0x0202, 0x56 }, { 0x0203, 0xb6 }, { 0x0212, 0x80 }, { 0x0213, 0x07 },
	{ 0x0215, 0x10 }, { 0x003e, 0x91 }, { 0x0027, 0x71 }, { 0x0215, 0x10 }, { 0x024d, 0x00 }, { 0x001a, 0x9c },
	{ 0x005a, 0x00 }, { 0x005b, 0x7c }, { 0x0183, 0x01 }, { 0x0187, 0x50 }, { 0x0032, 0xfd },
};

static const SensCmd k_cmd_start[] = {
	{ 0x003e, 0x91 },
};

static const SensCmd k_cmd_stop[] = {
	{ 0x003e, 0x00 },
};

static void SENSOR_configInitSeq(uint8_t path_idx)
{
	int fd = g_i2c_fd[path_idx];

	SENSOR_writeSeq(fd, sizeof(k_cmd_format_1080p_30fps) / sizeof(SensCmd), k_cmd_format_1080p_30fps,
	                k_i2c_slave_addr[path_idx]);

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
	float sensor_fps = SENSOR_FPS;
	int16_t frame_len_line = SENSOR_HEIGHT;

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
	p->sensor_res.height = HDR_HEIGHT;
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
	p->mipi.t_hs_settle = 0xA;
	p->mipi.t_hs_settle_ns = T_HS_SETTLE_NS;
	p->mipi.t_d_term_en_ns = T_D_TERM_EN_NS;
	p->mipi.t_clk_settle_ns = T_CLK_SETTLE_NS;
	p->mipi.t_clk_term_en_ns = T_CLK_TERM_EN_NS;

	p->hdr.vc_enable = 0;
	p->hdr.hdr_mode = HDR_MODE;
	p->hdr.image_num = HDR_IMAGE_NUM;
	p->hdr.blank_line_num[0] = HDR_BLANK_LINE;

	return MPI_SUCCESS;
}
