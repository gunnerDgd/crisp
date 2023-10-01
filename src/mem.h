#ifndef __MEM_H__
#define __MEM_H__

#include "alloc.h"

typedef void*                        mem;
typedef struct ptr { u64_t ptr[2]; } ptr;

mem
    mem_init
        (alloc*, u64_t);

mem
    mem_init_as_clone
        (mem);

void
    mem_deinit
        (mem);

ptr
    mem_ptr
        (mem);

void*
    mem_ptr_raw
        (mem);

ptr
    ptr_move
        (ptr, u64_t);

bool_t
    ptr_rd8
        (ptr, u8_t*);

bool_t
    ptr_rd16
        (ptr, u16_t*);

bool_t
    ptr_rd32
        (ptr, u32_t*);

bool_t
    ptr_rd64
        (ptr, u64_t*);

u64_t
    ptr_read
        (ptr, void*, u64_t);

bool_t
    ptr_wr8
        (ptr, u8_t);

bool_t
    ptr_wr16
        (ptr, u16_t);

bool_t
    ptr_wr32
        (ptr, u32_t);

bool_t
    ptr_wr64
        (ptr, u64_t);

u64_t
    ptr_write
        (ptr, void*, u64_t);


#endif
