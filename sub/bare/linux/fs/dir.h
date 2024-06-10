#ifndef __BARE_LINUX_DIR_H__
#define __BARE_LINUX_DIR_H__

#include "../abi.h"

#include <sys/syscall.h>
#include <linux/types.h>
#include <linux/fcntl.h>

/*
 * int mkdir(const char *path, mode_t mode);
 */

static __attribute__((unused))
int sys_mkdir(const char *path, mode_t mode)
{
#ifdef __NR_mkdirat
	return my_syscall3(__NR_mkdirat, AT_FDCWD, path, mode);
#elif defined(__NR_mkdir)
	return my_syscall2(__NR_mkdir, path, mode);
#else
	return __nolibc_enosys(__func__, path, mode);
#endif
}

static __attribute__((unused))
int mkdir(const char *path, mode_t mode)
{
	return __sysret(sys_mkdir(path, mode));
}

/*
 * int rmdir(const char *path);
 */

static __attribute__((unused))
int sys_rmdir(const char *path)
{
#ifdef __NR_rmdir
	return my_syscall1(__NR_rmdir, path);
#elif defined(__NR_unlinkat)
	return my_syscall3(__NR_unlinkat, AT_FDCWD, path, AT_REMOVEDIR);
#else
	return __nolibc_enosys(__func__, path);
#endif
}

static __attribute__((unused))
int rmdir(const char *path)
{
	return __sysret(sys_rmdir(path));
}


/*
 * int mknod(const char *path, mode_t mode, dev_t dev);
 */

static __attribute__((unused))
long sys_mknod(const char *path, mode_t mode, dev_t dev)
{
#ifdef __NR_mknodat
	return my_syscall4(__NR_mknodat, AT_FDCWD, path, mode, dev);
#elif defined(__NR_mknod)
	return my_syscall3(__NR_mknod, path, mode, dev);
#else
	return __nolibc_enosys(__func__, path, mode, dev);
#endif
}

static __attribute__((unused))
int mknod(const char *path, mode_t mode, dev_t dev)
{
	return __sysret(sys_mknod(path, mode, dev));
}

static __attribute__((unused))
int sys_mount(const char *src, const char *tgt, const char *fst,
                     unsigned long flags, const void *data)
{
	return my_syscall5(__NR_mount, src, tgt, fst, flags, data);
}

static __attribute__((unused))
int mount(const char *src, const char *tgt,
          const char *fst, unsigned long flags,
          const void *data)
{
	return __sysret(sys_mount(src, tgt, fst, flags, data));
}


#endif
