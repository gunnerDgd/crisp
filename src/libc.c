#include "libc.h"

obj_trait libc_trait = make_trait (
    libc_new           ,
    libc_clone         ,
    libc_ref           ,
    libc_del           ,
    sizeof(struct libc),
    null_t
);

obj_trait  *libc_t = &libc_trait;
struct libc libc;

bool_t
    libc_new
        (struct libc* par_libc, u32_t par_count, va_list par)                  {
            if (trait_of(&core) != core_t)                       return false_t;
            if (!make_at(&libc_mem, mem) from (1, &libc_mem_do)) return false_t;
            core.mem = &libc_mem;
            return true_t;
}

bool_t libc_clone(struct libc* par, struct libc* par_clone) { return false_t; }
bool_t libc_ref  (struct libc* par)                         { return false_t; }

void
    libc_del
        (struct libc* par)   {
            core.mem = null_t;
            del (&libc_mem);
}