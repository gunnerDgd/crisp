#ifndef __MAP_H__
#define __MAP_H__

#include "obj.h"
#include "list.h"

typedef struct map_key      {
    bool_t (*eq)(obj*, obj*);
    bool_t (*lt)(obj*, obj*);
    bool_t (*gt)(obj*, obj*);
}   map_key;

extern obj_trait* map_t   ;
typedef list_elem map_elem;
typedef struct    map     {
    obj      head;
    map_key* key ;
    list     map ;
}   map;

bool_t    map_new    (map*, u32_t, va_list);
bool_t    map_clone  (map*, map*)          ;
void      map_del    (map*)                ;

map_elem* map_push   (map*, obj*)          ;
void      map_pop    (map*, map_elem*)     ;
map_elem* map_find   (map*, obj*)          ;

bool_t    map_empty  (map*)                ;
map_elem* map_begin  (map*)                ;
map_elem* map_end    (map*)                ;
map_elem* map_next   (map_elem*)           ;
map_elem* map_prev   (map_elem*)           ;
obj*      map_get    (map_elem*)           ;

#endif