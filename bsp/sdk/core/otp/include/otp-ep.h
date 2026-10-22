/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef __OTP_EP_H__
#define __OTP_EP_H__

#ifdef __KERNEL__
#include <linux/types.h>
#else
#include <stdint.h>
#endif /* __KERNEL__ */

#define OTP_GATE_ID 'g'
#define OTP_IVA_MD_EN _IO(OTP_GATE_ID, 10)
#define OTP_IVA_OD_V4_3_EN _IO(OTP_GATE_ID, 11)
#define OTP_IVA_HD_EN _IO(OTP_GATE_ID, 12)
#define OTP_IVA_OD_V5_0_EN _IO(OTP_GATE_ID, 13)
#define OTP_IVA_FD_V5_0_EN _IO(OTP_GATE_ID, 14)
#define OTP_IVA_FD_EN _IO(OTP_GATE_ID, 15)
#define OTP_IVA_FR_EN _IO(OTP_GATE_ID, 16)
#define OTP_IVA_TD_EN _IO(OTP_GATE_ID, 17)
#define OTP_IVA_PD_EN _IO(OTP_GATE_ID, 18)
#define OTP_IVA_SHD_EN _IO(OTP_GATE_ID, 19)
#define OTP_IVA_AROI_EN _IO(OTP_GATE_ID, 20)
#define OTP_IVA_EF_EN _IO(OTP_GATE_ID, 21)
#define OTP_IVA_QR_EN _IO(OTP_GATE_ID, 22)
#define OTP_IVA_FDD_EN _IO(OTP_GATE_ID, 23)
#define OTP_IVA_PFM_EN _IO(OTP_GATE_ID, 24)
#define OTP_IVA_DK_EN _IO(OTP_GATE_ID, 25)
#define OTP_IVA_BM_EN _IO(OTP_GATE_ID, 26)
#define OTP_IVA_PC_EN _IO(OTP_GATE_ID, 27)
#define OTP_IVA_FLD_EN _IO(OTP_GATE_ID, 28)
#define OTP_IVA_VD_EN _IO(OTP_GATE_ID, 29)
#define OTP_IVA_PKD_EN _IO(OTP_GATE_ID, 30)
#define OTP_IVA_LOD_EN _IO(OTP_GATE_ID, 31)

#define OTP_IAA_CD_EN _IO(OTP_GATE_ID, 40)
#define OTP_IAA_BSD_EN _IO(OTP_GATE_ID, 41)

#define OTP_VIDEO_DARK_LIGHT_EN _IOR(OTP_GATE_ID, 50, int32_t)

#define OTP_ISP_RESOL_EN _IOW(OTP_GATE_ID, 60, uint32_t)
#define OTP_DRAM_SIZE_EN _IOW(OTP_GATE_ID, 61, uint32_t)
#define OTP_FASTBOOT_EN _IO(OTP_GATE_ID, 62)
#define OTP_ISPV2_EN _IO(OTP_GATE_ID, 63)
#define OTP_EIS_EN _IO(OTP_GATE_ID, 64)
#define OTP_HDR_EN _IO(OTP_GATE_ID, 65)
#define OTP_STITCHING_EN _IO(OTP_GATE_ID, 66)
#define OTP_FOUR_CAMERA_EN _IO(OTP_GATE_ID, 67)

#endif /* __OTP_EP_H__ */
