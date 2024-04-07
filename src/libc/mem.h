#ifndef __LIBC_MEM_H__
#define __LIBC_MEM_H__

#include "../core.h"

void*          libc_mem_do_acq(any_t, void*, u64_t);
void           libc_mem_do_rel(any_t, void*, u64_t);
any_t          libc_mem_do_new(u32_t, va_list);
void           libc_mem_do_del(any_t)         ;
extern mem_ops libc_mem_do;
extern mem     libc_mem   ;

#endif
