#pragma once
#include <atomic_structure/allocator/allocator.h>

atomic_allocator*
    atomic_allocator_aligned_heap_initialize
        (size_t);

void
    atomic_allocator_aligned_heap_cleanup
        (atomic_allocator*);