#pragma once
#include <atomic_structure/queue/mpmc/details/details_mpmc_types.h>

__atomic_mpmc
    __atomic_mpmc_initialize
        (size_t, __atomic_allocator*);

__atomic_mpmc
    __atomic_mpmc_intialize_from_memory
        (void*, size_t*, size_t);

void
    __atomic_mpmc_cleanup
        (__atomic_mpmc);