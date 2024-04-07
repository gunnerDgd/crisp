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

obj_trait core_trait = make_trait (
    core_new           ,
    core_clone         ,
    core_ref           ,
    core_del           ,
    sizeof(struct core),
    null_t
);

obj_trait  *core_t = &core_trait;
struct core core;

bool_t
    core_new
        (struct core* par_core, u32_t par_count, va_list par)             {
            mem* mem = null_t; if (par_count > 0) mem = va_arg(par, void*);
            par_core->mem = mem;
            return true_t;
}

bool_t core_clone(struct core* par, struct core* par_clone) { return false_t; }
bool_t core_ref  (struct core* par)                         { return false_t; }
void   core_del  (struct core* par)                         {                 }