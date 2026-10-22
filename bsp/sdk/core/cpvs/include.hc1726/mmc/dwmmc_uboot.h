/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef __MMC_HW_H
#define __MMC_HW_H

#include <stdint.h>

#define MMC_CTRL 0x00
#define MMC_PWREN 0x04
#define MMC_CLKDIV 0x08
#define MMC_CLKSRC 0x0C
#define MMC_CLKENA 0x10
#define MMC_TMOUT 0x14
#define MMC_CTYPE 0x18
#define MMC_BLKSIZ 0x1C
#define MMC_BYTCNT 0x20
#define MMC_INTMASK 0x24
#define MMC_CMDARG 0x28
#define MMC_CMD 0x2C
#define MMC_RESP0 0x30
#define MMC_RINTSTS 0x44
#define MMC_STATUS 0x48
#define MMC_FIFOTH 0x4C
#define MMC_CDETECT 0x50
#define MMC_BMOD 0x80
#define MMC_DBADDR 0x88
#define MMC_IDSTS 0x8C
#define MMC_DATA 0x200

#define MMC_INTMSK_ALL 0xffffffff
#define MMC_INTMSK_RE (1 << 1)
#define MMC_INTMSK_CDONE (1 << 2)
#define MMC_INTMSK_DTO (1 << 3)
#define MMC_INTMSK_TXDR (1 << 4)
#define MMC_INTMSK_RXDR (1 << 5)
#define MMC_INTMSK_DCRC (1 << 7)
#define MMC_INTMSK_RTO (1 << 8)
#define MMC_INTMSK_BDS (1 << 9)
#define MMC_INTMSK_DRTO (1 << 9)
#define MMC_INTMSK_HTO (1 << 10)
#define MMC_INTMSK_FRUN (1 << 11)
#define MMC_INTMSK_HLE (1 << 12)
#define MMC_INTMSK_SBE (1 << 13)
#define MMC_INTMSK_ACD (1 << 14)
#define MMC_INTMSK_EBE (1 << 15)

#define MMC_DATA_ERR \
	(MMC_INTMSK_EBE | MMC_INTMSK_SBE | MMC_INTMSK_HLE | MMC_INTMSK_FRUN | MMC_INTMSK_EBE | MMC_INTMSK_DCRC)
#define MMC_DATA_TOUT (MMC_INTMSK_HTO | MMC_INTMSK_DRTO)

#define MMC_CTRL_RESET (1 << 0)
#define MMC_CTRL_FIFO_RESET (1 << 1)
#define MMC_CTRL_DMA_RESET (1 << 2)
#define MMC_DMA_EN (1 << 5)
#define MMC_IDMAC_EN (1 << 25)
#define MMC_RESET_ALL (MMC_CTRL_RESET | MMC_CTRL_FIFO_RESET | MMC_CTRL_DMA_RESET)

#define MMC_CMD_RESP_EXP (1 << 6)
#define MMC_CMD_RESP_LENGTH (1 << 7)
#define MMC_CMD_CHECK_CRC (1 << 8)
#define MMC_CMD_DATA_EXP (1 << 9)
#define MMC_CMD_RW (1 << 10)
#define MMC_CMD_SEND_STOP (1 << 12)
#define MMC_CMD_ABORT_STOP (1 << 14)
#define MMC_CMD_PRV_DAT_WAIT (1 << 13)
#define MMC_CMD_SEND_INIT (1 << 15)
#define MMC_CMD_UPD_CLK (1 << 21)
#define MMC_CMD_EN_BOOT (1 << 24)
#define MMC_CMD_BOOT_ACK_EXP (1 << 25)
#define MMC_CMD_DISABLE_BOOT (1 << 26)
#define MMC_CMD_USE_HOLD_REG (1 << 29)
#define MMC_CMD_START (1 << 31)

#define MMC_FIFO_EMPTY (1 << 2)
#define MMC_BUSY (1 << 9)

#define MSIZE(x) ((x) << 28)
#define RX_WMARK(x) ((x) << 16)
#define TX_WMARK(x) (x)
#define MMC_IDMAC_OWN (1 << 31)
#define MMC_IDMAC_CH (1 << 4)
#define MMC_IDMAC_FS (1 << 3)
#define MMC_IDMAC_LD (1 << 2)

#define MMC_BMOD_IDMAC_FB (1 << 1)
#define MMC_BMOD_IDMAC_EN (1 << 7)

struct dwmci_idmac {
	uint32_t flags;
	uint32_t cnt;
	uint32_t addr;
	uint32_t next_addr;
} __attribute__((aligned(64)));

#define MMC_CMD_GO_IDLE_STATE 0
#define MMC_CMD_SEND_OP_COND 1
#define MMC_CMD_ALL_SEND_CID 2
#define MMC_CMD_SET_RELATIVE_ADDR 3
#define MMC_CMD_SWITCH 6
#define MMC_CMD_SELECT_CARD 7
#define MMC_CMD_SEND_EXT_CSD 8
#define MMC_CMD_STOP_TRANSMISSION 12
#define MMC_CMD_SEND_STATUS 13
#define MMC_CMD_SET_BLOCKLEN 16
#define MMC_CMD_READ_SINGLE_BLOCK 17
#define MMC_CMD_READ_MULTIPLE_BLOCK 18
#define MMC_CMD_SET_BLOCK_COUNT 23

#define OCR_BUSY 0x80000000
#define MMC_STATUS_RDY_FOR_DATA (1 << 8)
#define MMC_STATUS_CURR_STATE (0xf << 9)
#define MMC_SWITCH_MODE_WRITE_BYTE 0x03 /* Set target byte to value */

#define EXT_CSD_BOOT_BUS_WIDTH 177
#define EXT_CSD_PART_CONF 179 /* R/W */
#define EXT_CSD_BUS_WIDTH 183 /* R/W */
#define EXT_CSD_HS_TIMING 185 /* R/W */
#define EXT_CSD_CARD_TYPE 196 /* RO */
#define EXT_CSD_CARD_TYPE_26 (1 << 0) /* Card can run at 26MHz */
#define EXT_CSD_CARD_TYPE_52 (1 << 1) /* Card can run at 52MHz */
#define EXT_CSD_CARD_TYPE_DDR_1_8V (1 << 2)
#define EXT_CSD_CARD_TYPE_DDR_1_2V (1 << 3)

/* Maximum block size for MMC */
#define MMC_MAX_BLOCK_LEN 512

#endif
