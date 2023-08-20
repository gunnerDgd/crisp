#ifndef CRISP_LIST_H
#define CRISP_LIST_H

#include <crisp/alloc.h>
#include <crisp/obj.h>

typedef struct
    c_list_t { c_u64_t handle[11];}
        c_list_t;

typedef void* c_list_iter_t;

c_bool_t
    c_list_init
        (c_list_t*, c_alloc_t*);

c_bool_t
    c_list_init_as_clone
        (c_list_t*, c_list_t*);

c_bool_t
    c_list_deinit
        (c_list_t*);

c_list_iter_t
    c_list_push_back
        (c_list_t*, c_obj_t);

c_list_iter_t
    c_list_push_front
        (c_list_t*, c_obj_t);

c_list_iter_t
    c_list_push_at
        (c_list_t*, c_obj_t, c_list_iter_t);

c_obj_t
    c_list_pop_front
        (c_list_t*);

c_obj_t
    c_list_pop_back
        (c_list_t*);

c_obj_t
    c_list_pop_at
        (c_list_t*, c_list_iter_t);

c_list_iter_t
	c_list_iter_begin
		(c_list_t*);

c_list_iter_t
	c_list_iter_end
		(c_list_t*);

c_list_iter_t
    c_list_iter_next
        (c_list_iter_t);

c_list_iter_t
    c_list_iter_prev
        (c_list_iter_t);

c_obj_t*
    c_list_iter_object
        (c_list_iter_t);

#endif
