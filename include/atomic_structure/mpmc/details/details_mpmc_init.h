#pragma once
#include <atomic_structure/mpmc/details/details_mpmc_types.h>

__atomic_mpmc*
    __atomic_mpmc_initialize
        (size_t, atomic_allocator*);

void
    __atomic_mpmc_cleanup
        (__atomic_mpmc*);