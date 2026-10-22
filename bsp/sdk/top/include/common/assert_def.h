#ifndef ASSERT_DEF_H_
#define ASSERT_DEF_H_


#include <sys/reboot.h>
#ifdef __KERNEL__
#ifdef PRODUCT_RELEASE
#define ASSERT_TRACE(c,s,...)                        \
	do {                                         \
		if (!(c)) {                          \
			printk(s "\n", ##VA_ARGS__); \
		}                                    \
	} while (0);

#define ASSERT_REBOOT(c,s,...)                       \
	do {                                         \
		if (!(c)) {                          \
			printk(s "\n", ##VA_ARGS__); \
			reboot(RB_AUTOBOOT);         \
		}                                    \
	} while (0);
#else
#endif





#else




#endif


/* TRACE COMPILATION OPTION CONTROL SECTION */
#define TRC_ON                        1
#define TRC_OFF                       0

/* ERROR/WARNING trace control */
#define TRC_ERR                       TRC_ON
#define TRC_WARN                      TRC_ON

/* Hight/Middle/Low info trace control */
#define TRC_INFO_H                    TRC_ON
#define TRC_INFO_M                    TRC_ON
#define TRC_INFO_L                    TRC_ON

/* Module trace control */
#define LIBVB_TRC                     TRC_ON
#define LIBSR_TRC                     TRC_ON
#define LIBSENIF_TRC                  TRC_ON
#define LIBIS_TRC                     TRC_ON
#define LIBISP_TRC                    TRC_ON
#define LIBENC_TRC                    TRC_ON
#define LIBOSD_TRC                    TRC_ON
#define LIBVPC_TRC                    TRC_ON
#define LIBDIP_TRC                    TRC_ON
#define LIBIVA_TRC                    TRC_ON

/* Macros for integrating control commands */
#define LIBVB_ERR(en)                (TRC_ERR    && LIBVB_TRC && en)
#define LIBVB_WARN(en)               (TRC_WARN   && LIBVB_TRC && en)
#define LIBVB_INFO_H(en)             (TRC_INFO_H && LIBVB_TRC && en)
#define LIBVB_INFO_M(en)             (TRC_INFO_M && LIBVB_TRC && en)
#define LIBVB_INFO_L(en)             (TRC_INFO_L && LIBVB_TRC && en)

#define LIBSR_ERR(en)                (TRC_ERR    && LIBSR_TRC && en)
#define LIBSR_WARN(en)               (TRC_WARN   && LIBSR_TRC && en)
#define LIBSR_INFO_H(en)             (TRC_INFO_H && LIBSR_TRC && en)
#define LIBSR_INFO_M(en)             (TRC_INFO_M && LIBSR_TRC && en)
#define LIBSR_INFO_L(en)             (TRC_INFO_L && LIBSR_TRC && en)

#define LIBSENIF_ERR(en)             (TRC_ERR    && LIBSENIF_TRC && en)
#define LIBSENIF_WARN(en)            (TRC_WARN   && LIBSENIF_TRC && en)
#define LIBSENIF_INFO_H(en)          (TRC_INFO_H && LIBSENIF_TRC && en)
#define LIBSENIF_INFO_M(en)          (TRC_INFO_M && LIBSENIF_TRC && en)
#define LIBSENIF_INFO_L(en)          (TRC_INFO_L && LIBSENIF_TRC && en)

#define LIBIS_ERROR(en)              (TRC_ERR    && LIBIS_TRC && en)
#define LIBIS_WARN(en)               (TRC_WARN   && LIBIS_TRC && en)
#define LIBIS_INFO_H(en)             (TRC_INFO_H && LIBIS_TRC && en)
#define LIBIS_INFO_M(en)             (TRC_INFO_M && LIBIS_TRC && en)
#define LIBIS_INFO_L(en)             (TRC_INFO_L && LIBIS_TRC && en)

#define LIBISP_ERR(en)               (TRC_ERR    && LIBISP_TRC && en)
#define LIBISP_WARN(en)              (TRC_WARN   && LIBISP_TRC && en)
#define LIBISP_INFO_H(en)            (TRC_INFO_H && LIBISP_TRC && en)
#define LIBISP_INFO_M(en)            (TRC_INFO_M && LIBISP_TRC && en)
#define LIBISP_INFO_L(en)            (TRC_INFO_L && LIBISP_TRC && en)

#define LIBENC_ERR(en)               (TRC_ERR    && LIBENC_TRC && en)
#define LIBENC_WARN(en)              (TRC_WARN   && LIBENC_TRC && en)
#define LIBENC_INFO_H(en)            (TRC_INFO_H && LIBENC_TRC && en)
#define LIBENC_INFO_M(en)            (TRC_INFO_M && LIBENC_TRC && en)
#define LIBENC_INFO_L(en)            (TRC_INFO_L && LIBENC_TRC && en)

#define LIBOSD_ERR(en)               (TRC_ERR    && LIBOSD_TRC && en)
#define LIBOSD_WARN(en)              (TRC_WARN   && LIBOSD_TRC && en)
#define LIBOSD_INFO_H(en)            (TRC_INFO_H && LIBOSD_TRC && en)
#define LIBOSD_INFO_M(en)            (TRC_INFO_M && LIBOSD_TRC && en)
#define LIBOSD_INFO_L(en)            (TRC_INFO_L && LIBOSD_TRC && en)

#define LIBVPC_ERR(en)               (TRC_ERR    && LIBVPC_TRC && en)
#define LIBVPC_WARN(en)              (TRC_WARN   && LIBVPC_TRC && en)
#define LIBVPC_INFO_H(en)            (TRC_INFO_H && LIBVPC_TRC && en)
#define LIBVPC_INFO_M(en)            (TRC_INFO_M && LIBVPC_TRC && en)
#define LIBVPC_INFO_L(en)            (TRC_INFO_L && LIBVPC_TRC && en)

#define LIBDIP_ERR(en)               (TRC_ERR    && LIBDIP_TRC && en)
#define LIBDIP_WARN(en)              (TRC_WARN   && LIBDIP_TRC && en)
#define LIBDIP_INFO_H(en)            (TRC_INFO_H && LIBDIP_TRC && en)
#define LIBDIP_INFO_M(en)            (TRC_INFO_M && LIBDIP_TRC && en)
#define LIBDIP_INFO_L(en)            (TRC_INFO_L && LIBDIP_TRC && en)

#define LIBIVA_ERR(en)               (TRC_ERR    && LIBIVA_TRC && en)
#define LIBIVA_WARN(en)              (TRC_WARN   && LIBIVA_TRC && en)
#define LIBIVA_INFO_H(en)            (TRC_INFO_H && LIBIVA_TRC && en)
#define LIBIVA_INFO_M(en)            (TRC_INFO_M && LIBIVA_TRC && en)
#define LIBIVA_INFO_L(en)            (TRC_INFO_L && LIBIVA_TRC && en)

/* VB trace control */
#define LIBVB_TRACE_ERR               LIBVB_ERR(TRC_ON)
#define LIBVB_TRACE_WARN              LIBVB_WARN(TRC_ON)
#define LIBVB_TRACE_H                 LIBVB_INFO_H(TRC_ON)
#define LIBVB_TRACE_M                 LIBVB_INFO_M(TRC_ON)
#define LIBVB_TRACE_L                 LIBVB_INFO_L(TRC_ON)

/* SR trace control */
#define LIBSR_TRACE_ERR               LIBSR_ERR(TRC_ON)
#define LIBSR_TRACE_WARN              LIBSR_WARN(TRC_ON)
#define LIBSR_TRACE_H                 LIBSR_INFO_H(TRC_ON)
#define LIBSR_TRACE_M                 LIBSR_INFO_M(TRC_ON)
#define LIBSR_TRACE_L                 LIBSR_INFO_L(TRC_ON)

/* SENIF trace control */
#define LIBSENIF_TRACE_ERR            LIBSENIF_ERR(TRC_ON)
#define LIBSENIF_TRACE_WARN           LIBSENIF_WARN(TRC_ON)
#define LIBSENIF_TRACE_H              LIBSENIF_INFO_H(TRC_ON)
#define LIBSENIF_TRACE_M              LIBSENIF_INFO_M(TRC_ON)
#define LIBSENIF_TRACE_L              LIBSENIF_INFO_L(TRC_ON)

/* IS trace control */
#define LIBIS_TRACE_ERR               LIBIS_ERROR(TRC_ON)
#define LIBIS_TRACE_WARN              LIBIS_WARN(TRC_ON)
#define LIBIS_TRACE_H                 LIBIS_INFO_H(TRC_ON)
#define LIBIS_TRACE_M                 LIBIS_INFO_M(TRC_ON)
#define LIBIS_TRACE_L                 LIBIS_INFO_L(TRC_ON)

/* ISP trace control */
#define LIBISP_TRACE_ERR              LIBISP_ERR(TRC_ON)
#define LIBISP_TRACE_WARN             LIBISP_WARN(TRC_ON)
#define LIBISP_TRACE_H                LIBISP_INFO_H(TRC_ON)
#define LIBISP_TRACE_M                LIBISP_INFO_M(TRC_ON)
#define LIBISP_TRACE_L                LIBISP_INFO_L(TRC_ON)

/* ENC trace control */
#define LIBENC_TRACE_ERR              LIBENC_ERR(TRC_ON)
#define LIBENC_TRACE_WARN             LIBENC_WARN(TRC_ON)
#define LIBENC_TRACE_H                LIBENC_INFO_H(TRC_ON)
#define LIBENC_TRACE_M                LIBENC_INFO_M(TRC_ON)
#define LIBENC_TRACE_L                LIBENC_INFO_L(TRC_ON)

/* OSD trace control */
#define LIBOSD_TRACE_ERR              LIBOSD_ERR(TRC_ON)
#define LIBOSD_TRACE_WARN             LIBOSD_WARN(TRC_ON)
#define LIBOSD_TRACE_H                LIBOSD_INFO_H(TRC_ON)
#define LIBOSD_TRACE_M                LIBOSD_INFO_M(TRC_ON)
#define LIBOSD_TRACE_L                LIBOSD_INFO_L(TRC_ON)

/* VPC trace control */
#define LIBVPC_TRACE_ERR              LIBVPC_ERR(TRC_ON)
#define LIBVPC_TRACE_WARN             LIBVPC_WARN(TRC_ON)
#define LIBVPC_TRACE_H                LIBVPC_INFO_H(TRC_ON)
#define LIBVPC_TRACE_M                LIBVPC_INFO_M(TRC_ON)
#define LIBVPC_TRACE_L                LIBVPC_INFO_L(TRC_ON)

/* DIP trace control */
#define LIBDIP_TRACE_ERR              LIBDIP_ERR(TRC_ON)
#define LIBDIP_TRACE_WARN             LIBDIP_WARN(TRC_ON)
#define LIBDIP_TRACE_H                LIBDIP_INFO_H(TRC_ON)
#define LIBDIP_TRACE_M                LIBDIP_INFO_M(TRC_ON)
#define LIBDIP_TRACE_L                LIBDIP_INFO_L(TRC_ON)

/* IVA trace control */
#define LIBIVA_TRACE_ERR              LIBIVA_ERR(TRC_ON)
#define LIBIVA_TRACE_WARN             LIBIVA_WARN(TRC_ON)
#define LIBIVA_TRACE_H                LIBIVA_INFO_H(TRC_ON)
#define LIBIVA_TRACE_M                LIBIVA_INFO_M(TRC_ON)
#define LIBIVA_TRACE_L                LIBIVA_INFO_L(TRC_ON)


typedef enum trace_space {
	TRACE_SPACE_USER,
	TRACE_SPACE_KER,
	TRACE_SPACE_NUM,
} TraceSpace;

typedef enum trace_type {
	TRACE_TYPE_INFO_L,
	TRACE_TYPE_INFO_M,
	TRACE_TYPE_INFO_H,
	TRACE_TYPE_WARN,
	TRACE_TYPE_ERROR,
	TRACE_TYPE_NUM,
} TraceType;

/* Do NOT change the order of enum elements */
typedef enum trace_item {
	TRACE_ITEM_SR,
	TRACE_ITEM_VB,
	TRACE_ITEM_IS,
	TRACE_ITEM_ISP,
	TRACE_ITEM_ENC,
	TRACE_ITEM_OSD,
	TRACE_ITEM_SENIF,
	TRACE_ITEM_VPC,
	TRACE_ITEM_DIP,
	TRACE_ITEM_IVA,
	TRACE_ITEM_NUM, /* new item should be added prior to this one */
} TraceItem;

/* Do NOT change the order of enum elements */
typedef enum trace_ker_item {
	TRACE_KER_ITEM_SR,
	TRACE_KER_ITEM_VB,
	TRACE_KER_ITEM_IS,
	TRACE_KER_ITEM_ISP,
	TRACE_KER_ITEM_ENC,
	TRACE_KER_ITEM_OSD,
	TRACE_KER_ITEM_SENIF,
	TRACE_KER_ITEM_NUM, /* new item should be added prior to this one */
} TraceKerItem;


#endif /* !ASSERT_DEF_H_ */
