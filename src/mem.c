#include "mem.h"

mem* global_mem;

mem* 
    get_mem()            {
        return global_mem;
}

mem* 
    set_mem
        (mem* par)                                 {
            mem* ret = global_mem; global_mem = par;
            return   ret;
}

void* 
    mem_new    
        (mem* par, u64_t par_size)            {
            if (!par)         par = global_mem;
            if (!par)         return 0;
            if (!par->on_new) return 0;

            return par->on_new(par, par_size);
}

void  
    mem_del
        (mem* par, void* par_del)             {
            if (!par)         par = global_mem;
            if (!par)         return;
            if (!par->on_del) return;

            par->on_del(par, par_del);
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