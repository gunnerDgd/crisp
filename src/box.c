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
            u64_t size = 0;
            mem  *res  = 0;

            switch (par_count)                                                    {
                case 1 : size = va_arg(par, u64_t); res = get_mem()        ; break;
                case 2 : size = va_arg(par, u64_t); res = va_arg(par, mem*); break;
                default: return false_t;
            }

            if (!size) return false_t;
            if (!res)  return false_t;

            par_box->size = size              ;
            par_box->res  = res               ;
            par_box->mem  = mem_new(res, size);

            return par_box->mem != 0;
}

bool_t 
    box_clone
        (box* par, box* par_clone)             {
            if (!par_clone->mem) return false_t;
            if (!par_clone->res) return false_t;

            par->size = par_clone->size             ;
            par->res  = par_clone->res              ;
            par->mem  = mem_new(par->res, par->size); if (!par->mem) return false_t;

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
        (box* par)              {
            if(!par->res) return;
            if(!par->mem) return;

            mem_del(par->res, par->mem);
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