#include "box.h"

obj_trait box_trait      = {
    .on_new   = &box_new   ,
    .on_clone = &box_clone ,
    .on_ref   = &box_ref   ,
    .on_del   = &box_del   ,
    .size     = sizeof(box)
};

obj_trait* box_t = &box_trait;

bool_t 
    box_new
        (box* par_box, u32_t par_count, va_list par) {
            par_box->size    = va_arg(par, u64_t);
            par_box->mem_res = (par_count == 2) ? va_arg(par, mem_res*) : get_mem_res();

            if (!par_box->mem_res)                return false_t;
            if (par_count != 1 && par_count != 2) return false_t;

            par_box->mem  = mem_new(par_box->mem_res, par_box->size);
            return par_box->mem != 0;
}

bool_t 
    box_clone
        (box* par, box* par_clone)                 {
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
    box_ref
        (box* par)       {
            return true_t;
}

void   
    box_del
        (box* par)                  {
            if(!par->mem_res) return;
            if(!par->mem)     return;

            mem_del(par->mem_res, par->mem);
}

void*   
    box_ptr
        (box* par)                              {
            if (!par)                   return 0;
            if (trait_of(par) != box_t) return 0;

            return par->mem;
}

u64_t 
    box_size
        (box* par)                              {
            if (!par)                   return 0;
            if (trait_of(par) != box_t) return 0;

            return par->size;
}