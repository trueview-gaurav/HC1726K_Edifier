#ifndef CSR_BANK_CROP_H_
#define CSR_BANK_CROP_H_

#ifndef __KERNEL__
#include <stdint.h>
#else
#include <linux/types.h>
#endif

/***  C struct generated from crop  ***/
typedef struct csr_bank_crop {
	/* WORD_FRAME_START 9'h000 */
	union {
		uint32_t word_frame_start; // word name
		struct {
			uint32_t frame_start : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* RESOLUTION 9'h004 */
	union {
		uint32_t resolution; // word name
		struct {
			uint32_t width : 16;
			uint32_t height : 16;
		};
	};
	/* CROP_X 9'h008 */
	union {
		uint32_t crop_x; // word name
		struct {
			uint32_t crop_left : 16;
			uint32_t crop_right : 16;
		};
	};
	/* CROP_Y 9'h00C */
	union {
		uint32_t crop_y; // word name
		struct {
			uint32_t crop_up : 16;
			uint32_t crop_down : 16;
		};
	};
} CsrBankCrop;

#endif