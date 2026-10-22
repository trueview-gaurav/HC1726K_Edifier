/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef CSR_BANK_AIOC_H_
#define CSR_BANK_AIOC_H_

#ifndef __KERNEL__
#include <stdint.h>
#else
#include <linux/types.h>
#endif

/***  C struct generated from aioc  ***/
typedef struct csr_bank_aioc {
	/* XIN_IOCFG 10'h000 */
	union {
		uint32_t xin_iocfg; // word name
		struct {
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t pad_xin_pcfg : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* RESETB_IOCFG 10'h004 */
	union {
		uint32_t resetb_iocfg; // word name
		struct {
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t pad_resetb_pcfg : 3;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* POWER_CTRL_0_IOCFG 10'h008 */
	union {
		uint32_t power_ctrl_0_iocfg; // word name
		struct {
			uint32_t pad_power_ctrl_0_pu : 1;
			uint32_t pad_power_ctrl_0_pd : 1;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t pad_power_ctrl_0_pcfg : 3;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* POWER_CTRL_1_IOCFG 10'h00C */
	union {
		uint32_t power_ctrl_1_iocfg; // word name
		struct {
			uint32_t pad_power_ctrl_1_pu : 1;
			uint32_t pad_power_ctrl_1_pd : 1;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t pad_power_ctrl_1_pcfg : 3;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* AO_DVP_0_IOCFG 10'h010 */
	union {
		uint32_t ao_dvp_0_iocfg; // word name
		struct {
			uint32_t pad_ao_dvp_0_pu : 1;
			uint32_t pad_ao_dvp_0_pd : 1;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t pad_ao_dvp_0_pcfg : 3;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* AO_DVP_1_IOCFG 10'h014 */
	union {
		uint32_t ao_dvp_1_iocfg; // word name
		struct {
			uint32_t pad_ao_dvp_1_pu : 1;
			uint32_t pad_ao_dvp_1_pd : 1;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t pad_ao_dvp_1_pcfg : 3;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* AO_DVP_2_IOCFG 10'h018 */
	union {
		uint32_t ao_dvp_2_iocfg; // word name
		struct {
			uint32_t pad_ao_dvp_2_pu : 1;
			uint32_t pad_ao_dvp_2_pd : 1;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t pad_ao_dvp_2_pcfg : 3;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* AO_DVP_3_IOCFG 10'h01C */
	union {
		uint32_t ao_dvp_3_iocfg; // word name
		struct {
			uint32_t pad_ao_dvp_3_pu : 1;
			uint32_t pad_ao_dvp_3_pd : 1;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t pad_ao_dvp_3_pcfg : 3;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* AO_DVP_4_IOCFG 10'h020 */
	union {
		uint32_t ao_dvp_4_iocfg; // word name
		struct {
			uint32_t pad_ao_dvp_4_pu : 1;
			uint32_t pad_ao_dvp_4_pd : 1;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t pad_ao_dvp_4_pcfg : 3;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* AO_DVP_5_IOCFG 10'h024 */
	union {
		uint32_t ao_dvp_5_iocfg; // word name
		struct {
			uint32_t pad_ao_dvp_5_pu : 1;
			uint32_t pad_ao_dvp_5_pd : 1;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t pad_ao_dvp_5_pcfg : 3;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* AO_DVP_6_IOCFG 10'h028 */
	union {
		uint32_t ao_dvp_6_iocfg; // word name
		struct {
			uint32_t pad_ao_dvp_6_pu : 1;
			uint32_t pad_ao_dvp_6_pd : 1;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t pad_ao_dvp_6_pcfg : 3;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* AO_DVP_7_IOCFG 10'h02C */
	union {
		uint32_t ao_dvp_7_iocfg; // word name
		struct {
			uint32_t pad_ao_dvp_7_pu : 1;
			uint32_t pad_ao_dvp_7_pd : 1;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t pad_ao_dvp_7_pcfg : 3;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* AO_DVP_8_IOCFG 10'h030 */
	union {
		uint32_t ao_dvp_8_iocfg; // word name
		struct {
			uint32_t pad_ao_dvp_8_pu : 1;
			uint32_t pad_ao_dvp_8_pd : 1;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t pad_ao_dvp_8_pcfg : 3;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* AO_BUTTON_IOCFG 10'h034 */
	union {
		uint32_t ao_button_iocfg; // word name
		struct {
			uint32_t pad_ao_button_pu : 1;
			uint32_t pad_ao_button_pd : 1;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t pad_ao_button_pcfg : 3;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* AO_WAKEUP_IOCFG 10'h038 */
	union {
		uint32_t ao_wakeup_iocfg; // word name
		struct {
			uint32_t pad_ao_wakeup_pu : 1;
			uint32_t pad_ao_wakeup_pd : 1;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t pad_ao_wakeup_pcfg : 3;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* POWER_CTRL_0_IOSEL 10'h03C */
	union {
		uint32_t power_ctrl_0_iosel; // word name
		struct {
			uint32_t pad_power_ctrl_0_iosel : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* POWER_CTRL_1_IOSEL 10'h040 */
	union {
		uint32_t power_ctrl_1_iosel; // word name
		struct {
			uint32_t pad_power_ctrl_1_iosel : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* AO_DVP_0_IOSEL 10'h044 */
	union {
		uint32_t ao_dvp_0_iosel; // word name
		struct {
			uint32_t pad_ao_dvp_0_iosel : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* AO_DVP_1_IOSEL 10'h048 */
	union {
		uint32_t ao_dvp_1_iosel; // word name
		struct {
			uint32_t pad_ao_dvp_1_iosel : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* AO_DVP_2_IOSEL 10'h04C */
	union {
		uint32_t ao_dvp_2_iosel; // word name
		struct {
			uint32_t pad_ao_dvp_2_iosel : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* AO_DVP_3_IOSEL 10'h050 */
	union {
		uint32_t ao_dvp_3_iosel; // word name
		struct {
			uint32_t pad_ao_dvp_3_iosel : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* AO_DVP_4_IOSEL 10'h054 */
	union {
		uint32_t ao_dvp_4_iosel; // word name
		struct {
			uint32_t pad_ao_dvp_4_iosel : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* AO_DVP_5_IOSEL 10'h058 */
	union {
		uint32_t ao_dvp_5_iosel; // word name
		struct {
			uint32_t pad_ao_dvp_5_iosel : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* AO_DVP_6_IOSEL 10'h05C */
	union {
		uint32_t ao_dvp_6_iosel; // word name
		struct {
			uint32_t pad_ao_dvp_6_iosel : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* AO_DVP_7_IOSEL 10'h060 */
	union {
		uint32_t ao_dvp_7_iosel; // word name
		struct {
			uint32_t pad_ao_dvp_7_iosel : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* AO_DVP_8_IOSEL 10'h064 */
	union {
		uint32_t ao_dvp_8_iosel; // word name
		struct {
			uint32_t pad_ao_dvp_8_iosel : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* AO_BUTTON_IOSEL 10'h068 */
	union {
		uint32_t ao_button_iosel; // word name
		struct {
			uint32_t pad_ao_button_iosel : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* AO_WAKEUP_IOSEL 10'h06C */
	union {
		uint32_t ao_wakeup_iosel; // word name
		struct {
			uint32_t pad_ao_wakeup_iosel : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_TST_SEL 10'h070 */
	union {
		uint32_t word_tst_sel; // word name
		struct {
			uint32_t tst_sel : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
} CsrBankAioc;

#endif