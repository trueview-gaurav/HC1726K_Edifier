#ifndef SENSOR_SETTINGS_H_
#define SENSOR_SETTINGS_H_

#include "sensor_params.h"

#if SET_3840_2160_20fps_2lane
#define LVDS_LANE_NUM (2)
#define SENSOR_WIDTH (3840)
#define SENSOR_HEIGHT (2160)
#define SENSOR_FPS (20)
#define INIT_FRAME_LINE (2250) // 0x8CA
#define INIT_LINE_LEN (4200) // 0x834 = 2100, 2100*2 = 4200
#define MIN_FPS (5)
#define MAX_FPS (20)
#define T_HS_SETTLE_NS (126)
#define T_D_TERM_EN_NS (50)
#define T_CLK_SETTLE_NS (194)
#define T_CLK_TERM_EN_NS (52)
#endif

#if SET_3840_2160_40fps_4lane
#define LVDS_LANE_NUM (4)
#define SENSOR_WIDTH (3840)
#define SENSOR_HEIGHT (2160)
#define SENSOR_FPS (40)
#define INIT_FRAME_LINE (2250) // 0x8CA
#define INIT_LINE_LEN (4200) // 0x834 = 2100, 2100*2 = 4200
#define MIN_FPS (5)
#define MAX_FPS (40)
#define T_HS_SETTLE_NS (126)
#define T_D_TERM_EN_NS (50)
#define T_CLK_SETTLE_NS (194)
#define T_CLK_TERM_EN_NS (52)
#endif

#define PCLK (INIT_LINE_LEN * INIT_FRAME_LINE * SENSOR_FPS)
#define SENSOR_FRAME_LINES_MAX (INIT_FRAME_LINE * SENSOR_FPS / MIN_FPS)
#define SENSOR_FRAME_LINES_MIN (INIT_FRAME_LINE * SENSOR_FPS / MAX_FPS)
#define SENSOR_GAIN_MAX (4032) // spec 2.3.3  A gain max 32x. D gain max 3.938x. 32*32*3.983=4032
#define SENSOR_GAIN_MIN (32) // 32 is 1.0x

#endif /* SENSOR_SETTINGS_H_ */
