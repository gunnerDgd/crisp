#ifndef __BOX_H__
#define __BOX_H__

#include "obj.h"
#include "ptr.h"
#include "mem.h"

extern obj_trait* box_t;
typedef struct    box { u8_t box[64]; } box;

ptr   box_ptr (box*, u64_t);
u64_t box_size(box*)       ;

#endif