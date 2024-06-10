#ifndef __BARE_LINUX_PROC_EXIT_H__
#define __BARE_LINUX_PROC_EXIT_H__

#include "../abi.h"

static __attribute__((noreturn,unused))
void sys_exit(int status)
{
	my_syscall1(__NR_exit, status & 255);
	while(1); /* shut the "noreturn" warnings. */
}

static __attribute__((noreturn,unused))
void exit(int status)
{
	sys_exit(status);
}

#endif
