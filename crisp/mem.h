#ifndef CRISP_MEM_H
#define CRISP_MEM_H

#include <crisp/type.h>
#include <crisp/type_atomic.h>

#include <crisp/alloc.h>

c_handle_t(c_mem_t)

c_mem_t
    c_mem_init
        (c_alloc_t*, c_u64_t);

c_mem_t
    c_mem_init_as_clone
        (c_mem_t);

c_bool_t
    c_mem_deinit
        (c_mem_t);

c_u64_t
    c_mem_copy
        (c_mem_t, c_u64_t, c_mem_t, c_u64_t);

c_u64_t
    c_mem_copy_from
        (c_mem_t, c_u64_t, void*, c_u64_t);

c_u64_t
    c_mem_copy_to
        (c_mem_t, c_u64_t, void*, c_u64_t);

c_u64_t
    c_mem_move
        (c_mem_t, c_mem_t);

c_u64_t
    c_mem_size
        (c_mem_t);

void*
    c_mem_ptr
        (c_mem_t);

#endif
