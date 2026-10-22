#ifndef CSR_BANK_ISK_CFG_H_
#define CSR_BANK_ISK_CFG_H_

#ifndef __KERNEL__
#include <stdint.h>
#else
#include <linux/types.h>
#endif

/***  C struct generated from isk_cfg  ***/
typedef struct csr_bank_isk_cfg {
	/* CONF0_AGMA 10'h000 */
	union {
		uint32_t conf0_agma; // word name
		struct {
			uint32_t cken_agma : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_agma : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CONF1_AGMA 10'h004 */
	union {
		uint32_t conf1_agma; // word name
		struct {
			uint32_t sw_rst_agma : 1;
			uint32_t : 7; // padding bits
			uint32_t csr_rst_agma : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CONF0_CVS 10'h008 */
	union {
		uint32_t conf0_cvs; // word name
		struct {
			uint32_t cken_cvs : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_cvs : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CONF1_CVS 10'h00C */
	union {
		uint32_t conf1_cvs; // word name
		struct {
			uint32_t sw_rst_cvs : 1;
			uint32_t : 7; // padding bits
			uint32_t csr_rst_cvs : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CONF0_CS 10'h010 */
	union {
		uint32_t conf0_cs; // word name
		struct {
			uint32_t cken_cs : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_cs : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CONF1_CS 10'h014 */
	union {
		uint32_t conf1_cs; // word name
		struct {
			uint32_t sw_rst_cs : 1;
			uint32_t : 7; // padding bits
			uint32_t csr_rst_cs : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CONF0_FPNR 10'h018 */
	union {
		uint32_t conf0_fpnr; // word name
		struct {
			uint32_t cken_fpnr : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_fpnr : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CONF1_FPNR 10'h01C */
	union {
		uint32_t conf1_fpnr; // word name
		struct {
			uint32_t sw_rst_fpnr : 1;
			uint32_t : 7; // padding bits
			uint32_t csr_rst_fpnr : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CONF0_BSP 10'h020 */
	union {
		uint32_t conf0_bsp; // word name
		struct {
			uint32_t cken_bsp : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_bsp : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CONF1_BSP 10'h024 */
	union {
		uint32_t conf1_bsp; // word name
		struct {
			uint32_t sw_rst_bsp : 1;
			uint32_t : 7; // padding bits
			uint32_t csr_rst_bsp : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CONF0_FSC 10'h028 */
	union {
		uint32_t conf0_fsc; // word name
		struct {
			uint32_t cken_fsc : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_fsc : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CONF1_FSC 10'h02C */
	union {
		uint32_t conf1_fsc; // word name
		struct {
			uint32_t sw_rst_fsc : 1;
			uint32_t : 7; // padding bits
			uint32_t csr_rst_fsc : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CONF0_FGMA 10'h030 */
	union {
		uint32_t conf0_fgma; // word name
		struct {
			uint32_t cken_fgma : 1;
			uint32_t : 7; // padding bits
			uint32_t lv_rst_fgma : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CONF1_FGMA 10'h034 */
	union {
		uint32_t conf1_fgma; // word name
		struct {
			uint32_t sw_rst_fgma : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CONF0_CTRL 10'h038 */
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
	/* CONF1_CTRL 10'h03C */
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
} CsrBankIsk_cfg;

#endif