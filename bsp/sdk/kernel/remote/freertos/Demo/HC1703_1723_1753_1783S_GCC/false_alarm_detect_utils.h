#ifndef FALSE_ALRAM_DETECT_UTILS_H_
#define FALSE_ALRAM_DETECT_UTILS_H_

#include "net.h"
#include <stdint.h>

#define MPI_IVA_MAX_OBJ_NUM 10

#define FALSE_ALARM_SIMULATE 0
#define FALSE_ALARM_DEBUG 0
#define LPRINTF(format, ...) printf("[RTOS EARLY DETECT]: " format, ##__VA_ARGS__)

#if FALSE_ALARM_DEBUG
#define LOG_SECTION(__section_name, __stmts)          \
	printf("<<< Start of " #__section_name "\n"); \
	__stmts;                                      \
	printf(">>> End of " #__section_name "\n")
#else
#define LOG_SECTION(__section_name, __stmts) __stmts;
#endif

#ifndef MAX
#define MAX(a, b)                       \
	({                              \
		__typeof__(a) _a = (a); \
		__typeof__(a) _b = (b); \
		_a > _b ? _a : _b;      \
	})
#endif

#ifndef MIN
#define MIN(a, b)                       \
	({                              \
		__typeof__(a) _a = (a); \
		__typeof__(a) _b = (b); \
		_a < _b ? _a : _b;      \
	})
#endif

#ifndef ABS
#define ABS(a) (((a) < 0) ? -(a) : (a))
#endif

#ifndef SIGNED
#define SIGNED(a) (((a) < 0) ? -1 : 1)
#endif

#ifndef ROUND_DIV
#define ROUND_DIV(a, b) (((ABS(a) + (ABS(b) / 2)) / (ABS(b))) * SIGNED(a) * SIGNED(b))
#endif

#define CLIP(min_v, max_v, v) (MAX(MIN((max_v), (v)), (min_v)))

#define IS_OVERLAP(sx0, ex0, sx1, ex1, overlap) ((((sx0) - (overlap)) <= (ex1)) && (((ex0) + (overlap)) >= (sx1)))

const uint8_t use_int8_inference = 0;
const uint8_t use_winograd_convolution = 1;
const uint8_t use_sgemm_convolution = 1;
const uint8_t use_packing_layout = 1;
const int m_input_dim[4] = { 256, 256, 3, 1 };

const int od_iou_th = 40; // should be 0 to 100
const int class_num = 3;

// ROI Internal Parameters from ODv4.4 (DO NOT MODIFY!)
#define DET_MAX_X_SEG 100
#define MAX_CURR_MOL_OBJ_NUM 200
#define GET_OBJ_FROM_MVF_SY 1
#define GET_OBJ_FROM_MVF_SX 0
#define TMV_CACHE_SIZE 8
#define MV_BLOCK_SIZE 8
#define ROI_MIN_SIZE 16
const int16_t det_min_obj_x_size_init = 8;
const int16_t det_min_obj_y_size_init = 8;
const int16_t det_merge_overlap_th = 24; // could be higher, different part to be merged easily
const int16_t det_x_seg_overlap_th = 0; // could be 8
const int16_t obj_speed_center_x_rto = 6;
const int16_t obj_speed_center_y_rto = 6;
const int16_t obj_mv_n_bgmv_tolerance = 4;
const int16_t obj_mv_n_bgmv_lvl_slope = 4;
const int16_t obj_speed_n_bgmv_gain = 3;

// OD Parameters
const int16_t od_size_th = 30;
const int16_t od_sen = 254;

typedef struct rect_point {
	int16_t sx; /**< X coordinate of start point corresponding to input. */
	int16_t sy; /**< Y coordinate of start point corresponding to input. */
	int16_t ex; /**< X coordinate of end point corresponding to input. */
	int16_t ey; /**< Y coordinate of end point corresponding to input. */
} RECT_POINT_S;

typedef struct DetectionBox {
	RECT_POINT_S rect;
	uint32_t cat;
	std::vector<int> cat_cnt;
	uint32_t priority;
	int obj_id;
	int type;
	uint8_t conf; // should be 0 to 100
	uint8_t matched;
} DetBox;

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

typedef struct uboot_snapshot_info {
	void *phy_addr_y; /* Address of the frame's starting point, containing the luminance data of the YUV format. */
	void *phy_addr_c; /* Address of the chrominance data of the YUV format. */
	uint32_t size_y; /* Size of the luminance data in bytes. */
	uint32_t size_c; /* Size of the chrominance data in bytes. */
	uint16_t width; /* Width of the snapshot in pixels. */
	uint16_t height; /* Height of the snapshot in pixels. */
	uint8_t bit_depth; /* Bit depth of the snapshot. */
} UbootSnapshotInfo;

typedef struct uboot_mv_info {
	UbootHwMotionVec *phy_addr; /* Address of the starting point of motion vectors (MV) */
	uint32_t fps; /* Frame rate of the sensor in U-Boot */
	uint32_t duration; /* Duration of one frame in jiffies (10ms) */
	uint16_t win_width; /* Width of the window in pixels */
	uint16_t win_height; /* Height of the window in pixels */
} UbootMvInfo;

typedef struct tmv {
	UbootHwMotionVec *mv_addr;
	int32_t delta_frame;
	uint32_t instant;
	uint32_t duration;
	uint32_t win_idx;
	uint16_t win_width;
	uint16_t win_height;
	uint16_t mv_width;
	uint16_t mv_height;
} Tmv;

typedef struct motion_vec {
	int16_t x; /**< X component of motion vector. */
	int16_t y; /**< Y component of motion vector. */
} MOTION_VEC_S;

typedef struct mov_obj_attr {
	int32_t idx;
	RECT_POINT_S rect;
	MOTION_VEC_S mv;
	uint32_t cat; /**< Category ID of the object*/
	uint8_t conf; /**< Confidence score of the object prediction*/
} MovObjAttr;

typedef struct curr_mov_obj_list {
	int32_t obj_cnt; // Number of objects. Can be defined by unsigned type
	MovObjAttr obj[MAX_CURR_MOL_OBJ_NUM];
} CurrMovObjList;

void NmsBoxes(std::vector<DetBox> &input, float iou, uint32_t max_cnt, std::vector<DetBox> &output);
int update_model_shape(ncnn::Net &net, int target_width, int target_height);
void getROIsFromMV(const UbootMvInfo *uboot_mv, CurrMovObjList *curr_mol);
void refineROI(RECT_POINT_S &rect, int min_size, int W, int H);
void getMaxROIFromList(CurrMovObjList *curr_mol, RECT_POINT_S *roi_out, int *idx);

#endif // FALSE_ALRAM_DETECT_UTILS_H_