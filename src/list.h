#ifndef __LIST_H__
#define __LIST_H__

#include "alloc.h"
#include "obj.h"

typedef struct
    list { u64_t handle[11];}
        list;

typedef void* list_iter;

bool_t
    list_init
        (list*, alloc*);

bool_t
    list_init_as_clone
        (list*, list*);

bool_t
    list_deinit
        (list*);

list_iter
    list_push_back
        (list*, obj*);

list_iter
    list_push_front
        (list*, obj*);

list_iter
    list_push_at
        (list*, obj*, list_iter);

obj*
    list_pop_front
        (list*);

obj*
    list_pop_back
        (list*);

obj*
    list_pop_at
        (list*, list_iter);

list_iter
	list_iter_begin
		(list*);

list_iter
	list_iter_end
		(list*);

list_iter
    list_iter_next
        (list_iter);

list_iter
    list_iter_prev
        (list_iter);

obj*
    list_iter_object
        (list_iter);

#endif
