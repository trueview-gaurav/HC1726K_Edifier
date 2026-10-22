#ifndef CSR_BANK_JPEG_H_
#define CSR_BANK_JPEG_H_

#ifndef __KERNEL__
#include <stdint.h>
#else
#include <linux/types.h>
#endif

/***  C struct generated from jpeg  ***/
typedef struct csr_bank_jpeg {
	/* JPEG00 10'h000 */
	union {
		uint32_t jpeg00; // word name
		struct {
			uint32_t frm_start : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* JPEG01 10'h004 */
	union {
		uint32_t jpeg01; // word name
		struct {
			uint32_t irq_clear_frame_end : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* JPEG02 10'h008 */
	union {
		uint32_t jpeg02; // word name
		struct {
			uint32_t status_frame_end : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* JPEG03 10'h00C */
	union {
		uint32_t jpeg03; // word name
		struct {
			uint32_t irq_mask_frame_end : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* JPEG04 10'h010 */
	union {
		uint32_t jpeg04; // word name
		struct {
			uint32_t jpeg_enc_format : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* JPEG05 10'h014 */
	union {
		uint32_t jpeg05; // word name
		struct {
			uint32_t frm_width : 16;
			uint32_t frm_height : 16;
		};
	};
	/* JPEG06 10'h018 */
	union {
		uint32_t jpeg06; // word name
		struct {
			uint32_t frm_mcu_hor_num_m1 : 13;
			uint32_t : 3; // padding bits
			uint32_t frm_mcu_ver_num_m1 : 13;
			uint32_t : 3; // padding bits
		};
	};
	/* JPEG07 10'h01C */
	union {
		uint32_t jpeg07; // word name
		struct {
			uint32_t quality : 7;
			uint32_t : 1; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* JPEG08 10'h020 */
	union {
		uint32_t jpeg08; // word name
		struct {
			uint32_t q_table_sr_en : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* JPEG09 10'h024 */
	union {
		uint32_t jpeg09; // word name
		struct {
			uint32_t q_table_sr_addr : 6;
			uint32_t : 2; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* JPEG10 10'h028 */
	union {
		uint32_t jpeg10; // word name
		struct {
			uint32_t q_table_sr_data_0 : 32;
		};
	};
	/* JPEG11 10'h02C */
	union {
		uint32_t jpeg11; // word name
		struct {
			uint32_t q_table_sr_data_1 : 32;
		};
	};
	/* JPEG12 10'h030 */
	union {
		uint32_t jpeg12; // word name
		struct {
			uint32_t q_table_sr_data_2 : 32;
		};
	};
	/* JPEG13 10'h034 */
	union {
		uint32_t jpeg13; // word name
		struct {
			uint32_t q_table_sr_data_3 : 32;
		};
	};
	/* JPEG14 10'h038 */
	union {
		uint32_t jpeg14; // word name
		struct {
			uint32_t reserved_0 : 32;
		};
	};
	/* JPEG15 10'h03C */
	union {
		uint32_t jpeg15; // word name
		struct {
			uint32_t reserved_1 : 32;
		};
	};
	/* JPEG16 10'h040 */
	union {
		uint32_t jpeg16; // word name
		struct {
			uint32_t debug_mon_reg : 32;
		};
	};
	/* JPEG17 10'h044 */
	union {
		uint32_t jpeg17; // word name
		struct {
			uint32_t frame_bs_byte_length : 32;
		};
	};
} CsrBankJpeg;

#endif