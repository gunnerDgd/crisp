#ifndef __SET_H__
#define __SET_H__

#include "obj.h"

extern obj_trait* set_root_t  ;
typedef struct    set_root    {
    obj              head     ;
    obj             *node[64] ;
    u64_t            free     ;
    u64_t            use      ;

    u64_t            sub_count;
    struct set_root *sub [64] ;
}   set_root;

bool_t set_root_new  (set_root*, u32_t, va_list);
bool_t set_root_clone(set_root*, set_root*)     ;
void   set_root_del  (set_root*)                ;

obj*   set_root_acq  (set_root*)      ;
bool_t set_root_rel  (set_root*, obj*);

extern obj_trait *set_t;
typedef struct    set  {
    obj       head;
    set_root* set ;
}   set;

bool_t set_new  (set*, u32_t, va_list);
bool_t set_clone(set*, set*)          ;
void   set_del  (set*)                ;

obj*   set_acq  (set*)      ;
void   set_rel  (set*, obj*);

#endif