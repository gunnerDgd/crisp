#pragma once
#include <atomic_structure/queue/spsc/spsc_type.h>
#include <atomic_structure/allocator/allocator.h>

atomic_spsc
    atomic_spsc_initialize
        (size_t, atomic_allocator);

atomic_spsc
    atomic_spsc_initialize_from_memory
        (void*, size_t*, size_t);

void
    atomic_spsc_cleanup
        (atomic_spsc);