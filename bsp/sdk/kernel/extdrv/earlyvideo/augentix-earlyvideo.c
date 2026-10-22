#include "augentix-earlyvideo.h"

#include <linux/interrupt.h>
#include <linux/mm.h>
#include <linux/module.h>
#include <linux/of_address.h>
#include <linux/of_irq.h>
#include <linux/platform_device.h>
#include <linux/slab.h>
#include <linux/version.h>
#include <linux/workqueue.h>

#ifdef EARLYVIDEO_CSR_V1
#include "csr_bank_frame_time_gen.h"
#elif defined(EARLYVIDEO_CSR_V2)
#include "csr_bank_tg.h"
#endif

#include "csr_bank_edp.h"
#include "csr_bank_is_cfg.h"
#include "csr_bank_isk_cfg.h"
#include "csr_bank_pxw.h"
#include "csr_bank_rx.h"
#include "csr_bank_dec.h"
#include "csr_bank_rx_ctrl.h"
#include "csr_bank_senif_syscfg.h"
#include "csr_bank_slb.h"
#include "da_define.h"

#define DRV_NAME "earlyvideo"

#define LOG_EARLYVIDEO(fmt, ...) printk("[EARLYVIDEO] " fmt "\n", ##__VA_ARGS__)

#define SENIF_IRQ_DEC_FRAME_DONE BIT(0)
#define SENIF_IRQ_DEC_FRAME_END BIT(1)
#define SENIF_IRQ_DEC_MASK_ALL (0x0001FFFF)

#define EARLYVIDEO_STR_CONCAT(s1, s2) s1##s2
#define EARLYVIDEO_UBOOTENV_SETUP(var, value)                                                              \
	static int EARLYVIDEO_STR_CONCAT(g_ubootenv_, var) = value;                                        \
	static __attribute__((unused)) int __init EARLYVIDEO_STR_CONCAT(earlyvideo_setup_, var)(char *str) \
	{                                                                                                  \
		sscanf(str, "%i", &EARLYVIDEO_STR_CONCAT(g_ubootenv_, var));                               \
		return 1;                                                                                  \
	}                                                                                                  \
	__setup(#var "=", EARLYVIDEO_STR_CONCAT(earlyvideo_setup_, var));

enum earlyvb_alloc_strategy {
	EARLYVB_ALLOC_STRATEGY_OVERWRITE_TAIL = 0,
	EARLYVB_ALLOC_STRATEGY_OVERWRITE_HEAD,
};

/* Information from Uboot */
EARLYVIDEO_UBOOTENV_SETUP(early_vb_size, 0);
EARLYVIDEO_UBOOTENV_SETUP(early_vb_memaddr, 0);
EARLYVIDEO_UBOOTENV_SETUP(fal_alarm_debug, 0);
/* Strategy could be moved to dts */
EARLYVIDEO_UBOOTENV_SETUP(early_vb_path0_strategy, EARLYVB_ALLOC_STRATEGY_OVERWRITE_TAIL);
EARLYVIDEO_UBOOTENV_SETUP(early_vb_path1_strategy, EARLYVB_ALLOC_STRATEGY_OVERWRITE_TAIL);

#ifdef EARLYVIDEO_CSR_V1
enum irq_num {
	SENIF_IRQ_DEC0 = 0,
	IS_IRQ_ISWROI0,
	SENIF_IRQ_DEC1,
	IS_IRQ_ISWROI1,
	EARLYVIDEO_IRQ_NUM,
};
#elif defined(EARLYVIDEO_CSR_V2)
enum irq_num {
	SENIF_IRQ_DEC0 = 0,
	SENIF_IRQ_DEC1,
	IS_IRQ_ISW0,
	IS_IRQ_ISW1,
	EARLYVIDEO_IRQ_NUM,
};
#endif

struct earlyvb_pool {
	struct list_head lavail_head;
	struct list_head lused_head;
	struct list_head lfifo_head;
	struct vb_block *blk;
	uint32_t pool_size;
	uint32_t blk_size;
	uint32_t blk_num; /* Total number of allocated block */
	uint32_t keep_blk_num; /* Number of blocks to keep while releasing */
	uint32_t available_blk_num; /* Current number of available blocks */
	int32_t force_drop_num; /* The number of frames to drop while stopping */

	enum earlyvb_alloc_strategy strategy;
	spinlock_t lock;
};

struct video_param {
	uint32_t bit_depth;
	uint32_t path_width;
	uint32_t path_height;
};

#ifdef EARLYVIDEO_CSR_V1
struct earlyvideo_csr {
	/* SENIF */
	volatile struct csr_bank_senif_syscfg *senif_syscfg;
	volatile struct csr_bank_slb *slb[EARLYVIDEO_MAX_PATH_NUM];
	volatile struct csr_bank_rx *lvds_rx[EARLYVIDEO_MAX_PATH_NUM];
	volatile struct csr_bank_dec *lvds_dec[EARLYVIDEO_MAX_PATH_NUM];
	volatile struct csr_bank_rx_ctrl *rxphy_ctrl[EARLYVIDEO_MAX_PATH_NUM];
	/* IS */
	volatile struct csr_bank_is_cfg *is_cfg;
	volatile struct csr_bank_edp *edp[EARLYVIDEO_MAX_PATH_NUM];
	volatile struct csr_bank_frame_time_gen *frame_time_gen[EARLYVIDEO_MAX_PATH_NUM];
	volatile struct csr_bank_pxw *iswroi[EARLYVIDEO_MAX_PATH_NUM];
};
#elif defined(EARLYVIDEO_CSR_V2)
struct earlyvideo_csr {
	/* SENIF */
	volatile struct csr_bank_senif_syscfg *senif_syscfg;
	volatile struct csr_bank_slb *slb[EARLYVIDEO_MAX_PATH_NUM];
	volatile struct csr_bank_rx *lvds_rx;
	volatile struct csr_bank_dec *lvds_dec[EARLYVIDEO_MAX_PATH_NUM];
	volatile struct csr_bank_rx_ctrl *rxphy_ctrl;
	/* IS */
	volatile struct csr_bank_is_cfg *is_cfg;
	volatile struct csr_bank_isk_cfg *isk_cfg[EARLYVIDEO_MAX_PATH_NUM];
	volatile struct csr_bank_edp *edp[EARLYVIDEO_MAX_PATH_NUM];
	volatile struct csr_bank_tg *tg[EARLYVIDEO_MAX_PATH_NUM];
	volatile struct csr_bank_pxw *isw[EARLYVIDEO_MAX_PATH_NUM];
};
#endif

struct earlyvideo_path_info {
	uint8_t idx;
	uint16_t frame_cnt;

#define SENIF_STATE_RUNNING (0)
#define SENIF_STATE_FRAME_DONE BIT(0)
#define SENIF_STATE_FRAME_END BIT(1)
#define SENIF_STATE_IDLE (~SENIF_STATE_RUNNING)
	uint8_t senif_state;

	struct video_param param;

	struct work_struct wdt_work;
	struct completion wdt_completion;

	/* Earlyvb */
	struct earlyvb_pool vb_pool;
	struct vb_block *blk;
};

struct earlyvideo_drvdata {
	int irq[EARLYVIDEO_IRQ_NUM];
	uint32_t paddr;
	uint32_t size;
	void __iomem *vaddr;

	struct device *dev;

	enum earlyvideo_status status;
	spinlock_t status_lock;

	struct earlyvideo_csr csr;

	uint8_t sensor_bmp; /* BIT(0): sensor 0, BIT(1): sensor 1 */
	struct earlyvideo_path_info path[EARLYVIDEO_MAX_PATH_NUM];
	bool destroy_all_pools; /* The flag to indicate if all pre-roll frames are dropped */

	earlyvideo_callback_senif earlyvideo_cb_senif[EARLYVIDEO_MAX_PATH_NUM];
	earlyvideo_callback_is earlyvideo_cb_is;
	struct mutex senif_cb_lock;
	struct mutex is_cb_lock;

	struct work_struct release_work;

	struct earlyvideo_shm_info *shm_addr;
};
struct earlyvideo_drvdata *g_drvdata;

#define EV_DRIVER_SHM_SIZE (4 * 1024)
typedef union uboot_hw_motion_vec {
	struct {
		int64_t x0 : 10;
		int64_t y0 : 10;
		int64_t valid0 : 1;
		int64_t padding0 : 11;
		int64_t x1 : 10;
		int64_t y1 : 10;
		int64_t valid1 : 1;
		int64_t padding1 : 11;
	};
	int64_t value;
} UbootHwMotionVec;

struct uboot_mv_info {
	UbootHwMotionVec *phy_addr; /* Address of the starting point of motion vectors (MV) */
	uint32_t fps; /* Frame rate of the sensor in U-Boot */
	uint32_t duration; /* Duration of one frame in jiffies (10ms) */
	uint16_t win_width; /* Width of the window in pixels */
	uint16_t win_height; /* Height of the window in pixels */
};

struct uboot_snapshot_info {
	void *phy_addr_y; /* Address of the frame's starting point, containing the luminance data of the YUV format. */
	void *phy_addr_c; /* Address of the chrominance data of the YUV format. */
	uint32_t size_y; /* Size of the luminance data in bytes. */
	uint32_t size_c; /* Size of the chrominance data in bytes. */
	uint16_t width; /* Width of the snapshot in pixels. */
	uint16_t height; /* Height of the snapshot in pixels. */
	uint8_t bit_depth; /* Bit depth of the snapshot. */
};

struct early_detect_info {
	struct uboot_mv_info mv;
	struct uboot_snapshot_info snapshot;
	uint8_t is_used; /* Flag indicating whether these information has been used and can be freed. */
};

/* Structure for shared memory between Uboot and Linux early video driver */
struct earlyvideo_shm_segment {
	uint32_t base_addr;
	uint32_t snapshot_size;
	uint32_t mv_addr; /* Equals base_addr + 4 * snapshot_size */
	uint32_t mv_size;
	uint32_t raw_addr; /* Equals mv_addr + 2 * mv_size */
	uint32_t pool_size;
	uint32_t frame_size;
	uint32_t total_frame_num;
	uint32_t uboot_capture_num;
	uint32_t keep_num;
	/* Resolution */
	uint32_t width;
	uint32_t height;
	/* Sensor data */
	uint32_t fps;
	uint32_t exps_time_us;
	uint32_t gain32;
	/* Snapshot and MV information */
	struct early_detect_info early_detect_info;
};

struct earlyvideo_shm_info {
	struct earlyvideo_shm_segment segments[EARLYVIDEO_MAX_PATH_NUM];
};

int earlyvideo_register_cb_senif(earlyvideo_callback_senif cb_func_ptr, uint8_t path)
{
	if (g_drvdata == NULL) {
		LOG_EARLYVIDEO("Driver data is uninitialized during SENIF callback registration");
		return -EFAULT;
	}

	if (path > EARLYVIDEO_MAX_PATH_NUM) {
		LOG_EARLYVIDEO("The path index is invalid during SENIF callback registration");
		return -EINVAL;
	}

	WARN_ON(g_drvdata->earlyvideo_cb_senif[path]);

	g_drvdata->earlyvideo_cb_senif[path] = cb_func_ptr;

	return 0;
}
EXPORT_SYMBOL(earlyvideo_register_cb_senif);

int earlyvideo_unregister_cb_senif(uint8_t path)
{
	if (g_drvdata == NULL) {
		LOG_EARLYVIDEO("Driver data is uninitialized during SENIF callback unregistration");
		return -EFAULT;
	}
	if (path > EARLYVIDEO_MAX_PATH_NUM) {
		LOG_EARLYVIDEO("The path index is invalid during SENIF callback unregistration");
		return -EINVAL;
	}
	if (g_drvdata->earlyvideo_cb_senif[path] != NULL && mutex_trylock(&g_drvdata->senif_cb_lock)) {
		g_drvdata->earlyvideo_cb_senif[path] = NULL;
		mutex_unlock(&g_drvdata->senif_cb_lock);
	} else {
		/* The callback function has been processed or is being processed. */
		return -EBUSY;
	}

	return 0;
}
EXPORT_SYMBOL(earlyvideo_unregister_cb_senif);

int earlyvideo_register_cb_is(earlyvideo_callback_is cb_func_ptr)
{
	if (g_drvdata == NULL) {
		LOG_EARLYVIDEO("Driver data is uninitialized during IS callback registration");
		return -EFAULT;
	}

	WARN_ON(g_drvdata->earlyvideo_cb_is);

	g_drvdata->earlyvideo_cb_is = cb_func_ptr;

	return 0;
}
EXPORT_SYMBOL(earlyvideo_register_cb_is);

int earlyvideo_unregister_cb_is(void)
{
	if (g_drvdata == NULL) {
		LOG_EARLYVIDEO("Driver data is uninitialized during IS callback unregistration");
		return -EFAULT;
	}
	if (g_drvdata->earlyvideo_cb_is != NULL && mutex_trylock(&g_drvdata->is_cb_lock)) {
		g_drvdata->earlyvideo_cb_is = NULL;
		mutex_unlock(&g_drvdata->is_cb_lock);
	} else {
		/* The callback function has been processed or is being processed. */
		return -EBUSY;
	}

	return 0;
}
EXPORT_SYMBOL(earlyvideo_unregister_cb_is);

static inline int earlyvb_count_list(struct list_head *head)
{
	struct vb_block *blk;
	int count = 0;

	list_for_each_entry(blk, head, lblk) {
		count++;
	}
	return count;
}

int earlyvb_init(struct earlyvideo_drvdata *drvdata)
{
	struct earlyvideo_shm_info *shm_info = drvdata->shm_addr;
	struct earlyvb_pool *pool;
	struct video_param *param;
	struct vb_block *blk;
	uint8_t path;
	int i;

	for (path = 0; path < EARLYVIDEO_MAX_PATH_NUM; path++) {
		pool = &drvdata->path[path].vb_pool;
		param = &drvdata->path[path].param;

		INIT_LIST_HEAD(&pool->lavail_head);
		INIT_LIST_HEAD(&pool->lused_head);
		INIT_LIST_HEAD(&pool->lfifo_head);
		spin_lock_init(&pool->lock);

		if (drvdata->sensor_bmp & BIT(path)) {
			pool->pool_size = shm_info->segments[path].pool_size;
			pool->blk_size = shm_info->segments[path].frame_size;
			pool->blk_num = shm_info->segments[path].total_frame_num;
			pool->keep_blk_num = shm_info->segments[path].keep_num;
			printk("Path %d: pool_size %dk res %dx%d blk_num %d ", path, pool->pool_size >> 10,
			       param->path_width, param->path_height, pool->blk_num);
			printk("fps %d inttime %u gain %u\n", shm_info->segments[path].fps,
			       shm_info->segments[path].exps_time_us, shm_info->segments[path].gain32);
		} else {
			pool->pool_size = 0;
			pool->blk_size = 0;
			pool->blk_num = 0;
			pool->keep_blk_num = 0;
		}

		/* Assign the overwrite strategy */
		pool->strategy = path ? g_ubootenv_early_vb_path1_strategy : g_ubootenv_early_vb_path0_strategy;

		/* Allocate memory for VB blocks structure */
		pool->blk = kzalloc(sizeof(*blk) * pool->blk_num, GFP_ATOMIC);
		if (pool->blk == NULL) {
			pr_err("Failed to allocate early VB block structures for path %d!\n", path);
			return -ENOMEM;
		}

		/* Initialize VB blocks */
		for (i = 0; i < pool->blk_num; i++) {
			blk = pool->blk + i;
			blk->id = i;
			blk->size = pool->blk_size;
			blk->pool = (struct vb_pool *)pool;
			blk->vir_addr = 0; /* These blocks cannot be accessed by the CPU through the OS */
			blk->phy_addr = shm_info->segments[path].raw_addr + pool->blk_size * i;

			if (i + 1 > shm_info->segments[path].uboot_capture_num) {
				list_add_tail(&blk->lblk, &pool->lavail_head);
			} else {
				struct earlyvideo_metadata metadata;

				metadata.fps = shm_info->segments[path].fps;
				metadata.inttime = shm_info->segments[path].exps_time_us;
				metadata.sys_gain = shm_info->segments[path].gain32;
#if LINUX_VERSION_CODE < KERNEL_VERSION(5, 6, 0)
				getrawmonotonic(&metadata.tspec);
				metadata.jiffies = timespec_to_jiffies(&metadata.tspec);
#else
				struct timespec64 tmp_ts64;
				ktime_get_raw_ts64(&tmp_ts64);
				metadata.tspec.tv_sec = tmp_ts64.tv_sec;
				metadata.tspec.tv_nsec = tmp_ts64.tv_nsec;
				metadata.jiffies = timespec64_to_jiffies(&tmp_ts64);
#endif /* LINUX_VERSION_CODE */
				earlyvb_set_prv_data(blk, sizeof(struct earlyvideo_metadata), (void *)&metadata);

				if (i + 1 == shm_info->segments[path].uboot_capture_num) {
					list_add_tail(&blk->lblk, &pool->lused_head);
					drvdata->path[path].blk = blk;
				} else {
					list_add_tail(&blk->lblk, &pool->lfifo_head);
					drvdata->path[path].frame_cnt++;
				}
			}
		}
		pool->available_blk_num = pool->blk_num;
	}

	return 0;
}

struct vb_block *earlyvb_try_alloc(uint8_t path)
{
	struct earlyvb_pool *pool = NULL;
	struct vb_block *blk = NULL;
	unsigned long flags = 0;

	/* Check argument */
	if (path >= EARLYVIDEO_MAX_PATH_NUM) {
		return NULL;
	}
	pool = &g_drvdata->path[path].vb_pool;

	spin_lock_irqsave(&pool->lock, flags);
	if (list_empty(&pool->lavail_head)) {
		/* The available list is empty; allocate block according to the strategy */
		switch (pool->strategy) {
		case EARLYVB_ALLOC_STRATEGY_OVERWRITE_TAIL:
			/* Return NULL to overwrite the current block */
			break;
		case EARLYVB_ALLOC_STRATEGY_OVERWRITE_HEAD:
			if (!list_empty(&pool->lfifo_head)) {
				blk = list_first_entry(&pool->lfifo_head, struct vb_block, lblk);
				if (blk->private_data) {
					kfree(blk->private_data);
					blk->private_data = NULL;
				}
				list_move_tail(&blk->lblk, &pool->lused_head);
			}
			break;
		default:
			BUG();
			break;
		}
	} else {
		/* Allocate block from the available list */
		blk = list_first_entry(&pool->lavail_head, struct vb_block, lblk);
		list_move_tail(&blk->lblk, &pool->lused_head);
	}
	spin_unlock_irqrestore(&pool->lock, flags);

	return blk;
}
EXPORT_SYMBOL(earlyvb_try_alloc);

/**
 * @brief Free a block from earlyvb pool.
 * @param[in] blk       The vb_block to be freed.
 * @param[in] strategy  The strategy to decide whether to force the reuse of this vb_block or not.
 * @retval 1  All non-necessary vb_blocks are released.
 * @retval 0  Some vb_blocks will still be reused.
 */
int earlyvb_free(struct vb_block *blk, uint8_t strategy)
{
	struct earlyvb_pool *pool = (struct earlyvb_pool *)blk->pool;
	unsigned long flags = 0;

	BUG_ON(!blk);

	spin_lock_irqsave(&pool->lock, flags);

	/* Free private_data */
	if (blk->private_data) {
		kfree(blk->private_data);
		blk->private_data = NULL;
	}

	/* Determine whether to free or return this blk to available list */
	if (strategy == EARLYVB_FREE_STRATEGY_NORMAL &&
	    (blk->id >= pool->keep_blk_num && !list_empty(&pool->lavail_head))) {
		list_del(&blk->lblk);
		pool->available_blk_num--;
		if (pool->available_blk_num == pool->keep_blk_num) {
			struct earlyvideo_path_info *path_info =
			        container_of(pool, struct earlyvideo_path_info, vb_pool);
			struct earlyvideo_shm_segment *segment = &g_drvdata->shm_addr->segments[path_info->idx];
			uint32_t keep_size = pool->keep_blk_num * pool->blk_size;
			bool all_release = true;
			int i;

			free_reserved_area(__va(segment->raw_addr + keep_size),
			                   __va(segment->raw_addr + segment->pool_size), -1, NULL);
			printk("Release the early video buffer of path %u, except for the necessary %u blocks\n",
			       path_info->idx, pool->keep_blk_num);
			/* Free the page used to store information between U-Boot and the Linux early video driver */
			for (i = 0; i < EARLYVIDEO_MAX_PATH_NUM; i++) {
				if (g_drvdata->path[i].vb_pool.available_blk_num !=
				    g_drvdata->path[i].vb_pool.keep_blk_num) {
					all_release = false;
				}
			}
			if (all_release) {
				/* Free the memory for early detection */
				if (g_ubootenv_fal_alarm_debug == 0) {
					for (i = 0; i < EARLYVIDEO_MAX_PATH_NUM; i++) {
						struct earlyvideo_shm_segment *segment =
						        &g_drvdata->shm_addr->segments[i];
						if (segment->early_detect_info.is_used &&
						    (segment->base_addr != segment->raw_addr)) {
							free_reserved_area(__va(segment->base_addr),
							                   __va(segment->raw_addr), -1, NULL);
						}
					}
				}
				/* Free the shared memory */
				free_reserved_area(__va(g_ubootenv_early_vb_memaddr),
				                   __va(g_ubootenv_early_vb_memaddr + EV_DRIVER_SHM_SIZE), -1, NULL);
			}
		}
	} else {
		list_move_tail(&blk->lblk, &pool->lavail_head);
	}

	spin_unlock_irqrestore(&pool->lock, flags);

	return (pool->available_blk_num == pool->keep_blk_num);
}
EXPORT_SYMBOL(earlyvb_free);

int earlyvb_try_write(struct vb_block *blk)
{
	struct earlyvb_pool *pool = (struct earlyvb_pool *)blk->pool;
	unsigned long flags = 0;

	if (!blk) {
		WARN_ON(!blk);
		return -EINVAL;
	}

	spin_lock_irqsave(&pool->lock, flags);

	/* Put block into FIFO */
	list_move_tail(&blk->lblk, &pool->lfifo_head);

	spin_unlock_irqrestore(&pool->lock, flags);
	return 0;
}
EXPORT_SYMBOL(earlyvb_try_write);

struct vb_block *earlyvb_try_read(uint8_t path)
{
	struct vb_block *blk = NULL;
	struct earlyvb_pool *pool = NULL;
	unsigned long flags = 0;

	/* Check argument */
	if (path >= EARLYVIDEO_MAX_PATH_NUM) {
		return NULL;
	}
	pool = &g_drvdata->path[path].vb_pool;

	spin_lock_irqsave(&pool->lock, flags);
	if (!list_empty(&pool->lfifo_head)) {
		/* The FIFO list is not empty, get a block from it */
		blk = list_first_entry(&pool->lfifo_head, struct vb_block, lblk);
		list_move_tail(&blk->lblk, &pool->lused_head);
	}
	spin_unlock_irqrestore(&pool->lock, flags);

	return blk;
}
EXPORT_SYMBOL(earlyvb_try_read);

int earlyvb_get_blk_num(uint8_t path)
{
	struct earlyvb_pool *pool;

	/* Check argument */
	if (path >= EARLYVIDEO_MAX_PATH_NUM) {
		return -EINVAL;
	}

	pool = &g_drvdata->path[path].vb_pool;
	return pool->blk_num;
}
EXPORT_SYMBOL(earlyvb_get_blk_num);

struct vb_block *earlyvb_get_blks(uint8_t path)
{
	struct earlyvb_pool *pool;

	/* Check argument */
	if (path >= EARLYVIDEO_MAX_PATH_NUM) {
		return NULL;
	}

	pool = &g_drvdata->path[path].vb_pool;
	return pool->blk;
}
EXPORT_SYMBOL(earlyvb_get_blks);

/**
 * @brief This function will return the usage status of earlyvb of the specified path
 * @see earlyvb_init()
 * @see earlyvb_free()
 */
int earlyvb_get_curr_usage(uint8_t path, uint32_t *curr_usage, uint8_t *release)
{
	struct earlyvb_pool *pool = NULL;
	unsigned long flags = 0;

	/* Check argument */
	if (path >= EARLYVIDEO_MAX_PATH_NUM) {
		pr_err("Try to query earlyvb usage of an invalid path %d!\n", path);
		return -EINVAL;
	}
	pool = &g_drvdata->path[path].vb_pool;
	*curr_usage = 0;

	spin_lock_irqsave(&pool->lock, flags);
	if (pool->available_blk_num == pool->keep_blk_num) {
		*curr_usage = pool->keep_blk_num * pool->blk_size;
	} else {
		*curr_usage = pool->pool_size;
	}

	*release = (*curr_usage == 0 || pool->available_blk_num == pool->keep_blk_num) ? 1 : 0;
	spin_unlock_irqrestore(&pool->lock, flags);

	return 0;
}
EXPORT_SYMBOL(earlyvb_get_curr_usage);

/**
 * @brief Drops pre-roll frames and checks if all frames have been dropped
 * @see earlyvideo_stop()
 * @see earlyvideo_irq_handler()
 */
void earlyvb_force_drop(uint8_t path, int32_t drop_num, bool *all_frame_dropped, uint32_t *inttime, uint32_t *sys_gain)
{
	struct earlyvb_pool *pool = NULL;
	unsigned long flags = 0;
	int i;

	/* Check argument */
	if (path >= EARLYVIDEO_MAX_PATH_NUM || (g_drvdata->sensor_bmp & BIT(path)) == 0) {
		pr_err("Try to drop pre-roll frames for an invalid path %d!\n", path);
		return;
	}

	spin_lock_irqsave(&g_drvdata->status_lock, flags);
	pool = &g_drvdata->path[path].vb_pool;
	pool->force_drop_num = drop_num;

	/* Set the exposure parameter to prevent the first frame from being too dark */
	*inttime = g_drvdata->shm_addr->segments[path].exps_time_us;
	*sys_gain = g_drvdata->shm_addr->segments[path].gain32;

	/* Check if all frames have been dropped */
	g_drvdata->destroy_all_pools = true;
	for (i = 0; i < EARLYVIDEO_MAX_PATH_NUM; i++) {
		pool = &g_drvdata->path[i].vb_pool;
		if (g_drvdata->sensor_bmp & BIT(i) &&
		    (pool->force_drop_num <= 0 || pool->blk_num > pool->force_drop_num)) {
			g_drvdata->destroy_all_pools = false;
		}
	}
	*all_frame_dropped = g_drvdata->destroy_all_pools;
	spin_unlock_irqrestore(&g_drvdata->status_lock, flags);

	if (g_drvdata->destroy_all_pools) {
		earlyvideo_stop();
	}
}
EXPORT_SYMBOL(earlyvb_force_drop);

int earlyvb_set_prv_data(struct vb_block *blk, uint32_t size, void *prv_data)
{
	BUG_ON(!blk);
	BUG_ON(blk->private_data != NULL);

	blk->private_data = kmalloc(size, GFP_ATOMIC);
	if (blk->private_data == NULL) {
		return -ENOMEM;
	}
	memcpy(blk->private_data, prv_data, size);

	return 0;
}
EXPORT_SYMBOL(earlyvb_set_prv_data);

static void is_trigger_frame(struct earlyvideo_drvdata *drvdata, uint8_t path)
{
	struct earlyvideo_csr *csr = &drvdata->csr;
	struct video_param *param = &drvdata->path[path].param;

	if (!drvdata->path[path].blk) {
		pr_err("Attempted to trigger the next frame, but the output block is not set for path %d!\n", path);
		BUG();
	}
#ifdef EARLYVIDEO_CSR_V1
	/* Update DA write address */
	csr->iswroi[path]->ini_addr_linear_0 = drvdata->path[path].blk->phy_addr >> 3;

	/* The height setting may initially be (frame_height * uboot_capture_num) */
	csr->iswroi[path]->height = param->path_height;
	csr->iswroi[path]->v_end = param->path_height - 1;
	csr->edp[path]->height = param->path_height;
	csr->frame_time_gen[path]->height = param->path_height;

	/* Trigger hardware */
	csr->iswroi[path]->frame_start = 1;
	csr->edp[path]->frame_start = 1;
	csr->frame_time_gen[path]->frame_start = 1;
#elif defined(EARLYVIDEO_CSR_V2)
	/* Update DA write address */
	csr->isw[path]->ini_addr_linear_0 = drvdata->path[path].blk->phy_addr >> 3;

	/* The height setting may initially be (frame_height * uboot_capture_num) */
	csr->isw[path]->height = param->path_height;
	csr->isw[path]->v_end = param->path_height - 1;
	csr->edp[path]->height = param->path_height;
	csr->tg[path]->height = param->path_height;

	/* Trigger hardware */
	csr->isw[path]->frame_start = 1;
	csr->edp[path]->frame_start = 1;
	csr->tg[path]->frame_start = 1;
#endif
}

#define fps_to_jiffies(fps) ((fps) > 0 ? msecs_to_jiffies(1000 / fps) : 0)
static void earlyvideo_wdt_work(struct work_struct *work)
{
	struct earlyvideo_path_info *path_info = container_of(work, struct earlyvideo_path_info, wdt_work);
	long wait_jiffies = 3 * fps_to_jiffies(g_drvdata->shm_addr->segments[path_info->idx].fps);
	unsigned long timeout;

	while (g_drvdata->status == EARLYVIDEO_STATUS_RUNNING) {
		reinit_completion(&path_info->wdt_completion);
		timeout = wait_for_completion_timeout(&path_info->wdt_completion, wait_jiffies);

		if (timeout == 0) {
			g_drvdata->sensor_bmp &= ~BIT(path_info->idx);
		}
	}
}

static irqreturn_t earlyvideo_irq_handler(int irq, void *dev_id)
{
	struct earlyvideo_drvdata *drvdata = (struct earlyvideo_drvdata *)dev_id;
	struct earlyvideo_csr *csr = &drvdata->csr;
	struct vb_block *blk = NULL;

	if (drvdata->status == EARLYVIDEO_STATUS_RELEASING && drvdata->sensor_bmp == 0) {
		return IRQ_HANDLED;
	}

	/* SENIF irq */
	if (irq == drvdata->irq[SENIF_IRQ_DEC0] || irq == drvdata->irq[SENIF_IRQ_DEC1]) {
		uint8_t path = irq == drvdata->irq[SENIF_IRQ_DEC0] ? 0 : 1;
		volatile struct csr_bank_senif_syscfg *senif_syscfg = csr->senif_syscfg;
		volatile struct csr_bank_dec *lvds_dec = csr->lvds_dec[path];
		uint32_t status = lvds_dec->irqsta;

		drvdata->sensor_bmp |= BIT(path);
		complete(&drvdata->path[path].wdt_completion);

		if (status & SENIF_IRQ_DEC_FRAME_DONE) {
			lvds_dec->irqack = SENIF_IRQ_DEC_FRAME_DONE;
			drvdata->path[path].senif_state |= SENIF_STATE_FRAME_DONE;
		}
		if (status & SENIF_IRQ_DEC_FRAME_END) {
			lvds_dec->irqack = SENIF_IRQ_DEC_FRAME_END;
			drvdata->path[path].senif_state |= SENIF_STATE_FRAME_END;
		}
		if ((drvdata->path[path].senif_state & SENIF_STATE_FRAME_DONE) &&
		    (drvdata->path[path].senif_state & SENIF_STATE_FRAME_END)) {
#ifdef EARLYVIDEO_CSR_V1
			if (path == 0) {
				senif_syscfg->lv_rst_dec0_senif_clk = 1;
				senif_syscfg->lv_rst_dec0_out_clk = 1;
				senif_syscfg->sw_rst_slb0_out_clk = 1;
				senif_syscfg->lv_rst_dec0_senif_clk = 0;
				senif_syscfg->lv_rst_dec0_out_clk = 0;
			} else if (path == 1) {
				senif_syscfg->lv_rst_dec1_senif_clk = 1;
				senif_syscfg->lv_rst_dec1_out_clk = 1;
				senif_syscfg->sw_rst_slb1_out_clk = 1;
				senif_syscfg->lv_rst_dec1_senif_clk = 0;
				senif_syscfg->lv_rst_dec1_out_clk = 0;
			}
#elif defined(EARLYVIDEO_CSR_V2)
			if (path == 0) {
				senif_syscfg->lv_rst_dec0_senif = 1;
				senif_syscfg->lv_rst_dec0_out = 1;
				senif_syscfg->lv_rst_slb0_out = 1;
				senif_syscfg->lv_rst_slb0_out = 0;
				senif_syscfg->lv_rst_dec0_out = 0;
				senif_syscfg->lv_rst_dec0_senif = 0;
			} else if (path == 1) {
				senif_syscfg->lv_rst_dec1_senif = 1;
				senif_syscfg->lv_rst_dec1_out = 1;
				senif_syscfg->lv_rst_slb1_out = 1;
				senif_syscfg->lv_rst_slb1_out = 0;
				senif_syscfg->lv_rst_dec1_out = 0;
				senif_syscfg->lv_rst_dec1_senif = 0;
			}
#endif
			is_trigger_frame(drvdata, path);

			/* Only jump into senif irq once */
			lvds_dec->irqmsk = SENIF_IRQ_DEC_MASK_ALL;
			drvdata->path[path].senif_state = SENIF_STATE_RUNNING;
		}
#ifdef EARLYVIDEO_CSR_V1
	} else if (irq == drvdata->irq[IS_IRQ_ISWROI0] || irq == drvdata->irq[IS_IRQ_ISWROI1]) {
		uint8_t path = irq == drvdata->irq[IS_IRQ_ISWROI0] ? 0 : 1;
		volatile struct csr_bank_pxw *iswroi = csr->iswroi[path];
		struct earlyvideo_shm_info *shm_info = drvdata->shm_addr;
		struct earlyvideo_metadata metadata;

		iswroi->irq_clear_frame_end = 1;
#elif defined(EARLYVIDEO_CSR_V2)
	} else if (irq == drvdata->irq[IS_IRQ_ISW0] || irq == drvdata->irq[IS_IRQ_ISW1]) {
		uint8_t path = irq == drvdata->irq[IS_IRQ_ISW0] ? 0 : 1;
		volatile struct csr_bank_pxw *isw = csr->isw[path];
		struct earlyvideo_shm_info *shm_info = drvdata->shm_addr;
		struct earlyvideo_metadata metadata;

		isw->irq_clear_frame_end = 1;
#endif
		drvdata->sensor_bmp |= BIT(path);
		complete(&drvdata->path[path].wdt_completion);

		if (drvdata->path[path].frame_cnt++ == 0) {
			printk("1st frame[%d]\n", path);
		}

		/* Allocate the next output vb_block */
		blk = earlyvb_try_alloc(path);
		if (blk) {
			/* Update metadata */
			metadata.fps = shm_info->segments[path].fps;
			metadata.inttime = shm_info->segments[path].exps_time_us;
			metadata.sys_gain = shm_info->segments[path].gain32;
#if LINUX_VERSION_CODE < KERNEL_VERSION(5, 6, 0)
			getrawmonotonic(&metadata.tspec);
			metadata.jiffies = timespec_to_jiffies(&metadata.tspec);
#else
			struct timespec64 tmp_ts64;
			ktime_get_raw_ts64(&tmp_ts64);
			metadata.tspec.tv_sec = tmp_ts64.tv_sec;
			metadata.tspec.tv_nsec = tmp_ts64.tv_nsec;
			metadata.jiffies = timespec64_to_jiffies(&tmp_ts64);
#endif /* LINUX_VERSION_CODE */
			earlyvb_set_prv_data(drvdata->path[path].blk, sizeof(struct earlyvideo_metadata),
			                     (void *)&metadata);

			/* Write block */
			earlyvb_try_write(drvdata->path[path].blk);

			drvdata->path[path].blk = blk;
		} else {
			/* Overwrite the current block */
		}

		/* Trigger next frame */
		if (drvdata->status == EARLYVIDEO_STATUS_RUNNING) {
			is_trigger_frame(drvdata, path);
		}

		/* Handle stop procedure */
		if (drvdata->status == EARLYVIDEO_STATUS_STOPPING) {
#ifdef EARLYVIDEO_CSR_V1
			iswroi->irq_mask_frame_end = 1;

			drvdata->sensor_bmp &= ~BIT(path);

			/* Stop SENIF */
			csr->rxphy_ctrl[path]->ctrl_1 = csr->lvds_rx[path]->lane_en | csr->lvds_rx[path]->lane_ck_en;
			csr->lvds_rx[path]->rx_en = 0;
			csr->lvds_dec[path]->dec_en = 0;
			csr->slb[path]->enable = 0;
			if (path == 0) {
				csr->senif_syscfg->sw_rst_rx0_senif_clk = 1;
				csr->senif_syscfg->lv_rst_dec0_senif_clk = 1;
				csr->senif_syscfg->lv_rst_dec0_out_clk = 1;
				csr->senif_syscfg->sw_rst_slb0_out_clk = 1;
				csr->senif_syscfg->lv_rst_dec0_senif_clk = 0;
				csr->senif_syscfg->lv_rst_dec0_out_clk = 0;
			} else if (path == 1) {
				csr->senif_syscfg->sw_rst_rx1_senif_clk = 1;
				csr->senif_syscfg->lv_rst_dec1_senif_clk = 1;
				csr->senif_syscfg->lv_rst_dec1_out_clk = 1;
				csr->senif_syscfg->sw_rst_slb1_out_clk = 1;
				csr->senif_syscfg->lv_rst_dec1_senif_clk = 0;
				csr->senif_syscfg->lv_rst_dec1_out_clk = 0;
			}
#elif defined(EARLYVIDEO_CSR_V2)
			isw->irq_mask_frame_end = 1;

			drvdata->sensor_bmp &= ~BIT(path);

			/* Stop SENIF */
			csr->lvds_dec[path]->dec_en = 0;
			csr->slb[path]->enable = 0;
			if (path == 0) {
				csr->senif_syscfg->lv_rst_dec0_senif = 1;
				csr->senif_syscfg->lv_rst_dec0_out = 1;
				csr->senif_syscfg->lv_rst_slb0_out = 1;
				csr->senif_syscfg->lv_rst_slb0_out = 0;
				csr->senif_syscfg->lv_rst_dec0_out = 0;
				csr->senif_syscfg->lv_rst_dec0_senif = 0;
			} else if (path == 1) {
				csr->senif_syscfg->lv_rst_dec1_senif = 1;
				csr->senif_syscfg->lv_rst_dec1_out = 1;
				csr->senif_syscfg->lv_rst_slb1_out = 1;
				csr->senif_syscfg->lv_rst_slb1_out = 0;
				csr->senif_syscfg->lv_rst_dec1_out = 0;
				csr->senif_syscfg->lv_rst_dec1_senif = 0;
			}
#endif
			drvdata->path[path].senif_state = SENIF_STATE_IDLE;

			if (drvdata->sensor_bmp == 0) {
				printk("Early video stop from status %d, frame count %u/%u\n", drvdata->status,
				       drvdata->path[0].frame_cnt, drvdata->path[1].frame_cnt);
				drvdata->status = EARLYVIDEO_STATUS_RELEASING;
#ifdef EARLYVIDEO_CSR_V2
				csr->rxphy_ctrl->ctrl_1 = csr->lvds_rx->lane_en | csr->lvds_rx->lane_ck_en;
				csr->lvds_rx->rx_en = 0;
				csr->senif_syscfg->lv_rst_rx0_senif = 1;
				csr->senif_syscfg->lv_rst_rx0_senif = 0;
#endif
				/* Drop the specified number of frames from each pool */
				for (path = 0; path < EARLYVIDEO_MAX_PATH_NUM; path++) {
					struct earlyvb_pool *pool = &drvdata->path[path].vb_pool;

					if (drvdata->destroy_all_pools) {
						struct earlyvideo_shm_segment *segment =
						        &g_drvdata->shm_addr->segments[path];
						int i;

						for (i = 0; i < pool->blk_num; i++) {
							blk = pool->blk + i;
							if (blk->private_data) {
								kfree(blk->private_data);
							}
							list_del(&blk->lblk);
						}
						pool->keep_blk_num = 0;
						pool->available_blk_num = 0;
						kfree(pool->blk);
						free_reserved_area(__va(segment->raw_addr),
						                   __va(segment->raw_addr + segment->pool_size), -1,
						                   NULL);
						/* Free the snapshot memory */
						if (g_ubootenv_fal_alarm_debug == 0) {
							if (segment->early_detect_info.is_used &&
							    (segment->base_addr != segment->raw_addr)) {
								free_reserved_area(__va(segment->base_addr),
								                   __va(segment->raw_addr), -1, NULL);
							}
						}
						/* Free the shared memory */
						if (path == (EARLYVIDEO_MAX_PATH_NUM - 1)) {
							free_reserved_area(
							        __va(g_ubootenv_early_vb_memaddr),
							        __va(g_ubootenv_early_vb_memaddr + EV_DRIVER_SHM_SIZE),
							        -1, NULL);
							printk("Release all early video buffers and destroy the pools\n");
						}
					} else {
						/* Please refer to #87953-8 for the behavior when dropping frames partially */
						struct vb_block *tmp_blk = NULL;
						int tmp_num = pool->blk_num;

						/* Drop the frames from the head or end of the list */
						if (pool->force_drop_num > 0) {
							list_for_each_entry_safe_reverse (blk, tmp_blk,
							                                  &pool->lfifo_head, lblk) {
								if (pool->force_drop_num <= 0) {
									break;
								}
								earlyvb_free(blk, EARLYVB_FREE_STRATEGY_NORMAL);
								pool->force_drop_num--;
							}
						} else if (pool->force_drop_num < 0) {
							pool->force_drop_num += earlyvb_count_list(&pool->lfifo_head);
							list_for_each_entry_safe (blk, tmp_blk, &pool->lfifo_head,
							                          lblk) {
								if (pool->force_drop_num <= 0) {
									break;
								}
								earlyvb_free(blk, EARLYVB_FREE_STRATEGY_NORMAL);
								pool->force_drop_num--;
							}
						} else {
							/* Do nothing when pool->force_drop_num == 0 */
						}

						/* Free all the unused blocks */
						list_for_each_entry_safe (blk, tmp_blk, &pool->lavail_head, lblk) {
							if (tmp_num <= 0) {
								/* Avoid an infinite loop */
								break;
							}
							earlyvb_free(blk, EARLYVB_FREE_STRATEGY_NORMAL);
							tmp_num--;
						}

						/* Free the block that is about to be used */
						if (drvdata->path[path].blk) {
							earlyvb_free(drvdata->path[path].blk,
							             EARLYVB_FREE_STRATEGY_NORMAL);
						}
					}
				}
				/* Disable all SENIF clocks after the early video driver has been stopped */
#ifdef EARLYVIDEO_CSR_V1
				csr->senif_syscfg->cken_rx0 = 0;
				csr->senif_syscfg->cken_rx1 = 0;
				csr->senif_syscfg->cken_dec0 = 0;
				csr->senif_syscfg->cken_dec1 = 0;
				csr->senif_syscfg->cken_ps = 0;
				csr->senif_syscfg->cken_slb1 = 0; /* Do not disable SLB0 */
#elif defined(EARLYVIDEO_CSR_V2)
				csr->senif_syscfg->cken_rx0_senif = 0;
				csr->senif_syscfg->cken_ps_senif = 0;
				csr->senif_syscfg->cken_dec0_senif = 0;
				csr->senif_syscfg->cken_dec1_senif = 0;
				csr->senif_syscfg->cken_ps_out = 0;
				csr->senif_syscfg->cken_spi_out = 0;
				csr->senif_syscfg->cken_dec0_out = 0;
				csr->senif_syscfg->cken_dec1_out = 0;
				csr->senif_syscfg->cken_slb1_out = 0;
#if defined(CONFIG_SAPPORO)
				csr->is_cfg->cken_isw0_d = 0;
				csr->is_cfg->cken_isw0_k = 0;
				csr->is_cfg->cken_isw0_ref = 0;
				csr->is_cfg->cken_isw1_d = 0;
				csr->is_cfg->cken_isw1_k = 0;
				csr->is_cfg->cken_isw1_ref = 0;
				csr->is_cfg->cken_isw2_d = 0;
				csr->is_cfg->cken_isw2_k = 0;
				csr->is_cfg->cken_isw2_ref = 0;
				csr->is_cfg->cken_isw3_d = 0;
				csr->is_cfg->cken_isw3_k = 0;
				csr->is_cfg->cken_isw3_ref = 0;
				csr->is_cfg->cken_isr0_d = 0;
				csr->is_cfg->cken_isr0_k = 0;
				csr->is_cfg->cken_isr1_d = 0;
				csr->is_cfg->cken_isr1_k = 0;
				csr->is_cfg->cken_fe0_k = 0;
				csr->is_cfg->cken_fe0_ref = 0;
				csr->is_cfg->cken_fe1_k = 0;
				csr->is_cfg->cken_fe1_ref = 0;
				csr->isk_cfg[0]->cken_cvs_k = 0;
				csr->isk_cfg[0]->cken_crop_k = 0;
				csr->isk_cfg[0]->cken_bsp_k = 0;
				csr->isk_cfg[0]->cken_fsc_k = 0;
				csr->isk_cfg[1]->cken_cvs_k = 0;
				csr->isk_cfg[1]->cken_crop_k = 0;
				csr->isk_cfg[1]->cken_bsp_k = 0;
				csr->isk_cfg[1]->cken_fsc_k = 0;
				csr->is_cfg->cken_isk0_d = 0;
				csr->is_cfg->cken_isk0_k = 0;
				csr->is_cfg->cken_isk1_d = 0;
				csr->is_cfg->cken_isk1_k = 0;
				csr->is_cfg->cken_bspshb_k = 0;
				csr->is_cfg->cken_fscshb_k = 0;
				csr->is_cfg->cken_checksum_d = 0;
				csr->is_cfg->cken_checksum_k = 0;
#elif defined(CONFIG_OSAKA)
				csr->is_cfg->cken_isw0_d = 0;
				csr->is_cfg->cken_isw0_k = 0;
				csr->is_cfg->cken_isw0_ref = 0;
				csr->is_cfg->cken_isw1_d = 0;
				csr->is_cfg->cken_isw1_k = 0;
				csr->is_cfg->cken_isw1_ref = 0;
				csr->is_cfg->cken_isw2_d = 0;
				csr->is_cfg->cken_isw2_k = 0;
				csr->is_cfg->cken_isw2_ref = 0;
				csr->is_cfg->cken_isw3_d = 0;
				csr->is_cfg->cken_isw3_k = 0;
				csr->is_cfg->cken_isw3_ref = 0;
				csr->is_cfg->cken_isw4_d = 0;
				csr->is_cfg->cken_isw4_k = 0;
				csr->is_cfg->cken_isw4_ref = 0;
				csr->is_cfg->cken_isw5_d = 0;
				csr->is_cfg->cken_isw5_k = 0;
				csr->is_cfg->cken_isw5_ref = 0;
				csr->is_cfg->cken_isr0_d = 0;
				csr->is_cfg->cken_isr0_k = 0;
				csr->is_cfg->cken_isr1_d = 0;
				csr->is_cfg->cken_isr1_k = 0;
				csr->is_cfg->cken_fe0_k = 0;
				csr->is_cfg->cken_fe0_ref = 0;
				csr->is_cfg->cken_fe1_k = 0;
				csr->is_cfg->cken_fe1_ref = 0;
				csr->isk_cfg[0]->cken_cvs_k = 0;
				csr->isk_cfg[0]->cken_crop_k = 0;
				csr->isk_cfg[0]->cken_bsp_k = 0;
				csr->isk_cfg[0]->cken_fsc0_k = 0;
				csr->isk_cfg[0]->cken_fsc1_k = 0;
				csr->isk_cfg[1]->cken_cvs_k = 0;
				csr->isk_cfg[1]->cken_crop_k = 0;
				csr->isk_cfg[1]->cken_bsp_k = 0;
				csr->isk_cfg[1]->cken_fsc0_k = 0;
				csr->isk_cfg[1]->cken_fsc1_k = 0;
				csr->is_cfg->cken_isk0_d = 0;
				csr->is_cfg->cken_isk0_k = 0;
				csr->is_cfg->cken_isk1_d = 0;
				csr->is_cfg->cken_isk1_k = 0;
				csr->is_cfg->cken_bspshb_k = 0;
				csr->is_cfg->cken_fsc0_fscshb_k = 0;
				csr->is_cfg->cken_fsc1_fscshb_k = 0;
				csr->is_cfg->cken_checksum_d = 0;
				csr->is_cfg->cken_checksum_k = 0;
#endif
#endif
				return IRQ_WAKE_THREAD;
			}
		}
	}

	return IRQ_HANDLED;
}

/* The bottom-half IRQ handler handles the callback function and schedule the releases work. */
static irqreturn_t earlyvideo_thread_irq_handler(int irq, void *dev_id)
{
	struct earlyvideo_drvdata *drvdata = (struct earlyvideo_drvdata *)dev_id;
	uint8_t path;

	/* Execute the registered callback functions */
	mutex_lock(&drvdata->senif_cb_lock);
	for (path = 0; path < EARLYVIDEO_MAX_PATH_NUM; path++) {
		if (drvdata->earlyvideo_cb_senif[path]) {
			drvdata->earlyvideo_cb_senif[path](path);
			drvdata->earlyvideo_cb_senif[path] = NULL;
		}
	}
	mutex_unlock(&drvdata->senif_cb_lock);

	mutex_lock(&drvdata->is_cb_lock);
	if (drvdata->earlyvideo_cb_is) {
		drvdata->earlyvideo_cb_is();
		drvdata->earlyvideo_cb_is = NULL;
	}
	mutex_unlock(&drvdata->is_cb_lock);

	if (drvdata->status != EARLYVIDEO_STATUS_IDLE) {
		schedule_work(&drvdata->release_work);
	}

	return IRQ_HANDLED;
}

/* The bottom-half work releases resources. */
static void earlyvideo_release_work(struct work_struct *work)
{
	struct earlyvideo_drvdata *drvdata = container_of(work, struct earlyvideo_drvdata, release_work);
	int i;

	/* Remove IRQ handler */
	for (i = 0; i < EARLYVIDEO_IRQ_NUM; i++) {
		devm_free_irq(drvdata->dev, drvdata->irq[i], drvdata);
	}

	/* Unmap CSR IO memory */
	devm_iounmap(drvdata->dev, drvdata->vaddr);

	drvdata->status = EARLYVIDEO_STATUS_IDLE;
}

#ifdef EARLYVIDEO_CSR_V1
static void earlyvideo_init_csr(struct earlyvideo_drvdata *drvdata)
{
	struct earlyvideo_csr *csr = &drvdata->csr;

#define SENIF_OFFSET (0x500000)
#define SENIF_SYSCFG_OFFSET (0x70000)
#define SENIF_SLB0_OFFSET (0x50000)
#define SENIF_SLB1_OFFSET (0x60000)
#define SENIF_LVDS0_RX_OFFSET (0x20000)
#define SENIF_LVDS1_RX_OFFSET (0x30000)
#define SENIF_LVDS0_DEC_OFFSET (0x20400)
#define SENIF_LVDS1_DEC_OFFSET (0x30400)
#define SENIF_RXPHY0_RX_CTRL_OFFSET (0x400)
#define SENIF_RXPHY1_RX_CTRL_OFFSET (0x10400)

#define IS_OFFSET (0)
#define IS_CFG_OFFSET (0x400)
#define IS_ISWROI0_OFFSET (0x80000)
#define IS_ISWROI1_OFFSET (0x90000)
#define IS_PG0_FRAME_TIME_GEN_OFFSET (0x20400)
#define IS_PG1_FRAME_TIME_GEN_OFFSET (0x50400)
#define IS_EDP0_OFFSET (0x40000)
#define IS_EDP1_OFFSET (0x70000)

	void *senif_base = drvdata->vaddr + SENIF_OFFSET;
	void *is_base = drvdata->vaddr + IS_OFFSET;

	/* SENIF */
	csr->senif_syscfg = (volatile CsrBankSenif_syscfg *)(senif_base + SENIF_SYSCFG_OFFSET);
	csr->slb[0] = (volatile CsrBankSlb *)(senif_base + SENIF_SLB0_OFFSET);
	csr->slb[1] = (volatile CsrBankSlb *)(senif_base + SENIF_SLB1_OFFSET);
	csr->lvds_rx[0] = (volatile CsrBankRx *)(senif_base + SENIF_LVDS0_RX_OFFSET);
	csr->lvds_rx[1] = (volatile CsrBankRx *)(senif_base + SENIF_LVDS1_RX_OFFSET);
	csr->lvds_dec[0] = (volatile CsrBankDec *)(senif_base + SENIF_LVDS0_DEC_OFFSET);
	csr->lvds_dec[1] = (volatile CsrBankDec *)(senif_base + SENIF_LVDS1_DEC_OFFSET);
	csr->rxphy_ctrl[0] = (volatile CsrBankRx_ctrl *)(senif_base + SENIF_RXPHY0_RX_CTRL_OFFSET);
	csr->rxphy_ctrl[1] = (volatile CsrBankRx_ctrl *)(senif_base + SENIF_RXPHY1_RX_CTRL_OFFSET);

	/* IS */
	csr->is_cfg = (volatile CsrBankIs_cfg *)(is_base + IS_CFG_OFFSET);
	csr->frame_time_gen[0] = (volatile CsrBankFrame_time_gen *)(is_base + IS_PG0_FRAME_TIME_GEN_OFFSET);
	csr->frame_time_gen[1] = (volatile CsrBankFrame_time_gen *)(is_base + IS_PG1_FRAME_TIME_GEN_OFFSET);
	csr->edp[0] = (volatile CsrBankEdp *)(is_base + IS_EDP0_OFFSET);
	csr->edp[1] = (volatile CsrBankEdp *)(is_base + IS_EDP1_OFFSET);
	csr->iswroi[0] = (volatile CsrBankPxw *)(is_base + IS_ISWROI0_OFFSET);
	csr->iswroi[1] = (volatile CsrBankPxw *)(is_base + IS_ISWROI1_OFFSET);
}
#elif defined(EARLYVIDEO_CSR_V2)
static void earlyvideo_init_csr(struct earlyvideo_drvdata *drvdata)
{
	struct earlyvideo_csr *csr = &drvdata->csr;

#define SENIF_OFFSET (0x500000)
#define SENIF_RXPHY0_RX_CTRL_OFFSET (0x400)
#define SENIF_LVDS0_RX_OFFSET (0x20000)
#define SENIF_LVDS0_DEC_OFFSET (0x20400)
#define SENIF_LVDS1_DEC_OFFSET (0x30000)
#define SENIF_SLB0_OFFSET (0x50000)
#define SENIF_SLB1_OFFSET (0x60000)
#define SENIF_SYSCFG_OFFSET (0x70000)

#define IS_OFFSET (0)
#define IS_CFG_OFFSET (0x400)
#define ISK0_CFG_OFFSET (0x100400)
#define ISK1_CFG_OFFSET (0x180400)
#define IS_FE0_TG_OFFSET (0x20400)
#define IS_FE0_EDP_OFFSET (0x20800)
#define IS_FE1_TG_OFFSET (0x30400)
#define IS_FE1_EDP_OFFSET (0x30800)
#define IS_ISW0_OFFSET (0x60000)
#define IS_ISW1_OFFSET (0x70000)

	void *senif_base = drvdata->vaddr + SENIF_OFFSET;
	void *is_base = drvdata->vaddr + IS_OFFSET;

	/* SENIF */
	csr->rxphy_ctrl = (volatile CsrBankRx_ctrl *)(senif_base + SENIF_RXPHY0_RX_CTRL_OFFSET);
	csr->lvds_rx = (volatile CsrBankRx *)(senif_base + SENIF_LVDS0_RX_OFFSET);
	csr->lvds_dec[0] = (volatile CsrBankDec *)(senif_base + SENIF_LVDS0_DEC_OFFSET);
	csr->lvds_dec[1] = (volatile CsrBankDec *)(senif_base + SENIF_LVDS1_DEC_OFFSET);
	csr->slb[0] = (volatile CsrBankSlb *)(senif_base + SENIF_SLB0_OFFSET);
	csr->slb[1] = (volatile CsrBankSlb *)(senif_base + SENIF_SLB1_OFFSET);
	csr->senif_syscfg = (volatile CsrBankSenif_syscfg *)(senif_base + SENIF_SYSCFG_OFFSET);

	/* IS */
	csr->is_cfg = (volatile CsrBankIs_cfg *)(is_base + IS_CFG_OFFSET);
	csr->isk_cfg[0] = (volatile CsrBankIsk_cfg *)(is_base + ISK0_CFG_OFFSET);
	csr->isk_cfg[1] = (volatile CsrBankIsk_cfg *)(is_base + ISK1_CFG_OFFSET);
	csr->tg[0] = (volatile CsrBankTg *)(is_base + IS_FE0_TG_OFFSET);
	csr->edp[0] = (volatile CsrBankEdp *)(is_base + IS_FE0_EDP_OFFSET);
	csr->tg[1] = (volatile CsrBankTg *)(is_base + IS_FE1_TG_OFFSET);
	csr->edp[1] = (volatile CsrBankEdp *)(is_base + IS_FE1_EDP_OFFSET);
	csr->isw[0] = (volatile CsrBankPxw *)(is_base + IS_ISW0_OFFSET);
	csr->isw[1] = (volatile CsrBankPxw *)(is_base + IS_ISW1_OFFSET);
}
#endif

static int earlyvideo_init(struct earlyvideo_drvdata *drvdata)
{
	struct video_param *param = NULL;
	struct earlyvideo_shm_segment *segment = NULL;
	struct device *dev = drvdata->dev;
	struct resource res;
	uint8_t i;

	/* Initailize CSR address */
	if (of_address_to_resource(dev->of_node, 0, &res)) {
		return -ENODEV;
	}
	drvdata->paddr = res.start;
	drvdata->size = resource_size(&res);
	drvdata->vaddr = devm_ioremap(dev, drvdata->paddr, drvdata->size);
	if (IS_ERR(drvdata->vaddr)) {
		return PTR_ERR(drvdata->vaddr);
	}

	drvdata->shm_addr = __va(g_ubootenv_early_vb_memaddr);

	/* Initialize the sensor bitmap and parameters */
	drvdata->sensor_bmp = 0;
	for (i = 0; i < EARLYVIDEO_MAX_PATH_NUM; i++) {
		segment = &drvdata->shm_addr->segments[i];
		if (segment->pool_size != 0) {
			drvdata->sensor_bmp |= BIT(i);
			param = &drvdata->path[i].param;
			param->bit_depth = ISW_BIT_NUM;
			param->path_width = segment->width;
			param->path_height = segment->height;
		}
		drvdata->path[i].idx = i;
		drvdata->path[i].blk = NULL;
		drvdata->earlyvideo_cb_senif[i] = NULL;
		INIT_WORK(&drvdata->path[i].wdt_work, earlyvideo_wdt_work);
		init_completion(&drvdata->path[i].wdt_completion);
	}

	if (g_ubootenv_early_vb_size &&
	    segment->raw_addr + segment->pool_size != g_ubootenv_early_vb_memaddr + (g_ubootenv_early_vb_size << 20)) {
		/* Free the unused memory if any */
		printk("Free the unused memory from 0x%08x to 0x%08x\n", segment->raw_addr + segment->pool_size,
		       g_ubootenv_early_vb_memaddr + (g_ubootenv_early_vb_size << 20));
		free_reserved_area(__va(segment->raw_addr + segment->pool_size),
		                   __va(g_ubootenv_early_vb_memaddr + (g_ubootenv_early_vb_size << 20)), -1, NULL);
	}

	/* Initialize callback functions' pointer to NULL */
	drvdata->earlyvideo_cb_is = NULL;

	drvdata->destroy_all_pools = false;
	mutex_init(&drvdata->senif_cb_lock);
	mutex_init(&drvdata->is_cb_lock);

	earlyvideo_init_csr(drvdata);

	return 0;
}

static int earlyvideo_start(struct earlyvideo_drvdata *drvdata)
{
	struct earlyvideo_csr *csr = &drvdata->csr;
	struct vb_block *blk = NULL;
	unsigned long flags = 0;
	int i;

	spin_lock_irqsave(&drvdata->status_lock, flags);
	/* Initialize the interrupt handler */
	for (i = 0; i < EARLYVIDEO_IRQ_NUM; i++) {
		drvdata->irq[i] = irq_of_parse_and_map(drvdata->dev->of_node, i);

		if (devm_request_threaded_irq(drvdata->dev, drvdata->irq[i], earlyvideo_irq_handler,
		                              earlyvideo_thread_irq_handler, IRQF_SHARED, DRV_NAME, drvdata)) {
			return -EINVAL;
		}
	}
#ifdef EARLYVIDEO_CSR_V1
	for (i = 0; i < EARLYVIDEO_MAX_PATH_NUM; i++) {
		if (drvdata->sensor_bmp & BIT(i)) {
			if (drvdata->shm_addr->segments[i].uboot_capture_num == 0) {
				blk = earlyvb_try_alloc(i);
				if (!blk) {
					/* Return and keep the status in EARLYVIDEO_STATUS_INITIALIZED */
					return -ENOMEM;
				}
				drvdata->path[i].blk = blk;
				drvdata->csr.lvds_dec[i]->irqmsk &=
				        ~(SENIF_IRQ_DEC_FRAME_DONE | SENIF_IRQ_DEC_FRAME_END);
			} else if (csr->iswroi[i]->status_frame_end) {
				drvdata->path[i].frame_cnt++;
				blk = earlyvb_try_alloc(i);
				if (blk) {
					earlyvb_try_write(drvdata->path[i].blk);
					drvdata->path[i].blk = blk;
				}
				csr->iswroi[i]->irq_clear_frame_end = 1;
				drvdata->csr.lvds_dec[i]->irqmsk &=
				        ~(SENIF_IRQ_DEC_FRAME_DONE | SENIF_IRQ_DEC_FRAME_END);
			} else {
				/* Wait for ISW to capture the assigned frame number, free private date */
				if (drvdata->path[i].blk->private_data) {
					kfree(drvdata->path[i].blk->private_data);
					drvdata->path[i].blk->private_data = NULL;
				}
			}
			csr->iswroi[i]->irq_mask_frame_end = 0;
			drvdata->csr.lvds_dec[i]->irqack = SENIF_IRQ_DEC_MASK_ALL;

			schedule_work(&drvdata->path[i].wdt_work);
		}
	}
#elif defined(EARLYVIDEO_CSR_V2)
	for (i = 0; i < EARLYVIDEO_MAX_PATH_NUM; i++) {
		if (drvdata->sensor_bmp & BIT(i)) {
			if (drvdata->shm_addr->segments[i].uboot_capture_num == 0) {
				blk = earlyvb_try_alloc(i);
				if (!blk) {
					/* Return and keep the status in EARLYVIDEO_STATUS_INITIALIZED */
					return -ENOMEM;
				}
				drvdata->path[i].blk = blk;
				drvdata->csr.lvds_dec[i]->irqmsk &=
				        ~(SENIF_IRQ_DEC_FRAME_DONE | SENIF_IRQ_DEC_FRAME_END);
			} else if (csr->isw[i]->status_frame_end) {
				drvdata->path[i].frame_cnt++;
				blk = earlyvb_try_alloc(i);
				if (blk) {
					earlyvb_try_write(drvdata->path[i].blk);
					drvdata->path[i].blk = blk;
				}
				csr->isw[i]->irq_clear_frame_end = 1;
				drvdata->csr.lvds_dec[i]->irqmsk &=
				        ~(SENIF_IRQ_DEC_FRAME_DONE | SENIF_IRQ_DEC_FRAME_END);
			} else {
				/* Wait for ISW to capture the assigned frame number, free private date */
				if (drvdata->path[i].blk->private_data) {
					kfree(drvdata->path[i].blk->private_data);
					drvdata->path[i].blk->private_data = NULL;
				}
			}
			csr->isw[i]->irq_mask_frame_end = 0;
			drvdata->csr.lvds_dec[i]->irqack = SENIF_IRQ_DEC_MASK_ALL;

			schedule_work(&drvdata->path[i].wdt_work);
		}
	}
#endif
	drvdata->status = EARLYVIDEO_STATUS_RUNNING;
	spin_unlock_irqrestore(&drvdata->status_lock, flags);

	return 0;
}

int earlyvideo_stop(void)
{
	struct earlyvideo_drvdata *drvdata = g_drvdata;
	struct device *dev = drvdata->dev;
	unsigned long flags = 0;
	int i;

	spin_lock_irqsave(&drvdata->status_lock, flags);
	switch (drvdata->status) {
	case EARLYVIDEO_STATUS_RUNNING:
		drvdata->status = EARLYVIDEO_STATUS_STOPPING;
		break;
	case EARLYVIDEO_STATUS_INITIALIZED:
		drvdata->status = EARLYVIDEO_STATUS_IDLE;
		/* Remove IRQ handler */
		for (i = 0; i < EARLYVIDEO_IRQ_NUM; i++) {
			devm_free_irq(dev, drvdata->irq[i], drvdata);
		}

		/* Unmap IO memory */
		devm_iounmap(dev, drvdata->vaddr);
		break;
	case EARLYVIDEO_STATUS_STOPPING:
	case EARLYVIDEO_STATUS_RELEASING:
	case EARLYVIDEO_STATUS_IDLE:
		break;
	default:
		WARN_ON(1);
		break;
	}
	spin_unlock_irqrestore(&drvdata->status_lock, flags);

	return drvdata->status;
}
EXPORT_SYMBOL(earlyvideo_stop);

enum earlyvideo_status earlyvideo_get_status(void)
{
	return g_drvdata->status;
}
EXPORT_SYMBOL(earlyvideo_get_status);

static int earlyvideo_probe(struct platform_device *pdev)
{
	struct earlyvideo_drvdata *drvdata = g_drvdata;
	unsigned long flags;
	int err;

	drvdata->dev = &pdev->dev;
	platform_set_drvdata(pdev, drvdata);
	/* Initialize drvdata and hardware */
	err = earlyvideo_init(drvdata);
	if (err) {
		return err;
	}
	INIT_WORK(&drvdata->release_work, earlyvideo_release_work);

	spin_lock_irqsave(&drvdata->status_lock, flags);
	drvdata->status = EARLYVIDEO_STATUS_INITIALIZED;
	spin_unlock_irqrestore(&drvdata->status_lock, flags);

	/* Initialize early video buffer and trigger start */
	err = earlyvb_init(drvdata);
	if (err) {
		return err;
	}
	earlyvideo_start(drvdata);

	return 0;
}

static int earlyvideo_remove(struct platform_device *pdev)
{
	struct earlyvideo_drvdata *drvdata = platform_get_drvdata(pdev);

	flush_work(&drvdata->release_work);
	flush_work(&drvdata->path[0].wdt_work);
	flush_work(&drvdata->path[1].wdt_work);

	platform_set_drvdata(pdev, NULL);

	return 0;
}

static const struct of_device_id earlyvideo_dt_ids[] = {
	{ .compatible = "augentix,earlyvideo" },
	{},
};
MODULE_DEVICE_TABLE(of, earlyvideo_dt_ids);

static struct platform_driver earlyvideo_platform_driver = {
	.probe = earlyvideo_probe,
	.remove = earlyvideo_remove,
	.driver =
	    {
	        .owner = THIS_MODULE,
	        .name = DRV_NAME,
	        .of_match_table = earlyvideo_dt_ids,
	    },
};

static int __init earlyvideo_module_init(void)
{
	unsigned long flags = 0;
	int ret;

	/* Allocate driver data */
	g_drvdata = kzalloc(sizeof(struct earlyvideo_drvdata), GFP_KERNEL);
	if (g_drvdata == NULL) {
		return -ENOMEM;
	}

	spin_lock_init(&g_drvdata->status_lock);

	/* Initialize the status */
	spin_lock_irqsave(&g_drvdata->status_lock, flags);
	g_drvdata->status = EARLYVIDEO_STATUS_IDLE;
	spin_unlock_irqrestore(&g_drvdata->status_lock, flags);

	/* Register platform driver */
	ret = platform_driver_register(&earlyvideo_platform_driver);
	if (ret) {
		/* Don't care, we need the APIs */
	}

	return 0;
}

static void __exit earlyvideo_module_exit(void)
{
	platform_driver_unregister(&earlyvideo_platform_driver);

	if (g_drvdata) {
		kfree(g_drvdata);
		g_drvdata = NULL;
	}
}

postcore_initcall(earlyvideo_module_init);
module_exit(earlyvideo_module_exit);

MODULE_DESCRIPTION("Augentix early video module");
MODULE_AUTHOR("<henry.liu@augentix.com>");
MODULE_LICENSE("GPL");
