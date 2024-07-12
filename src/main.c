#include "core.h"

int run   ();

int do_run(mem* mem, int(*func)(any_t), any_t arg)    {
    if (!make_at(&core, core) from (1, mem)) return -1;
    if (!mod_new())                          return -2;

    if (!func) func = run;
    bool_t res = obj_new_at (
        &this ,
        this_t,
        2     ,
        func  ,
        arg
    );

    if (!res) return -3;
    u64_t ret = (u64_t) this.ret;
    del(&this);
    mod_del ();

    return ret;
}