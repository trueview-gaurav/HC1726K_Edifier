#ifndef CSR_BANK_CS_H_
#define CSR_BANK_CS_H_

#ifndef __KERNEL__
#include <stdint.h>
#else
#include <linux/types.h>
#endif

/***  C struct generated from cs  ***/
typedef struct csr_bank_cs {
	/* CS00 16'h0000 */
	union {
		uint32_t cs00; // word name
		struct {
			uint32_t frame_start : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CS01 16'h0004 */
	union {
		uint32_t cs01; // word name
		struct {
			uint32_t irq_clear_frame_end : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CS02 16'h0008 */
	union {
		uint32_t cs02; // word name
		struct {
			uint32_t status_frame_end : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CS03 16'h000C */
	union {
		uint32_t cs03; // word name
		struct {
			uint32_t irq_mask_frame_end : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CS04 16'h0010 */
	union {
		uint32_t cs04; // word name
		struct {
			uint32_t legacy_420 : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CS05 16'h0014 */
	union {
		uint32_t cs05; // word name
		struct {
			uint32_t chroma_shift_sampling : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CS06 16'h0018 */
	union {
		uint32_t cs06; // word name
		struct {
			uint32_t chroma_even_line : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CS07 16'h001C */
	union {
		uint32_t cs07; // word name
		struct {
			uint32_t width : 16;
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CS08 16'h0020 */
	union {
		uint32_t cs08; // word name
		struct {
			uint32_t height : 16;
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CS09 16'h0024 */
	union {
		uint32_t cs09; // word name
		struct {
			uint32_t debug_mon_sel : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
} CsrBankCs;

#endif