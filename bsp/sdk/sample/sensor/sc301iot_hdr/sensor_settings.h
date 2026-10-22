#ifndef SENSOR_SETTINGS_H_
#define SENSOR_SETTINGS_H_

#include "sensor_params.h"

#if SET_2048_1536_20fps_2lane_SHDR
#define LVDS_LANE_NUM (2)
#define SENSOR_WIDTH (2048)
#define SENSOR_HEIGHT (1536)
#define SENSOR_FPS (20)
#define INIT_FRAME_LINE (3200) // 0x320E/0x320F => default:0xc80 = 3200
#define INIT_LINE_LEN (2250) // 0x320C/0x320D => 0x465 = 1125 * 2 = 2250
#define SENSOR_FPS_MAX (20)
#define SENSOR_FPS_MIN (5)
#define T_HS_SETTLE_NS (132) //  [85, 155] real value : 132ns
#define T_D_TERM_EN_NS (39) //   [0, 39]   real value : 53.5ns
#define T_CLK_SETTLE_NS (200) // [95, 300] real value : 200ns
#define T_CLK_TERM_EN_NS (38) // [0, 38]   real value : 53ns
#define HDR_MODE MPI_HDR_MODE_LINE_COLOC
#define HDR_IMAGE_NUM (2)
#define HDR_BLANK_LINE (56)
#define HDR_HEIGHT (SENSOR_HEIGHT * HDR_IMAGE_NUM) // actual lines of the image in HDR mode
#endif

#if SET_2048_1536_30fps_2lane_SHDR
#define LVDS_LANE_NUM (2)
#define SENSOR_WIDTH (2048)
#define SENSOR_HEIGHT (1536)
#define SENSOR_FPS (30)
#define INIT_FRAME_LINE (3200) // 0x320E/0x320F => default:0xc80 = 3200
#define INIT_LINE_LEN (2250) // 0x320C/0x320D => 0x465 = 1125 * 2 = 2250
#define SENSOR_FPS_MAX (30)
#define SENSOR_FPS_MIN (5)
#define T_HS_SETTLE_NS (120) //  [85, 155] real value : 120ns
#define T_D_TERM_EN_NS (39) //   [0, 39]   real value : 45ns
#define T_CLK_SETTLE_NS (196) // [95, 300] real value : 196ns
#define T_CLK_TERM_EN_NS (38) // [0, 38]   real value : 46ns
#define HDR_MODE MPI_HDR_MODE_LINE_COLOC
#define HDR_IMAGE_NUM (2)
#define HDR_BLANK_LINE (49)
#define HDR_HEIGHT (SENSOR_HEIGHT * HDR_IMAGE_NUM) // actual lines of the image in HDR mode

#endif

#define PCLK ((uint64_t)SENSOR_FPS * INIT_FRAME_LINE * INIT_LINE_LEN)
#define SENSOR_FRAME_LINES_MAX (INIT_FRAME_LINE * SENSOR_FPS / SENSOR_FPS_MIN)
#define SENSOR_FRAME_LINES_MIN (INIT_FRAME_LINE * SENSOR_FPS / SENSOR_FPS_MAX)
#define SENSOR_GAIN_MAX (16383) // 1713x, including analog and digital
#define SENSOR_GAIN_MIN (32)

#endif /* SENSOR_SETTINGS_H_ */
