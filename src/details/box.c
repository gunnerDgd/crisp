#include "box.h"

obj_trait __box_trait      = {
    .on_new   = &__box_new   ,
    .on_clone = &__box_clone ,
    .on_ref   = &__box_ref   ,
    .on_del   = &__box_del   ,
    .size     = sizeof(__box)
};

bool_t 
    __box_new
        (__box* par_box, u32_t par_count, va_list par) {
            u64_t  par_alloc_size = va_arg(par, u64_t);
            alloc *par_alloc      = (par_count == 2) ? va_arg(par, alloc*) : get_alloc();

            if (!par_alloc)
                return false_t;

                   par_box->mem  = mem_new(par_alloc, par_alloc_size);
            return par_box->mem != 0;
}

bool_t 
    __box_clone
        (__box* par, __box* par_clone)                 {
                   par->mem = mem_clone(par_clone->mem);
            return par->mem != 0;
}

bool_t 
    __box_ref
        (__box* par) {
            return true_t;
}

void   
    __box_del
        (__box* par)             {
            if(par->mem)         {
                mem_del(par->mem);
                par->mem = 0;
            }
}