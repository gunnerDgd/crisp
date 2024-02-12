#include "box.h"

obj_trait box_trait = make_trait (
    box_new    ,
    box_clone  ,
    box_ref    ,
    box_del    ,
    sizeof(box),
    null_t
);

obj_trait* box_t = &box_trait;

bool_t 
    box_new
        (box* par_box, u32_t par_count, va_list par)                    {
            u64_t size = 0; if (par_count > 0) size = va_arg(par, u64_t);
            mem  *res  = 0; if (par_count > 1) res  = va_arg(par, void*);
            if (!res)  res = get_mem();
            if (!res)  return false_t;
            if (!size) return false_t;

            par_box->mem  = mem_new(res, size);
            par_box->size = size;
            par_box->res  = res ;
            return par_box->mem != 0;
}

bool_t 
    box_clone
        (box* par, box* par_clone)             {
            if (!par_clone->mem) return false_t;
            if (!par_clone->res) return false_t;

            par->mem = mem_new(par->res, par->size); if (!par->mem) return false_t;
            par->size = par_clone->size;
            par->res  = par_clone->res ;

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