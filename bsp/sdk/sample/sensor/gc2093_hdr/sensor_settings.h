#ifndef SENSOR_SETTINGS_H_
#define SENSOR_SETTINGS_H_

#include "sensor_params.h"

#ifdef SET_1920_1080_30fps_hdr_nonVC_2lane
#define SENSOR_WIDTH (1920)
#define SENSOR_HEIGHT (1080)
#define SENSOR_FPS (30)
#define INIT_FRAME_LINE (1250)
#define INIT_LINE_LEN (2640)
#define MAX_FPS (30)
#define MIN_FPS (5)
#define T_HS_SETTLE_NS (100)
#define T_D_TERM_EN_NS (35)
#define T_CLK_SETTLE_NS (240)
#define T_CLK_TERM_EN_NS (35)

#define HDR_MODE MPI_HDR_MODE_LINE_COLOC
#define HDR_IMAGE_NUM (2)
#define HDR_BLANK_LINE (124)
#define HDR_HEIGHT (SENSOR_HEIGHT * HDR_IMAGE_NUM) // actual lines of the image in HDR mode
#endif

#define PCLK (INIT_LINE_LEN * INIT_FRAME_LINE * SENSOR_FPS)
#define SENSOR_FRAME_LINES_MAX (INIT_FRAME_LINE * SENSOR_FPS / MIN_FPS)
#define SENSOR_FRAME_LINES_MIN (INIT_FRAME_LINE * SENSOR_FPS / MAX_FPS)
#define SENSOR_MAX_GAIN (16383)

#endif /* SENSOR_SETTINGS_H_ */
