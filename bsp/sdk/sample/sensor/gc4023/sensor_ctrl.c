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

// 2560x1440 30fps_2lane
static const SensCmd k_cmd_format_1440p_30fps[] = {
	{ 0x03fe, 0xf0 }, { 0x03fe, 0x00 },         { 0x03fe, 0x10 }, { 0x03fe, 0x00 }, { 0x0a38, 0x00 },
	{ 0x0a38, 0x01 }, { 0x0a20, 0x17 },         { 0x061c, 0x50 }, { 0x061d, 0x21 }, { 0x061e, 0x6c },
	{ 0x061f, 0x06 }, { 0x0a21, 0x10 },         { 0x0a34, 0x40 }, { 0x0a35, 0x01 }, { 0x0a36, 0x58 },
	{ 0x0a37, 0x06 }, { 0x0314, 0x50 },         { 0x0315, 0x00 }, { 0x031c, 0xce }, { 0x0219, 0x47 },
	{ 0x0342, 0x04 }, { 0x0343, 0xb0 },         { 0x0259, 0x05 }, { 0x025a, 0xa0 }, { 0x0340, 0x05 },
	{ 0x0341, 0xdc }, { 0x0347, 0x02 },         { 0x0348, 0x0a }, { 0x0349, 0x08 }, { 0x034a, 0x05 },
	{ 0x034b, 0xa8 }, { 0x0094, 0x0a },         { 0x0095, 0x00 }, { 0x0096, 0x05 }, { 0x0097, 0xa0 },
	{ 0x0099, 0x04 }, { 0x009b, 0x04 },         { 0x0709, 0x40 }, { 0x0719, 0x40 }, { 0x060c, 0x01 },
	{ 0x060e, 0x08 }, { 0x060f, 0x05 },         { 0x070c, 0x01 }, { 0x070e, 0x08 }, { 0x070f, 0x05 },
	{ 0x0909, 0x03 }, { 0x0902, 0x04 },         { 0x0904, 0x0b }, { 0x0907, 0x54 }, { 0x0908, 0x06 },
	{ 0x0903, 0x9d }, { 0x072a, 0x18 },         { 0x0724, 0x0a }, { 0x0727, 0x0a }, { 0x072a, 0x1c },
	{ 0x072b, 0x0a }, { 0x1466, 0x10 },         { 0x1468, 0x18 }, { 0x1467, 0x18 }, { 0x1469, 0x80 },
	{ 0x146a, 0xe8 }, { 0x0707, 0x07 },         { 0x0737, 0x0f }, { 0x0704, 0x01 }, { 0x0706, 0x02 },
	{ 0x0716, 0x02 }, { 0x0708, 0xc8 },         { 0x0718, 0xc8 }, { 0x061a, 0x00 }, { 0x1430, 0x80 },
	{ 0x1407, 0x10 }, { 0x1408, 0x16 },         { 0x1409, 0x03 }, { 0x146d, 0x0e }, { 0x146e, 0x42 },
	{ 0x146f, 0x43 }, { 0x1470, 0x3c },         { 0x1471, 0x3d }, { 0x1472, 0x3a }, { 0x1473, 0x3a },
	{ 0x1474, 0x40 }, { 0x1475, 0x46 },         { 0x1420, 0x14 }, { 0x1464, 0x15 }, { 0x146c, 0x40 },
	{ 0x146d, 0x40 }, { 0x1423, 0x08 },         { 0x1428, 0x10 }, { 0x1462, 0x18 }, { 0x02ce, 0x04 },
	{ 0x143a, 0x0f }, { 0x142b, 0x88 },         { 0x0245, 0xc9 }, { 0x023a, 0x08 }, { 0x02cd, 0x92 },
	{ 0x0612, 0x02 }, { 0x0613, 0xc7 },         { 0x0243, 0x03 }, { 0x021b, 0x09 }, { 0x0089, 0x03 },
	{ 0x0040, 0xa3 }, { 0x0075, 0x64 },         { 0x0004, 0x0f }, { 0x0002, 0xab }, { 0x0053, 0x0a },
	{ 0x0205, 0x0c }, { 0x0202, 0x06 },         { 0x0203, 0x27 }, { 0x0614, 0x00 }, { 0x0615, 0x00 },
	{ 0x0181, 0x0c }, { 0x0182, 0x05 },         { 0x0185, 0x01 }, { 0x0180, 0x46 }, { 0x0100, 0x08 },
	{ 0x0106, 0x38 }, { 0x010d, 0x80 },         { 0x010e, 0x0c }, { 0x0113, 0x02 }, { 0x0114, 0x01 },
	{ 0x0115, 0x10 }, { 0x0100, 0x09 },         { 0x0052, 0x02 }, { 0x0076, 0x01 }, { 0x021a, 0x10 },
	{ 0x0434, 0x75 }, { 0x0435, 0x75 },         { 0x0436, 0x75 }, { 0x0437, 0x75 }, { 0x0430, 0x0a },
	{ 0x0431, 0x0a }, { 0x0432, 0x0a },         { 0x0433, 0x0a }, { 0x0458, 0x00 }, { 0x0459, 0x00 },
	{ 0x045a, 0x00 }, { 0x045b, 0x00 },         { 0x0a67, 0x80 }, { 0x0a54, 0x0e }, { 0x0a65, 0x10 },
	{ 0x0a98, 0x10 }, { 0x05be, 0x00 },         { 0x05a9, 0x01 }, { 0x0029, 0x08 }, { 0x002b, 0xa8 },
	{ 0x0a83, 0xe0 }, { 0x0a72, 0x02 },         { 0x0a73, 0x60 }, { 0x0a75, 0x41 }, { 0x0a70, 0x03 },
	{ 0x0a5a, 0x80 }, { SENSOR_DELAY_REG, 20 }, { 0x05be, 0x01 }, { 0x0a70, 0x00 }, { 0x0080, 0x02 },
	{ 0x0a67, 0x00 },
};

static const SensCmd k_cmd_start[] = {
	{ 0x0100, 0x09 },
};

static const SensCmd k_cmd_stop[] = {
	{ 0x0100, 0x00 },
};

static void SENSOR_configInitSeq(uint8_t path_idx)
{
	int fd = g_i2c_fd[path_idx];

	SENSOR_writeSeq(fd, sizeof(k_cmd_format_1440p_30fps) / sizeof(SensCmd), k_cmd_format_1440p_30fps,
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
	p->mipi.t_hs_settle = 0xA;
	p->mipi.t_hs_settle_ns = T_HS_SETTLE_NS;
	p->mipi.t_d_term_en_ns = T_D_TERM_EN_NS;
	p->mipi.t_clk_settle_ns = T_CLK_SETTLE_NS;
	p->mipi.t_clk_term_en_ns = T_CLK_TERM_EN_NS;

	return MPI_SUCCESS;
}
