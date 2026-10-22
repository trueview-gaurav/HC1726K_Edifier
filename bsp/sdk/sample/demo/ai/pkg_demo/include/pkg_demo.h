#ifndef __PKG_DEMO_H__
#define __PKG_DEMO_H__
void help(const char *name);
int main(int argc, char **argv);

int modifyParam(ML_PKG_PARAM_S *output_param, const ML_PKG_PARAM_S *input_param);
int runPackageDetection(MPI_WIN mpi_idx, const ML_PKG_PARAM_S *pkg_input_param, uint8_t frame_y_avg_cfg_idx,
                        uint8_t *roi_y_avg_cfg_idx, uint32_t snap_duration_ms);
static void determinePkgStatus(const ML_PKG_STATUS_S *foreground_status, int od_idx, int buf_idx, int start, int end,
                               UINT16 *y_avg);

static void handleSigInt(int signo);
uint8_t isStatusChanged(const ML_PKG_STATUS_S *status, const int region_num, MPI_IVA_OBJ_LIST_S *obj_list);

#endif
