#ifndef __MEM_H__
#define __MEM_H__

#include "type.h"

typedef struct mem_res                                   {
    bool_t (*on_new)    (struct mem_res*, u32_t, va_list);
    void   (*on_del)    (struct mem_res*)                ;
    void*  (*on_mem_new)(struct mem_res*, u64_t)         ;
    void*  (*on_mem_del)(struct mem_res*, void*)         ;
}   mem_res;

mem_res* get_mem_res   ()        ;
mem_res* set_mem_res   (mem_res*);

bool_t   mem_res_new   (mem_res*, u32_t, ...)      ;
bool_t   mem_res_new_va(mem_res*, u32_t, va_list)  ;
void     mem_res_del   (mem_res*)                  ;
void*    mem_new       (mem_res*, u64_t)           ;
void     mem_del       (mem_res*, void*)           ;

void     mem_set       (void*, u8_t , u64_t)       ;
void     mem_copy      (void*, void*, u64_t)       ;
void     mem_move      (void*, void*, u64_t)       ;
u64_t    mem_find      (void*, void*, u64_t, u64_t);
bool_t   mem_eq        (void*, void*, u64_t)       ;
bool_t   mem_gt        (void*, void*, u64_t)       ;
bool_t   mem_lt        (void*, void*, u64_t)       ;

#define kb *(1ull << 10ull)
#define mb *(1ull << 20ull)
#define gb *(1ull << 30ull)

#endif
