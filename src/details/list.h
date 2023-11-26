#ifndef __DETAILS_LIST_H__
#define __DETAILS_LIST_H__

#include "../obj.h"
#include "../mem.h"

#include "iter.h"

typedef struct __list_elem         {
    struct __list_elem *prev, *next;
    struct __list      *list       ;
    obj                *elem       ;
}   __list_elem;

extern __iter_trait __list_iter_trait;
extern obj_trait    __list_trait     ;
typedef struct      __list           {
    obj         head      ;
    mem_res    *res       ;
    __list_elem begin, end;
}   __list;

bool_t __list_new  (__list*, u32_t, va_list);
bool_t __list_clone(__list*, __list*)       ;
void   __list_del  (__list*)                ;

__list_elem* __list_push_back (__list*, obj*)              ;
__list_elem* __list_push_front(__list*, obj*)              ;
__list_elem* __list_push_at   (__list*, obj*, __list_elem*);

void   __list_pop_front(__list*)              ;
void   __list_pop_back (__list*)              ;
void   __list_pop_at   (__list*, __list_elem*);
bool_t __list_empty    (__list*)              ;

void   __list_iter     (__list*, __iter*)   ;
void*  __list_iter_next(__list_elem*)       ;
void*  __list_iter_get (__list_elem*)       ;
void*  __list_iter_set (__list_elem*, void*);

#endif
