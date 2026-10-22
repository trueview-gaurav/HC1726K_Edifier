#include <stdlib.h>
#include <stdint.h>

size_t strlen(const char *str)
{
	const char *tmp = str;

	while (*tmp)
		tmp++;

	return tmp - str;
}

int strncmp(const char *strg1, const char *strg2, size_t n)
{
	while ((*strg1 != '\0' && *strg2 != '\0') && *strg1 == *strg2 && n) {
		strg1++;
		strg2++;
		n--;
	}

	if (n == 0)
		return 0;

	if (*strg1 == *strg2) {
		return 0; // strings are identical
	} else {
		return *strg1 - *strg2;
	}
}

char *strncpy(char *dest, const char *src, size_t count)
{
	char *ret = dest;

	while (count-- && ('\0' != (*dest++ = *src++))) {
		/* do nothing */;
	}

	return ret;
}

int memcmp(const void *cs, const void *ct, size_t count)
{
	int ret = 0;
	const unsigned char *lhs; // left-hand side
	const unsigned char *rhs; // right-hand side

	lhs = cs;
	rhs = ct;
	for (; 0 < count; ++lhs, ++rhs, count--) {
		if (0 != (ret = *lhs - *rhs)) {
			break;
		}
	}
	return ret;
}

void *memcpy(void *dest, const void *src, unsigned int len)
{
	char *d = dest;
	const char *s = src;
	while (len--) {
		*d++ = *s++;
	}
	return dest;
}

void *memset(void *dest, int val, unsigned int len)
{
	unsigned char *ptr = dest;
	while (len-- > 0) {
		*ptr++ = val;
	}
	return dest;
}

int strcmp(const char *p1, const char *p2)
{
	const unsigned char *s1 = (const unsigned char *)p1;
	const unsigned char *s2 = (const unsigned char *)p2;
	unsigned char c1;
	unsigned char c2;

	do {
		c1 = (unsigned char)*s1++;
		c2 = (unsigned char)*s2++;
		if (c1 == '\0') {
			return c1 - c2;
		}
	} while (c1 == c2);

	return c1 - c2;
}

