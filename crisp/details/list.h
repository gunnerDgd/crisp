#ifndef CRISP_DETAILS_LIST_H
#define CRISP_DETAILS_LIST_H

#include <crisp/details/obj.h>

typedef struct list_element_t {
    mem_t                 *mem        ;
    struct list_element_t *prev, *next;
    struct list_t         *list;
    obj_t                 *elem;
}   list_element_t;

typedef struct
    list_t { alloc_t *alloc; list_element_t begin, end; }
        list_t;

c_bool_t
    list_init
        (list_t*, alloc_t*);

c_bool_t
    list_init_as_clone
        (list_t*, list_t*);

c_bool_t
    list_deinit
        (list_t*);

list_element_t*
    list_push_back
        (list_t*, obj_t*);

list_element_t*
    list_push_front
        (list_t*, obj_t*);

list_element_t*
    list_push_at
        (list_t*, obj_t*, list_element_t*);

obj_t*
    list_pop_front
        (list_t*);

obj_t*
    list_pop_back
        (list_t*);

obj_t*
    list_pop_at
        (list_t*, list_element_t*);

#endif
