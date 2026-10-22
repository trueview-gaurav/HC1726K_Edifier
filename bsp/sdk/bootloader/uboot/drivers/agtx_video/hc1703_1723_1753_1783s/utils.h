#ifndef AGTX_VIDEO_UTILS_H_
#define AGTX_VIDEO_UTILS_H_

#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define CEIL(x) ((x) == (int)(x) ? (int)(x) : (int)((x) + 1))
#define FLOOR(x) ((x) < 0 && (x) != (int)(x) ? (int)(x)-1 : (int)(x))
#define round_up_div(value, base) ((value) + (base - 1)) / (base)
#define round_down_div(value, base) ((value) / (base))
#define round_up_base(value, base) (((value) + (base - 1)) / (base)) * (base)
#define round_down_base(value, base) ((value) / (base)) * (base)

#define SWAP(a, b)                      \
	do {                            \
		__typeof__(a) _tmp = a; \
		a = b;                  \
		b = _tmp;               \
	} while (0)

#endif