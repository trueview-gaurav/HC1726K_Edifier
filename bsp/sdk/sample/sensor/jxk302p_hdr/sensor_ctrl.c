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
int g_i2c_fd[2] = {
	-1,
	-1,
};

static const uint16_t k_i2c_slave_addr[2] = {
	SENSOR_I2C_SLAVE_ADDR,
	SENSOR_I2C_SLAVE_ADDR1,
};
#else
int g_i2c_fd[1] = {
	-1,
};

static const uint16_t k_i2c_slave_addr[1] = {
	SENSOR_I2C_SLAVE_ADDR,
};
#endif

#ifdef SET_2688_1520_15fps_hdr_nonVC_2lane
// 2688x1520 HDR 15fps 2lane
static const SensCmd k_cmd_format_2688x1520_hdr[] = {
	{ 0x12, 0x48 },
	{ 0x48, 0x8A },
	{ 0x48, 0x0A },
	{ 0x0E, 0x11 },
	{ 0x0F, 0x04 },
	{ 0x10, 0x48 },
	{ 0x11, 0x80 },
	{ 0x0D, 0x50 },
	{ 0x57, 0x60 },
	{ 0x58, 0x18 },
	{ 0x5F, 0x41 },
	{ 0x60, 0x24 },
	{ 0x20, 0xEE },
	{ 0x21, 0x02 },
	{ 0x22, 0x00 },
	{ 0x23, 0x0F },
	{ 0x24, 0xA0 },
	{ 0x25, 0xF0 },
	{ 0x26, 0x52 },
	{ 0x27, 0xEA },
	{ 0x28, 0x41 },
	{ 0x29, 0x02 },
	{ 0x2A, 0xDE },
	{ 0x2B, 0x12 },
	{ 0x2C, 0x00 },
	{ 0x2D, 0x00 },
	{ 0x2E, 0x85 },
	{ 0x2F, 0x44 },
	{ 0x41, 0xA2 },
	{ 0x42, 0x22 },
	{ 0x46, 0x1C },
	{ 0x47, 0x72 },
	{ 0x80, 0x02 },
	{ 0xAF, 0x22 },
	{ 0xBD, 0x80 },
	{ 0xBE, 0x0A },
	{ 0x1D, 0x00 },
	{ 0x1E, 0x04 },
	{ 0x6C, 0x40 },
	{ 0x70, 0xD5 },
	{ 0x71, 0x9B },
	{ 0x72, 0x6D },
	{ 0x73, 0x49 },
	{ 0x75, 0xD6 },
	{ 0x74, 0x02 },
	{ 0x89, 0x0F },
	{ 0x0C, 0x80 },
	{ 0x6B, 0x20 },
	{ 0x86, 0x00 },
	{ 0x9E, 0x80 },
	{ 0x78, 0x44 },
	{ 0x30, 0x8A },
	{ 0x31, 0x0A },
	{ 0x32, 0x52 },
	{ 0x33, 0x58 },
	{ 0x34, 0x3E },
	{ 0x35, 0x3E },
	{ 0x3A, 0xAF },
	{ 0x45, 0x87 },
	{ 0x56, 0x00 },
	{ 0x59, 0x4D },
	{ 0x85, 0x30 },
	{ 0x8A, 0x04 },
	{ 0x91, 0x22 },
	{ 0x9B, 0x83 },
	{ 0x5B, 0xAC },
	{ 0x5C, 0xFE },
	{ 0x5D, 0x74 },
	{ 0x5E, 0x00 },
	{ 0x61, 0x20 },
	{ 0x64, 0xE0 },
	{ 0x65, 0x32 },
	{ 0x66, 0x00 },
	{ 0x67, 0x46 },
	{ 0x68, 0x20 },
	{ 0x69, 0xF4 },
	{ 0x6A, 0x28 },
	{ 0x7A, 0x00 },
	{ 0x82, 0x30 },
	{ 0x8F, 0x90 },
	{ 0x9D, 0x71 },
	{ 0xBF, 0x01 },
	{ 0x57, 0x22 },
	{ 0x5E, 0x21 },
	{ 0xBF, 0x00 },
	{ 0x97, 0xFA },
	{ 0x13, 0x01 },
	{ 0x96, 0x04 },
	{ 0x4A, 0x01 },
	{ 0x7E, 0xCC },
	{ 0x50, 0x02 },
	{ 0x49, 0x10 },
	{ 0x7F, 0x57 },
	{ 0x8E, 0x00 },
	{ 0xA7, 0x80 },
	{ 0xBF, 0x01 },
	{ 0x4E, 0x11 },
	{ 0x50, 0x00 },
	{ 0x51, 0x0F },
	{ 0x55, 0x20 },
	{ 0x58, 0x00 },
	{ 0xBF, 0x00 },
	{ 0x19, 0x20 },
	{ 0x07, 0x03 },
	{ 0x1B, 0x4F },
	//{ 0x06, 0x23},
	{ 0x06, 0xF0 },
	{ 0x03, 0xFF },
	{ 0x04, 0xFF },
	{ 0x79, 0x00 },
};

static const SensCmd k_cmd_start[] = {
	{ 0x12, 0x08},
	{ 0x00, 0x10},
	{ 0x0A, 0x0A},
	{ 0x0A, 0x0A},
	{ 0x0A, 0x0A},
	{ 0x0A, 0x0A},
	{ 0x0A, 0x0A},
	{ 0x0A, 0x0A},
	{ 0x0A, 0x0A},
	{ 0x0A, 0x0A},
	{ 0x75, 0x56},
};
#endif

static const SensCmd k_cmd_stop[] = {
	{ 0x12, 0x40 },
};

static void SENSOR_configInitSeq(uint8_t path_idx)
{
	int fd = g_i2c_fd[path_idx];

	SENSOR_writeSeq(fd, sizeof(k_cmd_format_2688x1520_hdr) / sizeof(SensCmd), k_cmd_format_2688x1520_hdr,
	                k_i2c_slave_addr[path_idx]);

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

#ifdef DUAL_SENSOR_SUPPORT
	/* TODO: Remove this workaround */
	if (k_i2c_slave_addr[0] == k_i2c_slave_addr[1]) {
		SENSOR_writeSeqBaddrBdata(fd, sizeof(k_cmd_start) / sizeof(SensCmd), k_cmd_start,
		                          k_i2c_slave_addr[path_idx]);
	} else {
		/* For the case of different I2C slave address, enable both
		 * sensors when path_idx == 1 */
		if (path_idx == 1) {
			uint8_t i = 0;

			for (i = 0; i < MPI_MAX_INPUT_PATH_NUM; i++) {
				fd = g_i2c_fd[i];

				SENSOR_writeSeq(fd, sizeof(k_cmd_start) / sizeof(SensCmd), k_cmd_start,
				                k_i2c_slave_addr[i]);
			}
		}
	}
#else
	SENSOR_writeSeq(fd, sizeof(k_cmd_start) / sizeof(SensCmd), k_cmd_start, k_i2c_slave_addr[path_idx]);
#endif
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

	p->sensor_mode = MPI_SNS_MODE_MASTER;
	p->slv_sync_src = MPI_SLV_SYNC_SRC_NONE;
	p->bit_width = MPI_BITS_10;
	p->intf_ptcl = MPI_INTF_PTCL_MIPI;
	p->ptcl_mode = MPI_MIPI_CSI2;
	p->hsync_plty = MPI_PLTY_HIGH;
	p->vsync_plty = MPI_PLTY_HIGH;
	p->bayer = MPI_BAYER_PHASE_B;
	p->ext_clk_freq = SENSOR_EXT_CLK_FREQ;
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

	p->sensor_res.width = SENSOR_WIDTH;
	p->sensor_res.height = HDR_HEIGHT;
	p->hdr.vc_enable = 0;
	p->hdr.hdr_mode = HDR_MODE;
	p->hdr.image_num = HDR_IMAGE_NUM;
	p->hdr.blank_line_num[0] = HDR_MIPI_BLANK_LINE;

	return MPI_SUCCESS;
}
