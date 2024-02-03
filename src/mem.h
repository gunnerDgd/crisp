#ifndef __MEM_H__
#define __MEM_H__

#include "type.h"

typedef struct mem                      {
    void* (*on_new) (struct mem*, u64_t);
    void  (*on_del) (struct mem*, void*);
}   mem;

mem*     get_mem ()                          ;
mem*     set_mem (mem*)                      ;
void*    mem_new (mem*, u64_t)               ;
void     mem_del (mem*, void*)               ;

void     mem_set (void*, u8_t , u64_t)       ;
void     mem_copy(void*, void*, u64_t)       ;
void     mem_move(void*, void*, u64_t)       ;
u64_t    mem_find(void*, void*, u64_t, u64_t);
bool_t   mem_eq  (void*, void*, u64_t)       ;
bool_t   mem_gt  (void*, void*, u64_t)       ;
bool_t   mem_lt  (void*, void*, u64_t)       ;

#define KB *(1ull << 10ull)
#define MB *(1ull << 20ull)
#define GB *(1ull << 30ull)

#ifndef __cplusplus
#define new(par)  mem_new(0, sizeof(par))
#define drop(par) mem_del(0, par)
#endif

#endif
