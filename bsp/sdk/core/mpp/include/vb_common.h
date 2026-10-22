/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */
#ifndef VB_COMMON_H_
#define VB_COMMON_H_

/*
 * vb_common.h: Common header for kernel and user space
 */

#ifdef __KERNEL__
#include <linux/types.h>
#else
#include <stdint.h>
typedef uint32_t u32;
typedef uint8_t u8;
#endif

/**
 * @cond code fragment skipped by Doxygen.
 */

#define MAX_PORT_NAME_LEN 32
#define MAX_POOL_NAME_LEN 16
#define MAX_PUB_POOL 16

struct vb_port;
struct vb_epoll;
struct vb_block;

typedef struct vb_pool_conf {
	u32 blk_size; /* block size in this pool */
	u32 blk_cnt; /* how many blocks in this pool */
	char name[MAX_POOL_NAME_LEN]; /* pool name */
} VbPoolConf;

typedef int pool_t;

typedef struct vb_conf {
	u32 max_pool_cnt; /* max pools including public and private pools */
	VbPoolConf pub_pool[MAX_PUB_POOL];
} VbConf;

typedef struct vb_blk {
	u32 phy_addr;
	u32 size;
	char *ptr;
	u32 kptr;
} VbBlk;

/**
 * @endcond
 */

#endif
