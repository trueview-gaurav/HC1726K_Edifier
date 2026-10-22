#ifdef USE_NCNN
#include <string.h>

void  *memmove(void *dest, const void *src, size_t n)
{
	char *tmp_dst = (char *)dest;
	char *tmp_src = (char *)src;
	void *ret_dst = dest;

	if (tmp_src < tmp_dst) {
		tmp_src += n;
		tmp_dst += n;

		for (; 0 != n; --n) {
			*--tmp_dst = *--tmp_src;
		}
	} else if (tmp_src != tmp_dst) {
		for (; 0 != n; --n) {
			*tmp_dst++ = *tmp_src++;
		}
	}

	return ret_dst;
}
#endif
