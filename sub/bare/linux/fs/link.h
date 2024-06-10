#ifndef __BARE_LINUX_LINK_H__
#define __BARE_LINUX_LINK_H__

#include "../abi.h"

#include <sys/syscall.h>
#include <linux/types.h>
#include <linux/fcntl.h>

static __attribute__((unused))
int sys_link(const char *old, const char *new)
{
#ifdef __NR_linkat
	return my_syscall5(__NR_linkat, AT_FDCWD, old, AT_FDCWD, new, 0);
#elif defined(__NR_link)
	return my_syscall2(__NR_link, old, new);
#else
	return __nolibc_enosys(__func__, old, new);
#endif
}

static __attribute__((unused))
int link(const char *old, const char *new)
{
	return __sysret(sys_link(old, new));
}


static __attribute__((unused))
int sys_unlink(const char *path)
{
#ifdef __NR_unlinkat
	return my_syscall3(__NR_unlinkat, AT_FDCWD, path, 0);
#elif defined(__NR_unlink)
	return my_syscall1(__NR_unlink, path);
#else
	return __nolibc_enosys(__func__, path);
#endif
}

static __attribute__((unused))
int unlink(const char *path)
{
	return __sysret(sys_unlink(path));
}

#endif
