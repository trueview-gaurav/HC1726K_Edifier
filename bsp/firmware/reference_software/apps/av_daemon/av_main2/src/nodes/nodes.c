#include "nodes.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>

#include "log_define.h"

Node g_nodes[NODE_NUM];

extern bool g_no_iva_flag;
extern bool g_no_image_preference_flag;
extern bool g_no_video_control_flag;

int NODES_initNodes(void)
{
	/*assign node id and func ptr*/
	g_nodes[VB].id = VB;
	g_nodes[VB].init = NODE_initVb;
	g_nodes[VB].start = NODE_startVb;
	g_nodes[VB].stop = NODE_stopVb;
	g_nodes[VB].exit = NODE_exitVb;
	g_nodes[VB].set = NULL;

	g_nodes[DEV].id = DEV;
	g_nodes[DEV].init = NODE_initDev;
	g_nodes[DEV].start = NODE_startDev;
	g_nodes[DEV].stop = NODE_stopDev;
	g_nodes[DEV].exit = NODE_exitDev;
	g_nodes[DEV].set = NODE_setDev;

	g_nodes[IMAGE_PREFERENCE].id = IMAGE_PREFERENCE;
	g_nodes[IMAGE_PREFERENCE].init = NODE_initImagePreference;
	g_nodes[IMAGE_PREFERENCE].start = NODE_startImagePreference;
	g_nodes[IMAGE_PREFERENCE].stop = NODE_stopImagePreference;
	g_nodes[IMAGE_PREFERENCE].exit = NODE_exitImagePreference;
	g_nodes[IMAGE_PREFERENCE].set = NODE_setImagePreference;

	g_nodes[CHN].id = CHN;
	g_nodes[CHN].init = NODE_initChn;
	g_nodes[CHN].start = NODE_startChn;
	g_nodes[CHN].stop = NODE_stopChn;
	g_nodes[CHN].exit = NODE_exitChn;
	g_nodes[CHN].set = NODE_setChn;

	g_nodes[WIN_IMAGE_PREFERENCE].id = WIN_IMAGE_PREFERENCE;
	g_nodes[WIN_IMAGE_PREFERENCE].init = NODE_initWinImagePreference;
	g_nodes[WIN_IMAGE_PREFERENCE].start = NODE_startWinImagePreference;
	g_nodes[WIN_IMAGE_PREFERENCE].stop = NODE_stopWinImagePreference;
	g_nodes[WIN_IMAGE_PREFERENCE].exit = NODE_exitWinImagePreference;
	g_nodes[WIN_IMAGE_PREFERENCE].set = NODE_setWinImagePreference;

	g_nodes[IVA].id = IVA;
	g_nodes[IVA].init = NODE_initIva;
	g_nodes[IVA].start = NODE_startIva;
	g_nodes[IVA].stop = NODE_stopIva;
	g_nodes[IVA].exit = NODE_exitIva;
	g_nodes[IVA].set = NODE_setIva;

	g_nodes[ENC].id = ENC;
	g_nodes[ENC].init = NODE_initEnc;
	g_nodes[ENC].start = NODE_startEnc;
	g_nodes[ENC].stop = NODE_stopEnc;
	g_nodes[ENC].exit = NODE_exitEnc;
	g_nodes[ENC].set = NODE_setEnc;

	/*link each Nodes to others*/
	/*VB*/
	g_nodes[VB].parent = NULL;
	g_nodes[VB].child[0] = &g_nodes[DEV];
	g_nodes[VB].child[1] = NULL;
	g_nodes[VB].child[2] = NULL;

	/*DEV*/
	g_nodes[DEV].parent = &g_nodes[VB];
	g_nodes[DEV].child[0] = &g_nodes[IMAGE_PREFERENCE];
	g_nodes[DEV].child[1] = &g_nodes[CHN];
	g_nodes[DEV].child[2] = NULL;

	/*IMAGE_PREFERENCE*/
	g_nodes[IMAGE_PREFERENCE].parent = &g_nodes[DEV];
	g_nodes[IMAGE_PREFERENCE].child[0] = NULL;
	g_nodes[IMAGE_PREFERENCE].child[1] = NULL;
	g_nodes[IMAGE_PREFERENCE].child[2] = NULL;

	/*CHN*/
	g_nodes[CHN].parent = &g_nodes[DEV];
	g_nodes[CHN].child[0] = &g_nodes[WIN_IMAGE_PREFERENCE];
	g_nodes[CHN].child[1] = &g_nodes[ENC];
	g_nodes[CHN].child[2] = &g_nodes[IVA];

	/*WIN_IMAGE_PREFERENCE*/
	g_nodes[WIN_IMAGE_PREFERENCE].parent = &g_nodes[CHN];
	g_nodes[WIN_IMAGE_PREFERENCE].child[0] = NULL;
	g_nodes[WIN_IMAGE_PREFERENCE].child[1] = NULL;
	g_nodes[WIN_IMAGE_PREFERENCE].child[2] = NULL;

	/*IVA*/
	g_nodes[IVA].parent = &g_nodes[CHN];
	g_nodes[IVA].child[0] = NULL;
	g_nodes[IVA].child[1] = NULL;
	g_nodes[IVA].child[2] = NULL;

	/*ENC*/
	g_nodes[ENC].parent = &g_nodes[CHN];
	g_nodes[ENC].child[0] = NULL;
	g_nodes[ENC].child[1] = NULL;
	g_nodes[ENC].child[2] = NULL;

	return 0;
}

static bool isSkipCase(Node *current)
{
	bool isSkip = false;

	if (current == NULL) {
		goto end;
	}

	if (current->id == IVA && g_no_iva_flag) {
		avmain2_log_notice("skip IVA");
		isSkip = true;
	}

	if (current->id == IMAGE_PREFERENCE && g_no_image_preference_flag) {
		avmain2_log_notice("skip  IMAGE_PREFERENCE");
		isSkip = true;
	}

	if ((current->id == VB || current->id == DEV || current->id == CHN || current->id == ENC) &&
	    g_no_video_control_flag) {
		avmain2_log_notice("skip VIDEO CONTROL");
		isSkip = true;
	}

end:
	return isSkip;
}

int NODES_enterNodespreOrderTraversal(Node *current)
{
	int ret = 0;
	if (current == NULL) {
		return 0;
	}

	avmain2_log_info("NODE id: %d", current->id);

	/*e.g if skip IVA, use main.c flag to skip .start() func of node_IVA at here */
	if (current->init != NULL && isSkipCase(current) == false) {
		if (current->init() != 0) {
			return ret;
		}
	} else {
		avmain2_log_err("init ptr == NULL");
	}

	NODES_enterNodespreOrderTraversal(current->child[0]);
	NODES_enterNodespreOrderTraversal(current->child[1]);
	NODES_enterNodespreOrderTraversal(current->child[2]);

	return 0;
}

int NODES_startNodespreOrderTraversal(Node *current)
{
	int ret = 0;
	if (current == NULL) {
		return 0;
	}

	avmain2_log_info("NODE id: %d", current->id);

	if (current->start != NULL && isSkipCase(current) == false) {
		if (current->start() != 0) {
			return ret;
		}
	} else {
		avmain2_log_err("start ptr == NULL");
	}
	NODES_startNodespreOrderTraversal(current->child[0]);
	NODES_startNodespreOrderTraversal(current->child[1]);
	NODES_startNodespreOrderTraversal(current->child[2]);

	return 0;
}

/*
method ref:
https://www.includehelp.com/data-structure-tutorial/reverse-postorder-traversal-in-binary-tree-using-recursion-in-c-cpp.aspx
*/
int NODES_leaveNodespreOrderTraversal(Node *current)
{
	int ret = 0;
	if (current == NULL) {
		return 0;
	}

	NODES_leaveNodespreOrderTraversal(((Node *)current)->child[2]);
	NODES_leaveNodespreOrderTraversal(((Node *)current)->child[1]);
	NODES_leaveNodespreOrderTraversal(((Node *)current)->child[0]);

	avmain2_log_info("NODE id: %d", current->id);

	if (current->stop != NULL && isSkipCase(current) == false) {
		ret = current->stop();
		if (ret != 0) {
			return ret;
		}
	} else {
		avmain2_log_err("stop ptr == NULL");
	}

	if (current->exit != NULL && isSkipCase(current) == false) {
		ret = current->exit();
		if (ret != 0) {
			return ret;
		}
	} else {
		avmain2_log_err("exit ptr == NULL");
	}

	return 0;
}

static int execStart(Node *current)
{
	if (current == NULL) {
		return 0;
	}

	int ret = 0;

	if (current->start != NULL && isSkipCase(current) == false) {
		ret = current->start();
		avmain2_log_debug("id %d start!", current->id);
		if (ret != 0) {
			return ret;
		}
	} else {
		avmain2_log_err("start ptr == NULL");
		return -EACCES;
	}

	execStart(current->child[0]);
	execStart(current->child[1]);
	execStart(current->child[2]);

	return 0;
}

static int execStop(Node *current)
{
	if (current == NULL) {
		return 0;
	}

	execStop(((Node *)current)->child[2]);
	execStop(((Node *)current)->child[1]);
	execStop(((Node *)current)->child[0]);

	int ret = 0;

	if (current->stop != NULL && isSkipCase(current) == false) {
		avmain2_log_debug("id %d stop!", current->id);
		ret = current->stop();
		if (ret != 0) {
			return ret;
		}
	} else {
		avmain2_log_err("stop ptr == NULL");
		return -EACCES;
	}

	return 0;
}

int NODES_execRestart(Node *current)
{
	if (current == NULL) {
		avmain2_log_err("node is NULL ptr");
		return -EACCES;
	}

	int ret = 0;

	ret = execStop(current);
	if (ret != 0) {
		avmain2_log_err("failed to exec stop, id:%d", current->id);
		return ret;
	}
	ret = execStart(current);
	if (ret != 0) {
		avmain2_log_err("failed to exec start, id:%d", current->id);
		return ret;
	}

	return 0;
}

int NODES_execSet(Node *node, int agtx_cmd_id, void *data)
{
	avmain2_log_debug("NODE id: %d", node->id);

	if ((node->set == NULL) || (data == NULL)) {
		avmain2_log_err("ptr is null");
		return -ENOENT;
	}

	if (isSkipCase(node)) {
		avmain2_log_info("skip this node");
		return 0;
	}

	int ret = 0;
	ret = node->set(agtx_cmd_id, data);
	if (ret != 0) {
		avmain2_log_err("failed to exec set");
		return -EINVAL;
	}
	return 0;
}
