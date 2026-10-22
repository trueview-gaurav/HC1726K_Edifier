#ifndef SENSOR_SETTINGS_H_
#define SENSOR_SETTINGS_H_

#include "sensor_params.h"

#define LVDS_LANE_NUM (2)
#define SENSOR_WIDTH (1920)
#define SENSOR_HEIGHT (1080)
#define SENSOR_FPS (60)
#define INIT_FRAME_LINE (1200) // 0x23/0x22 = 0x4B0 = 1200
#define INIT_LINE_LEN (2400) // 0x21/0x20 = 0x258 = 600,  600*4 = 2400
#define MAX_FPS (60)
#define MIN_FPS (5)
#define T_HS_SETTLE_NS (142)
#define T_D_TERM_EN_NS (39) // real MIPI timming is 78 ns
#define T_CLK_SETTLE_NS (142)
#define T_CLK_TERM_EN_NS (38)

#define PCLK (SENSOR_FPS * INIT_FRAME_LINE * INIT_LINE_LEN)
#define SENSOR_FRAME_LINES_MAX (INIT_FRAME_LINE * SENSOR_FPS / MIN_FPS)
#define SENSOR_FRAME_LINES_MIN (INIT_FRAME_LINE * SENSOR_FPS / MAX_FPS)

#define SENSOR_MIN_GAIN (32)
#define SENSOR_MAX_GAIN (992)

#define ROW_TIME_PRC (8)
#define ROW_TIME_UNIT (1 << ROW_TIME_PRC)
#define FPS_PRC (15)
#define FPS_UNIT (1 << FPS_PRC)

typedef enum {
	IDX_VMAX_1,
	IDX_VMAX_2,
	IDX_SHS_1,
	IDX_SHS_2,
	IDX_GAIN,
	IDX_NUM,
} I2C_DATA_IDX_E;

#endif /* SENSOR_SETTINGS_H_ */
