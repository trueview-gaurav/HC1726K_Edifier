/*
 * Copyright (c) 2017, Linaro Limited
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 * this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 * this list of conditions and the following disclaimer in the documentation
 * and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */
#ifndef __USER_AUTH_AGTX_H__
#define __USER_AUTH_AGTX_H__

/* UUID of the trusted application */
#define TA_USER_AUTH_AGTX_UUID                                         \
	{                                                              \
		0x5b1c4a3d, 0x2f86, 0x4a3d,                            \
		{                                                      \
			0x9f, 0x87, 0x2c, 0x6d, 0x13, 0xa8, 0xe1, 0xf2 \
		}                                                      \
	}

/*
 * TA_USER_AUTH_AGTX_CMD_CHECK - Check a persistent object
 * param[0] (memref) ID used the identify the persistent object
 * param[1] unused
 * param[2] unused
 * param[3] unused
 */
#define TA_USER_AUTH_AGTX_CMD_CHECK 0

/*
 * TA_USER_AUTH_AGTX_CMD_RESET - Reset a persistent object
 * param[0] (memref) ID used the identify the persistent object
 * param[1] (memref) Username to be veriified
 * param[2] (memref) Password to be verified
 * param[3] unused
 */
#define TA_USER_AUTH_AGTX_CMD_RESET 1

/*
 * TA_USER_AUTH_AGTX_CMD_ADD_USER - Add username and password in a secure storage file
 * param[0] (memref) ID used the identify the persistent object
 * param[1] (memref) Username to be written in the persistent object
 * param[2] (memref) Password to be written in the persistent object
 * param[3] unused
 */
#define TA_USER_AUTH_AGTX_CMD_ADD_USER 2

/*
 * TA_USER_AUTH_AGTX_CMD_MODIFY_USER - Modify password of a user in a secure storage file
 * param[0] (memref) ID used the identify the persistent object
 * param[1] (memref) Username to be written in the persistent object
 * param[2] (memref) Password to be verified in the persistent object
 * param[3] (memref) New password to be written in the persistent object
 */
#define TA_USER_AUTH_AGTX_CMD_MODIFY_USER 3

/*
 * TA_USER_AUTH_AGTX_CMD_VERIFY_USER - Verify username and password in a secure storage file
 * param[0] (memref) ID used the identify the persistent object
 * param[1] (memref) Username to be verified
 * param[2] (memref) Password to be verified
 * param[3] unused
 */
#define TA_USER_AUTH_AGTX_CMD_VERIFY_USER 4

/*
 * TA_USER_AUTH_AGTX_CMD_DELETE_USER - Verify username and password and delete if correct
 * param[0] (memref) ID used the identify the persistent object
 * param[1] (memref) Username to be verified and deleted
 * param[2] (memref) Password to be verified and deleted
 * param[3] unused
 */
#define TA_USER_AUTH_AGTX_CMD_DELETE_USER 5

#endif /* __USER_AUTH_AGTX_H__ */
