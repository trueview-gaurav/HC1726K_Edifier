/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef CSR_BANK_EFUSE_CTRL_H_
#define CSR_BANK_EFUSE_CTRL_H_

#ifndef __KERNEL__
#include <stdint.h>
#else
#include <linux/types.h>
#endif

/***  C struct generated from efuse_ctrl  ***/
typedef struct csr_bank_efuse_ctrl {
	/* WORD_MODE 10'h00 */
	union {
		uint32_t word_mode; // word name
		struct {
			uint32_t mode : 3;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* TIME_SET0 10'h04 */
	union {
		uint32_t time_set0; // word name
		struct {
			uint32_t tsu_pd_ps : 7;
			uint32_t : 1; // padding bits
			uint32_t tsu_ps_cs : 7;
			uint32_t : 1; // padding bits
			uint32_t th_cs : 3;
			uint32_t : 5; // padding bits
			uint32_t th_ps_cs : 4;
			uint32_t : 4; // padding bits
		};
	};
	/* TIME_SET1 10'h08 */
	union {
		uint32_t time_set1; // word name
		struct {
			uint32_t tsu_a : 3;
			uint32_t : 5; // padding bits
			uint32_t th_a : 3;
			uint32_t : 5; // padding bits
			uint32_t t_strobe : 11;
			uint32_t : 5; // padding bits
		};
	};
	/* CTRL 10'h0C */
	union {
		uint32_t ctrl; // word name
		struct {
			uint32_t start : 1;
			uint32_t : 7; // padding bits
			uint32_t stop : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* ADDR 10'h10 */
	union {
		uint32_t addr; // word name
		struct {
			uint32_t rw_addr : 10;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WDATA 10'h14 */
	union {
		uint32_t wdata; // word name
		struct {
			uint32_t w_data : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* RDATA 10'h18 */
	union {
		uint32_t rdata; // word name
		struct {
			uint32_t r_data : 32;
		};
	};
	/* HW_RDATA 10'h1C */
	union {
		uint32_t hw_rdata; // word name
		struct {
			uint32_t hardware_r_data : 32;
		};
	};
	/* STATUS 10'h20 */
	union {
		uint32_t status; // word name
		struct {
			uint32_t rw_ready : 1;
			uint32_t : 7; // padding bits
			uint32_t rd_done : 1;
			uint32_t : 7; // padding bits
			uint32_t esc_done : 1;
			uint32_t : 7; // padding bits
			uint32_t power_dn : 1;
			uint32_t : 7; // padding bits
		};
	};
	/* WORD_TIME_CNT 10'h24 */
	union {
		uint32_t word_time_cnt; // word name
		struct {
			uint32_t time_cnt : 16;
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_LOCK 10'h28 */
	union {
		uint32_t word_lock; // word name
		struct {
			uint32_t lock : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* STATUS_IRQ 10'h2C */
	union {
		uint32_t status_irq; // word name
		struct {
			uint32_t status_irq_pgm : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* MASK 10'h30 */
	union {
		uint32_t mask; // word name
		struct {
			uint32_t irq_mask_pgm : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CLEAR_IRQ 10'h34 */
	union {
		uint32_t clear_irq; // word name
		struct {
			uint32_t irq_clear_pgm : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* STATUS_R 10'h38 */
	union {
		uint32_t status_r; // word name
		struct {
			uint32_t rf0 : 1;
			uint32_t : 7; // padding bits
			uint32_t rf1 : 1;
			uint32_t : 7; // padding bits
			uint32_t rf2 : 1;
			uint32_t : 7; // padding bits
			uint32_t rf3 : 1;
			uint32_t : 7; // padding bits
		};
	};
	/* STATUS_HW_RDATA 10'h3C */
	union {
		uint32_t status_hw_rdata; // word name
		struct {
			uint32_t hw_rdata_done : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* MASK_HW_R 10'h40 */
	union {
		uint32_t mask_hw_r; // word name
		struct {
			uint32_t hw_rdata_mask : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CLEAR_HW_R 10'h44 */
	union {
		uint32_t clear_hw_r; // word name
		struct {
			uint32_t hw_rdata_clear : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
} CsrBankEfuse_ctrl;

#endif