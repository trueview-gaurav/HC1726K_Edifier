/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef KYOTO_COMMON_H_
#define KYOTO_COMMON_H_

#ifndef __KERNEL__
#include <stdint.h>
#else
#include <linux/types.h>
#endif

#define COLOR_CHN_NUM (3)
#define CFA_PHASE_ENTRY_NUM (16)

typedef enum cfa_phase {
	CFA_PHASE_G0 = 0, // GR
	CFA_PHASE_R,
	CFA_PHASE_B,
	CFA_PHASE_G1, // GB
	CFA_PHASE_S,
	CFA_PHASE_NUM,
} CfaPhase;

typedef enum ini_bayer_phase {
	INI_BAYER_PHASE_G0 = 0, // GR
	INI_BAYER_PHASE_R,
	INI_BAYER_PHASE_B,
	INI_BAYER_PHASE_G1, // GB
	INI_BAYER_PHASE_NUM,
} IniBayerPhase;

typedef struct res {
	uint16_t width;
	uint16_t height;
} Res;

typedef struct rect {
	uint16_t x;
	uint16_t y;
	uint16_t width;
	uint16_t height;
} Rect;

typedef struct rect_point {
	int16_t sx;
	int16_t sy;
	int16_t ex;
	int16_t ey;
} RectPoint;

typedef struct point {
	uint16_t x;
	uint16_t y;
} Point;

#endif /* KYOTO_COMMON_H_ */