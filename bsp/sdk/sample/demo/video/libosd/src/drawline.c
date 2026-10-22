#include "drawline.h"
#include "libosd.h"

int calcNewLine(int startx, int starty, int endx, int endy, int thickness, OsdRegion *targetReg, OsdLine *output)
{
	if ((startx == endx) && (starty == endy)) {
		libosd_log_err("this is not a line");
		return -EINVAL;
	}

	if ((startx < (int)targetReg->startX)) {
		libosd_log_info("start exceed region: %d->%d", startx, targetReg->startX);
		startx = targetReg->startX;
	}

	if ((starty < (int)targetReg->startY)) {
		libosd_log_info("start exceed region: %d->%d", starty, targetReg->startY);
		starty = targetReg->startY;
	}

	if (startx >= (int)(targetReg->startX + targetReg->width - 1)) {
		libosd_log_info("end exceed region: %d->%d", endx, targetReg->startX + targetReg->width - 1);
		startx = targetReg->startX + targetReg->width - 1;
	}

	if (starty >= (int)(targetReg->startY + targetReg->height - 1)) {
		libosd_log_info("end exceed region: %d->%d", endy, targetReg->startY + targetReg->height - 1);
		starty = targetReg->startY + targetReg->height - 1;
	}

	if ((endx < (int)targetReg->startX)) {
		libosd_log_info("start exceed region: %d->%d", startx, targetReg->startX);
		endx = targetReg->startX;
	}

	if ((endy < (int)targetReg->startY)) {
		libosd_log_info("start exceed region: %d->%d", starty, targetReg->startY);
		endy = targetReg->startY;
	}

	if (endx >= (int)(targetReg->startX + targetReg->width - 1)) {
		libosd_log_info("end exceed region: %d->%d", endx, targetReg->startX + targetReg->width - 1);
		endx = targetReg->startX + targetReg->width - 1;
	}

	if (endy >= (int)(targetReg->startY + targetReg->height - 1)) {
		libosd_log_info("end exceed region: %d->%d", endy, targetReg->startY + targetReg->height - 1);
		endy = targetReg->startY + targetReg->height - 1;
	}

	output->start.x = startx;
	output->start.y = starty;
	output->end.x = endx;
	output->end.y = endy;
	output->thickness = thickness;

	return 0;
}

void initTransBack(OsdRegion *region, char *ayuv_buf)
{
	int y, u, v, i, j;
	int ayuv_idx = 0;
	int set_a, set_r, set_g, set_b;

	/*draw to  white*/
	for (i = 0; (uint32_t)i < region->height; i++) {
		for (j = 0; (uint32_t)j < region->width; j++) {
			set_a = 0x00;
			set_b = 0xff;
			set_g = 0xff;
			set_r = 0xff;

#if 0
			y = 0.299 * set_r + 0.587 * set_g + 0.114 * set_b;
			u = -0.147 * set_r - 0.289 * set_g + 0.436 * set_b + 128;
			v = 0.615 * set_r - 0.515 * set_g - 0.100 * set_b + 128;
#else
			RGBTrans2YUV(&set_r, &set_g, &set_b, &y, &u, &v);
#endif

			normalizeAYUV3544(&set_a, &y, &u, &v);

			ayuv_buf[ayuv_idx] = MERGE44(u, v);
			ayuv_idx += 1;
			ayuv_buf[ayuv_idx] = MERGE35(set_a, y);
			ayuv_idx += 1;
		}
	}
}

int setColorPixel(int px, int py, char *color, int canvas_width, int x_offset __attribute__((unused)), int y_offset,
                  OsdRegion *region, COLOR_MODE mode, char *ayuvBuf)
{
	if ((px <= 0) || ((uint32_t)px >= region->width)) {
		return -EINVAL;
	}

	if ((py <= 0) || ((uint32_t)(py + y_offset) >= region->height - 2)) {
		return -EINVAL;
	}
	libosd_log_debug("come %d %d %d %d", px, py, x_offset, y_offset);

	int set_a, set_r, set_g, set_b;
	int ayuv_idx = 0;
	if (mode == AYUV_3544) {
		ayuv_idx = ((y_offset + py) * canvas_width + (px)) * 2;
		int y, u, v;

		set_a = color[3];
		set_r = color[0];
		set_g = color[1];
		set_b = color[2];

		RGBTrans2YUV(&set_r, &set_g, &set_b, &y, &u, &v);
		normalizeAYUV3544(&set_a, &y, &u, &v);
		if (ayuv_idx < 0) {
			libosd_log_err("ayuv idx < 0: %d", ayuv_idx);
			return -EINVAL;
		}
		libosd_log_debug("ayuv idx :%d %d %d", ayuv_idx, MERGE44(u, v), MERGE35(set_a, y));

		ayuvBuf[ayuv_idx] = MERGE44(u, v);
		ayuv_idx += 1;
		ayuvBuf[ayuv_idx] = MERGE35(set_a, y);

	} else if (mode == PALETTE_8) {
		ayuv_idx = ((y_offset + py) * canvas_width + (px));
		char alpha = color[0];
		char color_idx = color[1];
		if (ayuv_idx < 0) {
			libosd_log_err("ayuv idx < 0: %d", ayuv_idx);
			return -EINVAL;
		}

		ayuvBuf[ayuv_idx] = MERGE35(alpha, color_idx);
	}

	return 0;
}

void bresenhamLine(int x0, int y0, int x1, int y1, char *color, int canvas_width, int x_offset, int y_offset,
                   OsdRegion *region, COLOR_MODE mode, char *ayuvBuf)
{
	int delta_x = abs(x1 - x0), step_x = x0 < x1 ? 1 : -1;
	int delta_y = abs(y1 - y0), step_y = y0 < y1 ? 1 : -1;
	int err = (delta_x > delta_y ? delta_x : -delta_y) / 2;

	while (setColorPixel(x0, y0, color, canvas_width, x_offset, y_offset, region, mode, ayuvBuf),
	       x0 != x1 || y0 != y1) {
		int e2 = err;
		if (e2 > -delta_x) {
			err -= delta_y;
			x0 += step_x;
		}
		if (e2 < delta_y) {
			err += delta_x;
			y0 += step_y;
		}
	}
}

void drawLineOverlap(unsigned int aXStart, unsigned int aYStart, unsigned int aXEnd, unsigned int aYEnd,
                     uint8_t aOverlap, char *color, int canvas_width, int x_offset, int y_offset, OsdRegion *region,
                     COLOR_MODE mode, char *ayuvBuf)
{
	int16_t error, delta_x_double, delta_y_double;
	int16_t delta_x = aXEnd - aXStart;
	int16_t delta_y = aYEnd - aYStart;
	int16_t step_x = (delta_x < 0) ? -1 : 1;
	int16_t step_y = (delta_y < 0) ? -1 : 1;

	delta_x = (delta_x < 0) ? -delta_x : delta_x;
	delta_y = (delta_y < 0) ? -delta_y : delta_y;
	delta_x_double = delta_x << 1;
	delta_y_double = delta_y << 1;

	/*draw start pixel*/
	setColorPixel(aXStart, aYStart, color, canvas_width, x_offset, y_offset, region, mode, ayuvBuf);
	if (delta_x > delta_y) {
		/* start value represents a half step in Y direction*/
		error = delta_y_double - delta_x;
		while (aXStart != aXEnd) {
			/* step in main direction*/
			aXStart += step_x;
			if (error >= 0) {
				if (aOverlap & LINE_OVERLAP_MAJOR) {
					/* draw pixel in main direction before changing */
					setColorPixel(aXStart, aYStart, color, canvas_width, x_offset, y_offset, region,
					              mode, ayuvBuf);
				}
				/* change Y */
				aYStart += step_y;
				if (aOverlap & LINE_OVERLAP_MINOR) {
					/* draw pixel in minor direction before changing */
					setColorPixel(aXStart, aYStart, color, canvas_width, x_offset, y_offset, region,
					              mode, ayuvBuf);
				}
				error -= delta_x_double;
			}
			error += delta_y_double;
			setColorPixel(aXStart, aYStart, color, canvas_width, x_offset, y_offset, region, mode, ayuvBuf);
		}
	} else {
		error = delta_x_double - delta_y;
		while (aYStart != aYEnd) {
			aYStart += step_y;
			if (error >= 0) {
				if (aOverlap & LINE_OVERLAP_MAJOR) {
					/* draw pixel in main direction before changing*/
					setColorPixel(aXStart, aYStart, color, canvas_width, x_offset, y_offset, region,
					              mode, ayuvBuf);
				}
				aXStart += step_x;
				if (aOverlap & LINE_OVERLAP_MINOR) {
					/* draw pixel in minor direction before changing*/
					setColorPixel(aXStart, aYStart, color, canvas_width, x_offset, y_offset, region,
					              mode, ayuvBuf);
				}
				error -= delta_y_double;
			}
			error += delta_x_double;
			setColorPixel(aXStart, aYStart, color, canvas_width, x_offset, y_offset, region, mode, ayuvBuf);
		}
	}
}

void drawThickLineSimple(unsigned int aXStart, unsigned int aYStart, unsigned int aXEnd, unsigned int aYEnd,
                         unsigned int aThickness, uint8_t aThicknessMode, char *color, int canvas_width, int x_offset,
                         int y_offset, OsdRegion *region, COLOR_MODE mode, char *ayuvBuf)
{
	unsigned int i;
	int16_t error, delta_x_double, delta_y_double;
	int16_t delta_y = aXStart - aXEnd;
	int16_t delta_x = aYEnd - aYStart;
	int16_t step_y = (delta_y < 0) ? -1 : 1;
	int16_t step_x = (delta_x < 0) ? -1 : 1;
	bool overlapMode = LINE_OVERLAP_NONE;

	delta_y = (delta_y < 0) ? -delta_y : delta_y;
	delta_x = (delta_x < 0) ? -delta_x : delta_x;
	delta_x_double = delta_x << 1;
	delta_y_double = delta_y << 1;

	/* which octant are we now*/
	if (delta_x > delta_y) {
		if (aThicknessMode == LINE_THICKNESS_MIDDLE) {
			/* adjust draw start point*/
			error = delta_y_double - delta_x;
			for (i = aThickness / 2; i > 0; i--) {
				/* change X (main direction here) */
				aXStart -= step_x;
				aXEnd -= step_x;
				if (error >= 0) {
					/* change Y*/
					aYStart -= step_y;
					aYEnd -= step_y;
					error -= delta_x_double;
				}
				error += delta_y_double;
			}
		}
		/*draw start line*/
		bresenhamLine(aXStart, aYStart, aXEnd, aYEnd, color, canvas_width, x_offset, y_offset, region, mode,
		              ayuvBuf);

		/* draw aThickness lines */
		error = delta_y_double - delta_x;
		for (i = aThickness; i > 1; i--) {
			/* change X (main direction here)*/
			aXStart += step_x;
			aXEnd += step_x;
			overlapMode = LINE_OVERLAP_BOTH;

			if (error >= 0) {
				/* change Y */
				aYStart += step_y;
				aYEnd += step_y;
				error -= delta_x_double;
				overlapMode = LINE_OVERLAP_BOTH;
			}
			error += delta_y_double;
			drawLineOverlap(aXStart, aYStart, aXEnd, aYEnd, overlapMode, color, canvas_width, x_offset,
			                y_offset, region, mode, ayuvBuf);
		}
	} else {
		/* adjust draw start point */
		if (aThicknessMode == LINE_THICKNESS_MIDDLE) {
			error = delta_x_double - delta_y;
			for (i = aThickness / 2; i > 0; i--) {
				aYStart -= step_y;
				aYEnd -= step_y;

				if (error >= 0) {
					aXStart -= step_x;
					aXEnd -= step_x;
					error -= delta_y_double;
				}
				error += delta_x_double;
			}
		}
		/*draw start line */
		bresenhamLine(aXStart, aYStart, aXEnd, aYEnd, color, canvas_width, x_offset, y_offset, region, mode,
		              ayuvBuf);

		error = delta_x_double - delta_y;
		for (i = aThickness; i > 1; i--) {
			aYStart += step_y;
			aYEnd += step_y;
			overlapMode = LINE_OVERLAP_BOTH;

			if (error >= 0) {
				aXStart += step_x;
				aXEnd += step_x;
				error -= delta_y_double;
				overlapMode = LINE_OVERLAP_BOTH;
			}
			error += delta_x_double;
			drawLineOverlap(aXStart, aYStart, aXEnd, aYEnd, overlapMode, color, canvas_width, x_offset,
			                y_offset, region, mode, ayuvBuf);
		}
	}
}
