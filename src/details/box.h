#ifndef __DETAILS_BOX_H__
#define __DETAILS_BOX_H__

#include "obj.h"
#include "mem.h"

extern __obj_trait __box_trait;
typedef struct     __box      {
    __obj    head;
    __mem*   mem ;
}   __box;

bool_t __box_init         (__box*, u32_t, va_list);
bool_t __box_init_as_clone(__box*, __box*)        ;
bool_t __box_init_as_ref  (__box*)                ;
void   __box_deinit       (__box*)                ;
u64_t  __box_size         ()                      ;

#endif