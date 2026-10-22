#ifndef SENSOR_SETTINGS_H_
#define SENSOR_SETTINGS_H_

#include "sensor_params.h"

#if defined SET_4096_3072_5fps_2lane

#define LVDS_LANE_NUM (2)
#define SENSOR_WIDTH (4096)
#define SENSOR_HEIGHT (3072)
#define SENSOR_FPS (5)
#define INIT_FRAME_LINE (3334)
#define INIT_LINE_LEN (3600) // 3600 in initial sequence, should be 3600 * 2 lane = 7200 in real
#define MAX_FPS (5)
#define MIN_FPS (2)
#define T_HS_SETTLE_NS (91)
#define T_D_TERM_EN_NS (14)
#define T_CLK_SETTLE_NS (135)
#define T_CLK_TERM_EN_NS (14)

#elif defined SET_1920_1080_30fps_4lane

// this part might be fixed someday if needed
#define LVDS_LANE_NUM (4)
#define SENSOR_WIDTH (1920)
#define SENSOR_HEIGHT (1080)
#define SENSOR_FPS (30)
#define INIT_FRAME_LINE ()
#define INIT_LINE_LEN ()
#define PCLK (INIT_LINE_LEN * INIT_FRAME_LINE * SENSOR_FPS)
#define MAX_FPS (30)
#define MIN_FPS (5)
#define T_HS_SETTLE_NS (91)
#define T_D_TERM_EN_NS (14)
#define T_CLK_SETTLE_NS (135)
#define T_CLK_TERM_EN_NS (14)

#endif

#define PCLK (INIT_LINE_LEN * INIT_FRAME_LINE * SENSOR_FPS)
#define SENSOR_FRAME_LINES_MAX (INIT_FRAME_LINE * SENSOR_FPS / MIN_FPS)
#define SENSOR_FRAME_LINES_MIN (INIT_FRAME_LINE * SENSOR_FPS / MAX_FPS)
#define SENSOR_MAX_GAIN (512)

#define ROW_TIME_PRC (8)
#define ROW_TIME_UNIT (1 << ROW_TIME_PRC)
#define FPS_PRC (15)
#define FPS_UNIT (1 << FPS_PRC)

typedef enum {
	IDX_VTS_1,
	IDX_VTS_2,
	IDX_EXPO_1,
	IDX_EXPO_2,
	IDX_GAIN_S,
	IDX_GAIN_1,
	IDX_GAIN_2,
	IDX_NUM,
} I2C_DATA_IDX_E;

#endif /* SENSOR_SETTINGS_H_ */
