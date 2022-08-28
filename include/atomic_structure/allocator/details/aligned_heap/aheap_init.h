#pragma once
#include <atomic_structure/allocator/details/aligned_heap/aheap_type.h>

__atomic_allocator_aligned_heap*
    __atomic_allocator_aligned_heap_initialize
        (size_t);

void
    __atomic_allocator_aligned_heap_cleanup
        (__atomic_allocator_aligned_heap*);