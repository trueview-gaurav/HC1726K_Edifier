/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef __OTP_AGTX_H
#define __OTP_AGTX_H

#ifdef __KERNEL__
#include <linux/types.h>
#else
#include <stdint.h>
#endif /* __KERNEL__ */

struct otp_vendor {
	uint32_t vendor_id[1];
};

struct otp_user {
	uint32_t user_custom[4];
};

#define OTP_ID 'f'
#ifdef CONFIG_SAPPORO
#define OTP_KEY_LEN 8
#else
#define OTP_KEY_LEN 7
#endif
#define OTP_READ_VENDOR_ID _IOR(OTP_ID, 0, struct otp_vendor)
#define OTP_READ_USER _IOR(OTP_ID, 1, struct otp_user)
#define OTP_WRITE_USER _IOW(OTP_ID, 2, struct otp_user)
#define OTP_DOWNLOAD_KEY _IOW(OTP_ID, 3, uint32_t[OTP_KEY_LEN])
#define OTP_CHECK_KEY _IOR(OTP_ID, 4, uint32_t[OTP_KEY_LEN])
#define OTP_ENABLE_SECURE _IO(OTP_ID, 5)
#define OTP_DISABLE_DEBUG _IO(OTP_ID, 6)

void otp_register(int chip_id);

#endif /* __OTP_AGTX_H */
