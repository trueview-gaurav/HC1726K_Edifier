#include <drivers/spi/agtx_spi.h>
#include <drivers/spi/agtx_spi_nor.h>

uint32_t agtx_wait_nor_flash_ready(uint32_t timeout)
{
	uint32_t csr = 0;
	uint32_t umask;
	uint32_t expect;

	umask = NOR_FLASH_SR1__BUSY__UMASK;
	expect = 0;

	do {
		agtx_nor_read_status(NOR_FLASH_CMD__READ_SR1, &csr);

		if ((csr & umask) == expect)
			return ESUCCESS;
	} while (--timeout > 0);

	return ETIMEOUT;
}

static uint32_t wait_nor_flash_wel(uint32_t timeout)
{
	uint32_t csr = 0;
	uint32_t umask;
	uint32_t expect;

	umask = NOR_FLASH_SR1__WEL__UMASK;
	expect = NOR_FLASH_SR1__WEL__UMASK;

	do {
		agtx_nor_read_status(NOR_FLASH_CMD__READ_SR1, &csr);

		if ((csr & umask) == expect)
			return ESUCCESS;
	} while (--timeout > 0);

	return ETIMEOUT;
}

uint32_t agtx_nor_write_status(uint32_t sr_opcode, uint32_t value)
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
	qspi_reg->addr_l = QSPI_ADDR_L__0_BIT;
	qspi_reg->wait_l = QSPI_WAIT_L__0_CYCLE;
	/* write with 8-bit DFS can not work, which is unreasonable */
	// qspi_reg->data_frame_size = QSPI_DFS__8_BIT;
	qspi_reg->data_frame_size = QSPI_DFS__32_BIT;
	/* set word10 (QSPI_DATA_SIZE) */
	qspi_reg->ndf = 1;

	// register read op
	qspi_reg->wr_data = sr_opcode;
	qspi_reg->wr_data = value & 0xFF;

	/* start */
	qspi_reg->start = 1;

	if (agtx_wait_qspi_transfer(QSPI_TIMEOUT_TIME, QSPI_WAIT_DONE) != ESUCCESS) {
		EMSG("%s: wait_qspi_transfer timeout\n", __func__);
		return ETIMEOUT;
	}

	return ESUCCESS;
}

uint32_t agtx_nor_read_status(uint32_t sr_opcode, uint32_t *value_ptr)
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
	qspi_reg->wait_l = QSPI_WAIT_L__0_CYCLE;
	/* Use 8-bit data frame size will get nothing, which is unreasonable */
	// qspi_reg->data_frame_size = QSPI_DFS__8_BIT;
	qspi_reg->data_frame_size = QSPI_DFS__32_BIT;
	/* set word10 (QSPI_DATA_SIZE) */
	qspi_reg->ndf = 1;

	// register read op
	qspi_reg->wr_data = sr_opcode;

	/* start */
	qspi_reg->start = 1;

	status = agtx_wait_qspi_transfer(QSPI_TIMEOUT_TIME, QSPI_WAIT_DONE);
	if (status != ESUCCESS) {
		EMSG("%s: wait_qspi_transfer timeout\n", __func__);
		return ETIMEOUT;
	}
	*value_ptr = qspi_reg->rd_data & 0xFF;
	// DMSG("sr: %#x\n", *value_ptr);

	return ESUCCESS;
}

uint32_t agtx_nor_read_id(uint8_t *id)
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
	qspi_reg->wait_l = QSPI_WAIT_L__0_CYCLE;
	qspi_reg->data_frame_size = QSPI_DFS__8_BIT;
	/* set word10 (QSPI_DATA_SIZE) */
	qspi_reg->ndf = 3;

	/* Set instruction */
	qspi_reg->wr_data = NAND_FLASH_CMD__READ_ID;

	/* Start transmission */
	qspi_reg->start = 1;

	status = agtx_wait_qspi_transfer(QSPI_TIMEOUT_TIME, QSPI_WAIT_DONE);
	if (status != ESUCCESS) {
		EMSG("wait_qspi_transfer timeout\n");
		return ETIMEOUT;
	}

	id[2] = qspi_reg->rd_data_inv;
	id[1] = qspi_reg->rd_data_inv;
	id[0] = qspi_reg->rd_data_inv;

	return ESUCCESS;
}

uint32_t agtx_nor_write_enable(void)
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
	qspi_reg->wr_data = NOR_FLASH_CMD__WRITE_ENABLE;

	/* Start transmission */
	qspi_reg->start = 1;

	status = agtx_wait_qspi_transfer(QSPI_TIMEOUT_TIME, QSPI_WAIT_DONE);
	if (status != ESUCCESS) {
		EMSG("%s: wait_qspi_transfer timeout\n", __func__);
		return ETIMEOUT;
	}

	if (wait_nor_flash_wel(QSPI_TIMEOUT_TIME) != ESUCCESS) {
		EMSG("%s: wait_nor_flash_wel timeout\n", __func__);
		return ETIMEOUT;
	}

	return ESUCCESS;
}

static uint32_t nor_write(uint32_t addr, uint32_t byte_count, const uint32_t *data)
{
	struct agtx_qspi_data *qspi_data = agtx_get_qspi_data();
	volatile struct csr_bank_qspi *qspi_reg = (struct csr_bank_qspi *)qspi_data->qspi_base;
	uint8_t frame_format;
	uint8_t addr_l;
	uint32_t i;

	/* Use single mode if the selected flash is configured for dual read mode, since NOR flash only supports
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

	/* determine addr_l through target address */
	if (addr & 0xFF000000)
		addr_l = QSPI_ADDR_L__32_BIT;
	else
		addr_l = QSPI_ADDR_L__24_BIT;

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
	qspi_reg->addr_l = addr_l;
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
	if (frame_format == QSPI_FRF__SSPI && addr_l == QSPI_ADDR_L__24_BIT)
		qspi_reg->wr_data = NOR_FLASH_CMD__SINGLE_PROG_PAGE;
	else if (frame_format == QSPI_FRF__SSPI && addr_l == QSPI_ADDR_L__32_BIT)
		qspi_reg->wr_data = NOR_FLASH_CMD__SINGLE_PROG_PAGE_4B;
	else if (frame_format == QSPI_FRF__QSPI && addr_l == QSPI_ADDR_L__24_BIT)
		qspi_reg->wr_data = NOR_FLASH_CMD__QUAD_PROG_PAGE;
	else if (frame_format == QSPI_FRF__QSPI && addr_l == QSPI_ADDR_L__32_BIT)
		qspi_reg->wr_data = NOR_FLASH_CMD__QUAD_PROG_PAGE_4B;
	else
		EMSG("QSPI instruction is not set\n");

	/* Set address */
	qspi_reg->wr_data = addr;

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
		EMSG("wait_qspi_transfer timeout\n");
		return ETIMEOUT;
	} else if (agtx_wait_nor_flash_ready(QSPI_TIMEOUT_TIME) != ESUCCESS) {
		EMSG("wait_nor_flash_ready timeout\n");
		return ETIMEOUT;
	}

	return ESUCCESS;
}

static uint32_t nor_one_block_erase(uint32_t addr)
{
	uint8_t addr_l;
	uint32_t status;
	uint32_t wait_wel_counter = 0;
	struct agtx_qspi_data *qspi_data = agtx_get_qspi_data();
	volatile struct csr_bank_qspi *qspi_reg = (struct csr_bank_qspi *)qspi_data->qspi_base;

	/* determine addr_l through target address */
	if (addr & 0xFF000000)
		addr_l = QSPI_ADDR_L__32_BIT;
	else
		addr_l = QSPI_ADDR_L__24_BIT;

	do {
		status = agtx_nor_write_enable();
		if (status == ESUCCESS)
			break;
		wait_wel_counter += 1;
	} while (wait_wel_counter < 10);

	if (status == ETIMEOUT) {
		EMSG("%s: WE timeout\n", __func__);
		return ETIMEOUT;
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
	qspi_reg->addr_l = addr_l;
	qspi_reg->wait_l = QSPI_WAIT_L__0_CYCLE;
	qspi_reg->data_frame_size = QSPI_DFS__32_BIT;
	/* set word10 (QSPI_DATA_SIZE) */
	qspi_reg->ndf = 0;

	/* Set instruction */
	qspi_reg->wr_data = (addr_l == QSPI_ADDR_L__32_BIT) ? NOR_FLASH_CMD__BLOCK_ERASE_4B :
	                                                      NOR_FLASH_CMD__BLOCK_ERASE;

	qspi_reg->wr_data = addr;

	/* Start transmission */
	qspi_reg->start = 1;

	status = agtx_wait_qspi_transfer(QSPI_TIMEOUT_TIME, QSPI_WAIT_DONE);
	if (status != ESUCCESS) {
		EMSG("%s: wait_qspi_transfer timeout\n", __func__);
		return ETIMEOUT;
	}

	if (agtx_wait_nor_flash_ready(1) == ESUCCESS) {
		// Flash IC erase time should be ms level
		return EFAIL;
	}
	if (agtx_wait_nor_flash_ready(QSPI_TIMEOUT_TIME) != ESUCCESS) {
		EMSG("wait_nor_flash_ready timeout\n");
		return ETIMEOUT;
	}

	return ESUCCESS;
}

static uint32_t nor_half_block_erase(uint32_t addr)
{
	struct agtx_qspi_data *qspi_data = agtx_get_qspi_data();
	volatile struct csr_bank_qspi *qspi_reg = (struct csr_bank_qspi *)qspi_data->qspi_base;
	uint32_t wait_wel_counter = 0;
	uint32_t status;

	do {
		status = agtx_nor_write_enable();
		if (status == ESUCCESS)
			break;
		wait_wel_counter += 1;
	} while (wait_wel_counter < 10);

	if (status == ETIMEOUT) {
		EMSG("%s: WE timeout\n", __func__);
		return ETIMEOUT;
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
	/* Erase half block only when using flash with capacity <= 16MB */
	qspi_reg->addr_l = QSPI_ADDR_L__24_BIT;
	qspi_reg->wait_l = QSPI_WAIT_L__0_CYCLE;
	qspi_reg->data_frame_size = QSPI_DFS__32_BIT;
	/* set word10 (QSPI_DATA_SIZE) */
	qspi_reg->ndf = 0;

	/* Set instruction and address */
	qspi_reg->wr_data = NOR_FLASH_CMD__HALF_BLOCK_ERASE;
	qspi_reg->wr_data = addr;

	/* Start transmission */
	qspi_reg->start = 1;

	status = agtx_wait_qspi_transfer(QSPI_TIMEOUT_TIME, QSPI_WAIT_DONE);
	if (status != ESUCCESS) {
		EMSG("%s: wait_qspi_transfer timeout\n", __func__);
		return ETIMEOUT;
	}

	if (agtx_wait_nor_flash_ready(1) == ESUCCESS) {
		// Flash IC erase time should be ms level
		return EFAIL;
	}
	if (agtx_wait_nor_flash_ready(QSPI_TIMEOUT_TIME) != ESUCCESS) {
		EMSG("wait_nor_flash_ready timeout\n");
		return ETIMEOUT;
	}

	return ESUCCESS;
}

static uint32_t nor_sector_erase(uint32_t addr)
{
	struct agtx_qspi_data *qspi_data = agtx_get_qspi_data();
	volatile struct csr_bank_qspi *qspi_reg = (struct csr_bank_qspi *)qspi_data->qspi_base;
	uint8_t addr_l;
	uint32_t wait_wel_counter = 0;
	uint32_t status;

	/* determine addr_l through target address */
	if (addr & 0xFF000000)
		addr_l = QSPI_ADDR_L__32_BIT;
	else
		addr_l = QSPI_ADDR_L__24_BIT;

	do {
		status = agtx_nor_write_enable();
		if (status == ESUCCESS)
			break;
		wait_wel_counter += 1;
	} while (wait_wel_counter < 10);

	if (status == ETIMEOUT) {
		EMSG("%s: WE timeout\n", __func__);
		return ETIMEOUT;
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
	qspi_reg->addr_l = addr_l;
	qspi_reg->wait_l = QSPI_WAIT_L__0_CYCLE;
	qspi_reg->data_frame_size = QSPI_DFS__32_BIT;
	/* set word10 (QSPI_DATA_SIZE) */
	qspi_reg->ndf = 0;

	/* Set instruction and address */
	qspi_reg->wr_data = (addr_l == QSPI_ADDR_L__24_BIT) ? NOR_FLASH_CMD__SECTOR_ERASE :
	                                                      NOR_FLASH_CMD__SECTOR_ERASE_4B;
	qspi_reg->wr_data = addr;

	/* Start transmission */
	qspi_reg->start = 1;

	status = agtx_wait_qspi_transfer(QSPI_TIMEOUT_TIME, QSPI_WAIT_DONE);
	if (status != ESUCCESS) {
		EMSG("%s: wait_qspi_transfer timeout\n", __func__);
		return ETIMEOUT;
	}

	if (agtx_wait_nor_flash_ready(1) == ESUCCESS) {
		// Flash IC erase time should be ms level
		return EFAIL;
	}
	if (agtx_wait_nor_flash_ready(QSPI_TIMEOUT_TIME) != ESUCCESS) {
		EMSG("wait_qspi_transfer timeout\n");
		return ETIMEOUT;
	}

	return ESUCCESS;
}

uint32_t agtx_nor_erase_partition(uint32_t addr, uint32_t size)
{
	uint32_t status = ESUCCESS;

	DMSG("Erase NOR partition: start address=0x%#x, size=%#x\n", addr, size);

	while (size) {
		if ((size >= 65536) && ((addr % 65536) == 0)) {
			status = nor_one_block_erase(addr);
			addr += 65536;
			size -= 65536;
		} else if ((size >= 32768) && ((addr % 32768) == 0) && (addr < 0x1000000)) {
			// Because 32K erase doesn't support flash size >16Mb
			status = nor_half_block_erase(addr);
			addr += 32768;
			size -= 32768;
		} else if ((size >= 4096) && ((addr % 4096) == 0)) {
			status = nor_sector_erase(addr);
			addr += 4096;
			size -= 4096;
		} else {
			EMSG("%s: Wrong address or size\n", __func__);
			return EFAIL;
		}

		if (status != ESUCCESS) {
			EMSG("%s: Erase partition failed\n", __func__);
			return status;
		}
	}

	return status;
}

static uint32_t nor_read(uint32_t addr, uint32_t byte_count)
{
	struct agtx_qspi_data *qspi_data = agtx_get_qspi_data();
	volatile struct csr_bank_qspi *qspi_reg = (struct csr_bank_qspi *)qspi_data->qspi_base;
	uint8_t addr_l;

	if ((qspi_data->frame_format != QSPI_FRF__SSPI) && (qspi_data->frame_format != QSPI_FRF__DSPI) &&
	    (qspi_data->frame_format != QSPI_FRF__QSPI)) {
		EMSG("Unsupported frame format\n");
		return EFAIL;
	}

	/* determine addr_l through target address */
	if (addr & 0xFF000000)
		addr_l = QSPI_ADDR_L__32_BIT;
	else
		addr_l = QSPI_ADDR_L__24_BIT;

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
	qspi_reg->frame_format = qspi_data->frame_format;
	/* set word9 (QSPI_DATA_FORMAT) */
	qspi_reg->inst_l = QSPI_INST_L__8_BIT;
	qspi_reg->addr_l = addr_l;
	qspi_reg->wait_l = QSPI_WAIT_L__8_CYCLE;
	qspi_reg->data_frame_size = QSPI_DFS__32_BIT;
	/* Word 10 (QSPI_DATA_SIZE) */
	/* Make sure byte count will be 4*n for quad, 2*n for dual */
	if ((qspi_data->frame_format == QSPI_FRF__DSPI) && (byte_count & 0x1)) {
		EMSG("%s: frame_format & byte_count not meet (DUAL_MODE)\n", __func__);
		return EFAIL;
	} else if ((qspi_data->frame_format == QSPI_FRF__QSPI) && (byte_count & 0x3)) {
		EMSG("%s: frame_format & byte_count not meet (QUAD_MODE).\n", __func__);
		return EFAIL;
	}
	qspi_reg->ndf = byte_count >> qspi_data->frame_format;

	/* Set instruction */
	if (qspi_data->frame_format == QSPI_FRF__SSPI)
		qspi_reg->wr_data = (addr_l == QSPI_ADDR_L__24_BIT) ? NOR_FLASH_CMD__SINGLE_READ :
		                                                      NOR_FLASH_CMD__SINGLE_READ_4B;
	else if (qspi_data->frame_format == QSPI_FRF__DSPI)
		qspi_reg->wr_data = (addr_l == QSPI_ADDR_L__24_BIT) ? NOR_FLASH_CMD__DUAL_READ :
		                                                      NOR_FLASH_CMD__DUAL_READ_4B;
	else
		qspi_reg->wr_data = (addr_l == QSPI_ADDR_L__24_BIT) ? NOR_FLASH_CMD__QUAD_READ :
		                                                      NOR_FLASH_CMD__QUAD_READ_4B;

	qspi_reg->wr_data = addr;

	/* Start transmission */
	qspi_reg->start = 1;

	if (agtx_wait_qspi_transfer(QSPI_TIMEOUT_TIME, QSPI_WAIT_DONE) != ESUCCESS) {
		EMSG("wait_qspi_transfer timeout\n");
		return ETIMEOUT;
	}

	return ESUCCESS;
}

uint32_t agtx_nor_normal_read(uint32_t *dst, uint32_t addr, uint32_t data_size)
{
	struct agtx_qspi_data *qspi_data;
	uint32_t cur_pos = 0;
	uint32_t *pBuf = dst;
	uint32_t byte_count;
	uint32_t read_byte_count;

	qspi_data = agtx_get_qspi_data();
	read_byte_count = data_size;

	/* Kyoto limitation: byte count must be 4*n for quad, 2*n for dual. */
	if (data_size % 4 != 0) {
		EMSG("Limitation (NOR normal read): NDF in unit of WORD\n");
		return EFAIL;
	}

	if (qspi_data->frame_format != QSPI_FRF__QSPI && qspi_data->frame_format != QSPI_FRF__DSPI &&
	    qspi_data->frame_format != QSPI_FRF__SSPI) {
		EMSG("Unsupported frame format\n");
		return EFAIL;
	}

	do {
		byte_count = (read_byte_count > QSPI_RX_FIFO_SIZE) ? QSPI_RX_FIFO_SIZE : read_byte_count;
		if (nor_read((addr + cur_pos), byte_count) != ESUCCESS) {
			EMSG("nor_read fail\n");
			return EDATA;
		}
		if (agtx_qspi_fifo_read(pBuf, byte_count) != ESUCCESS) {
			EMSG("agtx_qspi_fifo_read fail\n");
			return EDATA;
		}

		cur_pos += byte_count;
		read_byte_count -= byte_count;
		pBuf += (byte_count >> 2);
	} while (cur_pos < data_size);

	return ESUCCESS;
}

uint32_t agtx_nor_normal_write(uint32_t addr, uint32_t byte_count, const uint32_t *data)
{
	uint32_t ret = ESUCCESS;
	uint32_t byte_unwrite = byte_count;

	/* Early termination */
	if (byte_count == 0)
		return ESUCCESS;

	do {
		if (agtx_nor_write_enable() == ETIMEOUT) {
			EMSG("write_enable timeout\n");
			return EFAIL;
		}

		byte_count = (byte_unwrite > QSPI_TX_FIFO_SIZE) ? QSPI_TX_FIFO_SIZE : byte_unwrite;
		ret = nor_write(addr, byte_count, data);

		addr += byte_count;
		byte_unwrite -= byte_count;
		data += (byte_count >> 2);
	} while (byte_unwrite);

	return ret;
}
