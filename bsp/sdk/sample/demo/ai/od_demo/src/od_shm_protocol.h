#if defined(AOV_BLOCK_BY_OBJECT)
#ifndef _OD_SHM_PROTOCOL_H_
#define _OD_SHM_PROTOCOL_H_

#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

/* Shared Memory Identifier */
#define OD_SHM_NAME        "/vftr_od_status"
#define OD_SHM_SIZE        64 
#define OD_NAME_MAX_LEN 32

typedef struct {
    volatile bool detect_flag;  /* 0: No target, 1: Target detected */
    volatile int obj_num;      /* Total objects in current frame */
    volatile unsigned int seq; /* Updated by Writer to notify Reader */
    char od_name[OD_NAME_MAX_LEN];
    int reserved[8];
} od_shm_data_t;

#endif
#endif