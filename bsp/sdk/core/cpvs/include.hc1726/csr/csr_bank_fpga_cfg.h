/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef CSR_BANK_FPGA_CFG_H_
#define CSR_BANK_FPGA_CFG_H_

#ifndef __KERNEL__
#include <stdint.h>
#else
#include <linux/types.h>
#endif

/***  C struct generated from fpga_cfg  ***/
typedef struct csr_bank_fpga_cfg {
	/* RESERVE 10'h00 */
	union {
		uint32_t reserve; // word name
		struct {
			uint32_t reverse_word : 32;
		};
	};
	/* WORD_FPGA_DBG0_IOSEL 10'h04 */
	union {
		uint32_t word_fpga_dbg0_iosel; // word name
		struct {
			uint32_t fpga_dbg0_iosel : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_FPGA_DBG1_IOSEL 10'h08 */
	union {
		uint32_t word_fpga_dbg1_iosel; // word name
		struct {
			uint32_t fpga_dbg1_iosel : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_FPGA_DBG2_IOSEL 10'h0C */
	union {
		uint32_t word_fpga_dbg2_iosel; // word name
		struct {
			uint32_t fpga_dbg2_iosel : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_FPGA_DBG3_IOSEL 10'h10 */
	union {
		uint32_t word_fpga_dbg3_iosel; // word name
		struct {
			uint32_t fpga_dbg3_iosel : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_FPGA_DBG4_IOSEL 10'h14 */
	union {
		uint32_t word_fpga_dbg4_iosel; // word name
		struct {
			uint32_t fpga_dbg4_iosel : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_FPGA_DBG5_IOSEL 10'h18 */
	union {
		uint32_t word_fpga_dbg5_iosel; // word name
		struct {
			uint32_t fpga_dbg5_iosel : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_FPGA_DBG6_IOSEL 10'h1C */
	union {
		uint32_t word_fpga_dbg6_iosel; // word name
		struct {
			uint32_t fpga_dbg6_iosel : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_FPGA_DBG7_IOSEL 10'h20 */
	union {
		uint32_t word_fpga_dbg7_iosel; // word name
		struct {
			uint32_t fpga_dbg7_iosel : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_FPGA_DBG8_IOSEL 10'h24 */
	union {
		uint32_t word_fpga_dbg8_iosel; // word name
		struct {
			uint32_t fpga_dbg8_iosel : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_FPGA_DBG9_IOSEL 10'h28 */
	union {
		uint32_t word_fpga_dbg9_iosel; // word name
		struct {
			uint32_t fpga_dbg9_iosel : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_FPGA_DBG10_IOSEL 10'h2C */
	union {
		uint32_t word_fpga_dbg10_iosel; // word name
		struct {
			uint32_t fpga_dbg10_iosel : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_FPGA_DBG11_IOSEL 10'h30 */
	union {
		uint32_t word_fpga_dbg11_iosel; // word name
		struct {
			uint32_t fpga_dbg11_iosel : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_FPGA_DBG12_IOSEL 10'h34 */
	union {
		uint32_t word_fpga_dbg12_iosel; // word name
		struct {
			uint32_t fpga_dbg12_iosel : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_ADAC_CLKI_SAADC_CH6 10'h38 */
	union {
		uint32_t word_adac_clki_saadc_ch6; // word name
		struct {
			uint32_t adac_clki_saadc_ch6_iosel : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_AADC_L_ENREFI_SAADCCS_CALN2 10'h3C */
	union {
		uint32_t word_aadc_l_enrefi_saadccs_caln2; // word name
		struct {
			uint32_t aadc_l_enrefi_saadccs_caln2_iosel : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_AADC_L_CHPAI_SAADCCS_SETN6 10'h40 */
	union {
		uint32_t word_aadc_l_chpai_saadccs_setn6; // word name
		struct {
			uint32_t aadc_l_chpai_saadccs_setn6_iosel : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_AADC_R_ENBIASI_SAADC_CH0 10'h44 */
	union {
		uint32_t word_aadc_r_enbiasi_saadc_ch0; // word name
		struct {
			uint32_t aadc_r_enbiasi_saadc_ch0_iosel : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_AADC_L_PH2DI_SAADCCS_SAMPLE 10'h48 */
	union {
		uint32_t word_aadc_l_ph2di_saadccs_sample; // word name
		struct {
			uint32_t aadc_l_ph2di_saadccs_sample_iosel : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_AADC_L_BGCHOPI_SAADCCS_SPWR 10'h4C */
	union {
		uint32_t word_aadc_l_bgchopi_saadccs_spwr; // word name
		struct {
			uint32_t aadc_l_bgchopi_saadccs_spwr_iosel : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_AADC_R_REFCHPAI_SAADC_VREFPSEL5 10'h50 */
	union {
		uint32_t word_aadc_r_refchpai_saadc_vrefpsel5; // word name
		struct {
			uint32_t aadc_r_refchpai_saadc_vrefpsel5_iosel : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_AADC_L_PH2I_SAADCCS_CK 10'h54 */
	union {
		uint32_t word_aadc_l_ph2i_saadccs_ck; // word name
		struct {
			uint32_t aadc_l_ph2i_saadccs_ck_iosel : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_AADC_R_ENBGPI_SAADC_CH1 10'h58 */
	union {
		uint32_t word_aadc_r_enbgpi_saadc_ch1; // word name
		struct {
			uint32_t aadc_r_enbgpi_saadc_ch1_iosel : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_AADC_R_PH1I_SAADC_VCMSEL3 10'h5C */
	union {
		uint32_t word_aadc_r_ph1i_saadc_vcmsel3; // word name
		struct {
			uint32_t aadc_r_ph1i_saadc_vcmsel3_iosel : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_AADC_L_ENBGPI_SAADCCS_CALP2 10'h60 */
	union {
		uint32_t word_aadc_l_enbgpi_saadccs_calp2; // word name
		struct {
			uint32_t aadc_l_enbgpi_saadccs_calp2_iosel : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_AADC_R_BGCHOPI_SAADC_CH2 10'h64 */
	union {
		uint32_t word_aadc_r_bgchopi_saadc_ch2; // word name
		struct {
			uint32_t aadc_r_bgchopi_saadc_ch2_iosel : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_AADC_L_ENBIASI_SAADCCS_CALP1 10'h68 */
	union {
		uint32_t word_aadc_l_enbiasi_saadccs_calp1; // word name
		struct {
			uint32_t aadc_l_enbiasi_saadccs_calp1_iosel : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_AADC_L_PH1DI_SAADCCS_CALN0 10'h6C */
	union {
		uint32_t word_aadc_l_ph1di_saadccs_caln0; // word name
		struct {
			uint32_t aadc_l_ph1di_saadccs_caln0_iosel : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_AADC_L_PH1I_SAADCCS_CALN1 10'h70 */
	union {
		uint32_t word_aadc_l_ph1i_saadccs_caln1; // word name
		struct {
			uint32_t aadc_l_ph1i_saadccs_caln1_iosel : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_AADC_R_PH2DI_SAADC_VCMSEL0 10'h74 */
	union {
		uint32_t word_aadc_r_ph2di_saadc_vcmsel0; // word name
		struct {
			uint32_t aadc_r_ph2di_saadc_vcmsel0_iosel : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_AADC_R_RESETBI_SAADCCS_VREFPSEL3 10'h78 */
	union {
		uint32_t word_aadc_r_resetbi_saadccs_vrefpsel3; // word name
		struct {
			uint32_t aadc_r_resetbi_saadccs_vrefpsel3_iosel : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_AADC_R_CHPAI_SAADC_VREFPSEL4 10'h7C */
	union {
		uint32_t word_aadc_r_chpai_saadc_vrefpsel4; // word name
		struct {
			uint32_t aadc_r_chpai_saadc_vrefpsel4_iosel : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_AADC_L_ENSDMI_SAADCCS_CALP0 10'h80 */
	union {
		uint32_t word_aadc_l_ensdmi_saadccs_calp0; // word name
		struct {
			uint32_t aadc_l_ensdmi_saadccs_calp0_iosel : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_AADC_L_REFCHPAI_SAADCCS_SETN7 10'h84 */
	union {
		uint32_t word_aadc_l_refchpai_saadccs_setn7; // word name
		struct {
			uint32_t aadc_l_refchpai_saadccs_setn7_iosel : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_AADC_R_ENSDMI_SAADC_VCMSEL5 10'h88 */
	union {
		uint32_t word_aadc_r_ensdmi_saadc_vcmsel5; // word name
		struct {
			uint32_t aadc_r_ensdmi_saadc_vcmsel5_iosel : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_AADC_R_SDMOI_SAADCCS_VREFPSEL2 10'h8C */
	union {
		uint32_t word_aadc_r_sdmoi_saadccs_vrefpsel2; // word name
		struct {
			uint32_t aadc_r_sdmoi_saadccs_vrefpsel2_iosel : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_ADAC_DINI_SAADC_CH7 10'h90 */
	union {
		uint32_t word_adac_dini_saadc_ch7; // word name
		struct {
			uint32_t adac_dini_saadc_ch7_iosel : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_AADC_R_PH1DI_SAADC_VCMSEL2 10'h94 */
	union {
		uint32_t word_aadc_r_ph1di_saadc_vcmsel2; // word name
		struct {
			uint32_t aadc_r_ph1di_saadc_vcmsel2_iosel : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_AADC_L_SDMO_SAADC_SETN4 10'h98 */
	union {
		uint32_t word_aadc_l_sdmo_saadc_setn4; // word name
		struct {
			uint32_t aadc_l_sdmo_saadc_setn4_iosel : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_AADC_R_ENREFI_SAADC_VCMSEL4 10'h9C */
	union {
		uint32_t word_aadc_r_enrefi_saadc_vcmsel4; // word name
		struct {
			uint32_t aadc_r_enrefi_saadc_vcmsel4_iosel : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_AADC_R_PH2I_SAADC_VCMSEL1 10'hA0 */
	union {
		uint32_t word_aadc_r_ph2i_saadc_vcmsel1; // word name
		struct {
			uint32_t aadc_r_ph2i_saadc_vcmsel1_iosel : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_AADC_L_RSTB_SAADC_SETN5 10'hA4 */
	union {
		uint32_t word_aadc_l_rstb_saadc_setn5; // word name
		struct {
			uint32_t aadc_l_rstb_saadc_setn5_iosel : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_FPGA_DBG13_IOSEL 10'hA8 */
	union {
		uint32_t word_fpga_dbg13_iosel; // word name
		struct {
			uint32_t fpga_dbg13_iosel : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_FPGA_DBG14_IOSEL 10'hAC */
	union {
		uint32_t word_fpga_dbg14_iosel; // word name
		struct {
			uint32_t fpga_dbg14_iosel : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_FPGA_DBG15_IOSEL 10'hB0 */
	union {
		uint32_t word_fpga_dbg15_iosel; // word name
		struct {
			uint32_t fpga_dbg15_iosel : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_FPGA_DBG16_IOSEL 10'hB4 */
	union {
		uint32_t word_fpga_dbg16_iosel; // word name
		struct {
			uint32_t fpga_dbg16_iosel : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_FPGA_DBG17_IOSEL 10'hB8 */
	union {
		uint32_t word_fpga_dbg17_iosel; // word name
		struct {
			uint32_t fpga_dbg17_iosel : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
} CsrBankFpga_cfg;

#endif
