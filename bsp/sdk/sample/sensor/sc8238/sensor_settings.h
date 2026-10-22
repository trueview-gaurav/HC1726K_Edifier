#ifndef SENSOR_SETTINGS_H_
#define SENSOR_SETTINGS_H_

#include "sensor_params.h"

#ifdef SET_3840_2160_15fps_2lane

#define SENSOR_WIDTH (3840)
#define SENSOR_HEIGHT (2160)
#define SENSOR_FPS (15)
#define INIT_FRAME_LINE (2250)
#define INIT_LINE_LEN (4160)
#define MIN_FPS (5)
#define MAX_FPS (15)
#define T_HS_SETTLE_NS (91)
#define T_D_TERM_EN_NS (14)
#define T_CLK_SETTLE_NS (135)
#define T_CLK_TERM_EN_NS (14)

#endif

#ifdef SET_3840_2160_30fps_2lane

#define SENSOR_WIDTH (3840)
#define SENSOR_HEIGHT (2160)
#define SENSOR_FPS (30)
#define INIT_FRAME_LINE (2250)
#define INIT_LINE_LEN (4160)
#define MIN_FPS (5)
#define MAX_FPS (30)
#define T_HS_SETTLE_NS (91)
#define T_D_TERM_EN_NS (14)
#define T_CLK_SETTLE_NS (135)
#define T_CLK_TERM_EN_NS (14)

#endif

#define PCLK (INIT_LINE_LEN * INIT_FRAME_LINE * SENSOR_FPS)
#define SENSOR_MAX_A_GAIN (508) // 5 bit.
#define SENSOR_MIN_GAIN (32) // 5 bit, 1x
#define SENSOR_MAX_GAIN (16002) // 5 bit
#define SENSOR_FRAME_LINES_MAX (INIT_FRAME_LINE * SENSOR_FPS / MIN_FPS) // min fps = 5
#define SENSOR_FRAME_LINES_MIN (INIT_FRAME_LINE * SENSOR_FPS / MAX_FPS) // fps = 15

#define ROW_TIME_PRC (8)
#define ROW_TIME_UNIT (1 << ROW_TIME_PRC)
#define FPS_PRC (15)
#define FPS_UNIT (1 << FPS_PRC)

typedef enum {
	IDX_VMAX_1,
	IDX_VMAX_2,
	IDX_FRAME,
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
