/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef CSR_TABLE_DRAMCONTROLLER_H_
#define CSR_TABLE_DRAMCONTROLLER_H_

#include <stdint.h>

CsrFieldEntry csr_field_table_dramcontroller[] = {
	// WORD mstr
	{ "field_mstr", 0x00000000, 31, 0, CSR_RW, 0x00000000 },
	{ "MSTR", 0x00000000, 31, 0, CSR_RW, 0x00000000 },
	// WORD stat
	{ "field_stat", 0x00000004, 31, 0, CSR_RW, 0x00000000 },
	{ "STAT", 0x00000004, 31, 0, CSR_RW, 0x00000000 },
	// WORD mstr1
	{ "field_mstr1", 0x00000008, 31, 0, CSR_RW, 0x00000000 },
	{ "MSTR1", 0x00000008, 31, 0, CSR_RW, 0x00000000 },
	// WORD mrctrl0
	{ "field_mrctrl0", 0x00000010, 31, 0, CSR_RW, 0x00000000 },
	{ "MRCTRL0", 0x00000010, 31, 0, CSR_RW, 0x00000000 },
	// WORD mrctrl1
	{ "field_mrctrl1", 0x00000014, 31, 0, CSR_RW, 0x00000000 },
	{ "MRCTRL1", 0x00000014, 31, 0, CSR_RW, 0x00000000 },
	// WORD mrstat
	{ "field_mrstat", 0x00000018, 31, 0, CSR_RW, 0x00000000 },
	{ "MRSTAT", 0x00000018, 31, 0, CSR_RW, 0x00000000 },
	// WORD mrctrl2
	{ "field_mrctrl2", 0x0000001C, 31, 0, CSR_RW, 0x00000000 },
	{ "MRCTRL2", 0x0000001C, 31, 0, CSR_RW, 0x00000000 },
	// WORD derateen
	{ "field_derateen", 0x00000020, 31, 0, CSR_RW, 0x00000000 },
	{ "DERATEEN", 0x00000020, 31, 0, CSR_RW, 0x00000000 },
	// WORD derateint
	{ "field_derateint", 0x00000024, 31, 0, CSR_RW, 0x00000000 },
	{ "DERATEINT", 0x00000024, 31, 0, CSR_RW, 0x00000000 },
	// WORD mstr2
	{ "field_mstr2", 0x00000028, 31, 0, CSR_RW, 0x00000000 },
	{ "MSTR2", 0x00000028, 31, 0, CSR_RW, 0x00000000 },
	// WORD deratectl
	{ "field_deratectl", 0x0000002C, 31, 0, CSR_RW, 0x00000000 },
	{ "DERATECTL", 0x0000002C, 31, 0, CSR_RW, 0x00000000 },
	// WORD pwrctl
	{ "field_pwrctl", 0x00000030, 31, 0, CSR_RW, 0x00000000 },
	{ "PWRCTL", 0x00000030, 31, 0, CSR_RW, 0x00000000 },
	// WORD pwrtmg
	{ "field_pwrtmg", 0x00000034, 31, 0, CSR_RW, 0x00000000 },
	{ "PWRTMG", 0x00000034, 31, 0, CSR_RW, 0x00000000 },
	// WORD hwlpctl
	{ "field_hwlpctl", 0x00000038, 31, 0, CSR_RW, 0x00000000 },
	{ "HWLPCTL", 0x00000038, 31, 0, CSR_RW, 0x00000000 },
	// WORD hwffcctl
	{ "field_hwffcctl", 0x0000003C, 31, 0, CSR_RW, 0x00000000 },
	{ "HWFFCCTL", 0x0000003C, 31, 0, CSR_RW, 0x00000000 },
	// WORD hwffcstat
	{ "field_hwffcstat", 0x00000040, 31, 0, CSR_RW, 0x00000000 },
	{ "HWFFCSTAT", 0x00000040, 31, 0, CSR_RW, 0x00000000 },
	// WORD hwffcex_rank1
	{ "field_hwffcex_rank1", 0x00000044, 31, 0, CSR_RW, 0x00000000 },
	{ "HWFFCEX_RANK1", 0x00000044, 31, 0, CSR_RW, 0x00000000 },
	// WORD hwffcex_rank2
	{ "field_hwffcex_rank2", 0x00000048, 31, 0, CSR_RW, 0x00000000 },
	{ "HWFFCEX_RANK2", 0x00000048, 31, 0, CSR_RW, 0x00000000 },
	// WORD hwffcex_rank3
	{ "field_hwffcex_rank3", 0x0000004C, 31, 0, CSR_RW, 0x00000000 },
	{ "HWFFCEX_RANK3", 0x0000004C, 31, 0, CSR_RW, 0x00000000 },
	// WORD rfshctl0
	{ "field_rfshctl0", 0x00000050, 31, 0, CSR_RW, 0x00000000 },
	{ "RFSHCTL0", 0x00000050, 31, 0, CSR_RW, 0x00000000 },
	// WORD rfshctl1
	{ "field_rfshctl1", 0x00000054, 31, 0, CSR_RW, 0x00000000 },
	{ "RFSHCTL1", 0x00000054, 31, 0, CSR_RW, 0x00000000 },
	// WORD rfshctl2
	{ "field_rfshctl2", 0x00000058, 31, 0, CSR_RW, 0x00000000 },
	{ "RFSHCTL2", 0x00000058, 31, 0, CSR_RW, 0x00000000 },
	// WORD rfshctl4
	{ "field_rfshctl4", 0x0000005C, 31, 0, CSR_RW, 0x00000000 },
	{ "RFSHCTL4", 0x0000005C, 31, 0, CSR_RW, 0x00000000 },
	// WORD rfshctl3
	{ "field_rfshctl3", 0x00000060, 31, 0, CSR_RW, 0x00000000 },
	{ "RFSHCTL3", 0x00000060, 31, 0, CSR_RW, 0x00000000 },
	// WORD rfshtmg
	{ "field_rfshtmg", 0x00000064, 31, 0, CSR_RW, 0x00000000 },
	{ "RFSHTMG", 0x00000064, 31, 0, CSR_RW, 0x00000000 },
	// WORD rfshtmg1
	{ "field_rfshtmg1", 0x00000068, 31, 0, CSR_RW, 0x00000000 },
	{ "RFSHTMG1", 0x00000068, 31, 0, CSR_RW, 0x00000000 },
	// WORD ecccfg0
	{ "field_ecccfg0", 0x00000070, 31, 0, CSR_RW, 0x00000000 },
	{ "ECCCFG0", 0x00000070, 31, 0, CSR_RW, 0x00000000 },
	// WORD ecccfg1
	{ "field_ecccfg1", 0x00000074, 31, 0, CSR_RW, 0x00000000 },
	{ "ECCCFG1", 0x00000074, 31, 0, CSR_RW, 0x00000000 },
	// WORD eccstat
	{ "field_eccstat", 0x00000078, 31, 0, CSR_RW, 0x00000000 },
	{ "ECCSTAT", 0x00000078, 31, 0, CSR_RW, 0x00000000 },
	// WORD eccctl
	{ "field_eccctl", 0x0000007C, 31, 0, CSR_RW, 0x00000000 },
	{ "ECCCTL", 0x0000007C, 31, 0, CSR_RW, 0x00000000 },
	// WORD eccerrcnt
	{ "field_eccerrcnt", 0x00000080, 31, 0, CSR_RW, 0x00000000 },
	{ "ECCERRCNT", 0x00000080, 31, 0, CSR_RW, 0x00000000 },
	// WORD ecccaddr0
	{ "field_ecccaddr0", 0x00000084, 31, 0, CSR_RW, 0x00000000 },
	{ "ECCCADDR0", 0x00000084, 31, 0, CSR_RW, 0x00000000 },
	// WORD ecccaddr1
	{ "field_ecccaddr1", 0x00000088, 31, 0, CSR_RW, 0x00000000 },
	{ "ECCCADDR1", 0x00000088, 31, 0, CSR_RW, 0x00000000 },
	// WORD ecccsyn0
	{ "field_ecccsyn0", 0x0000008C, 31, 0, CSR_RW, 0x00000000 },
	{ "ECCCSYN0", 0x0000008C, 31, 0, CSR_RW, 0x00000000 },
	// WORD ecccsyn1
	{ "field_ecccsyn1", 0x00000090, 31, 0, CSR_RW, 0x00000000 },
	{ "ECCCSYN1", 0x00000090, 31, 0, CSR_RW, 0x00000000 },
	// WORD ecccsyn2
	{ "field_ecccsyn2", 0x00000094, 31, 0, CSR_RW, 0x00000000 },
	{ "ECCCSYN2", 0x00000094, 31, 0, CSR_RW, 0x00000000 },
	// WORD eccbitmask0
	{ "field_eccbitmask0", 0x00000098, 31, 0, CSR_RW, 0x00000000 },
	{ "ECCBITMASK0", 0x00000098, 31, 0, CSR_RW, 0x00000000 },
	// WORD eccbitmask1
	{ "field_eccbitmask1", 0x0000009C, 31, 0, CSR_RW, 0x00000000 },
	{ "ECCBITMASK1", 0x0000009C, 31, 0, CSR_RW, 0x00000000 },
	// WORD eccbitmask2
	{ "field_eccbitmask2", 0x000000A0, 31, 0, CSR_RW, 0x00000000 },
	{ "ECCBITMASK2", 0x000000A0, 31, 0, CSR_RW, 0x00000000 },
	// WORD eccuaddr0
	{ "field_eccuaddr0", 0x000000A4, 31, 0, CSR_RW, 0x00000000 },
	{ "ECCUADDR0", 0x000000A4, 31, 0, CSR_RW, 0x00000000 },
	// WORD eccuaddr1
	{ "field_eccuaddr1", 0x000000A8, 31, 0, CSR_RW, 0x00000000 },
	{ "ECCUADDR1", 0x000000A8, 31, 0, CSR_RW, 0x00000000 },
	// WORD eccusyn0
	{ "field_eccusyn0", 0x000000AC, 31, 0, CSR_RW, 0x00000000 },
	{ "ECCUSYN0", 0x000000AC, 31, 0, CSR_RW, 0x00000000 },
	// WORD eccusyn1
	{ "field_eccusyn1", 0x000000B0, 31, 0, CSR_RW, 0x00000000 },
	{ "ECCUSYN1", 0x000000B0, 31, 0, CSR_RW, 0x00000000 },
	// WORD eccusyn2
	{ "field_eccusyn2", 0x000000B4, 31, 0, CSR_RW, 0x00000000 },
	{ "ECCUSYN2", 0x000000B4, 31, 0, CSR_RW, 0x00000000 },
	// WORD eccpoisonaddr0
	{ "field_eccpoisonaddr0", 0x000000B8, 31, 0, CSR_RW, 0x00000000 },
	{ "ECCPOISONADDR0", 0x000000B8, 31, 0, CSR_RW, 0x00000000 },
	// WORD eccpoisonaddr1
	{ "field_eccpoisonaddr1", 0x000000BC, 31, 0, CSR_RW, 0x00000000 },
	{ "ECCPOISONADDR1", 0x000000BC, 31, 0, CSR_RW, 0x00000000 },
	// WORD crcparctl0
	{ "field_crcparctl0", 0x000000C0, 31, 0, CSR_RW, 0x00000000 },
	{ "CRCPARCTL0", 0x000000C0, 31, 0, CSR_RW, 0x00000000 },
	// WORD crcparctl1
	{ "field_crcparctl1", 0x000000C4, 31, 0, CSR_RW, 0x00000000 },
	{ "CRCPARCTL1", 0x000000C4, 31, 0, CSR_RW, 0x00000000 },
	// WORD crcparctl2
	{ "field_crcparctl2", 0x000000C8, 31, 0, CSR_RW, 0x00000000 },
	{ "CRCPARCTL2", 0x000000C8, 31, 0, CSR_RW, 0x00000000 },
	// WORD crcparstat
	{ "field_crcparstat", 0x000000CC, 31, 0, CSR_RW, 0x00000000 },
	{ "CRCPARSTAT", 0x000000CC, 31, 0, CSR_RW, 0x00000000 },
	// WORD init0
	{ "field_init0", 0x000000D0, 31, 0, CSR_RW, 0x00000000 },
	{ "INIT0", 0x000000D0, 31, 0, CSR_RW, 0x00000000 },
	// WORD init1
	{ "field_init1", 0x000000D4, 31, 0, CSR_RW, 0x00000000 },
	{ "INIT1", 0x000000D4, 31, 0, CSR_RW, 0x00000000 },
	// WORD init2
	{ "field_init2", 0x000000D8, 31, 0, CSR_RW, 0x00000000 },
	{ "INIT2", 0x000000D8, 31, 0, CSR_RW, 0x00000000 },
	// WORD init3
	{ "field_init3", 0x000000DC, 31, 0, CSR_RW, 0x00000000 },
	{ "INIT3", 0x000000DC, 31, 0, CSR_RW, 0x00000000 },
	// WORD init4
	{ "field_init4", 0x000000E0, 31, 0, CSR_RW, 0x00000000 },
	{ "INIT4", 0x000000E0, 31, 0, CSR_RW, 0x00000000 },
	// WORD init5
	{ "field_init5", 0x000000E4, 31, 0, CSR_RW, 0x00000000 },
	{ "INIT5", 0x000000E4, 31, 0, CSR_RW, 0x00000000 },
	// WORD init6
	{ "field_init6", 0x000000E8, 31, 0, CSR_RW, 0x00000000 },
	{ "INIT6", 0x000000E8, 31, 0, CSR_RW, 0x00000000 },
	// WORD init7
	{ "field_init7", 0x000000EC, 31, 0, CSR_RW, 0x00000000 },
	{ "INIT7", 0x000000EC, 31, 0, CSR_RW, 0x00000000 },
	// WORD dimmctl
	{ "field_dimmctl", 0x000000F0, 31, 0, CSR_RW, 0x00000000 },
	{ "DIMMCTL", 0x000000F0, 31, 0, CSR_RW, 0x00000000 },
	// WORD rankctl
	{ "field_rankctl", 0x000000F4, 31, 0, CSR_RW, 0x00000000 },
	{ "RANKCTL", 0x000000F4, 31, 0, CSR_RW, 0x00000000 },
	// WORD rankctl1
	{ "field_rankctl1", 0x000000F8, 31, 0, CSR_RW, 0x00000000 },
	{ "RANKCTL1", 0x000000F8, 31, 0, CSR_RW, 0x00000000 },
	// WORD chctl
	{ "field_chctl", 0x000000FC, 31, 0, CSR_RW, 0x00000000 },
	{ "CHCTL", 0x000000FC, 31, 0, CSR_RW, 0x00000000 },
	// WORD dramtmg0
	{ "field_dramtmg0", 0x00000100, 31, 0, CSR_RW, 0x00000000 },
	{ "DRAMTMG0", 0x00000100, 31, 0, CSR_RW, 0x00000000 },
	// WORD dramtmg1
	{ "field_dramtmg1", 0x00000104, 31, 0, CSR_RW, 0x00000000 },
	{ "DRAMTMG1", 0x00000104, 31, 0, CSR_RW, 0x00000000 },
	// WORD dramtmg2
	{ "field_dramtmg2", 0x00000108, 31, 0, CSR_RW, 0x00000000 },
	{ "DRAMTMG2", 0x00000108, 31, 0, CSR_RW, 0x00000000 },
	// WORD dramtmg3
	{ "field_dramtmg3", 0x0000010C, 31, 0, CSR_RW, 0x00000000 },
	{ "DRAMTMG3", 0x0000010C, 31, 0, CSR_RW, 0x00000000 },
	// WORD dramtmg4
	{ "field_dramtmg4", 0x00000110, 31, 0, CSR_RW, 0x00000000 },
	{ "DRAMTMG4", 0x00000110, 31, 0, CSR_RW, 0x00000000 },
	// WORD dramtmg5
	{ "field_dramtmg5", 0x00000114, 31, 0, CSR_RW, 0x00000000 },
	{ "DRAMTMG5", 0x00000114, 31, 0, CSR_RW, 0x00000000 },
	// WORD dramtmg6
	{ "field_dramtmg6", 0x00000118, 31, 0, CSR_RW, 0x00000000 },
	{ "DRAMTMG6", 0x00000118, 31, 0, CSR_RW, 0x00000000 },
	// WORD dramtmg7
	{ "field_dramtmg7", 0x0000011C, 31, 0, CSR_RW, 0x00000000 },
	{ "DRAMTMG7", 0x0000011C, 31, 0, CSR_RW, 0x00000000 },
	// WORD dramtmg8
	{ "field_dramtmg8", 0x00000120, 31, 0, CSR_RW, 0x00000000 },
	{ "DRAMTMG8", 0x00000120, 31, 0, CSR_RW, 0x00000000 },
	// WORD dramtmg9
	{ "field_dramtmg9", 0x00000124, 31, 0, CSR_RW, 0x00000000 },
	{ "DRAMTMG9", 0x00000124, 31, 0, CSR_RW, 0x00000000 },
	// WORD dramtmg10
	{ "field_dramtmg10", 0x00000128, 31, 0, CSR_RW, 0x00000000 },
	{ "DRAMTMG10", 0x00000128, 31, 0, CSR_RW, 0x00000000 },
	// WORD dramtmg11
	{ "field_dramtmg11", 0x0000012C, 31, 0, CSR_RW, 0x00000000 },
	{ "DRAMTMG11", 0x0000012C, 31, 0, CSR_RW, 0x00000000 },
	// WORD dramtmg12
	{ "field_dramtmg12", 0x00000130, 31, 0, CSR_RW, 0x00000000 },
	{ "DRAMTMG12", 0x00000130, 31, 0, CSR_RW, 0x00000000 },
	// WORD dramtmg13
	{ "field_dramtmg13", 0x00000134, 31, 0, CSR_RW, 0x00000000 },
	{ "DRAMTMG13", 0x00000134, 31, 0, CSR_RW, 0x00000000 },
	// WORD dramtmg14
	{ "field_dramtmg14", 0x00000138, 31, 0, CSR_RW, 0x00000000 },
	{ "DRAMTMG14", 0x00000138, 31, 0, CSR_RW, 0x00000000 },
	// WORD dramtmg15
	{ "field_dramtmg15", 0x0000013C, 31, 0, CSR_RW, 0x00000000 },
	{ "DRAMTMG15", 0x0000013C, 31, 0, CSR_RW, 0x00000000 },
	// WORD dramtmg16
	{ "field_dramtmg16", 0x00000140, 31, 0, CSR_RW, 0x00000000 },
	{ "DRAMTMG16", 0x00000140, 31, 0, CSR_RW, 0x00000000 },
	// WORD dramtmg17
	{ "field_dramtmg17", 0x00000144, 31, 0, CSR_RW, 0x00000000 },
	{ "DRAMTMG17", 0x00000144, 31, 0, CSR_RW, 0x00000000 },
	// WORD rfshtmg_het
	{ "field_rfshtmg_het", 0x00000150, 31, 0, CSR_RW, 0x00000000 },
	{ "RFSHTMG_HET", 0x00000150, 31, 0, CSR_RW, 0x00000000 },
	// WORD mramtmg0
	{ "field_mramtmg0", 0x00000170, 31, 0, CSR_RW, 0x00000000 },
	{ "MRAMTMG0", 0x00000170, 31, 0, CSR_RW, 0x00000000 },
	// WORD mramtmg1
	{ "field_mramtmg1", 0x00000174, 31, 0, CSR_RW, 0x00000000 },
	{ "MRAMTMG1", 0x00000174, 31, 0, CSR_RW, 0x00000000 },
	// WORD mramtmg4
	{ "field_mramtmg4", 0x00000178, 31, 0, CSR_RW, 0x00000000 },
	{ "MRAMTMG4", 0x00000178, 31, 0, CSR_RW, 0x00000000 },
	// WORD mramtmg9
	{ "field_mramtmg9", 0x0000017C, 31, 0, CSR_RW, 0x00000000 },
	{ "MRAMTMG9", 0x0000017C, 31, 0, CSR_RW, 0x00000000 },
	// WORD zqctl0
	{ "field_zqctl0", 0x00000180, 31, 0, CSR_RW, 0x00000000 },
	{ "ZQCTL0", 0x00000180, 31, 0, CSR_RW, 0x00000000 },
	// WORD zqctl1
	{ "field_zqctl1", 0x00000184, 31, 0, CSR_RW, 0x00000000 },
	{ "ZQCTL1", 0x00000184, 31, 0, CSR_RW, 0x00000000 },
	// WORD zqctl2
	{ "field_zqctl2", 0x00000188, 31, 0, CSR_RW, 0x00000000 },
	{ "ZQCTL2", 0x00000188, 31, 0, CSR_RW, 0x00000000 },
	// WORD zqstat
	{ "field_zqstat", 0x0000018C, 31, 0, CSR_RW, 0x00000000 },
	{ "ZQSTAT", 0x0000018C, 31, 0, CSR_RW, 0x00000000 },
	// WORD dfitmg0
	{ "field_dfitmg0", 0x00000190, 31, 0, CSR_RW, 0x00000000 },
	{ "DFITMG0", 0x00000190, 31, 0, CSR_RW, 0x00000000 },
	// WORD dfitmg1
	{ "field_dfitmg1", 0x00000194, 31, 0, CSR_RW, 0x00000000 },
	{ "DFITMG1", 0x00000194, 31, 0, CSR_RW, 0x00000000 },
	// WORD dfilpcfg0
	{ "field_dfilpcfg0", 0x00000198, 31, 0, CSR_RW, 0x00000000 },
	{ "DFILPCFG0", 0x00000198, 31, 0, CSR_RW, 0x00000000 },
	// WORD dfilpcfg1
	{ "field_dfilpcfg1", 0x0000019C, 31, 0, CSR_RW, 0x00000000 },
	{ "DFILPCFG1", 0x0000019C, 31, 0, CSR_RW, 0x00000000 },
	// WORD dfiupd0
	{ "field_dfiupd0", 0x000001A0, 31, 0, CSR_RW, 0x00000000 },
	{ "DFIUPD0", 0x000001A0, 31, 0, CSR_RW, 0x00000000 },
	// WORD dfiupd1
	{ "field_dfiupd1", 0x000001A4, 31, 0, CSR_RW, 0x00000000 },
	{ "DFIUPD1", 0x000001A4, 31, 0, CSR_RW, 0x00000000 },
	// WORD dfiupd2
	{ "field_dfiupd2", 0x000001A8, 31, 0, CSR_RW, 0x00000000 },
	{ "DFIUPD2", 0x000001A8, 31, 0, CSR_RW, 0x00000000 },
	// WORD dfimisc
	{ "field_dfimisc", 0x000001B0, 31, 0, CSR_RW, 0x00000000 },
	{ "DFIMISC", 0x000001B0, 31, 0, CSR_RW, 0x00000000 },
	// WORD dfitmg2
	{ "field_dfitmg2", 0x000001B4, 31, 0, CSR_RW, 0x00000000 },
	{ "DFITMG2", 0x000001B4, 31, 0, CSR_RW, 0x00000000 },
	// WORD dfitmg3
	{ "field_dfitmg3", 0x000001B8, 31, 0, CSR_RW, 0x00000000 },
	{ "DFITMG3", 0x000001B8, 31, 0, CSR_RW, 0x00000000 },
	// WORD dfistat
	{ "field_dfistat", 0x000001BC, 31, 0, CSR_RW, 0x00000000 },
	{ "DFISTAT", 0x000001BC, 31, 0, CSR_RW, 0x00000000 },
	// WORD dbictl
	{ "field_dbictl", 0x000001C0, 31, 0, CSR_RW, 0x00000000 },
	{ "DBICTL", 0x000001C0, 31, 0, CSR_RW, 0x00000000 },
	// WORD dfiphymstr
	{ "field_dfiphymstr", 0x000001C4, 31, 0, CSR_RW, 0x00000000 },
	{ "DFIPHYMSTR", 0x000001C4, 31, 0, CSR_RW, 0x00000000 },
	// WORD addrmap0
	{ "field_addrmap0", 0x00000200, 31, 0, CSR_RW, 0x00000000 },
	{ "ADDRMAP0", 0x00000200, 31, 0, CSR_RW, 0x00000000 },
	// WORD addrmap1
	{ "field_addrmap1", 0x00000204, 31, 0, CSR_RW, 0x00000000 },
	{ "ADDRMAP1", 0x00000204, 31, 0, CSR_RW, 0x00000000 },
	// WORD addrmap2
	{ "field_addrmap2", 0x00000208, 31, 0, CSR_RW, 0x00000000 },
	{ "ADDRMAP2", 0x00000208, 31, 0, CSR_RW, 0x00000000 },
	// WORD addrmap3
	{ "field_addrmap3", 0x0000020C, 31, 0, CSR_RW, 0x00000000 },
	{ "ADDRMAP3", 0x0000020C, 31, 0, CSR_RW, 0x00000000 },
	// WORD addrmap4
	{ "field_addrmap4", 0x00000210, 31, 0, CSR_RW, 0x00000000 },
	{ "ADDRMAP4", 0x00000210, 31, 0, CSR_RW, 0x00000000 },
	// WORD addrmap5
	{ "field_addrmap5", 0x00000214, 31, 0, CSR_RW, 0x00000000 },
	{ "ADDRMAP5", 0x00000214, 31, 0, CSR_RW, 0x00000000 },
	// WORD addrmap6
	{ "field_addrmap6", 0x00000218, 31, 0, CSR_RW, 0x00000000 },
	{ "ADDRMAP6", 0x00000218, 31, 0, CSR_RW, 0x00000000 },
	// WORD addrmap7
	{ "field_addrmap7", 0x0000021C, 31, 0, CSR_RW, 0x00000000 },
	{ "ADDRMAP7", 0x0000021C, 31, 0, CSR_RW, 0x00000000 },
	// WORD addrmap8
	{ "field_addrmap8", 0x00000220, 31, 0, CSR_RW, 0x00000000 },
	{ "ADDRMAP8", 0x00000220, 31, 0, CSR_RW, 0x00000000 },
	// WORD addrmap9
	{ "field_addrmap9", 0x00000224, 31, 0, CSR_RW, 0x00000000 },
	{ "ADDRMAP9", 0x00000224, 31, 0, CSR_RW, 0x00000000 },
	// WORD addrmap10
	{ "field_addrmap10", 0x00000228, 31, 0, CSR_RW, 0x00000000 },
	{ "ADDRMAP10", 0x00000228, 31, 0, CSR_RW, 0x00000000 },
	// WORD addrmap11
	{ "field_addrmap11", 0x0000022C, 31, 0, CSR_RW, 0x00000000 },
	{ "ADDRMAP11", 0x0000022C, 31, 0, CSR_RW, 0x00000000 },
	// WORD odtcfg
	{ "field_odtcfg", 0x00000240, 31, 0, CSR_RW, 0x00000000 },
	{ "ODTCFG", 0x00000240, 31, 0, CSR_RW, 0x00000000 },
	// WORD odtmap
	{ "field_odtmap", 0x00000244, 31, 0, CSR_RW, 0x00000000 },
	{ "ODTMAP", 0x00000244, 31, 0, CSR_RW, 0x00000000 },
	// WORD sched
	{ "field_sched", 0x00000250, 31, 0, CSR_RW, 0x00000000 },
	{ "SCHED", 0x00000250, 31, 0, CSR_RW, 0x00000000 },
	// WORD sched1
	{ "field_sched1", 0x00000254, 31, 0, CSR_RW, 0x00000000 },
	{ "SCHED1", 0x00000254, 31, 0, CSR_RW, 0x00000000 },
	// WORD sched2
	{ "field_sched2", 0x00000258, 31, 0, CSR_RW, 0x00000000 },
	{ "SCHED2", 0x00000258, 31, 0, CSR_RW, 0x00000000 },
	// WORD perfhpr1
	{ "field_perfhpr1", 0x0000025C, 31, 0, CSR_RW, 0x00000000 },
	{ "PERFHPR1", 0x0000025C, 31, 0, CSR_RW, 0x00000000 },
	// WORD perflpr1
	{ "field_perflpr1", 0x00000264, 31, 0, CSR_RW, 0x00000000 },
	{ "PERFLPR1", 0x00000264, 31, 0, CSR_RW, 0x00000000 },
	// WORD perfwr1
	{ "field_perfwr1", 0x0000026C, 31, 0, CSR_RW, 0x00000000 },
	{ "PERFWR1", 0x0000026C, 31, 0, CSR_RW, 0x00000000 },
	// WORD sched3
	{ "field_sched3", 0x00000270, 31, 0, CSR_RW, 0x00000000 },
	{ "SCHED3", 0x00000270, 31, 0, CSR_RW, 0x00000000 },
	// WORD sched4
	{ "field_sched4", 0x00000274, 31, 0, CSR_RW, 0x00000000 },
	{ "SCHED4", 0x00000274, 31, 0, CSR_RW, 0x00000000 },
	// WORD sched5
	{ "field_sched5", 0x00000278, 31, 0, CSR_RW, 0x00000000 },
	{ "SCHED5", 0x00000278, 31, 0, CSR_RW, 0x00000000 },
	// WORD dqmap0
	{ "field_dqmap0", 0x00000280, 31, 0, CSR_RW, 0x00000000 },
	{ "DQMAP0", 0x00000280, 31, 0, CSR_RW, 0x00000000 },
	// WORD dqmap1
	{ "field_dqmap1", 0x00000284, 31, 0, CSR_RW, 0x00000000 },
	{ "DQMAP1", 0x00000284, 31, 0, CSR_RW, 0x00000000 },
	// WORD dqmap2
	{ "field_dqmap2", 0x00000288, 31, 0, CSR_RW, 0x00000000 },
	{ "DQMAP2", 0x00000288, 31, 0, CSR_RW, 0x00000000 },
	// WORD dqmap3
	{ "field_dqmap3", 0x0000028C, 31, 0, CSR_RW, 0x00000000 },
	{ "DQMAP3", 0x0000028C, 31, 0, CSR_RW, 0x00000000 },
	// WORD dqmap4
	{ "field_dqmap4", 0x00000290, 31, 0, CSR_RW, 0x00000000 },
	{ "DQMAP4", 0x00000290, 31, 0, CSR_RW, 0x00000000 },
	// WORD dqmap5
	{ "field_dqmap5", 0x00000294, 31, 0, CSR_RW, 0x00000000 },
	{ "DQMAP5", 0x00000294, 31, 0, CSR_RW, 0x00000000 },
	// WORD dbg0
	{ "field_dbg0", 0x00000300, 31, 0, CSR_RW, 0x00000000 },
	{ "DBG0", 0x00000300, 31, 0, CSR_RW, 0x00000000 },
	// WORD dbg1
	{ "field_dbg1", 0x00000304, 31, 0, CSR_RW, 0x00000000 },
	{ "DBG1", 0x00000304, 31, 0, CSR_RW, 0x00000000 },
	// WORD dbgcam
	{ "field_dbgcam", 0x00000308, 31, 0, CSR_RW, 0x00000000 },
	{ "DBGCAM", 0x00000308, 31, 0, CSR_RW, 0x00000000 },
	// WORD dbgcmd
	{ "field_dbgcmd", 0x0000030C, 31, 0, CSR_RW, 0x00000000 },
	{ "DBGCMD", 0x0000030C, 31, 0, CSR_RW, 0x00000000 },
	// WORD dbgstat
	{ "field_dbgstat", 0x00000310, 31, 0, CSR_RW, 0x00000000 },
	{ "DBGSTAT", 0x00000310, 31, 0, CSR_RW, 0x00000000 },
	// WORD dbgcam1
	{ "field_dbgcam1", 0x00000318, 31, 0, CSR_RW, 0x00000000 },
	{ "DBGCAM1", 0x00000318, 31, 0, CSR_RW, 0x00000000 },
	// WORD swctl
	{ "field_swctl", 0x00000320, 31, 0, CSR_RW, 0x00000000 },
	{ "SWCTL", 0x00000320, 31, 0, CSR_RW, 0x00000000 },
	// WORD swstat
	{ "field_swstat", 0x00000324, 31, 0, CSR_RW, 0x00000000 },
	{ "SWSTAT", 0x00000324, 31, 0, CSR_RW, 0x00000000 },
	// WORD swctlstatic
	{ "field_swctlstatic", 0x00000328, 31, 0, CSR_RW, 0x00000000 },
	{ "SWCTLSTATIC", 0x00000328, 31, 0, CSR_RW, 0x00000000 },
	// WORD ocparcfg0
	{ "field_ocparcfg0", 0x00000330, 31, 0, CSR_RW, 0x00000000 },
	{ "OCPARCFG0", 0x00000330, 31, 0, CSR_RW, 0x00000000 },
	// WORD ocparcfg1
	{ "field_ocparcfg1", 0x00000334, 31, 0, CSR_RW, 0x00000000 },
	{ "OCPARCFG1", 0x00000334, 31, 0, CSR_RW, 0x00000000 },
	// WORD ocparstat0
	{ "field_ocparstat0", 0x00000338, 31, 0, CSR_RW, 0x00000000 },
	{ "OCPARSTAT0", 0x00000338, 31, 0, CSR_RW, 0x00000000 },
	// WORD ocparstat1
	{ "field_ocparstat1", 0x0000033C, 31, 0, CSR_RW, 0x00000000 },
	{ "OCPARSTAT1", 0x0000033C, 31, 0, CSR_RW, 0x00000000 },
	// WORD ocparstat2
	{ "field_ocparstat2", 0x00000340, 31, 0, CSR_RW, 0x00000000 },
	{ "OCPARSTAT2", 0x00000340, 31, 0, CSR_RW, 0x00000000 },
	// WORD ocparstat3
	{ "field_ocparstat3", 0x00000344, 31, 0, CSR_RW, 0x00000000 },
	{ "OCPARSTAT3", 0x00000344, 31, 0, CSR_RW, 0x00000000 },
	// WORD ocparstat4
	{ "field_ocparstat4", 0x00000348, 31, 0, CSR_RW, 0x00000000 },
	{ "OCPARSTAT4", 0x00000348, 31, 0, CSR_RW, 0x00000000 },
	// WORD ocparstat5
	{ "field_ocparstat5", 0x0000034C, 31, 0, CSR_RW, 0x00000000 },
	{ "OCPARSTAT5", 0x0000034C, 31, 0, CSR_RW, 0x00000000 },
	// WORD ocparstat6
	{ "field_ocparstat6", 0x00000350, 31, 0, CSR_RW, 0x00000000 },
	{ "OCPARSTAT6", 0x00000350, 31, 0, CSR_RW, 0x00000000 },
	// WORD ocparstat7
	{ "field_ocparstat7", 0x00000354, 31, 0, CSR_RW, 0x00000000 },
	{ "OCPARSTAT7", 0x00000354, 31, 0, CSR_RW, 0x00000000 },
	// WORD ocecccfg0
	{ "field_ocecccfg0", 0x00000358, 31, 0, CSR_RW, 0x00000000 },
	{ "OCECCCFG0", 0x00000358, 31, 0, CSR_RW, 0x00000000 },
	// WORD ocecccfg1
	{ "field_ocecccfg1", 0x0000035C, 31, 0, CSR_RW, 0x00000000 },
	{ "OCECCCFG1", 0x0000035C, 31, 0, CSR_RW, 0x00000000 },
	// WORD oceccstat0
	{ "field_oceccstat0", 0x00000360, 31, 0, CSR_RW, 0x00000000 },
	{ "OCECCSTAT0", 0x00000360, 31, 0, CSR_RW, 0x00000000 },
	// WORD oceccstat1
	{ "field_oceccstat1", 0x00000364, 31, 0, CSR_RW, 0x00000000 },
	{ "OCECCSTAT1", 0x00000364, 31, 0, CSR_RW, 0x00000000 },
	// WORD oceccstat2
	{ "field_oceccstat2", 0x00000368, 31, 0, CSR_RW, 0x00000000 },
	{ "OCECCSTAT2", 0x00000368, 31, 0, CSR_RW, 0x00000000 },
	// WORD poisoncfg
	{ "field_poisoncfg", 0x0000036C, 31, 0, CSR_RW, 0x00000000 },
	{ "POISONCFG", 0x0000036C, 31, 0, CSR_RW, 0x00000000 },
	// WORD poisonstat
	{ "field_poisonstat", 0x00000370, 31, 0, CSR_RW, 0x00000000 },
	{ "POISONSTAT", 0x00000370, 31, 0, CSR_RW, 0x00000000 },
	// WORD adveccindex
	{ "field_adveccindex", 0x00000374, 31, 0, CSR_RW, 0x00000000 },
	{ "ADVECCINDEX", 0x00000374, 31, 0, CSR_RW, 0x00000000 },
	// WORD adveccstat
	{ "field_adveccstat", 0x00000378, 31, 0, CSR_RW, 0x00000000 },
	{ "ADVECCSTAT", 0x00000378, 31, 0, CSR_RW, 0x00000000 },
	// WORD eccpoisonpat0
	{ "field_eccpoisonpat0", 0x0000037C, 31, 0, CSR_RW, 0x00000000 },
	{ "ECCPOISONPAT0", 0x0000037C, 31, 0, CSR_RW, 0x00000000 },
	// WORD eccpoisonpat1
	{ "field_eccpoisonpat1", 0x00000380, 31, 0, CSR_RW, 0x00000000 },
	{ "ECCPOISONPAT1", 0x00000380, 31, 0, CSR_RW, 0x00000000 },
	// WORD eccpoisonpat2
	{ "field_eccpoisonpat2", 0x00000384, 31, 0, CSR_RW, 0x00000000 },
	{ "ECCPOISONPAT2", 0x00000384, 31, 0, CSR_RW, 0x00000000 },
	// WORD eccapstat
	{ "field_eccapstat", 0x00000388, 31, 0, CSR_RW, 0x00000000 },
	{ "ECCAPSTAT", 0x00000388, 31, 0, CSR_RW, 0x00000000 },
	// WORD caparpoisonctl
	{ "field_caparpoisonctl", 0x000003A0, 31, 0, CSR_RW, 0x00000000 },
	{ "CAPARPOISONCTL", 0x000003A0, 31, 0, CSR_RW, 0x00000000 },
	// WORD caparpoisonstat
	{ "field_caparpoisonstat", 0x000003A4, 31, 0, CSR_RW, 0x00000000 },
	{ "CAPARPOISONSTAT", 0x000003A4, 31, 0, CSR_RW, 0x00000000 },
	// WORD dynbsmstat
	{ "field_dynbsmstat", 0x000003B0, 31, 0, CSR_RW, 0x00000000 },
	{ "DYNBSMSTAT", 0x000003B0, 31, 0, CSR_RW, 0x00000000 },
	// WORD crcparctl3
	{ "field_crcparctl3", 0x000003B8, 31, 0, CSR_RW, 0x00000000 },
	{ "CRCPARCTL3", 0x000003B8, 31, 0, CSR_RW, 0x00000000 },
	// WORD regparcfg
	{ "field_regparcfg", 0x000003C0, 31, 0, CSR_RW, 0x00000000 },
	{ "REGPARCFG", 0x000003C0, 31, 0, CSR_RW, 0x00000000 },
	// WORD regparstat
	{ "field_regparstat", 0x000003C4, 31, 0, CSR_RW, 0x00000000 },
	{ "REGPARSTAT", 0x000003C4, 31, 0, CSR_RW, 0x00000000 },
	// WORD rcdinit1
	{ "field_rcdinit1", 0x000003D0, 31, 0, CSR_RW, 0x00000000 },
	{ "RCDINIT1", 0x000003D0, 31, 0, CSR_RW, 0x00000000 },
	// WORD rcdinit2
	{ "field_rcdinit2", 0x000003D4, 31, 0, CSR_RW, 0x00000000 },
	{ "RCDINIT2", 0x000003D4, 31, 0, CSR_RW, 0x00000000 },
	// WORD rcdinit3
	{ "field_rcdinit3", 0x000003D8, 31, 0, CSR_RW, 0x00000000 },
	{ "RCDINIT3", 0x000003D8, 31, 0, CSR_RW, 0x00000000 },
	// WORD rcdinit4
	{ "field_rcdinit4", 0x000003DC, 31, 0, CSR_RW, 0x00000000 },
	{ "RCDINIT4", 0x000003DC, 31, 0, CSR_RW, 0x00000000 },
	// WORD occapcfg
	{ "field_occapcfg", 0x000003E0, 31, 0, CSR_RW, 0x00000000 },
	{ "OCCAPCFG", 0x000003E0, 31, 0, CSR_RW, 0x00000000 },
	// WORD occapstat
	{ "field_occapstat", 0x000003E4, 31, 0, CSR_RW, 0x00000000 },
	{ "OCCAPSTAT", 0x000003E4, 31, 0, CSR_RW, 0x00000000 },
	// WORD occapcfg1
	{ "field_occapcfg1", 0x000003E8, 31, 0, CSR_RW, 0x00000000 },
	{ "OCCAPCFG1", 0x000003E8, 31, 0, CSR_RW, 0x00000000 },
	// WORD occapstat1
	{ "field_occapstat1", 0x000003EC, 31, 0, CSR_RW, 0x00000000 },
	{ "OCCAPSTAT1", 0x000003EC, 31, 0, CSR_RW, 0x00000000 },
	// WORD deratestat
	{ "field_deratestat", 0x000003F0, 31, 0, CSR_RW, 0x00000000 },
	{ "DERATESTAT", 0x000003F0, 31, 0, CSR_RW, 0x00000000 },
	// WORD pstat
	{ "field_pstat", 0x000003FC, 31, 0, CSR_RW, 0x00000000 },
	{ "PSTAT", 0x000003FC, 31, 0, CSR_RW, 0x00000000 },
	// WORD pccfg
	{ "field_pccfg", 0x00000400, 31, 0, CSR_RW, 0x00000000 },
	{ "PCCFG", 0x00000400, 31, 0, CSR_RW, 0x00000000 },
	// WORD pcfgr_0
	{ "field_pcfgr_0", 0x00000404, 31, 0, CSR_RW, 0x00000000 },
	{ "PCFGR_0", 0x00000404, 31, 0, CSR_RW, 0x00000000 },
	// WORD pcfgw_0
	{ "field_pcfgw_0", 0x00000408, 31, 0, CSR_RW, 0x00000000 },
	{ "PCFGW_0", 0x00000408, 31, 0, CSR_RW, 0x00000000 },
	// WORD pcfgc_0
	{ "field_pcfgc_0", 0x0000040C, 31, 0, CSR_RW, 0x00000000 },
	{ "PCFGC_0", 0x0000040C, 31, 0, CSR_RW, 0x00000000 },
	// WORD pcfgidmaskch0_0
	{ "field_pcfgidmaskch0_0", 0x00000410, 31, 0, CSR_RW, 0x00000000 },
	{ "PCFGIDMASKCH0_0", 0x00000410, 31, 0, CSR_RW, 0x00000000 },
	// WORD pcfgidvaluech0_0
	{ "field_pcfgidvaluech0_0", 0x00000414, 31, 0, CSR_RW, 0x00000000 },
	{ "PCFGIDVALUECH0_0", 0x00000414, 31, 0, CSR_RW, 0x00000000 },
	// WORD pcfgidmaskch1_0
	{ "field_pcfgidmaskch1_0", 0x00000418, 31, 0, CSR_RW, 0x00000000 },
	{ "PCFGIDMASKCH1_0", 0x00000418, 31, 0, CSR_RW, 0x00000000 },
	// WORD pcfgidvaluech1_0
	{ "field_pcfgidvaluech1_0", 0x0000041C, 31, 0, CSR_RW, 0x00000000 },
	{ "PCFGIDVALUECH1_0", 0x0000041C, 31, 0, CSR_RW, 0x00000000 },
	// WORD pcfgidmaskch2_0
	{ "field_pcfgidmaskch2_0", 0x00000420, 31, 0, CSR_RW, 0x00000000 },
	{ "PCFGIDMASKCH2_0", 0x00000420, 31, 0, CSR_RW, 0x00000000 },
	// WORD pcfgidvaluech2_0
	{ "field_pcfgidvaluech2_0", 0x00000424, 31, 0, CSR_RW, 0x00000000 },
	{ "PCFGIDVALUECH2_0", 0x00000424, 31, 0, CSR_RW, 0x00000000 },
	// WORD pcfgidmaskch3_0
	{ "field_pcfgidmaskch3_0", 0x00000428, 31, 0, CSR_RW, 0x00000000 },
	{ "PCFGIDMASKCH3_0", 0x00000428, 31, 0, CSR_RW, 0x00000000 },
	// WORD pcfgidvaluech3_0
	{ "field_pcfgidvaluech3_0", 0x0000042C, 31, 0, CSR_RW, 0x00000000 },
	{ "PCFGIDVALUECH3_0", 0x0000042C, 31, 0, CSR_RW, 0x00000000 },
	// WORD pcfgidmaskch4_0
	{ "field_pcfgidmaskch4_0", 0x00000430, 31, 0, CSR_RW, 0x00000000 },
	{ "PCFGIDMASKCH4_0", 0x00000430, 31, 0, CSR_RW, 0x00000000 },
	// WORD pcfgidvaluech4_0
	{ "field_pcfgidvaluech4_0", 0x00000434, 31, 0, CSR_RW, 0x00000000 },
	{ "PCFGIDVALUECH4_0", 0x00000434, 31, 0, CSR_RW, 0x00000000 },
	// WORD pcfgidmaskch5_0
	{ "field_pcfgidmaskch5_0", 0x00000438, 31, 0, CSR_RW, 0x00000000 },
	{ "PCFGIDMASKCH5_0", 0x00000438, 31, 0, CSR_RW, 0x00000000 },
	// WORD pcfgidvaluech5_0
	{ "field_pcfgidvaluech5_0", 0x0000043C, 31, 0, CSR_RW, 0x00000000 },
	{ "PCFGIDVALUECH5_0", 0x0000043C, 31, 0, CSR_RW, 0x00000000 },
	// WORD pcfgidmaskch6_0
	{ "field_pcfgidmaskch6_0", 0x00000440, 31, 0, CSR_RW, 0x00000000 },
	{ "PCFGIDMASKCH6_0", 0x00000440, 31, 0, CSR_RW, 0x00000000 },
	// WORD pcfgidvaluech6_0
	{ "field_pcfgidvaluech6_0", 0x00000444, 31, 0, CSR_RW, 0x00000000 },
	{ "PCFGIDVALUECH6_0", 0x00000444, 31, 0, CSR_RW, 0x00000000 },
	// WORD pcfgidmaskch7_0
	{ "field_pcfgidmaskch7_0", 0x00000448, 31, 0, CSR_RW, 0x00000000 },
	{ "PCFGIDMASKCH7_0", 0x00000448, 31, 0, CSR_RW, 0x00000000 },
	// WORD pcfgidvaluech7_0
	{ "field_pcfgidvaluech7_0", 0x0000044C, 31, 0, CSR_RW, 0x00000000 },
	{ "PCFGIDVALUECH7_0", 0x0000044C, 31, 0, CSR_RW, 0x00000000 },
	// WORD pcfgidmaskch8_0
	{ "field_pcfgidmaskch8_0", 0x00000450, 31, 0, CSR_RW, 0x00000000 },
	{ "PCFGIDMASKCH8_0", 0x00000450, 31, 0, CSR_RW, 0x00000000 },
	// WORD pcfgidvaluech8_0
	{ "field_pcfgidvaluech8_0", 0x00000454, 31, 0, CSR_RW, 0x00000000 },
	{ "PCFGIDVALUECH8_0", 0x00000454, 31, 0, CSR_RW, 0x00000000 },
	// WORD pcfgidmaskch9_0
	{ "field_pcfgidmaskch9_0", 0x00000458, 31, 0, CSR_RW, 0x00000000 },
	{ "PCFGIDMASKCH9_0", 0x00000458, 31, 0, CSR_RW, 0x00000000 },
	// WORD pcfgidvaluech9_0
	{ "field_pcfgidvaluech9_0", 0x0000045C, 31, 0, CSR_RW, 0x00000000 },
	{ "PCFGIDVALUECH9_0", 0x0000045C, 31, 0, CSR_RW, 0x00000000 },
	// WORD pcfgidmaskch10_0
	{ "field_pcfgidmaskch10_0", 0x00000460, 31, 0, CSR_RW, 0x00000000 },
	{ "PCFGIDMASKCH10_0", 0x00000460, 31, 0, CSR_RW, 0x00000000 },
	// WORD pcfgidvaluech10_0
	{ "field_pcfgidvaluech10_0", 0x00000464, 31, 0, CSR_RW, 0x00000000 },
	{ "PCFGIDVALUECH10_0", 0x00000464, 31, 0, CSR_RW, 0x00000000 },
	// WORD pcfgidmaskch11_0
	{ "field_pcfgidmaskch11_0", 0x00000468, 31, 0, CSR_RW, 0x00000000 },
	{ "PCFGIDMASKCH11_0", 0x00000468, 31, 0, CSR_RW, 0x00000000 },
	// WORD pcfgidvaluech11_0
	{ "field_pcfgidvaluech11_0", 0x0000046C, 31, 0, CSR_RW, 0x00000000 },
	{ "PCFGIDVALUECH11_0", 0x0000046C, 31, 0, CSR_RW, 0x00000000 },
	// WORD pcfgidmaskch12_0
	{ "field_pcfgidmaskch12_0", 0x00000470, 31, 0, CSR_RW, 0x00000000 },
	{ "PCFGIDMASKCH12_0", 0x00000470, 31, 0, CSR_RW, 0x00000000 },
	// WORD pcfgidvaluech12_0
	{ "field_pcfgidvaluech12_0", 0x00000474, 31, 0, CSR_RW, 0x00000000 },
	{ "PCFGIDVALUECH12_0", 0x00000474, 31, 0, CSR_RW, 0x00000000 },
	// WORD pcfgidmaskch13_0
	{ "field_pcfgidmaskch13_0", 0x00000478, 31, 0, CSR_RW, 0x00000000 },
	{ "PCFGIDMASKCH13_0", 0x00000478, 31, 0, CSR_RW, 0x00000000 },
	// WORD pcfgidvaluech13_0
	{ "field_pcfgidvaluech13_0", 0x0000047C, 31, 0, CSR_RW, 0x00000000 },
	{ "PCFGIDVALUECH13_0", 0x0000047C, 31, 0, CSR_RW, 0x00000000 },
	// WORD pcfgidmaskch14_0
	{ "field_pcfgidmaskch14_0", 0x00000480, 31, 0, CSR_RW, 0x00000000 },
	{ "PCFGIDMASKCH14_0", 0x00000480, 31, 0, CSR_RW, 0x00000000 },
	// WORD pcfgidvaluech14_0
	{ "field_pcfgidvaluech14_0", 0x00000484, 31, 0, CSR_RW, 0x00000000 },
	{ "PCFGIDVALUECH14_0", 0x00000484, 31, 0, CSR_RW, 0x00000000 },
	// WORD pcfgidmaskch15_0
	{ "field_pcfgidmaskch15_0", 0x00000488, 31, 0, CSR_RW, 0x00000000 },
	{ "PCFGIDMASKCH15_0", 0x00000488, 31, 0, CSR_RW, 0x00000000 },
	// WORD pcfgidvaluech15_0
	{ "field_pcfgidvaluech15_0", 0x0000048C, 31, 0, CSR_RW, 0x00000000 },
	{ "PCFGIDVALUECH15_0", 0x0000048C, 31, 0, CSR_RW, 0x00000000 },
	// WORD pctrl_0
	{ "field_pctrl_0", 0x00000490, 31, 0, CSR_RW, 0x00000000 },
	{ "PCTRL_0", 0x00000490, 31, 0, CSR_RW, 0x00000000 },
	// WORD pcfgqos0_0
	{ "field_pcfgqos0_0", 0x00000494, 31, 0, CSR_RW, 0x00000000 },
	{ "PCFGQOS0_0", 0x00000494, 31, 0, CSR_RW, 0x00000000 },
	// WORD pcfgqos1_0
	{ "field_pcfgqos1_0", 0x00000498, 31, 0, CSR_RW, 0x00000000 },
	{ "PCFGQOS1_0", 0x00000498, 31, 0, CSR_RW, 0x00000000 },
	// WORD pcfgwqos0_0
	{ "field_pcfgwqos0_0", 0x0000049C, 31, 0, CSR_RW, 0x00000000 },
	{ "PCFGWQOS0_0", 0x0000049C, 31, 0, CSR_RW, 0x00000000 },
	// WORD pcfgwqos1_0
	{ "field_pcfgwqos1_0", 0x000004A0, 31, 0, CSR_RW, 0x00000000 },
	{ "PCFGWQOS1_0", 0x000004A0, 31, 0, CSR_RW, 0x00000000 },
	// WORD pcfgr_1
	{ "field_pcfgr_1", 0x000004B4, 31, 0, CSR_RW, 0x00000000 },
	{ "PCFGR_1", 0x000004B4, 31, 0, CSR_RW, 0x00000000 },
	// WORD pcfgw_1
	{ "field_pcfgw_1", 0x000004B8, 31, 0, CSR_RW, 0x00000000 },
	{ "PCFGW_1", 0x000004B8, 31, 0, CSR_RW, 0x00000000 },
	// WORD pcfgc_1
	{ "field_pcfgc_1", 0x000004BC, 31, 0, CSR_RW, 0x00000000 },
	{ "PCFGC_1", 0x000004BC, 31, 0, CSR_RW, 0x00000000 },
	// WORD pcfgidmaskch0_1
	{ "field_pcfgidmaskch0_1", 0x000004C0, 31, 0, CSR_RW, 0x00000000 },
	{ "PCFGIDMASKCH0_1", 0x000004C0, 31, 0, CSR_RW, 0x00000000 },
	// WORD pcfgidvaluech0_1
	{ "field_pcfgidvaluech0_1", 0x000004C4, 31, 0, CSR_RW, 0x00000000 },
	{ "PCFGIDVALUECH0_1", 0x000004C4, 31, 0, CSR_RW, 0x00000000 },
	// WORD pcfgidmaskch1_1
	{ "field_pcfgidmaskch1_1", 0x000004C8, 31, 0, CSR_RW, 0x00000000 },
	{ "PCFGIDMASKCH1_1", 0x000004C8, 31, 0, CSR_RW, 0x00000000 },
	// WORD pcfgidvaluech1_1
	{ "field_pcfgidvaluech1_1", 0x000004CC, 31, 0, CSR_RW, 0x00000000 },
	{ "PCFGIDVALUECH1_1", 0x000004CC, 31, 0, CSR_RW, 0x00000000 },
	// WORD pcfgidmaskch2_1
	{ "field_pcfgidmaskch2_1", 0x000004D0, 31, 0, CSR_RW, 0x00000000 },
	{ "PCFGIDMASKCH2_1", 0x000004D0, 31, 0, CSR_RW, 0x00000000 },
	// WORD pcfgidvaluech2_1
	{ "field_pcfgidvaluech2_1", 0x000004D4, 31, 0, CSR_RW, 0x00000000 },
	{ "PCFGIDVALUECH2_1", 0x000004D4, 31, 0, CSR_RW, 0x00000000 },
	// WORD pcfgidmaskch3_1
	{ "field_pcfgidmaskch3_1", 0x000004D8, 31, 0, CSR_RW, 0x00000000 },
	{ "PCFGIDMASKCH3_1", 0x000004D8, 31, 0, CSR_RW, 0x00000000 },
	// WORD pcfgidvaluech3_1
	{ "field_pcfgidvaluech3_1", 0x000004DC, 31, 0, CSR_RW, 0x00000000 },
	{ "PCFGIDVALUECH3_1", 0x000004DC, 31, 0, CSR_RW, 0x00000000 },
	// WORD pcfgidmaskch4_1
	{ "field_pcfgidmaskch4_1", 0x000004E0, 31, 0, CSR_RW, 0x00000000 },
	{ "PCFGIDMASKCH4_1", 0x000004E0, 31, 0, CSR_RW, 0x00000000 },
	// WORD pcfgidvaluech4_1
	{ "field_pcfgidvaluech4_1", 0x000004E4, 31, 0, CSR_RW, 0x00000000 },
	{ "PCFGIDVALUECH4_1", 0x000004E4, 31, 0, CSR_RW, 0x00000000 },
	// WORD pcfgidmaskch5_1
	{ "field_pcfgidmaskch5_1", 0x000004E8, 31, 0, CSR_RW, 0x00000000 },
	{ "PCFGIDMASKCH5_1", 0x000004E8, 31, 0, CSR_RW, 0x00000000 },
	// WORD pcfgidvaluech5_1
	{ "field_pcfgidvaluech5_1", 0x000004EC, 31, 0, CSR_RW, 0x00000000 },
	{ "PCFGIDVALUECH5_1", 0x000004EC, 31, 0, CSR_RW, 0x00000000 },
	// WORD pcfgidmaskch6_1
	{ "field_pcfgidmaskch6_1", 0x000004F0, 31, 0, CSR_RW, 0x00000000 },
	{ "PCFGIDMASKCH6_1", 0x000004F0, 31, 0, CSR_RW, 0x00000000 },
	// WORD pcfgidvaluech6_1
	{ "field_pcfgidvaluech6_1", 0x000004F4, 31, 0, CSR_RW, 0x00000000 },
	{ "PCFGIDVALUECH6_1", 0x000004F4, 31, 0, CSR_RW, 0x00000000 },
	// WORD pcfgidmaskch7_1
	{ "field_pcfgidmaskch7_1", 0x000004F8, 31, 0, CSR_RW, 0x00000000 },
	{ "PCFGIDMASKCH7_1", 0x000004F8, 31, 0, CSR_RW, 0x00000000 },
	// WORD pcfgidvaluech7_1
	{ "field_pcfgidvaluech7_1", 0x000004FC, 31, 0, CSR_RW, 0x00000000 },
	{ "PCFGIDVALUECH7_1", 0x000004FC, 31, 0, CSR_RW, 0x00000000 },
	// WORD pcfgidmaskch8_1
	{ "field_pcfgidmaskch8_1", 0x00000500, 31, 0, CSR_RW, 0x00000000 },
	{ "PCFGIDMASKCH8_1", 0x00000500, 31, 0, CSR_RW, 0x00000000 },
	// WORD pcfgidvaluech8_1
	{ "field_pcfgidvaluech8_1", 0x00000504, 31, 0, CSR_RW, 0x00000000 },
	{ "PCFGIDVALUECH8_1", 0x00000504, 31, 0, CSR_RW, 0x00000000 },
	// WORD pcfgidmaskch9_1
	{ "field_pcfgidmaskch9_1", 0x00000508, 31, 0, CSR_RW, 0x00000000 },
	{ "PCFGIDMASKCH9_1", 0x00000508, 31, 0, CSR_RW, 0x00000000 },
	// WORD pcfgidvaluech9_1
	{ "field_pcfgidvaluech9_1", 0x0000050C, 31, 0, CSR_RW, 0x00000000 },
	{ "PCFGIDVALUECH9_1", 0x0000050C, 31, 0, CSR_RW, 0x00000000 },
	// WORD pcfgidmaskch10_1
	{ "field_pcfgidmaskch10_1", 0x00000510, 31, 0, CSR_RW, 0x00000000 },
	{ "PCFGIDMASKCH10_1", 0x00000510, 31, 0, CSR_RW, 0x00000000 },
	// WORD pcfgidvaluech10_1
	{ "field_pcfgidvaluech10_1", 0x00000514, 31, 0, CSR_RW, 0x00000000 },
	{ "PCFGIDVALUECH10_1", 0x00000514, 31, 0, CSR_RW, 0x00000000 },
	// WORD pcfgidmaskch11_1
	{ "field_pcfgidmaskch11_1", 0x00000518, 31, 0, CSR_RW, 0x00000000 },
	{ "PCFGIDMASKCH11_1", 0x00000518, 31, 0, CSR_RW, 0x00000000 },
	// WORD pcfgidvaluech11_1
	{ "field_pcfgidvaluech11_1", 0x0000051C, 31, 0, CSR_RW, 0x00000000 },
	{ "PCFGIDVALUECH11_1", 0x0000051C, 31, 0, CSR_RW, 0x00000000 },
	// WORD pcfgidmaskch12_1
	{ "field_pcfgidmaskch12_1", 0x00000520, 31, 0, CSR_RW, 0x00000000 },
	{ "PCFGIDMASKCH12_1", 0x00000520, 31, 0, CSR_RW, 0x00000000 },
	// WORD pcfgidvaluech12_1
	{ "field_pcfgidvaluech12_1", 0x00000524, 31, 0, CSR_RW, 0x00000000 },
	{ "PCFGIDVALUECH12_1", 0x00000524, 31, 0, CSR_RW, 0x00000000 },
	// WORD pcfgidmaskch13_1
	{ "field_pcfgidmaskch13_1", 0x00000528, 31, 0, CSR_RW, 0x00000000 },
	{ "PCFGIDMASKCH13_1", 0x00000528, 31, 0, CSR_RW, 0x00000000 },
	// WORD pcfgidvaluech13_1
	{ "field_pcfgidvaluech13_1", 0x0000052C, 31, 0, CSR_RW, 0x00000000 },
	{ "PCFGIDVALUECH13_1", 0x0000052C, 31, 0, CSR_RW, 0x00000000 },
	// WORD pcfgidmaskch14_1
	{ "field_pcfgidmaskch14_1", 0x00000530, 31, 0, CSR_RW, 0x00000000 },
	{ "PCFGIDMASKCH14_1", 0x00000530, 31, 0, CSR_RW, 0x00000000 },
	// WORD pcfgidvaluech14_1
	{ "field_pcfgidvaluech14_1", 0x00000534, 31, 0, CSR_RW, 0x00000000 },
	{ "PCFGIDVALUECH14_1", 0x00000534, 31, 0, CSR_RW, 0x00000000 },
	// WORD pcfgidmaskch15_1
	{ "field_pcfgidmaskch15_1", 0x00000538, 31, 0, CSR_RW, 0x00000000 },
	{ "PCFGIDMASKCH15_1", 0x00000538, 31, 0, CSR_RW, 0x00000000 },
	// WORD pcfgidvaluech15_1
	{ "field_pcfgidvaluech15_1", 0x0000053C, 31, 0, CSR_RW, 0x00000000 },
	{ "PCFGIDVALUECH15_1", 0x0000053C, 31, 0, CSR_RW, 0x00000000 },
	// WORD pctrl_1
	{ "field_pctrl_1", 0x00000540, 31, 0, CSR_RW, 0x00000000 },
	{ "PCTRL_1", 0x00000540, 31, 0, CSR_RW, 0x00000000 },
	// WORD pcfgqos0_1
	{ "field_pcfgqos0_1", 0x00000544, 31, 0, CSR_RW, 0x00000000 },
	{ "PCFGQOS0_1", 0x00000544, 31, 0, CSR_RW, 0x00000000 },
	// WORD pcfgqos1_1
	{ "field_pcfgqos1_1", 0x00000548, 31, 0, CSR_RW, 0x00000000 },
	{ "PCFGQOS1_1", 0x00000548, 31, 0, CSR_RW, 0x00000000 },
	// WORD pcfgwqos0_1
	{ "field_pcfgwqos0_1", 0x0000054C, 31, 0, CSR_RW, 0x00000000 },
	{ "PCFGWQOS0_1", 0x0000054C, 31, 0, CSR_RW, 0x00000000 },
	// WORD pcfgwqos1_1
	{ "field_pcfgwqos1_1", 0x00000550, 31, 0, CSR_RW, 0x00000000 },
	{ "PCFGWQOS1_1", 0x00000550, 31, 0, CSR_RW, 0x00000000 },
	// WORD pcfgr_2
	{ "field_pcfgr_2", 0x00000564, 31, 0, CSR_RW, 0x00000000 },
	{ "PCFGR_2", 0x00000564, 31, 0, CSR_RW, 0x00000000 },
	// WORD pcfgw_2
	{ "field_pcfgw_2", 0x00000568, 31, 0, CSR_RW, 0x00000000 },
	{ "PCFGW_2", 0x00000568, 31, 0, CSR_RW, 0x00000000 },
	// WORD pcfgc_2
	{ "field_pcfgc_2", 0x0000056C, 31, 0, CSR_RW, 0x00000000 },
	{ "PCFGC_2", 0x0000056C, 31, 0, CSR_RW, 0x00000000 },
	// WORD pcfgidmaskch0_2
	{ "field_pcfgidmaskch0_2", 0x00000570, 31, 0, CSR_RW, 0x00000000 },
	{ "PCFGIDMASKCH0_2", 0x00000570, 31, 0, CSR_RW, 0x00000000 },
	// WORD pcfgidvaluech0_2
	{ "field_pcfgidvaluech0_2", 0x00000574, 31, 0, CSR_RW, 0x00000000 },
	{ "PCFGIDVALUECH0_2", 0x00000574, 31, 0, CSR_RW, 0x00000000 },
	// WORD pcfgidmaskch1_2
	{ "field_pcfgidmaskch1_2", 0x00000578, 31, 0, CSR_RW, 0x00000000 },
	{ "PCFGIDMASKCH1_2", 0x00000578, 31, 0, CSR_RW, 0x00000000 },
	// WORD pcfgidvaluech1_2
	{ "field_pcfgidvaluech1_2", 0x0000057C, 31, 0, CSR_RW, 0x00000000 },
	{ "PCFGIDVALUECH1_2", 0x0000057C, 31, 0, CSR_RW, 0x00000000 },
	// WORD pcfgidmaskch2_2
	{ "field_pcfgidmaskch2_2", 0x00000580, 31, 0, CSR_RW, 0x00000000 },
	{ "PCFGIDMASKCH2_2", 0x00000580, 31, 0, CSR_RW, 0x00000000 },
	// WORD pcfgidvaluech2_2
	{ "field_pcfgidvaluech2_2", 0x00000584, 31, 0, CSR_RW, 0x00000000 },
	{ "PCFGIDVALUECH2_2", 0x00000584, 31, 0, CSR_RW, 0x00000000 },
	// WORD pcfgidmaskch3_2
	{ "field_pcfgidmaskch3_2", 0x00000588, 31, 0, CSR_RW, 0x00000000 },
	{ "PCFGIDMASKCH3_2", 0x00000588, 31, 0, CSR_RW, 0x00000000 },
	// WORD pcfgidvaluech3_2
	{ "field_pcfgidvaluech3_2", 0x0000058C, 31, 0, CSR_RW, 0x00000000 },
	{ "PCFGIDVALUECH3_2", 0x0000058C, 31, 0, CSR_RW, 0x00000000 },
	// WORD pcfgidmaskch4_2
	{ "field_pcfgidmaskch4_2", 0x00000590, 31, 0, CSR_RW, 0x00000000 },
	{ "PCFGIDMASKCH4_2", 0x00000590, 31, 0, CSR_RW, 0x00000000 },
	// WORD pcfgidvaluech4_2
	{ "field_pcfgidvaluech4_2", 0x00000594, 31, 0, CSR_RW, 0x00000000 },
	{ "PCFGIDVALUECH4_2", 0x00000594, 31, 0, CSR_RW, 0x00000000 },
	// WORD pcfgidmaskch5_2
	{ "field_pcfgidmaskch5_2", 0x00000598, 31, 0, CSR_RW, 0x00000000 },
	{ "PCFGIDMASKCH5_2", 0x00000598, 31, 0, CSR_RW, 0x00000000 },
	// WORD pcfgidvaluech5_2
	{ "field_pcfgidvaluech5_2", 0x0000059C, 31, 0, CSR_RW, 0x00000000 },
	{ "PCFGIDVALUECH5_2", 0x0000059C, 31, 0, CSR_RW, 0x00000000 },
	// WORD pcfgidmaskch6_2
	{ "field_pcfgidmaskch6_2", 0x000005A0, 31, 0, CSR_RW, 0x00000000 },
	{ "PCFGIDMASKCH6_2", 0x000005A0, 31, 0, CSR_RW, 0x00000000 },
	// WORD pcfgidvaluech6_2
	{ "field_pcfgidvaluech6_2", 0x000005A4, 31, 0, CSR_RW, 0x00000000 },
	{ "PCFGIDVALUECH6_2", 0x000005A4, 31, 0, CSR_RW, 0x00000000 },
	// WORD pcfgidmaskch7_2
	{ "field_pcfgidmaskch7_2", 0x000005A8, 31, 0, CSR_RW, 0x00000000 },
	{ "PCFGIDMASKCH7_2", 0x000005A8, 31, 0, CSR_RW, 0x00000000 },
	// WORD pcfgidvaluech7_2
	{ "field_pcfgidvaluech7_2", 0x000005AC, 31, 0, CSR_RW, 0x00000000 },
	{ "PCFGIDVALUECH7_2", 0x000005AC, 31, 0, CSR_RW, 0x00000000 },
	// WORD pcfgidmaskch8_2
	{ "field_pcfgidmaskch8_2", 0x000005B0, 31, 0, CSR_RW, 0x00000000 },
	{ "PCFGIDMASKCH8_2", 0x000005B0, 31, 0, CSR_RW, 0x00000000 },
	// WORD pcfgidvaluech8_2
	{ "field_pcfgidvaluech8_2", 0x000005B4, 31, 0, CSR_RW, 0x00000000 },
	{ "PCFGIDVALUECH8_2", 0x000005B4, 31, 0, CSR_RW, 0x00000000 },
	// WORD pcfgidmaskch9_2
	{ "field_pcfgidmaskch9_2", 0x000005B8, 31, 0, CSR_RW, 0x00000000 },
	{ "PCFGIDMASKCH9_2", 0x000005B8, 31, 0, CSR_RW, 0x00000000 },
	// WORD pcfgidvaluech9_2
	{ "field_pcfgidvaluech9_2", 0x000005BC, 31, 0, CSR_RW, 0x00000000 },
	{ "PCFGIDVALUECH9_2", 0x000005BC, 31, 0, CSR_RW, 0x00000000 },
	// WORD pcfgidmaskch10_2
	{ "field_pcfgidmaskch10_2", 0x000005C0, 31, 0, CSR_RW, 0x00000000 },
	{ "PCFGIDMASKCH10_2", 0x000005C0, 31, 0, CSR_RW, 0x00000000 },
	// WORD pcfgidvaluech10_2
	{ "field_pcfgidvaluech10_2", 0x000005C4, 31, 0, CSR_RW, 0x00000000 },
	{ "PCFGIDVALUECH10_2", 0x000005C4, 31, 0, CSR_RW, 0x00000000 },
	// WORD pcfgidmaskch11_2
	{ "field_pcfgidmaskch11_2", 0x000005C8, 31, 0, CSR_RW, 0x00000000 },
	{ "PCFGIDMASKCH11_2", 0x000005C8, 31, 0, CSR_RW, 0x00000000 },
	// WORD pcfgidvaluech11_2
	{ "field_pcfgidvaluech11_2", 0x000005CC, 31, 0, CSR_RW, 0x00000000 },
	{ "PCFGIDVALUECH11_2", 0x000005CC, 31, 0, CSR_RW, 0x00000000 },
	// WORD pcfgidmaskch12_2
	{ "field_pcfgidmaskch12_2", 0x000005D0, 31, 0, CSR_RW, 0x00000000 },
	{ "PCFGIDMASKCH12_2", 0x000005D0, 31, 0, CSR_RW, 0x00000000 },
	// WORD pcfgidvaluech12_2
	{ "field_pcfgidvaluech12_2", 0x000005D4, 31, 0, CSR_RW, 0x00000000 },
	{ "PCFGIDVALUECH12_2", 0x000005D4, 31, 0, CSR_RW, 0x00000000 },
	// WORD pcfgidmaskch13_2
	{ "field_pcfgidmaskch13_2", 0x000005D8, 31, 0, CSR_RW, 0x00000000 },
	{ "PCFGIDMASKCH13_2", 0x000005D8, 31, 0, CSR_RW, 0x00000000 },
	// WORD pcfgidvaluech13_2
	{ "field_pcfgidvaluech13_2", 0x000005DC, 31, 0, CSR_RW, 0x00000000 },
	{ "PCFGIDVALUECH13_2", 0x000005DC, 31, 0, CSR_RW, 0x00000000 },
	// WORD pcfgidmaskch14_2
	{ "field_pcfgidmaskch14_2", 0x000005E0, 31, 0, CSR_RW, 0x00000000 },
	{ "PCFGIDMASKCH14_2", 0x000005E0, 31, 0, CSR_RW, 0x00000000 },
	// WORD pcfgidvaluech14_2
	{ "field_pcfgidvaluech14_2", 0x000005E4, 31, 0, CSR_RW, 0x00000000 },
	{ "PCFGIDVALUECH14_2", 0x000005E4, 31, 0, CSR_RW, 0x00000000 },
	// WORD pcfgidmaskch15_2
	{ "field_pcfgidmaskch15_2", 0x000005E8, 31, 0, CSR_RW, 0x00000000 },
	{ "PCFGIDMASKCH15_2", 0x000005E8, 31, 0, CSR_RW, 0x00000000 },
	// WORD pcfgidvaluech15_2
	{ "field_pcfgidvaluech15_2", 0x000005EC, 31, 0, CSR_RW, 0x00000000 },
	{ "PCFGIDVALUECH15_2", 0x000005EC, 31, 0, CSR_RW, 0x00000000 },
	// WORD pctrl_2
	{ "field_pctrl_2", 0x000005F0, 31, 0, CSR_RW, 0x00000000 },
	{ "PCTRL_2", 0x000005F0, 31, 0, CSR_RW, 0x00000000 },
	// WORD pcfgqos0_2
	{ "field_pcfgqos0_2", 0x000005F4, 31, 0, CSR_RW, 0x00000000 },
	{ "PCFGQOS0_2", 0x000005F4, 31, 0, CSR_RW, 0x00000000 },
	// WORD pcfgqos1_2
	{ "field_pcfgqos1_2", 0x000005F8, 31, 0, CSR_RW, 0x00000000 },
	{ "PCFGQOS1_2", 0x000005F8, 31, 0, CSR_RW, 0x00000000 },
	// WORD pcfgwqos0_2
	{ "field_pcfgwqos0_2", 0x000005FC, 31, 0, CSR_RW, 0x00000000 },
	{ "PCFGWQOS0_2", 0x000005FC, 31, 0, CSR_RW, 0x00000000 },
	// WORD pcfgwqos1_2
	{ "field_pcfgwqos1_2", 0x00000600, 31, 0, CSR_RW, 0x00000000 },
	{ "PCFGWQOS1_2", 0x00000600, 31, 0, CSR_RW, 0x00000000 },
	// WORD sarbase0
	{ "field_sarbase0", 0x00000F04, 31, 0, CSR_RW, 0x00000000 },
	{ "SARBASE0", 0x00000F04, 31, 0, CSR_RW, 0x00000000 },
	// WORD sarsize0
	{ "field_sarsize0", 0x00000F08, 31, 0, CSR_RW, 0x00000000 },
	{ "SARSIZE0", 0x00000F08, 31, 0, CSR_RW, 0x00000000 },
	// WORD sarbase1
	{ "field_sarbase1", 0x00000F0C, 31, 0, CSR_RW, 0x00000000 },
	{ "SARBASE1", 0x00000F0C, 31, 0, CSR_RW, 0x00000000 },
	// WORD sarsize1
	{ "field_sarsize1", 0x00000F10, 31, 0, CSR_RW, 0x00000000 },
	{ "SARSIZE1", 0x00000F10, 31, 0, CSR_RW, 0x00000000 },
	// WORD sarbase2
	{ "field_sarbase2", 0x00000F14, 31, 0, CSR_RW, 0x00000000 },
	{ "SARBASE2", 0x00000F14, 31, 0, CSR_RW, 0x00000000 },
	// WORD sarsize2
	{ "field_sarsize2", 0x00000F18, 31, 0, CSR_RW, 0x00000000 },
	{ "SARSIZE2", 0x00000F18, 31, 0, CSR_RW, 0x00000000 },
	// WORD sarbase3
	{ "field_sarbase3", 0x00000F1C, 31, 0, CSR_RW, 0x00000000 },
	{ "SARBASE3", 0x00000F1C, 31, 0, CSR_RW, 0x00000000 },
	// WORD sarsize3
	{ "field_sarsize3", 0x00000F20, 31, 0, CSR_RW, 0x00000000 },
	{ "SARSIZE3", 0x00000F20, 31, 0, CSR_RW, 0x00000000 },
	// WORD sbrctl
	{ "field_sbrctl", 0x00000F24, 31, 0, CSR_RW, 0x00000000 },
	{ "SBRCTL", 0x00000F24, 31, 0, CSR_RW, 0x00000000 },
	// WORD sbrstat
	{ "field_sbrstat", 0x00000F28, 31, 0, CSR_RW, 0x00000000 },
	{ "SBRSTAT", 0x00000F28, 31, 0, CSR_RW, 0x00000000 },
	// WORD sbrwdata0
	{ "field_sbrwdata0", 0x00000F2C, 31, 0, CSR_RW, 0x00000000 },
	{ "SBRWDATA0", 0x00000F2C, 31, 0, CSR_RW, 0x00000000 },
	// WORD sbrwdata1
	{ "field_sbrwdata1", 0x00000F30, 31, 0, CSR_RW, 0x00000000 },
	{ "SBRWDATA1", 0x00000F30, 31, 0, CSR_RW, 0x00000000 },
	// WORD pdch
	{ "field_pdch", 0x00000F34, 31, 0, CSR_RW, 0x00000000 },
	{ "PDCH", 0x00000F34, 31, 0, CSR_RW, 0x00000000 },
	// WORD sbrstart0
	{ "field_sbrstart0", 0x00000F38, 31, 0, CSR_RW, 0x00000000 },
	{ "SBRSTART0", 0x00000F38, 31, 0, CSR_RW, 0x00000000 },
	// WORD sbrstart1
	{ "field_sbrstart1", 0x00000F3C, 31, 0, CSR_RW, 0x00000000 },
	{ "SBRSTART1", 0x00000F3C, 31, 0, CSR_RW, 0x00000000 },
	// WORD sbrrange0
	{ "field_sbrrange0", 0x00000F40, 31, 0, CSR_RW, 0x00000000 },
	{ "SBRRANGE0", 0x00000F40, 31, 0, CSR_RW, 0x00000000 },
	// WORD sbrrange1
	{ "field_sbrrange1", 0x00000F44, 31, 0, CSR_RW, 0x00000000 },
	{ "SBRRANGE1", 0x00000F44, 31, 0, CSR_RW, 0x00000000 },
	// WORD sbrstart0dch1
	{ "field_sbrstart0dch1", 0x00000F48, 31, 0, CSR_RW, 0x00000000 },
	{ "SBRSTART0DCH1", 0x00000F48, 31, 0, CSR_RW, 0x00000000 },
	// WORD sbrstart1dch1
	{ "field_sbrstart1dch1", 0x00000F4C, 31, 0, CSR_RW, 0x00000000 },
	{ "SBRSTART1DCH1", 0x00000F4C, 31, 0, CSR_RW, 0x00000000 },
	// WORD sbrrange0dch1
	{ "field_sbrrange0dch1", 0x00000F50, 31, 0, CSR_RW, 0x00000000 },
	{ "SBRRANGE0DCH1", 0x00000F50, 31, 0, CSR_RW, 0x00000000 },
	// WORD sbrrange1dch1
	{ "field_sbrrange1dch1", 0x00000F54, 31, 0, CSR_RW, 0x00000000 },
	{ "SBRRANGE1DCH1", 0x00000F54, 31, 0, CSR_RW, 0x00000000 },
	// WORD umctl2_ver_number
	{ "field_umctl2_ver_number", 0x00000FF0, 31, 0, CSR_RW, 0x00000000 },
	{ "UMCTL2_VER_NUMBER", 0x00000FF0, 31, 0, CSR_RW, 0x00000000 },
	// WORD umctl2_ver_type
	{ "field_umctl2_ver_type", 0x00000FF4, 31, 0, CSR_RW, 0x00000000 },
	{ "UMCTL2_VER_TYPE", 0x00000FF4, 31, 0, CSR_RW, 0x00000000 },
	// end of table
	{ 0, 0, 0, 0, 0, 0 }
};

#endif // CSR_TABLE_DRAMCONTROLLER_H_
