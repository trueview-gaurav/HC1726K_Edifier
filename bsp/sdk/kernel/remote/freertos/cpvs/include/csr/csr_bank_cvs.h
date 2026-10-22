#ifndef CSR_BANK_CVS_H_
#define CSR_BANK_CVS_H_

#ifndef __KERNEL__
#include <stdint.h>
#else
#include <linux/types.h>
#endif

/***  C struct generated from cvs  ***/
typedef struct csr_bank_cvs {
	/* CVS00 16'h0000 */
	union {
		uint32_t cvs00; // word name
		struct {
			uint32_t frame_start : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CVS01 16'h0004 */
	union {
		uint32_t cvs01; // word name
		struct {
			uint32_t status_frame_end : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CVS02 16'h0008 */
	union {
		uint32_t cvs02; // word name
		struct {
			uint32_t irq_clear_frame_end : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CVS03 16'h000C */
	union {
		uint32_t cvs03; // word name
		struct {
			uint32_t irq_mask_frame_end : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CVS04 16'h0010 */
	union {
		uint32_t cvs04; // word name
		struct {
			uint32_t width : 16;
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CVS05 16'h0014 */
	union {
		uint32_t cvs05; // word name
		struct {
			uint32_t height : 16;
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CVS06 16'h0018 */
	union {
		uint32_t cvs06; // word name
		struct {
			uint32_t mode : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CVS07 16'h001C */
	union {
		uint32_t cvs07; // word name
		struct {
			uint32_t debug_mon_sel : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
} CsrBankCvs;

#endif