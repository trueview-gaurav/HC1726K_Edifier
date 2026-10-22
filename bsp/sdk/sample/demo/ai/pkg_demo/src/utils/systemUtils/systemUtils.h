#ifndef __PKG_SYSTEM_UTILS_H__
#define __PKG_SYSTEM_UTILS_H__
#include <stdio.h>
#include "json_object.h"

#include "json.h"
#include "log.h"
#include "mpi_base_types.h"
// #include "mpi_dev.h"
// #include "mpi_iva.h"
// #include "mpi_sys.h"
// #include "vftr.h"
#include "ml_pkg.h"
#include <time.h>

// extern volatile sig_atomic_t g_run_flag;

int parseConfig(const char *file_name, MPI_IVA_OD_PARAM_S *od_param, ML_PKG_PARAM_S *pkg_param);
uint32_t timer_record_ms();
// static void handleSigInt(int signo, sig_atomic_t* g_run_flag);

#include "systemUtils.c"
#endif
