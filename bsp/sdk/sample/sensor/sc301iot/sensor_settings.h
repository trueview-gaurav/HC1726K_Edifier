#ifndef SENSOR_SETTINGS_H_
#define SENSOR_SETTINGS_H_

#include "sensor_params.h"

#if SET_2048_1536_30fps_1lane

#define LVDS_LANE_NUM (1)
#define SENSOR_WIDTH (2048)
#define SENSOR_HEIGHT (1536)
#define SENSOR_FPS (30)
#define INIT_FRAME_LINE (1600) // 0x320E/0x320F => default:0x640 = 1600
#define INIT_LINE_LEN (2250) // 0x320C/0x320D => 0x465 = 1125 * 2 = 2250
#define SENSOR_FPS_MAX (30)
#define SENSOR_FPS_MIN (5)
#define T_HS_SETTLE_NS (132) //  [85, 155] real value : 132ns
#define T_D_TERM_EN_NS (39) //   [0, 39]   real value : 53.5ns
#define T_CLK_SETTLE_NS (200) // [95, 300] real value : 200ns
#define T_CLK_TERM_EN_NS (38) // [0, 38]   real value : 53ns

#endif

#if SET_2048_1536_30fps_2lane

#define LVDS_LANE_NUM (2)
#define SENSOR_WIDTH (2048)
#define SENSOR_HEIGHT (1536)
#define SENSOR_FPS (30)
#define INIT_FRAME_LINE (1600) // 0x320E/0x320F => default:0x640 = 1600
#define INIT_LINE_LEN (2250) // 0x320C/0x320D => 0x465 = 1125 * 2 = 2250
#define SENSOR_FPS_MAX (30)
#define SENSOR_FPS_MIN (5)
#define T_HS_SETTLE_NS (155) //  [85, 155] real value : 167.5ns
#define T_D_TERM_EN_NS (39) //   [0, 39]   real value : 66.5ns
#define T_CLK_SETTLE_NS (206) // [95, 300] real value : 206.6ns
#define T_CLK_TERM_EN_NS (38) // [0, 38]   real value : 50ns

#endif

#if SET_2048_1536_1fps_2lane

#define LVDS_LANE_NUM (2)
#define SENSOR_WIDTH (2048)
#define SENSOR_HEIGHT (1536)
#define SENSOR_FPS (1)
#define INIT_FRAME_LINE (24000) // 0x320E/0x320F => default:0x5DC0 = 24000
#define INIT_LINE_LEN (2250) // 0x320C/0x320D => 0x465 = 1125 * 2 = 2250
#define SENSOR_FPS_MAX (1)
#define SENSOR_FPS_MIN (1)
#define T_HS_SETTLE_NS (155) //  [85, 155] real value : 208ns
#define T_D_TERM_EN_NS (39) //   [0, 39]   real value : 67ns
#define T_CLK_SETTLE_NS (257) // [95, 300] real value : 257ns
#define T_CLK_TERM_EN_NS (38) // [0, 38]   real value : 68ns

#endif

#if SET_768_768_120fps_2lane

#define LVDS_LANE_NUM (2)
#define SENSOR_WIDTH (768)
#define SENSOR_HEIGHT (768)
#define SENSOR_FPS (120)
#define INIT_FRAME_LINE (786) // {0x320E,0x320F} = 0x312 = 786
#define INIT_LINE_LEN (1060) // {0x320C,0x320D} = 0x424 = 1060
#define SENSOR_FPS_MAX (120)
#define SENSOR_FPS_MIN (5)
#define T_HS_SETTLE_NS (155) //  [85, 155] real value : 167.5ns
#define T_D_TERM_EN_NS (39) //   [0, 39]   real value : 66.5ns
#define T_CLK_SETTLE_NS (206) // [95, 300] real value : 206.6ns
#define T_CLK_TERM_EN_NS (38) // [0, 38]   real value : 50ns

#endif

#define PCLK ((uint64_t)SENSOR_FPS * INIT_FRAME_LINE * INIT_LINE_LEN)
#define SENSOR_FRAME_LINES_MAX (INIT_FRAME_LINE * SENSOR_FPS / SENSOR_FPS_MIN)
#define SENSOR_FRAME_LINES_MIN (INIT_FRAME_LINE * SENSOR_FPS / SENSOR_FPS_MAX)
#define SENSOR_GAIN_MAX (16383) // 1713x, including analog and digital
#define SENSOR_GAIN_MIN (32)

#endif /* SENSOR_SETTINGS_H_ */
