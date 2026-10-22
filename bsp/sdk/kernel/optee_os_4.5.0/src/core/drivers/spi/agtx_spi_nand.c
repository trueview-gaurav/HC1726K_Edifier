#include <drivers/spi/agtx_spi.h>
#include <drivers/spi/agtx_spi_nand.h>

static uint32_t wait_nand_flash_wel(uint32_t timeout)
{
	uint32_t csr = 0;
	uint32_t umask;
	uint32_t expect;

	umask = NAND_FLASH_C0__WEL__UMASK;
	expect = NAND_FLASH_C0__WEL__UMASK;

	do {
		agtx_nand_read_status(NAND_SR3_ADDR, &csr);

		if ((csr & umask) == expect)
			return ESUCCESS;
	} while (--timeout > 0);

	return ETIMEOUT;
}

uint32_t agtx_wait_nand_ready(uint32_t timeout)
{
	uint32_t csr = 0;
	uint32_t umask;
	uint32_t expect;

	umask = NAND_FLASH_C0__BUSY__UMASK;
	expect = 0;

	do {
		agtx_nand_read_status(NAND_SR3_ADDR, &csr);

		if ((csr & umask) == expect)
			return ESUCCESS;
	} while (--timeout > 0);

	return ETIMEOUT;
}

uint32_t agtx_nand_page_read(uint32_t page_addr)
{
	struct agtx_qspi_data *qspi_data = agtx_get_qspi_data();
	volatile struct csr_bank_qspi *qspi_reg = (struct csr_bank_qspi *)qspi_data->qspi_base;
	uint32_t csr = 0;
	uint32_t status;

	/* Clear the SPI done IRQ first, since the TEE does not clear it upon 
	 * completion of SPI operations. This ensures that the final IRQ triggered 
	 * by the TEE remains available to wake up any Linux process waiting for 
	 * SPI access through the TEE.
	 */
	agtx_clear_done_irq();

	/* Set QSPI engine */
	/* set word7 (QSPI_TRANS_CTRL_0) */
	qspi_reg->transfer_mode = QSPI_TMOD__WRITE;
	qspi_reg->dma_mode_en = QSPI_DMA_M__DIS;
	qspi_reg->frame_format = QSPI_FRF__SSPI;
	/* set word9 (QSPI_DATA_FORMAT) */
	qspi_reg->inst_l = QSPI_INST_L__8_BIT;
	qspi_reg->addr_l = QSPI_ADDR_L__24_BIT;
	qspi_reg->wait_l = QSPI_WAIT_L__0_CYCLE;
	// Workaround for Kyoto, must be 32-bit.
	qspi_reg->data_frame_size = QSPI_DFS__32_BIT;
	/* set word10 (QSPI_DATA_SIZE) */
	qspi_reg->ndf = 0;

	/* Set instruction */
	qspi_reg->wr_data = NAND_FLASH_CMD__PAGE_READ;
	qspi_reg->wr_data = page_addr;

	/* Start transmission */
	qspi_reg->start = 1;

	status = agtx_wait_qspi_transfer(QSPI_TIMEOUT_TIME, QSPI_WAIT_DONE);
	if (status != ESUCCESS) {
		EMSG("Wait QSPI transfer timeout\n");
		return ETIMEOUT;
	}

	if (agtx_wait_nand_ready(QSPI_TIMEOUT_TIME) != ESUCCESS) {
		EMSG("Wait NAND ready timeout\n");
		return ETIMEOUT;
	}

	agtx_nand_read_status(NAND_SR3_ADDR, &csr);
	csr &= NAND_FLASH_C0__ECC_FLAG__UMASK;
	if (csr == NAND_FLASH_C0__ECC_FLAG__ERROR_SINGLE_PAGE || csr == NAND_FLASH_C0__ECC_FLAG__ERROR_MULTIPLE_PAGE) {
		EMSG("ECC error bit detected\n");
		return EFAIL;
	}

	return ESUCCESS;
}

uint32_t agtx_nand_read(uint32_t byte_offset, uint32_t byte_count)
{
	struct agtx_qspi_data *qspi_data = agtx_get_qspi_data();
	volatile struct csr_bank_qspi *qspi_reg = (struct csr_bank_qspi *)qspi_data->qspi_base;

	if ((qspi_data->frame_format != QSPI_FRF__SSPI) && (qspi_data->frame_format != QSPI_FRF__DSPI) &&
	    (qspi_data->frame_format != QSPI_FRF__QSPI)) {
		EMSG("Unsupported frame format\n");
		return EFAIL;
	}

	/* Clear the SPI done IRQ first, since the TEE does not clear it upon 
	 * completion of SPI operations. This ensures that the final IRQ triggered 
	 * by the TEE remains available to wake up any Linux process waiting for 
	 * SPI access through the TEE.
	 */
	agtx_clear_done_irq();

	/* Set QSPI engine */
	/* Word7 (QSPI_TRANS_CTRL_0) */
	qspi_reg->transfer_mode = QSPI_TMOD__READ;
	qspi_reg->dma_mode_en = QSPI_DMA_M__DIS;
	qspi_reg->frame_format = qspi_data->frame_format;
	/* Word9 (QSPI_DATA_FORMAT) */
	qspi_reg->inst_l = QSPI_INST_L__8_BIT;
	qspi_reg->addr_l = QSPI_ADDR_L__16_BIT;
	qspi_reg->wait_l = QSPI_WAIT_L__8_CYCLE;
	qspi_reg->data_frame_size = QSPI_DFS__32_BIT;
	/* Word 10 (QSPI_DATA_SIZE) */
	/* Make sure byte count will be 4*n for quad, 2*n for dual */
	if ((qspi_data->frame_format == QSPI_FRF__DSPI) && (byte_count & 0x1)) {
		EMSG("frame_format & byte_count not meet (DUAL_MODE)\n");
		return EFAIL;
	} else if ((qspi_data->frame_format == QSPI_FRF__QSPI) && (byte_count & 0x3)) {
		EMSG("frame_format & byte_count not meet (QUAD_MODE).\n");
		return EFAIL;
	}
	qspi_reg->ndf = byte_count >> qspi_data->frame_format;

	/* Set instruction */
	if (qspi_data->frame_format == QSPI_FRF__SSPI)
		qspi_reg->wr_data = NAND_FLASH_CMD__SINGLE_READ;
	else if (qspi_data->frame_format == QSPI_FRF__DSPI)
		qspi_reg->wr_data = NAND_FLASH_CMD__DUAL_READ;
	else
		qspi_reg->wr_data = NAND_FLASH_CMD__QUAD_READ;

	qspi_reg->wr_data = byte_offset;

	/* Start transmission */
	qspi_reg->start = 1;

	if (agtx_wait_qspi_transfer(QSPI_TIMEOUT_TIME, QSPI_WAIT_DONE) != ESUCCESS) {
		EMSG("Wait QSPI transfer timeout\n");
		return ETIMEOUT;
	}

	return ESUCCESS;
}

/**
 * @block_addr: block address
 * @b_ofst: offset of data buffer
 * @return: ESUCCESS if no bad block is detected, EBADBLOCK if any bad block is detected
 */
uint32_t agtx_nand_is_bad_block(uint32_t block_addr, uint32_t b_ofst, uint32_t p_ofst)
{
	struct agtx_qspi_data *qspi_data = agtx_get_qspi_data();
	volatile struct csr_bank_qspi *qspi_reg = (struct csr_bank_qspi *)qspi_data->qspi_base;

	uint8_t blk_marker_val;
	uint32_t blk_marker_addr = (1 << b_ofst);
	uint32_t page = block_addr << p_ofst;

	qspi_data = agtx_get_qspi_data();

	if (agtx_nand_page_read(page) == ETIMEOUT) {
		EMSG("read from flash array timeout\n");
		return ETIMEOUT;
	}

	/* read block marker; 1 byte rounded up to 1 WORD */
	if (agtx_nand_read(blk_marker_addr, 4) != ESUCCESS) {
		EMSG("Read from flash buffer error\n");
		return EDATA;
	}

	blk_marker_val = qspi_reg->rd_data;
	if ((blk_marker_val & (0xFF)) != 0xFF) {
		EMSG("Bad block marker not equal 0xff\n");
		return EBADBLOCK;
	}

	return ESUCCESS;
}

uint32_t agtx_nand_normal_read(uint32_t *dst, uint32_t addr, uint32_t data_size)
{
	struct agtx_qspi_data *qspi_data = agtx_get_qspi_data();
	uint32_t status;
	uint32_t page_addr = nand_addr_to_page(addr, BYTES_OFFSET_2048);
	uint32_t byte_addr = addr & 0x7FF;
	uint32_t *pBuf = dst;
	uint32_t byte_count;
	uint32_t byte_unread = data_size;
	uint32_t chunk_size;
	uint32_t byte_remain;
	bool has_read_page = false;

	if (qspi_data->frame_format != QSPI_FRF__QSPI && qspi_data->frame_format != QSPI_FRF__DSPI &&
	    qspi_data->frame_format != QSPI_FRF__SSPI) {
		EMSG("Unsupported frame format\n");
		return EFAIL;
	}

	do {
		/* Read page to data buffer */
		if (has_read_page == false) {
			status = agtx_nand_page_read(page_addr);
			if (status != ESUCCESS) {
				EMSG("Read page failed\n");
				return EFAIL;
			}

			has_read_page = true;
		}

		/* Calculate the maximum chunk to read:
		 * - Limited by FIFO depth
		 * - Limited by remaining page size
		 * - Limited by remaining bytes to read
		 */
		chunk_size = (byte_unread > QSPI_RX_FIFO_SIZE) ? QSPI_RX_FIFO_SIZE : byte_unread;
		byte_remain = NAND_FLASH_PAGE_SIZE - byte_addr;
		byte_count = (chunk_size > byte_remain) ? byte_remain : chunk_size;

		/* Read data located in this page */
		if (agtx_nand_read(byte_addr, byte_count) != ESUCCESS) {
			EMSG("Read data from data buffer failed\n");
			return EFAIL;
		}
		if (agtx_qspi_fifo_read(pBuf, byte_count) != ESUCCESS)
			return EDATA;

		/* Check whether to read the next page */
		byte_addr += byte_count;
		if (byte_addr == NAND_FLASH_PAGE_SIZE) {
			byte_addr = 0;
			has_read_page = false;
		}
		byte_unread -= byte_count;
		pBuf += (byte_count >> 2);
	} while (byte_unread > 0);

	return ESUCCESS;
}

uint32_t agtx_nand_read_id(uint8_t *id)
{
	uint32_t status;
	struct agtx_qspi_data *qspi_data = agtx_get_qspi_data();
	volatile struct csr_bank_qspi *qspi_reg = (struct csr_bank_qspi *)qspi_data->qspi_base;

	/* Clear the SPI done IRQ first, since the TEE does not clear it upon 
	 * completion of SPI operations. This ensures that the final IRQ triggered 
	 * by the TEE remains available to wake up any Linux process waiting for 
	 * SPI access through the TEE.
	 */
	agtx_clear_done_irq();

	/* Set QSPI engine */
	/* set word7 (QSPI_TRANS_CTRL_0) */
	qspi_reg->transfer_mode = QSPI_TMOD__READ;
	qspi_reg->dma_mode_en = QSPI_DMA_M__DIS;
	qspi_reg->frame_format = QSPI_FRF__SSPI;
	/* set word9 (QSPI_DATA_FORMAT) */
	qspi_reg->inst_l = QSPI_INST_L__8_BIT;
	qspi_reg->addr_l = QSPI_ADDR_L__0_BIT;
	qspi_reg->wait_l = QSPI_WAIT_L__8_CYCLE;
	qspi_reg->data_frame_size = QSPI_DFS__8_BIT;
	/* set word10 (QSPI_DATA_SIZE) */
	qspi_reg->ndf = 3;

	/* Set instruction */
	qspi_reg->wr_data = NAND_FLASH_CMD__READ_ID;

	/* Start transmission */
	qspi_reg->start = 1;

	status = agtx_wait_qspi_transfer(QSPI_TIMEOUT_TIME, QSPI_WAIT_DONE);
	if (status != ESUCCESS) {
		EMSG("Wait QSPI transfer timeout\n");
		return ETIMEOUT;
	}

	id[2] = qspi_reg->rd_data_inv;
	id[1] = qspi_reg->rd_data_inv;
	id[0] = qspi_reg->rd_data_inv;

	return ESUCCESS;
}

uint32_t agtx_nand_read_status(uint8_t sr_addr, uint32_t *value_ptr)
{
	uint32_t status;
	struct agtx_qspi_data *qspi_data = agtx_get_qspi_data();
	volatile struct csr_bank_qspi *qspi_reg = (struct csr_bank_qspi *)qspi_data->qspi_base;

	/* Clear the SPI done IRQ first, since the TEE does not clear it upon 
	 * completion of SPI operations. This ensures that the final IRQ triggered 
	 * by the TEE remains available to wake up any Linux process waiting for 
	 * SPI access through the TEE.
	 */
	agtx_clear_done_irq();

	/* Set QSPI engine */
	/* set word7 (QSPI_TRANS_CTRL_0) */
	qspi_reg->transfer_mode = QSPI_TMOD__READ;
	qspi_reg->dma_mode_en = QSPI_DMA_M__DIS;
	qspi_reg->frame_format = QSPI_FRF__SSPI;
	/* set word9 (QSPI_DATA_FORMAT) */
	qspi_reg->inst_l = QSPI_INST_L__8_BIT;
	qspi_reg->addr_l = QSPI_ADDR_L__8_BIT;
	qspi_reg->wait_l = QSPI_WAIT_L__0_CYCLE;
	/* Use 8-bit data frame size will get nothing, which is unreasonable */
	// qspi_reg->data_frame_size = QSPI_DFS__8_BIT;
	qspi_reg->data_frame_size = QSPI_DFS__32_BIT;
	/* set word10 (QSPI_DATA_SIZE) */
	qspi_reg->ndf = 1;

	/* Command and status register address */
	qspi_reg->wr_data = NAND_FLASH_CMD__READ_STA_REG;
	qspi_reg->wr_data = sr_addr;

	/* start */
	qspi_reg->start = 1;

	status = agtx_wait_qspi_transfer(QSPI_TIMEOUT_TIME, QSPI_WAIT_DONE);
	if (status != ESUCCESS) {
		EMSG("wait_qspi_transfer timeout\n");
		return ETIMEOUT;
	}
	*value_ptr = qspi_reg->rd_data & 0xFF;

	return ESUCCESS;
}

uint32_t agtx_nand_write_status(uint8_t sr_addr, uint32_t value)
{
	struct agtx_qspi_data *qspi_data = agtx_get_qspi_data();
	volatile struct csr_bank_qspi *qspi_reg = (struct csr_bank_qspi *)qspi_data->qspi_base;

	/* Clear the SPI done IRQ first, since the TEE does not clear it upon 
	 * completion of SPI operations. This ensures that the final IRQ triggered 
	 * by the TEE remains available to wake up any Linux process waiting for 
	 * SPI access through the TEE.
	 */
	agtx_clear_done_irq();

	/* Set QSPI engine */
	/* set word7 (QSPI_TRANS_CTRL_0) */
	qspi_reg->transfer_mode = QSPI_TMOD__WRITE;
	qspi_reg->dma_mode_en = QSPI_DMA_M__DIS;
	qspi_reg->frame_format = QSPI_FRF__SSPI;
	/* set word9 (QSPI_DATA_FORMAT) */
	qspi_reg->inst_l = QSPI_INST_L__8_BIT;
	qspi_reg->addr_l = QSPI_ADDR_L__8_BIT;
	qspi_reg->wait_l = QSPI_WAIT_L__0_CYCLE;
	/* write with 8-bit DFS can not work, which is unreasonable */
	// qspi_reg->data_frame_size = QSPI_DFS__8_BIT;
	qspi_reg->data_frame_size = QSPI_DFS__32_BIT;
	/* set word10 (QSPI_DATA_SIZE) */
	qspi_reg->ndf = 1;

	/* Command, status register address, status to be set */
	qspi_reg->wr_data = NAND_FLASH_CMD__WRITE_STA_REG;
	qspi_reg->wr_data = sr_addr;
	qspi_reg->wr_data = value & 0xFF;

	/* start */
	qspi_reg->start = 1;

	if (agtx_wait_qspi_transfer(QSPI_TIMEOUT_TIME, QSPI_WAIT_DONE) != ESUCCESS) {
		EMSG("Wait QSPI transfer timeout\n");
		return ETIMEOUT;
	}

	return ESUCCESS;
}

uint32_t agtx_nand_write_enable(void)
{
	uint32_t status;
	struct agtx_qspi_data *qspi_data = agtx_get_qspi_data();
	volatile struct csr_bank_qspi *qspi_reg = (struct csr_bank_qspi *)qspi_data->qspi_base;

	/* Clear the SPI done IRQ first, since the TEE does not clear it upon 
	 * completion of SPI operations. This ensures that the final IRQ triggered 
	 * by the TEE remains available to wake up any Linux process waiting for 
	 * SPI access through the TEE.
	 */
	agtx_clear_done_irq();

	/* Set QSPI engine */
	/* set word7 (QSPI_TRANS_CTRL_0) */
	qspi_reg->transfer_mode = QSPI_TMOD__WRITE;
	qspi_reg->dma_mode_en = QSPI_DMA_M__DIS;
	qspi_reg->frame_format = QSPI_FRF__SSPI;
	/* set word9 (QSPI_DATA_FORMAT) */
	qspi_reg->inst_l = QSPI_INST_L__8_BIT;
	qspi_reg->addr_l = QSPI_ADDR_L__0_BIT;
	qspi_reg->wait_l = QSPI_WAIT_L__0_CYCLE;
	qspi_reg->data_frame_size = QSPI_DFS__32_BIT;
	/* set word10 (QSPI_DATA_SIZE) */
	qspi_reg->ndf = 0;

	/* Set instruction */
	qspi_reg->wr_data = NAND_FLASH_CMD__WRITE_ENABLE;

	/* Start transmission */
	qspi_reg->start = 1;

	status = agtx_wait_qspi_transfer(QSPI_TIMEOUT_TIME, QSPI_WAIT_DONE);
	if (status != ESUCCESS) {
		EMSG("Wait QSPI transfer timeout\n");
		return ETIMEOUT;
	}

	if (wait_nand_flash_wel(QSPI_TIMEOUT_TIME) != ESUCCESS) {
		EMSG("Wait NAND WEL timeout\n");
		return ETIMEOUT;
	}

	return ESUCCESS;
}

static uint32_t nand_block_erase(uint32_t block_addr)
{
	struct agtx_qspi_data *qspi_data = agtx_get_qspi_data();
	volatile struct csr_bank_qspi *qspi_reg = (struct csr_bank_qspi *)qspi_data->qspi_base;
	uint32_t page_addr = block_addr << PAGES_OFFSET_64;
	uint32_t status;
	uint32_t csr = 0;

	status = agtx_nand_write_enable();
	if (status != ESUCCESS) {
		EMSG("write_enable failed\n");
		return EFAIL;
	}

	/* Clear the SPI done IRQ first, since the TEE does not clear it upon 
	 * completion of SPI operations. This ensures that the final IRQ triggered 
	 * by the TEE remains available to wake up any Linux process waiting for 
	 * SPI access through the TEE.
	 */
	agtx_clear_done_irq();

	/* Set QSPI engine */
	/* set word7 (QSPI_TRANS_CTRL_0) */
	qspi_reg->transfer_mode = QSPI_TMOD__WRITE;
	qspi_reg->dma_mode_en = QSPI_DMA_M__DIS;
	qspi_reg->frame_format = QSPI_FRF__SSPI;
	/* set word9 (QSPI_DATA_FORMAT) */
	qspi_reg->inst_l = QSPI_INST_L__8_BIT;
	qspi_reg->addr_l = QSPI_ADDR_L__24_BIT;
	qspi_reg->wait_l = QSPI_WAIT_L__0_CYCLE;
	qspi_reg->data_frame_size = QSPI_DFS__32_BIT;
	/* set word10 (QSPI_DATA_SIZE) */
	qspi_reg->ndf = 0;

	/* Set instruction */
	qspi_reg->wr_data = NAND_FLASH_CMD__BLOCK_ERASE;
	qspi_reg->wr_data = page_addr;

	/* Start transmission */
	qspi_reg->start = 1;

	status = agtx_wait_qspi_transfer(QSPI_TIMEOUT_TIME, QSPI_WAIT_DONE);
	if (status != ESUCCESS) {
		EMSG("Wait QSPI transfer timeout\n");
		return ETIMEOUT;
	}

	if (agtx_wait_nand_ready(QSPI_TIMEOUT_TIME) != ESUCCESS) {
		EMSG("Wait NAND ready timeout\n");
		return ETIMEOUT;
	}

	agtx_nand_read_status(NAND_SR3_ADDR, &csr);
	if ((csr & NAND_FLASH_C0__ERASE_FAIL__UMASK)) {
		EMSG("Erase failed status detected.\n");
		return EFAIL;
	}

	return ESUCCESS;
}

uint32_t agtx_nand_normal_erase(uint32_t addr, uint32_t size)
{
	uint32_t status;
	uint32_t block_addr = nand_addr_to_block(addr, BYTES_OFFSET_2048, PAGES_OFFSET_64);
	uint32_t block_cnt;

	/* Make sure the erase start address is 128KB block-aligned */
	if (addr & 0x1FFFF) {
		EMSG("Invalid erase address: must be block-aligned\n");
		return EFAIL;
	}

	block_cnt = (size >> (BYTES_OFFSET_2048 + PAGES_OFFSET_64));
	if (size & 0x7FF)
		++block_cnt;

	while (block_cnt) {
		status = nand_block_erase(block_addr);
		if (status != ESUCCESS) {
			EMSG("Erase failed\n");
			return EFAIL;
		}
		++block_addr;
		--block_cnt;
	}

	return ESUCCESS;
}

uint32_t agtx_nand_write(const uint32_t *data, uint32_t byte_offset, uint32_t byte_count, bool had_written)
{
	struct agtx_qspi_data *qspi_data = agtx_get_qspi_data();
	volatile struct csr_bank_qspi *qspi_reg = (struct csr_bank_qspi *)qspi_data->qspi_base;
	uint8_t frame_format;
	int i;

	/* Use single mode if the selected flash is configured for dual read mode, since NAND flash only supports 
	 * program in single and quad modes.
	 * Handle invaild arguments also.
	 */
	switch (qspi_data->frame_format) {
	case QSPI_FRF__SSPI:
	case QSPI_FRF__DSPI:
		frame_format = QSPI_FRF__SSPI;
		break;
	case QSPI_FRF__QSPI:
		frame_format = QSPI_FRF__QSPI;
		break;
	default:
		EMSG("Unsupported frame format\n");
		return EFAIL;
	}

	/* Clear the SPI done IRQ first, since the TEE does not clear it upon 
	 * completion of SPI operations. This ensures that the final IRQ triggered 
	 * by the TEE remains available to wake up any Linux process waiting for 
	 * SPI access through the TEE.
	 */
	agtx_clear_done_irq();

	/* Set QSPI engine */
	/* set word7 (QSPI_TRANS_CTRL_0) */
	qspi_reg->transfer_mode = QSPI_TMOD__WRITE;
	qspi_reg->dma_mode_en = QSPI_DMA_M__DIS;
	qspi_reg->frame_format = frame_format;
	/* set word9 (QSPI_DATA_FORMAT) */
	qspi_reg->inst_l = QSPI_INST_L__8_BIT;
	qspi_reg->addr_l = QSPI_ADDR_L__16_BIT;
	qspi_reg->wait_l = QSPI_WAIT_L__0_CYCLE;
	qspi_reg->data_frame_size = QSPI_DFS__32_BIT;
	/* Word 10 (QSPI_DATA_SIZE) */
	/* Make sure byte count will be 4*n for quad */
	if ((frame_format == QSPI_FRF__QSPI) && (byte_count & 0x3)) {
		EMSG("Quad mode's data size needs WORD align\n");
		return EFAIL;
	}
	qspi_reg->ndf = byte_count >> frame_format;

	/* Set instruction */
	if (frame_format == QSPI_FRF__SSPI)
		qspi_reg->wr_data = (had_written == false) ? NAND_FLASH_CMD__SINGLE_PROG_PAGE_0x02 :
		                                             NAND_FLASH_CMD__SINGLE_PROG_PAGE_0x84;
	else
		qspi_reg->wr_data = (had_written == false) ? NAND_FLASH_CMD__QUAD_PROG_PAGE_0x32 :
		                                             NAND_FLASH_CMD__QUAD_PROG_PAGE_0x34;

	/* Set address */
	qspi_reg->wr_data = byte_offset;

	/* Set data */
	i = (byte_count + 3) >> 2; // round up
	while (i) {
		qspi_reg->wr_data = *data;
		--i;
		++data;
	}

	/* Start transmission */
	qspi_reg->start = 1;

	if (agtx_wait_qspi_transfer(QSPI_TIMEOUT_TIME, QSPI_WAIT_DONE) != ESUCCESS) {
		EMSG("Wait QSPI transfer timeout\n");
		return ETIMEOUT;
	}

	return ESUCCESS;
}

uint32_t agtx_nand_program(uint32_t page_addr)
{
	struct agtx_qspi_data *qspi_data = agtx_get_qspi_data();
	volatile struct csr_bank_qspi *qspi_reg = (struct csr_bank_qspi *)qspi_data->qspi_base;
	uint32_t csr = 0;

	/* Clear the SPI done IRQ first, since the TEE does not clear it upon 
	 * completion of SPI operations. This ensures that the final IRQ triggered 
	 * by the TEE remains available to wake up any Linux process waiting for 
	 * SPI access through the TEE.
	 */
	agtx_clear_done_irq();

	/* Set QSPI engine */
	/* set word7 (QSPI_TRANS_CTRL_0) */
	qspi_reg->transfer_mode = QSPI_TMOD__WRITE;
	qspi_reg->dma_mode_en = QSPI_DMA_M__DIS;
	qspi_reg->frame_format = QSPI_FRF__SSPI;
	/* set word9 (QSPI_DATA_FORMAT) */
	qspi_reg->inst_l = QSPI_INST_L__8_BIT;
	qspi_reg->addr_l = QSPI_ADDR_L__24_BIT;
	qspi_reg->wait_l = QSPI_WAIT_L__0_CYCLE;
	/* write with 8-bit DFS can not work, which is unreasonable */
	// qspi_reg->data_frame_size = QSPI_DFS__8_BIT;
	qspi_reg->data_frame_size = QSPI_DFS__32_BIT;
	/* set word10 (QSPI_DATA_SIZE) */
	qspi_reg->ndf = 0;

	/* Command, status register address, status to be set */
	qspi_reg->wr_data = NAND_FLASH_CMD__PROG_EXEC;
	qspi_reg->wr_data = page_addr;

	/* start */
	qspi_reg->start = 1;

	if (agtx_wait_qspi_transfer(QSPI_TIMEOUT_TIME, QSPI_WAIT_DONE) != ESUCCESS) {
		EMSG("Wait QSPI transfer timeout\n");
		return ETIMEOUT;
	}

	if (agtx_wait_nand_ready(QSPI_TIMEOUT_TIME) != ESUCCESS) {
		EMSG("Wait nand ready timeout\n");
		return ETIMEOUT;
	}

	agtx_nand_read_status(NAND_SR3_ADDR, &csr);
	if ((csr & NAND_FLASH_C0__PROGRAM_FAIL__UMASK)) {
		EMSG("Program failed status detected\n");
		return EFAIL;
	}

	return ESUCCESS;
}

uint32_t agtx_nand_normal_write(const uint32_t *data, uint32_t addr, uint32_t byte_count)
{
	uint32_t status;
	const uint32_t *pBuf = data;
	uint32_t byte_addr = addr & 0x7FF;
	uint32_t page_addr = nand_addr_to_page(addr, BYTES_OFFSET_2048);
	uint32_t byte_unwrite = byte_count;
	uint32_t chunk_size;
	uint32_t byte_remain;
	bool had_written = false;

	/* Early termination */
	if (byte_count == 0)
		return ESUCCESS;

	do {
		if (agtx_nand_write_enable() == ETIMEOUT) {
			EMSG("Write enable timeout\n");
			return EFAIL;
		}

		while (byte_unwrite && byte_addr < NAND_FLASH_PAGE_SIZE) {
			chunk_size = (byte_unwrite > QSPI_TX_FIFO_SIZE) ? QSPI_TX_FIFO_SIZE : byte_unwrite;
			byte_remain = NAND_FLASH_PAGE_SIZE - byte_addr;
			byte_count = (chunk_size > byte_remain) ? byte_remain : chunk_size;
			if (agtx_nand_write(pBuf, byte_addr, byte_count, had_written) != ESUCCESS) {
				EMSG("Failed to write data buffer\n");
				return EFAIL;
			}

			if (had_written == false)
				had_written = true;

			pBuf += (byte_count >> 2);
			byte_addr += byte_count;
			byte_unwrite -= byte_count;
		}

		status = agtx_nand_program(page_addr);
		if (status != ESUCCESS) {
			EMSG("Failed to program page\n");
			return EFAIL;
		}

		byte_addr = 0;
		had_written = false;
		++page_addr;
	} while (byte_unwrite);

	return ESUCCESS;
}
