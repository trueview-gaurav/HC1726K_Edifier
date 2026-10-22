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

// 1920x1080 30fps 12bit 2lane
static const SensCmd k_cmd_format_1920x1080_30fps_12bit[] = {
	{ 0x3009, 0x12 }, // FRSEL [1:0]
	{ 0x3011, 0x02 }, //
	{ 0x301C, 0x30 }, // HMAX [15:0]
	{ 0x301D, 0x11 }, //
	{ 0x3020, 0x0A }, // SHS1 [19:0]
	{ 0x3046, 0x01 }, // ODBIT[1:0]
	{ 0x305C, 0x18 }, // INCKSEL1
	{ 0x305D, 0x03 }, // INCKSEL2
	{ 0x305E, 0x20 }, // INCKSEL3
	{ 0x309E, 0x4A }, // -
	{ 0x309F, 0x4A }, // -
	{ 0x30D2, 0x19 }, // -
	{ 0x30D7, 0x03 }, // -
	{ 0x313B, 0x61 }, // -
	{ 0x315E, 0x1A }, // INCKSEL5
	{ 0x3164, 0x1A }, // INCKSEL6
	{ 0x317C, 0x00 }, // ADBIT2
	{ 0x3404, 0x01 }, // Non-continuous clock at V blanking
	{ 0x3405, 0x10 }, // -
	{ 0x3407, 0x01 }, // PHYSICAL_LANE_NUM [1:0]
	{ 0x3443, 0x01 }, // CSI_LANE_MODE [1:0]
	{ 0x3444, 0x20 }, // EXTCK_FREQ[15:0]
	{ 0x3445, 0x25 }, //
	{ 0x3446, 0x57 }, // TCLKPOST[8:0]
	{ 0x3448, 0x37 }, // THSZERO[8:0]
	{ 0x344A, 0x1F }, // THSPREPARE[8:0]
	{ 0x344C, 0x1F }, // TCLKTRAIL[8:0]
	{ 0x344E, 0x1F }, // THSTRAIL[8:0]
	{ 0x3450, 0x77 }, // TCLKZERO[8:0]
	{ 0x3452, 0x1F }, // TCLKPREPARE [8:0]
	{ 0x3454, 0x17 }, // TLPX[8:0]
	{ 0x3480, 0x49 }, // INCKSEL7
};

static const SensCmd k_cmd_start[] = {
	{ 0x3000, 0x00 }, // operating mode
	{ SENSOR_DELAY_REG, 0x14 }, // delay 20ms
	{ 0x3002, 0x00 }, // master mode start
};

static const SensCmd k_cmd_stop[] = {
	{ 0x3000, 0x01 }, //standby mode
	// { 0x3002, 0x01 }, //master mode stop  /* Comment out this line does NOT match datasheet */
};

static void SENSOR_configInitSeq(uint8_t path_idx)
{
	int fd = g_i2c_fd[path_idx];
	// int width = SENSOR_WIDTH;
	// int height = SENSOR_HEIGHT;
	// int fps = SENSOR_FPS; // should check if this should be int or float

#if SET_1920_1080_30fps_2lane
	SENSOR_writeSeq(fd, sizeof(k_cmd_format_1920x1080_30fps_12bit) / sizeof(SensCmd),
	                k_cmd_format_1920x1080_30fps_12bit, k_i2c_slave_addr[path_idx]);
#endif

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
	p->bit_width = BIT_DEPTH;
	p->intf_ptcl = MPI_INTF_PTCL_MIPI;
	p->ptcl_mode = MPI_MIPI_CSI2;
	p->hsync_plty = MPI_PLTY_HIGH;
	p->vsync_plty = MPI_PLTY_HIGH;
	p->bayer = MPI_BAYER_PHASE_R;
	p->ext_clk_freq = SENSOR_EXT_CLK_FREQ;
	p->sensor_res.width = 1948; //1920 + 12 +16
	p->sensor_res.height = 1097; //1080 + 8 + 9
	p->sensor_fps = sensor_fps;
	p->frame_len_line = frame_len_line;
	p->i2c_slv_addr = k_i2c_slave_addr[path_idx];
	p->ob_enable = 0;
	p->reserved = 0;

	memcpy(&p->parl_lane, &k_parl_lane[path_idx], sizeof(MPI_PARL_LANE_INFO_S));
	memcpy(&p->serl_lane[0], &k_serl_lane[path_idx], MPI_MAX_LVDSRX_LANE_NUM * sizeof(MPI_SERL_LANE_INFO_S));
	SENSOR_getLvdsDelay(sns_idx, p->serl_lane);

	p->mipi.bp_img.hor = 12;
	p->mipi.bp_img.ver = 8;
	p->mipi.fp_img.hor = 16;
	p->mipi.fp_img.ver = 9;

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
