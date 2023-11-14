#include "coro.h"
#include "details/coro.h"

obj_trait* coro_t = &__coro_trait;

void*  
    coro_yield
        (coro* par, void* par_arg) { 
            if (!par)                    return false_t;
            if (trait_of(par) != coro_t) return false_t;

            return __coro_yield(par, par_arg); 
}