#pragma once
#include <atomic_structure/allocator/allocator.h>

typedef struct
    __atomic_allocator_aligned_heap
{
    atomic_allocator
        aheap_allocator;
    size_t
        aheap_allocate_alignment;
}   __atomic_allocator_aligned_heap;