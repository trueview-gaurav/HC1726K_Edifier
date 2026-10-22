#ifndef CSR_BANK_TX_ENC_H_
#define CSR_BANK_TX_ENC_H_

#ifndef __KERNEL__
#include <stdint.h>
#else
#include <linux/types.h>
#endif

/***  C struct generated from tx_enc  ***/
typedef struct csr_bank_tx_enc {
	/* EN 10'h000 */
	union {
		uint32_t en; // word name
		struct {
			uint32_t enable : 1;
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
			uint32_t frame_reset : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t soft_reset : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CTRL 10'h008 */
	union {
		uint32_t ctrl; // word name
		struct {
			uint32_t start : 1;
			uint32_t : 7; // padding bits
			uint32_t stop : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* IRQSTA 10'h00C */
	union {
		uint32_t irqsta; // word name
		struct {
			uint32_t status_frame_end : 1;
			uint32_t status_frame_start : 1;
			uint32_t status_fifo_undrflow : 1;
			uint32_t status_tearing_effect : 1;
			uint32_t status_err_read_fifo_over_write : 1;
			uint32_t status_inf_check_cmd_ecc : 1;
			uint32_t status_err_check_cmd_ecc : 1;
			uint32_t status_err_check_crc : 1;
			uint32_t status_err_bit_format : 1;
			uint32_t status_ta_to : 1;
			uint32_t status_presp_to : 1;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* IRQMSK 10'h010 */
	union {
		uint32_t irqmsk; // word name
		struct {
			uint32_t irq_mask_frame_end : 1;
			uint32_t irq_mask_frame_start : 1;
			uint32_t irq_mask_fifo_undrflow : 1;
			uint32_t irq_mask_tearing_effect : 1;
			uint32_t irq_mask_err_read_fifo_over_write : 1;
			uint32_t irq_mask_inf_check_cmd_ecc : 1;
			uint32_t irq_mask_err_check_cmd_ecc : 1;
			uint32_t irq_mask_err_check_crc : 1;
			uint32_t irq_mask_err_bit_format : 1;
			uint32_t irq_mask_ta_to : 1;
			uint32_t irq_mask_presp_to : 1;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* IRQACK 10'h014 */
	union {
		uint32_t irqack; // word name
		struct {
			uint32_t irq_clear_frame_end : 1;
			uint32_t irq_clear_frame_start : 1;
			uint32_t irq_clear_fifo_undrflow : 1;
			uint32_t irq_clear_tearing_effect : 1;
			uint32_t irq_clear_err_read_fifo_over_write : 1;
			uint32_t irq_clear_inf_check_cmd_ecc : 1;
			uint32_t irq_clear_err_check_cmd_ecc : 1;
			uint32_t irq_clear_err_check_crc : 1;
			uint32_t irq_clear_err_bit_format : 1;
			uint32_t irq_clear_ta_to : 1;
			uint32_t irq_clear_presp_to : 1;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* SPEC 10'h018 */
	union {
		uint32_t spec; // word name
		struct {
			uint32_t lane_sel : 2;
			uint32_t : 6; // padding bits
			uint32_t mipi_spec : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FMT 10'h01C */
	union {
		uint32_t fmt; // word name
		struct {
			uint32_t data_type : 4;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* PIX 10'h020 */
	union {
		uint32_t pix; // word name
		struct {
			uint32_t width : 16;
			uint32_t height : 16;
		};
	};
	/* WC 10'h024 */
	union {
		uint32_t wc; // word name
		struct {
			uint32_t word_cnt : 16;
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* DSI 10'h028 */
	union {
		uint32_t dsi; // word name
		struct {
			uint32_t dsi_mode : 1;
			uint32_t : 7; // padding bits
			uint32_t eotp_en : 1;
			uint32_t : 7; // padding bits
			uint32_t cm_mode_sel : 1;
			uint32_t : 7; // padding bits
			uint32_t dis_ecc_crt : 1;
			uint32_t : 7; // padding bits
		};
	};
	/* CSI 10'h02C */
	union {
		uint32_t csi; // word name
		struct {
			uint32_t line_sync : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* MIPI 10'h030 */
	union {
		uint32_t mipi; // word name
		struct {
			uint32_t clk_mode : 2;
			uint32_t : 6; // padding bits
			uint32_t clk_freerun : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* PKT 10'h034 */
	union {
		uint32_t pkt; // word name
		struct {
			uint32_t vc_num : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* VM0 10'h038 */
	union {
		uint32_t vm0; // word name
		struct {
			uint32_t vm_type : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* VM1 10'h03C */
	union {
		uint32_t vm1; // word name
		struct {
			uint32_t perd_hsa : 12;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* VM2 10'h040 */
	union {
		uint32_t vm2; // word name
		struct {
			uint32_t perd_hbp : 12;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* VM3 10'h044 */
	union {
		uint32_t vm3; // word name
		struct {
			uint32_t perd_hfp : 12;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* VM4 10'h048 */
	union {
		uint32_t vm4; // word name
		struct {
			uint32_t line_vsa : 12;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* VM5 10'h04C */
	union {
		uint32_t vm5; // word name
		struct {
			uint32_t line_vbp : 12;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* VM6 10'h050 */
	union {
		uint32_t vm6; // word name
		struct {
			uint32_t line_vfp : 12;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* VM7 10'h054 */
	union {
		uint32_t vm7; // word name
		struct {
			uint32_t lp_hsa : 1;
			uint32_t : 7; // padding bits
			uint32_t lp_hbp : 1;
			uint32_t : 7; // padding bits
			uint32_t lp_hfp : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* VM8 10'h058 [Unused] */
	uint32_t empty_word_vm8;
	/* VM9 10'h05C [Unused] */
	uint32_t empty_word_vm9;
	/* CM0 10'h060 */
	union {
		uint32_t cm0; // word name
		struct {
			uint32_t auto_mode : 1;
			uint32_t : 7; // padding bits
			uint32_t read_cmdq : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CM1 10'h064 */
	union {
		uint32_t cm1; // word name
		struct {
			uint32_t te_en : 1;
			uint32_t : 7; // padding bits
			uint32_t te_src : 2;
			uint32_t : 6; // padding bits
			uint32_t te_detect : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CM2 10'h068 */
	union {
		uint32_t cm2; // word name
		struct {
			uint32_t te_toggle : 1;
			uint32_t : 7; // padding bits
			uint32_t te_cmd_header : 8;
			uint32_t te_esc_header : 8;
			uint32_t : 8; // padding bits
		};
	};
	/* CM3 10'h06C [Unused] */
	uint32_t empty_word_cm3;
	/* DCS 10'h070 */
	union {
		uint32_t dcs; // word name
		struct {
			uint32_t dcs_wm_start : 8;
			uint32_t dcs_wm_cont : 8;
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* MIPITXENC029 10'h074 [Unused] */
	uint32_t empty_word_mipitxenc029;
	/* MIPITXENC030 10'h078 [Unused] */
	uint32_t empty_word_mipitxenc030;
	/* MIPITXENC031 10'h07C [Unused] */
	uint32_t empty_word_mipitxenc031;
	/* TIME0 10'h080 */
	union {
		uint32_t time0; // word name
		struct {
			uint32_t time_lpx : 8;
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* TIME1 10'h084 */
	union {
		uint32_t time1; // word name
		struct {
			uint32_t time_hs_prepare : 8;
			uint32_t time_hs_zero : 8;
			uint32_t time_hs_trail : 8;
			uint32_t time_hs_exit : 8;
		};
	};
	/* TIME2 10'h088 */
	union {
		uint32_t time2; // word name
		struct {
			uint32_t time_clk_prepare : 8;
			uint32_t time_clk_zero : 8;
			uint32_t time_clk_trail : 8;
			uint32_t time_clk_exit : 8;
		};
	};
	/* TIME3 10'h08C */
	union {
		uint32_t time3; // word name
		struct {
			uint32_t time_clk_pre : 8;
			uint32_t time_clk_post : 8;
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* TIME4 10'h090 */
	union {
		uint32_t time4; // word name
		struct {
			uint32_t time_wakeup : 12;
			uint32_t : 4; // padding bits
			uint32_t time_oe : 8;
			uint32_t : 8; // padding bits
		};
	};
	/* TIME5 10'h094 */
	union {
		uint32_t time5; // word name
		struct {
			uint32_t time_lp_hsa : 12;
			uint32_t : 4; // padding bits
			uint32_t time_lp_hbp : 12;
			uint32_t : 4; // padding bits
		};
	};
	/* TIME6 10'h098 */
	union {
		uint32_t time6; // word name
		struct {
			uint32_t time_lp_hfp : 12;
			uint32_t : 4; // padding bits
			uint32_t time_frame_blanking : 12;
			uint32_t : 4; // padding bits
		};
	};
	/* TIME7 10'h09C */
	union {
		uint32_t time7; // word name
		struct {
			uint32_t time_lp_bllp_trail : 12;
			uint32_t : 4; // padding bits
			uint32_t time_frame_blanking_max : 16;
		};
	};
	/* TIME8 10'h0A0 */
	union {
		uint32_t time8; // word name
		struct {
			uint32_t time_bta_go : 12;
			uint32_t : 4; // padding bits
			uint32_t time_bta_sure : 12;
			uint32_t : 4; // padding bits
		};
	};
	/* TIME9 10'h0A4 */
	union {
		uint32_t time9; // word name
		struct {
			uint32_t time_bta_get : 12;
			uint32_t : 4; // padding bits
			uint32_t time_bta_go_lprx_en : 12;
			uint32_t : 4; // padding bits
		};
	};
	/* GSTA 10'h0A8 */
	union {
		uint32_t gsta; // word name
		struct {
			uint32_t enc_busy : 1;
			uint32_t : 7; // padding bits
			uint32_t enc_sta : 4;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FCNT 10'h0AC */
	union {
		uint32_t fcnt; // word name
		struct {
			uint32_t frame_cnt : 16;
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* MIPITXENC044 10'h0B0 [Unused] */
	uint32_t empty_word_mipitxenc044;
	/* MIPITXENC045 10'h0B4 [Unused] */
	uint32_t empty_word_mipitxenc045;
	/* TD0 10'h0B8 */
	union {
		uint32_t td0; // word name
		struct {
			uint32_t time_esc_esc : 8;
			uint32_t time_esc_hs : 8;
			uint32_t time_esc_bta : 8;
			uint32_t time_hs_hs : 8;
		};
	};
	/* TD1 10'h0BC */
	union {
		uint32_t td1; // word name
		struct {
			uint32_t time_hs_bta : 8;
			uint32_t time_bta_bta : 8;
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* ESCCMD0 10'h0C0 */
	union {
		uint32_t esccmd0; // word name
		struct {
			uint32_t esc_cmd : 8;
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* ESCCMD1 10'h0C4 */
	union {
		uint32_t esccmd1; // word name
		struct {
			uint32_t esc_finish : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* ESCTIME 10'h0C8 */
	union {
		uint32_t esctime; // word name
		struct {
			uint32_t esc_time_wait : 8;
			uint32_t : 8; // padding bits
			uint32_t esc_time_mark1 : 16;
		};
	};
	/* WCMD0 10'h0CC */
	union {
		uint32_t wcmd0; // word name
		struct {
			uint32_t w_cmd_word_0 : 32;
		};
	};
	/* WCMD1 10'h0D0 */
	union {
		uint32_t wcmd1; // word name
		struct {
			uint32_t w_cmd_word_1 : 32;
		};
	};
	/* WCMD2 10'h0D4 */
	union {
		uint32_t wcmd2; // word name
		struct {
			uint32_t w_cmd_word_2 : 32;
		};
	};
	/* WCMD3 10'h0D8 */
	union {
		uint32_t wcmd3; // word name
		struct {
			uint32_t w_cmd_word_3 : 32;
		};
	};
	/* WCMD4 10'h0DC */
	union {
		uint32_t wcmd4; // word name
		struct {
			uint32_t w_cmd_valid : 4;
			uint32_t : 4; // padding bits
			uint32_t w_cmd_byte_valid : 4;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WCMD5 10'h0E0 */
	union {
		uint32_t wcmd5; // word name
		struct {
			uint32_t w_is_long_packet : 1;
			uint32_t : 7; // padding bits
			uint32_t w_packet_conti : 1;
			uint32_t : 7; // padding bits
			uint32_t w_cal_ecc : 1;
			uint32_t : 7; // padding bits
			uint32_t w_cal_cs : 1;
			uint32_t : 7; // padding bits
		};
	};
	/* WCMD6 10'h0E4 */
	union {
		uint32_t wcmd6; // word name
		struct {
			uint32_t w_cmd_update : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WCMD7 10'h0E8 [Unused] */
	uint32_t empty_word_wcmd7;
	/* WCMD8 10'h0EC [Unused] */
	uint32_t empty_word_wcmd8;
	/* RCMD0 10'h0F0 */
	union {
		uint32_t rcmd0; // word name
		struct {
			uint32_t r_receive_cmd_ready : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* RCMD1 10'h0F4 */
	union {
		uint32_t rcmd1; // word name
		struct {
			uint32_t r_lprx_mode_valid : 1;
			uint32_t : 7; // padding bits
			uint32_t r_lprx_cmd_valid : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* RCMD2 10'h0F8 */
	union {
		uint32_t rcmd2; // word name
		struct {
			uint32_t r_lprx_mode : 8;
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* RCMD3 10'h0FC */
	union {
		uint32_t rcmd3; // word name
		struct {
			uint32_t r_lprx_cmd : 32;
		};
	};
	/* RCMD4 10'h100 */
	union {
		uint32_t rcmd4; // word name
		struct {
			uint32_t w_lprx_cmd_read_done : 1;
			uint32_t : 7; // padding bits
			uint32_t w_lprx_mode_read_done : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* RCMD5 10'h104 */
	union {
		uint32_t rcmd5; // word name
		struct {
			uint32_t user_def_longid : 30;
			uint32_t : 2; // padding bits
		};
	};
	/* MIPITXENC066 10'h108 [Unused] */
	uint32_t empty_word_mipitxenc066;
	/* MIPITXENC067 10'h10C [Unused] */
	uint32_t empty_word_mipitxenc067;
	/* MIPITXENC068 10'h110 [Unused] */
	uint32_t empty_word_mipitxenc068;
	/* MIPITXENC069 10'h114 [Unused] */
	uint32_t empty_word_mipitxenc069;
	/* MIPITXENC070 10'h118 [Unused] */
	uint32_t empty_word_mipitxenc070;
	/* MIPITXENC071 10'h11C [Unused] */
	uint32_t empty_word_mipitxenc071;
	/* CS0 10'h120 */
	union {
		uint32_t cs0; // word name
		struct {
			uint32_t line_emb : 12;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CS1 10'h124 */
	union {
		uint32_t cs1; // word name
		struct {
			uint32_t line_blk : 12;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CS2 10'h128 */
	union {
		uint32_t cs2; // word name
		struct {
			uint32_t perd_vbp : 12;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CS3 10'h12C */
	union {
		uint32_t cs3; // word name
		struct {
			uint32_t perd_emb : 12;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CS4 10'h130 */
	union {
		uint32_t cs4; // word name
		struct {
			uint32_t perd_blk : 12;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CS5 10'h134 */
	union {
		uint32_t cs5; // word name
		struct {
			uint32_t perd_vfp : 12;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CS6 10'h138 [Unused] */
	uint32_t empty_word_cs6;
	/* CS7 10'h13C [Unused] */
	uint32_t empty_word_cs7;
	/* CS8 10'h140 [Unused] */
	uint32_t empty_word_cs8;
	/* CS9 10'h144 [Unused] */
	uint32_t empty_word_cs9;
	/* CS10 10'h148 [Unused] */
	uint32_t empty_word_cs10;
	/* CS11 10'h14C [Unused] */
	uint32_t empty_word_cs11;
	/* MIPITXENC084 10'h150 [Unused] */
	uint32_t empty_word_mipitxenc084;
	/* TO0 10'h154 */
	union {
		uint32_t to0; // word name
		struct {
			uint32_t time_ta_to : 12;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* TO1 10'h158 */
	union {
		uint32_t to1; // word name
		struct {
			uint32_t time_presp_to_start : 1;
			uint32_t : 7; // padding bits
			uint32_t time_presp_to_reset : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* TO2 10'h15C */
	union {
		uint32_t to2; // word name
		struct {
			uint32_t time_presp_to : 20;
			uint32_t : 4; // padding bits
			uint32_t time_presp_to_mask : 1;
			uint32_t : 7; // padding bits
		};
	};
	/* MIPITXENC088 10'h160 [Unused] */
	uint32_t empty_word_mipitxenc088;
	/* DBG0 10'h164 */
	union {
		uint32_t dbg0; // word name
		struct {
			uint32_t pix_debug_sel : 4;
			uint32_t : 4; // padding bits
			uint32_t debug_sel : 6;
			uint32_t : 2; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* DBG1 10'h168 */
	union {
		uint32_t dbg1; // word name
		struct {
			uint32_t pix_debug_mon : 32;
		};
	};
	/* DBG2 10'h16C */
	union {
		uint32_t dbg2; // word name
		struct {
			uint32_t debug_mon : 32;
		};
	};
	/* MIPITXENC092 10'h170 [Unused] */
	uint32_t empty_word_mipitxenc092;
	/* MIPITXENC093 10'h174 [Unused] */
	uint32_t empty_word_mipitxenc093;
	/* MIPITXENC094 10'h178 [Unused] */
	uint32_t empty_word_mipitxenc094;
	/* MIPITXENC095 10'h17C [Unused] */
	uint32_t empty_word_mipitxenc095;
	/* RESV 10'h180 */
	union {
		uint32_t resv; // word name
		struct {
			uint32_t reserved : 32;
		};
	};
} CsrBankTx_enc;

#endif