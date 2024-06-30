#ifndef COLLECTIONS_MAP_H
#define COLLECTIONS_MAP_H

#include "list.h"

extern obj_trait* map_t;
typedef struct    map  {
    obj  head;
    list map ;
}   map;

pos*   map_move (map* self, any_t* move);
pos*   map_push (map* self, any_t  push);
void   map_pop  (map* self, any_t  pop) ;
pos*   map_find (map* self, any_t  find);

bool_t map_empty(map* self);
pos*   map_begin(map* self);
pos*   map_end  (map* self);

#endif