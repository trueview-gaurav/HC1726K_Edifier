/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef SAPPORO_CCQ_H_
#define SAPPORO_CCQ_H_

#include "csr_bank_ccq.h"
#include "csr_bank_ccqr.h"
#include "csr_bank_ccqw.h"
#include "da_define.h"

#if __KERNEL__
#include <linux/kernel.h>
#include <linux/types.h>

#define CCQ_PRINT (0)

#define ccq_print(format, args...) printk("[%s:%d] " format, __func__, __LINE__, ##args)
#define ccq_dump_print(format, args...) printk("[%s:%d] " format, __func__, __LINE__, ##args, ##args)
#else
#include <stdint.h>
#include "printf.h"

#define CCQ_PRINT (1)

#define ccq_print(format, args...) printf("[%s:%d] " format, __func__, __LINE__, ##args)
#define ccq_dump_print(format, args...) printf("[%s:%d] " format, __func__, __LINE__, ##args, ##args)
#endif /* __KERNEL__ */

#define u64 uint64_t
#define u32 uint32_t
#define s32 int
#define s16 short
#define u16 unsigned short
#define u8 uint8_t

//IS
#define CCQ_IS_BASE (0x83010000)
#define CCQW_IS_BASE (0x83010800)
#define CCQR_IS_BASE (0x83010400)
//ISP
#define CCQ_ISP_BASE (0x82010000)
#define CCQW_ISP_BASE (0x82010800)
#define CCQR_ISP_BASE (0x82010400)
//DISP
#define CCQ_DISP_BASE (0x83310000)
#define CCQW_DISP_BASE (0x83310800)
#define CCQR_DISP_BASE (0x83310400)

typedef enum ccq_module {
	CCQ_MODULE_IS = 0,
	CCQ_MODULE_ISP,
	CCQ_MODULE_DISP,
	MAX_CCQ_MODULE,
} CcqModule;

typedef enum ccq_irq_flag {
	CCQ_IRQ_FLAG_ISSUE_IRQ,
	CCQ_IRQ_FLAG_UNEXCEPT_IRQ,
	CCQ_IRQ_FLAG_CCQR,
	CCQ_IRQ_FLAG_CCQW,
} CcqIrqFlag;

typedef enum ccq_op_code {
	CCQ_OP_CODE_CSR_WRITE = 0,
	CCQ_OP_CODE_CSR_BURST_WRITE_INCR,
	CCQ_OP_CODE_CSR_BURST_WRITE_FIXED,
	CCQ_OP_CODE_CSR_READ,
	CCQ_OP_CODE_CSR_BURST_READ_INCR,
	CCQ_OP_CODE_CSR_BURST_READ_FIXED,
	CCQ_OP_CODE_CSR_POLLING,
	CCQ_OP_CODE_CSR_CHECK,
	CCQ_OP_CODE_WAIT,
	CCQ_OP_CODE_WAIT_IRQ,
	CCQ_OP_CODE_ISSUE_IRQ,
	MAX_CCQ_OP_CODE,
} CcqOpCode;

typedef enum ccq_is_irq {
	CCQ_IS_ISW1_IRQ = 0,
	CCQ_IS_ISW0_IRQ,
	CCQ_IS_ISW_ROI0_IRQ,
	CCQ_IS_ISK1_FSC_IRQ,
	CCQ_IS_ISK1_CS_IRQ,
	CCQ_IS_ISK1_CVS_IRQ,
	CCQ_IS_ISK1_BSP_IRQ,
	CCQ_IS_ISK1_DPCR_IRQ,
	CCQ_IS_ISK1_LSC_IRQ,
	CCQ_IS_ISK1_DCC_IRQ,
	CCQ_IS_ISK1_DBC_IRQ,
	CCQ_IS_ISK1_BLS_IRQ,
	CCQ_IS_ISK1_FPNR_IRQ,
	CCQ_IS_ISK0_FSC_IRQ,
	CCQ_IS_ISK0_CS_IRQ,
	CCQ_IS_ISK0_CVS_IRQ,
	CCQ_IS_ISK0_BSP_IRQ,
	CCQ_IS_ISK0_DPCR_IRQ,
	CCQ_IS_ISK0_LSC_IRQ,
	CCQ_IS_ISK0_DCC_IRQ,
	CCQ_IS_ISK0_DBC_IRQ,
	CCQ_IS_ISK0_BLS_IRQ,
	CCQ_IS_ISK0_FPNR_IRQ,
	CCQ_IS_ISEDP1_IRQ,
	CCQ_IS_ISEDP0_IRQ,
	CCQ_IS_ISR1_CVS_IRQ,
	CCQ_IS_ISR0_IRQ,
	CCQ_IS_TG1_IRQ,
	CCQ_IS_TG0_IRQ,
	CCQ_IS_ISLP_NOT_ACK_IRQ,
} CccqIsIrq;

typedef enum ccq_isp_irq {
	CCQ_ISP_VENC_NVW_IRQ = 0,
	CCQ_ISP_MVW_IRQ,
	CCQ_ISP_MVR_IRQ,
	CCQ_ISP_NRW_IRQ,
	CCQ_ISP_MER_IRQ,
	CCQ_ISP_MCVP_IRQ,
	CCQ_ISP_B2R_IRQ,
	CCQ_ISP_VPW2_IRQ,
	CCQ_ISP_VPW1_IRQ,
	CCQ_ISP_VPW0_IRQ,

	CCQ_ISP_VPPUP_IRQ,
	CCQ_ISP_DHZ_IRQ,
	CCQ_ISP_NR2D_IRQ,
	CCQ_ISP_CDS_IRQ,
	CCQ_ISP_CUS_IRQ,
	CCQ_ISP_SC_IRQ,
	CCQ_ISP_SHP_IRQ,
	CCQ_ISP_PCA_IRQ,
	CCQ_ISP_FCS_IRQ,
	CCQ_ISP_DMS_IRQ,

	CCQ_ISP_HDR_IRQ,
	CCQ_ISP_BLD_IRQ,
	CCQ_ISP_CS1_IRQ,
	CCQ_ISP_CS0_IRQ,
	CCQ_ISP_GFX0_IRQ,
	CCQ_ISP_ISPR1_IRQ,
	CCQ_ISP_ISPR0_IRQ,
} CccqIspIrq;

typedef enum ccq_disp_irq {
	CCQ_DISP_DISPMIPI_OUT_IRQ = 0,
	CCQ_DISP_DISPMIPI_ENC_IRQ,
	CCQ_DISP_DISPPD_IRQ,
	CCQ_DISP_DISPCFA_IRQ,
	CCQ_DISP_DISPOSDR1_IRQ,
	CCQ_DISP_DISPOSDR0_IRQ,
	CCQ_DISP_DISPCS_IRQ,
	CCQ_DISP_DISPOSD_IRQ,
	CCQ_DISP_DISPYUV422TO444_IRQ,
	CCQ_DISP_DISPYUV420TO444_IRQ,
	CCQ_DISP_DISPR_CS_IRQ,
	CCQ_DISP_TIME_GEN_IRQ,
	CCQ_DISP_DISPR_IRQ,
} CcqDispIrq;

typedef enum ccq_disp_irq_mask {
	CCQ_DISP_MIPI_OUT = 0,
} CcqDispIrqMask;

typedef struct ccq_buffer_setting {
	u32 ccqr_phy_addr;
	u32 ccqr_virt_addr;
	u32 ccqr_size;
	u32 ccqw_phy_addr;
	u32 ccqw_virt_addr;
	u32 ccqw_size;
} CcqBufferSetting;

u32 hw_ccq_get_cmd_len(void);
u32 hw_ccq_check_irq(u32 module);
void hw_ccq_dump_command(u32 *ptr, u32 instruction_length);
void hw_ccq_add_csr_write_cmd(u32 *ptr, u32 csr_addr, u32 data);
void hw_ccq_add_csr_read_cmd(u32 *ptr, u32 csr_addr);
void hw_ccq_add_csr_write_increase_cmd(u32 *ptr, u32 csr_addr, u32 *data, u32 len);
void hw_ccq_add_csr_write_fixed_cmd(u32 *ptr, u32 csr_addr, u32 *data, u32 len);
void hw_ccq_add_csr_read_increase_cmd(u32 *ptr, u32 csr_addr, u32 len);
void hw_ccq_add_csr_read_fixed_cmd(u32 *ptr, u32 csr_addr, u32 len);
void hw_ccq_add_csr_polling_cmd(u32 *ptr, u32 csr_addr, u32 data);
void hw_ccq_add_csr_check_cmd(u32 *ptr, u32 csr_addr, u32 data);
void hw_ccq_add_csr_wait_cmd(u32 *ptr, u32 cycle);
void hw_ccq_add_csr_wait_irq_cmd(u32 *ptr, u64 irq);
void hw_ccq_add_csr_issue_irq_cmd(u32 *ptr);
void hw_ccq_buffer_setting(CcqModule module, CcqBufferSetting *buffer_setting);
void hw_ccq_start(CcqModule module, u32 instruction_length);
void hw_ccq_init(CcqModule module, DramAgentConfig *ccqr_dram_config, DramAgentConfig *ccqw_dram_config);
void hw_ccq_csr_init(CcqModule module, volatile CsrBankCcq *ccq_base, volatile CsrBankCcqw *ccqw_base,
                     volatile CsrBankCcqr *ccqr_base);

#endif /* SAPPORO_CCQ_H_ */
