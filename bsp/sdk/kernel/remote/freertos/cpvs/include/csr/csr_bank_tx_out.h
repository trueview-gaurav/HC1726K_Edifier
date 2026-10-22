#ifndef CSR_BANK_TX_OUT_H_
#define CSR_BANK_TX_OUT_H_

#ifndef __KERNEL__
#include <stdint.h>
#else
#include <linux/types.h>
#endif

/***  C struct generated from tx_out  ***/
typedef struct csr_bank_tx_out {
	/* MAIN 10'h000 */
	union {
		uint32_t main; // word name
		struct {
			uint32_t enable : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* IRQSTA 10'h004 */
	union {
		uint32_t irqsta; // word name
		struct {
			uint32_t status_fifo_err : 1;
			uint32_t status_lpcd_err : 1;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* IRQACK 10'h008 */
	union {
		uint32_t irqack; // word name
		struct {
			uint32_t irq_clear_fifo_err : 1;
			uint32_t irq_clear_lpcd_err : 1;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* IRQMSK 10'h00C */
	union {
		uint32_t irqmsk; // word name
		struct {
			uint32_t irq_mask_fifo_err : 1;
			uint32_t irq_mask_lpcd_err : 1;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* HSCK 10'h010 */
	union {
		uint32_t hsck; // word name
		struct {
			uint32_t ck_pat : 8;
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* LN0_CTRL 10'h014 */
	union {
		uint32_t ln0_ctrl; // word name
		struct {
			uint32_t ln0_en : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t ln0_pn_sel : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* LN1_CTRL 10'h018 */
	union {
		uint32_t ln1_ctrl; // word name
		struct {
			uint32_t ln1_en : 1;
			uint32_t : 7; // padding bits
			uint32_t ln1_rx_sel : 2;
			uint32_t : 6; // padding bits
			uint32_t ln1_pn_sel : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* LN2_CTRL 10'h01C */
	union {
		uint32_t ln2_ctrl; // word name
		struct {
			uint32_t ln2_en : 1;
			uint32_t : 7; // padding bits
			uint32_t ln2_rx_sel : 2;
			uint32_t : 6; // padding bits
			uint32_t ln2_pn_sel : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* LN3_CTRL 10'h020 */
	union {
		uint32_t ln3_ctrl; // word name
		struct {
			uint32_t ln3_en : 1;
			uint32_t : 7; // padding bits
			uint32_t ln3_rx_sel : 2;
			uint32_t : 6; // padding bits
			uint32_t ln3_pn_sel : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* LN4_CTRL 10'h024 */
	union {
		uint32_t ln4_ctrl; // word name
		struct {
			uint32_t ln4_en : 1;
			uint32_t : 7; // padding bits
			uint32_t ln4_rx_sel : 2;
			uint32_t : 6; // padding bits
			uint32_t ln4_pn_sel : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* LN0_TEST 10'h028 */
	union {
		uint32_t ln0_test; // word name
		struct {
			uint32_t ln0_test_en : 2;
			uint32_t : 6; // padding bits
			uint32_t ln0_test_lp : 4;
			uint32_t : 4; // padding bits
			uint32_t ln0_test_hs : 8;
			uint32_t : 8; // padding bits
		};
	};
	/* LN1_TEST 10'h02C */
	union {
		uint32_t ln1_test; // word name
		struct {
			uint32_t ln1_test_en : 2;
			uint32_t : 6; // padding bits
			uint32_t ln1_test_lp : 4;
			uint32_t : 4; // padding bits
			uint32_t ln1_test_hs : 8;
			uint32_t : 8; // padding bits
		};
	};
	/* LN2_TEST 10'h030 */
	union {
		uint32_t ln2_test; // word name
		struct {
			uint32_t ln2_test_en : 2;
			uint32_t : 6; // padding bits
			uint32_t ln2_test_lp : 4;
			uint32_t : 4; // padding bits
			uint32_t ln2_test_hs : 8;
			uint32_t : 8; // padding bits
		};
	};
	/* LN3_TEST 10'h034 */
	union {
		uint32_t ln3_test; // word name
		struct {
			uint32_t ln3_test_en : 2;
			uint32_t : 6; // padding bits
			uint32_t ln3_test_lp : 4;
			uint32_t : 4; // padding bits
			uint32_t ln3_test_hs : 8;
			uint32_t : 8; // padding bits
		};
	};
	/* LN4_TEST 10'h038 */
	union {
		uint32_t ln4_test; // word name
		struct {
			uint32_t ln4_test_en : 2;
			uint32_t : 6; // padding bits
			uint32_t ln4_test_lp : 4;
			uint32_t : 4; // padding bits
			uint32_t ln4_test_hs : 8;
			uint32_t : 8; // padding bits
		};
	};
	/* TXOUT_03 10'h03C [Unused] */
	uint32_t empty_word_txout_03;
	/* LN0_STA 10'h040 */
	union {
		uint32_t ln0_sta; // word name
		struct {
			uint32_t ln0_rx_sta : 4;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* DBGSTA 10'h044 */
	union {
		uint32_t dbgsta; // word name
		struct {
			uint32_t debug_sta : 32;
		};
	};
	/* DBGSEL 10'h048 */
	union {
		uint32_t dbgsel; // word name
		struct {
			uint32_t debug_sel : 4;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
} CsrBankTx_out;

#endif