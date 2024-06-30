#include "core.h"

mem*
    get_mem()          {
        return core.mem;
}

mem*
    set_mem
        (mem* par)                               {
            mem*   ret = core.mem; core.mem = par;
            return ret;
}

struct core core;

static bool_t
    do_new
        (struct core* self, u32_t count, va_list arg)                  {
            mem*  mem = null_t; if (count > 0) mem = va_arg(arg, any_t);
            self->mem = mem;
            return true_t;
}

static bool_t do_clone(struct core* par, struct core* par_clone) { return false_t; }
static bool_t do_ref  (struct core* par)                         { return true_t ; }
static void   do_del  (struct core* par)                         {                 }

static obj_trait
    do_obj = make_trait    (
        do_new             ,
        do_clone           ,
        do_ref             ,
        do_del             ,
        sizeof(struct core),
        null_t
);

obj_trait  *core_t = &do_obj;