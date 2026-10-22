#ifndef AUGENTIX_PROC_H
#define AUGENTIX_PROC_H

struct remoteproc_priv {
	const char *shm_dev_name;
	const char *shm_dev_bus_name;
	struct metal_device *shm_dev;
	struct metal_io_region *shm_io;
	atomic_int ipi_nokick;
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
int remoteproc_nitofied(struct remoteproc_priv *rproc);

#endif /*AUGENTIX_PROC_H*/
