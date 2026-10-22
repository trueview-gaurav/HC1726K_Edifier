#ifndef SENSOR_SETTINGS_H_
#define SENSOR_SETTINGS_H_

#include "sensor_params.h"

#define LVDS_LANE_NUM (2)
#define SENSOR_WIDTH (1920)
#define SENSOR_HEIGHT (1080)
#define SENSOR_FPS (30)
#define INIT_FRAME_LINE (1158) // VMAX {0x301A,0x3019,0x3018} = 0x486 = 1158
#define INIT_LINE_LEN (2136) // HMAX {0x301D,0x301C} = 0x858 = 2136
#define MAX_FPS (30)
#define MIN_FPS (5)
#define T_HS_SETTLE_NS (155) // real timming is 217ns
#define T_D_TERM_EN_NS (39) // real timming is 81ns
#define T_CLK_SETTLE_NS (135)
#define T_CLK_TERM_EN_NS (14)

#define SENSOR_RAW_WIDTH (1952) // 1920 + 16 +16
#define SENSOR_RAW_HEIGHT (2294) // {0x3419,0x3418}= 0x8F6 = 2294
#define HDR_MODE (MPI_HDR_MODE_FRAME_COMB)
#define HDR_IMAGE_NUM (2)
#define RHS1 (0x65) // {0x3032,0x3031,0x3030} = 0x65 = 101
#define HDR_BLANK_LINE ((RHS1 - 1) / 2) // 50  // IMX327_AppNote_DOL_E_Rev1.0.pdf ,  page 13

#define PCLK (SENSOR_FPS * INIT_FRAME_LINE * INIT_LINE_LEN * HDR_IMAGE_NUM)
#define SENSOR_FRAME_LINES_MAX (INIT_FRAME_LINE * SENSOR_FPS / MIN_FPS)
#define SENSOR_FRAME_LINES_MIN (INIT_FRAME_LINE * SENSOR_FPS / MAX_FPS)
#define SENSOR_GAIN_MAX (90188)
#define SENSOR_GAIN_MIN (32)

#endif /* SENSOR_SETTINGS_H_ */
