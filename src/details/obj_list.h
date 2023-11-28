#ifndef __DETAILS_OBJ_LIST_H__
#define __DETAILS_OBJ_LIST_H__

#include "../obj.h"
#include "../mem.h"

typedef struct __obj_list_elem         {
    struct __obj_list_elem *prev, *next;
    struct __obj_list      *list       ;
    obj                    *elem       ;
}   __obj_list_elem;

extern obj_trait  __obj_list_trait;
typedef struct    __obj_list      {
    obj             head      ;
    mem_res        *res       ;
    __obj_list_elem begin, end;
}   __obj_list;

bool_t           __obj_list_new       (__obj_list*, u32_t, va_list);
bool_t           __obj_list_clone     (__obj_list*, __obj_list*)   ;
void             __obj_list_del       (__obj_list*)                ;

__obj_list_elem* __obj_list_push_back (__obj_list*, obj*)              ;
__obj_list_elem* __obj_list_push_front(__obj_list*, obj*)              ;
__obj_list_elem* __obj_list_push_at   (__obj_list*, obj*, __obj_list_elem*);

obj*             __obj_list_pop_front (__obj_list*)                  ;
obj*             __obj_list_pop_back  (__obj_list*)                  ;
obj*             __obj_list_pop_at    (__obj_list*, __obj_list_elem*);
bool_t           __obj_list_empty     (__obj_list*)                  ;

#endif
