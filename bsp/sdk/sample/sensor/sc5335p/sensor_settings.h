#ifndef SENSOR_SETTINGS_H_
#define SENSOR_SETTINGS_H_

#include "sensor_params.h"

#ifdef SET_2592_1944_20fps_2lane

#define LVDS_LANE_NUM (2)
#define SENSOR_WIDTH (2592)
#define SENSOR_HEIGHT (1944)
#define SENSOR_FPS (20)
#define INIT_FRAME_LINE (1980)
#define INIT_LINE_LEN (3000)
#define MAX_FPS (20)
#define MIN_FPS (5)
#define T_HS_SETTLE_NS (91)
#define T_D_TERM_EN_NS (14)
#define T_CLK_SETTLE_NS (135)
#define T_CLK_TERM_EN_NS (14)

#elif defined SET_2592_1944_25fps_2lane

#define LVDS_LANE_NUM (2)
#define SENSOR_WIDTH (2592)
#define SENSOR_HEIGHT (1944)
#define SENSOR_FPS (25)
#define INIT_FRAME_LINE (2000)
#define INIT_LINE_LEN (2880)
#define MAX_FPS (25)
#define MIN_FPS (5)
#define T_HS_SETTLE_NS (91)
#define T_D_TERM_EN_NS (14)
#define T_CLK_SETTLE_NS (135)
#define T_CLK_TERM_EN_NS (14)

#elif defined SET_2592_1944_30fps_2lane

#define LVDS_LANE_NUM (2)
#define SENSOR_WIDTH (2592)
#define SENSOR_HEIGHT (1944)
#define SENSOR_FPS (30)
#define INIT_FRAME_LINE (2000)
#define INIT_LINE_LEN (3000)
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
#define SENSOR_MAX_GAIN (7938)

#define ROW_TIME_PRC (6)
#define ROW_TIME_UNIT (1 << ROW_TIME_PRC)
#define FPS_PRC (14)
#define FPS_UNIT (1 << FPS_PRC)

typedef enum {
	IDX_VMAX_1,
	IDX_VMAX_2,
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
