#ifndef __LIBC_H__
#define __LIBC_H__

#include "core.h"
#include "libc/mem.h"

struct             libc  { obj head; };
extern obj_trait  *libc_t;
extern struct libc libc;

bool_t libc_new  (struct libc*, u32_t, va_list);
bool_t libc_clone(struct libc*, struct libc*)  ;
bool_t libc_ref  (struct libc*)                ;
void   libc_del  (struct libc*)                ;

#endif
