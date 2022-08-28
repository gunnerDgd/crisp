#pragma once
#include <atomic_structure/spsc/spsc_type.h>
#include <atomic_structure/allocator/allocator.h>

atomic_spsc
    atomic_spsc_initialize
        (size_t, atomic_allocator*);

void
    atomic_spsc_cleanup
        (atomic_spsc);