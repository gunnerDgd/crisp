#include "box.h"

obj_trait box_trait = make_trait (
    box_new    ,
    box_clone  ,
    null_t     ,
    box_del    ,
    sizeof(box),
    null_t
);

obj_trait* box_t = &box_trait;

bool_t 
    box_new
        (box* par_box, u32_t par_count, va_list par)                  {
            u64_t len = 0; if (par_count > 0) len = va_arg(par, u64_t);
            mem  *mem = 0; if (par_count > 1) mem = va_arg(par, void*);
            if (trait_of(mem) != mem_t) mem = get_mem();
            if (trait_of(mem) != mem_t) return false_t;
            if (!len) return false_t;

            par_box->ptr = mem_acq(mem, null_t, len);
            par_box->len = len;
            par_box->mem = mem;
            return par_box->ptr != 0;
}

bool_t 
    box_clone
        (box* par, box* par_clone)                                         {
            if (!par_clone->mem) return false_t; mem  *mem = par_clone->mem;
            if (!par_clone->ptr) return false_t; void *ptr = par_clone->ptr;
            if (!par_clone->len) return false_t; u64_t len = par_clone->len;

            par->ptr = mem_acq(mem, null_t, len); if (!par->ptr) return false_t;
            par->len = par_clone->len;
            par->mem = par_clone->mem;

            mem_copy(par->ptr, par_clone->ptr, len);
            return true_t;
}

void   
    box_del
        (box* par)                        {
            mem_rel(par->mem, par->ptr, 0);
}

void*
    box_ptr
        (box* par)                                   {
            if (trait_of(par) != box_t) return null_t;
            return par->ptr;
}

u64_t 
    box_size
        (box* par)                              {
            if (trait_of(par) != box_t) return 0;
            return par->len;
}