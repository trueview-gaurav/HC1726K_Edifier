#include <stdlib.h>

#include "flv_list.h"
#include "utlist.h"
#include "log_define.h"

VideoFrameNode *node_create(uint32_t len, uint8_t *data)
{
	VideoFrameNode *new = malloc(sizeof(VideoFrameNode));
	if (!new) {
		flv_server_log_err("malloc failed with errno: %d", errno);
		return NULL;
	}

	new->len = len;
	new->data = data;
	new->next = NULL;
	return new;
}

void list_free(VideoFrameNode **head)
{
	VideoFrameNode *node, *tmp;
	LL_FOREACH_SAFE(*head, node, tmp)
	{
		LL_DELETE(*head, node);
		free(node);
	}
}