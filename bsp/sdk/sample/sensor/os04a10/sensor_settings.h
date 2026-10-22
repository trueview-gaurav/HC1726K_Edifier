#ifndef SENSOR_SETTINGS_H_
#define SENSOR_SETTINGS_H_

#include "sensor_params.h"

#if SET_2688_1520_30fps_4lane
#define LVDS_LANE_NUM (4)
#define SENSOR_WIDTH (2688)
#define SENSOR_HEIGHT (1520)
#define SENSOR_FPS (30)
#define INIT_FRAME_LINE (1624) // {0x380e,0x380f} = 0x658 = 1624
#define INIT_LINE_LEN (2956) // {0x380c,0x380d} = 0x5c6 = 1478, 1478*2 = 2956
#define SENSOR_FPS_MAX (30)
#define SENSOR_FPS_MIN (5)
#define T_HS_SETTLE_NS (127) // 127.2 ns
#define T_D_TERM_EN_NS (39) // real timming is 56.4 ns
#define T_CLK_SETTLE_NS (135)
#define T_CLK_TERM_EN_NS (14)
#endif
#if SET_2688_1520_30fps_2lane
#define LVDS_LANE_NUM (2)
#define SENSOR_WIDTH (2688)
#define SENSOR_HEIGHT (1520)
#define SENSOR_FPS (30)
#define INIT_FRAME_LINE (1624) // {0x380e,0x380f} = 0x658 = 1624
#define INIT_LINE_LEN (2956) // {0x380c,0x380d} = 0x5c6 = 1478, 1478*2 = 2956
#define SENSOR_FPS_MAX (30)
#define SENSOR_FPS_MIN (5)
#define T_HS_SETTLE_NS (155) // 
#define T_D_TERM_EN_NS (39) // 
#define T_CLK_SETTLE_NS (135)
#define T_CLK_TERM_EN_NS (14)
#endif

#define PCLK (SENSOR_FPS * INIT_FRAME_LINE * INIT_LINE_LEN)
#define SENSOR_FRAME_LINES_MAX (PCLK / INIT_LINE_LEN / SENSOR_FPS_MIN)
#define SENSOR_FRAME_LINES_MIN (PCLK / INIT_LINE_LEN / SENSOR_FPS_MAX)

#define SENSOR_GAIN_MAX (7930) // SENSOR_MIN_GAIN x15.5 x15.9882 = 7930.1875
//#define SENSOR_MAX_AGAIN (496) // SENSOR_MIN_GAIN x15.5 = 496 , fastboot compile will fail
#define SENSOR_GAIN_MIN (32)

#endif /* SENSOR_SETTINGS_H_ */
