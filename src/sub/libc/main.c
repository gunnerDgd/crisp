#include "../../core.h"

extern mem_ops libc_mem_do;
extern mem     libc_mem;

int run  ();
int main (int argc, char** argv)                 {
    if (!make_at(&core, core) from (0)) return -1;
    if (!mod_new())                     return -2;
    set_mem(&libc_mem);

    if (!make_at(&libc_mem, mem) from (1, &libc_mem_do)) return -3;
    bool_t res = obj_new_at           (
        &this ,
        this_t,
        2     ,
        run   ,
        null_t
    );

    if (!res) return false_t;
    u64_t ret = (u64_t) this.ret;
    mod_del ();
    del(&this);
    return ret;
}