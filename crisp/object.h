#ifndef CRISP_OBJECT_H
#define CRISP_OBJECT_H

#include <crisp/type_atomic.h>
#include <crisp/type.h>

#include <crisp/alloc.h>
#include <crisp/mem.h>

#define c_object_type(name, element)     \
    typedef struct name {                \
        struct { c_u64_t __head__[3]; }; \
        element                          \
    }   name;

c_handle_t(c_object_t)

c_object_t
    c_object_init
        (c_alloc_t*, c_u64_t);

c_object_t
    c_object_init_as_clone
        (c_object_t);

c_object_t
    c_object_init_as_ref
        (c_object_t);

c_bool_t
    c_object_deinit
        (c_object_t);

void*
    c_object_ptr
        (c_object_t);
#endif
