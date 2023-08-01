#ifndef CRISP_DETAILS_OBJECT_H
#define CRISP_DETAILS_OBJECT_H

#include <crisp/type.h>
#include <crisp/type_atomic.h>

#include <crisp/details/mem.h>
#include <crisp/details/alloc.h>

typedef struct object_trait_t {
    void (*init_as_clone)(void*, void*);
    void (*init_as_ref)  (void*);
    void (*deinit)       (void*);
}   object_trait_t;

typedef struct object_t {
    mem_t          *mem  ;
    alloc_t        *alloc;
    c_atomic_u64_t  ref  ;
    object_trait_t *trait;
}   object_t;

object_t*
    object_init
        (alloc_t*, object_trait_t*, c_u64_t);

object_t*
    object_init_as_clone
        (object_t*);

object_t*
    object_init_as_ref
        (object_t*);

c_bool_t
    object_deinit
        (object_t*);

#endif
