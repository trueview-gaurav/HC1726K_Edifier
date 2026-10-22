#ifndef FLV_LIST_H_
#define FLV_LIST_H_

#include "flv_muxer.h"
#include "utlist.h"

VideoFrameNode *node_create(uint32_t len, uint8_t *data);
void list_free(VideoFrameNode **head);

#endif //FLV_LIST_H_