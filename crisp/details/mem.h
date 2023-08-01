#ifndef CRISP_DETAILS_MEM_H
#define CRISP_DETAILS_MEM_H

#include <crisp/type.h>
#include <crisp/type_atomic.h>

typedef struct
    mem_handle_t { struct alloc_t* alloc; c_u64_t size; c_u8_t* ptr; }
        mem_handle_t;

typedef struct mem_trait_t {
    c_u64_t (*copy)       (struct mem_t*, c_u64_t, struct mem_t*, c_u64_t);
    c_u64_t (*copy_from)  (struct mem_t*, c_u64_t, void*, c_u64_t)        ;
    c_u64_t (*copy_to)    (struct mem_t*, c_u64_t, void*, c_u64_t)        ;
    c_u64_t (*move)       (struct mem_t*, struct mem_t*)                  ;
    void*   (*get_pointer)(struct mem_t*)                                 ;
}   mem_trait_t;

typedef struct
    mem_t { mem_handle_t handle; mem_trait_t* handle_trait; }
        mem_t;

extern mem_trait_t mem_global_trait;

mem_t*
    mem_init
        (struct alloc_t*, c_u64_t);

mem_t*
    mem_init_as_clone
        (mem_t*);

c_bool_t
    mem_deinit
        (mem_t*);

c_u64_t
    mem_copy
        (mem_t*, c_u64_t, mem_t*, c_u64_t);

c_u64_t
    mem_copy_from
        (mem_t*, c_u64_t, void*, c_u64_t);

c_u64_t
    mem_copy_to
        (mem_t*, c_u64_t, void*, c_u64_t);

c_u64_t
    mem_move
        (mem_t*, mem_t*);

c_u8_t*
    mem_ptr
        (mem_t*);

#endif
