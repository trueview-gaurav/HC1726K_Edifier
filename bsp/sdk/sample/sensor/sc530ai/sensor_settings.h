#ifndef SENSOR_SETTINGS_H_
#define SENSOR_SETTINGS_H_

#include "sensor_params.h"

#if SET_2880_1624_30fps_2lane
#define LVDS_LANE_NUM (2)
#define SENSOR_WIDTH (2880)
#define SENSOR_HEIGHT (1624)
#define SENSOR_FPS (30)
#define INIT_FRAME_LINE (1650)
#define INIT_LINE_LEN (3200)
#define MAX_FPS (30)
#define MIN_FPS (5)
#define T_HS_SETTLE_NS (91)
#define T_D_TERM_EN_NS (14)
#define T_CLK_SETTLE_NS (135)
#define T_CLK_TERM_EN_NS (14)
#endif

#if SET_1920_1080_60fps_2lane
#define LVDS_LANE_NUM (2)
#define SENSOR_WIDTH (1920)
#define SENSOR_HEIGHT (1080)
#define SENSOR_FPS (60)
#define INIT_FRAME_LINE (1200) // {0x320E,0x320F} = 0x4B0 = 1200
#define INIT_LINE_LEN (2200) // {0x320C,0x320D} = 0x898 = 2200
#define MAX_FPS (60)
#define MIN_FPS (5)
#define T_HS_SETTLE_NS (125)
#define T_D_TERM_EN_NS (39) // real timming is 53ns
#define T_CLK_SETTLE_NS (204)
#define T_CLK_TERM_EN_NS (38) // real timming is 58ns
#endif

#define PCLK ((uint64_t)SENSOR_FPS * INIT_FRAME_LINE * INIT_LINE_LEN)
#define SENSOR_FRAME_LINES_MAX ((uint64_t)INIT_FRAME_LINE * SENSOR_FPS / MIN_FPS)
#define SENSOR_FRAME_LINES_MIN ((uint64_t)INIT_FRAME_LINE * SENSOR_FPS / MAX_FPS)
//#define SENSOR_GAIN_MAX (10282) // 321x, including analog and digital
#define SENSOR_GAIN_MAX (2248) // only analog gain
#define SENSOR_GAIN_MIN (32)

typedef enum {
	IDX_VMAX_1,
	IDX_VMAX_2,
	IDX_SHS_1,
	IDX_SHS_2,
	IDX_SHS_3,
	IDX_AC,
	IDX_DC,
	IDX_DF,
	IDX_NUM,
} I2C_DATA_IDX_E;

#endif /* SENSOR_SETTINGS_H_ */
