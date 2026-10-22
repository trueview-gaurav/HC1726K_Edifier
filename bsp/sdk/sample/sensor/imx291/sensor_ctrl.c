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

// 1920x1080 30fps_4lane
static const SensCmd k_cmd_format_1080p_30fps[] = {
//	{ 0x3000, 0x01 },
//	{ 0x3002, 0x01 },

	/* Internal A/D conversion bits setting */
	{ 0x3005, 0x01 }, // RAW10:0x00, RAW12:0x01
	{ 0x3129, 0x00 }, // RAW10:0x1D, RAW12:0x00
	{ 0x317C, 0x00 }, // RAW10:0x12, RAW12:0x00
	{ 0x31EC, 0x0E }, // RAW10:0x37, RAW12:0x0E

	{ 0x3009, 0x12 }, // [1:0], 30fps:0x2, 60fps:0x1
	{ 0x300F, 0x00 },
	{ 0x3010, 0x21 },
	{ 0x3012, 0x64 },
	{ 0x3016, 0x09 },
	{ 0x301C, 0x30 },
	{ 0x301D, 0x11 },
#if (SENIF == SONYLVDS)
#if (LANE == QUAD_LANE)
	{ 0x3046, 0xE1 },
#elif (LANE == DUAL_LANE)
	{ 0x3046, 0xD1 },
#endif
#endif
	/* INCK setting */
	{ 0x305C, 0x18 },
#if (SENIF == SONYLVDS)
	{ 0x305D, 0x00 },
#elif (SENIF == MIPI)
	{ 0x305D, 0x03 },
#endif
	{ 0x305E, 0x20 },
	{ 0x305F, 0x01 },
	{ 0x315E, 0x1A },
	{ 0x3164, 0x1A },
	{ 0x3480, 0x49 },
	{ 0x3070, 0x02 },
	{ 0x3071, 0x11 },
	{ 0x309B, 0x10 },
	{ 0x309C, 0x22 },
	{ 0x30A2, 0x02 },
	{ 0x30A6, 0x20 },
	{ 0x30A8, 0x20 },
	{ 0x30AA, 0x20 },
	{ 0x30AC, 0x20 },
	{ 0x30B0, 0x43 },
	{ 0x3119, 0x9E },
	{ 0x311C, 0x1E },
	{ 0x311E, 0x08 },
	{ 0x3128, 0x05 },
	{ 0x313D, 0x83 },
	{ 0x3150, 0x03 },
	{ 0x317E, 0x00 },
	{ 0x32B8, 0x50 },
	{ 0x32B9, 0x10 },
	{ 0x32BA, 0x00 },
	{ 0x32BB, 0x04 },
	{ 0x32C8, 0x50 },
	{ 0x32C9, 0x10 },
	{ 0x32CA, 0x00 },
	{ 0x32CB, 0x04 },
	{ 0x332C, 0xD3 },
	{ 0x332D, 0x10 },
	{ 0x332E, 0x0D },
	{ 0x3358, 0x06 },
	{ 0x3359, 0xE1 },
	{ 0x335A, 0x11 },
	{ 0x3360, 0x1E },
	{ 0x3361, 0x61 },
	{ 0x3362, 0x10 },
	{ 0x33B0, 0x50 },
	{ 0x33B2, 0x1A },
	{ 0x33B3, 0x04 },
	{ 0x3405, 0x20 },
	{ 0x3407, 0x03 }, // Physical lane number
	{ 0x3418, 0x49 },
	{ 0x3419, 0x04 },
	{ 0x3441, 0x0C }, // RAW10:0x0A, RAW12:0x0C
	{ 0x3442, 0x0C }, // RAW10:0x0A, RAW12:0x0C
#if (LANE == QUAD_LANE)
	{ 0x3443, 0x03 }, // LANE_MODE, 2Lane:0x01, 4Lane:0x03
#elif (LANE == DUAL_LANE)
	{ 0x3443, 0x01 }, // LANE_MODE, 2Lane:0x01, 4Lane:0x03
#endif
	{ 0x3444, 0x20 },
	{ 0x3445, 0x25 },
	{ 0x3446, 0x47 },
	{ 0x3448, 0x1F },
	{ 0x344A, 0x17 },
	{ 0x344C, 0x0F },
	{ 0x344E, 0x17 },
	{ 0x3450, 0x47 },
	{ 0x3452, 0x0F },
	{ 0x3454, 0x0F },

	{ 0x3000, 0x00 },
	{ 0x3002, 0x00 },
        //init exposure
	{ 0x3018, 0x65 }, //fps line = 1125(30fps) [7:0]
	{ 0x3019, 0x04 }, //[15:8]
	{ 0x301A, 0x00 }, //[17:16]
	{ 0x3020, 0x37 }, //exposure time = 16500 <us> [7:0]
	{ 0x3021, 0x02 }, //[15:8]
	{ 0x3022, 0x00 }, //[17:16]
	{ 0x3014, 0x00 }, //gain = 0(1x)
};

// 1920x1080 60fps_4lane
static const SensCmd k_cmd_format_1080p_60fps[] = {
//	{ 0x3000, 0x01 },
//	{ 0x3002, 0x01 },

	{ 0x3005, 0x01 },
	{ 0x3009, 0x11 },
	{ 0x300F, 0x00 },
	{ 0x3010, 0x21 },
	{ 0x3012, 0x64 },
	{ 0x3016, 0x09 },
	{ 0x301C, 0x98 },
	{ 0x301D, 0x08 },
	{ 0x305C, 0x18 },
	{ 0x305D, 0x03 },
	{ 0x305E, 0x20 },
	{ 0x305F, 0x01 },
	{ 0x3070, 0x02 },
	{ 0x3071, 0x11 },
	{ 0x309B, 0x10 },
	{ 0x309C, 0x22 },
	{ 0x30A2, 0x02 },
	{ 0x30A6, 0x20 },
	{ 0x30A8, 0x20 },
	{ 0x30AA, 0x20 },
	{ 0x30AC, 0x20 },
	{ 0x30B0, 0x43 },
	{ 0x3119, 0x9E },
	{ 0x311C, 0x1E },
	{ 0x311E, 0x08 },
	{ 0x3128, 0x05 },
	{ 0x3129, 0x00 },
	{ 0x313D, 0x83 },
	{ 0x3150, 0x03 },
	{ 0x315E, 0x1A },
	{ 0x3164, 0x1A },
	{ 0x317C, 0x00 },
	{ 0x317E, 0x00 },
	{ 0x31EC, 0x0E },
	{ 0x32B8, 0x50 },
	{ 0x32B9, 0x10 },
	{ 0x32BA, 0x00 },
	{ 0x32BB, 0x04 },
	{ 0x32C8, 0x50 },
	{ 0x32C9, 0x10 },
	{ 0x32CA, 0x00 },
	{ 0x32CB, 0x04 },
	{ 0x332C, 0xD3 },
	{ 0x332D, 0x10 },
	{ 0x332E, 0x0D },
	{ 0x3358, 0x06 },
	{ 0x3359, 0xE1 },
	{ 0x335A, 0x11 },
	{ 0x3360, 0x1E },
	{ 0x3361, 0x61 },
	{ 0x3362, 0x10 },
	{ 0x33B0, 0x50 },
	{ 0x33B2, 0x1A },
	{ 0x33B3, 0x04 },
	{ 0x3405, 0x10 },
	{ 0x3407, 0x03 },
	{ 0x3418, 0x49 },
	{ 0x3419, 0x04 },
	{ 0x3441, 0x0C },
	{ 0x3442, 0x0C },
	{ 0x3443, 0x03 },
	{ 0x3444, 0x20 },
	{ 0x2445, 0x25 },
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
	{ 0x3002, 0x00 },
};

static const SensCmd k_cmd_start[] = {
	{ 0x3000, 0x00           },
	{ SENSOR_DELAY_REG, 0x14 }, //delay 20ms
	{ 0x3002, 0x00           },
};

static const SensCmd k_cmd_stop[] = {
	{ 0x3000, 0x01 },
	{ 0x3002, 0x01 },
};


static void SENSOR_configInitSeq(uint8_t path_idx)
{
	int fd = g_i2c_fd[path_idx];

#if (FORMAT == FULLHD)
	SENSOR_writeSeqWaddrBdata(fd, sizeof(k_cmd_format_1080p_30fps) / sizeof(SensCmd),
				  k_cmd_format_1080p_30fps, k_i2c_slave_addr[path_idx]);
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
	p->bit_width = MPI_BITS_12;
	p->intf_ptcl = MPI_INTF_PTCL_SONY_LVDS;
	p->ptcl_mode = MPI_SONY_LVDS_DDR;
	p->hsync_plty = MPI_PLTY_HIGH;
	p->vsync_plty = MPI_PLTY_HIGH;
	p->bayer = MPI_BAYER_PHASE_R;
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

	p->sonylvds.bp_img.hor = 12;
	p->sonylvds.bp_img.ver = 21;
	p->sonylvds.fp_img.hor = 16;
	p->sonylvds.fp_img.ver = 9;

	p->sonylvds.ob_conf.skipped_line_num = 0;
	p->sonylvds.ob_conf.pos = MPI_POS_NONE;
	p->sonylvds.ob_conf.region.x = 0;
	p->sonylvds.ob_conf.region.y = 0;
	p->sonylvds.ob_conf.region.width = 0;
	p->sonylvds.ob_conf.region.height = 0;

	return MPI_SUCCESS;
}
