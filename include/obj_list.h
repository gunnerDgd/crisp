#ifndef __OBJ_LIST_H__
#define __OBJ_LIST_H__

#include "obj.h"

extern obj_trait  *obj_list_t   ;
typedef struct     obj_list     { u64_t handle[16]; } obj_list;
typedef void*      obj_list_elem;

obj_list_elem obj_list_push_back (obj_list*, obj*)               ;
obj_list_elem obj_list_push_front(obj_list*, obj*)               ;
obj_list_elem obj_list_push_at   (obj_list*, obj*, obj_list_elem);

obj*          obj_list_pop_front (obj_list*)	           ;
obj*          obj_list_pop_back  (obj_list*)	           ;
obj*          obj_list_pop_at    (obj_list*, obj_list_elem);

bool_t        obj_list_empty     (obj_list*)          ;
obj_list_elem obj_list_begin     (obj_list*)          ;
obj_list_elem obj_list_end       (obj_list*)          ;
obj_list_elem obj_list_next      (obj_list_elem)      ;
obj_list_elem obj_list_prev      (obj_list_elem)      ;
obj*          obj_list_get       (obj_list_elem)      ;
obj*          obj_list_set       (obj_list_elem, obj*);

#define obj_list_for(par, par_it)\
    obj_list_elem par_it = obj_list_begin(par), par_it##_end = obj_list_end(par);\
    for( ; par_it != par_it##_end ; par_it = obj_list_next(par_it))

#define obj_list_while(par, par_it)\
    obj_list_elem par_it = obj_list_begin(par), par_it##_end = obj_list_end(par);\
    while(par_it != par_it##_end)

#endif
