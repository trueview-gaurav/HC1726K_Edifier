/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef CSR_TABLE_SAADCCTR_H_
#define CSR_TABLE_SAADCCTR_H_

#include <stdint.h>

CsrFieldEntry csr_field_table_saadcctr[] = {
	// WORD mode
	{ "ctrl_mode", 0x00000000, 0, 0, CSR_RW, 0x00000001 },
	{ "calibration_on", 0x00000000, 8, 8, CSR_RW, 0x00000001 },
	{ "parallel_mode", 0x00000000, 16, 16, CSR_RW, 0x00000001 },
	{ "single_end_mode", 0x00000000, 24, 24, CSR_RW, 0x00000001 },
	{ "MODE", 0x00000000, 31, 0, CSR_RW, 0x00000000 },
	// WORD adc_ctrl0
	{ "start", 0x00000004, 0, 0, CSR_W1P, 0x00000000 },
	{ "calibration_swset", 0x00000004, 8, 8, CSR_W1P, 0x00000000 },
	{ "bist_catch_start", 0x00000004, 16, 16, CSR_W1P, 0x00000000 },
	{ "dbg_start", 0x00000004, 20, 20, CSR_W1P, 0x00000000 },
	{ "dbg_stop", 0x00000004, 24, 24, CSR_W1P, 0x00000000 },
	{ "ADC_CTRL0", 0x00000004, 31, 0, CSR_W1P, 0x00000000 },
	// WORD adc_ctrl1
	{ "enbgp", 0x00000008, 0, 0, CSR_RW, 0x00000000 },
	{ "enbias", 0x00000008, 8, 8, CSR_RW, 0x00000000 },
	{ "enamp", 0x00000008, 17, 16, CSR_RW, 0x00000000 },
	{ "enadc", 0x00000008, 24, 24, CSR_RW, 0x00000000 },
	{ "ADC_CTRL1", 0x00000008, 31, 0, CSR_RW, 0x00000000 },
	// WORD adc_ctrl2
	{ "spwr", 0x0000000C, 0, 0, CSR_RW, 0x00000000 },
	{ "calp_wr", 0x0000000C, 10, 8, CSR_RW, 0x00000000 },
	{ "caln_wr", 0x0000000C, 18, 16, CSR_RW, 0x00000000 },
	{ "calibration_times", 0x0000000C, 28, 24, CSR_RW, 0x0000000A },
	{ "ADC_CTRL2", 0x0000000C, 31, 0, CSR_RW, 0x00000000 },
	// WORD adc_ctrl3
	{ "ch_en", 0x00000010, 3, 0, CSR_RW, 0x0000000F },
	{ "tsensor_enable", 0x00000010, 4, 4, CSR_RW, 0x00000000 },
	{ "bgchop_en", 0x00000010, 8, 8, CSR_RW, 0x00000000 },
	{ "ampchop_en", 0x00000010, 16, 16, CSR_RW, 0x00000000 },
	{ "bist_catch_ch", 0x00000010, 31, 24, CSR_RW, 0x00000001 },
	{ "ADC_CTRL3", 0x00000010, 31, 0, CSR_RW, 0x00000000 },
	// WORD adc_ctrl4
	{ "vcmsel", 0x00000014, 5, 0, CSR_RW, 0x0000003E },
	{ "vrefpsel", 0x00000014, 13, 8, CSR_RW, 0x00000017 },
	{ "ADC_CTRL4", 0x00000014, 31, 0, CSR_RW, 0x00000000 },
	// WORD cycle0
	{ "sample_cycle", 0x00000018, 15, 0, CSR_RW, 0x00000000 },
	{ "sample_pre_cycle", 0x00000018, 31, 16, CSR_RW, 0x00000000 },
	{ "CYCLE0", 0x00000018, 31, 0, CSR_RW, 0x00000000 },
	// WORD cycle1
	{ "saadccs_ck_half_cycle", 0x0000001C, 15, 0, CSR_RW, 0x00000000 },
	{ "none_overlap_cycle", 0x0000001C, 31, 16, CSR_RW, 0x00000000 },
	{ "CYCLE1", 0x0000001C, 31, 0, CSR_RW, 0x00000000 },
	// WORD irq_mask0
	{ "irq_mask_saadc_real_stop", 0x00000020, 0, 0, CSR_RW, 0x00000001 },
	{ "irq_mask_no_ack", 0x00000020, 4, 4, CSR_RW, 0x00000001 },
	{ "irq_mask_hw_calibration_fail", 0x00000020, 8, 8, CSR_RW, 0x00000001 },
	{ "irq_mask_hw_calibration_done", 0x00000020, 12, 12, CSR_RW, 0x00000001 },
	{ "irq_mask_ch0_sample_done", 0x00000020, 16, 16, CSR_RW, 0x00000001 },
	{ "irq_mask_ch1_sample_done", 0x00000020, 20, 20, CSR_RW, 0x00000001 },
	{ "irq_mask_ch2_sample_done", 0x00000020, 24, 24, CSR_RW, 0x00000001 },
	{ "irq_mask_ch3_sample_done", 0x00000020, 28, 28, CSR_RW, 0x00000001 },
	{ "IRQ_MASK0", 0x00000020, 31, 0, CSR_RW, 0x00000000 },
	// WORD irq_clear0
	{ "irq_clear_saadc_real_stop", 0x00000024, 0, 0, CSR_W1P, 0x00000000 },
	{ "irq_clear_no_ack", 0x00000024, 4, 4, CSR_W1P, 0x00000000 },
	{ "irq_clear_hw_calibration_fail", 0x00000024, 8, 8, CSR_W1P, 0x00000000 },
	{ "irq_clear_hw_calibration_done", 0x00000024, 12, 12, CSR_W1P, 0x00000000 },
	{ "irq_clear_ch0_sample_done", 0x00000024, 16, 16, CSR_W1P, 0x00000000 },
	{ "irq_clear_ch1_sample_done", 0x00000024, 20, 20, CSR_W1P, 0x00000000 },
	{ "irq_clear_ch2_sample_done", 0x00000024, 24, 24, CSR_W1P, 0x00000000 },
	{ "irq_clear_ch3_sample_done", 0x00000024, 28, 28, CSR_W1P, 0x00000000 },
	{ "IRQ_CLEAR0", 0x00000024, 31, 0, CSR_W1P, 0x00000000 },
	// WORD irq_status0
	{ "irq_status_saadc_real_stop", 0x00000028, 0, 0, CSR_RO, 0x00000000 },
	{ "irq_status_no_ack", 0x00000028, 4, 4, CSR_RO, 0x00000000 },
	{ "irq_status_hw_calibration_fail", 0x00000028, 8, 8, CSR_RO, 0x00000000 },
	{ "irq_status_hw_calibration_done", 0x00000028, 12, 12, CSR_RO, 0x00000000 },
	{ "irq_status_ch0_sample_done", 0x00000028, 16, 16, CSR_RO, 0x00000000 },
	{ "irq_status_ch1_sample_done", 0x00000028, 20, 20, CSR_RO, 0x00000000 },
	{ "irq_status_ch2_sample_done", 0x00000028, 24, 24, CSR_RO, 0x00000000 },
	{ "irq_status_ch3_sample_done", 0x00000028, 28, 28, CSR_RO, 0x00000000 },
	{ "IRQ_STATUS0", 0x00000028, 31, 0, CSR_RO, 0x00000000 },
	// WORD status0
	{ "saadc_kernel_idle", 0x0000002C, 0, 0, CSR_RO, 0x00000000 },
	{ "ch0_kernel_idle", 0x0000002C, 4, 4, CSR_RO, 0x00000000 },
	{ "ch1_kernel_idle", 0x0000002C, 8, 8, CSR_RO, 0x00000000 },
	{ "ch2_kernel_idle", 0x0000002C, 12, 12, CSR_RO, 0x00000000 },
	{ "ch3_kernel_idle", 0x0000002C, 16, 16, CSR_RO, 0x00000000 },
	{ "STATUS0", 0x0000002C, 31, 0, CSR_RO, 0x00000000 },
	// WORD status1
	{ "calp_rd", 0x00000030, 2, 0, CSR_RO, 0x00000000 },
	{ "caln_rd", 0x00000030, 10, 8, CSR_RO, 0x00000000 },
	{ "cmpo_p", 0x00000030, 23, 16, CSR_RO, 0x00000000 },
	{ "cmpo_n", 0x00000030, 31, 24, CSR_RO, 0x00000000 },
	{ "STATUS1", 0x00000030, 31, 0, CSR_RO, 0x00000000 },
	// WORD saadc_reg0
	{ "rg_saadccs_enext", 0x00000034, 0, 0, CSR_RW, 0x00000000 },
	{ "rg_saadccs_engpi", 0x00000034, 27, 24, CSR_RW, 0x00000000 },
	{ "SAADC_REG0", 0x00000034, 31, 0, CSR_RW, 0x00000000 },
	// WORD reserved00
	{ "reserved", 0x00000038, 31, 0, CSR_RW, 0x00000000 },
	{ "RESERVED00", 0x00000038, 31, 0, CSR_RW, 0x00000000 },
	// WORD dbg0
	{ "dbg_data0", 0x0000003C, 31, 0, CSR_RO, 0x00000000 },
	{ "DBG0", 0x0000003C, 31, 0, CSR_RO, 0x00000000 },
	// WORD dbg1
	{ "dbg_data1", 0x00000040, 31, 0, CSR_RO, 0x00000000 },
	{ "DBG1", 0x00000040, 31, 0, CSR_RO, 0x00000000 },
	// WORD dbg2
	{ "dbg_data2", 0x00000044, 31, 0, CSR_RO, 0x00000000 },
	{ "DBG2", 0x00000044, 31, 0, CSR_RO, 0x00000000 },
	// WORD dbg3
	{ "dbg_data3", 0x00000048, 31, 0, CSR_RO, 0x00000000 },
	{ "DBG3", 0x00000048, 31, 0, CSR_RO, 0x00000000 },
	// WORD saadc_ctrl_period0
	{ "period_1us", 0x0000004C, 15, 0, CSR_RW, 0x000000C8 },
	{ "period_10us", 0x0000004C, 31, 16, CSR_RW, 0x000007D0 },
	{ "SAADC_CTRL_PERIOD0", 0x0000004C, 31, 0, CSR_RW, 0x00000000 },
	// WORD saadc_ctrl_period1
	{ "period_20us", 0x00000050, 15, 0, CSR_RW, 0x00000FA0 },
	{ "period_30us", 0x00000050, 31, 16, CSR_RW, 0x00001770 },
	{ "SAADC_CTRL_PERIOD1", 0x00000050, 31, 0, CSR_RW, 0x00000000 },
	// WORD saadc_ctrl_period2
	{ "period_40us", 0x00000054, 15, 0, CSR_RW, 0x00001F40 },
	{ "SAADC_CTRL_PERIOD2", 0x00000054, 31, 0, CSR_RW, 0x00000000 },
	// WORD adc_stat_ctrl0
	{ "sample_mode_ch0", 0x00000058, 0, 0, CSR_RW, 0x00000000 },
	{ "sample_mode_ch1", 0x00000058, 2, 2, CSR_RW, 0x00000000 },
	{ "sample_mode_ch2", 0x00000058, 4, 4, CSR_RW, 0x00000000 },
	{ "sample_mode_ch3", 0x00000058, 8, 8, CSR_RW, 0x00000000 },
	{ "sample_data_num_ch0", 0x00000058, 21, 12, CSR_RW, 0x00000000 },
	{ "sample_data_num_ch1", 0x00000058, 31, 22, CSR_RW, 0x00000000 },
	{ "ADC_STAT_CTRL0", 0x00000058, 31, 0, CSR_RW, 0x00000000 },
	// WORD adc_stat_ctrl1
	{ "sample_data_num_ch2", 0x0000005C, 9, 0, CSR_RW, 0x00000000 },
	{ "sample_data_num_ch3", 0x0000005C, 25, 16, CSR_RW, 0x00000000 },
	{ "ADC_STAT_CTRL1", 0x0000005C, 31, 0, CSR_RW, 0x00000000 },
	// WORD stat_one_shot_result
	{ "saadc_data_ch0", 0x00000060, 7, 0, CSR_RO, 0x00000000 },
	{ "saadc_data_ch1", 0x00000060, 15, 8, CSR_RO, 0x00000000 },
	{ "saadc_data_ch2", 0x00000060, 23, 16, CSR_RO, 0x00000000 },
	{ "saadc_data_ch3", 0x00000060, 31, 24, CSR_RO, 0x00000000 },
	{ "STAT_ONE_SHOT_RESULT", 0x00000060, 31, 0, CSR_RO, 0x00000000 },
	// WORD stat_oversample_max
	{ "max_ch0", 0x00000064, 7, 0, CSR_RO, 0x00000000 },
	{ "max_ch1", 0x00000064, 15, 8, CSR_RO, 0x00000000 },
	{ "max_ch2", 0x00000064, 23, 16, CSR_RO, 0x00000000 },
	{ "max_ch3", 0x00000064, 31, 24, CSR_RO, 0x00000000 },
	{ "STAT_OVERSAMPLE_MAX", 0x00000064, 31, 0, CSR_RO, 0x00000000 },
	// WORD stat_oversample_min
	{ "min_ch0", 0x00000068, 7, 0, CSR_RO, 0x00000000 },
	{ "min_ch1", 0x00000068, 15, 8, CSR_RO, 0x00000000 },
	{ "min_ch2", 0x00000068, 23, 16, CSR_RO, 0x00000000 },
	{ "min_ch3", 0x00000068, 31, 24, CSR_RO, 0x00000000 },
	{ "STAT_OVERSAMPLE_MIN", 0x00000068, 31, 0, CSR_RO, 0x00000000 },
	// WORD stat_oversample_sum0
	{ "sum_ch0", 0x0000006C, 17, 0, CSR_RO, 0x00000000 },
	{ "STAT_OVERSAMPLE_SUM0", 0x0000006C, 31, 0, CSR_RO, 0x00000000 },
	// WORD stat_oversample_sum1
	{ "sum_ch1", 0x00000070, 17, 0, CSR_RO, 0x00000000 },
	{ "STAT_OVERSAMPLE_SUM1", 0x00000070, 31, 0, CSR_RO, 0x00000000 },
	// WORD stat_oversample_sum2
	{ "sum_ch2", 0x00000074, 17, 0, CSR_RO, 0x00000000 },
	{ "STAT_OVERSAMPLE_SUM2", 0x00000074, 31, 0, CSR_RO, 0x00000000 },
	// WORD stat_oversample_sum3
	{ "sum_ch3", 0x00000078, 17, 0, CSR_RO, 0x00000000 },
	{ "STAT_OVERSAMPLE_SUM3", 0x00000078, 31, 0, CSR_RO, 0x00000000 },
	// WORD stat_oversample_avg0
	{ "avg_ch0", 0x0000007C, 17, 0, CSR_RO, 0x00000000 },
	{ "STAT_OVERSAMPLE_AVG0", 0x0000007C, 31, 0, CSR_RO, 0x00000000 },
	// WORD stat_oversample_avg1
	{ "avg_ch1", 0x00000080, 17, 0, CSR_RO, 0x00000000 },
	{ "STAT_OVERSAMPLE_AVG1", 0x00000080, 31, 0, CSR_RO, 0x00000000 },
	// WORD stat_oversample_avg2
	{ "avg_ch2", 0x00000084, 17, 0, CSR_RO, 0x00000000 },
	{ "STAT_OVERSAMPLE_AVG2", 0x00000084, 31, 0, CSR_RO, 0x00000000 },
	// WORD stat_oversample_avg3
	{ "avg_ch3", 0x00000088, 17, 0, CSR_RO, 0x00000000 },
	{ "STAT_OVERSAMPLE_AVG3", 0x00000088, 31, 0, CSR_RO, 0x00000000 },
	// WORD bist_ctrl0_ch0
	{ "ch0_upper_th", 0x0000008C, 17, 0, CSR_RW, 0x00000064 },
	{ "BIST_CTRL0_CH0", 0x0000008C, 31, 0, CSR_RW, 0x00000000 },
	// WORD bist_ctrl1_ch0
	{ "ch0_lower_th", 0x00000090, 17, 0, CSR_RW, 0x00000000 },
	{ "BIST_CTRL1_CH0", 0x00000090, 31, 0, CSR_RW, 0x00000000 },
	// WORD bist_ctrl0_ch1
	{ "ch1_upper_th", 0x00000094, 17, 0, CSR_RW, 0x00000064 },
	{ "BIST_CTRL0_CH1", 0x00000094, 31, 0, CSR_RW, 0x00000000 },
	// WORD bist_ctrl1_ch1
	{ "ch1_lower_th", 0x00000098, 17, 0, CSR_RW, 0x00000000 },
	{ "BIST_CTRL1_CH1", 0x00000098, 31, 0, CSR_RW, 0x00000000 },
	// WORD bist_ctrl0_ch2
	{ "ch2_upper_th", 0x0000009C, 17, 0, CSR_RW, 0x00000064 },
	{ "BIST_CTRL0_CH2", 0x0000009C, 31, 0, CSR_RW, 0x00000000 },
	// WORD bist_ctrl1_ch2
	{ "ch2_lower_th", 0x000000A0, 17, 0, CSR_RW, 0x00000000 },
	{ "BIST_CTRL1_CH2", 0x000000A0, 31, 0, CSR_RW, 0x00000000 },
	// WORD bist_ctrl0_ch3
	{ "ch3_upper_th", 0x000000A4, 17, 0, CSR_RW, 0x00000064 },
	{ "BIST_CTRL0_CH3", 0x000000A4, 31, 0, CSR_RW, 0x00000000 },
	// WORD bist_ctrl1_ch3
	{ "ch3_lower_th", 0x000000A8, 17, 0, CSR_RW, 0x00000000 },
	{ "BIST_CTRL1_CH3", 0x000000A8, 31, 0, CSR_RW, 0x00000000 },
	// WORD bist_result
	{ "ch0_test_result", 0x000000AC, 0, 0, CSR_RO, 0x00000000 },
	{ "ch1_test_result", 0x000000AC, 1, 1, CSR_RO, 0x00000000 },
	{ "ch2_test_result", 0x000000AC, 2, 2, CSR_RO, 0x00000000 },
	{ "ch3_test_result", 0x000000AC, 3, 3, CSR_RO, 0x00000000 },
	{ "BIST_RESULT", 0x000000AC, 31, 0, CSR_RO, 0x00000000 },
	// end of table
	{ 0, 0, 0, 0, 0, 0 }
};

#endif // CSR_TABLE_SAADCCTR_H_
