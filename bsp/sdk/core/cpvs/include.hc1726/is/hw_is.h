/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef HW_IS_H_
#define HW_IS_H_

#ifndef __KERNEL__
#include <stdint.h>
#else
#include <linux/types.h>
#endif
#include "csr_bank_is.h"
#include "csr_bank_isk.h"

#define IS_IS_BASE 0x83000000
#define IS_IS_CFG_BASE 0x83000400
#define IS_IS_CHECKSUM_BASE 0x83000800
#define ISK0_ISK_BASE 0x83100000
#define ISK0_ISK_CFG_BASE 0x83100400

#ifdef CONFIG_AUGENTIX_SAPPORO
#define ISK1_ISK_BASE 0x83180000
#define ISK1_ISK_CFG_BASE 0x83180400
#else /* Kyoto */
#define ISK1_ISK_BASE 0x83200000
#define ISK1_ISK_CFG_BASE 0x83200400
#endif

#define _reg(addr) *((volatile uint32_t *)(addr))

enum mode {
	NORMAL,
	DISABLE,
};

typedef enum is_edp_sel { IS_EDP_SEL_ISR = 0, IS_EDP_SEL_PG } IsEdpSel;

typedef struct is_prd_brdcst {
	uint8_t to_edp;
	uint8_t to_fe_out2;
} IsPrdBrdcst;

typedef enum is_iroute_src {
	IS_IROUTE_SRC_LP_SENSOR,
	IS_IROUTE_SRC_EDP0_OUT0,
	IS_IROUTE_SRC_EDP0_OUT1,
	IS_IROUTE_SRC_ISR0,
	IS_IROUTE_SRC_EDP1_OUT0,
	IS_IROUTE_SRC_EDP1_OUT1,
	IS_IROUTE_SRC_ISR1,
	IS_IROUTE_SRC_NONE
} IsIrouteSrc;

typedef enum is_oroute_src {
	IS_OROUTE_SRC_BYPASS_ISK0,
	IS_OROUTE_SRC_ISK0_AGMA,
	IS_OROUTE_SRC_ISK0_CROP,
	IS_OROUTE_SRC_ISK0_BSP,
	IS_OROUTE_SRC_ISK0_FGMA,
	IS_OROUTE_SRC_ISK0_FSC,
	IS_OROUTE_SRC_ISK0_CVS,
	IS_OROUTE_SRC_ISK0_CS,
	IS_OROUTE_SRC_ISK0_INK,
	IS_OROUTE_SRC_BYPASS_ISK1,
	IS_OROUTE_SRC_ISK1_AGMA,
	IS_OROUTE_SRC_ISK1_CROP,
	IS_OROUTE_SRC_ISK1_BSP,
	IS_OROUTE_SRC_ISK1_FGMA,
	IS_OROUTE_SRC_ISK1_FSC,
	IS_OROUTE_SRC_ISK1_CVS,
	IS_OROUTE_SRC_ISK1_CS,
	IS_OROUTE_SRC_ISK1_INK,
	IS_OROUTE_SRC_NONE
} IsOrouteSrc;

typedef union is_iroute_dst {
	struct {
		uint32_t isk0_bypass : 1;
		uint32_t isk0_in0 : 1;
		uint32_t isk0_in1 : 1;
		uint32_t isk1_bypass : 1;
		uint32_t isk1_in0 : 1;
		uint32_t isk1_in1 : 1;
		uint32_t dummy : 26; /* padding */
	};
	uint32_t value;
} IsIrouteDst;

typedef union is_oroute_dst {
	struct {
		uint32_t isw_roi0 : 1;
		uint32_t isw_roi1 : 1;
		uint32_t isw0 : 1;
		uint32_t isw1 : 1;
		uint32_t dummy : 28; /* padding */
	};
	uint32_t value;
} IsOrouteDst;

typedef struct isk_in1_brdcst {
	uint8_t to_fpnr;
	uint8_t to_cvs;
	uint8_t to_cs;
} IskIn1Brdcst;

typedef struct isk_agma_brdcst {
	uint8_t to_isk_out;
	uint8_t to_fpnr;
} IskAgmaBrdcst;

typedef struct isk_fpnr_brdcst {
	uint8_t to_bls;
	uint8_t to_crop;
} IskFpnrBrdcst;

typedef struct isk_crop_brdcst {
	uint8_t to_isk_out;
	uint8_t to_dbc;
} IskCropBrdcst;

typedef struct isk_bsp_brdcst {
	uint8_t to_isk_out;
	uint8_t to_fgma;
} IskBspBrdcst;

typedef struct isk_fgma_brdcst {
	uint8_t to_isk_out;
	uint8_t to_fsc;
} IskFgmaBrdcst;

typedef struct is_path_cfg {
	/* Fe */
	enum is_edp_sel edp0_mux;
	enum is_edp_sel edp1_mux;
	struct is_prd_brdcst prd0_brdcst;
	struct is_prd_brdcst prd1_brdcst;
	/* IRoute */
	enum is_iroute_src bypass_isk0_sel;
	enum is_iroute_src isk0_in0_sel;
	enum is_iroute_src isk0_in1_sel;
	enum is_iroute_src bypass_isk1_sel;
	enum is_iroute_src isk1_in0_sel;
	enum is_iroute_src isk1_in1_sel;
	/* ORoute */
	enum is_oroute_src isw_roi0_sel;
	enum is_oroute_src isw_roi1_sel;
	enum is_oroute_src isw0_sel;
	enum is_oroute_src isw1_sel;
} IsPathCfg;

typedef struct isk_path_cfg {
	/* Kernel */
	struct isk_in1_brdcst in1_brdcst;
	struct isk_agma_brdcst agma_brdcst;
	struct isk_fpnr_brdcst fpnr_brdcst;
	struct isk_crop_brdcst crop_brdcst;
	struct isk_bsp_brdcst bsp_brdcst;
	struct isk_fgma_brdcst fgma_brdcst;
} IskPathCfg;

void is_set_path(volatile CsrBankIs *csr, const IsPathCfg *cfg);
void isk_set_path(volatile CsrBankIsk *csr, const IskPathCfg *cfg);

/* Old */
typedef enum iroute_src {
	I_LP,
	I_FE0_EDP0,
	I_FE0_EDP1,
	I_FE0_ISR,
	I_FE1_EDP0,
	I_FE1_EDP1,
	I_FE1_ISR,
	I_NONE
} IrouteSrc;

typedef enum iroute_dst {
	I_BYPASS_ISK0,
	I_ISK0_IN0,
	I_ISK0_IN1,
	I_BYPASS_ISK1,
	I_ISK1_IN0,
	I_ISK1_IN1,
	I_ALL
} IrouteDst;

typedef enum oroute_src {
	O_BYPASS_ISK0,
	O_ISK0_AGMA,
	O_ISK0_CROP,
	O_ISK0_BSP,
	O_ISK0_FGMA,
	O_ISK0_FSC,
	O_ISK0_CVS,
	O_ISK0_CS,
	O_ISK0_INK,
	O_BYPASS_ISK1,
	O_ISK1_AGMA,
	O_ISK1_CROP,
	O_ISK1_BSP,
	O_ISK1_FGMA,
	O_ISK1_FSC,
	O_ISK1_CVS,
	O_ISK1_CS,
	O_ISK1_INK,
	O_NONE
} OrouteSrc;

typedef enum oroute_dst { O_ISWROI0, O_ISWROI1, O_ISW0, O_ISW1, O_ALL } OrouteDst;

void hw_is_top_reset(void);
void hw_is_csr_reset(void);
void hw_isk0_csr_reset(void);
void hw_isk1_csr_reset(void);
void hw_is_top_set_route(uint32_t route_case_idx, uint32_t is_top_bit_depth);
void hw_is_top_set_route1_fpnr(uint32_t route_case_idx, uint32_t is_top_bit_depth);
void iroute_setting(IrouteDst dst, IrouteSrc src);
void oroute_setting(OrouteDst dst, OrouteSrc src);
void hw_is_routing_0(uint32_t bit_depth);
void hw_is_routing_1(uint32_t bit_depth);
void hw_is_routing_420(void);
void hw_is_isk0_disable(void);
void hw_is_isk1_disable(void);
void is_clear_checksum(void);
uint32_t is_get_isw0_checksum(void);
uint32_t is_get_isw1_checksum(void);
void is_share_mode(uint32_t mode);

#endif
