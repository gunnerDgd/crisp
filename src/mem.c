#include "mem.h"
#include "details/mem.h"
#include "details/ptr.h"
mem
    mem_new
        (alloc* par, u64_t par_size) {
        if (!par)      par = get_alloc();
        if (!par)      return 0;
        if (!par_size) return 0;

        __mem*  ret = __mem_new(par, par_size);
        if    (!ret)                             return 0;
        if    (!ret->trait) { __mem_del(ret); return 0; }

        return ret;
}

mem
    mem_clone
        (mem par)                  {
            if (!par)      return 0;
            return __mem_clone(par);
}

void
    mem_del
        (mem par)         {
            __mem_del(par);
}

u64_t 
    mem_size(mem par)    {
        if(!par) return 0;
        return ((__mem*)par)->size; 
}

ptr   
    mem_ptr 
        (mem par, u64_t par_cur) {
            if (par_cur >= mem_size(par))
                return ptr_null();

            ptr    ret                   ;
            __ptr* ret_ptr      = &ret   ;
                   ret_ptr->cur = par_cur;
                   ret_ptr->mem = par    ;
            return ret;
}

void*
    mem_ptr_raw
        (mem par)                    {
            if(!par)         return 0;
            return ((__mem*)par)->ptr;
}