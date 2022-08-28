#pragma once
#include <atomic_structure/allocator/allocator.h>

atomic_allocator*
    atomic_allocator_syspaging_initialize
        ();

atomic_allocator*
    atomic_allocator_syspaging_initialize_large
        (size_t);

atomic_allocator*
    atomic_allocator_syspaging_initialize_heap
        (size_t);

void
    atomic_allocator_syspaging_cleanup
        (atomic_allocator*);