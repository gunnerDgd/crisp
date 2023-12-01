#ifndef __DETAILS_LIST_H__
#define __DETAILS_LIST_H__

#include "../obj.h"
#include "../mem.h"

typedef struct __list_elem         {
    struct __list_elem *prev, *next;
    struct __list      *list       ;
    obj                *elem       ;
}   __list_elem;

extern obj_trait  __list_trait;
typedef struct    __list      {
    obj         head      ;
    mem_res    *res       ;
    __list_elem begin, end;
}   __list;

bool_t       __list_new       (__list*, u32_t, va_list);
bool_t       __list_clone     (__list*, __list*)       ;
void         __list_del       (__list*)                ;

__list_elem* __list_push_back (__list*, obj*)              ;
__list_elem* __list_push_front(__list*, obj*)              ;
__list_elem* __list_push      (__list*, obj*, __list_elem*);

obj*         __list_pop_front (__list*)              ;
obj*         __list_pop_back  (__list*)              ;
obj*         __list_pop       (__list*, __list_elem*);
bool_t       __list_empty     (__list*)              ;

#endif
