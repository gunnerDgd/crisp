#ifndef __BARE_LINUX_STD_IO_H__
#define __BARE_LINUX_STD_IO_H__

#include "../abi.h"
#include "../fs.h"
#include "lib.h"

#ifndef EOF
#define EOF (-1)
#endif

#define _IOFBF 0	/* Fully buffered. */
#define _IOLBF 1	/* Line buffered. */
#define _IONBF 2	/* No buffering. */

typedef struct FILE {
	char dummy[1];
} FILE;

static __attribute__((unused)) FILE* const stdin  = (FILE*)(intptr_t)~0;
static __attribute__((unused)) FILE* const stdout = (FILE*)(intptr_t)~1;
static __attribute__((unused)) FILE* const stderr = (FILE*)(intptr_t)~2;

__attribute__((weak,unused,section(".text.nolibc_strlen")))
size_t strlen(const char *str)
{
	size_t len;

	for (len = 0; str[len]; len++)
		__asm__("");
	return len;
}

static __attribute__((unused))
int fileno(FILE *stream)
{
	intptr_t i = (intptr_t)stream;

	if (i >= 0) {
		SET_ERRNO(EBADF);
		return -1;
	}
	return ~i;
}

static __attribute__((unused))
int _fwrite(const void *buf, size_t size, FILE *stream)
{
	ssize_t ret;
	int fd = fileno(stream);

	while (size) {
		ret = write(fd, buf, size);
		if (ret <= 0)
			return EOF;
		size -= ret;
		buf += ret;
	}
	return 0;
}

static __attribute__((unused))
size_t fwrite(const void *s, size_t size, size_t nmemb, FILE *stream)
{
	size_t written;

	for (written = 0; written < nmemb; written++) {
		if (_fwrite(s, size, stream) != 0)
			break;
		s += size;
	}
	return written;
}

static __attribute__((unused, format(printf, 2, 0)))
int vfprintf(FILE *stream, const char *fmt, va_list args)
{
	char escape, lpref, c;
	unsigned long long v;
	unsigned int written;
	size_t len, ofs;
	char tmpbuf[21];
	const char *outstr;

	written = ofs = escape = lpref = 0;
	while (1) {
		c = fmt[ofs++];

		if (escape) {
			/* we're in an escape sequence, ofs == 1 */
			escape = 0;
			if (c == 'c' || c == 'd' || c == 'u' || c == 'x' || c == 'p') {
				char *out = tmpbuf;

				if (c == 'p')
					v = va_arg(args, unsigned long);
				else if (lpref) {
					if (lpref > 1)
						v = va_arg(args, unsigned long long);
					else
						v = va_arg(args, unsigned long);
				} else
					v = va_arg(args, unsigned int);

				if (c == 'd') {
					/* sign-extend the value */
					if (lpref == 0)
						v = (long long)(int)v;
					else if (lpref == 1)
						v = (long long)(long)v;
				}

				switch (c) {
				case 'c':
					out[0] = v;
					out[1] = 0;
					break;
				case 'd':
					i64toa_r(v, out);
					break;
				case 'u':
					u64toa_r(v, out);
					break;
				case 'p':
					*(out++) = '0';
					*(out++) = 'x';
					/* fall through */
				default: /* 'x' and 'p' above */
					u64toh_r(v, out);
					break;
				}
				outstr = tmpbuf;
			}
			else if (c == 's') {
				outstr = va_arg(args, char *);
				if (!outstr)
					outstr="(null)";
			}
			else if (c == '%') {
				/* queue it verbatim */
				continue;
			}
			else {
				/* modifiers or final 0 */
				if (c == 'l') {
					/* long format prefix, maintain the escape */
					lpref++;
				}
				escape = 1;
				goto do_escape;
			}
			len = strlen(outstr);
			goto flush_str;
		}

		/* not an escape sequence */
		if (c == 0 || c == '%') {
			/* flush pending data on escape or end */
			escape = 1;
			lpref = 0;
			outstr = fmt;
			len = ofs - 1;
		flush_str:
			if (_fwrite(outstr, len, stream) != 0)
				break;

			written += len;
		do_escape:
			if (c == 0)
				break;
			fmt += ofs;
			ofs = 0;
			continue;
		}

		/* literal char, just queue it */
	}
	return written;
}

static __attribute__((unused, format(printf, 1, 0)))
int vprintf(const char *fmt, va_list args)
{
	return vfprintf(stdout, fmt, args);
}

static __attribute__((unused, format(printf, 1, 2)))
int printf(const char *fmt, ...)
{
	va_list args;
	int ret;

	va_start(args, fmt);
	ret = vfprintf(stdout, fmt, args);
	va_end(args);
	return ret;
}

#endif
