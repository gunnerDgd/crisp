#ifndef __BARE_LINUX_PROC_EXEC_H__
#define __BARE_LINUX_PROC_EXEC_H__

#include "../abi.h"
#include <asm/signal.h>

#ifndef sys_fork
static __attribute__((unused))
pid_t sys_fork(void)
{
#ifdef __NR_clone
	/* note: some archs only have clone() and not fork(). Different archs
	 * have a different API, but most archs have the flags on first arg and
	 * will not use the rest with no other flag.
	 */
	return my_syscall5(__NR_clone, SIGCHLD, 0, 0, 0, 0);
#elif defined(__NR_fork)
	return my_syscall0(__NR_fork);
#else
	return __nolibc_enosys(__func__);
#endif
}
#endif

static __attribute__((unused))
pid_t fork(void)
{
	return __sysret(sys_fork());
}

#endif
