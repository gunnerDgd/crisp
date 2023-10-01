#ifndef __DETAILS_MEM_H__
#define __DETAILS_MEM_H__

#include "../type.h"
#include "../type_atomic.h"

typedef struct __ptr     {
    struct __mem* mem    ;
    u64_t         mem_cur;
}   __ptr;

typedef struct __mem_trait         {
    bool_t (*rd8)  (__ptr*, u8_t *);
    bool_t (*rd16) (__ptr*, u16_t*);
    bool_t (*rd32) (__ptr*, u32_t*);
    bool_t (*rd64) (__ptr*, u64_t*);
    u64_t  (*read) (__ptr*, void*, u64_t);

    bool_t (*wr8)  (__ptr*, u8_t)  ;
    bool_t (*wr16) (__ptr*, u16_t) ;
    bool_t (*wr32) (__ptr*, u32_t) ;
    bool_t (*wr64) (__ptr*, u64_t) ;
    u64_t  (*write)(__ptr*, void*, u64_t);
}   __mem_trait;

typedef struct __mem          {
	struct __alloc *alloc	  ;
	u64_t			alloc_size;
    u8_t*           ptr       ;
    __mem_trait    *trait     ;
}	__mem;

__mem*
    __mem_init
        (struct __alloc*, u64_t);

__mem*
    __mem_init_as_clone
        (__mem*);

void
    __mem_deinit
        (__mem*);

#endif