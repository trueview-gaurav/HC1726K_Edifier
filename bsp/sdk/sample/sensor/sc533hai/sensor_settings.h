#ifndef SENSOR_SETTINGS_H_
#define SENSOR_SETTINGS_H_

#include "sensor_params.h"


#define LVDS_LANE_NUM (2)
#define SENSOR_WIDTH (2944)
#define SENSOR_HEIGHT (1664)
#define SENSOR_FPS (30)
#define INIT_FRAME_LINE (1800)
#define INIT_LINE_LEN (3200)
#define MAX_FPS (30)
#define MIN_FPS (5)
#define T_HS_SETTLE_NS (91)
#define T_D_TERM_EN_NS (14)
#define T_CLK_SETTLE_NS (135)
#define T_CLK_TERM_EN_NS (14)

#define PCLK ((uint64_t)SENSOR_FPS * INIT_FRAME_LINE * INIT_LINE_LEN)
#define SENSOR_FRAME_LINES_MAX ((uint64_t)INIT_FRAME_LINE * SENSOR_FPS / MIN_FPS)
#define SENSOR_FRAME_LINES_MIN ((uint64_t)INIT_FRAME_LINE * SENSOR_FPS / MAX_FPS)
//#define SENSOR_GAIN_MAX (10282) // 321x, including analog and digital
#define SENSOR_GAIN_MAX (2681) //83.79x only analog gain
#define SENSOR_GAIN_MIN (32)

typedef enum {
	IDX_VMAX_1,
	IDX_VMAX_2,
	IDX_VMAX_3,
	IDX_SHS_1,
	IDX_SHS_2,
	IDX_SHS_3,
	IDX_AC,
	IDX_AF,
	IDX_DC,
	IDX_DF,
	IDX_NUM,
} I2C_DATA_IDX_E;

#endif /* SENSOR_SETTINGS_H_ */
