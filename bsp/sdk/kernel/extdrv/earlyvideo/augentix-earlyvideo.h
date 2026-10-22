#ifndef _AUGENTIX_EARLYVIDEO_H_
#define _AUGENTIX_EARLYVIDEO_H_

/* TODO: Replace with the correct definition at SDK v4.0 */
#if !defined(CONFIG_SAPPORO) && !defined(CONFIG_KAMO) && !defined(CONFIG_OSAKA)
#define EARLYVIDEO_CSR_V1
#else
#define EARLYVIDEO_CSR_V2
#endif

#include <linux/types.h>

#include "mpi_enc.h"
#include "vb.h"

#define EARLYVIDEO_MAX_PATH_NUM (2)

enum earlyvb_free_strategy {
	EARLYVB_FREE_STRATEGY_NORMAL = 0,
	EARLYVB_FREE_STRATEGY_KEEP,
};

enum earlyvideo_status {
	EARLYVIDEO_STATUS_IDLE = 0,
	EARLYVIDEO_STATUS_INITIALIZED, /* IRQ and IOMEM initialized */
	EARLYVIDEO_STATUS_RUNNING,
	EARLYVIDEO_STATUS_STOPPING,
	EARLYVIDEO_STATUS_RELEASING,
};

struct earlyvideo_metadata {
	uint32_t fps; /* ISP, ENC */
	unsigned long jiffies; /* ENC */
	TIMESPEC_S tspec; /* ENC */
	uint32_t inttime; /* DIP */
	uint32_t sys_gain; /* DIP */
};

/* Early video buffer */
struct vb_block *earlyvb_try_alloc(uint8_t path);
struct vb_block *earlyvb_try_read(uint8_t path);
int earlyvb_free(struct vb_block *blk, uint8_t strategy);
int earlyvb_try_write(struct vb_block *blk);
int earlyvb_get_blk_num(uint8_t path);
struct vb_block *earlyvb_get_blks(uint8_t path);
int earlyvb_get_curr_usage(uint8_t path, uint32_t *curr_usage, uint8_t *release);
int earlyvb_set_prv_data(struct vb_block *blk, uint32_t size, void *prv_data);

/* Early video */
int earlyvideo_stop(void);
enum earlyvideo_status earlyvideo_get_status(void);
void earlyvb_force_drop(uint8_t path, int32_t drop_num, bool *all_frame_dropped, uint32_t *inttime, uint32_t *sys_gain);

/* Callback function */
typedef void (*earlyvideo_callback_senif)(uint8_t path);
typedef int (*earlyvideo_callback_is)(void);
int earlyvideo_register_cb_senif(earlyvideo_callback_senif cb_func_ptr, uint8_t path);
int earlyvideo_register_cb_is(earlyvideo_callback_is cb_func_ptr);
int earlyvideo_unregister_cb_senif(uint8_t path);
int earlyvideo_unregister_cb_is(void);

#endif /* _AUGENTIX_EARLYVIDEO_H_ */
