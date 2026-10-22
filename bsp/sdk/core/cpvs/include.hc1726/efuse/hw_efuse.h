/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

/**
 * @file hw_efuse.h
 * @brief efuse ctrl
 */
#ifndef HW_EFUSE_CTRL_H
#define HW_EFUSE_CTRL_H

#ifndef __KERNEL__
#include <stdint.h>
#else
#include <linux/types.h>
#endif

/*
 * Busy-wait delay for efuse operations — no CK_BASE / UART CSR dependency.
 *
 * Calibrated with ICache enabled, PLL on (~1GHz):
 *   Each SUBS+BNE iteration ≈ 9.085 ns
 *   N = ((ns * 451) + 4095) >> 12
 *
 * Max supported delay: ~4.7 ms
 */
static inline void eb_delay_ns(unsigned int ns)
{
	register unsigned int count = ((ns * 451u) + 4095u) >> 12;
	if (count == 0)
		count = 1;
	asm volatile("1:\n"
	             "SUBS %[count], %[count], #1\n"
	             "BNE 1b\n"
	             : [count] "+r"(count)
	             :
	             : "cc", "memory");
}

extern volatile struct csr_bank_efuse_ctrl *efuse_ctrl_reg;

void prog_get(volatile struct csr_bank_efuse_ctrl *efuse_ctrl_reg, uint8_t *pubkey1_hash);
void prog_set(volatile struct csr_bank_efuse_ctrl *efuse_ctrl_reg, uint8_t *pubkey1_hash);
uint8_t prog_check(volatile struct csr_bank_efuse_ctrl *efuse_ctrl_reg);
void prog_enable(volatile struct csr_bank_efuse_ctrl *efuse_ctrl_reg);
uint8_t debug_check(volatile struct csr_bank_efuse_ctrl *efuse_ctrl_reg);
void debug_disable(volatile struct csr_bank_efuse_ctrl *efuse_ctrl_reg);
void otp_get(volatile struct csr_bank_efuse_ctrl *efuse_ctrl_reg, uint8_t *otp);
void otp_set(volatile struct csr_bank_efuse_ctrl *efuse_ctrl_reg, uint8_t *otp);
void _conf_load(volatile struct csr_bank_efuse_ctrl *efuse_ctrl_reg);
uint32_t conf_check_tz_en(void);
uint32_t conf_cpu_clk_rate(void);

#endif
