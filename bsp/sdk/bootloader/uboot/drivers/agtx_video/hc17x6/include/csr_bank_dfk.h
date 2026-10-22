#ifndef CSR_BANK_DFK_H_
#define CSR_BANK_DFK_H_

#ifndef __KERNEL__
#include <stdint.h>
#else
#include <linux/types.h>
#endif

/***  C struct generated from dfk  ***/
typedef struct csr_bank_dfk {
	/* WORD_FRAME_START 14'h0000 */
	union {
		uint32_t word_frame_start; // word name
		struct {
			uint32_t frame_start : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* IRQ_CLEAR 14'h0004 */
	union {
		uint32_t irq_clear; // word name
		struct {
			uint32_t irq_clear_frame_end : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* STATUS 14'h0008 */
	union {
		uint32_t status; // word name
		struct {
			uint32_t status_frame_end : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* IRQ_MASK 14'h000C */
	union {
		uint32_t irq_mask; // word name
		struct {
			uint32_t irq_mask_frame_end : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* DFK_MODE 14'h0010 */
	union {
		uint32_t dfk_mode; // word name
		struct {
			uint32_t deflicker_enable : 1;
			uint32_t : 7; // padding bits
			uint32_t deflicker_bypass : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* SENSOR_SETTING_00 14'h0014 */
	union {
		uint32_t sensor_setting_00; // word name
		struct {
			uint32_t line_per_period : 10;
			uint32_t : 6; // padding bits
			uint32_t bayer_ini_phase_i : 2;
			uint32_t : 6; // padding bits
			uint32_t cfa_mode : 2;
			uint32_t : 6; // padding bits
		};
	};
	/* SENSOR_SETTING_01 14'h0018 */
	union {
		uint32_t sensor_setting_01; // word name
		struct {
			uint32_t width : 16;
			uint32_t height : 16;
		};
	};
	/* CFA_PHASE_SETTING_0 14'h001C */
	union {
		uint32_t cfa_phase_setting_0; // word name
		struct {
			uint32_t cfa_phase_0 : 3;
			uint32_t : 5; // padding bits
			uint32_t cfa_phase_1 : 3;
			uint32_t : 5; // padding bits
			uint32_t cfa_phase_2 : 3;
			uint32_t : 5; // padding bits
			uint32_t cfa_phase_3 : 3;
			uint32_t : 5; // padding bits
		};
	};
	/* CFA_PHASE_SETTING_1 14'h0020 */
	union {
		uint32_t cfa_phase_setting_1; // word name
		struct {
			uint32_t cfa_phase_4 : 3;
			uint32_t : 5; // padding bits
			uint32_t cfa_phase_5 : 3;
			uint32_t : 5; // padding bits
			uint32_t cfa_phase_6 : 3;
			uint32_t : 5; // padding bits
			uint32_t cfa_phase_7 : 3;
			uint32_t : 5; // padding bits
		};
	};
	/* CFA_PHASE_SETTING_2 14'h0024 */
	union {
		uint32_t cfa_phase_setting_2; // word name
		struct {
			uint32_t cfa_phase_8 : 3;
			uint32_t : 5; // padding bits
			uint32_t cfa_phase_9 : 3;
			uint32_t : 5; // padding bits
			uint32_t cfa_phase_10 : 3;
			uint32_t : 5; // padding bits
			uint32_t cfa_phase_11 : 3;
			uint32_t : 5; // padding bits
		};
	};
	/* CFA_PHASE_SETTING_3 14'h0028 */
	union {
		uint32_t cfa_phase_setting_3; // word name
		struct {
			uint32_t cfa_phase_12 : 3;
			uint32_t : 5; // padding bits
			uint32_t cfa_phase_13 : 3;
			uint32_t : 5; // padding bits
			uint32_t cfa_phase_14 : 3;
			uint32_t : 5; // padding bits
			uint32_t cfa_phase_15 : 3;
			uint32_t : 5; // padding bits
		};
	};
	/* G_LINE_AVG_ROI_X_0 14'h002C */
	union {
		uint32_t g_line_avg_roi_x_0; // word name
		struct {
			uint32_t roi_g_line_avg_sx_0 : 16;
			uint32_t roi_g_line_avg_ex_0 : 16;
		};
	};
	/* G_LINE_AVG_ROI_Y_0 14'h0030 */
	union {
		uint32_t g_line_avg_roi_y_0; // word name
		struct {
			uint32_t roi_g_line_avg_sy_0 : 16;
			uint32_t roi_g_line_avg_ey_0 : 16;
		};
	};
	/* G_LINE_AVG_ROI_X_1 14'h0034 */
	union {
		uint32_t g_line_avg_roi_x_1; // word name
		struct {
			uint32_t roi_g_line_avg_sx_1 : 16;
			uint32_t roi_g_line_avg_ex_1 : 16;
		};
	};
	/* G_LINE_AVG_ROI_Y_1 14'h0038 */
	union {
		uint32_t g_line_avg_roi_y_1; // word name
		struct {
			uint32_t roi_g_line_avg_sy_1 : 16;
			uint32_t roi_g_line_avg_ey_1 : 16;
		};
	};
	/* G_LINE_AVG_ROI_X_2 14'h003C */
	union {
		uint32_t g_line_avg_roi_x_2; // word name
		struct {
			uint32_t roi_g_line_avg_sx_2 : 16;
			uint32_t roi_g_line_avg_ex_2 : 16;
		};
	};
	/* G_LINE_AVG_ROI_Y_2 14'h0040 */
	union {
		uint32_t g_line_avg_roi_y_2; // word name
		struct {
			uint32_t roi_g_line_avg_sy_2 : 16;
			uint32_t roi_g_line_avg_ey_2 : 16;
		};
	};
	/* G_LINE_AVG_ROI_PIX_NUM 14'h0044 */
	union {
		uint32_t g_line_avg_roi_pix_num; // word name
		struct {
			uint32_t roi_g_line_avg_pix_num_0 : 16;
			uint32_t roi_g_line_avg_pix_num_1 : 16;
		};
	};
	/* DFK_X_APPLY_0 14'h0048 */
	union {
		uint32_t dfk_x_apply_0; // word name
		struct {
			uint32_t roi_g_line_avg_pix_num_2 : 16;
			uint32_t amp_x_apply_0 : 16;
		};
	};
	/* DFK_X_APPLY_1 14'h004C */
	union {
		uint32_t dfk_x_apply_1; // word name
		struct {
			uint32_t amp_x_apply_1 : 16;
			uint32_t amp_x_apply_2 : 16;
		};
	};
	/* G_LINE_AVG_ROI_EN 14'h0050 */
	union {
		uint32_t g_line_avg_roi_en; // word name
		struct {
			uint32_t roi_g_line_avg_en_0 : 1;
			uint32_t : 7; // padding bits
			uint32_t roi_g_line_avg_en_1 : 1;
			uint32_t : 7; // padding bits
			uint32_t roi_g_line_avg_en_2 : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* DFK_GAIN_0 14'h0054 */
	union {
		uint32_t dfk_gain_0; // word name
		struct {
			uint32_t dfk_amp_0 : 7;
			uint32_t : 1; // padding bits
			uint32_t dfk_amp_1 : 7;
			uint32_t : 1; // padding bits
			uint32_t dfk_amp_2 : 7;
			uint32_t : 1; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* DFK_PHASE 14'h0058 */
	union {
		uint32_t dfk_phase; // word name
		struct {
			uint32_t dfk_phase_curr : 9;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* DFK_GAIN_1 14'h005C */
	union {
		uint32_t dfk_gain_1; // word name
		struct {
			uint32_t amp_slop_0 : 16;
			uint32_t amp_slop_1 : 16;
		};
	};
	/* WORD_CSR2SRAM_SEL 14'h0060 */
	union {
		uint32_t word_csr2sram_sel; // word name
		struct {
			uint32_t csr2sram_sel : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* ROI_AVG_ADDR 14'h0064 */
	union {
		uint32_t roi_avg_addr; // word name
		struct {
			uint32_t roi_avg_r_addr : 11;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* ROI_R_DATA 14'h0068 */
	union {
		uint32_t roi_r_data; // word name
		struct {
			uint32_t roi_avg_r_data : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* DFK_SIN_0 14'h006C */
	union {
		uint32_t dfk_sin_0; // word name
		struct {
			uint32_t sin_wave_0 : 8;
			uint32_t sin_wave_1 : 8;
			uint32_t sin_wave_2 : 8;
			uint32_t sin_wave_3 : 8;
		};
	};
	/* DFK_SIN_1 14'h0070 */
	union {
		uint32_t dfk_sin_1; // word name
		struct {
			uint32_t sin_wave_4 : 8;
			uint32_t sin_wave_5 : 8;
			uint32_t sin_wave_6 : 8;
			uint32_t sin_wave_7 : 8;
		};
	};
	/* DFK_SIN_2 14'h0074 */
	union {
		uint32_t dfk_sin_2; // word name
		struct {
			uint32_t sin_wave_8 : 8;
			uint32_t sin_wave_9 : 8;
			uint32_t sin_wave_10 : 8;
			uint32_t sin_wave_11 : 8;
		};
	};
	/* DFK_SIN_3 14'h0078 */
	union {
		uint32_t dfk_sin_3; // word name
		struct {
			uint32_t sin_wave_12 : 8;
			uint32_t sin_wave_13 : 8;
			uint32_t sin_wave_14 : 8;
			uint32_t sin_wave_15 : 8;
		};
	};
	/* DFK_SIN_4 14'h007C */
	union {
		uint32_t dfk_sin_4; // word name
		struct {
			uint32_t sin_wave_16 : 8;
			uint32_t sin_wave_17 : 8;
			uint32_t sin_wave_18 : 8;
			uint32_t sin_wave_19 : 8;
		};
	};
	/* DFK_SIN_5 14'h0080 */
	union {
		uint32_t dfk_sin_5; // word name
		struct {
			uint32_t sin_wave_20 : 8;
			uint32_t sin_wave_21 : 8;
			uint32_t sin_wave_22 : 8;
			uint32_t sin_wave_23 : 8;
		};
	};
	/* DFK_SIN_6 14'h0084 */
	union {
		uint32_t dfk_sin_6; // word name
		struct {
			uint32_t sin_wave_24 : 8;
			uint32_t sin_wave_25 : 8;
			uint32_t sin_wave_26 : 8;
			uint32_t sin_wave_27 : 8;
		};
	};
	/* DFK_SIN_7 14'h0088 */
	union {
		uint32_t dfk_sin_7; // word name
		struct {
			uint32_t sin_wave_28 : 8;
			uint32_t sin_wave_29 : 8;
			uint32_t sin_wave_30 : 8;
			uint32_t sin_wave_31 : 8;
		};
	};
	/* DFK_SIN_8 14'h008C */
	union {
		uint32_t dfk_sin_8; // word name
		struct {
			uint32_t sin_wave_32 : 8;
			uint32_t sin_wave_33 : 8;
			uint32_t sin_wave_34 : 8;
			uint32_t sin_wave_35 : 8;
		};
	};
	/* DFK_SIN_9 14'h0090 */
	union {
		uint32_t dfk_sin_9; // word name
		struct {
			uint32_t sin_wave_36 : 8;
			uint32_t sin_wave_37 : 8;
			uint32_t sin_wave_38 : 8;
			uint32_t sin_wave_39 : 8;
		};
	};
	/* DFK_SIN_10 14'h0094 */
	union {
		uint32_t dfk_sin_10; // word name
		struct {
			uint32_t sin_wave_40 : 8;
			uint32_t sin_wave_41 : 8;
			uint32_t sin_wave_42 : 8;
			uint32_t sin_wave_43 : 8;
		};
	};
	/* DFK_SIN_11 14'h0098 */
	union {
		uint32_t dfk_sin_11; // word name
		struct {
			uint32_t sin_wave_44 : 8;
			uint32_t sin_wave_45 : 8;
			uint32_t sin_wave_46 : 8;
			uint32_t sin_wave_47 : 8;
		};
	};
	/* DFK_SIN_12 14'h009C */
	union {
		uint32_t dfk_sin_12; // word name
		struct {
			uint32_t sin_wave_48 : 8;
			uint32_t sin_wave_49 : 8;
			uint32_t sin_wave_50 : 8;
			uint32_t sin_wave_51 : 8;
		};
	};
	/* DFK_SIN_13 14'h00A0 */
	union {
		uint32_t dfk_sin_13; // word name
		struct {
			uint32_t sin_wave_52 : 8;
			uint32_t sin_wave_53 : 8;
			uint32_t sin_wave_54 : 8;
			uint32_t sin_wave_55 : 8;
		};
	};
	/* DFK_SIN_14 14'h00A4 */
	union {
		uint32_t dfk_sin_14; // word name
		struct {
			uint32_t sin_wave_56 : 8;
			uint32_t sin_wave_57 : 8;
			uint32_t sin_wave_58 : 8;
			uint32_t sin_wave_59 : 8;
		};
	};
	/* DFK_SIN_15 14'h00A8 */
	union {
		uint32_t dfk_sin_15; // word name
		struct {
			uint32_t sin_wave_60 : 8;
			uint32_t sin_wave_61 : 8;
			uint32_t sin_wave_62 : 8;
			uint32_t sin_wave_63 : 8;
		};
	};
	/* DFK_SIN_16 14'h00AC */
	union {
		uint32_t dfk_sin_16; // word name
		struct {
			uint32_t sin_wave_64 : 8;
			uint32_t sin_wave_65 : 8;
			uint32_t sin_wave_66 : 8;
			uint32_t sin_wave_67 : 8;
		};
	};
	/* DFK_SIN_17 14'h00B0 */
	union {
		uint32_t dfk_sin_17; // word name
		struct {
			uint32_t sin_wave_68 : 8;
			uint32_t sin_wave_69 : 8;
			uint32_t sin_wave_70 : 8;
			uint32_t sin_wave_71 : 8;
		};
	};
	/* DFK_SIN_18 14'h00B4 */
	union {
		uint32_t dfk_sin_18; // word name
		struct {
			uint32_t sin_wave_72 : 8;
			uint32_t sin_wave_73 : 8;
			uint32_t sin_wave_74 : 8;
			uint32_t sin_wave_75 : 8;
		};
	};
	/* DFK_SIN_19 14'h00B8 */
	union {
		uint32_t dfk_sin_19; // word name
		struct {
			uint32_t sin_wave_76 : 8;
			uint32_t sin_wave_77 : 8;
			uint32_t sin_wave_78 : 8;
			uint32_t sin_wave_79 : 8;
		};
	};
	/* DFK_SIN_20 14'h00BC */
	union {
		uint32_t dfk_sin_20; // word name
		struct {
			uint32_t sin_wave_80 : 8;
			uint32_t sin_wave_81 : 8;
			uint32_t sin_wave_82 : 8;
			uint32_t sin_wave_83 : 8;
		};
	};
	/* DFK_SIN_21 14'h00C0 */
	union {
		uint32_t dfk_sin_21; // word name
		struct {
			uint32_t sin_wave_84 : 8;
			uint32_t sin_wave_85 : 8;
			uint32_t sin_wave_86 : 8;
			uint32_t sin_wave_87 : 8;
		};
	};
	/* DFK_SIN_22 14'h00C4 */
	union {
		uint32_t dfk_sin_22; // word name
		struct {
			uint32_t sin_wave_88 : 8;
			uint32_t sin_wave_89 : 8;
			uint32_t sin_wave_90 : 8;
			uint32_t sin_wave_91 : 8;
		};
	};
	/* DFK_SIN_23 14'h00C8 */
	union {
		uint32_t dfk_sin_23; // word name
		struct {
			uint32_t sin_wave_92 : 8;
			uint32_t sin_wave_93 : 8;
			uint32_t sin_wave_94 : 8;
			uint32_t sin_wave_95 : 8;
		};
	};
	/* DFK_SIN_24 14'h00CC */
	union {
		uint32_t dfk_sin_24; // word name
		struct {
			uint32_t sin_wave_96 : 8;
			uint32_t sin_wave_97 : 8;
			uint32_t sin_wave_98 : 8;
			uint32_t sin_wave_99 : 8;
		};
	};
	/* DFK_SIN_25 14'h00D0 */
	union {
		uint32_t dfk_sin_25; // word name
		struct {
			uint32_t sin_wave_100 : 8;
			uint32_t sin_wave_101 : 8;
			uint32_t sin_wave_102 : 8;
			uint32_t sin_wave_103 : 8;
		};
	};
	/* DFK_SIN_26 14'h00D4 */
	union {
		uint32_t dfk_sin_26; // word name
		struct {
			uint32_t sin_wave_104 : 8;
			uint32_t sin_wave_105 : 8;
			uint32_t sin_wave_106 : 8;
			uint32_t sin_wave_107 : 8;
		};
	};
	/* DFK_SIN_27 14'h00D8 */
	union {
		uint32_t dfk_sin_27; // word name
		struct {
			uint32_t sin_wave_108 : 8;
			uint32_t sin_wave_109 : 8;
			uint32_t sin_wave_110 : 8;
			uint32_t sin_wave_111 : 8;
		};
	};
	/* DFK_SIN_28 14'h00DC */
	union {
		uint32_t dfk_sin_28; // word name
		struct {
			uint32_t sin_wave_112 : 8;
			uint32_t sin_wave_113 : 8;
			uint32_t sin_wave_114 : 8;
			uint32_t sin_wave_115 : 8;
		};
	};
	/* DFK_SIN_29 14'h00E0 */
	union {
		uint32_t dfk_sin_29; // word name
		struct {
			uint32_t sin_wave_116 : 8;
			uint32_t sin_wave_117 : 8;
			uint32_t sin_wave_118 : 8;
			uint32_t sin_wave_119 : 8;
		};
	};
	/* DFK_SIN_30 14'h00E4 */
	union {
		uint32_t dfk_sin_30; // word name
		struct {
			uint32_t sin_wave_120 : 8;
			uint32_t sin_wave_121 : 8;
			uint32_t sin_wave_122 : 8;
			uint32_t sin_wave_123 : 8;
		};
	};
	/* DFK_SIN_31 14'h00E8 */
	union {
		uint32_t dfk_sin_31; // word name
		struct {
			uint32_t sin_wave_124 : 8;
			uint32_t sin_wave_125 : 8;
			uint32_t sin_wave_126 : 8;
			uint32_t sin_wave_127 : 8;
		};
	};
	/* DFK_SIN_32 14'h00EC */
	union {
		uint32_t dfk_sin_32; // word name
		struct {
			uint32_t sin_wave_128 : 8;
			uint32_t sin_wave_ds : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_ATPG_CTRL 14'h00F0 */
	union {
		uint32_t word_atpg_ctrl; // word name
		struct {
			uint32_t atpg_ctrl : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* RESERVED_0 14'h00F4 */
	union {
		uint32_t reserved_0; // word name
		struct {
			uint32_t resevered_0 : 32;
		};
	};
	/* RESERVED_1 14'h00F8 */
	union {
		uint32_t reserved_1; // word name
		struct {
			uint32_t resevered_1 : 32;
		};
	};
	/* FPGA_ROI_R_DATA_0 14'h00FC */
	union {
		uint32_t fpga_roi_r_data_0; // word name
		struct {
			uint32_t roi_avg_r_data_0 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_1 14'h0100 */
	union {
		uint32_t fpga_roi_r_data_1; // word name
		struct {
			uint32_t roi_avg_r_data_1 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_2 14'h0104 */
	union {
		uint32_t fpga_roi_r_data_2; // word name
		struct {
			uint32_t roi_avg_r_data_2 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_3 14'h0108 */
	union {
		uint32_t fpga_roi_r_data_3; // word name
		struct {
			uint32_t roi_avg_r_data_3 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_4 14'h010C */
	union {
		uint32_t fpga_roi_r_data_4; // word name
		struct {
			uint32_t roi_avg_r_data_4 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_5 14'h0110 */
	union {
		uint32_t fpga_roi_r_data_5; // word name
		struct {
			uint32_t roi_avg_r_data_5 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_6 14'h0114 */
	union {
		uint32_t fpga_roi_r_data_6; // word name
		struct {
			uint32_t roi_avg_r_data_6 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_7 14'h0118 */
	union {
		uint32_t fpga_roi_r_data_7; // word name
		struct {
			uint32_t roi_avg_r_data_7 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_8 14'h011C */
	union {
		uint32_t fpga_roi_r_data_8; // word name
		struct {
			uint32_t roi_avg_r_data_8 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_9 14'h0120 */
	union {
		uint32_t fpga_roi_r_data_9; // word name
		struct {
			uint32_t roi_avg_r_data_9 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_10 14'h0124 */
	union {
		uint32_t fpga_roi_r_data_10; // word name
		struct {
			uint32_t roi_avg_r_data_10 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_11 14'h0128 */
	union {
		uint32_t fpga_roi_r_data_11; // word name
		struct {
			uint32_t roi_avg_r_data_11 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_12 14'h012C */
	union {
		uint32_t fpga_roi_r_data_12; // word name
		struct {
			uint32_t roi_avg_r_data_12 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_13 14'h0130 */
	union {
		uint32_t fpga_roi_r_data_13; // word name
		struct {
			uint32_t roi_avg_r_data_13 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_14 14'h0134 */
	union {
		uint32_t fpga_roi_r_data_14; // word name
		struct {
			uint32_t roi_avg_r_data_14 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_15 14'h0138 */
	union {
		uint32_t fpga_roi_r_data_15; // word name
		struct {
			uint32_t roi_avg_r_data_15 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_16 14'h013C */
	union {
		uint32_t fpga_roi_r_data_16; // word name
		struct {
			uint32_t roi_avg_r_data_16 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_17 14'h0140 */
	union {
		uint32_t fpga_roi_r_data_17; // word name
		struct {
			uint32_t roi_avg_r_data_17 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_18 14'h0144 */
	union {
		uint32_t fpga_roi_r_data_18; // word name
		struct {
			uint32_t roi_avg_r_data_18 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_19 14'h0148 */
	union {
		uint32_t fpga_roi_r_data_19; // word name
		struct {
			uint32_t roi_avg_r_data_19 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_20 14'h014C */
	union {
		uint32_t fpga_roi_r_data_20; // word name
		struct {
			uint32_t roi_avg_r_data_20 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_21 14'h0150 */
	union {
		uint32_t fpga_roi_r_data_21; // word name
		struct {
			uint32_t roi_avg_r_data_21 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_22 14'h0154 */
	union {
		uint32_t fpga_roi_r_data_22; // word name
		struct {
			uint32_t roi_avg_r_data_22 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_23 14'h0158 */
	union {
		uint32_t fpga_roi_r_data_23; // word name
		struct {
			uint32_t roi_avg_r_data_23 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_24 14'h015C */
	union {
		uint32_t fpga_roi_r_data_24; // word name
		struct {
			uint32_t roi_avg_r_data_24 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_25 14'h0160 */
	union {
		uint32_t fpga_roi_r_data_25; // word name
		struct {
			uint32_t roi_avg_r_data_25 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_26 14'h0164 */
	union {
		uint32_t fpga_roi_r_data_26; // word name
		struct {
			uint32_t roi_avg_r_data_26 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_27 14'h0168 */
	union {
		uint32_t fpga_roi_r_data_27; // word name
		struct {
			uint32_t roi_avg_r_data_27 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_28 14'h016C */
	union {
		uint32_t fpga_roi_r_data_28; // word name
		struct {
			uint32_t roi_avg_r_data_28 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_29 14'h0170 */
	union {
		uint32_t fpga_roi_r_data_29; // word name
		struct {
			uint32_t roi_avg_r_data_29 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_30 14'h0174 */
	union {
		uint32_t fpga_roi_r_data_30; // word name
		struct {
			uint32_t roi_avg_r_data_30 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_31 14'h0178 */
	union {
		uint32_t fpga_roi_r_data_31; // word name
		struct {
			uint32_t roi_avg_r_data_31 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_32 14'h017C */
	union {
		uint32_t fpga_roi_r_data_32; // word name
		struct {
			uint32_t roi_avg_r_data_32 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_33 14'h0180 */
	union {
		uint32_t fpga_roi_r_data_33; // word name
		struct {
			uint32_t roi_avg_r_data_33 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_34 14'h0184 */
	union {
		uint32_t fpga_roi_r_data_34; // word name
		struct {
			uint32_t roi_avg_r_data_34 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_35 14'h0188 */
	union {
		uint32_t fpga_roi_r_data_35; // word name
		struct {
			uint32_t roi_avg_r_data_35 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_36 14'h018C */
	union {
		uint32_t fpga_roi_r_data_36; // word name
		struct {
			uint32_t roi_avg_r_data_36 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_37 14'h0190 */
	union {
		uint32_t fpga_roi_r_data_37; // word name
		struct {
			uint32_t roi_avg_r_data_37 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_38 14'h0194 */
	union {
		uint32_t fpga_roi_r_data_38; // word name
		struct {
			uint32_t roi_avg_r_data_38 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_39 14'h0198 */
	union {
		uint32_t fpga_roi_r_data_39; // word name
		struct {
			uint32_t roi_avg_r_data_39 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_40 14'h019C */
	union {
		uint32_t fpga_roi_r_data_40; // word name
		struct {
			uint32_t roi_avg_r_data_40 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_41 14'h01A0 */
	union {
		uint32_t fpga_roi_r_data_41; // word name
		struct {
			uint32_t roi_avg_r_data_41 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_42 14'h01A4 */
	union {
		uint32_t fpga_roi_r_data_42; // word name
		struct {
			uint32_t roi_avg_r_data_42 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_43 14'h01A8 */
	union {
		uint32_t fpga_roi_r_data_43; // word name
		struct {
			uint32_t roi_avg_r_data_43 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_44 14'h01AC */
	union {
		uint32_t fpga_roi_r_data_44; // word name
		struct {
			uint32_t roi_avg_r_data_44 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_45 14'h01B0 */
	union {
		uint32_t fpga_roi_r_data_45; // word name
		struct {
			uint32_t roi_avg_r_data_45 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_46 14'h01B4 */
	union {
		uint32_t fpga_roi_r_data_46; // word name
		struct {
			uint32_t roi_avg_r_data_46 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_47 14'h01B8 */
	union {
		uint32_t fpga_roi_r_data_47; // word name
		struct {
			uint32_t roi_avg_r_data_47 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_48 14'h01BC */
	union {
		uint32_t fpga_roi_r_data_48; // word name
		struct {
			uint32_t roi_avg_r_data_48 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_49 14'h01C0 */
	union {
		uint32_t fpga_roi_r_data_49; // word name
		struct {
			uint32_t roi_avg_r_data_49 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_50 14'h01C4 */
	union {
		uint32_t fpga_roi_r_data_50; // word name
		struct {
			uint32_t roi_avg_r_data_50 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_51 14'h01C8 */
	union {
		uint32_t fpga_roi_r_data_51; // word name
		struct {
			uint32_t roi_avg_r_data_51 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_52 14'h01CC */
	union {
		uint32_t fpga_roi_r_data_52; // word name
		struct {
			uint32_t roi_avg_r_data_52 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_53 14'h01D0 */
	union {
		uint32_t fpga_roi_r_data_53; // word name
		struct {
			uint32_t roi_avg_r_data_53 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_54 14'h01D4 */
	union {
		uint32_t fpga_roi_r_data_54; // word name
		struct {
			uint32_t roi_avg_r_data_54 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_55 14'h01D8 */
	union {
		uint32_t fpga_roi_r_data_55; // word name
		struct {
			uint32_t roi_avg_r_data_55 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_56 14'h01DC */
	union {
		uint32_t fpga_roi_r_data_56; // word name
		struct {
			uint32_t roi_avg_r_data_56 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_57 14'h01E0 */
	union {
		uint32_t fpga_roi_r_data_57; // word name
		struct {
			uint32_t roi_avg_r_data_57 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_58 14'h01E4 */
	union {
		uint32_t fpga_roi_r_data_58; // word name
		struct {
			uint32_t roi_avg_r_data_58 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_59 14'h01E8 */
	union {
		uint32_t fpga_roi_r_data_59; // word name
		struct {
			uint32_t roi_avg_r_data_59 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_60 14'h01EC */
	union {
		uint32_t fpga_roi_r_data_60; // word name
		struct {
			uint32_t roi_avg_r_data_60 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_61 14'h01F0 */
	union {
		uint32_t fpga_roi_r_data_61; // word name
		struct {
			uint32_t roi_avg_r_data_61 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_62 14'h01F4 */
	union {
		uint32_t fpga_roi_r_data_62; // word name
		struct {
			uint32_t roi_avg_r_data_62 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_63 14'h01F8 */
	union {
		uint32_t fpga_roi_r_data_63; // word name
		struct {
			uint32_t roi_avg_r_data_63 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_64 14'h01FC */
	union {
		uint32_t fpga_roi_r_data_64; // word name
		struct {
			uint32_t roi_avg_r_data_64 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_65 14'h0200 */
	union {
		uint32_t fpga_roi_r_data_65; // word name
		struct {
			uint32_t roi_avg_r_data_65 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_66 14'h0204 */
	union {
		uint32_t fpga_roi_r_data_66; // word name
		struct {
			uint32_t roi_avg_r_data_66 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_67 14'h0208 */
	union {
		uint32_t fpga_roi_r_data_67; // word name
		struct {
			uint32_t roi_avg_r_data_67 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_68 14'h020C */
	union {
		uint32_t fpga_roi_r_data_68; // word name
		struct {
			uint32_t roi_avg_r_data_68 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_69 14'h0210 */
	union {
		uint32_t fpga_roi_r_data_69; // word name
		struct {
			uint32_t roi_avg_r_data_69 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_70 14'h0214 */
	union {
		uint32_t fpga_roi_r_data_70; // word name
		struct {
			uint32_t roi_avg_r_data_70 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_71 14'h0218 */
	union {
		uint32_t fpga_roi_r_data_71; // word name
		struct {
			uint32_t roi_avg_r_data_71 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_72 14'h021C */
	union {
		uint32_t fpga_roi_r_data_72; // word name
		struct {
			uint32_t roi_avg_r_data_72 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_73 14'h0220 */
	union {
		uint32_t fpga_roi_r_data_73; // word name
		struct {
			uint32_t roi_avg_r_data_73 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_74 14'h0224 */
	union {
		uint32_t fpga_roi_r_data_74; // word name
		struct {
			uint32_t roi_avg_r_data_74 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_75 14'h0228 */
	union {
		uint32_t fpga_roi_r_data_75; // word name
		struct {
			uint32_t roi_avg_r_data_75 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_76 14'h022C */
	union {
		uint32_t fpga_roi_r_data_76; // word name
		struct {
			uint32_t roi_avg_r_data_76 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_77 14'h0230 */
	union {
		uint32_t fpga_roi_r_data_77; // word name
		struct {
			uint32_t roi_avg_r_data_77 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_78 14'h0234 */
	union {
		uint32_t fpga_roi_r_data_78; // word name
		struct {
			uint32_t roi_avg_r_data_78 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_79 14'h0238 */
	union {
		uint32_t fpga_roi_r_data_79; // word name
		struct {
			uint32_t roi_avg_r_data_79 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_80 14'h023C */
	union {
		uint32_t fpga_roi_r_data_80; // word name
		struct {
			uint32_t roi_avg_r_data_80 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_81 14'h0240 */
	union {
		uint32_t fpga_roi_r_data_81; // word name
		struct {
			uint32_t roi_avg_r_data_81 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_82 14'h0244 */
	union {
		uint32_t fpga_roi_r_data_82; // word name
		struct {
			uint32_t roi_avg_r_data_82 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_83 14'h0248 */
	union {
		uint32_t fpga_roi_r_data_83; // word name
		struct {
			uint32_t roi_avg_r_data_83 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_84 14'h024C */
	union {
		uint32_t fpga_roi_r_data_84; // word name
		struct {
			uint32_t roi_avg_r_data_84 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_85 14'h0250 */
	union {
		uint32_t fpga_roi_r_data_85; // word name
		struct {
			uint32_t roi_avg_r_data_85 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_86 14'h0254 */
	union {
		uint32_t fpga_roi_r_data_86; // word name
		struct {
			uint32_t roi_avg_r_data_86 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_87 14'h0258 */
	union {
		uint32_t fpga_roi_r_data_87; // word name
		struct {
			uint32_t roi_avg_r_data_87 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_88 14'h025C */
	union {
		uint32_t fpga_roi_r_data_88; // word name
		struct {
			uint32_t roi_avg_r_data_88 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_89 14'h0260 */
	union {
		uint32_t fpga_roi_r_data_89; // word name
		struct {
			uint32_t roi_avg_r_data_89 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_90 14'h0264 */
	union {
		uint32_t fpga_roi_r_data_90; // word name
		struct {
			uint32_t roi_avg_r_data_90 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_91 14'h0268 */
	union {
		uint32_t fpga_roi_r_data_91; // word name
		struct {
			uint32_t roi_avg_r_data_91 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_92 14'h026C */
	union {
		uint32_t fpga_roi_r_data_92; // word name
		struct {
			uint32_t roi_avg_r_data_92 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_93 14'h0270 */
	union {
		uint32_t fpga_roi_r_data_93; // word name
		struct {
			uint32_t roi_avg_r_data_93 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_94 14'h0274 */
	union {
		uint32_t fpga_roi_r_data_94; // word name
		struct {
			uint32_t roi_avg_r_data_94 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_95 14'h0278 */
	union {
		uint32_t fpga_roi_r_data_95; // word name
		struct {
			uint32_t roi_avg_r_data_95 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_96 14'h027C */
	union {
		uint32_t fpga_roi_r_data_96; // word name
		struct {
			uint32_t roi_avg_r_data_96 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_97 14'h0280 */
	union {
		uint32_t fpga_roi_r_data_97; // word name
		struct {
			uint32_t roi_avg_r_data_97 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_98 14'h0284 */
	union {
		uint32_t fpga_roi_r_data_98; // word name
		struct {
			uint32_t roi_avg_r_data_98 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_99 14'h0288 */
	union {
		uint32_t fpga_roi_r_data_99; // word name
		struct {
			uint32_t roi_avg_r_data_99 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_100 14'h028C */
	union {
		uint32_t fpga_roi_r_data_100; // word name
		struct {
			uint32_t roi_avg_r_data_100 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_101 14'h0290 */
	union {
		uint32_t fpga_roi_r_data_101; // word name
		struct {
			uint32_t roi_avg_r_data_101 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_102 14'h0294 */
	union {
		uint32_t fpga_roi_r_data_102; // word name
		struct {
			uint32_t roi_avg_r_data_102 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_103 14'h0298 */
	union {
		uint32_t fpga_roi_r_data_103; // word name
		struct {
			uint32_t roi_avg_r_data_103 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_104 14'h029C */
	union {
		uint32_t fpga_roi_r_data_104; // word name
		struct {
			uint32_t roi_avg_r_data_104 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_105 14'h02A0 */
	union {
		uint32_t fpga_roi_r_data_105; // word name
		struct {
			uint32_t roi_avg_r_data_105 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_106 14'h02A4 */
	union {
		uint32_t fpga_roi_r_data_106; // word name
		struct {
			uint32_t roi_avg_r_data_106 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_107 14'h02A8 */
	union {
		uint32_t fpga_roi_r_data_107; // word name
		struct {
			uint32_t roi_avg_r_data_107 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_108 14'h02AC */
	union {
		uint32_t fpga_roi_r_data_108; // word name
		struct {
			uint32_t roi_avg_r_data_108 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_109 14'h02B0 */
	union {
		uint32_t fpga_roi_r_data_109; // word name
		struct {
			uint32_t roi_avg_r_data_109 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_110 14'h02B4 */
	union {
		uint32_t fpga_roi_r_data_110; // word name
		struct {
			uint32_t roi_avg_r_data_110 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_111 14'h02B8 */
	union {
		uint32_t fpga_roi_r_data_111; // word name
		struct {
			uint32_t roi_avg_r_data_111 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_112 14'h02BC */
	union {
		uint32_t fpga_roi_r_data_112; // word name
		struct {
			uint32_t roi_avg_r_data_112 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_113 14'h02C0 */
	union {
		uint32_t fpga_roi_r_data_113; // word name
		struct {
			uint32_t roi_avg_r_data_113 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_114 14'h02C4 */
	union {
		uint32_t fpga_roi_r_data_114; // word name
		struct {
			uint32_t roi_avg_r_data_114 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_115 14'h02C8 */
	union {
		uint32_t fpga_roi_r_data_115; // word name
		struct {
			uint32_t roi_avg_r_data_115 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_116 14'h02CC */
	union {
		uint32_t fpga_roi_r_data_116; // word name
		struct {
			uint32_t roi_avg_r_data_116 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_117 14'h02D0 */
	union {
		uint32_t fpga_roi_r_data_117; // word name
		struct {
			uint32_t roi_avg_r_data_117 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_118 14'h02D4 */
	union {
		uint32_t fpga_roi_r_data_118; // word name
		struct {
			uint32_t roi_avg_r_data_118 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_119 14'h02D8 */
	union {
		uint32_t fpga_roi_r_data_119; // word name
		struct {
			uint32_t roi_avg_r_data_119 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_120 14'h02DC */
	union {
		uint32_t fpga_roi_r_data_120; // word name
		struct {
			uint32_t roi_avg_r_data_120 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_121 14'h02E0 */
	union {
		uint32_t fpga_roi_r_data_121; // word name
		struct {
			uint32_t roi_avg_r_data_121 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_122 14'h02E4 */
	union {
		uint32_t fpga_roi_r_data_122; // word name
		struct {
			uint32_t roi_avg_r_data_122 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_123 14'h02E8 */
	union {
		uint32_t fpga_roi_r_data_123; // word name
		struct {
			uint32_t roi_avg_r_data_123 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_124 14'h02EC */
	union {
		uint32_t fpga_roi_r_data_124; // word name
		struct {
			uint32_t roi_avg_r_data_124 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_125 14'h02F0 */
	union {
		uint32_t fpga_roi_r_data_125; // word name
		struct {
			uint32_t roi_avg_r_data_125 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_126 14'h02F4 */
	union {
		uint32_t fpga_roi_r_data_126; // word name
		struct {
			uint32_t roi_avg_r_data_126 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_127 14'h02F8 */
	union {
		uint32_t fpga_roi_r_data_127; // word name
		struct {
			uint32_t roi_avg_r_data_127 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_128 14'h02FC */
	union {
		uint32_t fpga_roi_r_data_128; // word name
		struct {
			uint32_t roi_avg_r_data_128 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_129 14'h0300 */
	union {
		uint32_t fpga_roi_r_data_129; // word name
		struct {
			uint32_t roi_avg_r_data_129 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_130 14'h0304 */
	union {
		uint32_t fpga_roi_r_data_130; // word name
		struct {
			uint32_t roi_avg_r_data_130 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_131 14'h0308 */
	union {
		uint32_t fpga_roi_r_data_131; // word name
		struct {
			uint32_t roi_avg_r_data_131 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_132 14'h030C */
	union {
		uint32_t fpga_roi_r_data_132; // word name
		struct {
			uint32_t roi_avg_r_data_132 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_133 14'h0310 */
	union {
		uint32_t fpga_roi_r_data_133; // word name
		struct {
			uint32_t roi_avg_r_data_133 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_134 14'h0314 */
	union {
		uint32_t fpga_roi_r_data_134; // word name
		struct {
			uint32_t roi_avg_r_data_134 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_135 14'h0318 */
	union {
		uint32_t fpga_roi_r_data_135; // word name
		struct {
			uint32_t roi_avg_r_data_135 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_136 14'h031C */
	union {
		uint32_t fpga_roi_r_data_136; // word name
		struct {
			uint32_t roi_avg_r_data_136 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_137 14'h0320 */
	union {
		uint32_t fpga_roi_r_data_137; // word name
		struct {
			uint32_t roi_avg_r_data_137 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_138 14'h0324 */
	union {
		uint32_t fpga_roi_r_data_138; // word name
		struct {
			uint32_t roi_avg_r_data_138 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_139 14'h0328 */
	union {
		uint32_t fpga_roi_r_data_139; // word name
		struct {
			uint32_t roi_avg_r_data_139 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_140 14'h032C */
	union {
		uint32_t fpga_roi_r_data_140; // word name
		struct {
			uint32_t roi_avg_r_data_140 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_141 14'h0330 */
	union {
		uint32_t fpga_roi_r_data_141; // word name
		struct {
			uint32_t roi_avg_r_data_141 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_142 14'h0334 */
	union {
		uint32_t fpga_roi_r_data_142; // word name
		struct {
			uint32_t roi_avg_r_data_142 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_143 14'h0338 */
	union {
		uint32_t fpga_roi_r_data_143; // word name
		struct {
			uint32_t roi_avg_r_data_143 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_144 14'h033C */
	union {
		uint32_t fpga_roi_r_data_144; // word name
		struct {
			uint32_t roi_avg_r_data_144 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_145 14'h0340 */
	union {
		uint32_t fpga_roi_r_data_145; // word name
		struct {
			uint32_t roi_avg_r_data_145 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_146 14'h0344 */
	union {
		uint32_t fpga_roi_r_data_146; // word name
		struct {
			uint32_t roi_avg_r_data_146 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_147 14'h0348 */
	union {
		uint32_t fpga_roi_r_data_147; // word name
		struct {
			uint32_t roi_avg_r_data_147 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_148 14'h034C */
	union {
		uint32_t fpga_roi_r_data_148; // word name
		struct {
			uint32_t roi_avg_r_data_148 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_149 14'h0350 */
	union {
		uint32_t fpga_roi_r_data_149; // word name
		struct {
			uint32_t roi_avg_r_data_149 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_150 14'h0354 */
	union {
		uint32_t fpga_roi_r_data_150; // word name
		struct {
			uint32_t roi_avg_r_data_150 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_151 14'h0358 */
	union {
		uint32_t fpga_roi_r_data_151; // word name
		struct {
			uint32_t roi_avg_r_data_151 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_152 14'h035C */
	union {
		uint32_t fpga_roi_r_data_152; // word name
		struct {
			uint32_t roi_avg_r_data_152 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_153 14'h0360 */
	union {
		uint32_t fpga_roi_r_data_153; // word name
		struct {
			uint32_t roi_avg_r_data_153 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_154 14'h0364 */
	union {
		uint32_t fpga_roi_r_data_154; // word name
		struct {
			uint32_t roi_avg_r_data_154 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_155 14'h0368 */
	union {
		uint32_t fpga_roi_r_data_155; // word name
		struct {
			uint32_t roi_avg_r_data_155 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_156 14'h036C */
	union {
		uint32_t fpga_roi_r_data_156; // word name
		struct {
			uint32_t roi_avg_r_data_156 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_157 14'h0370 */
	union {
		uint32_t fpga_roi_r_data_157; // word name
		struct {
			uint32_t roi_avg_r_data_157 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_158 14'h0374 */
	union {
		uint32_t fpga_roi_r_data_158; // word name
		struct {
			uint32_t roi_avg_r_data_158 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_159 14'h0378 */
	union {
		uint32_t fpga_roi_r_data_159; // word name
		struct {
			uint32_t roi_avg_r_data_159 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_160 14'h037C */
	union {
		uint32_t fpga_roi_r_data_160; // word name
		struct {
			uint32_t roi_avg_r_data_160 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_161 14'h0380 */
	union {
		uint32_t fpga_roi_r_data_161; // word name
		struct {
			uint32_t roi_avg_r_data_161 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_162 14'h0384 */
	union {
		uint32_t fpga_roi_r_data_162; // word name
		struct {
			uint32_t roi_avg_r_data_162 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_163 14'h0388 */
	union {
		uint32_t fpga_roi_r_data_163; // word name
		struct {
			uint32_t roi_avg_r_data_163 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_164 14'h038C */
	union {
		uint32_t fpga_roi_r_data_164; // word name
		struct {
			uint32_t roi_avg_r_data_164 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_165 14'h0390 */
	union {
		uint32_t fpga_roi_r_data_165; // word name
		struct {
			uint32_t roi_avg_r_data_165 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_166 14'h0394 */
	union {
		uint32_t fpga_roi_r_data_166; // word name
		struct {
			uint32_t roi_avg_r_data_166 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_167 14'h0398 */
	union {
		uint32_t fpga_roi_r_data_167; // word name
		struct {
			uint32_t roi_avg_r_data_167 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_168 14'h039C */
	union {
		uint32_t fpga_roi_r_data_168; // word name
		struct {
			uint32_t roi_avg_r_data_168 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_169 14'h03A0 */
	union {
		uint32_t fpga_roi_r_data_169; // word name
		struct {
			uint32_t roi_avg_r_data_169 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_170 14'h03A4 */
	union {
		uint32_t fpga_roi_r_data_170; // word name
		struct {
			uint32_t roi_avg_r_data_170 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_171 14'h03A8 */
	union {
		uint32_t fpga_roi_r_data_171; // word name
		struct {
			uint32_t roi_avg_r_data_171 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_172 14'h03AC */
	union {
		uint32_t fpga_roi_r_data_172; // word name
		struct {
			uint32_t roi_avg_r_data_172 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_173 14'h03B0 */
	union {
		uint32_t fpga_roi_r_data_173; // word name
		struct {
			uint32_t roi_avg_r_data_173 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_174 14'h03B4 */
	union {
		uint32_t fpga_roi_r_data_174; // word name
		struct {
			uint32_t roi_avg_r_data_174 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_175 14'h03B8 */
	union {
		uint32_t fpga_roi_r_data_175; // word name
		struct {
			uint32_t roi_avg_r_data_175 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_176 14'h03BC */
	union {
		uint32_t fpga_roi_r_data_176; // word name
		struct {
			uint32_t roi_avg_r_data_176 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_177 14'h03C0 */
	union {
		uint32_t fpga_roi_r_data_177; // word name
		struct {
			uint32_t roi_avg_r_data_177 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_178 14'h03C4 */
	union {
		uint32_t fpga_roi_r_data_178; // word name
		struct {
			uint32_t roi_avg_r_data_178 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_179 14'h03C8 */
	union {
		uint32_t fpga_roi_r_data_179; // word name
		struct {
			uint32_t roi_avg_r_data_179 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_180 14'h03CC */
	union {
		uint32_t fpga_roi_r_data_180; // word name
		struct {
			uint32_t roi_avg_r_data_180 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_181 14'h03D0 */
	union {
		uint32_t fpga_roi_r_data_181; // word name
		struct {
			uint32_t roi_avg_r_data_181 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_182 14'h03D4 */
	union {
		uint32_t fpga_roi_r_data_182; // word name
		struct {
			uint32_t roi_avg_r_data_182 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_183 14'h03D8 */
	union {
		uint32_t fpga_roi_r_data_183; // word name
		struct {
			uint32_t roi_avg_r_data_183 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_184 14'h03DC */
	union {
		uint32_t fpga_roi_r_data_184; // word name
		struct {
			uint32_t roi_avg_r_data_184 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_185 14'h03E0 */
	union {
		uint32_t fpga_roi_r_data_185; // word name
		struct {
			uint32_t roi_avg_r_data_185 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_186 14'h03E4 */
	union {
		uint32_t fpga_roi_r_data_186; // word name
		struct {
			uint32_t roi_avg_r_data_186 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_187 14'h03E8 */
	union {
		uint32_t fpga_roi_r_data_187; // word name
		struct {
			uint32_t roi_avg_r_data_187 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_188 14'h03EC */
	union {
		uint32_t fpga_roi_r_data_188; // word name
		struct {
			uint32_t roi_avg_r_data_188 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_189 14'h03F0 */
	union {
		uint32_t fpga_roi_r_data_189; // word name
		struct {
			uint32_t roi_avg_r_data_189 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_190 14'h03F4 */
	union {
		uint32_t fpga_roi_r_data_190; // word name
		struct {
			uint32_t roi_avg_r_data_190 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_191 14'h03F8 */
	union {
		uint32_t fpga_roi_r_data_191; // word name
		struct {
			uint32_t roi_avg_r_data_191 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_192 14'h03FC */
	union {
		uint32_t fpga_roi_r_data_192; // word name
		struct {
			uint32_t roi_avg_r_data_192 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_193 14'h0400 */
	union {
		uint32_t fpga_roi_r_data_193; // word name
		struct {
			uint32_t roi_avg_r_data_193 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_194 14'h0404 */
	union {
		uint32_t fpga_roi_r_data_194; // word name
		struct {
			uint32_t roi_avg_r_data_194 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_195 14'h0408 */
	union {
		uint32_t fpga_roi_r_data_195; // word name
		struct {
			uint32_t roi_avg_r_data_195 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_196 14'h040C */
	union {
		uint32_t fpga_roi_r_data_196; // word name
		struct {
			uint32_t roi_avg_r_data_196 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_197 14'h0410 */
	union {
		uint32_t fpga_roi_r_data_197; // word name
		struct {
			uint32_t roi_avg_r_data_197 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_198 14'h0414 */
	union {
		uint32_t fpga_roi_r_data_198; // word name
		struct {
			uint32_t roi_avg_r_data_198 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_199 14'h0418 */
	union {
		uint32_t fpga_roi_r_data_199; // word name
		struct {
			uint32_t roi_avg_r_data_199 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_200 14'h041C */
	union {
		uint32_t fpga_roi_r_data_200; // word name
		struct {
			uint32_t roi_avg_r_data_200 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_201 14'h0420 */
	union {
		uint32_t fpga_roi_r_data_201; // word name
		struct {
			uint32_t roi_avg_r_data_201 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_202 14'h0424 */
	union {
		uint32_t fpga_roi_r_data_202; // word name
		struct {
			uint32_t roi_avg_r_data_202 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_203 14'h0428 */
	union {
		uint32_t fpga_roi_r_data_203; // word name
		struct {
			uint32_t roi_avg_r_data_203 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_204 14'h042C */
	union {
		uint32_t fpga_roi_r_data_204; // word name
		struct {
			uint32_t roi_avg_r_data_204 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_205 14'h0430 */
	union {
		uint32_t fpga_roi_r_data_205; // word name
		struct {
			uint32_t roi_avg_r_data_205 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_206 14'h0434 */
	union {
		uint32_t fpga_roi_r_data_206; // word name
		struct {
			uint32_t roi_avg_r_data_206 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_207 14'h0438 */
	union {
		uint32_t fpga_roi_r_data_207; // word name
		struct {
			uint32_t roi_avg_r_data_207 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_208 14'h043C */
	union {
		uint32_t fpga_roi_r_data_208; // word name
		struct {
			uint32_t roi_avg_r_data_208 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_209 14'h0440 */
	union {
		uint32_t fpga_roi_r_data_209; // word name
		struct {
			uint32_t roi_avg_r_data_209 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_210 14'h0444 */
	union {
		uint32_t fpga_roi_r_data_210; // word name
		struct {
			uint32_t roi_avg_r_data_210 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_211 14'h0448 */
	union {
		uint32_t fpga_roi_r_data_211; // word name
		struct {
			uint32_t roi_avg_r_data_211 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_212 14'h044C */
	union {
		uint32_t fpga_roi_r_data_212; // word name
		struct {
			uint32_t roi_avg_r_data_212 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_213 14'h0450 */
	union {
		uint32_t fpga_roi_r_data_213; // word name
		struct {
			uint32_t roi_avg_r_data_213 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_214 14'h0454 */
	union {
		uint32_t fpga_roi_r_data_214; // word name
		struct {
			uint32_t roi_avg_r_data_214 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_215 14'h0458 */
	union {
		uint32_t fpga_roi_r_data_215; // word name
		struct {
			uint32_t roi_avg_r_data_215 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_216 14'h045C */
	union {
		uint32_t fpga_roi_r_data_216; // word name
		struct {
			uint32_t roi_avg_r_data_216 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_217 14'h0460 */
	union {
		uint32_t fpga_roi_r_data_217; // word name
		struct {
			uint32_t roi_avg_r_data_217 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_218 14'h0464 */
	union {
		uint32_t fpga_roi_r_data_218; // word name
		struct {
			uint32_t roi_avg_r_data_218 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_219 14'h0468 */
	union {
		uint32_t fpga_roi_r_data_219; // word name
		struct {
			uint32_t roi_avg_r_data_219 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_220 14'h046C */
	union {
		uint32_t fpga_roi_r_data_220; // word name
		struct {
			uint32_t roi_avg_r_data_220 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_221 14'h0470 */
	union {
		uint32_t fpga_roi_r_data_221; // word name
		struct {
			uint32_t roi_avg_r_data_221 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_222 14'h0474 */
	union {
		uint32_t fpga_roi_r_data_222; // word name
		struct {
			uint32_t roi_avg_r_data_222 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_223 14'h0478 */
	union {
		uint32_t fpga_roi_r_data_223; // word name
		struct {
			uint32_t roi_avg_r_data_223 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_224 14'h047C */
	union {
		uint32_t fpga_roi_r_data_224; // word name
		struct {
			uint32_t roi_avg_r_data_224 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_225 14'h0480 */
	union {
		uint32_t fpga_roi_r_data_225; // word name
		struct {
			uint32_t roi_avg_r_data_225 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_226 14'h0484 */
	union {
		uint32_t fpga_roi_r_data_226; // word name
		struct {
			uint32_t roi_avg_r_data_226 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_227 14'h0488 */
	union {
		uint32_t fpga_roi_r_data_227; // word name
		struct {
			uint32_t roi_avg_r_data_227 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_228 14'h048C */
	union {
		uint32_t fpga_roi_r_data_228; // word name
		struct {
			uint32_t roi_avg_r_data_228 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_229 14'h0490 */
	union {
		uint32_t fpga_roi_r_data_229; // word name
		struct {
			uint32_t roi_avg_r_data_229 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_230 14'h0494 */
	union {
		uint32_t fpga_roi_r_data_230; // word name
		struct {
			uint32_t roi_avg_r_data_230 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_231 14'h0498 */
	union {
		uint32_t fpga_roi_r_data_231; // word name
		struct {
			uint32_t roi_avg_r_data_231 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_232 14'h049C */
	union {
		uint32_t fpga_roi_r_data_232; // word name
		struct {
			uint32_t roi_avg_r_data_232 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_233 14'h04A0 */
	union {
		uint32_t fpga_roi_r_data_233; // word name
		struct {
			uint32_t roi_avg_r_data_233 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_234 14'h04A4 */
	union {
		uint32_t fpga_roi_r_data_234; // word name
		struct {
			uint32_t roi_avg_r_data_234 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_235 14'h04A8 */
	union {
		uint32_t fpga_roi_r_data_235; // word name
		struct {
			uint32_t roi_avg_r_data_235 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_236 14'h04AC */
	union {
		uint32_t fpga_roi_r_data_236; // word name
		struct {
			uint32_t roi_avg_r_data_236 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_237 14'h04B0 */
	union {
		uint32_t fpga_roi_r_data_237; // word name
		struct {
			uint32_t roi_avg_r_data_237 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_238 14'h04B4 */
	union {
		uint32_t fpga_roi_r_data_238; // word name
		struct {
			uint32_t roi_avg_r_data_238 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_239 14'h04B8 */
	union {
		uint32_t fpga_roi_r_data_239; // word name
		struct {
			uint32_t roi_avg_r_data_239 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_240 14'h04BC */
	union {
		uint32_t fpga_roi_r_data_240; // word name
		struct {
			uint32_t roi_avg_r_data_240 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_241 14'h04C0 */
	union {
		uint32_t fpga_roi_r_data_241; // word name
		struct {
			uint32_t roi_avg_r_data_241 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_242 14'h04C4 */
	union {
		uint32_t fpga_roi_r_data_242; // word name
		struct {
			uint32_t roi_avg_r_data_242 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_243 14'h04C8 */
	union {
		uint32_t fpga_roi_r_data_243; // word name
		struct {
			uint32_t roi_avg_r_data_243 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_244 14'h04CC */
	union {
		uint32_t fpga_roi_r_data_244; // word name
		struct {
			uint32_t roi_avg_r_data_244 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_245 14'h04D0 */
	union {
		uint32_t fpga_roi_r_data_245; // word name
		struct {
			uint32_t roi_avg_r_data_245 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_246 14'h04D4 */
	union {
		uint32_t fpga_roi_r_data_246; // word name
		struct {
			uint32_t roi_avg_r_data_246 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_247 14'h04D8 */
	union {
		uint32_t fpga_roi_r_data_247; // word name
		struct {
			uint32_t roi_avg_r_data_247 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_248 14'h04DC */
	union {
		uint32_t fpga_roi_r_data_248; // word name
		struct {
			uint32_t roi_avg_r_data_248 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_249 14'h04E0 */
	union {
		uint32_t fpga_roi_r_data_249; // word name
		struct {
			uint32_t roi_avg_r_data_249 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_250 14'h04E4 */
	union {
		uint32_t fpga_roi_r_data_250; // word name
		struct {
			uint32_t roi_avg_r_data_250 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_251 14'h04E8 */
	union {
		uint32_t fpga_roi_r_data_251; // word name
		struct {
			uint32_t roi_avg_r_data_251 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_252 14'h04EC */
	union {
		uint32_t fpga_roi_r_data_252; // word name
		struct {
			uint32_t roi_avg_r_data_252 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_253 14'h04F0 */
	union {
		uint32_t fpga_roi_r_data_253; // word name
		struct {
			uint32_t roi_avg_r_data_253 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_254 14'h04F4 */
	union {
		uint32_t fpga_roi_r_data_254; // word name
		struct {
			uint32_t roi_avg_r_data_254 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_255 14'h04F8 */
	union {
		uint32_t fpga_roi_r_data_255; // word name
		struct {
			uint32_t roi_avg_r_data_255 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_256 14'h04FC */
	union {
		uint32_t fpga_roi_r_data_256; // word name
		struct {
			uint32_t roi_avg_r_data_256 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_257 14'h0500 */
	union {
		uint32_t fpga_roi_r_data_257; // word name
		struct {
			uint32_t roi_avg_r_data_257 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_258 14'h0504 */
	union {
		uint32_t fpga_roi_r_data_258; // word name
		struct {
			uint32_t roi_avg_r_data_258 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_259 14'h0508 */
	union {
		uint32_t fpga_roi_r_data_259; // word name
		struct {
			uint32_t roi_avg_r_data_259 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_260 14'h050C */
	union {
		uint32_t fpga_roi_r_data_260; // word name
		struct {
			uint32_t roi_avg_r_data_260 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_261 14'h0510 */
	union {
		uint32_t fpga_roi_r_data_261; // word name
		struct {
			uint32_t roi_avg_r_data_261 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_262 14'h0514 */
	union {
		uint32_t fpga_roi_r_data_262; // word name
		struct {
			uint32_t roi_avg_r_data_262 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_263 14'h0518 */
	union {
		uint32_t fpga_roi_r_data_263; // word name
		struct {
			uint32_t roi_avg_r_data_263 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_264 14'h051C */
	union {
		uint32_t fpga_roi_r_data_264; // word name
		struct {
			uint32_t roi_avg_r_data_264 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_265 14'h0520 */
	union {
		uint32_t fpga_roi_r_data_265; // word name
		struct {
			uint32_t roi_avg_r_data_265 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_266 14'h0524 */
	union {
		uint32_t fpga_roi_r_data_266; // word name
		struct {
			uint32_t roi_avg_r_data_266 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_267 14'h0528 */
	union {
		uint32_t fpga_roi_r_data_267; // word name
		struct {
			uint32_t roi_avg_r_data_267 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_268 14'h052C */
	union {
		uint32_t fpga_roi_r_data_268; // word name
		struct {
			uint32_t roi_avg_r_data_268 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_269 14'h0530 */
	union {
		uint32_t fpga_roi_r_data_269; // word name
		struct {
			uint32_t roi_avg_r_data_269 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_270 14'h0534 */
	union {
		uint32_t fpga_roi_r_data_270; // word name
		struct {
			uint32_t roi_avg_r_data_270 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_271 14'h0538 */
	union {
		uint32_t fpga_roi_r_data_271; // word name
		struct {
			uint32_t roi_avg_r_data_271 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_272 14'h053C */
	union {
		uint32_t fpga_roi_r_data_272; // word name
		struct {
			uint32_t roi_avg_r_data_272 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_273 14'h0540 */
	union {
		uint32_t fpga_roi_r_data_273; // word name
		struct {
			uint32_t roi_avg_r_data_273 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_274 14'h0544 */
	union {
		uint32_t fpga_roi_r_data_274; // word name
		struct {
			uint32_t roi_avg_r_data_274 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_275 14'h0548 */
	union {
		uint32_t fpga_roi_r_data_275; // word name
		struct {
			uint32_t roi_avg_r_data_275 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_276 14'h054C */
	union {
		uint32_t fpga_roi_r_data_276; // word name
		struct {
			uint32_t roi_avg_r_data_276 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_277 14'h0550 */
	union {
		uint32_t fpga_roi_r_data_277; // word name
		struct {
			uint32_t roi_avg_r_data_277 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_278 14'h0554 */
	union {
		uint32_t fpga_roi_r_data_278; // word name
		struct {
			uint32_t roi_avg_r_data_278 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_279 14'h0558 */
	union {
		uint32_t fpga_roi_r_data_279; // word name
		struct {
			uint32_t roi_avg_r_data_279 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_280 14'h055C */
	union {
		uint32_t fpga_roi_r_data_280; // word name
		struct {
			uint32_t roi_avg_r_data_280 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_281 14'h0560 */
	union {
		uint32_t fpga_roi_r_data_281; // word name
		struct {
			uint32_t roi_avg_r_data_281 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_282 14'h0564 */
	union {
		uint32_t fpga_roi_r_data_282; // word name
		struct {
			uint32_t roi_avg_r_data_282 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_283 14'h0568 */
	union {
		uint32_t fpga_roi_r_data_283; // word name
		struct {
			uint32_t roi_avg_r_data_283 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_284 14'h056C */
	union {
		uint32_t fpga_roi_r_data_284; // word name
		struct {
			uint32_t roi_avg_r_data_284 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_285 14'h0570 */
	union {
		uint32_t fpga_roi_r_data_285; // word name
		struct {
			uint32_t roi_avg_r_data_285 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_286 14'h0574 */
	union {
		uint32_t fpga_roi_r_data_286; // word name
		struct {
			uint32_t roi_avg_r_data_286 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_287 14'h0578 */
	union {
		uint32_t fpga_roi_r_data_287; // word name
		struct {
			uint32_t roi_avg_r_data_287 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_288 14'h057C */
	union {
		uint32_t fpga_roi_r_data_288; // word name
		struct {
			uint32_t roi_avg_r_data_288 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_289 14'h0580 */
	union {
		uint32_t fpga_roi_r_data_289; // word name
		struct {
			uint32_t roi_avg_r_data_289 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_290 14'h0584 */
	union {
		uint32_t fpga_roi_r_data_290; // word name
		struct {
			uint32_t roi_avg_r_data_290 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_291 14'h0588 */
	union {
		uint32_t fpga_roi_r_data_291; // word name
		struct {
			uint32_t roi_avg_r_data_291 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_292 14'h058C */
	union {
		uint32_t fpga_roi_r_data_292; // word name
		struct {
			uint32_t roi_avg_r_data_292 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_293 14'h0590 */
	union {
		uint32_t fpga_roi_r_data_293; // word name
		struct {
			uint32_t roi_avg_r_data_293 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_294 14'h0594 */
	union {
		uint32_t fpga_roi_r_data_294; // word name
		struct {
			uint32_t roi_avg_r_data_294 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_295 14'h0598 */
	union {
		uint32_t fpga_roi_r_data_295; // word name
		struct {
			uint32_t roi_avg_r_data_295 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_296 14'h059C */
	union {
		uint32_t fpga_roi_r_data_296; // word name
		struct {
			uint32_t roi_avg_r_data_296 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_297 14'h05A0 */
	union {
		uint32_t fpga_roi_r_data_297; // word name
		struct {
			uint32_t roi_avg_r_data_297 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_298 14'h05A4 */
	union {
		uint32_t fpga_roi_r_data_298; // word name
		struct {
			uint32_t roi_avg_r_data_298 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_299 14'h05A8 */
	union {
		uint32_t fpga_roi_r_data_299; // word name
		struct {
			uint32_t roi_avg_r_data_299 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_300 14'h05AC */
	union {
		uint32_t fpga_roi_r_data_300; // word name
		struct {
			uint32_t roi_avg_r_data_300 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_301 14'h05B0 */
	union {
		uint32_t fpga_roi_r_data_301; // word name
		struct {
			uint32_t roi_avg_r_data_301 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_302 14'h05B4 */
	union {
		uint32_t fpga_roi_r_data_302; // word name
		struct {
			uint32_t roi_avg_r_data_302 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_303 14'h05B8 */
	union {
		uint32_t fpga_roi_r_data_303; // word name
		struct {
			uint32_t roi_avg_r_data_303 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_304 14'h05BC */
	union {
		uint32_t fpga_roi_r_data_304; // word name
		struct {
			uint32_t roi_avg_r_data_304 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_305 14'h05C0 */
	union {
		uint32_t fpga_roi_r_data_305; // word name
		struct {
			uint32_t roi_avg_r_data_305 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_306 14'h05C4 */
	union {
		uint32_t fpga_roi_r_data_306; // word name
		struct {
			uint32_t roi_avg_r_data_306 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_307 14'h05C8 */
	union {
		uint32_t fpga_roi_r_data_307; // word name
		struct {
			uint32_t roi_avg_r_data_307 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_308 14'h05CC */
	union {
		uint32_t fpga_roi_r_data_308; // word name
		struct {
			uint32_t roi_avg_r_data_308 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_309 14'h05D0 */
	union {
		uint32_t fpga_roi_r_data_309; // word name
		struct {
			uint32_t roi_avg_r_data_309 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_310 14'h05D4 */
	union {
		uint32_t fpga_roi_r_data_310; // word name
		struct {
			uint32_t roi_avg_r_data_310 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_311 14'h05D8 */
	union {
		uint32_t fpga_roi_r_data_311; // word name
		struct {
			uint32_t roi_avg_r_data_311 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_312 14'h05DC */
	union {
		uint32_t fpga_roi_r_data_312; // word name
		struct {
			uint32_t roi_avg_r_data_312 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_313 14'h05E0 */
	union {
		uint32_t fpga_roi_r_data_313; // word name
		struct {
			uint32_t roi_avg_r_data_313 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_314 14'h05E4 */
	union {
		uint32_t fpga_roi_r_data_314; // word name
		struct {
			uint32_t roi_avg_r_data_314 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_315 14'h05E8 */
	union {
		uint32_t fpga_roi_r_data_315; // word name
		struct {
			uint32_t roi_avg_r_data_315 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_316 14'h05EC */
	union {
		uint32_t fpga_roi_r_data_316; // word name
		struct {
			uint32_t roi_avg_r_data_316 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_317 14'h05F0 */
	union {
		uint32_t fpga_roi_r_data_317; // word name
		struct {
			uint32_t roi_avg_r_data_317 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_318 14'h05F4 */
	union {
		uint32_t fpga_roi_r_data_318; // word name
		struct {
			uint32_t roi_avg_r_data_318 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_319 14'h05F8 */
	union {
		uint32_t fpga_roi_r_data_319; // word name
		struct {
			uint32_t roi_avg_r_data_319 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_320 14'h05FC */
	union {
		uint32_t fpga_roi_r_data_320; // word name
		struct {
			uint32_t roi_avg_r_data_320 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_321 14'h0600 */
	union {
		uint32_t fpga_roi_r_data_321; // word name
		struct {
			uint32_t roi_avg_r_data_321 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_322 14'h0604 */
	union {
		uint32_t fpga_roi_r_data_322; // word name
		struct {
			uint32_t roi_avg_r_data_322 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_323 14'h0608 */
	union {
		uint32_t fpga_roi_r_data_323; // word name
		struct {
			uint32_t roi_avg_r_data_323 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_324 14'h060C */
	union {
		uint32_t fpga_roi_r_data_324; // word name
		struct {
			uint32_t roi_avg_r_data_324 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_325 14'h0610 */
	union {
		uint32_t fpga_roi_r_data_325; // word name
		struct {
			uint32_t roi_avg_r_data_325 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_326 14'h0614 */
	union {
		uint32_t fpga_roi_r_data_326; // word name
		struct {
			uint32_t roi_avg_r_data_326 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_327 14'h0618 */
	union {
		uint32_t fpga_roi_r_data_327; // word name
		struct {
			uint32_t roi_avg_r_data_327 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_328 14'h061C */
	union {
		uint32_t fpga_roi_r_data_328; // word name
		struct {
			uint32_t roi_avg_r_data_328 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_329 14'h0620 */
	union {
		uint32_t fpga_roi_r_data_329; // word name
		struct {
			uint32_t roi_avg_r_data_329 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_330 14'h0624 */
	union {
		uint32_t fpga_roi_r_data_330; // word name
		struct {
			uint32_t roi_avg_r_data_330 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_331 14'h0628 */
	union {
		uint32_t fpga_roi_r_data_331; // word name
		struct {
			uint32_t roi_avg_r_data_331 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_332 14'h062C */
	union {
		uint32_t fpga_roi_r_data_332; // word name
		struct {
			uint32_t roi_avg_r_data_332 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_333 14'h0630 */
	union {
		uint32_t fpga_roi_r_data_333; // word name
		struct {
			uint32_t roi_avg_r_data_333 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_334 14'h0634 */
	union {
		uint32_t fpga_roi_r_data_334; // word name
		struct {
			uint32_t roi_avg_r_data_334 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_335 14'h0638 */
	union {
		uint32_t fpga_roi_r_data_335; // word name
		struct {
			uint32_t roi_avg_r_data_335 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_336 14'h063C */
	union {
		uint32_t fpga_roi_r_data_336; // word name
		struct {
			uint32_t roi_avg_r_data_336 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_337 14'h0640 */
	union {
		uint32_t fpga_roi_r_data_337; // word name
		struct {
			uint32_t roi_avg_r_data_337 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_338 14'h0644 */
	union {
		uint32_t fpga_roi_r_data_338; // word name
		struct {
			uint32_t roi_avg_r_data_338 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_339 14'h0648 */
	union {
		uint32_t fpga_roi_r_data_339; // word name
		struct {
			uint32_t roi_avg_r_data_339 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_340 14'h064C */
	union {
		uint32_t fpga_roi_r_data_340; // word name
		struct {
			uint32_t roi_avg_r_data_340 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_341 14'h0650 */
	union {
		uint32_t fpga_roi_r_data_341; // word name
		struct {
			uint32_t roi_avg_r_data_341 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_342 14'h0654 */
	union {
		uint32_t fpga_roi_r_data_342; // word name
		struct {
			uint32_t roi_avg_r_data_342 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_343 14'h0658 */
	union {
		uint32_t fpga_roi_r_data_343; // word name
		struct {
			uint32_t roi_avg_r_data_343 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_344 14'h065C */
	union {
		uint32_t fpga_roi_r_data_344; // word name
		struct {
			uint32_t roi_avg_r_data_344 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_345 14'h0660 */
	union {
		uint32_t fpga_roi_r_data_345; // word name
		struct {
			uint32_t roi_avg_r_data_345 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_346 14'h0664 */
	union {
		uint32_t fpga_roi_r_data_346; // word name
		struct {
			uint32_t roi_avg_r_data_346 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_347 14'h0668 */
	union {
		uint32_t fpga_roi_r_data_347; // word name
		struct {
			uint32_t roi_avg_r_data_347 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_348 14'h066C */
	union {
		uint32_t fpga_roi_r_data_348; // word name
		struct {
			uint32_t roi_avg_r_data_348 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_349 14'h0670 */
	union {
		uint32_t fpga_roi_r_data_349; // word name
		struct {
			uint32_t roi_avg_r_data_349 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_350 14'h0674 */
	union {
		uint32_t fpga_roi_r_data_350; // word name
		struct {
			uint32_t roi_avg_r_data_350 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_351 14'h0678 */
	union {
		uint32_t fpga_roi_r_data_351; // word name
		struct {
			uint32_t roi_avg_r_data_351 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_352 14'h067C */
	union {
		uint32_t fpga_roi_r_data_352; // word name
		struct {
			uint32_t roi_avg_r_data_352 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_353 14'h0680 */
	union {
		uint32_t fpga_roi_r_data_353; // word name
		struct {
			uint32_t roi_avg_r_data_353 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_354 14'h0684 */
	union {
		uint32_t fpga_roi_r_data_354; // word name
		struct {
			uint32_t roi_avg_r_data_354 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_355 14'h0688 */
	union {
		uint32_t fpga_roi_r_data_355; // word name
		struct {
			uint32_t roi_avg_r_data_355 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_356 14'h068C */
	union {
		uint32_t fpga_roi_r_data_356; // word name
		struct {
			uint32_t roi_avg_r_data_356 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_357 14'h0690 */
	union {
		uint32_t fpga_roi_r_data_357; // word name
		struct {
			uint32_t roi_avg_r_data_357 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_358 14'h0694 */
	union {
		uint32_t fpga_roi_r_data_358; // word name
		struct {
			uint32_t roi_avg_r_data_358 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_359 14'h0698 */
	union {
		uint32_t fpga_roi_r_data_359; // word name
		struct {
			uint32_t roi_avg_r_data_359 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_360 14'h069C */
	union {
		uint32_t fpga_roi_r_data_360; // word name
		struct {
			uint32_t roi_avg_r_data_360 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_361 14'h06A0 */
	union {
		uint32_t fpga_roi_r_data_361; // word name
		struct {
			uint32_t roi_avg_r_data_361 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_362 14'h06A4 */
	union {
		uint32_t fpga_roi_r_data_362; // word name
		struct {
			uint32_t roi_avg_r_data_362 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_363 14'h06A8 */
	union {
		uint32_t fpga_roi_r_data_363; // word name
		struct {
			uint32_t roi_avg_r_data_363 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_364 14'h06AC */
	union {
		uint32_t fpga_roi_r_data_364; // word name
		struct {
			uint32_t roi_avg_r_data_364 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_365 14'h06B0 */
	union {
		uint32_t fpga_roi_r_data_365; // word name
		struct {
			uint32_t roi_avg_r_data_365 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_366 14'h06B4 */
	union {
		uint32_t fpga_roi_r_data_366; // word name
		struct {
			uint32_t roi_avg_r_data_366 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_367 14'h06B8 */
	union {
		uint32_t fpga_roi_r_data_367; // word name
		struct {
			uint32_t roi_avg_r_data_367 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_368 14'h06BC */
	union {
		uint32_t fpga_roi_r_data_368; // word name
		struct {
			uint32_t roi_avg_r_data_368 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_369 14'h06C0 */
	union {
		uint32_t fpga_roi_r_data_369; // word name
		struct {
			uint32_t roi_avg_r_data_369 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_370 14'h06C4 */
	union {
		uint32_t fpga_roi_r_data_370; // word name
		struct {
			uint32_t roi_avg_r_data_370 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_371 14'h06C8 */
	union {
		uint32_t fpga_roi_r_data_371; // word name
		struct {
			uint32_t roi_avg_r_data_371 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_372 14'h06CC */
	union {
		uint32_t fpga_roi_r_data_372; // word name
		struct {
			uint32_t roi_avg_r_data_372 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_373 14'h06D0 */
	union {
		uint32_t fpga_roi_r_data_373; // word name
		struct {
			uint32_t roi_avg_r_data_373 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_374 14'h06D4 */
	union {
		uint32_t fpga_roi_r_data_374; // word name
		struct {
			uint32_t roi_avg_r_data_374 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_375 14'h06D8 */
	union {
		uint32_t fpga_roi_r_data_375; // word name
		struct {
			uint32_t roi_avg_r_data_375 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_376 14'h06DC */
	union {
		uint32_t fpga_roi_r_data_376; // word name
		struct {
			uint32_t roi_avg_r_data_376 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_377 14'h06E0 */
	union {
		uint32_t fpga_roi_r_data_377; // word name
		struct {
			uint32_t roi_avg_r_data_377 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_378 14'h06E4 */
	union {
		uint32_t fpga_roi_r_data_378; // word name
		struct {
			uint32_t roi_avg_r_data_378 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_379 14'h06E8 */
	union {
		uint32_t fpga_roi_r_data_379; // word name
		struct {
			uint32_t roi_avg_r_data_379 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_380 14'h06EC */
	union {
		uint32_t fpga_roi_r_data_380; // word name
		struct {
			uint32_t roi_avg_r_data_380 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_381 14'h06F0 */
	union {
		uint32_t fpga_roi_r_data_381; // word name
		struct {
			uint32_t roi_avg_r_data_381 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_382 14'h06F4 */
	union {
		uint32_t fpga_roi_r_data_382; // word name
		struct {
			uint32_t roi_avg_r_data_382 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_383 14'h06F8 */
	union {
		uint32_t fpga_roi_r_data_383; // word name
		struct {
			uint32_t roi_avg_r_data_383 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_384 14'h06FC */
	union {
		uint32_t fpga_roi_r_data_384; // word name
		struct {
			uint32_t roi_avg_r_data_384 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_385 14'h0700 */
	union {
		uint32_t fpga_roi_r_data_385; // word name
		struct {
			uint32_t roi_avg_r_data_385 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_386 14'h0704 */
	union {
		uint32_t fpga_roi_r_data_386; // word name
		struct {
			uint32_t roi_avg_r_data_386 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_387 14'h0708 */
	union {
		uint32_t fpga_roi_r_data_387; // word name
		struct {
			uint32_t roi_avg_r_data_387 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_388 14'h070C */
	union {
		uint32_t fpga_roi_r_data_388; // word name
		struct {
			uint32_t roi_avg_r_data_388 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_389 14'h0710 */
	union {
		uint32_t fpga_roi_r_data_389; // word name
		struct {
			uint32_t roi_avg_r_data_389 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_390 14'h0714 */
	union {
		uint32_t fpga_roi_r_data_390; // word name
		struct {
			uint32_t roi_avg_r_data_390 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_391 14'h0718 */
	union {
		uint32_t fpga_roi_r_data_391; // word name
		struct {
			uint32_t roi_avg_r_data_391 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_392 14'h071C */
	union {
		uint32_t fpga_roi_r_data_392; // word name
		struct {
			uint32_t roi_avg_r_data_392 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_393 14'h0720 */
	union {
		uint32_t fpga_roi_r_data_393; // word name
		struct {
			uint32_t roi_avg_r_data_393 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_394 14'h0724 */
	union {
		uint32_t fpga_roi_r_data_394; // word name
		struct {
			uint32_t roi_avg_r_data_394 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_395 14'h0728 */
	union {
		uint32_t fpga_roi_r_data_395; // word name
		struct {
			uint32_t roi_avg_r_data_395 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_396 14'h072C */
	union {
		uint32_t fpga_roi_r_data_396; // word name
		struct {
			uint32_t roi_avg_r_data_396 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_397 14'h0730 */
	union {
		uint32_t fpga_roi_r_data_397; // word name
		struct {
			uint32_t roi_avg_r_data_397 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_398 14'h0734 */
	union {
		uint32_t fpga_roi_r_data_398; // word name
		struct {
			uint32_t roi_avg_r_data_398 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_399 14'h0738 */
	union {
		uint32_t fpga_roi_r_data_399; // word name
		struct {
			uint32_t roi_avg_r_data_399 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_400 14'h073C */
	union {
		uint32_t fpga_roi_r_data_400; // word name
		struct {
			uint32_t roi_avg_r_data_400 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_401 14'h0740 */
	union {
		uint32_t fpga_roi_r_data_401; // word name
		struct {
			uint32_t roi_avg_r_data_401 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_402 14'h0744 */
	union {
		uint32_t fpga_roi_r_data_402; // word name
		struct {
			uint32_t roi_avg_r_data_402 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_403 14'h0748 */
	union {
		uint32_t fpga_roi_r_data_403; // word name
		struct {
			uint32_t roi_avg_r_data_403 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_404 14'h074C */
	union {
		uint32_t fpga_roi_r_data_404; // word name
		struct {
			uint32_t roi_avg_r_data_404 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_405 14'h0750 */
	union {
		uint32_t fpga_roi_r_data_405; // word name
		struct {
			uint32_t roi_avg_r_data_405 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_406 14'h0754 */
	union {
		uint32_t fpga_roi_r_data_406; // word name
		struct {
			uint32_t roi_avg_r_data_406 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_407 14'h0758 */
	union {
		uint32_t fpga_roi_r_data_407; // word name
		struct {
			uint32_t roi_avg_r_data_407 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_408 14'h075C */
	union {
		uint32_t fpga_roi_r_data_408; // word name
		struct {
			uint32_t roi_avg_r_data_408 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_409 14'h0760 */
	union {
		uint32_t fpga_roi_r_data_409; // word name
		struct {
			uint32_t roi_avg_r_data_409 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_410 14'h0764 */
	union {
		uint32_t fpga_roi_r_data_410; // word name
		struct {
			uint32_t roi_avg_r_data_410 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_411 14'h0768 */
	union {
		uint32_t fpga_roi_r_data_411; // word name
		struct {
			uint32_t roi_avg_r_data_411 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_412 14'h076C */
	union {
		uint32_t fpga_roi_r_data_412; // word name
		struct {
			uint32_t roi_avg_r_data_412 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_413 14'h0770 */
	union {
		uint32_t fpga_roi_r_data_413; // word name
		struct {
			uint32_t roi_avg_r_data_413 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_414 14'h0774 */
	union {
		uint32_t fpga_roi_r_data_414; // word name
		struct {
			uint32_t roi_avg_r_data_414 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_415 14'h0778 */
	union {
		uint32_t fpga_roi_r_data_415; // word name
		struct {
			uint32_t roi_avg_r_data_415 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_416 14'h077C */
	union {
		uint32_t fpga_roi_r_data_416; // word name
		struct {
			uint32_t roi_avg_r_data_416 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_417 14'h0780 */
	union {
		uint32_t fpga_roi_r_data_417; // word name
		struct {
			uint32_t roi_avg_r_data_417 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_418 14'h0784 */
	union {
		uint32_t fpga_roi_r_data_418; // word name
		struct {
			uint32_t roi_avg_r_data_418 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_419 14'h0788 */
	union {
		uint32_t fpga_roi_r_data_419; // word name
		struct {
			uint32_t roi_avg_r_data_419 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_420 14'h078C */
	union {
		uint32_t fpga_roi_r_data_420; // word name
		struct {
			uint32_t roi_avg_r_data_420 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_421 14'h0790 */
	union {
		uint32_t fpga_roi_r_data_421; // word name
		struct {
			uint32_t roi_avg_r_data_421 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_422 14'h0794 */
	union {
		uint32_t fpga_roi_r_data_422; // word name
		struct {
			uint32_t roi_avg_r_data_422 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_423 14'h0798 */
	union {
		uint32_t fpga_roi_r_data_423; // word name
		struct {
			uint32_t roi_avg_r_data_423 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_424 14'h079C */
	union {
		uint32_t fpga_roi_r_data_424; // word name
		struct {
			uint32_t roi_avg_r_data_424 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_425 14'h07A0 */
	union {
		uint32_t fpga_roi_r_data_425; // word name
		struct {
			uint32_t roi_avg_r_data_425 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_426 14'h07A4 */
	union {
		uint32_t fpga_roi_r_data_426; // word name
		struct {
			uint32_t roi_avg_r_data_426 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_427 14'h07A8 */
	union {
		uint32_t fpga_roi_r_data_427; // word name
		struct {
			uint32_t roi_avg_r_data_427 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_428 14'h07AC */
	union {
		uint32_t fpga_roi_r_data_428; // word name
		struct {
			uint32_t roi_avg_r_data_428 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_429 14'h07B0 */
	union {
		uint32_t fpga_roi_r_data_429; // word name
		struct {
			uint32_t roi_avg_r_data_429 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_430 14'h07B4 */
	union {
		uint32_t fpga_roi_r_data_430; // word name
		struct {
			uint32_t roi_avg_r_data_430 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_431 14'h07B8 */
	union {
		uint32_t fpga_roi_r_data_431; // word name
		struct {
			uint32_t roi_avg_r_data_431 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_432 14'h07BC */
	union {
		uint32_t fpga_roi_r_data_432; // word name
		struct {
			uint32_t roi_avg_r_data_432 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_433 14'h07C0 */
	union {
		uint32_t fpga_roi_r_data_433; // word name
		struct {
			uint32_t roi_avg_r_data_433 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_434 14'h07C4 */
	union {
		uint32_t fpga_roi_r_data_434; // word name
		struct {
			uint32_t roi_avg_r_data_434 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_435 14'h07C8 */
	union {
		uint32_t fpga_roi_r_data_435; // word name
		struct {
			uint32_t roi_avg_r_data_435 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_436 14'h07CC */
	union {
		uint32_t fpga_roi_r_data_436; // word name
		struct {
			uint32_t roi_avg_r_data_436 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_437 14'h07D0 */
	union {
		uint32_t fpga_roi_r_data_437; // word name
		struct {
			uint32_t roi_avg_r_data_437 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_438 14'h07D4 */
	union {
		uint32_t fpga_roi_r_data_438; // word name
		struct {
			uint32_t roi_avg_r_data_438 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_439 14'h07D8 */
	union {
		uint32_t fpga_roi_r_data_439; // word name
		struct {
			uint32_t roi_avg_r_data_439 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_440 14'h07DC */
	union {
		uint32_t fpga_roi_r_data_440; // word name
		struct {
			uint32_t roi_avg_r_data_440 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_441 14'h07E0 */
	union {
		uint32_t fpga_roi_r_data_441; // word name
		struct {
			uint32_t roi_avg_r_data_441 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_442 14'h07E4 */
	union {
		uint32_t fpga_roi_r_data_442; // word name
		struct {
			uint32_t roi_avg_r_data_442 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_443 14'h07E8 */
	union {
		uint32_t fpga_roi_r_data_443; // word name
		struct {
			uint32_t roi_avg_r_data_443 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_444 14'h07EC */
	union {
		uint32_t fpga_roi_r_data_444; // word name
		struct {
			uint32_t roi_avg_r_data_444 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_445 14'h07F0 */
	union {
		uint32_t fpga_roi_r_data_445; // word name
		struct {
			uint32_t roi_avg_r_data_445 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_446 14'h07F4 */
	union {
		uint32_t fpga_roi_r_data_446; // word name
		struct {
			uint32_t roi_avg_r_data_446 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_447 14'h07F8 */
	union {
		uint32_t fpga_roi_r_data_447; // word name
		struct {
			uint32_t roi_avg_r_data_447 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_448 14'h07FC */
	union {
		uint32_t fpga_roi_r_data_448; // word name
		struct {
			uint32_t roi_avg_r_data_448 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_449 14'h0800 */
	union {
		uint32_t fpga_roi_r_data_449; // word name
		struct {
			uint32_t roi_avg_r_data_449 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_450 14'h0804 */
	union {
		uint32_t fpga_roi_r_data_450; // word name
		struct {
			uint32_t roi_avg_r_data_450 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_451 14'h0808 */
	union {
		uint32_t fpga_roi_r_data_451; // word name
		struct {
			uint32_t roi_avg_r_data_451 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_452 14'h080C */
	union {
		uint32_t fpga_roi_r_data_452; // word name
		struct {
			uint32_t roi_avg_r_data_452 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_453 14'h0810 */
	union {
		uint32_t fpga_roi_r_data_453; // word name
		struct {
			uint32_t roi_avg_r_data_453 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_454 14'h0814 */
	union {
		uint32_t fpga_roi_r_data_454; // word name
		struct {
			uint32_t roi_avg_r_data_454 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_455 14'h0818 */
	union {
		uint32_t fpga_roi_r_data_455; // word name
		struct {
			uint32_t roi_avg_r_data_455 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_456 14'h081C */
	union {
		uint32_t fpga_roi_r_data_456; // word name
		struct {
			uint32_t roi_avg_r_data_456 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_457 14'h0820 */
	union {
		uint32_t fpga_roi_r_data_457; // word name
		struct {
			uint32_t roi_avg_r_data_457 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_458 14'h0824 */
	union {
		uint32_t fpga_roi_r_data_458; // word name
		struct {
			uint32_t roi_avg_r_data_458 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_459 14'h0828 */
	union {
		uint32_t fpga_roi_r_data_459; // word name
		struct {
			uint32_t roi_avg_r_data_459 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_460 14'h082C */
	union {
		uint32_t fpga_roi_r_data_460; // word name
		struct {
			uint32_t roi_avg_r_data_460 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_461 14'h0830 */
	union {
		uint32_t fpga_roi_r_data_461; // word name
		struct {
			uint32_t roi_avg_r_data_461 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_462 14'h0834 */
	union {
		uint32_t fpga_roi_r_data_462; // word name
		struct {
			uint32_t roi_avg_r_data_462 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_463 14'h0838 */
	union {
		uint32_t fpga_roi_r_data_463; // word name
		struct {
			uint32_t roi_avg_r_data_463 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_464 14'h083C */
	union {
		uint32_t fpga_roi_r_data_464; // word name
		struct {
			uint32_t roi_avg_r_data_464 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_465 14'h0840 */
	union {
		uint32_t fpga_roi_r_data_465; // word name
		struct {
			uint32_t roi_avg_r_data_465 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_466 14'h0844 */
	union {
		uint32_t fpga_roi_r_data_466; // word name
		struct {
			uint32_t roi_avg_r_data_466 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_467 14'h0848 */
	union {
		uint32_t fpga_roi_r_data_467; // word name
		struct {
			uint32_t roi_avg_r_data_467 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_468 14'h084C */
	union {
		uint32_t fpga_roi_r_data_468; // word name
		struct {
			uint32_t roi_avg_r_data_468 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_469 14'h0850 */
	union {
		uint32_t fpga_roi_r_data_469; // word name
		struct {
			uint32_t roi_avg_r_data_469 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_470 14'h0854 */
	union {
		uint32_t fpga_roi_r_data_470; // word name
		struct {
			uint32_t roi_avg_r_data_470 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_471 14'h0858 */
	union {
		uint32_t fpga_roi_r_data_471; // word name
		struct {
			uint32_t roi_avg_r_data_471 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_472 14'h085C */
	union {
		uint32_t fpga_roi_r_data_472; // word name
		struct {
			uint32_t roi_avg_r_data_472 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_473 14'h0860 */
	union {
		uint32_t fpga_roi_r_data_473; // word name
		struct {
			uint32_t roi_avg_r_data_473 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_474 14'h0864 */
	union {
		uint32_t fpga_roi_r_data_474; // word name
		struct {
			uint32_t roi_avg_r_data_474 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_475 14'h0868 */
	union {
		uint32_t fpga_roi_r_data_475; // word name
		struct {
			uint32_t roi_avg_r_data_475 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_476 14'h086C */
	union {
		uint32_t fpga_roi_r_data_476; // word name
		struct {
			uint32_t roi_avg_r_data_476 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_477 14'h0870 */
	union {
		uint32_t fpga_roi_r_data_477; // word name
		struct {
			uint32_t roi_avg_r_data_477 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_478 14'h0874 */
	union {
		uint32_t fpga_roi_r_data_478; // word name
		struct {
			uint32_t roi_avg_r_data_478 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_479 14'h0878 */
	union {
		uint32_t fpga_roi_r_data_479; // word name
		struct {
			uint32_t roi_avg_r_data_479 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_480 14'h087C */
	union {
		uint32_t fpga_roi_r_data_480; // word name
		struct {
			uint32_t roi_avg_r_data_480 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_481 14'h0880 */
	union {
		uint32_t fpga_roi_r_data_481; // word name
		struct {
			uint32_t roi_avg_r_data_481 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_482 14'h0884 */
	union {
		uint32_t fpga_roi_r_data_482; // word name
		struct {
			uint32_t roi_avg_r_data_482 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_483 14'h0888 */
	union {
		uint32_t fpga_roi_r_data_483; // word name
		struct {
			uint32_t roi_avg_r_data_483 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_484 14'h088C */
	union {
		uint32_t fpga_roi_r_data_484; // word name
		struct {
			uint32_t roi_avg_r_data_484 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_485 14'h0890 */
	union {
		uint32_t fpga_roi_r_data_485; // word name
		struct {
			uint32_t roi_avg_r_data_485 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_486 14'h0894 */
	union {
		uint32_t fpga_roi_r_data_486; // word name
		struct {
			uint32_t roi_avg_r_data_486 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_487 14'h0898 */
	union {
		uint32_t fpga_roi_r_data_487; // word name
		struct {
			uint32_t roi_avg_r_data_487 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_488 14'h089C */
	union {
		uint32_t fpga_roi_r_data_488; // word name
		struct {
			uint32_t roi_avg_r_data_488 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_489 14'h08A0 */
	union {
		uint32_t fpga_roi_r_data_489; // word name
		struct {
			uint32_t roi_avg_r_data_489 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_490 14'h08A4 */
	union {
		uint32_t fpga_roi_r_data_490; // word name
		struct {
			uint32_t roi_avg_r_data_490 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_491 14'h08A8 */
	union {
		uint32_t fpga_roi_r_data_491; // word name
		struct {
			uint32_t roi_avg_r_data_491 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_492 14'h08AC */
	union {
		uint32_t fpga_roi_r_data_492; // word name
		struct {
			uint32_t roi_avg_r_data_492 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_493 14'h08B0 */
	union {
		uint32_t fpga_roi_r_data_493; // word name
		struct {
			uint32_t roi_avg_r_data_493 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_494 14'h08B4 */
	union {
		uint32_t fpga_roi_r_data_494; // word name
		struct {
			uint32_t roi_avg_r_data_494 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_495 14'h08B8 */
	union {
		uint32_t fpga_roi_r_data_495; // word name
		struct {
			uint32_t roi_avg_r_data_495 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_496 14'h08BC */
	union {
		uint32_t fpga_roi_r_data_496; // word name
		struct {
			uint32_t roi_avg_r_data_496 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_497 14'h08C0 */
	union {
		uint32_t fpga_roi_r_data_497; // word name
		struct {
			uint32_t roi_avg_r_data_497 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_498 14'h08C4 */
	union {
		uint32_t fpga_roi_r_data_498; // word name
		struct {
			uint32_t roi_avg_r_data_498 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_499 14'h08C8 */
	union {
		uint32_t fpga_roi_r_data_499; // word name
		struct {
			uint32_t roi_avg_r_data_499 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_500 14'h08CC */
	union {
		uint32_t fpga_roi_r_data_500; // word name
		struct {
			uint32_t roi_avg_r_data_500 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_501 14'h08D0 */
	union {
		uint32_t fpga_roi_r_data_501; // word name
		struct {
			uint32_t roi_avg_r_data_501 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_502 14'h08D4 */
	union {
		uint32_t fpga_roi_r_data_502; // word name
		struct {
			uint32_t roi_avg_r_data_502 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_503 14'h08D8 */
	union {
		uint32_t fpga_roi_r_data_503; // word name
		struct {
			uint32_t roi_avg_r_data_503 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_504 14'h08DC */
	union {
		uint32_t fpga_roi_r_data_504; // word name
		struct {
			uint32_t roi_avg_r_data_504 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_505 14'h08E0 */
	union {
		uint32_t fpga_roi_r_data_505; // word name
		struct {
			uint32_t roi_avg_r_data_505 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_506 14'h08E4 */
	union {
		uint32_t fpga_roi_r_data_506; // word name
		struct {
			uint32_t roi_avg_r_data_506 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_507 14'h08E8 */
	union {
		uint32_t fpga_roi_r_data_507; // word name
		struct {
			uint32_t roi_avg_r_data_507 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_508 14'h08EC */
	union {
		uint32_t fpga_roi_r_data_508; // word name
		struct {
			uint32_t roi_avg_r_data_508 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_509 14'h08F0 */
	union {
		uint32_t fpga_roi_r_data_509; // word name
		struct {
			uint32_t roi_avg_r_data_509 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_510 14'h08F4 */
	union {
		uint32_t fpga_roi_r_data_510; // word name
		struct {
			uint32_t roi_avg_r_data_510 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_511 14'h08F8 */
	union {
		uint32_t fpga_roi_r_data_511; // word name
		struct {
			uint32_t roi_avg_r_data_511 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_512 14'h08FC */
	union {
		uint32_t fpga_roi_r_data_512; // word name
		struct {
			uint32_t roi_avg_r_data_512 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_513 14'h0900 */
	union {
		uint32_t fpga_roi_r_data_513; // word name
		struct {
			uint32_t roi_avg_r_data_513 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_514 14'h0904 */
	union {
		uint32_t fpga_roi_r_data_514; // word name
		struct {
			uint32_t roi_avg_r_data_514 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_515 14'h0908 */
	union {
		uint32_t fpga_roi_r_data_515; // word name
		struct {
			uint32_t roi_avg_r_data_515 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_516 14'h090C */
	union {
		uint32_t fpga_roi_r_data_516; // word name
		struct {
			uint32_t roi_avg_r_data_516 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_517 14'h0910 */
	union {
		uint32_t fpga_roi_r_data_517; // word name
		struct {
			uint32_t roi_avg_r_data_517 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_518 14'h0914 */
	union {
		uint32_t fpga_roi_r_data_518; // word name
		struct {
			uint32_t roi_avg_r_data_518 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_519 14'h0918 */
	union {
		uint32_t fpga_roi_r_data_519; // word name
		struct {
			uint32_t roi_avg_r_data_519 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_520 14'h091C */
	union {
		uint32_t fpga_roi_r_data_520; // word name
		struct {
			uint32_t roi_avg_r_data_520 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_521 14'h0920 */
	union {
		uint32_t fpga_roi_r_data_521; // word name
		struct {
			uint32_t roi_avg_r_data_521 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_522 14'h0924 */
	union {
		uint32_t fpga_roi_r_data_522; // word name
		struct {
			uint32_t roi_avg_r_data_522 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_523 14'h0928 */
	union {
		uint32_t fpga_roi_r_data_523; // word name
		struct {
			uint32_t roi_avg_r_data_523 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_524 14'h092C */
	union {
		uint32_t fpga_roi_r_data_524; // word name
		struct {
			uint32_t roi_avg_r_data_524 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_525 14'h0930 */
	union {
		uint32_t fpga_roi_r_data_525; // word name
		struct {
			uint32_t roi_avg_r_data_525 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_526 14'h0934 */
	union {
		uint32_t fpga_roi_r_data_526; // word name
		struct {
			uint32_t roi_avg_r_data_526 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_527 14'h0938 */
	union {
		uint32_t fpga_roi_r_data_527; // word name
		struct {
			uint32_t roi_avg_r_data_527 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_528 14'h093C */
	union {
		uint32_t fpga_roi_r_data_528; // word name
		struct {
			uint32_t roi_avg_r_data_528 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_529 14'h0940 */
	union {
		uint32_t fpga_roi_r_data_529; // word name
		struct {
			uint32_t roi_avg_r_data_529 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_530 14'h0944 */
	union {
		uint32_t fpga_roi_r_data_530; // word name
		struct {
			uint32_t roi_avg_r_data_530 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_531 14'h0948 */
	union {
		uint32_t fpga_roi_r_data_531; // word name
		struct {
			uint32_t roi_avg_r_data_531 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_532 14'h094C */
	union {
		uint32_t fpga_roi_r_data_532; // word name
		struct {
			uint32_t roi_avg_r_data_532 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_533 14'h0950 */
	union {
		uint32_t fpga_roi_r_data_533; // word name
		struct {
			uint32_t roi_avg_r_data_533 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_534 14'h0954 */
	union {
		uint32_t fpga_roi_r_data_534; // word name
		struct {
			uint32_t roi_avg_r_data_534 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_535 14'h0958 */
	union {
		uint32_t fpga_roi_r_data_535; // word name
		struct {
			uint32_t roi_avg_r_data_535 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_536 14'h095C */
	union {
		uint32_t fpga_roi_r_data_536; // word name
		struct {
			uint32_t roi_avg_r_data_536 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_537 14'h0960 */
	union {
		uint32_t fpga_roi_r_data_537; // word name
		struct {
			uint32_t roi_avg_r_data_537 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_538 14'h0964 */
	union {
		uint32_t fpga_roi_r_data_538; // word name
		struct {
			uint32_t roi_avg_r_data_538 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_539 14'h0968 */
	union {
		uint32_t fpga_roi_r_data_539; // word name
		struct {
			uint32_t roi_avg_r_data_539 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_540 14'h096C */
	union {
		uint32_t fpga_roi_r_data_540; // word name
		struct {
			uint32_t roi_avg_r_data_540 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_541 14'h0970 */
	union {
		uint32_t fpga_roi_r_data_541; // word name
		struct {
			uint32_t roi_avg_r_data_541 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_542 14'h0974 */
	union {
		uint32_t fpga_roi_r_data_542; // word name
		struct {
			uint32_t roi_avg_r_data_542 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_543 14'h0978 */
	union {
		uint32_t fpga_roi_r_data_543; // word name
		struct {
			uint32_t roi_avg_r_data_543 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_544 14'h097C */
	union {
		uint32_t fpga_roi_r_data_544; // word name
		struct {
			uint32_t roi_avg_r_data_544 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_545 14'h0980 */
	union {
		uint32_t fpga_roi_r_data_545; // word name
		struct {
			uint32_t roi_avg_r_data_545 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_546 14'h0984 */
	union {
		uint32_t fpga_roi_r_data_546; // word name
		struct {
			uint32_t roi_avg_r_data_546 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_547 14'h0988 */
	union {
		uint32_t fpga_roi_r_data_547; // word name
		struct {
			uint32_t roi_avg_r_data_547 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_548 14'h098C */
	union {
		uint32_t fpga_roi_r_data_548; // word name
		struct {
			uint32_t roi_avg_r_data_548 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_549 14'h0990 */
	union {
		uint32_t fpga_roi_r_data_549; // word name
		struct {
			uint32_t roi_avg_r_data_549 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_550 14'h0994 */
	union {
		uint32_t fpga_roi_r_data_550; // word name
		struct {
			uint32_t roi_avg_r_data_550 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_551 14'h0998 */
	union {
		uint32_t fpga_roi_r_data_551; // word name
		struct {
			uint32_t roi_avg_r_data_551 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_552 14'h099C */
	union {
		uint32_t fpga_roi_r_data_552; // word name
		struct {
			uint32_t roi_avg_r_data_552 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_553 14'h09A0 */
	union {
		uint32_t fpga_roi_r_data_553; // word name
		struct {
			uint32_t roi_avg_r_data_553 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_554 14'h09A4 */
	union {
		uint32_t fpga_roi_r_data_554; // word name
		struct {
			uint32_t roi_avg_r_data_554 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_555 14'h09A8 */
	union {
		uint32_t fpga_roi_r_data_555; // word name
		struct {
			uint32_t roi_avg_r_data_555 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_556 14'h09AC */
	union {
		uint32_t fpga_roi_r_data_556; // word name
		struct {
			uint32_t roi_avg_r_data_556 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_557 14'h09B0 */
	union {
		uint32_t fpga_roi_r_data_557; // word name
		struct {
			uint32_t roi_avg_r_data_557 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_558 14'h09B4 */
	union {
		uint32_t fpga_roi_r_data_558; // word name
		struct {
			uint32_t roi_avg_r_data_558 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_559 14'h09B8 */
	union {
		uint32_t fpga_roi_r_data_559; // word name
		struct {
			uint32_t roi_avg_r_data_559 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_560 14'h09BC */
	union {
		uint32_t fpga_roi_r_data_560; // word name
		struct {
			uint32_t roi_avg_r_data_560 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_561 14'h09C0 */
	union {
		uint32_t fpga_roi_r_data_561; // word name
		struct {
			uint32_t roi_avg_r_data_561 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_562 14'h09C4 */
	union {
		uint32_t fpga_roi_r_data_562; // word name
		struct {
			uint32_t roi_avg_r_data_562 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_563 14'h09C8 */
	union {
		uint32_t fpga_roi_r_data_563; // word name
		struct {
			uint32_t roi_avg_r_data_563 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_564 14'h09CC */
	union {
		uint32_t fpga_roi_r_data_564; // word name
		struct {
			uint32_t roi_avg_r_data_564 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_565 14'h09D0 */
	union {
		uint32_t fpga_roi_r_data_565; // word name
		struct {
			uint32_t roi_avg_r_data_565 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_566 14'h09D4 */
	union {
		uint32_t fpga_roi_r_data_566; // word name
		struct {
			uint32_t roi_avg_r_data_566 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_567 14'h09D8 */
	union {
		uint32_t fpga_roi_r_data_567; // word name
		struct {
			uint32_t roi_avg_r_data_567 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_568 14'h09DC */
	union {
		uint32_t fpga_roi_r_data_568; // word name
		struct {
			uint32_t roi_avg_r_data_568 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_569 14'h09E0 */
	union {
		uint32_t fpga_roi_r_data_569; // word name
		struct {
			uint32_t roi_avg_r_data_569 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_570 14'h09E4 */
	union {
		uint32_t fpga_roi_r_data_570; // word name
		struct {
			uint32_t roi_avg_r_data_570 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_571 14'h09E8 */
	union {
		uint32_t fpga_roi_r_data_571; // word name
		struct {
			uint32_t roi_avg_r_data_571 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_572 14'h09EC */
	union {
		uint32_t fpga_roi_r_data_572; // word name
		struct {
			uint32_t roi_avg_r_data_572 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_573 14'h09F0 */
	union {
		uint32_t fpga_roi_r_data_573; // word name
		struct {
			uint32_t roi_avg_r_data_573 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_574 14'h09F4 */
	union {
		uint32_t fpga_roi_r_data_574; // word name
		struct {
			uint32_t roi_avg_r_data_574 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_575 14'h09F8 */
	union {
		uint32_t fpga_roi_r_data_575; // word name
		struct {
			uint32_t roi_avg_r_data_575 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_576 14'h09FC */
	union {
		uint32_t fpga_roi_r_data_576; // word name
		struct {
			uint32_t roi_avg_r_data_576 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_577 14'h0A00 */
	union {
		uint32_t fpga_roi_r_data_577; // word name
		struct {
			uint32_t roi_avg_r_data_577 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_578 14'h0A04 */
	union {
		uint32_t fpga_roi_r_data_578; // word name
		struct {
			uint32_t roi_avg_r_data_578 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_579 14'h0A08 */
	union {
		uint32_t fpga_roi_r_data_579; // word name
		struct {
			uint32_t roi_avg_r_data_579 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_580 14'h0A0C */
	union {
		uint32_t fpga_roi_r_data_580; // word name
		struct {
			uint32_t roi_avg_r_data_580 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_581 14'h0A10 */
	union {
		uint32_t fpga_roi_r_data_581; // word name
		struct {
			uint32_t roi_avg_r_data_581 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_582 14'h0A14 */
	union {
		uint32_t fpga_roi_r_data_582; // word name
		struct {
			uint32_t roi_avg_r_data_582 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_583 14'h0A18 */
	union {
		uint32_t fpga_roi_r_data_583; // word name
		struct {
			uint32_t roi_avg_r_data_583 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_584 14'h0A1C */
	union {
		uint32_t fpga_roi_r_data_584; // word name
		struct {
			uint32_t roi_avg_r_data_584 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_585 14'h0A20 */
	union {
		uint32_t fpga_roi_r_data_585; // word name
		struct {
			uint32_t roi_avg_r_data_585 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_586 14'h0A24 */
	union {
		uint32_t fpga_roi_r_data_586; // word name
		struct {
			uint32_t roi_avg_r_data_586 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_587 14'h0A28 */
	union {
		uint32_t fpga_roi_r_data_587; // word name
		struct {
			uint32_t roi_avg_r_data_587 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_588 14'h0A2C */
	union {
		uint32_t fpga_roi_r_data_588; // word name
		struct {
			uint32_t roi_avg_r_data_588 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_589 14'h0A30 */
	union {
		uint32_t fpga_roi_r_data_589; // word name
		struct {
			uint32_t roi_avg_r_data_589 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_590 14'h0A34 */
	union {
		uint32_t fpga_roi_r_data_590; // word name
		struct {
			uint32_t roi_avg_r_data_590 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_591 14'h0A38 */
	union {
		uint32_t fpga_roi_r_data_591; // word name
		struct {
			uint32_t roi_avg_r_data_591 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_592 14'h0A3C */
	union {
		uint32_t fpga_roi_r_data_592; // word name
		struct {
			uint32_t roi_avg_r_data_592 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_593 14'h0A40 */
	union {
		uint32_t fpga_roi_r_data_593; // word name
		struct {
			uint32_t roi_avg_r_data_593 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_594 14'h0A44 */
	union {
		uint32_t fpga_roi_r_data_594; // word name
		struct {
			uint32_t roi_avg_r_data_594 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_595 14'h0A48 */
	union {
		uint32_t fpga_roi_r_data_595; // word name
		struct {
			uint32_t roi_avg_r_data_595 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_596 14'h0A4C */
	union {
		uint32_t fpga_roi_r_data_596; // word name
		struct {
			uint32_t roi_avg_r_data_596 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_597 14'h0A50 */
	union {
		uint32_t fpga_roi_r_data_597; // word name
		struct {
			uint32_t roi_avg_r_data_597 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_598 14'h0A54 */
	union {
		uint32_t fpga_roi_r_data_598; // word name
		struct {
			uint32_t roi_avg_r_data_598 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_599 14'h0A58 */
	union {
		uint32_t fpga_roi_r_data_599; // word name
		struct {
			uint32_t roi_avg_r_data_599 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_600 14'h0A5C */
	union {
		uint32_t fpga_roi_r_data_600; // word name
		struct {
			uint32_t roi_avg_r_data_600 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_601 14'h0A60 */
	union {
		uint32_t fpga_roi_r_data_601; // word name
		struct {
			uint32_t roi_avg_r_data_601 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_602 14'h0A64 */
	union {
		uint32_t fpga_roi_r_data_602; // word name
		struct {
			uint32_t roi_avg_r_data_602 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_603 14'h0A68 */
	union {
		uint32_t fpga_roi_r_data_603; // word name
		struct {
			uint32_t roi_avg_r_data_603 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_604 14'h0A6C */
	union {
		uint32_t fpga_roi_r_data_604; // word name
		struct {
			uint32_t roi_avg_r_data_604 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_605 14'h0A70 */
	union {
		uint32_t fpga_roi_r_data_605; // word name
		struct {
			uint32_t roi_avg_r_data_605 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_606 14'h0A74 */
	union {
		uint32_t fpga_roi_r_data_606; // word name
		struct {
			uint32_t roi_avg_r_data_606 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_607 14'h0A78 */
	union {
		uint32_t fpga_roi_r_data_607; // word name
		struct {
			uint32_t roi_avg_r_data_607 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_608 14'h0A7C */
	union {
		uint32_t fpga_roi_r_data_608; // word name
		struct {
			uint32_t roi_avg_r_data_608 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_609 14'h0A80 */
	union {
		uint32_t fpga_roi_r_data_609; // word name
		struct {
			uint32_t roi_avg_r_data_609 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_610 14'h0A84 */
	union {
		uint32_t fpga_roi_r_data_610; // word name
		struct {
			uint32_t roi_avg_r_data_610 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_611 14'h0A88 */
	union {
		uint32_t fpga_roi_r_data_611; // word name
		struct {
			uint32_t roi_avg_r_data_611 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_612 14'h0A8C */
	union {
		uint32_t fpga_roi_r_data_612; // word name
		struct {
			uint32_t roi_avg_r_data_612 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_613 14'h0A90 */
	union {
		uint32_t fpga_roi_r_data_613; // word name
		struct {
			uint32_t roi_avg_r_data_613 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_614 14'h0A94 */
	union {
		uint32_t fpga_roi_r_data_614; // word name
		struct {
			uint32_t roi_avg_r_data_614 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_615 14'h0A98 */
	union {
		uint32_t fpga_roi_r_data_615; // word name
		struct {
			uint32_t roi_avg_r_data_615 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_616 14'h0A9C */
	union {
		uint32_t fpga_roi_r_data_616; // word name
		struct {
			uint32_t roi_avg_r_data_616 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_617 14'h0AA0 */
	union {
		uint32_t fpga_roi_r_data_617; // word name
		struct {
			uint32_t roi_avg_r_data_617 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_618 14'h0AA4 */
	union {
		uint32_t fpga_roi_r_data_618; // word name
		struct {
			uint32_t roi_avg_r_data_618 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_619 14'h0AA8 */
	union {
		uint32_t fpga_roi_r_data_619; // word name
		struct {
			uint32_t roi_avg_r_data_619 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_620 14'h0AAC */
	union {
		uint32_t fpga_roi_r_data_620; // word name
		struct {
			uint32_t roi_avg_r_data_620 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_621 14'h0AB0 */
	union {
		uint32_t fpga_roi_r_data_621; // word name
		struct {
			uint32_t roi_avg_r_data_621 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_622 14'h0AB4 */
	union {
		uint32_t fpga_roi_r_data_622; // word name
		struct {
			uint32_t roi_avg_r_data_622 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_623 14'h0AB8 */
	union {
		uint32_t fpga_roi_r_data_623; // word name
		struct {
			uint32_t roi_avg_r_data_623 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_624 14'h0ABC */
	union {
		uint32_t fpga_roi_r_data_624; // word name
		struct {
			uint32_t roi_avg_r_data_624 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_625 14'h0AC0 */
	union {
		uint32_t fpga_roi_r_data_625; // word name
		struct {
			uint32_t roi_avg_r_data_625 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_626 14'h0AC4 */
	union {
		uint32_t fpga_roi_r_data_626; // word name
		struct {
			uint32_t roi_avg_r_data_626 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_627 14'h0AC8 */
	union {
		uint32_t fpga_roi_r_data_627; // word name
		struct {
			uint32_t roi_avg_r_data_627 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_628 14'h0ACC */
	union {
		uint32_t fpga_roi_r_data_628; // word name
		struct {
			uint32_t roi_avg_r_data_628 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_629 14'h0AD0 */
	union {
		uint32_t fpga_roi_r_data_629; // word name
		struct {
			uint32_t roi_avg_r_data_629 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_630 14'h0AD4 */
	union {
		uint32_t fpga_roi_r_data_630; // word name
		struct {
			uint32_t roi_avg_r_data_630 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_631 14'h0AD8 */
	union {
		uint32_t fpga_roi_r_data_631; // word name
		struct {
			uint32_t roi_avg_r_data_631 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_632 14'h0ADC */
	union {
		uint32_t fpga_roi_r_data_632; // word name
		struct {
			uint32_t roi_avg_r_data_632 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_633 14'h0AE0 */
	union {
		uint32_t fpga_roi_r_data_633; // word name
		struct {
			uint32_t roi_avg_r_data_633 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_634 14'h0AE4 */
	union {
		uint32_t fpga_roi_r_data_634; // word name
		struct {
			uint32_t roi_avg_r_data_634 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_635 14'h0AE8 */
	union {
		uint32_t fpga_roi_r_data_635; // word name
		struct {
			uint32_t roi_avg_r_data_635 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_636 14'h0AEC */
	union {
		uint32_t fpga_roi_r_data_636; // word name
		struct {
			uint32_t roi_avg_r_data_636 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_637 14'h0AF0 */
	union {
		uint32_t fpga_roi_r_data_637; // word name
		struct {
			uint32_t roi_avg_r_data_637 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_638 14'h0AF4 */
	union {
		uint32_t fpga_roi_r_data_638; // word name
		struct {
			uint32_t roi_avg_r_data_638 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_639 14'h0AF8 */
	union {
		uint32_t fpga_roi_r_data_639; // word name
		struct {
			uint32_t roi_avg_r_data_639 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_640 14'h0AFC */
	union {
		uint32_t fpga_roi_r_data_640; // word name
		struct {
			uint32_t roi_avg_r_data_640 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_641 14'h0B00 */
	union {
		uint32_t fpga_roi_r_data_641; // word name
		struct {
			uint32_t roi_avg_r_data_641 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_642 14'h0B04 */
	union {
		uint32_t fpga_roi_r_data_642; // word name
		struct {
			uint32_t roi_avg_r_data_642 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_643 14'h0B08 */
	union {
		uint32_t fpga_roi_r_data_643; // word name
		struct {
			uint32_t roi_avg_r_data_643 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_644 14'h0B0C */
	union {
		uint32_t fpga_roi_r_data_644; // word name
		struct {
			uint32_t roi_avg_r_data_644 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_645 14'h0B10 */
	union {
		uint32_t fpga_roi_r_data_645; // word name
		struct {
			uint32_t roi_avg_r_data_645 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_646 14'h0B14 */
	union {
		uint32_t fpga_roi_r_data_646; // word name
		struct {
			uint32_t roi_avg_r_data_646 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_647 14'h0B18 */
	union {
		uint32_t fpga_roi_r_data_647; // word name
		struct {
			uint32_t roi_avg_r_data_647 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_648 14'h0B1C */
	union {
		uint32_t fpga_roi_r_data_648; // word name
		struct {
			uint32_t roi_avg_r_data_648 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_649 14'h0B20 */
	union {
		uint32_t fpga_roi_r_data_649; // word name
		struct {
			uint32_t roi_avg_r_data_649 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_650 14'h0B24 */
	union {
		uint32_t fpga_roi_r_data_650; // word name
		struct {
			uint32_t roi_avg_r_data_650 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_651 14'h0B28 */
	union {
		uint32_t fpga_roi_r_data_651; // word name
		struct {
			uint32_t roi_avg_r_data_651 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_652 14'h0B2C */
	union {
		uint32_t fpga_roi_r_data_652; // word name
		struct {
			uint32_t roi_avg_r_data_652 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_653 14'h0B30 */
	union {
		uint32_t fpga_roi_r_data_653; // word name
		struct {
			uint32_t roi_avg_r_data_653 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_654 14'h0B34 */
	union {
		uint32_t fpga_roi_r_data_654; // word name
		struct {
			uint32_t roi_avg_r_data_654 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_655 14'h0B38 */
	union {
		uint32_t fpga_roi_r_data_655; // word name
		struct {
			uint32_t roi_avg_r_data_655 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_656 14'h0B3C */
	union {
		uint32_t fpga_roi_r_data_656; // word name
		struct {
			uint32_t roi_avg_r_data_656 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_657 14'h0B40 */
	union {
		uint32_t fpga_roi_r_data_657; // word name
		struct {
			uint32_t roi_avg_r_data_657 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_658 14'h0B44 */
	union {
		uint32_t fpga_roi_r_data_658; // word name
		struct {
			uint32_t roi_avg_r_data_658 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_659 14'h0B48 */
	union {
		uint32_t fpga_roi_r_data_659; // word name
		struct {
			uint32_t roi_avg_r_data_659 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_660 14'h0B4C */
	union {
		uint32_t fpga_roi_r_data_660; // word name
		struct {
			uint32_t roi_avg_r_data_660 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_661 14'h0B50 */
	union {
		uint32_t fpga_roi_r_data_661; // word name
		struct {
			uint32_t roi_avg_r_data_661 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_662 14'h0B54 */
	union {
		uint32_t fpga_roi_r_data_662; // word name
		struct {
			uint32_t roi_avg_r_data_662 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_663 14'h0B58 */
	union {
		uint32_t fpga_roi_r_data_663; // word name
		struct {
			uint32_t roi_avg_r_data_663 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_664 14'h0B5C */
	union {
		uint32_t fpga_roi_r_data_664; // word name
		struct {
			uint32_t roi_avg_r_data_664 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_665 14'h0B60 */
	union {
		uint32_t fpga_roi_r_data_665; // word name
		struct {
			uint32_t roi_avg_r_data_665 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_666 14'h0B64 */
	union {
		uint32_t fpga_roi_r_data_666; // word name
		struct {
			uint32_t roi_avg_r_data_666 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_667 14'h0B68 */
	union {
		uint32_t fpga_roi_r_data_667; // word name
		struct {
			uint32_t roi_avg_r_data_667 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_668 14'h0B6C */
	union {
		uint32_t fpga_roi_r_data_668; // word name
		struct {
			uint32_t roi_avg_r_data_668 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_669 14'h0B70 */
	union {
		uint32_t fpga_roi_r_data_669; // word name
		struct {
			uint32_t roi_avg_r_data_669 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_670 14'h0B74 */
	union {
		uint32_t fpga_roi_r_data_670; // word name
		struct {
			uint32_t roi_avg_r_data_670 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_671 14'h0B78 */
	union {
		uint32_t fpga_roi_r_data_671; // word name
		struct {
			uint32_t roi_avg_r_data_671 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_672 14'h0B7C */
	union {
		uint32_t fpga_roi_r_data_672; // word name
		struct {
			uint32_t roi_avg_r_data_672 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_673 14'h0B80 */
	union {
		uint32_t fpga_roi_r_data_673; // word name
		struct {
			uint32_t roi_avg_r_data_673 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_674 14'h0B84 */
	union {
		uint32_t fpga_roi_r_data_674; // word name
		struct {
			uint32_t roi_avg_r_data_674 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_675 14'h0B88 */
	union {
		uint32_t fpga_roi_r_data_675; // word name
		struct {
			uint32_t roi_avg_r_data_675 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_676 14'h0B8C */
	union {
		uint32_t fpga_roi_r_data_676; // word name
		struct {
			uint32_t roi_avg_r_data_676 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_677 14'h0B90 */
	union {
		uint32_t fpga_roi_r_data_677; // word name
		struct {
			uint32_t roi_avg_r_data_677 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_678 14'h0B94 */
	union {
		uint32_t fpga_roi_r_data_678; // word name
		struct {
			uint32_t roi_avg_r_data_678 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_679 14'h0B98 */
	union {
		uint32_t fpga_roi_r_data_679; // word name
		struct {
			uint32_t roi_avg_r_data_679 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_680 14'h0B9C */
	union {
		uint32_t fpga_roi_r_data_680; // word name
		struct {
			uint32_t roi_avg_r_data_680 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_681 14'h0BA0 */
	union {
		uint32_t fpga_roi_r_data_681; // word name
		struct {
			uint32_t roi_avg_r_data_681 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_682 14'h0BA4 */
	union {
		uint32_t fpga_roi_r_data_682; // word name
		struct {
			uint32_t roi_avg_r_data_682 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_683 14'h0BA8 */
	union {
		uint32_t fpga_roi_r_data_683; // word name
		struct {
			uint32_t roi_avg_r_data_683 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_684 14'h0BAC */
	union {
		uint32_t fpga_roi_r_data_684; // word name
		struct {
			uint32_t roi_avg_r_data_684 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_685 14'h0BB0 */
	union {
		uint32_t fpga_roi_r_data_685; // word name
		struct {
			uint32_t roi_avg_r_data_685 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_686 14'h0BB4 */
	union {
		uint32_t fpga_roi_r_data_686; // word name
		struct {
			uint32_t roi_avg_r_data_686 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_687 14'h0BB8 */
	union {
		uint32_t fpga_roi_r_data_687; // word name
		struct {
			uint32_t roi_avg_r_data_687 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_688 14'h0BBC */
	union {
		uint32_t fpga_roi_r_data_688; // word name
		struct {
			uint32_t roi_avg_r_data_688 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_689 14'h0BC0 */
	union {
		uint32_t fpga_roi_r_data_689; // word name
		struct {
			uint32_t roi_avg_r_data_689 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_690 14'h0BC4 */
	union {
		uint32_t fpga_roi_r_data_690; // word name
		struct {
			uint32_t roi_avg_r_data_690 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_691 14'h0BC8 */
	union {
		uint32_t fpga_roi_r_data_691; // word name
		struct {
			uint32_t roi_avg_r_data_691 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_692 14'h0BCC */
	union {
		uint32_t fpga_roi_r_data_692; // word name
		struct {
			uint32_t roi_avg_r_data_692 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_693 14'h0BD0 */
	union {
		uint32_t fpga_roi_r_data_693; // word name
		struct {
			uint32_t roi_avg_r_data_693 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_694 14'h0BD4 */
	union {
		uint32_t fpga_roi_r_data_694; // word name
		struct {
			uint32_t roi_avg_r_data_694 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_695 14'h0BD8 */
	union {
		uint32_t fpga_roi_r_data_695; // word name
		struct {
			uint32_t roi_avg_r_data_695 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_696 14'h0BDC */
	union {
		uint32_t fpga_roi_r_data_696; // word name
		struct {
			uint32_t roi_avg_r_data_696 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_697 14'h0BE0 */
	union {
		uint32_t fpga_roi_r_data_697; // word name
		struct {
			uint32_t roi_avg_r_data_697 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_698 14'h0BE4 */
	union {
		uint32_t fpga_roi_r_data_698; // word name
		struct {
			uint32_t roi_avg_r_data_698 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_699 14'h0BE8 */
	union {
		uint32_t fpga_roi_r_data_699; // word name
		struct {
			uint32_t roi_avg_r_data_699 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_700 14'h0BEC */
	union {
		uint32_t fpga_roi_r_data_700; // word name
		struct {
			uint32_t roi_avg_r_data_700 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_701 14'h0BF0 */
	union {
		uint32_t fpga_roi_r_data_701; // word name
		struct {
			uint32_t roi_avg_r_data_701 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_702 14'h0BF4 */
	union {
		uint32_t fpga_roi_r_data_702; // word name
		struct {
			uint32_t roi_avg_r_data_702 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_703 14'h0BF8 */
	union {
		uint32_t fpga_roi_r_data_703; // word name
		struct {
			uint32_t roi_avg_r_data_703 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_704 14'h0BFC */
	union {
		uint32_t fpga_roi_r_data_704; // word name
		struct {
			uint32_t roi_avg_r_data_704 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_705 14'h0C00 */
	union {
		uint32_t fpga_roi_r_data_705; // word name
		struct {
			uint32_t roi_avg_r_data_705 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_706 14'h0C04 */
	union {
		uint32_t fpga_roi_r_data_706; // word name
		struct {
			uint32_t roi_avg_r_data_706 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_707 14'h0C08 */
	union {
		uint32_t fpga_roi_r_data_707; // word name
		struct {
			uint32_t roi_avg_r_data_707 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_708 14'h0C0C */
	union {
		uint32_t fpga_roi_r_data_708; // word name
		struct {
			uint32_t roi_avg_r_data_708 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_709 14'h0C10 */
	union {
		uint32_t fpga_roi_r_data_709; // word name
		struct {
			uint32_t roi_avg_r_data_709 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_710 14'h0C14 */
	union {
		uint32_t fpga_roi_r_data_710; // word name
		struct {
			uint32_t roi_avg_r_data_710 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_711 14'h0C18 */
	union {
		uint32_t fpga_roi_r_data_711; // word name
		struct {
			uint32_t roi_avg_r_data_711 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_712 14'h0C1C */
	union {
		uint32_t fpga_roi_r_data_712; // word name
		struct {
			uint32_t roi_avg_r_data_712 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_713 14'h0C20 */
	union {
		uint32_t fpga_roi_r_data_713; // word name
		struct {
			uint32_t roi_avg_r_data_713 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_714 14'h0C24 */
	union {
		uint32_t fpga_roi_r_data_714; // word name
		struct {
			uint32_t roi_avg_r_data_714 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_715 14'h0C28 */
	union {
		uint32_t fpga_roi_r_data_715; // word name
		struct {
			uint32_t roi_avg_r_data_715 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_716 14'h0C2C */
	union {
		uint32_t fpga_roi_r_data_716; // word name
		struct {
			uint32_t roi_avg_r_data_716 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_717 14'h0C30 */
	union {
		uint32_t fpga_roi_r_data_717; // word name
		struct {
			uint32_t roi_avg_r_data_717 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_718 14'h0C34 */
	union {
		uint32_t fpga_roi_r_data_718; // word name
		struct {
			uint32_t roi_avg_r_data_718 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_719 14'h0C38 */
	union {
		uint32_t fpga_roi_r_data_719; // word name
		struct {
			uint32_t roi_avg_r_data_719 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_720 14'h0C3C */
	union {
		uint32_t fpga_roi_r_data_720; // word name
		struct {
			uint32_t roi_avg_r_data_720 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_721 14'h0C40 */
	union {
		uint32_t fpga_roi_r_data_721; // word name
		struct {
			uint32_t roi_avg_r_data_721 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_722 14'h0C44 */
	union {
		uint32_t fpga_roi_r_data_722; // word name
		struct {
			uint32_t roi_avg_r_data_722 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_723 14'h0C48 */
	union {
		uint32_t fpga_roi_r_data_723; // word name
		struct {
			uint32_t roi_avg_r_data_723 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_724 14'h0C4C */
	union {
		uint32_t fpga_roi_r_data_724; // word name
		struct {
			uint32_t roi_avg_r_data_724 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_725 14'h0C50 */
	union {
		uint32_t fpga_roi_r_data_725; // word name
		struct {
			uint32_t roi_avg_r_data_725 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_726 14'h0C54 */
	union {
		uint32_t fpga_roi_r_data_726; // word name
		struct {
			uint32_t roi_avg_r_data_726 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_727 14'h0C58 */
	union {
		uint32_t fpga_roi_r_data_727; // word name
		struct {
			uint32_t roi_avg_r_data_727 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_728 14'h0C5C */
	union {
		uint32_t fpga_roi_r_data_728; // word name
		struct {
			uint32_t roi_avg_r_data_728 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_729 14'h0C60 */
	union {
		uint32_t fpga_roi_r_data_729; // word name
		struct {
			uint32_t roi_avg_r_data_729 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_730 14'h0C64 */
	union {
		uint32_t fpga_roi_r_data_730; // word name
		struct {
			uint32_t roi_avg_r_data_730 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_731 14'h0C68 */
	union {
		uint32_t fpga_roi_r_data_731; // word name
		struct {
			uint32_t roi_avg_r_data_731 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_732 14'h0C6C */
	union {
		uint32_t fpga_roi_r_data_732; // word name
		struct {
			uint32_t roi_avg_r_data_732 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_733 14'h0C70 */
	union {
		uint32_t fpga_roi_r_data_733; // word name
		struct {
			uint32_t roi_avg_r_data_733 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_734 14'h0C74 */
	union {
		uint32_t fpga_roi_r_data_734; // word name
		struct {
			uint32_t roi_avg_r_data_734 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_735 14'h0C78 */
	union {
		uint32_t fpga_roi_r_data_735; // word name
		struct {
			uint32_t roi_avg_r_data_735 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_736 14'h0C7C */
	union {
		uint32_t fpga_roi_r_data_736; // word name
		struct {
			uint32_t roi_avg_r_data_736 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_737 14'h0C80 */
	union {
		uint32_t fpga_roi_r_data_737; // word name
		struct {
			uint32_t roi_avg_r_data_737 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_738 14'h0C84 */
	union {
		uint32_t fpga_roi_r_data_738; // word name
		struct {
			uint32_t roi_avg_r_data_738 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_739 14'h0C88 */
	union {
		uint32_t fpga_roi_r_data_739; // word name
		struct {
			uint32_t roi_avg_r_data_739 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_740 14'h0C8C */
	union {
		uint32_t fpga_roi_r_data_740; // word name
		struct {
			uint32_t roi_avg_r_data_740 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_741 14'h0C90 */
	union {
		uint32_t fpga_roi_r_data_741; // word name
		struct {
			uint32_t roi_avg_r_data_741 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_742 14'h0C94 */
	union {
		uint32_t fpga_roi_r_data_742; // word name
		struct {
			uint32_t roi_avg_r_data_742 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_743 14'h0C98 */
	union {
		uint32_t fpga_roi_r_data_743; // word name
		struct {
			uint32_t roi_avg_r_data_743 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_744 14'h0C9C */
	union {
		uint32_t fpga_roi_r_data_744; // word name
		struct {
			uint32_t roi_avg_r_data_744 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_745 14'h0CA0 */
	union {
		uint32_t fpga_roi_r_data_745; // word name
		struct {
			uint32_t roi_avg_r_data_745 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_746 14'h0CA4 */
	union {
		uint32_t fpga_roi_r_data_746; // word name
		struct {
			uint32_t roi_avg_r_data_746 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_747 14'h0CA8 */
	union {
		uint32_t fpga_roi_r_data_747; // word name
		struct {
			uint32_t roi_avg_r_data_747 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_748 14'h0CAC */
	union {
		uint32_t fpga_roi_r_data_748; // word name
		struct {
			uint32_t roi_avg_r_data_748 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_749 14'h0CB0 */
	union {
		uint32_t fpga_roi_r_data_749; // word name
		struct {
			uint32_t roi_avg_r_data_749 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_750 14'h0CB4 */
	union {
		uint32_t fpga_roi_r_data_750; // word name
		struct {
			uint32_t roi_avg_r_data_750 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_751 14'h0CB8 */
	union {
		uint32_t fpga_roi_r_data_751; // word name
		struct {
			uint32_t roi_avg_r_data_751 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_752 14'h0CBC */
	union {
		uint32_t fpga_roi_r_data_752; // word name
		struct {
			uint32_t roi_avg_r_data_752 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_753 14'h0CC0 */
	union {
		uint32_t fpga_roi_r_data_753; // word name
		struct {
			uint32_t roi_avg_r_data_753 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_754 14'h0CC4 */
	union {
		uint32_t fpga_roi_r_data_754; // word name
		struct {
			uint32_t roi_avg_r_data_754 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_755 14'h0CC8 */
	union {
		uint32_t fpga_roi_r_data_755; // word name
		struct {
			uint32_t roi_avg_r_data_755 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_756 14'h0CCC */
	union {
		uint32_t fpga_roi_r_data_756; // word name
		struct {
			uint32_t roi_avg_r_data_756 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_757 14'h0CD0 */
	union {
		uint32_t fpga_roi_r_data_757; // word name
		struct {
			uint32_t roi_avg_r_data_757 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_758 14'h0CD4 */
	union {
		uint32_t fpga_roi_r_data_758; // word name
		struct {
			uint32_t roi_avg_r_data_758 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_759 14'h0CD8 */
	union {
		uint32_t fpga_roi_r_data_759; // word name
		struct {
			uint32_t roi_avg_r_data_759 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_760 14'h0CDC */
	union {
		uint32_t fpga_roi_r_data_760; // word name
		struct {
			uint32_t roi_avg_r_data_760 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_761 14'h0CE0 */
	union {
		uint32_t fpga_roi_r_data_761; // word name
		struct {
			uint32_t roi_avg_r_data_761 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_762 14'h0CE4 */
	union {
		uint32_t fpga_roi_r_data_762; // word name
		struct {
			uint32_t roi_avg_r_data_762 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_763 14'h0CE8 */
	union {
		uint32_t fpga_roi_r_data_763; // word name
		struct {
			uint32_t roi_avg_r_data_763 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_764 14'h0CEC */
	union {
		uint32_t fpga_roi_r_data_764; // word name
		struct {
			uint32_t roi_avg_r_data_764 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_765 14'h0CF0 */
	union {
		uint32_t fpga_roi_r_data_765; // word name
		struct {
			uint32_t roi_avg_r_data_765 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_766 14'h0CF4 */
	union {
		uint32_t fpga_roi_r_data_766; // word name
		struct {
			uint32_t roi_avg_r_data_766 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_767 14'h0CF8 */
	union {
		uint32_t fpga_roi_r_data_767; // word name
		struct {
			uint32_t roi_avg_r_data_767 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_768 14'h0CFC */
	union {
		uint32_t fpga_roi_r_data_768; // word name
		struct {
			uint32_t roi_avg_r_data_768 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_769 14'h0D00 */
	union {
		uint32_t fpga_roi_r_data_769; // word name
		struct {
			uint32_t roi_avg_r_data_769 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_770 14'h0D04 */
	union {
		uint32_t fpga_roi_r_data_770; // word name
		struct {
			uint32_t roi_avg_r_data_770 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_771 14'h0D08 */
	union {
		uint32_t fpga_roi_r_data_771; // word name
		struct {
			uint32_t roi_avg_r_data_771 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_772 14'h0D0C */
	union {
		uint32_t fpga_roi_r_data_772; // word name
		struct {
			uint32_t roi_avg_r_data_772 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_773 14'h0D10 */
	union {
		uint32_t fpga_roi_r_data_773; // word name
		struct {
			uint32_t roi_avg_r_data_773 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_774 14'h0D14 */
	union {
		uint32_t fpga_roi_r_data_774; // word name
		struct {
			uint32_t roi_avg_r_data_774 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_775 14'h0D18 */
	union {
		uint32_t fpga_roi_r_data_775; // word name
		struct {
			uint32_t roi_avg_r_data_775 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_776 14'h0D1C */
	union {
		uint32_t fpga_roi_r_data_776; // word name
		struct {
			uint32_t roi_avg_r_data_776 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_777 14'h0D20 */
	union {
		uint32_t fpga_roi_r_data_777; // word name
		struct {
			uint32_t roi_avg_r_data_777 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_778 14'h0D24 */
	union {
		uint32_t fpga_roi_r_data_778; // word name
		struct {
			uint32_t roi_avg_r_data_778 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_779 14'h0D28 */
	union {
		uint32_t fpga_roi_r_data_779; // word name
		struct {
			uint32_t roi_avg_r_data_779 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_780 14'h0D2C */
	union {
		uint32_t fpga_roi_r_data_780; // word name
		struct {
			uint32_t roi_avg_r_data_780 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_781 14'h0D30 */
	union {
		uint32_t fpga_roi_r_data_781; // word name
		struct {
			uint32_t roi_avg_r_data_781 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_782 14'h0D34 */
	union {
		uint32_t fpga_roi_r_data_782; // word name
		struct {
			uint32_t roi_avg_r_data_782 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_783 14'h0D38 */
	union {
		uint32_t fpga_roi_r_data_783; // word name
		struct {
			uint32_t roi_avg_r_data_783 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_784 14'h0D3C */
	union {
		uint32_t fpga_roi_r_data_784; // word name
		struct {
			uint32_t roi_avg_r_data_784 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_785 14'h0D40 */
	union {
		uint32_t fpga_roi_r_data_785; // word name
		struct {
			uint32_t roi_avg_r_data_785 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_786 14'h0D44 */
	union {
		uint32_t fpga_roi_r_data_786; // word name
		struct {
			uint32_t roi_avg_r_data_786 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_787 14'h0D48 */
	union {
		uint32_t fpga_roi_r_data_787; // word name
		struct {
			uint32_t roi_avg_r_data_787 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_788 14'h0D4C */
	union {
		uint32_t fpga_roi_r_data_788; // word name
		struct {
			uint32_t roi_avg_r_data_788 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_789 14'h0D50 */
	union {
		uint32_t fpga_roi_r_data_789; // word name
		struct {
			uint32_t roi_avg_r_data_789 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_790 14'h0D54 */
	union {
		uint32_t fpga_roi_r_data_790; // word name
		struct {
			uint32_t roi_avg_r_data_790 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_791 14'h0D58 */
	union {
		uint32_t fpga_roi_r_data_791; // word name
		struct {
			uint32_t roi_avg_r_data_791 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_792 14'h0D5C */
	union {
		uint32_t fpga_roi_r_data_792; // word name
		struct {
			uint32_t roi_avg_r_data_792 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_793 14'h0D60 */
	union {
		uint32_t fpga_roi_r_data_793; // word name
		struct {
			uint32_t roi_avg_r_data_793 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_794 14'h0D64 */
	union {
		uint32_t fpga_roi_r_data_794; // word name
		struct {
			uint32_t roi_avg_r_data_794 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_795 14'h0D68 */
	union {
		uint32_t fpga_roi_r_data_795; // word name
		struct {
			uint32_t roi_avg_r_data_795 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_796 14'h0D6C */
	union {
		uint32_t fpga_roi_r_data_796; // word name
		struct {
			uint32_t roi_avg_r_data_796 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_797 14'h0D70 */
	union {
		uint32_t fpga_roi_r_data_797; // word name
		struct {
			uint32_t roi_avg_r_data_797 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_798 14'h0D74 */
	union {
		uint32_t fpga_roi_r_data_798; // word name
		struct {
			uint32_t roi_avg_r_data_798 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_799 14'h0D78 */
	union {
		uint32_t fpga_roi_r_data_799; // word name
		struct {
			uint32_t roi_avg_r_data_799 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_800 14'h0D7C */
	union {
		uint32_t fpga_roi_r_data_800; // word name
		struct {
			uint32_t roi_avg_r_data_800 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_801 14'h0D80 */
	union {
		uint32_t fpga_roi_r_data_801; // word name
		struct {
			uint32_t roi_avg_r_data_801 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_802 14'h0D84 */
	union {
		uint32_t fpga_roi_r_data_802; // word name
		struct {
			uint32_t roi_avg_r_data_802 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_803 14'h0D88 */
	union {
		uint32_t fpga_roi_r_data_803; // word name
		struct {
			uint32_t roi_avg_r_data_803 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_804 14'h0D8C */
	union {
		uint32_t fpga_roi_r_data_804; // word name
		struct {
			uint32_t roi_avg_r_data_804 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_805 14'h0D90 */
	union {
		uint32_t fpga_roi_r_data_805; // word name
		struct {
			uint32_t roi_avg_r_data_805 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_806 14'h0D94 */
	union {
		uint32_t fpga_roi_r_data_806; // word name
		struct {
			uint32_t roi_avg_r_data_806 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_807 14'h0D98 */
	union {
		uint32_t fpga_roi_r_data_807; // word name
		struct {
			uint32_t roi_avg_r_data_807 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_808 14'h0D9C */
	union {
		uint32_t fpga_roi_r_data_808; // word name
		struct {
			uint32_t roi_avg_r_data_808 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_809 14'h0DA0 */
	union {
		uint32_t fpga_roi_r_data_809; // word name
		struct {
			uint32_t roi_avg_r_data_809 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_810 14'h0DA4 */
	union {
		uint32_t fpga_roi_r_data_810; // word name
		struct {
			uint32_t roi_avg_r_data_810 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_811 14'h0DA8 */
	union {
		uint32_t fpga_roi_r_data_811; // word name
		struct {
			uint32_t roi_avg_r_data_811 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_812 14'h0DAC */
	union {
		uint32_t fpga_roi_r_data_812; // word name
		struct {
			uint32_t roi_avg_r_data_812 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_813 14'h0DB0 */
	union {
		uint32_t fpga_roi_r_data_813; // word name
		struct {
			uint32_t roi_avg_r_data_813 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_814 14'h0DB4 */
	union {
		uint32_t fpga_roi_r_data_814; // word name
		struct {
			uint32_t roi_avg_r_data_814 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_815 14'h0DB8 */
	union {
		uint32_t fpga_roi_r_data_815; // word name
		struct {
			uint32_t roi_avg_r_data_815 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_816 14'h0DBC */
	union {
		uint32_t fpga_roi_r_data_816; // word name
		struct {
			uint32_t roi_avg_r_data_816 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_817 14'h0DC0 */
	union {
		uint32_t fpga_roi_r_data_817; // word name
		struct {
			uint32_t roi_avg_r_data_817 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_818 14'h0DC4 */
	union {
		uint32_t fpga_roi_r_data_818; // word name
		struct {
			uint32_t roi_avg_r_data_818 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_819 14'h0DC8 */
	union {
		uint32_t fpga_roi_r_data_819; // word name
		struct {
			uint32_t roi_avg_r_data_819 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_820 14'h0DCC */
	union {
		uint32_t fpga_roi_r_data_820; // word name
		struct {
			uint32_t roi_avg_r_data_820 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_821 14'h0DD0 */
	union {
		uint32_t fpga_roi_r_data_821; // word name
		struct {
			uint32_t roi_avg_r_data_821 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_822 14'h0DD4 */
	union {
		uint32_t fpga_roi_r_data_822; // word name
		struct {
			uint32_t roi_avg_r_data_822 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_823 14'h0DD8 */
	union {
		uint32_t fpga_roi_r_data_823; // word name
		struct {
			uint32_t roi_avg_r_data_823 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_824 14'h0DDC */
	union {
		uint32_t fpga_roi_r_data_824; // word name
		struct {
			uint32_t roi_avg_r_data_824 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_825 14'h0DE0 */
	union {
		uint32_t fpga_roi_r_data_825; // word name
		struct {
			uint32_t roi_avg_r_data_825 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_826 14'h0DE4 */
	union {
		uint32_t fpga_roi_r_data_826; // word name
		struct {
			uint32_t roi_avg_r_data_826 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_827 14'h0DE8 */
	union {
		uint32_t fpga_roi_r_data_827; // word name
		struct {
			uint32_t roi_avg_r_data_827 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_828 14'h0DEC */
	union {
		uint32_t fpga_roi_r_data_828; // word name
		struct {
			uint32_t roi_avg_r_data_828 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_829 14'h0DF0 */
	union {
		uint32_t fpga_roi_r_data_829; // word name
		struct {
			uint32_t roi_avg_r_data_829 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_830 14'h0DF4 */
	union {
		uint32_t fpga_roi_r_data_830; // word name
		struct {
			uint32_t roi_avg_r_data_830 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_831 14'h0DF8 */
	union {
		uint32_t fpga_roi_r_data_831; // word name
		struct {
			uint32_t roi_avg_r_data_831 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_832 14'h0DFC */
	union {
		uint32_t fpga_roi_r_data_832; // word name
		struct {
			uint32_t roi_avg_r_data_832 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_833 14'h0E00 */
	union {
		uint32_t fpga_roi_r_data_833; // word name
		struct {
			uint32_t roi_avg_r_data_833 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_834 14'h0E04 */
	union {
		uint32_t fpga_roi_r_data_834; // word name
		struct {
			uint32_t roi_avg_r_data_834 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_835 14'h0E08 */
	union {
		uint32_t fpga_roi_r_data_835; // word name
		struct {
			uint32_t roi_avg_r_data_835 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_836 14'h0E0C */
	union {
		uint32_t fpga_roi_r_data_836; // word name
		struct {
			uint32_t roi_avg_r_data_836 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_837 14'h0E10 */
	union {
		uint32_t fpga_roi_r_data_837; // word name
		struct {
			uint32_t roi_avg_r_data_837 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_838 14'h0E14 */
	union {
		uint32_t fpga_roi_r_data_838; // word name
		struct {
			uint32_t roi_avg_r_data_838 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_839 14'h0E18 */
	union {
		uint32_t fpga_roi_r_data_839; // word name
		struct {
			uint32_t roi_avg_r_data_839 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_840 14'h0E1C */
	union {
		uint32_t fpga_roi_r_data_840; // word name
		struct {
			uint32_t roi_avg_r_data_840 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_841 14'h0E20 */
	union {
		uint32_t fpga_roi_r_data_841; // word name
		struct {
			uint32_t roi_avg_r_data_841 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_842 14'h0E24 */
	union {
		uint32_t fpga_roi_r_data_842; // word name
		struct {
			uint32_t roi_avg_r_data_842 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_843 14'h0E28 */
	union {
		uint32_t fpga_roi_r_data_843; // word name
		struct {
			uint32_t roi_avg_r_data_843 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_844 14'h0E2C */
	union {
		uint32_t fpga_roi_r_data_844; // word name
		struct {
			uint32_t roi_avg_r_data_844 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_845 14'h0E30 */
	union {
		uint32_t fpga_roi_r_data_845; // word name
		struct {
			uint32_t roi_avg_r_data_845 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_846 14'h0E34 */
	union {
		uint32_t fpga_roi_r_data_846; // word name
		struct {
			uint32_t roi_avg_r_data_846 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_847 14'h0E38 */
	union {
		uint32_t fpga_roi_r_data_847; // word name
		struct {
			uint32_t roi_avg_r_data_847 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_848 14'h0E3C */
	union {
		uint32_t fpga_roi_r_data_848; // word name
		struct {
			uint32_t roi_avg_r_data_848 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_849 14'h0E40 */
	union {
		uint32_t fpga_roi_r_data_849; // word name
		struct {
			uint32_t roi_avg_r_data_849 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_850 14'h0E44 */
	union {
		uint32_t fpga_roi_r_data_850; // word name
		struct {
			uint32_t roi_avg_r_data_850 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_851 14'h0E48 */
	union {
		uint32_t fpga_roi_r_data_851; // word name
		struct {
			uint32_t roi_avg_r_data_851 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_852 14'h0E4C */
	union {
		uint32_t fpga_roi_r_data_852; // word name
		struct {
			uint32_t roi_avg_r_data_852 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_853 14'h0E50 */
	union {
		uint32_t fpga_roi_r_data_853; // word name
		struct {
			uint32_t roi_avg_r_data_853 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_854 14'h0E54 */
	union {
		uint32_t fpga_roi_r_data_854; // word name
		struct {
			uint32_t roi_avg_r_data_854 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_855 14'h0E58 */
	union {
		uint32_t fpga_roi_r_data_855; // word name
		struct {
			uint32_t roi_avg_r_data_855 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_856 14'h0E5C */
	union {
		uint32_t fpga_roi_r_data_856; // word name
		struct {
			uint32_t roi_avg_r_data_856 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_857 14'h0E60 */
	union {
		uint32_t fpga_roi_r_data_857; // word name
		struct {
			uint32_t roi_avg_r_data_857 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_858 14'h0E64 */
	union {
		uint32_t fpga_roi_r_data_858; // word name
		struct {
			uint32_t roi_avg_r_data_858 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_859 14'h0E68 */
	union {
		uint32_t fpga_roi_r_data_859; // word name
		struct {
			uint32_t roi_avg_r_data_859 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_860 14'h0E6C */
	union {
		uint32_t fpga_roi_r_data_860; // word name
		struct {
			uint32_t roi_avg_r_data_860 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_861 14'h0E70 */
	union {
		uint32_t fpga_roi_r_data_861; // word name
		struct {
			uint32_t roi_avg_r_data_861 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_862 14'h0E74 */
	union {
		uint32_t fpga_roi_r_data_862; // word name
		struct {
			uint32_t roi_avg_r_data_862 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_863 14'h0E78 */
	union {
		uint32_t fpga_roi_r_data_863; // word name
		struct {
			uint32_t roi_avg_r_data_863 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_864 14'h0E7C */
	union {
		uint32_t fpga_roi_r_data_864; // word name
		struct {
			uint32_t roi_avg_r_data_864 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_865 14'h0E80 */
	union {
		uint32_t fpga_roi_r_data_865; // word name
		struct {
			uint32_t roi_avg_r_data_865 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_866 14'h0E84 */
	union {
		uint32_t fpga_roi_r_data_866; // word name
		struct {
			uint32_t roi_avg_r_data_866 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_867 14'h0E88 */
	union {
		uint32_t fpga_roi_r_data_867; // word name
		struct {
			uint32_t roi_avg_r_data_867 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_868 14'h0E8C */
	union {
		uint32_t fpga_roi_r_data_868; // word name
		struct {
			uint32_t roi_avg_r_data_868 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_869 14'h0E90 */
	union {
		uint32_t fpga_roi_r_data_869; // word name
		struct {
			uint32_t roi_avg_r_data_869 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_870 14'h0E94 */
	union {
		uint32_t fpga_roi_r_data_870; // word name
		struct {
			uint32_t roi_avg_r_data_870 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_871 14'h0E98 */
	union {
		uint32_t fpga_roi_r_data_871; // word name
		struct {
			uint32_t roi_avg_r_data_871 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_872 14'h0E9C */
	union {
		uint32_t fpga_roi_r_data_872; // word name
		struct {
			uint32_t roi_avg_r_data_872 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_873 14'h0EA0 */
	union {
		uint32_t fpga_roi_r_data_873; // word name
		struct {
			uint32_t roi_avg_r_data_873 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_874 14'h0EA4 */
	union {
		uint32_t fpga_roi_r_data_874; // word name
		struct {
			uint32_t roi_avg_r_data_874 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_875 14'h0EA8 */
	union {
		uint32_t fpga_roi_r_data_875; // word name
		struct {
			uint32_t roi_avg_r_data_875 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_876 14'h0EAC */
	union {
		uint32_t fpga_roi_r_data_876; // word name
		struct {
			uint32_t roi_avg_r_data_876 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_877 14'h0EB0 */
	union {
		uint32_t fpga_roi_r_data_877; // word name
		struct {
			uint32_t roi_avg_r_data_877 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_878 14'h0EB4 */
	union {
		uint32_t fpga_roi_r_data_878; // word name
		struct {
			uint32_t roi_avg_r_data_878 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_879 14'h0EB8 */
	union {
		uint32_t fpga_roi_r_data_879; // word name
		struct {
			uint32_t roi_avg_r_data_879 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_880 14'h0EBC */
	union {
		uint32_t fpga_roi_r_data_880; // word name
		struct {
			uint32_t roi_avg_r_data_880 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_881 14'h0EC0 */
	union {
		uint32_t fpga_roi_r_data_881; // word name
		struct {
			uint32_t roi_avg_r_data_881 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_882 14'h0EC4 */
	union {
		uint32_t fpga_roi_r_data_882; // word name
		struct {
			uint32_t roi_avg_r_data_882 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_883 14'h0EC8 */
	union {
		uint32_t fpga_roi_r_data_883; // word name
		struct {
			uint32_t roi_avg_r_data_883 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_884 14'h0ECC */
	union {
		uint32_t fpga_roi_r_data_884; // word name
		struct {
			uint32_t roi_avg_r_data_884 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_885 14'h0ED0 */
	union {
		uint32_t fpga_roi_r_data_885; // word name
		struct {
			uint32_t roi_avg_r_data_885 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_886 14'h0ED4 */
	union {
		uint32_t fpga_roi_r_data_886; // word name
		struct {
			uint32_t roi_avg_r_data_886 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_887 14'h0ED8 */
	union {
		uint32_t fpga_roi_r_data_887; // word name
		struct {
			uint32_t roi_avg_r_data_887 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_888 14'h0EDC */
	union {
		uint32_t fpga_roi_r_data_888; // word name
		struct {
			uint32_t roi_avg_r_data_888 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_889 14'h0EE0 */
	union {
		uint32_t fpga_roi_r_data_889; // word name
		struct {
			uint32_t roi_avg_r_data_889 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_890 14'h0EE4 */
	union {
		uint32_t fpga_roi_r_data_890; // word name
		struct {
			uint32_t roi_avg_r_data_890 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_891 14'h0EE8 */
	union {
		uint32_t fpga_roi_r_data_891; // word name
		struct {
			uint32_t roi_avg_r_data_891 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_892 14'h0EEC */
	union {
		uint32_t fpga_roi_r_data_892; // word name
		struct {
			uint32_t roi_avg_r_data_892 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_893 14'h0EF0 */
	union {
		uint32_t fpga_roi_r_data_893; // word name
		struct {
			uint32_t roi_avg_r_data_893 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_894 14'h0EF4 */
	union {
		uint32_t fpga_roi_r_data_894; // word name
		struct {
			uint32_t roi_avg_r_data_894 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_895 14'h0EF8 */
	union {
		uint32_t fpga_roi_r_data_895; // word name
		struct {
			uint32_t roi_avg_r_data_895 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_896 14'h0EFC */
	union {
		uint32_t fpga_roi_r_data_896; // word name
		struct {
			uint32_t roi_avg_r_data_896 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_897 14'h0F00 */
	union {
		uint32_t fpga_roi_r_data_897; // word name
		struct {
			uint32_t roi_avg_r_data_897 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_898 14'h0F04 */
	union {
		uint32_t fpga_roi_r_data_898; // word name
		struct {
			uint32_t roi_avg_r_data_898 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_899 14'h0F08 */
	union {
		uint32_t fpga_roi_r_data_899; // word name
		struct {
			uint32_t roi_avg_r_data_899 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_900 14'h0F0C */
	union {
		uint32_t fpga_roi_r_data_900; // word name
		struct {
			uint32_t roi_avg_r_data_900 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_901 14'h0F10 */
	union {
		uint32_t fpga_roi_r_data_901; // word name
		struct {
			uint32_t roi_avg_r_data_901 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_902 14'h0F14 */
	union {
		uint32_t fpga_roi_r_data_902; // word name
		struct {
			uint32_t roi_avg_r_data_902 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_903 14'h0F18 */
	union {
		uint32_t fpga_roi_r_data_903; // word name
		struct {
			uint32_t roi_avg_r_data_903 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_904 14'h0F1C */
	union {
		uint32_t fpga_roi_r_data_904; // word name
		struct {
			uint32_t roi_avg_r_data_904 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_905 14'h0F20 */
	union {
		uint32_t fpga_roi_r_data_905; // word name
		struct {
			uint32_t roi_avg_r_data_905 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_906 14'h0F24 */
	union {
		uint32_t fpga_roi_r_data_906; // word name
		struct {
			uint32_t roi_avg_r_data_906 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_907 14'h0F28 */
	union {
		uint32_t fpga_roi_r_data_907; // word name
		struct {
			uint32_t roi_avg_r_data_907 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_908 14'h0F2C */
	union {
		uint32_t fpga_roi_r_data_908; // word name
		struct {
			uint32_t roi_avg_r_data_908 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_909 14'h0F30 */
	union {
		uint32_t fpga_roi_r_data_909; // word name
		struct {
			uint32_t roi_avg_r_data_909 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_910 14'h0F34 */
	union {
		uint32_t fpga_roi_r_data_910; // word name
		struct {
			uint32_t roi_avg_r_data_910 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_911 14'h0F38 */
	union {
		uint32_t fpga_roi_r_data_911; // word name
		struct {
			uint32_t roi_avg_r_data_911 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_912 14'h0F3C */
	union {
		uint32_t fpga_roi_r_data_912; // word name
		struct {
			uint32_t roi_avg_r_data_912 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_913 14'h0F40 */
	union {
		uint32_t fpga_roi_r_data_913; // word name
		struct {
			uint32_t roi_avg_r_data_913 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_914 14'h0F44 */
	union {
		uint32_t fpga_roi_r_data_914; // word name
		struct {
			uint32_t roi_avg_r_data_914 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_915 14'h0F48 */
	union {
		uint32_t fpga_roi_r_data_915; // word name
		struct {
			uint32_t roi_avg_r_data_915 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_916 14'h0F4C */
	union {
		uint32_t fpga_roi_r_data_916; // word name
		struct {
			uint32_t roi_avg_r_data_916 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_917 14'h0F50 */
	union {
		uint32_t fpga_roi_r_data_917; // word name
		struct {
			uint32_t roi_avg_r_data_917 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_918 14'h0F54 */
	union {
		uint32_t fpga_roi_r_data_918; // word name
		struct {
			uint32_t roi_avg_r_data_918 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_919 14'h0F58 */
	union {
		uint32_t fpga_roi_r_data_919; // word name
		struct {
			uint32_t roi_avg_r_data_919 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_920 14'h0F5C */
	union {
		uint32_t fpga_roi_r_data_920; // word name
		struct {
			uint32_t roi_avg_r_data_920 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_921 14'h0F60 */
	union {
		uint32_t fpga_roi_r_data_921; // word name
		struct {
			uint32_t roi_avg_r_data_921 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_922 14'h0F64 */
	union {
		uint32_t fpga_roi_r_data_922; // word name
		struct {
			uint32_t roi_avg_r_data_922 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_923 14'h0F68 */
	union {
		uint32_t fpga_roi_r_data_923; // word name
		struct {
			uint32_t roi_avg_r_data_923 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_924 14'h0F6C */
	union {
		uint32_t fpga_roi_r_data_924; // word name
		struct {
			uint32_t roi_avg_r_data_924 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_925 14'h0F70 */
	union {
		uint32_t fpga_roi_r_data_925; // word name
		struct {
			uint32_t roi_avg_r_data_925 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_926 14'h0F74 */
	union {
		uint32_t fpga_roi_r_data_926; // word name
		struct {
			uint32_t roi_avg_r_data_926 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_927 14'h0F78 */
	union {
		uint32_t fpga_roi_r_data_927; // word name
		struct {
			uint32_t roi_avg_r_data_927 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_928 14'h0F7C */
	union {
		uint32_t fpga_roi_r_data_928; // word name
		struct {
			uint32_t roi_avg_r_data_928 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_929 14'h0F80 */
	union {
		uint32_t fpga_roi_r_data_929; // word name
		struct {
			uint32_t roi_avg_r_data_929 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_930 14'h0F84 */
	union {
		uint32_t fpga_roi_r_data_930; // word name
		struct {
			uint32_t roi_avg_r_data_930 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_931 14'h0F88 */
	union {
		uint32_t fpga_roi_r_data_931; // word name
		struct {
			uint32_t roi_avg_r_data_931 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_932 14'h0F8C */
	union {
		uint32_t fpga_roi_r_data_932; // word name
		struct {
			uint32_t roi_avg_r_data_932 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_933 14'h0F90 */
	union {
		uint32_t fpga_roi_r_data_933; // word name
		struct {
			uint32_t roi_avg_r_data_933 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_934 14'h0F94 */
	union {
		uint32_t fpga_roi_r_data_934; // word name
		struct {
			uint32_t roi_avg_r_data_934 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_935 14'h0F98 */
	union {
		uint32_t fpga_roi_r_data_935; // word name
		struct {
			uint32_t roi_avg_r_data_935 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_936 14'h0F9C */
	union {
		uint32_t fpga_roi_r_data_936; // word name
		struct {
			uint32_t roi_avg_r_data_936 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_937 14'h0FA0 */
	union {
		uint32_t fpga_roi_r_data_937; // word name
		struct {
			uint32_t roi_avg_r_data_937 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_938 14'h0FA4 */
	union {
		uint32_t fpga_roi_r_data_938; // word name
		struct {
			uint32_t roi_avg_r_data_938 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_939 14'h0FA8 */
	union {
		uint32_t fpga_roi_r_data_939; // word name
		struct {
			uint32_t roi_avg_r_data_939 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_940 14'h0FAC */
	union {
		uint32_t fpga_roi_r_data_940; // word name
		struct {
			uint32_t roi_avg_r_data_940 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_941 14'h0FB0 */
	union {
		uint32_t fpga_roi_r_data_941; // word name
		struct {
			uint32_t roi_avg_r_data_941 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_942 14'h0FB4 */
	union {
		uint32_t fpga_roi_r_data_942; // word name
		struct {
			uint32_t roi_avg_r_data_942 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_943 14'h0FB8 */
	union {
		uint32_t fpga_roi_r_data_943; // word name
		struct {
			uint32_t roi_avg_r_data_943 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_944 14'h0FBC */
	union {
		uint32_t fpga_roi_r_data_944; // word name
		struct {
			uint32_t roi_avg_r_data_944 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_945 14'h0FC0 */
	union {
		uint32_t fpga_roi_r_data_945; // word name
		struct {
			uint32_t roi_avg_r_data_945 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_946 14'h0FC4 */
	union {
		uint32_t fpga_roi_r_data_946; // word name
		struct {
			uint32_t roi_avg_r_data_946 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_947 14'h0FC8 */
	union {
		uint32_t fpga_roi_r_data_947; // word name
		struct {
			uint32_t roi_avg_r_data_947 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_948 14'h0FCC */
	union {
		uint32_t fpga_roi_r_data_948; // word name
		struct {
			uint32_t roi_avg_r_data_948 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_949 14'h0FD0 */
	union {
		uint32_t fpga_roi_r_data_949; // word name
		struct {
			uint32_t roi_avg_r_data_949 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_950 14'h0FD4 */
	union {
		uint32_t fpga_roi_r_data_950; // word name
		struct {
			uint32_t roi_avg_r_data_950 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_951 14'h0FD8 */
	union {
		uint32_t fpga_roi_r_data_951; // word name
		struct {
			uint32_t roi_avg_r_data_951 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_952 14'h0FDC */
	union {
		uint32_t fpga_roi_r_data_952; // word name
		struct {
			uint32_t roi_avg_r_data_952 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_953 14'h0FE0 */
	union {
		uint32_t fpga_roi_r_data_953; // word name
		struct {
			uint32_t roi_avg_r_data_953 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_954 14'h0FE4 */
	union {
		uint32_t fpga_roi_r_data_954; // word name
		struct {
			uint32_t roi_avg_r_data_954 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_955 14'h0FE8 */
	union {
		uint32_t fpga_roi_r_data_955; // word name
		struct {
			uint32_t roi_avg_r_data_955 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_956 14'h0FEC */
	union {
		uint32_t fpga_roi_r_data_956; // word name
		struct {
			uint32_t roi_avg_r_data_956 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_957 14'h0FF0 */
	union {
		uint32_t fpga_roi_r_data_957; // word name
		struct {
			uint32_t roi_avg_r_data_957 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_958 14'h0FF4 */
	union {
		uint32_t fpga_roi_r_data_958; // word name
		struct {
			uint32_t roi_avg_r_data_958 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_959 14'h0FF8 */
	union {
		uint32_t fpga_roi_r_data_959; // word name
		struct {
			uint32_t roi_avg_r_data_959 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_960 14'h0FFC */
	union {
		uint32_t fpga_roi_r_data_960; // word name
		struct {
			uint32_t roi_avg_r_data_960 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_961 14'h1000 */
	union {
		uint32_t fpga_roi_r_data_961; // word name
		struct {
			uint32_t roi_avg_r_data_961 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_962 14'h1004 */
	union {
		uint32_t fpga_roi_r_data_962; // word name
		struct {
			uint32_t roi_avg_r_data_962 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_963 14'h1008 */
	union {
		uint32_t fpga_roi_r_data_963; // word name
		struct {
			uint32_t roi_avg_r_data_963 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_964 14'h100C */
	union {
		uint32_t fpga_roi_r_data_964; // word name
		struct {
			uint32_t roi_avg_r_data_964 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_965 14'h1010 */
	union {
		uint32_t fpga_roi_r_data_965; // word name
		struct {
			uint32_t roi_avg_r_data_965 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_966 14'h1014 */
	union {
		uint32_t fpga_roi_r_data_966; // word name
		struct {
			uint32_t roi_avg_r_data_966 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_967 14'h1018 */
	union {
		uint32_t fpga_roi_r_data_967; // word name
		struct {
			uint32_t roi_avg_r_data_967 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_968 14'h101C */
	union {
		uint32_t fpga_roi_r_data_968; // word name
		struct {
			uint32_t roi_avg_r_data_968 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_969 14'h1020 */
	union {
		uint32_t fpga_roi_r_data_969; // word name
		struct {
			uint32_t roi_avg_r_data_969 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_970 14'h1024 */
	union {
		uint32_t fpga_roi_r_data_970; // word name
		struct {
			uint32_t roi_avg_r_data_970 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_971 14'h1028 */
	union {
		uint32_t fpga_roi_r_data_971; // word name
		struct {
			uint32_t roi_avg_r_data_971 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_972 14'h102C */
	union {
		uint32_t fpga_roi_r_data_972; // word name
		struct {
			uint32_t roi_avg_r_data_972 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_973 14'h1030 */
	union {
		uint32_t fpga_roi_r_data_973; // word name
		struct {
			uint32_t roi_avg_r_data_973 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_974 14'h1034 */
	union {
		uint32_t fpga_roi_r_data_974; // word name
		struct {
			uint32_t roi_avg_r_data_974 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_975 14'h1038 */
	union {
		uint32_t fpga_roi_r_data_975; // word name
		struct {
			uint32_t roi_avg_r_data_975 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_976 14'h103C */
	union {
		uint32_t fpga_roi_r_data_976; // word name
		struct {
			uint32_t roi_avg_r_data_976 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_977 14'h1040 */
	union {
		uint32_t fpga_roi_r_data_977; // word name
		struct {
			uint32_t roi_avg_r_data_977 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_978 14'h1044 */
	union {
		uint32_t fpga_roi_r_data_978; // word name
		struct {
			uint32_t roi_avg_r_data_978 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_979 14'h1048 */
	union {
		uint32_t fpga_roi_r_data_979; // word name
		struct {
			uint32_t roi_avg_r_data_979 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_980 14'h104C */
	union {
		uint32_t fpga_roi_r_data_980; // word name
		struct {
			uint32_t roi_avg_r_data_980 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_981 14'h1050 */
	union {
		uint32_t fpga_roi_r_data_981; // word name
		struct {
			uint32_t roi_avg_r_data_981 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_982 14'h1054 */
	union {
		uint32_t fpga_roi_r_data_982; // word name
		struct {
			uint32_t roi_avg_r_data_982 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_983 14'h1058 */
	union {
		uint32_t fpga_roi_r_data_983; // word name
		struct {
			uint32_t roi_avg_r_data_983 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_984 14'h105C */
	union {
		uint32_t fpga_roi_r_data_984; // word name
		struct {
			uint32_t roi_avg_r_data_984 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_985 14'h1060 */
	union {
		uint32_t fpga_roi_r_data_985; // word name
		struct {
			uint32_t roi_avg_r_data_985 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_986 14'h1064 */
	union {
		uint32_t fpga_roi_r_data_986; // word name
		struct {
			uint32_t roi_avg_r_data_986 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_987 14'h1068 */
	union {
		uint32_t fpga_roi_r_data_987; // word name
		struct {
			uint32_t roi_avg_r_data_987 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_988 14'h106C */
	union {
		uint32_t fpga_roi_r_data_988; // word name
		struct {
			uint32_t roi_avg_r_data_988 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_989 14'h1070 */
	union {
		uint32_t fpga_roi_r_data_989; // word name
		struct {
			uint32_t roi_avg_r_data_989 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_990 14'h1074 */
	union {
		uint32_t fpga_roi_r_data_990; // word name
		struct {
			uint32_t roi_avg_r_data_990 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_991 14'h1078 */
	union {
		uint32_t fpga_roi_r_data_991; // word name
		struct {
			uint32_t roi_avg_r_data_991 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_992 14'h107C */
	union {
		uint32_t fpga_roi_r_data_992; // word name
		struct {
			uint32_t roi_avg_r_data_992 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_993 14'h1080 */
	union {
		uint32_t fpga_roi_r_data_993; // word name
		struct {
			uint32_t roi_avg_r_data_993 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_994 14'h1084 */
	union {
		uint32_t fpga_roi_r_data_994; // word name
		struct {
			uint32_t roi_avg_r_data_994 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_995 14'h1088 */
	union {
		uint32_t fpga_roi_r_data_995; // word name
		struct {
			uint32_t roi_avg_r_data_995 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_996 14'h108C */
	union {
		uint32_t fpga_roi_r_data_996; // word name
		struct {
			uint32_t roi_avg_r_data_996 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_997 14'h1090 */
	union {
		uint32_t fpga_roi_r_data_997; // word name
		struct {
			uint32_t roi_avg_r_data_997 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_998 14'h1094 */
	union {
		uint32_t fpga_roi_r_data_998; // word name
		struct {
			uint32_t roi_avg_r_data_998 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_999 14'h1098 */
	union {
		uint32_t fpga_roi_r_data_999; // word name
		struct {
			uint32_t roi_avg_r_data_999 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_1000 14'h109C */
	union {
		uint32_t fpga_roi_r_data_1000; // word name
		struct {
			uint32_t roi_avg_r_data_1000 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_1001 14'h10A0 */
	union {
		uint32_t fpga_roi_r_data_1001; // word name
		struct {
			uint32_t roi_avg_r_data_1001 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_1002 14'h10A4 */
	union {
		uint32_t fpga_roi_r_data_1002; // word name
		struct {
			uint32_t roi_avg_r_data_1002 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_1003 14'h10A8 */
	union {
		uint32_t fpga_roi_r_data_1003; // word name
		struct {
			uint32_t roi_avg_r_data_1003 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_1004 14'h10AC */
	union {
		uint32_t fpga_roi_r_data_1004; // word name
		struct {
			uint32_t roi_avg_r_data_1004 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_1005 14'h10B0 */
	union {
		uint32_t fpga_roi_r_data_1005; // word name
		struct {
			uint32_t roi_avg_r_data_1005 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_1006 14'h10B4 */
	union {
		uint32_t fpga_roi_r_data_1006; // word name
		struct {
			uint32_t roi_avg_r_data_1006 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_1007 14'h10B8 */
	union {
		uint32_t fpga_roi_r_data_1007; // word name
		struct {
			uint32_t roi_avg_r_data_1007 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_1008 14'h10BC */
	union {
		uint32_t fpga_roi_r_data_1008; // word name
		struct {
			uint32_t roi_avg_r_data_1008 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_1009 14'h10C0 */
	union {
		uint32_t fpga_roi_r_data_1009; // word name
		struct {
			uint32_t roi_avg_r_data_1009 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_1010 14'h10C4 */
	union {
		uint32_t fpga_roi_r_data_1010; // word name
		struct {
			uint32_t roi_avg_r_data_1010 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_1011 14'h10C8 */
	union {
		uint32_t fpga_roi_r_data_1011; // word name
		struct {
			uint32_t roi_avg_r_data_1011 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_1012 14'h10CC */
	union {
		uint32_t fpga_roi_r_data_1012; // word name
		struct {
			uint32_t roi_avg_r_data_1012 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_1013 14'h10D0 */
	union {
		uint32_t fpga_roi_r_data_1013; // word name
		struct {
			uint32_t roi_avg_r_data_1013 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_1014 14'h10D4 */
	union {
		uint32_t fpga_roi_r_data_1014; // word name
		struct {
			uint32_t roi_avg_r_data_1014 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_1015 14'h10D8 */
	union {
		uint32_t fpga_roi_r_data_1015; // word name
		struct {
			uint32_t roi_avg_r_data_1015 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_1016 14'h10DC */
	union {
		uint32_t fpga_roi_r_data_1016; // word name
		struct {
			uint32_t roi_avg_r_data_1016 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_1017 14'h10E0 */
	union {
		uint32_t fpga_roi_r_data_1017; // word name
		struct {
			uint32_t roi_avg_r_data_1017 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_1018 14'h10E4 */
	union {
		uint32_t fpga_roi_r_data_1018; // word name
		struct {
			uint32_t roi_avg_r_data_1018 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_1019 14'h10E8 */
	union {
		uint32_t fpga_roi_r_data_1019; // word name
		struct {
			uint32_t roi_avg_r_data_1019 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_1020 14'h10EC */
	union {
		uint32_t fpga_roi_r_data_1020; // word name
		struct {
			uint32_t roi_avg_r_data_1020 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_1021 14'h10F0 */
	union {
		uint32_t fpga_roi_r_data_1021; // word name
		struct {
			uint32_t roi_avg_r_data_1021 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_1022 14'h10F4 */
	union {
		uint32_t fpga_roi_r_data_1022; // word name
		struct {
			uint32_t roi_avg_r_data_1022 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_1023 14'h10F8 */
	union {
		uint32_t fpga_roi_r_data_1023; // word name
		struct {
			uint32_t roi_avg_r_data_1023 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_1024 14'h10FC */
	union {
		uint32_t fpga_roi_r_data_1024; // word name
		struct {
			uint32_t roi_avg_r_data_1024 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_1025 14'h1100 */
	union {
		uint32_t fpga_roi_r_data_1025; // word name
		struct {
			uint32_t roi_avg_r_data_1025 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_1026 14'h1104 */
	union {
		uint32_t fpga_roi_r_data_1026; // word name
		struct {
			uint32_t roi_avg_r_data_1026 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_1027 14'h1108 */
	union {
		uint32_t fpga_roi_r_data_1027; // word name
		struct {
			uint32_t roi_avg_r_data_1027 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_1028 14'h110C */
	union {
		uint32_t fpga_roi_r_data_1028; // word name
		struct {
			uint32_t roi_avg_r_data_1028 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_1029 14'h1110 */
	union {
		uint32_t fpga_roi_r_data_1029; // word name
		struct {
			uint32_t roi_avg_r_data_1029 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_1030 14'h1114 */
	union {
		uint32_t fpga_roi_r_data_1030; // word name
		struct {
			uint32_t roi_avg_r_data_1030 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_1031 14'h1118 */
	union {
		uint32_t fpga_roi_r_data_1031; // word name
		struct {
			uint32_t roi_avg_r_data_1031 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_1032 14'h111C */
	union {
		uint32_t fpga_roi_r_data_1032; // word name
		struct {
			uint32_t roi_avg_r_data_1032 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_1033 14'h1120 */
	union {
		uint32_t fpga_roi_r_data_1033; // word name
		struct {
			uint32_t roi_avg_r_data_1033 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_1034 14'h1124 */
	union {
		uint32_t fpga_roi_r_data_1034; // word name
		struct {
			uint32_t roi_avg_r_data_1034 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_1035 14'h1128 */
	union {
		uint32_t fpga_roi_r_data_1035; // word name
		struct {
			uint32_t roi_avg_r_data_1035 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_1036 14'h112C */
	union {
		uint32_t fpga_roi_r_data_1036; // word name
		struct {
			uint32_t roi_avg_r_data_1036 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_1037 14'h1130 */
	union {
		uint32_t fpga_roi_r_data_1037; // word name
		struct {
			uint32_t roi_avg_r_data_1037 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_1038 14'h1134 */
	union {
		uint32_t fpga_roi_r_data_1038; // word name
		struct {
			uint32_t roi_avg_r_data_1038 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_1039 14'h1138 */
	union {
		uint32_t fpga_roi_r_data_1039; // word name
		struct {
			uint32_t roi_avg_r_data_1039 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_1040 14'h113C */
	union {
		uint32_t fpga_roi_r_data_1040; // word name
		struct {
			uint32_t roi_avg_r_data_1040 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_1041 14'h1140 */
	union {
		uint32_t fpga_roi_r_data_1041; // word name
		struct {
			uint32_t roi_avg_r_data_1041 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_1042 14'h1144 */
	union {
		uint32_t fpga_roi_r_data_1042; // word name
		struct {
			uint32_t roi_avg_r_data_1042 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_1043 14'h1148 */
	union {
		uint32_t fpga_roi_r_data_1043; // word name
		struct {
			uint32_t roi_avg_r_data_1043 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_1044 14'h114C */
	union {
		uint32_t fpga_roi_r_data_1044; // word name
		struct {
			uint32_t roi_avg_r_data_1044 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_1045 14'h1150 */
	union {
		uint32_t fpga_roi_r_data_1045; // word name
		struct {
			uint32_t roi_avg_r_data_1045 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_1046 14'h1154 */
	union {
		uint32_t fpga_roi_r_data_1046; // word name
		struct {
			uint32_t roi_avg_r_data_1046 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_1047 14'h1158 */
	union {
		uint32_t fpga_roi_r_data_1047; // word name
		struct {
			uint32_t roi_avg_r_data_1047 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_1048 14'h115C */
	union {
		uint32_t fpga_roi_r_data_1048; // word name
		struct {
			uint32_t roi_avg_r_data_1048 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_1049 14'h1160 */
	union {
		uint32_t fpga_roi_r_data_1049; // word name
		struct {
			uint32_t roi_avg_r_data_1049 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_1050 14'h1164 */
	union {
		uint32_t fpga_roi_r_data_1050; // word name
		struct {
			uint32_t roi_avg_r_data_1050 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_1051 14'h1168 */
	union {
		uint32_t fpga_roi_r_data_1051; // word name
		struct {
			uint32_t roi_avg_r_data_1051 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_1052 14'h116C */
	union {
		uint32_t fpga_roi_r_data_1052; // word name
		struct {
			uint32_t roi_avg_r_data_1052 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_1053 14'h1170 */
	union {
		uint32_t fpga_roi_r_data_1053; // word name
		struct {
			uint32_t roi_avg_r_data_1053 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_1054 14'h1174 */
	union {
		uint32_t fpga_roi_r_data_1054; // word name
		struct {
			uint32_t roi_avg_r_data_1054 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_1055 14'h1178 */
	union {
		uint32_t fpga_roi_r_data_1055; // word name
		struct {
			uint32_t roi_avg_r_data_1055 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_1056 14'h117C */
	union {
		uint32_t fpga_roi_r_data_1056; // word name
		struct {
			uint32_t roi_avg_r_data_1056 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_1057 14'h1180 */
	union {
		uint32_t fpga_roi_r_data_1057; // word name
		struct {
			uint32_t roi_avg_r_data_1057 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_1058 14'h1184 */
	union {
		uint32_t fpga_roi_r_data_1058; // word name
		struct {
			uint32_t roi_avg_r_data_1058 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_1059 14'h1188 */
	union {
		uint32_t fpga_roi_r_data_1059; // word name
		struct {
			uint32_t roi_avg_r_data_1059 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_1060 14'h118C */
	union {
		uint32_t fpga_roi_r_data_1060; // word name
		struct {
			uint32_t roi_avg_r_data_1060 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_1061 14'h1190 */
	union {
		uint32_t fpga_roi_r_data_1061; // word name
		struct {
			uint32_t roi_avg_r_data_1061 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_1062 14'h1194 */
	union {
		uint32_t fpga_roi_r_data_1062; // word name
		struct {
			uint32_t roi_avg_r_data_1062 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_1063 14'h1198 */
	union {
		uint32_t fpga_roi_r_data_1063; // word name
		struct {
			uint32_t roi_avg_r_data_1063 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_1064 14'h119C */
	union {
		uint32_t fpga_roi_r_data_1064; // word name
		struct {
			uint32_t roi_avg_r_data_1064 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_1065 14'h11A0 */
	union {
		uint32_t fpga_roi_r_data_1065; // word name
		struct {
			uint32_t roi_avg_r_data_1065 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_1066 14'h11A4 */
	union {
		uint32_t fpga_roi_r_data_1066; // word name
		struct {
			uint32_t roi_avg_r_data_1066 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_1067 14'h11A8 */
	union {
		uint32_t fpga_roi_r_data_1067; // word name
		struct {
			uint32_t roi_avg_r_data_1067 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_1068 14'h11AC */
	union {
		uint32_t fpga_roi_r_data_1068; // word name
		struct {
			uint32_t roi_avg_r_data_1068 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_1069 14'h11B0 */
	union {
		uint32_t fpga_roi_r_data_1069; // word name
		struct {
			uint32_t roi_avg_r_data_1069 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_1070 14'h11B4 */
	union {
		uint32_t fpga_roi_r_data_1070; // word name
		struct {
			uint32_t roi_avg_r_data_1070 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_1071 14'h11B8 */
	union {
		uint32_t fpga_roi_r_data_1071; // word name
		struct {
			uint32_t roi_avg_r_data_1071 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_1072 14'h11BC */
	union {
		uint32_t fpga_roi_r_data_1072; // word name
		struct {
			uint32_t roi_avg_r_data_1072 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_1073 14'h11C0 */
	union {
		uint32_t fpga_roi_r_data_1073; // word name
		struct {
			uint32_t roi_avg_r_data_1073 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_1074 14'h11C4 */
	union {
		uint32_t fpga_roi_r_data_1074; // word name
		struct {
			uint32_t roi_avg_r_data_1074 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_1075 14'h11C8 */
	union {
		uint32_t fpga_roi_r_data_1075; // word name
		struct {
			uint32_t roi_avg_r_data_1075 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_1076 14'h11CC */
	union {
		uint32_t fpga_roi_r_data_1076; // word name
		struct {
			uint32_t roi_avg_r_data_1076 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_1077 14'h11d0 */
	union {
		uint32_t fpga_roi_r_data_1077; // word name
		struct {
			uint32_t roi_avg_r_data_1077 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_1078 14'h11d4 */
	union {
		uint32_t fpga_roi_r_data_1078; // word name
		struct {
			uint32_t roi_avg_r_data_1078 : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* FPGA_ROI_R_DATA_1079 14'h11d8 */
	union {
		uint32_t fpga_roi_r_data_1079; // word name
		struct {
			uint32_t roi_avg_r_data_1079 : 30;
			uint32_t : 2; // padding bits
		};
	};
} CsrBankDfk;

#endif