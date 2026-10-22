#ifndef CSR_BANK_DEC_H_
#define CSR_BANK_DEC_H_

#ifndef __KERNEL__
#include <stdint.h>
#else
#include <linux/types.h>
#endif

/***  C struct generated from dec  ***/
typedef struct csr_bank_dec {
	/* MAIN 10'h000 */
	union {
		uint32_t main; // word name
		struct {
			uint32_t dec_en : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* RST 10'h004 */
	union {
		uint32_t rst; // word name
		struct {
			uint32_t dec_reset : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t frame_reset : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* IRQSTA 10'h008 */
	union {
		uint32_t irqsta; // word name
		struct {
			uint32_t status_frame_done : 1;
			uint32_t status_frame_end : 1;
			uint32_t status_frame_start : 1;
			uint32_t status_mipi_short_pkt : 1;
			uint32_t status_mipi_ecc_crt : 1;
			uint32_t status_mipi_ecc_err : 1;
			uint32_t status_mipi_pkt_err : 1;
			uint32_t status_mipi_vc_err : 1;
			uint32_t status_mipi_crc_err : 1;
			uint32_t status_mipi_ovr_err : 1;
			uint32_t status_mipi_word_err : 1;
			uint32_t status_mipi_line_err : 1;
			uint32_t status_hsp_ptc_err : 1;
			uint32_t status_sony_ptc_err : 1;
			uint32_t status_frame_size_err : 1;
			uint32_t status_fifo_over_err : 1;
			uint32_t status_lane_skew_err : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* IRQACK 10'h00C */
	union {
		uint32_t irqack; // word name
		struct {
			uint32_t irq_clear_frame_done : 1;
			uint32_t irq_clear_frame_end : 1;
			uint32_t irq_clear_frame_start : 1;
			uint32_t irq_clear_mipi_short_pkt : 1;
			uint32_t irq_clear_mipi_ecc_crt : 1;
			uint32_t irq_clear_mipi_ecc_err : 1;
			uint32_t irq_clear_mipi_pkt_err : 1;
			uint32_t irq_clear_mipi_vc_err : 1;
			uint32_t irq_clear_mipi_crc_err : 1;
			uint32_t irq_clear_mipi_ovr_err : 1;
			uint32_t irq_clear_mipi_word_err : 1;
			uint32_t irq_clear_mipi_line_err : 1;
			uint32_t irq_clear_hsp_ptc_err : 1;
			uint32_t irq_clear_sony_ptc_err : 1;
			uint32_t irq_clear_frame_size_err : 1;
			uint32_t irq_clear_fifo_over_err : 1;
			uint32_t irq_clear_lane_skew_err : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* IRQMSK 10'h010 */
	union {
		uint32_t irqmsk; // word name
		struct {
			uint32_t irq_mask_frame_done : 1;
			uint32_t irq_mask_frame_end : 1;
			uint32_t irq_mask_frame_start : 1;
			uint32_t irq_mask_mipi_short_pkt : 1;
			uint32_t irq_mask_mipi_ecc_crt : 1;
			uint32_t irq_mask_mipi_ecc_err : 1;
			uint32_t irq_mask_mipi_pkt_err : 1;
			uint32_t irq_mask_mipi_vc_err : 1;
			uint32_t irq_mask_mipi_crc_err : 1;
			uint32_t irq_mask_mipi_ovr_err : 1;
			uint32_t irq_mask_mipi_word_err : 1;
			uint32_t irq_mask_mipi_line_err : 1;
			uint32_t irq_mask_hsp_ptc_err : 1;
			uint32_t irq_mask_sony_ptc_err : 1;
			uint32_t irq_mask_frame_size_err : 1;
			uint32_t irq_mask_fifo_over_err : 1;
			uint32_t irq_mask_lane_skew_err : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CFG 10'h014 */
	union {
		uint32_t cfg; // word name
		struct {
			uint32_t spec_sel : 3;
			uint32_t : 5; // padding bits
			uint32_t mode_sel : 2;
			uint32_t : 6; // padding bits
			uint32_t lane_sel : 2;
			uint32_t : 6; // padding bits
			uint32_t mipi_sw_en : 1;
			uint32_t : 3; // padding bits
			uint32_t mipi_sw_num : 2;
			uint32_t : 2; // padding bits
		};
	};
	/* WORD 10'h018 */
	union {
		uint32_t word; // word name
		struct {
			uint32_t word_size : 3;
			uint32_t : 5; // padding bits
			uint32_t msb_first : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WTH 10'h01C */
	union {
		uint32_t wth; // word name
		struct {
			uint32_t word_num : 16;
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* HIGH 10'h020 */
	union {
		uint32_t high; // word name
		struct {
			uint32_t line_num : 16;
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* HSP 10'h024 */
	union {
		uint32_t hsp; // word name
		struct {
			uint32_t enable_word_flr : 1;
			uint32_t : 7; // padding bits
			uint32_t enable_word_crc : 1;
			uint32_t : 7; // padding bits
			uint32_t ail_msb_first : 1;
			uint32_t : 7; // padding bits
			uint32_t flr_word_num : 8;
		};
	};
	/* VBLK 10'h028 */
	union {
		uint32_t vblk; // word name
		struct {
			uint32_t vbp_line_num : 12;
			uint32_t : 4; // padding bits
			uint32_t vfp_line_num : 12;
			uint32_t : 4; // padding bits
		};
	};
	/* HBLK 10'h02C */
	union {
		uint32_t hblk; // word name
		struct {
			uint32_t hbp_word_num : 16;
			uint32_t hfp_word_num : 16;
		};
	};
	/* CHK 10'h030 */
	union {
		uint32_t chk; // word name
		struct {
			uint32_t dis_ecc_crt : 1;
			uint32_t : 7; // padding bits
			uint32_t dis_crc_check : 1;
			uint32_t : 7; // padding bits
			uint32_t vc_num_bypass : 16;
		};
	};
	/* MIPI0 10'h034 */
	union {
		uint32_t mipi0; // word name
		struct {
			uint32_t short_pkt_en : 8;
			uint32_t user_pkt_en : 8;
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* MIPI1 10'h038 */
	union {
		uint32_t mipi1; // word name
		struct {
			uint32_t out0_vc_vld : 16;
			uint32_t out1_vc_vld : 16;
		};
	};
	/* ERR 10'h03C */
	union {
		uint32_t err; // word name
		struct {
			uint32_t ec_en : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* SIZE 10'h040 */
	union {
		uint32_t size; // word name
		struct {
			uint32_t width : 16;
			uint32_t height : 16;
		};
	};
	/* OUT 10'h044 */
	union {
		uint32_t out; // word name
		struct {
			uint32_t frame_start_sel : 2;
			uint32_t : 6; // padding bits
			uint32_t frame_done_sel : 2;
			uint32_t : 6; // padding bits
			uint32_t frame_end_sel : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* DCMP 10'h048 */
	union {
		uint32_t dcmp; // word name
		struct {
			uint32_t dcmp_en : 1;
			uint32_t : 7; // padding bits
			uint32_t dcmp_mode : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* SONY 10'h04C */
	union {
		uint32_t sony; // word name
		struct {
			uint32_t dol_sydinfo_en : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FCNT 10'h050 */
	union {
		uint32_t fcnt; // word name
		struct {
			uint32_t frame_count_0 : 16;
			uint32_t frame_count_1 : 16;
		};
	};
	/* GSPKT 10'h054 */
	union {
		uint32_t gspkt; // word name
		struct {
			uint32_t gene_short_pkt : 24;
			uint32_t : 4; // padding bits
			uint32_t mipi_sw_status : 2;
			uint32_t : 2; // padding bits
		};
	};
	/* DBG0 10'h058 */
	union {
		uint32_t dbg0; // word name
		struct {
			uint32_t debug_sel : 4;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* DBG1 10'h05C */
	union {
		uint32_t dbg1; // word name
		struct {
			uint32_t debug_mon : 32;
		};
	};
	/* CSTM0 10'h060 */
	union {
		uint32_t cstm0; // word name
		struct {
			uint32_t custom_sync_code_size : 4;
			uint32_t : 4; // padding bits
			uint32_t custom_byte_format : 1;
			uint32_t : 7; // padding bits
			uint32_t custom_dis_eof_eol : 1;
			uint32_t : 7; // padding bits
			uint32_t custom_dis_sof_eof : 1;
			uint32_t : 7; // padding bits
		};
	};
	/* CSTM1 10'h064 */
	union {
		uint32_t cstm1; // word name
		struct {
			uint32_t custom_idl : 16;
			uint32_t enable_custom_idl : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CSTM2 10'h068 */
	union {
		uint32_t cstm2; // word name
		struct {
			uint32_t custom_sync_code_0 : 16;
			uint32_t custom_sync_code_1 : 16;
		};
	};
	/* CSTM3 10'h06C */
	union {
		uint32_t cstm3; // word name
		struct {
			uint32_t custom_sync_code_2 : 16;
			uint32_t custom_sync_code_3 : 16;
		};
	};
	/* CSTM4 10'h070 */
	union {
		uint32_t cstm4; // word name
		struct {
			uint32_t custom_sync_code_4 : 16;
			uint32_t custom_sync_code_5 : 16;
		};
	};
	/* CSTM5 10'h074 */
	union {
		uint32_t cstm5; // word name
		struct {
			uint32_t custom_sync_code_6 : 16;
			uint32_t custom_sync_code_7 : 16;
		};
	};
	/* CSTM6 10'h078 */
	union {
		uint32_t cstm6; // word name
		struct {
			uint32_t custom_sof_0 : 16;
			uint32_t custom_sol_0 : 16;
		};
	};
	/* CSTM7 10'h07C */
	union {
		uint32_t cstm7; // word name
		struct {
			uint32_t custom_eof_0 : 16;
			uint32_t custom_eol_0 : 16;
		};
	};
	/* CSTM8 10'h080 */
	union {
		uint32_t cstm8; // word name
		struct {
			uint32_t custom_sof_1 : 16;
			uint32_t custom_sol_1 : 16;
		};
	};
	/* CSTM9 10'h084 */
	union {
		uint32_t cstm9; // word name
		struct {
			uint32_t custom_eof_1 : 16;
			uint32_t custom_eol_1 : 16;
		};
	};
	/* CSTM10 10'h088 */
	union {
		uint32_t cstm10; // word name
		struct {
			uint32_t custom_sof_2 : 16;
			uint32_t custom_sol_2 : 16;
		};
	};
	/* CSTM11 10'h08C */
	union {
		uint32_t cstm11; // word name
		struct {
			uint32_t custom_eof_2 : 16;
			uint32_t custom_eol_2 : 16;
		};
	};
	/* CSTM12 10'h090 */
	union {
		uint32_t cstm12; // word name
		struct {
			uint32_t custom_sof_3 : 16;
			uint32_t custom_sol_3 : 16;
		};
	};
	/* CSTM13 10'h094 */
	union {
		uint32_t cstm13; // word name
		struct {
			uint32_t custom_eof_3 : 16;
			uint32_t custom_eol_3 : 16;
		};
	};
	/* STA0 10'h098 */
	union {
		uint32_t sta0; // word name
		struct {
			uint32_t sync_bytes : 32;
		};
	};
	/* STAH0 10'h09C */
	union {
		uint32_t stah0; // word name
		struct {
			uint32_t hispi_status : 8;
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* STAH1 10'h0A0 */
	union {
		uint32_t stah1; // word name
		struct {
			uint32_t hispi_active_count : 16;
			uint32_t hispi_blank_count : 16;
		};
	};
	/* STAH2 10'h0A4 */
	union {
		uint32_t stah2; // word name
		struct {
			uint32_t hispi_word_count : 16;
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* STAS0 10'h0A8 */
	union {
		uint32_t stas0; // word name
		struct {
			uint32_t sony_status : 16;
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* STAS1 10'h0AC */
	union {
		uint32_t stas1; // word name
		struct {
			uint32_t sony_active_count : 16;
			uint32_t sony_blank_count : 16;
		};
	};
	/* STAS2 10'h0B0 */
	union {
		uint32_t stas2; // word name
		struct {
			uint32_t sony_word_count : 16;
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* STAM0 10'h0B4 */
	union {
		uint32_t stam0; // word name
		struct {
			uint32_t mipi_hs_ln0_sta : 8;
			uint32_t mipi_hs_ln1_sta : 8;
			uint32_t mipi_hs_ln2_sta : 8;
			uint32_t mipi_hs_ln3_sta : 8;
		};
	};
	/* STAM1 10'h0B8 */
	union {
		uint32_t stam1; // word name
		struct {
			uint32_t mipi_active_count : 16;
			uint32_t mipi_active_count_1 : 16;
		};
	};
	/* STAM2 10'h0BC */
	union {
		uint32_t stam2; // word name
		struct {
			uint32_t mipi_blank_count : 16;
			uint32_t mipi_blank_count_1 : 16;
		};
	};
	/* STAM3 10'h0C0 */
	union {
		uint32_t stam3; // word name
		struct {
			uint32_t mipi_word_count : 16;
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* STAM4 10'h0C4 */
	union {
		uint32_t stam4; // word name
		struct {
			uint32_t mipi_frame_number : 16;
			uint32_t mipi_frame_number_1 : 16;
		};
	};
	/* STAM5 10'h0C8 */
	union {
		uint32_t stam5; // word name
		struct {
			uint32_t mipi_crc_word : 16;
			uint32_t mipi_crc_calc : 16;
		};
	};
	/* STAM6 10'h0CC */
	union {
		uint32_t stam6; // word name
		struct {
			uint32_t pkt_hdr_rec_0 : 32;
		};
	};
	/* STAM7 10'h0D0 */
	union {
		uint32_t stam7; // word name
		struct {
			uint32_t pkt_hdr_rec_1 : 32;
		};
	};
	/* STAM8 10'h0D4 */
	union {
		uint32_t stam8; // word name
		struct {
			uint32_t pkt_hdr_rec_2 : 32;
		};
	};
	/* STAM9 10'h0D8 */
	union {
		uint32_t stam9; // word name
		struct {
			uint32_t pkt_hdr_rec_3 : 32;
		};
	};
} CsrBankDec;

#endif