#ifndef AGTX_VIDEO_BUFFER_LAYOUT_H_
#define AGTX_VIDEO_BUFFER_LAYOUT_H_

/*
 * Early Video Buffer Layout
 * ==================================================================== early_vb_memaddr
 * EV_DRIVER_SHM_SIZE
 *  - Shared memory between U-Boot and Linux early video driver
 *
 * ==================================================================== segments[0].base_addr
 * SNAPSHOT_SIZE
 *  - For the scaling down pass VPW buffer
 * SNAPSHOT_SIZE
 *  - For the reordering chroma pixels pass VPW buffer (snapshot for RTOS)
 * SNAPSHOT_SIZE * 2
 *  - For the processing MV pass NRW/MER buffers
 *
 * ==================================================================== segments[0].mv_addr
 * MV_SIZE
 *  - For the processing MV pass MV8W/MV8R buffer (MV for RTOS)
 * MV_SIZE
 *  - For the processing MV pass VENC_MVW buffer
 *
 * ==================================================================== segments[0].raw_addr
 * POOL_SIZE
 *  - Raw buffer pool
 *
 * ==================================================================== segments[1].base_addr
 * (Same layout as segments[0])
 */

#define EV_DRIVER_SHM_SIZE				(4 * 1024)
#define EV_TOTAL_SNAPSHOT_SIZE(size)	(4 * (size))
#define EV_TOTAL_MV_SIZE(size)			(2 * (size))

/* ISPR address */
#define EV_PRIMARY_ISPR_ADDR(raw_addr, frame_cnt, frame_size)	((raw_addr) + ((frame_cnt) * (frame_size)))
#define EV_REUSED_ISPR_ADDR(base_addr, snapshot_size)			((base_addr) + 0 * (snapshot_size))
/* VPW address */
#define EV_VPW_ADDR(base_addr, snapshot_size)				((base_addr) + 0 * (snapshot_size))
#define EV_REORDERED_VPW_ADDR(base_addr, snapshot_size)		((base_addr) + 1 * (snapshot_size))
/* MCVP address*/
#define EV_NRW_ADDR(base_addr, snapshot_size)				((base_addr) + 2 * (snapshot_size))
#define EV_MER_ADDR(base_addr, snapshot_size)				((base_addr) + 3 * (snapshot_size))
#define EV_MV8W_ADDR(mv_addr, mv_size)						((mv_addr) + 0 * (mv_size))
#define EV_MV8R_ADDR(mv_addr, mv_size)						((mv_addr) + 0 * (mv_size))
#define EV_VENC_MVW_ADDR(mv_addr, mv_size)					((mv_addr) + 1 * (mv_size))

#endif