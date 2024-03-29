#ifndef __COLLECTIONS_LIST_H__
#define __COLLECTIONS_LIST_H__

#include "node.h"

extern obj_trait  *list_t   ;
typedef struct     list     { u8_t handle[256]; } list;

node*  list_push_back (list*, obj*);
node*  list_push_front(list*, obj*);

obj*   list_pop_front (list*)      ;
obj*   list_pop_back  (list*)	   ;

bool_t list_empty     (list*)      ;
node*  list_begin     (list*)      ;
node*  list_end       (list*)      ;

#define list_for(par, par_it)                                        \
    node* par_it = list_begin(par), *par_it##_end = list_end(par);   \
    for( ; par_it && (par_it != par_it##_end) ; par_it = next(par_it))

#define list_while(par, par_it)                                   \
    node* par_it = list_begin(par), *par_it##_end = list_end(par);\
    while(par_it && (par_it != par_it##_end))

#endif
