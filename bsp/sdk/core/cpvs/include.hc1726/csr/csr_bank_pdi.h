/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef CSR_BANK_PDI_H_
#define CSR_BANK_PDI_H_

#ifndef __KERNEL__
#include <stdint.h>
#else
#include <linux/types.h>
#endif

/***  C struct generated from pdi  ***/
typedef struct csr_bank_pdi {
	/* PDI00 9'h000 */
	union {
		uint32_t pdi00; // word name
		struct {
			uint32_t start : 1;
			uint32_t : 7; // padding bits
			uint32_t stop : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* PDI01 9'h004 */
	union {
		uint32_t pdi01; // word name
		struct {
			uint32_t irq_clear_frame_end : 1;
			uint32_t : 7; // padding bits
			uint32_t irq_clear_insufficient : 1;
			uint32_t : 7; // padding bits
			uint32_t irq_clear_drop_frame : 1;
			uint32_t : 7; // padding bits
			uint32_t irq_clear_seq_end : 1;
			uint32_t : 7; // padding bits
		};
	};
	/* PDI02 9'h008 */
	union {
		uint32_t pdi02; // word name
		struct {
			uint32_t status_frame_end : 1;
			uint32_t : 7; // padding bits
			uint32_t status_insufficient : 1;
			uint32_t : 7; // padding bits
			uint32_t status_drop_frame : 1;
			uint32_t : 7; // padding bits
			uint32_t status_seq_end : 1;
			uint32_t : 7; // padding bits
		};
	};
	/* PDI03 9'h00C */
	union {
		uint32_t pdi03; // word name
		struct {
			uint32_t irq_mask_frame_end : 1;
			uint32_t : 7; // padding bits
			uint32_t irq_mask_insufficient : 1;
			uint32_t : 7; // padding bits
			uint32_t irq_mask_drop_frame : 1;
			uint32_t : 7; // padding bits
			uint32_t irq_mask_seq_end : 1;
			uint32_t : 7; // padding bits
		};
	};
	/* PDI04 9'h010 */
	union {
		uint32_t pdi04; // word name
		struct {
			uint32_t frame_start_mode : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* PDI05 9'h014 */
	union {
		uint32_t pdi05; // word name
		struct {
			uint32_t eav : 16;
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* PDI06 9'h018 */
	union {
		uint32_t pdi06; // word name
		struct {
			uint32_t ln : 16;
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* PDI07 9'h01C */
	union {
		uint32_t pdi07; // word name
		struct {
			uint32_t crc : 16;
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* PDI08 9'h020 */
	union {
		uint32_t pdi08; // word name
		struct {
			uint32_t blank_data : 16;
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* PDI09 9'h024 */
	union {
		uint32_t pdi09; // word name
		struct {
			uint32_t sav : 16;
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* PDI10 9'h028 */
	union {
		uint32_t pdi10; // word name
		struct {
			uint32_t h_back_porch : 16;
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* PDI11 9'h02C */
	union {
		uint32_t pdi11; // word name
		struct {
			uint32_t active_data : 16;
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* PDI12 9'h030 */
	union {
		uint32_t pdi12; // word name
		struct {
			uint32_t h_front_porch : 16;
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* PDI13 9'h034 */
	union {
		uint32_t pdi13; // word name
		struct {
			uint32_t field0_vsync : 12;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* PDI14 9'h038 */
	union {
		uint32_t pdi14; // word name
		struct {
			uint32_t field0_blanking_top : 12;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* PDI15 9'h03C */
	union {
		uint32_t pdi15; // word name
		struct {
			uint32_t field0_active_data : 12;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* PDI16 9'h040 */
	union {
		uint32_t pdi16; // word name
		struct {
			uint32_t field0_blanking_bottom : 12;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* PDI17 9'h044 */
	union {
		uint32_t pdi17; // word name
		struct {
			uint32_t field1_vsync : 12;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* PDI18 9'h048 */
	union {
		uint32_t pdi18; // word name
		struct {
			uint32_t field1_blanking_top : 12;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* PDI19 9'h04C */
	union {
		uint32_t pdi19; // word name
		struct {
			uint32_t field1_active_data : 12;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* PDI20 9'h050 */
	union {
		uint32_t pdi20; // word name
		struct {
			uint32_t field1_blanking_bottom : 12;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* PDI21 9'h054 */
	union {
		uint32_t pdi21; // word name
		struct {
			uint32_t eav_user_mode : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* PDI22 9'h058 */
	union {
		uint32_t pdi22; // word name
		struct {
			uint32_t eav_user_setting_0 : 10;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* PDI23 9'h05C */
	union {
		uint32_t pdi23; // word name
		struct {
			uint32_t eav_user_setting_1 : 10;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* PDI24 9'h060 */
	union {
		uint32_t pdi24; // word name
		struct {
			uint32_t eav_user_setting_2 : 10;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* PDI25 9'h064 */
	union {
		uint32_t pdi25; // word name
		struct {
			uint32_t eav_user_setting_3 : 10;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* PDI26 9'h068 */
	union {
		uint32_t pdi26; // word name
		struct {
			uint32_t eav_user_setting_4 : 10;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* PDI27 9'h06C */
	union {
		uint32_t pdi27; // word name
		struct {
			uint32_t eav_user_setting_5 : 10;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* PDI28 9'h070 */
	union {
		uint32_t pdi28; // word name
		struct {
			uint32_t eav_user_setting_6 : 10;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* PDI29 9'h074 */
	union {
		uint32_t pdi29; // word name
		struct {
			uint32_t eav_user_setting_7 : 10;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* PDI30 9'h078 */
	union {
		uint32_t pdi30; // word name
		struct {
			uint32_t blank_data_mode : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* PDI31 9'h07C */
	union {
		uint32_t pdi31; // word name
		struct {
			uint32_t ln_height : 12;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* PDI32 9'h080 */
	union {
		uint32_t pdi32; // word name
		struct {
			uint32_t crc_empty_mode : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* PDI33 9'h084 */
	union {
		uint32_t pdi33; // word name
		struct {
			uint32_t sav_user_mode : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* PDI34 9'h088 */
	union {
		uint32_t pdi34; // word name
		struct {
			uint32_t sav_user_setting_0 : 10;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* PDI35 9'h08C */
	union {
		uint32_t pdi35; // word name
		struct {
			uint32_t sav_user_setting_1 : 10;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* PDI36 9'h090 */
	union {
		uint32_t pdi36; // word name
		struct {
			uint32_t sav_user_setting_2 : 10;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* PDI37 9'h094 */
	union {
		uint32_t pdi37; // word name
		struct {
			uint32_t sav_user_setting_3 : 10;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* PDI38 9'h098 */
	union {
		uint32_t pdi38; // word name
		struct {
			uint32_t sav_user_setting_4 : 10;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* PDI39 9'h09C */
	union {
		uint32_t pdi39; // word name
		struct {
			uint32_t sav_user_setting_5 : 10;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* PDI40 9'h0A0 */
	union {
		uint32_t pdi40; // word name
		struct {
			uint32_t sav_user_setting_6 : 10;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* PDI41 9'h0A4 */
	union {
		uint32_t pdi41; // word name
		struct {
			uint32_t sav_user_setting_7 : 10;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* PDI42 9'h0A8 */
	union {
		uint32_t pdi42; // word name
		struct {
			uint32_t hbp_mode : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* PDI43 9'h0AC */
	union {
		uint32_t pdi43; // word name
		struct {
			uint32_t empty_data_mode : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* PDI44 9'h0B0 */
	union {
		uint32_t pdi44; // word name
		struct {
			uint32_t hfp_mode : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* PDI45 9'h0B4 */
	union {
		uint32_t pdi45; // word name
		struct {
			uint32_t active_data_rab_uppacker : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* PDI46 9'h0B8 */
	union {
		uint32_t pdi46; // word name
		struct {
			uint32_t active_data_rab_bypass : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* PDI47 9'h0BC */
	union {
		uint32_t pdi47; // word name
		struct {
			uint32_t active_data_ram_active : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* PDI48 9'h0C0 */
	union {
		uint32_t pdi48; // word name
		struct {
			uint32_t data_format_sel : 3;
			uint32_t : 5; // padding bits
			uint32_t rgb_bitwidth_sel : 2;
			uint32_t : 6; // padding bits
			uint32_t mcu_format_en : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* PDI49 9'h0C4 */
	union {
		uint32_t pdi49; // word name
		struct {
			uint32_t vsync_set : 9;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* PDI50 9'h0C8 */
	union {
		uint32_t pdi50; // word name
		struct {
			uint32_t hsync_set : 9;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* PDI51 9'h0CC */
	union {
		uint32_t pdi51; // word name
		struct {
			uint32_t de_set : 11;
			uint32_t : 5; // padding bits
			uint32_t wrx_set : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* PDI52 9'h0D0 */
	union {
		uint32_t pdi52; // word name
		struct {
			uint32_t mode : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* PDI53 9'h0D4 */
	union {
		uint32_t pdi53; // word name
		struct {
			uint32_t dummy_th : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* PDI54 9'h0D8 */
	union {
		uint32_t pdi54; // word name
		struct {
			uint32_t wxh : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* PDI55 9'h0DC */
	union {
		uint32_t pdi55; // word name
		struct {
			uint32_t width : 16;
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* PDI56 9'h0E0 */
	union {
		uint32_t pdi56; // word name
		struct {
			uint32_t height : 12;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* PDI57 9'h0E4 */
	union {
		uint32_t pdi57; // word name
		struct {
			uint32_t value_0_i : 10;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* PDI58 9'h0E8 */
	union {
		uint32_t pdi58; // word name
		struct {
			uint32_t value_1_i : 10;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* PDI59 9'h0EC */
	union {
		uint32_t pdi59; // word name
		struct {
			uint32_t value_2_i : 10;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* PDI60 9'h0F0 */
	union {
		uint32_t pdi60; // word name
		struct {
			uint32_t reg_pd_reset : 1;
			uint32_t : 7; // padding bits
			uint32_t reg_sd : 1;
			uint32_t : 7; // padding bits
			uint32_t reg_cm : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* PDI61 9'h0F4 */
	union {
		uint32_t pdi61; // word name
		struct {
			uint32_t is_one_frame : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* PDI62 9'h0F8 */
	union {
		uint32_t pdi62; // word name
		struct {
			uint32_t frame_cnt : 16;
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* PDI63 9'h0FC */
	union {
		uint32_t pdi63; // word name
		struct {
			uint32_t frame_cnt_clear : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* PDI64 9'h100 */
	union {
		uint32_t pdi64; // word name
		struct {
			uint32_t csr_wrx_i : 1;
			uint32_t : 7; // padding bits
			uint32_t csr_rdx_i : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* PDI65 9'h104 */
	union {
		uint32_t pdi65; // word name
		struct {
			uint32_t csr_csx_i : 1;
			uint32_t : 7; // padding bits
			uint32_t csr_dcx_i : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* PDI66 9'h108 */
	union {
		uint32_t pdi66; // word name
		struct {
			uint32_t csr_data_i : 18;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* PDI67 9'h10C */
	union {
		uint32_t pdi67; // word name
		struct {
			uint32_t mapping_sel : 4;
			uint32_t : 4; // padding bits
			uint32_t up_sampling : 2;
			uint32_t : 6; // padding bits
			uint32_t double_sampling : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* PDI68 9'h110 */
	union {
		uint32_t pdi68; // word name
		struct {
			uint32_t : 8; // padding bits
			uint32_t csr_data_i_en : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* PDI69 9'h114 */
	union {
		uint32_t pdi69; // word name
		struct {
			uint32_t reserved : 32;
		};
	};
} CsrBankPdi;

#endif