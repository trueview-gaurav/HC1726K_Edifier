/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef CSR_BANK_SAADCCTR_H_
#define CSR_BANK_SAADCCTR_H_

#ifndef __KERNEL__
#include <stdint.h>
#else
#include <linux/types.h>
#endif

/***  C struct generated from saadcctr  ***/
typedef struct csr_bank_saadcctr {
	/* MODE 8'h00 */
	union {
		uint32_t mode; // word name
		struct {
			uint32_t ctrl_mode : 1;
			uint32_t : 7; // padding bits
			uint32_t calibration_on : 1;
			uint32_t : 7; // padding bits
			uint32_t parallel_mode : 1;
			uint32_t : 7; // padding bits
			uint32_t single_end_mode : 1;
			uint32_t : 7; // padding bits
		};
	};
	/* ADC_CTRL0 8'h04 */
	union {
		uint32_t adc_ctrl0; // word name
		struct {
			uint32_t start : 1;
			uint32_t : 7; // padding bits
			uint32_t calibration_swset : 1;
			uint32_t : 7; // padding bits
			uint32_t bist_catch_start : 1;
			uint32_t : 3; // padding bits
			uint32_t dbg_start : 1;
			uint32_t : 3; // padding bits
			uint32_t dbg_stop : 1;
			uint32_t : 7; // padding bits
		};
	};
	/* ADC_CTRL1 8'h08 */
	union {
		uint32_t adc_ctrl1; // word name
		struct {
			uint32_t enbgp : 1;
			uint32_t : 7; // padding bits
			uint32_t enbias : 1;
			uint32_t : 7; // padding bits
			uint32_t enamp : 2;
			uint32_t : 6; // padding bits
			uint32_t enadc : 1;
			uint32_t : 7; // padding bits
		};
	};
	/* ADC_CTRL2 8'h0C */
	union {
		uint32_t adc_ctrl2; // word name
		struct {
			uint32_t spwr : 1;
			uint32_t : 7; // padding bits
			uint32_t calp_wr : 3;
			uint32_t : 5; // padding bits
			uint32_t caln_wr : 3;
			uint32_t : 5; // padding bits
			uint32_t calibration_times : 5;
			uint32_t : 3; // padding bits
		};
	};
	/* ADC_CTRL3 8'h10 */
	union {
		uint32_t adc_ctrl3; // word name
		struct {
			uint32_t ch_en : 4;
			uint32_t tsensor_enable : 1;
			uint32_t : 3; // padding bits
			uint32_t bgchop_en : 1;
			uint32_t : 7; // padding bits
			uint32_t ampchop_en : 1;
			uint32_t : 7; // padding bits
			uint32_t bist_catch_ch : 8;
		};
	};
	/* ADC_CTRL4 8'h14 */
	union {
		uint32_t adc_ctrl4; // word name
		struct {
			uint32_t vcmsel : 6;
			uint32_t : 2; // padding bits
			uint32_t vrefpsel : 6;
			uint32_t : 2; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CYCLE0 8'h18 */
	union {
		uint32_t cycle0; // word name
		struct {
			uint32_t sample_cycle : 16;
			uint32_t sample_pre_cycle : 16;
		};
	};
	/* CYCLE1 8'h1C */
	union {
		uint32_t cycle1; // word name
		struct {
			uint32_t saadccs_ck_half_cycle : 16;
			uint32_t none_overlap_cycle : 16;
		};
	};
	/* IRQ_MASK0 8'h20 */
	union {
		uint32_t irq_mask0; // word name
		struct {
			uint32_t irq_mask_saadc_real_stop : 1;
			uint32_t : 3; // padding bits
			uint32_t irq_mask_no_ack : 1;
			uint32_t : 3; // padding bits
			uint32_t irq_mask_hw_calibration_fail : 1;
			uint32_t : 3; // padding bits
			uint32_t irq_mask_hw_calibration_done : 1;
			uint32_t : 3; // padding bits
			uint32_t irq_mask_ch0_sample_done : 1;
			uint32_t : 3; // padding bits
			uint32_t irq_mask_ch1_sample_done : 1;
			uint32_t : 3; // padding bits
			uint32_t irq_mask_ch2_sample_done : 1;
			uint32_t : 3; // padding bits
			uint32_t irq_mask_ch3_sample_done : 1;
			uint32_t : 3; // padding bits
		};
	};
	/* IRQ_CLEAR0 8'h24 */
	union {
		uint32_t irq_clear0; // word name
		struct {
			uint32_t irq_clear_saadc_real_stop : 1;
			uint32_t : 3; // padding bits
			uint32_t irq_clear_no_ack : 1;
			uint32_t : 3; // padding bits
			uint32_t irq_clear_hw_calibration_fail : 1;
			uint32_t : 3; // padding bits
			uint32_t irq_clear_hw_calibration_done : 1;
			uint32_t : 3; // padding bits
			uint32_t irq_clear_ch0_sample_done : 1;
			uint32_t : 3; // padding bits
			uint32_t irq_clear_ch1_sample_done : 1;
			uint32_t : 3; // padding bits
			uint32_t irq_clear_ch2_sample_done : 1;
			uint32_t : 3; // padding bits
			uint32_t irq_clear_ch3_sample_done : 1;
			uint32_t : 3; // padding bits
		};
	};
	/* IRQ_STATUS0 8'h28 */
	union {
		uint32_t irq_status0; // word name
		struct {
			uint32_t irq_status_saadc_real_stop : 1;
			uint32_t : 3; // padding bits
			uint32_t irq_status_no_ack : 1;
			uint32_t : 3; // padding bits
			uint32_t irq_status_hw_calibration_fail : 1;
			uint32_t : 3; // padding bits
			uint32_t irq_status_hw_calibration_done : 1;
			uint32_t : 3; // padding bits
			uint32_t irq_status_ch0_sample_done : 1;
			uint32_t : 3; // padding bits
			uint32_t irq_status_ch1_sample_done : 1;
			uint32_t : 3; // padding bits
			uint32_t irq_status_ch2_sample_done : 1;
			uint32_t : 3; // padding bits
			uint32_t irq_status_ch3_sample_done : 1;
			uint32_t : 3; // padding bits
		};
	};
	/* STATUS0 8'h2C */
	union {
		uint32_t status0; // word name
		struct {
			uint32_t saadc_kernel_idle : 1;
			uint32_t : 3; // padding bits
			uint32_t ch0_kernel_idle : 1;
			uint32_t : 3; // padding bits
			uint32_t ch1_kernel_idle : 1;
			uint32_t : 3; // padding bits
			uint32_t ch2_kernel_idle : 1;
			uint32_t : 3; // padding bits
			uint32_t ch3_kernel_idle : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* STATUS1 8'h30 */
	union {
		uint32_t status1; // word name
		struct {
			uint32_t calp_rd : 3;
			uint32_t : 5; // padding bits
			uint32_t caln_rd : 3;
			uint32_t : 5; // padding bits
			uint32_t cmpo_p : 8;
			uint32_t cmpo_n : 8;
		};
	};
	/* SAADC_REG0 8'h34 */
	union {
		uint32_t saadc_reg0; // word name
		struct {
			uint32_t rg_saadccs_enext : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t rg_saadccs_engpi : 4;
			uint32_t : 4; // padding bits
		};
	};
	/* RESERVED00 8'h38 */
	union {
		uint32_t reserved00; // word name
		struct {
			uint32_t reserved : 32;
		};
	};
	/* DBG0 8'h3C */
	union {
		uint32_t dbg0; // word name
		struct {
			uint32_t dbg_data0 : 32;
		};
	};
	/* DBG1 8'h40 */
	union {
		uint32_t dbg1; // word name
		struct {
			uint32_t dbg_data1 : 32;
		};
	};
	/* DBG2 8'h44 */
	union {
		uint32_t dbg2; // word name
		struct {
			uint32_t dbg_data2 : 32;
		};
	};
	/* DBG3 8'h48 */
	union {
		uint32_t dbg3; // word name
		struct {
			uint32_t dbg_data3 : 32;
		};
	};
	/* SAADC_CTRL_PERIOD0 8'h4C */
	union {
		uint32_t saadc_ctrl_period0; // word name
		struct {
			uint32_t period_1us : 16;
			uint32_t period_10us : 16;
		};
	};
	/* SAADC_CTRL_PERIOD1 8'h50 */
	union {
		uint32_t saadc_ctrl_period1; // word name
		struct {
			uint32_t period_20us : 16;
			uint32_t period_30us : 16;
		};
	};
	/* SAADC_CTRL_PERIOD2 8'h54 */
	union {
		uint32_t saadc_ctrl_period2; // word name
		struct {
			uint32_t period_40us : 16;
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* ADC_STAT_CTRL0 8'h58 */
	union {
		uint32_t adc_stat_ctrl0; // word name
		struct {
			uint32_t sample_mode_ch0 : 1;
			uint32_t : 1; // padding bits
			uint32_t sample_mode_ch1 : 1;
			uint32_t : 1; // padding bits
			uint32_t sample_mode_ch2 : 1;
			uint32_t : 3; // padding bits
			uint32_t sample_mode_ch3 : 1;
			uint32_t : 3; // padding bits
			uint32_t sample_data_num_ch0 : 10;
			uint32_t sample_data_num_ch1 : 10;
		};
	};
	/* ADC_STAT_CTRL1 8'h5C */
	union {
		uint32_t adc_stat_ctrl1; // word name
		struct {
			uint32_t sample_data_num_ch2 : 10;
			uint32_t : 6; // padding bits
			uint32_t sample_data_num_ch3 : 10;
			uint32_t : 6; // padding bits
		};
	};
	/* STAT_ONE_SHOT_RESULT 8'h60 */
	union {
		uint32_t stat_one_shot_result; // word name
		struct {
			uint32_t saadc_data_ch0 : 8;
			uint32_t saadc_data_ch1 : 8;
			uint32_t saadc_data_ch2 : 8;
			uint32_t saadc_data_ch3 : 8;
		};
	};
	/* STAT_OVERSAMPLE_MAX 8'h64 */
	union {
		uint32_t stat_oversample_max; // word name
		struct {
			uint32_t max_ch0 : 8;
			uint32_t max_ch1 : 8;
			uint32_t max_ch2 : 8;
			uint32_t max_ch3 : 8;
		};
	};
	/* STAT_OVERSAMPLE_MIN 8'h68 */
	union {
		uint32_t stat_oversample_min; // word name
		struct {
			uint32_t min_ch0 : 8;
			uint32_t min_ch1 : 8;
			uint32_t min_ch2 : 8;
			uint32_t min_ch3 : 8;
		};
	};
	/* STAT_OVERSAMPLE_SUM0 8'h6C */
	union {
		uint32_t stat_oversample_sum0; // word name
		struct {
			uint32_t sum_ch0 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* STAT_OVERSAMPLE_SUM1 8'h70 */
	union {
		uint32_t stat_oversample_sum1; // word name
		struct {
			uint32_t sum_ch1 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* STAT_OVERSAMPLE_SUM2 8'h74 */
	union {
		uint32_t stat_oversample_sum2; // word name
		struct {
			uint32_t sum_ch2 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* STAT_OVERSAMPLE_SUM3 8'h78 */
	union {
		uint32_t stat_oversample_sum3; // word name
		struct {
			uint32_t sum_ch3 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* STAT_OVERSAMPLE_AVG0 8'h7C */
	union {
		uint32_t stat_oversample_avg0; // word name
		struct {
			uint32_t avg_ch0 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* STAT_OVERSAMPLE_AVG1 8'h80 */
	union {
		uint32_t stat_oversample_avg1; // word name
		struct {
			uint32_t avg_ch1 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* STAT_OVERSAMPLE_AVG2 8'h84 */
	union {
		uint32_t stat_oversample_avg2; // word name
		struct {
			uint32_t avg_ch2 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* STAT_OVERSAMPLE_AVG3 8'h88 */
	union {
		uint32_t stat_oversample_avg3; // word name
		struct {
			uint32_t avg_ch3 : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* BIST_CTRL0_CH0 8'h8C */
	union {
		uint32_t bist_ctrl0_ch0; // word name
		struct {
			uint32_t ch0_upper_th : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* BIST_CTRL1_CH0 8'h90 */
	union {
		uint32_t bist_ctrl1_ch0; // word name
		struct {
			uint32_t ch0_lower_th : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* BIST_CTRL0_CH1 8'h94 */
	union {
		uint32_t bist_ctrl0_ch1; // word name
		struct {
			uint32_t ch1_upper_th : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* BIST_CTRL1_CH1 8'h98 */
	union {
		uint32_t bist_ctrl1_ch1; // word name
		struct {
			uint32_t ch1_lower_th : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* BIST_CTRL0_CH2 8'h9C */
	union {
		uint32_t bist_ctrl0_ch2; // word name
		struct {
			uint32_t ch2_upper_th : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* BIST_CTRL1_CH2 8'hA0 */
	union {
		uint32_t bist_ctrl1_ch2; // word name
		struct {
			uint32_t ch2_lower_th : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* BIST_CTRL0_CH3 8'hA4 */
	union {
		uint32_t bist_ctrl0_ch3; // word name
		struct {
			uint32_t ch3_upper_th : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* BIST_CTRL1_CH3 8'hA8 */
	union {
		uint32_t bist_ctrl1_ch3; // word name
		struct {
			uint32_t ch3_lower_th : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* BIST_RESULT 8'hAC */
	union {
		uint32_t bist_result; // word name
		struct {
			uint32_t ch0_test_result : 1;
			uint32_t ch1_test_result : 1;
			uint32_t ch2_test_result : 1;
			uint32_t ch3_test_result : 1;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
} CsrBankSaadcctr;

#endif
