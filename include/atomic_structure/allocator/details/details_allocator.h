#pragma once
#include <atomic_structure/allocator/details/details_allocator_type.h>

void
    __atomic_allocator_initialize
        (__atomic_allocator*,
         void*(*)(void*, size_t, void*),
         void (*)(void*, size_t, void*),
         size_t, size_t, void*);