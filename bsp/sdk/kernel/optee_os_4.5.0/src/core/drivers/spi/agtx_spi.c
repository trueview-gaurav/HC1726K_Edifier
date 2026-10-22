/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#include <stdint.h>
#include <tee_api_defines.h>
#include <trace.h>
#include <io.h>
#include <drivers/spi/agtx_spi.h>
#include <drivers/spi/flash_protect.h>
#include <mm/core_memprot.h>
#include <mm/core_mmu.h>
#include <kernel/panic.h>

struct agtx_qspi_data qspi_data;
#ifdef CFG_IDENTITY_MAPPING
register_phys_mem(MEM_AREA_IO_SEC, QSPI_BASE, QSPI_SIZE);
register_phys_mem(MEM_AREA_IO_SEC, QSPIR_BASE, QSPIR_SIZE);
#else
register_phys_mem_pgdir(MEM_AREA_IO_SEC, QSPI_BASE, QSPI_SIZE);
register_phys_mem_pgdir(MEM_AREA_IO_SEC, QSPIR_BASE, QSPIR_SIZE);
// register_phys_mem_pgdir(MEM_AREA_IO_SEC, QSPIW_BASE, QSPIW_SIZE);
#endif
static uint32_t wait_rx_fifo_ready(uint32_t timeout)
{
	volatile struct csr_bank_qspi *qspi_reg;
	qspi_reg = (struct csr_bank_qspi *)qspi_data.qspi_base;

	do {
		if (qspi_reg->rx_fifo_empty == 1)
			return ESUCCESS;
	} while (--timeout > 0);

	return ETIMEOUT;
}

uint32_t agtx_qspi_fifo_read(uint32_t *dst, uint32_t byte_count)
{
	volatile struct csr_bank_qspi *qspi_reg;
	uint32_t words_unread;
	volatile uint32_t *src;

	qspi_reg = (struct csr_bank_qspi *)qspi_data.qspi_base;

	// rd_data is a bitfield and thus can not be referred to
	src = &(qspi_reg->qspi_rd_data);
	words_unread = (byte_count >> 2);

	asm volatile("head_memcpy:\n\t"
	             "cmp 	%[words_unread], #8\n\t" //if count < 8?
	             "blt 	less_8\n\t" //if <8
	             "loop_8:\n\t"
	             "ldr 	r3, [%[src]]\n\t"
	             "ldr 	r4, [%[src]]\n\t"
	             "ldr 	r5, [%[src]]\n\t"
	             "ldr 	r6, [%[src]]\n\t"
	             "ldr 	r7, [%[src]]\n\t"
	             "ldr 	r8, [%[src]]\n\t"
	             "ldr 	r9, [%[src]]\n\t"
	             "ldr 	r10, [%[src]]\n\t"
	             "stm 	%[dst]!, {r3-r10}\n\t" //brust write
	             "subs	%[words_unread], %[words_unread], #8\n\t" //count -=8
	             "beq	loop_end\n\t" //if ==0 then end
	             "b		head_memcpy\n\t" //if !=0 then jump

	             "less_8:\n\t"
	             "tst 	%[words_unread], #0x4\n\t" //if r2 have bit[2]
	             "beq	loop_2\n\t"
	             "ldr	r3, [%[src]]\n\t" //load single
	             "ldr	r4, [%[src]]\n\t" //load single
	             "ldr	r5, [%[src]]\n\t" //load single
	             "ldr	r6, [%[src]]\n\t" //load single
	             "stm	%[dst]!, {r3-r6}\n\t" //4 writr
	             "loop_2:\n\t"
	             "tst 	%[words_unread], #0x2\n\t" //if r2 have bit[1]
	             "beq	loop_single\n\t"
	             "ldr	r3, [%[src]]\n\t" //load single
	             "ldr	r4, [%[src]]\n\t" //load single
	             "stm	%[dst]!, {r3-r4}\n\t" //double wrie
	             "loop_single:\n\t"
	             "tst 	%[words_unread], #0x1\n\t" //if r2 have bit[0]
	             "beq	loop_end\n\t"
	             "ldr	r3, [%[src]]\n\t" //load single
	             "str	r3, [%[dst]], #4\n\t" //save single
	             "loop_end:\n\t"
	             : [dst] "+r"(dst), [words_unread] "+r"(words_unread)
	             : [src] "r"(src)
	             : "r3", "r4", "r5", "r6", "r7", "r8", "r9", "r10", "cc", "memory");

	if (wait_rx_fifo_ready(QSPI_TIMEOUT_TIME) != ESUCCESS) {
		EMSG("%s: wait_rx_fifo_ready timeout\n", __func__);
		return ETIMEOUT;
	}
	return ESUCCESS;
}

uint32_t agtx_wait_qspi_transfer(uint32_t timeout, uint32_t cond_flag)
{
	volatile struct csr_bank_qspi *qspi_reg;
	uint32_t csr = 0;

	qspi_reg = (struct csr_bank_qspi *)qspi_data.qspi_base;
	/* Wait for DONE flag raised */
	do /* do at least once even if timeout == 0 */
	{
		if ((cond_flag & QSPI_WAIT_DONE) && (qspi_reg->status_spi_dma_done))
			csr |= QSPI_WAIT_DONE;

		if (csr == cond_flag) {
			/* Cancel clearing the interrupt after transmission; instead, 
			 * clear it before accessing the SPI controller. This change 
			 * preserves the IRQ for waking up any Linux process that may be 
			 * waiting for the TEE. 
			 */
			// qspi_reg->irq_clear_spi_done = 1;
			// qspi_reg->irq_clear_spi_dma_done = 1;
			return ESUCCESS;
		}

	} while (--timeout > 0);

	/* Cancel clearing the interrupt after transmission; instead, clear it 
	 * before accessing the SPI controller. This change preserves the IRQ for 
	 * waking up any Linux process that may be waiting for the TEE. 
	 */
	// qspi_reg->irq_clear_spi_done = 1;
	// qspi_reg->irq_clear_spi_dma_done = 1;

	return ETIMEOUT;
}

void agtx_show_spi_csr_status(void)
{
	volatile struct csr_bank_qspi *qspi_reg;
	volatile struct csr_bank_qspir *qspir_reg;
	qspi_reg = (struct csr_bank_qspi *)qspi_data.qspi_base;
	qspir_reg = (struct csr_bank_qspir *)qspi_data.qspir_base;

	EMSG("qspi_irq_status: %#x\n", qspi_reg->qspi_irq_status);
	EMSG("qspi_irq_mask: %#x\n", qspi_reg->qspi_irq_mask);
	EMSG("qspi_status: %#x\n", qspi_reg->qspi_status);
	EMSG("cnt_frame: %#x\n", qspi_reg->cnt_frame);
	EMSG("transfer_mode: %#x, transfer_type: %#x, dma_mode_en: %#x, frame_format: %#x\n", qspi_reg->transfer_mode,
	     qspi_reg->transfer_type, qspi_reg->dma_mode_en, qspi_reg->frame_format);
	EMSG("inst_l: %#x, addr_l: %#x, wait_l: %#x, data_frame_size: %#x\n", qspi_reg->inst_l, qspi_reg->addr_l,
	     qspi_reg->wait_l, qspi_reg->data_frame_size);
	EMSG("ndf: %#x\n", qspi_reg->ndf);
	EMSG("TEE flags: %#x\n", qspi_reg->sck_wr_state_gating_en);
	EMSG("Linux flags: %#x\n", qspi_reg->debug_mon_sel);
	EMSG("Turn: %#x\n", qspir_reg->reserved);
}

void agtx_clear_done_irq(void)
{
	volatile struct csr_bank_qspi *qspi_reg;
	qspi_reg = (struct csr_bank_qspi *)qspi_data.qspi_base;

	qspi_reg->irq_clear_spi_done = 1;
	qspi_reg->irq_clear_spi_dma_done = 1;
}

uint32_t agtx_set_spi_lock_flag(void)
{
	/* Peterson Algo. implemented using the following CSRs (#91613):
	 *   QSPI W18: sck_wr_state_gating_en: OPTEE flag (Confirmed with Jason.
	 *   Tsai that the functionality of this CSR has been removed, and it can
	 *   be used without affecting HW functionality)
	 *   QSPI W19: qspi_debug_mon_sel: Linux flag
	 *   QSPIR W13: turn (Confirmed with Molly that it is approved for use.)
	 */
	uint32_t q18;
	uint32_t q19;
	uint32_t qr13;

	q18 = io_read32(qspi_data.qspi_base + QSPI_SCK_GATING_FUNC_CTRL);
	q18 |= (1 << OFFSET_SCK_WR_STATE_GATING_EN);
	io_write32(qspi_data.qspi_base + QSPI_SCK_GATING_FUNC_CTRL, q18);

	io_write32(qspi_data.qspir_base + QSPIR_RESERVED, SPI_LOCK_FLAG_LINUX);

	do {
		q19 = io_read32(qspi_data.qspi_base + QSPI_DEBUG_MON_SEL) & 0x1;
		qr13 = io_read32(qspi_data.qspir_base + QSPIR_RESERVED) & 0x1;
	} while ((q19 == SPI_LOCK_FLAG_LINUX) && (qr13 == SPI_LOCK_TURN_LINUX));

	qspi_data.irq_mask = io_read32(qspi_data.qspi_base + QSPI_IRQ_MASK);
	io_write32(qspi_data.qspi_base + QSPI_IRQ_MASK, 0xFFFFFFFF);

	return ESUCCESS;
}

bool agtx_spi_is_busy(void)
{
	volatile struct csr_bank_qspi *qspi_reg;
	qspi_reg = (struct csr_bank_qspi *)qspi_data.qspi_base;

	return !!qspi_reg->spi_busy;
}

bool agtx_spi_rx_fifo_empty(void)
{
	volatile struct csr_bank_qspi *qspi_reg;
	qspi_reg = (struct csr_bank_qspi *)qspi_data.qspi_base;

	return !!qspi_reg->rx_fifo_empty;
}

bool agtx_spi_tx_fifo_empty(void)
{
	volatile struct csr_bank_qspi *qspi_reg;
	qspi_reg = (struct csr_bank_qspi *)qspi_data.qspi_base;

	return !!qspi_reg->tx_fifo_empty;
}

uint32_t agtx_unset_spi_lock_flag(void)
{
	uint32_t q18;

	q18 = io_read32(qspi_data.qspi_base + QSPI_SCK_GATING_FUNC_CTRL);
	q18 &= ~(1 << OFFSET_SCK_WR_STATE_GATING_EN);
	io_write32(qspi_data.qspi_base + QSPI_SCK_GATING_FUNC_CTRL, q18);

	io_write32(qspi_data.qspi_base + QSPI_IRQ_MASK, qspi_data.irq_mask);

	return ESUCCESS;
}

TEE_Result agtx_qspi_init(void)
{
	volatile struct csr_bank_qspi *qspi_reg;

	qspi_data.qspi_base = (vaddr_t)phys_to_virt_io(QSPI_BASE, QSPI_SIZE);
	if (!qspi_data.qspi_base) {
		EMSG("Failed to map %#x size physical address %#x", QSPI_SIZE, QSPI_BASE);
		panic();
	}
	qspi_data.qspir_base = (vaddr_t)phys_to_virt_io(QSPIR_BASE, QSPIR_SIZE);
	if (!qspi_data.qspir_base) {
		EMSG("Failed to map %#x size physical address %#x", QSPIR_BASE, QSPI_BASE);
		panic();
	}
	// qspi_data.qspiw_base = (vaddr_t)phys_to_virt_io(QSPIW_BASE, QSPIW_SIZE);
	// if (!qspi_data.qspiw_base) {
	// 	EMSG("Failed to map %#x size physical address %#x", QSPIW_SIZE, QSPIW_BASE);
	// 	panic();
	// }

	qspi_reg = (struct csr_bank_qspi *)qspi_data.qspi_base;

	/* Utilize the setting checked in SPL */
	qspi_data.frame_format = qspi_reg->frame_format;
	DMSG("Using frame format: %#x\n", qspi_data.frame_format);

	/* Check current sck_wr_state_gating_en value */
	qspi_reg->sck_wr_state_gating_en = 0x0;

	agtx_set_spi_lock_flag();
	if (fp_check_support() != TEE_SUCCESS) {
		EMSG("Unsupported flash\n");
		goto err_unknown;
	}

	agtx_unset_spi_lock_flag();
	agtx_clear_done_irq();

	return TEE_SUCCESS;
err_unknown:
	agtx_unset_spi_lock_flag();
	agtx_clear_done_irq();

	return TEE_ERROR_GENERIC;
	/*
	 * Do nothing, everything for qspi initialization is done in SPL.
	 */
}
driver_init(agtx_qspi_init);

struct agtx_qspi_data *agtx_get_qspi_data(void)
{
	return &qspi_data;
}
