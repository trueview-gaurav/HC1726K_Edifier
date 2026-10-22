#ifndef SENSOR_SETTINGS_H_
#define SENSOR_SETTINGS_H_

#include "sensor_params.h"

#ifdef SET_2880_1624_25fps_4lane_SHDR

#define LVDS_LANE_NUM (4)
#define SENSOR_WIDTH (2880)
#define SENSOR_HEIGHT (1624)
#define SENSOR_FPS (25)
#define INIT_FRAME_LINE (4050)
#define INIT_LINE_LEN (3200)
#define MAX_FPS (25)
#define MIN_FPS (5)
#define T_HS_SETTLE_NS (91)
#define T_D_TERM_EN_NS (14)
#define T_CLK_SETTLE_NS (135)
#define T_CLK_TERM_EN_NS (14)

#define HDR_MODE MPI_HDR_MODE_LINE_COLOC
#define HDR_IMAGE_NUM (2)
#define HDR_BLANK_LINE (230)
#define HDR_HEIGHT (SENSOR_HEIGHT * HDR_IMAGE_NUM) // actual lines of the image in HDR mode

#elif defined SET_2560_1440_30fps_4lane_SHDR

#define LVDS_LANE_NUM (4)
#define SENSOR_WIDTH (2560)
#define SENSOR_HEIGHT (1440)
#define SENSOR_FPS (30)
#define INIT_FRAME_LINE (3375)
#define INIT_LINE_LEN (3200)
#define MAX_FPS (30)
#define MIN_FPS (5)
#define T_HS_SETTLE_NS (91)
#define T_D_TERM_EN_NS (14)
#define T_CLK_SETTLE_NS (135)
#define T_CLK_TERM_EN_NS (14)

#define HDR_MODE MPI_HDR_MODE_LINE_COLOC
#define HDR_IMAGE_NUM (2)
#define HDR_BLANK_LINE (102)
#define HDR_HEIGHT (SENSOR_HEIGHT * HDR_IMAGE_NUM) // actual lines of the image in HDR mode

#elif defined SET_2880_1624_15fps_2lane_SHDR

#define LVDS_LANE_NUM (2)
#define SENSOR_WIDTH (2880)
#define SENSOR_HEIGHT (1624)
#define SENSOR_FPS (15)
#define INIT_FRAME_LINE (3500)
#define INIT_LINE_LEN (3200)
#define MAX_FPS (15)
#define MIN_FPS (5)
#define T_HS_SETTLE_NS (91)
#define T_D_TERM_EN_NS (14)
#define T_CLK_SETTLE_NS (135)
#define T_CLK_TERM_EN_NS (14)

#define HDR_MODE MPI_HDR_MODE_LINE_COLOC
#define HDR_IMAGE_NUM (2)
#define HDR_BLANK_LINE (104)
#define HDR_HEIGHT (SENSOR_HEIGHT * HDR_IMAGE_NUM) // actual lines of the image in HDR mode

#else
#error "Invalid sensor define setting!"
#endif

#define PCLK (SENSOR_FPS * INIT_FRAME_LINE * INIT_LINE_LEN)
#define SENSOR_FRAME_LINES_MAX (INIT_FRAME_LINE * SENSOR_FPS / MIN_FPS)
#define SENSOR_FRAME_LINES_MIN (INIT_FRAME_LINE * SENSOR_FPS / MAX_FPS)
#define SENSOR_GAIN_MAX (16383) // 1713x, including analog and digital
#define SENSOR_GAIN_MIN (32)

#define ROW_TIME_PRC (6)
#define ROW_TIME_UNIT (1 << ROW_TIME_PRC)
#define FPS_PRC (14)
#define FPS_UNIT (1 << FPS_PRC)

typedef enum {
	IDX_VMAX_1,
	IDX_VMAX_2,
	IDX_L_SHS_1,
	IDX_L_SHS_2,
	IDX_L_SHS_3,
	IDX_S_SHS_2,
	IDX_S_SHS_3,
	IDX_L_DC,
	IDX_L_DF,
	IDX_L_AC,
	IDX_L_AF,
	IDX_S_DC,
	IDX_S_DF,
	IDX_S_AC,
	IDX_S_AF,
	IDX_S_SHS_1,
	IDX_LOGIC_1,
	IDX_NUM,
} I2C_DATA_IDX_E;

#endif /* SENSOR_SETTINGS_H_ */
