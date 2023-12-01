#ifndef __OBJ_LIST_H__
#define __OBJ_LIST_H__

#include "obj.h"

extern obj_trait  *list_t   ;
typedef struct     list     { u64_t handle[16]; } list;
typedef void*      list_elem;

list_elem list_push_back (list*, obj*)           ;
list_elem list_push_front(list*, obj*)           ;
list_elem list_push      (list*, obj*, list_elem);

obj*      list_pop_front (list*)	       ;
obj*      list_pop_back  (list*)	       ;
obj*      list_pop       (list*, list_elem);

bool_t    list_empty     (list*)          ;
list_elem list_begin     (list*)          ;
list_elem list_end       (list*)          ;
list_elem list_next      (list_elem)      ;
list_elem list_prev      (list_elem)      ;
obj*      list_get       (list_elem)      ;
obj*      list_set       (list_elem, obj*);

#define list_for(par, par_it)                                        \
    list_elem par_it = list_begin(par), par_it##_end = list_end(par);\
    for( ; par_it != par_it##_end ; par_it = list_next(par_it))

#define list_while(par, par_it)\
    list_elem par_it = list_begin(par), par_it##_end = list_end(par);\
    while(par_it != par_it##_end)

#endif
