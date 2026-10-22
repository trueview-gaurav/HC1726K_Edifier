#ifndef AUGENTIX_PROC_H
#define AUGENTIX_PROC_H

#include <pthread.h>

struct remoteproc_priv {
	const char *shm_dev_name;
	const char *shm_dev_bus_name;
	struct metal_io_region *ipi_io; /**< pointer to IPI i/o region */
	struct metal_device *shm_dev;
	struct metal_io_region *shm_io;
	struct remoteproc_mem shm_mem; /**< shared memory */
	atomic_int ipi_nokick;
	pthread_mutex_t mut;
	pthread_cond_t cond;
};

/**
 * remoteproc_nitofied - remote processor notified
 *
 * It will check remote processor notified
 *
 * @rproc: remoteproc device to be checked
 *
 * return 1 for notified, 0 for non-notified
 */
int remoteproc_wait(struct remoteproc_priv *rproc, const struct timespec *restrict abstime);

#endif /*AUGENTIX_PROC_H*/
