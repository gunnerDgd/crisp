#ifndef CORE_MEM_H
#define CORE_MEM_H

#include "type.h"
#include "obj.h"

typedef struct mem_ops                   {
    void  (*on_free)(any_t, void*, u64_t);
    void* (*on_use) (any_t, void*, u64_t);
    any_t (*on_new) (u32_t, va_list);
    void  (*on_del) (any_t);
}   mem_ops;

#define make_mem_ops(do_use, do_free, do_new, do_del)     {\
    .on_use  = ((void* (*)(any_t, void*, u64_t))(do_use)) ,\
    .on_free = ((void  (*)(any_t, void*, u64_t))(do_free)),\
    .on_new  = ((any_t (*)(u32_t, va_list))     (do_new)) ,\
    .on_del  = ((void  (*)(any_t))              (do_del))  \
}

extern obj_trait* mem_t;
typedef struct    mem { u8_t mem[64]; } mem;

mem*   get_mem ()                          ;
mem*   set_mem (mem*)                      ;

void   mem_free (mem*, void*, u64_t);
void*  mem_use  (mem*, void*, u64_t);

void   mem_set (void*, u8_t , u64_t)       ;
ord_t  mem_ord (void*, void*, u64_t)       ;
void   mem_copy(void*, void*, u64_t)       ;
void   mem_move(void*, void*, u64_t)       ;
u64_t  mem_find(void*, void*, u64_t, u64_t);
bool_t mem_eq  (void*, void*, u64_t)       ;
bool_t mem_gt  (void*, void*, u64_t)       ;
bool_t mem_lt  (void*, void*, u64_t)       ;

#define KB *(1ULL << 10ULL)
#define MB *(1ULL << 20ULL)
#define GB *(1ULL << 30ULL)

#ifndef __cplusplus
#define new(par)  mem_use (get_mem(), null_t, sizeof(par))
#define drop(par) mem_free(get_mem(), par   , 0)
#endif

#endif
