#include "box.h"
#include "details/box.h"

obj_trait* box_t = &__box_trait;

ptr   
    box_ptr
        (box* par, u64_t par_off)                        {
            if (!par)                   return ptr_null();
            if (trait_of(par) != box_t) return ptr_null();

            return mem_ptr (((__box*)par)->mem, par_off);
}

u64_t 
    box_size
        (box* par) {
            if (!par)                   return 0;
            if (trait_of(par) != box_t) return 0;

            return mem_size(((__box*)par)->mem);
}