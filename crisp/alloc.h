#ifndef CRISP_ALLOC_H
#define CRISP_ALLOC_H

#include <crisp/type.h>
#include <crisp/type_atomic.h>

typedef struct
    c_alloc_t { c_u8_t handle[256]; }
        c_alloc_t;

c_alloc_t*
	c_global_alloc
		();

c_bool_t
    c_alloc_init
        (c_alloc_t*);

c_bool_t
    c_alloc_init_as_clone
        (c_alloc_t*, c_alloc_t*);

c_bool_t
    c_alloc_deinit
        (c_alloc_t*);

#endif
