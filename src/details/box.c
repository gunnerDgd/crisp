#include "box.h"

__obj_trait __box_trait                = {
    .init          = &__box_init         ,
    .init_as_clone = &__box_init_as_clone,
    .init_as_ref   = &__box_init_as_ref  ,
    .deinit        = &__box_deinit       ,
    .size          = &__box_size         ,
    .name          = 0
};

bool_t 
    __box_init
        (__box* par_box, u32_t par_count, va_list par) {
            u64_t    alloc_size = va_arg(par, u64_t);
            __alloc *alloc      = (par_count == 2) ? va_arg(par, __alloc*) : global_alloc;
            if (!alloc)
                return false_t;

                   par_box->mem  = __mem_init(alloc, alloc_size);
            return par_box->mem != 0;
}

bool_t 
    __box_init_as_clone
        (__box* par, __box* par_clone) {
                   par->mem = __mem_init_as_clone(par_clone->mem);
            return par->mem != 0;
}

bool_t 
    __box_init_as_ref
        (__box* par) {
            return true_t;
}

void   
    __box_deinit
        (__box* par)                  {
            if(par->mem)              {
                __mem_deinit(par->mem);
                par->mem = 0;
            }
}

u64_t
    __box_size()            {
        return sizeof(__box);
}