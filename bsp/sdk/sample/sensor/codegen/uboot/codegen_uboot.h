#ifndef CODEGEN_UBOOT_H_
#define CODEGEN_UBOOT_H_

#include "mpi_limits.h"
#include "mpi_dip_sns.h"
#include "sensor_types.h"

extern MPI_SNS_OP_INFO_S g_codegen_sensor_info;
extern MPI_SNS_CALLBACK_S g_codegen_sns_callbacks[MPI_MAX_INPUT_PATH_NUM];
extern int g_codegen_slave_addr;
extern SensCmd *g_codegen_init_cmd;
extern int g_codegen_init_cmd_len;
extern int g_codegen_start_cmd;
extern int g_codegen_cmd_addr_len;
extern int g_codegen_cmd_data_len;

int gen_uboot_file(MPI_PATH path_idx, const char *uboot_sns_path);

#endif
