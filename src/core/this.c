#include "this.h"

#ifdef CRISP_TLS
#ifdef PRESET_COMPILER_GCC
__thread struct this this;
#endif

#ifdef PRESET_COMPILER_MSVC
__declspec(thread) struct this this;
#endif
#endif

static bool_t
    do_new
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

static bool_t do_clone(struct this* self, struct this* clone) { return false_t; }
static bool_t do_ref  (struct this* self)                     { return false_t; }
static void   do_del  (struct this* self)                     {}

static obj_trait
    do_obj = make_trait    (
        do_new             ,
        do_clone           ,
        do_ref             ,
        do_del             ,
        sizeof(struct this),
        null_t
);

obj_trait *this_t = &do_obj;