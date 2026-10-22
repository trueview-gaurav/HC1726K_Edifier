#ifndef SENSOR_SETTINGS_H_
#define SENSOR_SETTINGS_H_

#include "sensor_params.h"

#ifdef SET_2592_1944_30fps_2lane

#define LVDS_LANE_NUM (2)
#define SENSOR_WIDTH (2592)
#define SENSOR_HEIGHT (1944)
#define SENSOR_FPS (30)
#define INIT_FRAME_LINE (4500)
#define INIT_LINE_LEN (5500)
#define MAX_FPS (30)
#define MIN_FPS (5)
#define BIT_DEPTH MPI_BITS_10
#define T_HS_SETTLE_NS (91)
#define T_D_TERM_EN_NS (14)
#define T_CLK_SETTLE_NS (135)
#define T_CLK_TERM_EN_NS (14)

#elif defined SET_2592_1944_30fps_4lane

#define LVDS_LANE_NUM (4)
#define SENSOR_WIDTH (2592)
#define SENSOR_HEIGHT (1944)
#define SENSOR_FPS (30)
#define INIT_FRAME_LINE (4500)
#define INIT_LINE_LEN (5500)
#define MAX_FPS (30)
#define MIN_FPS (5)
#define BIT_DEPTH MPI_BITS_12
#define T_HS_SETTLE_NS (91)
#define T_D_TERM_EN_NS (14)
#define T_CLK_SETTLE_NS (135)
#define T_CLK_TERM_EN_NS (14)

#endif

#define PCLK ((uint64_t)SENSOR_FPS * INIT_FRAME_LINE * INIT_LINE_LEN)
#define SENSOR_FRAME_LINES_MAX (INIT_FRAME_LINE * SENSOR_FPS / MIN_FPS)
#define SENSOR_FRAME_LINES_MIN (INIT_FRAME_LINE * SENSOR_FPS / MAX_FPS)
// #define SENSOR_GAIN_MAX (90188) // 2818x, stepping ratio is quite high in later steps
#define SENSOR_GAIN_MAX (16383) // soft limit of AE, will be increased in future
#define SENSOR_GAIN_MIN (32)

#define ROW_TIME_PRC (6)
#define ROW_TIME_UNIT (1 << ROW_TIME_PRC)
#define FPS_PRC (14)
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
