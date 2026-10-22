#ifdef EARLY_DETECT
#include <stdint.h>

#include "false_alarm_detect_utils.h"

static int getRectArea(const RECT_POINT_S *rect)
{
	return (rect->ex - rect->sx + 1) * (rect->ey - rect->sy + 1);
}

static void Heapify(std::vector<DetBox>& input, int n, int i)
{
	int smallest = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;

	if (left < n && input[left].conf < input[smallest].conf) {
		smallest = left;
	}

	if (right < n && input[right].conf < input[smallest].conf) {
		smallest = right;
	}

	if (smallest != i) {
		std::swap(input[i], input[smallest]);
		Heapify(input, n, smallest);
	}
}

static void HeapSort(std::vector<DetBox>& input)
{
	int n = input.size();

	for (int i = n / 2 - 1; i >= 0; --i) {
		Heapify(input, n, i);
	}

	for (int i = n - 1; i > 0; --i) {
		std::swap(input[0], input[i]);
		Heapify(input, i, 0);
	}
}

void NmsBoxes(std::vector<DetBox>& input, float iou, uint32_t max_cnt, std::vector<DetBox>& output)
{
	// Sort the input boxes based on their confidence scores (or any other relevant criterion)
	HeapSort(input);

	// Number of input boxes
	uint32_t box_num = input.size();

	// Vector to keep track of merged boxes
	std::vector<int> merged(box_num, 0);

	// Loop through each input box
	for (uint32_t i = 0; i < box_num; i++) {
		// Skip the box if it's already merged with another box
		if (merged[i])
			continue;

		// Add the current box to the output list
		output.push_back(input[i]);

		// Check if we've reached the maximum number of output boxes
		if (output.size() == max_cnt)
			return;

		// Calculate area of the current box
		float h0 = input[i].rect.ey - input[i].rect.sy + 1;
		float w0 = input[i].rect.ex - input[i].rect.sx + 1;
		float area0 = h0 * w0;

		// Compare the current box with the remaining boxes
		for (uint32_t j = i + 1; j < box_num; j++) {
			// Skip the box if it's already merged with another box
			if (merged[j])
				continue;

			// Calculate intersection coordinates and dimensions
			float inner_x0 = std::max(input[i].rect.sx, input[j].rect.sx);
			float inner_y0 = std::max(input[i].rect.sy, input[j].rect.sy);
			float inner_x1 = std::min(input[i].rect.ex, input[j].rect.ex);
			float inner_y1 = std::min(input[i].rect.ey, input[j].rect.ey);
			float inner_h = std::max(0.0f, inner_y1 - inner_y0 + 1);
			float inner_w = std::max(0.0f, inner_x1 - inner_x0 + 1);
			float inner_area = inner_h * inner_w;

			// Calculate area of the other box
			float h1 = input[j].rect.ey - input[j].rect.sy + 1;
			float w1 = input[j].rect.ex - input[j].rect.sx + 1;
			float area1 = h1 * w1;

			// Calculate IoU score
			float score = inner_area / (area0 + area1 - inner_area);


			// If IoU score is above the threshold, mark the other box as merged
			if (score > iou)
				merged[j] = 1;
		}
	}
}

int update_model_shape(ncnn::Net& net, int target_width, int target_height) {
	/* NOTE: the INDICES and VALUES are dedicated for ODv5.2 */
	int _h, _w, _d, _c;
	int total = 0;

	// Precomputed constants
	int wxh = (target_width >> 3) * (target_height >> 3);
	int head_w = target_width >> 5;
	int head_h = target_height >> 5;

	// Helper lambda to update layer dimensions
	auto update_layer = [&](int layer_index, int new_w, int new_h = -1) {
		net.mutable_layers()[layer_index]->get_attr(_h, _w, _d, _c);
		net.mutable_layers()[layer_index]->set_attr(new_h == -1 ? _h : new_h, new_w, _d, _c);
	};

	std::vector<int> layer_indices_1(2);
	layer_indices_1[0] = 251;
	layer_indices_1[1] = 252;
	for (int layer_index : layer_indices_1) {
		update_layer(layer_index, wxh);
		total += wxh;
		wxh >>= 2; // Divide wxh by 4
	}

	total += wxh;
	std::vector<int> layer_indices_2(3);
	layer_indices_2[0] = 253;
	layer_indices_2[1] = 105;
	layer_indices_2[2] = 125;
	for (int layer_index : layer_indices_2) {
		update_layer(layer_index, wxh);
	}

	// Update layers 257 and 261 with tota
	std::vector<int> layer_indices_3(2);
	layer_indices_3[0] = 256;
	layer_indices_3[1] = 260;
	for (int layer_index : layer_indices_3) {
		update_layer(layer_index, total);
	}

	// Update tensor dimensions in layers
	std::vector<int> layer_indices_4(4);
	layer_indices_4[0] = 113;
	layer_indices_4[1] = 114;
	layer_indices_4[2] = 133;
	layer_indices_4[3] = 134;
	for (int layer_index : layer_indices_4) {
		update_layer(layer_index, head_w, head_h);
	}

	return 0;
}


void getROIsFromMV(const UbootMvInfo *uboot_mv,
                           CurrMovObjList *curr_mol)
{
	(void) uboot_mv;
	(void) curr_mol;
	return;
}

void refineROI(RECT_POINT_S& rect, int min_size, int W, int H) {
	int width = rect.ex - rect.sx;
	int height = rect.ey - rect.sy;
	int centerX = rect.sx + width / 2;
	int centerY = rect.sy + height / 2;

	width = width*1.2;
	width = std::max(width, min_size);

	height = height*1.2;
	height = std::max(height, min_size);

	rect.sx = centerX - width / 2;
	rect.sy = centerY - height / 2;
	rect.ex = rect.sx + width;
	rect.ey = rect.sy + height;

	// Ensure the square does not exceed the boundaries
	rect.sx = std::min(std::max(0, (int)rect.sx), W-1);
	rect.ex = std::min(std::max(0, (int)rect.ex), W-1);
	rect.sy = std::min(std::max(0, (int)rect.sy), H-1);
	rect.ey = std::min(std::max(0, (int)rect.ey), H-1);
}

void getMaxROIFromList(CurrMovObjList *curr_mol, RECT_POINT_S *roi_out, int *idx)
{
	int max_area = 0;
	for (int i = 0; i < curr_mol->obj_cnt; i++) {
		int area = getRectArea(&curr_mol->obj[i].rect);
		if (area > max_area) {
			max_area = area;
			*idx = i;
		}
	}
	*roi_out = curr_mol->obj[*idx].rect;
	return;
}

#endif	// EARLY_DETECT

