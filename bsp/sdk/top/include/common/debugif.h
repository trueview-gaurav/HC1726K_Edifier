/*
 * AUGENTIX INC. - PROPRIETARY
 *
 * debugif.h - Hardware debug interface module definitions
 * Unpublished Copyright (c) 2018 Augentix Inc. - All Rights Reserved
 *
 * NOTICE: The information contained herein is the property of Augentix Inc.
 * Unauthorized copying and distributing of this file, via any medium,
 * is strictly prohibited.
 *
 * * Brief:
 * *
 * * The file should contain only a list of flags that is declared by
 * * certain modules.
 * *
 * * Each status flag is of a single byte, and consists of two parts,
 * * MODULE and STATE:
 * *
 * *   MODULE    bit[7:4]    Identifier of the module
 * *   STATE     bit[3:0]    Identifier of the status of the module
 * *
 * * The declared flags are to be used when calling debugif write:
 * *
 * *   debugif_writeb(DBGIF_IS_ISR_INVOKED);
 * *
 *
 * * Author: ShihChieh Lin <shihchieh.lin@augentix.com>
 */
#ifndef DEBUGIF_H
#define DEBUGIF_H

#define __MODULE_MASK  0xF0
#define __MODULE_SHIFT 4
#define __STATE_MASK   0x0F
#define __STATE_SHIFT  0

#define DECLARE_FLAG(mod, state) \
	( ((mod   << __MODULE_SHIFT) & __MODULE_MASK) | \
	  ((state << __STATE_SHIFT ) & __STATE_MASK )  )

#ifdef CONFIG_DBG_SPI_TOOL
extern int debugif_writeb(uint8_t value);
#else
int debugif_writeb(uint8_t value) { return 0; }
#endif


/*
 * Module declaration
 */
#define SYS   0
#define IS    1
#define ISP   2
#define ENC   3
#define OSD   4
#define DEBUG_SENIF 5
#define DISP  6

/*
 * Preserved state flags
 * For modules without IRQ or trigger event,
 * these state flags could be overridden
 */
#define ISR_INVOKED 0
#define ISR_EXIT    1
#define WQ_INVOKED  2
#define FRAME_START 3
#define WQ_EXIT     4

/*===========================================================================
 * SYS state and flags
 *==========================================================================*/
#define SYS_EXCP_CATCH  0
#define SYS_BUG         1

#define DBGIF_SYS_EXCP           DECLARE_FLAG(SYS, SYS_EXCP)
#define DBGIF_SYS_BUG            DECLARE_FLAG(SYS, SYS_BUG)

/*===========================================================================
 * IS state and flags
 *==========================================================================*/
#define DBGIF_IS_ISR_INVOKED     0x10
#define DBGIF_IS_ISR_EXIT        0x11
#define DBGIF_IS_WQ_INVOKED      0x12
#define DBGIF_IS_FRAME_START     0x13
#define DBGIF_IS_WQ_EXIT         0x14
#define DBGIF_IS_READ_CSR_BEGIN  0x15
#define DBGIF_IS_READ_CSR_END    0x16
#define DBGIF_IS_REQ_BUF_BEGIN   0x17
#define DBGIF_IS_REQ_BUF_END     0x18
#define DBGIF_IS_WRITE_CSR_BEGIN 0x19
#define DBGIF_IS_WRITE_CSR_END   0x1A

/*===========================================================================
 * ISP state and flags
 *==========================================================================*/
#define DBGIF_ISP_FRAME_START    DECLARE_FLAG(ISP, FRAME_START)
#define DBGIF_ISP_ISR_INVOKED    DECLARE_FLAG(ISP, ISR_INVOKED)
#define DBGIF_ISP_ISR_EXIT       DECLARE_FLAG(ISP, ISR_EXIT)
#define DBGIF_ISP_WQ_INVOKED     DECLARE_FLAG(ISP, WQ_INVOKED)
#define DBGIF_ISP_WQ_EXIT        DECLARE_FLAG(ISP, WQ_EXIT)

/*===========================================================================
 * ENC state and flags
 *==========================================================================*/
#define DBGIF_BSW_BUF_FULL_0     3
#define DBGIF_BSW_BUF_FULL_1     4
#define DBGIF_GET_BSB_IOCTL      5

#define DBGIF_ENC_FRAME_START    DECLARE_FLAG(ENC, FRAME_START)
#define DBGIF_ENC_WQ_INVOKED     DECLARE_FLAG(ENC, WQ_INVOKED)
#define DBGIF_ENC_WQ_EXIT        DECLARE_FLAG(ENC, WQ_EXIT)
#define DBGIF_ENC_ISR_INVOKED    DECLARE_FLAG(ENC, ISR_INVOKED)
#define DBGIF_ENC_ISR_EXIT       DECLARE_FLAG(ENC, ISR_EXIT)
#define DBGIF_ENC_BSW_BUF_FULL_0 DECLARE_FLAG(ENC, BSW_BUF_FULL_0)
#define DBGIF_ENC_BSW_BUF_FULL_1 DECLARE_FLAG(ENC, BSW_BUF_FULL_1)
#define DBGIF_ENC_GET_BSB_IOCTL  DECLARE_FLAG(ENC, GET_BSB_IOCTL)

/*===========================================================================
 * SENIF state and flags
 *==========================================================================*/
#define SENIF_START		0
#define SENIF_FRAME_DONE	1
#define DBGIF_SENIF_START	DECLARE_FLAG(DEBUG_SENIF, SENIF_START)
#define DBGIF_SENIF_FRAME_DONE	DECLARE_FLAG(DEBUG_SENIF, SENIF_FRAME_DONE)

#endif /* DEBUGIF_H */
