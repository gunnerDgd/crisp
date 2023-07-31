#ifndef CRISP_LIST_H
#define CRISP_LIST_H

#include <crisp/alloc.h>
#include <crisp/object.h>

typedef struct
    c_list_t { c_u64_t handle[11];}
        c_list_t;

c_handle_t(c_list_elem_t)

c_bool_t
    c_list_init
        (c_list_t*, c_alloc_t*);

c_bool_t
    c_list_init_as_clone
        (c_list_t*, c_list_t*);

c_bool_t
    c_list_deinit
        (c_list_t*);

c_list_elem_t
    c_list_push_back
        (c_list_t*, c_object_t);

c_list_elem_t
    c_list_push_front
        (c_list_t*, c_object_t);

c_list_elem_t
    c_list_push_at
        (c_list_t*, c_object_t, c_list_elem_t);

c_object_t
    c_list_pop_front
        (c_list_t*);

c_object_t
    c_list_pop_back
        (c_list_t*);

c_object_t
    c_list_pop_at
        (c_list_t*, c_list_elem_t);

c_list_elem_t
    c_list_elem_next
        (c_list_elem_t);

c_list_elem_t
    c_list_elem_prev
        (c_list_elem_t);

c_object_t
    c_list_elem_object
        (c_list_elem_t);

#endif
