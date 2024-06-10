#ifndef __BARE_LINUX_FILE_H__
#define __BARE_LINUX_FILE_H__

#include "../abi.h"

#include <sys/syscall.h>
#include <linux/fcntl.h>
#include <linux/types.h>

static __attribute__((unused))
int sys_open(const char *path, int flags, mode_t mode)
{
#ifdef __NR_openat
	return my_syscall4(__NR_openat, AT_FDCWD, path, flags, mode);
#elif defined(__NR_open)
	return my_syscall3(__NR_open, path, flags, mode);
#else
	return __nolibc_enosys(__func__, path, flags, mode);
#endif
}

static __attribute__((unused))
int open(const char *path, int flags, ...)
{
	mode_t mode = 0;

	if (flags & O_CREAT) {
		va_list args;

		va_start(args, flags);
		mode = va_arg(args, int);
		va_end(args);
	}

	return __sysret(sys_open(path, flags, mode));
}

static __attribute__((unused))
int sys_poll(struct pollfd *fds, int nfds, int timeout)
{
#if defined(__NR_ppoll)
	struct timespec t;

	if (timeout >= 0) {
		t.tv_sec  = timeout / 1000;
		t.tv_nsec = (timeout % 1000) * 1000000;
	}
	return my_syscall5(__NR_ppoll, fds, nfds, (timeout >= 0) ? &t : NULL, NULL, 0);
#elif defined(__NR_poll)
	return my_syscall3(__NR_poll, fds, nfds, timeout);
#else
	return __nolibc_enosys(__func__, fds, nfds, timeout);
#endif
}

static __attribute__((unused))
int poll(struct pollfd *fds, int nfds, int timeout)
{
	return __sysret(sys_poll(fds, nfds, timeout));
}


static __attribute__((unused))
int sys_ioctl(int fd, unsigned long req, void *value)
{
	return my_syscall3(__NR_ioctl, fd, req, value);
}

static __attribute__((unused))
int ioctl(int fd, unsigned long req, void *value)
{
	return __sysret(sys_ioctl(fd, req, value));
}

static __attribute__((unused))
ssize_t sys_read(int fd, void *buf, size_t count)
{
	return my_syscall3(__NR_read, fd, buf, count);
}

static __attribute__((unused))
ssize_t read(int fd, void *buf, size_t count)
{
	return __sysret(sys_read(fd, buf, count));
}

static __attribute__((unused))
ssize_t sys_write(int fd, const void *buf, size_t count)
{
	return my_syscall3(__NR_write, fd, buf, count);
}

static __attribute__((unused))
ssize_t write(int fd, const void *buf, size_t count)
{
	return __sysret(sys_write(fd, buf, count));
}

#endif
