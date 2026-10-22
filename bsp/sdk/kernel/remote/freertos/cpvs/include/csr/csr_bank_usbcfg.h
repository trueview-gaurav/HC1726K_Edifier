#ifndef CSR_BANK_USBCFG_H_
#define CSR_BANK_USBCFG_H_

#ifndef __KERNEL__
#include <stdint.h>
#else
#include <linux/types.h>
#endif

/***  C struct generated from usbcfg  ***/
typedef struct csr_bank_usbcfg {
	/* USBC00 8'h00 */
	union {
		uint32_t usbc00; // word name
		struct {
			uint32_t debug_sel : 3;
			uint32_t : 5; // padding bits
			uint32_t debug_en : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* USBC01 8'h04 */
	union {
		uint32_t usbc01; // word name
		struct {
			uint32_t sd : 1;
			uint32_t : 7; // padding bits
			uint32_t slp : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* USBC02 8'h08 */
	union {
		uint32_t usbc02; // word name
		struct {
			uint32_t ss_scaledown_mode : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* USBC03 8'h0C */
	union {
		uint32_t usbc03; // word name
		struct {
			uint32_t dbnce_fltr_bypass : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* USBC04 8'h10 */
	union {
		uint32_t usbc04; // word name
		struct {
			uint32_t sys_dma_done_trig : 1;
			uint32_t : 7; // padding bits
			uint32_t sys_dma_done_auto : 1;
			uint32_t : 7; // padding bits
			uint32_t sys_dma_done_cnt : 8;
			uint32_t : 8; // padding bits
		};
	};
	/* USBC05 8'h14 */
	union {
		uint32_t usbc05; // word name
		struct {
			uint32_t int_dma_req : 1;
			uint32_t : 7; // padding bits
			uint32_t int_dma_done_flag : 1;
			uint32_t : 7; // padding bits
			uint32_t chep_number : 4;
			uint32_t : 4; // padding bits
			uint32_t chep_last_trans : 1;
			uint32_t : 7; // padding bits
		};
	};
	/* USBC06 8'h18 */
	union {
		uint32_t usbc06; // word name
		struct {
			uint32_t sof_toggle_out : 1;
			uint32_t : 7; // padding bits
			uint32_t sof_sent_rcvd_tgl : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* USBC07 8'h1C */
	union {
		uint32_t usbc07; // word name
		struct {
			uint32_t rg_phy_pllitune : 2;
			uint32_t : 6; // padding bits
			uint32_t rg_phy_pllptune : 4;
			uint32_t : 4; // padding bits
			uint32_t rg_phy_pllbtune : 1;
			uint32_t : 7; // padding bits
			uint32_t rg_phy_compdistune : 3;
			uint32_t : 5; // padding bits
		};
	};
	/* USBC08 8'h20 */
	union {
		uint32_t usbc08; // word name
		struct {
			uint32_t rg_phy_sqrxtune : 3;
			uint32_t : 5; // padding bits
			uint32_t rg_phy_vdatreftune : 2;
			uint32_t : 6; // padding bits
			uint32_t rg_phy_otgtune : 3;
			uint32_t : 5; // padding bits
			uint32_t rg_phy_txhsxvtune : 2;
			uint32_t : 6; // padding bits
		};
	};
	/* USBC09 8'h24 */
	union {
		uint32_t usbc09; // word name
		struct {
			uint32_t rg_phy_txfslstune : 4;
			uint32_t : 4; // padding bits
			uint32_t rg_phy_txvreftune : 4;
			uint32_t : 4; // padding bits
			uint32_t rg_phy_txrisetune : 2;
			uint32_t : 6; // padding bits
			uint32_t rg_phy_txrestune : 2;
			uint32_t : 6; // padding bits
		};
	};
	/* USBC10 8'h28 */
	union {
		uint32_t usbc10; // word name
		struct {
			uint32_t rg_phy_txpreempamptune : 2;
			uint32_t : 6; // padding bits
			uint32_t rg_phy_txpreemppulsetune : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* USBC11 8'h2C */
	union {
		uint32_t usbc11; // word name
		struct {
			uint32_t rg_phy_fsel : 3;
			uint32_t : 5; // padding bits
			uint32_t rg_phy_refclksel : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* USBC12 8'h30 */
	union {
		uint32_t usbc12; // word name
		struct {
			uint32_t rg_phy_commononn : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t rg_phy_vregbypass : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* USBC13 8'h34 */
	union {
		uint32_t usbc13; // word name
		struct {
			uint32_t dev_hird_vld_tgl : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t dev_hird_rcvd : 4;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* USBC14 8'h38 */
	union {
		uint32_t usbc14; // word name
		struct {
			uint32_t reserved : 32;
		};
	};
	/* USBC15 8'h3C */
	union {
		uint32_t usbc15; // word name
		struct {
			uint32_t rg_phy_atereset : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* USBC16 8'h40 */
	union {
		uint32_t usbc16; // word name
		struct {
			uint32_t rg_phy_testdatain : 8;
			uint32_t : 8; // padding bits
			uint32_t rg_phy_testaddr : 4;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* USBC17 8'h44 */
	union {
		uint32_t usbc17; // word name
		struct {
			uint32_t rg_phy_testdataoutsel : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* USBC18 8'h48 */
	union {
		uint32_t usbc18; // word name
		struct {
			uint32_t phy_testdataout : 4;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
			uint32_t phy_resackout : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* USBC19 8'h4C */
	union {
		uint32_t usbc19; // word name
		struct {
			uint32_t rg_phy_testclk : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* USBC20 8'h50 */
	union {
		uint32_t usbc20; // word name
		struct {
			uint32_t rg_phy_siddq : 1;
			uint32_t : 7; // padding bits
			uint32_t rg_phy_loopbackenb : 1;
			uint32_t : 7; // padding bits
			uint32_t rg_phy_testburnin : 1;
			uint32_t : 7; // padding bits
			uint32_t rg_phy_resreqin : 1;
			uint32_t : 7; // padding bits
		};
	};
	/* USBC21 8'h54 */
	union {
		uint32_t usbc21; // word name
		struct {
			uint32_t rg_phy_otgdisable : 1;
			uint32_t : 7; // padding bits
			uint32_t rg_phy_vbusvldextsel : 1;
			uint32_t : 7; // padding bits
			uint32_t rg_phy_vbusvldext : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* USBC22 8'h58 */
	union {
		uint32_t usbc22; // word name
		struct {
			uint32_t rg_phy_port_rst : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
} CsrBankUsbcfg;

#endif