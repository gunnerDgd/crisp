#include "mem.h"
#include "alloc.h"

__mem* 
    __mem_new
        (__alloc* par, u64_t par_size)                  {
            return par->trait->on_mem_new(par, par_size); 
}

__mem*
    __mem_clone
        (__mem* par)                       {
            __alloc *ret_alloc = par->alloc;
            
            if (!ret_alloc)        return 0;
            if (!ret_alloc->trait) return 0;

            __mem   *ret = ret_alloc->trait->on_mem_clone(ret_alloc, par);
            return   ret;
}

void
    __mem_del
        (__mem *par)                 {
            __alloc *ret = par->alloc;
                     ret->trait->on_mem_del(ret, par);
}