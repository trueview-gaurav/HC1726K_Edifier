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
	-1, -1,
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

// 1920x1080 30fps_2lane
static const SensCmd k_cmd_format_1080p_30fps[] = {
	{ 0x0103, 0x01           },
	{ SENSOR_DELAY_REG, 0x0A }, //delay 10ms
	{ 0x0100, 0x00           },
	{ 0x36e9, 0x80           },
	{ 0x36f9, 0x80           },
	{ 0x301c, 0x78           },
	{ 0x3205, 0x8b           },
	{ 0x3207, 0x43           },
	{ 0x3208, 0x07           },
	{ 0x3209, 0x80           },
	{ 0x320a, 0x04           },
	{ 0x320b, 0x38           },
	{ 0x320e, 0x04           },
	{ 0x320f, 0x65           },
	{ 0x3211, 0x06           },
	{ 0x3213, 0x06           },
	{ 0x3214, 0x11           },
	{ 0x3215, 0x11           },
	{ 0x3253, 0x0c           },
	{ 0x3274, 0x09           },
	{ 0x3301, 0x05           },
	{ 0x3304, 0x68           },
	{ 0x3306, 0x40           },
	{ 0x330b, 0xc6           },
	{ 0x331c, 0x01           },
	{ 0x331e, 0x61           },
	{ 0x3333, 0x10           },
	{ 0x3364, 0x17           },
	{ 0x3391, 0x18           },
	{ 0x3392, 0x38           },
	{ 0x3393, 0x08           },
	{ 0x3394, 0x0b           },
	{ 0x3395, 0x50           },
	{ 0x3620, 0x88           },
	{ 0x3622, 0x06           },
	{ 0x3630, 0xf8           },
	{ 0x3634, 0x44           },
	{ 0x3637, 0x16           },
	{ 0x363a, 0x1f           },
	{ 0x3670, 0x1c           },
	{ 0x3677, 0x84           },
	{ 0x3678, 0x86           },
	{ 0x3679, 0x8b           },
	{ 0x367e, 0x18           },
	{ 0x367f, 0x38           },
	{ 0x3690, 0x53           },
	{ 0x3691, 0x63           },
	{ 0x3692, 0x63           },
	{ 0x369c, 0x08           },
	{ 0x369d, 0x38           },
	{ 0x36a4, 0x08           },
	{ 0x36a5, 0x18           },
	{ 0x36a8, 0x08           },
	{ 0x36a9, 0x28           },
	{ 0x36aa, 0x2a           },
	{ 0x36ea, 0x1f           },
	{ 0x36fc, 0x11           },
	{ 0x36fd, 0x34           },
	{ 0x3e01, 0x8c           },
	{ 0x3e03, 0x0b           },
	{ 0x3e08, 0x03           },
	{ 0x3e09, 0x20           },
	{ 0x3e1b, 0x15           },
	{ 0x3f03, 0x06           },
	{ 0x36e9, 0x59           },
	{ 0x36f9, 0x21           },
	//{ 0x0100, 0x01           },
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

	SENSOR_writeSeqWaddrBdata(fd, sizeof(k_cmd_format_1080p_30fps) / sizeof(SensCmd),
	                          k_cmd_format_1080p_30fps, k_i2c_slave_addr[path_idx]);

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

	SENSOR_writeSeqWaddrBdata(fd, sizeof(k_cmd_start) / sizeof(SensCmd),
	                          k_cmd_start, k_i2c_slave_addr[path_idx]);
}

static void SENSOR_configExitSeq(uint8_t path_idx)
{
	int fd = g_i2c_fd[path_idx];

	SENSOR_writeSeqWaddrBdata(fd, sizeof(k_cmd_stop) / sizeof(SensCmd),
				  k_cmd_stop, k_i2c_slave_addr[path_idx]);
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
	p->bayer = MPI_BAYER_PHASE_B;
	p->ext_clk_freq = SENSOR_EXT_CLK_FREQ;
	p->sensor_res.width = SENSOR_WIDTH;
	p->sensor_res.height = SENSOR_HEIGHT;
	p->sensor_fps = SENSOR_FPS;
	p->frame_len_line = 1125;
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
	p->mipi.t_hs_settle = 34;
	p->mipi.t_hs_settle_ns = T_HS_SETTLE_NS;
	p->mipi.t_d_term_en_ns = T_D_TERM_EN_NS;
	p->mipi.t_clk_settle_ns = T_CLK_SETTLE_NS;
	p->mipi.t_clk_term_en_ns = T_CLK_TERM_EN_NS;

	return MPI_SUCCESS;
}
