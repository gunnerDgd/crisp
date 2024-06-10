#include <core.h>

int run   ();
int do_run()                                     {
    if (!make_at(&core, core) from (0)) return -1;
    if (!mod_new())                     return -2;
    bool_t res = obj_new_at                      (
        &this ,
        this_t,
        2     ,
        run   ,
        null_t
    );

    if (!res) return -3;
    u64_t ret = (u64_t) this.ret;
    del(&this);
    mod_del ();

    return ret;
}