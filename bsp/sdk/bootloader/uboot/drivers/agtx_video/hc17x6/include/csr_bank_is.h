#ifndef CSR_BANK_IS_H_
#define CSR_BANK_IS_H_

#ifndef __KERNEL__
#include <stdint.h>
#else
#include <linux/types.h>
#endif

/***  C struct generated from is  ***/
typedef struct csr_bank_is {
	/* WORD_FRAME_START 10'h000 */
	union {
		uint32_t word_frame_start; // word name
		struct {
			uint32_t frame_start_fe0 : 1;
			uint32_t : 7; // padding bits
			uint32_t frame_start_fe1 : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* IRQ_CLEAR_SENSOR0 10'h004 */
	union {
		uint32_t irq_clear_sensor0; // word name
		struct {
			uint32_t irq_clear_frame_end_auto0 : 1;
			uint32_t : 7; // padding bits
			uint32_t irq_clear_frame_start_late_auto0 : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* IRQ_CLEAR_SENSOR1 10'h008 */
	union {
		uint32_t irq_clear_sensor1; // word name
		struct {
			uint32_t irq_clear_frame_end_auto1 : 1;
			uint32_t : 7; // padding bits
			uint32_t irq_clear_frame_start_late_auto1 : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* STATUS_SENSOR0 10'h00C */
	union {
		uint32_t status_sensor0; // word name
		struct {
			uint32_t status_frame_end_auto0 : 1;
			uint32_t : 7; // padding bits
			uint32_t status_frame_start_late_auto0 : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* STATUS_SENSOR1 10'h010 */
	union {
		uint32_t status_sensor1; // word name
		struct {
			uint32_t status_frame_end_auto1 : 1;
			uint32_t : 7; // padding bits
			uint32_t status_frame_start_late_auto1 : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* IRQ_MASK_SENSOR0 10'h014 */
	union {
		uint32_t irq_mask_sensor0; // word name
		struct {
			uint32_t irq_mask_frame_end_auto0 : 1;
			uint32_t : 7; // padding bits
			uint32_t irq_mask_frame_start_late_auto0 : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* IRQ_MASK_SENSOR1 10'h018 */
	union {
		uint32_t irq_mask_sensor1; // word name
		struct {
			uint32_t irq_mask_frame_end_auto1 : 1;
			uint32_t : 7; // padding bits
			uint32_t irq_mask_frame_start_late_auto1 : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* EFUSE_VIO 10'h01C */
	union {
		uint32_t efuse_vio; // word name
		struct {
			uint32_t fe0_efuse_resolution_violation : 1;
			uint32_t : 7; // padding bits
			uint32_t fe0_efuse_data_rate_violation : 1;
			uint32_t : 7; // padding bits
			uint32_t fe1_efuse_resolution_violation : 1;
			uint32_t : 7; // padding bits
			uint32_t fe1_efuse_data_rate_violation : 1;
			uint32_t : 7; // padding bits
		};
	};
	/* RESOLUTION_PATH_0 10'h020 */
	union {
		uint32_t resolution_path_0; // word name
		struct {
			uint32_t width_0 : 16;
			uint32_t height_0 : 16;
		};
	};
	/* RESOLUTION_PATH_1 10'h024 */
	union {
		uint32_t resolution_path_1; // word name
		struct {
			uint32_t width_1 : 16;
			uint32_t height_1 : 16;
		};
	};
	/* AUTO_FRAME_START_CTRL 10'h028 */
	union {
		uint32_t auto_frame_start_ctrl; // word name
		struct {
			uint32_t fe0_auto_frame_start_mode : 1;
			uint32_t : 7; // padding bits
			uint32_t fe1_auto_frame_start_mode : 1;
			uint32_t : 7; // padding bits
			uint32_t auto_frame_start_blanking_mode : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FE0_CTRL 10'h02C */
	union {
		uint32_t fe0_ctrl; // word name
		struct {
			uint32_t fe0_prd_mode : 1;
			uint32_t : 7; // padding bits
			uint32_t fe0_broadcast_enable : 2;
			uint32_t : 6; // padding bits
			uint32_t fe0_edp_mux_sel : 1;
			uint32_t : 7; // padding bits
			uint32_t fe0_ack_not_sel : 2;
			uint32_t : 6; // padding bits
		};
	};
	/* FE1_CTRL 10'h030 */
	union {
		uint32_t fe1_ctrl; // word name
		struct {
			uint32_t fe1_prd_mode : 1;
			uint32_t : 7; // padding bits
			uint32_t fe1_broadcast_enable : 2;
			uint32_t : 6; // padding bits
			uint32_t fe1_edp_mux_sel : 1;
			uint32_t : 7; // padding bits
			uint32_t fe1_ack_not_sel : 2;
			uint32_t : 6; // padding bits
		};
	};
	/* IROUTE_ENABLE_0 10'h034 */
	union {
		uint32_t iroute_enable_0; // word name
		struct {
			uint32_t iroute_src_fe0_edp0_broadcast_enable : 6;
			uint32_t : 2; // padding bits
			uint32_t iroute_src_fe0_edp1_broadcast_enable : 6;
			uint32_t : 2; // padding bits
			uint32_t iroute_src_fe0_isr_broadcast_enable : 6;
			uint32_t : 2; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* IROUTE_ENABLE_1 10'h038 */
	union {
		uint32_t iroute_enable_1; // word name
		struct {
			uint32_t iroute_src_fe1_edp0_broadcast_enable : 6;
			uint32_t : 2; // padding bits
			uint32_t iroute_src_fe1_edp1_broadcast_enable : 6;
			uint32_t : 2; // padding bits
			uint32_t iroute_src_fe1_isr_broadcast_enable : 6;
			uint32_t : 2; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* IROUTE_SEL_0 10'h03C */
	union {
		uint32_t iroute_sel_0; // word name
		struct {
			uint32_t iroute_dst_bypass_isk0_sel : 3;
			uint32_t : 5; // padding bits
			uint32_t iroute_dst_isk0_in0_sel : 3;
			uint32_t : 5; // padding bits
			uint32_t iroute_dst_isk0_in1_sel : 3;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* IROUTE_SEL_1 10'h040 */
	union {
		uint32_t iroute_sel_1; // word name
		struct {
			uint32_t iroute_dst_bypass_isk1_sel : 3;
			uint32_t : 5; // padding bits
			uint32_t iroute_dst_isk1_in0_sel : 3;
			uint32_t : 5; // padding bits
			uint32_t iroute_dst_isk1_in1_sel : 3;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* IROUTE_ACK_NOT_SEL 10'h044 */
	union {
		uint32_t iroute_ack_not_sel; // word name
		struct {
			uint32_t iroute_src_broadcast_ack_not_sel : 6;
			uint32_t : 2; // padding bits
			uint32_t iroute_dst_mux_ack_not_sel : 6;
			uint32_t : 2; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* IROUTE_CAT 10'h048 */
	union {
		uint32_t iroute_cat; // word name
		struct {
			uint32_t iroute_dst_msb_cat : 6;
			uint32_t : 2; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* OROUTE_ENABLE_0 10'h04C */
	union {
		uint32_t oroute_enable_0; // word name
		struct {
			uint32_t oroute_src_bypass_isk0_broadcast_enable : 4;
			uint32_t : 4; // padding bits
			uint32_t oroute_src_isk0_crop_broadcast_enable : 4;
			uint32_t : 4; // padding bits
			uint32_t oroute_src_isk0_bsp_broadcast_enable : 4;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* OROUTE_ENABLE_1 10'h050 */
	union {
		uint32_t oroute_enable_1; // word name
		struct {
			uint32_t oroute_src_isk0_fgma_broadcast_enable : 4;
			uint32_t : 4; // padding bits
			uint32_t oroute_src_isk0_fsc_broadcast_enable : 4;
			uint32_t : 4; // padding bits
			uint32_t oroute_src_isk0_cvs_broadcast_enable : 4;
			uint32_t : 4; // padding bits
			uint32_t oroute_src_isk0_cs_broadcast_enable : 4;
			uint32_t : 4; // padding bits
		};
	};
	/* OROUTE_ENABLE_2 10'h054 */
	union {
		uint32_t oroute_enable_2; // word name
		struct {
			uint32_t oroute_src_bypass_isk1_broadcast_enable : 4;
			uint32_t : 4; // padding bits
			uint32_t oroute_src_isk1_crop_broadcast_enable : 4;
			uint32_t : 4; // padding bits
			uint32_t oroute_src_isk1_bsp_broadcast_enable : 4;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* OROUTE_ENABLE_3 10'h058 */
	union {
		uint32_t oroute_enable_3; // word name
		struct {
			uint32_t oroute_src_isk1_fgma_broadcast_enable : 4;
			uint32_t : 4; // padding bits
			uint32_t oroute_src_isk1_fsc_broadcast_enable : 4;
			uint32_t : 4; // padding bits
			uint32_t oroute_src_isk1_cvs_broadcast_enable : 4;
			uint32_t : 4; // padding bits
			uint32_t oroute_src_isk1_cs_broadcast_enable : 4;
			uint32_t : 4; // padding bits
		};
	};
	/* OROUTE_SEL 10'h05C */
	union {
		uint32_t oroute_sel; // word name
		struct {
			uint32_t oroute_dst_isw0_sel : 4;
			uint32_t : 4; // padding bits
			uint32_t oroute_dst_isw1_sel : 4;
			uint32_t : 4; // padding bits
			uint32_t oroute_dst_isw2_sel : 4;
			uint32_t : 4; // padding bits
			uint32_t oroute_dst_isw3_sel : 4;
			uint32_t : 4; // padding bits
		};
	};
	/* OROUTE_CAT 10'h060 */
	union {
		uint32_t oroute_cat; // word name
		struct {
			uint32_t oroute_dst_isw0_msb_cat : 1;
			uint32_t : 7; // padding bits
			uint32_t oroute_dst_isw1_msb_cat : 1;
			uint32_t : 7; // padding bits
			uint32_t oroute_dst_isw2_msb_cat : 1;
			uint32_t : 7; // padding bits
			uint32_t oroute_dst_isw3_msb_cat : 1;
			uint32_t : 7; // padding bits
		};
	};
	/* OROUTE_ACK_NOT_SEL_0 10'h064 */
	union {
		uint32_t oroute_ack_not_sel_0; // word name
		struct {
			uint32_t oroute_src0_broadcast_ack_not_sel : 7;
			uint32_t : 1; // padding bits
			uint32_t oroute_src1_broadcast_ack_not_sel : 7;
			uint32_t : 1; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* OROUTE_ACK_NOT_SEL_1 10'h068 */
	union {
		uint32_t oroute_ack_not_sel_1; // word name
		struct {
			uint32_t oroute_dst_mux_ack_not_sel : 4;
			uint32_t : 4; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* LPMD_ENABLE 10'h06C */
	union {
		uint32_t lpmd_enable; // word name
		struct {
			uint32_t lpmd_broadcast_to_is_enable : 1;
			uint32_t : 7; // padding bits
			uint32_t lpmd_broadcast_to_lpmd_enable : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* WORD_LPMD_ACK_NOT_SEL 10'h070 */
	union {
		uint32_t word_lpmd_ack_not_sel; // word name
		struct {
			uint32_t lpmd_ack_not_sel : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* SHARED_SRAM_FSC 10'h074 */
	union {
		uint32_t shared_sram_fsc; // word name
		struct {
			uint32_t fsc_buf_mode : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* SHARED_SRAM_CFG 10'h078 */
	union {
		uint32_t shared_sram_cfg; // word name
		struct {
			uint32_t bsp_cvs_cs_sram_mode : 1;
			uint32_t : 7; // padding bits
			uint32_t bsp_cvs_cs_sram_master : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* PWE_MODE 10'h07C */
	union {
		uint32_t pwe_mode; // word name
		struct {
			uint32_t pwe0_mode : 1;
			uint32_t : 7; // padding bits
			uint32_t pwe1_mode : 1;
			uint32_t : 7; // padding bits
			uint32_t pwe2_mode : 1;
			uint32_t : 7; // padding bits
			uint32_t pwe3_mode : 1;
			uint32_t : 7; // padding bits
		};
	};
	/* DRAM_WADDR_0_0 10'h080 */
	union {
		uint32_t dram_waddr_0_0; // word name
		struct {
			uint32_t isw0_ex_ini_addr_0 : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* DRAM_WADDR_0_1 10'h084 */
	union {
		uint32_t dram_waddr_0_1; // word name
		struct {
			uint32_t isw0_ex_ini_addr_1 : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* DRAM_WADDR_0_2 10'h088 */
	union {
		uint32_t dram_waddr_0_2; // word name
		struct {
			uint32_t isw0_ex_ini_addr_2 : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* DRAM_WADDR_0_3 10'h08C */
	union {
		uint32_t dram_waddr_0_3; // word name
		struct {
			uint32_t isw0_ex_ini_addr_3 : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* DRAM_WADDR_1_0 10'h090 */
	union {
		uint32_t dram_waddr_1_0; // word name
		struct {
			uint32_t isw1_ex_ini_addr_0 : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* DRAM_WADDR_1_1 10'h094 */
	union {
		uint32_t dram_waddr_1_1; // word name
		struct {
			uint32_t isw1_ex_ini_addr_1 : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* DRAM_WADDR_1_2 10'h098 */
	union {
		uint32_t dram_waddr_1_2; // word name
		struct {
			uint32_t isw1_ex_ini_addr_2 : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* DRAM_WADDR_1_3 10'h09C */
	union {
		uint32_t dram_waddr_1_3; // word name
		struct {
			uint32_t isw1_ex_ini_addr_3 : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* DRAM_WADDR_2_0 10'h0A0 */
	union {
		uint32_t dram_waddr_2_0; // word name
		struct {
			uint32_t isw2_ex_ini_addr_0 : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* DRAM_WADDR_2_1 10'h0A4 */
	union {
		uint32_t dram_waddr_2_1; // word name
		struct {
			uint32_t isw2_ex_ini_addr_1 : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* DRAM_WADDR_2_2 10'h0A8 */
	union {
		uint32_t dram_waddr_2_2; // word name
		struct {
			uint32_t isw2_ex_ini_addr_2 : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* DRAM_WADDR_2_3 10'h0AC */
	union {
		uint32_t dram_waddr_2_3; // word name
		struct {
			uint32_t isw2_ex_ini_addr_3 : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* DRAM_WADDR_3_0 10'h0B0 */
	union {
		uint32_t dram_waddr_3_0; // word name
		struct {
			uint32_t isw3_ex_ini_addr_0 : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* DRAM_WADDR_3_1 10'h0B4 */
	union {
		uint32_t dram_waddr_3_1; // word name
		struct {
			uint32_t isw3_ex_ini_addr_1 : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* DRAM_WADDR_3_2 10'h0B8 */
	union {
		uint32_t dram_waddr_3_2; // word name
		struct {
			uint32_t isw3_ex_ini_addr_2 : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* DRAM_WADDR_3_3 10'h0BC */
	union {
		uint32_t dram_waddr_3_3; // word name
		struct {
			uint32_t isw3_ex_ini_addr_3 : 28;
			uint32_t : 4; // padding bits
		};
	};
	/* SENSOR_SW_STATUS 10'h0C0 */
	union {
		uint32_t sensor_sw_status; // word name
		struct {
			uint32_t mipi_sel : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* DBG_MON_SEL 10'h0C4 */
	union {
		uint32_t dbg_mon_sel; // word name
		struct {
			uint32_t debug_mon_sel : 6;
			uint32_t : 2; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* BUF_UPDATE 10'h0C8 */
	union {
		uint32_t buf_update; // word name
		struct {
			uint32_t double_buf_update : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* MEM_LP_CTRL 10'h0CC */
	union {
		uint32_t mem_lp_ctrl; // word name
		struct {
			uint32_t sd : 1;
			uint32_t : 7; // padding bits
			uint32_t slp : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FE_DBG_MON_SEL 10'h0D0 */
	union {
		uint32_t fe_dbg_mon_sel; // word name
		struct {
			uint32_t fe0_debug_mon_sel : 2;
			uint32_t : 6; // padding bits
			uint32_t fe1_debug_mon_sel : 2;
			uint32_t : 6; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* ISK_DBG_MON_SEL 10'h0D4 */
	union {
		uint32_t isk_dbg_mon_sel; // word name
		struct {
			uint32_t isk0_debug_mon_sel : 3;
			uint32_t : 5; // padding bits
			uint32_t isk1_debug_mon_sel : 3;
			uint32_t : 5; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
} CsrBankIs;

#endif