#ifndef SENSOR_SETTINGS_H_
#define SENSOR_SETTINGS_H_

#include "sensor_params.h"

#ifdef SET_1980_1080_30FPS_2LANE

#define LVDS_LANE_NUM (2)
#define SENSOR_WIDTH (1980)
#define SENSOR_HEIGHT (1080)
#define SENSOR_FPS (30)
#define INIT_FRAME_LINE (1125)
// #define INIT_LINE_LEN (4400) // original value
#define INIT_LINE_LEN (4512) // adjusted value since our MCLK is 38.07MHz
#define MAX_FPS (30)
#define MIN_FPS (5)
#define T_HS_SETTLE_NS (91)
#define T_D_TERM_EN_NS (14)
#define T_CLK_SETTLE_NS (135)
#define T_CLK_TERM_EN_NS (14)

#endif

#define PCLK (SENSOR_FPS * INIT_FRAME_LINE * INIT_LINE_LEN)
#define SENSOR_FRAME_LINES_MAX (INIT_FRAME_LINE * SENSOR_FPS / MIN_FPS)
#define SENSOR_FRAME_LINES_MIN (INIT_FRAME_LINE * SENSOR_FPS / MAX_FPS)
// #define SENSOR_MAX_GAIN (127394) // hard limit, not suggested
#define SENSOR_MAX_GAIN (1012) // soft limit, only use the analog gain

#define ROW_TIME_PRC (8)
#define ROW_TIME_UNIT (1 << ROW_TIME_PRC)
#define FPS_PRC (15)
#define FPS_UNIT (1 << FPS_PRC)

typedef enum {
	IDX_VMAX_1,
	IDX_VMAX_2,
	IDX_VMAX_3,
	IDX_SHS_1,
	IDX_SHS_2,
	IDX_SHS_3,
	IDX_GAIN_1,
	IDX_GAIN_2,
	IDX_NUM,
} I2C_DATA_IDX_E;

#endif /* SENSOR_SETTINGS_H_ */
