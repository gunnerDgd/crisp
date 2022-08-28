#pragma once

#include <stdint.h>
#include <stddef.h>

typedef struct
    atomic_allocator
{
    void*
        (*allocate)     
            (struct atomic_allocator*, size_t, void*);
    size_t
        (*allocate_alignment)
            (struct atomic_allocator*);
    void
        (*deallocate)
            (struct atomic_allocator*, size_t, void*);
}   atomic_allocator;