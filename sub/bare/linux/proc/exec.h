#ifndef __BARE_LINUX_PROC_EXEC_H__
#define __BARE_LINUX_PROC_EXEC_H__

#include "../abi.h"

static __attribute__((unused))
int sys_execve(const char *filename, char *const argv[], char *const envp[])
{
	return my_syscall3(__NR_execve, filename, argv, envp);
}

static __attribute__((unused))
int execve(const char *filename, char *const argv[], char *const envp[])
{
	return __sysret(sys_execve(filename, argv, envp));
}

#endif
