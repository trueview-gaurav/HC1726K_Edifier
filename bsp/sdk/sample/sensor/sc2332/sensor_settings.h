#ifndef SENSOR_SETTINGS_H_
#define SENSOR_SETTINGS_H_

#include "sensor_params.h"

#define SENSOR_WIDTH           (1920)
#define SENSOR_HEIGHT          (1080)
#define SENSOR_FPS             (30)
#define INIT_FRAME_LINE        (1125)
#define INIT_LINE_LEN          (2200)
#define T_HS_SETTLE_NS (91)
#define T_D_TERM_EN_NS (14)
#define T_CLK_SETTLE_NS (135)
#define T_CLK_TERM_EN_NS (14)

#define PCLK                   (INIT_LINE_LEN * INIT_FRAME_LINE * SENSOR_FPS)
#define SENSOR_FRAME_LINES_MAX (6750) // min fps = 5
#define SENSOR_FRAME_LINES_MIN (1125) // fps = 25
#define SENSOR_MAX_GAIN        (504) // 5 bit, only use a_gian 15.75x

#define ROW_TIME_PRC (5)
#define ROW_TIME_UNIT (1 << ROW_TIME_PRC)
#define FPS_PRC (6)
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
	IDX_UPDATE_1,
	IDX_LOGIC_1,
	IDX_LOGIC_2,
	IDX_LOGIC_3,
	IDX_UPDATE_2,
	IDX_NUM,
} I2C_DATA_IDX_E;

#endif /* SENSOR_SETTINGS_H_ */
