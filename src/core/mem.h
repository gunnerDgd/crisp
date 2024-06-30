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

extern obj_trait *mem_t;
typedef struct    mem  {
    obj      head;
    mem_ops *ops ;
    any_t    mem ;
}   mem;

mem*   get_mem  (void);
mem*   set_mem  (mem*);

void   mem_free (mem*, void*, u64_t);
void*  mem_use  (mem*, void*, u64_t);

u64_t  mem_find (u8_t*, u8_t*, u64_t, u64_t);
void   mem_set  (u8_t*, u8_t , u64_t);
void   mem_copy (u8_t*, u8_t*, u64_t);
void   mem_move (u8_t*, u8_t*, u64_t);

ord_t  mem_ord  (u8_t*, u8_t*, u64_t);
bool_t mem_eq   (u8_t*, u8_t*, u64_t);
bool_t mem_gt   (u8_t*, u8_t*, u64_t);
bool_t mem_lt   (u8_t*, u8_t*, u64_t);

#define KB *(1ull << 10ull)
#define MB *(1ull << 20ull)
#define GB *(1ull << 30ull)

#ifndef __cplusplus
#define new(par)  mem_use (get_mem(), null_t, sizeof(par))
#define drop(par) mem_free(get_mem(), par   , 0)
#endif

#endif
