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

/* clang-format off */

// 2592x1944 30fps 10bit 2lane 1188Mbps
static const SensCmd k_cmd_format_2592x1944_30fps_10bit[] = {
	{ 0x300C, 0x3B }, // INCK related
	{ 0x300D, 0x2A }, // INCK related
	{ 0x3018, 0x00 }, // All pixel scan
	{ 0x3030, 0x94 }, // VMAX [ 7: 0]
	{ 0x3031, 0x11 }, // VMAX [15: 8]
	{ 0x3032, 0x00 }, // VMAX [19:16]
	{ 0x3034, 0x26 }, // HMAX [ 7: 0]
	{ 0x3035, 0x02 }, // HMAX [15: 8]
	{ 0x3050, 0x00 }, // AD 10 bit
	{ 0x3056, 0xAC }, // Y_OUT_SIZE [ 7: 0]
	{ 0x3057, 0x07 }, // Y_OUT_SIZE [12: 8]
	{ 0x3058, 0xE1 }, // SHS [ 7: 0]
	{ 0x3059, 0x08 }, // SHS [15: 8]
	{ 0x3060, 0x00 }, // SHS [19:16]
	{ 0x30E8, 0x00 }, // GAIN [ 7: 0]
	{ 0x30E9, 0x00 }, // GAIN [10: 8]
	{ 0x314C, 0xC6 }, // INCK related
	{ 0x314D, 0x00 }, // INCK related
	{ 0x315A, 0x02 }, // INCK related
	{ 0x3168, 0xA0 }, // INCK related
	{ 0x316A, 0x7E }, // INCK related
	{ 0x3199, 0x00 }, // All pixel scan
	{ 0x319D, 0x00 }, // AD 10 bit
	{ 0x319E, 0x01 }, // INCK related
	{ 0x31A1, 0x00 }, // Master mode
	{ 0x3300, 0x00 }, // All pixel scan
	{ 0x3302, 0x32 }, // Black level offset [ 7: 0]
	{ 0x3303, 0x00 }, // Black level offset [ 9: 8]
	{ 0x341C, 0xFF }, // AD 10 bit
	{ 0x341D, 0x01 }, // Ad 10 bit
	{ 0x3A01, 0x01 }, // CSI-2 2 lanes
	// Reserved settings
	{ 0x3288, 0x21 }, { 0x328A, 0x02 }, { 0x3414, 0x05 }, { 0x3416, 0x18 }, { 0x3648, 0x01 }, { 0x364A, 0x04 },
	{ 0x364C, 0x04 }, { 0x3678, 0x01 }, { 0x367C, 0x31 }, { 0x367E, 0x31 }, { 0x3706, 0x10 }, { 0x3708, 0x03 },
	{ 0x3714, 0x02 }, { 0x3715, 0x02 }, { 0x3716, 0x01 }, { 0x3717, 0x03 }, { 0x371C, 0x3D }, { 0x371D, 0x3F },
	{ 0x372C, 0x00 }, { 0x372D, 0x00 }, { 0x372E, 0x46 }, { 0x372F, 0x00 }, { 0x3730, 0x89 }, { 0x3731, 0x00 },
	{ 0x3732, 0x08 }, { 0x3733, 0x01 }, { 0x3734, 0xFE }, { 0x3735, 0x05 }, { 0x3740, 0x02 }, { 0x375D, 0x00 },
	{ 0x375E, 0x00 }, { 0x375F, 0x11 }, { 0x3760, 0x01 }, { 0x3768, 0x1B }, { 0x3769, 0x1B }, { 0x376A, 0x1B },
	{ 0x376B, 0x1B }, { 0x376C, 0x1A }, { 0x376D, 0x17 }, { 0x376E, 0x0F }, { 0x3776, 0x00 }, { 0x3777, 0x00 },
	{ 0x3778, 0x46 }, { 0x3779, 0x00 }, { 0x377A, 0x89 }, { 0x377B, 0x00 }, { 0x377C, 0x08 }, { 0x377D, 0x01 },
	{ 0x377E, 0x23 }, { 0x377F, 0x02 }, { 0x3780, 0xD9 }, { 0x3781, 0x03 }, { 0x3782, 0xF5 }, { 0x3783, 0x06 },
	{ 0x3784, 0xA5 }, { 0x3788, 0x0F }, { 0x378A, 0xD9 }, { 0x378B, 0x03 }, { 0x378C, 0xEB }, { 0x378D, 0x05 },
	{ 0x378E, 0x87 }, { 0x378F, 0x06 }, { 0x3790, 0xF5 }, { 0x3792, 0x43 }, { 0x3794, 0x7A }, { 0x3796, 0xA1 },
	{ 0x37B0, 0x36 },
};

// 2592x1944 30fps 12bit 4lane 1188Mbps
static const SensCmd k_cmd_format_2592x1944_30fps_12bit[] = {
	{ 0x300C, 0x3B }, // INCK related
	{ 0x300D, 0x2A }, // INCK related
	{ 0x3018, 0x00 }, // All pixel scan
	{ 0x3030, 0x94 }, // VMAX [ 7: 0]
	{ 0x3031, 0x11 }, // VMAX [15: 8]
	{ 0x3032, 0x00 }, // VMAX [19:16]
	{ 0x3034, 0x26 }, // HMAX [ 7: 0]
	{ 0x3035, 0x02 }, // HMAX [15: 8]
	{ 0x3050, 0x01 }, // AD 12 bit
	{ 0x3056, 0xAC }, // Y_OUT_SIZE [ 7: 0]
	{ 0x3057, 0x07 }, // Y_OUT_SIZE [12: 8]
	{ 0x3058, 0xE1 }, // SHS [ 7: 0]
	{ 0x3059, 0x08 }, // SHS [15: 8]
	{ 0x3060, 0x00 }, // SHS [19:16]
	{ 0x30E8, 0x00 }, // GAIN [ 7: 0]
	{ 0x30E9, 0x00 }, // GAIN [10: 8]
	{ 0x314C, 0xC6 }, // INCK related
	{ 0x314D, 0x00 }, // INCK related
	{ 0x315A, 0x02 }, // INCK related
	{ 0x3168, 0xA0 }, // INCK related
	{ 0x316A, 0x7E }, // INCK related
	{ 0x3199, 0x00 }, // All pixel scan
	{ 0x319D, 0x01 }, // AD 12 bit
	{ 0x319E, 0x01 }, // INCK related
	{ 0x31A1, 0x00 }, // Master mode
	{ 0x3300, 0x00 }, // All pixel scan
	{ 0x3302, 0x32 }, // Black level offset [ 7: 0]
	{ 0x3303, 0x00 }, // Black level offset [ 9: 8]
	{ 0x341C, 0x47 }, // AD 12 bit
	{ 0x341D, 0x00 }, // Ad 12 bit
	{ 0x3A01, 0x03 }, // CSI-2 4 lanes
	// Reserved settings
	{ 0x3288, 0x21 }, { 0x328A, 0x02 }, { 0x3414, 0x05 }, { 0x3416, 0x18 }, { 0x3648, 0x01 }, { 0x364A, 0x04 },
	{ 0x364C, 0x04 }, { 0x3678, 0x01 }, { 0x367C, 0x31 }, { 0x367E, 0x31 }, { 0x3706, 0x10 }, { 0x3708, 0x03 },
	{ 0x3714, 0x02 }, { 0x3715, 0x02 }, { 0x3716, 0x01 }, { 0x3717, 0x03 }, { 0x371C, 0x3D }, { 0x371D, 0x3F },
	{ 0x372C, 0x00 }, { 0x372D, 0x00 }, { 0x372E, 0x46 }, { 0x372F, 0x00 }, { 0x3730, 0x89 }, { 0x3731, 0x00 },
	{ 0x3732, 0x08 }, { 0x3733, 0x01 }, { 0x3734, 0xFE }, { 0x3735, 0x05 }, { 0x3740, 0x02 }, { 0x375D, 0x00 },
	{ 0x375E, 0x00 }, { 0x375F, 0x11 }, { 0x3760, 0x01 }, { 0x3768, 0x1B }, { 0x3769, 0x1B }, { 0x376A, 0x1B },
	{ 0x376B, 0x1B }, { 0x376C, 0x1A }, { 0x376D, 0x17 }, { 0x376E, 0x0F }, { 0x3776, 0x00 }, { 0x3777, 0x00 },
	{ 0x3778, 0x46 }, { 0x3779, 0x00 }, { 0x377A, 0x89 }, { 0x377B, 0x00 }, { 0x377C, 0x08 }, { 0x377D, 0x01 },
	{ 0x377E, 0x23 }, { 0x377F, 0x02 }, { 0x3780, 0xD9 }, { 0x3781, 0x03 }, { 0x3782, 0xF5 }, { 0x3783, 0x06 },
	{ 0x3784, 0xA5 }, { 0x3788, 0x0F }, { 0x378A, 0xD9 }, { 0x378B, 0x03 }, { 0x378C, 0xEB }, { 0x378D, 0x05 },
	{ 0x378E, 0x87 }, { 0x378F, 0x06 }, { 0x3790, 0xF5 }, { 0x3792, 0x43 }, { 0x3794, 0x7A }, { 0x3796, 0xA1 },
	{ 0x37B0, 0x36 },
};

/* clang-format on */

static const SensCmd k_cmd_start[] = {
	{ 0x3000, 0x00 },
	{ SENSOR_DELAY_REG, 18 }, // regulator stablization
	{ 0x3002, 0x00 },
};

static const SensCmd k_cmd_stop[] = {
	{ 0x3000, 0x01 },
	{ 0x3002, 0x01 },
	{ 0x3004, 0x04 },
	{ SENSOR_DELAY_REG, 10 }, // datasheet doesn't mentioned the time needed
	{ 0x3004, 0x00 },
};

static void SENSOR_configInitSeq(uint8_t path_idx)
{
	int fd = g_i2c_fd[path_idx];
	// int width = SENSOR_WIDTH;
	// int height = SENSOR_HEIGHT;
	// int fps = SENSOR_FPS; // should check if this should be int or float

#ifdef SET_2592_1944_30fps_2lane
	SENSOR_writeSeq(fd, sizeof(k_cmd_format_2592x1944_30fps_10bit) / sizeof(SensCmd),
	                k_cmd_format_2592x1944_30fps_10bit, k_i2c_slave_addr[path_idx]);
#elif defined SET_2592_1944_30fps_4lane
	SENSOR_writeSeq(fd, sizeof(k_cmd_format_2592x1944_30fps_12bit) / sizeof(SensCmd),
	                k_cmd_format_2592x1944_30fps_12bit, k_i2c_slave_addr[path_idx]);
#else
	assert(0);
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
	p->sensor_res.width = 2616; // 12 + 2592 + 12
	p->sensor_res.height = 1964; // 4 + 8 + 1944 + 8
	p->sensor_fps = sensor_fps;
	p->frame_len_line = frame_len_line;
	p->i2c_slv_addr = k_i2c_slave_addr[path_idx];
	p->ob_enable = 0;
	p->reserved = 0;

	memcpy(&p->parl_lane, &k_parl_lane[path_idx], sizeof(MPI_PARL_LANE_INFO_S));
	memcpy(&p->serl_lane[0], &k_serl_lane[path_idx], MPI_MAX_LVDSRX_LANE_NUM * sizeof(MPI_SERL_LANE_INFO_S));
	SENSOR_getLvdsDelay(sns_idx, p->serl_lane);

	p->mipi.bp_img.hor = 12;
	p->mipi.bp_img.ver = 12;
	p->mipi.fp_img.hor = 12;
	p->mipi.fp_img.ver = 8;

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
