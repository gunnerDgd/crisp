#ifndef __THREAD_H__
#define __THREAD_H__

#include "thread/mtx.h"
#include "thread/thd.h"

extern obj_trait *thread_t;
struct            thread  {
    obj   head;
    thd  *this;
    u64_t uid;
};

bool_t thread_new  (struct thread*, u32_t, va_list);
bool_t thread_clone(struct thread*, struct thread*);
bool_t thread_ref  (struct thread*);
void   thread_del  (struct thread*);

#ifdef PRESET_COMPILER_GCC
extern __thread           struct thread thread;
#elif  PRESET_COMPILER_MSVC
extern __declspec(thread) struct thread thread;
#endif

u64_t this_thd_id();
thd*  this_thd   ();

#endif