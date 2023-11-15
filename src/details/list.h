#ifndef __DETAILS_LIST_H__
#define __DETAILS_LIST_H__

#include "../obj.h"
#include "../mem.h"
#include "../alloc.h"

typedef struct __list_elem         {
    mem                 mem        ;
    struct __list_elem *prev, *next;
    struct __list_t    *list       ;
    obj                *elem       ;
}   __list_elem;

extern obj_trait __list_trait;
typedef struct   __list      {
    obj         head         ;
    alloc      *alloc        ;
    __list_elem begin, end   ;
}   __list;

bool_t       __list_init         (__list*, u32_t, va_list);
bool_t       __list_init_as_clone(__list*, __list*)       ;
void         __list_deinit       (__list*)                ;
u64_t        __list_size         ()                       ;

__list_elem* __list_push_back    (__list*, obj*)              ;
__list_elem* __list_push_front   (__list*, obj*)              ;
__list_elem* __list_push_at      (__list*, obj*, __list_elem*);

void         __list_pop_front    (__list*)              ;
void         __list_pop_back     (__list*)              ;
void         __list_pop_at       (__list*, __list_elem*);
bool_t       __list_empty        (__list*)              ;

#endif
