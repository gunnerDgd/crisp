#ifndef __MEM_H__
#define __MEM_H__

#include "alloc.h"

typedef void* mem;

mem
    mem_init
        (alloc*, u64_t);

mem
    mem_init_as_clone
        (mem);

bool_t
    mem_deinit
        (mem);

u64_t
    mem_copy_from
        (mem, void*, u64_t);

u64_t
    mem_copy_to
        (mem, void*, u64_t);

u64_t
    mem_move
        (mem, mem);

u64_t
    mem_size
        (mem);

void*
    mem_ptr
        (mem);

#endif
