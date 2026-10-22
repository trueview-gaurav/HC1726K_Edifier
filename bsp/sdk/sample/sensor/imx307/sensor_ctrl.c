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

#ifdef IMX307_ALL_PIXEL_SCAN

// All-pixel scan with (1945 + 3)x1080 pixels
// might change to 1097 lines later
static const SensCmd k_cmd_format_1080p_30fps_2lane[] = {
	//	{ 0x3002, 0x01 },           //master mode stop
	//	{ SENSOR_DELAY_REG, 0x14 }, //delay 20ms
	//	{ 0x3000, 0x01 },           //standby mode
	//	{ SENSOR_DELAY_REG, 0x14 }, //delay 20ms
	{ 0x3005, 0x01 },
	{ 0x3007, 0x00 },
	{ 0x3009, 0x02 },
	{ 0x300A, 0xF0 },
	{ 0x300B, 0x00 },
	{ 0x3011, 0x0A },
	{ 0x3012, 0x64 },
	{ 0x3013, 0x00 },
	{ 0x3016, 0x08 },
	{ 0x3018, 0x65 },
	{ 0x3019, 0x04 },
	{ 0x301A, 0x00 },
	{ 0x301C, 0x30 },
	{ 0x301D, 0x11 },
	{ 0x3020, 0x08 },
	{ 0x3021, 0x23 },
	{ 0x3046, 0x01 },
	{ 0x305C, 0x18 },
	{ 0x305D, 0x03 },
	{ 0x305E, 0x20 },
	{ 0x305f, 0x01 },
	{ 0x309E, 0x4A },
	{ 0x309F, 0x4A },
	{ 0x311C, 0x0E },
	{ 0x3128, 0x04 },
	{ 0x3129, 0x00 },
	{ 0x313B, 0x41 },
	{ 0x315E, 0x1A },
	{ 0x3164, 0x1A },
	{ 0x317C, 0x00 },
	{ 0x317E, 0x00 },
	{ 0x31EC, 0x0E },
	{ 0x3405, 0x10 },
	{ 0x3407, 0x01 },
	{ 0x3414, 0x0a },
	{ 0x3418, 0x38 },
	{ 0x3419, 0x04 },
	{ 0x3441, 0x0C },
	{ 0x3442, 0x0C },
	{ 0x3443, 0x01 },
	{ 0x3444, 0x20 },
	{ 0x3445, 0x25 },
	{ 0x3446, 0x57 },
	{ 0x3448, 0x37 },
	{ 0x344A, 0x1F },
	{ 0x344C, 0x1F },
	{ 0x344E, 0x1F },
	{ 0x3450, 0x77 },
	{ 0x3452, 0x1F },
	{ 0x3454, 0x17 },
	{ 0x3480, 0x49 },
	{ 0x3000, 0x00 },
	{ SENSOR_DELAY_REG, 0x14 },
};

#else

// 1920x1080 30fps 2lane using window cropping mode
static const SensCmd k_cmd_format_1080p_30fps_2lane_crop[] = {
	{ 0x3005, 0x01 }, // ADBIT 12 bit
	{ 0x3007, 0x40 }, // no flipping, enable window cropping
	{ 0x3009, 0x02 }, // 2 lane 30/25fps
	{ 0x300A, 0xF0 }, // black level for 12 bit output
	{ 0x300B, 0x00 },
	{ 0x3011, 0x0a }, // official tuning
	{ 0x3012, 0x64 }, // init setting, need to be verified
	{ 0x3013, 0x00 }, // init setting, default 0
	{ 0x3016, 0x08 }, // official tuning

	{ 0x3018, 0x65 }, // VMAX[7:0]   vertical span in master mode
	{ 0x3019, 0x04 }, // VMAX[15:8]  also known as frame line
	{ 0x301a, 0x00 }, // VMAX[17:16] the main control of the fps
	{ 0x301c, 0x30 }, // HMAX[7:0]   horizontal span
	{ 0x301d, 0x11 }, // HMAX[15:8]  also known as line length

	{ 0x303a, 0x0c }, // effective OB + 2 in cropping mode
	{ 0x303c, 0x08 }, // vertical cropping point
	{ 0x303d, 0x00 }, // set to 8 pixels
	{ 0x303e, 0x38 }, // crop window height
	{ 0x303f, 0x04 }, // set to 1080 pixels
	{ 0x3040, 0x0c }, // horizontal cropping point
	{ 0x3041, 0x00 }, // set to 12 pixels
	{ 0x3042, 0x80 }, // crop window width
	{ 0x3043, 0x07 }, // set to 1920 pixels
	{ 0x3046, 0x01 }, // ODBIT = 1 for 12 bit, OPORTSEL is don't care under CSI-2
	{ 0x305c, 0x18 }, // internal clock rate (0x305c-0x305f, 0x315e, 0x3164, 0x3480)
	{ 0x305d, 0x03 }, // these values mean it use 37.125MHz
	{ 0x305e, 0x20 },
	{ 0x305f, 0x01 },

	{ 0x309e, 0x4a }, // official tuning
	{ 0x309f, 0x4a }, // official tuning
	{ 0x311C, 0x0e }, // official tuning
	{ 0x3128, 0x04 }, // official tuning
	{ 0x3129, 0x00 }, // ADBIT 12 bit
	{ 0x313B, 0x41 }, // official tuning
	{ 0x315E, 0x1A }, // internal clock rate
	{ 0x3164, 0x1A }, // internal clock rate
	{ 0x317C, 0x00 }, // ADBIT 12 bit
	{ 0x317E, 0x00 }, // official tuning
	{ 0x31EC, 0x0E }, // ADBIT 12 bit

	{ 0x3405, 0x10 }, // repetition
	{ 0x3407, 0x01 }, // 2 lane
	{ 0x3414, 0x0a }, // vertical OB, default 0x0a
	{ 0x3418, 0x38 }, // Y_OUT_SIZE[7:0] = WINWV = 1080
	{ 0x3419, 0x04 }, // Y_OUT_SIZE[12:8]
	// { 0x3441, 0x0c }, // raw 12
	// { 0x3442, 0x0c }, // raw 12
	{ 0x3443, 0x01 }, // 2 lane
	{ 0x3444, 0x20 }, // external MCLK frequency (0x3444-0x3445)
	{ 0x3445, 0x25 }, // these values mean it use 37.125MHz
	{ 0x3446, 0x57 }, // global timing (0x3446-0x3455)
	{ 0x3448, 0x37 }, // unchanged values are omitted
	{ 0x344A, 0x1F },
	{ 0x344C, 0x1F },
	{ 0x344E, 0x1f },
	{ 0x3450, 0x77 },
	{ 0x3452, 0x1F },
	{ 0x3454, 0x17 },
	{ 0x3480, 0x49 }, // internal clock rate
	// { 0x3000, 0x00 }, // standby cancel, moved to startup command
	// { SENSOR_DELAY_REG, 0x14 }, // delay 20ms, moved to startup command
};

#endif

/* clang-format on */

static const SensCmd k_cmd_start[] = {
	{ 0x3000,           0x00 }, //operating mode
	{ SENSOR_DELAY_REG, 0x14 }, //delay 20ms
	{ 0x3002,           0x00 }, //master mode start
};

static const SensCmd k_cmd_stop[] = {
	{ 0x3000, 0x01 }, //standby mode
	//	{ SENSOR_DELAY_REG, 0x14 }, //delay 20ms
	//	{ 0x3002,           0x01 }, //master mode stop  /* Comment out this line does NOT match datasheet */
};

static void SENSOR_configInitSeq(uint8_t path_idx)
{
	int fd = g_i2c_fd[path_idx];
#ifdef IMX307_ALL_PIXEL_SCAN
	SENSOR_writeSeqWaddrBdata(fd, sizeof(k_cmd_format_1080p_30fps_2lane) / sizeof(SensCmd),
	                          k_cmd_format_1080p_30fps_2lane, k_i2c_slave_addr[path_idx]);
#else
	SENSOR_writeSeqWaddrBdata(fd, sizeof(k_cmd_format_1080p_30fps_2lane_crop) / sizeof(SensCmd),
	                          k_cmd_format_1080p_30fps_2lane_crop, k_i2c_slave_addr[path_idx]);
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

	SENSOR_writeSeqWaddrBdata(fd, sizeof(k_cmd_start) / sizeof(SensCmd),
				  k_cmd_start, k_i2c_slave_addr[path_idx]);

	/* Sensor needs 8 frames to output stable image */
//	usleep(320000);
}

static void SENSOR_configExitSeq(uint8_t path_idx)
{
	int fd = g_i2c_fd[path_idx];

	SENSOR_writeSeqWaddrBdata(fd, sizeof(k_cmd_stop) / sizeof(SensCmd),
				  k_cmd_stop, k_i2c_slave_addr[path_idx]);

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
	p->bit_width = MPI_BITS_12;
	p->intf_ptcl = MPI_INTF_PTCL_MIPI;
	p->ptcl_mode = MPI_MIPI_CSI2;
	p->hsync_plty = MPI_PLTY_HIGH;
	p->vsync_plty = MPI_PLTY_HIGH;
	p->bayer = MPI_BAYER_PHASE_R;
	p->ext_clk_freq = SENSOR_EXT_CLK_FREQ;
	// we still don't know why the image width is 1948 under cropping mode
	// so we use all-pixel scan to make sure it's 1948 now
	p->sensor_res.width = 1948;
	p->sensor_res.height = 1080;
	p->sensor_fps = FPS;
	p->frame_len_line = 1125;
	p->i2c_slv_addr = k_i2c_slave_addr[path_idx];
	p->ob_enable = 0;
	p->reserved = 0;

	memcpy(&p->parl_lane, &k_parl_lane[path_idx], sizeof(MPI_PARL_LANE_INFO_S));
	memcpy(&p->serl_lane[0], &k_serl_lane[path_idx], MPI_MAX_LVDSRX_LANE_NUM * sizeof(MPI_SERL_LANE_INFO_S));
	SENSOR_getLvdsDelay(sns_idx, p->serl_lane);

	// porch for all-pixel scan
#ifdef IMX307_ALL_PIXEL_SCAN
	p->mipi.bp_img.hor = 12;
	p->mipi.bp_img.ver = 0;
	p->mipi.fp_img.hor = 16;
	p->mipi.fp_img.ver = 0;
#else
	p->mipi.bp_img.hor = 0;
	p->mipi.bp_img.ver = 0;
	p->mipi.fp_img.hor = 0;
	p->mipi.fp_img.ver = 0;
#endif
	p->mipi.bp_eff_pix.hor = 0;
	p->mipi.bp_eff_pix.ver = 0;

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
