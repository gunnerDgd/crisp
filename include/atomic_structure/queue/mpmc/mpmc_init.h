#pragma once

#include <atomic_structure/allocator/allocator.h>
#include <atomic_structure/queue/mpmc/mpmc_type.h>

atomic_mpmc
    atomic_mpmc_initialize
        (size_t, atomic_allocator);

atomic_mpmc
    atomic_mpmc_initialize_from_memory
        (void*, size_t*, size_t);

void
    atomic_mpmc_cleanup
        (atomic_mpmc);