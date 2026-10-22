#ifndef __AGTX_SE_SIM_H
#define __AGTX_SE_SIM_H

/* Command IDs */
#define PTA_CMD_HMAC_SHA256 0x0
#define PTA_CMD_DATA_ENC_AES_ECB_256_NO_PAD 0x1
#define PTA_CMD_DATA_DEC_AES_ECB_256_NO_PAD 0x2
#define PTA_CMD_DATA_HKDF 0x03

#define SE_SIM_UUID                                                    \
	{                                                              \
		0x21dbe80f, 0xc6ca, 0x49b5,                            \
		{                                                      \
			0x9a, 0x94, 0xde, 0x24, 0xd0, 0x4a, 0x81, 0xc4 \
		}                                                      \
	}

#endif /* __AGTX_SE_SIM_H */
