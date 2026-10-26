#ifndef SENSOR_SETTINGS_H_
#define SENSOR_SETTINGS_H_

#include "sensor_params.h"

#ifdef SET_2592_1944_12fps_DOL_HDR_NONVC_2lane
#define LVDS_LANE_NUM (2)
#define SENSOR_WIDTH (2592)
#define SENSOR_HEIGHT (1944)
#define SENSOR_FPS (12)
#define INIT_FRAME_LINE (2812) // VMAX = 2812 (15 fps: 2250)
#define INIT_LINE_LEN (1100) // HMAX = 1100
#define MAX_FPS (12)
#define MIN_FPS (5)
#define BIT_DEPTH (10)

#define RHS1 (629) // L:S = 4990:624 = 7.997
#define MIPI_HBP (24) // 16(LI) + 8(Margin)
#define MIPI_VBP (64) // ( 10(Ignored OB) + 10(OB) + 4(Ignored) + 8(Margin) ) * 2(HDR)
#define MIPI_HFP (8) // 8(Margin)
#define MIPI_VFP (16) // 8(Margin) * 2(HDR)

#define T_HS_SETTLE_NS (115)
#define T_D_TERM_EN_NS (39)
#define T_CLK_SETTLE_NS (182)
#define T_CLK_TERM_EN_NS (38)
#endif

#ifdef SET_2592_1944_12fps_DOL_HDR_NONVC_2lane_12B
#define LVDS_LANE_NUM (2)
#define SENSOR_WIDTH (2592)
#define SENSOR_HEIGHT (1944)
#define SENSOR_FPS (12)
#define INIT_FRAME_LINE (2750) // VMAX = 2750 (15 fps: 2200)
#define INIT_LINE_LEN (1125) // HMAX = 1100
#define MAX_FPS (12)
#define MIN_FPS (5)
#define BIT_DEPTH (12)

#define RHS1 (617) // L:S = 4878:612 = 7.971
#define MIPI_HBP (24) // 16(LI) + 8(Margin)
#define MIPI_VBP (64) // ( 10(Ignored OB) + 10(OB) + 4(Ignored) + 8(Margin) ) * 2(HDR)
#define MIPI_HFP (8) // 8(Margin)
#define MIPI_VFP (16) // 8(Margin) * 2(HDR)

#define T_HS_SETTLE_NS (115)
#define T_D_TERM_EN_NS (39)
#define T_CLK_SETTLE_NS (182)
#define T_CLK_TERM_EN_NS (38)
#endif

#define HDR_MODE MPI_HDR_MODE_FRAME_COMB
#define HDR_IMAGE_NUM (2)

#define HDR_BLANK_LINE (((RHS1)-1) / 2) // HDR blank line (VBP1) Datasheet: VBP1 = (RHS1 - 3) / 2 + 1  page:17

#define PCLK (SENSOR_FPS * INIT_FRAME_LINE * INIT_LINE_LEN * HDR_IMAGE_NUM)
#define SENSOR_FRAME_LINES_MAX (INIT_FRAME_LINE * SENSOR_FPS / MIN_FPS)
#define SENSOR_FRAME_LINES_MIN (INIT_FRAME_LINE * SENSOR_FPS / MAX_FPS)
#define SENSOR_GAIN_MAX (1012) // analog gain max is 1012 (30 db), total max is 127394 (72 db)
#define SENSOR_GAIN_MIN (32)

#endif /* SENSOR_SETTINGS_H_ */
