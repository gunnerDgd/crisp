#ifndef __MAP_H__
#define __MAP_H__

#include "obj.h"

extern obj_trait* map_t   ;
typedef void     *map_elem;
typedef struct    map                    { u8_t map[256]; } map;
typedef struct    map_ops                {
    bool_t (*eq)   (obj*, obj*)          ;
    bool_t (*eq_va)(obj*, u32_t, va_list);

    bool_t (*lt)   (obj*, obj*)          ;
    bool_t (*lt_va)(obj*, u32_t, va_list);
    
    bool_t (*gt)   (obj*, obj*)          ;
    bool_t (*gt_va)(obj*, u32_t, va_list);
}   map_ops;

map_elem map_push   (map*, obj*)          ;
void     map_pop    (map*, map_elem)      ;
map_elem map_find   (map*, u32_t, ...)    ;
map_elem map_find_va(map*, u32_t, va_list);

#endif