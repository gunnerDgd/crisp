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

void
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

void
    list_pop_front
        (list*);

void
    list_pop_back
        (list*);

void
    list_pop_at
        (list*, list_iter);

list_iter
	list_begin
		(list*);

list_iter
	list_end
		(list*);

list_iter
    list_next
        (list_iter);

list_iter
    list_prev
        (list_iter);

obj*
    list_obj
        (list_iter);

#endif
