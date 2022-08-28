#pragma once
#include <atomic_structure/allocator/details/aligned_heap/aheap_type.h>

void*
    __atomic_allocator_aligned_heap_allocate
        (__atomic_allocator_aligned_heap*, size_t, void*);

size_t
    __atomic_allocator_aligned_heap_allocate_alignment
        (__atomic_allocator_aligned_heap*);

void
    __atomic_allocator_aligned_heap_deallocate
        (__atomic_allocator_aligned_heap*, size_t, void*);