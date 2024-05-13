#ifndef __THREAD_H__
#define __THREAD_H__

#include "thread/mtx.h"
#include "thread/thd.h"

extern obj_trait *thread_t;
struct thread { u8_t thread[2 KB]; };

#ifdef PRESET_COMPILER_MSVC
#define thd_local __declspec(thread)
#elif  PRESET_COMPILER_GCC
#define thd_local __thread
#endif

extern thd_local struct thread thread;

u64_t this_thd_id();
thd*  this_thd   ();

#endif