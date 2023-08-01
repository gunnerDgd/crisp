#ifndef CRISP_DETAILS_MEM_CSTD_H
#define CRISP_DETAILS_MEM_CSTD_H

#include <crisp/details/mem.h>

c_u64_t
    cstd_mem_copy
        (mem_t*, mem_t*);

c_u64_t
    cstd_mem_copy_with_offset
        (mem_t*, mem_t*);

c_u64_t
    cstd_mem_copy_from
        (mem_t*, void*, c_u64_t);

c_u64_t
    cstd_mem_copy_to
        (mem_t*, void*, c_u64_t);

c_u64_t
    cstd_mem_move
        (mem_t*, mem_t*);

void*
    cstd_mem_ptr
        (mem_t*);

#endif
