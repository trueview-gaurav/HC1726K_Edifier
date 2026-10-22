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

// 2304x1296 30fps_2lane
static const SensCmd k_cmd_format_2304x1536_30fps[] = {
	{ 0x03fe, 0xf0 },
	{ 0x03fe, 0xf0 },
	{ 0x03fe, 0xf0 },
	{ 0x03fe, 0x00 },
	{ 0x03f3, 0x00 },
	{ 0x03f5, 0xc0 },
	{ 0x03f6, 0x06 },
	{ 0x03f7, 0x01 },
	{ 0x03f8, 0x4f },
	{ 0x03f9, 0x13 },
	{ 0x03fa, 0x00 },
	{ 0x03e0, 0x16 },
	{ 0x03e1, 0x0d },
	{ 0x03e2, 0x36 },
	{ 0x03e4, 0x08 },
	{ 0x03fc, 0xce },
	{ 0x0d05, 0x05 },
	{ 0x0d06, 0x40 },
	{ 0x0d76, 0x00 },
	{ 0x0d41, 0x05 },
	{ 0x0d42, 0x3c },
	{ 0x0d0a, 0x02 },
	{ 0x000c, 0x02 },
	{ 0x0d0d, 0x05 },
	{ 0x0d0e, 0x18 },
	{ 0x000f, 0x09 },
	{ 0x0010, 0x08 },
	{ 0x0017, 0x0c },
	{ 0x0d53, 0x12 },
	{ 0x0051, 0x03 },
	{ 0x0082, 0x01 },
	{ 0x0086, 0x20 },
	{ 0x008a, 0x01 },
	{ 0x008b, 0x1d },
	{ 0x008c, 0x05 },
	{ 0x008d, 0xd0 },
	{ 0x0db7, 0x01 },
	{ 0x0db0, 0x05 },
	{ 0x0db1, 0x00 },
	{ 0x0db2, 0x04 },
	{ 0x0db3, 0x54 },
	{ 0x0db4, 0x00 },
	{ 0x0db5, 0x17 },
	{ 0x0db6, 0x08 },
	{ 0x0d25, 0xcb },
	{ 0x0d4a, 0x04 },
	{ 0x00d2, 0x70 },
	{ 0x00d7, 0x19 },
	{ 0x00d9, 0x10 },
	{ 0x00da, 0xc1 },
	{ 0x0d55, 0x1b },
	{ 0x0d92, 0x17 },
	{ 0x0dc2, 0x30 },
	{ 0x0d2a, 0x30 },
	{ 0x0d19, 0x51 },
	{ 0x0d29, 0x30 },
	{ 0x0d20, 0x30 },
	{ 0x0d72, 0x12 },
	{ 0x0d4e, 0x12 },
	{ 0x0d43, 0x20 },
	{ 0x0050, 0x0c },
	{ 0x006e, 0x03 },
	{ 0x0153, 0x50 },
	{ 0x0192, 0x04 },
	{ 0x0194, 0x04 },
	{ 0x0195, 0x05 },
	{ 0x0196, 0x10 },
	{ 0x0197, 0x09 },
	{ 0x0198, 0x00 },
	{ 0x0077, 0x01 },
	{ 0x0078, 0x65 },
	{ 0x0079, 0x04 },
	{ 0x0067, 0xc0 },
	{ 0x0054, 0xff },
	{ 0x0055, 0x02 },
	{ 0x0056, 0x00 },
	{ 0x0057, 0x04 },
	{ 0x005a, 0xff },
	{ 0x005b, 0x07 },
	{ 0x00d5, 0x03 },
	{ 0x0102, 0x10 },
	{ 0x0d4a, 0x04 },
	{ 0x04e0, 0xff },
	{ 0x031e, 0x3e },
	{ 0x0159, 0x01 },
	{ 0x014f, 0x28 },
	{ 0x0150, 0x40 },
	{ 0x0026, 0x00 },
	{ 0x0d26, 0xa0 },

	{ 0x0414, 0x74 },
	{ 0x0415, 0x74 },
	{ 0x0416, 0x74 },
	{ 0x0417, 0x74 },

	{ 0x0155, 0x00 },
	{ 0x0170, 0x3e },
	{ 0x0171, 0x3e },
	{ 0x0172, 0x3e },
	{ 0x0173, 0x3e },
	{ 0x0428, 0x0b },
	{ 0x0429, 0x0b },
	{ 0x042a, 0x0b },
	{ 0x042b, 0x0b },
	{ 0x042c, 0x0b },
	{ 0x042d, 0x0b },
	{ 0x042e, 0x0b },
	{ 0x042f, 0x0b }, //b_use
	{ 0x0430, 0x05 },
	{ 0x0431, 0x05 },
	{ 0x0432, 0x05 },
	{ 0x0433, 0x05 },
	{ 0x0434, 0x04 },
	{ 0x0435, 0x04 },
	{ 0x0436, 0x04 },
	{ 0x0437, 0x04 }, //a_use
	{ 0x0438, 0x18 },
	{ 0x0439, 0x18 },
	{ 0x043a, 0x18 },
	{ 0x043b, 0x18 },
	{ 0x043c, 0x1d },
	{ 0x043d, 0x20 },
	{ 0x043e, 0x22 },
	{ 0x043f, 0x24 }, //d_use
	{ 0x0468, 0x04 },
	{ 0x0469, 0x04 },
	{ 0x046a, 0x04 },
	{ 0x046b, 0x04 },
	{ 0x046c, 0x04 },
	{ 0x046d, 0x04 },
	{ 0x046e, 0x04 },
	{ 0x046f, 0x04 }, //c_use
	{ 0x0108, 0xf0 },
	{ 0x0109, 0x80 },
	{ 0x0d03, 0x05 },
	{ 0x0d04, 0x00 },
	{ 0x007a, 0x60 },
	{ 0x00d0, 0x00 },
	{ 0x0080, 0x09 },
	{ 0x0291, 0x0f },
	{ 0x0292, 0xff },
	{ 0x0201, 0x27 },
	{ 0x0202, 0x53 },
	{ 0x0203, 0x4e },
	{ 0x0206, 0x03 },
	{ 0x0212, 0x0b },
	{ 0x0213, 0x40 },
	{ 0x0215, 0x12 },
	{ 0x023e, 0x99 },
	{ 0x03fe, 0x10 },
	{ 0x0183, 0x09 },
	{ 0x0187, 0x51 },
	{ 0x0d22, 0x04 },
	{ 0x0d21, 0x3C },
	{ 0x0d03, 0x01 },
	{ 0x0d04, 0x28 },
	{ 0x0d23, 0x0e },
	//{ 0x03fe, 0x00 },
};

static const SensCmd k_cmd_start[] = {
	{ 0x03fe, 0x00 },
};

static const SensCmd k_cmd_stop[] = {
	{ 0x03fe, 0x10 },
};

static void SENSOR_configInitSeq(uint8_t path_idx)
{
	int fd = g_i2c_fd[path_idx];

	SENSOR_writeSeqWaddrBdata(fd, sizeof(k_cmd_format_2304x1536_30fps) / sizeof(SensCmd),
	                          k_cmd_format_2304x1536_30fps, k_i2c_slave_addr[path_idx]);

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
	p->bayer = MPI_BAYER_PHASE_R;
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
