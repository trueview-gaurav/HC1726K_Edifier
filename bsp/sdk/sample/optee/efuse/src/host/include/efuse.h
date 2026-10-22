#ifndef __AGTX_EFUSE_H
#define __AGTX_EFUSE_H

#define PTA_CMD_EB_OTP_SET 0
#define PTA_CMD_EB_OTP_GET 1
#define PTA_CMD_EB_PROG_CHECK 2

#define EFUSE_PTA_UUID                                                 \
	{                                                              \
		0xb3514255, 0x08bc, 0x4643,                            \
		{                                                      \
			0xb2, 0x5a, 0x57, 0x8e, 0x0d, 0x6e, 0x99, 0x48 \
		}                                                      \
	}

#endif /* __AGTX_EFUSE_H */
