#ifndef SENSOR_SETTINGS_H_
#define SENSOR_SETTINGS_H_

#include "sensor_params.h"

#define LVDS_LANE_NUM (2)
#define SENSOR_WIDTH (2688)
#define SENSOR_HEIGHT (1520)
#define SENSOR_FPS (30)
#define INIT_FRAME_LINE (1600) // 0x23/0x22 => 0x640 = 1600
#define INIT_LINE_LEN (3000) // 0x21/0x20 => 0x2EE = 750,  750*4=3000
#define MAX_FPS (30)
#define MIN_FPS (5)
#define T_HS_SETTLE_NS (148) //  [85, 155] real value : 148ns
#define T_D_TERM_EN_NS (39) //   [0, 39]   real value : 86ns
#define T_CLK_SETTLE_NS (238) // [95, 300] real value : 238ns
#define T_CLK_TERM_EN_NS (38) // [0, 38]   real value : 70ns

#define PCLK (SENSOR_FPS * INIT_FRAME_LINE * INIT_LINE_LEN)
#define SENSOR_FRAME_LINES_MAX (INIT_FRAME_LINE * SENSOR_FPS / MIN_FPS)
#define SENSOR_FRAME_LINES_MIN (INIT_FRAME_LINE * SENSOR_FPS / MAX_FPS)

#define SENSOR_MIN_GAIN (32)
#define SENSOR_MAX_GAIN (496) // MAX:2031616

#define EXP_LINE_GAP (1) // should be 0 but let's give it some time to reset properly
#define SENSOR_EXP_LINES_MAX (SENSOR_FRAME_LINES_MAX - EXP_LINE_GAP)
#define SENSOR_EXP_LINES_MIN (1) // should be tested if 1 line doesn't have a proper IQ
#define SENSOR_EXP_LINE_SHIF (0) // Sensor Datasheet spec 2.2.2 AEC step size : 1 step size = 0 or 0.5 step size = 1

#define ROW_TIME_PRC (5)
#define ROW_TIME_UNIT (1 << ROW_TIME_PRC)
#define FPS_PRC (16)
#define FPS_UNIT (1 << FPS_PRC)
#endif /* SENSOR_SETTINGS_H_ */
