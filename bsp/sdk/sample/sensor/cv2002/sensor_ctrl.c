/******************************************************************************
 * *
 * * Copyright (c) Augentix Inc. - All Rights Reserved
 * *
 * * Unauthorized copying of this file, via any medium is strictly prohibited.
 * *
 * * Proprietary and confidential.
 * *
 * *****************************************************************************/

#include "sensor.h"

#include <stdio.h>
#include <unistd.h>
#include <stdint.h>
#include <string.h>

#include "sensor_settings.h"
#include "sensor_params.h"
#include "sensor_lvds.h"

static int g_i2c_fd[1] = {
	-1,
};

static const uint16_t k_i2c_slave_addr[1] = {
	SENSOR_I2C_SLAVE_ADDR,
};

#ifdef SET_896_504_115fps_2lane
#define k_cmd_format k_cmd_format_896x504_115fps
static const SensCmd k_cmd_format_896x504_115fps[] = {
	{ 0x3020, 0xE4 }, { 0x3021, 0x04 }, { 0x3022, 0x00 }, { 0x3024, 0x70 }, { 0x3025, 0x02 }, { 0x3029, 0x00 },
	{ 0x302A, 0x00 }, { 0x302C, 0x01 }, { 0x302D, 0x01 }, { 0x3030, 0x01 }, { 0x3034, 0x12 }, { 0x3035, 0x00 },
	{ 0x3036, 0xF8 }, { 0x3037, 0x01 }, { 0x3038, 0x40 }, { 0x3039, 0x00 }, { 0x303a, 0x00 }, { 0x303b, 0x07 },
	{ 0x3161, 0x01 }, { 0x3165, 0x01 }, { 0x3257, 0x00 }, { 0x327A, 0x96 }, { 0x327B, 0x08 }, { 0x327C, 0xFE },
	{ 0x327D, 0x1F }, { 0x327E, 0xFE }, { 0x327F, 0x1F }, { 0x3284, 0xFE }, { 0x3285, 0x1F }, { 0x3286, 0xFE },
	{ 0x3287, 0x1F }, { 0x3300, 0x01 }, { 0x3401, 0x01 }, { 0x3440, 0x03 }, { 0x3442, 0x01 }, { 0x3806, 0x01 },
	{ 0x3908, 0x4B }, { 0x3909, 0x00 }, { 0x3158, 0x01 }, { 0x3159, 0x01 }, { 0x315A, 0x01 }, { 0x315B, 0x01 },
	{ 0x3148, 0x64 }, { 0x3670, 0x00 }, { 0x3679, 0x02 }, { 0x35b3, 0x15 }, { 0x320E, 0x02 }, { 0x3804, 0x10 },
	{ 0x35a1, 0x06 }, { 0x35a8, 0x06 }, { 0x35a9, 0x06 }, { 0x35aa, 0x06 }, { 0x35ab, 0x06 }, { 0x35ac, 0x06 },
	{ 0x35ad, 0x06 }, { 0x35ae, 0x07 }, { 0x35af, 0x07 }, { 0x333B, 0x01 }, { 0x3338, 0x1E }, { 0x3339, 0x00 },
	{ 0x3141, 0x01 }, { 0x3031, 0x00 }, { 0x3118, 0x00 }, //OB调整使能
	{ 0x3119, 0x06 }, //OB输出6行
	{ 0x3330, 0x00 }, //不插入EBD
	{ 0x3000, 0x00 }, { 0x3420, 0x1f }, //THSPREPARE: 71 ns ; min limit: 49 ; max limt: 98.33333333333333
	{ 0x3422, 0x47 }, //THSZERO   : 160 ns ; min limit: 167 ; max limt: 1000
	{ 0x3424, 0x2f }, //THSTRAIL  : 106 ns ; min limit: 73 ; max limt: 1000
	{ 0x3426, 0x37 }, //THSEXIT   : 124 ns ; min limit: 100 ; max limt: 1000
	{ 0x3428, 0x1f }, //TLPX      : 71 ns ; min limit: 50 ; max limt: 1000
	{ 0x3400, 0x11 }

};
#endif

#ifdef SET_1920_1080_30fps_2lane
#define k_cmd_format k_cmd_format_1080p_30fps
// 1920x1080 30fps_2lane
//0x3400 : 0x11, MIPI clk non-continue; 0x10, continue
static const SensCmd k_cmd_format_1080p_30fps[] = {
	{ 0x306D, 0x00 }, { 0x3070, 0x00 }, { 0x3071, 0x00 }, { 0x3074, 0x00 }, { 0x3075, 0x00 }, { 0x3078, 0x00 },
	{ 0x3079, 0x00 }, { 0x307A, 0x02 }, { 0x307B, 0x00 }, { 0x324C, 0x00 }, { 0x324D, 0x04 }, { 0x324E, 0x00 },
	{ 0x324F, 0x04 }, { 0x3250, 0x00 }, { 0x3251, 0x04 }, { 0x3252, 0x00 }, { 0x3253, 0x04 }, { 0x342F, 0x03 },
	{ 0x3430, 0x00 }, { 0x3431, 0x01 }, { 0x3432, 0x04 }, { 0x3433, 0x05 }, { 0x3440, 0x01 }, //HMAX 0x44c=29.62963us
	{ 0x3441, 0x00 }, { 0x3442, 0x00 }, { 0x3443, 0x00 }, { 0x3300, 0x01 }, { 0x3401, 0x01 }, { 0x3440, 0x03 },
	{ 0x3442, 0x00 }, { 0x3806, 0x01 }, { 0x3158, 0x01 }, { 0x3159, 0x01 }, { 0x315A, 0x01 }, { 0x315B, 0x01 },
	{ 0x35B3, 0x15 }, { 0x3148, 0x64 }, { 0x3031, 0x00 }, { 0x3118, 0x01 }, { 0x3119, 0x06 }, { 0x3670, 0x00 },
	{ 0x3679, 0x02 }, { 0x3330, 0x00 }, { 0x320e, 0x02 }, { 0x3804, 0x10 }, { 0x35a1, 0x06 }, { 0x35a8, 0x06 },
	{ 0x35a9, 0x06 }, { 0x35aa, 0x06 }, { 0x35ab, 0x06 }, { 0x35ac, 0x06 }, { 0x35ad, 0x06 }, { 0x35ae, 0x07 },
	{ 0x35af, 0x07 }, { 0x333B, 0x01 }, { 0x3338, 0x1E }, { 0x3339, 0x00 }, { 0x3141, 0x01 }, { 0x3030, 0x01 },
	{ 0x3020, 0xC4 }, //C4   88
	{ 0x3021, 0x09 }, //09    13
	{ 0x3024, 0x78 }, { 0x3025, 0x02 }, //X add? //0xF0, 0x04
	{ 0x3038, 0x00 }, //X add?
	{ 0x3039, 0x00 }, //X add?
	{ 0x303A, 0x80 }, //89
	{ 0x303B, 0x07 }, { 0x3034, 0x04 }, { 0x3035, 0x00 }, { 0x3036, 0x38 }, { 0x3037, 0x04 }, { 0x3908, 0x4f },
	{ 0x390A, 0x04 }, //0x02

	{ 0x3420 , 0x37 },//THSPREPARE: 59 ns ; min limit: 44 ; max limt: 91.32911392405063
	{ 0x3422 , 0x9f },//THSZERO   : 168 ns ; min limit: 156 ; max limt: 1000
	{ 0x3424 , 0x4f },//THSTRAIL  : 84 ns ; min limit: 68 ; max limt: 1000
	{ 0x3426 , 0x67 },//THSEXIT   : 109 ns ; min limit: 100 ; max limt: 1000
	{ 0x3428 , 0x37 },//TLPX      : 59 ns ; min limit: 50 ; max limt: 1000

	{ 0x3400, 0x11 }
};
#endif

#ifdef SET_1280_960_60fps_2lane
#define k_cmd_format k_cmd_format_1280x960_60fpss
static const SensCmd k_cmd_format_1280x960_60fpss[] = {
	{ 0x3029, 0x00 }, { 0x302a, 0x00 }, { 0x3300, 0x01 }, { 0x3401, 0x01 }, { 0x3422, 0xBF }, { 0x3460, 0x03 },
	{ 0x3440, 0x03 }, { 0x3442, 0x00 }, { 0x3806, 0x01 }, { 0x3908, 0x4b }, { 0x3909, 0x00 }, { 0x3158, 0x01 },
	{ 0x3159, 0x01 }, { 0x315a, 0x01 }, { 0x315b, 0x01 }, { 0x3148, 0x64 }, { 0x3670, 0x00 }, { 0x3679, 0x02 },
	{ 0x35b3, 0x15 }, { 0x320e, 0x02 }, { 0x3804, 0x10 }, { 0x35a1, 0x06 }, { 0x35a8, 0x06 }, { 0x35a9, 0x06 },
	{ 0x35aa, 0x06 }, { 0x35ab, 0x06 }, { 0x35ac, 0x06 }, { 0x35ad, 0x06 }, { 0x35ae, 0x07 }, { 0x35af, 0x07 },
	{ 0x333b, 0x01 }, { 0x3339, 0x00 }, { 0x3031, 0x00 }, { 0x3118, 0x01 }, { 0x3119, 0x06 }, { 0x3330, 0x00 },
	{ 0x3030, 0x01 }, { 0x3020, 0x60 }, { 0x3021, 0x09 }, //vts = 1200
	{ 0x3024, 0x8A }, { 0x3025, 0x02 }, //hts = 2600
	{ 0x3038, 0xB2 }, { 0x3039, 0x01 }, { 0x303a, 0x00 }, { 0x303b, 0x05 }, { 0x3034, 0x44 }, { 0x3035, 0x00 },
	{ 0x3036, 0xC0 }, { 0x3037, 0x03 }, { 0x3908, 0x4E }, { 0x390a, 0x02 }, { 0x3400, 0x11 }, { 0x3141, 0x01 }
};
#endif

static const SensCmd k_cmd_start[] = {
	{ 0x3000, 0x00 },
};

static const SensCmd k_cmd_stop[] = {
	{ 0x3000, 0x01 },
};

static void SENSOR_configInitSeq(uint8_t path_idx)
{
	int fd = g_i2c_fd[path_idx];
	SENSOR_writeSeqWaddrBdata(fd, sizeof(k_cmd_format) / sizeof(SensCmd), k_cmd_format, k_i2c_slave_addr[path_idx]);

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

	p->mipi.vc_bmp = 0x1;
	p->mipi.dt_bmp = 0x0;
	p->mipi.t_hs_settle = 0xA;
	p->mipi.t_hs_settle_ns = T_HS_SETTLE_NS;
	p->mipi.t_d_term_en_ns = T_D_TERM_EN_NS;
	p->mipi.t_clk_settle_ns = T_CLK_SETTLE_NS;
	p->mipi.t_clk_term_en_ns = T_CLK_TERM_EN_NS;

	return MPI_SUCCESS;
}
