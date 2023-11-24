#ifndef __DETAILS_BOX_H__
#define __DETAILS_BOX_H__

#include "../obj.h"
#include "../mem.h"

extern obj_trait __box_trait;
typedef struct   __box      {
    obj head;
    mem mem ;
}   __box   ;

bool_t __box_new  (__box*, u32_t, va_list);
bool_t __box_clone(__box*, __box*)        ;
bool_t __box_ref  (__box*)                ;
void   __box_del  (__box*)                ;

#endif