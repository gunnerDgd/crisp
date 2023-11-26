#include "box.h"
#include "details/box.h"

obj_trait* box_t = &__box_trait;

void*   
    box_ptr
        (box* par)                              {
            if (!par)                   return 0;
            if (trait_of(par) != box_t) return 0;

            return ((__box*)par)->mem;
}

u64_t 
    box_size
        (box* par)                              {
            if (!par)                   return 0;
            if (trait_of(par) != box_t) return 0;

            return ((__box*)par)->size;
}