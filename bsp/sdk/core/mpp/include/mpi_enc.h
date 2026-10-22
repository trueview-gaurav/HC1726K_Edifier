/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

/**
 * @file mpi_enc.h
 * @brief MPI for encoder channel
 */

#ifndef MPI_ENC_H_
#define MPI_ENC_H_

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#include "mpi_index.h"
#include "mpi_limits.h"

/**
 * @brief typedef of struct timespec
 */
#ifdef __KERNEL__
#include <linux/time.h>
#include <linux/version.h>
#if LINUX_VERSION_CODE < KERNEL_VERSION(5, 6, 0)
typedef struct timespec TIMESPEC_S;
#else
typedef struct mpi_timespec {
	long int tv_sec;
	long int tv_nsec;
} TIMESPEC_S;
#endif /* LINUX_VERSION_CODE */
#else
#include <time.h>
typedef struct timespec TIMESPEC_S;
#endif /* __KERNEL__ */

/**
 * @brief Enumeration of frame type.
 */
typedef enum mpi_frame_type {
	MPI_FRAME_TYPE_SPS = 0, /**< SPS frame. */
	MPI_FRAME_TYPE_PPS, /**< PPS frame. */
	MPI_FRAME_TYPE_I, /**< I frame. */
	MPI_FRAME_TYPE_P, /**< P frame. */
	MPI_FRAME_TYPE_B, /**< B frame. */
	MPI_FRAME_TYPE_LTR_P, /**< P frame that refers to the IDR frame as a long-term reference */
	MPI_FRAME_TYPE_NUM,
} MPI_FRAME_TYPE_E;

/**
 * @brief Enumeration of rate control mode.
 */
typedef enum mpi_rc_mode {
	MPI_RC_MODE_VBR = 0, /**< Variable bit rate mode. */
	MPI_RC_MODE_CBR, /**< Conttant bit rate mode. */
	MPI_RC_MODE_SBR, /**< Smart bit rate mode. */
	MPI_RC_MODE_CQP, /**< Constant QP mode. */
	MPI_RC_MODE_NUM,
} MPI_RC_MODE_E;

/**
 * @brief Enumeration of video codec profile.
 */
typedef enum mpi_venc_prfl {
	MPI_PRFL_BASELINE = 0, /**< Baseline profile. */
	MPI_PRFL_MAIN, /**< Main profile. */
	MPI_PRFL_HIGH, /**< High profile. */
	MPI_PRFL_NUM,
} MPI_VENC_PRFL_E;

/**
 * @brief Enumeration of video encoder type.
 */
typedef enum mpi_venc_type {
	MPI_VENC_TYPE_H264 = 0, /**< H.264. */
	MPI_VENC_TYPE_H265, /**< H.265. */
	MPI_VENC_TYPE_MJPEG, /**< Motion JPEG. */
	MPI_VENC_TYPE_JPEG, /**< JPEG. */
	MPI_VENC_TYPE_NUM,
} MPI_VENC_TYPE_E;

/**
 * @brief Struct for the buffer segment.
 */
typedef struct mpi_buf_seg {
	UINT32 paddr; /**< Buffer physical address */
	UINT8 *uaddr; /**< Buffer userspace address */
	UINT32 offset; /**< Buffer offset from the start of the bitstream buffer */
	UINT32 size; /**< Buffer size */
	INT32 type; /**< Type of the buffer content (SPS/PPS/I/P) */
	UINT8 *frame_end; /**< I/P Frame end indicator (internal debug only) */
} MPI_BUF_SEG_S;

#define MPI_ENC_MAX_FRAME_SEG_CNT 16 /**< Maximum frame segment count */

/**
 * @brief Detailed information for each frame
 */
typedef struct mpi_frame_info {
	UINT32 exposure_time; /**< Exposure time(in microsecond). */
	UINT32 iso; /**< sensor_gain * isp_gain * 100. */
	UINT32 f_number; /**< F value of the current lens. */
	UINT32 flash; /**< Flash status. */
	UINT32 focal_length; /**< Focal length status. */
} MPI_FRAME_INFO_S;

/**
 * @brief Stream frame buffer parameter.
 * @details A single frame consists of one or more segment.
 */
typedef struct mpi_stream_param {
	MPI_BUF_SEG_S seg[MPI_ENC_MAX_FRAME_SEG_CNT]; /**< Frame buffer Segments */
	UINT32 seg_cnt; /**< Number of buffers in seg */
	UINT32 frame_id; /**< Frame sequence index in the channel */
	UINT32 timestamp; /**< Timestamp of the frame */
	UINT32 win_timestamp[MPI_MAX_VIDEO_WIN_NUM]; /**< Timestamp of windows */
	UINT32 jiffies; /**< Jiffies of the frame */
	UINT32 win_jiffies[MPI_MAX_VIDEO_WIN_NUM]; /**< Jiffies of windows */
} MPI_STREAM_PARAMS_S;

/**
 * @brief Stream frame buffer parameter.
 * @details A single frame consists of one or more segment.
 */
typedef struct mpi_stream_params_v2 {
	MPI_BUF_SEG_S seg[MPI_ENC_MAX_FRAME_SEG_CNT]; /**< Frame buffer segments. */
	UINT32 seg_cnt; /**< Number of buffers in MPI_BUF_SEG_S MPI_STREAM_PARAMS_V2_S::seg */
	UINT32 frame_id; /**< Frame sequence index in the channel */
	TIMESPEC_S timestamp; /**< Timestamp of the frame */
	TIMESPEC_S win_timestamp[MPI_MAX_VIDEO_WIN_NUM]; /**< Timestamp of windows */
	UINT32 jiffies; /**< Jiffies of the frame */
	UINT32 win_jiffies[MPI_MAX_VIDEO_WIN_NUM]; /**< Jiffies of windows */
} MPI_STREAM_PARAMS_V2_S;

/**
 * @brief Stream frame buffer parameter.
 * @details A single frame consists of one or more segment.
 */
typedef struct mpi_stream_params_v3 {
	MPI_BUF_SEG_S seg[MPI_ENC_MAX_FRAME_SEG_CNT]; /**< Frame buffer segments. */
	UINT32 seg_cnt; /**< Number of buffers in MPI_BUF_SEG_S MPI_STREAM_PARAMS_V3_S::seg */
	UINT32 frame_id; /**< Frame sequence index in the channel */
	TIMESPEC_S timestamp; /**< Timestamp of the frame */
	TIMESPEC_S win_timestamp[MPI_MAX_VIDEO_WIN_NUM]; /**< Timestamp of windows */
	MPI_FRAME_INFO_S frame_info; /**< Frame information */
} MPI_STREAM_PARAMS_V3_S;

/**
 * @brief Struct for the encoder channel attributes.
 * @note
 * @arg `MPI_ENC_CHN_ATTR_S::res` should be equal to the resolution of video
 *      channel `MPI_CHN_ATTR_S::res` it binds to.
 * @arg `MPI_ENC_CHN_ATTR_S::max_res` should equal to `MPI_ENC_CHN_ATTR_S::res`.
 */
typedef struct mpi_enc_chn_attr {
	MPI_SIZE_S res; /**< Encoder channel resolution. */
	MPI_SIZE_S max_res; /**< Maximum encoder channel resolution. */
} MPI_ENC_CHN_ATTR_S;

/**
 * @brief Struct for the encoder channel binding info.
 */
typedef struct mpi_enc_bind_info {
	MPI_CHN idx; /**< Binding channel index. */
} MPI_ENC_BIND_INFO_S;

/**
 * @brief Struct for the parameters of rate control in variable bit rate mode
 * for motion-compensation-based video compression standard.
 *
 * @note [dynamic parameters]: ALL except i_continue_weight
 * @deprecated i_continue_weight
 */
typedef struct mpi_mcvc_vbr_param {
	UINT32 max_bit_rate; /**< Maximum bit rate, in kbit/s. Range: [1, 51200]. */
	UINT32 quality_level_index; /**< Quality level for VBR mode. Range: [0, 9]. */
	UINT32 fluc_level; /**< Fluctuation level, which can determine to apply which QP-delta curve. Range: [0, 4]. */
	UINT32 regression_speed; /**< Determine how fast to update the reference QP. Range: [0, 9]. */
	UINT32 scene_smooth; /**< Determine the maximum of IP-ratio. Range: [0, 9]. */
	UINT32 i_continue_weight; /**< (Deprecated) Determine the final QP between reference QP and current QP. */
	UINT32 max_qp; /**< Maximum QP under VBR mode. Range: [0, 51] */
	INT32 i_qp_offset; /**< I-frame QP offset. Range: [-10, 10]. */
	UINT32 motion_tolerance_level; /**< The level of tolerance burst bit-rate. The higher level would make the time of
	                                    burst bit-rate longer. Range: [0, 100]. */
	UINT32 motion_tolerance_qp; /**< The QP threshold of tolerance burst bit-rate. RC would try to keep the runtime QP
	                                 at the threshold while QP is raising and exceeds the threshold. It should be equal
	                                 or smaller than 'max_qp'. Range: [0, 51] */
} MPI_MCVC_VBR_PARAM_S;

/**
 * @brief Struct for the parameters of rate control in constant bit rate mode for motion-compensation-based video
 *        compression standard.
 *
 * @note [dynamic parameters]: ALL except i_continue_weight
 * @deprecated i_continue_weight
 */
typedef struct mpi_mcvc_cbr_param {
	UINT32 bit_rate; /**< Average bit rate, in kbit/s. Range: [1, 51200]. */
	UINT32 fluc_level; /**< Fluctuation level, which can determine to apply which QP-delta curve. Range: [0, 4]. */
	UINT32 regression_speed; /**< Determine how fast to update the reference QP. Range: [0, 9]. */
	UINT32 scene_smooth; /**< Determine the maximum of IP-ratio. Range: [0, 9]. */
	UINT32 i_continue_weight; /**< (Deprecated) Determine the final QP between reference QP and current QP. */
	UINT32 max_qp; /**< Maximum QP under CBR mode. Range: [0, 51], and should be bigger than 'min_qp'. */
	UINT32 min_qp; /**< Minimum QP under CBR mode. Range: [0, 51], and should be smaller than 'max_qp'. */
	INT32 i_qp_offset; /**< I-frame QP offset. Range: [-10, 10]. */
	UINT32 motion_tolerance_level; /**< The level of tolerance burst bit-rate. The higher level would make the time of
	                                    burst bit-rate longer. Range: [0, 100]. */
	UINT32 motion_tolerance_qp; /**< The QP threshold of tolerance burst bit-rate. RC would try to keep the runtime QP
	                                 at the threshold while QP is raising and exceeds the threshold. It should be equal
	                                 or smaller than 'max_qp'. Range: [0, 51] */
} MPI_MCVC_CBR_PARAM_S;

/**
 * @brief Struct for the parameters of rate control in smart bit rate mode for motion-compensation-based video
 *        compression standard.
 *
 * @note [dynamic parameters]: ALL except i_continue_weight
 * @deprecated i_continue_weight
 */
typedef struct mpi_mcvc_sbr_param {
	UINT32 bit_rate; /**< Average bit rate, in kbit/s. Range: [1, 51200]. */
	UINT32 fluc_level; /**< Fluctuation level, which can determine to apply which QP-delta curve. Range: [0, 4]. */
	UINT32 regression_speed; /**< Determine how fast to update the reference QP. Range: [0, 9]. */
	UINT32 scene_smooth; /**< Determine the maximum of IP-ratio. Range: [0, 9]. */
	UINT32 i_continue_weight; /**< (Deprecated) Determine the final QP between reference QP and current QP. */
	UINT32 max_qp; /**< Maximum QP under CBR mode. Range: [0, 51], and should be bigger than 'min_qp'. */
	UINT32 min_qp; /**< Minimum QP under CBR mode. Range: [0, 51], and should be smaller than 'max_qp'. */
	UINT32 adjust_br_thres_pc; /**< The threshold of adjusting bit-rate, based on a RC internal buffer. The bit-rate
	                                will be adjusted when RC finds out that the usage amount of the ENC bit-stream
	                                buffer exceeds this threshold. Unit: percent. Range: [50, 150]. */
	UINT32 adjust_step_times; /**< Set the range of adjusting bit-rate between the threshold, the range is N times of
	                               the adjusting step, and the step is 1/100 of the RC internal buffer. Enlarge the
	                               range can make the adjustment slower. Range: [1, 50]. */
	UINT32 converge_frame; /**< Converge frame size adjustment in several frames. Suggest setting frame rate as default
	                            value. Unit: frame. Range: [1, 240]. */
	INT32 i_qp_offset; /**< I-frame QP offset. Range: [-10, 10]. */
	UINT32 motion_tolerance_level; /**< The level of tolerance burst bit-rate. The higher level would make the time of
	                                    burst bit-rate longer. Range: [0, 100]. */
	UINT32 motion_tolerance_qp; /**< The QP threshold of tolerance burst bit-rate. RC would try to keep the runtime QP
	                                 at the threshold while QP is raising and exceeds the threshold. It should be equal
	                                 or smaller than 'max_qp'. Range: [0, 51] */
} MPI_MCVC_SBR_PARAM_S;

/**
 * @brief Struct for the parameters of rate control in constant QP mode for motion-compensation-based video compression
 *        standard.
 *
 * @note [dynamic parameters]: ALL
 */
typedef struct mpi_mcvc_cqp_param {
	UINT32 i_frame_qp; /**< Constant QP for I frame. Range: [0, 51]. */
	UINT32 p_frame_qp; /**< Constant QP for P frame. Range: [0, 51]. */
} MPI_MCVC_CQP_PARAM_S;

/**
 * @brief Struct for rate control for Motion-Compensation-based Video Compression (MCVC) standard.
 *
 * @note [static parameters]: mode
 * @note [dynamic parameters]: gop
 * @deprecated frm_rate_o
 */
typedef struct mpi_mcvc_rc_attr {
	MPI_RC_MODE_E mode; /**< Rate control mode. */
	UINT32 gop; /**< Number of group of picture. Range: [1, 250]. */
	INT32 frm_rate_o; /**< Highest fps with encoder resolution that use to set level value in sps, it's not affected output fps. */
	UINT32 max_frame_size; /**< Maximum encoded target frame size. However, it cannot exceed half of the encoder
	                            bit-stream buffer size. If so, the system will cut down it on half of bit-stream buffer
	                            size automatically. Setting it as '0' means ignoring the parameter, and RC will set
	                            half of bit-stream buffer size as its restriction on single frame size. Unit: KB. */
	UINT32 ltr_period; /**< Period between LTR-P frames */
	union {
		MPI_MCVC_VBR_PARAM_S vbr; /**< Parameters of variable bit rate mode. */
		MPI_MCVC_CBR_PARAM_S cbr; /**< Parameters of constant bit rate mode. */
		MPI_MCVC_SBR_PARAM_S sbr; /**< Parameters of smart bit rate mode. */
		MPI_MCVC_CQP_PARAM_S cqp; /**< Parameters of fixed QP mode. */
	}; /**< Union of rate control parameters. */
} MPI_MCVC_RC_ATTR_S;

/**
 * @brief Struct for rate control for intra-frame based video compression standard.
 *
 * @note [static parameters]: mode
 * @note [dynamic parameters]: ALL except mode, frm_rate_o
 * @deprecated frm_rate_o
 */
typedef struct mpi_vc_rc_attr {
	MPI_RC_MODE_E mode; /**< Rate control mode. */
	UINT32 frm_rate_o; /**< Highest fps with encoder resolution, it's not affected output fps. */
	UINT32 fluc_level; /**< Fluctuation control for VBR and CBR mode. Range: [0, 4]. */
	UINT32 bit_rate; /**< Average bit rate, in kbit/s for CBR mode. Range: [8192, 51200]. */
	UINT32 max_q_factor; /**< Maximum quantization factor for CBR mode.
	                          Range: [0, 100], and should be bigger than 'min_q_factor'. */
	UINT32 min_q_factor; /**< Minimum quantization factor for CBR mode.
	                          Range: [0, 100], and should be smaller than 'max_q_factor'. */
	UINT32 max_bit_rate; /**< Maximum bit rate, in kbit/s for VBR mode. Range: [8192, 51200]. */
	UINT32 quality_level_index; /**< Quality level for VBR mode. Range: [0, 9]. */
	UINT32 q_factor; /**< Constant Q factor for CQP mode. Range: [0, 100]. */
	UINT32 adjust_br_thres_pc; /**< The threshold of adjusting bit-rate, based on a RC internal buffer. The bit-rate
	                                will be adjusted when RC finds out that the usage amount of the ENC bit-stream
	                                buffer exceeds this threshold. Unit: percent. Range: [50, 150]. */
	UINT32 adjust_step_times; /**< Set the range of adjusting bit-rate between the threshold, the range is N times of
	                               the adjusting step, and the step is 1/100 of the RC internal buffer. Enlarge the
	                               range can make the adjustment slower. Range: [1, 50]. */
	UINT32 converge_frame; /**< Converge frame size adjustment in several frames. Unit: frame. Range: [1, 240]. */
	UINT32 max_frame_size; /**< Maximum encoded target frame size. However, it cannot exceed half of the encoder
	                            bit-stream buffer size. If so, the system will cut down it on half of bit-stream buffer
	                            size automatically. Setting it as '0' means ignoring the parameter, and RC will set
	                            half of bit-stream buffer size as its restriction on single frame size. Unit: KB. */
	UINT32 motion_tolerance_level; /**< The level of tolerance burst bit-rate. The higher level would make the time of
	                                    burst bit-rate longer. Range: [0, 100]. */
	UINT32 motion_tolerance_qfactor; /**< The Q-factor threshold of tolerance burst bit-rate. RC would try to keep the
	                                      runtime Q-factor at the threshold while Q-factor is declining and lower than
	                                      the threshold. It should be equal or bigger than 'min_q_factor'.
	                                      Range: [0, 100] */
} MPI_VC_RC_ATTR_S;

/**
 * @brief Struct for H264 encoder attribute.
 *
 * @note [static parameters]: profile
 */
typedef struct mpi_venc_attr_h264 {
	MPI_VENC_PRFL_E profile; /**< Video codec profile. */
	MPI_MCVC_RC_ATTR_S rc; /**< Rate control attribute of motion-compensation-based video compression standard. */
} MPI_VENC_ATTR_H264_S;

/**
 * @brief Struct for H265 encoder attribute.
 *
 * @note [static parameters]: profile
 */
typedef struct mpi_venc_attr_h265 {
	MPI_VENC_PRFL_E profile; /**< Video codec profile. */
	MPI_MCVC_RC_ATTR_S rc; /**< Rate control attribute of motion-compensation-based video compression standard. */
} MPI_VENC_ATTR_H265_S;

/**
 * @brief Struct for MJPEG encoder attribute.
 */
typedef struct mpi_venc_attr_mjpeg {
	MPI_VC_RC_ATTR_S rc; /**< Rate control attribute of intra-frame based video compression standard. */
} MPI_VENC_ATTR_MJPEG_S;

/**
 * @brief Struct for JPEG encoder attribute.
 *
 * @note [dynamic parameters]: ALL
 */
typedef struct mpi_venc_attr_jpeg {
	UINT32 q_factor; /**< Quatization factor. Range: [0, 100]. */
} MPI_VENC_ATTR_JPEG_S;

/**
 * @brief Struct for video codec.
 *
 * @attention
 * Some parameters under MPI_VENC_ATTR_S are unresettable (static). That is, we have to stop the encoder and create a
 * new one with different value of the unresettable parameters. Resettable parameters (dynamic) mean their value can be
 * changed in runtime and without stopping encoder.
 *
 * @note [static parameters]: type
 */
typedef struct mpi_venc_attr {
	MPI_VENC_TYPE_E type; /**< Video encoder type. */
	union {
		MPI_VENC_ATTR_H264_S h264; /**< H.264 encoder attribute. */
		MPI_VENC_ATTR_H265_S h265; /**< H.265 encoder attribute. */
		MPI_VENC_ATTR_MJPEG_S mjpeg; /**< Motion JPEG encoder attribute. */
		MPI_VENC_ATTR_JPEG_S jpeg; /**< JPEG encoder attribute. */
	};
} MPI_VENC_ATTR_S;

/**
 * @brief Struct for encoder information
 */
typedef struct mpi_venc_info {
    UINT32 last_qp; /**< last qp. */
    UINT32 last_i_qp; /**< last i frame qp. */
    UINT32 bps; /**< real time bps. */
    UINT32 fps; /**< real time fps. */
    UINT32 frame_cnt_in_streambuffer; /**< frame count in stream buffer. */
    UINT32 frame_drop_cnt; /**< frame drop conut. */
} MPI_VENC_INFO_S;

/**
 * @cond
 */

#define MPI_VENC_ROI_NUM (8) /**< Number of video encode ROI. */

/**
 * @endcond
 */

/* Interface function prototype */
INT32 MPI_ENC_createChn(MPI_ECHN chn_idx, const MPI_ENC_CHN_ATTR_S *p_chn_attr);
INT32 MPI_ENC_destroyChn(MPI_ECHN chn_idx);
INT32 MPI_ENC_bindToVideoChn(MPI_ECHN chn_idx, const MPI_ENC_BIND_INFO_S *p_bind_info);
INT32 MPI_ENC_unbindFromVideoChn(MPI_ECHN chn_idx);
INT32 MPI_ENC_setChnAttr(MPI_ECHN chn_idx, const MPI_ENC_CHN_ATTR_S *p_chn_attr);
INT32 MPI_ENC_getChnAttr(MPI_ECHN chn_idx, MPI_ENC_CHN_ATTR_S *p_chn_attr);
INT32 MPI_ENC_setVencAttr(MPI_ECHN chn_idx, const MPI_VENC_ATTR_S *p_venc_attr);
INT32 MPI_ENC_getVencAttr(MPI_ECHN chn_idx, MPI_VENC_ATTR_S *p_venc_attr);
INT32 MPI_ENC_setVencExtendFile(MPI_ECHN chn_idx, const char *file_path);
INT32 MPI_ENC_getVencExtendFile(MPI_ECHN chn_idx, const char *file_path);

INT32 MPI_ENC_startChn(MPI_ECHN chn_idx);
INT32 MPI_ENC_stopChn(MPI_ECHN chn_idx);
INT32 MPI_ENC_queryVencInfo(MPI_ECHN chn_idx, MPI_VENC_INFO_S *p_venc_info);

INT32 MPI_initBitStreamSystem(void);
INT32 MPI_exitBitStreamSystem(void);
MPI_BCHN MPI_createBitStreamChn(MPI_ECHN chn_idx);
INT32 MPI_destroyBitStreamChn(MPI_BCHN chn_idx);
INT32 MPI_getBitStream(MPI_BCHN chn_idx, MPI_STREAM_PARAMS_S *stream_params, INT32 time_ms);
INT32 MPI_getBitStreamV2(MPI_BCHN idx, MPI_STREAM_PARAMS_V2_S *stream_params, INT32 time_ms);
INT32 MPI_getBitStreamV3(MPI_BCHN idx, MPI_STREAM_PARAMS_V3_S *stream_params, INT32 time_ms);
INT32 MPI_releaseBitStream(MPI_BCHN chn_idx, MPI_STREAM_PARAMS_S *stream_params);
INT32 MPI_releaseBitStreamV2(MPI_BCHN chn_idx, MPI_STREAM_PARAMS_V2_S *stream_params);
INT32 MPI_releaseBitStreamV3(MPI_BCHN chn_idx, MPI_STREAM_PARAMS_V3_S *stream_params);

INT32 MPI_ENC_getChnFrame(MPI_ECHN idx, MPI_STREAM_PARAMS_S *stream_params, INT32 time_ms);
INT32 MPI_ENC_releaseChnFrame(MPI_ECHN idx, MPI_STREAM_PARAMS_S *stream_params);
INT32 MPI_ENC_getChnFrameV2(MPI_ECHN idx, INT32 quality_idx, MPI_STREAM_PARAMS_V2_S *stream_params, INT32 time_ms);
INT32 MPI_ENC_releaseChnFrameV2(MPI_ECHN idx, MPI_STREAM_PARAMS_V2_S *stream_params);
INT32 MPI_ENC_getChnFrameV3(MPI_ECHN idx, INT32 quality_idx, MPI_STREAM_PARAMS_V3_S *stream_params, INT32 time_ms);
INT32 MPI_ENC_releaseChnFrameV3(MPI_ECHN idx, MPI_STREAM_PARAMS_V3_S *stream_params);

INT32 MPI_ENC_requestIdr(MPI_ECHN idx);

/**
* @cond
*
* code fragment skipped by Doxygen.
*/

/* Deprecated MPI */

#define MPI_ISP_MAX_WIN_NUM                                                                                   \
	_Pragma("GCC error \"MPI_ISP_MAX_WIN_NUM is deprecated. Please use MPI_MAX_VIDEO_WIN_NUM instead.\"") \
	        MPI_MAX_VIDEO_WIN_NUM

/**
 * @endcond
 */

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* MPI_ENC_H_ */
