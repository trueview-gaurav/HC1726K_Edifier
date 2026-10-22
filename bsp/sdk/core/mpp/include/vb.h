/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */
#ifndef VIDEO_BUFFER_H_
#define VIDEO_BUFFER_H_

#include "vb_common.h"
#include <linux/list.h>
#include <linux/mutex.h>

/**
 * @cond code fragment skipped by Doxygen.
 */

struct vb_block {
	u32 phy_addr; /* physical address of the buffer */
	void __iomem *vir_addr; /* virtual address */
	u32 size; /* @size: buffer size */

	u8 id; /* unique number in a pool */
	u8 ref_cnt; /* reference count */
	u8 rel_cnt; /* release if (rel_cnt == ref_cnt) */
#define VB_BLK_EMPTY 0
#define VB_BLK_WRITING 1
#define VB_BLK_READY 2
#define VB_BLK_READING 3
	u8 state; /* block state */

	u8 dummy_link_cnt; /* number of dummy blocks linking to this block */
	struct vb_block *linked_blk; /* pointer to the linked normal block if this is a dummy block */

	void *private_data; /* store private data */
	spinlock_t lock; /* lock for protecting state variable */
	struct list_head lblk; /* block head if you use link list */
	struct vb_pool *pool;
};

struct vb_zone {
	u32 num;
	u32 phy_addr[3];
};

struct vb_event {
#define VB_EVENT_READY 0x1
#define VB_EVENT_ERR 0x2
#define VB_EVENT_HANG 0x3
	u32 event;
	struct vb_port *rport;
};

/*
 * vb_alloc_phy() - Allocate physical memory from VB system.
 * @size: size of memory space. 
 *
 * Return: if failure, return zero, else positive value.
 */
u32 vb_alloc_phy(u32 size);

/*
 * vb_free_phy() - Free physical memory to VB space.
 * @addr: physical address allocated.
 */
void vb_free_phy(u32 phy_addr);

/*
 * get_viraddr() - Get virtual address of specified physical address.
 * @phy_addr: target physical address
 *
 * Return: virtual address or NULL pointer.
 */
void __iomem *get_viraddr(u32 phy_addr);

/*
 * vb_set_conf() - Set public pool configuration.
 * @conf: structure of public pool configuration.
 *
 * Before calling vb_init_system(), you should call this function first.
 * Otherwise, vb_init_system() will return false.
 *
 * Return: return negative value if failure, otherwise, zero.
 * */
int vb_set_conf(struct vb_conf *conf);
int vb_get_conf(struct vb_conf *conf);

/*
 * vb_init_system() - Initialize video buffer system.
 *
 * This function create and initialize pools according to the configuration
 * set by vb_set_conf(). If you never call vb_set_conf() before, an error
 * code will be returned.
 *
 * Return: negative value if an error occurs, otherwise, return zero
 */
int vb_init_system(void);
int vb_exit_system(void);

#define VB_POOL_PUBLIC 0
#define VB_POOL_PRIVATE 1

/*
 * vb_create_pool() - Create a public or a private pool
 * @cnt: the number of blocks.
 * @size: block size.
 * @flag: public or private pools.
 *
 * You can create a public or private pool by specifying VB_POOL_PUBLIC
 * or VB_POOL_PRIVATE respectively.
 *
 * Return: negative value if failure.
 */
pool_t vb_create_pool(u32 cnt, u32 size, const char *name, u32 flag);
void vb_destroy_pool(pool_t pool_id);

/*
 * vb_find_pool() - Find a pool by name.
 * @name: pool name.
 *
 * Reurn: negative values if failure.
 */
pool_t vb_find_pool(const char *name);

/*
 * vb_get_pool() - Find a pool that its block size bigger than the size.
 * @size: target block size.
 *
 * This function will return the pool whose size is equal or larger than
 * ths specified size.
 *
 * Return: negative value if failure.
 */
pool_t vb_get_pool(u32 size);

#define VB_BLK_TYPE_NORMAL (0)
#define VB_BLK_TYPE_DUMMY (1)
/*
 * vb_get_blk_cnt() - Return the number of blocks for the given pool
 * @pool_id: pool id.
 * @blk_type: block type (VB_BLK_TYPE_NORMAL or VB_BLK_TYPE_DUMMY)
 */
u32 vb_get_blk_cnt(pool_t pool_id, u32 blk_type);

/*
 * vb_convert_blk_type() - Convert a block type between normal and dummy
 * @pool_id: pool id.
 * @blk_type: target block type (VB_BLK_TYPE_NORMAL or VB_BLK_TYPE_DUMMY).
 *
 * This function converts a block in the given pool to the specified type:
 * - Normal → Dummy: releases the block's memory and links it to a normal block
 *   with the least number of dummy references.
 * - Dummy → Normal: allocates memory for the block and decreases the reference
 *   count of the previously linked normal block.
 *
 * Return: 0 on success, negative error code on failure.
 */
int vb_convert_blk_type(pool_t pool_id, u32 blk_type);

/*
 * vb_get_pool_avail_blk() - Return the number of available blocks for the given pool
 * @pool_id: pool id.
 */
int vb_get_avail_blk_cnt(pool_t pool_id);

/*
 * vb_get_blk_size() - Return the size of block for the given pool
 * @pool_id: pool id.
 */
u32 vb_get_blk_size(pool_t pool_id);

/*
 * vb_get_blk_size() - Return the array of blocks for the given pool
 * @pool_id: pool id.
 */
struct vb_block *vb_get_blks(pool_t pool_id);

/*
 * vb_get_pool_wr_blk() - Return the number of blocks in WRITING state for the given pool
 * @pool_id: pool id.
 */
int vb_get_allocated_blk_cnt(pool_t pool_id);

/*
 * vb_get_pool_pushed_blk() - Return the number of blocks pushed rport for the given pool
 * @pool_id: pool id.
 */
int vb_get_pushed_blk_cnt(pool_t pool_id);

/*
 * vb_get_pool_pushed_blk() - Return the number of blocks being read by rport for the given pool
 * @pool_id: pool id.
 */
int vb_get_read_blk_cnt(pool_t pool_id);

/*
 * vb_try_alloc() - Try to request a block from the pool.
 * @pool_id: pool id.
 *
 * Return: NULL if an error occurs.
 */
struct vb_block *vb_try_alloc(pool_t pool_id);
struct vb_block *vb_alloc(pool_t pool_id);

/*
 * vb_set_prv_data() - Set private data into the block.
 * @block: block pointer
 * @size: private data size
 * @data: the private data to be set
 *
 * We can set private data *once* only in state VB_BLK_WRITING in the
 * life cycle of a block.
 *
 * Return: negative value if failure.
 */
int vb_set_prv_data(struct vb_block *block, uint32_t size, void *data);

/*
 * vb_free() - Free a block to the pool.
 * @block: block pointer
 *
 * The block is not actually freed to video pool if release count is not
 * equal to reference count.
 *
 * No return
 */
void vb_free(struct vb_block *block);

/*
 * vb_create_wport() - Create a writer port.
 * @name: unique port name with maxlens 32 bytes.
 * @fifo_depth: the maximun number of fifo entry.
 *
 * Port name should be unique over all reader/writer ports.
 *
 * If fifo_depth is negative, this indicates FIFO depth is infinity. As a
 * block is written to a writer port, it will check the writer's FIFO first.
 * If the FIFO is not full, push to it, otherwise, push to reader's FIFO.
 *
 * Return: If errors occur, return NULL pointer.
 *
 * See also: vb_write(), vb_try_write()
 */
struct vb_port *vb_create_wport(char *name, int fifo_depth);
struct vb_port *vb_create_rport(char *name, int fifo_depth);

/*
 * vb_get_rport() - Get rport by name.
 */
struct vb_port *vb_get_rport(char *name);
struct vb_port *vb_get_wport(char *name);

/*
 * vb_destroy_port() - Destroy a writer/reader port.
 * @port: port to be destroyed.
 *
 * This function will unbind all connected ports and clear FIFO.
 *
 * No return.
 */
void vb_destroy_port(struct vb_port *port);

/*
 * vb_get_rport() - Find reader port by name.
 * @name: reader name.
 *
 * TBD
 *
 * Return: NULL if an error occurs.
 */
struct vb_port *vb_get_rport(char *name);
struct vb_port *vb_get_wport(char *name);
int vb_get_rport_cnt(struct vb_port *wport);
char *vb_get_port_name(struct vb_port *port);

/*
 * vb_bind() - Bind a reader port and a writer port.
 * @rport: reader port.
 * @wport: writer port.
 *
 * If writer's FIFO is not empty, its entris will flush to reader's FIFO when
 * first reader is bound to it.
 *
 * Return: Negative if an error occurs, otherwise, zero.
 */
int vb_bind(struct vb_port *rport, struct vb_port *wport);
int vb_sbind(char *rport_name, char *wport_name);
int vb_unbind(struct vb_port *rport);

/*
 * enum excp_policy - exception handling policy.
 *
 * @EXPT_RETERR: Returns error index
 * @EXPT_DSCRD:  Discards the current buffer
 * @EXPT_FREL:   Forcibly release the latest unused buffer from ports
 */
enum excp_policy { EXCP_RETERR = 0, EXCP_DSCRD, EXCP_FREL };

/*
 * vb_try_write() - Try to write a block to the wport.
 * @port: writer port.
 * @blk: block pointer.
 * @excp: expection handling.
 *
 * Return: Negative value if an error occurs, otherwise, zero.
 */
int vb_try_write(struct vb_port *wport, struct vb_block *blk, int excp);
int vb_write(struct vb_port *port, struct vb_block *buffer);

/*
 * vb_try_read() - Try to read a block from the rport.
 * @port: reader port.
 *
 * TBD
 *
 * Return: NULL pointer if failure.
 */
int vb_force_wake_up_rport(struct vb_port *rport);
struct vb_block *vb_read_timeout(struct vb_port *rport, uint32_t timeout_ms);
struct vb_block *vb_try_read(struct vb_port *port);
struct vb_block *vb_read(struct vb_port *port);

/*
 * vb_is_fifo_empty() - Check FIFO empty.
 * @port: video buffer port.
 *
 * TBD
 *
 * Return: True or false.
 */
int vb_is_fifo_empty(struct vb_port *port);
int vb_is_fifo_full(struct vb_port *port);
int vb_get_fifo_cnt(struct vb_port *port);
int vb_get_fifo_depth(struct vb_port *port);
//int vb_set_fifo_depth(struct vb_port *port, int fifo_depth);

#define VB_EPOLL_ADD 0x1
#define VB_EPOLL_MOD 0x2
#define VB_EPOLL_DEL 0x4

/*
 * vb_epoll_create() - Create an epoll instance.
 *
 * TBD
 *
 * Return: NULL pointer if failure.
 */
struct vb_epoll *vb_epoll_create(void);

/*
 * vb_epoll_ctl() - TBD
 *
 * TBD
 *
 * Return: Negative value if an error occurs.
 */
int vb_epoll_ctl(struct vb_epoll *ep, struct vb_port *rport, int ops);

/*
 * vb_epoll_wait() - Wait rports unitil an event happened.
 * @ep: input epoll structure.
 * @events: pointer to event array.
 * @max_events: number of max events.
 *
 * Return: possitive value if sccuess, otherwise, failure.
 *
 * Negative values indicate erros and zero value indicates timeout event.
 */
int vb_epoll_wait(struct vb_epoll *ep, struct vb_event *events, int max_events);
int vb_epoll_wait_timeout(struct vb_epoll *ep, struct vb_event *events, int max_events, u32 msec);

/*
 * vb_epoll_close() - Close epoll.
 */
int vb_epoll_close(struct vb_epoll *ep);

/*
 * vb_to_virt() - Converts a VB physical address to its virtual address.
 * @phys_addr: The physical address to be converted.
 *
 * The virtual address returned by dma_alloc_coherent() my differ from the
 * one provided by phys_to_virt(). Using phys_to_virt() can result in a
 * cached mapping, leading to DMA cache inconsistency.
 *
 * This funcion returns the specific virtual address mapping created by
 * dma_allco_coherent(). Use this function instead of phys_to_virt()
 * when accessing the VB.
 *
 * Return: Corresponding VB virtual address.
 */
void *vb_to_virt(u32 phys_addr);

/*
 * vb_sync_for_cpu() - Invalidates VB cache for CPU
 * @phys_addr: The physical address of VB
 * @size: The size of VB
 *
 * Some applications may map VB into userspace for reading,
 * which involves cache in the userspace mapping.
 * This function invalidates the cache, which sould be invoke
 * before the userspace application starts reading the VB.
 */
void vb_sync_for_cpu(u32 phys_addr, u32 size);

/* block operation functions */
#define get_blk_data(blk) ((blk)->private_data)

#define get_blk_size(blk) ((blk)->size)

#define get_blk_phyaddr(blk) ((blk)->phy_addr)

#define get_blk_viraddr(blk) ((blk)->vir_addr)

#define get_blk_ref_cnt(blk) ((blk)->ref_cnt)

#define get_blk_rel_cnt(blk) ((blk)->rel_cnt)

#define set_blk_data(blk, data) vb_set_prv_data(blk, sizeof(*data), (void *)data)

#define inc_blk_ref(blk, val)          \
	do {                           \
		(blk)->ref_cnt += val; \
	} while (0)

#define dec_blk_ref(blk)          \
	do {                      \
		--(blk)->ref_cnt; \
	} while (0)

#define inc_blk_rel(blk, val)          \
	do {                           \
		(blk)->rel_cnt += val; \
	} while (0)

/**
 * @endcond
 */

#endif
