#ifndef __BARE_LINUX_ABI_CALL_H__
#define __BARE_LINUX_ABI_CALL_H__

#include <asm/errno.h>

#define SET_ERRNO(v) do { errno = (v); } while (0)
int errno __attribute__((weak));

#define my_syscall0(num)                         \
({                                               \
	long _ret;                                   \
	register long _num  __asm__ ("rax") = (num); \
									             \
	__asm__ volatile (                           \
		"syscall\n"                              \
		: "=a"(_ret)                             \
		: "0"(_num)                              \
		: "rcx", "r11", "memory", "cc"           \
	);                                           \
	_ret;                                        \
})

#define my_syscall1(num, arg1)                          \
({                                                      \
	long _ret;                                          \
	register long _num  __asm__ ("rax") = (num);        \
	register long _arg1 __asm__ ("rdi") = (long)(arg1); \
                                                        \
	__asm__ volatile (                                  \
		"syscall\n"                                     \
		: "=a"(_ret)                                    \
		: "r"(_arg1),                                   \
		  "0"(_num)                                     \
		: "rcx", "r11", "memory", "cc"                  \
	);                                                  \
	_ret;                                               \
})

#define my_syscall2(num, arg1, arg2)                                          \
({                                                                            \
	long _ret;                                                            \
	register long _num  __asm__ ("rax") = (num);                          \
	register long _arg1 __asm__ ("rdi") = (long)(arg1);                   \
	register long _arg2 __asm__ ("rsi") = (long)(arg2);                   \
									      \
	__asm__ volatile (                                                    \
		"syscall\n"                                                   \
		: "=a"(_ret)                                                  \
		: "r"(_arg1), "r"(_arg2),                                     \
		  "0"(_num)                                                   \
		: "rcx", "r11", "memory", "cc"                                \
	);                                                                    \
	_ret;                                                                 \
})

#define my_syscall3(num, arg1, arg2, arg3)                                    \
({                                                                            \
	long _ret;                                                            \
	register long _num  __asm__ ("rax") = (num);                          \
	register long _arg1 __asm__ ("rdi") = (long)(arg1);                   \
	register long _arg2 __asm__ ("rsi") = (long)(arg2);                   \
	register long _arg3 __asm__ ("rdx") = (long)(arg3);                   \
									      \
	__asm__ volatile (                                                    \
		"syscall\n"                                                   \
		: "=a"(_ret)                                                  \
		: "r"(_arg1), "r"(_arg2), "r"(_arg3),                         \
		  "0"(_num)                                                   \
		: "rcx", "r11", "memory", "cc"                                \
	);                                                                    \
	_ret;                                                                 \
})

#define my_syscall4(num, arg1, arg2, arg3, arg4)                              \
({                                                                            \
	long _ret;                                                            \
	register long _num  __asm__ ("rax") = (num);                          \
	register long _arg1 __asm__ ("rdi") = (long)(arg1);                   \
	register long _arg2 __asm__ ("rsi") = (long)(arg2);                   \
	register long _arg3 __asm__ ("rdx") = (long)(arg3);                   \
	register long _arg4 __asm__ ("r10") = (long)(arg4);                   \
									      \
	__asm__ volatile (                                                    \
		"syscall\n"                                                   \
		: "=a"(_ret)                                                  \
		: "r"(_arg1), "r"(_arg2), "r"(_arg3), "r"(_arg4),             \
		  "0"(_num)                                                   \
		: "rcx", "r11", "memory", "cc"                                \
	);                                                                    \
	_ret;                                                                 \
})

#define my_syscall5(num, arg1, arg2, arg3, arg4, arg5)                        \
({                                                                            \
	long _ret;                                                            \
	register long _num  __asm__ ("rax") = (num);                          \
	register long _arg1 __asm__ ("rdi") = (long)(arg1);                   \
	register long _arg2 __asm__ ("rsi") = (long)(arg2);                   \
	register long _arg3 __asm__ ("rdx") = (long)(arg3);                   \
	register long _arg4 __asm__ ("r10") = (long)(arg4);                   \
	register long _arg5 __asm__ ("r8")  = (long)(arg5);                   \
									      \
	__asm__ volatile (                                                    \
		"syscall\n"                                                   \
		: "=a"(_ret)                                                  \
		: "r"(_arg1), "r"(_arg2), "r"(_arg3), "r"(_arg4), "r"(_arg5), \
		  "0"(_num)                                                   \
		: "rcx", "r11", "memory", "cc"                                \
	);                                                                    \
	_ret;                                                                 \
})

#define my_syscall6(num, arg1, arg2, arg3, arg4, arg5, arg6)                  \
({                                                                            \
	long _ret;                                                            \
	register long _num  __asm__ ("rax") = (num);                          \
	register long _arg1 __asm__ ("rdi") = (long)(arg1);                   \
	register long _arg2 __asm__ ("rsi") = (long)(arg2);                   \
	register long _arg3 __asm__ ("rdx") = (long)(arg3);                   \
	register long _arg4 __asm__ ("r10") = (long)(arg4);                   \
	register long _arg5 __asm__ ("r8")  = (long)(arg5);                   \
	register long _arg6 __asm__ ("r9")  = (long)(arg6);                   \
									      \
	__asm__ volatile (                                                    \
		"syscall\n"                                                   \
		: "=a"(_ret)                                                  \
		: "r"(_arg1), "r"(_arg2), "r"(_arg3), "r"(_arg4), "r"(_arg5), \
		  "r"(_arg6), "0"(_num)                                       \
		: "rcx", "r11", "memory", "cc"                                \
	);                                                                    \
	_ret;                                                                 \
})

#define __sysret(arg)							\
({									\
	__typeof__(arg) __sysret_arg = (arg);				\
	(__sysret_arg < 0)                              /* error ? */	\
		? (({ SET_ERRNO(-__sysret_arg); }), -1) /* ret -1 with errno = -arg */ \
		: __sysret_arg;                         /* return original value */ \
})

static __inline__ int __nolibc_enosys(const char *syscall, ...)
{
	(void)syscall;
	return -ENOSYS;
}

#define __syscall_narg(_0, _1, _2, _3, _4, _5, _6, N, ...) N
#define _syscall_narg(...) __syscall_narg(__VA_ARGS__, 6, 5, 4, 3, 2, 1, 0)
#define _syscall(N, ...)   __sysret(my_syscall##N(__VA_ARGS__))
#define _syscall_n(N, ...) _syscall(N, __VA_ARGS__)
#define syscall(...)       _syscall_n(_syscall_narg(__VA_ARGS__), ##__VA_ARGS__)


#endif
