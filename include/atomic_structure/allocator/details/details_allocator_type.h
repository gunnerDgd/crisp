#pragma once
#include <stdint.h>
#include <stddef.h>

typedef struct
    __atomic_allocator
{
    void*
        (*allocate)  (void*, size_t, void*);
    void
        (*deallocate)(void*, size_t, void*);
    
    size_t
        allocate_max_size ;
    size_t
        allocate_alignment;
    void*
        allocate_parameter;
}  __atomic_allocator;