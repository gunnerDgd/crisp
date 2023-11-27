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
            par_box->size    = va_arg(par, u64_t);
            par_box->mem_res = (par_count == 2) ? va_arg(par, mem_res*) : get_mem_res();

            if (!par_box->mem_res)
                return false_t;

                   par_box->mem  = mem_new(par_box->mem_res, par_box->size);
            return par_box->mem != 0;
}

bool_t 
    __box_clone
        (__box* par, __box* par_clone)             {
            if (!par_clone->mem)     return false_t;
            if (!par_clone->mem_res) return false_t;

            par->size    = par_clone->size                 ;
            par->mem_res = par_clone->mem_res              ;
            par->mem     = mem_new(par->mem_res, par->size);
            if (!par->mem)
                return false_t;

            mem_copy(par->mem, par_clone->mem, par->size);
            return true_t;
}

bool_t 
    __box_ref
        (__box* par) {
            return true_t;
}

void   
    __box_del
        (__box* par)                {
            if(!par->mem_res) return;
            if(!par->mem)     return;

            mem_del(par->mem_res, par->mem);
}