/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef __HW_DRAM_SETTING_H
#define __HW_DRAM_SETTING_H

#include "config.h"
#ifdef __KERNEL__
#include <linux/types.h>
#else
#include <stdint.h>
#endif

struct dram_controller_param {
	//RFSHTMG
	uint16_t t_rfc_min; //9:0
	uint16_t t_rfc_nom_x1_x32; //27:16

	//DRAMTMG8
	uint8_t t_xs_x32; //6:0
	uint8_t t_xs_dll_x32; //14:8
	uint8_t t_xs_abort_x32; //22:16
	uint8_t t_xs_fast_x32; //30:24

	//ADDRMAP6
	uint8_t addrmap_row_b12; //3:0
	uint8_t addrmap_row_b13; //11:8
	uint8_t addrmap_row_b14; //19:16
	uint8_t addrmap_row_b15; //27:24
};

struct ddr_phy_param {
	//PTR1
	uint32_t t_DINIT0; //18:0
	uint8_t t_DINIT1; //26:19

	//DTPR1
	uint8_t t_AOND; //1:0
	uint8_t t_RTW; //2
	uint8_t t_FAW; //8:3
	uint8_t t_MOD; //10:9
	uint8_t t_RTODT; //11
	uint8_t t_RFC; //23:16
	uint8_t t_DQSCK; //26:24
	uint8_t t_DQSCKMAX; //29:27
};

int hw_dram_init(struct dram_controller_param *dcp, struct ddr_phy_param *dpp);
int hw_dram_init_v2(struct dram_controller_param *dcp, struct ddr_phy_param *dpp, unsigned int dram_mts);
int hw_hyperram_init(uint32_t dram_mts);

#endif /* __HW_DRAM_SETTING_H */
