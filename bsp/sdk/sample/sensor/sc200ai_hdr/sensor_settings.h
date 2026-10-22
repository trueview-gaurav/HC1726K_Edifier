#ifndef SENSOR_SETTINGS_H_
#define SENSOR_SETTINGS_H_

#include "sensor_params.h"

#ifdef SET_1920_1080_30fps_2lane_HDR

#define LVDS_LANE_NUM (2)
#define SENSOR_WIDTH (1920)
#define SENSOR_HEIGHT (1080)
#define SENSOR_FPS (30)
#define INIT_FRAME_LINE (2400)
#define INIT_LINE_LEN (2200)
#define MAX_FPS (30)
#define MIN_FPS (5)
#define T_HS_SETTLE_NS (91)
#define T_D_TERM_EN_NS (14)
#define T_CLK_SETTLE_NS (135)
#define T_CLK_TERM_EN_NS (14)

#define HDR_IMAGE_NUM (2)
#define HDR_BLANK_LINE (72)
#define HDR_HEIGHT ((SENSOR_HEIGHT + HDR_BLANK_LINE) * HDR_IMAGE_NUM) // actual lines of the image in HDR mode

#endif

#ifdef SET_1920_1080_5fps_2lane_VC

#define LVDS_LANE_NUM (2)
#define SENSOR_WIDTH (1920)
#define SENSOR_HEIGHT (1080)
#define SENSOR_FPS (5)
#define INIT_FRAME_LINE (3600)
#define INIT_LINE_LEN (2200)
#define MAX_FPS (5)
#define MIN_FPS (2)
#define T_HS_SETTLE_NS (91)
#define T_D_TERM_EN_NS (14)
#define T_CLK_SETTLE_NS (135)
#define T_CLK_TERM_EN_NS (14)

#define HDR_MODE (MPI_HDR_MODE_VIRTUAL_CHN)
#define HDR_IMAGE_NUM (2)
#define HDR_BLANK_LINE (216)
#define HDR_HEIGHT ((SENSOR_HEIGHT + HDR_BLANK_LINE) * HDR_IMAGE_NUM) // actual lines of the image in HDR mode
#define VIRTUAL_CHANNEL_ENABLE

#endif

#define PCLK ((uint64_t)SENSOR_FPS * INIT_FRAME_LINE * INIT_LINE_LEN)
#define SENSOR_FRAME_LINES_MAX (INIT_FRAME_LINE * SENSOR_FPS / MIN_FPS)
#define SENSOR_FRAME_LINES_MIN (INIT_FRAME_LINE * SENSOR_FPS / MAX_FPS)
// #define SENSOR_GAIN_MAX (54816) // 1713x, including analog and digital
#define SENSOR_GAIN_MAX (16383) // soft limit of AE, will be increased in future
#define SENSOR_GAIN_MIN (32)

#define ROW_TIME_PRC (6)
#define ROW_TIME_UNIT (1 << ROW_TIME_PRC)
#define FPS_PRC (14)
#define FPS_UNIT (1 << FPS_PRC)

typedef enum {
	IDX_VMAX_1,
	IDX_VMAX_2,
	IDX_L_SHS_1,
	IDX_L_SHS_2,
	IDX_L_SHS_3,
	IDX_L_AC,
	IDX_L_AF,
	IDX_L_DC,
	IDX_L_DF,
	IDX_S_SHS_1,
	IDX_S_SHS_2,
	IDX_S_SHS_3,
	IDX_S_AC,
	IDX_S_AF,
	IDX_S_DC,
	IDX_S_DF,
	IDX_LOGIC_1,
	IDX_NUM,
} I2C_DATA_IDX_E;


#endif /* SENSOR_SETTINGS_H_ */
