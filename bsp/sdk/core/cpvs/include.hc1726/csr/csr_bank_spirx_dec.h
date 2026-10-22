/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef CSR_BANK_SPIRX_DEC_H_
#define CSR_BANK_SPIRX_DEC_H_

#ifndef __KERNEL__
#include <stdint.h>
#else
#include <linux/types.h>
#endif

/***  C struct generated from spirx_dec  ***/
typedef struct csr_bank_spirx_dec {
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
			uint32_t status_spi_short_pkt : 1;
			uint32_t status_spi_pkt_err : 1;
			uint32_t status_spi_line_err : 1;
			uint32_t status_himax_crc_err : 1;
			uint32_t status_frame_size_err : 1;
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
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
			uint32_t irq_clear_spi_short_pkt : 1;
			uint32_t irq_clear_spi_pkt_err : 1;
			uint32_t irq_clear_spi_line_err : 1;
			uint32_t irq_clear_himax_crc_err : 1;
			uint32_t irq_clear_frame_size_err : 1;
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
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
			uint32_t irq_mask_spi_short_pkt : 1;
			uint32_t irq_mask_spi_pkt_err : 1;
			uint32_t irq_mask_spi_line_err : 1;
			uint32_t irq_mask_himax_crc_err : 1;
			uint32_t irq_mask_frame_size_err : 1;
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* CFG 10'h014 */
	union {
		uint32_t cfg; // word name
		struct {
			uint32_t des_bit_size : 2;
			uint32_t wire_inverse : 1;
			uint32_t : 1; // padding bits
			uint32_t sensor_type : 2;
			uint32_t : 2; // padding bits
			uint32_t ddr_mode_en : 1;
			uint32_t sclk_pol_sel : 1;
			uint32_t sclk_latch_en : 1;
			uint32_t rise_sclk_middle : 1;
			uint32_t : 1; // padding bits
			uint32_t msb_first : 1;
			uint32_t yuv422_mode : 1;
			uint32_t : 1; // padding bits
			uint32_t sclk_gating : 1;
			uint32_t himax_frame_code_en : 1;
			uint32_t himax_crc_check : 1;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* DELAY_CFG 10'h018 */
	union {
		uint32_t delay_cfg; // word name
		struct {
			uint32_t sd0_data_delay_sel : 3;
			uint32_t : 1; // padding bits
			uint32_t sd1_data_delay_sel : 3;
			uint32_t : 1; // padding bits
			uint32_t sd2_data_delay_sel : 3;
			uint32_t : 1; // padding bits
			uint32_t sd3_data_delay_sel : 3;
			uint32_t : 1; // padding bits
			uint32_t sclk_data_delay_sel : 3;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* SYNC_CODE 10'h01C */
	union {
		uint32_t sync_code; // word name
		struct {
			uint32_t custom_sync_code0 : 8;
			uint32_t custom_sync_code1 : 8;
			uint32_t custom_sync_code2 : 8;
			uint32_t : 8; // padding bits
		};
	};
	/* SYNC_ID0 10'h020 */
	union {
		uint32_t sync_id0; // word name
		struct {
			uint32_t line_end_id : 8;
			uint32_t line_start_id : 8;
			uint32_t frame_end_id : 8;
			uint32_t frame_start_id : 8;
		};
	};
	/* SYNC_ID1 10'h024 */
	union {
		uint32_t sync_id1; // word name
		struct {
			uint32_t line_data_id : 8;
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WTH 10'h028 */
	union {
		uint32_t wth; // word name
		struct {
			uint32_t word_num : 16;
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* HIGH 10'h02C */
	union {
		uint32_t high; // word name
		struct {
			uint32_t line_num : 16;
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* ERR 10'h030 */
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
	/* SIZE 10'h034 */
	union {
		uint32_t size; // word name
		struct {
			uint32_t width : 16;
			uint32_t height : 16;
		};
	};
	/* FCNT 10'h038 */
	union {
		uint32_t fcnt; // word name
		struct {
			uint32_t frame_count : 16;
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* STAS0 10'h03C */
	union {
		uint32_t stas0; // word name
		struct {
			uint32_t spi_sensor_dec_sta : 7;
			uint32_t : 1; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* STAS1 10'h040 */
	union {
		uint32_t stas1; // word name
		struct {
			uint32_t spi_sensor_active_count : 16;
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* STAS2 10'h044 */
	union {
		uint32_t stas2; // word name
		struct {
			uint32_t spi_sensor_word_count : 16;
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* HIMAX_SIZE 10'h048 */
	union {
		uint32_t himax_size; // word name
		struct {
			uint32_t himax_hsize : 10;
			uint32_t : 6; // padding bits
			uint32_t himax_vsize : 9;
			uint32_t : 7; // padding bits
		};
	};
	/* HIMAX_LENGTH 10'h04C */
	union {
		uint32_t himax_length; // word name
		struct {
			uint32_t himax_line_length : 16;
			uint32_t himax_frame_length : 16;
		};
	};
	/* HIMAX_GAIN 10'h050 */
	union {
		uint32_t himax_gain; // word name
		struct {
			uint32_t himax_ana_gain : 8;
			uint32_t : 8; // padding bits
			uint32_t himax_dig_gain : 11;
			uint32_t : 5; // padding bits
		};
	};
	/* HIMAX_FRAME 10'h054 */
	union {
		uint32_t himax_frame; // word name
		struct {
			uint32_t himax_frame_count : 16;
			uint32_t himax_frame_status : 16;
		};
	};
	/* HIMAX_INTG 10'h058 */
	union {
		uint32_t himax_intg; // word name
		struct {
			uint32_t himax_intg_time : 16;
			uint32_t himax_int_src : 5;
			uint32_t : 3; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* HIMAX_CRC 10'h05C */
	union {
		uint32_t himax_crc; // word name
		struct {
			uint32_t himax_crc1 : 8;
			uint32_t himax_crc2 : 8;
			uint32_t himax_crc_cal : 16;
		};
	};
	/* DBG0 10'h060 */
	union {
		uint32_t dbg0; // word name
		struct {
			uint32_t debug_sel : 3;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* DBG1 10'h064 */
	union {
		uint32_t dbg1; // word name
		struct {
			uint32_t debug_mon : 32;
		};
	};
} CsrBankSpirx_dec;

#endif