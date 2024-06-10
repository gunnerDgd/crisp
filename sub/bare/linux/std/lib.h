#ifndef __BARE_LINUX_STD_LIB_H__
#define __BARE_LINUX_STD_LIB_H__

#include "../abi.h"

static __attribute__((unused)) char itoa_buffer[21];

static __attribute__((unused))
long atol(const char *s)
{
	unsigned long ret = 0;
	unsigned long d;
	int neg = 0;

	if (*s == '-') {
		neg = 1;
		s++;
	}

	while (1) {
		d = (*s++) - '0';
		if (d > 9)
			break;
		ret *= 10;
		ret += d;
	}

	return neg ? -ret : ret;
}

static __attribute__((unused))
int atoi(const char *s)
{
	return atol(s);
}

static __attribute__((unused))
int utoh_r(unsigned long in, char *buffer)
{
	signed char pos = (~0UL > 0xfffffffful) ? 60 : 28;
	int digits = 0;
	int dig;

	do {
		dig = in >> pos;
		in -= (uint64_t)dig << pos;
		pos -= 4;
		if (dig || digits || pos < 0) {
			if (dig > 9)
				dig += 'a' - '0' - 10;
			buffer[digits++] = '0' + dig;
		}
	} while (pos >= 0);

	buffer[digits] = 0;
	return digits;
}

static __attribute__((unused))
int utoa_r(unsigned long in, char *buffer)
{
	unsigned long lim;
	int digits = 0;
	int pos = (~0UL > 0xfffffffful) ? 19 : 9;
	int dig;

	do {
		for (dig = 0, lim = 1; dig < pos; dig++)
			lim *= 10;

		if (digits || in >= lim || !pos) {
			for (dig = 0; in >= lim; dig++)
				in -= lim;
			buffer[digits++] = '0' + dig;
		}
	} while (pos--);

	buffer[digits] = 0;
	return digits;
}

static __attribute__((unused))
int itoa_r(long in, char *buffer)
{
	char *ptr = buffer;
	int len = 0;

	if (in < 0) {
		in = -in;
		*(ptr++) = '-';
		len++;
	}
	len += utoa_r(in, ptr);
	return len;
}

static __inline__ __attribute__((unused))
char *ltoa_r(long in, char *buffer)
{
	itoa_r(in, buffer);
	return buffer;
}

static __inline__ __attribute__((unused))
char *itoa(long in)
{
	itoa_r(in, itoa_buffer);
	return itoa_buffer;
}

static __inline__ __attribute__((unused))
char *ltoa(long in)
{
	itoa_r(in, itoa_buffer);
	return itoa_buffer;
}

static __inline__ __attribute__((unused))
char *utoa(unsigned long in)
{
	utoa_r(in, itoa_buffer);
	return itoa_buffer;
}

static __attribute__((unused))
int u64toh_r(uint64_t in, char *buffer)
{
	signed char pos = 60;
	int digits = 0;
	int dig;

	do {
		if (sizeof(long) >= 8) {
			dig = (in >> pos) & 0xF;
		} else {
			/* 32-bit platforms: avoid a 64-bit shift */
			uint32_t d = (pos >= 32) ? (in >> 32) : in;
			dig = (d >> (pos & 31)) & 0xF;
		}
		if (dig > 9)
			dig += 'a' - '0' - 10;
		pos -= 4;
		if (dig || digits || pos < 0)
			buffer[digits++] = '0' + dig;
	} while (pos >= 0);

	buffer[digits] = 0;
	return digits;
}

static __inline__ __attribute__((unused))
char *u64toh(uint64_t in)
{
	u64toh_r(in, itoa_buffer);
	return itoa_buffer;
}

static __attribute__((unused))
int u64toa_r(uint64_t in, char *buffer)
{
	unsigned long long lim;
	int digits = 0;
	int pos = 19; /* start with the highest possible digit */
	int dig;

	do {
		for (dig = 0, lim = 1; dig < pos; dig++)
			lim *= 10;

		if (digits || in >= lim || !pos) {
			for (dig = 0; in >= lim; dig++)
				in -= lim;
			buffer[digits++] = '0' + dig;
		}
	} while (pos--);

	buffer[digits] = 0;
	return digits;
}

static __attribute__((unused))
int i64toa_r(int64_t in, char *buffer)
{
	char *ptr = buffer;
	int len = 0;

	if (in < 0) {
		in = -in;
		*(ptr++) = '-';
		len++;
	}
	len += u64toa_r(in, ptr);
	return len;
}

static __inline__ __attribute__((unused))
char *i64toa(int64_t in)
{
	i64toa_r(in, itoa_buffer);
	return itoa_buffer;
}

static __inline__ __attribute__((unused))
char *u64toa(uint64_t in)
{
	u64toa_r(in, itoa_buffer);
	return itoa_buffer;
}

#endif
