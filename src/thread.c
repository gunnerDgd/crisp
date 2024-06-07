#include "thread.h"


#ifdef PRESET_LINUX
#include <sys/syscall.h>
#include <unistd.h>
#elif  PRESET_WIN32
#include <Windows.h>
#endif

thd_local struct thread thread;

obj_trait thread_trait = make_trait (
    thread_new           ,
    thread_clone         ,
    thread_ref           ,
    thread_del           ,
    sizeof(struct thread),
    null_t
);

obj_trait *thread_t = &thread_trait;

bool_t
    thread_new
        (struct thread* self, u32_t count, va_list arg) {
#ifdef PRESET_LINUX
#ifdef SYS_gettid
            self->uid = syscall(SYS_gettid);
            return true_t;
#endif
#endif

#ifdef PRESET_WIN32
            self->uid = GetCurrentThreadId();
            return true_t;
#endif
            return false_t;
}

bool_t thread_clone(struct thread* self, struct thread* clone) { return false_t; }
bool_t thread_ref  (struct thread* self)                       { return false_t; }
void   thread_del  (struct thread* self)                       {  }

u64_t  this_thd_id() { return thread.uid ; }
thd*   this_thd   () { return thread.this; }