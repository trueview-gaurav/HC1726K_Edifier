/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef CSR_TABLE_DDRPHY_H_
#define CSR_TABLE_DDRPHY_H_

#include <stdint.h>

CsrFieldEntry csr_field_table_ddrphy[] = {
	// WORD ridr
	{ "field_ridr", 0x00000000, 31, 0, CSR_RW, 0x00000000 },
	{ "RIDR", 0x00000000, 31, 0, CSR_RW, 0x00000000 },
	// WORD pir
	{ "field_pir", 0x00000004, 31, 0, CSR_RW, 0x00000000 },
	{ "PIR", 0x00000004, 31, 0, CSR_RW, 0x00000000 },
	// WORD pgcr
	{ "field_pgcr", 0x00000008, 31, 0, CSR_RW, 0x00000000 },
	{ "PGCR", 0x00000008, 31, 0, CSR_RW, 0x00000000 },
	// WORD pgsr
	{ "field_pgsr", 0x0000000C, 31, 0, CSR_RW, 0x00000000 },
	{ "PGSR", 0x0000000C, 31, 0, CSR_RW, 0x00000000 },
	// WORD dllgcr
	{ "field_dllgcr", 0x00000010, 31, 0, CSR_RW, 0x00000000 },
	{ "DLLGCR", 0x00000010, 31, 0, CSR_RW, 0x00000000 },
	// WORD acdllcr
	{ "field_acdllcr", 0x00000014, 31, 0, CSR_RW, 0x00000000 },
	{ "ACDLLCR", 0x00000014, 31, 0, CSR_RW, 0x00000000 },
	// WORD ptr0
	{ "field_ptr0", 0x00000018, 31, 0, CSR_RW, 0x00000000 },
	{ "PTR0", 0x00000018, 31, 0, CSR_RW, 0x00000000 },
	// WORD ptr1
	{ "field_ptr1", 0x0000001C, 31, 0, CSR_RW, 0x00000000 },
	{ "PTR1", 0x0000001C, 31, 0, CSR_RW, 0x00000000 },
	// WORD ptr2
	{ "field_ptr2", 0x00000020, 31, 0, CSR_RW, 0x00000000 },
	{ "PTR2", 0x00000020, 31, 0, CSR_RW, 0x00000000 },
	// WORD aciocr
	{ "field_aciocr", 0x00000024, 31, 0, CSR_RW, 0x00000000 },
	{ "ACIOCR", 0x00000024, 31, 0, CSR_RW, 0x00000000 },
	// WORD dxccr
	{ "field_dxccr", 0x00000028, 31, 0, CSR_RW, 0x00000000 },
	{ "DXCCR", 0x00000028, 31, 0, CSR_RW, 0x00000000 },
	// WORD dsgcr
	{ "field_dsgcr", 0x0000002C, 31, 0, CSR_RW, 0x00000000 },
	{ "DSGCR", 0x0000002C, 31, 0, CSR_RW, 0x00000000 },
	// WORD dcr
	{ "field_dcr", 0x00000030, 31, 0, CSR_RW, 0x00000000 },
	{ "DCR", 0x00000030, 31, 0, CSR_RW, 0x00000000 },
	// WORD dtpr0
	{ "field_dtpr0", 0x00000034, 31, 0, CSR_RW, 0x00000000 },
	{ "DTPR0", 0x00000034, 31, 0, CSR_RW, 0x00000000 },
	// WORD dtpr1
	{ "field_dtpr1", 0x00000038, 31, 0, CSR_RW, 0x00000000 },
	{ "DTPR1", 0x00000038, 31, 0, CSR_RW, 0x00000000 },
	// WORD dtpr2
	{ "field_dtpr2", 0x0000003C, 31, 0, CSR_RW, 0x00000000 },
	{ "DTPR2", 0x0000003C, 31, 0, CSR_RW, 0x00000000 },
	// WORD mr0
	{ "field_mr0", 0x00000040, 31, 0, CSR_RW, 0x00000000 },
	{ "MR0", 0x00000040, 31, 0, CSR_RW, 0x00000000 },
	// WORD mr1
	{ "field_mr1", 0x00000044, 31, 0, CSR_RW, 0x00000000 },
	{ "MR1", 0x00000044, 31, 0, CSR_RW, 0x00000000 },
	// WORD mr2
	{ "field_mr2", 0x00000048, 31, 0, CSR_RW, 0x00000000 },
	{ "MR2", 0x00000048, 31, 0, CSR_RW, 0x00000000 },
	// WORD mr3
	{ "field_mr3", 0x0000004C, 31, 0, CSR_RW, 0x00000000 },
	{ "MR3", 0x0000004C, 31, 0, CSR_RW, 0x00000000 },
	// WORD odtcr
	{ "field_odtcr", 0x00000050, 31, 0, CSR_RW, 0x00000000 },
	{ "ODTCR", 0x00000050, 31, 0, CSR_RW, 0x00000000 },
	// WORD dtar
	{ "field_dtar", 0x00000054, 31, 0, CSR_RW, 0x00000000 },
	{ "DTAR", 0x00000054, 31, 0, CSR_RW, 0x00000000 },
	// WORD dtdr0
	{ "field_dtdr0", 0x00000058, 31, 0, CSR_RW, 0x00000000 },
	{ "DTDR0", 0x00000058, 31, 0, CSR_RW, 0x00000000 },
	// WORD dtdr1
	{ "field_dtdr1", 0x0000005C, 31, 0, CSR_RW, 0x00000000 },
	{ "DTDR1", 0x0000005C, 31, 0, CSR_RW, 0x00000000 },
	// WORD dcuar
	{ "field_dcuar", 0x000000C0, 31, 0, CSR_RW, 0x00000000 },
	{ "DCUAR", 0x000000C0, 31, 0, CSR_RW, 0x00000000 },
	// WORD dcudr
	{ "field_dcudr", 0x000000C4, 31, 0, CSR_RW, 0x00000000 },
	{ "DCUDR", 0x000000C4, 31, 0, CSR_RW, 0x00000000 },
	// WORD dcurr
	{ "field_dcurr", 0x000000C8, 31, 0, CSR_RW, 0x00000000 },
	{ "DCURR", 0x000000C8, 31, 0, CSR_RW, 0x00000000 },
	// WORD dculr
	{ "field_dculr", 0x000000CC, 31, 0, CSR_RW, 0x00000000 },
	{ "DCULR", 0x000000CC, 31, 0, CSR_RW, 0x00000000 },
	// WORD dcugcr
	{ "field_dcugcr", 0x000000D0, 31, 0, CSR_RW, 0x00000000 },
	{ "DCUGCR", 0x000000D0, 31, 0, CSR_RW, 0x00000000 },
	// WORD dcutpr
	{ "field_dcutpr", 0x000000D4, 31, 0, CSR_RW, 0x00000000 },
	{ "DCUTPR", 0x000000D4, 31, 0, CSR_RW, 0x00000000 },
	// WORD dcusr0
	{ "field_dcusr0", 0x000000D8, 31, 0, CSR_RW, 0x00000000 },
	{ "DCUSR0", 0x000000D8, 31, 0, CSR_RW, 0x00000000 },
	// WORD dcusr1
	{ "field_dcusr1", 0x000000DC, 31, 0, CSR_RW, 0x00000000 },
	{ "DCUSR1", 0x000000DC, 31, 0, CSR_RW, 0x00000000 },
	// WORD bistrr
	{ "field_bistrr", 0x00000100, 31, 0, CSR_RW, 0x00000000 },
	{ "BISTRR", 0x00000100, 31, 0, CSR_RW, 0x00000000 },
	// WORD bistmskr0
	{ "field_bistmskr0", 0x00000104, 31, 0, CSR_RW, 0x00000000 },
	{ "BISTMSKR0", 0x00000104, 31, 0, CSR_RW, 0x00000000 },
	// WORD bistmskr1
	{ "field_bistmskr1", 0x00000108, 31, 0, CSR_RW, 0x00000000 },
	{ "BISTMSKR1", 0x00000108, 31, 0, CSR_RW, 0x00000000 },
	// WORD bistwcr
	{ "field_bistwcr", 0x0000010C, 31, 0, CSR_RW, 0x00000000 },
	{ "BISTWCR", 0x0000010C, 31, 0, CSR_RW, 0x00000000 },
	// WORD bistlsr
	{ "field_bistlsr", 0x00000110, 31, 0, CSR_RW, 0x00000000 },
	{ "BISTLSR", 0x00000110, 31, 0, CSR_RW, 0x00000000 },
	// WORD bistar0
	{ "field_bistar0", 0x00000114, 31, 0, CSR_RW, 0x00000000 },
	{ "BISTAR0", 0x00000114, 31, 0, CSR_RW, 0x00000000 },
	// WORD bistar1
	{ "field_bistar1", 0x00000118, 31, 0, CSR_RW, 0x00000000 },
	{ "BISTAR1", 0x00000118, 31, 0, CSR_RW, 0x00000000 },
	// WORD bistar2
	{ "field_bistar2", 0x0000011C, 31, 0, CSR_RW, 0x00000000 },
	{ "BISTAR2", 0x0000011C, 31, 0, CSR_RW, 0x00000000 },
	// WORD bistudpr
	{ "field_bistudpr", 0x00000120, 31, 0, CSR_RW, 0x00000000 },
	{ "BISTUDPR", 0x00000120, 31, 0, CSR_RW, 0x00000000 },
	// WORD bistgsr
	{ "field_bistgsr", 0x00000124, 31, 0, CSR_RW, 0x00000000 },
	{ "BISTGSR", 0x00000124, 31, 0, CSR_RW, 0x00000000 },
	// WORD bistwer
	{ "field_bistwer", 0x00000128, 31, 0, CSR_RW, 0x00000000 },
	{ "BISTWER", 0x00000128, 31, 0, CSR_RW, 0x00000000 },
	// WORD bistber0
	{ "field_bistber0", 0x0000012C, 31, 0, CSR_RW, 0x00000000 },
	{ "BISTBER0", 0x0000012C, 31, 0, CSR_RW, 0x00000000 },
	// WORD bistber1
	{ "field_bistber1", 0x00000130, 31, 0, CSR_RW, 0x00000000 },
	{ "BISTBER1", 0x00000130, 31, 0, CSR_RW, 0x00000000 },
	// WORD bistber2
	{ "field_bistber2", 0x00000134, 31, 0, CSR_RW, 0x00000000 },
	{ "BISTBER2", 0x00000134, 31, 0, CSR_RW, 0x00000000 },
	// WORD bistwcsr
	{ "field_bistwcsr", 0x00000138, 31, 0, CSR_RW, 0x00000000 },
	{ "BISTWCSR", 0x00000138, 31, 0, CSR_RW, 0x00000000 },
	// WORD bistfwr0
	{ "field_bistfwr0", 0x0000013C, 31, 0, CSR_RW, 0x00000000 },
	{ "BISTFWR0", 0x0000013C, 31, 0, CSR_RW, 0x00000000 },
	// WORD bistfwr1
	{ "field_bistfwr1", 0x00000140, 31, 0, CSR_RW, 0x00000000 },
	{ "BISTFWR1", 0x00000140, 31, 0, CSR_RW, 0x00000000 },
	// WORD gpr0
	{ "field_gpr0", 0x00000178, 31, 0, CSR_RW, 0x00000000 },
	{ "GPR0", 0x00000178, 31, 0, CSR_RW, 0x00000000 },
	// WORD gpr1
	{ "field_gpr1", 0x0000017C, 31, 0, CSR_RW, 0x00000000 },
	{ "GPR1", 0x0000017C, 31, 0, CSR_RW, 0x00000000 },
	// WORD zq0cr0
	{ "field_zq0cr0", 0x00000180, 31, 0, CSR_RW, 0x00000000 },
	{ "ZQ0CR0", 0x00000180, 31, 0, CSR_RW, 0x00000000 },
	// WORD zq0cr1
	{ "field_zq0cr1", 0x00000184, 31, 0, CSR_RW, 0x00000000 },
	{ "ZQ0CR1", 0x00000184, 31, 0, CSR_RW, 0x00000000 },
	// WORD zq0sr0
	{ "field_zq0sr0", 0x00000188, 31, 0, CSR_RW, 0x00000000 },
	{ "ZQ0SR0", 0x00000188, 31, 0, CSR_RW, 0x00000000 },
	// WORD zq0sr1
	{ "field_zq0sr1", 0x0000018C, 31, 0, CSR_RW, 0x00000000 },
	{ "ZQ0SR1", 0x0000018C, 31, 0, CSR_RW, 0x00000000 },
	// WORD zq1cr0
	{ "field_zq1cr0", 0x00000190, 31, 0, CSR_RW, 0x00000000 },
	{ "ZQ1CR0", 0x00000190, 31, 0, CSR_RW, 0x00000000 },
	// WORD dx0gcr
	{ "field_dx0gcr", 0x000001C0, 31, 0, CSR_RW, 0x00000000 },
	{ "DX0GCR", 0x000001C0, 31, 0, CSR_RW, 0x00000000 },
	// WORD dx0gsr0
	{ "field_dx0gsr0", 0x000001C4, 31, 0, CSR_RW, 0x00000000 },
	{ "DX0GSR0", 0x000001C4, 31, 0, CSR_RW, 0x00000000 },
	// WORD dx0gsr1
	{ "field_dx0gsr1", 0x000001C8, 31, 0, CSR_RW, 0x00000000 },
	{ "DX0GSR1", 0x000001C8, 31, 0, CSR_RW, 0x00000000 },
	// WORD dx0dllcr
	{ "field_dx0dllcr", 0x000001CC, 31, 0, CSR_RW, 0x00000000 },
	{ "DX0DLLCR", 0x000001CC, 31, 0, CSR_RW, 0x00000000 },
	// WORD dx0dqtr
	{ "field_dx0dqtr", 0x000001D0, 31, 0, CSR_RW, 0x00000000 },
	{ "DX0DQTR", 0x000001D0, 31, 0, CSR_RW, 0x00000000 },
	// WORD dx0dqstr
	{ "field_dx0dqstr", 0x000001D4, 31, 0, CSR_RW, 0x00000000 },
	{ "DX0DQSTR", 0x000001D4, 31, 0, CSR_RW, 0x00000000 },
	// WORD dx1gcr
	{ "field_dx1gcr", 0x00000200, 31, 0, CSR_RW, 0x00000000 },
	{ "DX1GCR", 0x00000200, 31, 0, CSR_RW, 0x00000000 },
	// WORD dx1gsr0
	{ "field_dx1gsr0", 0x00000204, 31, 0, CSR_RW, 0x00000000 },
	{ "DX1GSR0", 0x00000204, 31, 0, CSR_RW, 0x00000000 },
	// WORD dx1gsr1
	{ "field_dx1gsr1", 0x00000208, 31, 0, CSR_RW, 0x00000000 },
	{ "DX1GSR1", 0x00000208, 31, 0, CSR_RW, 0x00000000 },
	// WORD dx1dllcr
	{ "field_dx1dllcr", 0x0000020C, 31, 0, CSR_RW, 0x00000000 },
	{ "DX1DLLCR", 0x0000020C, 31, 0, CSR_RW, 0x00000000 },
	// WORD dx1dqtr
	{ "field_dx1dqtr", 0x00000210, 31, 0, CSR_RW, 0x00000000 },
	{ "DX1DQTR", 0x00000210, 31, 0, CSR_RW, 0x00000000 },
	// WORD dx1dqstr
	{ "field_dx1dqstr", 0x00000214, 31, 0, CSR_RW, 0x00000000 },
	{ "DX1DQSTR", 0x00000214, 31, 0, CSR_RW, 0x00000000 },
	// end of table
	{ 0, 0, 0, 0, 0, 0 }
};

#endif // CSR_TABLE_DDRPHY_H_
