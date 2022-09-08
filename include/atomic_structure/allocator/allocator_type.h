#pragma once

#include <stdint.h>
#include <stddef.h>

typedef void*
    (*atomic_allocator_allocate_t)
        (void*, size_t, void*);
typedef void
    (*atomic_allocator_deallocate_t)
        (void*, size_t, void*);

typedef struct 
    atomic_allocator
        { void* handle; }
            atomic_allocator;