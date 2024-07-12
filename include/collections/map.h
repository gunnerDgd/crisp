#ifndef COLLECTIONS_MAP_H
#define COLLECTIONS_MAP_H

#include "pos.h"

extern obj_trait* map_t;
typedef struct    map  { u8_t map[256]; } map;

pos*   map_move (map*, obj*) ;
pos*   map_push (map*, obj*) ;
void   map_pop  (map*, any_t);
pos*   map_find (map*, any_t);

bool_t map_empty(map*);
pos*   map_begin(map*);
pos*   map_end  (map*);

#endif