#include "this.h"

#ifdef PRESET_FEATURE_THREAD
#ifdef PRESET_COMPILER_GCC
__thread struct this this;
#endif

#ifdef PRESET_COMPILER_MSVC
__declspec(thread) struct this this;
#endif

#else
struct this this;
#endif

obj_trait this_trait = make_trait (
    this_new           ,
    this_clone         ,
    this_ref           ,
    this_del           ,
    sizeof(struct this),
    null_t
);

obj_trait *this_t = &this_trait;

bool_t
    this_new
        (struct this* self, u32_t count, va_list par)                  {
            any_t run = null_t; if (count > 0) run = va_arg(par, any_t);
            any_t arg = null_t; if (count > 1) arg = va_arg(par, any_t);
            if (!run) return false_t;

            self->task = null_t;
            self->run  = run;
            self->arg  = arg;

            self->ret = self->run (self->arg);
            return true_t;
}

bool_t this_clone(struct this* self, struct this* clone) { return false_t; }
bool_t this_ref  (struct this* self)                     { return false_t; }
void   this_del  (struct this* self)                     {}