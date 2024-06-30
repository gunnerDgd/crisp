#ifndef CORE_BOX_H
#define CORE_BOX_H

#include "obj.h"
#include "mem.h"

extern obj_trait* box_t;
typedef struct    box { u8_t box[64]; } box;

void* box_ptr (box*);
u64_t box_size(box*);

#endif