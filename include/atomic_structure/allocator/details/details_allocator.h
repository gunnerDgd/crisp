#pragma once
#include <atomic_structure/allocator/details/details_allocator_type.h>

__atomic_allocator*
    __atomic_allocator_initialize
        (void*(*)(void*, size_t, void*),
         void (*)(void*, size_t, void*),
         size_t, size_t, void*);

void
    __atomic_allocator_cleanup
        (__atomic_allocator*);