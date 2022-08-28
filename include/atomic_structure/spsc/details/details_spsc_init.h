#pragma once
#include <atomic_structure/allocator/allocator.h>
#include <atomic_structure/spsc/details/details_spsc_type.h>

__atomic_spsc*
    __atomic_spsc_initialize
        (size_t, atomic_allocator*);

void
    __atomic_spsc_cleanup
        (__atomic_spsc*);