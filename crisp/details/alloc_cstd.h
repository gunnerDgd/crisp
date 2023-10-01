#ifndef __DETAILS_ALLOC_CSTD_H__
#define __DETAILS_ALLOC_CSTD_H__

#include "mem.h"
#include "alloc.h"

extern __alloc_trait cstd_alloc_trait;

bool_t
    cstd_alloc_init
        (__alloc*);

bool_t
    cstd_alloc_init_as_clone
        (__alloc*, __alloc*);

void
    cstd_alloc_deinit
        (__alloc*);

__mem*
    cstd_mem_init
        (__alloc*, u64_t);

__mem*
    cstd_mem_init_as_clone
        (__alloc*, __mem*);

bool_t
    cstd_mem_deinit
        (__alloc*, __mem*);

#endif
