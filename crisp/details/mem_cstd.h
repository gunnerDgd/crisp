#ifndef __DETAILS_MEM_CSTD_H__
#define __DETAILS_MEM_CSTD_H__

#include "mem.h"

extern __mem_trait cstd_mem_trait;

u64_t
    cstd_mem_copy_from
        (__mem*, void*, u64_t);

u64_t
    cstd_mem_copy_to
        (__mem*, void*, u64_t);

u64_t
    cstd_mem_move
        (__mem*, __mem*);

void*
    cstd_mem_ptr
        (__mem*);

#endif
