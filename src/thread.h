#ifndef THREAD_H
#define THREAD_H

#include "thread/mtx.h"
#include "thread/thd.h"

extern obj_trait *thread_t;
struct            thread  {
    obj   head;
    thd  *this;
    u64_t uid;
};

#ifdef PRESET_COMPILER_MSVC
#define thd_local __declspec(thread)
#elif  PRESET_COMPILER_GCC
#define thd_local __thread
#endif

#ifdef PRESET_COMPILER_GCC
extern __thread           struct thread thread;
#elif  PRESET_COMPILER_MSVC
extern __declspec(thread) struct thread thread;
#endif

u64_t this_thd_id();
thd*  this_thd   ();

#endif