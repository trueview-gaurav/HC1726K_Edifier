/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

/**
 * @file mpi_senif.h
 * @brief MPI for sensor interface callbacks
 */

#ifndef MPI_SENIF_H_
#define MPI_SENIF_H_

#ifdef __KERNEL__
#include <linux/types.h>

/**
 * @brief typedef of struct sensor_pm_ops
 */
struct sensor_pm_ops {
        int (*sensor_suspend_callback)(int sensor_id);
        int (*sensor_resume_callback)(int sensor_id);
};

int sensor_register_pm_cb(const struct sensor_pm_ops *ops);
int sensor_unregister_pm_cb(void);

#endif /* __KERNEL__ */

#endif /* MPI_SENIF_H_ */
