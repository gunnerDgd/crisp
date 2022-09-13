#pragma once
#include <atomic_structure/allocator/allocator_type.h>

void
    atomic_allocator_initialize
        (atomic_allocator*,
            atomic_allocator_allocate_t, atomic_allocator_deallocate_t,
                size_t, size_t, void*);