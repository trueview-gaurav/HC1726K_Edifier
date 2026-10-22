#ifndef CSR_BANK_PERF_H_
#define CSR_BANK_PERF_H_

#ifndef __KERNEL__
#include <stdint.h>
#else
#include <linux/types.h>
#endif

/***  C struct generated from perf  ***/
typedef struct csr_bank_perf {
	/* LOG_EN 10'h000 */
	union {
		uint32_t log_en; // word name
		struct {
			uint32_t log_start : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* LOG_CFG 10'h004 */
	union {
		uint32_t log_cfg; // word name
		struct {
			uint32_t log_period : 32;
		};
	};
	/* LOG_STA_00 10'h008 */
	union {
		uint32_t log_sta_00; // word name
		struct {
			uint32_t log_hif_wr : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* LOG_STA_01 10'h00C */
	union {
		uint32_t log_sta_01; // word name
		struct {
			uint32_t log_hif_rd : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* LOG_STA_02 10'h010 */
	union {
		uint32_t log_sta_02; // word name
		struct {
			uint32_t log_hif_rmw : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* LOG_STA_03 10'h014 */
	union {
		uint32_t log_sta_03; // word name
		struct {
			uint32_t log_hif_hi_pri_rd : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* LOG_STA_04 10'h018 */
	union {
		uint32_t log_sta_04; // word name
		struct {
			uint32_t log_dfi_wr_data_cycles : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* LOG_STA_05 10'h01C */
	union {
		uint32_t log_sta_05; // word name
		struct {
			uint32_t log_dfi_rd_data_cycles : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* LOG_STA_06 10'h020 */
	union {
		uint32_t log_sta_06; // word name
		struct {
			uint32_t log_hpr_xact_when_critical : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* LOG_STA_07 10'h024 */
	union {
		uint32_t log_sta_07; // word name
		struct {
			uint32_t log_lpr_xact_when_critical : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* LOG_STA_08 10'h028 */
	union {
		uint32_t log_sta_08; // word name
		struct {
			uint32_t log_wr_xact_when_critical : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* LOG_STA_09 10'h02C */
	union {
		uint32_t log_sta_09; // word name
		struct {
			uint32_t log_op_is_activate : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* LOG_STA_10 10'h030 */
	union {
		uint32_t log_sta_10; // word name
		struct {
			uint32_t log_op_is_rd_or_wr : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* LOG_STA_11 10'h034 */
	union {
		uint32_t log_sta_11; // word name
		struct {
			uint32_t log_op_is_rd_activate : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* LOG_STA_12 10'h038 */
	union {
		uint32_t log_sta_12; // word name
		struct {
			uint32_t log_op_is_rd : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* LOG_STA_13 10'h03C */
	union {
		uint32_t log_sta_13; // word name
		struct {
			uint32_t log_op_is_wr : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* LOG_STA_14 10'h040 */
	union {
		uint32_t log_sta_14; // word name
		struct {
			uint32_t log_op_is_precharge : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* LOG_STA_15 10'h044 */
	union {
		uint32_t log_sta_15; // word name
		struct {
			uint32_t log_precharge_for_rdwr : 24;
			uint32_t : 8; // padding bits
		};
	};
	/* LOG_STA_16 10'h048 */
	union {
		uint32_t log_sta_16; // word name
		struct {
			uint32_t log_precharge_for_other : 24;
			uint32_t : 8; // padding bits
		};
	};
	/* LOG_STA_17 10'h04C */
	union {
		uint32_t log_sta_17; // word name
		struct {
			uint32_t log_rdwr_transitions : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* LOG_STA_18 10'h050 */
	union {
		uint32_t log_sta_18; // word name
		struct {
			uint32_t log_write_combine : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* LOG_STA_19 10'h054 */
	union {
		uint32_t log_sta_19; // word name
		struct {
			uint32_t log_war_hazard : 24;
			uint32_t : 8; // padding bits
		};
	};
	/* LOG_STA_20 10'h058 */
	union {
		uint32_t log_sta_20; // word name
		struct {
			uint32_t log_raw_hazard : 24;
			uint32_t : 8; // padding bits
		};
	};
	/* LOG_STA_21 10'h05C */
	union {
		uint32_t log_sta_21; // word name
		struct {
			uint32_t log_waw_hazard : 24;
			uint32_t : 8; // padding bits
		};
	};
	/* LOG_STA_22 10'h060 */
	union {
		uint32_t log_sta_22; // word name
		struct {
			uint32_t log_op_is_enter_selfref : 24;
			uint32_t : 8; // padding bits
		};
	};
	/* LOG_STA_23 10'h064 */
	union {
		uint32_t log_sta_23; // word name
		struct {
			uint32_t log_op_is_enter_powerdown : 24;
			uint32_t : 8; // padding bits
		};
	};
	/* LOG_STA_24 10'h068 */
	union {
		uint32_t log_sta_24; // word name
		struct {
			uint32_t log_op_is_refresh : 24;
			uint32_t : 8; // padding bits
		};
	};
	/* LOG_STA_25 10'h06C */
	union {
		uint32_t log_sta_25; // word name
		struct {
			uint32_t log_op_is_load_mode : 24;
			uint32_t : 8; // padding bits
		};
	};
	/* LOG_STA_26 10'h070 */
	union {
		uint32_t log_sta_26; // word name
		struct {
			uint32_t log_op_is_zqcl : 24;
			uint32_t : 8; // padding bits
		};
	};
	/* LOG_STA_27 10'h074 */
	union {
		uint32_t log_sta_27; // word name
		struct {
			uint32_t log_op_is_zqcs : 24;
			uint32_t : 8; // padding bits
		};
	};
	/* LOG_STA_28 10'h078 */
	union {
		uint32_t log_sta_28; // word name
		struct {
			uint32_t log_selfref_mode : 32;
		};
	};
	/* LOG_STA_29 10'h07C */
	union {
		uint32_t log_sta_29; // word name
		struct {
			uint32_t log_hpr_req_with_nocredit : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* LOG_STA_30 10'h080 */
	union {
		uint32_t log_sta_30; // word name
		struct {
			uint32_t log_lpr_req_with_nocredit : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* LOG_STA_31 10'h084 */
	union {
		uint32_t log_sta_31; // word name
		struct {
			uint32_t log_op_is_crit_ref : 24;
			uint32_t : 8; // padding bits
		};
	};
	/* LOG_STA_32 10'h088 */
	union {
		uint32_t log_sta_32; // word name
		struct {
			uint32_t log_op_is_spec_ref : 24;
			uint32_t : 8; // padding bits
		};
	};
	/* LOG_STA_33 10'h08C */
	union {
		uint32_t log_sta_33; // word name
		struct {
			uint32_t log_bank_rec_0 : 32;
		};
	};
	/* LOG_STA_34 10'h090 */
	union {
		uint32_t log_sta_34; // word name
		struct {
			uint32_t log_bank_rec_1 : 32;
		};
	};
	/* LOG_STA_35 10'h094 */
	union {
		uint32_t log_sta_35; // word name
		struct {
			uint32_t log_bank_rec_2 : 32;
		};
	};
	/* LOG_STA_36 10'h098 */
	union {
		uint32_t log_sta_36; // word name
		struct {
			uint32_t log_bank_rec_3 : 32;
		};
	};
} CsrBankPerf;

#endif