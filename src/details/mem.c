#include "mem.h"

bool_t 
    __mem_res_new
        (__mem_res* par_res, __mem_res_trait* par_trait, u32_t par_count, va_list par) {
                   par_res->trait = par_trait;
            return par_res->trait->on_new    (
                   par_res   ,
                   par_count, 
                   par
            );
}

void  
    __mem_res_del
        (__mem_res* par)                   { 
            if (!par->trait)         return;
            if (!par->trait->on_del) return;

            par->trait->on_del(par);
}

void*
    __mem_new
        (__mem_res* par, u64_t par_size)         {
            if (!par->trait)             return 0;
            if (!par->trait->on_mem_new) return 0;
            
            return par->trait->on_mem_new(par, par_size);
}

void
    __mem_del
        (__mem_res* par, void* par_del)        {
            if (!par->trait)             return;
            if (!par->trait->on_mem_del) return;
            
            par->trait->on_mem_del(par, par_del);
}