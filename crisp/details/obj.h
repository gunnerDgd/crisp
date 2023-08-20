#ifndef CRISP_DETAILS_OBJECT_H
#define CRISP_DETAILS_OBJECT_H

#include <crisp/type.h>
#include <crisp/type_atomic.h>

#include <crisp/details/mem.h>
#include <crisp/details/alloc.h>

typedef struct obj_trait_t {
	c_bool_t (*init)		 (void*, void*);
    c_bool_t (*init_as_clone)(void*, void*);
    c_bool_t (*init_as_ref)  (void*);
    c_bool_t (*deinit)       (void*);
}   obj_trait_t;

typedef struct obj_t {
    mem_t          *alloc_mem;
    alloc_t        *alloc	 ;
    c_atomic_u64_t  ref  	 ;
    obj_trait_t    *trait	 ;
}   obj_t;

obj_t*
    obj_init
        (alloc_t*, c_u64_t, obj_trait_t*, void*);

obj_t*
    obj_init_as_clone
        (obj_t*);

obj_t*
    obj_init_as_ref
        (obj_t*);

c_bool_t
    obj_deinit
        (obj_t*);

#endif
