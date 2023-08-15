#ifndef CRISP_OBJECT_H
#define CRISP_OBJECT_H

#include <crisp/type_atomic.h>
#include <crisp/type.h>

#include <crisp/alloc.h>
#include <crisp/mem.h>

typedef struct
	c_object_t { c_u64_t handle[4]; }
		c_object_t;

typedef struct c_object_trait_t {
    c_bool_t (*init)		 (c_object_t, void*);
    c_bool_t (*init_as_clone)(c_object_t, c_object_t*);
    c_bool_t (*init_as_ref)  (c_object_t);
    c_bool_t (*deinit)       (c_object_t);
}   c_object_trait_t;

c_object_t*
    c_object_init
        (c_alloc_t*, c_u64_t, c_object_trait_t*, void*);

c_object_t*
    c_object_init_as_clone
        (c_object_t*);

c_object_t*
    c_object_init_as_ref
        (c_object_t*);

c_bool_t
    c_object_deinit
        (c_object_t*);

void*
    c_object_ptr
        (c_object_t*);
#endif
