#ifndef SENSOR_SETTINGS_H_
#define SENSOR_SETTINGS_H_

#include "sensor_params.h"

#ifdef SET_1920_1080_30fps_2lane

#define LVDS_LANE_NUM (2)
#define SENSOR_WIDTH (1920) // Sensor Datasheet image width active pixels
#define SENSOR_HEIGHT (1080) // Sensor Datasheet image height active pixels
#define SENSOR_FPS (30) // Sensor Datasheet FPS Max
#define INIT_FRAME_LINE (1130) // Sensor Register 0x320e & 0x320f, VTS , FrameH, VMAX
#define INIT_LINE_LEN (2124) // Sensor Register 0x320c & 0x320d, HTS , FrameW, LINE width
#define MAX_FPS (30)
#define MIN_FPS (5)

#define T_HS_SETTLE_NS (155) // [85, 155]
#define T_D_TERM_EN_NS (39) // [0, 39]
#define T_CLK_SETTLE_NS (190) // [95, 300]
#define T_CLK_TERM_EN_NS (30) // [0, 38]

#endif

#ifdef SET_1920_1080_15fps_2lane_PSEUDO_MASTER
#define LVDS_LANE_NUM (2)
#define SENSOR_WIDTH (1920)
#define SENSOR_HEIGHT (1080)
#define SENSOR_FPS (15)
#define INIT_FRAME_LINE (2453)
#define INIT_LINE_LEN (2200)
#define MAX_FPS (30)
#define MIN_FPS (5)
#define T_HS_SETTLE_NS (91)
#define T_D_TERM_EN_NS (14)
#define T_CLK_SETTLE_NS (135)
#define T_CLK_TERM_EN_NS (14)
#endif

#ifdef SET_1920_1080_15fps_2lane_PSEUDO_SLAVE
#define LVDS_LANE_NUM (2)
#define SENSOR_WIDTH (1920)
#define SENSOR_HEIGHT (1080)
#define SENSOR_FPS (15)
#define INIT_FRAME_LINE (2453)
#define INIT_LINE_LEN (2200)
#define MAX_FPS (30)
#define MIN_FPS (5)
#define T_HS_SETTLE_NS (91)
#define T_D_TERM_EN_NS (14)
#define T_CLK_SETTLE_NS (135)
#define T_CLK_TERM_EN_NS (14)
#define SNS_SLAVE_MODE
#endif

#ifdef SET_1920_1080_20fps_2lane
#define LVDS_LANE_NUM (2)
#define SENSOR_WIDTH (1920)
#define SENSOR_HEIGHT (1080)
#define MAX_FPS (30)
#define MIN_FPS (5)
#define T_HS_SETTLE_NS (155) // [85, 155]
#define T_D_TERM_EN_NS (39) // [0, 39]
#define T_CLK_SETTLE_NS (262) // [95, 300]
#define T_CLK_TERM_EN_NS (38) // [0, 38]
#endif

#ifdef SET_1920_1080_20to10fps_2lane
#define SENSOR_FPS (10)
#define INIT_FRAME_LINE (2500)
#define INIT_LINE_LEN (2208) // 0x320c 0x320d : 0x8a0
#endif

#ifdef SET_1920_1080_20to125fps_2lane
#define SENSOR_FPS (12.5)
#define INIT_FRAME_LINE (2000)
#define INIT_LINE_LEN (2208) // 0x320c 0x320d : 0x8a0
#endif

#define PCLK (uint64_t)(SENSOR_FPS * INIT_FRAME_LINE * INIT_LINE_LEN)
#define SENSOR_FRAME_LINES_MAX (uint64_t)(INIT_FRAME_LINE * SENSOR_FPS / MIN_FPS)
#define SENSOR_FRAME_LINES_MIN (uint64_t)(INIT_FRAME_LINE * SENSOR_FPS / MAX_FPS)
#define SENSOR_GAIN_MAX (4096) // Sensor Datasheet spec 2.3.3 A gain max 32x. D gain max 4x. 32*32*4=4096
#define SENSOR_GAIN_MIN (32) // 32 is 1.0x

#endif /* SENSOR_SETTINGS_H_ */
