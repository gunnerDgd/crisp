#ifndef __LIST_H__
#define __LIST_H__

#include "obj.h"

typedef struct list_elem         {
    obj               head       ;
    struct list_elem *prev, *next;
    struct list      *list       ;
    obj              *elem       ;
}   list_elem;

extern obj_trait* list_t;
typedef struct    list  {
    obj       head      ;
    mem      *res       ;
    list_elem begin, end;
}   list;

bool_t     list_new       (list*, u32_t, va_list)  ;
bool_t     list_clone     (list*, list*)           ;
void       list_del       (list*)                  ;

list_elem* list_push_back (list*, obj*)            ;
list_elem* list_push_front(list*, obj*)            ;
list_elem* list_push      (list*, obj*, list_elem*);

obj*       list_pop_front (list*)                  ;
obj*       list_pop_back  (list*)                  ;
obj*       list_pop       (list*, list_elem*)      ;

bool_t     list_empty     (list*)                  ;
list_elem* list_begin     (list*)                  ;
list_elem* list_end       (list*)                  ;
list_elem* list_next      (list_elem*)             ;
list_elem* list_prev      (list_elem*)             ;
obj*       list_get       (list_elem*)             ;
obj*       list_set       (list_elem*, obj*)       ;

#define list_for(par, par_it)                                          \
    list_elem* par_it = list_begin(par), *par_it##_end = list_end(par);\
    for( ; par_it != par_it##_end ; par_it = list_next(par_it))

#define list_while(par, par_it)                                        \
    list_elem* par_it = list_begin(par), *par_it##_end = list_end(par);\
    while(par_it != par_it##_end)

#endif
