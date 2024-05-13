#ifndef __THREAD_H__
#define __THREAD_H__

#include "thread/mtx.h"
#include "thread/thd.h"

extern obj_trait *thread_t;
struct thread { u8_t thread[2 KB]; };

#ifdef PRESET_COMPILER_GCC
extern __thread           struct thread thread;
#elif  PRESET_COMPILER_MSVC
extern __declspec(thread) struct thread thread;
#endif

u64_t this_thd_id();
thd*  this_thd   ();

#endif