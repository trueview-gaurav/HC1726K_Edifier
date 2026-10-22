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
	{ 0x03fe, 0xf0 },
	{ 0x03fe, 0x00 },
	{ 0x0317, 0x00 },
	{ 0x0320, 0x77 },
	{ 0x0324, 0xc8 },
	{ 0x0325, 0x06 },
	{ 0x0326, 0x6c },
	{ 0x0327, 0x03 },
	{ 0x0334, 0x40 },
	{ 0x0336, 0x6c },
	{ 0x0337, 0x82 },
	{ 0x0315, 0x25 },
	{ 0x031c, 0xc6 },
	{ 0x0287, 0x18 },
	{ 0x0084, 0x00 },
	{ 0x0087, 0x50 },
	{ 0x029d, 0x08 },
	{ 0x0290, 0x00 },
	{ 0x0340, 0x05 },
	{ 0x0341, 0xdc },
	{ 0x0345, 0x06 },
	{ 0x034b, 0xb0 },
	{ 0x0352, 0x08 },
	{ 0x0354, 0x08 },
	{ 0x02d1, 0xe0 },
	{ 0x0223, 0xf2 },
	{ 0x0238, 0xa4 },
	{ 0x02ce, 0x7f },
	{ 0x0232, 0xc4 },
	{ 0x02d3, 0x05 },
	{ 0x0243, 0x06 },
	{ 0x02ee, 0x30 },
	{ 0x026f, 0x70 },
	{ 0x0257, 0x09 },
	{ 0x0211, 0x02 },
	{ 0x0219, 0x09 },
	{ 0x023f, 0x2d },
	{ 0x0518, 0x00 },
	{ 0x0519, 0x01 },
	{ 0x0515, 0x08 },
	{ 0x02d9, 0x3f },
	{ 0x02da, 0x02 },
	{ 0x02db, 0xe8 },
	{ 0x02e6, 0x20 },
	{ 0x021b, 0x10 },
	{ 0x0252, 0x22 },
	{ 0x024e, 0x22 },
	{ 0x02c4, 0x01 },
	{ 0x021d, 0x17 },
	{ 0x024a, 0x01 },
	{ 0x02ca, 0x02 },
	{ 0x0262, 0x10 },
	{ 0x029a, 0x20 },
	{ 0x021c, 0x0e },
	{ 0x0298, 0x03 },
	{ 0x029c, 0x00 },
	{ 0x027e, 0x14 },
	{ 0x02c2, 0x10 },
	{ 0x0540, 0x20 },
	{ 0x0546, 0x01 },
	{ 0x0548, 0x01 },
	{ 0x0544, 0x01 },
	{ 0x0242, 0x1b },
	{ 0x02c0, 0x1b },
	{ 0x02c3, 0x20 },
	{ 0x02e4, 0x10 },
	{ 0x022e, 0x00 },
	{ 0x027b, 0x3f },
	{ 0x0269, 0x0f },
	{ 0x02d2, 0x40 },
	{ 0x027c, 0x08 },
	{ 0x023a, 0x2e },
	{ 0x0245, 0xce },
	{ 0x0530, 0x20 },
	{ 0x0531, 0x02 },
	{ 0x0228, 0x50 },
	{ 0x02ab, 0x00 },
	{ 0x0250, 0x00 },
	{ 0x0221, 0x50 },
	{ 0x02ac, 0x00 },
	{ 0x02a5, 0x02 },
	{ 0x0260, 0x0b },
	{ 0x0216, 0x04 },
	{ 0x0299, 0x1C },
	{ 0x02bb, 0x0d },
	{ 0x02a3, 0x02 },
	{ 0x02a4, 0x02 },
	{ 0x021e, 0x02 },
	{ 0x024f, 0x08 },
	{ 0x028c, 0x08 },
	{ 0x0532, 0x3f },
	{ 0x0533, 0x02 },
	{ 0x0277, 0xc0 },
	{ 0x0276, 0xc0 },
	{ 0x0239, 0xc0 },
	{ 0x0202, 0x05 },
	{ 0x0203, 0xd0 },
	{ 0x0205, 0xc0 },
	{ 0x02b0, 0x68 },
	{ 0x0002, 0xa9 },
	{ 0x0004, 0x01 },

	{ 0x021a, 0x98 },
	{ 0x0266, 0xa0 },
	{ 0x0020, 0x01 },
	{ 0x0021, 0x03 },
	{ 0x0022, 0x00 },
	{ 0x0023, 0x04 },

	{ 0x0342, 0x06 },
	{ 0x0343, 0x40 },
	{ 0x03fe, 0x10 },
	{ 0x03fe, 0x00 },
	{ 0x0106, 0x78 },
	{ 0x0108, 0x0c },
	{ 0x0114, 0x01 },
	{ 0x0115, 0x10 },
	{ 0x0180, 0x46 },
	{ 0x0181, 0x30 },
	{ 0x0182, 0x05 },
	{ 0x0185, 0x01 },
	{ 0x03fe, 0x10 },
	{ 0x03fe, 0x00 },
	{ 0x000f, 0x00 },
	{ 0x0100, 0x09 }, //stream on
	//otp
	{ 0x0080, 0x02 },
	{ 0x0097, 0x0a },
	{ 0x0098, 0x10 },
	{ 0x0099, 0x05 },
	{ 0x009a, 0xb0 },
	{ 0x0317, 0x08 },
	{ 0x0a67, 0x80 },
	{ 0x0a70, 0x03 },
	{ 0x0a82, 0x00 },
	{ 0x0a83, 0x10 },
	{ 0x0a80, 0x2b },
	{ 0x05be, 0x00 },
	{ 0x05a9, 0x01 },
	{ 0x0313, 0x80 },
	{ 0x05be, 0x01 },
	{ 0x0317, 0x00 },
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
	p->bayer = MPI_BAYER_PHASE_G0;	// Sensor Datasheet spec 6.2 Pixel readout
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
