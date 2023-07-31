#ifndef CRISP_DETAILS_ALLOC_CSTD_H
#define CRISP_DETAILS_ALLOC_CSTD_H

#include <crisp/details/alloc.h>

c_bool_t
    cstd_alloc_init
        (alloc_t*);

c_bool_t
    cstd_alloc_init_as_clone
        (alloc_t*, alloc_t*);

c_bool_t
    cstd_alloc_deinit
        (alloc_t*);

struct mem_t*
    cstd_mem_init
        (alloc_t*, c_u64_t);

struct mem_t*
    cstd_mem_init_as_clone
        (alloc_t*, struct mem_t*);

c_bool_t
    cstd_mem_deinit
        (alloc_t*, struct mem_t*);

#endif
