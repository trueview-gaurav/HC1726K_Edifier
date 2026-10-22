/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

/*
 * vb_sys.c: User-space library header 
 */
#ifndef VB_SYS_H_
#define VB_SYS_H_

#include "vb_common.h"

typedef u32 VbRport;
typedef u32 VbWport;
typedef int VbPool;

/* Initialize VB system */
int VB_setConf(const VbConf *conf);
int VB_getConf(VbConf *conf);
int VB_init(void);
int VB_exit(void);

/* Open VB system, exclusive to VB_setConf */
int VB_open(void);
int VB_close(void);

/* Port operations */
VbRport VB_createRport(const char *name, int fifo_depth);
VbWport VB_createWport(const char *name, int fifo_depth);
int VB_sbind(const char *rport, const char *wport);
int VB_unbind(VbRport port);
void VB_destroyPort(u32 port);

/* Block operations */
VbPool VB_getPool(u32 size);
int VB_alloc(VbPool pid, VbBlk *blk);
int VB_read(VbRport port, VbBlk *blk);
int VB_write(VbRport port, const VbBlk *blk);
void VB_free(VbBlk *blk);
int __setVbPrvData(VbBlk *blk, uint32_t size, void *data);
int __getVbPrvData(VbBlk *blk, uint32_t size, void *data);
#define VB_setVbPrvData(x,y) __setVbPrvData(x, sizeof(*y), (void *)y)
#define VB_getVbPrvData(x,y) __getVbPrvData(x, sizeof(*y), (void *)y)

#endif
