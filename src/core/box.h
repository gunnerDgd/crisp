#ifndef CORE_BOX_H
#define CORE_BOX_H

#include "obj.h"
#include "mem.h"

extern obj_trait* box_t;
typedef struct    box  {
    obj   head;
    mem*  mem;
    u8_t* ptr;
    u64_t len;
}   box;

void*  box_ptr  (box*);
u64_t  box_size (box*);

#endif