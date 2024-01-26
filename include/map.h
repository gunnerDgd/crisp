#ifndef __MAP_H__
#define __MAP_H__

#include "node.h"

extern obj_trait* map_t     ;
typedef struct    map       { u8_t map[256]; } map;
typedef struct    map_key   {
    bool_t (*eq)(obj*, obj*);
    bool_t (*lt)(obj*, obj*);
    bool_t (*gt)(obj*, obj*);
}   map_key;

node*  map_push (map*, obj*);
void   map_pop  (map*, obj*);
node*  map_find (map*, obj*);

bool_t map_empty(map*);
node*  map_begin(map*);
node*  map_end  (map*);

#endif