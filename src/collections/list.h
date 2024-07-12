#ifndef COLLECTIONS_LIST_H
#define COLLECTIONS_LIST_H

#include "pos.h"

extern obj_trait* list_t;
typedef struct    list  {
    obj  head      ;
    pos  begin, end;
    mem *mem       ;
}   list;

pos*   list_move_front(list* self, any_t* move);
pos*   list_move_back (list* self, any_t* move);

pos*   list_push_front(list* self, any_t move);
pos*   list_push_back (list* self, any_t move);

any_t  list_pop_front (list* self);
any_t  list_pop_back  (list* self);

bool_t list_empty     (list* self);
pos*   list_begin     (list* self);
pos*   list_end       (list* self);

#define list_for(name, cur)                                         \
    pos* cur = list_begin((name));                                  \
    for( ; (cur) && (cur) != list_end((name)) ; (cur) = next((cur)))\

#endif
