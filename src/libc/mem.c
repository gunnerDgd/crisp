#include "mem.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

any_t   libc_mem_do_new(u32_t par_count, va_list par) { return &libc_mem_do; }
void    libc_mem_do_del(any_t par)                    {  }

void*   
    libc_mem_do_acq
        (any_t par, void* par_acq, u64_t par_len) {
            if (par != &libc_mem_do) return null_t;
            if (!par_len)            return null_t;

            void   *ret = malloc(par_len); if  (!ret) return null_t;
            mem_set(ret, 0x00, par_len);
            return  ret;
}

void    
    libc_mem_do_rel
        (any_t par, void* par_rel, u64_t par_len) {
            if (par != &libc_mem_do) return;
            if (!par_rel)            return;
            free(par_rel); 
}

mem     libc_mem;
mem_ops libc_mem_do = make_mem_ops (
        libc_mem_do_acq,
        libc_mem_do_rel,
        libc_mem_do_new,
        libc_mem_do_del
);