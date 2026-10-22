#ifndef SENSOR_SETTINGS_H_
#define SENSOR_SETTINGS_H_

// SET_1920_1080_30FPS_2LANE
#define LVDS_LANE_NUM (2)
#define SENSOR_WIDTH (1920)
#define SENSOR_HEIGHT (1080)
#define SENSOR_FPS (30)
#define MAX_FPS (30)
#define MIN_FPS (5)
#define INIT_FRAME_LINE (1125)
#define INIT_LINE_LEN (2200)
#define T_HS_SETTLE_NS (91)
#define T_D_TERM_EN_NS (14)
#define T_CLK_SETTLE_NS (135)
#define T_CLK_TERM_EN_NS (14)

#define PCLK (INIT_LINE_LEN * INIT_FRAME_LINE * SENSOR_FPS)
#define SENSOR_FRAME_LINES_MAX (INIT_FRAME_LINE * SENSOR_FPS / MIN_FPS)
#define SENSOR_FRAME_LINES_MIN (INIT_FRAME_LINE * SENSOR_FPS / MAX_FPS)
#define SENSOR_MAX_GAIN (504) // 5 bit, only use a_gian 15.75x
#define SENSOR_MAX_GAIN_ANA (508) // hardware limit of analog gain
#define SENSOR_MAX_GAIN_HARD (16129) // hardware limit of total gain

#define ROW_TIME_PRC (8)
#define ROW_TIME_UNIT (1 << ROW_TIME_PRC)
#define FPS_PRC (15)
#define FPS_UNIT (1 << FPS_PRC)

typedef enum {
	IDX_VMAX_1,
	IDX_VMAX_2,
	IDX_SHS_1,
	IDX_SHS_2,
	IDX_SHS_3,
	IDX_AC,
	IDX_AF,
	IDX_DC,
	IDX_DF,
	IDX_GROUP_START,
	IDX_LOGIC_1,
	IDX_GROUP_END,
	IDX_NUM,
} I2C_DATA_IDX_E;


#endif /* SENSOR_SETTINGS_H_ */
