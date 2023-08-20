#ifndef CRISP_OBJECT_H
#define CRISP_OBJECT_H

#include <crisp/type_atomic.h>
#include <crisp/type.h>

#include <crisp/alloc.h>
#include <crisp/mem.h>

typedef void*  c_obj_t;
typedef struct c_obj_trait_t {
    c_bool_t (*init)		 (void*, void*);
    c_bool_t (*init_as_clone)(void*, void*);
    c_bool_t (*init_as_ref)  (void*);
    c_bool_t (*deinit)       (void*);
}   c_obj_trait_t;

c_obj_t
    c_obj_init
        (c_alloc_t*, c_u64_t, c_obj_trait_t*, void*);

c_obj_t
    c_obj_init_as_clone
        (c_obj_t);

c_obj_t
    c_obj_init_as_ref
        (c_obj_t);

c_bool_t
    c_obj_deinit
        (c_obj_t);

void*
	c_obj_ptr
		(c_obj_t);

#endif
