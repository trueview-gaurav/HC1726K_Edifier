/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

/**
 * @file mpi_index.h
 * @brief Data types and methods for indexing MPI objects
 */

#ifndef MPI_INDEX_H_
#define MPI_INDEX_H_

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#include "mpi_base_types.h"
#include "mpi_limits.h"

/**
 * @brief MPI index of video device
 */
typedef union mpi_dev {
	struct {
		UINT8 dev; /**< Video device index. Range [0, @link MPI_MAX_VIDEO_DEV_NUM @endlink) */
		UINT8 dummy2; /* padding */
		UINT8 dummy1; /* padding */
		UINT8 dummy0; /* padding */
	};
	UINT32 value : 8; /**< used for assignment between MPI indexes */
} MPI_DEV;

/**
 * @brief MPI index of input path
 */
typedef union mpi_path {
	struct {
		UINT8 dev; /**< Video device index. Range [0, @link MPI_MAX_VIDEO_DEV_NUM @endlink) */
		UINT8 path; /**< Input path index. Range [0, @link MPI_MAX_INPUT_PATH_NUM @endlink) */
		UINT8 dummy1; /* padding */
		UINT8 dummy0; /* padding */
	};
	UINT32 value : 16; /**< used for assignment between MPI indexes */
} MPI_PATH;

/**
 * @brief MPI index of video channel
 */
typedef union mpi_chn {
	struct {
		UINT8 dev; /**< Video device index. Range [0, @link MPI_MAX_VIDEO_DEV_NUM @endlink) */
		UINT8 chn; /**< Video channel index. Range [0, @link MPI_MAX_VIDEO_CHN_NUM @endlink) */
		UINT8 dummy1; /* padding */
		UINT8 dummy0; /* padding */
	};
	UINT32 value : 16; /**< used for assignment between MPI indexes */
} MPI_CHN;

/**
 * @brief MPI index of video window
 */
typedef union mpi_win {
	struct {
		UINT8 dev; /**< Video device index. Range [0, @link MPI_MAX_VIDEO_DEV_NUM @endlink) */
		UINT8 chn; /**< Video channel index. Range [0, @link MPI_MAX_VIDEO_CHN_NUM @endlink) */
		UINT8 win; /**< Video window index. Range [0, @link MPI_MAX_VIDEO_WIN_NUM @endlink) */
		UINT8 dummy0; /* padding */
	};
	UINT32 value : 24; /**< used for assignment between MPI indexes */
} MPI_WIN;

/**
 * @brief MPI index of encoder channel
 */
typedef union mpi_echn {
	struct {
		UINT8 chn; /**< Encoder channel index. Range [0, @link MPI_MAX_ENC_CHN_NUM @endlink) */
		UINT8 dummy2; /* padding */
		UINT8 dummy1; /* padding */
		UINT8 dummy0; /* padding */
	};
	UINT32 value : 8; /**< used for assignment between MPI indexes */
} MPI_ECHN;

/**
 * @brief MPI index of bit-stream channel
 * @see MPI_createBitStreamChn()
 */
typedef union mpi_bchn {
	struct {
		UINT8 chn; /**< Encoder channel index. Range [0, @link MPI_MAX_ENC_CHN_NUM @endlink) */
		UINT8 bchn; /**< Bit-stream channel index. */
		UINT8 dummy1; /* padding */
		UINT8 dummy0; /* padding */
	};
	UINT32 value : 16; /**< used for assignment between MPI indexes */
} MPI_BCHN;

/**
 * @brief A short-hand notation for byte "INVALID"
 */
#define MPI_BYTE_INVALID 0x80

/**
 * @brief A macro to set MPI index of video device
 * @param[in] d    video device index
 */
#define MPI_VIDEO_DEV(d) \
	((MPI_DEV){      \
	        { .dev = (d), .dummy2 = MPI_BYTE_INVALID, .dummy1 = MPI_BYTE_INVALID, .dummy0 = MPI_BYTE_INVALID } })

/**
 * @brief A macro to check MPI index of video device
 * @param[in] i    MPI_DEV
 * @return Boolean. True if input argument is valid index for video device.
 */
#define VALID_MPI_VIDEO_DEV(i)                                                                                    \
	(((i).dev != MPI_BYTE_INVALID) && ((i).dummy0 == MPI_BYTE_INVALID) && ((i).dummy1 == MPI_BYTE_INVALID) && \
	 ((i).dummy2 == MPI_BYTE_INVALID))

/**
 * @brief A macro to set MPI index of input path
 * @param[in] d    video device index
 * @param[in] p    input path index
 */
#define MPI_INPUT_PATH(d, p) \
	((MPI_PATH){ { .dev = (d), .path = (p), .dummy1 = MPI_BYTE_INVALID, .dummy0 = MPI_BYTE_INVALID } })

/**
 * @brief A macro to check MPI index of input path
 * @param[in] i    MPI_PATH
 * @return Boolean. True if input argument is valid index for input path.
 */
#define VALID_MPI_INPUT_PATH(i)                                                                                 \
	(((i).dev != MPI_BYTE_INVALID) && ((i).path != MPI_BYTE_INVALID) && ((i).dummy0 == MPI_BYTE_INVALID) && \
	 ((i).dummy1 == MPI_BYTE_INVALID))

/**
 * @brief A macro to set MPI index of video channel
 * @param[in] d    video device index
 * @param[in] c    video channel index
 */
#define MPI_VIDEO_CHN(d, c) \
	((MPI_CHN){ { .dev = (d), .chn = (c), .dummy1 = MPI_BYTE_INVALID, .dummy0 = MPI_BYTE_INVALID } })

/**
 * @brief A macro to check MPI index of video channel
 * @param[in] i    MPI_CHN
 * @return Boolean. True if input argument is valid index for video channel.
 */
#define VALID_MPI_VIDEO_CHN(i)                                                                                 \
	(((i).dev != MPI_BYTE_INVALID) && ((i).chn != MPI_BYTE_INVALID) && ((i).dummy0 == MPI_BYTE_INVALID) && \
	 ((i).dummy1 == MPI_BYTE_INVALID))

/**
 * @brief A macro to set MPI index of video widow
 * @param[in] d    video device index
 * @param[in] c    video channel index
 * @param[in] w    video window index
 */
#define MPI_VIDEO_WIN(d, c, w) ((MPI_WIN){ { .dev = (d), .chn = (c), .win = (w), .dummy0 = MPI_BYTE_INVALID } })

/**
 * @brief A macro to check MPI index of video widow
 * @param[in] i    MPI_WIN
 * @return Boolean. True if input argument is valid index for video window.
 */
#define VALID_MPI_VIDEO_WIN(i)                                                                              \
	(((i).dev != MPI_BYTE_INVALID) && ((i).chn != MPI_BYTE_INVALID) && ((i).win != MPI_BYTE_INVALID) && \
	 ((i).dummy0 == MPI_BYTE_INVALID))

/**
 * @brief A function to set MPI index of encoder channel
 * @param[in] c    encoder channel index
 */
#define MPI_ENC_CHN(c) \
	((MPI_ECHN){   \
	        { .chn = (c), .dummy2 = MPI_BYTE_INVALID, .dummy1 = MPI_BYTE_INVALID, .dummy0 = MPI_BYTE_INVALID } })

/**
 * @brief A macro to check MPI index of video widow
 * @param[in] i    MPI_ECHN
 * @return Boolean. True if input argument is valid index for encoder channel.
 */
#define VALID_MPI_ENC_CHN(i)                                                                                      \
	(((i).chn != MPI_BYTE_INVALID) && ((i).dummy0 == MPI_BYTE_INVALID) && ((i).dummy1 == MPI_BYTE_INVALID) && \
	 ((i).dummy2 == MPI_BYTE_INVALID))

/**
 * @brief A function to set MPI index of encoder bit-stream channel
 * @param[in] c    encoder channel index
 * @param[in] b    bit-stream channel index
 */
#define MPI_ENC_BCHN(c, b) \
	((MPI_BCHN){ { .chn = (c), .bchn = (b), .dummy1 = MPI_BYTE_INVALID, .dummy0 = MPI_BYTE_INVALID } })

/**
 * @brief A macro to check MPI index of encoder bit-stream channel
 * @param[in] i    MPI_BCHN
 * @return Boolean. True if input argument is valid index for bit-stream channel.
 */
#define VALID_MPI_ENC_BCHN(i)                                                                                   \
	(((i).chn != MPI_BYTE_INVALID) && ((i).bchn != MPI_BYTE_INVALID) && ((i).dummy0 == MPI_BYTE_INVALID) && \
	 ((i).dummy1 == MPI_BYTE_INVALID))

/**
 * @cond code fragment skipped by Doxygen.
 */

/**
 * A legacy function to get video device index from MPI index
 */
#define MPI_GET_VIDEO_DEV(idx) ((idx).dev)

/**
 * A legacy function to get input path index from MPI index
 */
#define MPI_GET_INPUT_PATH(idx) ((idx).path)

/**
 * A legacy function to get video channel index from MPI index
 */
#define MPI_GET_VIDEO_CHN(idx) ((idx).chn)

/**
 * A legacy function to get video window index from MPI index
 */
#define MPI_GET_VIDEO_WIN(idx) ((idx).win)

/**
 * A legacy function to get encoder channel index from MPI index
 */
#define MPI_GET_ENC_CHN(idx) ((idx).chn)

/**
 * @endcond
 */

/**
 * @brief A short-hand notation for invalid MPI_DEV
 */
#define MPI_INVALID_VIDEO_DEV MPI_VIDEO_DEV(MPI_BYTE_INVALID)

/**
 * @brief A short-hand notation for invalid MPI_PATH
 */
#define MPI_INVALID_INPUT_PATH MPI_INPUT_PATH(MPI_BYTE_INVALID, MPI_BYTE_INVALID)

/**
 * @brief A short-hand notation for invalid MPI_CHN
 */
#define MPI_INVALID_VIDEO_CHN MPI_VIDEO_CHN(MPI_BYTE_INVALID, MPI_BYTE_INVALID)

/**
 * @brief A short-hand notation for invalid MPI_WIN
 */
#define MPI_INVALID_VIDEO_WIN MPI_VIDEO_WIN(MPI_BYTE_INVALID, MPI_BYTE_INVALID, MPI_BYTE_INVALID)

/**
 * @brief A short-hand notation for invalid MPI_ECHN
 */
#define MPI_INVALID_ENC_CHN MPI_ENC_CHN(MPI_BYTE_INVALID)

/**
 * @brief A short-hand notation for invalid MPI_ECHN
 */
#define MPI_INVALID_ENC_BCHN MPI_ENC_BCHN(MPI_BYTE_INVALID, MPI_BYTE_INVALID)

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* MPI_INDEX_H_ */
