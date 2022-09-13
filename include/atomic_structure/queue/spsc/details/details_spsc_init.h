#pragma once
#include <atomic_structure/queue/spsc/details/details_spsc_type.h>

__atomic_spsc
    __atomic_spsc_initialize
        (size_t, __atomic_allocator*);

__atomic_spsc
    __atomic_spsc_initialize_from_memory
        (void*, size_t*, size_t);

void
    __atomic_spsc_cleanup
        (__atomic_spsc);