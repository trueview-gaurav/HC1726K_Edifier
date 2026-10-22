#ifndef SENSOR_SETTINGS_H_
#define SENSOR_SETTINGS_H_

#include "sensor_params.h"

#ifdef SET_2688_1520_15fps_hdr_nonVC_2lane
#define LVDS_LANE_NUM (2)
#define SENSOR_WIDTH (2688)
#define SENSOR_HEIGHT (1520)
#define SENSOR_FPS (15)
#define INIT_FRAME_LINE (3840) // 0x23/0x22 => 0xF00 = 3840
#define INIT_LINE_LEN (3000) // 0x21/0x20 => 0x2EE = 750,  750*4=3000
#define MAX_FPS (15)
#define MIN_FPS (5)
#define T_HS_SETTLE_NS (125) //  [85, 155] real value : 125ns
#define T_D_TERM_EN_NS (39) //   [0, 39]   real value : 86ns
#define T_CLK_SETTLE_NS (197) // [95, 300] real value : 197ns
#define T_CLK_TERM_EN_NS (38) // [0, 38]   real value : 70ns

#define HDR_MODE MPI_HDR_MODE_LINE_COLOC
#define HDR_IMAGE_NUM (2)
#define HDR_MIPI_BLANK_LINE (240) // Reg:0x06 {SFramSt,SAEC[7:0]:Short exposure frame start position in HDR mode}
#define HDR_BLANK_LINE ((HDR_MIPI_BLANK_LINE * 2) + 1) // Note: Reg0x06 is 2N+1 base, so the default 0x23 is short exp data shift 71 line
#define HDR_HEIGHT (SENSOR_HEIGHT * HDR_IMAGE_NUM)

// JXK-302P HDR by SOI FAE
// short exposure lines <  (Short exposure frame start position * 2 + 1) - 5
// Reg 0x08[0] 0x05[7:0] < ((Reg 0x06 * 2 + 1) - 5)
// Reg 0x06=0x35 => 53*2+1=107 => 107-5=102
// Hardware limitations MAX = 0x1DB
#define HDR_SHORT_EXPS_MAX (0x1DB)

// JXK-302P HDR by SOI FAE
// long exposure lines <  FH(0x23 , 0x22) - (Short exposure frame start position * 2 + 1) + 6
// Reg 0x08[0] 0x05[7:0] < 0xF00 - ((Reg 0x06 * 2 + 1) + 6)
// Reg 0x06=0xF0 => 240*2+1=481 => 481+6=487
// 3840 - 487 = 3353 = 0xD19
#define HDR_LONG_EXPS_MAX (0xD19)
#endif

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
