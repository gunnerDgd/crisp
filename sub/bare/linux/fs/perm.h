#ifndef __BARE_LINUX_PERM_H__
#define __BARE_LINUX_PERM_H__

#include <sys/syscall.h>
#include <linux/types.h>
#include <linux/fcntl.h>
#include "../abi.h"

static __attribute__((unused))
int sys_chmod(const char *path, mode_t mode)
{
#ifdef __NR_fchmodat
	return my_syscall4(__NR_fchmodat, AT_FDCWD, path, mode, 0);
#elif defined(__NR_chmod)
	return my_syscall2(__NR_chmod, path, mode);
#else
	return __nolibc_enosys(__func__, path, mode);
#endif
}

static __attribute__((unused))
int chmod(const char *path, mode_t mode)
{
	return __sysret(sys_chmod(path, mode));
}


/*
 * int chown(const char *path, uid_t owner, gid_t group);
 */

static __attribute__((unused))
int sys_chown(const char *path, uid_t owner, gid_t group)
{
#ifdef __NR_fchownat
	return my_syscall5(__NR_fchownat, AT_FDCWD, path, owner, group, 0);
#elif defined(__NR_chown)
	return my_syscall3(__NR_chown, path, owner, group);
#else
	return __nolibc_enosys(__func__, path, owner, group);
#endif
}

static __attribute__((unused))
int chown(const char *path, uid_t owner, gid_t group)
{
	return __sysret(sys_chown(path, owner, group));
}


/*
 * int chroot(const char *path);
 */

static __attribute__((unused))
int sys_chroot(const char *path)
{
	return my_syscall1(__NR_chroot, path);
}

static __attribute__((unused))
int chroot(const char *path)
{
	return __sysret(sys_chroot(path));
}

#endif
