#ifndef __BOX_H__
#define __BOX_H__

#include "obj.h"
#include "mem.h"

extern obj_trait* box_t;
typedef struct    box  {
    obj   head;
    mem*  mem;
    u8_t* ptr;
    u64_t len;
}   box;

bool_t box_new  (box*, u32_t, va_list);
bool_t box_clone(box*, box*)          ;
void   box_del  (box*)                ;

void*  box_ptr  (box*);
u64_t  box_size (box*);

#endif