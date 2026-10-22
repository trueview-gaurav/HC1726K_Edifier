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

/* clang-format off */

static const SensCmd k_cmd_format_1080p_30fps_2lane[] = {
	{ 0x3000, 0x01 }, // standby
	{ 0x3001, 0x00 },
	{ 0x3002, 0x01 }, // stop master mode
	// { 0x3003, 0x00 }, // SW_reset
	{ 0x3005, 0x00 }, // ADBIT, 10 bit
	{ 0x3007, 0x00 }, // full scan mode
	{ 0x3009, 0x02 },
	{ 0x300A, 0x3C },
	{ 0x300B, 0x00 },
	{ 0x3012, 0x2C },
	{ 0x3013, 0x01 },
	{ 0x3014, 0x00 }, // gain [7:0]
	{ 0x3015, 0x00 }, // gain [9:8]
	{ 0x3016, 0x09 }, // sync gain and shutter time
	{ 0x3018, 0x65 }, // VMAX [ 7:0]
	{ 0x3019, 0x04 }, // VMAX [15:8]
	{ 0x301A, 0x00 }, // VMAX [16], 0x465 = 1125
	// { 0x301B, 0x30 }, // HMAX [ 7: 0]
	// { 0x301C, 0x11 }, // HMAX [13: 8], 0x1130 = 4400
	{ 0x301B, 0xA0 }, // HMAX [ 7: 0]
	{ 0x301C, 0x11 }, // HMAX [13: 8], 0x11a0 = 4512
	{ 0x3020, 0x38 }, // SHS [ 7:0]
	{ 0x3021, 0x02 }, // SHS [15:8]
	{ 0x3022, 0x00 }, // SHS [16], set it later
	{ 0x3036, 0x10 }, // OB for window cropping mode
	// { 0x3038, 0x00 }, // WINPV [ 7:0]
	// { 0x3039, 0x00 }, // WINPV [10:8], vertical start in window cropping
	{ 0x303A, 0xD1 }, // WINWV [ 7:0]
	{ 0x303B, 0x03 }, // WINWV [10:8], 0x3d1 = 977? vertical hight of output
	// { 0x303C, 0x00 }, // WINPH [ 7:0]
	// { 0x303D, 0x00 }, // WINPH [10:8], * 4 = horizontal start in window cropping
	// { 0x303E, 0x1C }, // WINWH [ 7:0]
	// { 0x303F, 0x05 }, // WINWH [10:8], * 4 = horizontal width of output
	{ 0x3044, 0x01 }, // fixed to 1 in CSI-2
	{ 0x3046, 0x00 },
	{ 0x3047, 0x08 },
	{ 0x3049, 0x00 },
	{ 0x3054, 0x66 },
	{ 0x305C, 0x28 }, //incksel1
	{ 0x305D, 0x00 }, //incksel2
	{ 0x305E, 0x20 }, //incksel3
	{ 0x305F, 0x00 }, //incksel4
	{ 0x310B, 0x07 },
	{ 0x3110, 0x12 },
	{ 0x31ED, 0x38 },
	{ 0x3338, 0xD4 },
	{ 0x3339, 0x40 },
	{ 0x333A, 0x10 },
	{ 0x333B, 0x00 },
	{ 0x333C, 0xD4 },
	{ 0x333D, 0x40 },
	{ 0x333E, 0x10 },
	{ 0x333F, 0x00 },
	{ 0x3344, 0x10 },
	{ 0x3346, 0x01 }, // 2 lane
	{ 0x3353, 0x0E },
	// { 0x3357, 0x49 }, // PIC_SIZE_V [ 7:0], vertical effective pixel
	// { 0x3358, 0x04 }, // PIC_SIZE_V [12:8], 0x449 = 1097
	{ 0x3357, 0x38 }, // PIC_SIZE_V [ 7:0], vertical effective pixel
	{ 0x3358, 0x04 }, // PIC_SIZE_V [12:8], set to 1080 because there's a bug
	{ 0x336B, 0x37 }, //Global timing
	{ 0x336C, 0x1F }, //Global timing
	{ 0x337D, 0x0A }, // RAW 10
	{ 0x337E, 0x0A }, // RAW 10
	{ 0x337F, 0x01 }, // 2 lane
	{ 0x3380, 0x20 }, // MCLK
	{ 0x3381, 0x25 }, // 37.125MHz
	{ 0x3382, 0x5F }, //Global timing
	{ 0x3383, 0x1F }, //Global timing
	{ 0x3384, 0x37 }, //Global timing
	{ 0x3385, 0x1F }, //Global timing
	{ 0x3386, 0x1F }, //Global timing
	{ 0x3387, 0x17 }, //Global timing
	{ 0x3388, 0x67 }, //Global timing
	{ 0x3389, 0x27 }, //Global timing
	{ 0x338D, 0xB4 }, // MCLK
	{ 0x338E, 0x01 }, // 37.125MHz

	// { 0x3000, 0x00 }, // operating mode
	// { 0x3002, 0x00 }, // master mode start
};

// 1920x1080 30fps 2lane using window cropping mode
static const SensCmd k_cmd_format_1080p_30fps_2lane_crop[] = {
	{ 0x3000, 0x01 }, // standby
	{ 0x3001, 0x00 },
	{ 0x3002, 0x01 }, // stop master mode
	{ 0x3005, 0x00 }, // ADBIT, 10 bit
	{ 0x3007, 0x40 }, // window cropping
	{ 0x3009, 0x02 },
	{ 0x300A, 0x3C }, // DBC
	{ 0x300B, 0x00 }, // DBC
	{ 0x3012, 0x2C },
	{ 0x3013, 0x01 },
	{ 0x3014, 0x00 }, // gain [7:0]
	{ 0x3015, 0x00 }, // gain [9:8]
	{ 0x3016, 0x09 }, // sync gain and shutter time
	{ 0x3018, 0x65 }, // VMAX [ 7:0]
	{ 0x3019, 0x04 }, // VMAX [15:8]
	{ 0x301A, 0x00 }, // VMAX [16], 0x465 = 1125
	// { 0x301B, 0x30 }, // HMAX [ 7: 0]
	// { 0x301C, 0x11 }, // HMAX [13: 8], 0x1130 = 4400
	{ 0x301B, 0xA0 }, // HMAX [ 7: 0], adjusted due to MCLK frequency
	{ 0x301C, 0x11 }, // HMAX [13: 8], 0x11a0 = 4512
	{ 0x3020, 0x38 }, // SHS [ 7:0]
	{ 0x3021, 0x02 }, // SHS [15:8]
	{ 0x3022, 0x00 }, // SHS [16], set it later
	{ 0x3036, 0x10 }, // OB for window cropping mode
	{ 0x3038, 0x08 }, // WINPV [ 7:0]
	{ 0x3039, 0x00 }, // WINPV [10:8], vertical start in window cropping
	{ 0x303A, 0x38 }, // WINWV [ 7:0]
	{ 0x303B, 0x04 }, // WINWV [10:8], 0x438 = 1080 vertical hight of output
	{ 0x303C, 0x0C }, // WINPH [ 7:0]
	{ 0x303D, 0x00 }, // WINPH [10:8], horizontal start in window cropping
	{ 0x303E, 0x80 }, // WINWH [ 7:0]
	{ 0x303F, 0x07 }, // WINWH [10:8], horizontal width of output
	{ 0x3044, 0x01 }, // fixed to 1 in CSI-2
	{ 0x3046, 0x00 },
	{ 0x3047, 0x08 },
	{ 0x3049, 0x00 },
	{ 0x3054, 0x66 },
	{ 0x305C, 0x28 }, //incksel1
	{ 0x305D, 0x00 }, //incksel2
	{ 0x305E, 0x20 }, //incksel3
	{ 0x305F, 0x00 }, //incksel4
	{ 0x310B, 0x07 },
	{ 0x3110, 0x12 },
	{ 0x31ED, 0x38 },
	{ 0x3338, 0xD4 },
	{ 0x3339, 0x40 },
	{ 0x333A, 0x10 },
	{ 0x333B, 0x00 },
	{ 0x333C, 0xD4 },
	{ 0x333D, 0x40 },
	{ 0x333E, 0x10 },
	{ 0x333F, 0x00 },
	{ 0x3344, 0x10 },
	{ 0x3346, 0x01 }, // 2 lane
	{ 0x3353, 0x0E }, // OB_SIZE_V = 16 - 2 = 14
	{ 0x3357, 0x38 }, // PIC_SIZE_V [ 7:0], = WINWV in window cropping
	{ 0x3358, 0x04 }, // PIC_SIZE_V [12:8], 0x438 = 1080
	{ 0x336B, 0x37 }, //Global timing
	{ 0x336C, 0x1F }, //Global timing
	{ 0x337D, 0x0A }, // RAW 10
	{ 0x337E, 0x0A }, // RAW 10
	{ 0x337F, 0x01 }, // 2 lane
	{ 0x3380, 0x20 }, // MCLK
	{ 0x3381, 0x25 }, // 37.125MHz
	{ 0x3382, 0x5F }, //Global timing
	{ 0x3383, 0x1F }, //Global timing
	{ 0x3384, 0x37 }, //Global timing
	{ 0x3385, 0x1F }, //Global timing
	{ 0x3386, 0x1F }, //Global timing
	{ 0x3387, 0x17 }, //Global timing
	{ 0x3388, 0x67 }, //Global timing
	{ 0x3389, 0x27 }, //Global timing
	{ 0x338D, 0xB4 }, // MCLK
	{ 0x338E, 0x01 }, // 37.125MHz

	// { 0x3000, 0x00 }, // operating mode
	// { 0x3002, 0x00 }, // master mode start
};

/* clang-format on */

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

	SENSOR_writeSeqWaddrBdata(fd, sizeof(k_cmd_format_1080p_30fps_2lane_crop) / sizeof(SensCmd),
	                          k_cmd_format_1080p_30fps_2lane_crop, k_i2c_slave_addr[path_idx]);

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

	SENSOR_writeSeqWaddrBdata(fd, sizeof(k_cmd_start) / sizeof(SensCmd), k_cmd_start, k_i2c_slave_addr[path_idx]);

	/* Sensor needs 8 frames to output stable image */
	/* Not really have to skip those but should notice that there is a concern. */
	//	usleep(320000);
}

static void SENSOR_configExitSeq(uint8_t path_idx)
{
	int fd = g_i2c_fd[path_idx];

	SENSOR_writeSeqWaddrBdata(fd, sizeof(k_cmd_stop) / sizeof(SensCmd), k_cmd_stop, k_i2c_slave_addr[path_idx]);

	usleep(500000);
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
	p->sensor_res.width = 1945; //12 + 1920 + 13
	p->sensor_res.height = 1097; //8 + 1080 + 9
	p->sensor_fps = (float)SENSOR_FPS;
	p->frame_len_line = INIT_FRAME_LINE;
	p->i2c_slv_addr = k_i2c_slave_addr[path_idx];
	p->ob_enable = 0;
	p->reserved = 0;

	memcpy(&p->parl_lane, &k_parl_lane[path_idx], sizeof(MPI_PARL_LANE_INFO_S));
	memcpy(&p->serl_lane[0], &k_serl_lane[path_idx], MPI_MAX_LVDSRX_LANE_NUM * sizeof(MPI_SERL_LANE_INFO_S));
	SENSOR_getLvdsDelay(sns_idx, p->serl_lane);

	p->mipi.bp_img.hor = 12;
	p->mipi.bp_img.ver = 8;
	p->mipi.fp_img.hor = 13;
	p->mipi.fp_img.ver = 9;
	p->mipi.bp_eff_pix.hor = 0;
	p->mipi.bp_eff_pix.ver = 0;

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
