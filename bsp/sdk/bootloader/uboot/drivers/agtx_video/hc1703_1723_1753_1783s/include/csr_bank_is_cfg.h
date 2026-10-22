#ifndef CSR_BANK_IS_CFG_H_
#define CSR_BANK_IS_CFG_H_

#include <linux/types.h>

/***  C struct generated from is_cfg  ***/
typedef struct csr_bank_is_cfg {
	/* CONF0_ISR0 10'h000 */
	union {
		uint32_t conf0_isr0; // word name
		struct {
			uint32_t cken_isr0 : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_isr0 : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CONF1_ISR0 10'h004 */
	union {
		uint32_t conf1_isr0; // word name
		struct {
			uint32_t sw_rst_isr0 : 1;
			uint32_t : 7; // padding bits
			uint32_t csr_rst_isr0 : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CONF0_ISR1 10'h008 */
	union {
		uint32_t conf0_isr1; // word name
		struct {
			uint32_t cken_isr1 : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_isr1 : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CONF1_ISR1 10'h00C */
	union {
		uint32_t conf1_isr1; // word name
		struct {
			uint32_t sw_rst_isr1 : 1;
			uint32_t : 7; // padding bits
			uint32_t csr_rst_isr1 : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CONF0_FE0 10'h010 */
	union {
		uint32_t conf0_fe0; // word name
		struct {
			uint32_t cken_fe0 : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_fe0 : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CONF1_FE0 10'h014 */
	union {
		uint32_t conf1_fe0; // word name
		struct {
			uint32_t sw_rst_fe0 : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CONF0_FE1 10'h018 */
	union {
		uint32_t conf0_fe1; // word name
		struct {
			uint32_t cken_fe1 : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_fe1 : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CONF1_FE1 10'h01C */
	union {
		uint32_t conf1_fe1; // word name
		struct {
			uint32_t sw_rst_fe1 : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CONF0_ISK0 10'h020 */
	union {
		uint32_t conf0_isk0; // word name
		struct {
			uint32_t cken_isk0 : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_isk0 : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CONF1_ISK0 10'h024 */
	union {
		uint32_t conf1_isk0; // word name
		struct {
			uint32_t sw_rst_isk0 : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CONF0_ISK1 10'h028 */
	union {
		uint32_t conf0_isk1; // word name
		struct {
			uint32_t cken_isk1 : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_isk1 : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CONF1_ISK1 10'h02C */
	union {
		uint32_t conf1_isk1; // word name
		struct {
			uint32_t sw_rst_isk1 : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CONF0_ISWROI0 10'h030 */
	union {
		uint32_t conf0_iswroi0; // word name
		struct {
			uint32_t cken_iswroi0 : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_iswroi0 : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CONF1_ISWROI0 10'h034 */
	union {
		uint32_t conf1_iswroi0; // word name
		struct {
			uint32_t sw_rst_iswroi0 : 1;
			uint32_t : 7; // padding bits
			uint32_t csr_rst_iswroi0 : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CONF0_ISWROI1 10'h038 */
	union {
		uint32_t conf0_iswroi1; // word name
		struct {
			uint32_t cken_iswroi1 : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_iswroi1 : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CONF1_ISWROI1 10'h03C */
	union {
		uint32_t conf1_iswroi1; // word name
		struct {
			uint32_t sw_rst_iswroi1 : 1;
			uint32_t : 7; // padding bits
			uint32_t csr_rst_iswroi1 : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CONF0_ISW0 10'h040 */
	union {
		uint32_t conf0_isw0; // word name
		struct {
			uint32_t cken_isw0 : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_isw0 : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CONF1_ISW0 10'h044 */
	union {
		uint32_t conf1_isw0; // word name
		struct {
			uint32_t sw_rst_isw0 : 1;
			uint32_t : 7; // padding bits
			uint32_t csr_rst_isw0 : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CONF0_ISW1 10'h048 */
	union {
		uint32_t conf0_isw1; // word name
		struct {
			uint32_t cken_isw1 : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_isw1 : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CONF1_ISW1 10'h04C */
	union {
		uint32_t conf1_isw1; // word name
		struct {
			uint32_t sw_rst_isw1 : 1;
			uint32_t : 7; // padding bits
			uint32_t csr_rst_isw1 : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CONF0_CTRL 10'h050 */
	union {
		uint32_t conf0_ctrl; // word name
		struct {
			uint32_t cken_ctrl : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_ctrl : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CONF1_CTRL 10'h054 */
	union {
		uint32_t conf1_ctrl; // word name
		struct {
			uint32_t sw_rst_ctrl : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CONF0_LP 10'h058 */
	union {
		uint32_t conf0_lp; // word name
		struct {
			uint32_t cken_lp : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_lp : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CONF1_LP 10'h05C */
	union {
		uint32_t conf1_lp; // word name
		struct {
			uint32_t sw_rst_lp : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
} CsrBankIs_cfg;

#endif