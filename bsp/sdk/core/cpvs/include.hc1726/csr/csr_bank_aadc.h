/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef CSR_BANK_AADC_H_
#define CSR_BANK_AADC_H_

#ifndef __KERNEL__
#include <stdint.h>
#else
#include <linux/types.h>
#endif

/***  C struct generated from aadc  ***/
typedef struct csr_bank_aadc {
	/* AADC_CTRL_MODE 10'h000 */
	union {
		uint32_t aadc_ctrl_mode; // word name
		struct {
			uint32_t power_on_ctrl_mode : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* AADC_CTRL_POWER_ON_OFF 10'h004 */
	union {
		uint32_t aadc_ctrl_power_on_off; // word name
		struct {
			uint32_t start : 1;
			uint32_t : 7; // padding bits
			uint32_t stop : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* AADC_CTRL_ENABLE 10'h008 */
	union {
		uint32_t aadc_ctrl_enable; // word name
		struct {
			uint32_t ph_enable : 1;
			uint32_t : 7; // padding bits
			uint32_t bgchop_enable : 1;
			uint32_t : 7; // padding bits
			uint32_t chpa_enable : 1;
			uint32_t : 7; // padding bits
			uint32_t ref_chpa_enable : 1;
			uint32_t : 7; // padding bits
		};
	};
	/* AADC_CTRL_CYCLE 10'h00C */
	union {
		uint32_t aadc_ctrl_cycle; // word name
		struct {
			uint32_t ph_cycle : 8;
			uint32_t ph_prolong_cycle : 8;
			uint32_t chpa_cycle : 8;
			uint32_t refchpa_cycle : 8;
		};
	};
	/* AADC_CTRL0 10'h010 */
	union {
		uint32_t aadc_ctrl0; // word name
		struct {
			uint32_t enbgp : 1;
			uint32_t : 7; // padding bits
			uint32_t enbias : 1;
			uint32_t : 7; // padding bits
			uint32_t enref : 1;
			uint32_t : 7; // padding bits
			uint32_t ensdm : 1;
			uint32_t : 7; // padding bits
		};
	};
	/* AADC_CTRL1 10'h014 */
	union {
		uint32_t aadc_ctrl1; // word name
		struct {
			uint32_t resetb : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* AADC_CTRL_IRQ_MASK 10'h018 */
	union {
		uint32_t aadc_ctrl_irq_mask; // word name
		struct {
			uint32_t irq_mask_aadc_real_stop : 1;
			uint32_t : 7; // padding bits
			uint32_t irq_mask_no_ack : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* AADC_CTRL_IRQ_CLEAR 10'h01C */
	union {
		uint32_t aadc_ctrl_irq_clear; // word name
		struct {
			uint32_t irq_clear_aadc_real_stop : 1;
			uint32_t : 7; // padding bits
			uint32_t irq_clear_no_ack : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* AADC_CTRL_STATUS 10'h020 */
	union {
		uint32_t aadc_ctrl_status; // word name
		struct {
			uint32_t status_aadc_real_stop : 1;
			uint32_t : 7; // padding bits
			uint32_t status_no_ack : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* AADC_CTRL_PERIOD0 10'h024 */
	union {
		uint32_t aadc_ctrl_period0; // word name
		struct {
			uint32_t period_10us : 16;
			uint32_t period_20us : 16;
		};
	};
	/* AADC_CTRL_PERIOD1 10'h028 */
	union {
		uint32_t aadc_ctrl_period1; // word name
		struct {
			uint32_t period_30us : 16;
			uint32_t period_40us : 16;
		};
	};
	/* AADC_CTRL_PERIOD2 10'h02C */
	union {
		uint32_t aadc_ctrl_period2; // word name
		struct {
			uint32_t period_50us : 16;
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* AADC_PHY_REG00 10'h030 */
	union {
		uint32_t aadc_phy_reg00; // word name
		struct {
			uint32_t rg_aadc_bsel1 : 2;
			uint32_t : 6; // padding bits
			uint32_t rg_aadc_bsel2 : 2;
			uint32_t : 6; // padding bits
			uint32_t rg_aadc_vrefpsel : 3;
			uint32_t : 5; // padding bits
			uint32_t rg_aadc_vcmsel : 3;
			uint32_t : 5; // padding bits
		};
	};
	/* AADC_PHY_REG01 10'h034 */
	union {
		uint32_t aadc_phy_reg01; // word name
		struct {
			uint32_t rg_aadc_enbgchop : 1;
			uint32_t : 7; // padding bits
			uint32_t rg_aadc_iminus : 1;
			uint32_t : 7; // padding bits
			uint32_t rg_aadc_iplus : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* AADC_RESERVED00 10'h038 */
	union {
		uint32_t aadc_reserved00; // word name
		struct {
			uint32_t reserved : 32;
		};
	};
	/* PREAMP_REG0 10'h03C */
	union {
		uint32_t preamp_reg0; // word name
		struct {
			uint32_t rg_apreamp_cal_en : 1;
			uint32_t : 7; // padding bits
			uint32_t rg_apreamp_cal_sel : 8;
			uint32_t rg_apreamp_sw1_en : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* PREAMP_REG1 10'h040 */
	union {
		uint32_t preamp_reg1; // word name
		struct {
			uint32_t rg_apreamp_en : 1;
			uint32_t : 7; // padding bits
			uint32_t rg_apreamp_bias_en : 1;
			uint32_t : 7; // padding bits
			uint32_t rg_apreamp_gain_sel : 3;
			uint32_t : 5; // padding bits
			uint32_t apreamp_gain_sel : 1;
			uint32_t : 7; // padding bits
		};
	};
} CsrBankAadc;

#endif