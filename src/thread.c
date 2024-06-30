#include "thread.h"


#ifdef PRESET_LINUX
#include <sys/syscall.h>
#include <unistd.h>
#elif  PRESET_WIN32
#include <Windows.h>
#endif

thd_local struct thread thread;

static bool_t
    do_new
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

static bool_t do_clone(struct thread* self, struct thread* clone) { return false_t; }
static bool_t do_ref  (struct thread* self)                       { return false_t; }
static void   do_del  (struct thread* self)                       {  }

static obj_trait
    do_obj = make_trait      (
        do_new               ,
        do_clone             ,
        do_ref               ,
        do_del               ,
        sizeof(struct thread),
        null_t
);

obj_trait *thread_t = &do_obj;

u64_t  this_thd_id() { return thread.uid ; }
thd*   this_thd   () { return thread.this; }