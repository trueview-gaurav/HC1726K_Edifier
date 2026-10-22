/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */
#ifndef VB_DEV_H
#define VB_DEV_H

#include "vb_common.h"
#include <linux/ioctl.h>

#define DRV_NAME "vbs"
#define DEV_NODE "/dev/vbs"

/**
 * @cond code fragment skipped by Doxygen.
 */

typedef struct vb_mem_info {
	u32  phy_addr;
	u32  size;
} VbMemInfo;

/* This structure is designed to have similar form as VbBlk, please do not change */
typedef struct vb_ioctl_cmd {
	u32  arg0;
	u32  arg1;
	u32  arg2;
	u32  ret;
} VbIoctlCmd;

#define IOCTL_VBSYS 's'
#define IOCTL_VB_SET_CONF     _IOW(IOCTL_VBSYS, 0, struct vb_conf)
#define IOCTL_VB_INIT_SYS     _IO (IOCTL_VBSYS, 1)
#define IOCTL_VB_EXIT_SYS     _IO (IOCTL_VBSYS, 2)
#define IOCTL_VB_CMGR_INFO    _IO (IOCTL_VBSYS, 3)
#define IOCTL_VB_GET_MEMINFO  _IOR(IOCTL_VBSYS, 4, struct vb_mem_info)

#define IOCTL_VBCTL 'c'
#define IOCTL_VB_CREATE_RPORT _IOWR(IOCTL_VBCTL, 0, struct vb_ioctl_cmd)
#define IOCTL_VB_CREATE_WPORT _IOWR(IOCTL_VBCTL, 1, struct vb_ioctl_cmd)
#define IOCTL_VB_DESTROY_PORT _IOW (IOCTL_VBCTL, 2, struct vb_ioctl_cmd)
#define IOCTL_VB_READ         _IOWR(IOCTL_VBCTL, 3, struct vb_ioctl_cmd)
#define IOCTL_VB_WRITE        _IOWR(IOCTL_VBCTL, 4, struct vb_ioctl_cmd)
#define IOCTL_VB_BIND         _IOWR(IOCTL_VBCTL, 5, struct vb_ioctl_cmd)
#define IOCTL_VB_SBIND        _IOWR(IOCTL_VBCTL, 6, struct vb_ioctl_cmd)
#define IOCTL_VB_UNBIND       _IOWR(IOCTL_VBCTL, 7, struct vb_ioctl_cmd)
#define IOCTL_VB_FREE         _IOW (IOCTL_VBCTL, 8, struct vb_ioctl_cmd)
#define IOCTL_VB_GET_POOL     _IOWR(IOCTL_VBCTL, 9, struct vb_ioctl_cmd)
#define IOCTL_VB_ALLOC        _IOWR(IOCTL_VBCTL, 10, struct vb_ioctl_cmd)
#define IOCTL_VB_GET_PRV_DATA _IOWR(IOCTL_VBCTL, 11, struct vb_ioctl_cmd)
#define IOCTL_VB_SET_PRV_DATA _IOWR(IOCTL_VBCTL, 12, struct vb_ioctl_cmd)

/**
 * @endcond
 */

#endif /* VB_DEV_H */
