#ifndef CSR_BANK_RX_CTRL_H_
#define CSR_BANK_RX_CTRL_H_

#ifndef __KERNEL__
#include <stdint.h>
#else
#include <linux/types.h>
#endif

/***  C struct generated from rx_ctrl  ***/
typedef struct csr_bank_rx_ctrl {
	/* CTRL_0 10'h000 */
	union {
		uint32_t ctrl_0; // word name
		struct {
			uint32_t pwr_ctrl_sel : 5;
			uint32_t : 3; // padding bits
			uint32_t : 8; // padding bits
			uint32_t ctrl_sel : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CTRL_1 10'h004 */
	union {
		uint32_t ctrl_1; // word name
		struct {
			uint32_t ln0_pwron_start : 1;
			uint32_t ln1_pwron_start : 1;
			uint32_t ln2_pwron_start : 1;
			uint32_t ln3_pwron_start : 1;
			uint32_t ln4_pwron_start : 1;
			uint32_t all_pwron_start : 1;
			uint32_t : 2; // padding bits
			uint32_t ln0_gpi_pwron_start : 1;
			uint32_t ln1_gpi_pwron_start : 1;
			uint32_t ln2_gpi_pwron_start : 1;
			uint32_t ln3_gpi_pwron_start : 1;
			uint32_t ln4_gpi_pwron_start : 1;
			uint32_t : 3; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CTRL_LN0 10'h008 */
	union {
		uint32_t ctrl_ln0; // word name
		struct {
			uint32_t rx_ln0_ib10u_en : 1;
			uint32_t : 7; // padding bits
			uint32_t rx_ln0_bias_en : 1;
			uint32_t : 7; // padding bits
			uint32_t rx_ln0_bias_out_en : 1;
			uint32_t : 7; // padding bits
			uint32_t rx_ln0_lprx_en : 1;
			uint32_t : 7; // padding bits
		};
	};
	/* CTRL_LN1 10'h00C */
	union {
		uint32_t ctrl_ln1; // word name
		struct {
			uint32_t rx_ln1_ib10u_en : 1;
			uint32_t : 7; // padding bits
			uint32_t rx_ln1_bias_en : 1;
			uint32_t : 7; // padding bits
			uint32_t rx_ln1_bias_out_en : 1;
			uint32_t : 7; // padding bits
			uint32_t rx_ln1_lprx_en : 1;
			uint32_t : 7; // padding bits
		};
	};
	/* CTRL_LN2 10'h010 */
	union {
		uint32_t ctrl_ln2; // word name
		struct {
			uint32_t rx_ln2_ib10u_en : 1;
			uint32_t : 7; // padding bits
			uint32_t rx_ln2_bias_en : 1;
			uint32_t : 7; // padding bits
			uint32_t rx_ln2_bias_out_en : 1;
			uint32_t : 7; // padding bits
			uint32_t rx_ln2_lprx_en : 1;
			uint32_t : 7; // padding bits
		};
	};
	/* CTRL_LN3 10'h014 */
	union {
		uint32_t ctrl_ln3; // word name
		struct {
			uint32_t rx_ln3_ib10u_en : 1;
			uint32_t : 7; // padding bits
			uint32_t rx_ln3_bias_en : 1;
			uint32_t : 7; // padding bits
			uint32_t rx_ln3_bias_out_en : 1;
			uint32_t : 7; // padding bits
			uint32_t rx_ln3_lprx_en : 1;
			uint32_t : 7; // padding bits
		};
	};
	/* CTRL_LN4 10'h018 */
	union {
		uint32_t ctrl_ln4; // word name
		struct {
			uint32_t rx_ln4_ib10u_en : 1;
			uint32_t : 7; // padding bits
			uint32_t rx_ln4_bias_en : 1;
			uint32_t : 7; // padding bits
			uint32_t rx_ln4_bias_out_en : 1;
			uint32_t : 7; // padding bits
			uint32_t rx_ln4_lprx_en : 1;
			uint32_t : 7; // padding bits
		};
	};
	/* DUMMY_0 10'h01C [Unused] */
	uint32_t empty_word_dummy_0;
	/* CAL_EN 10'h020 */
	union {
		uint32_t cal_en; // word name
		struct {
			uint32_t cal_start : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CAL_CTRL 10'h024 */
	union {
		uint32_t cal_ctrl; // word name
		struct {
			uint32_t cal_enable : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t cal_lane_en : 5;
			uint32_t : 3; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CAL_LN0_ST 10'h028 */
	union {
		uint32_t cal_ln0_st; // word name
		struct {
			uint32_t cal_ln0_done : 1;
			uint32_t cal_ln0_fail : 1;
			uint32_t : 6; // padding bits
			uint32_t cal_ln0_sta : 4;
			uint32_t : 4; // padding bits
			uint32_t cal_ln0_cnt : 4;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CAL_LN1_ST 10'h02C */
	union {
		uint32_t cal_ln1_st; // word name
		struct {
			uint32_t cal_ln1_done : 1;
			uint32_t cal_ln1_fail : 1;
			uint32_t : 6; // padding bits
			uint32_t cal_ln1_sta : 4;
			uint32_t : 4; // padding bits
			uint32_t cal_ln1_cnt : 4;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CAL_LN2_ST 10'h030 */
	union {
		uint32_t cal_ln2_st; // word name
		struct {
			uint32_t cal_ln2_done : 1;
			uint32_t cal_ln2_fail : 1;
			uint32_t : 6; // padding bits
			uint32_t cal_ln2_sta : 4;
			uint32_t : 4; // padding bits
			uint32_t cal_ln2_cnt : 4;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CAL_LN3_ST 10'h034 */
	union {
		uint32_t cal_ln3_st; // word name
		struct {
			uint32_t cal_ln3_done : 1;
			uint32_t cal_ln3_fail : 1;
			uint32_t : 6; // padding bits
			uint32_t cal_ln3_sta : 4;
			uint32_t : 4; // padding bits
			uint32_t cal_ln3_cnt : 4;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CAL_LN4_ST 10'h038 */
	union {
		uint32_t cal_ln4_st; // word name
		struct {
			uint32_t cal_ln4_done : 1;
			uint32_t cal_ln4_fail : 1;
			uint32_t : 6; // padding bits
			uint32_t cal_ln4_sta : 4;
			uint32_t : 4; // padding bits
			uint32_t cal_ln4_cnt : 4;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* MIPI_RX_14 10'h03C [Unused] */
	uint32_t empty_word_mipi_rx_14;
	/* PWR_ST_MON 10'h040 */
	union {
		uint32_t pwr_st_mon; // word name
		struct {
			uint32_t pwr_st : 25;
			uint32_t : 7; // padding bits
		};
	};
	/* RESV 10'h044 */
	union {
		uint32_t resv; // word name
		struct {
			uint32_t reserved : 32;
		};
	};
} CsrBankRx_ctrl;

#endif