#ifndef SENSOR_SETTINGS_H_
#define SENSOR_SETTINGS_H_

#include "sensor_params.h"

#if SET_2592_1944_12fps_DOL_HDR_nonVC_2lane
#define LVDS_LANE_NUM (2)
#define SENSOR_WIDTH (2592)
#define SENSOR_HEIGHT (1944)
#define SENSOR_FPS (12)
#define INIT_FRAME_LINE (2812) // {0x302A,0x3029,0x3028} = 0xAFC = 2812
#define INIT_LINE_LEN \
	(1100) // INIT_FRAME_LINE * INIT_LINE_LEN = (MIPI data rate * MIPI lane ) / MIPI bit-width / fps  2200*3636=(1440*2)/12/30
#define MAX_FPS (12)
#define MIN_FPS (6)
#define T_HS_SETTLE_NS (115)
#define T_D_TERM_EN_NS (39)
#define T_CLK_SETTLE_NS (182)
#define T_CLK_TERM_EN_NS (38)
#endif

#define MIPI_HBP (24) // 16(LI) + 8(Margin)
#define MIPI_VBP (64) // ( 10(Ignored OB) + 10(OB) + 4(Ignored) + 8(Margin) ) * 2(HDR)
#define MIPI_HFP (8) // 8(Margin)
#define MIPI_VFP (16) // 8(Margin) * 2(HDR)

#define HDR_MODE MPI_HDR_MODE_FRAME_COMB
#define HDR_IMAGE_NUM (2)

#define RHS1 (45) //* RHS1  {0x3062,0x3061,0x3060} = 0x000009 Used to derive HDR blank line for ISP ， max is 47
#define HDR_BLANK_LINE (((RHS1)-3) / 2 + 1) // HDR blank line (VBP1) Datasheet: VBP1 = (RHS1 - 3) / 2 + 1  page:17

#define PCLK (SENSOR_FPS * INIT_FRAME_LINE * INIT_LINE_LEN * HDR_IMAGE_NUM)
#define SENSOR_FRAME_LINES_MAX (INIT_FRAME_LINE * SENSOR_FPS / MIN_FPS)
#define SENSOR_FRAME_LINES_MIN (INIT_FRAME_LINE * SENSOR_FPS / MAX_FPS)
#define SENSOR_GAIN_MAX (16383) // analog gain max is 716
#define SENSOR_GAIN_MIN (32)

#endif /* SENSOR_SETTINGS_H_ */
