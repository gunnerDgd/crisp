#include "mem.h"
#include <stdlib.h>

any_t   libc_mem_do_new(mem*  par)                               { return &libc_mem_do; }
void    libc_mem_do_del(any_t par)                               {  }
void*   libc_mem_do_acq(any_t par, void* par_acq, u64_t par_len) { return malloc(par_len); }
void    libc_mem_do_rel(any_t par, void* par_rel, u64_t par_len) { free(par_rel); }

mem     libc_mem;
mem_ops libc_mem_do = make_mem_ops (
        libc_mem_do_acq,
        libc_mem_do_rel,
        libc_mem_do_new,
        libc_mem_do_del
);