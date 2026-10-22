#ifndef CSR_BANK_I2CM_H_
#define CSR_BANK_I2CM_H_

#ifndef __KERNEL__
#include <stdint.h>
#else
#include <linux/types.h>
#endif

/***  C struct generated from i2cm  ***/
typedef struct csr_bank_i2cm {
	/* I2CM00 16'h00 */
	union {
		uint32_t i2cm00; // word name
		struct {
			uint32_t action_start : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* I2CM01 16'h04 */
	union {
		uint32_t i2cm01; // word name
		struct {
			uint32_t irq_clear_action_end : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* I2CM02 16'h08 */
	union {
		uint32_t i2cm02; // word name
		struct {
			uint32_t irq_action_action_end : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* I2CM03 16'h0C */
	union {
		uint32_t i2cm03; // word name
		struct {
			uint32_t irq_mask_action_end : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* I2CM04 16'h10 */
	union {
		uint32_t i2cm04; // word name
		struct {
			uint32_t engine_status : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t action_status : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* I2CM05 16'h14 */
	union {
		uint32_t i2cm05; // word name
		struct {
			uint32_t write_byte_cnt : 5;
			uint32_t : 3; // padding bits
			uint32_t write_trans_cnt : 5;
			uint32_t : 3; // padding bits
			uint32_t read_byte_cnt : 5;
			uint32_t : 3; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* I2CM06 16'h18 */
	union {
		uint32_t i2cm06; // word name
		struct {
			uint32_t sda_deglitch_th : 6;
			uint32_t : 2; // padding bits
			uint32_t sdo_delay_cycle : 8;
			uint32_t scl_rate_cycle : 8;
			uint32_t : 8; // padding bits
		};
	};
	/* I2CM07 16'h1C */
	union {
		uint32_t i2cm07; // word name
		struct {
			uint32_t read_mode : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t restart_mode : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* I2CM08 16'h20 */
	union {
		uint32_t i2cm08; // word name
		struct {
			uint32_t target_address : 7;
			uint32_t : 1; // padding bits
			uint32_t operation : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* I2CM09 16'h24 */
	union {
		uint32_t i2cm09; // word name
		struct {
			uint32_t write_byte_num_m1 : 5;
			uint32_t : 3; // padding bits
			uint32_t write_trans_num_m1 : 5;
			uint32_t : 3; // padding bits
			uint32_t read_byte_num_m1 : 5;
			uint32_t : 3; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* I2CM10 16'h28 */
	union {
		uint32_t i2cm10; // word name
		struct {
			uint32_t wdata_0 : 8;
			uint32_t wdata_1 : 8;
			uint32_t wdata_2 : 8;
			uint32_t wdata_3 : 8;
		};
	};
	/* I2CM11 16'h2C */
	union {
		uint32_t i2cm11; // word name
		struct {
			uint32_t wdata_4 : 8;
			uint32_t wdata_5 : 8;
			uint32_t wdata_6 : 8;
			uint32_t wdata_7 : 8;
		};
	};
	/* I2CM12 16'h30 */
	union {
		uint32_t i2cm12; // word name
		struct {
			uint32_t wdata_8 : 8;
			uint32_t wdata_9 : 8;
			uint32_t wdata_10 : 8;
			uint32_t wdata_11 : 8;
		};
	};
	/* I2CM13 16'h34 */
	union {
		uint32_t i2cm13; // word name
		struct {
			uint32_t wdata_12 : 8;
			uint32_t wdata_13 : 8;
			uint32_t wdata_14 : 8;
			uint32_t wdata_15 : 8;
		};
	};
	/* I2CM14 16'h38 */
	union {
		uint32_t i2cm14; // word name
		struct {
			uint32_t wdata_16 : 8;
			uint32_t wdata_17 : 8;
			uint32_t wdata_18 : 8;
			uint32_t wdata_19 : 8;
		};
	};
	/* I2CM15 16'h3C */
	union {
		uint32_t i2cm15; // word name
		struct {
			uint32_t wdata_20 : 8;
			uint32_t wdata_21 : 8;
			uint32_t wdata_22 : 8;
			uint32_t wdata_23 : 8;
		};
	};
	/* I2CM16 16'h40 */
	union {
		uint32_t i2cm16; // word name
		struct {
			uint32_t wdata_24 : 8;
			uint32_t wdata_25 : 8;
			uint32_t wdata_26 : 8;
			uint32_t wdata_27 : 8;
		};
	};
	/* I2CM17 16'h44 */
	union {
		uint32_t i2cm17; // word name
		struct {
			uint32_t wdata_28 : 8;
			uint32_t wdata_29 : 8;
			uint32_t wdata_30 : 8;
			uint32_t wdata_31 : 8;
		};
	};
	/* I2CM18 16'h48 */
	union {
		uint32_t i2cm18; // word name
		struct {
			uint32_t rdata_0 : 8;
			uint32_t rdata_1 : 8;
			uint32_t rdata_2 : 8;
			uint32_t rdata_3 : 8;
		};
	};
	/* I2CM19 16'h4C */
	union {
		uint32_t i2cm19; // word name
		struct {
			uint32_t rdata_4 : 8;
			uint32_t rdata_5 : 8;
			uint32_t rdata_6 : 8;
			uint32_t rdata_7 : 8;
		};
	};
	/* I2CM20 16'h50 */
	union {
		uint32_t i2cm20; // word name
		struct {
			uint32_t debug_mon_sel : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* I2CM21 16'h54 */
	union {
		uint32_t i2cm21; // word name
		struct {
			uint32_t reserved : 32;
		};
	};
} CsrBankI2cm;

#endif