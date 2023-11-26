#ifndef __DETAILS_MEM_H__
#define __DETAILS_MEM_H__

#include "../type.h"
#include "../type_atom.h"

typedef struct __mem_res_trait                           {
    bool_t (*on_new)    (struct mem_res*, u32_t, va_list);
    void   (*on_del)    (struct mem_res*)                ;
    void*  (*on_mem_new)(struct mem_res*, u64_t)         ;
    void*  (*on_mem_del)(struct mem_res*, void*)         ;
}   __mem_res_trait;

typedef struct __mem_res  {
    __mem_res_trait* trait;
}   __mem_res;

bool_t __mem_res_new (__mem_res*, __mem_res_trait*, u32_t, va_list);
void   __mem_res_del (__mem_res*)                                  ;
void*  __mem_new     (__mem_res*, u64_t)                           ;
void   __mem_del     (__mem_res*, void*)                           ;

#endif