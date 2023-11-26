#include "mem.h"
#include "details/mem.h"

mem_res* global_mem_res;

mem_res* 
    get_mem_res()            {
        return global_mem_res;
}

mem_res* 
    set_mem_res
        (mem_res* par)                                         {
            mem_res* ret = global_mem_res; global_mem_res = par;
            return   ret;
}

bool_t 
    mem_res_new
        (mem_res* par_res, mem_res_trait* par_trait, u32_t par_count, ...) {
            if (!par_res)               return false_t;
            if (!par_trait)             return false_t;

            if (!par_trait->on_new)     return false_t;
            if (!par_trait->on_del)     return false_t;
            if (!par_trait->on_mem_new) return false_t;
            if (!par_trait->on_mem_del) return false_t;

            va_list  par;
            va_start(par, par_count); bool_t ret = __mem_res_new(par_res, par_trait, par_count, par);
            va_end  (par);
            return   ret;
}

void  
    mem_res_del
        (mem_res* par)        {
            __mem_res_del(par); 
}

void* 
    mem_new    
        (mem_res* par, u64_t par_size)    {
            if (!par) par = global_mem_res;
            if (!par) return 0;

            return __mem_new(par, par_size); 
}

void  
    mem_del
        (mem_res* par, void* par_del)  {
            if (!par) par = global_mem_res;
            if (!par) return;

            __mem_del(par, par_del);
}

void
    mem_set
        (void* par, u8_t par_set, u64_t par_size) {
            if (!par_size) return;
            while(par_size--)
                ((u8_t*)par)[par_size] = par_set;
}

void
    mem_copy
        (void* par, void* par_src, u64_t par_size) {
            if(!par_size) return;
            if(!par)      return;
            if(!par_src)  return;

            u8_t* dst = par, * src = par_src;
            while(par_size--)
                *dst++ = *src++;
}

void
    mem_move
        (void* par, void* par_src, u64_t par_size) {
            if (!par_size) return;
            if (!par)      return;
            if (!par_src)  return;

            u8_t* dst = par, * src = par_src;
            for(u8_t i = 0 ; i < par_size ; ++i) {
                dst[i] = src[i];
                src[i] =      0;
            }
}

u64_t  
    mem_find
        (void* par, void* par_cmp, u64_t par_len, u64_t par_cmp_len) {
            if (!par)                  return -1;
            if (!par_cmp)              return -1;
            if (!par_len)              return -1;
            if (!par_cmp_len)          return -1;
            if (par_len < par_cmp_len) return -1;

            u8_t *src = par, *src_cmp = par_cmp;
            for(u8_t i = 0 ; i <= (par_len - par_cmp_len) ; ++i)
                if (mem_eq(src + i, src_cmp, par_cmp_len))
                    return i;

            return -1;
}

bool_t 
    mem_eq
        (void* par, void* par_cmp, u64_t par_size) {
            if (!par)      return false_t;
            if (!par_cmp)  return false_t;
            if (!par_size) return false_t;

            for (u64_t i = 0 ; i < par_size ; ++i)
                if (((u8_t*)par)[i] != ((u8_t*)par_cmp)[i])
                    return false_t;

            return true_t;
}

bool_t 
    mem_gt
        (void* par, void* par_cmp, u64_t par_size) {
            if (!par)      return false_t;
            if (!par_cmp)  return false_t;
            if (!par_size) return false_t;

            for (u64_t i = 0 ; i < par_size ; ++i)
                if (((u8_t*)par)[i] < ((u8_t*)par_cmp)[i])
                    return false_t;

            return ((u8_t*)par)[par_size - 1] > ((u8_t*)par_cmp)[par_size - 1];
}

bool_t 
    mem_lt
        (void* par, void* par_cmp, u64_t par_size) {
            if (!par)      return false_t;
            if (!par_cmp)  return false_t;
            if (!par_size) return false_t;

            for (u64_t i = 0 ; i < par_size ; ++i)
                if (((u8_t*)par)[i] != ((u8_t*)par_cmp)[i])
                    return false_t;

            return true_t;
}